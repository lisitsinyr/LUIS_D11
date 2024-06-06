
(*--------------------------------------------------------------------------

   %name: unicode.h %
   %version: 3 %
   %date_modified: Wed Dec 18 12:08:18 1996 %
   $Copyright:

   Copyright (c) 1989-1995 Novell, Inc.  All Rights Reserved.                      

   THIS WORK IS  SUBJECT  TO  U.S.  AND  INTERNATIONAL  COPYRIGHT  LAWS  AND
   TREATIES.   NO  PART  OF  THIS  WORK MAY BE  USED,  PRACTICED,  PERFORMED
   COPIED, DISTRIBUTED, REVISED, MODIFIED, TRANSLATED,  ABRIDGED, CONDENSED,
   EXPANDED,  COLLECTED,  COMPILED,  LINKED,  RECAST, TRANSFORMED OR ADAPTED
   WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC. ANY USE OR EXPLOITATION
   OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT THE PERPETRATOR TO
   CRIMINAL AND CIVIL LIABILITY.$

--------------------------------------------------------------------------*)



{$IFNDEF  UNICODE_H }
    {$DEFINE UNICODE_H}
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
    (*
 *    Definition of a Unicode character - Must be 16 bits wide
 *)
(*    Type unicode  =   nwchar ;
    Type punicode  =   pnwchar ;  *)
    Type ppunicode  =   ppnwchar ;
    (*
 *    Error codes
 *)
    {$DEFINE UNI_ALREADY_LOADED}
    Const UNI_ALREADY_LOADED = 489;
    {$DEFINE UNI_FUTURE_OPCODE}
    Const UNI_FUTURE_OPCODE = 490;
    {$DEFINE UNI_NO_SUCH_FILE}
    Const UNI_NO_SUCH_FILE = 491;
    {$DEFINE UNI_TOO_MANY_FILES}
    Const UNI_TOO_MANY_FILES = 492;
    {$DEFINE UNI_NO_PERMISSION}
    Const UNI_NO_PERMISSION = 493;
    {$DEFINE UNI_NO_MEMORY}
    Const UNI_NO_MEMORY = 494;
    {$DEFINE UNI_LOAD_FAILED}
    Const UNI_LOAD_FAILED = 495;
    {$DEFINE UNI_HANDLE_BAD}
    Const UNI_HANDLE_BAD = 496;
    {$DEFINE UNI_HANDLE_MISMATCH}
    Const UNI_HANDLE_MISMATCH = 497;
    {$DEFINE UNI_RULES_CORRUPT}
    Const UNI_RULES_CORRUPT = 498;
    {$DEFINE UNI_NO_DEFAULT}
    Const UNI_NO_DEFAULT = 499;
    {$DEFINE UNI_INSUFFICIENT_BUFFER}
    Const UNI_INSUFFICIENT_BUFFER = 500;
    {$DEFINE UNI_OPEN_FAILED}
    Const UNI_OPEN_FAILED = 501;
    {$DEFINE UNI_NO_LOAD_DIR}
    Const UNI_NO_LOAD_DIR = 502;
    {$DEFINE UNI_BAD_FILE_HANDLE}
    Const UNI_BAD_FILE_HANDLE = 503;
    {$DEFINE UNI_READ_FAILED}
    Const UNI_READ_FAILED = 504;
    {$DEFINE UNI_TRANS_CORRUPT}
    Const UNI_TRANS_CORRUPT = 505;
    (*
 *    unicode.h functions with no counterpart in string.h
 *)
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    Function NWInitUnicodeTables (
        countryCode  :   nint ;
        codePage  :   nint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLSetPrimaryUnicodeSearchPath (
        Var strSearchPath  : nstr
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWFreeUnicodeTables : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLoadRuleTable (
        ruleTableName  :   pnstr ;
        ruleHandle  :   pnptr 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUnloadRuleTable (
        ruleHandle  :   nptr 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF  N_PLAT_NLM}
        Function NWLocalToUnicode (
            ruleHandle  :   nptr ;
            dest  :   punicode ;
            maxLen  :   nuint32 ;
            src  :   nptr ;
            noMap  :   unicode ;
            len  :   pnuint ;
            allowNoMapFlag  :   nuint32 
        ) : nint;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
        Function NWUnicodeToLocal (
            ruleHandle  :   nptr ;
            dest  :   nptr ;
            maxLen  :   nuint32 ;
            src  :   punicode ;
            noMap  :   nuint8 ;
            len  :   pnuint ;
            allowNoMapFlag  :   nuint32 
        ) : nint;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
        {$IFNDEF  EXCLUDE_UNICODE_NLM_COMPATIBILITY_MACROS }
            (* TC #define NWLocalToUnicode ( P1 , P2 , P3 , P4 , P5 , P6 ) NWLocalToUnicode ( P1 , P2 , P3 , P4 , P5 , P6 , 1 )  *)
            (* TC #define NWUnicodeToLocal ( P1 , P2 , P3 , P4 , P5 , P6 ) NWUnicodeToLocal ( P1 , P2 , P3 , P4 , P5 , P6 , 1 )  *)
        {$ENDIF}
        (* If I could make size_t be nuint32 for N_PLAT_NLM all of the functions *)
        (* below here could be single sourced.                                   *)
        {$IFDEF 0}
            Function NWUnicodeToCollation (
                ruleHandle  :   nptr ;
                dest  :   punicode ;
                maxLen  :   nuint32 ;
                src  :   punicode ;
                noMap  :   unicode ;
                len  :   pnuint32 
            ) : nint;
            {$IFDEF N_ARCH_32}
            stdcall;
            {$ENDIF}
            Function NWUnicodeCompare (
                ruleHandle  :   nptr ;
                chr1  :   unicode ;
                chr2  :   unicode 
            ) : nint;
            {$IFDEF N_ARCH_32}
            stdcall;
            {$ENDIF}
            Function NWUnicodeToMonocase (
                ruleHandle  :   nptr ;
                dest  :   punicode ;
                maxLen  :   nuint32 ;
                src  :   punicode ;
                len  :   pnuint32 
            ) : nint;
            {$IFDEF N_ARCH_32}
            stdcall;
            {$ENDIF}
        {$ENDIF}
    {$ELSE}
        Function NWLocalToUnicode (
            ruleHandle  :   nptr ;
            dest  :   punicode ;
            maxLen  :   size_t ;
            src  :   pnuint8 ;
            noMap  :   unicode ;
            Var len  : size_t
        ) : nint;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
        Function NWUnicodeToLocal (
            ruleHandle  :   nptr ;
            dest  :   pnuint8 ;
            maxLen  :   size_t ;
            src  :   punicode ;
            noMap  :  nuint8;
            Var len  : size_t
        ) : nint;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
    {$ENDIF}
    Function NWUnicodeToCollation (
        ruleHandle  :   nptr ;
        dest  :   punicode ;
        maxLen  :   size_t ;
        src  :   punicode ;
        noMap  :   unicode ;
        Var len  : size_t
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUnicodeCompare (
        ruleHandle  :   nptr ;
        chr1  :   unicode ;
        chr2  :   unicode 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWUnicodeToMonocase (
        ruleHandle  :   nptr ;
        dest  :   punicode ;
        maxLen  :   size_t ;
        src  :   punicode ;
        Var len  : size_t
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (*
 *    Functions that work with XLate Tables
 *)
    {$IFDEF  N_PLAT_DOS}
    {$IFDEF  N_UNI_NEW_TABLES}
        {$DEFINE N_UNI_LOAD_MONOCASE}
        Const N_UNI_LOAD_MONOCASE = $0001;
        {$DEFINE N_UNI_LOAD_COLLATION}
        Const N_UNI_LOAD_COLLATION = $0002;
        (* Not implemented Function NWLInitXlateTables (
            codePage  :   nint ;
            flags  :   nflag8 
        ) : nint;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
        (* Not implemented Function NWLFreeXlateTables : nint;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
        (* Not implemented Function NWLLoadXlateTable (
            ruleTableName  :   pnstr ;
            ruleHandle  :   pnptr 
        ) : nint;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
        (* Not implemented Function NWLUnloadXlateTable (
            ruleHandle  :   nptr 
        ) : nint;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
        (* TC #define NWInitUnicodeTables ( CountryCode , CodePage ) NWLInitXlateTables ( CodePage , N_UNI_LOAD_MONOCASE | N_UNI_LOAD_COLLATION )  *)
        Type NWFreeUnicodeTables = NWLFreeXlateTables;
        Type NWLoadRuleTable = NWLLoadXlateTable;
        Type NWUnloadRuleTable = NWLUnloadXlateTable;
    {$ENDIF}
    {$ENDIF}
    Function NWGetUnicodeToLocalHandle (
        handle  :   pnptr 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetLocalToUnicodeHandle (
        handle  :   pnptr 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetMonocaseHandle (
        handle  :   pnptr 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetCollationHandle (
        handle  :   pnptr 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (*
 *    Functions in unicode.h that work like those in string.h
 *)
(*    Function unicat (
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
        len  :   size_t 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function unisize (
        s  :   punicode 
    ) : size_t;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF} *)
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
{$ENDIF}



