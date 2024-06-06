
(*---------------------------------------------------------------------------
   Source module name:  ntypes.h
   Header Revision:     1.49

   $Workfile:   ntypes.inc  $
   $Revision:   1.2  $
   $Modtime::   17 Jul 1996 19:27:22                        $
   $Copyright:

   Copyright (c) 1989-1995 Novell, Inc.  All Rights Reserved.

  THIS WORK IS  SUBJECT  TO  U.S.  AND  INTERNATIONAL  COPYRIGHT  LAWS  AND
  TREATIES.   NO  PART  OF  THIS  WORK MAY BE  USED,  PRACTICED,  PERFORMED
  COPIED, DISTRIBUTED, REVISED, MODIFIED, TRANSLATED,  ABRIDGED, CONDENSED,
  EXPANDED,  COLLECTED,  COMPILED,  LINKED,  RECAST, TRANSFORMED OR ADAPTED
  WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC. ANY USE OR EXPLOITATION
  OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT THE PERPETRATOR TO
  CRIMINAL AND CIVIL LIABILITY.$
---------------------------------------------------------------------------*)


{$IFNDEF NTYPES_H}
{$DEFINE NTYPES_H}

{
   For brief documentation, please refer to the associated ntypes.txt
   with the same release version. For in-depth documentation, please
   refer to the Portable API Definition Guide.
}


{
   Section 1:  Automatic definitions
   Section 1a: Platforms
}

{
   Since this file should only be used in Delphi, we will set some default
   defines to make the files easier to use
}

{ We will always be building for a Winows platform }
{$DEFINE N_PLAT_MSW}

{$IFDEF VER80}
   { VER80 is defined for Delphi 1.x (16 bit) so set defines for win16 }
   {$DEFINE N_ARCH_16}
{$ELSE}
   { Otherwise it must be a 32 bit platform }
   {$DEFINE N_ARCH_32}
{$ENDIF}

