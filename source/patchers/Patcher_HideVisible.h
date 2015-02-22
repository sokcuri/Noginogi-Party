#pragma once

/* 하이드 캐릭터 보이기
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_HideVisible : public IGenericPatcher {
public:
	CPatcher_HideVisible();
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
	static void patchHideVisible(void);
	// Variables for hook functions
	static LPBYTE addrIsArenaField;
	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_HideVisible> SngPatcher_HideVisible;