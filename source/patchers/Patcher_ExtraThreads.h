#pragma once

/* Extra Threads
 * Enables threads to control CPU usage and modify the Mabinogi system menu.
 * PATCHES: nothing
 */

#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ExtraThreads : public IGenericPatcher {
public:
	CPatcher_ExtraThreads();

	bool Install( void );
	bool Uninstall( void );
	bool Toggle( void );

	bool ReadINI( void );
	bool WriteINI( void );

private:
};

typedef Singleton<CPatcher_ExtraThreads> SngPatcher_ExtraThreads;