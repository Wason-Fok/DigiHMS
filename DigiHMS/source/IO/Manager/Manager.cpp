#include "Manager.h"
#include "../HAL_Driver.h"
#include <IO/Serial/Serial.h>
#include <Common/Checksum.h>

static QString ADD_ESCAPE_SEQUENCES(const QString& str)
{
	auto escapedStr = str;
	escapedStr = escapedStr.replace("\\a", "\a");
	escapedStr = escapedStr.replace("\\b", "\b");
	escapedStr = escapedStr.replace("\\f", "\f");
	escapedStr = escapedStr.replace("\\n", "\n");
	escapedStr = escapedStr.replace("\\r", "\r");
	escapedStr = escapedStr.replace("\\t", "\t");
	escapedStr = escapedStr.replace("\\v", "\v");
	return escapedStr;
}

Manager::Manager()
	: m_writeEnabled(true)
	, m_maxBufferSize(1024 * 1024)
	, m_driver(Q_NULLPTR)
	, m_receivedBytes(0)
	, m_enableCrc(false)
	, m_startSequence("/*")
	, m_finishSequence("*/")
	, m_separatorSequence(",")
{
	// 初始化设置
	setMaxBufferSize(1024 * 1024);
	setSelectedDriver(SelectedDriver::Serial);

	// 绑定选择设备更换信号
	connect(this, &Manager::selectedDriverChanged, this, &Manager::configurationChanged);
}

Manager& Manager::Instance()
{
	static Manager singleton;
	return singleton;
}

bool Manager::ReadOnly()
{
	return Connected() && !m_writeEnabled;
}

bool Manager::ReadWrite()
{
	return Connected() && m_writeEnabled;
}

bool Manager::Connected()
{
	if (m_driver)
		return m_driver->IsOpen();

	return false;
}

bool Manager::DeviceAvailable()
{
	return m_driver != Q_NULLPTR;
}

bool Manager::ConfigurationOk()
{
	if (m_driver)
		return m_driver->ConfigurationOk();

	return false;
}

qint32 Manager::MaxBufferSize() const
{
	return m_maxBufferSize;
}

HAL_Driver* Manager::Driver()
{
	return m_driver;
}

Manager::SelectedDriver Manager::GetSelectedDriver()
{
	return m_selectedDriver;
}

QStringList Manager::AvailableDrivers() const
{
	QStringList list;
	list.append(tr("Serial port"));
	return list;
}

qint64 Manager::WriteData(const QByteArray& data)
{
	if (Connected())
	{
		// 写入数据到设备
		auto bytes = m_driver->Write(data);

		// 触发信号
		if (bytes > 0)
		{
			auto writtenData = data;
			writtenData.chop(data.length() - bytes);
			emit dataSent(writtenData);
		}

		return bytes;
	}

	return -1;
}

QString Manager::StartSequence() const
{
	return m_startSequence;
}

QString Manager::FinishSequence() const
{
	return m_finishSequence;
}

QString Manager::SeparatorSequence() const
{
	return m_separatorSequence;
}

Manager::ValidationStatus Manager::IntegrityChecks(const QByteArray& frame, const QByteArray& cursor, qint32* bytes)
{
	auto finish = FinishSequence().toUtf8();
	auto crc8Header = finish + "crc8:";
	auto crc16Header = finish + "crc16:";
	auto crc32Header = finish + "crc32:";

	if (cursor.contains(crc8Header))
	{
		m_enableCrc = true;
		auto offset = cursor.indexOf(crc8Header) + crc8Header.length() - 1;

		if (cursor.length() >= offset + 1)
		{
			*bytes += crc8Header.length() + 1;

			const quint8 crc = cursor.at(offset + 1);

			if (CRC8(frame.data(), frame.length()) == crc)
				return ValidationStatus::FrameOk;
			else
				return ValidationStatus::ChecksumError;
		}
	}
	// Check CRC-16
	else if (cursor.contains(crc16Header))
	{
		// Enable the CRC flag
		m_enableCrc = true;
		auto offset = cursor.indexOf(crc16Header) + crc16Header.length() - 1;

		// Check if we have enough data in the buffer
		if (cursor.length() >= offset + 2)
		{
			// Increment the number of bytes to remove from master buffer
			*bytes += crc16Header.length() + 2;

			// Get 16-bit checksum
			const quint8 a = cursor.at(offset + 1);
			const quint8 b = cursor.at(offset + 2);
			const quint16 crc = (a << 8) | (b & 0xff);

			// Compare checksums
			if (CRC16(frame.data(), frame.length()) == crc)
				return ValidationStatus::FrameOk;
			else
				return ValidationStatus::ChecksumError;
		}
	}
	// Check CRC-32
	else if (cursor.contains(crc32Header))
	{
		// Enable the CRC flag
		m_enableCrc = true;
		auto offset = cursor.indexOf(crc32Header) + crc32Header.length() - 1;

		// Check if we have enough data in the buffer
		if (cursor.length() >= offset + 4)
		{
			// Increment the number of bytes to remove from master buffer
			*bytes += crc32Header.length() + 4;

			// Get 32-bit checksum
			const quint8 a = cursor.at(offset + 1);
			const quint8 b = cursor.at(offset + 2);
			const quint8 c = cursor.at(offset + 3);
			const quint8 d = cursor.at(offset + 4);
			const quint32 crc = (a << 24) | (b << 16) | (c << 8) | (d & 0xff);

			// Compare checksums
			if (CRC32(frame.data(), frame.length()) == crc)
				return ValidationStatus::FrameOk;
			else
				return ValidationStatus::ChecksumError;
		}
	}
	else if (!m_enableCrc)
	{
		*bytes += finish.length();
		return ValidationStatus::FrameOk;
	}

	return ValidationStatus::ChecksumIncomplete;
}

