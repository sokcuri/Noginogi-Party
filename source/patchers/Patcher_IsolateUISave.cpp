#include "Patcher_IsolateUISave.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

char CPatcher_IsolateUISave::data64ua[256] = "2%I64u";
wchar_t CPatcher_IsolateUISave::data64uu[256] = L"2%I64u";
//-----------------------------------------------------------------------------
// Constructor

CPatcher_IsolateUISave::CPatcher_IsolateUISave( void )
{
	patchname = "UI 별도 저장";

	vector<WORD> patch1;
	vector<WORD> patch2;
	vector<WORD> backup1;
	vector<WORD> backup2;

	// UI 로드 파트
	backup1 +=
		0xFF, 0xD3,
		0xFF, 0xB7, 0xCC, 0x00, 0x00, 0x00,
		0xC7, 0x45, -1, -1, -1, -1, -1,
		0xFF, 0xB7, 0xC8, 0x00, 0x00, 0x00,
		0x68, -1, -1, -1, -1,
		0x50,
		0xFF, 0x15;

	patch1 +=
		0xFF, 0xD3,
		0xFF, 0xB7, 0xC8, 0x00, 0x00, 0x00,
		0xC7, 0x45, -1, -1, -1, -1, -1,
		0xFF, 0xB7, 0xCC, 0x00, 0x00, 0x00,
		0x68, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x50,
		0xFF, 0x15;

	MemoryPatch mp1( NULL, patch1, backup1 );
	mp1.Search( L"Pleione.dll" );
	mp1.PatchExactAddress( 0x01, (LPBYTE)data64uu );
	//mp1.PatchRelativeAddress( 0x01, (LPBYTE)data64uu );
	
	// UI 저장 파트
	backup2 +=
		0xFF, 0xD7,
		0x8B, 0xD8,
		0x8B, 0x4D, -1,
		0xC6, 0x45, -1, -1,
		0xFF, 0x15, -1, -1, -1, -1,
		0x52,
		0x50,
		0x68, -1, -1, -1, -1,
		0x56;

	patch2 +=
		0xFF, 0xD7,
		0x8B, 0xD8,
		0x8B, 0x4D, -1,
		0xC6, 0x45, -1, -1,
		0xFF, 0x15, -1, -1, -1, -1,
		0x50,
		0x52,
		0x68, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x56;

	MemoryPatch mp2( NULL, patch2, backup2 );
	mp2.Search( L"Pleione.dll" );
	mp2.PatchExactAddress( 0x01, (LPBYTE)data64ua );
	//mp2.PatchRelativeAddress( 0x01, (LPBYTE)data64ua );
	
	patches += mp1;
	patches += mp2;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_IsolateUISave::patchIsolateUISave(void)
{

}
//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_IsolateUISave::Install( void ) {
	if ( ReadINI_Bool( L"IsolateUISave" ))
		return Install2();
	return true;
}

bool CPatcher_IsolateUISave::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_IsolateUISave::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_IsolateUISave::ReadINI( void )
{
	return true;
}

bool CPatcher_IsolateUISave::WriteINI( void )
{
	return true;
}