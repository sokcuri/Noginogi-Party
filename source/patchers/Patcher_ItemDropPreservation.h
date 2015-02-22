#pragma once

/* 아이템 드롭 보호
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ItemDropPreservation : public IGenericPatcher {
public:
	CPatcher_ItemDropPreservation();
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
	static void patchItemDropPreservation1(void);
	static void patchItemDropPreservation2(void);
	static void patchItemDropPreservation3(void);
	static void patchItemDropPreservation4(void);
	static void patchItemDropPreservation5(void);
	// Variables for hook functions
	static wchar_t NonUsingPSV[256];
	static wchar_t UsingPSV[256];
	static LPBYTE addrTargetReturn1;
	static LPBYTE addrTargetReturn2;
	static LPBYTE addrTargetReturn3;
	static LPBYTE addrTargetReturn4;
	LPBYTE funcPointer1;
	LPBYTE funcPointer2;
	LPBYTE funcPointer4;
	LPBYTE funcPointer5;
};

typedef Singleton<CPatcher_ItemDropPreservation> SngPatcher_ItemDropPreservation;