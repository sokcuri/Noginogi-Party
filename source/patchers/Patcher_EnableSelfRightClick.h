#pragma once

/* Enable Self Right-Click
 * Enable opening the right-click menu on your own character.
 * PATCHES: Pleione.dll
 */

#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_EnableSelfRightClick : public IGenericPatcher {
public:
	CPatcher_EnableSelfRightClick();
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
	static void patchSelfRightClick(void);
	// Variables for hook functions
	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_EnableSelfRightClick> SngPatcher_EnableSelfRightClick;