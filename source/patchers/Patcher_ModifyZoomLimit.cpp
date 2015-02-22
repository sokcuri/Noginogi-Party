#include "Patcher_ModifyZoomLimit.h"
#include "../Addr.h"

//-----------------------------------------------------------------------------
// Static variable initialization

float CPatcher_ModifyZoomLimit::zoomNear = 500;
float CPatcher_ModifyZoomLimit::zoomLimit = 1500;
float CPatcher_ModifyZoomLimit::zoomLimitDefault = 1500;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_ModifyZoomLimit::CPatcher_ModifyZoomLimit( void )
{
	patchname = "노기노기 시야설정";

	LPBYTE addrSetCamera = CAddr::Addr(CCameraControl_SetCamera);
	if (!addrSetCamera) {
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
		WriteLog("   종속 종속 요소가 없습니다.\n");
		return;
	}

	// Renderer.??0CQuaterViewCamera@pleione@@QAE@XZ+6C

	vector<WORD> backup1;
	vector<WORD> backup2;
	vector<WORD> patch1;
	vector<WORD> patch2;
	backup1 +=
		0x8B, 0x46, 0x64,
		0xD9, 0x05, -1, -1, -1, -1,
		0x51,
		0xD9, 0x98, -1, -1, -1, -1,
		0x51;

	patch1 +=
		0x8B, 0x46, 0x64,
		0xD9, 0x05,
		((int)(&zoomLimitDefault) & 0xFF),
		(((int)(&zoomLimitDefault) & 0xFF00) >> 8),
		(((int)(&zoomLimitDefault) & 0xFF0000) >> 16),
		(((int)(&zoomLimitDefault) & 0xFF000000) >> 24),
		0x51,
		0xD9, 0x98, -1, -1, -1, -1,
		0x51;

	MemoryPatch mp1( NULL, patch1, backup1 );
	mp1.Search( L"Renderer2.dll" );

	backup2 +=
		0xD9, 0x05, -1, -1, -1, -1,		// +57: FLD DWORD PTR DS:[xxxxxxxx] << 줌 최댓값 설정
		0x51,							// +5D: MOV ECX
		0x51,							// +5E: MOV ECX
		0xD9, 0x5C, 0x24, 0x04,			// +5F: FSTP DWORD PTR SS:[ESP+4]
		0xD9, 0x05, -1, -1, -1, -1,		// +63: FLD DWORD PTR DS:[xxxxxxxx] << 줌 최솟값 설정
		0xD9, 0x1C, 0x24,				// +69: FSTP DWORD PTR SS:[ESP]
		0xE8, -1, -1, -1, -1;			// +6C: CALL xxxxxxxx (Renderer.?SetZoomLimit@CCamera@pleione@@UAEXMM@Z)

	patch2 +=
		0xD9, 0x05,
		((int)(&zoomLimit) & 0xFF),
		(((int)(&zoomLimit) & 0xFF00) >> 8),
		(((int)(&zoomLimit) & 0xFF0000) >> 16),
		(((int)(&zoomLimit) & 0xFF000000) >> 24),
		-1,
		-1,
		-1, -1, -1, -1,
		0xD9, 0x05,
		((int)(&zoomNear) & 0xFF),
		(((int)(&zoomNear) & 0xFF00) >> 8),
		(((int)(&zoomNear) & 0xFF0000) >> 16),
		(((int)(&zoomNear) & 0xFF000000) >> 24),
		-1, -1, -1,
		-1, -1, -1, -1, -1;

	MemoryPatch mp2( NULL, patch2, backup2 );
	mp2.Search( L"Renderer2.dll" );

	patches += mp1;
	patches += mp2;

	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Options

bool CPatcher_ModifyZoomLimit::SetLimit( float value )
{
	zoomLimit = value;
	WriteLog("줌 최대값 설정: %f.\n", value);
	return true;
}

bool CPatcher_ModifyZoomLimit::SetDefault( float value )
{
	zoomLimitDefault = value;
	WriteLog("줌 기본값 설정: %f.\n", value);
	return true;
}

bool CPatcher_ModifyZoomLimit::SetNear( float value )
{
	zoomNear = value;
	WriteLog("줌 최소값 설정: %f.\n", value);
	return true;
}

int CPatcher_ModifyZoomLimit::GetLimit( void )
{
	return (int)zoomLimit;
}

int CPatcher_ModifyZoomLimit::GetNear( void )
{
	return (int)zoomNear;
}

//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_ModifyZoomLimit::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_ModifyZoomLimit::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_ModifyZoomLimit::ReadINI( void )
{
	int zoomSetting;
	
	// 줌 최대값 설정
	zoomSetting = ReadINI_Int( L"ZoomLimit", 1, 5000 );
	if ( !SetLimit( (float)zoomSetting ))
		return false;

	// 줌 최소값 설정
	zoomSetting = ReadINI_Int( L"ZoomNear", 1, 500 );
	if ( !SetNear( (float)zoomSetting ))
		return false;

	// 기본값 설정
	zoomSetting = ReadINI_Int( L"ZoomDefault", 1, 5000 );
	if ( !SetDefault( (float)zoomSetting ))
		return false;

	if ( ReadINI_Bool( L"ModifyZoomLimit" ))
	{
		return true;
	}
	return true;
}

bool CPatcher_ModifyZoomLimit::WriteINI( void )
{
	if ( IsInstalled() )
		WriteINI_Int( L"ModifyZoomLimit", GetLimit() );
	return true;
}