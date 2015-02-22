#include "Patcher_ExpressBoard.h"
#include "../Addr.h"

//-----------------------------------------------------------------------------
// Static variable initialization
wchar_t CPatcher_ExpressBoard::dataBuf[256];
wchar_t CPatcher_ExpressBoard::strHouseInfo[] = L"/house_info/";
wchar_t CPatcher_ExpressBoard::strHousingInfo[] = L"/housing_info/";
wchar_t CPatcher_ExpressBoard::strAdvertiseBoard[] = L"/advertise_board/";
wchar_t CPatcher_ExpressBoard::strDungeonRankingBoard[] = L"/dungeon_ranking_board/";
wchar_t CPatcher_ExpressBoard::strPartyBoard[] = L"/party_board/";
wchar_t CPatcher_ExpressBoard::strShadowMissionBoard[] = L"/shadow_mission_board/";

LPBYTE CPatcher_ExpressBoard::addrTargetReturn = NULL;
LPBYTE CPatcher_ExpressBoard::addrTargetReturn2 = NULL;
LPBYTE CPatcher_ExpressBoard::addrCalcDistance = NULL;
LPBYTE CPatcher_ExpressBoard::addrCMessage_ReadU8 = NULL;
LPBYTE CPatcher_ExpressBoard::addr_package_file_item = NULL;
LPBYTE CPatcher_ExpressBoard::addrIProp_CheckFastStringID = NULL;

