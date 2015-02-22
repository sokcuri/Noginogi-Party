#include "Patcher_AnyPutSkillFx.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

bool CPatcher_AnyPutSkillFx::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_AnyPutSkillFx::CPatcher_AnyPutSkillFx( void )
{
	patchname = "스킬키에 아무거나 넣기";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x5B,								// -02: POP EBX
		0xC3,								// -01: RETN
		0x8B, 0x4C, 0x24, 0x04,				// +00: MOV ECX,DWORD PTR SS:[ESP+4h]
		0x85, 0xC9,							// +04: TEST ECX,ECX
		0x74, 0x13,							// +06: JE SHORT +0x13h
		0x68, -1, -1, -1, -1,				// +08: PUSH xxxxxxxx (UNICODE "/hotkey_bar/")
		0xFF, 0x15, -1, -1, -1, -1,			// +0D: CALL DWORD PTR DS:[xxxxxxxx] (Standard.?CheckFastStringID@IItem@core@@QBE_NPB_W@Z)
		0x84, 0xC0,							// +13: TEST AL,AL
		0x74, 0x04;							// +15: JE SHORT +0x04h

	funcPointer = (LPBYTE)patchAnyPutSkillFx;

	patch +=
		0x5B,
		0xC3,
		0xFF, 0x15,
		((int)(&funcPointer) & 0xFF),
		(((int)(&funcPointer) & 0xFF00) >> 8),
		(((int)(&funcPointer) & 0xFF0000) >> 16),
		(((int)(&funcPointer) & 0xFF000000) >> 24),
		0x74, 0x13,
		-1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1,
		-1, -1,
		-1, -1;

	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"Pleione.dll" );
	//mp.PatchExactAddress( 0x01, (LPBYTE)patchNameOfMod );
	//mp.PatchRelativeAddress( 0x01, (LPBYTE)patchNameOfMod );
	
	patches += mp;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_AnyPutSkillFx::patchAnyPutSkillFx(void)
{
	// 작동중일때
	if (IsPatchEnabled())
	{
		__asm {
			POP		EAX
			MOV		EAX, 1
			RETN	4
		}
	}
	// 작동중이 아닐때
	else
	{
		__asm {
			MOV ECX,DWORD PTR SS:[ESP+8]
			TEST ECX, ECX
			RETN
		}
	}
}
//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_AnyPutSkillFx::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_AnyPutSkillFx::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_AnyPutSkillFx::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_AnyPutSkillFx::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_AnyPutSkillFx::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_AnyPutSkillFx::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_AnyPutSkillFx::ReadINI( void )
{
	if ( ReadINI_Bool( L"AnyPutSkillFx" ))
		return PatchEnable();
	return true;
}

bool CPatcher_AnyPutSkillFx::WriteINI( void )
{
	WriteINI_Bool( L"AnyPutSkillFx", IsPatchEnabled() );
	return true;
}