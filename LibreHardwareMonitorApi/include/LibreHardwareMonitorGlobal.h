#pragma once

#ifdef LIBREHARDWAREMONITOR_EXPORTS
#define LIBREHARDWAREMONITOR_API __declspec(dllexport)
#else
#define LIBREHARDWAREMONITOR_API __declspec(dllimport)
#endif