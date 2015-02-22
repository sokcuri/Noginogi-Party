#include "Patcher_UseBitmapFonts.h"
#include "../Addr.h"

//-------------------------------------------------------------------
// Local variables
LPBYTE CPatcher_UseBitmapFonts::addrTargetReturn1 = NULL;
LPBYTE CPatcher_UseBitmapFonts::addrTargetReturn2 = NULL;
LPBYTE CPatcher_UseBitmapFonts::addrTargetReturn3 = NULL;

bool CPatcher_UseBitmapFonts::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_UseBitmapFonts::CPatcher_UseBitmapFonts( void )
{
	patchname = "비트맵 폰트 사용";

	LPBYTE addrCompiler = CAddr::Addr(CDefaultCompiler_Compile);
	LPBYTE addrTagCompiler = CAddr::Addr(CDefaultTagCompiler_Compile);
	LPBYTE addrHTMLCompiler = CAddr::Addr(CHTMLCompiler_Compile);

	if (!addrCompiler ||
		!addrTagCompiler ||
		!addrHTMLCompiler)
	{
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
		WriteLog("   종속 요소가 없습니다.\n");
		return;
	}

	// Patch for CDefaultCompiler::Compile

	vector<WORD> patchCompiler;
	vector<WORD> backupCompiler;

	backupCompiler +=
		0x80, 0xBB, 0x80, 0x00, 0x00, 0x00, 0x00,	// +40: CMP BYTE PTR [EBX+80h], 0
		0x53,										// +47: PUSH EBX
		0xFF, 0x75, 0x08,							// +48: PUSH [EBP+08h]
		0x8B, 0xCE,									// +4B: MOV ECX, ESI
		0x74, 0x07;									// +4D: JZ SHORT +0x07

	funcPointer1 = (LPBYTE)patchUseBitmapFonts1;

	patchCompiler +=
		0xFF, 0x25,
		((int)(&funcPointer1) & 0xFF),
		(((int)(&funcPointer1) & 0xFF00) >> 8),
		(((int)(&funcPointer1) & 0xFF0000) >> 16),
		(((int)(&funcPointer1) & 0xFF000000) >> 24),
		-1,
		-1,
		-1, -1, -1,
		-1, -1,
		-1, -1;
	MemoryPatch mpCompiler( addrCompiler + 0x40, patchCompiler, backupCompiler );
	
	addrTargetReturn1 = mpCompiler.GetAddr() + 0x0D;

	// Patch for CDefaultTagCompiler::Compile

	vector<WORD> patchTagCompiler;
	vector<WORD> backupTagCompiler;

	backupTagCompiler +=
		0x80, 0xBE, 0x90, 0x00, 0x00, 0x00, 0x00,	// +153: CMP BYTE PTR [ESI+90h], 0
		0x8B, 0xCE,									// +15A: MOV ECX, ESI
		0x74, 0x11;									// +15C: JZ SHORT +0x11

	funcPointer2 = (LPBYTE)patchUseBitmapFonts2;

	patchTagCompiler +=
		0xFF, 0x25,
		((int)(&funcPointer2) & 0xFF),
		(((int)(&funcPointer2) & 0xFF00) >> 8),
		(((int)(&funcPointer2) & 0xFF0000) >> 16),
		(((int)(&funcPointer2) & 0xFF000000) >> 24),
		-1,
		-1, -1,
		-1, -1;
	MemoryPatch mpTagCompiler( addrTagCompiler + 0x153, patchTagCompiler, backupTagCompiler );

	addrTargetReturn2 = mpTagCompiler.GetAddr() + 0x09;

	// Patch for CHTMLCompiler::Compile

	vector<WORD> patchHTMLCompiler;
	vector<WORD> backupHTMLCompiler;

	backupHTMLCompiler +=
		0x80, 0xBE, 0x90, 0x00, 0x00, 0x00, 0x00,	// +D6: CMP BYTE PTR [ESI+90h], 0
		0x0F, 0xB7, 0xC0,							// +DD: MOVZX EAX, AX
		0x8B, 0xCE,									// +E0: MOV ECX, ESI
		0x74, 0x0B;									// +E2: JZ SHORT +0x0B

	funcPointer3 = (LPBYTE)patchUseBitmapFonts3;

	patchHTMLCompiler +=
		0xFF, 0x25,
		((int)(&funcPointer3) & 0xFF),
		(((int)(&funcPointer3) & 0xFF00) >> 8),
		(((int)(&funcPointer3) & 0xFF0000) >> 16),
		(((int)(&funcPointer3) & 0xFF000000) >> 24),
		-1,
		-1, -1, -1,
		-1, -1,
		-1, -1;
	MemoryPatch mpHTMLCompiler( addrHTMLCompiler + 0xD6, patchHTMLCompiler, backupHTMLCompiler );

	addrTargetReturn3 = mpHTMLCompiler.GetAddr() + 0x0C;
	// Add patches

	patches += mpCompiler;
	patches += mpTagCompiler;
	patches += mpHTMLCompiler;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

NAKED void CPatcher_UseBitmapFonts::patchUseBitmapFonts1(void)
{

	if (IsPatchEnabled())
	{
		__asm {
			MOV ECX, 1
			TEST CL, CL
			CMP BYTE PTR DS:[EBX+0x80],0
			PUSH EBX
			PUSH DWORD PTR SS:[EBP+0x08]
			MOV ECX, ESI
			JMP addrTargetReturn1
		}
	}
	else
	{
		__asm {
			CMP BYTE PTR DS:[EBX+0x80],0
			PUSH EBX
			PUSH DWORD PTR SS:[EBP+0x08]
			MOV ECX,ESI
			JMP addrTargetReturn1
		}
	}
}


NAKED void CPatcher_UseBitmapFonts::patchUseBitmapFonts2(void)
{
	if (IsPatchEnabled())
	{
		__asm {
			MOV ECX, 1
			TEST CL, CL
			MOV ECX, ESI
			JMP addrTargetReturn2
		}
	}
	else
	{
		__asm {
			CMP BYTE PTR DS:[ESI+90h],0
			MOV ECX,ESI
			JMP addrTargetReturn2
		}
	}
}

NAKED void CPatcher_UseBitmapFonts::patchUseBitmapFonts3(void)
{
	__asm {
		PUSH EAX
	}
	if (IsPatchEnabled())
	{
		__asm {
			POP EAX
			MOV ECX, 1
			TEST CL, CL
			MOV ECX, ESI
			JMP addrTargetReturn3
		}
	}
	else
	{
		__asm {
			POP EAX
			CMP BYTE PTR DS:[ESI+90h],0
			MOVZX EAX,AX
			MOV ECX,ESI
			JMP addrTargetReturn3
		}
	}
}


//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_UseBitmapFonts::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_UseBitmapFonts::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_UseBitmapFonts::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_UseBitmapFonts::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_UseBitmapFonts::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_UseBitmapFonts::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_UseBitmapFonts::ReadINI( void )
{
	if ( ReadINI_Bool( L"UseBitmapFonts" ))
		return PatchEnable();
	return true;
}

bool CPatcher_UseBitmapFonts::WriteINI( void )
{
	WriteINI_Bool( L"UseBitmapFonts", IsPatchEnabled() );
	return true;
}