#pragma once

/* Move To Same Channel
 * Enable moving to the same channel you are currently on
 * PATCHES: Pleione.dll
 */

#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_MoveToSameChannel : public IGenericPatcher {
public:
	CPatcher_MoveToSameChannel();
	bool Uninstall( void );
	bool Toggle( void );

	bool ReadINI( void );
	bool WriteINI( void );
	static bool IsPatchEnabled(void);
	static bool PatchToggle(void);
	static bool PatchEnable(void);
	static bool PatchDisable(void);
private:
	// Options
	static bool PatchEnabled;
	// Hook functions
	static void patchMoveToSameChannel(void);
	// Variables for hook functions
	static LPBYTE addrTargetReturn;
	static LPBYTE addrGetContents;
	static LPBYTE addrstrcmp;
};

typedef Singleton<CPatcher_MoveToSameChannel> SngPatcher_MoveToSameChannel;