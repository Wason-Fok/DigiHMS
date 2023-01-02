/*
  ==============================================================================

    Manager.h
    Created: 2022/12/31 11:06:57
    Author:  Wason
    
  ==============================================================================
*/

#pragma once

#include <QObject>
// #include <IO/HAL_Driver.h>

class HAL_Driver;

class Manager : public QObject
{
	Q_OBJECT

	Q_PROPERTY(bool readOnly
		READ ReadOnly
		NOTIFY connectedChanged)
	Q_PROPERTY(bool readWrite
		READ ReadWrite
		NOTIFY connectedChanged)
	Q_PROPERTY(bool connected
		READ Connected
		NOTIFY connectedChanged)
	Q_PROPERTY(bool deviceAvailable
		READ DeviceAvailable
		NOTIFY driverChanged)
	Q_PROPERTY(Manager::SelectedDriver selectedDriver
		READ GetSelectedDriver
		WRITE setSelectedDriver
		NOTIFY selectedDriverChanged)
	Q_PROPERTY(QString startSequence
		READ StartSequence
		WRITE setStartSequence
		NOTIFY startSequenceChanged)
	Q_PROPERTY(QString finishSequence
		READ FinishSequence
		WRITE setFinishSequence
		NOTIFY finishSequenceChanged)
	Q_PROPERTY(QString separatorSequence
		READ SeparatorSequence
		WRITE setSeparatorSequence
		NOTIFY separatorSequenceChanged)
	Q_PROPERTY(bool configurationOk
		READ ConfigurationOk
		NOTIFY configurationChanged)

	/**
	*  只能通过 Instance() 获取 Manager 实例
	*/
private:
	/// <summary>
	/// 构造 Manager
	/// </summary>
	explicit Manager();
	Manager(Manager&&) = delete;
	Manager(const Manager&) = delete;
	Manager& operator=(Manager&&) = delete;
	Manager& operator=(const Manager&) = delete;

public:
	enum class SelectedDriver
	{
		Serial
	};
	Q_ENUM(SelectedDriver)

	enum class ValidationStatus
	{
		FrameOk,
		ChecksumError,
		ChecksumIncomplete
	};
	Q_ENUM(ValidationStatus)

	/// <summary>
	/// 获取 Manager 单例
	/// </summary>
	/// <returns>Manager 实例</returns>
	static Manager& Instance();

	/// <summary>
	/// 获取设备已连接且是否为只读模式
	/// </summary>
	/// <returns>只读模式状态</returns>
	bool ReadOnly();
	/// <summary>
	/// 获取设备已连接且是否为读写模式
	/// </summary>
	/// <returns>读写模式状态</returns>
	bool ReadWrite();
	/// <summary>
	/// 获取设备是否连接
	/// </summary>
	/// <returns>连接状态</returns>
	bool Connected();
	/// <summary>
	/// 获取当前是否已选择设备
	/// </summary>
	/// <returns>选择状态</returns>
	bool DeviceAvailable();
	/// <summary>
	/// 获取设备是否配置完成
	/// </summary>
	/// <returns>配置完成状态</returns>
	bool ConfigurationOk();
	/// <summary>
	/// 获取缓冲区最大尺寸
	/// </summary>
	/// <returns>缓冲区最大尺寸</returns>
	qint32 MaxBufferSize() const;
	/// <summary>
	/// 获取当前使用的设备指针
	/// </summary>
	/// <returns>设备指针</returns>
	HAL_Driver* Driver();
	/// <summary>
	/// 获取当前选择的设备类型
	/// <para>Serial</para>
	/// </summary>
	/// <returns>设备类型</returns>
	SelectedDriver GetSelectedDriver();
	/// <summary>
	/// 获取设备类型字符串列表
	/// </summary>
	/// <returns>设备类型字符串列表</returns>
	Q_INVOKABLE QStringList AvailableDrivers() const;
	/// <summary>
	/// 将数据写入到当前使用的设备中
	/// </summary>
	/// <param name="data">要写入的数据</param>
	/// <returns>成功写入数据数量</returns>
	Q_INVOKABLE qint64 WriteData(const QByteArray& data);

	QString StartSequence() const;

	QString FinishSequence() const;

	QString SeparatorSequence() const;

private:
	ValidationStatus IntegrityChecks(const QByteArray& frame, const QByteArray& cursor, qint32* bytes);

signals:
	void driverChanged();
	void connectedChanged();
	void writeEnabledChanged();
	void configurationChanged();
	void receivedBytesChanged();
	void maxBufferSizeChanged();
	void startSequenceChanged();
	void finishSequenceChanged();
	void selectedDriverChanged();
	void separatorSequenceChanged();
	void frameValidationRegexChanged();
	void dataSent(const QByteArray& data);
	void dataReceived(const QByteArray& data);
	void frameReceived(const QByteArray& frame);

public slots:
	/// <summary>
	/// 关闭当前连接打开新的设备连接
	/// </summary>
	void connectDevice();
	/// <summary>
	/// 断开当前设备连接
	/// </summary>
	void disconnectDriver();
	/// <summary>
	/// 切换设备连接状态
	/// </summary>
	void toggleConnection();
	/// <summary>
	/// 设置设备是否允许写入
	/// </summary>
	/// <param name="enabled">是否允许写入</param>
	void setWriteEnable(const bool enabled);
	/// <summary>
	/// 模拟设备接收到数据
	/// <para>为了方便调试</para>
	/// </summary>
	/// <param name="payload">模拟数据</param>
	void processPayload(const QByteArray& payload);
	/// <summary>
	/// 设置缓冲区最大容量
	/// </summary>
	/// <param name="maxBufferSize">缓冲区大小</param>
	void setMaxBufferSize(const qint32 maxBufferSize);
	/// <summary>
	/// 设置通讯设备类型
	/// </summary>
	/// <param name="driver">设备类型</param>
	void setSelectedDriver(const Manager::SelectedDriver& driver);

	void setStartSequence(const QString& sequence);

	void setFinishSequence(const QString& sequence);

	void setSeparatorSequence(const QString& sequence);

private slots:
	void readFrames();
	/// <summary>
	/// 清空缓冲区内容
	/// </summary>
	void clearTempBuffer();
	/// <summary>
	/// 设置通讯设备
	/// </summary>
	/// <param name="driver">设备指针</param>
	void setDriver(HAL_Driver* driver);
	/// <summary>
	/// 设备接收到数据时回调函数
	/// </summary>
	/// <param name="data">接收到的数据</param>
	void onDataReceived(const QByteArray& data);

private:
	bool m_writeEnabled;
	qint32 m_maxBufferSize;
	HAL_Driver* m_driver;

	bool m_enableCrc;
	QString m_startSequence;
	QString m_finishSequence;
	QString m_separatorSequence;

	QByteArray m_dataBuffer;
	quint64 m_receivedBytes;

	SelectedDriver m_selectedDriver;
};
