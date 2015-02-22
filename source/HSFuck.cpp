#include <windows.h>
#include <stdio.h>
#include <psapi.h>


#define inline_hook(fnOld, fnNew) \
 do {\
  DWORD oldp;\
  VirtualProtect((LPVOID)fnOld, 5, PAGE_READWRITE, &oldp);\
  *(unsigned char *)fnOld = 0xE9;\
  *(unsigned long *)((unsigned char *)fnOld + 1) = (unsigned long)fnNew - (unsigned long)fnOld - 5;\
  VirtualProtect((LPVOID)fnOld, 5, PAGE_READWRITE, &oldp);\
 } while (0)

HMODULE KERNEL32;

FARPROC p_CreateMutexA;
FARPROC p_FindResourceW;

__declspec(naked) HRSRC WINAPI old_FindResourceW(HMODULE hModule, LPCWSTR lpName, LPCWSTR lpType)
{
	__asm
	{
		ENTER 0,0
		MOV EAX, p_FindResourceW
		ADD EAX, 5
		JMP EAX
	}
}

HRSRC WINAPI new_FindResourceW(HMODULE hModule, LPCWSTR lpName, LPCWSTR lpType)
{
	return 0;
	/*LPSTR lpszBaseName;
	BOOL  bSkip = FALSE;

	return 0;
	if (hModule != NULL)
	{
		lpszBaseName = (LPSTR)HeapAlloc(GetProcessHeap(), 0, MAX_PATH);
		if (lpszBaseName != NULL)
		{
			if (GetModuleBaseNameA(GetCurrentProcess(), hModule, lpszBaseName, MAX_PATH) != 0)
				if (lstrcmpiW(lpszBaseName, L"EHSvc.dll") == 0)
				{
					if (!IS_INTRESOURCE(lpType))
						if (lstrcmpiW(lpType, L"BINRES") == 0)
							bSkip = TRUE;
				}
			HeapFree(GetProcessHeap(), 0, (LPVOID)lpszBaseName);
		}
	}
	if (bSkip)
	{
		SetLastError(ERROR_RESOURCE_DATA_NOT_FOUND); // random FindResource error
		return NULL;
	}
	else
		return old_FindResourceA(hModule, lpName, lpType);*/
}

HANDLE WINAPI new_CreateMutexA(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCSTR lpName)
{
	WCHAR _lpName[256];
	LPCWSTR __lpName = NULL;

	if(lpName && strstr(lpName, "HxFV`rZxF"))
		lpName = NULL;

	if(lpName) {
		MultiByteToWideChar(CP_ACP, 0, lpName, -1, _lpName, 1000);
		__lpName = _lpName;
	}

	return CreateMutexW(lpMutexAttributes, bInitialOwner, __lpName);
}

void HSFuckInit()
{
	KERNEL32 = LoadLibraryA("kernel32");
	//p_FindResourceW = GetProcAddress(KERNEL32, "FindResourceW");
	p_CreateMutexA = GetProcAddress(KERNEL32, "CreateMutexA");

	//inline_hook(p_FindResourceW, new_FindResouceW);
	inline_hook(p_CreateMutexA, new_CreateMutexA);
}