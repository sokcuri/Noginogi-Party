#include "Patcher_TimeAlerm.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

wchar_t CPatcher_TimeAlerm::AlermText[256] = L"하야쿠 시간됨 %d %d";
wchar_t CPatcher_TimeAlerm::dataBuf[256];

int CPatcher_TimeAlerm::AlermHour;
int CPatcher_TimeAlerm::AlermHour1;
int CPatcher_TimeAlerm::AlermHour2;
int CPatcher_TimeAlerm::AlermMin;
int CPatcher_TimeAlerm::AlermMin1;
int CPatcher_TimeAlerm::AlermMin2;

int CPatcher_TimeAlerm::CaptionCode = 4;

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

bool CPatcher_TimeAlerm::IsAlermed = false;
bool CPatcher_TimeAlerm::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_TimeAlerm::CPatcher_TimeAlerm( void )
{
	patchname = "Time Alerm";

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
	/*
	backup3 +=
		0xC6, 0x45, 0xFC, 0x04,					// +1EE: MOV BYTE PTR SS:[EBP-4],4
		0xFF, 0x15, -1, -1, -1, -1,				// +1F2: CALL DWORD PTR DS:[xxxxxxxx] (Standard.?stdapi_ShowCaption@core@@YAX_KABV?$CStringT@_WVunicode_string_trait@esl@@Vunicode_string_implement@2@@esl@@W4EMessageCaptionType@@KKK0@Z)
		0x83, 0xC4, 0x24,						// +1F8: ADD ESP,24
		0x8D, 0x4D, 0xE0,						// +1FB: LEA ECX,DWORD PTR SS:[EBP-20]
		0xC6, 0x45, 0xFC, 0x03	,				// +1FE: MOV BYTE PTR SS:[EBP-4],3
		0xFF, 0xD3;								// +202: CALL EBX

	funcPointer3 = (LPBYTE)patchTimeAlermChatMsg;

	patch3 +=
		-1, -1, -1, -1,
		0xFF, 0x15,
		((int)(&funcPointer3) & 0xFF),
		(((int)(&funcPointer3) & 0xFF00) >> 8),
		(((int)(&funcPointer3) & 0xFF0000) >> 16),
		(((int)(&funcPointer3) & 0xFF000000) >> 24),
		0x83, 0xC4, 0x24,
		-1, -1, -1,
		-1, -1, -1, -1,
		-1, -1;

	MemoryPatch mp3( NULL, patch3, backup3 );
	mp3.Search(L"Pleione.dll");

	addrTargetReturn = mp3.GetAddr() + 0x0A + 0x03;
*/
	patches += mp1;
	patches += mp2;
	//patches += mp3;
	if (CheckPatches())
		WriteLog("패치 초기화 성공: %s.\n", patchname.c_str());
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

	// 알람 작동
	if (IsPatchEnabled())
	{
		__asm {
			POP		EAX
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

			CMP		AlermHour, 24
			JE		lCompareMin

			MOV		EAX, AlermHour1
			CMP		EAX, AlermHour2
			JA		lMoreHour						// AlermHour1 > AlermHour2
			JE		lEqualHour						// AlermHour1 = AlermHour2
			JMP		lLessHour						// AlermHour1 < AlermHour2


			// 0] 1 2 3 ... 21 22 23 [24
			lMoreHour:
			MOV		EAX, AlermHour2
			CMP		DWORD PTR SS:[EBP-1Ch], EAX
			JE		lMoreHour24
			MOV		EAX, AlermHour1
			CMP		DWORD PTR SS:[EBP-1Ch], EAX
			JE		lMoreHour23
			JMP		lEnd
			
			lMoreHour23:
			// 23시
			MOV		EAX, AlermMin1
			CMP		DWORD PTR SS:[EBP-28h], EAX
			JAE		lAlerm
			JMP		lEnd									// 23시 57분 이전

			lMoreHour24:
			// 24시
			MOV		EAX, AlermMin2
			CMP		DWORD PTR SS:[EBP-28h], EAX
			JBE		lAlerm
			JMP		lEnd									// 0시 3분 이후

			// 같은 시간
			lEqualHour:
			MOV		EAX, AlermHour1
			CMP		EAX, DWORD PTR SS:[EBP-1Ch]
			JNE		lEnd									// 시간이 다르다

			// 분 비교
			lCompareMin:
			MOV		EAX, AlermMin1
			CMP		DWORD PTR SS:[EBP-28h], EAX
			JB		lEnd
			MOV		EAX, AlermMin2
			CMP		DWORD PTR SS:[EBP-28h], EAX
			JA		lEnd
			JMP		lAlerm

			// 0 1 [2 3] 4 5 ...
			lLessHour:
			MOV		EAX, AlermHour1
			CMP		DWORD PTR SS:[EBP-1Ch], EAX
			JNE		lNext

			// 2시 57분 이전 모두 점프
			MOV		EAX, AlermMin1
			CMP		DWORD PTR SS:[EBP-28h], EAX
			JB		lEnd
			JMP		lAlerm

			lNext:
			// 2시도 3시도 아닌것들 골라내기
			MOV		EAX, AlermHour2
			CMP		DWORD PTR SS:[EBP-1Ch], EAX
			JNE		lEnd

			// 3시 3분 이후 모두 점프
			MOV		EAX, AlermMin2
			CMP		DWORD PTR SS:[EBP-28h], EAX
			JA		lEnd
			JMP		lAlerm

			// 알람 처리
			lAlerm:
			CMP		IsAlermed, 1					// 알람이 이미 울렸을때 점프
			JE		lEnd2

			MOV		IsAlermed, 1
			PUSH	DWORD PTR SS:[EBP-28h]
			PUSH	DWORD PTR SS:[EBP-1Ch]
			PUSH	offset AlermText
			PUSH	offset dataBuf
			CALL	patchFormat
			PUSH	offset dataBuf
			JMP		addrAlerm


			// 걍 없던걸로
			lEnd:
			MOV		IsAlermed, 0
			MOV		EAX, 0
			TEST	EAX, EAX
			JMP		addrNoAlerm

			// 알람 딜레이 (이미 한번 울렸다)
			lEnd2:
			MOV		EAX, 0
			TEST	EAX, EAX
			JMP		addrNoAlerm
		}
	}
	else
	{
		__asm {
			MOV		IsAlermed, 0
			POP		EAX
			JMP		addrIsUsingNaosSupport				// DS:[63CF1878]=019878EC (Standard.?IsUsingNaosSupport@IServiceMgr@core@@QBE_NXZ)

		}
	}
}

