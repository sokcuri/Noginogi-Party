#pragma once

/* 제로고도 비행
 * PATCHES: Pleione.dll
 *
 * CTRL+H "FlyZeroHigh"
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_FlyZeroHigh : public IGenericPatcher {
public:
	CPatcher_FlyZeroHigh();
	bool Uninstall( void );
	bool Toggle( void );

	bool ReadINI( void );
	bool WriteINI( void );
	static bool IsPatchEnabled(void);
	static bool PatchToggle(void);
	static bool PatchEnable(void);
	static bool PatchDisable(void);

	static float HighFloat1;
	static float HighFloat2;
	static double HighFloat3;


private:
	// Options
	static bool PatchEnabled;
	// Hook functions
	static void patchFlyZeroHigh(void);
	// Variables for hook functions
	static LPBYTE addrTargetJump;
	static LPBYTE addrTargetMsg;
	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_FlyZeroHigh> SngPatcher_FlyZeroHigh;