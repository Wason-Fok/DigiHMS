#pragma once

#include <QObject>
#include <QMessageBox>

class Utilities  : public QObject
{
	Q_OBJECT

public:
	Utilities() {}
	virtual ~Utilities() {}

public:
	static Utilities& Instance();
	static void RebootApplication();
	Q_INVOKABLE bool AskAutomaticUpdates();
	static qint32 ShowMessageBox(const QString& text,
		const QString& informativeText = "",
		const QString& windowTitle = "",
		const QMessageBox::StandardButtons& bt = QMessageBox::Ok);

public slots:
	static void AboutQt();
	static void RevealFile(const QString& pathToReveal);
};
