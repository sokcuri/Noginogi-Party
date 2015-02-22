#pragma once

/* Move While Talking
 * Allow moving while talking to NPCs.
 * PATCHES: Pleione.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_MoveWhileTalking : public IGenericPatcher {
public:
	CPatcher_MoveWhileTalking();
	bool ReadINI( void );
	bool WriteINI( void );
	bool Uninstall( void );
	bool Toggle( void );
	static bool IsPatchEnabled(void);
	static bool PatchToggle(void);
	static bool PatchEnable(void);
	static bool PatchDisable(void);
private:
	// Options
	static bool PatchEnabled;
	// Hook functions
	static void patchMoveWhileTalking(void);
	// Variables for hook functions
	static LPBYTE funcPointer;
	static LPBYTE addrTargetReturn;
};

typedef Singleton<CPatcher_MoveWhileTalking> SngPatcher_MoveWhileTalking;