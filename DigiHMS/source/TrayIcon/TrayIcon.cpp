#include "TrayIcon.h"
#include <QScreen>
#include <QApplication>
#include <QMenu>
#include <QSvgRenderer>
#include <QPainter>

TrayIcon::TrayIcon(QObject *parent)
	: QObject(parent)
	, m_Parent(parent)
{
	Init();
}

TrayIcon::~TrayIcon()
{
	if (m_Menu)
		delete m_Menu;
}

void TrayIcon::AddAction(const QString& text, QObject* receiver, const char* member)
{
	m_Menu->addAction(text, receiver, member);
}

void TrayIcon::AddSeparator()
{
	m_Menu->addSeparator();
}

void TrayIcon::SetIcon(QIcon& icon)
{
	if (!icon.isNull())
	{
		m_TrayIcon->setIcon(icon);
	}
}

void TrayIcon::ShowMessage(const QString& message)
{
	m_TrayIcon->showMessage(tr("DigiHMS Notification"), message);
}

void TrayIcon::onTrayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
	if (reason == QSystemTrayIcon::DoubleClick)
	{
		QWidget* widget = qobject_cast<QWidget*>(m_Parent);
		if (widget)
		{
			widget->show();
			widget->activateWindow();
		}
	}
}

void TrayIcon::Init()
{
	m_Menu = new QMenu(nullptr);

	m_TrayIcon = new QSystemTrayIcon(this);
	m_TrayIcon->setContextMenu(m_Menu);
	m_TrayIcon->setToolTip(tr("DigiHMS"));
	m_TrayIcon->show();

	QRect rect = m_TrayIcon->geometry();

	QScreen* screen = QApplication::primaryScreen();

	qint32 minSize = qMin(rect.width(), rect.height());
	minSize = minSize ? minSize : 48;
	minSize *= screen->devicePixelRatio();

	QPixmap pixmap(minSize, minSize);
	pixmap.fill(Qt::transparent);

	QSvgRenderer renderer(QString(":/DigiHMS/icons/TestSvg.svg"));
	QPainter painter(&pixmap);
	renderer.render(&painter);

	QIcon icon(pixmap);
	icon.setIsMask(true);
	m_TrayIcon->setIcon(icon);

	connect(m_TrayIcon, &QSystemTrayIcon::activated, this, &TrayIcon::onTrayIconActivated);
}
