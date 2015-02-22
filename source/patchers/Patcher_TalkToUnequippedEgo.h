#pragma once

/* Talk To Unequipped Ego
 * Allow conversation with unequipped spirit weapons.
 * PATCHES: Pleione.dll
 */

#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_TalkToUnequippedEgo : public IGenericPatcher {
public:
	CPatcher_TalkToUnequippedEgo();
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
	static void patchUnequippedEgo(void);
	// Variables for hook functions
	static LPBYTE addrTargetReturn;
	static LPBYTE addrIsEiry;
	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_TalkToUnequippedEgo> SngPatcher_TalkToUnequippedEgo;