{$IFNDEF N_INC_NO_AUTO}

   {$IFDEF NWOS2}
      {$IFNDEF N_PLAT_OS2}
         {$DEFINE N_PLAT_OS2}
      {$ENDIF}
      {$IFNDEF N_ARCH_16}
         {$DEFINE N_ARCH_16}
      {$ENDIF}
   {$ELSE} { ! NWOS2 }
      {$IFDEF NWWIN}
         {$IFNDEF N_PLAT_MSW}
            {$DEFINE N_PLAT_MSW}
         {$ENDIF}
         {$IFNDEF N_ARCH_16}
            {$DEFINE N_ARCH_16}
         {$ENDIF}
      {$ELSE} { ! NWWIN }
         {$IFDEF NWDOS}
            {$IFNDEF N_PLAT_DOS}
               {$DEFINE N_PLAT_DOS}
            {$ENDIF}
            {$IFNDEF N_ARCH_16}
               {$DEFINE N_ARCH_16}
            {$ENDIF}
         {$ELSE} { ! NWDOS }
            {$IFDEF WIN32}
               {$IFNDEF N_PLAT_MSW}
                  {$DEFINE N_PLAT_MSW}
               {$ENDIF}
               {$IFNDEF N_ARCH_32}
                  {$DEFINE N_ARCH_32}
               {$ENDIF}
            {$ENDIF} { WIN32 }
         {$ENDIF} { NWDOS }
      {$ENDIF} { NWWIN }
   {$ENDIF} { NWOS2 }

   {$IFDEF N_PLAT_WNT3}                {N_PLAT_WNT3 || N_PLAT_WNT4}
      {$IFNDEF N_PLAT_WNT}
         {$DEFINE N_PLAT_WNT}
      {$ENDIF}
      {$IFNDEF N_PLAT_MSW}
         {$DEFINE N_PLAT_MSW}
      {$ENDIF}
   {$ELSE}
      {$IFDEF N_PLAT_WNT4}
         {$IFNDEF N_PLAT_WNT}
            {$DEFINE N_PLAT_WNT}
         {$ENDIF}
         {$IFNDEF N_PLAT_MSW}
            {$DEFINE N_PLAT_MSW}
         {$ENDIF}
      {$ENDIF}
   {$ENDIF}

   {$IFDEF N_PLAT_WNT}
      {$IFNDEF N_PLAT_WNT3}            {!N_PLAT_WNT3 && !N_PLAT_WNT4}
         {$IFNDEF N_PLAT_WNT4}
            {$DEFINE N_PLAT_WNT3}
         {$ENDIF}
      {$ENDIF}
      {$IFNDEF N_PLAT_MSW}
         {$DEFINE N_PLAT_MSW}
      {$ENDIF}
   {$ENDIF}

   {$IFNDEF N_PLAT_MSW }
      {$IFDEF N_PLAT_MSW3}                {N_PLAT_MSW3 || N_PLAT_MSW4}
         {$DEFINE N_PLAT_MSW}
      {$ELSE}
         {$IFDEF N_PLAT_MSW4}
            {$DEFINE N_PLAT_MSW}
         {$ENDIF}
      {$ENDIF}
   {$ENDIF}


   {$IFDEF N_PLAT_MSW}                 {N_PLAT_MSW && !N_PLAT_WNT}
      {$IFNDEF N_PLAT_WNT}
         {$IFNDEF N_PLAT_MSW3}         {!N_PLAT_MSW3 && !N_PLAT_MSW4}
            {$IFNDEF N_PLAT_MSW4}
               {$DEFINE N_PLAT_MSW3}
            {$ENDIF}
         {$ENDIF}
      {$ENDIF}
   {$ENDIF}

   {
      Set a default architecture size if none is set.  Test order is
      important and must be elif'ed because N_PLAT_MSW can be set for
      various Windows platforms that have differing default int sizes.
   }

   {$IFNDEF N_ARCH_64}              {!N_ARCH_64 && !N_ARCH_32 && !N_ARCH_16}
      {$IFNDEF N_ARCH_32}
         {$IFNDEF N_ARCH_16}
            {$IFDEF N_PLAT_DOS}
               {$DEFINE N_ARCH_16}
            {$ELSE}
               {$IFDEF N_PLAT_WNT}
                  {$DEFINE N_ARCH_32}
               {$ELSE}
                  {$IFDEF N_PLAT_OS2}              {N_PLAT_OS2 && _MSC_VER}
                     {$IFDEF _MSC_VER}
                        {$DEFINE N_ARCH_16}
                     {$ELSE}
                        {$DEFINE N_ARCH_32}
                     {$ENDIF}
                  {$ELSE}
                     {$IFDEF N_PLAT_MSW4}
                        {$DEFINE N_ARCH_32}
                     {$ELSE}
                        {$IFDEF N_PLAT_MSW}
                           {$DEFINE N_ARCH_16}
                        {$ELSE}
                           {$DEFINE N_ARCH_32}
                        {$ENDIF}
                     {$ENDIF}
                  {$ENDIF}
               {$ENDIF}
            {$ENDIF}
         {$ENDIF}
      {$ENDIF}
   {$ENDIF}

{$ENDIF} { N_INC_NO_AUTO }

{
   Section 1b: Compiler specific
}

{$IFDEF _MSC_VER}
   {$IFDEF _MSC_VER < 700}
      {$DEFINE N_MSC_OLD}
   {$ELSE}
      {$DEFINE N_MSC}
   {$ENDIF}
{$ENDIF}

{
   Section 1c: Resource compiler specific
}

{$IFDEF RC_INVOKED}
   {$IFNDEF N_RC_INVOKED}
      {$DEFINE N_RC_INVOKED}
   {$ENDIF}
{$ENDIF}

{
   Section 2: Platform specific definitions
}

