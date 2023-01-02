#pragma once

#include "LibreHardwareMonitorGlobal.h"
#include <memory>
#include <string>
#include <map>

namespace LibreHardwareMonitorApi
{
	class ILibreHardwareMonitor
	{
	public:
		virtual void GetHardwareInfo() = 0;

		virtual std::wstring& GetMainboardName() = 0;
		/// <summary>
		/// 获取主板温度
		/// </summary>
		/// <returns></returns>
		virtual float GetMainboardTemperature() = 0;
		virtual std::map<std::wstring, float>& GetMainboardFanSpeed() = 0;

		virtual std::wstring& GetCpuName() = 0;
		virtual float GetCpuTemperature() = 0;
		virtual float GetCpuPower() = 0;
		virtual std::map<std::wstring, float>& GetAllCpuTemperature() = 0;
		virtual float GetCpuClock() = 0;
		virtual float GetCpuLoad() = 0;
		virtual std::map<std::wstring, float>& GetAllCpuLoad() = 0;

		virtual std::wstring& GetMemoryName() = 0;
		virtual float GetMemoryLoad() = 0;
		virtual float GetMemoryUsed() = 0;
		virtual float GetMemoryAvailable() = 0;

		virtual std::wstring& GetGpuName() = 0;
		virtual float GetGpuTemperature() = 0;
		virtual float GetGpuPower() = 0;
		virtual float GetGpuLoad() = 0;
		virtual float GetGpuFanSpeed() = 0;

		virtual std::map<std::wstring, float>& GetAllStorageTemperature() = 0;
		virtual std::map<std::wstring, std::pair<float, float>>& GetAllStorageReadWriteSpeed() = 0;

		virtual std::map<std::wstring, std::pair<float, float>>& GetAllNetworkSpeed() = 0;

		virtual bool SetFanSpeed(const std::wstring& name, float percent) = 0;

		virtual void SetMainboardEnable(bool enable) = 0;
		virtual void SetCpuEnable(bool enable) = 0;
		virtual void SetMemoryEnable(bool enable) = 0;
		virtual void SetGpuEnable(bool enable) = 0;
		virtual void SetStorageEnable(bool enable) = 0;
		virtual void SetNetworkEnable(bool enable) = 0;

	};

	LIBREHARDWAREMONITOR_API std::shared_ptr<ILibreHardwareMonitor> CreateInstance();
	LIBREHARDWAREMONITOR_API std::wstring GetErrorMessage();
}