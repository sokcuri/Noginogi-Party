#include "Patcher_MoveToSameChannel.h"
#include "../Addr.h"

//-------------------------------------------------------------------
// Local variables
bool CPatcher_MoveToSameChannel::PatchEnabled = false;

LPBYTE CPatcher_MoveToSameChannel::addrGetContents = NULL;
LPBYTE CPatcher_MoveToSameChannel::addrstrcmp = NULL;

//-----------------------------------------------------------------------------
// Constructor

CPatcher_MoveToSameChannel::CPatcher_MoveToSameChannel( void )
{
	patchname = "채널 재접속";

	addrstrcmp = CAddr::Addr(ESL_strcmp);
	addrGetContents = CAddr::Addr(CStringTUni_GetContents);

	if (!addrstrcmp ||
		!addrGetContents) {
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
		WriteLog("   종속 요소가 없습니다.\n");
		return;
	}
	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0xA1, -1, -1, -1, -1,				// +E4: MOV EAX,DWORD PTR DS:[xxxxxxxx]
		0x83, 0xC0, 0x0C,					// +E9: ADD EAX,0C
		0x50,								// +EC: PUSH EAX
		0xE8, -1, -1, -1, -1;				// +ED: CALL xxxxxxxx

	patch +=
		-1, -1, -1, -1, -1,
		-1, -1, -1,
		0x50,
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF;

	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"Pleione.dll" );
	mp.PatchRelativeAddress( 0x01, (LPBYTE)patchMoveToSameChannel );
	
	patches += mp;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

NAKED void CPatcher_MoveToSameChannel::patchMoveToSameChannel(void)
{
	if (IsPatchEnabled())
	{
		__asm {
			MOV		EAX, 0			// 채널 비교 무시하기~~
			RETN
		}
	}
	else
	{
		__asm {
			MOV		ECX,DWORD PTR SS:[ESP+8]
			PUSH	ESI
			MOV		ESI, addrGetContents
			CALL	ESI
			MOV		ECX,DWORD PTR SS:[ESP+8]
			PUSH	EAX
			CALL	ESI
			PUSH	EAX
			CALL	addrstrcmp
			POP		ECX
			NEG		EAX
			POP		ECX
			SBB		EAX,EAX
			INC		EAX
			POP		ESI
			RETN
		}
	}
}

bool CPatcher_MoveToSameChannel::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_MoveToSameChannel::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_MoveToSameChannel::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_MoveToSameChannel::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_MoveToSameChannel::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_MoveToSameChannel::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_MoveToSameChannel::ReadINI( void )
{
	if ( ReadINI_Bool( L"MoveToSameChannel" ))
		return PatchEnable();
	return true;
}

bool CPatcher_MoveToSameChannel::WriteINI( void )
{
	WriteINI_Bool( L"MoveToSameChannel", IsPatchEnabled() );
	return true;
}