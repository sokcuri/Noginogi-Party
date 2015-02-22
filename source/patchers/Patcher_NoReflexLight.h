#pragma once

/* 반사광 없애기
 * PATCHES: PLEIONE.dll
 *
 * CTRL+H "NoReflexLight"
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_NoReflexLight : public IGenericPatcher {
public:
	CPatcher_NoReflexLight();
	bool Uninstall( void );
	bool Toggle( void );

	bool ReadINI( void );
	bool WriteINI( void );
	static bool IsPatchEnabled(void);
	static bool PatchToggle(void);
	static bool PatchEnable(void);
	static bool PatchDisable(void);
	static LPBYTE addrTargetReturn;

private:
	// Options
	static bool PatchEnabled;
	// Hook functions
	static void patchNoReflexLight(void);
	// Variables for hook functions
	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_NoReflexLight> SngPatcher_NoReflexLight;