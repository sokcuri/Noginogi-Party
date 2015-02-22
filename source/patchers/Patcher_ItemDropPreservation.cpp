#include "Patcher_ItemDropPreservation.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

wchar_t CPatcher_ItemDropPreservation::NonUsingPSV[256] = L"code.client.window.ask_item_drop";
wchar_t CPatcher_ItemDropPreservation::UsingPSV[256];

LPBYTE CPatcher_ItemDropPreservation::addrTargetReturn1 = NULL;
LPBYTE CPatcher_ItemDropPreservation::addrTargetReturn2 = NULL;
LPBYTE CPatcher_ItemDropPreservation::addrTargetReturn3 = NULL;
LPBYTE CPatcher_ItemDropPreservation::addrTargetReturn4 = NULL;

bool CPatcher_ItemDropPreservation::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_ItemDropPreservation::CPatcher_ItemDropPreservation( void )
{
	patchname = "아이템 드롭 보호";

	vector<WORD> patch1;
	vector<WORD> patch2;
	vector<WORD> patch3;
	vector<WORD> patch4;
	vector<WORD> patch5;
	vector<WORD> backup1;
	vector<WORD> backup2;
	vector<WORD> backup3;
	vector<WORD> backup4;
	vector<WORD> backup5;

	backup1 +=
		0xD9, 0x1C, 0x24,				// +7C: FSTP DWORD PTR SS:[ESP]
		0x88, -1, -1,					// +7F: MOV BYTE PTR SS:[EBP-E],BL
		0xE8, -1, -1, -1, -1,			// +82: CALL xxxxxxxx
		0xD9, 0x5D, -1,					// +87: FSTP DWORD PTR SS:[EBP-20]
		0x38, 0x5D, -1,					// +8A: CMP BYTE PTR SS:[EBP+18], BL
		0x0F, 0x84, -1, -1, -1, -1,		// +8D: JE 0x2EC
		0x8B, 0x75, -1,					// +93: MOV ESI, DWORD PTR SS:[BBP-10]
		0x8B, 0xC6;						// +96: MOV EAX, ESI

	funcPointer1 = (LPBYTE)patchItemDropPreservation1;

	patch1 +=
		0xD9, 0x1C, 0x24,								// +7C: FSTP DWORD PTR SS:[ESP]
		0x88, -1, -1,									// +7F: MOV BYTE PTR SS:[EBP-E],BL
		0xE8, -1, -1, -1, -1,							// +82: CALL xxxxxxxx
		0xFF, 0x25,
		((int)(&funcPointer1) & 0xFF),
		(((int)(&funcPointer1) & 0xFF00) >> 8),
		(((int)(&funcPointer1) & 0xFF0000) >> 16),
		(((int)(&funcPointer1) & 0xFF000000) >> 24),
		0x0F, 0x84, -1, -1, -1, -1,						// +8D: JE 0x2EC
		0x8B, 0x75, -1,									// +93: MOV ESI, DWORD PTR SS:[BBP-10]
		0x8B, 0xC6;										// +96: MOV EAX, ESI

	MemoryPatch mp1( NULL, patch1, backup1 );
	mp1.Search( L"Pleione.dll" );
	addrTargetReturn1 = mp1.GetAddr() + 0x11;

	backup2 +=
		0xC6, 0x45, 0xF2, 0x01,			// +115: MOV BYTE PTR SS:[EBP-E],1
		0x8B, 0x7D, 0xE8,				// +119: MOV EDI,DWORD PTR SS:[EBP-18]
		0x38, 0x5D, 0xF3,				// +11C: CMP BYTE PTR SS:[EBP-D],BL
		0x0F, 0x84, -1, -1, -1, -1,		// +11F: JE 0x12C
		0x8B, 0x35, -1, -1, -1, -1,		// +125: MOV ESI,DWORD PTR DS:[xxxxxxxx] (ESL.??0?$CStringT@_WVunicode_string_trait@esl@@Vunicode_string_implement@2@@esl@@QAE@PB_W@Z)
		0x68, -1, -1, -1, -1,			// +12B: PUSH xxxxxxxx
		0x8D, 0x4D, -1,					// +130: LEA ECX,DWORD PTR SS:[EBP-1C]
		0xFF, 0xD6,						// +133: CALL ESI
		0x68, -1, -1, -1, -1,			// +135: PUSH xxxxxxxx (UNICODE "code.client.window.ask_item_drop")
		0x8D, 0x4D, -1;					// +13A: LEA ECX, DWORD PTR SS:[EBP-18]

	funcPointer2 = (LPBYTE)patchItemDropPreservation2;

	patch2 +=
		0xC6, 0x45, 0xF2, 0x01,
		0xFF, 0x15,
		((int)(&funcPointer2) & 0xFF),
		(((int)(&funcPointer2) & 0xFF00) >> 8),
		(((int)(&funcPointer2) & 0xFF0000) >> 16),
		(((int)(&funcPointer2) & 0xFF000000) >> 24),
		0x0F, 0x84, -1, -1, -1, -1,
		0x8B, 0x35, -1, -1, -1, -1,
		0x68, -1, -1, -1, -1,
		0x8D, 0x4D, -1,
		0xFF, 0xD6,
		0xE9, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x8D, 0x4D, -1;

	MemoryPatch mp2( NULL, patch2, backup2 );
	mp2.Search( L"Pleione.dll" );
	mp2.PatchRelativeAddress( 0x01, (LPBYTE)patchItemDropPreservation3 );

	addrTargetReturn2 = mp2.GetAddr() + 0x25;

	backup3 +=
	0x51,
	0x8B, 0xC8,
	0xC6, 0x45, 0xFC, 0x02,
	0xFF, 0x15, -1, -1, -1, -1,
	0x53,
	0x53,
	0x6A, 0x01,
	0x6A, 0x01,
	0x6A, 0x02,
	0x53,
	0x8D, 0x45, 0xE4;

	funcPointer4 = (LPBYTE)patchItemDropPreservation4;

	patch3 +=
	0x51,
	0x8B, 0xC8,
	0xC6, 0x45, 0xFC, 0x02,
	0xFF, 0x15, -1, -1, -1, -1,
	0x53,
	0x53,
	0xFF, 0x25,
	((int)(&funcPointer4) & 0xFF),
	(((int)(&funcPointer4) & 0xFF00) >> 8),
	(((int)(&funcPointer4) & 0xFF0000) >> 16),
	(((int)(&funcPointer4) & 0xFF000000) >> 24),
	0x53,
	0x8D, 0x45, 0xE4;

	MemoryPatch mp3( NULL, patch3, backup3 );
	mp3.Search( L"Pleione.dll" );
	addrTargetReturn3 = mp3.GetAddr() + 0x15;

	backup4 +=
		0xFF, 0xD6,
		0x39, 0x5D, 0xE0,
		0x0F, 0x84, -1, -1, -1, -1,
		0x8B, 0x4D, 0xEC,
		0xFF, 0x15, -1, -1, -1, -1,
		0x52,
		0x50,
		0x68, 0x47, 0x04, 0x00, 0x00;

	patch4 +=
		0xE8,
		0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x0F, 0x84, -1, -1, -1, -1,
		0x8B, 0x4D, 0xEC,
		0xFF, 0x15, -1, -1, -1, -1,
		0x52,
		0x50,
		0x68, 0x47, 0x04, 0x00, 0x00;

	MemoryPatch mp4( NULL, patch4, backup4 );
	mp4.Search( L"Pleione.dll" );
	mp4.PatchRelativeAddress( 0x01, (LPBYTE)patchItemDropPreservation5 );
	addrTargetReturn4 = mp4.GetAddr() + 0x05;

	// JUMP 수정
	backup5 +=
		0x8A, 0x40, -1,
		0x88, 0x45, -1,
		0xA1, -1, -1, -1, -1,
		0x38, 0x58, -1,
		0x74, 0x54;

	patch5 +=
		0x8A, 0x40, -1,
		0x88, 0x45, -1,
		0xA1, -1, -1, -1, -1,
		0x38, 0x58, -1,
		0x74, 0x51;

	MemoryPatch mp5( NULL, patch5, backup5 );
	mp5.Search( L"Pleione.dll" );

	patches += mp1;
	patches += mp2;
	patches += mp3;
	patches += mp4;
	patches += mp5;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_ItemDropPreservation::patchItemDropPreservation1(void)
{
	__asm {
		PUSH EAX
	}

	if (IsPatchEnabled())
	{
		__asm {
			MOV EAX, 1
			TEST EAX, EAX
			POP EAX
			FSTP DWORD PTR SS:[EBP-0x20]
			JMP addrTargetReturn1
		}
	}
	else
	{
		__asm {
			POP EAX
			FSTP DWORD PTR SS:[EBP-0x20]
			CMP BYTE PTR SS:[EBP+0x18],BL
			JMP addrTargetReturn1
		}
	}
}

NAKED void CPatcher_ItemDropPreservation::patchItemDropPreservation2(void)
{
	__asm {
		PUSH EAX
	}

	if (IsPatchEnabled())
	{
		__asm {
			MOV EDI,DWORD PTR SS:[EBP-0x18]
			MOV EAX, 1
			TEST EAX, EAX
			POP EAX
			RETN
		}
	}
	else
	{
		__asm {
			MOV EDI,DWORD PTR SS:[EBP-0x18]
			CMP BYTE PTR SS:[EBP-0x0D],BL
			POP EAX
			RETN
		}
	}
}

NAKED void CPatcher_ItemDropPreservation::patchItemDropPreservation3(void)
{
	__asm{
		PUSH EAX
	}

	if (IsPatchEnabled())
	{
		__asm{
			POP EAX
			PUSH offset UsingPSV
			JMP addrTargetReturn2
		}
	}
	else
	{
		__asm{
			POP EAX
			PUSH offset NonUsingPSV
			JMP addrTargetReturn2
		}
	}
}

NAKED void CPatcher_ItemDropPreservation::patchItemDropPreservation4(void)
{
	if (IsPatchEnabled())
	{
		__asm {
			PUSH 1
			PUSH 1
			PUSH 1
			JMP addrTargetReturn3
		}
	}
	else
	{
		__asm {
			PUSH 1
			PUSH 1
			PUSH 2
			JMP addrTargetReturn3
		}
	}
}

NAKED void CPatcher_ItemDropPreservation::patchItemDropPreservation5(void)
{
	if (IsPatchEnabled())
	{
		__asm {
			CALL ESI
			PUSH EAX
			MOV EAX, 0
			TEST EAX, EAX
			POP EAX
			JMP addrTargetReturn4

		}
	}
	else
	{
		__asm {
			CALL ESI
			CMP DWORD PTR SS:[EBP-0x20],EBX
			JMP addrTargetReturn4
		}
	}
}
//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_ItemDropPreservation::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_ItemDropPreservation::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_ItemDropPreservation::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_ItemDropPreservation::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_ItemDropPreservation::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_ItemDropPreservation::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_ItemDropPreservation::ReadINI( void )
{
	wchar_t buf[256];

	ReadINI_String( L"ItemDropPreservationMsg", buf );
	wcsncpy_s( UsingPSV, 256, buf, _TRUNCATE );

	if ( ReadINI_Bool( L"ItemDropPreservation" ))
		return PatchEnable();
	return true;
}

bool CPatcher_ItemDropPreservation::WriteINI( void )
{
	WriteINI_Bool( L"ItemDropPreservation", IsPatchEnabled() );
	return true;
}