#include "Patcher_RemoveLoginDelay.h"
#include "../Addr.h"

/* Remove Login Delay
 * Removes the 30-second login delay after disconnecting.
 * PATCHES: Pleione.dll
 */

//-------------------------------------------------------------------
// Local variables
bool CPatcher_RemoveLoginDelay::PatchEnabled = false;

LPBYTE CPatcher_RemoveLoginDelay::addrTargetReturn = NULL;

//-----------------------------------------------------------------------------
// Constructor

CPatcher_RemoveLoginDelay::CPatcher_RemoveLoginDelay( void )
{
	patchname = "Remove Login Delay";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x8B, 0xF1,							// +0C: MOV ESI, ECX
		0x89, 0x75, 0xDC,					// +0E: MOV [EBP-24h], ESI
		0x80, 0x7D, 0x08, 0x00,				// +11: CMP BYTE PTR [EBP+08h], 0
		0x0F, 0x84, -1, -1, -1, -1,			// +15: JZ xxxxxxxx
		0x83, 0x7E, 0x0C, 0x00,				// +1B: CMP DWORD PTR [ESI+0Ch], 0
		0x0F, 0x85, -1, -1, -1, -1,			// +1F: JNZ xxxxxxxx
		0x68, 0xA0, 0x01, 0x00, 0x00,		// +25: PUSH 1A0h
		0xE8, -1, -1, -1, -1,				// +2A: CALL xxxxxxxx
		0x8B, 0xC8,							// +2F: MOV ECX,EAX
		0xE8, -1, -1, -1, -1;				// +2A: CALL xxxxxxxx

	patch +=
		-1, -1,
		-1, -1, -1,
		-1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1,
		0x8B, 0xC8,
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF;

	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"Pleione.dll" );
	mp.PatchRelativeAddress( 0x01, (LPBYTE)patchRemoveLoginDelay );

	addrTargetReturn = mp.GetAddr() + 0x36;
	
	patches += mp;
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

NAKED void CPatcher_RemoveLoginDelay::patchRemoveLoginDelay(void)
{
	// 패치 활성
	if (IsPatchEnabled())
	{
		__asm
		{
			MOV EAX, 1
			TEST AL, AL
			POP EAX
			SUB EAX, 17h
			JMP addrTargetReturn
		}
	}
	// 패치 비활성
	else
	{
		__asm
		{
			ADD ECX,498
			MOV EAX,DWORD PTR DS:[ECX]
			JMP DWORD PTR DS:[EAX+4]
		}
	}
}

//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_RemoveLoginDelay::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_RemoveLoginDelay::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_RemoveLoginDelay::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_RemoveLoginDelay::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_RemoveLoginDelay::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_RemoveLoginDelay::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_RemoveLoginDelay::ReadINI( void )
{
	if ( ReadINI_Bool( L"RemoveLoginDelay" ))
		return PatchEnable();
	return true;
}

bool CPatcher_RemoveLoginDelay::WriteINI( void )
{
	WriteINI_Bool( L"RemoveLoginDelay", IsPatchEnabled() );
	return true;
}