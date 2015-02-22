#include "Patcher_BankTabEnable.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

BYTE CPatcher_BankTabEnable::dataCALL[4] = {0x00, 0x00, 0x00, 0x00};

bool CPatcher_BankTabEnable::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_BankTabEnable::CPatcher_BankTabEnable( void )
{
	patchname = "은행 탭 항상 열기";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x8B, 0xC8,								// +186: MOV ECX, EAX
		0xFF, 0xB0, -1, -1, -1, -1,				// +188: PUSH DWORD PTR DS:[EAX+C0]
		0xE8, -1, -1, -1, -1,					// +18E: CALL xxxxxxxx
		0x8B, 0xF8,								// +193: MOV EDI, EAX
		0x85, 0xFF,								// +195: TEST EDI, EDI
		0x0F, 0x84, -1, -1, -1, -1,				// +197: JE 0xF6
		0x8B, 0x87, 0x80, 0x00, 0x00, 0x00,		// +19D: MOV EAX,DWORD PTR DS:[EDI+80]
		0x8B, 0x80, -1, -1, -1, -1;				// +1A3: MOV EAX,DWORD PTR DS:[EAX+6BC]

	funcPointer = (LPBYTE)patchBankTabEnable;

	patch +=
		0x8B, 0xC8,
		0xFF, 0xB0, -1, -1, -1, -1,
		0xE8, -1, -1, -1, -1,
		0x8B, 0xF8,
		0xEB, 0x06,
		0x0F, 0x84, -1, -1, -1, -1,
		0xFF, 0x15,
		((int)(&funcPointer) & 0xFF),
		(((int)(&funcPointer) & 0xFF00) >> 8),
		(((int)(&funcPointer) & 0xFF0000) >> 16),
		(((int)(&funcPointer) & 0xFF000000) >> 24),
		0x8B, 0x80, -1, -1, -1, -1;

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

NAKED void CPatcher_BankTabEnable::patchBankTabEnable(void)
{
	// 작동중일때
	if(IsPatchEnabled())
	{
		__asm {
			SUB DWORD PTR DS:[ESP], 0Ch
			MOV EAX, 0
			TEST EAX, EAX
			RETN
		}
	}
	// 작동중이 아닐때
	else
	{
		__asm {
			TEST EDI, EDI
			JE JumpRutin
			MOV EAX,DWORD PTR DS:[EDI+80h]
			RETN
			JumpRutin:
			SUB DWORD PTR DS:[ESP], 0Ch
			RETN
		}
	}
}
//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_BankTabEnable::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_BankTabEnable::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_BankTabEnable::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_BankTabEnable::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_BankTabEnable::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_BankTabEnable::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_BankTabEnable::ReadINI( void )
{
	if ( ReadINI_Bool( L"BankTabEnable" ))
		return PatchEnable();
	return true;
}

bool CPatcher_BankTabEnable::WriteINI( void )
{
	WriteINI_Bool( L"BankTabEnable", IsPatchEnabled() );
	return true;
}