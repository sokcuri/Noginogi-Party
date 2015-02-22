#include "Patcher_TransformIgnore.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

LPBYTE CPatcher_TransformIgnore::addrInlineCall = NULL;
LPBYTE CPatcher_TransformIgnore::addrGetFullSuitID = NULL;
LPBYTE CPatcher_TransformIgnore::addrIsTransformed = NULL;

bool CPatcher_TransformIgnore::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_TransformIgnore::CPatcher_TransformIgnore( void )
{
	patchname = "변신 효과 무시";

	addrIsTransformed = CAddr::Addr(ITransformMgr_IsTransformed);
	addrGetFullSuitID = CAddr::Addr(ICharacter_GetFullSuitID);

	vector<WORD> patch1;
	vector<WORD> patch2;
	vector<WORD> patch3;
	vector<WORD> patch4;
	vector<WORD> patch5;
	vector<WORD> patch8;
	vector<WORD> patchA;
	vector<WORD> backup1;
	vector<WORD> backup2;
	vector<WORD> backup3;
	vector<WORD> backup4;
	vector<WORD> backup5;
	vector<WORD> backup8;
	vector<WORD> backupA;

	vector<WORD> search;
	
	// CALL 찾기
	search +=
		0x8B, 0x44, 0x24, 0x04,
		0x83, 0xF8, 0x0F,
		0x7D, 0x09,
		0x6B, 0xC0, 0x24,
		0x8B, 0x44, 0x08, 0x0C,
		0xEB, 0x02,
		0x33, 0xC0,
		0xC2, 0x04, 0x00;

	MemoryPatch ms( NULL, search, search );
	ms.Search(L"Pleione.dll");

	funcPointer = (LPBYTE)patchTransformIgnore;
	addrInlineCall = ms.GetAddr();

	if (!addrInlineCall) {
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
		WriteLog("   종속 요소가 없습니다.\n");
		return;
	}

	// GetFullSuitID Part
	// 변신 모습 유지 시키지 않기
	backup1 +=
		0xE8, -1, -1, -1, -1,					// +447: CALL xxxxxxxx
		0x8B, 0x8F, 0xAC, 0x00, 0x00, 0x00,		// +44C: MOV ECX,DWORD PTR DS:[EDI+AC]
		0xFF, 0x15, -1, -1, -1, -1,				// +452: CALL DWORD PTR DS:[xxxxxxxx] (Standard.?IsTransformed@ITransformMgr@core@@QBE_NXZ)
		0x84, 0xC0,								// +458: TEST AL, AL
		0x0F, 0x84, -1, -1, -1, -1,				// +45A: JE 0x9A
		0x8B, 0x86, -1, -1, -1, -1,				// +460: MOV EAX,DWORD PTR DS:[ESI+188]
		0x8B, 0x8F, -1, -1, -1, -1,				// +46C: MOV ECX,DWORD PTR DS:[EDI+AC]
		0x6A, 0x01;								// +46C: PUSH 1

	patch1 +=
		0xE8, -1, -1, -1, -1,					// +447: CALL xxxxxxxx
		0x8B, 0x8F, 0xAC, 0x00, 0x00, 0x00,		// +44C: MOV ECX,DWORD PTR DS:[EDI+AC]
		0xFF, 0x15,
		((int)(&funcPointer) & 0xFF),
		(((int)(&funcPointer) & 0xFF00) >> 8),
		(((int)(&funcPointer) & 0xFF0000) >> 16),
		(((int)(&funcPointer) & 0xFF000000) >> 24),
		0x84, 0xC0,								// +458: TEST AL, AL
		0x0F, 0x84, -1, -1, -1, -1,				// +45A: JE 0x9A
		0x8B, 0x86, -1, -1, -1, -1,				// +460: MOV EAX,DWORD PTR DS:[ESI+188]
		0x8B, 0x8F, -1, -1, -1, -1,				// +46C: MOV ECX,DWORD PTR DS:[EDI+AC]
		0x6A, 0x01;								// +46C: PUSH 1

	MemoryPatch mp1( NULL, patch1, backup1 );
	mp1.Search( L"Pleione.dll" );

	backup2 +=
		0xE8, -1, -1, -1, -1,				// +22F: CALL xxxxxxxx
		0x85, 0xC0,							// +234: TEST EAX, EAX
		0x75, 0x45,							// +236: JNZ 0x45
		0x8B, 0x46, 0x10,					// +238: MOV EAX,DWORD PTR DS:[ESI+10]
		0x8B, 0xB8, 0x88, 0x01, 0x00, 0x00,	// +23B: MOV EDI,DWORD PTR DS:[EAX+188]
		0x8D, 0x45, 0xE8,					// +241: LEA EAX,DWORD PTR SS:[EBP-18]
		0x6A, 0x01,							// +244: PUSH 1
		0x50,								// +246: PUSH EAX
		0x53,								// +247: PUSH EBX
		0x53,								// +248: PUSH EBX
		0x8B, 0xCE,							// +249: MOV ECX, ESI
		0xFF, 0x15, -1, -1, -1, -1,			// +24B: CALL DWORD PTR DS:
		0x50,								// +251: PUSH EAX
		0x6A, 0xFE;							// +252: PUSH -2

	patch2 +=
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x85, 0xC0,							// +234: TEST EAX, EAX
		0x75, 0x45,							// +236: JNZ 0x45
		0x8B, 0x46, 0x10,					// +238: MOV EAX,DWORD PTR DS:[ESI+10]
		0x8B, 0xB8, 0x88, 0x01, 0x00, 0x00,	// +23B: MOV EDI,DWORD PTR DS:[EAX+188]
		0x8D, 0x45, 0xE8,					// +241: LEA EAX,DWORD PTR SS:[EBP-18]
		0x6A, 0x01,							// +244: PUSH 1
		0x50,								// +246: PUSH EAX
		0x53,								// +247: PUSH EBX
		0x53,								// +248: PUSH EBX
		0x8B, 0xCE,							// +249: MOV ECX, ESI
		0xFF, 0x15, -1, -1, -1, -1,			// +24B: CALL DWORD PTR DS:
		0x50,								// +251: PUSH EAX
		0x6A, 0xFE;							// +252: PUSH -2
	MemoryPatch mp2( NULL, patch2, backup2 );
	mp2.Search( L"Pleione.dll" );
	mp2.PatchRelativeAddress( 0x01, (LPBYTE)patchInlineCall );

	backup3 +=
		0xE8, -1, -1, -1, -1,					// +1D3: CALL xxxxxxxx
		0x85, 0xC0,								// +1D8: TEST EAX, EAX
		0x75, 0x45,								// +1DA: JNZ 0x45
		0x8B, 0x46, 0x10,						// +1DC: MOV EAX,DWORD PTR DS:[ESI+10]
		0x8B, 0xB8, 0x88, 0x01, 0x00, 0x00,		// +1DF: MOV EDI,DWORD PTR DS:[EAX+188]
		0x8D, 0x44, 0x24, 0x1C,					// +1E5: LEA EAX,DWORD PTR SS:[ESP+1C]
		0x55,									// +1E9: PUSH EBP
		0x50,									// +1EA: PUSH EAX
		0x53,									// +1EB: PUSH EBX
		0x53,									// +1EC: PUSH EBX
		0x8B, 0xCE,								// +1ED: MOV ECX, ESI
		0xFF, 0x15, -1, -1, -1, -1,				// +1EF: CALL DWORD PTR DS:[xxxxxxxx] (Standard.?GetFullSuitID@ITransformMgr@core@@QBEKXZ)
		0x50,									// +1F5: PUSH EAX
		0x6A, 0xFE;								// +1F6: PUSH -2

	patch3 +=
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x85, 0xC0,								// +1D8: TEST EAX, EAX
		0x75, 0x45,								// +1DA: JNZ 0x45
		0x8B, 0x46, 0x10,						// +1DC: MOV EAX,DWORD PTR DS:[ESI+10]
		0x8B, 0xB8, 0x88, 0x01, 0x00, 0x00,		// +1DF: MOV EDI,DWORD PTR DS:[EAX+188]
		0x8D, 0x44, 0x24, 0x1C,					// +1E5: LEA EAX,DWORD PTR SS:[ESP+1C]
		0x55,									// +1E9: PUSH EBP
		0x50,									// +1EA: PUSH EAX
		0x53,									// +1EB: PUSH EBX
		0x53,									// +1EC: PUSH EBX
		0x8B, 0xCE,								// +1ED: MOV ECX, ESI
		0xFF, 0x15, -1, -1, -1, -1,				// +1EF: CALL DWORD PTR DS:[xxxxxxxx] (Standard.?GetFullSuitID@ITransformMgr@core@@QBEKXZ)
		0x50,									// +1F5: PUSH EAX
		0x6A, 0xFE;								// +1F6: PUSH -2

	MemoryPatch mp3( NULL, patch3, backup3 );
	mp3.Search( L"Pleione.dll" );
	mp3.PatchRelativeAddress( 0x01, (LPBYTE)patchInlineCall );

	backup4 +=
		0xE8, -1, -1, -1, -1,					// +4C7: CALL xxxxxxxx
		0x85, 0xC0,								// +4CC: TEST EAX, EAX
		0x75, 0x45,								// +4CE: JNZ 0x45
		0x8B, 0x43, 0x10,						// +4D0: MOV EAX,DWORD PTR DS:[EBX+10]
		0x8B, 0xB0, 0x88, 0x01, 0x00, 0x00,		// +4D3: MOV ESI,DWORD PTR DS:[EAX+188]
		0x8D, 0x45, 0xE4,						// +4D9: LEA EAX,DWORD PTR SS:[EBP-1C]
		0x6A, 0x01,								// +4DC: PUSH 1
		0x50,									// +4DE: PUSH EAX
		0x57,									// +4DF: PUSH EDI
		0x57,									// +4E0: PUSH EDI
		0x8B, 0xCB,								// +4E1: MOV ECX, EBX
		0xFF, 0x15, -1, -1, -1, -1,				// +4E3: CALL DWORD PTR DS:[xxxxxxxx] (Standard.?GetFullSuitID@ITransformMgr@core@@QBEKXZ)
		0x50,									// +4E9: PUSH EAX
		0x6A, 0xFE;								// +4EA: PUSH -2

	patch4 +=
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF,	// +4C7: CALL xxxxxxxx
		0x85, 0xC0,								// +4CC: TEST EAX, EAX
		0x75, 0x45,								// +4CE: JNZ 0x45
		0x8B, 0x43, 0x10,						// +4D0: MOV EAX,DWORD PTR DS:[EBX+10]
		0x8B, 0xB0, 0x88, 0x01, 0x00, 0x00,		// +4D3: MOV ESI,DWORD PTR DS:[EAX+188]
		0x8D, 0x45, 0xE4,						// +4D9: LEA EAX,DWORD PTR SS:[EBP-1C]
		0x6A, 0x01,								// +4DC: PUSH 1
		0x50,									// +4DE: PUSH EAX
		0x57,									// +4DF: PUSH EDI
		0x57,									// +4E0: PUSH EDI
		0x8B, 0xCB,								// +4E1: MOV ECX, EBX
		0xFF, 0x15, -1, -1, -1, -1,				// +4E3: CALL DWORD PTR DS:[xxxxxxxx] (Standard.?GetFullSuitID@ITransformMgr@core@@QBEKXZ)
		0x50,									// +4E9: PUSH EAX
		0x6A, 0xFE;								// +4EA: PUSH -2

	MemoryPatch mp4( NULL, patch4, backup4 );
	mp4.Search( L"Pleione.dll" );
	mp4.PatchRelativeAddress( 0x01, (LPBYTE)patchInlineCall );
	
	// IsTransformed(Standard) Part
	// 변신 체형으로 변화 시키지 않기
	backup5 +=
		0xC3,
		0x56,
		0x8B, 0xF1,
		0x8B, 0x06,
		0xFF, 0x50, 0x04,
		0x8B, 0x10,
		0x8B, 0xC8,
		0xFF, 0x92, 0xEC, 0x00, 0x00, 0x00,
		0x8B, 0xC8,
		0xE8, -1, -1, -1, -1,
		0x8B, 0xCE,
		0x84, 0xC0,
		0x74, 0x17,
		0x8B, 0x06,
		0xFF, 0x50, 0x04,
		0x8B, 0x10,
		0x8B, 0xC8,
		0xFF, 0x92, 0xEC, 0x00, 0x00, 0x00,
		0x8B, 0xC8,
		0x5E,
		0xE9, -1, -1, -1, -1,
		0x5E,
		0xE9, -1, -1, -1, -1,
		0x56,
		0x8B, 0xF1,
		0x8B, 0x06,
		0xFF, 0x50, 0x04,
		0x8B, 0x10,
		0x8B, 0xC8,
		0xFF, 0x92, 0xEC, 0x00, 0x00, 0x00,
		0x8B, 0xC8,
		0xE8, -1, -1, -1, -1,
		0x8B, 0xCE,
		0x84, 0xC0,
		0x74, 0x17,
		0x8B, 0x06,
		0xFF, 0x50, 0x04,
		0x8B, 0x10,
		0x8B, 0xC8,
		0xFF, 0x92, 0xEC, 0x00, 0x00, 0x00,
		0x8B, 0xC8,
		0x5E,
		0xE9, -1, -1, -1, -1,
		0x5E,
		0xE9, -1, -1, -1, -1,
		0x56,
		0x8B, 0xF1,
		0x8B, 0x06,
		0xFF, 0x50, 0x04,
		0x8B, 0x10,
		0x8B, 0xC8,
		0xFF, 0x92, 0xEC, 0x00, 0x00, 0x00,
		0x8B, 0xC8,
		0xE8, -1, -1, -1, -1,
		0x8B, 0xCE,
		0x84, 0xC0,
		0x74, 0x17;

	patch5 +=
		0xC3,
		0x56,
		0x8B, 0xF1,
		0x8B, 0x06,
		0xFF, 0x50, 0x04,
		0x8B, 0x10,
		0x8B, 0xC8,
		0xFF, 0x92, 0xEC, 0x00, 0x00, 0x00,
		0x8B, 0xC8,
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x8B, 0xCE,
		0x84, 0xC0,
		0x74, 0x17,
		0x8B, 0x06,
		0xFF, 0x50, 0x04,
		0x8B, 0x10,
		0x8B, 0xC8,
		0xFF, 0x92, 0xEC, 0x00, 0x00, 0x00,
		0x8B, 0xC8,
		0x5E,
		0xE9, -1, -1, -1, -1,
		0x5E,
		0xE9, -1, -1, -1, -1,
		0x56,
		0x8B, 0xF1,
		0x8B, 0x06,
		0xFF, 0x50, 0x04,
		0x8B, 0x10,
		0x8B, 0xC8,
		0xFF, 0x92, 0xEC, 0x00, 0x00, 0x00,
		0x8B, 0xC8,
		0xE8, 0x02FF, 0x02FF, 0x02FF, 0x02FF,
		0x8B, 0xCE,
		0x84, 0xC0,
		0x74, 0x17,
		0x8B, 0x06,
		0xFF, 0x50, 0x04,
		0x8B, 0x10,
		0x8B, 0xC8,
		0xFF, 0x92, 0xEC, 0x00, 0x00, 0x00,
		0x8B, 0xC8,
		0x5E,
		0xE9, -1, -1, -1, -1,
		0x5E,
		0xE9, -1, -1, -1, -1,
		0x56,
		0x8B, 0xF1,
		0x8B, 0x06,
		0xFF, 0x50, 0x04,
		0x8B, 0x10,
		0x8B, 0xC8,
		0xFF, 0x92, 0xEC, 0x00, 0x00, 0x00,
		0x8B, 0xC8,
		0xE8, 0x03FF, 0x03FF, 0x03FF, 0x03FF,
		0x8B, 0xCE,
		0x84, 0xC0,
		0x74, 0x17;
		

	MemoryPatch mp5( NULL, patch5, backup5 );
	mp5.Search( L"Standard.dll" );
	mp5.PatchRelativeAddress( 0x01, (LPBYTE)patchTransformIgnore );
	mp5.PatchRelativeAddress( 0x02, (LPBYTE)patchTransformIgnore );
	mp5.PatchRelativeAddress( 0x03, (LPBYTE)patchTransformIgnore );

	backup8 +=
		0x8B, 0x10,
		0x8B, 0xC8,
		0xFF, 0x92, 0xEC, 0x00, 0x00, 0x00,
		0x8B, 0xC8,
		0xE8, -1, -1, -1, -1,
		0x84, 0xC0,
		0x74, 0x1B,
		0x8B, 0x06,
		0x8B, 0xCE;

	patch8 +=

		0x8B, 0x10,
		0x8B, 0xC8,
		0xFF, 0x92, 0xEC, 0x00, 0x00, 0x00,
		0x8B, 0xC8,
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x84, 0xC0,
		0x74, 0x1B,
		0x8B, 0x06,
		0x8B, 0xCE;

	MemoryPatch mp8( NULL, patch8, backup8 );
	mp8.Search( L"Standard.dll" );
	mp8.PatchRelativeAddress( 0x01, (LPBYTE)patchTransformIgnore );

	backupA +=
		0x8B, 0xF1,
		0x8B, 0x4E, 0x0C,
		0x57,
		0xFF, 0x15, -1, -1, -1, -1,
		0x8B, 0xF8,
		0x8B, 0x46, 0x0C,
		0x8B, 0x88, -1, -1, -1, -1;

	funcPointerA = (LPBYTE)patchGetFullSuitID;

	patchA +=
		0x8B, 0xF1,
		0x8B, 0x4E, 0x0C,
		0x57,
		0xFF, 0x15,
		((int)(&funcPointerA) & 0xFF),
		(((int)(&funcPointerA) & 0xFF00) >> 8),
		(((int)(&funcPointerA) & 0xFF0000) >> 16),
		(((int)(&funcPointerA) & 0xFF000000) >> 24),
		0x8B, 0xF8,
		0x8B, 0x46, 0x0C,
		0x8B, 0x88, -1, -1, -1, -1;

	MemoryPatch mpA( NULL, patchA, backupA );
	mpA.Search( L"Pleione.dll" );

	patches += mp1;
	patches += mp2;
	patches += mp3;
	patches += mp4;

	patches += mp5;
	patches += mp8;

	patches += mpA;

	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions
NAKED void CPatcher_TransformIgnore::patchGetFullSuitID(void)
{
	__asm {
		PUSH EAX
	}

	if (IsPatchEnabled())
	{
		__asm {
			POP EAX
			MOV EAX, 0
			RETN
		}
	}
	else
	{
		__asm {
			POP EAX		
			JMP addrGetFullSuitID
		}
	}
}

NAKED void CPatcher_TransformIgnore::patchTransformIgnore(void)
{
	__asm
	{
		PUSH EAX
	}

	// 변신 무시 작동
	if (IsPatchEnabled())
	{
		__asm {
			POP EAX
			MOV EAX, 0
			RETN
		}
	}

	// 변신 무시 해제
	else
	{
		__asm {
			POP EAX
			JMP addrIsTransformed
		}
	}
}

NAKED void CPatcher_TransformIgnore::patchInlineCall(void)
{
	__asm
	{
		PUSH EAX
	}

	// 변신 무시 작동
	if (IsPatchEnabled())
	{
		__asm {
			POP EAX
			MOV EAX, 1
			RETN 4
		}
	}

	// 변신 무시 해제
	else
	{
		__asm {
			POP EAX
			JMP addrInlineCall
		}
	}
}

//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_TransformIgnore::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_TransformIgnore::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_TransformIgnore::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_TransformIgnore::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_TransformIgnore::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_TransformIgnore::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_TransformIgnore::ReadINI( void )
{
	if ( ReadINI_Bool( L"TransformIgnore" ))
		return PatchEnable();
	return true;
}

bool CPatcher_TransformIgnore::WriteINI( void )
{
	WriteINI_Bool( L"TransformIgnore", IsPatchEnabled() );
	return true;
}