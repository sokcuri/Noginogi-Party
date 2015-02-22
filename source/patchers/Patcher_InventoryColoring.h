#pragma once

/* InventoryColoring
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_InventoryColoring : public IGenericPatcher {
public:
	CPatcher_InventoryColoring();
	bool Uninstall( void );
	bool Toggle( void );

	bool ReadINI( void );
	bool WriteINI( void );
	static bool IsPatchEnabled(void);
	static bool PatchToggle(void);
	static bool PatchEnable(void);
	static bool PatchDisable(void);

	static unsigned long Color1;
	static unsigned long Color2;

	static bool ColorMOD;

	static int strCount;
	
	static struct InvStruct
	{
		wchar_t name[256];
		wchar_t category[256];
		unsigned long color[2];
	};
	static InvStruct InvColor[512];

private:
	// Options
	static bool PatchEnabled;
	// Hook functions
	static void patchInventoryColoring(void);
	static void patchIsEnable(void);
	// Variables for hook functions
	static LPBYTE addrCheckFastStringID;
	static LPBYTE addrTargetReturn;
	static LPBYTE addrItemColoring;
	static LPBYTE addrIsBroken;
	static LPBYTE addrIsExpired;
	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_InventoryColoring> SngPatcher_InventoryColoring;