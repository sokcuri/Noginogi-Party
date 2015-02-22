#include "Patcher_SpaceUnlock.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

bool CPatcher_SpaceUnlock::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_SpaceUnlock::CPatcher_SpaceUnlock( void )
{
	patchname = "스페이스바 캐릭터 동결 해제";

	vector<WORD> patch1;
	vector<WORD> patch2;
	vector<WORD> backup1;
	vector<WORD> backup2;

	funcPointer = (LPBYTE)patchSpaceUnlock;

	backup1 +=
		0x74, 0x28,
		0x80, 0x7E, 0x32, 0x00,
		0x75, 0x22,
		0x6A, 0x01,
		0x8B, 0xCE,
		0xE8, -1, -1, -1, -1,
		0x8B, 0x8F;

	patch1 +=
		0x74, 0x28,
		0xFF, 0x15,
		((int)(&funcPointer) & 0xFF),
		(((int)(&funcPointer) & 0xFF00) >> 8),
		(((int)(&funcPointer) & 0xFF0000) >> 16),
		(((int)(&funcPointer) & 0xFF000000) >> 24),
		0x6A, 0x01,
		0x8B, 0xCE,
		0xE8, -1, -1, -1, -1,
		0x8B, 0x8F;

	MemoryPatch mp1( NULL, patch1, backup1 );
	mp1.Search( L"Pleione.dll" );

	backup2 +=
		0x90, 0x90, 0x90;	// NOP

	patch2 +=
		0x90, 0x90, 0x90;	// NOP -> NOP

	MemoryPatch mp2( NULL, patch2, backup2 );
	mp2.Search( L"Pleione.dll" );

	patches += mp1;
	patches += mp2;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_SpaceUnlock::patchSpaceUnlock(void)
{
	if (IsPatchEnabled())
	{
		__asm RETN
	}
	else
	{
		__asm
		{
			CMP BYTE PTR DS:[ESI+0x32],0
			JNZ lJump
			__asm RETN

			lJump:
			XOR EAX, EAX
			CMP EAX, EAX
			POP EAX
			SUB EAX, 2
			JMP EAX
		}
	}
}
//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_SpaceUnlock::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_SpaceUnlock::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_SpaceUnlock::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_SpaceUnlock::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_SpaceUnlock::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_SpaceUnlock::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_SpaceUnlock::ReadINI( void )
{
	if ( ReadINI_Bool( L"SpaceUnlock" ))
		return PatchEnable();
	return true;
}

bool CPatcher_SpaceUnlock::WriteINI( void )
{
	WriteINI_Bool( L"SpaceUnlock", IsPatchEnabled() );
	return true;
}