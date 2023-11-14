#pragma once


#ifdef WIN32
#include <Windows.h>

#endif

#ifdef BUILD_DLL
	#define MYDIRECTX_API __declspec(dllexport)
#else
	#define MYDIRECTX_API __declspec(dllimport)
#endif