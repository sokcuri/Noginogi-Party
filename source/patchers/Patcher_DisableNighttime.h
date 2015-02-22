#pragma once

/* Disable Nighttime
 * Cause daylight appearance between the hours of 18:00 and 4:00.
 * PATCHES: Renderer2.dll
 */

#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_DisableNighttime : public IGenericPatcher {
public:
	CPatcher_DisableNighttime();
	bool Uninstall( void );
	bool Toggle( void );

	bool NightReadINI( void );
	bool NightWriteINI( void );
	bool SunReadINI( void );
	bool SunWriteINI( void );
	bool ReadINI( void );
	bool WriteINI( void );

	static bool IsNightPatchEnabled(void);
	static bool NightPatchToggle(void);
	static bool NightPatchEnable(void);
	static bool NightPatchDisable(void);
	
	static bool IsSunPatchEnabled(void);
	static bool SunPatchToggle(void);
	static bool SunPatchEnable(void);
	static bool SunPatchDisable(void);

private:
	// Options
	static bool NightPatchEnabled;
	static bool SunPatchEnabled;
	// Hook functions
	static void patchNighttime(void);
	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_DisableNighttime> SngPatcher_DisableNighttime;