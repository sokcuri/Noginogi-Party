#include "ModifyWindow.h"
#include "FileSystem.h"
#include "DBGHook.h"
#include "ThreadWatch.h"
#include "patchers/MasterPatcher.h"

//-------------------------------------------------------------------
// Local variables

static HWND hDlg = NULL;
static HWND mabiHWnd = NULL;
static WNDPROC wpPrevWndProc = NULL;
static HICON hIcon = NULL;
static HMENU nogipartySubMenu = NULL;
static bool isMinimized = false;

//-------------------------------------------------------------------
// Functions

bool CModifyWindow::SpawnModifier( void )
{
	SECURITY_ATTRIBUTES ThreadAttributes;
	ThreadAttributes.bInheritHandle = false;
	ThreadAttributes.lpSecurityDescriptor = NULL;
	ThreadAttributes.nLength = sizeof( SECURITY_ATTRIBUTES );
	DebugLog("로그: 감시 쓰레드 생성.\n");

	HANDLE hThr = CreateThread( &ThreadAttributes, 0, ModifierThreadMain, NULL, 0, NULL );
	if (hThr == NULL) {
		DebugLog("에러: 감시 쓰레드의 생성을 실패했습니다.\n");
		return false;
	}

	return true;
}

DWORD WINAPI CModifyWindow::ModifierThreadMain( LPVOID lpParam )
{
	wchar_t alert_title[] = L"노기노기 파티";
	wchar_t alert_body[] = L"이 프로그램은 필드테스트용 프로그램입니다.\r\n다음 사항에 동의해 주셔야 프로그램 사용이 가능합니다\r\n\r\n1. 파일의 유출 또는 재배포 금지\r\n2. 모든 리스크에 대한 책임은 사용자에게 있음\r\n3. 필드 테스터는 리포팅의 의무가 있음\r\n(이건 가랑넷에서 해주세요)\r\n4. 사용 설명서상의 동의 (nogiparty.txt 참고)\r\n\r\n동의하시면 예를 눌러주세요.";
	//time_t start, stop;
	//start = time(NULL);
	
	// splash
	hDlg = CreateDialog(g_hInstance, MAKEINTRESOURCE(101), mabiHWnd, NULL);
	//ShowWindow(mabiHWnd, true);

	int count = 0;

	// 마비 윈도우 핸들 찾기
	while(!FindMabiHWnd()) {
		Sleep(2000);
		count++;
		if (count > 1) DestroyWindow(hDlg);
	}
	DestroyWindow(hDlg);

	DebugLog("마비 윈도우를 찾았습니다.  HWND=0x%08lX\n", mabiHWnd);
	ModifyMenu();

	//SetWindowText(mabiHWnd, L"마비노기 in 노기노기 파티");

	return 0;
}

bool CModifyWindow::FindMabiHWnd()
{
	HWND hwnd = NULL;

	set<DWORD> threadList = CThreadWatch::GetList();
	set<DWORD>::iterator it;
	for (it = threadList.begin(); it != threadList.end(); it++ )
	{
		if (!EnumThreadWindows( *it, (WNDENUMPROC)EnumThreadWindows_fn, (LPARAM)&hwnd ))
			break;
	}
	if (hwnd == NULL)
		return false;

	mabiHWnd = hwnd;
	return true;
}

BOOL CModifyWindow::EnumThreadWindows_fn(HWND hwnd, LPARAM lparam)
{
	wchar_t buf[255];
	GetClassName(hwnd, (LPWSTR)&buf, 255);
	if (wcscmp(buf, L"Mabinogi") == 0) {
		*((HWND *)lparam) = hwnd;
		return false; // Do not continue enumeration
	}
	return true; // Continue enumeration
}

