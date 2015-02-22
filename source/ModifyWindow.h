#pragma once

#include "Main.h"

class CModifyWindow
{
public:
	static bool FindMabiHWnd( void );
	static bool SpawnModifier( void );
	static bool IsMinimized( void );
private:
	static bool ModifyMenu( void );
	static bool UpdateMenu( void );
	static bool UpdateIcon( void );
	static DWORD WINAPI CModifyWindow::ModifierThreadMain( LPVOID lpParam );
	static BOOL EnumThreadWindows_fn(HWND hwnd, LPARAM lparam);
	static LRESULT APIENTRY nogipartyWndFunc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
	static LRESULT CALLBACK HookProc(int nCode, WPARAM wParam, LPARAM lParam);
};