#include "Patcher_EnableNameColoring.h"
#include "../Addr.h"

//-----------------------------------------------------------------------------
// Static variable initialization

LPBYTE CPatcher_EnableNameColoring::addrTarget = NULL;
LPBYTE CPatcher_EnableNameColoring::addrIsElf = NULL;
LPBYTE CPatcher_EnableNameColoring::addrIsGiant = NULL;
LPBYTE CPatcher_EnableNameColoring::addrIsPet = NULL;
LPBYTE CPatcher_EnableNameColoring::addrIsNPC = NULL;
LPBYTE CPatcher_EnableNameColoring::addrIsGoodNPC = NULL;

unsigned long CPatcher_EnableNameColoring::CVHuman1;
unsigned long CPatcher_EnableNameColoring::CVHuman2;
unsigned long CPatcher_EnableNameColoring::CVElf1;
unsigned long CPatcher_EnableNameColoring::CVElf2;
unsigned long CPatcher_EnableNameColoring::CVGiant1;
unsigned long CPatcher_EnableNameColoring::CVGiant2;
unsigned long CPatcher_EnableNameColoring::CVPet1;
unsigned long CPatcher_EnableNameColoring::CVPet2;
unsigned long CPatcher_EnableNameColoring::CVNPC1;
unsigned long CPatcher_EnableNameColoring::CVNPC2;
unsigned long CPatcher_EnableNameColoring::CVEnemy1;
unsigned long CPatcher_EnableNameColoring::CVEnemy2;

bool CPatcher_EnableNameColoring::PatchEnabled = false;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_EnableNameColoring::CPatcher_EnableNameColoring( void )
{
	patchname = "이름 컬러링";

	addrIsElf = CAddr::Addr(ICharacter_IsElf);
	addrIsGiant = CAddr::Addr(ICharacter_IsGiant);
	addrIsPet = CAddr::Addr(ICharacter_IsPet);
	addrIsNPC = CAddr::Addr(ICharacter_IsNPC);
	addrIsGoodNPC = CAddr::Addr(ICharacter_IsGoodNPC);

	if (!addrIsElf   ||
		!addrIsGiant ||
		!addrIsPet   ||
		!addrIsNPC   ||
		!addrIsGoodNPC)
	{
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
		WriteLog("   종속 요소가 없습니다.\n");
		return;
	}

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0xEB, 0x0E,									// +53: JMP SHORT +0E
		0xC7, 0x46, 0x58, 0xFF, 0x66, 0x33, 0xFF,	// +55: MOV DWORD PTR DS:[ESI+58h], 0xFF3366FF
		0xC7, 0x46, 0x5C, 0xFF, 0x66, 0x33, 0x30,	// +5C: MOV DWORD PTR DS:[ESI+5Ch], 0x303366FF
		0x8B, 0xCF,									// +63: MOV ECX, EDI
		0xFF, 0x15,	-1, -1, -1, -1;					// +65: CALL xxxxxxxx (core::ICharacter::IsNPC)

	funcPointer = (LPBYTE)patchNameColoring;

	patch +=
		-1, -1,
		-1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1,
		-1, -1,
		0xFF, 0x15,
		((int)(&funcPointer) & 0xFF),
		(((int)(&funcPointer) & 0xFF00) >> 8),
		(((int)(&funcPointer) & 0xFF0000) >> 16),
		(((int)(&funcPointer) & 0xFF000000) >> 24);


	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"Pleione.dll" );
	//mp.PatchExactAddress( 0x01, (LPBYTE)patchNameOfMod );
	//mp.PatchRelativeAddress( 0x01, (LPBYTE)patchNameOfMod );
	
	patches += mp;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_EnableNameColoring::patchNameColoring(void)
{
	// 패치가 활성화 되어 있으면..
	if (IsPatchEnabled())
	{
		__asm {

			MOV		ECX, EDI
			CALL	addrIsGoodNPC
			TEST	AL, AL
			JNE SHORT LblGoodNPC

			MOV		ECX,EDI
			CALL	addrIsNPC
			TEST	AL, AL
			JNE SHORT LblEnemy

			MOV		ECX, EDI
			CALL	addrIsElf
			TEST	AL, AL
			JNE SHORT LblElf

			MOV		ECX, EDI
			CALL	addrIsGiant
			TEST	AL, AL
			JNE SHORT LblGiant
			
			MOV		ECX, EDI
			CALL	addrIsPet
			TEST	AL, AL
			JNE SHORT LblPet
			JMP SHORT LblHuman

		LblHuman:
			MOV		EAX, DWORD PTR DS:[CVHuman1]
			MOV		DWORD PTR DS:[ESI+58h], EAX
			MOV		EAX, DWORD PTR DS:[CVHuman2]
			MOV		DWORD PTR DS:[ESI+5Ch], EAX
			JMP		LblEnd
		LblElf:
			MOV		EAX, DWORD PTR DS:[CVElf1]
			MOV		DWORD PTR DS:[ESI+58h], EAX
			MOV		EAX, DWORD PTR DS:[CVElf2]
			MOV		DWORD PTR DS:[ESI+5Ch], EAX
			JMP		LblEnd
		LblGiant:
			MOV		EAX, DWORD PTR DS:[CVGiant1]
			MOV		DWORD PTR DS:[ESI+58h], EAX
			MOV		EAX, DWORD PTR DS:[CVGiant2]
			MOV		DWORD PTR DS:[ESI+5Ch], EAX
			JMP		LblEnd
		LblPet:
			MOV		EAX, DWORD PTR DS:[CVPet1]
			MOV		DWORD PTR DS:[ESI+58h], EAX
			MOV		EAX, DWORD PTR DS:[CVPet2]
			MOV		DWORD PTR DS:[ESI+5Ch], EAX
			JMP		LblEnd
		LblGoodNPC:
			MOV		EAX, DWORD PTR DS:[CVNPC1]
			MOV		DWORD PTR DS:[ESI+58h], EAX
			MOV		EAX, DWORD PTR DS:[CVNPC2]
			MOV		DWORD PTR DS:[ESI+5Ch], EAX
			JMP		LblEnd
		LblEnemy:
			MOV		EAX, DWORD PTR DS:[CVEnemy1]
			MOV		DWORD PTR DS:[ESI+58h], EAX
			MOV		EAX, DWORD PTR DS:[CVEnemy2]
			MOV		DWORD PTR DS:[ESI+5Ch], EAX
			JMP		LblEnd

		LblEnd:
			MOV		ECX, EDI
			//CALL	addrIsNPC
			MOV		EAX, 1
			RETN
		}
	}
	// 패치가 비활성화 상태 -> IsNPC~~ JMP
	else
	{
		__asm
		{
			//JMP		addrIsNPC
			MOV		EAX, 1
			RETN
		}
	}
}

