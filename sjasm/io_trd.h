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

// io_trd.h

#ifndef __IO_TRD
#define __IO_TRD

#include "filename.h"

int TRD_SaveEmpty(const Filename &fname);

int TRD_AddFile(const Filename &fname, const HobetaFilename &fhobname, int start, int length, int autostart);

int SaveHobeta(const Filename &fname, const HobetaFilename &fhobname, int start, int length);

//lua adapters
inline int TRD_SaveEmpty(char *fname) {
    return TRD_SaveEmpty(Filename(fname));
}

inline int TRD_AddFile(char *fname, char *fhobname, int start, int length, int autostart) {
    return TRD_AddFile(Filename(fname), HobetaFilename(fhobname), start, length, autostart);
}

#endif

//eof io_trd.h
