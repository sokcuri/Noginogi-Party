#include "Patcher_ShowTrueFoodQuality.h"
#include "../Addr.h"

//-----------------------------------------------------------------------------
// Static variable initialization

wchar_t CPatcher_ShowTrueFoodQuality::dataBuf[256];
LPBYTE CPatcher_ShowTrueFoodQuality::addrCStringTEquals = NULL;
LPBYTE CPatcher_ShowTrueFoodQuality::addrTargetReturn = NULL;

bool CPatcher_ShowTrueFoodQuality::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_ShowTrueFoodQuality::CPatcher_ShowTrueFoodQuality( void )
{
	patchname = "Show True Food Quality";

	addrCStringTEquals = CAddr::Addr(CStringTUni_Equals);
	if (!addrCStringTEquals) {
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
		WriteLog("   종속 요소가 없습니다.\n");
		return;
	}

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x8B, 0xCB,								// +CC: MOV ECX, EBX
		0xFF, 0x15, -1, -1, -1, -1,				// +CE: CALL xxxxxxxx (esl::CStringT::operator+=(wchar const *))
		0x80, 0x7D, 0x18, 0x00,					// +D4: CMP [EBP-10], 0
		0x0F, 0x84, 0x31, 0x01, 0x00, 0x00;		// +D8: JZ NEAR +0x131

	funcPointer = (LPBYTE)&patchFoodQuality;

	patch +=
		-1, -1,
		0xFF, 0x15,
		((int)(&funcPointer) & 0xFF),
		(((int)(&funcPointer) & 0xFF00) >> 8),
		(((int)(&funcPointer) & 0xFF0000) >> 16),
		(((int)(&funcPointer) & 0xFF000000) >> 24);
		-1, -1, -1, -1,						// +D1: NOP (x3)
		-1, -1, -1, -1, -1, -1;
	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"Pleione.dll" );

	addrTargetReturn = mp.GetAddr() + 0x08;		// +D4
	
	patches += mp;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_ShowTrueFoodQuality::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_ShowTrueFoodQuality::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_ShowTrueFoodQuality::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_ShowTrueFoodQuality::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_ShowTrueFoodQuality::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_ShowTrueFoodQuality::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_ShowTrueFoodQuality::patchFoodQuality(void)
{
	//EAX: Numeric food quality
	//EBX: String pointer
	//ECX: none
	__asm {
		pop		ecx				
		push	eax
		push	ecx
		push	offset dataBuf
		call	patchFoodQualityFormat
		add		esp, 0Ch

		push	offset dataBuf
		mov		ecx, ebx;
		call	addrCStringTEquals

		jmp		addrTargetReturn
	}
}

void CPatcher_ShowTrueFoodQuality::patchFoodQualityFormat(wchar_t * buff,wchar_t* str,int d)
{
	swprintf_s(buff,255,L"%s (%d)",str,d);
}

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_ShowTrueFoodQuality::ReadINI( void )
{
	if ( ReadINI_Bool( L"ShowTrueFoodQuality" ))
		return Install();
	return true;
}

bool CPatcher_ShowTrueFoodQuality::WriteINI( void )
{
	WriteINI_Bool( L"ShowTrueFoodQuality", IsInstalled() );
	return true;
}