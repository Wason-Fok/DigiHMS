/*
  ==============================================================================

    HAL_Driver.h
    Created: 2022/12/31 11:06:31
    Author:  Wason
    
  ==============================================================================
*/

#pragma once

#include <QObject>
#include <QIODevice>

class HAL_Driver : public QObject
{
	Q_OBJECT

signals:
	void configurationChanged();
	void dataSend(const QByteArray& data);
	void dataReceived(const QByteArray& data);

public:
	virtual bool Open(const QIODevice::OpenMode mode) = 0;
	virtual void Close() = 0;
	virtual bool IsOpen() const = 0;
	virtual bool IsReadable() const = 0;
	virtual bool IsWritable() const = 0;
	virtual quint64 Write(const QByteArray& data) = 0;
	virtual bool ConfigurationOk() const = 0;
};