bool CPatcher_ExpressBoard::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_ExpressBoard::CPatcher_ExpressBoard( void )
{
	patchname = "게시판 바로 열기";

	addrIProp_CheckFastStringID = CAddr::Addr(lProp_CheckFastStringID);
	addr_package_file_item = CAddr::Addr(ESL_package_file_item);
	addrCMessage_ReadU8 = CAddr::Addr(CMessage_ReadU8);

	if (!addr_package_file_item   ||
		!addrIProp_CheckFastStringID ||
		!CMessage_ReadU8)
	{
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
		WriteLog("   종속 요소가 없습니다.\n");
		return;
	}

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
	vector<WORD> search;

	// 거리제한 풀기
	backup1 +=							
		0xD9, 0x1C, 0x24,				// +2E7: FSTP DWORD PTR SS:[ESP]
		0xE8, -1, -1, -1, -1,			// +2EA: CALL xxxxxxxx
		0x84, 0xC0,						// +2EF: TEST AL, AL
		0x0F, 0x84, -1, -1, -1, -1,		// +2F1: JE 0xB0D
		0x80, 0x7D, 0x10, 0x00;			// +2F7: CMP BYTE PTR SS:[EBP+10],0

	patch1 +=
		-1, -1, -1,
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		-1, -1,
		-1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1;

	MemoryPatch mp1( NULL, patch1, backup1 );
	if (!mp1.Search( L"Pleione.dll" )) {
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
		return;
	}
	mp1.PatchRelativeAddress( 0x01, (LPBYTE)patchExpressBoard );

	addrTargetReturn = mp1.GetAddr() + 0x08;
	// 계속 뜨는 문제 없애기
	backup2 +=							
		0x68, 0x8B, 0x90, 0x00, 0x00,		// +00: PUSH 908B 
		0x8B, 0xCE,							// +05: MOV ECX,ESI
		0xE8, -1, -1, -1, -1,				// +07: CALL xxxxxxxx
		0x8D, 0x4D, 0x08,					// +0C: LEA ECX,DWORD PTR SS:[EBP+8]
		0xFF, 0x15, -1, -1, -1, -1,			// +0F: CALL DWORD PTR DS:[xxxxxxxx] (Mint.?ReadU8@CMessage@mint@@QAEEXZ)
		0x3C, 0x64,							// +15: CMP AL, 64
		0x0F, 0x85;							// +17: JNE -0x424

	funcPointer = (LPBYTE)patchReadU8;


	patch2 +=
		-1, -1, -1, -1, -1,
		-1, -1,
		-1, -1, -1, -1, -1,
		-1, -1, -1,
		-1, -1, -1, -1, -1, -1,
		-1, -1,
		-1, 0x81;

	MemoryPatch mp2( NULL, patch2, backup2 );
	if (!mp2.Search( L"Pleione.dll" )) {
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
		return;
	}
	addrTargetReturn2 = mp2.GetAddr() + 15;
	
	search +=							
		0x55,						// +00: PUSH EBP
		0x8B, 0xEC,					// +01: MOV EBP,ESP
		0xD9, 0x45, 0x0C,			// +03: FLD DWORD PTR SS:[EBP+C]
		0x51,						// +06: PUSH ECX
		0x51,						// +07: PUSH ECX
		0xD9, 0x5C, 0x24, 0x04,		// +08: FSTP DWORD PTR SS:[ESP+4]
		0xD9, 0x45, 0x08,			// +0C: FLD DWORD PTR SS:[EBP+8]
		0xD9, 0x1C, 0x24;			// +0F: FSTP DWORD PTR SS:[ESP]

	MemoryPatch ms( NULL, search, search );
	if (!ms.Search( L"Pleione.dll" )) {
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
		return;
	}
	addrCalcDistance = ms.GetAddr();

	backup3 +=							
		0x8B, 0x03,						// +30: MOV EAX,DWORD PTR DS:[EBX]
		0x8B, 0xCB,						// +32: MOV ECX,EBX
		0xFF, 0x90, -1, -1, -1, -1,		// +34: CALL DWORD PTR DS:[EAX+1DC]
		0x3B, 0x86, -1, -1, -1, -1,		// +3A: CMP EAX,DWORD PTR DS:[ESI+114]
		0x0F, 0x85;						// +40: JNZ 0x5E1

	patch3 +=
		-1, -1,
		-1, -1,
		-1, -1, -1, -1, -1, -1,
		0xEB, 0x0A,						// +3A: JMP 0x0A
		-1, -1, -1, -1,
		0x0F, 0x85;						// +40: JNZ 0x5E1

	MemoryPatch mp3( NULL, patch3, backup3 );
	if (!mp3.Search( L"Pleione.dll" )) {
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
		return;
	}
//63D11938=Pleione.63D11938 (UNICODE "code.interface.PLI_WindowShadowMissionBoard.31")

	backup4 +=							
		0x8B, 0xCB,						// +78: MOV ECX, EBX
		0xD9, 0x1C, 0x24,				// +7A: FSTP DWORD PTR SS:[ESP]
		0xE8, -1, -1, -1, -1,			// +7D: CALL xxxxxxxx
		0xDC, 0x1D, -1, -1, -1, -1,		// +82: FCOMP QWORD PTR DS:[63CF5F28]
		0xDF, 0xE0,						// +88: FSTSW AX
		0xF6, 0xC4, 0x41,				// +8A: TEST AH, 41
		0x0F, 0x84;						// +8C: JE 0x594

	patch4 +=
		-1, -1,
		-1, -1, -1,
		-1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1,
		-1, -1,
		0xEB, 0x07, -1,					// +8A: JMP	0x07
		0x0F, 0x84;

	MemoryPatch mp4( NULL, patch4, backup4 );
	if (!mp4.Search( L"Pleione.dll" )) {
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
		return;
	}

	patches += mp1;
	patches += mp2;
	patches += mp3;
	patches += mp4;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_ExpressBoard::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_ExpressBoard::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// Hook functions
NAKED void CPatcher_ExpressBoard::patchExpressBoard( void )
{
	// 게시판 멀리서 열기가 작동중일때
	if (IsPatchEnabled())
	{
		__asm {
			
			ADD		ESP, 4h							// Stack POP
			CALL	addrCalcDistance
			MOV		ESI, addr_package_file_item
			PUSH	EAX								// EAX 레지스터 저장

			// 하우스 프랍
			MOV		ECX,DWORD PTR SS:[EBP-10h]		// Target String?
			PUSH	offset strHouseInfo
			CALL	addrIProp_CheckFastStringID		// 확인
			TEST	AL, AL
			JNE		lDistIgnore

			// 하우징 프랍
			MOV		ECX,DWORD PTR SS:[EBP-10h]		// Target String?
			PUSH	offset strHousingInfo
			CALL	addrIProp_CheckFastStringID		// 확인
			TEST	AL, AL
			JNE		lDistIgnore

			// 광고판 프랍
			MOV		ECX,DWORD PTR SS:[EBP-10h]		// Target String?
			PUSH	offset strAdvertiseBoard
			CALL	addrIProp_CheckFastStringID		// 확인
			TEST	AL, AL
			JNE		lDistIgnore

			// 던전 랭킹 프랍
			MOV		ECX,DWORD PTR SS:[EBP-10h]		// Target String?
			PUSH	offset strDungeonRankingBoard
			CALL	addrIProp_CheckFastStringID		// 확인
			TEST	AL, AL
			JNE		lDistIgnore

			// 파티 보드 프랍
			MOV		ECX,DWORD PTR SS:[EBP-10h]		// Target String?
			PUSH	offset strPartyBoard
			CALL	addrIProp_CheckFastStringID		// 확인
			TEST	AL, AL
			JNE		lDistIgnore

			// 그림자 미션 보드 프랍
			MOV		ECX,DWORD PTR SS:[EBP-10h]		// Target String?
			PUSH	offset strShadowMissionBoard
			CALL	addrIProp_CheckFastStringID		// 확인
			TEST	AL, AL
			JNE		lDistIgnore
			JMP		lEnd

			lDistIgnore:
			
			ADD		ESP, 4h							// Stack POP
			MOV		EAX, 0h
			MOV		EAX, addrTargetReturn
			ADD		EAX, 18h
			JMP		EAX
			
			lEnd:
			POP		EAX
			JMP		addrTargetReturn
		}
	}

	// 게시판 멀리서 열기가 작동중이 아닐때
	else

	{
		__asm {
			JMP		addrCalcDistance
		}
	}
}

NAKED void CPatcher_ExpressBoard::patchReadU8( void )
{
	if (IsPatchEnabled())
	{
		__asm {
			//POP		EAX
			//ADD		ESP, 4
			//PUSH	EAX
			CALL		addrCMessage_ReadU8
			MOV EAX, 0
			JMP		addrTargetReturn2
		}
	}
	else
	{
		__asm {
			CALL		addrCMessage_ReadU8
			JMP			addrTargetReturn2
		}
	}
}
//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_ExpressBoard::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_ExpressBoard::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_ExpressBoard::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_ExpressBoard::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_ExpressBoard::ReadINI( void )
{
	if ( ReadINI_Bool( L"ExpressBoard" ))
		return PatchEnable();
	return true;
}

bool CPatcher_ExpressBoard::WriteINI( void )
{
	WriteINI_Bool( L"ExpressBoard", IsPatchEnabled() );
	return true;
}