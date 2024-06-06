(******************************************************************************

  %name:          nunicode.h %
  %version:       18 %
  %date_modified: Thu Nov  6 19:23:43 1997 %
  $Copyright:

  Copyright (c) 1989-1997 Novell, Inc.  All Rights Reserved.

  THIS WORK IS  SUBJECT  TO  U.S.  AND  INTERNATIONAL  COPYRIGHT  LAWS  AND
  TREATIES.   NO  PART  OF  THIS  WORK MAY BE  USED,  PRACTICED,  PERFORMED
  COPIED, DISTRIBUTED, REVISED, MODIFIED, TRANSLATED,  ABRIDGED, CONDENSED,
  EXPANDED,  COLLECTED,  COMPILED,  LINKED,  RECAST, TRANSFORMED OR ADAPTED
  WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC. ANY USE OR EXPLOITATION
  OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT THE PERPETRATOR TO
  CRIMINAL AND CIVIL LIABILITY.$

 *****************************************************************************)


{$IFNDEF  NUNICODE_H }
    {$DEFINE NUNICODE_H}
    {$IFNDEF SIZE_T}
{$DEFINE SIZE_T}
Type
  size_t = Cardinal;
  psize_t = ^size_t;
  ppsize_t = ^psize_t;
{$ENDIF}

    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
    {$IFDEF N_PLAT_OS2}
    (* TC #define PN_API * N_API  *)
    {$ELSE}
    (* TC #define PN_API N_API *  *)
    {$ENDIF}
    (*
   Novell-defined Unicode characters.
   Consult with the Internationalization group before adding to this list.
*)
    {$DEFINE UNI_CHANGE_NAMESPACE}
    Const UNI_CHANGE_NAMESPACE = $f8f4;
    {$DEFINE UNI_PREVIOUS_DIR}
    Const UNI_PREVIOUS_DIR = $f8f5;
    {$DEFINE UNI_CURRENT_DIR}
    Const UNI_CURRENT_DIR = $f8f6;
    {$DEFINE UNI_PATH_SEPARATOR}
    Const UNI_PATH_SEPARATOR = $F8F7;
    {$DEFINE UNI_VOLUMENAME_ROOT}
    Const UNI_VOLUMENAME_ROOT = $f8f8;
    {$DEFINE UNI_VOLUME_ROOT}
    Const UNI_VOLUME_ROOT = $f8f9;
    {$DEFINE UNI_NDS_ROOT}
    Const UNI_NDS_ROOT = $f8fa;
    {$DEFINE UNI_WILD_QMARK}
    Const UNI_WILD_QMARK = $f8fb;
    {$DEFINE UNI_WILD_ASTERISK}
    Const UNI_WILD_ASTERISK = $f8fc;
    {$DEFINE UNI_WILD_AUG_QMARK}
    Const UNI_WILD_AUG_QMARK = $f8fd;
    {$DEFINE UNI_WILD_AUG_ASTERISK}
    Const UNI_WILD_AUG_ASTERISK = $f8fe;
    {$DEFINE UNI_WILD_AUG_PERIOD}
    Const UNI_WILD_AUG_PERIOD = $f8ff;
    (*
    Actions to take when an unmappable byte or uni character is encountered.
    Used in SetNoMapAction call.
*)
    {$DEFINE NWU_UNCHANGED_ACTION}
    Const NWU_UNCHANGED_ACTION = 1;
    {$DEFINE NWU_RETURN_ERROR}
    Const NWU_RETURN_ERROR = 0;
    {$DEFINE NWU_SUBSTITUTE}
    Const NWU_SUBSTITUTE = 1;
    {$DEFINE NWU_CALL_HANDLER}
    Const NWU_CALL_HANDLER = 2;
    (*
    Codes to enable the Scan and Parse handler functions.
    Used in SetScanAction call.
*)
    {$DEFINE NWU_DISABLED}
    Const NWU_DISABLED = 0;
    {$DEFINE NWU_ENABLED}
    Const NWU_ENABLED = 2;
    (*
    Flags to pass to NWUXGetCaseConverter to specify whether to load
    a converter which converts to upper, lower or title case.
*)
    {$DEFINE NWU_LOWER_CASE}
    Const NWU_LOWER_CASE = 0;
    {$DEFINE NWU_UPPER_CASE}
    Const NWU_UPPER_CASE = 1;
    {$DEFINE NWU_TITLE_CASE}
    Const NWU_TITLE_CASE = 2;
    (*
    Flags to pass to NWUXGetNormalizeConverter to specify whether to
    load a converter which converts to pre-composed or de-composed
    unicode characters.
*)
    {$DEFINE NWU_PRECOMPOSED}
    Const NWU_PRECOMPOSED = 0;
    {$DEFINE NWU_DECOMPOSED}
    Const NWU_DECOMPOSED = 1;
    (*
    For use in SetByte/UniFunction calls
*)
    (* TC #define NWU_UNCHANGED_FUNCTION ( ( void N_FAR * ) - 1 )  *)
//    Type NWU_RESET_TO_DEFAULT = NIL;
    (*
    Error codes.  FFFFFDE0 to FFFFFDFF reserved for new unicode APIs.
*)
    {$DEFINE NWU_NO_CONVERTER}
    Const NWU_NO_CONVERTER = 544;
    {$DEFINE NWU_CONVERTER_NOT_FOUND}
    Const NWU_CONVERTER_NOT_FOUND = 543;
    {$DEFINE NWU_TOO_MANY_FILES}
    Const NWU_TOO_MANY_FILES = 542;
    {$DEFINE NWU_NO_PERMISSION}
    Const NWU_NO_PERMISSION = 541;
    {$DEFINE NWU_OPEN_FAILED}
    Const NWU_OPEN_FAILED = 540;
    {$DEFINE NWU_READ_FAILED}
    Const NWU_READ_FAILED = 539;
    {$DEFINE NWU_OUT_OF_MEMORY}
    Const NWU_OUT_OF_MEMORY = 538;
    {$DEFINE NWU_CANT_LOAD_CONVERTER}
    Const NWU_CANT_LOAD_CONVERTER = 537;
    {$DEFINE NWU_CONVERTER_CORRUPT}
    Const NWU_CONVERTER_CORRUPT = 536;
    {$DEFINE NWU_NULL_HANDLE}
    Const NWU_NULL_HANDLE = 535;
    {$DEFINE NWU_BAD_HANDLE}
    Const NWU_BAD_HANDLE = 534;
    {$DEFINE NWU_HANDLE_MISMATCH}
    Const NWU_HANDLE_MISMATCH = 533;
    {$DEFINE NWU_UNMAPPABLE_CHAR}
    Const NWU_UNMAPPABLE_CHAR = 532;
    {$DEFINE NWU_RANGE_ERROR}
    Const NWU_RANGE_ERROR = 531;
    {$DEFINE NWU_BUFFER_FULL}
    Const NWU_BUFFER_FULL = 530;
    {$DEFINE NWU_INPUT_MAX}
    Const NWU_INPUT_MAX = 529;
    {$DEFINE UNI_PARSER_ERROR}
    Const UNI_PARSER_ERROR = 528;
    {$DEFINE NWU_OLD_CONVERTER_VERSION}
    Const NWU_OLD_CONVERTER_VERSION = 527;
    {$DEFINE NWU_UNSUPPORTED_AUX_FUNCTION}
    Const NWU_UNSUPPORTED_AUX_FUNCTION = 526;
    {$DEFINE NWU_EMBEDDED_NULL}
    Const NWU_EMBEDDED_NULL = 525;
    {$IFNDEF  _CONVERT_H}
        (*
    Data types
*)
        Type unicode  =  nuint16;
        Type punicode  =  ^unicode;
        (* TC #define nwunisize ( x ) ( sizeof ( x ) / sizeof ( unicode ) )  *)
        (****************************************************************************)
        (*
    Converter handle
*)
        Type CONVERT  =  ^variant;
        Type pCONVERT  =  ^CONVERT;
    {$ENDIF}
    (****************************************************************************)
    (*
    IBM C/Set compiler requires   "typedef nint (* N_API xxx)"
    MSW and NLM platforms require "typedef nint (N_API * xxx)"
    The PN_API symbol is defined to satisfy both situations.
*)
    (*
    Function called when non-mappable bytes are found
*)
    Type  NMBYTE = Function(
    byteUniHandle : pCONVERT ;
    output : punicode;
    outputLeft : nuint;
    outputUsed : pnuint;
    badInput : pnuint8;
    badInputSize : nuint)
    :nint; 
    (*
    Function called when non-mappable unicode characters are found
*)
    Type NMUNI = Function(
    byteUniHandle : pCONVERT; 
    output : pnuint8; 
    outputLeft : nuint; 
    outputUsed : pnuint; 
    badInput : punicode; 
    badInputSize : nuint )
    :nint; 
    (*
    Function called to scan for special byte input
*)
    Type  SCBYTE = Function (
    byteUniHandle : pCONVERT; 
    input : pnuint8; 
    scanmax : nint )
    :pnuint8; 
    (*
    Function called to scan for special Unicode input
*)
    Type SCUNI = Function (
    byteUniHandle : pCONVERT; 
    input : punicode; 
    scanmax : nint )
    :punicode;
    (*
    Function called to parse special byte input
*)
    Type PRBYTE = Function(
    byteUniHandle : pCONVERT; 
    output : punicode; 
    outputleft : nuint; 
    outputUsed : pnuint; 
    input : pnuint8; 
    inputUsed : pnuint )
    :nint;
    (*
    Function called to parse special Unicode input
*)
    Type PRUNI = Function(
    byteUniHandle : pCONVERT; 
    output : pnuint8; 
    outputLeft : nuint; 
    outputUsed : pnuint; 
    input : punicode; 
    inputUsed : pnuint)
    :nint; 
    (****************************************************************************)
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    (*
    These are the Standard API's
*)
    Function NWUSStandardUnicodeInit : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Procedure NWUSStandardUnicodeRelease;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUSGetCodePage (
        pCodePage  :   pnuint ;
        pCountry  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* NOTE:  The actualLength parameter returned by the conversion routines
          does *not* include the null terminator.
*)
    Function NWUSByteToUnicode (
        unicodeOutput  :   punicode ;
        outputBufferLen  :   nuint ;
        byteInput  :   pnuint8 ;
        actualLength  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUSByteToUnicodePath (
        unicodeOutput  :   punicode ;
        outputBufferLen  :   nuint ;
        byteInput  :   pnuint8 ;
        actualLength  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUSLenByteToUnicode (
        unicodeOutput  :   punicode ;
        outputBufferLen  :   nuint ;
        byteInput  :   pnuint8 ;
        inLength  :   nint ;
        actualLength  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUSLenByteToUnicodePath (
        unicodeOutput  :   punicode ;
        outputBufferLen  :   nuint ;
        byteInput  :   pnuint8 ;
        inLength  :   nint ;
        actualLength  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUSUnicodeToByte (
        byteOutput  :   pnuint8 ;
        outputBufferLen  :   nuint ;
        unicodeInput  :   punicode ;
        actualLength  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUSUnicodeToBytePath (
        byteOutput  :   pnuint8 ;
        outputBufferLen  :   nuint ;
        unicodeInput  :   punicode ;
        actualLength  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUSUnicodeToUntermByte (
        byteOutput  :   pnuint8 ;
        outputBufferLen  :   nuint ;
        unicodeInput  :   punicode ;
        actualLength  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUSUnicodeToUntermBytePath (
        byteOutput  :   pnuint8 ;
        outputBufferLen  :   nuint ;
        unicodeInput  :   punicode ;
        actualLength  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUSUnicodeToLowerCase (
        lowerCaseOutput  :   punicode ;
        outputBufferLen  :   nuint ;
        unicodeInput  :   punicode ;
        actualLength  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUSUnicodeToUpperCase (
        upperCaseOutput  :   punicode ;
        outputBufferLen  :   nuint ;
        unicodeInput  :   punicode ;
        actualLength  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (*
    These are the Extended API's
*)
    Function NWUXLoadByteUnicodeConverter (
        codepage  :   nuint ;
        Var byteUniHandle  : pCONVERT
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXLoadCaseConverter (
        caseFlag  :   nuint ;
        Var caseHandle  : pCONVERT
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXLoadCollationConverter (
        countryCode  :   nuint ;
        Var collationHandle  : pCONVERT
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXLoadNormalizeConverter (
        preDeFlag  :   nuint ;
        Var normalizeHandle  : pCONVERT
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXUnloadConverter (
        converterHandle  :   pCONVERT 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXByteToUnicode (
        byteUniHandle  :   pCONVERT ;
        unicodeOutput  :   punicode ;
        outputBufferLen  :   nuint ;
        byteInput  :   pnuint8 ;
        actualLength  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXByteToUnicodePath (
        byteUniHandle  :   pCONVERT ;
        unicodeOutput  :   punicode ;
        outputBufferLen  :   nuint ;
        byteInput  :   pnuint8 ;
        actualLength  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXLenByteToUnicode (
        byteUniHandle  :   pCONVERT ;
        unicodeOutput  :   punicode ;
        outputBufferLen  :   nuint ;
        byteInput  :   pnuint8 ;
        inLength  :   nint ;
        actualLength  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXLenByteToUnicodePath (
        byteUniHandle  :   pCONVERT ;
        unicodeOutput  :   punicode ;
        outputBufferLen  :   nuint ;
        byteInput  :   pnuint8 ;
        inLength  :   nint ;
        actualLength  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXUnicodeToByte (
        byteUniHandle  :   pCONVERT ;
        byteOutput  :   pnuint8 ;
        outputBufferLen  :   nuint ;
        unicodeInput  :   punicode ;
        actualLength  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXUnicodeToBytePath (
        byteUniHandle  :   pCONVERT ;
        byteOutput  :   pnuint8 ;
        outputBufferLen  :   nuint ;
        unicodeInput  :   punicode ;
        actualLength  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXUnicodeToUntermByte (
        byteUniHandle  :   pCONVERT ;
        byteOutput  :   pnuint8 ;
        outputBufferLen  :   nuint ;
        unicodeInput  :   punicode ;
        actualLength  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXUnicodeToUntermBytePath (
        byteUniHandle  :   pCONVERT ;
        byteOutput  :   pnuint8 ;
        outputBufferLen  :   nuint ;
        unicodeInput  :   punicode ;
        actualLength  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXUnicodeToCase (
        caseHandle  :   pCONVERT ;
        monocasedOutput  :   punicode ;
        outputBufferLen  :   nuint ;
        unicodeInput  :   punicode ;
        actualLength  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXUnicodeToCollation (
        collationHandle  :   pCONVERT ;
        collationWeights  :   punicode ;
        outputBufferLen  :   nuint ;
        unicodeInput  :   punicode ;
        actualLength  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXUnicodeToNormalized (
        normalizeHandle  :   pCONVERT ;
        normalizedOutput  :   punicode ;
        outputBufferLen  :   nuint ;
        unicodeInput  :   punicode ;
        actualLength  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXGetCharSize (
        byteUniHandle  :   pCONVERT ;
        byteInput  :   pnuint8 ;
        pCharSize  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXSetNoMapAction (
        byteUniHandle  :   pCONVERT ;
        noMapByteAction  :   nint ;
        noMapUniAction  :   nint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXGetNoMapAction (
        byteUniHandle  :   pCONVERT ;
        noMapByteAction  :   pnint ;
        noMapUniAction  :   pnint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXSetScanAction (
        byteUniHandle  :   pCONVERT ;
        scanByteAction  :   nint ;
        scanUniAction  :   nint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXGetScanAction (
        byteUniHandle  :   pCONVERT ;
        scanByteAction  :   pnint ;
        scanUniAction  :   pnint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXSetSubByte (
        byteUniHandle  :   pCONVERT ;
        substituteByte  :   nuint8 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXGetSubByte (
        byteUniHandle  :   pCONVERT ;
        substituteByte  :   pnuint8 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXSetSubUni (
        byteUniHandle  :   pCONVERT ;
        substituteUni  :   unicode 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXGetSubUni (
        byteUniHandle  :   pCONVERT ;
        substituteUni  :   punicode 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXSetByteFunctions (
        byteUniHandle  :   pCONVERT ;
        noMapByteFunc  :   NMBYTE ;
        scanByteFunc  :   SCBYTE ;
        parseByteFunc  :   PRBYTE 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXGetByteFunctions (
        byteUniHandle  :   pCONVERT ;
        Var noMapByteFunc  : NMBYTE;
        Var scanByteFunc  : SCBYTE;
        Var parseByteFunc  : PRBYTE
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXSetUniFunctions (
        byteUniHandle  :   pCONVERT ;
        noMapUniFunc  :   NMUNI ;
        scanUniFunc  :   SCUNI ;
        parseUniFunc  :   PRUNI 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXGetUniFunctions (
        byteUniHandle  :   pCONVERT ;
        Var noMapUniFunc  : NMUNI;
        Var scanUniFunc  : SCUNI;
        Var parseUniFunc  : PRUNI
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUXResetConverter (
        convert  :   pCONVERT 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (****************************************************************************)
    (*
    Redefine these functions to use the new unicode API monocase routines.
*)
    (* TC #define uniicmp ( s1 , s2 ) nwusuniicmp ( s1 , s2 )  *)
    (* TC #define uninicmp ( s1 , s2 , l ) nwusuninicmp ( s1 , s2 , l )  *)
    Function unicat (
        s1  :   punicode ;
        s2  :   punicode 
    ) : punicode;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function unichr (
        s  :   punicode ;
        c  :   unicode 
    ) : punicode;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function unicpy (
        s1  :   punicode ;
        s2  :   punicode 
    ) : punicode;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function unicspn (
        s1  :   punicode ;
        s2  :   punicode 
    ) : size_t;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function unilen (
        s  :   punicode 
    ) : size_t;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function unincat (
        s1  :   punicode ;
        s2  :   punicode ;
        n  :   size_t 
    ) : punicode;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function unincpy (
        s1  :   punicode ;
        s2  :   punicode ;
        n  :   size_t 
    ) : punicode;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function uninset (
        s  :   punicode ;
        c  :   unicode ;
        n  :   size_t 
    ) : punicode;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function unipbrk (
        s1  :   punicode ;
        s2  :   punicode 
    ) : punicode;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function unipcpy (
        s1  :   punicode ;
        s2  :   punicode 
    ) : punicode;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function unirchr (
        s  :   punicode ;
        c  :   unicode 
    ) : punicode;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function unirev (
        s  :   punicode 
    ) : punicode;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function uniset (
        s  :   punicode ;
        c  :   unicode 
    ) : punicode;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function unispn (
        s1  :   punicode ;
        s2  :   punicode 
    ) : size_t;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function unistr (
        s1  :   punicode ;
        s2  :   punicode 
    ) : punicode;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function unitok (
        s1  :   punicode ;
        s2  :   punicode 
    ) : punicode;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function unicmp (
        s1  :   punicode ;
        s2  :   punicode 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function unincmp (
        s1  :   punicode ;
        s2  :   punicode ;
        len  :   nuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function uniicmp (
        s1  :   punicode ;
        s2  :   punicode 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function uninicmp (
        s1  :   punicode ;
        s2  :   punicode ;
        len  :   nuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function unisize (
        s  :   punicode 
    ) : size_t;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
{$ENDIF}


(****************************************************************************)

(****************************************************************************)


