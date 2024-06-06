(******************************************************************************

  %name: nwcaldef.h %
  %version: 4 %
  %date_modified: Wed Dec 18 12:05:47 1996 %
  $Copyright:

  Copyright (c) 1989-1995 Novell, Inc.  All Rights Reserved.                      

  THIS WORK IS  SUBJECT  TO  U.S.  AND  INTERNATIONAL  COPYRIGHT  LAWS  AND
  TREATIES.   NO  PART  OF  THIS  WORK MAY BE  USED,  PRACTICED,  PERFORMED
  COPIED, DISTRIBUTED, REVISED, MODIFIED, TRANSLATED,  ABRIDGED, CONDENSED,
  EXPANDED,  COLLECTED,  COMPILED,  LINKED,  RECAST, TRANSFORMED OR ADAPTED
  WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC. ANY USE OR EXPLOITATION
  OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT THE PERPETRATOR TO
  CRIMINAL AND CIVIL LIABILITY.$

 *****************************************************************************)


{$IFNDEF  NWCALDEF_H }
    {$DEFINE NWCALDEF_H}
    {$IFDEF N_PLAT_NLM}
    {$IFNDEF  _NWFATTR_H_ }
        {$I nwtypes.inc}
        {$I nwfattr.inc}
        {$ENDIF}
        {$UNDEF FA_NORMAL}
        {$UNDEF FA_HIDDEN}
        {$UNDEF FA_SYSTEM}
    {$ENDIF}
    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
