#pragma once

/* Name Of Mod
 * Description of mod
 * PATCHES: XXX.dll
 *
 * CTRL+H "FarSignRead"
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_FarSignRead : public IGenericPatcher {
public:
	CPatcher_FarSignRead();
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
	static void patchFarSignRead(void);
	// Variables for hook functions
	static LPBYTE addrTargetReturn;
	static LPBYTE addrTargetJump;
	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_FarSignRead> SngPatcher_FarSignRead;