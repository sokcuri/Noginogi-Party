#include "Patcher_DisableNighttime.h"
#include "../Addr.h"

//-----------------------------------------------------------------------------
// Static variable initialization

bool CPatcher_DisableNighttime::NightPatchEnabled = false;
bool CPatcher_DisableNighttime::SunPatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_DisableNighttime::CPatcher_DisableNighttime( void )
{
	patchname = "야간 효과 제거";

	LPBYTE addrSetSkyTime = CAddr::Addr(CAtmosphere_SetSkyTime);
	if (!addrSetSkyTime) {
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
		WriteLog("   종속 요소가 없습니다.\n");
		return;
	}

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		-1, -1, -1, -1, -1, -1;						// +00: No key (we are replacing the entire function)

	funcPointer = (LPBYTE)patchNighttime;

	patch +=
		0xFF, 0x25,									// +00: JMP patchNighttime
		((int)(&funcPointer) & 0xFF),
		(((int)(&funcPointer) & 0xFF00) >> 8),
		(((int)(&funcPointer) & 0xFF0000) >> 16),
		(((int)(&funcPointer) & 0xFF000000) >> 24);

	MemoryPatch mp( addrSetSkyTime, patch, backup );
	mp.PatchRelativeAddress( 0x01, (LPBYTE)patchNighttime );
	
	patches += mp;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_DisableNighttime::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_DisableNighttime::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_DisableNighttime::IsNightPatchEnabled(void)
{
	if (NightPatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_DisableNighttime::NightPatchEnable(void)
{
	NightPatchEnabled = true;
	return true;
}

bool CPatcher_DisableNighttime::NightPatchDisable(void)
{
	NightPatchEnabled = false;
	return true;
}

bool CPatcher_DisableNighttime::NightPatchToggle(void)
{
	if (IsNightPatchEnabled())
		NightPatchDisable();
	else NightPatchEnable();
	return true;
}

bool CPatcher_DisableNighttime::IsSunPatchEnabled(void)
{
	if (SunPatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_DisableNighttime::SunPatchEnable(void)
{
	SunPatchEnabled = true;
	return true;
}

bool CPatcher_DisableNighttime::SunPatchDisable(void)
{
	SunPatchEnabled = false;
	return true;
}

bool CPatcher_DisableNighttime::SunPatchToggle(void)
{
	if (IsSunPatchEnabled())
		SunPatchDisable();
	else SunPatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_DisableNighttime::patchNighttime(void)
{
	__asm {
		CMP NightPatchEnabled, 1
		JE jmp_start
		CMP SunPatchEnabled, 1
		JE jmp_start
		JMP jmp_original

		jmp_start:
		CMP NightPatchEnabled, 1
		JNZ		jmp_sun

//		jmp_night:
		MOV		EAX, DWORD PTR DS:[ECX]
		MOV		ECX, 3E2AAAADh				// 0x3E2AAAAD = 1/6 = 4:00
		CMP		ECX, DWORD PTR SS:[ESP+4h]
		JA		jmp_exit
		MOV		ECX, 3F400000h				// 0x3F400000 = 3/4 = 18:00
		CMP		ECX, DWORD PTR SS:[ESP+4h]
		JB		jmp_exit
		MOV		ECX, DWORD PTR SS:[ESP+4h]

		jmp_sun:
		CMP SunPatchEnabled, 1
		JNZ		jmp_exit

		MOV		EAX, DWORD PTR DS:[ECX]
		MOV		ECX, 3E2AAAADh				// 0x3E2AAAAD = 1/6 = 4:00
		CMP		ECX, DWORD PTR SS:[ESP+4h]
		JA		jmp_exit
		MOV		ECX, 3F400000h				// 0x3F400000 = 3/4 = 18:00
		CMP		ECX, DWORD PTR SS:[ESP+4h]
		JB		jmp_exit
		MOV		ECX, DWORD PTR SS:[ESP+4h]
		JMP		jmp_exit

		jmp_exit:								// ECX = time to set
		MOV		DWORD PTR DS:[EAX+0Ch], ECX
		RETN	4h

		jmp_original:
		MOV EAX,DWORD PTR DS:[ECX]
		FLD DWORD PTR SS:[ESP+4h]
		FSTP DWORD PTR DS:[EAX+0Ch]
		RETN 4h
	}
}

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_DisableNighttime::ReadINI( void )
{
	NightReadINI();
	SunReadINI();
	return true;
}

bool CPatcher_DisableNighttime::WriteINI( void )
{
	NightWriteINI();
	SunWriteINI();
	return true;
}

bool CPatcher_DisableNighttime::NightReadINI( void )
{
	if ( ReadINI_Bool( L"DisableNighttime" ))
		return NightPatchEnable();
	return true;
}

bool CPatcher_DisableNighttime::NightWriteINI( void )
{
	WriteINI_Bool( L"DisableNighttime", IsNightPatchEnabled() );
	return true;
}

bool CPatcher_DisableNighttime::SunReadINI( void )
{
	if ( ReadINI_Bool( L"DisableSuntime" ))
		return SunPatchEnable();
	return true;
}

bool CPatcher_DisableNighttime::SunWriteINI( void )
{
	WriteINI_Bool( L"DisableSuntime", IsSunPatchEnabled() );
	return true;
}
