#include "Patcher_DeadlyHPShow.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

wchar_t CPatcher_DeadlyHPShow::strDeadly[] = L"<color=4>DEADLY</color>";
wchar_t CPatcher_DeadlyHPShow::dataBuf[256];

LPBYTE CPatcher_DeadlyHPShow::addrGetLife = NULL;
LPBYTE CPatcher_DeadlyHPShow::addrTargetReturn = NULL;

bool CPatcher_DeadlyHPShow::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_DeadlyHPShow::CPatcher_DeadlyHPShow( void )
{
	patchname = "데들리 체력 표시";

	addrGetLife = CAddr::Addr(IParameterBase2_GetLife);

	vector<WORD> patch1;
	vector<WORD> patch2;
	vector<WORD> backup1;
	vector<WORD> backup2;
/*
	backup1 +=
		0x7D, 0x03,				// +105: JGE 0x03
		0x89, 0x45, 0xEC,		// +107: MOV DWORD PTR SS:[EBP-14],EAX
		0x3B, 0xF8,				// +10A: CMP EDI,EAX
		0x75, 0x0C,				// +10C: JNZ 0x0C
		0x39, 0x45, 0xEC,		// +10E: CMP DWORD PTR SS:[EBP-14],EAX
		0x75, 0x07,				// +111: JNZ 0x07
		0x68, -1, -1, -1, -1;	// +113: PUSH xxxxxxxx (UNICODE "<color=4>DEADLY</color>")

	patch1 +=
		0x7D, 0x03,
		0x89, 0x45, 0xEC,
		0x3B, 0xF8,
		0x75, 0x0C,
		0x39, 0x45, 0xEC,
		0x75, 0x07,
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF;

	MemoryPatch mp1( NULL, patch1, backup1 );
	mp1.Search( L"Pleione.dll" );
	//mp.PatchExactAddress( 0x01, (LPBYTE)patchDeadlyHPShow );
	mp1.PatchRelativeAddress( 0x01, (LPBYTE)patchDeadlyHPShow );
*/	
	backup2 +=
		0x7D, 0x03,				// +24E: JGE 0x03
		0x89, 0x45, 0xE4,		// +250: MOV DWORD PTR SS:[EBP-1C],EAX
		0x39, 0x45, 0xF0,		// +253: CMP DWORD PTR SS:[EBP-10],EAX
		0x75, 0x0C,				// +256: JNZ 0x0C
		0x39, 0x45, 0xE4,		// +258: CMP DWORD PTR SS:[EBP-1C],EAX
		0x75, 0x07,				// +25B: JNZ 0x07
		0x68, -1, -1, -1, -1;	// +25D: PUSH xxxxxxxx (UNICODE "<color=4>DEADLY</color>")

	patch2 +=
		0x7D, 0x03,
		0x89, 0x45, 0xE4,
		0x39, 0x45, 0xF0,
		0x75, 0x0C,
		0x39, 0x45, 0xE4,
		0x75, 0x07,
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF;

	MemoryPatch mp2( NULL, patch2, backup2 );
	mp2.Search( L"Pleione.dll" );
	//mp.PatchExactAddress( 0x01, (LPBYTE)patchDeadlyHPShow );
	mp2.PatchRelativeAddress( 0x01, (LPBYTE)patchDeadlyHPShow );
	/*
	backup3 +=
		0xFF, 0x50, 0x48,
		0xEB, 0x05,
		0x8B, 0x01,
		0xFF, 0x50, 0x40,
		0xC2, 0x04, 0x00s

	patch3 +=
		0x7D, 0x03,
		0x89, 0x45, 0xE4,
		0x39, 0x45, 0xF0,
		0x75, 0x0C,
		0x39, 0x45, 0xE4,
		0x75, 0x07,
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF;

	MemoryPatch mp3( NULL, patch3, backup3 );
	mp3.Search( L"Pleione.dll" );
	//mp.PatchExactAddress( 0x01, (LPBYTE)patchDeadlyHPShow );
	mp3.PatchRelativeAddress( 0x01, (LPBYTE)patchDeadlyHPShow );
	*/
	//patches += mp1;	
	patches += mp2;
	//patches += mp3;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_DeadlyHPShow::patchDeadlyHPShow(void)
{
	__asm {
		PUSH EAX
	}

	if (IsPatchEnabled())
	{
		__asm {
			POP EAX
			MOV ECX, EDI
			CALL addrGetLife
			SUB		ESP, 8h
			FSTP	QWORD PTR SS:[ESP]
			PUSH offset dataBuf
			CALL patchFormat
			POP ECX
			PUSH offset dataBuf
			JMP ECX
		}
	}
	else
	{
		__asm {
			POP EAX
			POP ECX
			PUSH offset strDeadly
			JMP ECX
		}
	}
}

void __stdcall CPatcher_DeadlyHPShow::patchFormat(wchar_t * buff,double f)
{
	wchar_t tmpbuff[256];
	swprintf_s(tmpbuff,255,L"%d",(int)f);
	swprintf_s(buff,255,L"<color=4>DEADLY</color> %s",tmpbuff);
}

//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_DeadlyHPShow::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_DeadlyHPShow::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_DeadlyHPShow::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_DeadlyHPShow::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_DeadlyHPShow::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_DeadlyHPShow::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_DeadlyHPShow::ReadINI( void )
{
	if ( ReadINI_Bool( L"DeadlyHPShow" ))
		return PatchEnable();
	return true;
}

bool CPatcher_DeadlyHPShow::WriteINI( void )
{
	WriteINI_Bool( L"DeadlyHPShow", IsPatchEnabled() );
	return true;
}