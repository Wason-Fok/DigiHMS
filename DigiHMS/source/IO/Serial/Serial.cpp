#include "Serial.h"
#include <QSerialPortInfo>
#include <Common\TimerEvents.h>
#include <Common\Utilities.h>
#include <IO\Manager\Manager.h>

#define SETTINGS_BAUDRATELIST "IO_Serial_BauRates"

Serial::Serial()
	: m_port(Q_NULLPTR)
	, m_autoReconnect(false)
	, m_lastSerialDeviceIndex(0)
	, m_portIndex(0)
{
	readSettings();

	disconnectDevice();

	// 初始化串口参数配置
	setBaudRate(115200);
	setDataBits(DataBitsList().indexOf("8"));
	setStopBits(StopBitsList().indexOf("1"));
	setParity(ParityList().indexOf(tr("None")));
	setFlowControl(FlowControlList().indexOf(tr("None")));

	// 每秒更新一次串口设备列表
	connect(&TimerEvents::Instance(), &TimerEvents::timeout1Hz, this, &Serial::refreshSerialDevices);

	// 当选择新的串口时 通知配置更改
	connect(this, &Serial::portIndexChanged, this, &Serial::configurationChanged);

}

Serial::~Serial()
{
	writeSettings();

	if (m_port)
		m_port->disconnect();
}

Serial& Serial::Instance()
{
	static Serial singleton;
	return singleton;
}

bool Serial::Open(const QIODevice::OpenMode mode)
{
	// 获取当前有效的串口列表
	auto ports = ValidPorts();
	// 忽略列表第一项 （第一项为 选择串口 选项）
	auto portId = m_portIndex - 1;

	if (portId >= 0 && portId < ports.count())
	{
		// 断开当前串口连接 更新当前选择的串口设备索引
		disconnectDevice();
		m_portIndex = portId + 1;
		m_lastSerialDeviceIndex = m_portIndex;
		emit portIndexChanged();

		// 创建新的串口设备对象
		m_port = new QSerialPort(ports.at(portId));

		// 配置串口参数
		m_port->setParity(m_parity);
		m_port->setBaudRate(m_baudRate);
		m_port->setDataBits(m_dataBits);
		m_port->setStopBits(m_stopBits);
		m_port->setFlowControl(m_flowControl);

		// 绑定串口错误信号
		connect(m_port, &QSerialPort::errorOccurred, this, &Serial::handleError);
		
		// 开启串口
		if (m_port->open(mode))
		{
			// 绑定串口准备读取信号
			connect(m_port, &QIODevice::readyRead, this, &Serial::onReadyRead);
			return true;
		}
	}

	disconnectDevice();
	return false;
}

void Serial::Close()
{
	if (IsOpen())
		m_port->close();
}

bool Serial::IsOpen() const
{
	if (m_port)
		return m_port->isOpen();
	
	return false;
}

bool Serial::IsReadable() const
{
	if (IsOpen())
		return m_port->isReadable();

	return false;
}

bool Serial::IsWritable() const
{
	if (IsOpen())
		return m_port->isWritable();
	
	return false;
}

quint64 Serial::Write(const QByteArray& data)
{
	if (IsWritable())
		return m_port->write(data);

	return -1;
}

bool Serial::ConfigurationOk() const
{
	return m_portIndex > 0;
}

QString Serial::PortName() const
{
	if (m_port)
		return m_port->portName();

	return tr("No Device");
}

QSerialPort* Serial::Port() const
{
	return m_port;
}

bool Serial::AutoReconnect() const
{
	return m_autoReconnect;
}

quint8 Serial::PortIndex() const
{
	return m_portIndex;
}

quint8 Serial::DataBitsIndex() const
{
	return m_dataBitsIndex;
}

quint8 Serial::ParityIndex() const
{
	return m_portIndex;
}

quint8 Serial::StopBitsIndex() const
{
	return m_stopBitsIndex;
}

quint8 Serial::FlowControlIndex() const
{
	return m_flowControlIndex;
}

qint32 Serial::BaudRate() const
{
	return m_baudRate;
}

QSerialPort::Parity Serial::Parity() const
{
	return m_parity;
}

QSerialPort::DataBits Serial::DataBits() const
{
	return m_dataBits;
}

QSerialPort::StopBits Serial::StopBits() const
{
	return m_stopBits;
}

QSerialPort::FlowControl Serial::FlowControl() const
{
	return m_flowControl;
}

QStringList Serial::PortList() const
{
	return m_portList;
}

QStringList Serial::BaudRateList() const
{
	return m_baudRateList;
}

