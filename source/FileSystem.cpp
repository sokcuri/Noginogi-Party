#include "FileSystem.h"

wstring g_iniFile;

//--------------------------------------------------------------
// System directory functions
// From chris & syoka's source code

wstring GetCurPath()   
{   
	wstring buff,path;
	wchar_t b[MAX_PATH];
	GetModuleFileNameW(NULL,b,MAX_PATH); 
	buff=b;
	path=buff.substr(0,buff.rfind(L'\\'));
	return(path);  
}

wstring GetSysDir()
{
	wchar_t buff[255];
	int i=GetSystemDirectory(buff,255);
	if(i!=0)
	{
		return(buff);
	}
	else
	{
		return(L"");
	}
}

//--------------------------------------------------------------
// Log file functions
// From chris & syoka's source code

void WriteLog( const char* format, ... )
{
	va_list	valist;
	FILE *fp;
	char buf1[32],buf2[32];

#if _MSC_VER >= 1400 // .NET2005
	if( fopen_s( &fp, ".\\nogi_partylog.txt", "a" ) )
		return;
	_strdate_s( buf1, 32 );
	_strtime_s( buf2, 32 );
#else
	fp = fopen( ".\\nogi_partylog.txt", "a" );
	if( fp == NULL )
		return;
	_strdate( buf1 );
	_strtime( buf2 );
#endif

	fprintf( fp, "[%s %s] - ", buf1, buf2 );

	va_start( valist, format );
	vfprintf( fp, format, valist );
	va_end( valist );
	fclose(fp);

}

void DebugLog( const char* format, ... )
{
	uint usingDebug = GetPrivateProfileInt(L"PATCH", L"Debug", 0, g_iniFile.c_str());
	if (usingDebug) {
		va_list	valist;
		FILE *fp;
		char buf1[32],buf2[32];

#if _MSC_VER >= 1400 // .NET2005
		if( fopen_s( &fp, ".\\nogi_partylog.txt", "a" ) )
			return;
		_strdate_s( buf1, 32 );
		_strtime_s( buf2, 32 );
#else
		fp = fopen( ".\\nogi_partylog.txt", "a" );
		if( fp == NULL )
			return;
		_strdate( buf1 );
		_strtime( buf2 );
#endif

		fprintf( fp, "[%s %s] - ", buf1, buf2 );

		va_start( valist, format );
		vfprintf( fp, format, valist );
		va_end( valist );
		fclose(fp);
	}
}

//--------------------------------------------------------------
// Ini file functions

bool ReadINI_Bool(const wchar_t *key)
{
	uint patchOn = GetPrivateProfileInt(L"PATCH", key, 0, g_iniFile.c_str());
	if (patchOn==0) {
		DebugLog("%ls off\n", key);
		return false;
	}
	DebugLog("%ls on\n", key);
	return true;
}

bool ReadINI_String(const wchar_t *key, wchar_t *buf)
{
	int n = GetPrivateProfileString(L"PATCH", key, NULL, buf, 255, g_iniFile.c_str());
	if (n == 0) {
		DebugLog("%ls undefined\n", key);
		return false;
	}

	//DebugLog("%ls = \"%ls\"\n", key, buf);

	return true;
}

int ReadINI_Int(const wchar_t *key, uint min, uint max)
{
	uint patchSetting = GetPrivateProfileInt(L"PATCH", key, 0, g_iniFile.c_str());
	if ((patchSetting < min) || (patchSetting > max)) {
		DebugLog("%ls off\n", key);
		return 0;
	}

	//DebugLog("%ls = %u\n", key, patchSetting);

	return patchSetting;
}

int ReadINI_Int(const wchar_t *key, uint min, uint max, uint def)
{
	uint patchSetting = GetPrivateProfileInt(L"PATCH", key, 0, g_iniFile.c_str());
	if ((patchSetting < min) || (patchSetting > max)) {
		DebugLog("%ls default = %u\n", key, def);
		return def;
	}

	//DebugLog("%ls = %u\n", key, patchSetting);

	return patchSetting;
}

bool WriteINI_Bool(const wchar_t *key, bool value)
{
	/*
	wchar_t buf[8];
	wsprintf(buf, L"%s", (value)?"1":"0");
	WritePrivateProfileString(L"PATCH", key, buf, g_iniFile.c_str());
	DebugLog("%ls=%ls written to INI.\n", key, buf);
	*/
	return true;
}

bool WriteINI_String(const wchar_t *key, wchar_t *buf)
{
	/*
	WritePrivateProfileString(L"PATCH", key, buf, g_iniFile.c_str());
	DebugLog("%ls=%ls written to INI.\n", key, buf);
	*/
	return true;
}

bool WriteINI_Int(const wchar_t *key, uint value)
{
	/*
	wchar_t buf[8];
	wsprintf(buf, L"%d", value);
	WritePrivateProfileString(L"PATCH", key, buf, g_iniFile.c_str());
	DebugLog("%ls=%ls written to INI.\n", key, buf);
	*/
	return true;
}