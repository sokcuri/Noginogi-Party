#include "Patcher_ScreenshotQuality.h"
#include "../Addr.h"
#include "../DBGHook.h"

static LPBYTE funcPointer;

//-----------------------------------------------------------------------------
// Constructor

CPatcher_ScreenshotQuality::CPatcher_ScreenshotQuality( void )
{
	patchname = "스크린샷 화질 조정";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		-1, -1, -1, -1, -1, -1;
	funcPointer = (LPBYTE)ijlWrite;

	patch +=
		0xFF, 0x25,
		((int)(&funcPointer) & 0xFF),
		(((int)(&funcPointer) & 0xFF00) >> 8),
		(((int)(&funcPointer) & 0xFF0000) >> 16),
		(((int)(&funcPointer) & 0xFF000000) >> 24);

	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"ijl15.dll" );
	
	patches += mp;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}


NAKED void CPatcher_ScreenshotQuality::ijlWrite()
{
	__asm {
		PUSH	EBP
		MOV		EBP, ESP
		MOV		EAX, DWORD PTR SS:[EBP+8h]
		MOV		ECX, ssQuality
		MOV		DWORD PTR DS:[EAX+50h], ECX
		MOV		EDX, DWORD PTR SS:[EBP+0Ch]
		PUSH	EDX
		MOV		EAX, DWORD PTR SS:[EBP+08h]
		PUSH	EAX
		CALL	lpfnIJLWrite
		POP		EBP
		RETN
	}
}

//-----------------------------------------------------------------------------
// Overriden Patching Functions

bool CPatcher_ScreenshotQuality::Install( void ) {
	return true;
}

bool CPatcher_ScreenshotQuality::Uninstall( void ) {
	return true;
}

bool CPatcher_ScreenshotQuality::Toggle( void ) {
	return true;
}

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_ScreenshotQuality::ReadINI( void )
{
	if ( ReadINI_Bool( L"ScreenshotQuality" )) {
		int qualitySetting = ReadINI_Int( L"ScreenshotQuality", 1, 100 );
		SngDBGHook::Instance()->SetSSQuality(qualitySetting);
	}
	return true;
}

bool CPatcher_ScreenshotQuality::WriteINI( void )
{
	WriteINI_Int( L"ScreenshotQuality", SngDBGHook::Instance()->GetSSQuality() );
	return true;
}
