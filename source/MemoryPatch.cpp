#include "MemoryPatch.h"
#include "FileSystem.h"

//----------------------------------------------------------------------------
// Member functions

bool MemoryPatch::Check()
{
	if ( addr == NULL )
	{
		return false;
	}
	for ( uint i = 0; i < backup.size(); i++ ) {
		if (HIBYTE(backup[i]) == 0x00) {				// If the byte is tagged to be checked...
			if (LOBYTE(backup[i]) != addr[i]) {			// Then compare it to the byte in memory
/*
					DebugLog(
					"ERROR: Patch check failed on byte %d | Key: %04X Found: %02X\n",
					i, backup[i], addr[i] );
*/
				DebugLog("에러: 패치 체크를 실패했습니다. (x: %04X, y: %02X)\n", backup[i], addr[i]);

				return false;
			}
		}
	}
	return true;
}

bool MemoryPatch::Apply()
{
	if ( patch.size() != backup.size() )
	{

		//DebugLog("ERROR: Patch and backup size do not match.\n");

		DebugLog("에러: 패치 패턴 사이즈가 맞지 않습니다.\n");

		return false;
	}
	BYTE bufBackup, bufPatch;
	for ( uint i = 0; i < patch.size(); i++ ) {
		if (HIBYTE(patch[i]) == 0x00) {					// If the byte is tagged to patch in the patch code...
			ReadMem((LPVOID)(addr + i), &bufBackup, 1);	// Then read the byte from memory
			backup[i] = (WORD)bufBackup;				// And store it in the backup
			bufPatch = LOBYTE(patch[i]);				// Then load the byte from the patch code
			WriteMem((LPVOID)(addr + i), &bufPatch, 1);	// And write it into memory
		}
	}
	return true;
}

bool MemoryPatch::Revert()
{
	if ( patch.size() != backup.size() ) {


		//DebugLog("ERROR: Patch and backup size do not match.\n");

		DebugLog("에러: 패치 패턴 사이즈가 맞지 않습니다.\n");

		return false;
	}
	BYTE bufPatch;
	for ( uint i = 0; i < backup.size(); i++ ) {
		if (HIBYTE(patch[i]) == 0x00) {					// If the byte is tagged to patch in the patch code...
			bufPatch = LOBYTE(backup[i]);				// Then load the byte from the backup code
			WriteMem((LPVOID)(addr + i), &bufPatch, 1);	// And write it back to memory
		}
	}
	return true;
}

bool MemoryPatch::Search( wchar_t *dllFile )
{
	HMODULE dllModule = GetModuleHandle( dllFile );
	if ( dllModule == NULL )
	{
		//DebugLog("ERROR: GetModuleHandle call failed on %ls.\n", dllFile);

		DebugLog("에러: %ls 파일의 GetModuleHandle에 실패했습니다.\n", dllFile);

		return false;
	}
	MODULEINFO dllInfo;
	GetModuleInformation( GetCurrentProcess(), dllModule, &dllInfo, sizeof(dllInfo) );

	// See: http://en.wikipedia.org/wiki/Boyer-Moore-Horspool_algorithm
	// Slightly modified to enable wildcards (decreases the default skip length)
	uint i;
	int scan;
	LPBYTE p;

	uint defaultSkipLength;
	uint skipLength[UCHAR_MAX + 1];
	uint searchSuccessCount;

	// Find total length of patch, ignoring wildcards at the end of the search
	// If we did not ignore these wildcards, then we would have a default skip
	// length of 1!
	uint backupEnd = backup.size() - 1;
	while ((HIBYTE(backup[backupEnd]) != 0x00) && (backupEnd > 0)) {
		backupEnd--;
	}

	// Find default skip length, based on wildcards (modification to algorithm)
	defaultSkipLength = backupEnd;
	for ( i = 0; i < backupEnd; i++ ) {
		if (HIBYTE(backup[i]) != 0x00) {
			defaultSkipLength = backupEnd - i;
		}
	}

	// Set default skip length for all possible bytes
	for ( i = 0; i < UCHAR_MAX + 1; i++ ) {
		skipLength[i] = defaultSkipLength;
	}

	// Preprocess skip lengths for each byte found in the patch
	for ( i = 0; i < backupEnd; i++ ) {
		if (HIBYTE(backup[i]) == 0x00) {
			skipLength[LOBYTE(backup[i])] = backupEnd - i;
		}
	}

	searchSuccessCount = 0;
	p = (LPBYTE)dllInfo.lpBaseOfDll;
	LPBYTE searchEnd = (LPBYTE)dllInfo.lpBaseOfDll + dllInfo.SizeOfImage;

	while (p + backup.size() < searchEnd) {
		scan = backupEnd;
		while (scan >= 0) {
			if ((HIBYTE(backup[scan]) == 0x00) && (LOBYTE(backup[scan]) != p[scan])) {
				break;
			}
			if ( scan == 0 ) // Found a successful patch!
			{

				DebugLog("패치 타켓을 0x%08X에서 찾았습니다.\n", p);

				addr = p;
				searchSuccessCount++;
				return true;
			}
			scan--;
		}
		p += skipLength[p[backupEnd]];
	}

	if ( searchSuccessCount == 0 )
	{

		//DebugLog("ERROR: Patch search failed within %ls.\n", dllFile);

		DebugLog("에러: %ls 파일에서 패치 값을 찾는데 실패했습니다.\n", dllFile);

		addr = NULL;
		return false;
	}

	if ( searchSuccessCount > 1 )
	{

		//DebugLog("ERROR: Patch search returned multiple results within %ls.\n", dllFile);

		DebugLog("에러: %ls 파일에서 다수의 패치 값이 검색되었습니다.\n", dllFile);

		addr = NULL;
		return false;
	}

	return true;
}

