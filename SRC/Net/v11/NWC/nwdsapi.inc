(******************************************************************************
  Source module name:  
  Release Version:     

  %name: nwdsapi.h %
  %version: 5 %
  %date_modified: Fri Oct  3 17:56:17 1997 %
  $Copyright:

  Copyright (c) 1989-1996 Novell, Inc.  All Rights Reserved.                      

  THIS WORK IS  SUBJECT  TO  U.S.  AND  INTERNATIONAL  COPYRIGHT  LAWS  AND
  TREATIES.   NO  PART  OF  THIS  WORK MAY BE  USED,  PRACTICED,  PERFORMED
  COPIED, DISTRIBUTED, REVISED, MODIFIED, TRANSLATED,  ABRIDGED, CONDENSED,
  EXPANDED,  COLLECTED,  COMPILED,  LINKED,  RECAST, TRANSFORMED OR ADAPTED
  WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC. ANY USE OR EXPLOITATION
  OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT THE PERPETRATOR TO
  CRIMINAL AND CIVIL LIABILITY.$

 *****************************************************************************)


{$IFNDEF __NWDSAPI_H__}

{$DEFINE __NWDSAPI_H__}
{$IFDEF  N_PLAT_NLM }
    (*
 ===============================================================================
 = This version of NWNET.H is specifically for use under NetWare 386 with the
 = Directory Services API library, 'DSAPI.NLM.' It should be included by users
 = of this library before any other includes prefixed with 'NWDS.'
 ===============================================================================
*)
    (* Fight nwfattr.h for the file attribute defines first.... *)
    {$IFNDEF  _NWFATTR_H_ }
        {$I nwtypes.inc}
        {$I nwfattr.inc}
        {$UNDEF FA_NORMAL}
        {$UNDEF FA_HIDDEN}
        {$UNDEF FA_SYSTEM}
    {$ENDIF}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    (* nwalias.h defines NWCONN_TYPE, NWSTATUS, NWOBJ_TYPE for us *)
    {$IFNDEF  NWALIAS_H }
        {$I nwalias.inc}
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
    (* nwdstype defines NWDSCODE for us *)
    {$IFNDEF  NWDSTYPE_H }
        {$I nwdstype.inc}
    {$ENDIF}
    {$IFNDEF NWCONN_ID}
    Type NWCONN_ID = nuint;
    {$ENDIF}
    {$IFNDEF NWCONN_NUM_BYTE}
    Type NWCONN_NUM_BYTE = byte;
    {$ENDIF}
    {$IFNDEF NWDSDEFS_H}
    {$I NWDSDefs.inc}
    Const
    SMF70 = 1;
    SMF71 = 2;
    SMTP = 3;
    X400 = 4;
    SNADS = 5;
    PROFS = 6;
    Type EMAIL_ADDRESS_TYPE = 0..6;
    {$DEFINE DS_TYPES_REQUIRED}
    Const DS_TYPES_REQUIRED = $0010;
    {$ENDIF}
    {$IFNDEF __NWDSERR_H}
    {$I NWDSErr.inc}
    {$ENDIF}
    {$IFNDEF NWDSNAME_H}
    {$I NWDSName.inc}
    {$ENDIF}
    {$IFNDEF NWDSFILT_H}
    {$I NWDSFilt.inc}
    {$ENDIF}
    {$IFNDEF NWDSMISC_H}
    {$I NWDSMisc.inc}
    {$ENDIF}
    {$IFNDEF NWDSACL_H}
    {$I NWDSACL.inc}
    {$ENDIF}
    {$IFNDEF NWDSAUD_H}
    {$I NWDSAud.inc}
    {$ENDIF}
    {$IFNDEF NWDSDSA_H}
    {$I NWDSDSA.inc}
    {$ENDIF}
    {$IFNDEF NWDSSCH_H}
    {$I NWDSSch.inc}
    {$ENDIF}
    {$IFNDEF NWDSATTR_H}
    {$I NWDSAttr.inc}
    {$ENDIF}
    {$IFNDEF NWDSASA_H}
    {$I NWDSASA.inc}
    {$DEFINE GENERATE_CERTIFICATION_KP_F}
    Const GENERATE_CERTIFICATION_KP_F = 1;
    {$ENDIF}
    {$IFNDEF NWDSPART_H}
    {$I NWDSPart.inc}
    {$ENDIF}
    {$IFNDEF NWDSBUFT_H}
    {$I NWDSBufT.inc}
    {$ENDIF}
    {$IFNDEF NWDSNMTP_H}
    {$I NWDSNMTP.inc}
    {$ENDIF}
    {$IFNDEF UNICODE_H}
    {$I Unicode.inc}
    {$DEFINE DONT_USE_NOMAP_CHAR}
    Const DONT_USE_NOMAP_CHAR = 0;
    {$DEFINE USE_NOMAP_CHAR}
    Const USE_NOMAP_CHAR = 1;
    {$ENDIF}
    (* Not implemented Function NWDSLoginAsServer (
        context  :   NWDSContextHandle 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (*==============================================================================
** NLM-specific error codes which may be returned from Directory Services calls.
** For principal Directory Services error codes, see file NWDSErr.h.
**==============================================================================
*)
    {$DEFINE ERR_BAD_SERVICE_CONNECTION}
    Const ERR_BAD_SERVICE_CONNECTION = 400;
    {$DEFINE ERR_BAD_NETWORK}
    Const ERR_BAD_NETWORK = 401;
    {$DEFINE ERR_BAD_ADDRESS}
    Const ERR_BAD_ADDRESS = 402;
    {$DEFINE ERR_SLOT_ALLOCATION}
    Const ERR_SLOT_ALLOCATION = 403;
    {$DEFINE ERR_BAD_BROADCAST}
    Const ERR_BAD_BROADCAST = 404;
    {$DEFINE ERR_BAD_SERVER_NAME}
    Const ERR_BAD_SERVER_NAME = 405;
    {$DEFINE ERR_BAD_USER_NAME}
    Const ERR_BAD_USER_NAME = 406;
    {$DEFINE ERR_NO_MEMORY}
    Const ERR_NO_MEMORY = 408;
    {$DEFINE ERR_BAD_SOCKET}
    Const ERR_BAD_SOCKET = 410;
    {$DEFINE ERR_TAG_ALLOCATION}
    Const ERR_TAG_ALLOCATION = 411;
    {$DEFINE ERR_CONNECTION_ABORTED}
    Const ERR_CONNECTION_ABORTED = 412;
    {$DEFINE ERR_TIMEOUT}
    Const ERR_TIMEOUT = 413;
    {$DEFINE ERR_CHECKSUM}
    Const ERR_CHECKSUM = 414;
    {$DEFINE ERR_NO_FRAGMENT_LIST}
    Const ERR_NO_FRAGMENT_LIST = 415;
{$ENDIF}

{$ENDIF}


