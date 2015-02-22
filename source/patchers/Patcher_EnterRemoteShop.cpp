#include "Patcher_EnterRemoteShop.h"
#include "../Addr.h"

//-------------------------------------------------------------------
// Local variables
float CPatcher_EnterRemoteShop::fl = 300;

bool CPatcher_EnterRemoteShop::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_EnterRemoteShop::CPatcher_EnterRemoteShop( void )
{
	patchname = "개인상점 멀리서 열기";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0xD9, 0x5D, 0xF0,				// +117: FSTP [EBP-10]
		0xD9, 0x05, -1, -1, -1, -1,		// +11A: FLD xxxxxxxx
		0xD8, 0x5D, 0xF0,				// +120: FCOMP [EBP-10]
		0xDF, 0xE0,						// +123: FSTSW AX
		0xF6, 0xC4, 0x01,				// +125: TEST AH, 1
		0x75, 0x15;						// +128: JNZ SHORT +15

	patch +=
		-1, -1, -1,
		-1, -1,
		((int)(&fl) & 0xFF),
		(((int)(&fl) & 0xFF00) >> 8),
		(((int)(&fl) & 0xFF0000) >> 16),
		(((int)(&fl) & 0xFF000000) >> 24),
		-1, -1, -1,
		-1, -1,
		-1, -1, -1,
		0x75, 0x15;						// +128: JNZ => NOP

	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"Pleione.dll" );
	
	patches += mp;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_EnterRemoteShop::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_EnterRemoteShop::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_EnterRemoteShop::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_EnterRemoteShop::PatchEnable(void)
{
	PatchEnabled = true;
	fl = 5000;
	return true;
}

bool CPatcher_EnterRemoteShop::PatchDisable(void)
{
	PatchEnabled = false;
	fl = 300.0;
	return true;
}

bool CPatcher_EnterRemoteShop::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_EnterRemoteShop::ReadINI( void )
{
	if ( ReadINI_Bool( L"EnterRemoteShop" ))
		return PatchEnable();
	return true;
}

bool CPatcher_EnterRemoteShop::WriteINI( void )
{
	WriteINI_Bool( L"EnterRemoteShop", IsPatchEnabled() );
	return true;
}