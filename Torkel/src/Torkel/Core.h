#pragma once

#ifdef TORKEL_PLATFORM_WINDOWS
	#ifdef TORKEL_BUILD_DLL
		#define TORKEL_API __declspec(dllexport) 
	#else
		#define TORKEL_API __declspec(dllimport) 
	#endif
#else
#error Torkel only supports Windows!
#endif
