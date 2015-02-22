#include "Patcher_ShowTrueDurability.h"
#include "../Addr.h"

/* Show True Durability
 * Show item durability with 1000x precision.
 * PATCHES: Pleione.dll, Standard.dll
 */

//-----------------------------------------------------------------------------
// Static variable initialization

wchar_t CPatcher_ShowTrueDurability::dataColorString[] = L"<color=3>";
wchar_t CPatcher_ShowTrueDurability::dataColorBuf[256];
wchar_t CPatcher_ShowTrueDurability::dataDurabilityString[256];
wchar_t CPatcher_ShowTrueDurability::dataFullString[256];
LPBYTE CPatcher_ShowTrueDurability::addrGetColor = NULL;
LPBYTE CPatcher_ShowTrueDurability::addrCFormatterInsert_ulong = NULL;
LPBYTE CPatcher_ShowTrueDurability::addrCFormatterInsert_pwchar = NULL;
LPBYTE CPatcher_ShowTrueDurability::addrTargetReturn = NULL;
LPBYTE CPatcher_ShowTrueDurability::addrColorReturn = NULL;
LPBYTE CPatcher_ShowTrueDurability::addrColorReturnPerfect = NULL;

//-----------------------------------------------------------------------------
// Constructor

CPatcher_ShowTrueDurability::CPatcher_ShowTrueDurability( void )
{
	patchname = "Show True Durability";
	colorEnabled = false;

	LPBYTE addrGetInterfaceDurability = CAddr::Addr(IItem_GetInterfaceDurability);
	LPBYTE addrGetInterfaceDurabilityMax = CAddr::Addr(IItem_GetInterfaceDurabilityMax);
	LPBYTE addrDurabilityString, addrColorHook;

	addrGetColor = CAddr::Addr(IItem_GetColor);
	addrCFormatterInsert_ulong = CAddr::Addr(CFormatter_Insert_ulong);
	addrCFormatterInsert_pwchar = CAddr::Addr(CFormatter_Insert_pwchar);

	if (!addrGetInterfaceDurability ||
		!addrGetInterfaceDurabilityMax ||
		!addrCFormatterInsert_ulong ||
		!addrCFormatterInsert_pwchar)
	{
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
		WriteLog("   종속 요소가 없습니다.\n");
		return;
	}



	//////////////////////////////////
	// STANDARD.DLL

	// Patch core::IItem::GetInterfaceDurability(Max) to jump to our custom functions
	vector<WORD> patchInterfaceDurability, backupInterfaceDurability;
	backupInterfaceDurability +=
		0x8B, 0x41, -1,							// +00: MOV EAX, [ECX+xx]
		0x05, 0xE7, 0x03, 0x00, 0x00,			// +03: ADD EAX, 999
		0x33, 0xD2,								// +08: XOR EDX, EDX
		0xB9, 0xE8, 0x03, 0x00, 0x00,			// +0A: MOV ECX, 1000
		0xF7, 0xF1,								// +0F: DIV ECX
		0xC3;									// +11: RETN
	patchInterfaceDurability +=
		0xE9, 0x01FF, 0x01FF, 0x01FF, 0x01FF,	// +00: JMP GetDurability(Max)
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1;

	MemoryPatch mpInterfaceDurability( addrGetInterfaceDurability, patchInterfaceDurability, backupInterfaceDurability );
	mpInterfaceDurability.PatchRelativeAddress( 0x01, (LPBYTE)GetDurability );

	MemoryPatch mpInterfaceDurabilityMax( addrGetInterfaceDurabilityMax, patchInterfaceDurability, backupInterfaceDurability );
	mpInterfaceDurabilityMax.PatchRelativeAddress( 0x01, (LPBYTE)GetDurabilityMax );



	//////////////////////////////////
	// PLEIONE.DLL

	// Insert our hook
	vector<WORD> patchHook, backupHook;
	backupHook +=
		0xFF, 0x15, -1, -1, -1, -1,		// +7A: CALL xxxxxxxx (core::IItem::GetInterfaceDurabilityMax)
		0x50,							// +80: PUSH EAX
		0x8B, 0xCF,						// +81: MOV ECX, EDI
		0xFF, 0xD3,						// +83: CALL EBX (core::IItem::GetInterfaceDurability)
		0x8B, 0xCE,						// +85: MOV ECX, ESI
		0x8B, 0x35, -1, -1, -1, -1,		// +87: MOV ESI, xxxxxxxx (esl::CFormatter::operator<<(ulong))
		0x50,							// +8D: PUSH EAX
		0xFF, 0xD6,						// +8E: CALL ESI
		0x8B, 0xC8,						// +90: MOV ECX, EAX
		0xFF, 0xD6;						// +92: CALL ESI
	patchHook +=
		0xE9, 0x01FF, 0x01FF, 0x01FF, 0x01FF,	// +7A: JMP patchDurability
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1;
	MemoryPatch mpHook( NULL, patchHook, backupHook );
	mpHook.Search( L"Pleione.dll" );
	mpHook.PatchRelativeAddress( 0x01, (LPBYTE)patchDurability );

	addrTargetReturn       = mpHook.GetAddr() - 0x7A + 0x94;
	addrColorReturn        = mpHook.GetAddr() - 0x7A + 0x17C;
	addrColorReturnPerfect = mpHook.GetAddr() - 0x7A + 0x1BC;
	addrDurabilityString   = mpHook.GetAddr() - 0x7A + 0x47;
	addrColorHook          = mpHook.GetAddr() - 0x7A + 0x177;

	// Patch over original durability string
	vector<WORD> patchDuraString, backupDuraString;
	backupDuraString +=
		0x68, -1, -1, -1, -1;					// +47: PUSH OFFSET xxxxxxxx (code.client.msg.item_durability)
	patchDuraString +=
		-1, 0x01FF, 0x01FF, 0x01FF, 0x01FF;		// +47: PUSH OFFSET dataDurabilityString

	MemoryPatch mpDuraString( addrDurabilityString, patchDuraString, backupDuraString );
	mpDuraString.PatchExactAddress( 0x01, (LPBYTE)(&dataFullString) );

	// Insert the 100% dura color hook
	vector<WORD> patchColorHook, backupColorHook;
	backupColorHook +=
		0xFF, 0xD3,								// +177: CALL EBX
		0x83, 0xF8, 0x0A;						// +179: CMP EAX, 0Ah
	patchColorHook +=
		0xE9, 0x01FF, 0x01FF, 0x01FF, 0x01FF;	// +177: JMP patchDurabilityColor
	MemoryPatch mpColorHook( addrColorHook, patchColorHook, backupColorHook );
	mpColorHook.PatchRelativeAddress( 0x01, (LPBYTE)patchDurabilityColor );

	patches += mpInterfaceDurability;
	patches += mpInterfaceDurabilityMax;
	patches += mpDuraString;
	patches += mpHook;
	patches += mpColorHook;

	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Options

bool CPatcher_ShowTrueDurability::SetString( wchar_t *string )
{
	wcsncpy_s( dataDurabilityString, 256, string, _TRUNCATE );
	wcsncpy_s( dataFullString, 256, dataDurabilityString, _TRUNCATE );
	if ( colorEnabled ) {
		wcscat_s( dataFullString, L"</color>\nColor {4}" );
	}
	return true;
}

bool CPatcher_ShowTrueDurability::IsColorEnabled(void)
{
	return colorEnabled;
}
bool CPatcher_ShowTrueDurability::EnableColor( void )
{
	colorEnabled = true;
	wcsncpy_s( dataFullString, 256, dataDurabilityString, _TRUNCATE );
	wcscat_s( dataFullString, L"</color>\nColor {4}" );
	WriteLog("Patch option enabled: Show Item Color.\n");
	return true;
}
bool CPatcher_ShowTrueDurability::DisableColor( void )
{
	colorEnabled = false;
	wcsncpy_s( dataFullString, 256, dataDurabilityString, _TRUNCATE );
	WriteLog("Patch option disabled: Show Item Color.\n");
	return true;
}
bool CPatcher_ShowTrueDurability::ToggleColor( void )
{
	if (colorEnabled)
		return DisableColor();
	else
		return EnableColor();
}

//-----------------------------------------------------------------------------
// Hook functions

/* This replacement for IItem::GetInterfaceDurability[Max](void) performs the
 * same functions as the old, giving the same return value on EAX.  It also
 * returns the high-precision value on EDX, which is legal because the
 * __thiscall calling conventions treat EDX as a caller-save register.  This
 * allows our own code to access the high-precision value, while maintaining
 * the functionality of any existing code which may use the function.
 */

NAKED void CPatcher_ShowTrueDurability::GetDurability(void)
{
	__asm {
		MOV		EAX, DWORD PTR DS:[ECX+48h]  // EAX = item durability x1000
		PUSH	EBX       // EBX is a callee-save register -> save it!
		MOV		EBX, EAX  // EBX = item durability x1000
		ADD		EAX, 999  // EAX = item dura x1000 + 999
		XOR		EDX, EDX  // EDX = 0
		MOV		ECX, 1000 // ECX = 1000
		DIV		ECX       // EAX = (item dura+999)/1000 = item durability
		MOV		EDX, EBX  // EDX = item durability x1000
		POP		EBX       // Restore value of EBX
		RETN              // EAX = item dura, EDX = item dura x1000
	}
}

NAKED void CPatcher_ShowTrueDurability::GetDurabilityMax(void)
{
	__asm {
		MOV		EAX, DWORD PTR DS:[ECX+4Ch] // EAX = item max durability x1000
		PUSH	EBX
		MOV		EBX, EAX
		ADD		EAX, 999
		XOR		EDX, EDX
		MOV		ECX, 1000
		DIV		ECX
		MOV		EDX, EBX
		POP		EBX
		RETN
	}
}

/* Formats the three long color values into a string
 */

void __stdcall CPatcher_ShowTrueDurability::patchItemColorFormat(wchar_t * buff, long color1, long color2, long color3)
{
	swprintf_s(buff,255,L"%08lX %08lX %08lX", color1, color2, color3);
}

/* Our patch for our target function overwrites the string formatting section
 * such that it passes our own values into the string formatter.
 */

NAKED void CPatcher_ShowTrueDurability::patchDurability(void)
{
	__asm {
		// Support for item color mod
		PUSH	2
		CALL	addrGetColor
		PUSH	EAX
		PUSH	1
		CALL	addrGetColor
		PUSH	EAX
		PUSH	0
		CALL	addrGetColor
		PUSH	EAX
		PUSH	offset dataColorBuf
		CALL	patchItemColorFormat
		PUSH	offset dataColorBuf	// {4} = Formatted item color (or "")

		// Dura mod
		MOV		ECX, EDI	// EDI was the location of our IItem object -> put into ECX for __thiscall calling conventions
		CALL	GetDurabilityMax
		PUSH	EDX			// {3} = Max dura x1000
		PUSH	EAX			// {2} = Max dura

		MOV		ECX, EDI
		CALL	GetDurability
		PUSH	EDX			// {1} = Current dura x1000
		PUSH	EAX			// {0} = Current dura

		MOV		ECX, ESI	// ESI was the location of our CFormatter object -> put into ECX for __thiscall calling conventions
		CALL	addrCFormatterInsert_ulong	// Replace {0}
		MOV		ECX, EAX	// CFormatter::operator<< puts our CFormatter object back in EAX.
		CALL	addrCFormatterInsert_ulong	// Replace {1}
		MOV		ECX, EAX
		CALL	addrCFormatterInsert_ulong	// Replace {2}
		MOV		ECX, EAX
		CALL	addrCFormatterInsert_ulong	// Replace {3}
		MOV		ECX, EAX
		CALL	addrCFormatterInsert_pwchar	// Replace {4}

		// Perform patched over code and return after hook
		MOV		ECX, EAX	// Put CFormatter back in ECX
		JMP		addrTargetReturn
	}
}

/* This patch enables a different color text if at 100% dura.
 * The line of code we are replacing would call GetDurability(),
 * and compare the result to 0x0A.  We leave EAX just as expected
 * and perform the comparison.  The values of ECX and EDX are
 * irrelevant because they are caller-save registers.
 */

NAKED void CPatcher_ShowTrueDurability::patchDurabilityColor(void)
{
	__asm {
		CALL	GetDurabilityMax
		PUSH	EDX				// Push Max x1000
		MOV		ECX, EDI
		CALL	GetDurability
		POP		ECX				// EDX = Dura x1000, ECX = Max x1000
		CMP		ECX, EDX
		JE		returnPerfect
		CMP		EAX, 0x0A
		JMP		addrColorReturn // Normal or red text if dura != max dura
	returnPerfect:
		PUSH	offset dataColorString
		JMP		addrColorReturnPerfect
	}
}

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_ShowTrueDurability::ReadINI( void )
{
	if ( ReadINI_Bool( L"ShowTrueDurability" ))
	{
		if ( ReadINI_Bool( L"ShowItemColor" ))
			EnableColor();
		wchar_t buf[256];
		ReadINI_String( L"ShowTrueDurability_str", buf );
		SetString( buf );
		return Install();
	}
	return true;
}

bool CPatcher_ShowTrueDurability::WriteINI( void )
{
	WriteINI_Bool( L"ShowTrueDurability", IsInstalled() );
	WriteINI_Bool( L"ShowItemColor", IsColorEnabled() );
	return true;
}