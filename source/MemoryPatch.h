#pragma once

#include "Main.h"

/* Format of the patch code:
 * Each byte of memory is encoded as a WORD
 * The low-order byte of the word is the memory value of that byte
 * The high-order byte of the word is a tag
 *
 * Tagging for backup code:
 * 0x00 = CHECK		-> This byte is part of the memory checking key
 * 0x?? = DEFAULT	-> This byte is not part of the key
 *
 * Tagging for patch code:
 * 0x00 = PATCH		-> This byte should be written to memory at patch time
 * 0x?? = ADDRESS	-> PatchRelativeAddress() should rewrite bytes with this tag
 *						with a relative address to the supplied target
 * 0x?? = IGNORE	-> This byte should not be written to memory at patch time
 *
 * -1 is equivalent to 0xFFFF, which is an ignored byte.
 */

class MemoryPatch
{
public:
	MemoryPatch(LPBYTE Address, vector<WORD> Patch, vector<WORD> Backup) {
		addr = Address;
		patch = Patch;
		backup = Backup;
	}

	bool Check();
	bool Apply();
	bool Revert();
	bool Search( wchar_t *dllFile );
	bool PatchDWord( BYTE tag, DWORD dword );
	bool PatchExactAddress( BYTE tag, LPBYTE address );
	bool PatchRelativeAddress( BYTE tag, LPBYTE address );
	static void ReadMem(LPVOID lpAddress, LPVOID lpBuffer, SIZE_T nSize);

	LPBYTE GetAddr() { return addr; }
	vector<WORD> GetPatch() { return patch; }
	vector<WORD> GetBackup() { return backup; }

	void SetAddr( LPBYTE Address ) { addr = Address; }
	void SetPatch( vector<WORD> Patch ) { patch = Patch; }
	void SetBackup( vector<WORD> Backup ) { backup = Backup; }

	void Dump( void );

private:
	static void WriteMem(LPVOID lpAddress, LPVOID lpBuffer, SIZE_T nSize);
	LPBYTE addr;
	vector<WORD> patch;
	vector<WORD> backup;
};