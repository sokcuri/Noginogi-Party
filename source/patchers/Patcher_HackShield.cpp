#include "Patcher_HackShield.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

BYTE   CPatcher_HackShield::pushBackup[4]    = { 0x00, 0x00, 0x00, 0x00 };
LPBYTE CPatcher_HackShield::addrCRT          = NULL;
LPBYTE CPatcher_HackShield::addrReturn       = NULL;
LPBYTE CPatcher_HackShield::targetEntry      = NULL;
LPBYTE CPatcher_HackShield::moduleEntry		 = NULL;
LPBYTE CPatcher_HackShield::hDllInst		 = NULL;
int    CPatcher_HackShield::ignoredHSThreads = 1;
int	   CPatcher_HackShield::HSOffset		 = 0;
int	   CPatcher_HackShield::IsHSThreadLog	 = 0;
int	   CPatcher_HackShield::LoopCount		 = 0;

//-----------------------------------------------------------------------------
// Constructor

CPatcher_HackShield::CPatcher_HackShield( void )
{
    LPBYTE addrKernelBaseCRTX, addrKernel32CRT;

	patchname = "CRT Patch";

    addrKernelBaseCRTX = CAddr::Addr(kernelbase_CreateRemoteThreadEx);
	addrKernel32CRT    = CAddr::Addr(kernel32_CreateRemoteThread);

	if (!addrKernel32CRT)
	{
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
		WriteLog("   종속 요소가 없습니다.\n");
		return;
	}

    addrCRT = addrKernel32CRT;
    if (addrKernelBaseCRTX)
    {
        DebugLog("Patching CRTX.\n");
        addrCRT = addrKernelBaseCRTX;
    }

	vector<WORD> patch;
	vector<WORD> backup;

	// CreateRemoteThread[Ex] begins with 0x68 (PUSH xxxxxxxx), so we
    // save the value of the push in order to reproduce it later.
	MemoryPatch::ReadMem( addrCRT + 1, pushBackup, 4 );

	backup +=
		-1,   -1, -1, -1, -1,			        // -05: NOP (x5) or INT3 (x5)
		0x68, -1, -1, -1, -1;				    // +00: PUSH xxxxxxxx
	patch +=
		0xE9, 0x01FF, 0x01FF, 0x01FF, 0x01FF,	// -05: JMP LONG patchCRT
		0xEB, 0xF9,								// +00: JMP SHORT -5
		0x90, 0x90, 0x90;						// +02: NOP x3
	addrReturn = addrCRT + 0x05;

	MemoryPatch mp( addrCRT - 0x05, patch, backup );
	mp.PatchRelativeAddress( 0x01, (LPBYTE)patchCRT );

	patches += mp;
	if (CheckPatches())
		WriteLog("패치 초기화 성공: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_HackShield::patchCRT( void )
{
	
	hDllInst = (LPBYTE)GetModuleHandle( L"EhSvc.dll" );
	moduleEntry = (LPBYTE)GetModuleHandle( L"EhSvc.dll" );

	__asm {
		MOV EAX, DWORD PTR SS:[ESP+0x10]
		MOV DWORD PTR DS:[moduleEntry], EAX
	}

	// 자동찾기
	if (hDllInst != 0 && HSOffset == 0)
	{
		HSOffset = (int)moduleEntry-(int)hDllInst;
		WriteLog("** HSOffset auto found: %X (i=%d).\n", HSOffset, LoopCount);
	}

	if(hDllInst != 0)
	{
		LoopCount++;
	}

	if(IsHSThreadLog && hDllInst != 0)
		WriteLog("** EhSvc target found. base+%X (0x%X, i=%d).\n", moduleEntry-hDllInst, moduleEntry, LoopCount);

	//WriteLog("EhSvc Target entry point address: %x.\n", hDllInst);
	moduleEntry = (LPBYTE)GetModuleHandle( L"EhSvc.dll" );

	__asm {
		// If we have already looked up our target entry point, pass this bit
		CMP		targetEntry, 0
		JNZ		gotTargetEntry
	}

	// Get the module handle for EhSvc.dll -> this is a pointer to the base
	// of the DLL, which can be loaded into a variable location at runtime.
	// The result -should- be stored in EAX, though I guess it's compiler-
	// dependent.  It works on Visual Studio 2008 Pro.  And any reasonable
	// compiler should do the same.  Would have done this as a CALL instruction
	// but the way I tried it, the inline assembler didn't like the string.

	__asm {
		// The result is 0 (NULL) if EhSvc.dll has not yet been loaded
		CMP		EAX, 0
		JZ		notHSThread

		// We have the base of EhSvc.dll -- the target entry point in
		// HackShield 5.2.4.828 is base+64FC6.
		ADD		EAX, DWORD PTR DS:[HSOffset]
		MOV		targetEntry, EAX

gotTargetEntry:
		// If the entry point for this thread (ESP+10h) is not our target,
		// go back to CreateRemoteThread as if nothing happened :)
		MOV		EAX, targetEntry
        CMP     DWORD PTR SS:[ESP+0x10], EAX
        JNE     notHSThread

		// This thread has our target entry point-- check if we are
		// supposed to ignore this one
		CMP		ignoredHSThreads, 0
		JZ		patchThisThread

		// Ignore this thread and go back to CRT
		SUB		ignoredHSThreads, 1

notHSThread:
		// We patched over a PUSH xxxxxxxx (68 xx xx xx xx)
		// Since we patched over real code, we have to execute it before
		// we jump back.
		MOV		EAX, DWORD PTR pushBackup // DWORD pushBackup = "xx xx xx xx" above
		PUSH	EAX
	}

//	if(IsHSThreadLog && hDllInst != 0)
//		WriteLog("** EhSvc target passed. base+%x (0x%x, i=%d).\n", hDllInst-moduleEntry, hDllInst, 1-ignoredHSThreads);
/*
	if (1-ignoredHSThreads > 10)
	{
		// Remove the hook
		SngPatcher_HackShield::Instance()->Uninstall();
	}
*/
	//WriteLog("핵쉴드 쓰레드가 아니다.\n");
	__asm {
		// Return to CreateRemoteThread after the hook code
		JMP		addrReturn

		// Found our target thread!
patchThisThread:
		MOV		DWORD PTR DS:[hDllInst], EAX
	}

//	if (IsHSThreadLog)
	WriteLog("** EhSvc target patched. base+%X (0x%X, i=%d).\n", hDllInst-moduleEntry, hDllInst, LoopCount);

	// Remove the hook
	SngPatcher_HackShield::Instance()->Uninstall();

	__asm {
		// Set the thread's entry point to our dummy function
		MOV		DWORD PTR SS:[ESP+0x10], offset dummyFunction
		// Return to CreateRemoteThread (no more hook code in the way)
		JMP		addrCRT
	}
}

DWORD WINAPI CPatcher_HackShield::dummyFunction( LPVOID lpParam )
{
	while(g_isRunning) {
		Sleep(INFINITE);
	}
	return 0;
}
//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_HackShield::Install( void ) {

	wchar_t buf[256];
	wchar_t *endptr = NULL;

    if ( !ReadINI_Bool( L"DisableHSPatch" )) {

		// 오프셋 문자열에서 16진수로 변환.
		ReadINI_String( L"HSThreadOffset", buf);
		HSOffset = wcstoul(buf, &endptr, 16);

		WriteLog("HSThreadOffset: %x.\n", HSOffset);

		// 핵쉴드 쓰레드 로그
		IsHSThreadLog = ReadINI_Bool( L"HSTOffsetLogging");

		// 핵쉴드 쓰레드 횟수
		ignoredHSThreads = ReadINI_Int( L"HSThreadNumber", 0, 10) - 1;

		WriteLog("HSThreadNumber: %d.\n", ignoredHSThreads);

		return Install2();
    }
	return true;
}

bool CPatcher_HackShield::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_HackShield::ReadINI( void )
{
	return true;
}

bool CPatcher_HackShield::WriteINI( void )
{
	// This patch cannot be disabled or enabled at runtime
	return true;
}