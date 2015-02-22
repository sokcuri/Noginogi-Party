#pragma once

/* ExpressBoard
 * Remote Board
 * PATCHES: Pleione.dll
 *
 * CTRL+H "NameOfMod"
 */

#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ExpressBoard : public IGenericPatcher {
public:
	CPatcher_ExpressBoard();
	bool ReadINI( void );
	bool WriteINI( void );
	bool Uninstall( void );
	bool Toggle( void );
	static bool IsPatchEnabled(void);
	static bool PatchToggle(void);
	static bool PatchEnable(void);
	static bool PatchDisable(void);

	// 프롭 관련 스트링
	static wchar_t strHouseInfo[];
	static wchar_t strHousingInfo[];
	static wchar_t strAdvertiseBoard[];
	static wchar_t strDungeonRankingBoard[];
	static wchar_t strPartyBoard[];
	static wchar_t strShadowMissionBoard[];
private:
	// Options
	static bool PatchEnabled;
	// Hook functions
	static void patchExpressBoard(void);
	static void patchReadU8(void);
	// Variables for hook functions
	static wchar_t dataBuf[256];

	static LPBYTE addrIProp_CheckFastStringID;
	static LPBYTE addrCMessage_ReadU8;
	static LPBYTE addr_package_file_item;
	static LPBYTE addrTargetReturn;
	static LPBYTE addrTargetReturn2;
	static LPBYTE addrCalcDistance;

	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_ExpressBoard> SngPatcher_ExpressBoard;