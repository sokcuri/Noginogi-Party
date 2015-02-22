#pragma once

/* CRT Patch
 * Disables the HackShield local memory hash thread.
 * PATCHES: kernel32.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_HackShield : public IGenericPatcher {
public:
	CPatcher_HackShield();
	bool Install( void );
	bool Toggle( void );

	bool ReadINI( void );
	bool WriteINI( void );
private:
	// Hook functions
	static void patchCRT(void);
	static DWORD WINAPI dummyFunction( LPVOID lpParam );

	// Variables for hook functions
	static BYTE pushBackup[4];		// Copy of the argument to the PUSH xxxxxxxx instruction of CreateRemoteThread
	static LPBYTE addrCRT;			// Address of CreateRemoteThread
	static LPBYTE addrReturn;		// Address to return to while hook is still in effect
	static LPBYTE targetEntry;		// Location of the original entry point of target thread
	static LPBYTE moduleEntry;
	static LPBYTE hDllInst;
	static int HSOffset;
	static int LoopCount;
	static int IsHSThreadLog;
	static int ignoredHSThreads;	// How many threads before the target share our target's entry point
};

typedef Singleton<CPatcher_HackShield> SngPatcher_HackShield;