bool CModifyWindow::ModifyMenu()
{
	HMENU systemMenu = GetSystemMenu( mabiHWnd, false );
	HMENU nogipartyMenu = LoadMenu( g_hInstance, MAKEINTRESOURCE(IDR_NOGIPARTY_MENU) );
	if (nogipartyMenu == NULL) {
		DebugLog("에러: 메뉴 로드에 실패했습니다.\n");
		return false;
	}

	nogipartySubMenu = GetSubMenu( nogipartyMenu, 0 );
	if (nogipartySubMenu == NULL) {
		DebugLog("에러: 서브메뉴 로드에 실패했습니다.\n");
		return false;
	}

	BOOL result = true;
	result &= InsertMenu( systemMenu, -1, MF_SEPARATOR, 0, 0 );
	result &= InsertMenu( systemMenu, -1, MF_BYPOSITION | MF_POPUP, (UINT_PTR)nogipartySubMenu, L"진수의 노기노기 파티" );
	if (!result) {
		DebugLog("에러: 서브메뉴 삽입에 실패했습니다.\n");
		return false;
	}

	wpPrevWndProc = (WNDPROC)SetWindowLong( mabiHWnd, GWLP_WNDPROC, (LONG)nogipartyWndFunc );
	if (wpPrevWndProc == 0) {
		DebugLog("에러: 시스템 윈도우 기능을 덮어씌우는데 실패했습니다.\n");
		return false;
	}

	DebugLog("메뉴 변경에 성공했습니다.\n");
	return true;
}

