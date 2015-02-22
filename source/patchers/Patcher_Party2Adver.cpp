#include "Patcher_Party2Adver.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

LPBYTE CPatcher_Party2Adver::addrAdvertiseBoard = NULL;
LPBYTE CPatcher_Party2Adver::addrPartyInlineCall = NULL;
LPBYTE CPatcher_Party2Adver::addrTargetReturn = NULL;

bool CPatcher_Party2Adver::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_Party2Adver::CPatcher_Party2Adver( void )
{
	patchname = "파티 게시판 스왑";

	vector<WORD> search1;
	vector<WORD> search2;
	vector<WORD> patch;
	vector<WORD> backup;

	// 광고지 보드 찾기
	search1 +=							
		0x6A, 0x08,							// +00: PUSH 3
		0xB8, -1, -1, -1, -1,				// +02: MOV EAX,xxxxxxxx
		0xE8, -1, -1, -1, -1,				// +07: CALL xxxxxxxx
		0x68, 0x25, 0x00, 0x00, 0x80,		// +0C: PUSH 80000025
		0xE8, -1, -1, -1, -1,				// +11: CALL xxxxxxxx
		0x8B, 0xC8,							// +16: MOV ECX, EAX
		0xE8, -1, -1, -1, -1,				// +18: CALL xxxxxxxx
		0x85, 0xC0;							// +1D: TEST EAX, EAX

	MemoryPatch ms1( NULL, search1, search1 );
	if (!ms1.Search( L"Pleione.dll" )) {
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
		return;
	}

	addrAdvertiseBoard = ms1.GetAddr();

	// 파티 게시판 +07h CALL 찾기
	search2 +=							
		0x50,											// +00: PUSH EAX
		0x64, 0xFF, 0x35, 0x00, 0x00, 0x00, 0x00,		// +01: PUSH DWORD PTR FS:[0]
		0x8D, 0x44, 0x24, 0x0C,							// +08: LEA EAX, DWORD PTR SS:[ESP+0Ch]
		0x2B, 0x64, 0x24, 0x0C,							// +0C: SUB ESP, DWORD PTR SS:[ESP+0Ch]
		0x53,											// +10: PUSH EBX
		0x56,											// +11: PUSH ESI
		0x57,											// +12: PUSH EDI
		0x89, 0x28,										// +13: MOV DWORD PTR DS:[EAX], EBP
		0x8B, 0xE8,										// +15: MOV EBP, EAX
		0xA1, -1, -1, -1, -1,							// +17: MOV EAX, DWORD PTR DS:[xxxxxxxx]
		0x33, 0xC5,										// +1C: XOR EAX, EBP
		0x50,											// +1E: PUSH EAX
		0xFF, 0x75, 0xFC,								// +1F: PUSH DWORD PTR SS:[EBP-04h]
		0xC7, 0x45, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF,		// +22: MOV DWORD PTR SS:[EBP-04h], -1
		0x8D, 0x45, 0xF4,								// +29: LEA EAX, DWORD PTR SS:[EBP-0Ch]
		0x64, 0xA3, 0x00, 0x00, 0x00, 0x00,				// +2C: MOV DWORD PTR FS:[0], EAX
		0xC3;											// +32: RETN

	MemoryPatch ms2( NULL, search2, search2 );
	if (!ms2.Search( L"Pleione.dll" )) {
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
		return;
	}

	addrPartyInlineCall = ms2.GetAddr();

	// 파티 게시판 수정
	backup +=
		0x6A, 0x24,						// +00: PUSH 24
		0xB8, -1, -1, -1, -1,			// +02: MOV EAX,xxxxxxxx
		0xE8, -1, -1, -1, -1,			// +07: CALL xxxxxxxx
		0x89, 0x4D, 0xE0,				// +0C: MOV DWORD PTR SS:[EBP-20],ECX
		0x8B, 0x35, -1, -1, -1, -1,		// +0F: MOV ESI,DWORD PTR DS:[xxxxxxxx] (Standard.?Instance@CFeatureMatrix@core@@SAAAV12@XZ)
		0x6A, 0x7A;						// +15: PUSH 7A

	funcPointer = (LPBYTE)patchParty2Adver;

	patch +=
		0x6A, 0x24,
		0xB8, -1, -1, -1, -1,
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x89, -1, -1,
		0x8B, -1, -1, -1, -1, -1,
		0x6A, 0x7A;

	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"Pleione.dll" );
	//mp.PatchExactAddress( 0x01, (LPBYTE)patchNameOfMod );
	mp.PatchRelativeAddress( 0x01, (LPBYTE)patchParty2Adver );

	patches += mp;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_Party2Adver::patchParty2Adver(void)
{
	// 스왑이 작동중일때
	if (IsPatchEnabled())
	{
		__asm {
			ADD		ESP, 4					// STACK POP (RETN ADDRESS)
			ADD		ESP, 4					// STACK POP (PARTY +00: PUSH 4)
			JMP		addrAdvertiseBoard
		}
	}
	// 작동을 하지 않을때
	else
	{
		__asm {
			JMP		addrPartyInlineCall
		}
	}
}
//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_Party2Adver::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_Party2Adver::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_Party2Adver::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_Party2Adver::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_Party2Adver::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_Party2Adver::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_Party2Adver::ReadINI( void )
{
	if ( ReadINI_Bool( L"Party2Adver" ))
		return PatchEnable();
	return true;
}

bool CPatcher_Party2Adver::WriteINI( void )
{
	WriteINI_Bool( L"Party2Adver", IsPatchEnabled() );
	return true;
}