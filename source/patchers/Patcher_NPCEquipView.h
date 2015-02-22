#pragma once

/* NPC 장비보기
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_NPCEquipView : public IGenericPatcher {
public:
	CPatcher_NPCEquipView();
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
	static void patchNPCEquipView(void);
	// Variables for hook functions
	static LPBYTE addrIsNPC;
	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_NPCEquipView> SngPatcher_NPCEquipView;