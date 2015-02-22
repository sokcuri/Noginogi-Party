#pragma once

/* 은행 탭 항상 열기
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_BankTabEnable : public IGenericPatcher {
public:
	CPatcher_BankTabEnable();
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
	static void patchBankTabEnable(void);
	// Variables for hook functions
	static BYTE dataCALL[4];
	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_BankTabEnable> SngPatcher_BankTabEnable;