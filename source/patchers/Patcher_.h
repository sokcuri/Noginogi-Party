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

class CPatcher_NameOfMod : public IGenericPatcher {
public:
	CPatcher_NameOfMod();
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
	static void patchNameOfMod(void);
	// Variables for hook functions
	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_NameOfMod> SngPatcher_NameOfMod;