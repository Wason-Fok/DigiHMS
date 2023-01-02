/*
  ==============================================================================

    Serial.h
    Created: 2022/12/30 22:07:13
    Author:  Wason
    
  ==============================================================================
*/

#pragma once

#include "../HAL_Driver.h"
#include <QSerialPort>
#include <QSettings>

/// <summary>
/// 串口设备类
/// </summary>
class Serial  : public HAL_Driver
{
	Q_OBJECT

public:
	Q_PROPERTY(QString portName
			   READ PortName
			   NOTIFY portChanged)
	Q_PROPERTY(bool autoReconnect
			   READ AutoReconnect
			   NOTIFY autoReconnectChanged)
	Q_PROPERTY(quint8 portIndex
			   READ PortIndex
			   NOTIFY portIndexChanged)
	Q_PROPERTY(quint8 parityIndex
			   READ ParityIndex
			   WRITE setParity
			   NOTIFY parityChanged)
	Q_PROPERTY(quint8 dataBitsIndex
			   READ DataBitsIndex
			   WRITE setDataBits
			   NOTIFY dataBitsChanged)
	Q_PROPERTY(quint8 stopBitsIndex
			   READ StopBitsIndex
			   WRITE setStopBits
			   NOTIFY stopBitsChanged)
	Q_PROPERTY(quint8 flowControlIndex
			   READ FlowControlIndex
			   WRITE setFlowControl
			   NOTIFY flowControlChanged)
	Q_PROPERTY(qint32 baudRate
			   READ BaudRate
			   WRITE setBaudRate
			   NOTIFY baudRateChanged)
	Q_PROPERTY(QStringList portList
			   READ PortList
			   NOTIFY availablePortsChanged)
	Q_PROPERTY(QStringList baudRateList
			   READ BaudRateList
			   NOTIFY baudRateListChanged)
	Q_PROPERTY(QStringList parityList
			   READ ParityList
			   CONSTANT)
	Q_PROPERTY(QStringList dataBitsList
			   READ DataBitsList
			   CONSTANT)
	Q_PROPERTY(QStringList stopBitsList
			   READ StopBitsList
			   CONSTANT)
	Q_PROPERTY(QStringList flowControlList
			   READ FlowControlList
			   CONSTANT)

	/**
	*  只能通过 Instance() 获取 Serial 实例
	*/
private:
	/// <summary>
	/// 构造 Serial
	/// </summary>
	explicit Serial();
	Serial(Serial&&) = delete;
	Serial(const Serial&) = delete;
	Serial& operator=(Serial&&) = delete;
	Serial& operator=(const Serial&) = delete;
	/// <summary>
	/// 析构 Serial
	/// <para>关闭串口连接</para>
	/// </summary>
	virtual ~Serial();

public:
	/// <summary>
	/// 获取 Serial 单例
	/// </summary>
	/// <returns>Serial 实例</returns>
	static Serial& Instance();

	/**
	 * HAL_Driver 接口
	 */
public:
	/// <summary>
	/// 开启当前选择的串口设备
	/// </summary>
	/// <param name="mode">串口开启模式</param>
	/// <returns>开启结果</returns>
	bool Open(const QIODevice::OpenMode mode) override;
	/// <summary>
	/// 关闭当前串口连接
	/// </summary>
	void Close() override;
	/// <summary>
	/// 获取当前串口是否开启
	/// </summary>
	/// <returns>串口开启状态</returns>
	bool IsOpen() const override;
	/// <summary>
	/// 获取当前串口是否可读
	/// </summary>
	/// <returns>串口可读状态</returns>
	bool IsReadable() const override;
	/// <summary>
	/// 获取当前串口是否可写
	/// </summary>
	/// <returns>串口可写状态</returns>
	bool IsWritable() const override;
	/// <summary>
	/// 将数据写入到串口设备并返回成功写入的字节数量
	/// </summary>
	/// <param name="data">要写入的数据</param>
	/// <returns>成功写入的字节数量</returns>
	quint64 Write(const QByteArray& data) override;
	/// <summary>
	/// 当前串口是否完成配置
	/// </summary>
	/// <returns>串口配置状态</returns>
	bool ConfigurationOk() const override;

public:
	/// <summary>
	/// 获取当前串口名称
	/// </summary>
	/// <returns>串口名称</returns>
	QString PortName() const;
	/// <summary>
	/// 获取串口对象指针
	/// </summary>
	/// <returns>串口对象指针</returns>
	QSerialPort* Port() const;
	/// <summary>
	/// 获取是否开启自动重连
	/// </summary>
	/// <returns>自动重连开启状态</returns>
	bool AutoReconnect() const;
	
	/// <summary>
	/// 获取当前选择的串口设备索引
	/// </summary>
	/// <returns>窗口设备索引</returns>
	quint8 PortIndex() const;
	/// <summary>
	/// 获取当前选择的数据位选项索引
	/// </summary>
	/// <returns>数据位选项索引</returns>
	quint8 DataBitsIndex() const;
	/// <summary>
	/// 获取当前选择的奇偶校验选项索引
	/// </summary>
	/// <returns>奇偶校验选项索引</returns>
	quint8 ParityIndex() const;
	// quint8 DisplayMode() const;
	/// <summary>
	/// 获取当前选择的停止位选项索引
	/// </summary>
	/// <returns>停止位选项索引</returns>
	quint8 StopBitsIndex() const;
	/// <summary>
	/// 获取当前选择的流控制选项索引
	/// </summary>
	/// <returns>流控制选项索引</returns>
	quint8 FlowControlIndex() const;