QStringList Serial::DataBitsList() const
{
	return QStringList{ "5", "6", "7", "8" };
}

QStringList Serial::ParityList() const
{
	QStringList list;
	list.append(tr("None"));
	list.append(tr("Even"));
	list.append(tr("Odd"));
	list.append(tr("Space"));
	list.append(tr("Mark"));
	return list;
}

QStringList Serial::StopBitsList() const
{
	return QStringList{ "1", "1.5", "2" };
}

QStringList Serial::FlowControlList() const
{
	QStringList list;
	list.append(tr("None"));
	list.append("RTS/CTS");
	list.append("XON/XOFF");
	return list;
}

QVector<QSerialPortInfo> Serial::ValidPorts() const
{
	QVector<QSerialPortInfo> ports;
	Q_FOREACH(QSerialPortInfo info, QSerialPortInfo::availablePorts())
	{
		if (!info.isNull())
		{
#ifdef Q_OS_MACOS
			if (info.portName().toLower().startsWith("tty."))
				continue;
#endif
			// 添加串口信息到列表中
			ports.append(info);
		}
	}

	return ports;
}

void Serial::disconnectDevice()
{
	if (m_port != Q_NULLPTR)
	{
		// 解除串口绑定的槽
		m_port->disconnect(this, SLOT(onReadyRead()));
		m_port->disconnect(this, SLOT(handleError(QSerialPort::SerialPortError)));

		// 关闭串口并释放指针
		m_port->close();
		m_port->deleteLater();
	}

	m_port = Q_NULLPTR;
	emit portChanged();
	emit availablePortsChanged();
}

void Serial::setPortIndex(const quint8 portIndex)
{
	auto portId = portIndex - 1;
	if (portId >= 0 && portId < ValidPorts().count())
		m_portIndex = portIndex;
	else
		m_portIndex = 0;

	emit portIndexChanged();
}

void Serial::setBaudRate(const qint32 rate)
{
	// 参数验证
	Q_ASSERT(rate > 10);

	// 更新波特率
	m_baudRate = rate;

	// 设置串口波特率
	if (m_port)
		m_port->setBaudRate(m_baudRate);

	emit baudRateChanged();
}

void Serial::setDataBits(const quint8 dataBitsIndex)
{
	// 参数验证
	Q_ASSERT(dataBitsIndex < DataBitsList().count());

	// 更新数据位选项索引
	m_dataBitsIndex = dataBitsIndex;

	// 根据索引获取选项
	switch (dataBitsIndex)
	{
	case 0:
		m_dataBits = QSerialPort::Data5;
		break;
	case 1:
		m_dataBits = QSerialPort::Data6;
		break;
	case 2:
		m_dataBits = QSerialPort::Data7;
		break;
	case 3:
		m_dataBits = QSerialPort::Data8;
		break;
	}

	// 更新串口设置
	if (m_port)
		m_port->setDataBits(m_dataBits);

	emit dataBitsChanged();
}

void Serial::setParity(const quint8 parityIndex)
{
	// 参数验证
	Q_ASSERT(parityIndex < ParityList().count());

	// 更新奇偶校验选项索引
	m_parityIndex = parityIndex;

	// 根据索引获取选项
	switch (parityIndex)
	{
	case 0:
		m_parity = QSerialPort::NoParity;
		break;
	case 1:
		m_parity = QSerialPort::EvenParity;
		break;
	case 2:
		m_parity = QSerialPort::OddParity;
		break;
	case 3:
		m_parity = QSerialPort::SpaceParity;
		break;
	case 4:
		m_parity = QSerialPort::MarkParity;
		break;
	}

	// 更新串口设置
	if (m_port)
		m_port->setParity(m_parity);

	emit parityChanged();
}

void Serial::setStopBits(const quint8 stopBitsIndex)
{
	// 参数验证
	Q_ASSERT(stopBitsIndex < StopBitsList().count());

	// 更新停止位选项索引
	m_stopBitsIndex = stopBitsIndex;

	// 根据索引获取选项
	switch (stopBitsIndex)
	{
	case 0:
		m_stopBits = QSerialPort::OneStop;
		break;
	case 1:
		m_stopBits = QSerialPort::OneAndHalfStop;
		break;
	case 2:
		m_stopBits = QSerialPort::TwoStop;
		break;
	}

	// 更新串口设置
	if (m_port)
		m_port->setStopBits(m_stopBits);

	emit stopBitsChanged();
}

