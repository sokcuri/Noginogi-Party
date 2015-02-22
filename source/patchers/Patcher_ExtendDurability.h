#pragma once

/* 확장 내구도
 * PATCHES: Pleione.dll, Standard.dll
 */

#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ExtendDurability : public IGenericPatcher {
public:
	CPatcher_ExtendDurability();
	bool Uninstall( void );
	bool Toggle( void );

	bool ReadINI( void );
	bool WriteINI( void );
	static bool IsPatchEnabled(void);
	static bool PatchToggle(void);
	static bool PatchEnable(void);
	static bool PatchDisable(void);

	// Options
	static bool SetString( wchar_t *string );
	bool IsColorEnabled(void);
	bool EnableColor( void );
	bool DisableColor( void );
	bool ToggleColor( void );

private:
	// Options
	static bool PatchEnabled;
	static bool ColorEnabled;

	// Hook functions
	static void GetDurability(void);
	static void GetDurabilityMax(void);
	static void patchDurability(void);
	static void patchDurabilityColor(void);
	static void __stdcall patchItemColorFormat(wchar_t * buff, long color1, long color2, long color3);

	// Variables for hook functions
	static wchar_t dataColorString[];
	static wchar_t dataColorBuf[256];
	static wchar_t dataINIDuraString[256];
	static wchar_t dataDefaultDuraFormat[256];
	static wchar_t dataDurabilityString[256];
	static wchar_t dataItemColorCodeFormat[256];
	static wchar_t dataFullString[256];
	static LPBYTE addrGetColor;
	static LPBYTE addrCFormatterInsert_ulong;
	static LPBYTE addrCFormatterInsert_pwchar;
	static LPBYTE addrTargetReturn;
	static LPBYTE addrColorReturn;
	static LPBYTE addrColorReturnPerfect;
};

typedef Singleton<CPatcher_ExtendDurability> SngPatcher_ExtendDurability;