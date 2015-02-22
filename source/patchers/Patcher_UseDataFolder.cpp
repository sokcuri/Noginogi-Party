#include "Patcher_UseDataFolder.h"
#include "../Addr.h"

//-----------------------------------------------------------------------------
// Constructor

CPatcher_UseDataFolder::CPatcher_UseDataFolder( void )
{
	patchname = "데이터 폴더 우선시";

	LPBYTE addrSetLookUpOrder = CAddr::Addr(CFileSystem_SetLookUpOrder);
	if (!addrSetLookUpOrder) {
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
		WriteLog("   종속 요소가 없습니다.\n");
		return;
	}

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x8B, 0x45, 0xEC,	// MOV EAX, [EBP-14h]
		0x8B, 0x40, 0x04,	// MOV EAX, [EAX+04h]
		0x8B, 0x40, 0x18,	// MOV EAX, [EAX+18h]
		0x83, 0xE8, 0x00;	// SUB EAX, 0  (wat?)

	patch +=
		0x8B, 0x45, 0xEC,
		-1, -1, -1,
		-1, -1, -1,
		-1, -1, 0x01;		// SUB EAX, 0 => SUB EAX, 1

	MemoryPatch mp( NULL, patch, backup );
	if (!mp.Search( L"ESL.dll" )) {
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
		return;
	}
	patches += mp;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_UseDataFolder::Install( void ) {
	if ( ReadINI_Bool( L"UseDataFolder" ))
		return Install2();
	return false;
}

bool CPatcher_UseDataFolder::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_UseDataFolder::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_UseDataFolder::ReadINI( void )
{
	return true;
}

bool CPatcher_UseDataFolder::WriteINI( void )
{
	WriteINI_Bool( L"UseDataFolder", IsInstalled() );
	return true;
}