bool MemoryPatch::PatchDWord( BYTE tag, DWORD dword )
{
	for ( uint i = 0; i < patch.size(); i++ ) {
		if (HIBYTE(patch[i]) == tag) {					// If the byte is tagged as the given tag...

			if ( i+3 >= patch.size() )	// Check for invalid tag -> overrun
				return false;

			patch[i]   = (WORD)LOBYTE(LOWORD(dword));	// Store the address in the patch code
			patch[i+1] = (WORD)HIBYTE(LOWORD(dword));	// in little-endian order
			patch[i+2] = (WORD)LOBYTE(HIWORD(dword));	// (because x86 wasn't annoying enough
			patch[i+3] = (WORD)HIBYTE(HIWORD(dword));	// without being encoded in LE...!)
		}
	}
	return true;
}

bool MemoryPatch::PatchExactAddress( BYTE tag, LPBYTE targetAddress )
{
	return PatchDWord( tag, (DWORD)targetAddress );
}

bool MemoryPatch::PatchRelativeAddress( BYTE tag, LPBYTE targetAddress )
{
	for ( uint i = 0; i < patch.size(); i++ ) {
		if (HIBYTE(patch[i]) == tag) {	// If the byte is tagged as the given tag...

			if ( i+3 >= patch.size() )	// Check for invalid tag -> overrun
				return false;

			// Then calculate the relative address based off of this position.
			// Note: the address is relative to the instruction FOLLOWING the relative jump
			// which means we have to calculate based off of i+4 (since the instruction is assumed
			// to end after the encoded address!)
			// Ex.  E9 xx xx xx xx 90 90 90
			//                     ^^ relative to this address

			LPBYTE relativeOffset = (LPBYTE)(targetAddress - (addr+i+4));
			patch[i]   = (WORD)LOBYTE(LOWORD(relativeOffset));	// Store the address in the patch code
			patch[i+1] = (WORD)HIBYTE(LOWORD(relativeOffset));	// in little-endian order
			patch[i+2] = (WORD)LOBYTE(HIWORD(relativeOffset));	// (because x86 wasn't hard enough
			patch[i+3] = (WORD)HIBYTE(HIWORD(relativeOffset));	// without being encoded in LE)
		}
	}
	return true;
}

void MemoryPatch::Dump( void )
{
	if ( addr == NULL )
		return;

	for ( LPBYTE i = (LPBYTE)((int)addr & 0xFFFFFFF0);
		i <= addr + patch.size();
		i += 0x10 )
	{
		
		DebugLog( "  %08X | %02X %02X %02X %02X %02X %02X %02X %02X   %02X %02X %02X %02X %02X %02X %02X %02X\n",
			i, *(i+0), *(i+1), *(i+2), *(i+3), *(i+4), *(i+5), *(i+6), *(i+7),
			*(i+8), *(i+9), *(i+10), *(i+11), *(i+12), *(i+13), *(i+14), *(i+15));

	}
}

//----------------------------------------------------------------------------
// Static functions

void MemoryPatch::WriteMem(LPVOID lpAddress, LPVOID lpBuffer, SIZE_T nSize)
{
	DWORD OldProtect, OldProtect2;
	VirtualProtect(lpAddress, nSize, PAGE_READWRITE, &OldProtect);
	memcpy(lpAddress, lpBuffer, nSize);
	VirtualProtect(lpAddress, nSize, OldProtect, &OldProtect2);
}

void MemoryPatch::ReadMem(LPVOID lpAddress, LPVOID lpBuffer, SIZE_T nSize)
{
	DWORD OldProtect, OldProtect2;
	VirtualProtect(lpAddress, nSize, PAGE_READWRITE, &OldProtect);
	memcpy(lpBuffer, lpAddress, nSize);
	VirtualProtect(lpAddress, nSize, OldProtect, &OldProtect2);
}