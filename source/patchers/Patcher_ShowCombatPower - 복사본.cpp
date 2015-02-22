#include "Patcher_ShowCombatPower.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

wchar_t CPatcher_ShowCombatPower::dataStrNull[1] = L"";
wchar_t CPatcher_ShowCombatPower::dataBuf[256];
wchar_t CPatcher_ShowCombatPower::combatBuf[256];
wchar_t CPatcher_ShowCombatPower::combatWeakest[50] = L"<mini>WEAKEST </mini>";
wchar_t CPatcher_ShowCombatPower::combatWeak[50] = L"<mini>WEAK </mini>";
wchar_t CPatcher_ShowCombatPower::combatStrong[50] = L"<mini>STRONG </mini>";
wchar_t CPatcher_ShowCombatPower::combatAwful[50] = L"<mini>AWFUL </mini>";
wchar_t CPatcher_ShowCombatPower::combatBoss[50] = L"<mini>BOSS </mini>";
LPBYTE CPatcher_ShowCombatPower::addrCStringTConstr = NULL;
LPBYTE CPatcher_ShowCombatPower::addrCStringTEquals = NULL;
LPBYTE CPatcher_ShowCombatPower::addrGetTargetCombatPower = NULL;
LPBYTE CPatcher_ShowCombatPower::addrGetCombatPower = NULL;
LPBYTE CPatcher_ShowCombatPower::addrTargetReturn = NULL;
LPBYTE CPatcher_ShowCombatPower::addrIsNPC = NULL;
LPBYTE CPatcher_ShowCombatPower::addrIsNamedNPC = NULL;

bool CPatcher_ShowCombatPower::PatchEnabled = false;

//-----------------------------------------------------------------------------
// Constructor

