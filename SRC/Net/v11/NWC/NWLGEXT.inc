(****************************************************************************
  Source module name:  nwlgext.h
  Release Version:     1.00

  $Workfile:   nwlgext.h  $
  $Revision:   $
  $Modtime::   $
  $Copyright:

  Copyright (c) 1989-1997 Novell, Inc.  All Rights Reserved.                      
  Patent Pending -- Novell, Inc.

  THIS WORK IS  SUBJECT  TO  U.S.  AND  INTERNATIONAL  COPYRIGHT  LAWS  AND
  TREATIES.   NO  PART  OF  THIS  WORK MAY BE  USED,  PRACTICED,  PERFORMED
  COPIED, DISTRIBUTED, REVISED, MODIFIED, TRANSLATED,  ABRIDGED, CONDENSED,
  EXPANDED,  COLLECTED,  COMPILED,  LINKED,  RECAST, TRANSFORMED OR ADAPTED
  WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC. ANY USE OR EXPLOITATION
  OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT THE PERPETRATOR TO
  CRIMINAL AND CIVIL LIABILITY.$

****************************************************************************)

{$IFNDEF NWLOGIN_H}

{$I nwlogin.inc}
{$ENDIF}


{$IFNDEF NWLGEXT_H}

{$DEFINE NWLGEXT_H}

{$IFDEF __cplusplus}

(* TC extern C *)
{$ENDIF}


Type
    tagNWLGLoginExtInfo = Record
        loginExtIDLen  :   nint ;
        loginExtID  :   pnstr ;
        loginExtDLLNameLen  :   nint ;
        loginExtDLLName  :   pnstr ;
        loginExtDescLen  :   nint ;
        loginExtDesc  :   pnstr ;
        loginExtType  :   DWORD ;
    End;
    NWLGLoginExtInfo = tagNWLGLoginExtInfo;


Type pNWLGLoginExtInfo  =  ^NWLGLoginExtInfo;

(* some arbitrary limits set by API *)

{$DEFINE LOGIN_EXT_MAX_ID_BYTES}
Const LOGIN_EXT_MAX_ID_BYTES = 32;
(* ct Type LOGIN_EXT_MAX_DLL_NAME = MAX_PATH; *)
{$DEFINE LOGIN_EXT_MAX_DESC}
Const LOGIN_EXT_MAX_DESC = 64;

(* definitions valid for loginExtType *)

{$DEFINE LOGIN_EXT_UI}
Const LOGIN_EXT_UI = $0001;
{$DEFINE LOGIN_EXT_AUTHENTICATE}
Const LOGIN_EXT_AUTHENTICATE = $0002;
{$DEFINE LOGIN_EXT_SCRIPT}
Const LOGIN_EXT_SCRIPT = $0004;
{$DEFINE LOGIN_EXT_ALL}
Const LOGIN_EXT_ALL = $00FF;

{$DEFINE LOGIN_EXT_MANDATORY}
Const LOGIN_EXT_MANDATORY = $0100;
{$DEFINE LOGIN_EXT_OPTIONAL}
Const LOGIN_EXT_OPTIONAL = $0200;

{$DEFINE LOGIN_EXT_SECONDARY}
Const LOGIN_EXT_SECONDARY = $4000;
{$DEFINE LOGIN_EXT_MASTER}
Const LOGIN_EXT_MASTER = $8000;

(* Login extension init (registration) entry point *)

Function NWLoginExtInit (
    Var pAccess  : pNWLGAccessRec;
    pCompiledVersion  :   pNWVersion ;
    pRuntimeVersion  :   pNWVersion ;
    reserved1  :   nptr ;
    reserved2  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* Function NWLGLoginExtRegOpen (
    Var hKey  : HKEY
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)


Function NWLGLoginExtRegGet (
    Var iSubKey  : DWORD;
    loginExtInfo  :   pNWLGLoginExtInfo 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWLGLoginExtRegWrite (
  xyz :  pNWLGLoginExtInfo    
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWLGLoginExtRegDelete (
    loginExtInfo  :   pNWLGLoginExtInfo 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}

{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}

{$ENDIF}