LRESULT APIENTRY CModifyWindow::nogipartyWndFunc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	switch (uMsg)
		
	{
	case WM_ACTIVATE:
		if (HIWORD(wParam) != 0)
			isMinimized = true;
		else
			isMinimized = false;
		//UpdateIcon();
		break;
	case WM_SYSCOMMAND:
		// Menu item selected
		switch (wParam)
		{
		case ID_EXECUTESETTINGS:
			CMasterPatcher::ExecuteINI();
			break;
		case ID_RELOADSETTINGS:
			CMasterPatcher::ReloadINI();
		break;
		case ID_CPUMENU_WHILEMINIMIZED:
			if (CThreadWatch::GetOptionOnlyMinimized())
				CThreadWatch::SetOptionOnlyMinimized(false);
			else
				CThreadWatch::SetOptionOnlyMinimized(true);
			UpdateIcon();
			break;
		case ID_CPUMENU_90:
			CThreadWatch::SetReductionPercentage( 90 );
			UpdateIcon();
			break;
		case ID_CPUMENU_80:
			CThreadWatch::SetReductionPercentage( 80 );
			UpdateIcon();
			break;
		case ID_CPUMENU_70:
			CThreadWatch::SetReductionPercentage( 70 );
			UpdateIcon();
			break;
		case ID_CPUMENU_60:
			CThreadWatch::SetReductionPercentage( 60 );
			UpdateIcon();
			break;
		case ID_CPUMENU_50:
			CThreadWatch::SetReductionPercentage( 50 );
			UpdateIcon();
			break;
		case ID_CPUMENU_40:
			CThreadWatch::SetReductionPercentage( 40 );
			UpdateIcon();
			break;
		case ID_CPUMENU_30:
			CThreadWatch::SetReductionPercentage( 30 );
			UpdateIcon();
			break;
		case ID_CPUMENU_20:
			CThreadWatch::SetReductionPercentage( 20 );
			UpdateIcon();
			break;
		case ID_CPUMENU_10:
			CThreadWatch::SetReductionPercentage( 10 );
			UpdateIcon();
			break;
		case ID_CPUMENU_OFF:
			CThreadWatch::SetReductionPercentage( 0 );
			UpdateIcon();
			break;
		case ID_TOGGLE_DISABLENIGHTTIME:
			SngPatcher_DisableNighttime::Instance()->NightPatchToggle();
			break;
		case ID_TOGGLE_DISABLESUNTIME:
			SngPatcher_DisableNighttime::Instance()->SunPatchToggle();
			break;
		case ID_TOGGLE_ENABLENAMECOLORING:
			SngPatcher_EnableNameColoring::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_ENABLESELFRIGHTCLICK:
			SngPatcher_EnableSelfRightClick::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_ENTERREMOTESHOP:
			SngPatcher_EnterRemoteShop::Instance()->PatchToggle();
			break;
		case ID_ZOOMLIMIT_5000:
			SngPatcher_ModifyZoomLimit::Instance()->SetLimit( 5000 );
			break;
		case ID_ZOOMLIMIT_3500:
			SngPatcher_ModifyZoomLimit::Instance()->SetLimit( 3500 );
			break;
		case ID_ZOOMLIMIT_1500:
			SngPatcher_ModifyZoomLimit::Instance()->SetLimit( 1500 );
			break;
		case ID_ZOOMNEAR_500:
			SngPatcher_ModifyZoomLimit::Instance()->SetNear( 500 );
			break;
		case ID_ZOOMNEAR_400:
			SngPatcher_ModifyZoomLimit::Instance()->SetNear( 400 );
			break;
		case ID_ZOOMNEAR_300:
			SngPatcher_ModifyZoomLimit::Instance()->SetNear( 300 );
			break;
		case ID_TOGGLE_MOVETOSAMECHANNEL:
			SngPatcher_MoveToSameChannel::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_MOVEWHILETALKING:
			SngPatcher_MoveWhileTalking::Instance()->PatchToggle();
			break;
		case ID_SSQUALITY_100:
			SngDBGHook::Instance()->SetSSQuality(100);
			break;
		case ID_SSQUALITY_90:
			SngDBGHook::Instance()->SetSSQuality(90);
			break;
		case ID_SSQUALITY_75:
			SngDBGHook::Instance()->SetSSQuality(75);
			break;
		case ID_SSQUALITY_50:
			SngDBGHook::Instance()->SetSSQuality(50);
			break;
		case ID_TOGGLE_SHOWCOMBATPOWER:
			SngPatcher_ShowCombatPower::Instance()->PatchToggle();
			break;
			/*
		case ID_TOGGLE_SHOWITEMPRICE:
			SngPatcher_ShowItemPrice::Instance()->Toggle();
			break;
		case ID_TOGGLE_EXTENDDURABILITY:
			SngPatcher_ExtendDurability::Instance()->Toggle();
			break;
		case ID_TOGGLE_SHOWITEMCOLOR:
			SngPatcher_ExtendDurability::Instance()->ToggleColor();
			break;
		case ID_TOGGLE_SHOWTRUEFOODQUALITY:
			SngPatcher_ShowTrueFoodQuality::Instance()->Toggle();
			break;
		case ID_TOGGLE_PARSECOMMAND:
			SngPatcher_ParseCommand::Instance()->Toggle();
			break;
			*/
		case ID_TOGGLE_TALKTOUNEQUIPPEDEGO:
			SngPatcher_TalkToUnequippedEgo::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_TARGETPROPS:
			SngPatcher_TargetProps::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_USEBITMAPFONTS:
			SngPatcher_UseBitmapFonts::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_UNLIMITPARTYTIME:
			SngPatcher_UnlimitPartytime::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_EXPRESSBOARD:
			SngPatcher_ExpressBoard::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_MINUTECLOCK:
			SngPatcher_MinuteClock::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_TIMEALERM:
			SngPatcher_TimeAlerm::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_ANYPUTSKILLFX:
			SngPatcher_AnyPutSkillFx::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_PARTY2ADVER:
			SngPatcher_Party2Adver::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_SIMPLEFRAMEIGNORE:
			SngPatcher_SimpleFrameIgnore::Instance()->PatchToggle();
			break;
//		case ID_TOGGLE_TRANSFORMIGNORE:
//			SngPatcher_TransformIgnore::Instance()->PatchToggle();
//			break;
		case ID_TOGGLE_FLYZEROHIGH:
			SngPatcher_FlyZeroHigh::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_MIMICNAMING:
			SngPatcher_MimicNaming::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_VISIONINALLNAME:
			SngPatcher_VisionInAllName::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_NOREFLEXLIGHT:
			SngPatcher_NoReflexLight::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_EXTENDDURABILITY:
			SngPatcher_ExtendDurability::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_SHOWITEMCOLOR:
			SngPatcher_ExtendDurability::Instance()->ToggleColor();
			break;
//		case ID_TOGGLE_ALWAYSBAGVIEW:
//			SngPatcher_AlwaysBagView::Instance()->PatchToggle();
//			break;
		case ID_TOGGLE_BANKTABENABLE:
			SngPatcher_BankTabEnable::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_NPCEQUIPVIEW:
			SngPatcher_NPCEquipView::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_CUTSCENEIMMEDIATESKIP:
			SngPatcher_CutSceneImmediateSkip::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_ITEMDROPPRESERVATION:
			SngPatcher_ItemDropPreservation::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_INVENTORYCOLORING:
			SngPatcher_InventoryColoring::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_DEADLYHPSHOW:
			SngPatcher_DeadlyHPShow::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_STATSFLOATING:
			SngPatcher_StatsFloating::Instance()->PatchToggle();
			break;
		/*case ID_TOGGLE_HIDEVISIBLE:
			SngPatcher_HideVisible::Instance()->PatchToggle();
			break;
		*/
		//case ID_TOGGLE_DEV1:
		//	SngPatcher_dev1::Instance()->PatchToggle();
		//	break;
		case ID_TOGGLE_SHOWITEMPRICE:
			SngPatcher_ShowItemPrice::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_FARSIGNREAD:
			SngPatcher_FarSignRead::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_INFRAMEWINPSV:
			SngPatcher_InframeWinPSV::Instance()->PatchToggle();
			break;
		case ID_TOGGLE_SPACEUNLOCK:
			SngPatcher_SpaceUnlock::Instance()->PatchToggle();
			break;

		//case ID_TOGGLE_NAMEOFMOD:
		//	SngPatcher_NameOfMod::Instance()->Toggle();
		//	break;
		}
		break;
	case WM_INITMENU:
		// Update display of menu
		UpdateMenu();
		break;
	}

	return CallWindowProc( wpPrevWndProc, hwnd, uMsg, wParam, lParam );
}

