#pragma once

/* 가방 항상 열기
 * PATCHES: PLEIONE.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_AlwaysBagView : public IGenericPatcher {
public:
	CPatcher_AlwaysBagView();
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
	static void patchAlwaysBagView(void);
	// Variables for hook functions
	static LPBYTE addrTargetReturn;
	static LPBYTE addrIsUsableContents;
	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_AlwaysBagView> SngPatcher_AlwaysBagView;