NAKED void CPatcher_TimeAlerm::patchTimeAlermCaption(void)
{
	__asm {
		PUSH	-1
		PUSH	EDI
		PUSH	EDI
		PUSH	dword ptr ds:[CaptionCode]
		JMP		addrTargetReturn
	}
}

NAKED void CPatcher_TimeAlerm::patchTimeAlermChatMsg(void)
{
	__asm {
		ADD		ESP, 4h
		CALL	addrShowCaption

		ADD		ESP,24h
		PUSH	63CFA018h							// UNICODE "<SYSTEM>"
		LEA		ECX,DWORD PTR SS:[EBP-14h]
		CALL	addrCStringTUni_wchar
		PUSH	EDI
		PUSH	EDI
		PUSH	0xFFFF8080
		LEA		EAX,DWORD PTR SS:[EBP+8h]
		PUSH	EAX
		LEA		EAX,DWORD PTR SS:[EBP-14h]
		PUSH	EAX
		MOV		EAX,DWORD PTR SS:[EBP-18h]
		MOV		ECX,DWORD PTR DS:[EAX+28h]
		MOV		BYTE PTR SS:[EBP-4h],4h
		CALL	addrGetObjectId
		PUSH	EDX
		PUSH	EAX
		CALL	addrShowChatMsg
		ADD		ESP,1Ch
		JMP		addrTargetReturn2

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
	wcsncpy_s( AlermText, 256, string, _TRUNCATE );

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
	if ( ReadINI_Bool( L"TimeAlerm" ))
	{
		wchar_t buf[256];
		ReadINI_String( L"TimeAlerm_str", buf );
		if (buf != NULL) SetString( buf );
		AlermHour = ReadINI_Int( L"AlermHour", 0, 24);
		AlermMin = ReadINI_Int( L"AlermMin", 0, 60);
		WriteLog("알람 정보-시간: %d.\n", AlermHour);
		WriteLog("알람 정보-분: %d.\n", AlermMin);

		AlermMin1 = (AlermMin - 3)%60;
		AlermMin2 = (AlermMin + 4)%60;
		WriteLog("AlermMin1: %d.\n", AlermMin1);
		WriteLog("AlermMin2: %d.\n", AlermMin2);
		
		AlermHour1 = (AlermHour - (AlermMin/60))%24;
		AlermHour2 = (AlermHour + (AlermMin/60))%24;

		if(AlermMin - 3 < 0)
		{
			AlermHour1 = AlermHour - 1;
			AlermMin1 = (60 + AlermMin - 3);
		}

		WriteLog("AlermMin1+: %d.\n", AlermMin1);
		WriteLog("AlermMin2+: %d.\n", AlermMin2);
		
		CaptionCode = ReadINI_Int( L"CaptionCode", 0, 10);
		if (CaptionCode < 0 && CaptionCode > 10)
			CaptionCode = 3;


		/*
		// 시계 수정 (3분을 빼서 0보다 작게 되면)
		if (AlermMin - 3 < 0)
		{
			AlermMin1 = 60 + AlermMin - 3;
			
			// 모든시간 해당이 아닐때만
			if (AlermHour != 24)
			{
				AlermHour1 = abs(AlermHour-1)%24;
			}
			else
			{
				AlermHour1 = 24;	// 시간이 상관없이
			}
		// 수정 해당사항 없는 경우
		} else {
			AlermMin1 = AlermMin;
			AlermHour1 = AlermHour;
		}

		// 나머지 처리
		AlermMin2 = AlermMin;
		AlermHour2 = AlermHour;

		int tmp;

		// 체크
		if (AlermMin1 > AlermMin2)
		{
			tmp = AlermMin1;
			AlermMin1 = AlermMin2;
			AlermMin2 = tmp;
		}

		if (AlermHour1 > AlermHour2)
		{
			tmp = AlermHour1;
			AlermHour1 = AlermHour2;
			AlermHour2 = tmp;
		}*/
			

		return PatchEnable();
	}
	return true;
}

bool CPatcher_TimeAlerm::WriteINI( void )
{
	WriteINI_Bool( L"TimeAlerm", IsPatchEnabled() );
	return true;
}