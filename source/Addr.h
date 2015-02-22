#pragma once

#include "Main.h"

enum DllAddress {
	kernel32_CreateMutexW,
	kernel32_CreateRemoteThread,
    kernelbase_CreateRemoteThreadEx,
	ESL_strcmp,
	CStringTUni_Constr,
	CStringTUni_wchar,
	CStringTUni_Equals,
	CStringTUni_GetContents,
	CFileSystem_SetLookUpOrder,
	ESL_package_file_item,
	CFormatter_Release,
	CFormatter_Insert_ulong,
	CFormatter_Insert_ushort,
	CFormatter_Insert_float,
	CFormatter_Insert_pwchar,
	CFormatter_GetString,
	ESL_ETC_TIME,
	CGameOptionMgr_ReadFSAA,
	CGameOptionMgr_ReadFSAAQuality,
	CPleione_CleanUp,
	CAtmosphere_SetSkyTime,
	CCameraControl_SetCamera,
	CObject_GetObjectId,
	CMessage_ReadU8,
	IParameter_GetLuck,
	CGateMgr_GetGateLocalName,
	IParameterBase2_GetLife,
	IParameterBase2_GetLifeMax,
	SItemEgoInfo_IsEiry,
	CDungeonRegion_SetFog,
	IParameterBase2_GetCombatPower,
	ICharacter_GetTargetCombatPower,
	IItem_GetInterfaceDurability,
	IItem_GetInterfaceDurabilityMax,
	IItem_GetColor,
	ICharacter_IsElf,
	ICharacter_IsGiant,
	ICharacter_IsPet,
	ICharacter_IsNPC,
	ICharacter_IsNamedNPC,
	ICharacter_IsGoodNPC,
	CDefaultCompiler_Compile,
	CDefaultTagCompiler_Compile,
	CHTMLCompiler_Compile,
	CRendererContext_RenderGlowOverlay,
	IParameterBase2_GetExploLevel,
	IParameter_GetExploExpPercent,
	CUserConsoleMgr_ParseCommand,
	CLocalizer_Instance,
	CLocalizer_GetLocalText,
	stdapi_ShowChattingMessage,
	stdapi_ShowCaption,
	stdapi_GetGlobalTime,
	stdapi_GlobalTimeToGameTime,
	IServiceMgr_IsUsingNaosSupport,
	lProp_CheckFastStringID,
	IServiceMgr_IsUsableContents,
	ITransformMgr_IsTransformed,
	ICharacter_GetFullSuitID,
	IItem_IsBroken,
	IItem_CheckFastStringID,
	IItem_IsExpired,
	IRegion_IsArenaField,
	IPVPMgr_CanAttackTarget,
	DllAddress_size // equal to the number of enum entries previously
};

class CAddr
{
public:
	static LPBYTE Addr( DllAddress addrNumber );
	static bool PreCacheAddresses( void );
private:
	static bool CacheAddress( DllAddress addrNumber );
};