{$IFNDEF N_RC_INVOKED}

   {$IFDEF N_PLAT_MSW}
      {$IFDEF N_ARCH_16}
         (* #if defined(N_ARCH_16) && defined(N_PLAT_MSW) *)

         {$IFNDEF NWWIN}
            {$DEFINE NWWIN}
         {$ENDIF}

         {$DEFINE PLATFORM_DEFINED}

      {$ELSE} { ! N_ARCH_16 }
         {$IFDEF N_ARCH_32}
            (* #elif defined(N_ARCH_32) && defined(N_PLAT_MSW) *)

            {$IFNDEF WIN32}
               {$DEFINE WIN32}
            {$ENDIF}

            {$DEFINE PLATFORM_DEFINED}
         {$ENDIF} { N_ARCH_32}
      {$ENDIF} { N_ARCH_16}
   {$ENDIF} { N_PLAT_MSW }

   {$IFDEF N_PLAT_OS2}
      {$IFDEF N_ARCH_16}
         (* #elif defined(N_ARCH_16) && defined(N_PLAT_OS2) *)

         {$IFNDEF NWOS2}
            {$DEFINE NWOS2}
         {$ENDIF}

         {$DEFINE PLATFORM_DEFINED}
      {$ELSE} { ! N_ARCH_16 }
         {$IFDEF N_ARCH_32}
            (* #elif defined(N_ARCH_32) && defined(N_PLAT_OS2) *)

            {$DEFINE PLATFORM_DEFINED}
         {$ENDIF} {N_ARCH_32}
      {$ENDIF} {N_ARCH_16}
   {$ENDIF} {N_PLAT_OS2}

   {$IFDEF N_PLAT_DOS}
      (* #elif defined N_PLAT_DOS *)
      {$IFNDEF NWDOS}
         {$DEFINE NWDOS}
      {$ENDIF}

      {$DEFINE PLATFORM_DEFINED}
   {$ENDIF}

   {$IFDEF N_PLAT_NLM}
      (* #elif defined N_PLAT_NLM *)

      {$DEFINE PLATFORM_DEFINED}
   {$ENDIF}

   {$IFDEF N_PLAT_UNIX
      (* #elif defined N_PLAT_UNIX *)

      {$DEFINE N_INT_STRICT_ALIGNMENT}

      {$DEFINE PLATFORM_DEFINED}
   {$ENDIF}

   {$IFNDEF PLATFORM_DEFINED}    { no platform constant }

         {$EXIT} {-----#error A platform must be defined-----}
   {$ENDIF}


{$ENDIF}  { !N_RC_INVOKED }

{
   Section 3:  Other constants
   Section 3a: NULL
}

{$IFNDEF NULL}
   {$IFDEF __cplusplus}
      {$DEFINE NULL}
const
   NULL = 0;

   {$ENDIF}
{$ENDIF}

{$IFDEF N_RC_INVOKED}
   {$DEFINE NULL}
const
   NULL = 0;
{$ENDIF}

{$IFNDEF NULL}
   {$IFDEF N_MSC}
      { #define NULL ((void *) 0) }
   {$ELSE} { ! N_MSC }
      (* $IFDEF M_I86S || defined(M_I86SM) || defined(M_I86C) || \
          defined(M_I86CM) || \
          defined(__TINY__) || defined(__SMALL__) || defined(__MEDIUM__) || \
          defined(N_PLAT_NLM *)

         (* #define NULL   0 *)
      (* $ELSE *)
Const
   NULL:LongInt = 0;

      (* $ENDIF *)
   {$ENDIF} { N_MSC }
{$ENDIF} { NULL }

{
   Section 3b: Standard constants
}

const
   N_ALWAYS     = 1;
   N_SUCCESS    = 0;
   N_FAILURE    = (-1);
   N_YES        = 1;
   N_NO         = 0;
   N_FALSE      = 0;
   N_TRUE       = 1;
   N_UNKNOWN    = (N_TRUE + 1);

{
   Section 3c: System constants
}

const
   N_SYS_USER          = 0;
   N_SYS_NETWARE       = 1;
   N_SYS_NAWF          = 2;
   N_SYS_MAX_COUNT     = 20;
   N_SYS_NAME_MAX_LEN  = 31;

{
   Section 3d: Historical constant synonyms
}

(*-----{$IFNDEF N_INC_NO_OLD_CONSTANTS}
   {$IFNDEF TRUE}
const
   TRUE = 1;
   {$ENDIF}
   {$IFNDEF FALSE}
Const
   FALSE = 0;
   {$ENDIF}
{$ENDIF}-----*)

{
   Section 3e: Miscellaneous constants
}

{
   N_BITSPERBYTE is currently only used internally
}
Const
{$IFDEF BITSPERBYTE}
   N_BITSPERBYTE = BITSPERBYTE;
{$ELSE}
   N_BITSPERBYTE = 8;
{$ENDIF}

{
   Section 4:  Types
   Section 4a: Machine dependent types
}

{$IFNDEF N_RC_INVOKED}

Type
   nint8 = ShortInt;
   {$IFNDEF N_PLAT_UNIX}
      nuint8 = Byte;
   {$ELSE}
      {
         WARNING:  THE NEXT STATEMENT PRESUMES CHAR IS UNSIGNED!
      }
     (* {$IFNDEF __GNUC__}
         typedef unsigned char nuint8;
      {$ELSE}
         typedef char nuint8;
      {$ENDIF} *)
   {$ENDIF}

   nint16 = SmallInt;
   nuint16 = Word;
   {$IFDEF __alpha}
      {----- typedef signed int nint32;
      typedef unsigned int nuint32;
      typedef signed long nint64;
      typedef unsigned long nuint64;
      #define nint64_type -----}
   {$ELSE}
      nint32 = LongInt;
      nuint32 = LongInt;     (* No unsigned 32-bit type *)
   {$ENDIF}
   nreal32 = Single;
   nreal64 = Double;

   {$IFNDEF N_PLAT_MAC}

      {$IFDEF N_FORCE_INT_32}
         (* typedef signed long     nint;
         typedef unsigned long   nuint; *)
      {-- #elif defined N_FORCE_INT_16 --}
         (* typedef signed short    nint;
         typedef unsigned short  nuint; *)
      {$ELSE}
         nint = Integer;
         nuint = Cardinal;
      {$ENDIF}

      nbool = WordBool;
      {$IFNDEF N_PLAT_MSW}
         {$IFNDEF N_ARCH_32}
            {$IFNDEF __alpha}
               {$IFNDEF _AIX}
                  nreal80 = Extended;
                  {$DEFINE nreal80_type}
               {
                  VC++ for NT does not support nreal80's by default. Check
                  readme for instructions on how to enable them.
               }
               {$ENDIF}
            {$ENDIF}
         {$ENDIF}
      {$ENDIF}

      nreal = Double;
   {$ELSE}
      (* typedef signed long     nint;
      typedef unsigned long   nuint;
      typedef unsigned char   nbool; *)

      { #if defined( powerc ) || defined( __powerc ) || defined( THINK_C ) }
         (* typedef long double nreal80;
         typedef double          nreal; *)
      { #else }
         (* typedef extended        nreal80;
         typedef extended        nreal; *)
      { #endif }
      { #define nreal80_type }
   {$ENDIF}

{
   Section 4b: Derived types
}

   {$IFDEF __alpha}
      (* typedef nuint64 nparam; *)
   {$ELSE}
      nparam = nuint32;
   {$ENDIF}
   nhdl = nparam;
   nid = nparam;
   nflag8 = nuint8;
   nflag16 = nuint16;
   nflag32 = nuint32;

   nbool8 = Byte;
   nbool16 = Word;
   nbool32 = LongInt;

   nfixed = nint32;
   {$IFDEF N_USE_UNSIGNED_CHAR}
      (* typedef nuint8  nstr8; *)
   {$ELSE}
      nstr8 = char;
   {$ENDIF}
   nstr16 = nuint16;
   {$IFDEF N_USE_STR_16}
      (* typedef  nstr16 nstr; *)
   {$ELSE}
      nstr = nstr8;
   {$ENDIF}
   nchar = nstr;
   nchar8 = nstr8;
   nchar16 = nstr16;
   nwchar = nchar16;

   {
      Return code for functions that return status/errors.
   }

   NWRCODE = nint32;


   {
      Pointers to scalars.
   }

Type
   nptr = Pointer;
   npproc = Pointer;

   pnint8 = ^nint8;
   pnuint8 = ^nuint8;
   pnint16 = ^nint16;
   pnuint16 = ^nuint16;
   pnint32 = ^nint32;
   pnuint32 = ^nuint32;
   {$IFDEF nint64_type}
      (* typedef nint64    N_FAR *  pnint64;
      typedef nuint64   N_FAR *  pnuint64; *)
   {$ENDIF}
   pnint = ^nint;
   pnuint = ^nuint;
   pnflag8 = ^nflag8;
   pnflag16 = ^nflag16;
   pnflag32 = ^nflag32;
   pnbool = ^nbool;
   pnbool8 = ^nbool8;
   pnbool16 = ^nbool16;
   pnbool32 = ^nbool32;
   pnfixed = ^nfixed;
   pnstr = ^nstr;
   ppnstr = ^pnstr;
   pnstr16 = ^nstr16;
   ppnstr16 = ^pnstr16;
   pnstr8 = ^nstr8;
   ppnstr8 = ^pnstr8;
   pnchar = ^nchar;
   ppnchar = ^pnchar;
   pnchar16 = ^nchar16;
   ppnchar16 = ^pnchar16;
   pnchar8 = ^nchar8;
   ppnchar8 = ^pnchar8;
   pnwchar = ^nwchar;
   ppnwchar = ^pnwchar;
   pnreal = ^nreal;
   pnreal32 = ^nreal32;
   pnreal64 = ^nreal64;
   {$IFDEF nreal80_type}
      {--- typedef nreal80   N_FAR *  pnreal80; ---}
   {$ENDIF}
   {-----pnid = ^nid;-----}
   {-----pnhdl = ^nhdl;-----}
   {-----pnparam = ^nparam;-----}

   {
      Pointers to pointers.
   }

   pnptr = ^nptr;
   pnpproc = ^npproc;

   ppnint8 = ^pnint8;
   ppnuint8 = ^pnuint8;
   ppnint16 = ^pnint16;
   ppnuint16 = ^pnuint16;
   ppnint32 = ^pnint32;
   ppnuint32 = ^pnuint32;
   {$IFDEF nint64_type}
      {--- typedef pnint64   N_FAR *  ppnint64;
      typedef pnuint64  N_FAR *  ppnuint64; ---}
   {$ENDIF}
   ppnint = ^pnint;
   ppnuint = ^pnuint;
   ppnflag8 = ^pnflag8;
   ppnflag16 = ^pnflag16;
   {-----ppnflag32 = ^pnflag32;-----}
   ppnbool = ^pnbool;
   ppnbool8 = ^pnbool8;
   ppnbool16 = ^pnbool16;
   ppnbool32 = ^pnbool32;
   ppnfixed = ^pnfixed;
   pppnstr = ^ppnstr;
   pppnstr16 = ^ppnstr16;
   pppnstr8 = ^ppnstr8;
   pppnchar = ^ppnchar;
   pppnchar16 = ^ppnchar16;
   pppnchar8 = ^ppnchar8;
   pppnwchar = ^ppnwchar;
   ppnreal = ^pnreal;
   ppnreal32 = ^pnreal32;
   ppnreal64 = ^pnreal64;
   {$IFDEF nreal80_type}
      {--- typedef pnreal80  N_FAR *  ppnreal80; ----}
   {$ENDIF}
   {-----ppnid = ^pnid;-----}
   {-----ppnhdl = ^pnhdl;-----}
   {-----ppnparam = ^pnparam;-----}
   ppnptr = ^pnptr;
   ppnpproc = ^pnpproc;

   {
      Section 4c: GUI structures - Removed
   }

   {
      Section 4d: Platform dependent types
   }

   {$IFDEF N_PLAT_MSW}
      {-----typedef unsigned char N_HUGE *   neptr;-----}
   {$ELSE}
      {$IFDEF N_PLAT_MAC}
         {--- typedef unsigned char N_HUGE *   neptr; ---}
      {--- #elif defined( N_PLAT_UNIX ) ---}
         {--- typedef unsigned char N_HUGE *   neptr; ---}
      {--- #elif defined( N_PLAT_OS2 ) ---}
         {--- typedef unsigned char N_HUGE *   neptr; ---}
      {--- #elif defined( N_PLAT_DOS ) ---}
         {--- typedef unsigned char N_HUGE *   neptr; ---}
      {--- #elif defined( N_PLAT_NLM ) ---}
      {
         We just need to include NLM in our thinking
      }
         {--- typedef unsigned char N_HUGE *   neptr; ---}
      {$ELSE}    { This should not be reached because it was already }
                 { tested earlier. }
         #error A platform must be defined
      {$ENDIF}
   {$ENDIF}   { MSW or MAC or UNIX or OS2 undefined }

   {
      Pointers to scalars.
   }

   {-----typedef neptr       N_FAR * pneptr;-----}
{$ENDIF} { ! N_RC_INVOKED }

   {
      Section 5: Macros - Not appropriate for Delphi
   }

{$ENDIF} { !NTYPES_H }


