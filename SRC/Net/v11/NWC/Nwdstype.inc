
(*---------------------------------------------------------------------------
   Source module name:  nwdstype.h
   Header Revision:     1.9
   
   $Workfile:   nwdstype.inc  $
   $Revision:   1.0  $
   $Modtime::   28 Sep 1995 15:41:16                        $
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


{$IFNDEF NWDSTYPE_H}
{$DEFINE NWDSTYPE_H}

Type
   uint32 = LongInt;      (* No unsigned 32-bit type *)
   int32 = LongInt;
   uint16 = Word;
   int16 = SmallInt;
   uint8 = Byte;
   int8 = ShortInt;
   LPSTR = pnuint8;
   LPCSTR = pnuint8;
   LPARAM = pnuint32;
   HINSTANCE = pnuint32;
   HBITMAP = pnuint32;
   HWND = pnuint32;
   HMENU = pnuint32;
   HICON = pnuint32;
   BOOL = pnuint32;
   UINT = pnuint32;


   time_t = LongInt;

{$IFNDEF SIZE_T}
{$DEFINE SIZE_T}
size_t = Cardinal;
psize_t = ^size_t;
ppsize_t = ^psize_t;
{$ENDIF}

{$IFNDEF NWDSCCODE}
{$DEFINE NWDSCCODE}
   NWDSCCODE = Integer;
{$ENDIF}

{$IFNDEF NWUNSIGNED}
{$DEFINE NWUNSIGNED}
   NWUNSIGNED = Cardinal;
{$ENDIF}

{$ENDIF} (* NWDSTYPE_H *)


