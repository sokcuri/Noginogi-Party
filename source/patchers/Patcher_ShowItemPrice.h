#pragma once

/* ShowItemPrice
 * Show the shop purchase and selling price in item descriptions.
 * PATCHES: Pleione.dll
 */

#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ShowItemPrice : public IGenericPatcher {
public:
	CPatcher_ShowItemPrice();
	bool Uninstall( void );
	bool Toggle( void );
	bool ReadINI( void );
	bool WriteINI( void );
	static bool IsPatchEnabled(void);
	static bool PatchToggle(void);
	static bool PatchEnable(void);
	static bool PatchDisable(void);

	static wchar_t strPUSH[];

private:
	// Options
	static bool PatchEnabled;
	// Hook functions
	static void patchShowItemPrice(void);
	// Variables for hook functions
	static LPBYTE addrTargetOn;
	static LPBYTE addrTargetOff;
	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_ShowItemPrice> SngPatcher_ShowItemPrice;