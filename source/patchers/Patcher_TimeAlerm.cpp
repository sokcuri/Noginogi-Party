#include "Patcher_TimeAlerm.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization
wchar_t CPatcher_TimeAlerm::dataBuf[256];

int CPatcher_TimeAlerm::CurNo = 0;

int CPatcher_TimeAlerm::tempRinged=0;
int CPatcher_TimeAlerm::tempUsing;
int CPatcher_TimeAlerm::tempHour;
int CPatcher_TimeAlerm::tempHour1;
int CPatcher_TimeAlerm::tempHour2;
int CPatcher_TimeAlerm::tempMin;
int CPatcher_TimeAlerm::tempMin1;
int CPatcher_TimeAlerm::tempMin2;
int CPatcher_TimeAlerm::tempCode;
wchar_t *CPatcher_TimeAlerm::tempText;

int CPatcher_TimeAlerm::AlermRinged[10];
int CPatcher_TimeAlerm::AlermUsing[10];
int CPatcher_TimeAlerm::AlermHour[10];
int CPatcher_TimeAlerm::AlermHour1[10];
int CPatcher_TimeAlerm::AlermHour2[10];
int CPatcher_TimeAlerm::AlermMin[10];
int CPatcher_TimeAlerm::AlermMin1[10];
int CPatcher_TimeAlerm::AlermMin2[10];
int CPatcher_TimeAlerm::AlermCode[10];

int CPatcher_TimeAlerm::DisableDummy;

wchar_t CPatcher_TimeAlerm::AlermText[10][256];

LPBYTE CPatcher_TimeAlerm::addrAlerm = NULL;
LPBYTE CPatcher_TimeAlerm::addrNoAlerm = NULL;
LPBYTE CPatcher_TimeAlerm::addrTargetReturn = NULL;
LPBYTE CPatcher_TimeAlerm::addrTargetReturn2 = NULL;

LPBYTE CPatcher_TimeAlerm::addrGetGlobalTime = NULL;
LPBYTE CPatcher_TimeAlerm::addrGlobalTimeToGameTime = NULL;
LPBYTE CPatcher_TimeAlerm::addrIsUsingNaosSupport = NULL;
LPBYTE CPatcher_TimeAlerm::addrShowCaption = NULL;
LPBYTE CPatcher_TimeAlerm::addrShowChatMsg = NULL;
LPBYTE CPatcher_TimeAlerm::addrCStringTUni_wchar = NULL;
LPBYTE CPatcher_TimeAlerm::addrGetObjectId = NULL;

wchar_t CPatcher_TimeAlerm::NaoRecharged[] = L"code.client.msg.nao_support.recharged";

