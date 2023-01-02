#pragma once

#include "LibreHardwareMonitorApi.h"
#include "UpdateVisitor.h"
#include <map>

#ifdef _DEBUG
#using ".\lib\Debug\LibreHardwareMonitorLib.dll"
#else
#using ".\lib\Release\LibreHardwareMonitorLib.dll"
#endif

using namespace System;
using namespace LibreHardwareMonitor::Hardware;

namespace LibreHardwareMonitorApi
{
	public class CLibreHardwareMonitor : public ILibreHardwareMonitor
	{
	public:
		CLibreHardwareMonitor();
		virtual ~CLibreHardwareMonitor();

	public:
		virtual void GetHardwareInfo() override;

		virtual std::wstring& GetMainboardName() override;
		virtual float GetMainboardTemperature() override;
		virtual std::map<std::wstring, float>& GetMainboardFanSpeed() override;
		
		virtual std::wstring& GetCpuName() override;
		virtual float GetCpuTemperature() override;									// °C
		virtual float GetCpuPower() override;										// W
		virtual std::map<std::wstring, float>& GetAllCpuTemperature() override;
		virtual float GetCpuClock() override;										// MHz
		virtual float GetCpuLoad() override;										// %
		virtual std::map<std::wstring, float>& GetAllCpuLoad() override;

		virtual std::wstring& GetMemoryName() override;
		virtual float GetMemoryLoad() override;										// %
		virtual float GetMemoryUsed() override;										// GB = 2^30 Bytes
		virtual float GetMemoryAvailable() override;								// GB = 2^30 Bytes

		virtual std::wstring& GetGpuName() override;
		virtual float GetGpuTemperature() override;									// °C
		virtual float GetGpuPower() override;										// W
		virtual float GetGpuLoad() override;										// %
		virtual float GetGpuFanSpeed() override;									// RPM

		virtual std::map<std::wstring, float>& GetAllStorageTemperature() override;
		virtual std::map<std::wstring, std::pair<float, float>>& GetAllStorageReadWriteSpeed() override;	// B/s

		virtual std::map<std::wstring, std::pair<float, float>>& GetAllNetworkSpeed() override;				// B/s

		virtual bool SetFanSpeed(const std::wstring& name, float percent) override;

		virtual void SetMainboardEnable(bool enable) override;
		virtual void SetCpuEnable(bool enable) override;
		virtual void SetMemoryEnable(bool enable);
		virtual void SetGpuEnable(bool enable) override;
		virtual void SetStorageEnable(bool enable) override;
		virtual void SetNetworkEnable(bool enable);

	private:
		void ResetAllValues();
		/// <summary>
		/// 计算 map 中所有 Value 的平均值
		/// </summary>
		/// <param name="map">std::map 对象</param>
		/// <returns>平均值</returns>
		float CalculateAverage(std::map<std::wstring, float>& map);
		bool GetHardwareName(IHardware^ hardware, std::wstring& name);
		bool GetSensorValue(IHardware^ hardware, SensorType^ type, String^ name, float& value);
		bool InsertValue2Map(std::map<std::wstring, float>& map, const std::wstring& key, float value);
		bool InsertValue2Map(std::map<std::wstring, std::pair<float, float>>& map, const std::wstring& key, std::pair<float, float>& value);

		bool MainboardTemperature(IHardware^ hardware, float& temperature);
		bool MainboardFanSpeed(IHardware^ hardware);

		bool CpuTemperature(IHardware^ hardware, float& temperature);
		bool CpuPower(IHardware^ hardware, float& power);
		bool CpuClock(IHardware^ hardware, float& clock);
		bool CpuLoad(IHardware^ hardware, float& load);

		bool MemoryLoad(IHardware^ hardware, float& load, float& used, float& available);

		bool GpuTemperature(IHardware^ hardware, float& temperature);
		bool GpuPower(IHardware^ hardware, float& power);
		bool GpuLoad(IHardware^ hardware, float& load);
		bool GpuFanSpeed(IHardware^ hardware, float& speed);
		bool GpuMemoryLoad(IHardware^ hardware, float& used, float& free, float& total);

		bool StorageTemperature(IHardware^ hardware, float& temperature);
		bool StorageReadWriteSpeed(IHardware^ hardware, std::pair<float, float>& speed);

		bool NetworkSpeed(IHardware^ hardware, std::pair<float, float>& speed);

	private:
		std::wstring m_MainboardName{};
		float m_MainboardTemperature{};

		std::wstring m_CpuName{};
		float m_CpuTemperature{};
		float m_CpuPower{};
		float m_CpuClock{};
		float m_CpuLoad{};

		std::wstring m_MemoryName{};
		float m_MemoryLoad{};
		float m_MemoryUsed{};
		float m_MemoryAvailable{};

		std::wstring m_GpuName{};
		float m_GpuTemperature{};
		float m_GpuPower{};
		float m_GpuLoad{};
		float m_GpuFanSpeed{};
		float m_GpuMemoryUsed{};
		float m_GpuMemoryFree{};
		float m_GpuMemoryTotal{};

		std::map<std::wstring, float> m_AllMainboardTemperature;
		std::map<std::wstring, float> m_AllMainboardFanSpeed;

		std::map<std::wstring, float> m_AllCpuTemperature;
		std::map<std::wstring, float> m_AllCpuClock;
		std::map<std::wstring, float> m_AllCpuLoad;

		std::map<std::wstring, float> m_AllStorageTemperature;
		std::map<std::wstring, std::pair<float, float>> m_AllStorageReadWriteSpeed;
		
		std::map<std::wstring, std::pair<float, float>> m_AllNetworkSpeed;

	};

	public ref class MonitorGlobal
	{
	public:
		MonitorGlobal() {};
		~MonitorGlobal() {};

	public:
		static MonitorGlobal^ Instance()
		{
			if (m_Instance == nullptr)
			{
				m_Instance = gcnew MonitorGlobal();
			}
			return m_Instance;
		}

		void Init()
		{
			updateVisitor = gcnew UpdateVisitor();
			computer = gcnew Computer();
			computer->IsMotherboardEnabled = true;
			computer->IsCpuEnabled = true;
			computer->IsMemoryEnabled = true;
			computer->IsGpuEnabled = true;
			computer->IsStorageEnabled = true;
			computer->IsNetworkEnabled = true;
			computer->Open();
		}

		void UnInit()
		{
			computer->Close();
		}

		Computer^ computer;
		UpdateVisitor^ updateVisitor{};

	private:
		static MonitorGlobal^ m_Instance{};
	};
}