void Manager::connectDevice()
{
	// 设置新的设备连接
	setSelectedDriver(m_selectedDriver);

	if (DeviceAvailable())
	{
		// 设置打开方式
		QIODevice::OpenMode mode = QIODevice::ReadOnly;
		if (m_writeEnabled)
			mode = QIODevice::ReadWrite;

		// 打开设备
		if (m_driver->Open(mode))
		{
			connect(m_driver, &HAL_Driver::dataReceived, this, &Manager::onDataReceived);
		}
		else
		{
			disconnectDriver();
		}

		emit connectedChanged();
	}
}

void Manager::disconnectDriver()
{
	if (DeviceAvailable())
	{
		disconnect(m_driver, &HAL_Driver::dataReceived, this, &Manager::onDataReceived);
		disconnect(m_driver, &HAL_Driver::configurationChanged, this, &Manager::configurationChanged);

		m_driver->Close();

		m_driver = Q_NULLPTR;
		m_receivedBytes = 0;
		m_dataBuffer.clear();
		m_dataBuffer.reserve(MaxBufferSize());

		emit driverChanged();
		emit connectedChanged();
	}
}

void Manager::toggleConnection()
{
	if (Connected())
		disconnectDriver();
	else
		connectDevice();
}

void Manager::setWriteEnable(const bool enabled)
{
	m_writeEnabled = enabled;
	emit writeEnabledChanged();
}

void Manager::processPayload(const QByteArray& payload)
{
	if (!payload.isEmpty())
	{
		m_receivedBytes += payload.size();
		if (m_receivedBytes >= UINT64_MAX)
			m_receivedBytes = 0;

		emit dataReceived(payload);
		emit frameReceived(payload);
		emit receivedBytesChanged();
	}
}

void Manager::setMaxBufferSize(const qint32 maxBufferSize)
{
	m_maxBufferSize = maxBufferSize;
	emit maxBufferSizeChanged();

	m_dataBuffer.reserve(maxBufferSize);
}

void Manager::setSelectedDriver(const SelectedDriver& driver)
{
	// 断开当前连接的设备
	disconnectDriver();

	// 更新通讯设备类型
	m_selectedDriver = driver;

	disconnectDriver();

	switch (m_selectedDriver)
	{
	case Manager::SelectedDriver::Serial:
		setDriver(&(Serial::Instance()));
		break;
	default:
		setDriver(Q_NULLPTR);
		break;
	}
	
	emit selectedDriverChanged();
}

void Manager::setStartSequence(const QString& sequence)
{
	m_startSequence = ADD_ESCAPE_SEQUENCES(sequence);
	if (m_startSequence.isEmpty())
		m_startSequence = "/*";

	emit startSequenceChanged();
}

void Manager::setFinishSequence(const QString& sequence)
{
	m_finishSequence = ADD_ESCAPE_SEQUENCES(sequence);
	if (m_finishSequence.isEmpty())
		m_finishSequence = "*/";

	Q_EMIT finishSequenceChanged();
}

void Manager::setSeparatorSequence(const QString& sequence)
{
	m_separatorSequence = ADD_ESCAPE_SEQUENCES(sequence);
	if (m_separatorSequence.isEmpty())
		m_separatorSequence = ",";

	Q_EMIT separatorSequenceChanged();
}

void Manager::readFrames()
{
	if (!Connected())
		return;

	auto bytes = 0;
	auto prevBytes = 0;
	auto cursor = m_dataBuffer;
	auto start = m_startSequence.toUtf8();
	auto finish = m_finishSequence.toUtf8();

	while (cursor.contains(start) && cursor.contains(finish))
	{
		auto sIndex = cursor.indexOf(start);
		cursor = cursor.mid(sIndex + start.length(), -1);
		bytes += sIndex + start.length();

		auto fIndex = cursor.indexOf(finish);
		auto frame = cursor.left(fIndex);

		qint32 chop = 0;
		auto result = IntegrityChecks(frame, cursor, &chop);
		if (result == ValidationStatus::FrameOk)
		{
			emit frameReceived(frame);
		}
		else if (result == ValidationStatus::ChecksumIncomplete)
		{
			bytes = prevBytes;
			break;
		}

		cursor = cursor.mid(fIndex + chop, -1);
		bytes += fIndex + chop;

		prevBytes = bytes;
	}

	m_dataBuffer.remove(0, bytes);
	if (m_dataBuffer.size() > m_maxBufferSize)
		clearTempBuffer();

}

void Manager::clearTempBuffer()
{
	m_dataBuffer.clear();
}

void Manager::setDriver(HAL_Driver* driver)
{
	if (driver)
		connect(driver, &HAL_Driver::configurationChanged, this, &Manager::configurationChanged);

	m_driver = driver;

	emit driverChanged();
	emit configurationChanged();
}

void Manager::onDataReceived(const QByteArray& data)
{
	if (m_driver == Q_NULLPTR)
		disconnectDriver();

	auto bytes = data.length();

	m_dataBuffer.append(data);
	readFrames();
	
	m_receivedBytes += bytes;
	if (m_receivedBytes >= UINT64_MAX)
		m_receivedBytes = 0;

	emit receivedBytesChanged();
	emit dataReceived(data);
}
