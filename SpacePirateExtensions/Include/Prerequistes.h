#pragma once

#define SPE_EXPORT __declspec(dllexport)
#define SPE_IMPORT __declspec(dllimport)

#if defined(SPE_STATIC)
	#define SPE_API
#else
	#ifdef SPE_BUILD
		#define SPE_API SPE_EXPORT
	#else
		#define SPE_API SPE_IMPORT
	#endif
#endif