bool CPatcher_TimeAlerm::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_TimeAlerm::CPatcher_TimeAlerm( void )
{
	patchname = "노기노기 사념파 알람";

	addrGetGlobalTime = CAddr::Addr(stdapi_GetGlobalTime);
	addrGlobalTimeToGameTime = CAddr::Addr(stdapi_GlobalTimeToGameTime);
	addrIsUsingNaosSupport = CAddr::Addr(IServiceMgr_IsUsingNaosSupport);
	addrShowCaption = CAddr::Addr(stdapi_ShowCaption);
	addrShowChatMsg = CAddr::Addr(stdapi_ShowChattingMessage);
	if (!addrGetGlobalTime ||
		!addrGlobalTimeToGameTime ||
		!addrIsUsingNaosSupport ||
		!addrShowCaption ||
		!addrShowChatMsg) {
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
		WriteLog("   종속 요소가 없습니다.\n");
		return;
	}

	vector<WORD> patch1;
	vector<WORD> patch2;
	vector<WORD> patch3;
	vector<WORD> backup1;
	vector<WORD> backup2;
	vector<WORD> backup3;

	backup1 +=
		0x8B, 0x8E, -1, -1, -1, -1,		// MOV ECX,DWORD PTR DS:[ESI+118h]
		0xFF, 0x15, -1, -1, -1, -1,		// CALL DWORD PTR DS:[xxxxxxxx] (Standard.?IsUsingNaosSupport@IServiceMgr@core@@QBE_NXZ)
		0xBF, 0x88, 0x13, 0x00, 0x00,	// MOV EDI, 1388h
		0x84, 0xC0;						// TEST AL, AL

	funcPointer1 = (LPBYTE)patchTimeAlerm;

	patch1 +=
		-1, -1, -1, -1, -1, -1,
		0xFF, 0x15,
		((int)(&funcPointer1) & 0xFF),
		(((int)(&funcPointer1) & 0xFF00) >> 8),
		(((int)(&funcPointer1) & 0xFF0000) >> 16),
		(((int)(&funcPointer1) & 0xFF000000) >> 24),
		-1, -1, -1, -1, -1,
		-1, -1;

	MemoryPatch mp1( NULL, patch1, backup1 );
	mp1.Search(L"Pleione.dll");

	addrAlerm = mp1.GetAddr() + 0xB7;
	addrNoAlerm = mp1.GetAddr() + 0x8A;

	backup2 +=
		0xC6, 0x45, 0xFC, 0x03,					// +1D0: MOV BYTE PTR SS:[EBP-4],3
		0xFF, 0x15, -1, -1, -1, -1,				// +1D4: CALL DWORD PTR DS:[xxxxxxxx] (ESL.??BCFormatter@esl@@QBE?AV?$CStringT@_WVunicode_string_trait@esl@@Vunicode_string_implement@2@@1@XZ)
		0x33, 0xC0,								// +1DA: XOR EAX, EAX
		0x50,									// +1DC: PUSH EAX
		0x50,									// +1DD: PUSH EAX
		0x6A, 0xFF,								// +1DE: PUSH -1
		0x57,									// +1E0: PUSH EDI
		0x57,									// +1E1: PUSH EDI
		0x6A, 0x04;								// +1E2: PUSH 4

	funcPointer2 = (LPBYTE)patchTimeAlermCaption;

	patch2 +=
		-1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1,
		-1, -1,
		0x50,
		0x50,
		0xFF,
		0x25,
		((int)(&funcPointer2) & 0xFF),
		(((int)(&funcPointer2) & 0xFF00) >> 8),
		(((int)(&funcPointer2) & 0xFF0000) >> 16),
		(((int)(&funcPointer2) & 0xFF000000) >> 24);

	MemoryPatch mp2( NULL, patch2, backup2 );
	mp2.Search(L"Pleione.dll");

	addrTargetReturn = mp2.GetAddr() + 0x14;

	patches += mp1;
	patches += mp2;

	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_TimeAlerm::patchTimeAlerm(void)
{
	__asm {
		PUSH	EAX
	}

	if (IsPatchEnabled() == false)
	{
		if (DisableDummy == 0)
		{
			AlermRinged[0] = 0;
			AlermRinged[1] = 0;
			AlermRinged[2] = 0;
			AlermRinged[3] = 0;
			AlermRinged[4] = 0;
			AlermRinged[5] = 0;
			AlermRinged[6] = 0;
			AlermRinged[7] = 0;
			AlermRinged[8] = 0;
			AlermRinged[9] = 0;
			DisableDummy = 1;
		}
		__asm {
			POP		EAX		
			JMP		addrIsUsingNaosSupport				// DS:[63CF1878]=019878EC (Standard.?IsUsingNaosSupport@IServiceMgr@core@@QBE_NXZ)
		}
	}
		tempRinged = AlermRinged[CurNo];
		tempHour = AlermHour[CurNo];
		tempHour1 = AlermHour1[CurNo];
		tempHour2 = AlermHour2[CurNo];
		tempMin = AlermMin[CurNo];
		tempMin1 = AlermMin1[CurNo];
		tempMin2 = AlermMin2[CurNo];
		tempCode = AlermCode[CurNo];
		tempUsing = AlermUsing[CurNo];
		tempText = (wchar_t *)&AlermText[CurNo];

	// 알람 작동
	if (IsPatchEnabled())
	{
		__asm {
			POP		EAX
			MOV		DisableDummy, 0
			ADD		ESP, 4h							// Stack POP
			MOV		EDI, 1388h
			LEA		EAX, DWORD PTR SS:[EBP-28h]		// Game Time; Minute
			PUSH	EAX
			LEA		EAX, DWORD PTR SS:[EBP-1Ch]		// Game Time; Hour
			PUSH	EAX
			LEA		EAX, DWORD PTR SS:[EBP-18h]		// Game Time; (Unknown)
			PUSH	EAX
			CALL	addrGetGlobalTime
			PUSH	EDX
			PUSH	EAX
			CALL	addrGlobalTimeToGameTime
			ADD		ESP, 14h

			// 사용여부에 따라 분류
			CMP		tempUsing, 0
			JE		lEnd2
			
			// 울리는 시간이 정해져 있으면 점프
			CMP		tempHour, 24
			MOV		EAX, tempHour1
			JNE		lNext

			// 시간 상관없는 경우
			MOV		EAX, tempMin1
			CMP		EAX, tempMin2
			JA		lAlermHour24Right
			JMP		lAlermHour24Left

			// AlermMin1 < AlermMin2
			lAlermHour24Left:
			MOV		EAX, tempMin1
			CMP		DWORD PTR SS:[EBP-28h], EAX
			JB		lEnd
			MOV		EAX, tempMin2
			CMP		DWORD PTR SS:[EBP-28h], EAX
			JA		lEnd
			JMP		lAlerm

			// AlermMin1 > AlermMin2
			lAlermHour24Right:
			MOV		EAX, tempMin1
			CMP		DWORD PTR SS:[EBP-28h], EAX
			JA		lAlerm
			MOV		EAX, tempMin2
			CMP		DWORD PTR SS:[EBP-28h], EAX
			JB		lAlerm
			JMP		lEnd

			lNext:

			// 시간이 정해져 있는 경우
			MOV		EAX, tempHour1
			CMP		EAX, tempHour2
			JA		lMoreHour						// AlermHour1 > AlermHour2
			JE		lEqualHour						// AlermHour1 = AlermHour2
			JMP		lLessHour						// AlermHour1 < AlermHour2


			// 0] 1 2 3 ... 21 22 23 [24
			lMoreHour:
			MOV		EAX, tempHour2
			CMP		DWORD PTR SS:[EBP-1Ch], EAX
			JE		lMoreHour24
			MOV		EAX, tempHour1
			CMP		DWORD PTR SS:[EBP-1Ch], EAX
			JE		lMoreHour23
			JMP		lEnd
			
			lMoreHour23:
			// 23시
			MOV		EAX, tempMin1
			CMP		DWORD PTR SS:[EBP-28h], EAX
			JAE		lAlerm
			JMP		lEnd									// 23시 57분 이전

			lMoreHour24:
			// 24시
			MOV		EAX, tempMin2
			CMP		DWORD PTR SS:[EBP-28h], EAX
			JBE		lAlerm
			JMP		lEnd									// 0시 3분 이후

			// 같은 시간
			lEqualHour:
			MOV		EAX, tempHour1
			CMP		EAX, DWORD PTR SS:[EBP-1Ch]
			JNE		lEnd									// 시간이 다르다
			JMP		lCompareMin

			// 분 비교
			lCompareMin:
			MOV		EAX, tempMin1
			CMP		DWORD PTR SS:[EBP-28h], EAX
			JB		lEnd
			MOV		EAX, tempMin2
			CMP		DWORD PTR SS:[EBP-28h], EAX
			JA		lEnd
			JMP		lAlerm

			// 0 1 [2 3] 4 5 ...
			lLessHour:
			MOV		EAX, tempHour1
			CMP		DWORD PTR SS:[EBP-1Ch], EAX
			JE		lLessHourLeft

			MOV		EAX, tempHour2
			CMP		DWORD PTR SS:[EBP-1Ch], EAX
			JE		lLessHourRight
			JMP		lEnd

			lLessHourLeft:
			MOV		EAX, tempMin1
			CMP		DWORD PTR SS:[EBP-28h], EAX
			JB		lEnd
			JMP		lAlerm

			lLessHourRight:
			MOV		EAX, tempMin2
			CMP		DWORD PTR SS:[EBP-28h], EAX
			JA		lEnd
			JMP		lAlerm

			// 알람 처리
			lAlerm:
			CMP		tempRinged, 1					// 알람이 이미 울렸을때 점프
			JE		lEnd2

			MOV		tempRinged, 1
			PUSH	DWORD PTR SS:[EBP-28h]
			PUSH	DWORD PTR SS:[EBP-1Ch]
			PUSH	DWORD PTR DS:[tempText]
			PUSH	offset dataBuf
			CALL	patchFormat
			PUSH	offset dataBuf
		}

		AlermRinged[CurNo] = tempRinged;

		if (CurNo == 9)
			CurNo = 0;
		else CurNo = CurNo+1;

		__asm {
			JMP		addrAlerm


			// 걍 없던걸로
			lEnd:
			MOV		tempRinged, 0
			MOV		EAX, 0
			TEST	EAX, EAX
		}

		AlermRinged[CurNo] = tempRinged;

		if (CurNo == 9)
			CurNo = 0;
		else CurNo = CurNo+1;

		__asm {

			JMP		addrNoAlerm

			// 알람 딜레이 (이미 한번 울렸다)
			lEnd2:
			MOV		EAX, 0
			TEST	EAX, EAX
		}

		AlermRinged[CurNo] = tempRinged;

		if (CurNo == 9)
			CurNo = 0;
		else CurNo = CurNo+1;

		__asm {
			JMP		addrNoAlerm
		}
	}/*
	else
	{
		__asm {
			MOV		tempRinged, 0
		}

		AlermRinged[CurNo] = tempRinged;

		if (CurNo == 9)
			CurNo = 0;
		else CurNo = CurNo+1;

		__asm {
			POP		EAX
			JMP		addrIsUsingNaosSupport				// DS:[63CF1878]=019878EC (Standard.?IsUsingNaosSupport@IServiceMgr@core@@QBE_NXZ)

		}
	}*/
}

NAKED void CPatcher_TimeAlerm::patchTimeAlermCaption(void)
{
	__asm {
		PUSH	-1
		PUSH	EDI
		PUSH	EDI

		// 알람 작동
		PUSH	EAX
	}

	if (IsPatchEnabled())
	{
		__asm {
			POP EAX
			PUSH DWORD PTR DS:[tempCode]
		}
	}
	else
	{
		__asm {
			POP EAX
			PUSH offset NaoRecharged
		}
	}

	__asm {
		JMP		addrTargetReturn
	}
}
//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_TimeAlerm::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_TimeAlerm::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_TimeAlerm::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_TimeAlerm::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_TimeAlerm::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_TimeAlerm::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}

//-----------------------------------------------------------------------------
// Options

bool CPatcher_TimeAlerm::SetString( wchar_t *string )
{
	//wcsncpy_s( AlermText, 256, string, _TRUNCATE );

	return true;
}
string __fastcall str_replace(const string &str, const string &pattern, const string &replace)   
{   
	string result = str;   
	string::size_type pos = 0;   
	string::size_type offset = 0;   

	while((pos = result.find(pattern, offset)) != string::npos)   
	{   
		result.replace(result.begin() + pos, result.begin() + pos + pattern.size(), replace);   
		offset = pos + replace.size();   
	}   

	return result;   
}
void __stdcall CPatcher_TimeAlerm::patchFormat(wchar_t * buff,wchar_t * str,int hour,int min)
{
	swprintf_s(buff,255,str,(hour+(min+3)/60)%24,(min+3)%60);
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_TimeAlerm::ReadINI( void )
{
	ReadINIAll();
	return true;
}

bool CPatcher_TimeAlerm::ReadINIAll( void )
{
	wchar_t buf[256];
	wchar_t inibuf[256];

	for (int i=0; i<10; i++)
	{
		//wcsncpy_s( buf2, 256, string, _TRUNCATE );
		swprintf( inibuf, 256, L"Alerm%d_%s", i+1, L"Text" );
		ReadINI_String( inibuf, buf );
		wcsncpy_s( AlermText[i], 256, buf, _TRUNCATE );
		//WriteLog("INI READ - %ls: %ls\n", inibuf, AlermText[i]);
		//wcsncpy_s( AlermText, 256, string, _TRUNCATE );
		//if (buf != NULL) SetString( buf );

		swprintf( inibuf, 256, L"Alerm%d_%s", i+1, L"Using" );
		AlermUsing[i] = ReadINI_Int( inibuf, 0, 24);

		swprintf( inibuf, 256, L"Alerm%d_%s", i+1, L"Hour" );
		AlermHour[i] = ReadINI_Int( inibuf, 0, 24);
		//WriteLog("INI READ - %ls: %d\n", inibuf, AlermHour[i]);

		swprintf( inibuf, 256, L"Alerm%d_%s", i+1, L"Min" );
		AlermMin[i] = ReadINI_Int( inibuf, 0, 60);
		//WriteLog("INI READ - %ls: %d\n", inibuf, AlermMin[i]);

		AlermMin1[i] = (AlermMin[i] - 4)%60;
		AlermMin2[i] = (AlermMin[i])%60;

		AlermHour1[i] = (AlermHour[i] - (AlermMin[i]/60))%24;
		AlermHour2[i] = (AlermHour[i] + (AlermMin[i]/60))%24;

		if(AlermMin[i] - 4 < 0)
		{
			AlermHour1[i] = AlermHour[i] - 1;
			AlermMin1[i] = (60 + AlermMin[i] - 4);
		}

		swprintf( inibuf, 256, L"Alerm%d_%s", i+1, L"Code" );
		AlermCode[i] = ReadINI_Int( inibuf, 1, 9);
		//WriteLog("INI READ - %ls: %d\n", inibuf, AlermCode[i]);
		if (AlermCode[i] < 1 && AlermCode[i] > 9)
			AlermCode[i] = 3;
	}

	if ( ReadINI_Bool( L"TimeAlerm" ))
	{
		return PatchEnable();
	}
	return true;
}

bool CPatcher_TimeAlerm::WriteINI( void )
{
	//WriteINI_Bool( L"TimeAlerm", IsPatchEnabled() );
	return true;
}