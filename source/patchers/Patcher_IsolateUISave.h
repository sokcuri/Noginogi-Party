#pragma once

/* IsolateUISave
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_IsolateUISave : public IGenericPatcher {
public:
	CPatcher_IsolateUISave();
	bool Install( void );
	bool Uninstall( void );
	bool Toggle( void );

	bool ReadINI( void );
	bool WriteINI( void );

private:
	// Options
	static char data64ua[256];
	static wchar_t data64uu[256];
	// Hook functions
	static void patchIsolateUISave(void);
	// Variables for hook functions
	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_IsolateUISave> SngPatcher_IsolateUISave;