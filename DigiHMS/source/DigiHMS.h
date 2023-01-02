#pragma once

#include <QObject>

class TrayIcon;

class DigiHMS : public QObject
{
	Q_OBJECT

public:
	DigiHMS();
	virtual ~DigiHMS();
	
public slots:
	void Test() {};

private:
	TrayIcon* m_trayIcon;
};