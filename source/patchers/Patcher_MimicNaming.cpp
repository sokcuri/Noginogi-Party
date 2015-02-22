#include "Patcher_MimicNaming.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

LPBYTE CPatcher_MimicNaming::addrIsPet = NULL;

bool CPatcher_MimicNaming::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_MimicNaming::CPatcher_MimicNaming( void )
{
	patchname = "미믹 이름표";

	addrIsPet = CAddr::Addr(ICharacter_IsPet);

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x85, 0xC0,									// +60: TEST EAX,EAX
		0x0F, 0x84, -1, -1, -1, -1,					// +62: JE xxxxxxxx
		0x8B, 0xCE,									// +68: MOV ECX,ESI
		0xE8, -1, -1, -1, -1,						// +6A: CALL xxxxxxxx (Standard.?IsPet@ICharacter@core@@QBE_NXZ)
		0x84, 0xC0,									// +6F: TEST AL, AL
		0x74, 0x16,									// +71: JE 0x16
		0x32, 0xDB;									// +73: XOR BL, BL

	patch +=
		0x85, 0xC0,
		-1, -1, -1, -1, -1, -1,
		-1, -1,
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		-1, -1,
		-1, -1,
		-1, -1;

	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"Standard.dll" );
	//mp.PatchExactAddress( 0x01, (LPBYTE)patchNameOfMod );
	mp.PatchRelativeAddress( 0x01, (LPBYTE)patchMimicNaming );
	
	patches += mp;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_MimicNaming::patchMimicNaming(void)
{
	// 미믹 이름표 보이기
	if(IsPatchEnabled())
	{
		__asm {
			MOV EAX, 1
			RETN
		}
	}
	// 미믹 이름표 안보이기
	else
	{
		__asm JMP addrIsPet
	}
}
//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_MimicNaming::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_MimicNaming::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_MimicNaming::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_MimicNaming::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_MimicNaming::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_MimicNaming::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_MimicNaming::ReadINI( void )
{
	if ( ReadINI_Bool( L"MimicNaming" ))
		return PatchEnable();
	return true;
}

bool CPatcher_MimicNaming::WriteINI( void )
{
	WriteINI_Bool( L"MimicNaming", IsPatchEnabled() );
	return true;
}