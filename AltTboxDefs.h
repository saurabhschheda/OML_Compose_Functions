////////////////////////////////////////////////////////////////////
// File   : PolynomialTboxDefs.h
// Date   : January, 2015
// Copyright (c) 2015 Altair Engineering Inc.  All Rights
// Reserved.  Contains trade secrets of Altair Engineering, Inc.
// Copyright notice does not imply publication.  Decompilation or
// disassembly of this software is strictly prohibited.
////////////////////////////////////////////////////////////////////
//:---------------------------------------------------------------------------
//:Description
//
//  Macros for exporting from the library
//
//:---------------------------------------------------------------------------

#ifndef _alt_Hml2_Tbox_Defs_h
#define _alt_Hml2_Tbox_Defs_h

// Windows export macro
#ifdef OS_WIN
  #ifdef ALTTBOX_EXPORT
    #undef  ALTTBOX_DECLS
    #define ALTTBOX_DECLS __declspec(dllexport)
  #else
    #undef  ALTTBOX_DECLS
    #define ALTTBOX_DECLS __declspec(dllimport)
  #endif  // ENCRYPTTBOX_EXPORT
#else
  #undef  ALTTBOX_DECLS
  #define ALTTBOX_DECLS
#endif // OS_WIN

#endif // _alt_Hml2_Tbox_Defs_h
