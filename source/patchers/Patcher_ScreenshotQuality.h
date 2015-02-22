#pragma once

/* Screenshot Quality
 * Set the JPEG compression levels for screenshots.
 * PATCHES: nothing
 */

#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ScreenshotQuality : public IGenericPatcher {
public:
	CPatcher_ScreenshotQuality();

	bool Install( void );
	bool Uninstall( void );
	bool Toggle( void );

	bool ReadINI( void );
	bool WriteINI( void );
	static LPBYTE funcPointer;
	static void ijlWrite(void);
private:
};

typedef Singleton<CPatcher_ScreenshotQuality> SngPatcher_ScreenshotQuality;