//-----------------------------------------------------------------------------
// 오버라이드 함수

bool CPatcher_EnableNameColoring::Uninstall( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

bool CPatcher_EnableNameColoring::Toggle( void ) {
	// 이 모드는 한번 설치하면 제거할 수 없습니다
	return false;
}

//-----------------------------------------------------------------------------
// 패치 토글 함수

bool CPatcher_EnableNameColoring::IsPatchEnabled(void)
{
	if (PatchEnabled == true)
		return true;
	else return false;
}

bool CPatcher_EnableNameColoring::PatchEnable(void)
{
	PatchEnabled = true;
	return true;
}

bool CPatcher_EnableNameColoring::PatchDisable(void)
{
	PatchEnabled = false;
	return true;
}

bool CPatcher_EnableNameColoring::PatchToggle(void)
{
	if (IsPatchEnabled())
		PatchDisable();
	else PatchEnable();
	return true;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_EnableNameColoring::ReadINI( void )
{
	wchar_t buf[256];
	wchar_t *endptr = NULL;

	ReadINI_String(L"CVHuman1", buf);
	CVHuman1 = wcstoul( buf, &endptr, 16);
	ReadINI_String(L"CVHuman2", buf);
	CVHuman2 = wcstoul( buf, &endptr, 16);

	WriteLog("CVHuman1: #%08X\n", CVHuman1);
	WriteLog("CVHuman2: #%08X\n", CVHuman2);

	ReadINI_String(L"CVElf1", buf);
	CVElf1 = wcstoul( buf, &endptr, 16);
	ReadINI_String(L"CVElf2", buf);
	CVElf2 = wcstoul( buf, &endptr, 16);

	WriteLog("CVElf1: #%08X\n", CVElf1);
	WriteLog("CVElf2: #%08X\n", CVElf2);

	ReadINI_String(L"CVGiant1", buf);
	CVGiant1 = wcstoul( buf, &endptr, 16);
	ReadINI_String(L"CVGiant2", buf);
	CVGiant2 = wcstoul( buf, &endptr, 16);

	WriteLog("CVGiant1: #%08X\n", CVGiant1);
	WriteLog("CVGiant2: #%08X\n", CVGiant2);

	ReadINI_String(L"CVPet1", buf);
	CVPet1 = wcstoul( buf, &endptr, 16);
	ReadINI_String(L"CVPet2", buf);
	CVPet2 = wcstoul( buf, &endptr, 16);

	WriteLog("CVPet1: #%08X\n", CVPet1);
	WriteLog("CVPet2: #%08X\n", CVPet2);

	ReadINI_String(L"CVNPC1", buf);
	CVNPC1 = wcstoul( buf, &endptr, 16);
	ReadINI_String(L"CVNPC2", buf);
	CVNPC2 = wcstoul( buf, &endptr, 16);

	WriteLog("CVNPC1: #%08X\n", CVNPC1);
	WriteLog("CVNPC2: #%08X\n", CVNPC2);

	ReadINI_String(L"CVEnemy1", buf);
	CVEnemy1 = wcstoul( buf, &endptr, 16);
	ReadINI_String(L"CVEnemy2", buf);
	CVEnemy2 = wcstoul( buf, &endptr, 16);

	WriteLog("CVEnemy1: #%08X\n", CVEnemy1);
	WriteLog("CVEnemy2: #%08X\n", CVEnemy2);


	if ( ReadINI_Bool( L"EnableNameColoring" ))
		return PatchEnable();
	return true;
}

bool CPatcher_EnableNameColoring::WriteINI( void )
{
	WriteINI_Bool( L"EnableNameColoring", IsPatchEnabled() );
	return true;
}