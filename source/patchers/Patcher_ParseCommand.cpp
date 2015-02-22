#include "Patcher_ParseCommand.h"
#include "../Addr.h"

//-----------------------------------------------------------------------------
// Static variable initialization
LPBYTE CPatcher_ParseCommand::addrParseCommand = NULL;
LPBYTE CPatcher_ParseCommand::addrTargetReturn = NULL;

LPBYTE CPatcher_ParseCommand::addrCString_wchar = NULL;
LPBYTE CPatcher_ParseCommand::addrCLocalizeInstance = NULL;
LPBYTE CPatcher_ParseCommand::addrCLocalizeGetLocalText = NULL;
LPBYTE CPatcher_ParseCommand::addrCFormatterGetString = NULL;
LPBYTE CPatcher_ParseCommand::addrCFormatterRelease = NULL;
LPBYTE CPatcher_ParseCommand::addrStdapi_ShowChattingMessage = NULL;
LPBYTE CPatcher_ParseCommand::addrESL_package_file_item = NULL;
//-----------------------------------------------------------------------------
// Constructor
CPatcher_ParseCommand::CPatcher_ParseCommand(void)
{
	patchname = "User Parsing Command";
    
	addrParseCommand = CAddr::Addr(CUserConsoleMgr_ParseCommand);
	addrCString_wchar = CAddr::Addr(CStringTUni_wchar);
	addrCLocalizeInstance = CAddr::Addr(CLocalizer_Instance);
	addrCLocalizeGetLocalText = CAddr::Addr(CLocalizer_GetLocalText);
	addrCFormatterGetString = CAddr::Addr(CFormatter_GetString);
	addrCFormatterRelease = CAddr::Addr(CFormatter_Release);
	addrStdapi_ShowChattingMessage = CAddr::Addr(stdapi_ShowChattingMessage);
	addrESL_package_file_item = CAddr::Addr(ESL_package_file_item);

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0xC6, 0x45, 0xFC, 0x02,				// +65: MOV BYTE PTR SS:[EBP-4],2
		0xFF, 0x15, -1, -1, -1, -1,			// +69: CALL xxxxxxxx
		0x8D, 0x4D, 0xEC,					// +6F: LEA ECX,DWORD PTR SS:[EBP-14]
		0x8A, 0xD8,							// +72: MOV BL,AL
		0xC6, 0x45, 0xFC, 0x01,				// +74: MOV BYTE PTR SS:[EBP-4],1
		0xFF, 0xD6;							// +78: CALL ESI

	pt = (int *)&patchParseCommand;

	patch +=
		-1, -1, -1, -1,
		-1, 0x25,
		((int)(&pt) & 0xFF),
		(((int)(&pt) & 0xFF00) >> 8),
		(((int)(&pt) & 0xFF0000) >> 16),
		(((int)(&pt) & 0xFF000000) >> 24),
		-1, -1, -1,
		-1, -1,
		-1, -1, -1, -1,
		-1, -1;

	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"Pleione.dll" );
	
	addrTargetReturn = (LPBYTE)(mp.GetAddr() + 0x0A);

	patches += mp;
	if (CheckPatches())
		WriteLog("패치 초기화 완료: %s.\n", patchname.c_str());
	else
		WriteLog("패치 초기화 실패: %s.\n", patchname.c_str());
}

NAKED void CPatcher_ParseCommand::patchParseCommand(void)
{
	__asm {
		CALL		addrParseCommand

		// 로그 남기기
		PUSH		EAX
		PUSH		EDX
		CALL		WriteLog

		// 채팅창 로그 남기기
		MOV		EDI, addrCString_wchar
		PUSH	0x63CFA248					// PUSH (채팅줄에 표시할 메세지)
		LEA		ECX,DWORD PTR SS:[EBP-0x24]
		CALL	EDI
		LEA		EAX,DWORD PTR SS:[EBP-0x24]
		PUSH	EAX
		LEA		EAX,DWORD PTR SS:[EBP-0x118]
		PUSH	EAX
		MOV		BYTE PTR SS:[EBP-4],4
		CALL	addrCLocalizeInstance
		MOV		ECX,EAX
		CALL	addrCLocalizeGetLocalText
		LEA		ECX,DWORD PTR SS:[EBP+0x2C]
		PUSH	ECX
		MOV		ECX,EAX
		MOV		BYTE PTR SS:[EBP-0x4],5
		CALL	addrCFormatterGetString
		PUSH	0x63CFA008					// PUSH UNICODE "<SYSTEM>"
		LEA		ECX,DWORD PTR SS:[EBP-0x50]
		MOV		BYTE PTR SS:[EBP-0x4],6
		CALL	EDI
		MOV		EAX,DWORD PTR DS:[ESI+0xC8]
		MOV		ESI,DWORD PTR DS:[ESI+0xCC]
		PUSH	EBX
		PUSH	EBX
		PUSH	0xFFFF8080
		LEA		ECX,DWORD PTR SS:[EBP+0x2C]
		PUSH	ECX
		LEA		ECX,DWORD PTR SS:[EBP-0x50]
		PUSH	ECX
		PUSH	ESI
		PUSH	EAX
		MOV		BYTE PTR SS:[EBP-0x4],7
		CALL	addrStdapi_ShowChattingMessage
		MOV		ESI,addrESL_package_file_item
		ADD		ESP,0x1C
		LEA		ECX,DWORD PTR SS:[EBP-0x50]
		MOV		BYTE PTR SS:[EBP-0x4],6
		CALL	ESI
		LEA		ECX,DWORD PTR SS:[EBP+0x2C]
		MOV		BYTE PTR SS:[EBP-0x4],5
		CALL	ESI
		LEA		ECX,DWORD PTR SS:[EBP-0x118]
		MOV		BYTE PTR SS:[EBP-0x4],4
		CALL	addrCFormatterRelease
		LEA		ECX,DWORD PTR SS:[EBP-0x24]
		MOV		BYTE PTR SS:[EBP-0x4],0
		CALL	ESI

		// pleione code로 돌아가기
		JMP		addrTargetReturn

	}
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_ParseCommand::ReadINI( void )
{
	if ( ReadINI_Bool( L"UserParsingCommand" ))
		return Install();
	return true;
}

bool CPatcher_ParseCommand::WriteINI( void )
{
	WriteINI_Bool( L"UserParsingCommand", IsInstalled() );
	return true;
}