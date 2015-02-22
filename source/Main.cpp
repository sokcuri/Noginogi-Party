// Mabinogi NogiParty Patch
// Created by Jinsu
// based by FANTASIA PATCH by spr33

// This source requires the Boost C++ libraries.
// http://www.boost.org/
// The default project configuration includes from
// the directory C:\Program Files\boost\boost_1_40_0\
// To change this, go to Project -> ijl15 Properties... ->
// Configuration Properties -> C/C++ -> General, and
// modify "Additional Include Directories".
#include "Main.h"

#include "Addr.h"
#include "FileSystem.h"
#include "DBGHook.h"
#include "patchers\MasterPatcher.h"

#define NOGI_VERSION "lv234"

//-------------------------------------------------------------------
// Global variables

HHOOK hHook;
bool g_isRunning;
HINSTANCE g_hInstance;

//-------------------------------------------------------------------
// Functions
void HSFuckInit();

bool WINAPI DllMain( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved )
{
	try
	{
		switch (fdwReason)
		{
		case DLL_PROCESS_ATTACH:
			{
				//time_t start, stop;
				//start = time(NULL);

				//HSFuckInit();

				g_hInstance = hinstDLL;
				g_isRunning = true;

				g_iniFile = GetCurPath();
				g_iniFile += L"\\nogiparty.ini";

				DeleteFile(L".\\nogi_partylog.txt");
				WriteLog("진수의 노기노기 파티 %s\n", NOGI_VERSION);
				WriteLog("Compile at %s %s\n", __DATE__, __TIME__);
				WriteLog("초기화를 완료했습니다. 작업을 시작합니다.\n");
				
				// dbgHelp 후킹해서 GetAddress하기
				if(!SngDBGHook::Instance()->Hook()) return false;

				// 얻어올 주소 담기
				CAddr::PreCacheAddresses();

				// 전체 인스톨하기
				CMasterPatcher::PatchInstall();

				// INI에서 패치하기
				CMasterPatcher::PatchFromINI();

				WriteLog("노기노기 파티 작업이 성공했습니다.\n");
				break;
			}

		case DLL_THREAD_ATTACH:break;
		case DLL_THREAD_DETACH:break;
		case DLL_PROCESS_DETACH:
			{
				// 훅을 해제한다
				UnhookWindowsHookEx(hHook);

				WriteLog("노기노기 파티가 언로드 되었습니다.\n");
				break;
			}
		}
		return true;
	}
	catch(...)
	{
		WriteLog("노기노기 파티 초기화에 실패했습니다.");
	}
}