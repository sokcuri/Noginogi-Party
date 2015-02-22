#include "Patcher_TalkToUnequippedEgo.h"
#include "../Addr.h"

//-------------------------------------------------------------------
// Local variables
bool CPatcher_TalkToUnequippedEgo::PatchEnabled = false;
LPBYTE CPatcher_TalkToUnequippedEgo::addrTargetReturn = NULL;
LPBYTE CPatcher_TalkToUnequippedEgo::addrIsEiry = NULL;

//-----------------------------------------------------------------------------
// Constructor

CPatcher_TalkToUnequippedEgo::CPatcher_TalkToUnequippedEgo( void )
{
	patchname = "항상 정령 대화 가능";

	addrIsEiry = CAddr::Addr(SItemEgoInfo_IsEiry);

	if (!addrIsEiry) {
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
		WriteLog("   종속 요소가 없습니다.\n");
		return;
	}
	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x0F, 0x84, -1, -1, -1, -1,			// +41: JE
		0x8B, 0xCF,							// +47: MOV ECX,EDI
		0xFF, 0x15, -1, -1, -1, -1,			// +49: CALL xxxxxxxx (Standard.?IsEiry@SItemEgoInfo@@QBE_NXZ)
		0x84, 0xC0,							// +4F: TEST AL, AL
		0x0F, 0x85, -1, -1, -1, -1,			// +51: JNZ
		0x8B, 0xCE,							// +57: MOV ECX,ESI
		0xE8;								// +59: CALL xxxxxxxx


	funcPointer = (LPBYTE)&patchUnequippedEgo;

	patch +=
		-1, -1, -1, -1, -1, -1,
		-1, -1,
		0xFF, 0x15,
		((int)(&funcPointer) & 0xFF),
		(((int)(&funcPointer) & 0xFF00) >> 8),
		(((int)(&funcPointer) & 0xFF0000) >> 16),
		(((int)(&funcPointer) & 0xFF000000) >> 24),
		-1, -1,
		-1, -1, -1, -1, -1, -1,
		-1, -1,
		-1;

	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"Pleione.dll" );

	addrTargetReturn = mp.GetAddr();
	
	patches += mp;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

NAKED void CPatcher_TalkToUnequippedEgo::patchUnequippedEgo(void)
{
	if (IsPatchEnabled())
	{
		__asm {
			MOV EAX, 1
			RETN
		}
	}
	else
	{
		__asm {

			JMP addrIsEiry
		}
	}
}

//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_TalkToUnequippedEgo::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_TalkToUnequippedEgo::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_TalkToUnequippedEgo::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_TalkToUnequippedEgo::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_TalkToUnequippedEgo::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_TalkToUnequippedEgo::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_TalkToUnequippedEgo::ReadINI( void )
{
	if ( ReadINI_Bool( L"TalkToUnequippedEgo" ))
		return PatchEnable();
	return true;
}

bool CPatcher_TalkToUnequippedEgo::WriteINI( void )
{
	WriteINI_Bool( L"TalkToUnequippedEgo", IsPatchEnabled() );
	return true;
}