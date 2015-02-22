#include "Patcher_NPCEquipView.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

LPBYTE CPatcher_NPCEquipView::addrIsNPC = NULL;

bool CPatcher_NPCEquipView::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_NPCEquipView::CPatcher_NPCEquipView( void )
{
	patchname = "NPC 장비보기";

	addrIsNPC = CAddr::Addr(ICharacter_IsNPC);

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0xE8, -1, -1, -1, -1,			// CALL xxxxxxxx
		0x8B, 0xCB,						// MOV ECX,EBX
		0xFF, 0x15, -1, -1, -1, -1,		// CALL DWORD PTR DS:[xxxxxxxx] (Standard.?IsNPC@ICharacter@core@@QBE_NXZ)
		0x84, 0xC0,						// TEST AL, AL
		0x0F, 0x85, -1, -1, -1, -1,		// JNZ 0xEA
		0x6A, 0x2C;						// PUSH 2C

	funcPointer = (LPBYTE)patchNPCEquipView;

	patch +=
		0xE8, -1, -1, -1, -1,
		0x8B, 0xCB,
		0xFF, 0x15,
		((int)(&funcPointer) & 0xFF),
		(((int)(&funcPointer) & 0xFF00) >> 8),
		(((int)(&funcPointer) & 0xFF0000) >> 16),
		(((int)(&funcPointer) & 0xFF000000) >> 24),
		0x84, 0xC0,
		0x0F, 0x85, -1, -1, -1, -1,
		0x6A, 0x2C;

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

NAKED void CPatcher_NPCEquipView::patchNPCEquipView(void)
{
	// NPC 장비보기가 작동중일 때
	if (IsPatchEnabled())
	{
		__asm {
			MOV EAX, 0
			RETN
		}
	}
	// NPC 장비보기가 작동중이 아닐 때
	else
	{
		__asm JMP addrIsNPC // IsNPC::ICharacter로 점프
	}
}
//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_NPCEquipView::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_NPCEquipView::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_NPCEquipView::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_NPCEquipView::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_NPCEquipView::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_NPCEquipView::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_NPCEquipView::ReadINI( void )
{
	if ( ReadINI_Bool( L"NPCEquipView" ))
		return PatchEnable();
	return true;
}

bool CPatcher_NPCEquipView::WriteINI( void )
{
	WriteINI_Bool( L"NPCEquipView", IsPatchEnabled() );
	return true;
}