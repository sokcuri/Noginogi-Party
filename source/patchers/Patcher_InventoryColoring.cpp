#include "Patcher_InventoryColoring.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

int CPatcher_InventoryColoring::strCount;

CPatcher_InventoryColoring::InvStruct CPatcher_InventoryColoring::InvColor[512];

unsigned long CPatcher_InventoryColoring::Color1;
unsigned long CPatcher_InventoryColoring::Color2;

bool CPatcher_InventoryColoring::ColorMOD = false;

LPBYTE CPatcher_InventoryColoring::addrTargetReturn = NULL;
LPBYTE CPatcher_InventoryColoring::addrItemColoring = NULL;

LPBYTE CPatcher_InventoryColoring::addrIsBroken = NULL;
LPBYTE CPatcher_InventoryColoring::addrIsExpired = NULL;
LPBYTE CPatcher_InventoryColoring::addrCheckFastStringID = NULL;

bool CPatcher_InventoryColoring::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_InventoryColoring::CPatcher_InventoryColoring( void )
{
	patchname = "인벤토리 컬러링";

	addrIsExpired = CAddr::Addr(IItem_IsExpired);
	addrIsBroken = CAddr::Addr(IItem_IsBroken);
	addrCheckFastStringID = CAddr::Addr(IItem_CheckFastStringID);

	int count = 0;

	//////////////////////////////////////////////////////////////////
	//																//
	//						툴 파트									//
	//																//
	//////////////////////////////////////////////////////////////////
	// 악기
	wcscpy_s(InvColor[count].category, 256, L"/instrument/");
	wcscpy_s(InvColor[count].name, 256, L"InvInstrument");
	count++;

	// 책
	wcscpy_s(InvColor[count].category, 256, L"/book/");
	wcscpy_s(InvColor[count].name, 256, L"InvBook");
	count++;

	//////////////////////////////////////////////////////////////////
	//																//
	//						장비 파트								//
	//																//
	//////////////////////////////////////////////////////////////////

	// 화살통
	wcscpy_s(InvColor[count].category, 256, L"/weapon/arrow/sac_item/largearrowsac/");
	wcscpy_s(InvColor[count].name, 256, L"InvArrowSac");
	count++;

	// 화살
	wcscpy_s(InvColor[count].category, 256, L"/weapon/arrow/");
	wcscpy_s(InvColor[count].name, 256, L"InvArrow");
	count++;

	// 무기
	wcscpy_s(InvColor[count].category, 256, L"/weapon/");
	wcscpy_s(InvColor[count].name, 256, L"InvEquipWeapon");
	count++;

	// 정령무기
	wcscpy_s(InvColor[count].category, 256, L"/ego_weapon/");
	wcscpy_s(InvColor[count].name, 256, L"InvEgoWeapon");
	count++;

	// 방패
	wcscpy_s(InvColor[count].category, 256, L"/shield/");
	wcscpy_s(InvColor[count].name, 256, L"InvEquipShield");
	count++;

	// 악세
	wcscpy_s(InvColor[count].category, 256, L"/accessary/");
	wcscpy_s(InvColor[count].name, 256, L"InvEquipAccessary");
	count++;

	// 모자
	wcscpy_s(InvColor[count].category, 256, L"/equip/head/");
	wcscpy_s(InvColor[count].name, 256, L"InvEquipHead");
	count++;

	// 옷
	wcscpy_s(InvColor[count].category, 256, L"/cloth/");
	wcscpy_s(InvColor[count].name, 256, L"InvEquipArmor");
	count++;

	// 신발
	wcscpy_s(InvColor[count].category, 256, L"/shoes/");
	wcscpy_s(InvColor[count].name, 256, L"InvEquipFoot");
	count++;

	// 장갑
	wcscpy_s(InvColor[count].category, 256, L"/glove/");
	wcscpy_s(InvColor[count].name, 256, L"InvEquipHand");
	count++;

	// 로브
	wcscpy_s(InvColor[count].category, 256, L"/robe/");
	wcscpy_s(InvColor[count].name, 256, L"InvEquipRobe");
	count++;


	//////////////////////////////////////////////////////////////////
	//																//
	//						 포션 & 치료 파트						//
	//																//
	//////////////////////////////////////////////////////////////////

	// 체력+마나 포션
	wcscpy_s(InvColor[count].category, 256, L"/usable/potion/mana/hp/");
	wcscpy_s(InvColor[count].name, 256, L"InvHPManaPotion");
	count++;

	// 스템+마나 포션
	wcscpy_s(InvColor[count].category, 256, L"/usable/potion/stamina/hp/");
	wcscpy_s(InvColor[count].name, 256, L"InvStaminaManaPotion");
	count++;

	// 생명력 포션
	wcscpy_s(InvColor[count].category, 256, L"/usable/potion/hp/");
	wcscpy_s(InvColor[count].name, 256, L"InvHPPotion");
	count++;

	// 마나 포션
	wcscpy_s(InvColor[count].category, 256, L"/usable/potion/mana/");
	wcscpy_s(InvColor[count].name, 256, L"InvManaPotion");
	count++;

	// 스테미나 포션
	wcscpy_s(InvColor[count].category, 256, L"/usable/potion/stamina/");
	wcscpy_s(InvColor[count].name, 256, L"InvStaminaPotion");
	count++;

	// 부상 회복 포션
	wcscpy_s(InvColor[count].category, 256, L"/usable/potion/wound/");
	wcscpy_s(InvColor[count].name, 256, L"InvWoundPotion");
	count++;

	// 완전 회복 포션
	wcscpy_s(InvColor[count].category, 256, L"/usable/potion/full_recovery_potion/");
	wcscpy_s(InvColor[count].name, 256, L"InvFullRecoveryPotion");
	count++;

	// 축복의 포션
	wcscpy_s(InvColor[count].category, 256, L"/usable/blessing/");
	wcscpy_s(InvColor[count].name, 256, L"InvBlessPotion");
	count++;

	// 독 포션
	wcscpy_s(InvColor[count].category, 256, L"/usable/potion/poison/");
	wcscpy_s(InvColor[count].name, 256, L"InvPoisonPotion");
	count++;

	// 해독 포션
	wcscpy_s(InvColor[count].category, 256, L"/usable/potion/antidote/");
	wcscpy_s(InvColor[count].name, 256, L"InvAntidotePotion");
	count++;

	// 새도우 크리스탈
	wcscpy_s(InvColor[count].category, 256, L"/usable/potion/no_hotkey/writelog_use/shadow_mission_bonus/not_feed/");
	wcscpy_s(InvColor[count].name, 256, L"InvShadowMissionBonus");
	count++;

	// 그외 모든 종류 포션
	wcscpy_s(InvColor[count].category, 256, L"/usable/potion/");
	wcscpy_s(InvColor[count].name, 256, L"InvOtherPotion");
	count++;

	// 깃털 아이템
	wcscpy_s(InvColor[count].category, 256, L"/usable/resurrection/");
	wcscpy_s(InvColor[count].name, 256, L"InvResurrection");
	count++;

	// 붕대 아이템
	wcscpy_s(InvColor[count].category, 256, L"/usable/material/tailor/bandage/");
	wcscpy_s(InvColor[count].name, 256, L"InvBandage");
	count++;

	//////////////////////////////////////////////////////////////////
	//																//
	//						엘레멘탈 파트							//
	//																//
	//////////////////////////////////////////////////////////////////
	
	// 아이스 엘레멘탈
	wcscpy_s(InvColor[count].category, 256, L"/ice_elemental/");
	wcscpy_s(InvColor[count].name, 256, L"InvIceElemental");
	count++;

	// 파이어 엘레멘탈
	wcscpy_s(InvColor[count].category, 256, L"/fire_elemental/");
	wcscpy_s(InvColor[count].name, 256, L"InvFireElemental");
	count++;
	
	// 라이트닝 엘레멘탈
	wcscpy_s(InvColor[count].category, 256, L"/lightning_elemental/");
	wcscpy_s(InvColor[count].name, 256, L"InvLightningElemental");
	count++;
	
	// 엘레멘탈 리무버
	wcscpy_s(InvColor[count].category, 256, L"/elemental_remover/");
	wcscpy_s(InvColor[count].name, 256, L"InvElementalRemover");
	count++;

	//////////////////////////////////////////////////////////////////
	//																//
	//						 광석 파트								//
	//																//
	//////////////////////////////////////////////////////////////////

	// 철광석
	wcscpy_s(InvColor[count].category, 256, L"/ore/ironore/");
	wcscpy_s(InvColor[count].name, 256, L"InvIronOre");
	count++;
	wcscpy_s(InvColor[count].category, 256, L"/ore/ironore_fragment/");
	wcscpy_s(InvColor[count].name, 256, L"InvIronOre");
	count++;

	// 은광석
	wcscpy_s(InvColor[count].category, 256, L"/ore/silverore/");
	wcscpy_s(InvColor[count].name, 256, L"InvSilverOre");
	count++;
	wcscpy_s(InvColor[count].category, 256, L"/ore/silverore_fragment/");
	wcscpy_s(InvColor[count].name, 256, L"InvSilverOre");
	count++;

	// 동광석
	wcscpy_s(InvColor[count].category, 256, L"/ore/copperore/");
	wcscpy_s(InvColor[count].name, 256, L"InvCopperOre");
	count++;
	wcscpy_s(InvColor[count].category, 256, L"/ore/copperore_fragment/");
	wcscpy_s(InvColor[count].name, 256, L"InvCopperOre");
	count++;

	// 금광석
	wcscpy_s(InvColor[count].category, 256, L"/ore/goldore/");
	wcscpy_s(InvColor[count].name, 256, L"InvGoldOre");
	count++;
	wcscpy_s(InvColor[count].category, 256, L"/ore/goldore_fragment/");
	wcscpy_s(InvColor[count].name, 256, L"InvGoldOre");
	count++;

	// 미스릴광석
	wcscpy_s(InvColor[count].category, 256, L"/ore/mythrilore/");
	wcscpy_s(InvColor[count].name, 256, L"InvMythrilOre");
	count++;
	wcscpy_s(InvColor[count].category, 256, L"/ore/mythrilore_fragment/");
	wcscpy_s(InvColor[count].name, 256, L"InvMythrilOre");
	count++;

	// StrangeOre
	wcscpy_s(InvColor[count].category, 256, L"/ore/strangeore_fragment/");
	wcscpy_s(InvColor[count].name, 256, L"InvStrangeOre");
	count++;

	// 철괴
	wcscpy_s(InvColor[count].category, 256, L"/ingot/ironingot/");
	wcscpy_s(InvColor[count].name, 256, L"InvIronIngot");
	count++;

	// 은괴
	wcscpy_s(InvColor[count].category, 256, L"/ingot/silveringot/");
	wcscpy_s(InvColor[count].name, 256, L"InvSilverIngot");
	count++;

	// 동괴
	wcscpy_s(InvColor[count].category, 256, L"/ingot/copperingot/");
	wcscpy_s(InvColor[count].name, 256, L"InvCopperIngot");
	count++;

	// 금괴
	wcscpy_s(InvColor[count].category, 256, L"/ingot/goldingot/");
	wcscpy_s(InvColor[count].name, 256, L"InvGoldIngot");
	count++;

	// 미스릴괴
	wcscpy_s(InvColor[count].category, 256, L"/ingot/mythrilingot/");
	wcscpy_s(InvColor[count].name, 256, L"InvMythrilIngot");
	count++;

	// 철판
	wcscpy_s(InvColor[count].category, 256, L"/plate/iron/");
	wcscpy_s(InvColor[count].name, 256, L"InvIronPlate");
	count++;

	// 은판
	wcscpy_s(InvColor[count].category, 256, L"/plate/silver/");
	wcscpy_s(InvColor[count].name, 256, L"InvSilverPlate");
	count++;

	// 동판
	wcscpy_s(InvColor[count].category, 256, L"/plate/copper/");
	wcscpy_s(InvColor[count].name, 256, L"InvCopperPlate");
	count++;

	// 금판
	wcscpy_s(InvColor[count].category, 256, L"/plate/gold/");
	wcscpy_s(InvColor[count].name, 256, L"InvGoldPlate");
	count++;

	// 미스릴판
	wcscpy_s(InvColor[count].category, 256, L"/plate/mythril/");
	wcscpy_s(InvColor[count].name, 256, L"InvMythrilPlate");
	count++;

	// 철봉
	wcscpy_s(InvColor[count].category, 256, L"/bar/iron/");
	wcscpy_s(InvColor[count].name, 256, L"InvIronBar");
	count++;

	// 은봉
	wcscpy_s(InvColor[count].category, 256, L"/bar/silver/");
	wcscpy_s(InvColor[count].name, 256, L"InvSilverBar");
	count++;

	// 동봉
	wcscpy_s(InvColor[count].category, 256, L"/bar/copper/");
	wcscpy_s(InvColor[count].name, 256, L"InvCopperBar");
	count++;

	// 금봉
	wcscpy_s(InvColor[count].category, 256, L"/bar/gold/");
	wcscpy_s(InvColor[count].name, 256, L"InvGoldBar");
	count++;

	// 미스릴봉
	wcscpy_s(InvColor[count].category, 256, L"/bar/mythril/");
	wcscpy_s(InvColor[count].name, 256, L"InvMythrilBar");
	count++;

	//////////////////////////////////////////////////////////////////
	//																//
	//						하우징 파트								//
	//																//
	//////////////////////////////////////////////////////////////////

	// 하우징 열쇠
	wcscpy_s(InvColor[count].category, 256, L"/usable/warp_scroll/target/house/host_warp/");
	wcscpy_s(InvColor[count].name, 256, L"InvHousingKey");
	count++;

	// 하우징 귀환 쿠폰
	wcscpy_s(InvColor[count].category, 256, L"/usable/warp_scroll/target/destroyable/");
	wcscpy_s(InvColor[count].name, 256, L"InvHousingReturnCoupon");
	count++;

	//////////////////////////////////////////////////////////////////
	//																//
	//						던전 파트								//
	//																//
	//////////////////////////////////////////////////////////////////

	// 마족 통행증 #g3_pass
	wcscpy_s(InvColor[count].category, 256, L"/item/g3_pass/");
	wcscpy_s(InvColor[count].name, 256, L"InvDungeonPass");
	count++;

	// 마족 통행증 #dungeon_pass
	wcscpy_s(InvColor[count].category, 256, L"/item/dungeon_pass/");
	wcscpy_s(InvColor[count].name, 256, L"InvDungeonPass");
	count++;

	// 마족 통행증 #unlimited_dungeon_pass
	wcscpy_s(InvColor[count].category, 256, L"/usable/unlimited_dungeon_pass/");
	wcscpy_s(InvColor[count].name, 256, L"InvDungeonPass");
	count++;

	// 유적 통행증
	wcscpy_s(InvColor[count].category, 256, L"/item/ruin_pass/");
	wcscpy_s(InvColor[count].name, 256, L"InvRuinPass");
	count++;

	// 그림자미션 통행증
	wcscpy_s(InvColor[count].category, 256, L"/item/shadowmission_pass/");
	wcscpy_s(InvColor[count].name, 256, L"InvShadowMissionPass");
	count++;

	// 던전 키
	wcscpy_s(InvColor[count].category, 256, L"/dungeon/key/");
	wcscpy_s(InvColor[count].name, 256, L"InvDungeonKey");
	count++;

	//////////////////////////////////////////////////////////////////
	//																//
	//						화석 파트								//
	//																//
	//////////////////////////////////////////////////////////////////

	// 복원 가능한 화석
	wcscpy_s(InvColor[count].category, 256, L"/item/usable/fossil_restoration/");
	wcscpy_s(InvColor[count].name, 256, L"InvFossilRestorable");
	count++;

	// 복원된 화석
	wcscpy_s(InvColor[count].category, 256, L"/item/fossil/");
	wcscpy_s(InvColor[count].name, 256, L"InvFossil");
	count++;


	//////////////////////////////////////////////////////////////////
	//																//
	//					 스크롤 아이템 파트						//
	//																//
	//////////////////////////////////////////////////////////////////

	// 인챈트 스크롤
	wcscpy_s(InvColor[count].category, 256, L"/enchant/enchantscroll/");
	wcscpy_s(InvColor[count].name, 256, L"InvEnchantScroll");
	count++;

	// 도면 스크롤
	wcscpy_s(InvColor[count].category, 256, L"/manual/");
	wcscpy_s(InvColor[count].name, 256, L"InvManualScroll");
	count++;

	// 퀘스트 스크롤
	wcscpy_s(InvColor[count].category, 256, L"/scroll/mission_paper/");
	wcscpy_s(InvColor[count].name, 256, L"InvQuestScroll");
	count++;
	wcscpy_s(InvColor[count].category, 256, L"/scroll/questscroll/");
	wcscpy_s(InvColor[count].name, 256, L"InvQuestScroll");
	count++;

	// 악보 스크롤
	wcscpy_s(InvColor[count].category, 256, L"/scroll/lefthand/no_abrasion/score/");
	wcscpy_s(InvColor[count].name, 256, L"InvScoreScroll");
	count++;

	// 그 외 나머지 스크롤
	wcscpy_s(InvColor[count].category, 256, L"/scroll/");
	wcscpy_s(InvColor[count].name, 256, L"InvOtherScroll");
	count++;

	//////////////////////////////////////////////////////////////////
	//																//
	//					사용가능 아이템 파트						//
	//																//
	//////////////////////////////////////////////////////////////////

	// 돈주머니
	wcscpy_s(InvColor[count].category, 256, L"/pouch/money/");
	wcscpy_s(InvColor[count].name, 256, L"InvMoneyPouch");
	count++;

	// 골드
	wcscpy_s(InvColor[count].category, 256, L"/money/not_given/");
	wcscpy_s(InvColor[count].name, 256, L"InvGoldMoney");
	count++;

	// 양털 주머니
	wcscpy_s(InvColor[count].category, 256, L"/sac_item/woolsac/not_given/");
	wcscpy_s(InvColor[count].name, 256, L"InvWoolSac");
	count++;

	// 식품
	wcscpy_s(InvColor[count].category, 256, L"/usable/food/");
	wcscpy_s(InvColor[count].name, 256, L"InvUsableFood");
	count++;

	// 날개 아이템
	wcscpy_s(InvColor[count].category, 256, L"/usable/warp_scroll/");
	wcscpy_s(InvColor[count].name, 256, L"InvWarpWing");
	count++;

	// 아이스 마인
	wcscpy_s(InvColor[count].category, 256, L"/usable/mine/ice/");
	wcscpy_s(InvColor[count].name, 256, L"InvIceMine");
	count++;

	// 개인 상점 허가증
	wcscpy_s(InvColor[count].category, 256, L"/usable/personalshoplicense/");
	wcscpy_s(InvColor[count].name, 256, L"InvPersonalShopLicense");
	count++;

	//////////////////////////////////////////////////////////////////
	//																//
	//						결정 아이템 파트						//
	//																//
	//////////////////////////////////////////////////////////////////

	// 구름의 결정 아이템
	wcscpy_s(InvColor[count].category, 256, L"/usable/crystal/cloud/");
	wcscpy_s(InvColor[count].name, 256, L"InvCloudCrystal");
	count++;

	// 눈보라의 결정 아이템
	wcscpy_s(InvColor[count].category, 256, L"/usable/crystal/snowstorm/");
	wcscpy_s(InvColor[count].name, 256, L"InvSnowStormCrystal");
	count++;

	// 방호벽의 결정 아이템
	wcscpy_s(InvColor[count].category, 256, L"/usable/crystal/barrier/");
	wcscpy_s(InvColor[count].name, 256, L"InvBarrierCrystal");
	count++;

	// 불의 결정 아이템
	wcscpy_s(InvColor[count].category, 256, L"/fire_crystal/crystal/");
	wcscpy_s(InvColor[count].name, 256, L"InvFireCrystal");
	count++;

	// 물의 결정 아이템
	wcscpy_s(InvColor[count].category, 256, L"/water_crystal/crystal/");
	wcscpy_s(InvColor[count].name, 256, L"InvWaterCrystal");
	count++;

	// 바람의 결정 아이템
	wcscpy_s(InvColor[count].category, 256, L"/wind_crystal/crystal/");
	wcscpy_s(InvColor[count].name, 256, L"InvWindCrystal");
	count++;

	// 땅의 결정 아이템
	wcscpy_s(InvColor[count].category, 256, L"/earth_crystal/crystal/");
	wcscpy_s(InvColor[count].name, 256, L"InvEarthCrystal");
	count++;

	// 파이어볼의 결정 아이템
	wcscpy_s(InvColor[count].category, 256, L"/usable/item/crystal/mana_forming/hotkey_bar/fireball_crystal/");
	wcscpy_s(InvColor[count].name, 256, L"InvFireBallCrystal");
	count++;

	// 아이스 스피어의 결정 아이템
	wcscpy_s(InvColor[count].category, 256, L"/usable/item/crystal/mana_forming/hotkey_bar/icespear_crystal/");
	wcscpy_s(InvColor[count].name, 256, L"InvIceSpearCrystal");
	count++;

	// 썬더의 결정 아이템
	wcscpy_s(InvColor[count].category, 256, L"/usable/item/crystal/mana_forming/hotkey_bar/thunder_crystal/");
	wcscpy_s(InvColor[count].name, 256, L"InvThunderCrystal");
	count++;

	// 라이프 드레인의 결정 아이템
	wcscpy_s(InvColor[count].category, 256, L"/item/crystal/lifedrain/usable/");
	wcscpy_s(InvColor[count].name, 256, L"InvLifeDrainCrystal");
	count++;

	// 워터 캐논의 결정 아이템
	wcscpy_s(InvColor[count].category, 256, L"/item/crystal/watercannon/");
	wcscpy_s(InvColor[count].name, 256, L"InvWaterCannonCrystal");
	count++;

	// 바위 골렘의 결정 아이템
	wcscpy_s(InvColor[count].category, 256, L"/item/crystal/rockgolem/recall/usable/");
	wcscpy_s(InvColor[count].name, 256, L"InvRockGolemCrystal");
	count++;

	// 숲 골렘의 결정 아이템
	wcscpy_s(InvColor[count].category, 256, L"/item/crystal/forestgolem/recall/usable/");
	wcscpy_s(InvColor[count].name, 256, L"InvForestGolemCrystal");
	count++;

	// 유황 골렘의 결정 아이템
	wcscpy_s(InvColor[count].category, 256, L"/item/crystal/sulfurgolem/recall/usable/");
	wcscpy_s(InvColor[count].name, 256, L"InvSulfurGolemCrystal");
	count++;

	// 순백/마법 골렘의 결정 아이템
	wcscpy_s(InvColor[count].category, 256, L"/item/crystal/whitegolem/recall/usable/");
	wcscpy_s(InvColor[count].name, 256, L"InvWhiteGolemCrystal");
	count++;

	// 스파크의 결정 아이템
	wcscpy_s(InvColor[count].category, 256, L"/item/crystal/spark/usable/");
	wcscpy_s(InvColor[count].name, 256, L"InvSparkCrystal");
	count++;

	// 그 외 결정 아이템
	wcscpy_s(InvColor[count].category, 256, L"/crystal/");
	wcscpy_s(InvColor[count].name, 256, L"InvCrystal");
	count++;

	//////////////////////////////////////////////////////////////////
	//																//
	//						채집 아이템 파트						//
	//																//
	//////////////////////////////////////////////////////////////////

	// 나무토막
	wcscpy_s(InvColor[count].category, 256, L"/item/wood/");
	wcscpy_s(InvColor[count].name, 256, L"InvWoodItem");
	count++;

	// 허브
	wcscpy_s(InvColor[count].category, 256, L"/herb/");
	wcscpy_s(InvColor[count].name, 256, L"InvHerbItem");
	count++;

	// 보석 아이템
	wcscpy_s(InvColor[count].category, 256, L"/jewel/");
	wcscpy_s(InvColor[count].name, 256, L"InvJewel");
	count++;

	//////////////////////////////////////////////////////////////////
	//																//
	//						수집 아이템 파트						//
	//																//
	//////////////////////////////////////////////////////////////////

	// 마족 스크롤
	wcscpy_s(InvColor[count].category, 256, L"/item/evilscroll/");
	wcscpy_s(InvColor[count].name, 256, L"InvEvilScroll");
	count++;

	// 나오 옷
	wcscpy_s(InvColor[count].category, 256, L"/item/nao_dress/");
	wcscpy_s(InvColor[count].name, 256, L"InvNaoDress");
	count++;

	//////////////////////////////////////////////////////////////////
	//																//
	//						일반 아이템 파트						//
	//																//
	//////////////////////////////////////////////////////////////////

	// 선물 아이템
	wcscpy_s(InvColor[count].category, 256, L"/present/");
	wcscpy_s(InvColor[count].name, 256, L"InvGiftItem");
	count++;

	// 배달 아이템
	wcscpy_s(InvColor[count].category, 256, L"/delivery/");
	wcscpy_s(InvColor[count].name, 256, L"InvDeliveryItem");
	count++;

	// 퀄린 스톤#01
	wcscpy_s(InvColor[count].category, 256, L"/item/stone01/");
	wcscpy_s(InvColor[count].name, 256, L"InvCuilinStone");
	count++;

	// 퀄린 스톤#02
	wcscpy_s(InvColor[count].category, 256, L"/item/stone02/");
	wcscpy_s(InvColor[count].name, 256, L"InvCuilinStone");
	count++;

	// 퀄린 스톤#03
	wcscpy_s(InvColor[count].category, 256, L"/item/stone03/");
	wcscpy_s(InvColor[count].name, 256, L"InvCuilinStone");
	count++;

	// 퀄린 스톤#04
	wcscpy_s(InvColor[count].category, 256, L"/item/stone04/");
	wcscpy_s(InvColor[count].name, 256, L"InvCuilinStone");
	count++;

	// 정령석(원석)
	wcscpy_s(InvColor[count].category, 256, L"/item/FragmentSpiritFossil/");
	wcscpy_s(InvColor[count].name, 256, L"InvSpiritFossil");
	count++;

	// 정령석
	wcscpy_s(InvColor[count].category, 256, L"/item/ego_stone/");
	wcscpy_s(InvColor[count].name, 256, L"InvEgoStone");
	count++;

	strCount = count;

	WriteLog("%d개의 인벤토리 컬러링 데이터가 있습니다.\n", strCount);

	vector<WORD> search;
	vector<WORD> patch1;
	vector<WORD> patch2;
	vector<WORD> patch3;
	vector<WORD> backup1;
	vector<WORD> backup2;
	vector<WORD> backup3;

	search +=
		0xFF, 0xD7,
		0x52,
		0x50,
		0xE8, -1, -1, -1, -1,
		0x83, 0xC4, 0x0C,
		0x84, 0xC0,
		0x74, 0x76;
/*
	patch3 +=
		0xFF, 0xD7,
		0x52,
		0x50,
		0xE8, -1, -1, -1, -1,
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x74, 0x76;
*/
	MemoryPatch mp( NULL, search, search );
	mp.Search( L"Pleione.dll" );
	addrItemColoring = mp.GetAddr() + 0x10;

	// 내구도 다됬을때
	backup1 +=
		0x8B, 0xF8,
		0x85, 0xDB,
		0x0F, 0x84, -1, -1, -1, -1,
		0x85, 0xFF,
		0x0F, 0x84, -1, -1, -1, -1,
		0x8B, 0xCF,
		0xFF, 0x15, -1, -1, -1, -1,
		0x84, 0xC0,
		0x0F, 0x85;

	funcPointer = (LPBYTE)patchInventoryColoring;

	patch1 +=
		0x8B, 0xF8,
		0x85, 0xDB,
		0x0F, 0x84, -1, -1, -1, -1,
		0x85, 0xFF,
		0x0F, 0x84, -1, -1, -1, -1,
		0x8B, 0xCF,
		0xFF, 0x15,
		((int)(&funcPointer) & 0xFF),
		(((int)(&funcPointer) & 0xFF00) >> 8),
		(((int)(&funcPointer) & 0xFF0000) >> 16),
		(((int)(&funcPointer) & 0xFF000000) >> 24),
		0x84, 0xC0,
		0x0F, 0x85;

	MemoryPatch mp1( NULL, patch1, backup1 );
	mp1.Search( L"Pleione.dll" );

	backup2 +=
		0x59,
		0x59,
		0x8B, 0x4D, 0x1C,
		0x89, 0x01,
		0xB8, 0x00, 0x00, 0xA0, 0x00,
		0x09, 0x06,
		0x09, 0x07,
		0xB8, 0x00, 0x00, 0xD0, 0x00,
		0xE9;

	patch2 +=
		0x59,
		0x59,
		0x8B, 0x4D, 0x1C,
		0x89, 0x01,
		0xA1,
		((int)(&Color1) & 0xFF),
		(((int)(&Color1) & 0xFF00) >> 8),
		(((int)(&Color1) & 0xFF0000) >> 16),
		(((int)(&Color1) & 0xFF000000) >> 24),
		0x09, 0x06,
		0x09, 0x07,
		0xA1,
		((int)(&Color2) & 0xFF),
		(((int)(&Color2) & 0xFF00) >> 8),
		(((int)(&Color2) & 0xFF0000) >> 16),
		(((int)(&Color2) & 0xFF000000) >> 24),
		0xE9;

	MemoryPatch mp2( NULL, patch2, backup2 );
	mp2.Search( L"Pleione.dll" );

	backup3 +=
		0x83, 0xBE, 0xAC, 0x00, 0x00, 0x00, 0x04,
		0x74, 0x39,
		0x53,
		0xFF, 0x75, 0xF8,
		0x8D, 0x8E;

	patch3 +=
		0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x85, 0xC0,
		0x74, 0x39,
		0x53,
		0xFF, 0x75, 0xF8,
		0x8D, 0x8E;

	MemoryPatch mp3( NULL, patch3, backup3 );
	mp3.Search( L"Pleione.dll" );
	mp3.PatchRelativeAddress( 0x01, (LPBYTE)patchIsEnable );

	addrTargetReturn = mp3.GetAddr() + 0x07;
	
	patches += mp1;
	patches += mp2;
	patches += mp3;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_InventoryColoring::patchInventoryColoring(void)
{
	if (IsPatchEnabled())
	{
		unsigned long c1;
		unsigned long c2;

		for(int lp=0; lp<strCount; lp++)
		{
			c1 = InvColor[lp].color[0];
			c2 = InvColor[lp].color[1];

			LPBYTE tp = (LPBYTE)&(InvColor[lp].category);

			__asm {
				MOV DWORD PTR DS:[Color1], 0x0A00000
				MOV DWORD PTR DS:[Color2], 0x0D00000

				MOV ECX, EDI
				CALL addrIsBroken
				TEST AL, AL
				JNE IsBroken

				//ColoringItem:

				MOV ECX, EDI
				PUSH DWORD PTR DS:[tp]
				CALL addrCheckFastStringID
				TEST AL, AL
				JNE TargetItem
				MOV BYTE PTR DS:[ColorMOD], 0
			}
		}

		__asm {
			JMP IsBroken
			// 해당되는 아이템일때
			TargetItem:
			MOV EAX, DWORD PTR DS:[c1]
			MOV DWORD PTR DS:[Color1], EAX
			MOV EAX, DWORD PTR DS:[c2]
			MOV DWORD PTR DS:[Color2], EAX
			MOV BYTE PTR DS:[ColorMOD], 1
		}

		// 색이 지정되지 않았을 땐 패스	
		if (c1 == 0 && c2 == 0)
		{
			__asm MOV BYTE PTR DS:[ColorMOD], 0
		}

		__asm {

			IsBroken:
			MOV ECX, EDI
			JMP addrIsBroken
		}
	}
	else
	{
		__asm {
			// 복구하기
			MOV ECX, EDI
			MOV DWORD PTR DS:[Color1], 0x0A00000
			MOV DWORD PTR DS:[Color2], 0x0D00000
			MOV BYTE PTR DS:[ColorMOD], 0
			JMP addrIsBroken
		}
	}
}

NAKED void CPatcher_InventoryColoring::patchIsEnable(void)
{
	__asm {
		//ADD ESP, 4h
		PUSH EAX
		/*
		TEST AL, AL
		JE lNext

		// Broke & Expire
		MOV DWORD PTR DS:[Color1], 0x0A00000
		MOV DWORD PTR DS:[Color2], 0x0D00000

		lNext:
		*/
	}

	// 패치설정중이고 인벤토리 컬러링에 걸린녀석일때
	if (IsPatchEnabled() && ColorMOD == 1)
	{
		__asm {
			POP EAX
			CMP DWORD PTR DS:[ESI+0xAC],4
			JE lMousePut
			//ADD ESP, 0x0C
			ADD ESP, 0x04
			JMP addrItemColoring
		}
	}
	else
	{
		__asm {
			POP EAX
			lMousePut:
			//ADD ESP, 0x0C
			CMP DWORD PTR DS:[ESI+0xAC],4
			RETN
		}
	}

}
//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_InventoryColoring::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_InventoryColoring::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_InventoryColoring::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_InventoryColoring::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_InventoryColoring::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_InventoryColoring::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_InventoryColoring::ReadINI( void )
{
	wchar_t buf[256];
	wchar_t name[256];
	wchar_t *endptr = NULL;

	for (int i=0; i<strCount; i++)
	{
		for (int j=1; j<=2; j++)
		{
			swprintf(name, sizeof(name), L"%ls%d", InvColor[i].name, j);
			ReadINI_String(name, buf);
			InvColor[i].color[j-1] = wcstoul(buf, &endptr, 16);
			WriteLog("%ls: #%08X\n", name, InvColor[i].color[j-1]);
		}

	}

	if ( ReadINI_Bool( L"InvColoring" ))
		return PatchEnable();
	return true;
}

bool CPatcher_InventoryColoring::WriteINI( void )
{
	WriteINI_Bool( L"InvColoring", IsPatchEnabled() );
	return true;
}