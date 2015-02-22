#pragma once

/* πÃπÕ ¿Ã∏ß«•
 * PATCHES: STANDARD.dll
 *
 * CTRL+H "MimicNaming"
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_MimicNaming : public IGenericPatcher {
public:
	CPatcher_MimicNaming();
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
	static void patchMimicNaming(void);
	// Variables for hook functions
	static LPBYTE addrIsPet;
	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_MimicNaming> SngPatcher_MimicNaming;