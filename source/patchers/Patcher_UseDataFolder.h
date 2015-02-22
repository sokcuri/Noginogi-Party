#pragma once

/* Use Data Folder
 * Load data from Data folder before loading from pack files.
 * PATCHES: ESL.dll
 */

#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_UseDataFolder : public IGenericPatcher {
public:
	CPatcher_UseDataFolder();
	bool Uninstall( void );
	bool Toggle( void );
	bool Install( void );

	bool ReadINI( void );
	bool WriteINI( void );
private:
};

typedef Singleton<CPatcher_UseDataFolder> SngPatcher_UseDataFolder;