//
//    OutputAnyFormat.h
//
//    SOAP2 / 2BWT
//
//    Copyright (C) 2012, HKU
//
//    This program is free software; you can redistribute it and/or
//    modify it under the terms of the GNU General Public License
//    as published by the Free Software Foundation; either version 2
//    of the License, or (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//
///////////////////////////////////////////////////////////////////////////////////////////////
/* 
    SRAOutput defines the function to parses the 
    output file generated by SOAP2 aligner.
    
    Date   : 3rh July 2011
    Author : Edward MK Wu
    Change : New file.

*/

#ifndef __OUTPUT_ANY_FORMAT_H__
#define __OUTPUT_ANY_FORMAT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "2bwt-lib/HSP.h"

#define OCC_OUTPUT_FORMAT            20111218
#define OCC_OUTPUT_MAX_LINE_LENGTH   1024
#define OCC_OUTPUT_NUM_HEADER_LINE   2

typedef struct SRAOutputFileInfo{
    FILE * outputFile;
    uint8_t outputFormat;
    uint8_t queryMode;
    unsigned int queryBatch;
    
    //Header information about the reference sequence
    unsigned int dbNumOfSeqs;
    unsigned int * dbLengthOfSeqs;
    Annotation * dbAnnotation;
    
    //Dump filenames
    unsigned int dumpNumOfFiles;
    char * dumpFileNames;
} SRAOutputFileInfo;

void SRAOutputFree(SRAOutputFileInfo * sraOutputFileInfo);

SRAOutputFileInfo * SRAOutputOpen(const char * fileName);

#endif
