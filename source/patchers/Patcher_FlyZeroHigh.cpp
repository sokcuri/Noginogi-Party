#include "Patcher_FlyZeroHigh.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

float CPatcher_FlyZeroHigh::HighFloat1 = 1000.000;
float CPatcher_FlyZeroHigh::HighFloat2 = 1500.000;
double CPatcher_FlyZeroHigh::HighFloat3 = 500.000;

LPBYTE CPatcher_FlyZeroHigh::addrTargetJump = NULL;
LPBYTE CPatcher_FlyZeroHigh::addrTargetMsg = NULL;

bool CPatcher_FlyZeroHigh::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_FlyZeroHigh::CPatcher_FlyZeroHigh( void )
{
	patchname = "제로 고도 비행";

	vector<WORD> patch;
	vector<WORD> patch2;
	vector<WORD> backup;
	vector<WORD> backup2;

	backup +=
		0x3D, 0x2C, 0x01, 0x00, 0x00,		// +72: CMP EAX,12C
		0x74, 0x19,							// +77: JE 0x19
		0x8B, 0x06,							// +79: MOV EAX,DWORD PTR DS:[ESI]
		0x8B, 0xCE,							// +7B: MOV ECX,ESI
		0xFF, 0x90, -1, -1, -1, -1,			// +7D: CALL DWORD PTR DS:[EAX+1DC]
		0x3D, 0x91, 0x01, 0x00, 0x00,		// +83: CMP EAX,191
		0x74, 0x08,							// +88: JE 0x08
		0xD9, 0x05, -1, -1, -1, -1,			// +8A: FLD DWORD PTR DS:[xxxxxxxx] (FLOAT 1000.000)
		0xEB, 0x06,							// +90: JMP 0x06
		0xD9, 0x05, -1, -1, -1, -1,			// +92: FLD DWORD PTR DS:[xxxxxxxx] (FLOAT 1500.000)
		0xE8;								// +98: CALL xxxxxxxx

	patch +=
		-1, -1, -1, -1, -1,
		-1, -1,
		-1, -1,
		-1, -1,
		-1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1,
		-1, -1,
		0xD9, 0x05,
		((int)(&HighFloat1) & 0xFF),
		(((int)(&HighFloat1) & 0xFF00) >> 8),
		(((int)(&HighFloat1) & 0xFF0000) >> 16),
		(((int)(&HighFloat1) & 0xFF000000) >> 24),
		0xEB, 0x06,
		0xD9, 0x05,
		((int)(&HighFloat2) & 0xFF),
		(((int)(&HighFloat2) & 0xFF00) >> 8),
		(((int)(&HighFloat2) & 0xFF0000) >> 16),
		(((int)(&HighFloat2) & 0xFF000000) >> 24),
		0xE8;

	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"Pleione.dll" );


	// 15m 고도제한 수정이염
	backup2 +=
		0xDD, 0x5D, 0x50,				// +19F: FSTP QWORD PTR SS:[EBP+50]
		0xE8, -1, -1, -1, -1,			// +1A2: CALL xxxxxxxx
		0xDC, 0x05, -1, -1, -1, -1,		// +1A7: FADD QWORD PTR DS:[xxxxxxxx]
		0xDC, 0x5D, 0x50,				// +1AD: FCOMP QWORD PTR SS:[EBP+50]
		0xDF, 0xE0,						// +1B0: FSTSW AX
		0xF6, 0xC4, 0x41,				// +1B2: TEST AH, 41
		0x0F, 0x8A, -1, -1, -1, -1;		// +1B5: JPE 0x8A

	funcPointer = (LPBYTE)patchFlyZeroHigh;

	patch2 +=
		-1, -1, -1,
		-1, -1, -1, -1, -1,
		0xFF, 0x25,
		((int)(&funcPointer) & 0xFF),
		(((int)(&funcPointer) & 0xFF00) >> 8),
		(((int)(&funcPointer) & 0xFF0000) >> 16),
		(((int)(&funcPointer) & 0xFF000000) >> 24),
		0xDC, 0x5D, 0x50,
		-1, -1,
		-1, -1, -1,
		0x0F, 0x81, -1, -1, -1, -1;

	MemoryPatch mp2( NULL, patch2, backup2 );
	mp2.Search( L"Pleione.dll" );

	addrTargetJump = mp2.GetAddr() + 0x16;
	addrTargetMsg = mp2.GetAddr() + 0x1C;
	
	patches += mp;
	patches += mp2;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_FlyZeroHigh::patchFlyZeroHigh(void)
{
	__asm {
		PUSH EAX
	}

	if (IsPatchEnabled())
	{
		__asm {
			POP EAX
			JMP DWORD PTR DS:[addrTargetJump]
		}
	}
	else
	{
		__asm {
			POP EAX
			FADD QWORD PTR DS:[HighFloat3]
			FCOMP QWORD PTR SS:[EBP+0x50]
			FSTSW AX
			TEST AH, 41h
			JPE ParityJump
			JMP DWORD PTR DS:[addrTargetMsg]
			ParityJump:
			JMP DWORD PTR DS:[addrTargetJump]
		}
	}
}

//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_FlyZeroHigh::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_FlyZeroHigh::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_FlyZeroHigh::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_FlyZeroHigh::PatchEnable(void)
{
	HighFloat1 = 0.000;
	HighFloat2 = 0.000;
	HighFloat3 = 0.000;
	PatchEnabled = true;
	return true;
}

bool CPatcher_FlyZeroHigh::PatchDisable(void)
{
	HighFloat1 = 1000.000;
	HighFloat2 = 1500.000;
	HighFloat3 = 500.000;
	PatchEnabled = false;
	return true;
}

bool CPatcher_FlyZeroHigh::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_FlyZeroHigh::ReadINI( void )
{
	if ( ReadINI_Bool( L"FlyZeroHigh" ))
		return PatchEnable();
	return true;
}

bool CPatcher_FlyZeroHigh::WriteINI( void )
{
	WriteINI_Bool( L"FlyZeroHigh", IsPatchEnabled() );
	return true;
}