(*    {$IFNDEF NWPASCAL}
    Type NWPASCAL = N_PASCAL;
    {$ENDIF}
    {$IFNDEF NWFAR}
    Type NWFAR = N_FAR;
    {$ENDIF}  *)
    Type NWCONN_HANDLE = nuint;
    Type pNWCONN_HANDLE = pnuint;
    Type NWCONN_NUM = nuint16;
    Type NWCCODE = nuint;
    Type NWDIR_HANDLE = nuint8;
    (*
Changes to this structure need to be mirrored in 
internal header nwclient.h.  Would be nice to have
win31 and OS/2 be defined as HFILE.  Need to look
into that a little more.
*)
    {$IFDEF  N_PLAT_MSW }
    {$IFDEF  N_ARCH_32 }
        Type NWFILE_HANDLE = nptr;
    {$ELSE} {$IFDEF  N_PLAT_OS2 }
        NWFILE_HANDLE = nuint;
    {$ELSE}
        Type NWFILE_HANDLE = nint;
    {$ENDIF}
    {$ENDIF}
    {$ELSE} {$IFDEF  N_PLAT_OS2 }
        Type NWFILE_HANDLE = nint;

    {$ELSE}
        Type NWFILE_HANDLE = nint;
    {$ENDIF}
    {$ENDIF}
    {$IFNDEF  __WINDOWS_H }
    {$IFNDEF  _INC_WINDOWS }
    {$IFNDEF  __WIN386_INCLUDED__ }
        {$IFNDEF  BYTE }
        {$IFNDEF  OS2DEF_INCLUDED }
            Type BYTE = nuint8;
        {$ENDIF}
        {$ENDIF}
        {$IFNDEF WORD}
        Type WORD = nuint16;
        {$ENDIF}
        {$IFNDEF DWORD}
        Type DWORD = nuint32;
        {$ENDIF}
        {$IFNDEF LONG}
        Type LONG = nuint32;
        {$ENDIF}
    {$ENDIF}
    {$ENDIF}
    {$ENDIF}
    {$IFNDEF FA_READ_ONLY}
    {$DEFINE FA_NORMAL}
    Const FA_NORMAL = $00;
    {$DEFINE FA_READ_ONLY}
    Const FA_READ_ONLY = $01;
    {$DEFINE FA_HIDDEN}
    Const FA_HIDDEN = $02;
    {$DEFINE FA_SYSTEM}
    Const FA_SYSTEM = $04;
    {$DEFINE FA_EXECUTE_ONLY}
    Const FA_EXECUTE_ONLY = $08;
    {$DEFINE FA_DIRECTORY}
    Const FA_DIRECTORY = $10;
    {$DEFINE FA_NEEDS_ARCHIVED}
    Const FA_NEEDS_ARCHIVED = $20;
    {$DEFINE FA_SHAREABLE}
    Const FA_SHAREABLE = $80;
    (* Extended file attributes *)
    {$DEFINE FA_TRANSACTIONAL}
    Const FA_TRANSACTIONAL = $10;
    {$DEFINE FA_INDEXED}
    Const FA_INDEXED = $20;
    {$DEFINE FA_READ_AUDIT}
    Const FA_READ_AUDIT = $40;
    {$DEFINE FA_WRITE_AUDIT}
    Const FA_WRITE_AUDIT = $80;
    {$ENDIF}
    (* the following is a the correct attribute mask list *)
    (* The difference between these and the FA_ constants above is that these
   are in the correct positions. The last four attributes above are 8 bits
   off. (They need to be shifted 8 bits to the left.) *)
    {$IFNDEF A_NORMAL}
    {$DEFINE A_NORMAL}
    Const A_NORMAL = $00000000;
    {$DEFINE A_READ_ONLY}
    Const A_READ_ONLY = $00000001;
    {$DEFINE A_HIDDEN}
    Const A_HIDDEN = $00000002;
    {$DEFINE A_SYSTEM}
    Const A_SYSTEM = $00000004;
    {$DEFINE A_EXECUTE_ONLY}
    Const A_EXECUTE_ONLY = $00000008;
    {$DEFINE A_DIRECTORY}
    Const A_DIRECTORY = $00000010;
    {$DEFINE A_NEEDS_ARCHIVED}
    Const A_NEEDS_ARCHIVED = $00000020;
    {$DEFINE A_SHAREABLE}
    Const A_SHAREABLE = $00000080;
    {$DEFINE A_DONT_SUBALLOCATE}
    Const A_DONT_SUBALLOCATE = $00000800;
    {$DEFINE A_TRANSACTIONAL}
    Const A_TRANSACTIONAL = $00001000;
    {$DEFINE A_INDEXED}
    Const A_INDEXED = $00002000;
    {$DEFINE A_READ_AUDIT}
    Const A_READ_AUDIT = $00004000;
    {$DEFINE A_WRITE_AUDIT}
    Const A_WRITE_AUDIT = $00008000;
    {$DEFINE A_IMMEDIATE_PURGE}
    Const A_IMMEDIATE_PURGE = $00010000;
    {$DEFINE A_RENAME_INHIBIT}
    Const A_RENAME_INHIBIT = $00020000;
    {$DEFINE A_DELETE_INHIBIT}
    Const A_DELETE_INHIBIT = $00040000;
    {$DEFINE A_COPY_INHIBIT}
    Const A_COPY_INHIBIT = $00080000;
    {$DEFINE A_FILE_MIGRATED}
    Const A_FILE_MIGRATED = $00400000;
    {$DEFINE A_DONT_MIGRATE}
    Const A_DONT_MIGRATE = $00800000;
    {$DEFINE A_IMMEDIATE_COMPRESS}
    Const A_IMMEDIATE_COMPRESS = $02000000;
    {$DEFINE A_FILE_COMPRESSED}
    Const A_FILE_COMPRESSED = $04000000;
    {$DEFINE A_DONT_COMPRESS}
    Const A_DONT_COMPRESS = $08000000;
    {$DEFINE A_CANT_COMPRESS}
    Const A_CANT_COMPRESS = $20000000;
    {$ENDIF}
    (* access rights attributes *)
    {$IFNDEF AR_READ_ONLY}
    {$DEFINE AR_READ}
    Const AR_READ = $0001;
    {$DEFINE AR_WRITE}
    Const AR_WRITE = $0002;
    {$DEFINE AR_READ_ONLY}
    Const AR_READ_ONLY = $0001;
    {$DEFINE AR_WRITE_ONLY}
    Const AR_WRITE_ONLY = $0002;
    {$DEFINE AR_DENY_READ}
    Const AR_DENY_READ = $0004;
    {$DEFINE AR_DENY_WRITE}
    Const AR_DENY_WRITE = $0008;
    {$DEFINE AR_COMPATIBILITY}
    Const AR_COMPATIBILITY = $0010;
    {$DEFINE AR_WRITE_THROUGH}
    Const AR_WRITE_THROUGH = $0040;
    {$DEFINE AR_OPEN_COMPRESSED}
    Const AR_OPEN_COMPRESSED = $0100;
    {$ENDIF}
    (* search attributes *)
    {$IFNDEF SA_HIDDEN}
    {$DEFINE SA_NORMAL}
    Const SA_NORMAL = $0000;
    {$DEFINE SA_HIDDEN}
    Const SA_HIDDEN = $0002;
    {$DEFINE SA_SYSTEM}
    Const SA_SYSTEM = $0004;
    {$DEFINE SA_SUBDIR_ONLY}
    Const SA_SUBDIR_ONLY = $0010;
    {$DEFINE SA_SUBDIR_FILES}
    Const SA_SUBDIR_FILES = $8000;
    {$DEFINE SA_ALL}
    Const SA_ALL = $8006;
    {$ENDIF}
    {$IFNDEF USE_NW_WILD_MATCH}
    {$DEFINE USE_NW_WILD_MATCH}
    Const USE_NW_WILD_MATCH = 0;
    {$ENDIF}
    {$IFNDEF USE_DOS_WILD_MATCH}
    {$DEFINE USE_DOS_WILD_MATCH}
    Const USE_DOS_WILD_MATCH = 1;
    {$ENDIF}
    (* Scope specifiers *)
    {$DEFINE GLOBAL}
    Const GLOBAL = 0;
    {$DEFINE PRIVATE}
    Const PRIVATE = 1;
    {$DEFINE MY_SESSION}
    Const MY_SESSION = 2;
    {$DEFINE ALL_SESSIONS}
    Const ALL_SESSIONS = 3;
{$ENDIF}

