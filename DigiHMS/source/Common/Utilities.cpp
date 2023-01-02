#include "Utilities.h"
#include <QApplication>
#include <QProcess>
#include <QFileInfo>
#include <QDir>
#include <QDesktopServices>
#include "AppInfo.h"

Utilities& Utilities::Instance()
{
	static Utilities singleton;
	return singleton;
}

void Utilities::RebootApplication()
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
	qApp->exit();
	QProcess::startDetached(qApp->arguments().first(), qApp->arguments());
#else
	#ifdef Q_OS_MAC
	auto bundle = qApp->applicationDirPath() + "/../../";
	QProcess::startDetached("open", { "-n", "-a", bundle });
	#else
	QProcess::startDetached(qApp->arguments().first(), qApp->arguments());
	#endif
	qApp->exit();
#endif
}

Q_INVOKABLE bool Utilities::AskAutomaticUpdates()
{
	const int result = ShowMessageBox(tr("Check for updates automatically?"),
		tr("Should %1 automatically check for updates? "
			"You can always check for updates manually from "
			"the \"Help\" menu")
		.arg(APP_NAME),
		APP_NAME, QMessageBox::Yes | QMessageBox::No);
	return result == QMessageBox::Yes;
}

qint32 Utilities::ShowMessageBox(const QString& text, const QString& informativeText /*= ""*/, const QString& windowTitle /*= ""*/, const QMessageBox::StandardButtons& bt /*= QMessageBox::Ok*/)
{
	QPixmap icon;
	if (qApp->devicePixelRatio() >= 2)
		icon.load(":/DigiHMS/icons/TestIcon.ico");
	else
		icon.load(":/DigiHMS/icons/TestIcon.ico");

	QMessageBox box;
	box.setIconPixmap(icon);
	box.setStandardButtons(bt);
	box.setWindowTitle(windowTitle);
	box.setText("<h3>" + text + "</h3>");
	box.setInformativeText(informativeText);

	return box.exec();
}

void Utilities::AboutQt()
{
	qApp->aboutQt();
}

void Utilities::RevealFile(const QString& pathToReveal)
{
#if defined(Q_OS_WIN)
	QStringList param;
	const QFileInfo fileInfo(pathToReveal);
	if (!fileInfo.isDir())
		param += QLatin1String("/select,");
	param += QDir::toNativeSeparators(fileInfo.canonicalFilePath());
	QProcess::startDetached("explorer.exe", param);
#elif defined(Q_OS_MAC)
	QStringList scriptArgs;
	scriptArgs << QLatin1String("-e")
		<< QString::fromLatin1(
			"tell application \"Finder\" to reveal POSIX file \"%1\"")
		.arg(pathToReveal);
	QProcess::execute(QLatin1String("/usr/bin/osascript"), scriptArgs);
	scriptArgs.clear();
	scriptArgs << QLatin1String("-e")
		<< QLatin1String("tell application \"Finder\" to activate");
	QProcess::execute("/usr/bin/osascript", scriptArgs);
#else
	QDesktopServices::openUrl(QUrl::fromLocalFile(pathToReveal));
#endif
}

