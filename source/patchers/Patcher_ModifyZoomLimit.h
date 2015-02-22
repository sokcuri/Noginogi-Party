#pragma once

/* Modify Zoom Limit
 * Modify the maximum zoom distance (1~5000).
 * PATCHES: Renderer2.dll
 */

#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ModifyZoomLimit : public IGenericPatcher {
public:
	CPatcher_ModifyZoomLimit();
	bool ReadINI( void );
	bool WriteINI( void );
	bool SetLimit(float value);
	bool SetNear(float value);
	bool SetDefault(float value);
	int GetLimit(void);
	int GetNear(void);
	bool Uninstall(void);
	bool Toggle(void);
	static float zoomNear;
	static float zoomLimit;
	static float zoomLimitDefault;
	static bool PatchEnabled;

private:
};

typedef Singleton<CPatcher_ModifyZoomLimit> SngPatcher_ModifyZoomLimit;