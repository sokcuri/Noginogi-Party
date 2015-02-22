#pragma once

/* Unlimit Party Time
 * Party Incruit Time to unlimit
 * PATCHES: Pleione.dll
 *
 */

#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_UnlimitPartytime : public IGenericPatcher {
public:
	CPatcher_UnlimitPartytime();
	bool Uninstall( void );
	bool Toggle( void );

	bool ReadINI( void );
	bool WriteINI( void );
	int *pt;
	static bool IsPatchEnabled(void);
	static bool PatchToggle(void);
	static bool PatchEnable(void);
	static bool PatchDisable(void);

private:
	// Options
	static bool PatchEnabled;
	// Hook functions
	static void patchUnlimitPartytime(void);
	// Variables for hook functions
	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_UnlimitPartytime> SngPatcher_UnlimitPartytime;