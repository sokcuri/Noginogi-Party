#pragma once

#include "Main.h"

class CThreadWatch
{
public:
	// Thread list (for CModifyWindow)
	static set<DWORD> GetList( void );
	// CPU mod functions
	static bool SpawnWatcher( void );
	static void SetReductionPercentage( int percent );
	static int  GetReductionPercentage( void );
	static void SetOptionOnlyMinimized( bool onlyMinimized );
	static bool GetOptionOnlyMinimized( void );
	static bool UpdateList( void );
private:
	static DWORD WINAPI WatcherThreadMain( LPVOID lpParam );
	static bool SleepAll( void );
	static bool WakeAll( void );
	};