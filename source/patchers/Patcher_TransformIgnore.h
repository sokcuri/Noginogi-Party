#pragma once

/* 변신 효과 무시
 * 변신을 무시한다
 * PATCHES: PLEIONE.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_TransformIgnore : public IGenericPatcher {
public:
	CPatcher_TransformIgnore();
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
	static void patchTransformIgnore(void);
	static void patchInlineCall(void);
	static void patchGetFullSuitID(void);
	// Variables for hook functions
	static LPBYTE addrInlineCall;
	static LPBYTE addrGetFullSuitID;
	static LPBYTE addrIsTransformed;
	LPBYTE funcPointer;
	LPBYTE funcPointerA;
};

typedef Singleton<CPatcher_TransformIgnore> SngPatcher_TransformIgnore;