void Serial::setFlowControl(const quint8 flowControlIndex)
{
	// 参数验证
	Q_ASSERT(flowControlIndex < FlowControlList().count());

	// 更新流控制选项索引
	m_flowControlIndex = flowControlIndex;

	// 根据索引获取选项
	switch (flowControlIndex)
	{
	case 0:
		m_flowControl = QSerialPort::NoFlowControl;
		break;
	case 1:
		m_flowControl = QSerialPort::HardwareControl;
		break;
	case 2:
		m_flowControl = QSerialPort::SoftwareControl;
		break;
	}
	
	// 更新串口设置
	if (m_port)
		m_port->setFlowControl(m_flowControl);

	emit flowControlChanged();
}

void Serial::setAutoReconnect(const bool autoreconnect)
{
	m_autoReconnect = autoreconnect;
	emit autoReconnectChanged();
}

void Serial::appendBaudRate(const QString& baudRate)
{
	if (!m_baudRateList.contains(baudRate))
	{
		m_baudRateList.append(baudRate);
		writeSettings();
		emit baudRateListChanged();

		// 弹出消息框
		Utilities::ShowMessageBox(tr("Baud rate registered successfully"),
			tr("Rate \"%1\" has been added to baud rate list").arg(baudRate));
	}
}

void Serial::onReadyRead()
{
	if (IsOpen())
		emit dataReceived(m_port->readAll());
}

void Serial::readSettings()
{
	// 默认波特率列表
	QStringList stdBaudRates{
		"300",   "1200",   "2400",   "4800",   "9600",   "19200",   "38400",  "57600",
		"74880", "115200", "230400", "250000", "500000", "1000000", "2000000"
	};

	// 从注册表读取 波特率列表
	QStringList list = m_settings.value(SETTINGS_BAUDRATELIST, stdBaudRates).toStringList();

	// 更新波特率列表
	m_baudRateList.clear();
	m_baudRateList.append(stdBaudRates);

	// 重新排序
	for (auto i = 0; i < m_baudRateList.count() - 1; i++)
	{
		for (auto j = 0; j < m_baudRateList.count() - i - 1; j++)
		{
			auto a = m_baudRateList.at(j).toInt();
			auto b = m_baudRateList.at(j + 1).toInt();
			if (a > b)
				m_baudRateList.swapItemsAt(j, j + 1);
		}
	}

	emit baudRateListChanged();

}

void Serial::writeSettings()
{
	// 重新排序
	for (auto i = 0; i < m_baudRateList.count() - 1; i++)
	{
		for (auto j = 0; j < m_baudRateList.count() - i - 1; j++)
		{
			auto a = m_baudRateList.at(j).toInt();
			auto b = m_baudRateList.at(j + 1).toInt();
			if (a > b)
			{
				m_baudRateList.swapItemsAt(j, j + 1);
				emit baudRateListChanged();
			}
			
		}
	}

	m_settings.setValue(SETTINGS_BAUDRATELIST, m_baudRateList);
}

void Serial::refreshSerialDevices()
{
	// 创建串口列表
	// 第一个元素位无效项（为了方便 UI 操作）
	QStringList ports;
	ports.append(tr("Select port"));

	// 获取有效串口列表
	auto validPortList = ValidPorts();
	Q_FOREACH(QSerialPortInfo info, validPortList)
	{
		if (!info.isNull())
			ports.append(info.portName());
	}

	// 只有新的列表现有不同时才进行更新
	if (m_portList != ports)
	{
		// 更新串口设备列表
		m_portList = ports;

		if (m_port)
		{
			// 获取当前连接的串口
			auto name = m_port->portName();
			for (qint32 i = 0; i < validPortList.count(); i++)
			{
				// 如果当前连接的串口包含在 新的有效串口列表中 则更新当前连接串口设备索引
				auto info = validPortList.at(i);
				if (info.portName() == name)
				{
					m_portIndex = i + 1;
					break;
				}
			}
		}

		// 如果当前选择的设备为串口 则检查是否需要自动重连
		if (Manager::Instance().GetSelectedDriver() == Manager::SelectedDriver::Serial)
		{
			if (m_autoReconnect && m_lastSerialDeviceIndex > 0)
			{
				if (m_lastSerialDeviceIndex < m_portList.count())
				{
					setPortIndex(m_lastSerialDeviceIndex);
					Manager::Instance().connectDevice();
				}
			}
		}

		emit availablePortsChanged();
	}
}

void Serial::handleError(QSerialPort::SerialPortError error)
{
	if (error != QSerialPort::NoError)
		Manager::Instance().disconnectDriver();
}

