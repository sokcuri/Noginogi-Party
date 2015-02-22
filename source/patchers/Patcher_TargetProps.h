#pragma once

/* Target Props
 * Enable CTRL-targeting props while in combat mode.
 * PATCHES: Pleione.dll
 */

#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_TargetProps : public IGenericPatcher {
public:
	CPatcher_TargetProps();
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
	// Variables for hook functions
	static wchar_t dataStr[50];
};

typedef Singleton<CPatcher_TargetProps> SngPatcher_TargetProps;