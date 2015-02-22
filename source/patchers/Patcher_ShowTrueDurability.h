#pragma once

/* Show True Durability
 * Show item durability with 1000x precision.
 * PATCHES: Pleione.dll, Standard.dll
 */

#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ShowTrueDurability : public IGenericPatcher {
public:
	CPatcher_ShowTrueDurability();
	bool ReadINI( void );
	bool WriteINI( void );

	// Options
	bool SetString( wchar_t *string );
	bool IsColorEnabled(void);
	bool EnableColor( void );
	bool DisableColor( void );
	bool ToggleColor( void );

private:
	// Options
	bool colorEnabled;

	// Hook functions
	static void GetDurability(void);
	static void GetDurabilityMax(void);
	static void patchDurability(void);
	static void patchDurabilityColor(void);
	static void __stdcall patchItemColorFormat(wchar_t * buff, long color1, long color2, long color3);

	// Variables for hook functions
	static wchar_t dataColorString[];
	static wchar_t dataColorBuf[256];
	static wchar_t dataDurabilityString[256];
	static wchar_t dataFullString[256];
	static LPBYTE addrGetColor;
	static LPBYTE addrCFormatterInsert_ulong;
	static LPBYTE addrCFormatterInsert_pwchar;
	static LPBYTE addrTargetReturn;
	static LPBYTE addrColorReturn;
	static LPBYTE addrColorReturnPerfect;
};

typedef Singleton<CPatcher_ShowTrueDurability> SngPatcher_ShowTrueDurability;