bool CModifyWindow::UpdateMenu()
{
	bool result = true;
	MENUITEMINFO info;
	info.cbSize = sizeof(MENUITEMINFO);
	info.fMask = MIIM_STATE;

	// Zoom limit
	switch (SngPatcher_ModifyZoomLimit::Instance()->GetLimit()) {
	case 5000:	result &= 0 != CheckMenuRadioItem( nogipartySubMenu, ID_ZOOMLIMIT_5000, ID_ZOOMLIMIT_1500, ID_ZOOMLIMIT_5000, 0 );	break;
	case 3500:	result &= 0 != CheckMenuRadioItem( nogipartySubMenu, ID_ZOOMLIMIT_5000, ID_ZOOMLIMIT_1500, ID_ZOOMLIMIT_3500, 0 );	break;
	case 1500:	result &= 0 != CheckMenuRadioItem( nogipartySubMenu, ID_ZOOMLIMIT_5000, ID_ZOOMLIMIT_1500, ID_ZOOMLIMIT_1500, 0 );	break;
	}

	// Zoom Near
	switch (SngPatcher_ModifyZoomLimit::Instance()->GetNear()) {
	case 500:	result &= 0 != CheckMenuRadioItem( nogipartySubMenu, ID_ZOOMNEAR_500, ID_ZOOMNEAR_300, ID_ZOOMNEAR_500, 0 );	break;
	case 400:	result &= 0 != CheckMenuRadioItem( nogipartySubMenu, ID_ZOOMNEAR_500, ID_ZOOMNEAR_300, ID_ZOOMNEAR_400, 0 );	break;
	case 300:	result &= 0 != CheckMenuRadioItem( nogipartySubMenu, ID_ZOOMNEAR_500, ID_ZOOMNEAR_300, ID_ZOOMNEAR_300, 0 );	break;
	}
	// 야간 효과 제거
	info.fState = (SngPatcher_DisableNighttime::Instance()->IsNightPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_DISABLENIGHTTIME, false, &info );

	// 이름 컬러링
	info.fState = (SngPatcher_EnableNameColoring::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_ENABLENAMECOLORING, false, &info );

	// 자기 거래 활성화
	info.fState = (SngPatcher_EnableSelfRightClick::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_ENABLESELFRIGHTCLICK, false, &info );

	// 멀리서 개인상점 열기
	info.fState = (SngPatcher_EnterRemoteShop::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_ENTERREMOTESHOP, false, &info );

	// 접속한 채널로 재접속
	info.fState = (SngPatcher_MoveToSameChannel::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_MOVETOSAMECHANNEL, false, &info );

	// NPC 이벤트 중 이동
	info.fState = (SngPatcher_MoveWhileTalking::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_MOVEWHILETALKING, false, &info );

	// 노기노기 스카우터
	info.fState = (SngPatcher_ShowCombatPower::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_SHOWCOMBATPOWER, false, &info );
	/*
	// Show item price
	info.fState = (SngPatcher_ShowItemPrice::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_SHOWITEMPRICE, false, &info );
	// Show true durability
	info.fState = (SngPatcher_ExtendDurability::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_EXTENDDURABILITY, false, &info );
	// Show item color
	info.fState = (SngPatcher_ExtendDurability::Instance()->IsInstalled()) ? MFS_ENABLED : MFS_DISABLED;
	info.fState |= (SngPatcher_ExtendDurability::Instance()->IsColorEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_SHOWITEMCOLOR, false, &info );
	// Show true food quality
	info.fState = (SngPatcher_ShowTrueFoodQuality::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_SHOWTRUEFOODQUALITY, false, &info );
	// User Parsing Command
	info.fState = (SngPatcher_ParseCommand::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_PARSECOMMAND, false, &info );
	*/
	// 항상 정령과 대화 가능 (장착하지 않아도 정령대화)
	info.fState = (SngPatcher_TalkToUnequippedEgo::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_TALKTOUNEQUIPPEDEGO, false, &info );

	// 프롭 타켓팅
	info.fState = (SngPatcher_TargetProps::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_TARGETPROPS, false, &info );

	// 비트맵 폰트 사용
	info.fState = (SngPatcher_UseBitmapFonts::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_USEBITMAPFONTS, false, &info );

	// 파티 모집시간 무제한
	info.fState = (SngPatcher_UnlimitPartytime::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_UNLIMITPARTYTIME, false, &info );

	// 분단위 시계
	info.fState = (SngPatcher_MinuteClock::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_MINUTECLOCK, false, &info );

	// 시간 알람
	info.fState = (SngPatcher_TimeAlerm::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_TIMEALERM, false, &info );

	// 스킬키에 아무거나 넣기
	info.fState = (SngPatcher_AnyPutSkillFx::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_ANYPUTSKILLFX, false, &info );

	// 파티 게시판 스왑
	info.fState = (SngPatcher_Party2Adver::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_PARTY2ADVER, false, &info );

	// 게시판 바로 열기
	info.fState = (SngPatcher_ExpressBoard::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_EXPRESSBOARD, false, &info );

	// 간소화 프레임 무시
	info.fState = (SngPatcher_SimpleFrameIgnore::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_SIMPLEFRAMEIGNORE, false, &info );

//	// 변신 효과 무시
//	info.fState = (SngPatcher_TransformIgnore::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
//	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_TRANSFORMIGNORE, false, &info );

	// 제로 고도 비행
	info.fState = (SngPatcher_FlyZeroHigh::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_FLYZEROHIGH, false, &info );

	// 미믹 이름표
	info.fState = (SngPatcher_MimicNaming::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_MIMICNAMING, false, &info );

	// 시야 내 모든 이름표 표시
	info.fState = (SngPatcher_VisionInAllName::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_VISIONINALLNAME, false, &info );

	// 반사광 제거
	//info.fState = (SngPatcher_NoReflexLight::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	//result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_NOREFLEXLIGHT, false, &info );
	
	// 내구도 확장
	info.fState = (SngPatcher_ExtendDurability::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_EXTENDDURABILITY, false, &info );
	
	// 아이템 색
	info.fState = (SngPatcher_ExtendDurability::Instance()->IsColorEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_SHOWITEMCOLOR, false, &info );
	
//	// 가방 항상 열기
//	info.fState = (SngPatcher_AlwaysBagView::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
//	result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_ALWAYSBAGVIEW, false, &info );

	// 은행 탭 항상 열기
	info.fState = (SngPatcher_BankTabEnable::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &=0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_BANKTABENABLE, false, &info );

	// NPC 장비 보기
	info.fState = (SngPatcher_NPCEquipView::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &=0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_NPCEQUIPVIEW, false, &info );

	// 컷신 빠르게 스킵
	info.fState = (SngPatcher_CutSceneImmediateSkip::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &=0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_CUTSCENEIMMEDIATESKIP, false, &info );

	// 아이템 드롭 보호
	info.fState = (SngPatcher_ItemDropPreservation::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &=0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_ITEMDROPPRESERVATION, false, &info );

	// 인벤토리 컬러링
	info.fState = (SngPatcher_InventoryColoring::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &=0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_INVENTORYCOLORING, false, &info );

	// 데들리 체력 표시
	info.fState = (SngPatcher_DeadlyHPShow::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &=0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_DEADLYHPSHOW, false, &info );

	// 스텟 소숫점
	info.fState = (SngPatcher_StatsFloating::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &=0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_STATSFLOATING, false, &info );

	// 빛무리 눈부심 없애기
	info.fState = (SngPatcher_NoReflexLight::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &=0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_NOREFLEXLIGHT, false, &info );

	/*
	// 하이드 캐릭터 보기
	info.fState = (SngPatcher_HideVisible::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &=0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_HIDEVISIBLE, false, &info );
	*/

	// 상점가 가격 표시
	info.fState = (SngPatcher_ShowItemPrice::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &=0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_SHOWITEMPRICE, false, &info );

	// 멀리서 표지판 읽기
	info.fState = (SngPatcher_FarSignRead::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &=0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_FARSIGNREAD, false, &info );

	// 인프레임 윈도우 보호
	info.fState = (SngPatcher_InframeWinPSV::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &=0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_INFRAMEWINPSV, false, &info );	

	// 스페이스바 캐릭터 동결 해제
	info.fState = (SngPatcher_SpaceUnlock::Instance()->IsPatchEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &=0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_SPACEUNLOCK, false, &info );	

	// // NameOfMod
	// info.fState = (SngPatcher_NameOfMod::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	// result &= 0 != SetMenuItemInfo( nogipartySubMenu, ID_TOGGLE_NAMEOFMOD, false, &info );

	if (!result)
		DebugLog("에러: 시스템 메뉴를 완전히 업데이트하지 못했습니다.\n");
	return result;
}

bool CModifyWindow::UpdateIcon( void )
{
	/*
	LPWSTR iconResource;
	if ((CThreadWatch::GetReductionPercentage() > 0) &&
		(!CThreadWatch::GetOptionOnlyMinimized() || isMinimized))
		iconResource = MAKEINTRESOURCE( IDI_ICON_BLUE );
	else iconResource = MAKEINTRESOURCE( IDI_ICON_ORANGE );

	if (hIcon)
		DeleteObject( hIcon );
	HICON icon = LoadIcon( g_hInstance, iconResource );
	if (icon == NULL) {
		DebugLog("ERROR: Loading icon resource 0x%08lX failed.\n", iconResource);
		return false;
	}
	SendMessage( mabiHWnd, WM_SETICON, ICON_SMALL, (LPARAM)icon );
	return true;	
	*/
	return false;
}

bool CModifyWindow::IsMinimized( void )
{
	return isMinimized;
}