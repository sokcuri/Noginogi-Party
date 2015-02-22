#pragma once

/* 데들리 체력 표시
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_DeadlyHPShow : public IGenericPatcher {
public:
	CPatcher_DeadlyHPShow();
	bool Uninstall( void );
	bool Toggle( void );

	bool ReadINI( void );
	bool WriteINI( void );
	static bool IsPatchEnabled(void);
	static bool PatchToggle(void);
	static bool PatchEnable(void);
	static bool PatchDisable(void);

	static wchar_t dataBuf[256];
	static wchar_t strDeadly[];

private:
	// Options
	static bool PatchEnabled;
	// Hook functions
	static void patchDeadlyHPShow(void);
	static void __stdcall patchFormat(wchar_t *buff, double f);
	// Variables for hook functions
	static LPBYTE addrGetLife;
	static LPBYTE addrTargetReturn;
	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_DeadlyHPShow> SngPatcher_DeadlyHPShow;