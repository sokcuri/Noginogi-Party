#include "Patcher_AlwaysBagView.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

LPBYTE CPatcher_AlwaysBagView::addrTargetReturn = NULL;
LPBYTE CPatcher_AlwaysBagView::addrIsUsableContents = NULL;

bool CPatcher_AlwaysBagView::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_AlwaysBagView::CPatcher_AlwaysBagView( void )
{
	patchname = "가방 항상 열기";

	addrIsUsableContents = CAddr::Addr(IServiceMgr_IsUsableContents);

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x8B, 0x46, -1,						// +3F: MOV EAX,DWORD PTR DS:[ESI+28]
		0x8B, 0x88, -1, -1, -1, -1,			// +42: MOV ECX,DWORD PTR DS:[EAX+118]
		0x8B, 0x3D, -1, -1, -1, -1,			// +48: MOV EDI,DWORD PTR DS:[xxxxxxxx] (Standard.?IsUsableContents@IServiceMgr@core@@QBE_NW4EServiceContents@2@@Z)
		0x6A, 0x02,							// +4E: PUSH 2
		0xFF, 0xD7,							// +50: CALL EDI
		0x8B, 0x1D, -1, -1, -1, -1,			// +52: MOV EBX, DWORD PTR DS:[xxxxxxxx] (Standard.?GetDBClassID@IItem@core@@QBEKXZ)
		0x84, 0xC0,							// +58: TEST AL, AL
		0x75;								// +5A: JNE 0x3C

	funcPointer = (LPBYTE)patchAlwaysBagView;

	patch +=
		0x8B, 0x46, -1,
		-1, -1, -1, -1, -1, -1,
		0x8B, 0x3D,
		((int)(&funcPointer) & 0xFF),
		(((int)(&funcPointer) & 0xFF00) >> 8),
		(((int)(&funcPointer) & 0xFF0000) >> 16),
		(((int)(&funcPointer) & 0xFF000000) >> 24),
		0x6A, 0x02,
		-1, -1,
		-1, -1, -1, -1, -1, -1,
		-1, -1,
		-1;

	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"Pleione.dll" );
	//mp.PatchExactAddress( 0x01, (LPBYTE)patchNameOfMod );
	//mp.PatchRelativeAddress( 0x01, (LPBYTE)patchNameOfMod );

	addrTargetReturn = mp.GetAddr() + 0x13;
	
	patches += mp;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_AlwaysBagView::patchAlwaysBagView(void)
{
	if (IsPatchEnabled())
	{
		__asm {
			MOV EAX, 1
			RETN 4
		}
	}
	else
	{
		__asm {
			JMP addrIsUsableContents
		}
	}
}
//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_AlwaysBagView::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_AlwaysBagView::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_AlwaysBagView::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_AlwaysBagView::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_AlwaysBagView::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_AlwaysBagView::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_AlwaysBagView::ReadINI( void )
{
	if ( ReadINI_Bool( L"AlwaysBagView" ))
		return PatchEnable();
	return true;
}

bool CPatcher_AlwaysBagView::WriteINI( void )
{
	WriteINI_Bool( L"AlwaysBagView", IsPatchEnabled() );
	return true;
}