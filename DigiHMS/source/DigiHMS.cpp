#include "DigiHMS.h"
#include <TrayIcon/TrayIcon.h>

DigiHMS::DigiHMS()
{
	m_trayIcon = new TrayIcon(this);
	m_trayIcon->AddAction("COM1", this, SLOT(Test()));
}

DigiHMS::~DigiHMS()
{

}
