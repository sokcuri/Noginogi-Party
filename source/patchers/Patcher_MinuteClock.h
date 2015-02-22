#pragma once

/* 분단위 시계
 * 시계를 분까지 나오게 한다
 * PATCHES: PLEIONE.dll
 *
 * CTRL+H "MinuteClock"
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_MinuteClock : public IGenericPatcher {
public:
	CPatcher_MinuteClock();
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
	static void patchMinuteClock(void);
	// Variables for hook functions
	LPBYTE funcPointer;
	static LPBYTE addrTargetReturn;
};

typedef Singleton<CPatcher_MinuteClock> SngPatcher_MinuteClock;