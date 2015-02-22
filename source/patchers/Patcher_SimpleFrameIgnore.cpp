#include "Patcher_SimpleFrameIgnore.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization
LPBYTE CPatcher_SimpleFrameIgnore::addr__time = NULL;

bool CPatcher_SimpleFrameIgnore::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_SimpleFrameIgnore::CPatcher_SimpleFrameIgnore( void )
{
	patchname = "간소화 프레임 무시";

	addr__time = CAddr::Addr(ESL_ETC_TIME);

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x8B, 0x08,								// +119: MOV ECX,DWORD PTR DS:[EAX]
		0x8B, 0x01,								// +11B: MOV EAX,DWORD PTR DS:[ECX]
		0xFF, 0x90, -1, -1, -1, -1,				// +11D: CALL DWORD PTR DS:[EAX+178]
		0x03, 0x46, -1,							// +123: ADD EAX,DWORD PTR DS:[ESI+28]
		0x8B, 0x3D, -1, -1, -1, -1,				// +126: MOV EDI,DWORD PTR DS:[xxxxxxxx] (ESL.?__time@etc@esl@@YAKXZ)
		0xD1, 0xE8;								// +12C: SHR EAX, 1


	funcPointer = (LPBYTE)patchSimpleFrameIgnore;

	patch +=
		-1, -1,
		-1, -1,
		0xFF, 0x90, -1, -1, -1, -1,
		0x03, 0x46, -1,
		0xFF, 0x15, 
		((int)(&funcPointer) & 0xFF),
		(((int)(&funcPointer) & 0xFF00) >> 8),
		(((int)(&funcPointer) & 0xFF0000) >> 16),
		(((int)(&funcPointer) & 0xFF000000) >> 24),
		0xD1, 0xE8;

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

NAKED void CPatcher_SimpleFrameIgnore::patchSimpleFrameIgnore(void)
{
	__asm {
		MOV		EDI, addr__time
		PUSH	EAX
	}

	// 간소화 프레임 무시 작동중일때
	if (IsPatchEnabled())
	{
		__asm {
			POP		EAX
			MOV		EAX, 0
			RETN
		}
	}
	// 간소화 프레임 무시 작동중이 아닐때
	else
	{
		__asm {
			POP		EAX
			RETN
		}
	}
}
//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_SimpleFrameIgnore::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_SimpleFrameIgnore::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_SimpleFrameIgnore::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_SimpleFrameIgnore::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_SimpleFrameIgnore::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_SimpleFrameIgnore::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_SimpleFrameIgnore::ReadINI( void )
{
	if ( ReadINI_Bool( L"SimpleFrameIgnore" ))
		return PatchEnable();
	return true;
}

bool CPatcher_SimpleFrameIgnore::WriteINI( void )
{
	WriteINI_Bool( L"SimpleFrameIgnore", IsPatchEnabled() );
	return true;
}