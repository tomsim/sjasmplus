/* 

  SjASMPlus Z80 Cross Compiler

  This is modified sources of SjASM by Aprisobal - aprisobal@tut.by

  Copyright (c) 2006 Sjoerd Mastijn

  This software is provided 'as-is', without any express or implied warranty.
  In no event will the authors be held liable for any damages arising from the
  use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it freely,
  subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not claim
	 that you wrote the original software. If you use this software in a product,
	 an acknowledgment in the product documentation would be appreciated but is
	 not required.

  2. Altered source versions must be plainly marked as such, and must not be
	 misrepresented as being the original software.

  3. This notice may not be removed or altered from any source distribution.

*/

#ifndef SJASMPLUS_SJIO_H
#define SJASMPLUS_SJIO_H

#include <boost/filesystem.hpp>
#include "sjdefs.h"
#include "errors.h"


namespace fs = boost::filesystem;

#define PAGESIZE 0x4000 /* added */

extern aint PreviousAddress, epadres;

#define OUTPUT_TRUNCATE 0
#define OUTPUT_REWIND 1
#define OUTPUT_APPEND 2

// void OpenDest(int); /* added from new SjASM 0.39g */
// void NewDest(const fs::path &newfilename, int mode); /* added from new SjASM 0.39g */

void ListFile();

void ListFileSkip(char *);

// void CheckPage(); /* added */
void EmitByte(uint8_t byte);

void EmitWord(uint16_t word);

void EmitBytes(int *bytes);

void EmitWords(int *words);

void EmitBlock(aint byte, aint len, bool nulled = false);

void OpenFile(const fs::path &nfilename);

void IncludeFile(const fs::path &nfilename);

void Close();

void OpenList();

void ReadBufLine(bool Parse = true, bool SplitByColon = true); /* added */
// void OpenDest();

void PrintHEX32(char *&p, aint h);

void PrintHEX16(char *&p, aint h); /* added */
void PrintHEXAlt(char *&p, aint h); /* added */


fs::path GetAbsPath(const fs::path &p);

fs::path getAbsPath(const fs::path &p, fs::path &f);

// char *GetPath(const char *fname, TCHAR **filenamebegin); /* added */
void BinIncFile(const fs::path &fname, int offset, int length);

int SaveRAM(fs::ofstream &ofs, int, int);

void *SaveRAM(void *dst, int start, int size);

uint8_t MemGetByte(uint16_t address); /* added */
uint16_t MemGetWord(uint16_t address); /* added */
int SaveBinary(const fs::path &fname, int start, int length);
int ReadLine(bool SplitByColon = true);

EReturn ReadFile();

EReturn ReadFile(const char *pp, const char *err); /* added */
EReturn SkipFile();

EReturn SkipFile(const char *pp, const char *err); /* added */
void NewDest(char *newfilename);

void SeekDest(long, std::ios_base::seekdir); /* added from new SjASM 0.39g */
int ReadFileToCStringsList(CStringsList *&f, const char *end);

void WriteExp(char *n, aint v);

#endif //SJASMPLUS_SJIO_H
