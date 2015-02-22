#include "Patcher_StatsFloating.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization
wchar_t CPatcher_StatsFloating::dataBuf[256];
LPBYTE CPatcher_StatsFloating::addrGetLuck = NULL;
LPBYTE CPatcher_StatsFloating::addrTargetReturn = NULL;
LPBYTE CPatcher_StatsFloating::addrCStringTEquals = NULL;

double CPatcher_StatsFloating::dummyDB100 = 100.00;

bool CPatcher_StatsFloating::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_StatsFloating::CPatcher_StatsFloating( void )
{
	patchname = "스텟 소숫점";

	wcscpy_s(dataBuf, sizeof(dataBuf), L"12.34");

	addrCStringTEquals = CAddr::Addr(CStringTUni_Equals);

	vector<WORD> patch;
	vector<WORD> backup;
	backup +=
		0x6A, 0x0A,
		0xBB, 0x80, 0x00, 0x00, 0x00,
		0x53,
		0x8D, 0x45, 0x00,
		0x50,
		0x57,
		0x8B, 0x3D, -1, -1, -1, -1,
		0xFF, 0xD7;

	funcPointer = (LPBYTE)patchStatsFloating;

	patch +=
		0x6A, 0x0A,
		0xBB, 0x80, 0x00, 0x00, 0x00,
		0x53,
		0x8D, 0x45, 0x00,
		0x50,
		0x57,
		0x8B, 0x3D, 
		((int)(&funcPointer) & 0xFF),
		(((int)(&funcPointer) & 0xFF00) >> 8),
		(((int)(&funcPointer) & 0xFF0000) >> 16),
		(((int)(&funcPointer) & 0xFF000000) >> 24),
		0xFF, 0xD7;

	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"Pleione.dll" );
	
	vector<WORD> patch1;
	vector<WORD> patch2;
	vector<WORD> patch3;
	vector<WORD> patch4;
	vector<WORD> patch5;
	vector<WORD> patch6;
	vector<WORD> backup1;
	vector<WORD> backup2;
	vector<WORD> backup3;
	vector<WORD> backup4;
	vector<WORD> backup5;
	vector<WORD> backup6;



	backup1 +=
		0x57,
		0x8B, 0xF9,
		0x8B, 0xCE,
		0xFF, 0x15, -1, -1, -1, -1,
		0xE8, -1, -1, -1, -1,
		0x50,
		0x8B, 0xCE,
		0xFF, 0x15, -1, -1, -1, -1,
		0xE8, -1, -1, -1, -1,
		0x8B, 0x8F;

	patch1 +=
		0x57,
		0x8B, 0xF9,
		0x8B, 0xCE,
		0xFF, 0x15, -1, -1, -1, -1,
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x50,
		0x8B, 0xCE,
		0xFF, 0x15, -1, -1, -1, -1,
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x8B, 0x8F;

	MemoryPatch mp1( NULL, patch1, backup1 );
	mp1.Search( L"Pleione.dll" );
	mp1.PatchRelativeAddress( 0x01, (LPBYTE)patchMultipleStats );


	backup2 +=
		0x59,
		0x59,
		0x8B, 0xCE,
		0xFF, 0x15, -1, -1, -1, -1,
		0xE8, -1, -1, -1, -1,
		0x50,
		0x8B, 0xCE,
		0xFF, 0x15, -1, -1, -1, -1,
		0xE8, -1, -1, -1, -1,
		0x8B, 0x8F, 0xBC, 0x01, 0x00, 0x00,
		0x50;

	patch2 +=
		0x59,
		0x59,
		0x8B, 0xCE,
		0xFF, 0x15, -1, -1, -1, -1,
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x50,
		0x8B, 0xCE,
		0xFF, 0x15, -1, -1, -1, -1,
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x8B, 0x8F, 0xBC, 0x01, 0x00, 0x00,
		0x50;

	MemoryPatch mp2( NULL, patch2, backup2 );
	mp2.Search( L"Pleione.dll" );
	mp2.PatchRelativeAddress( 0x01, (LPBYTE)patchMultipleStats );

	backup3 +=
		0x59,
		0x59,
		0x8B, 0xCE,
		0xFF, 0x15, -1, -1, -1, -1,
		0xE8, -1, -1, -1, -1,
		0x50,
		0x8B, 0xCE,
		0xFF, 0x15, -1, -1, -1, -1,
		0xE8, -1, -1, -1, -1,
		0x8B, 0x8F, 0xC0, 0x01, 0x00, 0x00,
		0x50;

	patch3 +=
		0x59,
		0x59,
		0x8B, 0xCE,
		0xFF, 0x15, -1, -1, -1, -1,
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x50,
		0x8B, 0xCE,
		0xFF, 0x15, -1, -1, -1, -1,
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x8B, 0x8F, 0xC0, 0x01, 0x00, 0x00,
		0x50;


	MemoryPatch mp3( NULL, patch3, backup3 );
	mp3.Search( L"Pleione.dll" );
	mp3.PatchRelativeAddress( 0x01, (LPBYTE)patchMultipleStats );

	backup4 +=
		0x59,
		0x59,
		0x8B, 0xCE,
		0xFF, 0x15, -1, -1, -1, -1,
		0xE8, -1, -1, -1, -1,
		0x50,
		0x8B, 0xCE,
		0xFF, 0x15, -1, -1, -1, -1,
		0xE8, -1, -1, -1, -1,
		0x8B, 0x8F, 0xC4, 0x01, 0x00, 0x00,
		0x50;

	patch4 +=
		0x59,
		0x59,
		0x8B, 0xCE,
		0xFF, 0x15, -1, -1, -1, -1,
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x50,
		0x8B, 0xCE,
		0xFF, 0x15, -1, -1, -1, -1,
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x8B, 0x8F, 0xC4, 0x01, 0x00, 0x00,
		0x50;


	MemoryPatch mp4( NULL, patch4, backup4 );
	mp4.Search( L"Pleione.dll" );
	mp4.PatchRelativeAddress( 0x01, (LPBYTE)patchMultipleStats );

	backup5 +=
		0x8B, 0xCF,
		0xE8, -1, -1, -1, -1,
		0x8B, 0x4D, -1,
		0xFF, 0x15, -1, -1, -1, -1,
		0xE8, -1, -1, -1, -1,
		0x8B, 0x4D, -1,
		0x50,
		0xFF, 0x15, -1, -1, -1, -1,
		0xE8, -1, -1, -1, -1,
		0x8B, 0x8F, -1, 0x01, 0x00, 0x00;

	patch5 +=
		0x8B, 0xCF,
		0xE8, -1, -1, -1, -1,
		0x8B, 0x4D, -1,
		0xFF, 0x15, -1, -1, -1, -1,
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x8B, 0x4D, -1,
		0x50,
		0xFF, 0x15, -1, -1, -1, -1,
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x8B, 0x8F, -1, 0x01, 0x00, 0x00;

	MemoryPatch mp5( NULL, patch5, backup5 );
	mp5.Search( L"Pleione.dll" );
	mp5.PatchRelativeAddress( 0x01, (LPBYTE)patchMultipleStats );
	
	backup6 +=
		0x8B, 0x8F, 0x70, 0x01, 0x00, 0x00,
		0x98,
		0x50,
		0xE8;

	patch6 +=
		0x98,
		0x50,
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x90,
		0xE8;

	MemoryPatch mp6( NULL, patch6, backup6 );
	mp6.Search( L"Pleione.dll" );
	mp6.PatchRelativeAddress( 0x01, (LPBYTE)patchMultipleStats2Defence );
	
	patches += mp;
	patches += mp1;
	patches += mp2;
	patches += mp3;
	patches += mp4;
	patches += mp5;
	patches += mp6;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions
