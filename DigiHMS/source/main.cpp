#include <QApplication>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "Common/Utilities.h"
#include "DigiHMS.h"


int32_t main(int32_t argc, char* argv[])
{
	QApplication a(argc, argv);

	Utilities::ShowMessageBox("Baud rate registered successfully",
		"Rate \"115200\" has been added to baud rate list");

	DigiHMS w;

	return a.exec();
}