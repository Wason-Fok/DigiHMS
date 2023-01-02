#include <iostream>
#include <codecvt>
#include <LibreHardwareMonitorApi.h>
#include <windows.h>
#include <algorithm>

inline std::string Wstring2String(std::wstring str)
{
//     std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
//     return converter.to_bytes(str);

    std::string s;
    std::transform(str.begin(), str.end(), std::back_inserter(s), [](wchar_t c) {
        return (char)c;
        });

    return s;
}

int main()
{
    std::cout << "API TEST\n";
    std::shared_ptr<LibreHardwareMonitorApi::ILibreHardwareMonitor> monitor = LibreHardwareMonitorApi::CreateInstance();

    monitor->GetHardwareInfo();
    std::cout << "GPU Fan Speed: " << monitor->GetGpuFanSpeed() << std::endl;

    bool a = monitor->SetFanSpeed(L"GPU Fan", 100);
    monitor->SetFanSpeed(L"Fan #1", 100);
    
    for (int32_t i = 0; i < 10; i++)
    {
		monitor->GetHardwareInfo();
		std::cout << "GPU Fan Speed: " << monitor->GetGpuFanSpeed() << std::endl;
        Sleep(1000);
    }

    a = monitor->SetFanSpeed(L"GPU Fan", -1);
    monitor->SetFanSpeed(L"Fan #1", -1);
	for (int32_t i = 0; i < 10; i++)
	{
		monitor->GetHardwareInfo();
		std::cout << "GPU Fan Speed: " << monitor->GetGpuFanSpeed() << std::endl;
		Sleep(1000);
	}

    std::cout << Wstring2String(LibreHardwareMonitorApi::GetErrorMessage()) << std::endl;
    

    system("pause");
    return 0;
}
