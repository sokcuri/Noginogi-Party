#pragma once

/* Enable Name Coloring
 * Enable coloring of ALT names based on character type.
 * PATCHES: Pleione.dll
 */

#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_EnableNameColoring : public IGenericPatcher {
public:
	CPatcher_EnableNameColoring();
	bool Uninstall( void );
	bool Toggle( void );

	bool ReadINI( void );
	bool WriteINI( void );
	static bool IsPatchEnabled(void);
	static bool PatchToggle(void);
	static bool PatchEnable(void);
	static bool PatchDisable(void);

	static unsigned long CVHuman1;
	static unsigned long CVHuman2;
	static unsigned long CVElf1;
	static unsigned long CVElf2;
	static unsigned long CVGiant1;
	static unsigned long CVGiant2;
	static unsigned long CVPet1;
	static unsigned long CVPet2;
	static unsigned long CVNPC1;
	static unsigned long CVNPC2;
	static unsigned long CVEnemy1;
	static unsigned long CVEnemy2;
private:
	// Options
	static bool PatchEnabled;
	// Hook functions
	static void patchNameColoring(void);

	// Variables for hook functions
	static LPBYTE addrTarget;
	static LPBYTE addrIsElf;
	static LPBYTE addrIsGiant;
	static LPBYTE addrIsPet;
	static LPBYTE addrIsNPC;
	static LPBYTE addrIsGoodNPC;
	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_EnableNameColoring> SngPatcher_EnableNameColoring;