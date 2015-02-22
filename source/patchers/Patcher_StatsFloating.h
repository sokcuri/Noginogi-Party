#pragma once

/* ½ºÅÈ ¼Ò¼ýÁ¡
 * PATCHES: PLEIONE.dll
 *
 * CTRL+H "StatsFloating"
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_StatsFloating : public IGenericPatcher {
public:
	CPatcher_StatsFloating();
	bool Uninstall( void );
	bool Toggle( void );

	bool ReadINI( void );
	bool WriteINI( void );
	static bool IsPatchEnabled(void);
	static bool PatchToggle(void);
	static bool PatchEnable(void);
	static bool PatchDisable(void);

	static double dummyDB100;

private:
	// Options
	static bool PatchEnabled;
	static wchar_t dataBuf[256];
	// Hook functions
	static void patchStatsFloating(void);
	static void patchFloatingFormat(void);
	static void __stdcall patchStatsFormat(int f, wchar_t * string, int size, int radix);
	static void __stdcall patchCPFormat(int f, wchar_t * string, int size, int radix);
	static long __stdcall _ftol(double fl);
	static long patchMultipleStats(void);
	static void patchMultipleStats2Defence(void);
	// Variables for hook functions
	static LPBYTE addrCStringTEquals;
	static LPBYTE addrTargetReturn;
	static LPBYTE addrGetLuck;
	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_StatsFloating> SngPatcher_StatsFloating;