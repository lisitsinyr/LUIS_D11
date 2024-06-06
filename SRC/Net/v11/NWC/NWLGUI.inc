(****************************************************************************
  Source module name:  nwlgui.h
  Release Version:     1.00

  $Workfile:   nwlgui.h  $
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


{$IFNDEF NWLGUI_H}

{$DEFINE NWLGUI_H}

{$IFDEF __cplusplus}

(* TC extern C *)
{$ENDIF}


{$DEFINE NWLGUI_MAJOR_VER}
Const NWLGUI_MAJOR_VER = 1;
{$DEFINE NWLGUI_MINOR_VER}
Const NWLGUI_MINOR_VER = 0;
{$DEFINE NWLGUI_REV_VER}
Const NWLGUI_REV_VER = 4;

(* TC #define NWLGUISetVersionP ( pVersion ) pVersion - > major = NWLGUI_MAJOR_VER ; pVersion - > minor = NWLGUI_MINOR_VER ; pVersion - > revision = NWLGUI_REV_VER ;  *)
(* TC #define NWLGUISetVersion ( version ) version . major = NWLGUI_MAJOR_VER ; version . minor = NWLGUI_MINOR_VER ; version . revision = NWLGUI_REV_VER ;  *)

(* TC #define NWLGUIVersionLong ( version ) ( unsigned long ) ( version . major * 1000000L + version . minor * 1000 + version . revision )  *)
(* TC #define NWLGUIVersionLongP ( pVersion ) ( unsigned long ) ( pVersion - > major * 1000000L + pVersion - > minor * 1000 + pVersion - > revision )  *)
(* TC #define NWLGUIVersionLongV ( major , minor , revision ) ( unsigned long ) ( major * 1000000L + minor * 1000 + revision )  *)
(* TC #define NWLGUI_CURRENT_VERSION NWLGUIVersionLongV ( NWLGUI_MAJOR_VER , NWLGUI_MINOR_VER , NWLGUI_REV_VER )  *)


{$DEFINE NWLG_IO_SET_FIELDS}
Const NWLG_IO_SET_FIELDS = 100;

Type NWLG_USAGE_FLAG  =   nint8 ;

(* NOTE: NWLG_USAGE_FLAGS are *NOT* boolean *)

{$DEFINE NWLG_OPTION_SAVED}
Const NWLG_OPTION_SAVED = $00;
{$DEFINE NWLG_OPTION_ON}
Const NWLG_OPTION_ON = $01;
{$DEFINE NWLG_OPTION_OFF}
Const NWLG_OPTION_OFF = $02;

(* Script Tabs (OR these together.) *)

{$DEFINE NWLG_TABS_SAVED}
Const NWLG_TABS_SAVED = $00;
{$DEFINE NWLG_LOGIN_TAB}
Const NWLG_LOGIN_TAB = $01;
{$DEFINE NWLG_CONNECTION_TAB}
Const NWLG_CONNECTION_TAB = $02;
{$DEFINE NWLG_SCRIPT_TAB}
Const NWLG_SCRIPT_TAB = $04;
{$DEFINE NWLG_VARIABLES_TAB}
Const NWLG_VARIABLES_TAB = $08;
{$DEFINE NWLG_ALL_TABS}
Const NWLG_ALL_TABS = NWLG_USAGE_FLAG($FF);

(* For skipUI only. *)

{$DEFINE NWLG_DISABLE_UI}
Const NWLG_DISABLE_UI = $04;
(* If not used, UI comes up if login fails on first try	*)

{$IFDEF  __BORLANDC__ }
    (* TC pragma *)
{$ELSE} {$IFDEF  N_ARCH_16 }
    (* TC pragma *)
{$ELSE}
    (* TC pragma *)
{$ENDIF}
{$ENDIF}


Type
    tagNWLGUIStartInfo = Record
        (* Options that may override registry. *)
        skipUI  :   NWLG_USAGE_FLAG ;
        autoClose  :   NWLG_USAGE_FLAG ;
        saveOnExit  :   NWLG_USAGE_FLAG ;
        treeLogin  :   NWLG_USAGE_FLAG ;
        notebookTabs  :   NWLG_USAGE_FLAG ;
        hEvent  :   Long ;
        (* Initial state of options.  (Overrides info in NWLGStartInfo.)		*)
        binderyConnOption  :   NWLG_USAGE_FLAG ;
        clearConnsOption  :   NWLG_USAGE_FLAG ;
        runScriptsOption  :   NWLG_USAGE_FLAG ;
        APIVersion  :   NWVersion ;
        access  :   NWLGAccessRec ;
        pSystemData  :   nptr ;
        pData  :   nptr ;
        displayResults  :   NWLG_USAGE_FLAG ;
        treeHistoryList  :   pNWLGStringElement ;
        serverHistoryList  :   pNWLGStringElement ;
        contextHistoryList  :   pNWLGStringElement ;
        scriptHistoryList  :   pNWLGStringElement ;
        profileHistoryList  :   pNWLGStringElement ;
    End;
    NWLGUIStartInfo = tagNWLGUIStartInfo;


Type pNWLGUIStartInfo  =  ^NWLGUIStartInfo;

{$IFDEF  __BORLANDC__ }
    (* TC pragma *)
{$ELSE}
    (* TC pragma *)
{$ENDIF}


(* End of UIStartInfo                                                      *)

(***************************************************************************)


Function NWLoginUI (
    lpszCmdLine  :   pnstr ;
    startInfo  :   pNWLGStartInfo ;
    uiInfo  :   pNWLGUIStartInfo 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* pNWLoginUI is a typedef for type of function NWLoginUI is. *)

Type pNWLoginUI = Function (
    lpszCmdLine  :   pnstr ;
    startInfo  :   pNWLGStartInfo ;
    uiInfo  :   pNWLGUIStartInfo 
) : NWCCODE;

{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}

{$ENDIF}

