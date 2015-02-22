#include "Patcher_TargetProps.h"
#include "../Addr.h"

//-----------------------------------------------------------------------------
// Static variable initialization

wchar_t CPatcher_TargetProps::dataStr[50] = L"enemy";

bool CPatcher_TargetProps::PatchEnabled = false;

//-----------------------------------------------------------------------------
// Constructor

CPatcher_TargetProps::CPatcher_TargetProps( void )
{
	patchname = "프롭 타켓팅";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x75, 0x07,							// +60: JNZ SHORT +0x07
		0x68, -1, -1, -1, -1,				// +62: PUSH OFFSET xxxxxxxx ("enemy")
		0xEB, 0x05,							// +67: JMP SHORT +0x05
		0x68, -1, -1, -1, -1,				// +69: PUSH OFFSET xxxxxxxx ("enemy > npc")
		0xFF, 0x15, -1, -1, -1, -1,			// +6E: CALL DWORD PTR DS:[<&ESL.??4?$CStringT@_>;]
		0x8B, 0x8F;							// +74: MOV ECX,DWORD PTR DS:[EDI+88]



	patch +=
		-1, -1,
		-1,
		((int)(&dataStr) & 0xFF),
		(((int)(&dataStr) & 0xFF00) >> 8),
		(((int)(&dataStr) & 0xFF0000) >> 16),
		(((int)(&dataStr) & 0xFF000000) >> 24),
		-1, -1,
		-1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1,
		-1, -1;

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

bool CPatcher_TargetProps::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_TargetProps::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_TargetProps::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_TargetProps::PatchEnable(void)
{
	PatchEnabled = true;
	wcscpy_s(dataStr, sizeof(dataStr), L"enemy|prop");
	return true;
}

bool CPatcher_TargetProps::PatchDisable(void)
{
	PatchEnabled = false;
	wcscpy_s(dataStr, sizeof(dataStr), L"enemy");
	return true;
}

bool CPatcher_TargetProps::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_TargetProps::ReadINI( void )
{
	if ( ReadINI_Bool( L"TargetProps" ))
		return PatchEnable();
	return true;
}

bool CPatcher_TargetProps::WriteINI( void )
{
	WriteINI_Bool( L"TargetProps", IsPatchEnabled() );
	return true;
}