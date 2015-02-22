#include "Patcher_VisionInAllName.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

float CPatcher_VisionInAllName::VisionFloat = 3000.000;

bool CPatcher_VisionInAllName::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_VisionInAllName::CPatcher_VisionInAllName( void )
{
	patchname = "시야내 이름표";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0xD9, 0x05, -1, -1, -1, -1,		// +38C: FLD DWORD PTR DS:[xxxxxxxx]
		0xD8, 0x5B, -1,					// +392: FCOMP DWORD PTR DS:[EBX+54]
		0x66, 0x89, 0x43, -1,			// +395: MOV WORD PTR DS:[EBX+60],AX
		0xDF, 0xE0,						// +399: FSTSW AX
		0xF6, 0xC4, 0x41,				// +39B: TEST AH,41
		0x0F, 0x85, -1, -1, -1, -1,		// +39E: JNZ 0x23C
		0xD9, 0xEE,						// +3A4: FLDZ
		0xD8, 0xD1;						// +3A6: FCOM ST(1)

	patch +=
		0xD9, 0x05,
		((int)(&VisionFloat) & 0xFF),
		(((int)(&VisionFloat) & 0xFF00) >> 8),
		(((int)(&VisionFloat) & 0xFF0000) >> 16),
		(((int)(&VisionFloat) & 0xFF000000) >> 24),
		-1, -1, -1,
		-1, -1, -1, -1,
		0xDF, 0xE0,
		-1, -1, -1,
		-1, -1, -1, -1, -1, -1,
		-1, -1,
		-1, -1;

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
// 오버라이드 함수

bool CPatcher_VisionInAllName::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_VisionInAllName::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_VisionInAllName::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_VisionInAllName::PatchEnable(void)
{
	PatchEnabled = true;
	VisionFloat = 3000000.000;
	return true;
}

bool CPatcher_VisionInAllName::PatchDisable(void)
{
	PatchEnabled = false;
	VisionFloat = 3000.000;
	return true;
}

bool CPatcher_VisionInAllName::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_VisionInAllName::ReadINI( void )
{
	if ( ReadINI_Bool( L"VisionInAllName" ))
		return PatchEnable();
	return true;
}

bool CPatcher_VisionInAllName::WriteINI( void )
{
	WriteINI_Bool( L"VisionInAllName", IsPatchEnabled() );
	return true;
}