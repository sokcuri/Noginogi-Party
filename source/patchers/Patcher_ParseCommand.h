#pragma once

/* User Parsing Command
 * PATCHES: Pleione.dll
 */

#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ParseCommand : public IGenericPatcher {
public:
	CPatcher_ParseCommand();
	bool ReadINI( void );
	bool WriteINI( void );
	int *pt;

private:
	// Hook functions
	static void patchParseCommand(void);
	// Variables for hook functions
	static LPBYTE addrParseCommand;
	static LPBYTE addrTargetReturn;
	static LPBYTE addrCString_wchar;
	static LPBYTE addrCLocalizeInstance;
	static LPBYTE addrCLocalizeGetLocalText;
	static LPBYTE addrCFormatterGetString;
	static LPBYTE addrCFormatterRelease;
	static LPBYTE addrStdapi_ShowChattingMessage;
	static LPBYTE addrESL_package_file_item;

};

typedef Singleton<CPatcher_ParseCommand> SngPatcher_ParseCommand;