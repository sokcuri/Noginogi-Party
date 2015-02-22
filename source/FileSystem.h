#pragma once
#include "main.h"

wstring GetCurPath();
wstring GetSysDir();

void WriteLog( const char* format, ... );
void DebugLog( const char* format, ... );

bool ReadINI_Bool(const wchar_t *key);
bool ReadINI_String(const wchar_t *key, wchar_t *buf);
int ReadINI_Int(const wchar_t *key, uint min, uint max);
int ReadINI_Int(const wchar_t *key, uint min, uint max, uint def);

bool WriteINI_Bool(const wchar_t *key, bool value);
bool WriteINI_String(const wchar_t *key, wchar_t *buf);
bool WriteINI_Int(const wchar_t *key, uint value);

extern wstring g_iniFile;