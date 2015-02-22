#pragma once

/* Enter Remote Shop
 * Enable opening of player shops from a distance.
 * PATCHES: Pleione.dll
 */

#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_EnterRemoteShop : public IGenericPatcher {
public:
	CPatcher_EnterRemoteShop();
	bool Uninstall( void );
	bool Toggle( void );

	bool ReadINI( void );
	bool WriteINI( void );
	static float fl;
	static bool IsPatchEnabled(void);
	static bool PatchToggle(void);
	static bool PatchEnable(void);
	static bool PatchDisable(void);

private:
	// Options
	static bool PatchEnabled;
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_EnterRemoteShop> SngPatcher_EnterRemoteShop;