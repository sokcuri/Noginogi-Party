#include "Patcher_ExtraThreads.h"
#include "../Addr.h"
#include "../ModifyWindow.h"
#include "../ThreadWatch.h"

//-----------------------------------------------------------------------------
// Constructor

CPatcher_ExtraThreads::CPatcher_ExtraThreads( void )
{
	patchname = "엑스트라 쓰레드";
}

//-----------------------------------------------------------------------------
// Overriden Patching Functions

bool CPatcher_ExtraThreads::Install( void ) {
	bool result = true;
	result &= CThreadWatch::SpawnWatcher();
	result &= CModifyWindow::SpawnModifier();
	installed = result;
	return result;
}


//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_ExtraThreads::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_ExtraThreads::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_ExtraThreads::ReadINI( void )
{
	return true;
}

bool CPatcher_ExtraThreads::WriteINI( void )
{
	return true;
}
