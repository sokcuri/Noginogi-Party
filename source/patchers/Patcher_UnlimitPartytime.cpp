#include "Patcher_UnlimitPartytime.h"
#include "../Addr.h"

//-----------------------------------------------------------------------------
// Static variable initialization

bool CPatcher_UnlimitPartytime::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_UnlimitPartytime::CPatcher_UnlimitPartytime( void )
{
	patchname = "파티창 모집시간 무제한";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x80, 0x7E, -1, 0x00,	// +0C: CMP BYTE PTR DS:[ESI+8],0
		0x74, -1,				// +10: JE
		0x8B, 0x44, -1, -1,		// +12; MOV EAX,DWORD PTR SS:[ESP+8]
		0x3B, 0x46, 0x0C,		// +16: CMP EAX,DWORD PTR DS:[ESI+C]
		0x76, -1,				// +19: JBE
		0x8B, 0xCE,				// +1B: MOV ECX,ESI
		0xE8;					// +1D: CALL xxxxxxxx

	funcPointer = (LPBYTE)patchUnlimitPartytime;

	patch +=
		-1, -1, -1, -1,
		-1, -1,
		0xFF, 0x15,
		((int)(&funcPointer) & 0xFF),
		(((int)(&funcPointer) & 0xFF00) >> 8),
		(((int)(&funcPointer) & 0xFF0000) >> 16),
		(((int)(&funcPointer) & 0xFF000000) >> 24),
		0x90,
		-1, -1,
		-1, -1,
		-1;

	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"Pleione.dll" );

	patches += mp;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}


//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_UnlimitPartytime::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_UnlimitPartytime::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_UnlimitPartytime::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_UnlimitPartytime::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_UnlimitPartytime::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_UnlimitPartytime::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_UnlimitPartytime::patchUnlimitPartytime(void)
{
	if (IsPatchEnabled())
	{
		__asm {
			MOV EAX, 0
			TEST AL, AL
			RETN
		}
	}
	else
	{
		__asm {
			MOV EAX,DWORD PTR SS:[ESP+0x04+0x8]
			CMP EAX,DWORD PTR DS:[ESI+0xC]
			RETN
		}
	}
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_UnlimitPartytime::ReadINI( void )
{
	if ( ReadINI_Bool( L"UnlimitPartyTime" ))
		return PatchEnable();
	return true;
}

bool CPatcher_UnlimitPartytime::WriteINI( void )
{
	WriteINI_Bool( L"UnlimitPartyTime", IsPatchEnabled() );
	return true;
}