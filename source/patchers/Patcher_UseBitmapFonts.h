#pragma once

/* Use Bitmap Fonts
 * Use bitmap fonts instead of vector fonts to prevent window lag.
 * PATCHES: Renderer2.dll
 */

#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_UseBitmapFonts : public IGenericPatcher {
public:
	CPatcher_UseBitmapFonts();
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
	static void patchUseBitmapFonts1(void);
	static void patchUseBitmapFonts2(void);
	static void patchUseBitmapFonts3(void);
	// Variables for hook functions
	static LPBYTE addrTargetReturn1;
	static LPBYTE addrTargetReturn2;
	static LPBYTE addrTargetReturn3;
	LPBYTE funcPointer1;
	LPBYTE funcPointer2;
	LPBYTE funcPointer3;
};

typedef Singleton<CPatcher_UseBitmapFonts> SngPatcher_UseBitmapFonts;