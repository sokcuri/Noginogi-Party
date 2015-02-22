#include "Patcher_NoReflexLight.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

LPBYTE CPatcher_NoReflexLight::addrTargetReturn = NULL;
bool CPatcher_NoReflexLight::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_NoReflexLight::CPatcher_NoReflexLight( void )
{
	patchname = "반사광 제거";

	LPBYTE addrRenderGlowOverlay = CAddr::Addr(CRendererContext_RenderGlowOverlay);

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x0F, 0x84, -1, -1, -1, -1,
		0x8B, 0x06;

	funcPointer = (LPBYTE)patchNoReflexLight;

	patch +=
		0xFF, 0x15,
		((int)(&funcPointer) & 0xFF),
		(((int)(&funcPointer) & 0xFF00) >> 8),
		(((int)(&funcPointer) & 0xFF0000) >> 16),
		(((int)(&funcPointer) & 0xFF000000) >> 24),
		0x8B, 0x06;

	MemoryPatch mp( addrRenderGlowOverlay + 0x15, patch, backup );
	//mp.Search( L"Target.dll" );
	//mp.PatchExactAddress( 0x01, (LPBYTE)patchNameOfMod );
	//mp.PatchRelativeAddress( 0x01, (LPBYTE)patchNameOfMod );

	addrTargetReturn = mp.GetAddr() + 0x06;
	
	patches += mp;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_NoReflexLight::patchNoReflexLight(void)
{
	__asm {
		PUSH EAX
	}

	if (IsPatchEnabled())
	{
		__asm {
			POP EAX
			MOV ECX, DWORD PTR SS:[EBP-0x0C]
			MOV DWORD PTR FS:[0], ECX
			POP ECX
			POP EDI
			POP EDI
			POP ESI
			POP EBX
			MOV ESP, EBP
			POP EBP
			PUSH ECX
			ADD ESP, 4
			RETN
		}
	}
	else
	{
		__asm {
			POP EAX
			ADD ESP, 4
			JMP addrTargetReturn
		}
	}
}
//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_NoReflexLight::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_NoReflexLight::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_NoReflexLight::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_NoReflexLight::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_NoReflexLight::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_NoReflexLight::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_NoReflexLight::ReadINI( void )
{
	if ( ReadINI_Bool( L"NoReflexLight" ))
		return PatchEnable();
	return true;
}

bool CPatcher_NoReflexLight::WriteINI( void )
{
	WriteINI_Bool( L"NoReflexLight", IsPatchEnabled() );
	return true;
}