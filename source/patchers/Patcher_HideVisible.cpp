#include "Patcher_HideVisible.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

LPBYTE CPatcher_HideVisible::addrIsArenaField = NULL;

bool CPatcher_HideVisible::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_HideVisible::CPatcher_HideVisible( void )
{
	patchname = "하이드 캐릭터 보기";

	addrIsArenaField = CAddr::Addr(IRegion_IsArenaField);

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x8B, 0x08,						// +CA: MOV ECX,DWORD PTR DS:[EAX]
		0xFF, 0x57, -1,					// +CC: CALL DWORD PTR DS:[EDI+C]
		0x85, 0xC0,						// +CF: TEST EAX,EAX
		0x74, 0x10,						// +D1: JE SHORT 63A591E7
		0x8B, 0xC8,						// +D3: MOV ECX,EAX
		0xFF, 0x15, -1, -1, -1, -1,		// +D5: CALL DWORD PTR DS:[xxxxxxxx] (Standard.?IsArenaField@IRegion@core@@QBE?B_NXZ)
		0x84, 0xC0,						// +DB: TEST AL, AL
		0x0F, 0x85, -1, -1, -1, -1,		// +DD: JNZ 0xFFFFFF46
		0x33, 0xC0;						// +E3: XOR EAX, EAX

	funcPointer = (LPBYTE)patchHideVisible;

	patch +=
		0x8B, 0x08,
		0xFF, 0x57, -1,
		0x85, 0xC0,
		0x74, 0x10,
		0x8B, 0xC8,
		0xFF, 0x15,
		((int)(&funcPointer) & 0xFF),
		(((int)(&funcPointer) & 0xFF00) >> 8),
		(((int)(&funcPointer) & 0xFF0000) >> 16),
		(((int)(&funcPointer) & 0xFF000000) >> 24),
		0x84, 0xC0,
		0x0F, 0x85, -1, -1, -1, -1,
		0x33, 0xC0;

	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"Pleione.dll" );
	//mp.PatchExactAddress( 0x01, (LPBYTE)patchHideVisible );
	//mp.PatchRelativeAddress( 0x01, (LPBYTE)patchHideVisible );
	
	patches += mp;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_HideVisible::patchHideVisible(void)
{
	if (IsPatchEnabled())
	{
		__asm {
			MOV EAX, 1
			RETN
		}
	}
	else
	{
		__asm JMP addrIsArenaField
	}
}
//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_HideVisible::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_HideVisible::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_HideVisible::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_HideVisible::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_HideVisible::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_HideVisible::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_HideVisible::ReadINI( void )
{
	if ( ReadINI_Bool( L"HideVisible" ))
		return PatchEnable();
	return true;
}

bool CPatcher_HideVisible::WriteINI( void )
{
	WriteINI_Bool( L"HideVisible", IsPatchEnabled() );
	return true;
}