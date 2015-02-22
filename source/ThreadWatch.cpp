#include "ThreadWatch.h"
#include "FileSystem.h"
#include "ModifyWindow.h"

// Lists of thread IDs and handles
// Do not add the watcher thread to these lists!
static set<DWORD> threadList = set<DWORD>();

// Watcher thread ID and handle
static DWORD tidWatcherThread = 0;
static HANDLE hWatcherThread = NULL;

// CPU mod settings
static int reductionPercentage = 0;
static bool onlyWhileMinimized = true;


set<DWORD> CThreadWatch::GetList( void )
{
	// DO NOT MODIFY THREAD LIST HERE
	// This function is called by the ModifyWindow thread!
	// If we are in the middle of some code which loops through this
	// list, and we modify it here, we are FUUUUCKED :(
	return threadList;
}

bool CThreadWatch::UpdateList( void )
{
	threadList.clear();

	DWORD pid = GetCurrentProcessId();
	HANDLE hSnapshot = CreateToolhelp32Snapshot( TH32CS_SNAPTHREAD, 0 );
	THREADENTRY32 te;
	te.dwSize = sizeof(te);

	if (!Thread32First( hSnapshot, &te ))
	{
		CloseHandle( hSnapshot );
		return false;
	}

	do
	{
		if ((te.th32OwnerProcessID == pid) &&
			(te.th32ThreadID != tidWatcherThread))
		{
			threadList.insert( te.th32ThreadID );
		}
	}
	while (Thread32Next(hSnapshot, &te));
	CloseHandle( hSnapshot );
	return true;
}


bool CThreadWatch::SpawnWatcher( void )
{
	SECURITY_ATTRIBUTES ThreadAttributes;
	ThreadAttributes.bInheritHandle = false;
	ThreadAttributes.lpSecurityDescriptor = NULL;
	ThreadAttributes.nLength = sizeof( SECURITY_ATTRIBUTES );

	DWORD tid;
	HANDLE hThr = CreateThread( &ThreadAttributes, 0, WatcherThreadMain, NULL, 0, &tid );
	if (hThr == NULL) {
		DebugLog("에러: 감시 쓰레드에서 CreateThread 함수를 불러오지 못했습니다.\n");
		return false;
	}

	hWatcherThread = hThr;
	tidWatcherThread = tid;

	if (!SetThreadPriority( hWatcherThread, THREAD_PRIORITY_TIME_CRITICAL ))
	{
		DebugLog("경고: 감시 쓰레드에서 SetThreadPriority 함수를 불러오지 못했습니다.\n");
	}
	return true;
}

DWORD WINAPI CThreadWatch::WatcherThreadMain( LPVOID lpParam )
{
	UpdateList(); // Get the initial list set up so ModifyWindow can find our HWnd
	while(g_isRunning)
	{
		if ((reductionPercentage == 0) ||
			(onlyWhileMinimized && !CModifyWindow::IsMinimized()))
		{
			Sleep(1000);
		}
		else
		{
			UpdateList();
			SleepAll();
			Sleep(reductionPercentage);
			WakeAll();
			Sleep(100-reductionPercentage);
		}
	}
	return 0;
}

bool CThreadWatch::SleepAll( void )
{
	bool result = true;
	set<DWORD>::iterator it;
	for (it = threadList.begin(); it != threadList.end(); it++)
	{
		HANDLE hThr = OpenThread( THREAD_SUSPEND_RESUME, false, *it );
		if (hThr == NULL)
		{
			DebugLog("에러: 쓰레드 핸드를 열 수 없습니다.  Id: 0x%lX\n", *it);
			result = false;
		}
		else
		{
			if (-1 == SuspendThread( hThr ))
			{
				DebugLog("에러: 쓰레드를 일시정지 할 수 없습니다.  Id: 0x%08lX\n", *it);
				result = false;
			}
			CloseHandle( hThr );
		}
	}
	return result;
}

bool CThreadWatch::WakeAll( void )
{
	bool result = true;
	set<DWORD>::iterator it;
	for (it = threadList.begin(); it != threadList.end(); it++)
	{
		HANDLE hThr = OpenThread( THREAD_SUSPEND_RESUME, false, *it );
		if (hThr == NULL)
		{
			DebugLog("에러: 쓰레드 핸들을 열 수 없습니다.  Id: 0x%lX\n", *it);
			result = false;
		}
		else
		{
			if (-1 == ResumeThread( hThr ))
			{
				DebugLog("에러: 쓰레드를 복귀할 수 없습니다.  Id: 0x%08lX\n", *it);
				result = false;
			}
			CloseHandle( hThr );
		}
	}
	return result;
}

void CThreadWatch::SetReductionPercentage( int percent )
{
	reductionPercentage = percent;
}

int CThreadWatch::GetReductionPercentage( void )
{
	return reductionPercentage;
}

void CThreadWatch::SetOptionOnlyMinimized( bool value )
{
	onlyWhileMinimized = value;
}

bool CThreadWatch::GetOptionOnlyMinimized( void )
{
	return onlyWhileMinimized;
}