void CPatcher_StatsFloating::patchStatsFloating(void)
{
	__asm JMP patchStatsFormat
}

long CPatcher_StatsFloating::patchMultipleStats(void)
{
	double db;

	__asm {
		FMUL QWORD PTR DS:[dummyDB100]
		SUB		ESP, 8h
		FSTP	QWORD PTR DS:[db]
	}
	return (long)db;
}
NAKED void CPatcher_StatsFloating::patchMultipleStats2Defence(void)
{
	__asm {
		PUSH EAX
		PUSH ECX
	}
	
	__asm {
		MOV ECX, 64h // 10진수 -> 100
		
		MOV EAX, DWORD PTR SS:[ESP+0x0C]
		MUL ECX
		MOV DWORD PTR SS:[ESP+0x0C], EAX

		MOV EAX, DWORD PTR SS:[ESP+0x10]
		MUL ECX
		MOV DWORD PTR SS:[ESP+0x10], EAX
	}

	__asm {
		POP ECX
		POP EAX
		MOV ECX,DWORD PTR DS:[EDI+0x170]
		RETN
	}
}
long __stdcall CPatcher_StatsFloating::_ftol(double fl) {
	return (long)fl;
}

void __stdcall CPatcher_StatsFloating::patchStatsFormat(int i, wchar_t * string, int size, int radix)
{
	float fl = (float)i;
	fl = fl / 100;
	//_itow_s(f, string, size, radix);
	//swprintf_s(string,size,L"%.2f",f);

	// 100배수 했으면 소숫점으로 표기
	if (IsPatchEnabled())
		swprintf_s(string,size,L"%.2f",fl);
	else swprintf_s(string,size,L"%.0f",fl);

	__asm {
		RETN
		//JMP _itow_s
		//		SUB ESP, 10h
//		RETN
	}
}

//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_StatsFloating::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_StatsFloating::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_StatsFloating::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_StatsFloating::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_StatsFloating::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_StatsFloating::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_StatsFloating::ReadINI( void )
{
	if ( ReadINI_Bool( L"StatsFloating" ))
		return PatchEnable();
	return true;
}

bool CPatcher_StatsFloating::WriteINI( void )
{
	WriteINI_Bool( L"StatsFloating", IsPatchEnabled() );
	return true;
}