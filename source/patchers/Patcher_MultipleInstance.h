#pragma once

/* Name Of Mod
 * Description of mod
 * PATCHES: XXX.dll
 *
 * CTRL+H "MultipleInstance"
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_MultipleInstance : public IGenericPatcher {
public:
	CPatcher_MultipleInstance();
	bool Uninstall( void );
	bool Toggle( void );

	bool ReadINI( void );
	bool WriteINI( void );
	static bool IsPatchEnabled(void);
	static bool PatchToggle(void);
	static bool PatchEnable(void);
	static bool PatchDisable(void);

	static wchar_t strMutex[];

private:
	// Options
	static bool PatchEnabled;
	// Hook functions
	static void patchMultipleInstance();
	// Variables for hook functions
	static LPBYTE addrTargetReturn;
	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_MultipleInstance> SngPatcher_MultipleInstance;