#include "Addr.h"
#include "FileSystem.h"

static LPBYTE DllAddresses[DllAddress_size];

LPBYTE CAddr::Addr( DllAddress addrNumber )
{
	if ( DllAddresses[addrNumber] != NULL )
		return DllAddresses[addrNumber];
	if ( CacheAddress( addrNumber ))
		return DllAddresses[addrNumber];
	return NULL;
}

bool CAddr::PreCacheAddresses( void )
{
	bool result = true;
	for (int i=0; i<DllAddress_size; i++)
		result &= CacheAddress( (DllAddress)i );

	if (result)
		WriteLog("주소 캐싱을 완료했습니다.\n");
	else
		WriteLog("경고: 일부 주소 캐싱이 실패했습니다.\n");

	return result;
}

bool CAddr::CacheAddress( DllAddress addrNumber )
{
	wchar_t *dllfile;
	char *dllfunction;
	char *fullname;

	switch (addrNumber) {

		// kernel32.dll

		case kernel32_CreateMutexW:
			dllfile = L"kernel32.dll";
			fullname = "CMx";
			dllfunction = "CreateMutexW";
			break;

		case kernel32_CreateRemoteThread:
			dllfile = L"kernel32.dll";
			fullname = "CRT";
			dllfunction = "CreateRemoteThread";
			break;

        // kernelbase.dll

		case kernelbase_CreateRemoteThreadEx:
			dllfile = L"KERNELBASE.dll";
			fullname = "CRTX";
			dllfunction = "CreateRemoteThreadEx";
			break;

		// esl.dll
		case ESL_strcmp:
			dllfile = L"esl.dll";
			fullname = "esl::strcmp(wchar_t *, wchar_t *)";
			dllfunction = "?strcmp@unicode_string_trait@esl@@SAJPB_W0@Z";
			break;
		case CStringTUni_Constr:
			dllfile = L"esl.dll"; 
			fullname = "esl::CStringT::CStringT(void)";
			dllfunction = "??0?$CStringT@_WVunicode_string_trait@esl@@Vunicode_string_implement@2@@esl@@QAE@XZ";
			break;
		case CStringTUni_wchar:
			dllfile = L"esl.dll";
			fullname = "esl::CStringT::CStringT(wchar_t *)";
			dllfunction = "??0?$CStringT@_WVunicode_string_trait@esl@@Vunicode_string_implement@2@@esl@@QAE@PB_W@Z";
			break;
		case CStringTUni_Equals:
			dllfile = L"esl.dll";
			fullname = "esl::CStringT::operator=(wchar_t *)";
			dllfunction = "??4?$CStringT@_WVunicode_string_trait@esl@@Vunicode_string_implement@2@@esl@@QAEAAV01@PB_W@Z";
			break;
		case CStringTUni_GetContents:
			dllfile = L"esl.dll";
			fullname = "esl::CStringT::GetContents";
			dllfunction = "?GetContent@?$CStringT@_WVunicode_string_trait@esl@@Vunicode_string_implement@2@@esl@@QBEPB_WXZ";
			break;
		case CFileSystem_SetLookUpOrder:
			dllfile = L"esl.dll";
			fullname = "esl::CFileSystem::SetLookUpOrder";
			dllfunction = "?SetLookUpOrder@CFileSystem@esl@@QAEXW4EFileLookUpOrder@esl_constant@2@@Z";
			break;
		case ESL_package_file_item:
			dllfile = L"esl.dll";
			fullname = "esl::package_file_item";
			dllfunction = "??1package_file_item@esl@@QAE@XZ";
			break;
		case CFormatter_Release:
			dllfile = L"esl.dll";
			fullname = "esl::CFormatter::Release";
			dllfunction = "??1CFormatter@esl@@QAE@XZ";
			break;
		case CFormatter_Insert_ulong:
			dllfile = L"esl.dll";
			fullname = "esl::CFormatter::operator<<(ulong)";
			dllfunction = "??6CFormatter@esl@@QAEAAV01@K@Z";
			break;
		case CFormatter_Insert_ushort:
			dllfile = L"esl.dll";
			fullname = "esl::CFormatter::operator<<(ushort)";
			dllfunction = "??6CFormatter@esl@@QAEAAV01@G@Z";
			break;
		case CFormatter_Insert_float:
			dllfile = L"esl.dll";
			fullname = "esl::CFormatter::operator<<(float)";
			dllfunction = "??6CFormatter@esl@@QAEAAV01@M@Z";
			break;
		case CFormatter_Insert_pwchar:
			dllfile = L"esl.dll";
			fullname = "esl::CFormatter::operator<<(wchar_t const *)";
			dllfunction = "??6CFormatter@esl@@QAEAAV01@PB_W@Z";
			break;
		case CFormatter_GetString:
			dllfile = L"esl.dll";
			fullname = "esl::CFormatter::GetString(wchar_t const *)";
			dllfunction = "??BCFormatter@esl@@QBE?AV?$CStringT@_WVunicode_string_trait@esl@@Vunicode_string_implement@2@@1@XZ";
			break;
		case ESL_ETC_TIME:
			dllfile = L"esl.dll";
			fullname = "esl::etc::__time";
			dllfunction = "?__time@etc@esl@@YAKXZ";
			break;

		// pleione.dll

		case CGameOptionMgr_ReadFSAA:
			dllfile = L"pleione.dll";
			fullname = "pleione::CGameOptionMgr::ReadFSAA";
			dllfunction = "?ReadFSAA@CGameOptionMgr@pleione@@QAE?AW4EFSAA@pleione_constant@2@XZ";
			break;
		case CGameOptionMgr_ReadFSAAQuality:
			dllfile = L"pleione.dll";
			fullname = "pleione::CGameOptionMgr::ReadFSAAQuality";
			dllfunction = "?ReadFSAAQuality@CGameOptionMgr@pleione@@QAEKXZ";
			break;
		case CPleione_CleanUp:
			dllfile = L"pleione.dll";
			fullname = "pleione::CPleione::CleanUp";
			dllfunction = "?CleanUp@CPleione@pleione@@QAE_NXZ";
			break;

		// renderer2.dll

		case CAtmosphere_SetSkyTime:
			dllfile = L"renderer2.dll";
			fullname = "pleione::CAtmosphere::SetSkyTime";
			dllfunction = "?SetSkyTime@CAtmosphere@pleione@@QAEXM@Z";
			break;
		case CCameraControl_SetCamera:
			dllfile = L"renderer2.dll";
			fullname = "pleione::CCameraControl::SetCamera";
			dllfunction = "?SetCamera@CCameraControl@pleione@@QAEXPAVCScene@2@PAVITerrain@2@KFF@Z";
			break;
		case CDefaultCompiler_Compile:
			dllfile = L"Renderer2.dll";
			fullname = "pleione::CDefaultCompiler::Compile";
			dllfunction = "?Compile@CDefaultCompiler@pleione@@UAEPAVCCompiledText@2@ABV?$CStringT@_WVunicode_string_trait@esl@@Vunicode_string_implement@2@@esl@@ABUtext_option@2@@Z";
			break;
		case CDefaultTagCompiler_Compile:
			dllfile = L"Renderer2.dll";
			fullname = "pleione::CDefaultTagCompiler::Compile";
			dllfunction = "?Compile@CDefaultTagCompiler@pleione@@UAEPAVCCompiledText@2@ABV?$CStringT@_WVunicode_string_trait@esl@@Vunicode_string_implement@2@@esl@@ABUtext_option@2@@Z";
			break;
		case CHTMLCompiler_Compile:
			dllfile = L"Renderer2.dll";
			fullname = "pleione::CHTMLCompiler::Compile";
			dllfunction = "?Compile@CHTMLCompiler@pleione@@UAEPAVCCompiledText@2@ABV?$CStringT@_WVunicode_string_trait@esl@@Vunicode_string_implement@2@@esl@@ABUtext_option@2@@Z";
			break;
		case CRendererContext_RenderGlowOverlay:
			dllfile = L"Renderer2.dll";
			fullname = "pleione::CRendererContext::RenderGlowOverlay";
			dllfunction = "?_RenderGlowOverlay@CRendererContext@pleione@@AAEXXZ";
			break;

		// mint.dll
		case CObject_GetObjectId:
			dllfile = L"Mint.dll";
			fullname = "mint::CObject::GetObjectId";
			dllfunction = "?GetObjectId@CObject@mint@@QBE_KXZ";
			break;
		case CMessage_ReadU8:
			dllfile = L"Mint.dll";
			fullname = "mint::CMessage::ReadU8";
			dllfunction = "?ReadU8@CMessage@mint@@QAEEXZ";
			break;

		// standard.dll

		case IParameter_GetLuck:
			dllfile = L"standard.dll";
			fullname = "core::IParameter::GetLuck";
			dllfunction = "?GetLuck@IParameter@core@@QAEMXZ";
			break;
		case CGateMgr_GetGateLocalName:
			dllfile = L"standard.dll";
			fullname = "core::CGateMgr::GetGateLocalName";
			dllfunction = "?GetGateLocalName@CGateMgr@core@@QBE?BV?$CStringT@_WVunicode_string_trait@esl@@Vunicode_string_implement@2@@esl@@ABV34@@Z";
			break;
		case IParameterBase2_GetLife:
			dllfile = L"standard.dll";
			fullname = "core::IParameterBase2::GetLife";
			dllfunction = "?GetLife@IParameterBase2@core@@QAEMXZ";
			break;
		case IParameterBase2_GetLifeMax:
			dllfile = L"standard.dll";
			fullname = "core::IParameterBase2::GetLifeMax";
			dllfunction = "?GetLifeMax@IParameterBase2@core@@QAEMXZ";
			break;
		case SItemEgoInfo_IsEiry:
			dllfile = L"standard.dll";
			fullname = "core::SItemEgoInfo::IsEiry";
			dllfunction = "?IsEiry@SItemEgoInfo@@QBE_NXZ";
			break;
		case CDungeonRegion_SetFog:
			dllfile = L"standard.dll";
			fullname = "core::CDungeonRegion::SetFog";
			dllfunction = "?SetFog@CDungeonRegion@core@@QAEX_N@Z";
			break;
		case ICharacter_GetTargetCombatPower:
			dllfile = L"standard.dll";
			fullname = "core::ICharacter::GetTargetCombatPower";
			dllfunction = "?GetTargetCombatPower@ICharacter@core@@QAE?AW4ECombatPower@@PBV12@@Z";
			break;
		case IParameterBase2_GetCombatPower:
			dllfile = L"standard.dll";
			fullname = "core::IParameterBase2::GetCombatPower";
			dllfunction = "?GetCombatPower@IParameterBase2@core@@QBEMXZ";
			break;
		case IItem_GetInterfaceDurability:
			dllfile = L"standard.dll";
			fullname = "core::IItem::GetInterfaceDurability";
			dllfunction = "?GetInterfaceDurability@IItem@core@@QBEKXZ";
			break;
		case IItem_GetInterfaceDurabilityMax:
			dllfile = L"standard.dll";
			fullname = "core::IItem::GetInterfaceDurabilityMax";
			dllfunction = "?GetInterfaceDurabilityMax@IItem@core@@QBEKXZ";
			break;
		case IItem_GetColor:
			dllfile = L"standard.dll";
			fullname = "core::IItem::GetColor";
			dllfunction = "?GetColor@IItem@core@@QBEKK@Z";
			break;
		case ICharacter_IsElf:
			dllfile = L"standard.dll";
			fullname = "core::ICharacter::IsElf";
			dllfunction = "?IsElf@ICharacter@core@@QBE_NXZ";
			break;
		case ICharacter_IsGiant:
			dllfile = L"standard.dll";
			fullname = "core::ICharacter::IsGiant";
			dllfunction = "?IsGiant@ICharacter@core@@QBE_NXZ";
			break;
		case ICharacter_IsPet:
			dllfile = L"standard.dll";
			fullname = "core::ICharacter::IsPet";
			dllfunction = "?IsPet@ICharacter@core@@QBE_NXZ";
			break;
		case ICharacter_IsNPC:
			dllfile = L"standard.dll";
			fullname = "core::ICharacter::IsNPC";
			dllfunction = "?IsNPC@ICharacter@core@@QBE_NXZ";
			break;
		case ICharacter_IsNamedNPC:
			dllfile = L"standard.dll";
			fullname = "core::ICharacter::IsNamedNPC";
			dllfunction = "?IsNamedNPC@ICharacter@core@@QBE_NXZ";
			break;
		case ICharacter_IsGoodNPC:
			dllfile = L"standard.dll";
			fullname = "core::ICharacter::IsGoodNPC";
			dllfunction = "?IsGoodNPC@ICharacter@core@@QBE_NXZ";
			break;
		case IParameterBase2_GetExploLevel:
			dllfile = L"standard.dll";
			fullname = "core::IParameterBase2::GetExploLevel";
			dllfunction = "?GetExploLevel@IParameterBase2@core@@QBEGXZ";
			break;
		case IParameter_GetExploExpPercent:
			dllfile = L"standard.dll";
			fullname = "core::IParameter::GetExploExpPercent";
			dllfunction = "?GetExploExpPercent@IParameter@core@@QBEMXZ";
			break;
		case CUserConsoleMgr_ParseCommand:
			dllfile = L"standard.dll";
			fullname = "core::CUserConsoleMgr::ParseCommand";
			dllfunction = "?ParseCommand@CUserConsoleMgr@core@@QBE_NABV?$CStringT@_WVunicode_string_trait@esl@@Vunicode_string_implement@2@@esl@@AAVCUserConsole@2@@Z";
			break;
		case CLocalizer_Instance:
			dllfile = L"standard.dll";
			fullname = "core::CLocalizer::Instance";
			dllfunction = "?Instance@CLocalizer@core@@SAAAV12@XZ";
			break;
		case CLocalizer_GetLocalText:
			dllfile = L"standard.dll";
			fullname = "core::CLocalizer_GetLocalText";
			dllfunction = "?GetLocalText@CLocalizer@core@@QBE?AVCFormatter@esl@@ABV?$CStringT@_WVunicode_string_trait@esl@@Vunicode_string_implement@2@@4@@Z";
			break;
		case stdapi_ShowChattingMessage:
			dllfile = L"standard.dll";
			fullname = "core::stdapi_ShowChattingMessage";
			dllfunction = "?stdapi_ShowChattingMessage@core@@YAX_KABV?$CStringT@_WVunicode_string_trait@esl@@Vunicode_string_implement@2@@esl@@1KKE@Z";
			break;
		case stdapi_ShowCaption:
			dllfile = L"standard.dll";
			fullname = "core::stdapi_ShowCaption";
			dllfunction = "?stdapi_ShowCaption@core@@YAX_KABV?$CStringT@_WVunicode_string_trait@esl@@Vunicode_string_implement@2@@esl@@W4EMessageCaptionType@@KKK0@Z";
			break;
		case stdapi_GetGlobalTime:
			dllfile = L"standard.dll";
			fullname = "core::stdapi_GetGlobalTime";
			dllfunction = "?stdapi_GetGlobalTime@core@@YA_KXZ";
			break;
		case stdapi_GlobalTimeToGameTime:
			dllfile = L"standard.dll";
			fullname = "core::stdapi_GlobalTimeToGameTime";
			dllfunction = "?stdapi_GlobalTimeToGameTime@core@@YAX_KAAK11@Z";
			break;
		case IServiceMgr_IsUsingNaosSupport:
			dllfile = L"standard.dll";
			fullname = "core::IServiceMgr::IsUsingNaosSupport";
			dllfunction = "?IsUsingNaosSupport@IServiceMgr@core@@QBE_NXZ";
			break;
		case lProp_CheckFastStringID:
			dllfile = L"standard.dll";
			fullname = "core::IProp_CheckFastStringID";
			dllfunction = "?CheckFastStringID@IProp@core@@QBE_NPB_W@Z";
			break;
		case IServiceMgr_IsUsableContents:
			dllfile = L"standard.dll";
			fullname = "core::IServiceMgr::IsUsableContents";
			dllfunction = "?IsUsableContents@IServiceMgr@core@@QBE_NW4EServiceContents@2@@Z";
			break;
		case ITransformMgr_IsTransformed:
			dllfile = L"standard.dll";
			fullname = "core::ITransformMgr::IsTransformed";
			dllfunction = "?IsTransformed@ITransformMgr@core@@QBE_NXZ";
			break;
		case ICharacter_GetFullSuitID:
			dllfile = L"standard.dll";
			fullname = "core::ICharacter::GetFullSuitID";
			dllfunction = "?GetFullSuitID@ICharacter@core@@QAEKXZ";
			break;
		case IItem_IsBroken:
			dllfile = L"standard.dll";
			fullname = "core::IItem::IsBroken";
			dllfunction = "?IsBroken@IItem@core@@QBE_NXZ";
			break;
		case IItem_CheckFastStringID:
			dllfile = L"standard.dll";
			fullname = "core::IItem::CheckFastStringID";
			dllfunction = "?CheckFastStringID@IItem@core@@QBE_NPB_W@Z";
			break;
		case IItem_IsExpired:
			dllfile = L"standard.dll";
			fullname = "core::IItem::IsExpired";
			dllfunction = "?IsExpired@IItem@core@@QAE_N_K@Z";
			break;
		case IRegion_IsArenaField:
			dllfile = L"standard.dll";
			fullname = "core::IRegion::IsArenaField";
			dllfunction = "?IsArenaField@IRegion@core@@QBE?B_NXZ";
			break;
		case IPVPMgr_CanAttackTarget:
			dllfile = L"standard.dll";
			fullname = "core::IPVPMgr::CanAttackTarget";
			dllfunction = "?CanAttackTarget@IPVPMgr@core@@QBE_NPBVICharacter@2@@Z";
			break;
		default:
			return false;
	}

	HMODULE dllmodule = GetModuleHandle( dllfile );
	LPBYTE address = (LPBYTE)GetProcAddress( dllmodule, dllfunction );
	if(address==NULL) {
		DebugLog("에러: %ls 파일에서 %s 함수를 찾을 수 없습니다..\n", dllfile, fullname);
		DllAddresses[addrNumber] = NULL;
		return false;
	}
	DebugLog("성공: %ls 파일에서 %s 함수를 찾았습니다. (0x%08lX)\n", dllfile, fullname, address);
	DllAddresses[addrNumber] = address;
	return true;
}