#include "Patcher_FarSignRead.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

LPBYTE CPatcher_FarSignRead::addrTargetJump = NULL;
LPBYTE CPatcher_FarSignRead::addrTargetReturn = NULL;

bool CPatcher_FarSignRead::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_FarSignRead::CPatcher_FarSignRead( void )
{
	patchname = "멀리서 표지판 읽기";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0xDF, 0xE0,			// +E5: FSTSW AX
		0xF6, 0xC4, 0x41,	// +E7: TEST AH,41
		0x7A, 0x0B,			// +EA: JPE 0x0B
		0x8D, 0x45, 0xF0,	// +EC: LEA EAX,DWORD PTR SS:[EBP-10]
		0x50,				// +EF: PUSH EAX
		0x8D, 0x4D, 0xE8;	// +F0: LEA ECX,DWORD PTR SS:[EBP-18]

	funcPointer = (LPBYTE)patchFarSignRead;

	patch +=
		0xFF, 0x25,
		((int)(&funcPointer) & 0xFF),
		(((int)(&funcPointer) & 0xFF00) >> 8),
		(((int)(&funcPointer) & 0xFF0000) >> 16),
		(((int)(&funcPointer) & 0xFF000000) >> 24),
		0x90,
		0x8D, 0x45, 0xF0,
		0x50,
		0x8D, 0x4D, 0xE8;

	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"Pleione.dll" );
	//mp.PatchExactAddress( 0x01, (LPBYTE)patchFarSignRead );
	//mp.PatchRelativeAddress( 0x01, (LPBYTE)patchFarSignRead );
	
	addrTargetJump = mp.GetAddr() + 0x12;
	addrTargetReturn = mp.GetAddr() + 0x07;

	patches += mp;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_FarSignRead::patchFarSignRead(void)
{
	__asm {
		PUSH EAX
	}

	if (IsPatchEnabled())
	{
		__asm {
			POP EAX
			JMP addrTargetReturn
		}
	}
	else
	{
		__asm {
			POP EAX
			FSTSW AX
			TEST AH,41
			JPE lFarJump
			JMP addrTargetReturn

			lFarJump:
			JMP addrTargetJump
		}
	}
}
//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_FarSignRead::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_FarSignRead::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_FarSignRead::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_FarSignRead::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_FarSignRead::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_FarSignRead::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_FarSignRead::ReadINI( void )
{
	if ( ReadINI_Bool( L"FarSignRead" ))
		return PatchEnable();
	return true;
}

bool CPatcher_FarSignRead::WriteINI( void )
{
	WriteINI_Bool( L"FarSignRead", IsPatchEnabled() );
	return true;
}