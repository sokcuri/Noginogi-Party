#include "Patcher_InframeWinPSV.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

bool CPatcher_InframeWinPSV::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_InframeWinPSV::CPatcher_InframeWinPSV( void )
{
	patchname = "인프레임 윈도우 보호";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x8B, -1, -1,
		0x3B, 0xF0,
		0x0F, 0x95, 0xC0,
		0x84, 0xC0,
		0x0F, 0x84, -1, -1, -1, -1,
		0x53;

	funcPointer = (LPBYTE)patchInframeWinPSV;

	patch +=
		0x8B, -1, -1,
		0xFF, 0x15,
		((int)(&funcPointer) & 0xFF),
		(((int)(&funcPointer) & 0xFF00) >> 8),
		(((int)(&funcPointer) & 0xFF0000) >> 16),
		(((int)(&funcPointer) & 0xFF000000) >> 24),
		0x90,
		0x0F, 0x84, -1, -1, -1, -1,
		0x53;

	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"Pleione.dll" );
	//mp.PatchExactAddress( 0x01, (LPBYTE)patchInframeWinPSV );
	//mp.PatchRelativeAddress( 0x01, (LPBYTE)patchInframeWinPSV );
	
	patches += mp;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_InframeWinPSV::patchInframeWinPSV(void)
{
	__asm {
		PUSH EAX
	}

	if (IsPatchEnabled())
	{
		__asm {
			POP EAX
			MOV EAX, 0
			TEST EAX, EAX
			RETN
		}
	}
	else
	{
		__asm {
			POP EAX
			CMP ESI, EAX
			SETNE AL
			TEST AL, AL
			RETN
		}
	}
}
//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_InframeWinPSV::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_InframeWinPSV::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_InframeWinPSV::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_InframeWinPSV::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_InframeWinPSV::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_InframeWinPSV::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_InframeWinPSV::ReadINI( void )
{
	if ( ReadINI_Bool( L"InframeWinPSV" ))
		return PatchEnable();
	return true;
}

bool CPatcher_InframeWinPSV::WriteINI( void )
{
	WriteINI_Bool( L"InframeWinPSV", IsPatchEnabled() );
	return true;
}