CPatcher_ShowCombatPower::CPatcher_ShowCombatPower( void )
{
	patchname = "Show Combat Power";

	addrCStringTConstr = CAddr::Addr(CStringTUni_Constr);
	addrCStringTEquals = CAddr::Addr(CStringTUni_Equals);
	addrGetCombatPower = CAddr::Addr(IParameterBase2_GetCombatPower);
	addrGetTargetCombatPower = CAddr::Addr(ICharacter_GetTargetCombatPower);
	addrIsNPC = CAddr::Addr(ICharacter_IsNPC);
	addrIsNamedNPC = CAddr::Addr(ICharacter_IsNamedNPC);

	if (!addrCStringTConstr ||
		!addrCStringTEquals ||
		!addrGetCombatPower)
	{
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
		WriteLog("   Missing dependency.\n");
		return;
	}

	// Patch mp1
	// We have to be careful here not to conflict with the Enable Name Coloring patch--
	// it modifies the same function up through +6C

	vector<WORD> patch1;
	vector<WORD> backup1;
	vector<WORD> patch2;
	vector<WORD> backup2;
	backup1 +=
		0x83, 0x65, 0xFC, 0x00,			// +63: AND DWORD PTR SS:[EBP-4],0
		0x56,							// +67: PUSH ESI
		0x8B, 0xCF,						// +68: MOV ECX, EDI
		0xFF, 0x15, -1, -1, -1, -1,		// +6A: CALL DWORD PTR DS:[xxxxxxxx] (Standard.?GetTargetCombatPower@ICharacter@core@@QAE?AW4ECombatPower@@PBV12@@Z)
		0x48;							// +70: DEC EAX

	funcPointer1 = (LPBYTE)patchShowCombatPower;

	patch1 +=
		-1, -1, -1, -1,
		-1,
		-1, -1,
		0xFF, 0x15, 
		((int)(&funcPointer1) & 0xFF),
		(((int)(&funcPointer1) & 0xFF00) >> 8),
		(((int)(&funcPointer1) & 0xFF0000) >> 16),
		(((int)(&funcPointer1) & 0xFF000000) >> 24),
		0x48;

	MemoryPatch mp1( NULL, patch1, backup1 );
	if (!mp1.Search( L"Pleione.dll" )) {
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
		return;
	}

		backup2 +=
		0x8B, 0xF8,							// 1E: MOV EDI,EAX
		0x85, 0xFF,							// 20: TEST EDI,EDI
		0x0F, 0x84, -1, -1, -1, -1,			// 22: JE xxxxxxxx (점프: 등급표시x)
		0x8B, 0xCE,							// 28: MOV ECX,ESI
		0xFF, 0x15, -1, -1, -1, -1,			// 2A: CALL xxxxxxxx (Standard.?IsNPC@ICharacter@core@@QBE_NXZ)
		0x84, 0xC0,							// 30: TEST AL,AL
		0x0F, 0x84, -1, -1, -1, -1,			// 32: JE xxxxxxxx (점프: 등급표시x)
		0x8B, 0xCE,							// 38: MOV ECX,ESI
		0xFF, 0x15, -1, -1, -1, -1,			// 3A: CALL xxxxxxxx (Standard.?IsNamedNPC@ICharacter@core@@QBE_NXZ)
		0x84, 0xC0,							// 40: TEST AL,AL
		0x0F, 0x85, -1, -1, -1, -1,			// 42: JNZ xxxxxxxx
		0x8B, 0x06,							// 48: MOV EAX,DWORD PTR DS:[ESI]
		0x8B, 0xCE,							// 4A: MOV ECX,ESI
		0xFF, 0x90, -1, -1, -1, -1,			// 4C: CALL xxxxxxxx (자기자신인지 확인)
		0x84, 0xC0;							// 52: TEST AL, AL


	funcPointer2 = (LPBYTE)patchIsNPC;
	funcPointer3 = (LPBYTE)patchIsNamedNPC;
	funcPointer4 = (LPBYTE)patchIsCurrentPlayer;

	patch2 +=
		-1, -1,
		-1, -1,
		-1, -1, -1, -1, -1, -1,
		-1, -1,
		0xFF, 0x15, 
		((int)(&funcPointer2) & 0xFF),
		(((int)(&funcPointer2) & 0xFF00) >> 8),
		(((int)(&funcPointer2) & 0xFF0000) >> 16),
		(((int)(&funcPointer2) & 0xFF000000) >> 24),
		0x84, 0xC0,
		0x0F, 0x84, -1, -1, -1, -1,
		0x8B, 0xCE,
		0xFF, 0x15,
		((int)(&funcPointer3) & 0xFF),
		(((int)(&funcPointer3) & 0xFF00) >> 8),
		(((int)(&funcPointer3) & 0xFF0000) >> 16),
		(((int)(&funcPointer3) & 0xFF000000) >> 24),
		0x84, 0xC0,
		0x0F, 0x85, -1, -1, -1, -1,
		-1, -1,
		-1, -1,
		0xFF, 0x15,
		((int)(&funcPointer4) & 0xFF),
		(((int)(&funcPointer4) & 0xFF00) >> 8),
		(((int)(&funcPointer4) & 0xFF0000) >> 16),
		(((int)(&funcPointer4) & 0xFF000000) >> 24),
		0x84, 0xC0;

	MemoryPatch mp2( NULL, patch2, backup2 );
	if (!mp2.Search( L"Pleione.dll" )) {
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
		return;
	}
	patches += mp1;
	patches += mp2;

	addrTargetReturn       = mp1.GetAddr() + 0x3E;
	//addrTargetReturn       = mp.GetAddr() + 0x0D;

	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_ShowCombatPower::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_ShowCombatPower::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_ShowCombatPower::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_ShowCombatPower::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_ShowCombatPower::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_ShowCombatPower::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// Hook functions

/* patchCP1 performs the initialization necessary to get us the character name
 * prefix CStringT object.  We jump to it for all cases where we do NOT want to
 * show BOSS, AWFUL, etc. relative CP -- players, NPCs, etc.
 * For normal enemies we should never get here.
 */
NAKED void CPatcher_ShowCombatPower::patchShowCombatPower(void)
{
	__asm {
		PUSH	EBP
		MOV		EBP,ESP
		PUSH	ECX
		PUSH	ECX
		PUSH	ESI
		MOV		ECX,DWORD PTR SS:[EBP+8]
		MOV		EAX,DWORD PTR DS:[ECX]
		CALL	DWORD PTR DS:[EAX+4Ch]
		MOV		ECX,EAX
		CALL	addrGetCombatPower
		SUB		ESP, 8h						// Allocate stack space for the CP value
		FSTP	QWORD PTR SS:[ESP]			// Store the CP value on the stack

		PUSH	offset dataBuf				// Push the CP value
		CALL	patchCPFormat				// Call our formatting function.  The string arg was pushed
											// either by the Pleione code (for enemies-- <mini>BOSS </mini>
											// or whatever) or by patchCP1.
		XOR		EAX,EAX
		POP		ESI
		LEAVE
		ADD		ESP,4
		POP		EAX
		//PUSH	offset dataBuf

		PUSH	ESI
		MOV		ECX,EDI
		CALL	addrGetTargetCombatPower

		DEC		EAX
		JE		CP_Weakest
		DEC		EAX
		JE		CP_Weak
		DEC		EAX
		DEC		EAX
		JE		CP_Strong
		DEC		EAX
		JE		CP_Awful
		DEC		EAX
		JNZ		CP_Null
		JMP		CP_Boss
		CP_Null:
		PUSH offset dataStrNull
		JMP CP_End
		CP_Boss:
		PUSH offset combatBoss
		JMP CP_End
		CP_Awful:
		PUSH offset combatAwful  
		JMP CP_End
		CP_Strong:
		PUSH offset combatStrong   
		JMP CP_End
		CP_Weak:
		PUSH offset combatWeak  
		JMP CP_End
		CP_Weakest:
		PUSH offset combatWeakest

		CP_End:
		PUSH offset dataBuf
		PUSH offset combatBuf
		CALL patchConnectFormat

		PUSH offset combatBuf
		JMP		addrTargetReturn


	}
}


// NPC인척하기
NAKED void CPatcher_ShowCombatPower::patchIsNPC(void)
{
	// 전투력 스카우터 On
	if (IsPatchEnabled())
	{
		__asm {
			MOV		EAX, 1
			RETN
		}
	// 스카우터 Off
	} else {
		__asm {
			JMP		addrIsNPC
		}
	}
}

// NPC인척하기
NAKED void CPatcher_ShowCombatPower::patchIsNamedNPC(void)
{
	// 전투력 스카우터 On
	if (IsPatchEnabled())
	{
		__asm {
			MOV		EAX, 0
			RETN
		}
	// 스카우터 Off
	} else {
		__asm {
			JMP		addrIsNamedNPC
		}
	}
}

// 플레이어일때 1이 됨
NAKED void CPatcher_ShowCombatPower::patchIsCurrentPlayer(void)
{
	// 전투력 스카우터 On
	if (IsPatchEnabled())
	{
		__asm {
			MOV		EAX, 0
			RETN
		}
	// 스카우터 Off
	} else {
		__asm {
			JMP DWORD PTR DS:[EAX+1F0h]
		}
	}
}
/*
NAKED void CPatcher_ShowCombatPower::patchCP1(void)
{
	__asm {
		LEA		ECX, DWORD PTR SS:[EBP-10h] // [EBP-10h] is the CStringT object for the text prefixing the character name
		CALL	addrCStringTConstr			// No arguments -- init to ""
		AND     DWORD PTR SS:[EBP-4h], 0	// The Pleione code does this after initializing the CStringT...?

		PUSH	offset dataStrNull
		JMP     patchCP2
	}
}
*/
/* patchCP2 takes the string prefix on the stack, gets the target CP,
 * formats it with our formatting function, and fills our CStringT object
 * with the formatted text.
 */
/*
NAKED void CPatcher_ShowCombatPower::patchCP2(void)
{
	__asm {
		MOV		ECX, ESI					// ESI holds the "this" pointer... but what object are we?
		MOV		EAX, DWORD PTR DS:[ECX]		// EAX = vftable
		CALL	DWORD PTR DS:[EAX+4Ch]		// Returns the target ICharacter? (not 100% sure on that)
		MOV		ECX, EAX					// ECX should be our target ICharacter object now
		CALL	addrGetCombatPower

		SUB		ESP, 8h						// Allocate stack space for the CP value
		FSTP	QWORD PTR SS:[ESP]			// Store the CP value on the stack

		PUSH	offset dataBuf				// Push the CP value
		CALL	patchCPFormat				// Call our formatting function.  The string arg was pushed
											// either by the Pleione code (for enemies-- <mini>BOSS </mini>
											// or whatever) or by patchCP1.

		PUSH	offset dataBuf				// Our buffer was now filled with the formatted string
		LEA		ECX, DWORD PTR SS:[EBP-10h]	// Put the CStringT object into the "this" register...
		CALL	addrCStringTEquals			// and set its text to our formatted string!

		JMP		addrTargetReturn;			// Jump back to Pleione code.
	}
}
*/
/* patchCPFormat takes our string prefix, the CP value, and writes
 * into the buffer a complete prefix including both.
 */
void __stdcall CPatcher_ShowCombatPower::patchCPFormat(wchar_t * buff,double f)
{
	swprintf_s(buff,255,L"%.2f",f);
}

void __stdcall CPatcher_ShowCombatPower::patchConnectFormat(wchar_t * buff,wchar_t * str1,wchar_t * str2)
{
	swprintf_s(buff,255,L"%s%s ",str2, str1);
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_ShowCombatPower::ReadINI( void )
{
	if ( ReadINI_Bool( L"ShowCombatPower" ))
		return PatchEnable();
	return true;
}

bool CPatcher_ShowCombatPower::WriteINI( void )
{
	WriteINI_Bool( L"ShowCombatPower", IsPatchEnabled() );
	return true;
}