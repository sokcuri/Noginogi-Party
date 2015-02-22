#include "Patcher_MoveWhileTalking.h"
#include "../Addr.h"

//-----------------------------------------------------------------------------
// Static variable initialization
LPBYTE CPatcher_MoveWhileTalking::addrTargetReturn = NULL;
LPBYTE CPatcher_MoveWhileTalking::funcPointer = NULL;

bool CPatcher_MoveWhileTalking::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_MoveWhileTalking::CPatcher_MoveWhileTalking( void )
{
	patchname = "NPC 이벤트 이동";
    
	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x56,								// +00: PUSH ESI
		0x8B, 0xF1,							// +01: MOV ESI, ECX
		0xE8, -1, -1, -1, -1,				// +03: CALL xxxxxxxx
		0x83, 0x78, 0x4C, 0x00,				// +08: CMP DWORD PTR [EAX+4Ch], 0
		0x74, 0x13,							// +0C: JZ SHORT +13h
		0x8B, 0x06,							// +0E: MOV EAX, [ESI]
		0x8B, 0xCE,							// +10: MOV ECX, ESI
		0xFF, 0x90, -1, -1, -1, -1,			// +12: CALL DWORD PTR [EAX+1F4h]
		0x84, 0xC0,							// +18: TEST AL, AL
		0x74, 0x05,							// +1A: JE SHRT +05h
		0x33, 0xC0;							// +1C: XOR EAX, EAX

	funcPointer = (LPBYTE)patchMoveWhileTalking;

	patch +=
		-1,
		-1, -1,
		-1, -1, -1, -1, -1,
		-1, -1, -1, -1,
		-1, -1,
		-1, -1,
		-1, -1,
		-1, -1, -1, -1, -1, -1,
		0xFF, 0x15,
		((int)(&funcPointer) & 0xFF),
		(((int)(&funcPointer) & 0xFF00) >> 8),
		(((int)(&funcPointer) & 0xFF0000) >> 16),
		(((int)(&funcPointer) & 0xFF000000) >> 24);

	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"Pleione.dll" );

	addrTargetReturn = mp.GetAddr() + 0x1E;
	
	patches += mp;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions
NAKED void CPatcher_MoveWhileTalking::patchMoveWhileTalking( void )
{
		__asm {
		PUSH	EAX
	}

	if (IsPatchEnabled())
	{
		__asm {
			POP EAX
			ADD ESP, 4			// unstack
			XOR EAX,EAX
			POP ESI
			RETN
		}
	}
	else
	{
		__asm {
			POP EAX
			ADD ESP, 4
			TEST AL,AL
			JE lEnd
			XOR EAX,EAX
			Jmp addrTargetReturn

			lEnd:
			XOR EAX,EAX
			INC EAX
			POP ESI
			RETN
		}
	}
}

//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_MoveWhileTalking::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_MoveWhileTalking::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_MoveWhileTalking::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_MoveWhileTalking::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_MoveWhileTalking::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_MoveWhileTalking::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_MoveWhileTalking::ReadINI( void )
{
	if ( ReadINI_Bool( L"MoveWhileTalking" ))
		return PatchEnable();
	return true;
}

bool CPatcher_MoveWhileTalking::WriteINI( void )
{
	WriteINI_Bool( L"MoveWhileTalking", IsPatchEnabled() );
	return true;
}