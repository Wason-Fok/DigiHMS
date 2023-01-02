#pragma once

#ifdef _DEBUG
#using ".\lib\Debug\LibreHardwareMonitorLib.dll"
#else
#using ".\lib\Release\LibreHardwareMonitorLib.dll"
#endif

using namespace LibreHardwareMonitor::Hardware;

namespace LibreHardwareMonitorApi
{
	public ref class UpdateVisitor : IVisitor
	{
	public:
		virtual void VisitComputer(IComputer^ computer);
		virtual void VisitHardware(IHardware^ hardware);
		virtual void VisitSensor(ISensor^ sensor);
		virtual void VisitParameter(IParameter^ parameter);
	};
}