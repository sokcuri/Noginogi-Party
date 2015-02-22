#include "Patcher_MinuteClock.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

bool CPatcher_MinuteClock::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_MinuteClock::CPatcher_MinuteClock( void )
{
	patchname = "분단위 시계";

	vector<WORD> patch1;
	vector<WORD> patch2;
	vector<WORD> backup1;
	vector<WORD> backup2;

	backup1 +=
		0x89, 0x45, 0x54,				// +8D: MOV DWORD PTR SS:[EBP+54],EAX
		0x8B, 0x45, 0x4C,				// +90: MOV EAX,DWORD PTR SS:[EBP+4Ch]
		0x6A, 0x0A,						// +93: PUSH 0Ah
		0x59,							// +95: POP ECX
		0x33, 0xD2,						// +96: XOR EDX,EDX
		0xF7, 0xF1;						// +98: DIV ECX

	funcPointer = (LPBYTE)patchMinuteClock;

	patch1 +=
		-1, -1, -1,
		0xFF, 0x15, 
		((int)(&funcPointer) & 0xFF),
		(((int)(&funcPointer) & 0xFF00) >> 8),
		(((int)(&funcPointer) & 0xFF0000) >> 16),
		(((int)(&funcPointer) & 0xFF000000) >> 24),
		-1, -1,
		-1, -1;

	MemoryPatch mp1( NULL, patch1, backup1 );
	mp1.Search( L"Pleione.dll" );

	backup2 +=
		0xE9, -1, -1, -1, -1,			// +8D: JMP xxxxxxxx
		0x8B, 0x45, 0x4C,				// +90: MOV EAX,DWORD PTR SS:[EBP+4Ch]
		0x6A, 0x0A,						// +93: PUSH 0Ah
		0x59,							// +95: POP ECX
		0x33, 0xD2,						// +96: XOR EDX,EDX
		0xF7, 0xF1;						// +98: DIV ECX

	funcPointer = (LPBYTE)patchMinuteClock;

	patch2 +=
		0xE9, -1, -1, -1, -1,
		0xFF, 0x15, 
		((int)(&funcPointer) & 0xFF),
		(((int)(&funcPointer) & 0xFF00) >> 8),
		(((int)(&funcPointer) & 0xFF0000) >> 16),
		(((int)(&funcPointer) & 0xFF000000) >> 24),
		-1, -1,
		-1, -1;

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

NAKED void CPatcher_MinuteClock::patchMinuteClock(void)
{
	__asm {
		MOV		EAX, DWORD PTR SS:[EBP+4Ch]		// +90: MOV EAX, DWORD PTR SS:[EBP+4Ch]
		PUSH	EAX								// EAX 스택. 함수호출후 바뀌기 때문에
	}

	// 분단위 시계가 작동할때
	if (IsPatchEnabled())
	{
		__asm {
			POP		EAX							// POP EAX
			PUSH	1h							// PUSH 0Ah -> PUSH 1h
			POP		ECX
			RETN
		}
	}
	// 작동하지 않는 상태
	else
	{
		__asm {
			POP		EAX							// POP EAX
			PUSH	0Ah							// PUSH 0Ah (10으로 나눠서 분단위 안보이게함)
			POP		ECX
			RETN
		}
	}
}
//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_MinuteClock::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_MinuteClock::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_MinuteClock::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_MinuteClock::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_MinuteClock::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_MinuteClock::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_MinuteClock::ReadINI( void )
{
	if ( ReadINI_Bool( L"MinuteClock" ))
		return PatchEnable();
	return true;
}

bool CPatcher_MinuteClock::WriteINI( void )
{
	WriteINI_Bool( L"MinuteClock", IsPatchEnabled() );
	return true;
}