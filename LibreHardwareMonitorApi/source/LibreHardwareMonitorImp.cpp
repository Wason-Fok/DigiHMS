#include "..\include\LibreHardwareMonitorImp.h"
#include <string>
#include <vector>

using namespace System::Text::RegularExpressions;

namespace LibreHardwareMonitorApi
{
	static std::wstring error_message;

	/// <summary>
	/// 将 CLR 的 String 类型转为 C++ 的 std::wstring 类型
	/// </summary>
	/// <param name="str">CLR String</param>
	/// <returns>转换后的 wstring</returns>
	static std::wstring ClrString2StdWstring(System::String^ str)
	{
		if (str == nullptr)
		{
			return std::wstring();
		}
		else
		{
			const wchar_t* chars = (const wchar_t*)(Runtime::InteropServices::Marshal::StringToHGlobalUni(str)).ToPointer();
			std::wstring os = chars;
			Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)chars));
			return os;
		}
	}

	static std::string ClrString2StdString(System::String^ str)
	{
		if (str == nullptr)
		{
			return std::string();
		}
		else
		{
			const char* chars = (const char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str)).ToPointer();
			std::string os = chars;
			Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)chars));
			return os;
		}
	}

	std::shared_ptr<ILibreHardwareMonitor> CreateInstance()
	{
		std::shared_ptr<ILibreHardwareMonitor> pMonitor;
		try
		{
			MonitorGlobal::Instance()->Init();
			pMonitor = std::make_shared<CLibreHardwareMonitor>();
		}
		catch (System::Exception^ e)
		{
			error_message = ClrString2StdWstring(e->Message);
		}

		return pMonitor;
	}

	std::wstring GetErrorMessage()
	{
		return error_message;
	}

	CLibreHardwareMonitor::CLibreHardwareMonitor()
	{
		ResetAllValues();
	}

	CLibreHardwareMonitor::~CLibreHardwareMonitor()
	{
		MonitorGlobal::Instance()->UnInit();
	}

	void CLibreHardwareMonitor::GetHardwareInfo()
	{
		ResetAllValues();
		error_message.clear();
		try 
		{
			auto computer = MonitorGlobal::Instance()->computer;
			computer->Accept(MonitorGlobal::Instance()->updateVisitor);
			
			for (int32_t i = 0; i < computer->Hardware->Count; i++)
			{
				switch (computer->Hardware[i]->HardwareType)
				{
				case HardwareType::Motherboard:
					if (m_MainboardName == L"")
						GetHardwareName(computer->Hardware[i], m_MainboardName);
					if (m_MainboardTemperature < 0)
						MainboardTemperature(computer->Hardware[i], m_MainboardTemperature);
					if (m_AllMainboardFanSpeed.empty())
						MainboardFanSpeed(computer->Hardware[i]);
					break;
				case HardwareType::Cpu:
					if (m_CpuName == L"")
						GetHardwareName(computer->Hardware[i], m_CpuName);
					if (m_CpuTemperature < 0)
						CpuTemperature(computer->Hardware[i], m_CpuTemperature);
					if (m_CpuPower < 0)
						CpuPower(computer->Hardware[i], m_CpuPower);
					if (m_CpuClock < 0)
						CpuClock(computer->Hardware[i], m_CpuClock);
					if (m_CpuLoad < 0)
						CpuLoad(computer->Hardware[i], m_CpuLoad);
					break;

				case HardwareType::Memory:
					if (m_MemoryName == L"")
						GetHardwareName(computer->Hardware[i], m_MemoryName);
					if (m_MemoryLoad < 0 || m_MemoryUsed < 0 || m_MemoryAvailable < 0)
						MemoryLoad(computer->Hardware[i], m_MemoryLoad, m_MemoryUsed, m_MemoryAvailable);
					break;
				case HardwareType::GpuNvidia:
				case HardwareType::GpuAmd:
				case HardwareType::GpuIntel:
					if (m_GpuName == L"")
						GetHardwareName(computer->Hardware[i], m_GpuName);
					if (m_GpuTemperature < 0)
						GpuTemperature(computer->Hardware[i], m_GpuTemperature);
					if (m_GpuPower < 0)
						GpuPower(computer->Hardware[i], m_GpuPower);
					if (m_GpuLoad < 0)
						GpuLoad(computer->Hardware[i], m_GpuLoad);
					if (m_GpuFanSpeed < 0)
						GpuFanSpeed(computer->Hardware[i], m_GpuFanSpeed);
					if (m_GpuMemoryUsed < 0 || m_GpuMemoryFree < 0 || m_GpuMemoryTotal < 0)
						GpuMemoryLoad(computer->Hardware[i], m_GpuMemoryUsed, m_GpuMemoryFree, m_GpuMemoryTotal);
					break;
				case HardwareType::Storage:
				{
					float temperature = -1;
					std::pair<float, float> readWriteSpeed = { -1.0, -1.0 };

					StorageTemperature(computer->Hardware[i], temperature);
					InsertValue2Map(m_AllStorageTemperature, ClrString2StdWstring(computer->Hardware[i]->Name), temperature);

					StorageReadWriteSpeed(computer->Hardware[i], readWriteSpeed);
					InsertValue2Map(m_AllStorageReadWriteSpeed, ClrString2StdWstring(computer->Hardware[i]->Name), readWriteSpeed);
					break;
				}
				case HardwareType::Network:
				{
					std::pair<float, float> speed = { -1.0, -1.0 };

					NetworkSpeed(computer->Hardware[i], speed);
					InsertValue2Map(m_AllNetworkSpeed, ClrString2StdWstring(computer->Hardware[i]->Name), speed);
					break;
				}
				default:
					break;
				}
			}
		}
		catch (System::Exception^ e)
		{
			error_message = ClrString2StdWstring(e->Message);
		}
	}

	std::wstring& CLibreHardwareMonitor::GetMainboardName()
	{
		return m_MainboardName;
	}

	float CLibreHardwareMonitor::GetMainboardTemperature()
	{
		return m_MainboardTemperature;
	}

	std::map<std::wstring, float>& CLibreHardwareMonitor::GetMainboardFanSpeed()
	{
		return m_AllMainboardFanSpeed;
	}

	std::wstring& CLibreHardwareMonitor::GetCpuName()
	{
		return m_CpuName;
	}

	float CLibreHardwareMonitor::GetCpuTemperature()
	{
		return m_CpuTemperature;
	}

	float CLibreHardwareMonitor::GetCpuPower()
	{
		return m_GpuPower;
	}

	std::map<std::wstring, float>& CLibreHardwareMonitor::GetAllCpuTemperature()
	{
		return m_AllCpuTemperature;
	}

	float CLibreHardwareMonitor::GetCpuClock()
	{
		return m_CpuClock;
	}

	float CLibreHardwareMonitor::GetCpuLoad()
	{
		return m_CpuLoad;
	}

	std::map<std::wstring, float>& CLibreHardwareMonitor::GetAllCpuLoad()
	{
		return m_AllCpuLoad;
	}

	std::wstring& CLibreHardwareMonitor::GetMemoryName()
	{
		return m_MemoryName;
	}

	float CLibreHardwareMonitor::GetMemoryLoad()
	{
		return m_MemoryLoad;
	}

	float CLibreHardwareMonitor::GetMemoryUsed()
	{
		return m_MemoryUsed;
	}

	float CLibreHardwareMonitor::GetMemoryAvailable()
	{
		return m_MemoryAvailable;
	}

	std::wstring& CLibreHardwareMonitor::GetGpuName()
	{
		return m_GpuName;
	}

	float CLibreHardwareMonitor::GetGpuTemperature()
	{
		return m_GpuTemperature;
	}

	float CLibreHardwareMonitor::GetGpuPower()
	{
		return m_GpuPower;
	}

	float CLibreHardwareMonitor::GetGpuLoad()
	{
		return m_GpuLoad;
	}

	float CLibreHardwareMonitor::GetGpuFanSpeed()
	{
		return m_GpuFanSpeed;
	}

	std::map<std::wstring, float>& CLibreHardwareMonitor::GetAllStorageTemperature()
	{
		return m_AllStorageTemperature;
	}

	std::map<std::wstring, std::pair<float, float>>& CLibreHardwareMonitor::GetAllStorageReadWriteSpeed()
	{
		return m_AllStorageReadWriteSpeed;
	}

	std::map<std::wstring, std::pair<float, float>>& CLibreHardwareMonitor::GetAllNetworkSpeed()
	{
		return m_AllNetworkSpeed;
	}

	bool CLibreHardwareMonitor::SetFanSpeed(const std::wstring& name, float percent)
	{
		auto computer = MonitorGlobal::Instance()->computer;
		String^ clrName = gcnew String(name.c_str());

		for (int32_t i = 0; i < computer->Hardware->Count; i++)
		{
			if (computer->Hardware[i]->SubHardware->Length > 0)
			{
				for (int32_t j = 0; j < computer->Hardware[i]->SubHardware->Length; j++)
				{
					auto subHardware = computer->Hardware[i]->SubHardware[j];
					for each (auto item in subHardware->Sensors)
					{
						if (item->SensorType == SensorType::Control && item->Name == clrName)
						{
							if (percent == -1)
							{
								item->Control->SetDefault();
								return true;
							}
							item->Control->SetSoftware(percent);
							return true;
						}
					}
				}
			}
			
			for each (auto item in computer->Hardware[i]->Sensors)
			{
				if (item->SensorType == SensorType::Control && item->Name == clrName)
				{
					if (percent == -1)
					{
						item->Control->SetDefault();
						return true;
					}
					item->Control->SetSoftware(percent);
					return true;
				}
			}
		}

		return false;
	}

	void CLibreHardwareMonitor::SetMainboardEnable(bool enable)
	{
		MonitorGlobal::Instance()->computer->IsMotherboardEnabled = enable;
	}

	void CLibreHardwareMonitor::SetCpuEnable(bool enable)
	{
		MonitorGlobal::Instance()->computer->IsCpuEnabled = enable;
	}

	void CLibreHardwareMonitor::SetMemoryEnable(bool enable)
	{
		MonitorGlobal::Instance()->computer->IsMemoryEnabled = enable;
	}

	void CLibreHardwareMonitor::SetGpuEnable(bool enable)
	{
		MonitorGlobal::Instance()->computer->IsGpuEnabled = enable;
	}

	void CLibreHardwareMonitor::SetStorageEnable(bool enable)
	{
		MonitorGlobal::Instance()->computer->IsStorageEnabled = enable;
	}

	void CLibreHardwareMonitor::SetNetworkEnable(bool enable)
	{
		MonitorGlobal::Instance()->computer->IsNetworkEnabled = enable;
	}

	void CLibreHardwareMonitor::ResetAllValues()
	{
		m_MainboardTemperature = -1;

		m_CpuTemperature = -1;
		m_CpuPower = -1;
		m_CpuClock = -1;
		m_CpuLoad = -1;

		m_MemoryLoad = -1;
		m_MemoryUsed = -1;
		m_MemoryAvailable = -1;

		m_GpuTemperature = -1;
		m_GpuPower = -1;
		m_GpuLoad = -1;
		m_GpuFanSpeed = -1;
		m_GpuMemoryUsed = -1;
		m_GpuMemoryFree = -1;
		m_GpuMemoryTotal = -1;

		m_AllMainboardTemperature.clear();
		m_AllMainboardFanSpeed.clear();

		m_AllCpuTemperature.clear();
		m_AllCpuClock.clear();
		m_AllCpuLoad.clear();

		m_AllStorageTemperature.clear();
		m_AllStorageReadWriteSpeed.clear();

		m_AllNetworkSpeed.clear();
	}

	float CLibreHardwareMonitor::CalculateAverage(std::map<std::wstring, float>& map)
	{
		if (!map.empty())
		{
			float sum{};
			for (const auto& item : map)
			{
				sum += item.second;
			}

			return sum / map.size();
		}

		return 0.f;
	}

	bool CLibreHardwareMonitor::GetHardwareName(IHardware^ hardware, std::wstring& name)
	{
		if (hardware->Name != L"")
		{
			name = ClrString2StdWstring(hardware->Name);
			return true;
		}

		return false;
	}

	bool CLibreHardwareMonitor::GetSensorValue(IHardware^ hardware, SensorType^ type, String^ name, float& value)
	{
		for (int32_t i = 0; i < hardware->Sensors->Length; i++)
		{
			if (hardware->Sensors[i]->SensorType.Equals(type))
			{
				if (name == L"")
				{
					value = Convert::ToDouble(hardware->Sensors[i]->Value);
					return true;
				}
				else if (hardware->Sensors[i]->Name == name)
				{
					value = Convert::ToDouble(hardware->Sensors[i]->Value);
					return true;
				}
			}
		}

		for (int32_t i = 0; i < hardware->SubHardware->Length; i++)
		{
			if (GetSensorValue(hardware->SubHardware[i], type, name, value))
				return true;
		}

		return false;

	}

	bool CLibreHardwareMonitor::InsertValue2Map(std::map<std::wstring, float>& map, const std::wstring& key, float value)
	{
		auto iter = map.find(key);

		// 如果 key 不在 map 中则新建
		if (iter == map.end())
		{
			map[key] = value;
			return true;
		}
		else
		{
			// 检查当前 key 是否包含 # 号
			std::wstring key_exist = iter->first;
			size_t index = key_exist.rfind(L'#');
			
			if (index != std::wstring::npos)
			{
				// 获取 # 号后数字并 +1
				int32_t num = _wtoi(key_exist.substr(index + 1).c_str());
				num++;
				key_exist = key_exist.substr(0, index + 1);
				key_exist += std::to_wstring(num);
			}
			else
			{
				key_exist += L" #1";
			}

			map[key_exist] = value;
			return true;
		}

		return false;
	}

	bool CLibreHardwareMonitor::InsertValue2Map(std::map<std::wstring, std::pair<float, float>>& map, const std::wstring& key, std::pair<float, float>& value)
	{
		auto iter = map.find(key);

		// 如果 key 不在 map 中则新建
		if (iter == map.end())
		{
			map[key] = value;
			return true;
		}
		else
		{
			// 检查当前 key 是否包含 # 号
			std::wstring key_exist = iter->first;
			size_t index = key_exist.rfind(L'#');

			if (index != std::wstring::npos)
			{
				// 获取 # 号后数字并 +1
				int32_t num = _wtoi(key_exist.substr(index + 1).c_str());
				num++;
				key_exist = key_exist.substr(0, index + 1);
				key_exist += std::to_wstring(num);
			}
			else
			{
				key_exist += L" #1";
			}

			map[key_exist] = value;
			return true;
		}

		return false;
	}

	bool CLibreHardwareMonitor::MainboardTemperature(IHardware^ hardware, float& temperature)
	{
		bool flag = false;

		for (int32_t i = 0; i < hardware->Sensors->Length; i++)
		{
			if (hardware->Sensors[i]->SensorType == SensorType::Temperature)
			{
				String^ name = hardware->Sensors[i]->Name;
				m_AllMainboardTemperature[ClrString2StdWstring(name)] = Convert::ToDouble(hardware->Sensors[i]->Value);

				flag = true;
			}
		}

		if (flag)
		{
			temperature = CalculateAverage(m_AllMainboardTemperature);
			return true;
		}

		for (int32_t i = 0; i < hardware->SubHardware->Length; i++)
		{
			if (MainboardTemperature(hardware->SubHardware[i], temperature))
				return true;
		}

		return false;
	}

	bool CLibreHardwareMonitor::MainboardFanSpeed(IHardware^ hardware)
	{
		bool flag = false;

		for (int32_t i = 0; i < hardware->Sensors->Length; i++)
		{
			if (hardware->Sensors[i]->SensorType == SensorType::Fan)
			{
				String^ name = hardware->Sensors[i]->Name;
				m_AllMainboardFanSpeed[ClrString2StdWstring(name)] = Convert::ToDouble(hardware->Sensors[i]->Value);
				flag = true;
			}
		}

		if (flag) return true;

		for (int32_t i = 0; i < hardware->SubHardware->Length; i++)
		{
			if (MainboardFanSpeed(hardware->SubHardware[i]))
				return true;
		}

		return false;
	}

	bool CLibreHardwareMonitor::CpuTemperature(IHardware^ hardware, float& temperature)
	{
		temperature = -1;

		for (int32_t i = 0; i < hardware->Sensors->Length; i++)
		{
			// 找到温度传感器
			if (hardware->Sensors[i]->SensorType == SensorType::Temperature)
			{
				String^ name = hardware->Sensors[i]->Name;
				if (Regex::IsMatch(name, L"^CPU Core #[1-9]+$"))
				{
					// 保存每个 CPU 温度传感器数值
					m_AllCpuTemperature[ClrString2StdWstring(name)] = Convert::ToDouble(hardware->Sensors[i]->Value);
				}

				if (name == L"Core Average")
				{
					temperature = Convert::ToDouble(hardware->Sensors[i]->Value);
				}
			}
		}

		// 如果未找到平均温度则自行计算
		if (temperature == -1)
		{
			temperature = CalculateAverage(m_AllCpuTemperature);
		}
	
		return temperature > 0;
	}

	bool CLibreHardwareMonitor::CpuPower(IHardware^ hardware, float& power)
	{
		return GetSensorValue(hardware, SensorType::Power, L"CPU Package", power);
	}

	bool CLibreHardwareMonitor::CpuClock(IHardware^ hardware, float& clock)
	{
		for (int32_t i = 0; i < hardware->Sensors->Length; i++)
		{
			if (hardware->Sensors[i]->SensorType == SensorType::Clock)
			{
				String^ name = hardware->Sensors[i]->Name;
				if (name != L"Bus Speed")
				{
					m_AllCpuClock[ClrString2StdWstring(name)] = Convert::ToDouble(hardware->Sensors[i]->Value);
				}
			}
		}

		clock = CalculateAverage(m_AllCpuClock);
		return clock > 0;
	}

	bool CLibreHardwareMonitor::CpuLoad(IHardware^ hardware, float& load)
	{
		load = -1;

		for (int32_t i = 0; i < hardware->Sensors->Length; i++)
		{
			if (hardware->Sensors[i]->SensorType == SensorType::Load)
			{
				String^ name = hardware->Sensors[i]->Name;
				if (name != L"CPU Total")
				{
					m_AllCpuLoad[ClrString2StdWstring(name)] = Convert::ToDouble(hardware->Sensors[i]->Value);
				}
				else
				{
					load = Convert::ToDouble(hardware->Sensors[i]->Value);
				}
			}
		}

		if (load == -1)
		{
			load = CalculateAverage(m_AllCpuLoad);
		}

		return load > 0;
	}

	bool CLibreHardwareMonitor::MemoryLoad(IHardware^ hardware, float& load, float& used, float& available)
	{
		for (int32_t i = 0; i < hardware->Sensors->Length; i++)
		{
			if (hardware->Sensors[i]->SensorType == SensorType::Load)
			{
				if (hardware->Sensors[i]->Name == L"Memory")
				{
					load = Convert::ToDouble(hardware->Sensors[i]->Value);
				}
			}

			if (hardware->Sensors[i]->SensorType == SensorType::Data)
			{
				if (hardware->Sensors[i]->Name == L"Memory Used")
				{
					used = Convert::ToDouble(hardware->Sensors[i]->Value);
				}

				if (hardware->Sensors[i]->Name == L"Memory Available")
				{
					available = Convert::ToDouble(hardware->Sensors[i]->Value);
				}
			}
		}

		return load > 0 || used > 0 || available > 0;
	}

	bool CLibreHardwareMonitor::GpuTemperature(IHardware^ hardware, float& temperature)
	{
		for (int32_t i = 0; i < hardware->Sensors->Length; i++)
		{
			if (hardware->Sensors[i]->SensorType == SensorType::Temperature)
			{
				String^ name = hardware->Sensors[i]->Name;
				if (name == L"GPU Core")
				{
					temperature = Convert::ToDouble(hardware->Sensors[i]->Value);
					return true;
				}
			}
		}

		return false;
	}

	bool CLibreHardwareMonitor::GpuPower(IHardware^ hardware, float& power)
	{
		return GetSensorValue(hardware, SensorType::Power, L"GPU Package", power);
	}

	bool CLibreHardwareMonitor::GpuLoad(IHardware^ hardware, float& load)
	{
		for (int32_t i = 0; i < hardware->Sensors->Length; i++)
		{
			if (hardware->Sensors[i]->SensorType == SensorType::Load)
			{
				if (hardware->Sensors[i]->Name == L"GPU Core")
				{
					load = Convert::ToDouble(hardware->Sensors[i]->Value);
					return true;
				}
			}
		}

		return false;
	}

	bool CLibreHardwareMonitor::GpuFanSpeed(IHardware^ hardware, float& speed)
	{
		return GetSensorValue(hardware, SensorType::Fan, L"GPU", speed);
	}

	bool CLibreHardwareMonitor::GpuMemoryLoad(IHardware^ hardware, float& used, float& free, float& total)
	{
		return GetSensorValue(hardware, SensorType::SmallData, L"GPU Memory Used", used) &&
			GetSensorValue(hardware, SensorType::SmallData, L"GPU Memory Free", free) &&
			GetSensorValue(hardware, SensorType::SmallData, L"GPU Memory Total", total);
	}

	bool CLibreHardwareMonitor::StorageTemperature(IHardware^ hardware, float& temperature)
	{
		return GetSensorValue(hardware, SensorType::Temperature, L"", temperature);
	}

	bool CLibreHardwareMonitor::StorageReadWriteSpeed(IHardware^ hardware, std::pair<float, float>& speed)
	{
		float read{};
		float write{};
		if (GetSensorValue(hardware, SensorType::Throughput, L"Read Rate", read) &&
			GetSensorValue(hardware, SensorType::Throughput, L"Write Rate", write))
		{
			speed.first = read;
			speed.second = write;
			return true;
		}

		return false;
	}

	bool CLibreHardwareMonitor::NetworkSpeed(IHardware^ hardware, std::pair<float, float>& speed)
	{
		float upload{};
		float download{};
		if (GetSensorValue(hardware, SensorType::Throughput, L"Upload Speed", upload) &&
			GetSensorValue(hardware, SensorType::Throughput, L"Download Speed", download))
		{
			speed.first = upload;
			speed.second = download;
			return true;
		}

		return false;
	}

}
