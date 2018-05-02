////////////////////////////////////////////////////////////////////
// File   : PolynomialTboxFuncs.h
// Date   : January, 2015
// Copyright (c) 2015 Altair Engineering Inc.  All Rights
// Reserved.  Contains trade secrets of Altair Engineering, Inc.
// Copyright notice does not imply publication.  Decompilation or
// disassembly of this software is strictly prohibited.
////////////////////////////////////////////////////////////////////

#pragma warning(disable: 4251)
#include "AltTboxDefs.h"

class OMLInterface;

extern "C" 
{
    ALTTBOX_DECLS int InitToolbox(OMLInterface* eval);
}
