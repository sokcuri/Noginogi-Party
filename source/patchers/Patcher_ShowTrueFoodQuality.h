#pragma once

/* Show True Food Quality
 * Show food quality numerically.
 * PATCHES: Pleione.dll
 */

#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ShowTrueFoodQuality : public IGenericPatcher {
public:
	CPatcher_ShowTrueFoodQuality();
	bool Uninstall( void );
	bool Toggle( void );

	bool ReadINI( void );
	bool WriteINI( void );

	static bool IsPatchEnabled(void);
	static bool PatchToggle(void);
	static bool PatchEnable(void);
	static bool PatchDisable(void);

private:
	// Options
	static bool PatchEnabled;
	// Hook functions
	static void patchFoodQuality(void);
	static void patchFoodQualityFormat(wchar_t * buff,wchar_t* str,int d);

	// Variables for hook functions
	static wchar_t dataBuf[256];
	static LPBYTE addrCStringTEquals;
	static LPBYTE addrTargetReturn;
	static LPBYTE addrIsGoodNPC;
	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_ShowTrueFoodQuality> SngPatcher_ShowTrueFoodQuality;