#pragma once

/* Show Combat Power
 * Show combat power numerically.
 * PATCHES: Pleione.dll
 */

#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ShowCombatPower : public IGenericPatcher {
public:
	CPatcher_ShowCombatPower();
	bool Uninstall( void );
	bool Toggle( void );

	bool ReadINI( void );
	bool WriteINI( void );
	static bool IsPatchEnabled(void);
	static bool PatchToggle(void);
	static bool PatchEnable(void);
	static bool PatchDisable(void);
	static bool NoCombatChar;
	static bool ShowCombatNPCGrade;
	static bool ShowCombatPlayerGrade;
	static bool ShowCombatGoodNPCGrade;
	static bool IsNPCChar;
private:
	// Options
	static bool PatchEnabled;
	// Hook functions
	//static void patchCP1(void);
	//static void patchCP2(void);
	static void patchIsNPC(void);
	static void patchIsNamedNPC(void);
	static void patchIsCurrentPlayer(void);
	static void patchShowCombatPower(void);
	static void __stdcall patchCPFormat(wchar_t * buff,double f);
	static void __stdcall patchConnectFormat(wchar_t * buff,wchar_t * str1,wchar_t * str2);
	static void __stdcall patchConnectFormat2(wchar_t * buff,wchar_t * str1,wchar_t * str2);

	// Variables for hook functions
	static wchar_t dataBuf[256];
	static wchar_t combatBuf[256];
	static wchar_t combatWeakest[50];
	static wchar_t combatWeak[50];
	static wchar_t combatStrong[50];
	static wchar_t combatAwful[50];
	static wchar_t combatBoss[50];
	static wchar_t dataStrNull[1];
	static LPBYTE addrCStringTConstr;
	static LPBYTE addrCStringTEquals;
	static LPBYTE addrGetTargetCombatPower;
	static LPBYTE addrGetCombatPower;
	static LPBYTE addrTargetReturn;
	static LPBYTE addrIsNPC;
	static LPBYTE addrIsGoodNPC;
	static LPBYTE addrIsNamedNPC;
	static LPBYTE addrGetLife;
	static BYTE callBackup[4];
	LPBYTE funcPointer1;
	LPBYTE funcPointer2;
	LPBYTE funcPointer3;
	LPBYTE funcPointer4;
};

typedef Singleton<CPatcher_ShowCombatPower> SngPatcher_ShowCombatPower;