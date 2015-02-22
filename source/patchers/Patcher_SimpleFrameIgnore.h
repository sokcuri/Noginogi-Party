#pragma once

/* Name Of Mod
 * Description of mod
 * PATCHES: XXX.dll
 *
 * CTRL+H "NameOfMod"
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_SimpleFrameIgnore : public IGenericPatcher {
public:
	CPatcher_SimpleFrameIgnore();
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
	static void patchSimpleFrameIgnore(void);
	// Variables for hook functions
	static LPBYTE addr__time;
	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_SimpleFrameIgnore> SngPatcher_SimpleFrameIgnore;