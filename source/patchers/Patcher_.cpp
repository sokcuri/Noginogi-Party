#include "Patcher_NameOfMod.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

bool CPatcher_NameOfMod::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_NameOfMod::CPatcher_NameOfMod( void )
{
	patchname = "NameOfMod";

	LPBYTE addrXXX = CAddr::Addr(kernel32_CreateRemoteThread);
	if (!addrXXX) {
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
		WriteLog("   종속 요소가 없습니다.\n");
		return;
	}

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x90, 0x90, 0x90;	// NOP

	funcPointer = (LPBYTE)patchNameOfMod;

	patch +=
		0x90, 0x90, 0x90;	// NOP -> NOP

	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"Target.dll" );
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

NAKED void CPatcher_NameOfMod::patchNameOfMod(void)
{

}
//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_NameOfMod::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_NameOfMod::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_NameOfMod::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_NameOfMod::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_NameOfMod::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_NameOfMod::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_NameOfMod::ReadINI( void )
{
	if ( ReadINI_Bool( L"NameOfMod" ))
		return PatchEnable();
	return true;
}

bool CPatcher_NameOfMod::WriteINI( void )
{
	WriteINI_Bool( L"NameOfMod", IsPatchEnabled() );
	return true;
}