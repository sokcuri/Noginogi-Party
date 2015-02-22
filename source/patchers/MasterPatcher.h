#pragma once

#include "../Main.h"
#include "Patcher_DisableNighttime.h"
#include "Patcher_EnableNameColoring.h"
#include "Patcher_EnableSelfRightClick.h"
#include "Patcher_EnterRemoteShop.h"
#include "Patcher_ExtraThreads.h"
#include "Patcher_ModifyZoomLimit.h"
#include "Patcher_MoveToSameChannel.h"
#include "Patcher_MoveWhileTalking.h"
#include "Patcher_ScreenshotQuality.h"
#include "Patcher_ShowCombatPower.h"
#include "Patcher_ShowItemPrice.h"
#include "Patcher_ExtendDurability.h"
#include "Patcher_ShowTrueFoodQuality.h"
#include "Patcher_TalkToUnequippedEgo.h"
#include "Patcher_TargetProps.h"
#include "Patcher_UseBitmapFonts.h"
#include "Patcher_UseDataFolder.h"
#include "Patcher_ParseCommand.h"
#include "Patcher_UnlimitPartyTime.h"
#include "Patcher_ExpressBoard.h"
#include "Patcher_MinuteClock.h"
#include "Patcher_TimeAlerm.h"
#include "Patcher_AnyPutSkillFx.h"
#include "Patcher_Party2Adver.h"
#include "Patcher_SimpleFrameIgnore.h"
//#include "Patcher_TransformIgnore.h"
#include "Patcher_FlyZeroHigh.h"
#include "Patcher_MimicNaming.h"
#include "Patcher_StatsFloating.h"
#include "Patcher_VisionInAllName.h"
#include "Patcher_NoReflexLight.h"
#include "Patcher_AfterADKill.h"
//#include "Patcher_AlwaysBagView.h"
#include "Patcher_BankTabEnable.h"
#include "Patcher_NPCEquipView.h"
#include "Patcher_IsolateUISave.h"
#include "Patcher_CutSceneImmediateSkip.h"
#include "Patcher_ItemDropPreservation.h"
#include "Patcher_InventoryColoring.h"
#include "Patcher_DeadlyHPShow.h"
#include "Patcher_StatsFloating.h"
#include "Patcher_HideVisible.h"
#include "Patcher_ShowItemPrice.h"
//#include "Patcher_MultipleInstance.h"
#include "Patcher_FarSignRead.h"
#include "Patcher_InframeWinPSV.h"
#include "Patcher_SpaceUnlock.h"
#include "Patcher_HackShield.h"

class CMasterPatcher {
public:
	static bool PatchInstall( void );
	static bool PatchFromINI( void );
	static bool SaveToINI( void );
	static bool ReloadINI( void );
	static bool ExecuteINI( void );
private:
	static vector<IGenericPatcher *> PatchList;
	static bool GetPatchList( void );
};