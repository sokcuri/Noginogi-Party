#include "Patcher_ShowItemPrice.h"
#include "../Addr.h"

//-----------------------------------------------------------------------------
// Static variable initialization

LPBYTE CPatcher_ShowItemPrice::addrTargetOn = NULL;
LPBYTE CPatcher_ShowItemPrice::addrTargetOff = NULL;

wchar_t CPatcher_ShowItemPrice::strPUSH[] = L"\x0A\x0A<color=0>";

bool CPatcher_ShowItemPrice::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_ShowItemPrice::CPatcher_ShowItemPrice( void )
{
	patchname = "아이템 상점가 보기";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x83, 0xF8, 0x02,					// +154: CMP EAX, 2
		0x0F, 0x85, 0x86, 0x01, 0x00, 0x00,	// +157: JNZ NEAR +186h
		0x68, -1, -1, -1, -1,				// +15D: PUSH xxxxxxxx (UNICODE "\x0A\x0A<color=0>")
		0x8B, 0xCE;							// +162: MOV ECX, ESI
	patch +=
		0xEB, 0x07, -1,						// +154: JMP 0x07
		-1, -1, -1, -1, -1, -1,
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x8B, 0xCE;
	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"Pleione.dll" );
	mp.PatchRelativeAddress( 0x01, (LPBYTE)patchShowItemPrice );

	addrTargetOn = mp.GetAddr() + 0x0E;
	addrTargetOff = mp.GetAddr() + 0x03;
	
	patches += mp;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}


//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_ShowItemPrice::patchShowItemPrice(void)
{
	__asm {
		PUSH EAX
	}

	if (IsPatchEnabled())
	{
		__asm {
			ADD ESP, 8
			PUSH offset strPUSH
			JMP addrTargetOn
		}
	}
	else
	{
		__asm {
			POP EAX
			CMP EAX, 3			// 상점가 표시여부 확인
			ADD ESP, 4
			JNZ lNonShow

			PUSH offset strPUSH
			JMP addrTargetOn	// 상점가 표시
			lNonShow:
			JMP addrTargetOff	// 상점가 표시안함
		}
	}
}
//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_ShowItemPrice::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_ShowItemPrice::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_ShowItemPrice::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_ShowItemPrice::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_ShowItemPrice::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_ShowItemPrice::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_ShowItemPrice::ReadINI( void )
{
	if ( ReadINI_Bool( L"ShowItemPrice" ))
		return PatchEnable();
	return true;
}

bool CPatcher_ShowItemPrice::WriteINI( void )
{
	WriteINI_Bool( L"ShowItemPrice", IsPatchEnabled() );
	return true;
}