	/// <summary>
	/// 获取当前选择的波特率
	/// </summary>
	/// <returns>当前选择的波特率</returns>
	qint32 BaudRate() const;
	/// <summary>
	/// 获取当前选择的数据位
	/// </summary>
	/// <returns>当前选择的数据位</returns>
	QSerialPort::DataBits DataBits() const;
	/// <summary>
	/// 获取当前选择的奇偶校验
	/// </summary>
	/// <returns>当前选择的奇偶校验</returns>
	QSerialPort::Parity Parity() const;
	/// <summary>
	/// 获取当前选择的停止位
	/// </summary>
	/// <returns>当前选择的停止位</returns>
	QSerialPort::StopBits StopBits() const;
	/// <summary>
	/// 获取当前选择的流控制
	/// </summary>
	/// <returns>当前选择的流控制</returns>
	QSerialPort::FlowControl FlowControl() const;

	/// <summary>
	/// 获取有效串口设备文本列表
	/// <para>为方便 UI 操作，第一项为 选择串口 无效选项</para>
	/// </summary>
	/// <returns>有效串口设备列表</returns>
	QStringList PortList() const;
	/// <summary>
	/// 获取波特率选项文本列表
	/// </summary>
	/// <returns>波特率选项文本列表</returns>
	QStringList BaudRateList() const;
	/// <summary>
	/// 获取数据为选项文本列表
	/// </summary>
	/// <returns>数据为选项文本列表</returns>
	QStringList DataBitsList() const;
	/// <summary>
	/// 获取奇偶校验选项文本列表
	/// </summary>
	/// <returns>奇偶校验选项本列表</returns>
	QStringList ParityList() const;
	/// <summary>
	/// 获取停止位选项文本列表
	/// </summary>
	/// <returns>停止位选项文本列表</returns>
	QStringList StopBitsList() const;
	/// <summary>
	/// 获取流控制选项文本列表
	/// </summary>
	/// <returns>流控制选项文本列表</returns>
	QStringList FlowControlList() const;

private:
	/// <summary>
	/// 获取所有有效串口设备
	/// </summary>
	/// <returns>串口设备信息列表</returns>
	QVector<QSerialPortInfo> ValidPorts() const;

signals:
	void portChanged();
	void parityChanged();
	void baudRateChanged();
	void dataBitsChanged();
	void stopBitsChanged();
	void portIndexChanged();
	void flowControlChanged();
	void baudRateListChanged();
	void autoReconnectChanged();
	void baudRateIndexChanged();
	void availablePortsChanged();
	void connectionError(const QString& name);

public slots:
	/// <summary>
	/// 断开当前串口设备连接并释放指针
	/// </summary>
	void disconnectDevice();
	/// <summary>
	/// 更改当前串口设备索引值
	/// <para>该索引值稍后会在 <c>Serial::Open()</c> 中用到</para>
	/// </summary>
	/// <param name="portIndex">串口设备索引</param>
	void setPortIndex(const quint8 portIndex);
	/// <summary>
	/// 设置串口波特率
	/// </summary>
	/// <param name="rate">波特率</param>
	void setBaudRate(const qint32 rate);
	/// <summary>
	/// 设置串口数据位
	/// </summary>
	/// <param name="dataBitsIndex">数据为选项索引</param>
	void setDataBits(const quint8 dataBitsIndex);
	/// <summary>
	/// 设置串口奇偶校验
	/// </summary>
	/// <param name="parityIndex">奇偶校验选项索引</param>
	void setParity(const quint8 parityIndex);
	/// <summary>
	/// 设置串口停止位
	/// </summary>
	/// <param name="stopBitsIndex">停止位选项索引</param>
	void setStopBits(const quint8 stopBitsIndex);
	/// <summary>
	/// 设置串口流控制
	/// </summary>
	/// <param name="flowControlIndex">流控制选项索引</param>
	void setFlowControl(const quint8 flowControlIndex);
	/// <summary>
	/// 设置串口自动重连开启状态
	/// </summary>
	/// <param name="autoreconnect">是否开启</param>
	void setAutoReconnect(const bool autoreconnect);
	/// <summary>
	/// 添加新的波特率到列表中
	/// </summary>
	/// <param name="baudRate">波特率</param>
	void appendBaudRate(const QString& baudRate);

private slots:
	/// <summary>
	/// 获取串口读取到的全部数据
	/// <para>并触发信号</para>
	/// </summary>
	void onReadyRead();
	/// <summary>
	/// 从注册表中读取设置
	/// </summary>
	void readSettings();
	/// <summary>
	/// 将设置写入到注册表中
	/// </summary>
	void writeSettings();
	/// <summary>
	/// 扫描可用串口设备并生成新的列表
	/// </summary>
	void refreshSerialDevices();
	/// <summary>
	/// 串口连接错误回调函数
	/// </summary>
	/// <param name="error">错误信息</param>
	void handleError(QSerialPort::SerialPortError error);

private:
	/// <summary>
	/// 串口设备对象指针
	/// </summary>
	QSerialPort* m_port;

	/// <summary>
	/// 串口自动重连开启状态
	/// </summary>
	bool m_autoReconnect;
	qint32 m_lastSerialDeviceIndex;
	QSettings m_settings;

	qint32 m_baudRate;
	QSerialPort::Parity m_parity;
	QSerialPort::DataBits m_dataBits;
	QSerialPort::StopBits m_stopBits;
	QSerialPort::FlowControl m_flowControl;

	/// <summary>
	/// 当前选择的串口设备索引
	/// </summary>
	quint8 m_portIndex;
	quint8 m_parityIndex;
	quint8 m_dataBitsIndex;
	quint8 m_stopBitsIndex;
	quint8 m_flowControlIndex;

	QStringList m_portList;
	QStringList m_baudRateList;
};
