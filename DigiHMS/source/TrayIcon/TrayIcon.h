#pragma once

#include <QObject>
#include <QSystemTrayIcon>

class TrayIcon  : public QObject
{
	Q_OBJECT

public:
	TrayIcon(QObject *parent);
	virtual ~TrayIcon();

public:
	virtual void AddAction(const QString& text, QObject* receiver, const char* member);
	virtual void AddSeparator();
	virtual void SetIcon(QIcon& icon);

public slots:
	virtual void ShowMessage(const QString& message);
	virtual void onTrayIconActivated(QSystemTrayIcon::ActivationReason reason);

private:
	void Init();

private:
	QObject* m_Parent;
	QSystemTrayIcon* m_TrayIcon;
	QMenu* m_Menu;
};
