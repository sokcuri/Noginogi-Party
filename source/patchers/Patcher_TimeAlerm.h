#pragma once

/* Name Of Mod
 * Description of mod
 * PATCHES: XXX.dll
 *
 * CTRL+H "NameOfMod"
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_TimeAlerm : public IGenericPatcher {
public:
	CPatcher_TimeAlerm();
	bool Uninstall( void );
	bool Toggle( void );

	bool ReadINI( void );
	bool WriteINI( void );
	bool ReadINIAll( void );
	static bool IsPatchEnabled(void);
	static bool PatchToggle(void);
	static bool PatchEnable(void);
	static bool PatchDisable(void);

	static wchar_t dataBuf[256];

	static int CurNo;

	static int tempRinged;
	static int tempUsing;
	static int tempHour;
	static int tempHour1;
	static int tempHour2;
	static int tempMin;
	static int tempMin1;
	static int tempMin2;
	static int tempCode;
	static wchar_t *tempText;

	static int AlermRinged[10];
	static int AlermUsing[10];
	static int AlermHour[10];
	static int AlermHour1[10];
	static int AlermHour2[10];
	static int AlermMin[10];
	static int AlermMin1[10];
	static int AlermMin2[10];
	static int AlermCode[10];
	static wchar_t AlermText[10][256];

	static int DisableDummy;

	static int AlermErrorRange1;
	static int AlermErrorRange2;

	static wchar_t NaoRecharged[];
private:
	// Options
	static bool PatchEnabled;
	static bool SetString(wchar_t * string);
	static void __stdcall patchFormat(wchar_t * buff,wchar_t * str,int min,int hour);
	// Hook functions
	static void patchTimeAlerm(void);
	static void patchTimeAlermCaption(void);
	// Variables for hook functions
	LPBYTE funcPointer1;
	LPBYTE funcPointer2;
	LPBYTE funcPointer3;
	static LPBYTE addrAlerm;
	static LPBYTE addrNoAlerm;
	static LPBYTE addrTargetReturn;
	static LPBYTE addrTargetReturn2;
	static LPBYTE addrGetGlobalTime;
	static LPBYTE addrShowCaption;
	static LPBYTE addrShowChatMsg;
	static LPBYTE addrCStringTUni_wchar;
	static LPBYTE addrGetObjectId;
	static LPBYTE addrGlobalTimeToGameTime;
	static LPBYTE addrIsUsingNaosSupport;
};

typedef Singleton<CPatcher_TimeAlerm> SngPatcher_TimeAlerm;