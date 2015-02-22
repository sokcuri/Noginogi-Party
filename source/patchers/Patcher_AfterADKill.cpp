#include "Patcher_AfterADKill.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_AfterADKill::CPatcher_AfterADKill( void )
{
	patchname = "게임 종료 광고 제거";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x84, 0xC0,				// +550: TEST AL,AL
		0x74, 0x02,				// +552: JE 0x02
		0x32, 0xDB,				// +554: XOR BL, BL
		0x84, 0xDB,				// +556: TEST BL, BL
		0x74, 0x29,				// +558: JE 0x29
		0x8D, 0x4D, 0xEC,		// +55A: LEA ECX,DWORD PTR SS:[EBP-14]
		0xFF, 0x15;				// +55D: CALL DWORD PTR DS:[xxxxxxxx] (ESL.?GetLength@?$CStringT@_WVunicode_string_trait@esl@@Vunicode_string_implement@2@@esl@@QBEKXZ)

	patch +=
		0x84, 0xC0,
		-1, -1,
		-1, -1,
		-1, -1,
		0xEB, -1,
		-1, -1, -1,
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

bool CPatcher_AfterADKill::Install( void ) {
	if ( ReadINI_Bool( L"AfterADKill" ))
		// INI가 존재하면 설치
		return Install2();
	return true;
}
bool CPatcher_AfterADKill::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_AfterADKill::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_AfterADKill::ReadINI( void )
{
	return true;
}

bool CPatcher_AfterADKill::WriteINI( void )
{
	return true;
}