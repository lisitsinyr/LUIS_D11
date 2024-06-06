(****************************************************************************
  Source module name:  nwlogin.h
  Release Version:     1.00

  $Workfile:   nwlogin.h  $
  $Revision:   1.49  $
  $Modtime::   31 Oct 1995 10:05:22                        $
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

{$DEFINE NWLOGIN_H}

{$IFNDEF NTYPES_H}

{$I ntypes.inc}
{$ENDIF}



{$IFNDEF  _WINDOWS_ }
{$IFNDEF  _INC_WINDOWS }
{$IFNDEF  __WINDOWS_H }
    {$IFDEF  N_PLAT_MSW3 }
//        Type HWND  =   nuint ;
    {$ENDIF}
    {$IFDEF  N_PLAT_MSW4 }
        Type HWND  =   nptr ;
    {$ELSE} {$IFDEF  N_PLAT_WNT }
        Type HWND  =   nptr ;
    {$ENDIF}
    {$ENDIF}
{$ENDIF}
{$ENDIF}
{$ENDIF}


{$IFNDEF NWCALDEF_H}

{$I nwcaldef.inc}
{$ENDIF}


{$IFNDEF __NWDSDEFS_H}

{$I nwdsdefs.inc}
{$ENDIF}


{$IFDEF  N_PLAT_WNT }
    {$IFNDEF  NWAPIDEF_H }
        {$I nwapidef.inc}
    {$ENDIF}
{$ENDIF}


{$IFNDEF _NWDSDC_HEADER_}

//{$I nwdsdc.inc}
{$ENDIF}


{$IFDEF __cplusplus}

(* TC extern C *)
{$ENDIF}


(*
	Event constants
   Command Line parsing events
*)


{$DEFINE NWLG_INITIALIZE}
Const NWLG_INITIALIZE = 0;
{$DEFINE NWLG_CMD_LINE_SERVICE}
Const NWLG_CMD_LINE_SERVICE = 1;
{$DEFINE NWLG_CMD_LINE_USER}
Const NWLG_CMD_LINE_USER = 2;
{$DEFINE NWLG_CMD_LINE_NS}
Const NWLG_CMD_LINE_NS = 3;
{$DEFINE NWLG_PRESCRIPT_CLS}
Const NWLG_PRESCRIPT_CLS = 4;
{$DEFINE NWLG_CMD_LINE_SCRIPT_FILE}
Const NWLG_CMD_LINE_SCRIPT_FILE = 5;
{$DEFINE NWLG_CMD_LINE_BIND_LOGIN}
Const NWLG_CMD_LINE_BIND_LOGIN = 6;
{$DEFINE NWLG_CMD_LINE_TREE}
Const NWLG_CMD_LINE_TREE = 7;
{$DEFINE NWLG_RESOLVE_USER_NAME}
Const NWLG_RESOLVE_USER_NAME = 8;
{$DEFINE NWLG_NO_BANNER}
Const NWLG_NO_BANNER = 9;
{$DEFINE NWLG_CMD_LINE_ARG_DONE}
Const NWLG_CMD_LINE_ARG_DONE = 10;
{$DEFINE NWLG_CMD_LINE_HELP}
Const NWLG_CMD_LINE_HELP = 11;

(*
	Script related events
*)

{$DEFINE NWLG_PRE_SCRIPTS}
Const NWLG_PRE_SCRIPTS = 12;
{$DEFINE NWLG_OPEN_SCRIPT}
Const NWLG_OPEN_SCRIPT = 13;
{$DEFINE NWLG_GET_SCRIPT_LINE}
Const NWLG_GET_SCRIPT_LINE = 14;
{$DEFINE NWLG_SCRIPT_BREAK}
Const NWLG_SCRIPT_BREAK = 15;
{$DEFINE NWLG_REWIND_SCRIPT}
Const NWLG_REWIND_SCRIPT = 16;
{$DEFINE NWLG_BIND_ATTACH}
Const NWLG_BIND_ATTACH = 17;
{$DEFINE NWLG_TERMINATE}
Const NWLG_TERMINATE = 18;
{$DEFINE NWLG_CLEAR_SCREEN}
Const NWLG_CLEAR_SCREEN = 19;
{$DEFINE NWLG_DOS_COMSPEC}
Const NWLG_DOS_COMSPEC = 20;
{$DEFINE NWLG_DS_CONTEXT}
Const NWLG_DS_CONTEXT = 21;
{$DEFINE NWLG_DISP_FILE}
Const NWLG_DISP_FILE = 22;
{$DEFINE NWLG_DOS_BREAK}
Const NWLG_DOS_BREAK = 23;
{$DEFINE NWLG_DOS_VERIFY}
Const NWLG_DOS_VERIFY = 24;
{$DEFINE NWLG_DRIVE}
Const NWLG_DRIVE = 25;
{$DEFINE NWLG_EXIT}
Const NWLG_EXIT = 26;
{$DEFINE NWLG_EXEC}
Const NWLG_EXEC = 27;
{$DEFINE NWLG_FIRE_PHASERS}
Const NWLG_FIRE_PHASERS = 28;
{$DEFINE NWLG_DISP_LTIME}
Const NWLG_DISP_LTIME = 29;
{$DEFINE NWLG_MACHINE}
Const NWLG_MACHINE = 30;
{$DEFINE NWLG_MEMBER_OF}
Const NWLG_MEMBER_OF = 31;
{$DEFINE NWLG_NO_DEFAULT}
Const NWLG_NO_DEFAULT = 32;
{$DEFINE NWLG_TERM_CMD}
Const NWLG_TERM_CMD = 33;
{$DEFINE NWLG_PAUSE}
Const NWLG_PAUSE = 34;
{$DEFINE NWLG_DOS_PC_COMPAT}
Const NWLG_DOS_PC_COMPAT = 35;
{$DEFINE NWLG_PROFILE}
Const NWLG_PROFILE = 36;
{$DEFINE NWLG_NOTHING}
Const NWLG_NOTHING = 37;
{$DEFINE NWLG_BIND_SCRIPT_SERVER}
Const NWLG_BIND_SCRIPT_SERVER = 38;
{$DEFINE NWLG_SET_ENV_VAR}
Const NWLG_SET_ENV_VAR = 39;
{$DEFINE NWLG_SYNC_TIME_FLAG}
Const NWLG_SYNC_TIME_FLAG = 40;
{$DEFINE NWLG_DOS_SWAP_PATH}
Const NWLG_DOS_SWAP_PATH = 41;
{$DEFINE NWLG_DISP_LINE}
Const NWLG_DISP_LINE = 42;
{$DEFINE NWLG_INCLUDE}
Const NWLG_INCLUDE = 43;
{$DEFINE NWLG_TREE_ATTACH}
Const NWLG_TREE_ATTACH = 44;
{$DEFINE NWLG_SWAP_CMD}
Const NWLG_SWAP_CMD = 45;
{$DEFINE NWLG_NO_SWAP_CMD}
Const NWLG_NO_SWAP_CMD = 46;
{$DEFINE NWLG_CHDIR}
Const NWLG_CHDIR = 47;
{$DEFINE NWLG_LOGOUT_ALL}
Const NWLG_LOGOUT_ALL = 48;
{$DEFINE NWLG_LOGOUT_ONE}
Const NWLG_LOGOUT_ONE = 49;
{$DEFINE NWLG_CONTINUE}
Const NWLG_CONTINUE = 50;

{$DEFINE NWLG_RUN_SCRIPT}
Const NWLG_RUN_SCRIPT = 60;
{$DEFINE NWLG_POST_SCRIPTS}
Const NWLG_POST_SCRIPTS = 61;
{$DEFINE NWLG_DISP_BANNER}
Const NWLG_DISP_BANNER = 62;

(*
	Connection Events
*)

{$DEFINE NWLG_CONN_GET}
Const NWLG_CONN_GET = 90;
{$DEFINE NWLG_CONN_AUTH}
Const NWLG_CONN_AUTH = 91;
{$DEFINE NWLG_CONN_EXPIRED}
Const NWLG_CONN_EXPIRED = 92;
{$DEFINE NWLG_SYNC_PWD_START}
Const NWLG_SYNC_PWD_START = 93;
{$DEFINE NWLG_SYNC_PWD_END}
Const NWLG_SYNC_PWD_END = 94;
{$DEFINE NWLG_SYNC_LIST_BLD}
Const NWLG_SYNC_LIST_BLD = 95;
{$DEFINE NWLG_SYNC_LIST_UPD}
Const NWLG_SYNC_LIST_UPD = 96;

{$DEFINE NWLG_PRE_LOGIN}
Const NWLG_PRE_LOGIN = 98;

{$DEFINE NWLG_ELSE}
Const NWLG_ELSE = 190;
{$DEFINE NWLG_END}
Const NWLG_END = 191;
{$DEFINE NWLG_GOTO}
Const NWLG_GOTO = 192;
{$DEFINE NWLG_IF}
Const NWLG_IF = 193;
{$DEFINE NWLG_IFDO}
Const NWLG_IFDO = 194;
{$DEFINE NWLG_LABEL}
Const NWLG_LABEL = 195;
{$DEFINE NWLG_MAP}
Const NWLG_MAP = 196;
{$DEFINE NWLG_SHIFT}
Const NWLG_SHIFT = 197;

(*
	Map events 
*)

(*	Individual map events *)

{$DEFINE NWLG_MAP_ADD}
Const NWLG_MAP_ADD = 200;
{$DEFINE NWLG_MAP_DEL}
Const NWLG_MAP_DEL = 201;
{$DEFINE NWLG_MAP_CHANGE}
Const NWLG_MAP_CHANGE = 202;
{$DEFINE NWLG_MAP_MOVE}
Const NWLG_MAP_MOVE = 203;
{$DEFINE NWLG_MAP_DISP}
Const NWLG_MAP_DISP = 204;
{$DEFINE NWLG_MAP_MSG}
Const NWLG_MAP_MSG = 205;
{$DEFINE NWLG_MAP_ERR}
Const NWLG_MAP_ERR = 206;

(*	detail map events from parser 
		summary events below are passed to event handler
*)

{$DEFINE NWLG_MAP_ADD_DRV}
Const NWLG_MAP_ADD_DRV = 210;
{$DEFINE NWLG_MAP_ADD_DRV_TO_SDRV}
Const NWLG_MAP_ADD_DRV_TO_SDRV = 211;
{$DEFINE NWLG_MAP_ADD_SRCH}
Const NWLG_MAP_ADD_SRCH = 212;
{$DEFINE NWLG_MAP_ADD_SRCH_TO_SDRV}
Const NWLG_MAP_ADD_SRCH_TO_SDRV = 213;
{$DEFINE NWLG_MAP_CHG_DRV_TO_SDRV}
Const NWLG_MAP_CHG_DRV_TO_SDRV = 214;
{$DEFINE NWLG_MAP_CHG_INS_DRV_TO_SDRV}
Const NWLG_MAP_CHG_INS_DRV_TO_SDRV = 215;
{$DEFINE NWLG_MAP_CHG_SRCH}
Const NWLG_MAP_CHG_SRCH = 216;
{$DEFINE NWLG_MAP_DEL_DRV}
Const NWLG_MAP_DEL_DRV = 217;
{$DEFINE NWLG_MAP_DEL_SRCH}
Const NWLG_MAP_DEL_SRCH = 218;
{$DEFINE NWLG_MAP_DISP_ALL_DRVS}
Const NWLG_MAP_DISP_ALL_DRVS = 219;
{$DEFINE NWLG_MAP_DISP_DRV}
Const NWLG_MAP_DISP_DRV = 220;
{$DEFINE NWLG_MAP_DISP_OFF}
Const NWLG_MAP_DISP_OFF = 221;
{$DEFINE NWLG_MAP_DISP_ON}
Const NWLG_MAP_DISP_ON = 222;
{$DEFINE NWLG_MAP_DISP_SRCH}
Const NWLG_MAP_DISP_SRCH = 223;
{$DEFINE NWLG_MAP_ERRORS_OFF}
Const NWLG_MAP_ERRORS_OFF = 224;
{$DEFINE NWLG_MAP_ERRORS_ON}
Const NWLG_MAP_ERRORS_ON = 225;
{$DEFINE NWLG_MAP_INS_SRCH}
Const NWLG_MAP_INS_SRCH = 226;
{$DEFINE NWLG_MAP_INS_SRCH_TO_SDRV}
Const NWLG_MAP_INS_SRCH_TO_SDRV = 227;
{$DEFINE NWLG_MAP_NEXT_DRV}
Const NWLG_MAP_NEXT_DRV = 228;

(*
   event types for extended script commands and to introduce some new hooks
   used by Mobile
*)

{$DEFINE NWLG_DISP_WIBBLE}
Const NWLG_DISP_WIBBLE = 300;
{$DEFINE NWLG_CAPTURE_PRINTER}
Const NWLG_CAPTURE_PRINTER = 301;
{$DEFINE NWLG_DCACHE_ADD}
Const NWLG_DCACHE_ADD = 302;
{$DEFINE NWLG_DCACHE_FIND}
Const NWLG_DCACHE_FIND = 303;

{$DEFINE NWLG_DO_GOTO}
Const NWLG_DO_GOTO = 305;

{$DEFINE NWLG_AVAILABLE_DRIVE}
Const NWLG_AVAILABLE_DRIVE = 309;
{$DEFINE NWLG_NOTIFY_PARENT_WINDOW}
Const NWLG_NOTIFY_PARENT_WINDOW = 310;
{$DEFINE NWLG_PARSE_SCRIPT_LINE}
Const NWLG_PARSE_SCRIPT_LINE = 311;
{$DEFINE NWLG_NOTIFY_LOGIN_NAMES}
Const NWLG_NOTIFY_LOGIN_NAMES = 312;
{$DEFINE NWLG_NOTIFY_PROGRESS}
Const NWLG_NOTIFY_PROGRESS = 313;
{$DEFINE NWLG_GET_LOCATION_NAME}
Const NWLG_GET_LOCATION_NAME = 314;
{$DEFINE NWLG_GET_FIRST_NETWORK_DRIVE}
Const NWLG_GET_FIRST_NETWORK_DRIVE = 315;

(*
   Event types for communication between extensions and default UI.
*)

{$DEFINE NWLG_UI_DATA_CHANGED}
Const NWLG_UI_DATA_CHANGED = 400;
(* Event types for NWLG_UI_DATA_CHANGED *)

{$DEFINE NWLG_UI_DC_USERNAME}
Const NWLG_UI_DC_USERNAME = $0101;
{$DEFINE NWLG_UI_DC_TREE_LOGIN}
Const NWLG_UI_DC_TREE_LOGIN = $0201;
{$DEFINE NWLG_UI_DC_TREE}
Const NWLG_UI_DC_TREE = $0202;
{$DEFINE NWLG_UI_DC_SERVER}
Const NWLG_UI_DC_SERVER = $0203;
{$DEFINE NWLG_UI_DC_BINDERY_CONN}
Const NWLG_UI_DC_BINDERY_CONN = $0204;
{$DEFINE NWLG_UI_DC_CONTEXT}
Const NWLG_UI_DC_CONTEXT = $0205;
{$DEFINE NWLG_UI_DC_CLEAR_CONNS}
Const NWLG_UI_DC_CLEAR_CONNS = $0206;
{$DEFINE NWLG_UI_DC_RUN_SCRIPTS}
Const NWLG_UI_DC_RUN_SCRIPTS = $0301;
{$DEFINE NWLG_UI_DC_DISPLAY_RESULTS}
Const NWLG_UI_DC_DISPLAY_RESULTS = $0302;
{$DEFINE NWLG_UI_DC_AUTO_CLOSE}
Const NWLG_UI_DC_AUTO_CLOSE = $0303;
{$DEFINE NWLG_UI_DC_LOGIN_SCRIPT}
Const NWLG_UI_DC_LOGIN_SCRIPT = $0304;
{$DEFINE NWLG_UI_DC_PROFILE_SCRIPT}
Const NWLG_UI_DC_PROFILE_SCRIPT = $0305;
{$DEFINE NWLG_UI_DC_VAR}
Const NWLG_UI_DC_VAR = $0400;
{$DEFINE NWLG_UI_DC_MOBILE_PROFILE}
Const NWLG_UI_DC_MOBILE_PROFILE = $4101;
{$DEFINE NWLG_UI_DC_CONNECT_OFFLINE}
Const NWLG_UI_DC_CONNECT_OFFLINE = $4102;
{$DEFINE NWLG_UI_DC_DEBUG_MODE}
Const NWLG_UI_DC_DEBUG_MODE = $4301;
{$DEFINE NWLG_UI_DC_VERBOSE_MODE}
Const NWLG_UI_DC_VERBOSE_MODE = $4302;

{$DEFINE NWLG_UNKNOWN}
Const NWLG_UNKNOWN = 999;
(*
	END OF Event constants
*)


(*
	NWLogin Shared Data identifier tags
*)

{$DEFINE NWLG_SD_SERVER}
Const NWLG_SD_SERVER = 1;
{$DEFINE NWLG_SD_USER}
Const NWLG_SD_USER = 2;
{$DEFINE NWLG_SD_NS}
Const NWLG_SD_NS = 3;
{$DEFINE NWLG_SD_CLS}
Const NWLG_SD_CLS = 4;
{$DEFINE NWLG_SD_SCRIPT_FILE}
Const NWLG_SD_SCRIPT_FILE = 5;
{$DEFINE NWLG_SD_BIND_LOGIN}
Const NWLG_SD_BIND_LOGIN = 6;
{$DEFINE NWLG_SD_TREE_NAME}
Const NWLG_SD_TREE_NAME = 7;
{$DEFINE NWLG_SD_SWAP_FLAG}
Const NWLG_SD_SWAP_FLAG = 8;
{$DEFINE NWLG_SD_SWAP_PATH}
Const NWLG_SD_SWAP_PATH = 9;
{$DEFINE NWLG_SD_NB}
Const NWLG_SD_NB = 10;

{$DEFINE NWLG_SD_ACCESS_SERVER}
Const NWLG_SD_ACCESS_SERVER = 11;
{$DEFINE NWLG_SD_AM_PM}
Const NWLG_SD_AM_PM = 12;
{$DEFINE NWLG_SD_DAY}
Const NWLG_SD_DAY = 13;
{$DEFINE NWLG_SD_DAY_OF_WEEK}
Const NWLG_SD_DAY_OF_WEEK = 14;
{$DEFINE NWLG_SD_ENVAR}
Const NWLG_SD_ENVAR = 15;
{$DEFINE NWLG_SD_FILE_SERVER}
Const NWLG_SD_FILE_SERVER = 16;
{$DEFINE NWLG_SD_FULL_NAME}
Const NWLG_SD_FULL_NAME = 17;
{$DEFINE NWLG_SD_GREETING_TIME}
Const NWLG_SD_GREETING_TIME = 18;
{$DEFINE NWLG_SD_HOUR}
Const NWLG_SD_HOUR = 19;
{$DEFINE NWLG_SD_HOUR24}
Const NWLG_SD_HOUR24 = 20;
{$DEFINE NWLG_SD_LAST_NAME}
Const NWLG_SD_LAST_NAME = 21;
{$DEFINE NWLG_SD_LOGIN_NAME}
Const NWLG_SD_LOGIN_NAME = 22;
{$DEFINE NWLG_SD_LOGIN_CONTEXT}
Const NWLG_SD_LOGIN_CONTEXT = 23;
{$DEFINE NWLG_SD_MACHINE}
Const NWLG_SD_MACHINE = 24;
{$DEFINE NWLG_SD_MINUTE}
Const NWLG_SD_MINUTE = 25;
{$DEFINE NWLG_SD_MONTH}
Const NWLG_SD_MONTH = 26;
{$DEFINE NWLG_SD_MONTH_NAME}
Const NWLG_SD_MONTH_NAME = 27;
{$DEFINE NWLG_SD_NDAY_OF_YEAR}
Const NWLG_SD_NDAY_OF_YEAR = 28;
{$DEFINE NWLG_SD_NET_ADDRESS}
Const NWLG_SD_NET_ADDRESS = 29;
{$DEFINE NWLG_SD_MAIL_STATUS}
Const NWLG_SD_MAIL_STATUS = 30;
{$DEFINE NWLG_SD_PASSWORD_EXPIRES}
Const NWLG_SD_PASSWORD_EXPIRES = 31;
{$DEFINE NWLG_SD_OS_VERSION}
Const NWLG_SD_OS_VERSION = 32;
{$DEFINE NWLG_SD_OS_NAME}
Const NWLG_SD_OS_NAME = 33;
{$DEFINE NWLG_SD_REQ_VERSION}
Const NWLG_SD_REQ_VERSION = 34;
{$DEFINE NWLG_SD_REQ_CONTEXT}
Const NWLG_SD_REQ_CONTEXT = 35;
{$DEFINE NWLG_SD_SECOND}
Const NWLG_SD_SECOND = 36;
{$DEFINE NWLG_SD_SHORT_YEAR}
Const NWLG_SD_SHORT_YEAR = 37;
{$DEFINE NWLG_SD_SHELL_VERSION}
Const NWLG_SD_SHELL_VERSION = 38;
{$DEFINE NWLG_SD_SHORT_MACHINE}
Const NWLG_SD_SHORT_MACHINE = 39;
{$DEFINE NWLG_SD_STATION}
Const NWLG_SD_STATION = 40;
{$DEFINE NWLG_SD_USER_OBJ}
Const NWLG_SD_USER_OBJ = 41;
{$DEFINE NWLG_SD_YEAR}
Const NWLG_SD_YEAR = 42;
{$DEFINE NWLG_SD_CL_USER}
Const NWLG_SD_CL_USER = 43;
{$DEFINE NWLG_SD_CL_SERVER}
Const NWLG_SD_CL_SERVER = 44;
{$DEFINE NWLG_SD_PROFILE}
Const NWLG_SD_PROFILE = 45;
{$DEFINE NWLG_SD_PASSWORD}
Const NWLG_SD_PASSWORD = 46;
{$DEFINE NWLG_SD_LOADPATH}
Const NWLG_SD_LOADPATH = 47;
{$DEFINE NWLG_SD_CMD_LINE_FLAGS}
Const NWLG_SD_CMD_LINE_FLAGS = 48;
{$DEFINE NWLG_SD_CMD_LINE_ARG}
Const NWLG_SD_CMD_LINE_ARG = 49;
{$DEFINE NWLG_SD_CONTEXT_HND}
Const NWLG_SD_CONTEXT_HND = 50;
{$DEFINE NWLG_SD_PC_COMPATIBLE}
Const NWLG_SD_PC_COMPATIBLE = 51;
{$DEFINE NWLG_SD_PRI_CONN_HANDLE}
Const NWLG_SD_PRI_CONN_HANDLE = 52;
{$DEFINE NWLG_SD_APP_INSTANCE_HND}
Const NWLG_SD_APP_INSTANCE_HND = 53;
{$DEFINE NWLG_SD_ERROR_LEVEL}
Const NWLG_SD_ERROR_LEVEL = 54;
{$DEFINE NWLG_SD_START_INFO}
Const NWLG_SD_START_INFO = 55;
{$DEFINE NWLG_SD_MULTI_TREE}
Const NWLG_SD_MULTI_TREE = 56;

(* Extensions to the Shared Data identifier tags for Mobile *)

{$DEFINE NWLG_SD_DISPLAY_ERRORS}
Const NWLG_SD_DISPLAY_ERRORS = 100;
{$DEFINE NWLG_SD_DISPLAY_MAPPINGS}
Const NWLG_SD_DISPLAY_MAPPINGS = 101;
{$DEFINE NWLG_SD_PARSED_NAME}
Const NWLG_SD_PARSED_NAME = 102;
{$DEFINE NWLG_SD_PARSED_STRING}
Const NWLG_SD_PARSED_STRING = 103;
{$DEFINE NWLG_SD_PARSED_CMD_TYPE}
Const NWLG_SD_PARSED_CMD_TYPE = 104;
{$DEFINE NWLG_SD_CL_SERVER_VERSION}
Const NWLG_SD_CL_SERVER_VERSION = 105;
{$DEFINE NWLG_SD_CL_SERVER_TYPE}
Const NWLG_SD_CL_SERVER_TYPE = 106;
{$DEFINE NWLG_SD_CL_TREE}
Const NWLG_SD_CL_TREE = 107;

(*
	END OF NWLogin Shared Data identifier tags
*)


(*
	Error codes
*)


{$DEFINE NWLG_ERR_VERSION}
Const NWLG_ERR_VERSION = $ff;

(*
	Return codes for handlers
*)

{$DEFINE NWLG_OK}
Const NWLG_OK = 0;
{$DEFINE NWLG_RETRY}
Const NWLG_RETRY = 1;
{$DEFINE NWLG_ABORT}
Const NWLG_ABORT = 2;
{$DEFINE NWLG_FAIL}
Const NWLG_FAIL = 3;
{$DEFINE NWLG_IGNORE}
Const NWLG_IGNORE = 4;
{$DEFINE NWLG_STOP_CYCLE}
Const NWLG_STOP_CYCLE = 5;
{$DEFINE NWLG_CANCEL}
Const NWLG_CANCEL = 6;
{$DEFINE NWLG_SHUT_DOWN}
Const NWLG_SHUT_DOWN = 7;
{$DEFINE NWLG_SHUT_DOWN_RESTART}
Const NWLG_SHUT_DOWN_RESTART = 8;

(*
	END OF Return codes for handlers
*)


Const NWLG_ON = N_TRUE;
Const NWLG_OFF = N_FALSE;

(*
	Command Line Flag masks (NWLG_SD_CMD_LINE_FLAGS)
*)


{$DEFINE NWLG_CL_FLAG_CLS}
Const NWLG_CL_FLAG_CLS = $00000001;
{$DEFINE NWLG_CL_FLAG_NS}
Const NWLG_CL_FLAG_NS = $00000002;
{$DEFINE NWLG_CL_FLAG_ATTACH}
Const NWLG_CL_FLAG_ATTACH = $00000002;
{$DEFINE NWLG_CL_FLAG_BIND}
Const NWLG_CL_FLAG_BIND = $00000004;
{$DEFINE NWLG_CL_FLAG_TREE}
Const NWLG_CL_FLAG_TREE = $00000008;

{$DEFINE NWLG_CL_FLAG_NB}
Const NWLG_CL_FLAG_NB = $00000010;
{$DEFINE NWLG_CL_FLAG_SWAP}
Const NWLG_CL_FLAG_SWAP = $00000020;
{$DEFINE NWLG_CL_FLAG_NOSWAP}
Const NWLG_CL_FLAG_NOSWAP = $00000040;
{$DEFINE NWLG_CL_FLAG_SCRIPT}
Const NWLG_CL_FLAG_SCRIPT = $00000080;

{$DEFINE NWLG_CL_FLAG_RDF}
Const NWLG_CL_FLAG_RDF = $00000100;
{$DEFINE NWLG_CL_FLAG_EXTFORK}
Const NWLG_CL_FLAG_EXTFORK = $00000200;
{$DEFINE NWLG_CL_FLAG_NO_DISPLAY}
Const NWLG_CL_FLAG_NO_DISPLAY = $00000400;
{$DEFINE NWLG_CL_FLAG_NA}
Const NWLG_CL_FLAG_NA = $00000800;

{$DEFINE NWLG_CL_FLAG_NO_CLOSE}
Const NWLG_CL_FLAG_NO_CLOSE = $00001000;
{$DEFINE NWLG_CL_FLAG_ADVANCED}
Const NWLG_CL_FLAG_ADVANCED = $00002000;
{$DEFINE NWLG_CL_FLAG_CONTINUE}
Const NWLG_CL_FLAG_CONTINUE = $00004000;
{$DEFINE NWLG_CL_FLAG_SIMPLE}
Const NWLG_CL_FLAG_SIMPLE = $00008000;

{$DEFINE NWLG_CL_FLAG_MAP_ROOT_OFF}
Const NWLG_CL_FLAG_MAP_ROOT_OFF = $00010000;
{$DEFINE NWLG_CL_FLAG_RUN_SCRIPT}
Const NWLG_CL_FLAG_RUN_SCRIPT = $20000000;
{$DEFINE NWLG_CL_FLAG_CLEAR_CONN}
Const NWLG_CL_FLAG_CLEAR_CONN = $40000000;
{$DEFINE NWLG_CL_FLAG_DEBUG}
Const NWLG_CL_FLAG_DEBUG = $80000000;

(* Map flags *)

{$DEFINE NWLG_MAP_FLAG_INSERT}
Const NWLG_MAP_FLAG_INSERT = $00000001;
{$DEFINE NWLG_MAP_FLAG_ROOT}
Const NWLG_MAP_FLAG_ROOT = $00000002;
{$DEFINE NWLG_MAP_FLAG_PHYSICAL}
Const NWLG_MAP_FLAG_PHYSICAL = $00000004;

(*
	Get Service connection type flags
*)

{$DEFINE NWLG_CONN_GET_DEFAULT}
Const NWLG_CONN_GET_DEFAULT = 0;
{$DEFINE NWLG_CONN_GET_SERVER}
Const NWLG_CONN_GET_SERVER = 1;
{$DEFINE NWLG_CONN_GET_TREE}
Const NWLG_CONN_GET_TREE = 2;

(*
	Message type and login process definitions.
	Allows room for future expansion and definitions
	Defines are used mainly for defining what type of messages are
	sent to IO routines.
	The first defines show what part of the login process we are in.
	The NWLG_MSGTYP_... are || with _PROC_ to indicate specific message type within
	process. Currently, the only one that is looked at is _MSGTYP_ERROR in
   IO event NWLG_IO_DATA_BLOCK
*)

{$DEFINE NWLG_PROC}
Const NWLG_PROC = $00ff;
{$DEFINE NWLG_PROC_INIT}
Const NWLG_PROC_INIT = $0000;
{$DEFINE NWLG_PROC_LOGIN}
Const NWLG_PROC_LOGIN = $0010;
{$DEFINE NWLG_PROC_SCRIPT}
Const NWLG_PROC_SCRIPT = $0020;
{$DEFINE NWLG_PROC_TERM}
Const NWLG_PROC_TERM = $0040;

{$DEFINE NWLG_MSGTYP}
Const NWLG_MSGTYP = $ff00;
{$DEFINE NWLG_MSGTYP_INFO}
Const NWLG_MSGTYP_INFO = $0100;
{$DEFINE NWLG_MSGTYP_ERROR}
Const NWLG_MSGTYP_ERROR = $0200;
{$DEFINE NWLG_MSGTYP_SCRIPT}
Const NWLG_MSGTYP_SCRIPT = $0400;

(************************ Handler definitions ********************)


(*
	I/O handler events
*)

{$DEFINE NWLG_IO_MSG_PAUSE}
Const NWLG_IO_MSG_PAUSE = 0;
{$DEFINE NWLG_IO_IDENTITY}
Const NWLG_IO_IDENTITY = 1;
{$DEFINE NWLG_IO_YES_NO}
Const NWLG_IO_YES_NO = 2;
{$DEFINE NWLG_IO_DATA_BLOCK}
Const NWLG_IO_DATA_BLOCK = 3;
{$DEFINE NWLG_IO_BANNER}
Const NWLG_IO_BANNER = 4;
{$DEFINE NWLG_IO_FILE}
Const NWLG_IO_FILE = 5;
{$DEFINE NWLG_IO_ERROR}
Const NWLG_IO_ERROR = 6;
{$DEFINE NWLG_IO_CLS}
Const NWLG_IO_CLS = 7;
{$DEFINE NWLG_IO_SOUNDS}
Const NWLG_IO_SOUNDS = 8;
{$DEFINE NWLG_IO_CHANGE_PWD}
Const NWLG_IO_CHANGE_PWD = 9;
{$DEFINE NWLG_IO_CONFIRM_REATTACH}
Const NWLG_IO_CONFIRM_REATTACH = 10;
{$DEFINE NWLG_IO_DOS_SWAP_PATH}
Const NWLG_IO_DOS_SWAP_PATH = 11;
{$DEFINE NWLG_IO_START_UI}
Const NWLG_IO_START_UI = 12;
{$DEFINE NWLG_IO_FINISH_UI}
Const NWLG_IO_FINISH_UI = 13;
{$DEFINE NWLG_IO_START_LOG}
Const NWLG_IO_START_LOG = 14;
{$DEFINE NWLG_IO_FINISH_LOG}
Const NWLG_IO_FINISH_LOG = 15;

{$DEFINE NWLG_IO_BRING_TO_FRONT}
Const NWLG_IO_BRING_TO_FRONT = 99;

(* IO routine optional extensions *)

{$DEFINE NWLG_IO_GET_DATA_LINE}
Const NWLG_IO_GET_DATA_LINE = 900;
{$DEFINE NWLG_IO_GET_DATA_BUF}
Const NWLG_IO_GET_DATA_BUF = 901;

{$IFDEF  N_PLAT_MSW }
    (*
   Special values for the progress to NWMLGUIUpdate().
   A positive integer indicates the line count of a disconnected script
*)
     NWLG_UIU_LOGIN_BEGIN =( - 1 );
     NWLG_UIU_LOGIN_PROPER_UPDATE =( - 2 );
     NWLG_UIU_SCRIPTS_BEGIN =( - 3 );
     NWLG_UIU_END_OF_SCRIPT =( - 4 );
     NWLG_UIU_ALL_PROCESSING_COMPLETE =( - 5 );
     NWLG_UIU_DISC_SCRIPT_LINE =( - 6 );
     NWLG_UIU_ABORTED_INCOMPLETE =( - 7 );
{$ENDIF}


(*
	Event manager return codes
*)


{$DEFINE NWLG_EVT_OK}
Const NWLG_EVT_OK = NWLG_OK;
{$DEFINE NWLG_EVT_RETRY}
Const NWLG_EVT_RETRY = NWLG_RETRY;
{$DEFINE NWLG_EVT_ABORT}
Const NWLG_EVT_ABORT = NWLG_ABORT;
{$DEFINE NWLG_EVT_FAIL}
Const NWLG_EVT_FAIL = NWLG_FAIL;
{$DEFINE NWLG_EVT_IGNORE}
Const NWLG_EVT_IGNORE = NWLG_IGNORE;
{$DEFINE NWLG_EVT_STOP_CYCLE}
Const NWLG_EVT_STOP_CYCLE = NWLG_STOP_CYCLE;
(*
	Event delivery types
*)


{$DEFINE NWLG_EVT_PRIVATE}
Const NWLG_EVT_PRIVATE = 1;
{$DEFINE NWLG_EVT_BROADCAST}
Const NWLG_EVT_BROADCAST = 2;
{$DEFINE NWLG_EVT_UNTIL_OK}
Const NWLG_EVT_UNTIL_OK = 3;
{$DEFINE NWLG_EVT_UNTIL_FAIL}
Const NWLG_EVT_UNTIL_FAIL = 4;

(*
   -> NT ONLY
   Defines for restartMode in startinfo structure.
   Normal processing is NONE. Initial login on Wnt require that we authenticate
   then roll out to login to the workstation. Login is then restarted after
   the authenticate.
   GINA flag indicates that GINA does initial login (password expiration handled
   differently)
*)

{$DEFINE NWLG_RESTART_NONE}
Const NWLG_RESTART_NONE = $0000;
{$DEFINE NWLG_RESTART_AUTH_ONLY}
Const NWLG_RESTART_AUTH_ONLY = $0001;
{$DEFINE NWLG_RESTART_SCRIPT}
Const NWLG_RESTART_SCRIPT = $0002;
{$DEFINE NWLG_RESTART_ALT_AUTH}
Const NWLG_RESTART_ALT_AUTH = $0004;
{$DEFINE NWLG_RESTART_GINA_AUTH}
Const NWLG_RESTART_GINA_AUTH = $8000;
{$DEFINE NWLG_RESTART_CITRIX_AUTH}
Const NWLG_RESTART_WS_ONLY = $0010;
{$DEFINE NWLG_RESTART_WS_ONLY}
Const NWLG_RESTART_CITRIX_AUTH = $0080;

(*
	Flag set/clear/test macros
*)


(* TC #define NWLGSetFlag ( flag , var ) ( ( var ) = ( flag ) | ( var ) )  *)
(* TC #define NWLGSetFlagP ( flag , pvar ) ( ( * pvar ) = ( flag ) | ( * pvar ) )  *)

(* TC #define NWLGClearFlag ( flag , var ) ( ( var ) = ( ( flag ) ) & ( var ) )  *)
(* TC #define NWLGClearFlagP ( flag , pvar ) ( ( * pvar ) = ( ( flag ) ) & ( * pvar ) )  *)

(* TC #define NWLGTestFlag ( flag , var ) ( ( ( var ) & ( flag ) ) ? N_TRUE : N_FALSE )  *)
(* TC #define NWLGTestFlagP ( flag , pvar ) ( ( ( * pvar ) & ( flag ) ) ? N_TRUE : N_FALSE )  *)

(*
   Version information
*)

{$DEFINE NWLG_MAJOR_VER}
Const NWLG_MAJOR_VER = 1;
{$DEFINE NWLG_MINOR_VER}
Const NWLG_MINOR_VER = 0;
{$DEFINE NWLG_REV_VER}
Const NWLG_REV_VER = 4;

(* TC #define NWLGSetVersionP ( pVersion ) pVersion - > major = NWLG_MAJOR_VER ; pVersion - > minor = NWLG_MINOR_VER ; pVersion - > revision = NWLG_REV_VER ;  *)
(* TC #define NWLGSetVersion ( version ) version . major = NWLG_MAJOR_VER ; version . minor = NWLG_MINOR_VER ; version . revision = NWLG_REV_VER ;  *)

(* TC #define NWLGVersionLong ( version ) ( unsigned long ) ( version . major * 1000000L + version . minor * 1000 + version . revision )  *)
(* TC #define NWLGVersionLongP ( pVersion ) ( unsigned long ) ( pVersion - > major * 1000000L + pVersion - > minor * 1000 + pVersion - > revision )  *)
(* TC #define NWLGVersionLongV ( major , minor , revision ) ( unsigned long ) ( major * 1000000L + minor * 1000 + revision )  *)
(* TC #define NWLG_CURRENT_VERSION NWLGUIVersionLongV ( NWLG_MAJOR_VER , NWLG_MINOR_VER , NWLG_REV_VER )  *)


Type pEvtHndlr = Function (
    pAccess  :   nptr ;
    event  :   nint ;
    eventType  :   nint ;
    eventSubType  :   nint ;
    param1  :   nparam ;
    param2  :   nparam ;
    flag  :   nflag32 
) : NWCCODE;


Type pIOHndlr = Function (
    pAccess  :   nptr ;
    ioEvent  :   nint ;
    param1  :   nparam ;
    param2  :   nparam ;
    flags  :   nflag32 
) : NWCCODE;



{$IFDEF  __BORLANDC__ }
    (* TC pragma *)
{$ELSE} {$IFDEF  N_ARCH_16 }
    (* TC pragma *)
{$ELSE}
    (* TC pragma *)
{$ENDIF}
{$ENDIF}


Type
    tagNWLGAccessRec = Record
        id  :   nid ;
        status  :   NWCCODE ;
        errCode  :   NWRCODE ;
        pEventHandler  :   pEvtHndlr ;
        pExceptionHandler  :   pEvtHndlr ;
        pIOHandler  :   pIOHndlr ;
        pUserData  :   nptr ;
    End;
    NWLGAccessRec = tagNWLGAccessRec;
Type pNWLGAccessRec  =  ^NWLGAccessRec;



Type
    tagNWVersion = Record
        major  :   nuint16 ;
        minor  :   nuint8 ;
        revision  :   nuint8 ;
    End;
    NWVersion = tagNWVersion;


Type pNWVersion  =  ^NWVersion;


(***************************************************************************)

(* Start up information structures                                         *)

(***************************************************************************)


(* Elemnts for a generic linked list where id contains the type of data *)

Type
    pNWLGStartInfoData  =  ^tagNWLGStartInfoData;
    tagNWLGStartInfoData = Record
        id  :   nuint32 ;
        next  :  pNWLGStartInfoData;
        data  :   nptr ;
    End;
    NWLGStartInfoData = tagNWLGStartInfoData;



(* Elements for a linked list of strings. *)

Type
    pNWLGStringElement  =  ^tagNWLGStringElement;
    tagNWLGStringElement = Record
        text  :   pnstr ;
        next  :  pNWLGStringElement;
    End;
    NWLGStringElement = tagNWLGStringElement;



(* linked list of command line args *)


Type
    pNWLGStartInfoCmdArgs  =  ^tagNWLGStartInfoCmdArgs;
    tagNWLGStartInfoCmdArgs = Record
        arg  :   pnstr ;
        next  :  pNWLGStartInfoCmdArgs;
    End;
    NWLGStartInfoCmdArgs = tagNWLGStartInfoCmdArgs;



Type
    tagNWLGStartInfo = Record
        {$IFDEF  N_PLAT_WNT }
            (* TC  NWCONN_HANDLE expiredConnID;  *)
            (* TC  nstr expiredPassword [ MAX_DN_BYTES ];  *)
            (* TC  nstr expiredServiceName [ NW_MAX_SERVER_NAME_BYTES ];  *)
            (* TC  nint expiredServiceType;  *)
            (* TC  nbool expiredDSbinderyServer;  *)
            (* TC  nbool expiredPrimaryLogin;  *)
            (* TC  nbool expiredWkstaPassword;  *)
            (* TC  nstr expiredWkstaNewPassword [ MAX_DN_BYTES ];  *)
        {$ENDIF}
        scriptUserLen  :   nint ;
        scriptUser  :   pnstr ;
        passwordLen  :   nint ;
        password  :   pnstr ;
        profileLen  :   nint ;
        profile  :   pnstr ;
        scriptFileLen  :   nint ;
        scriptFile  :   pnstr ;
        contextLen  :   nint ;
        context  :   pnstr ;
        bannerInfoLen  :   nint ;
        bannerInfo  :   pnstr ;
        swapPathLen  :   nint ;
        swapPath  :   pnstr ;
        cmdLine  :   pNWLGStartInfoCmdArgs ;
        noBanner  :   nbool ;
        bindery  :   nbool ;
        clearConns  :   nbool ;
        clearScreen  :   nbool ;
        singleTree  :   nbool ;
        restorePerm  :   nbool ;
        runScripts  :   nbool ;
        noSwap  :   nint ;
        debug  :   nint ;
        pData  :   nptr ;
        restartMode  :   nint ;
        disableLoginExt  :   nbool ;
        pReserved1  :   pEvtHndlr ;
        pReserved2  :   pEvtHndlr ;
        pReserved3  :   pEvtHndlr ;
    End;
    NWLGStartInfo = tagNWLGStartInfo;


Type pNWLGStartInfo  =  ^NWLGStartInfo;

(* IDs for items found in linked list 'dataList'									*)

{$DEFINE NWLGID_COMMAND_LINE}
Const NWLGID_COMMAND_LINE = $00000000;
{$DEFINE NWLGID_SI}
Const NWLGID_SI = $00000001;
{$DEFINE NWLGID_SI_ORIG}
Const NWLGID_SI_ORIG = $00000002;
{$DEFINE NWLGID_UI}
Const NWLGID_UI = $00000011;
{$DEFINE NWLGID_UI_ORIG}
Const NWLGID_UI_ORIG = $00000012;

(* End of StartInfo                                                        *)

(***************************************************************************)


Type
    tagNWLGMapRec = Record
        driveLetter  :   nchar ;
        searchOrder  :   nuint ;
        path  :   pnstr ;
    End;
    NWLGMapRec = tagNWLGMapRec;



Type pNWLGMapRec  =  ^NWLGMapRec;


(************************ NWLOGIN structures ********************)


Type
    tagNWLGUserIDStruct = Record
        context  :   nint32 ;
        server  :   pnstr ;
        user  :   pnstr ;
        password  :   pnstr ;
        changeServer  :   nbool ;
        DSLogin  :   nbool ;
        connID  :   NWCONN_HANDLE ;
        data  :   nptr ;
        flags  :   nflag32 ;
        tree  :   pnstr ;
        szContext  :   pnstr ;
        treeLogin  :   nbool ;
    End;
    NWLGUserID = tagNWLGUserIDStruct;


Type pNWLGUserID  =  ^NWLGUserID;

Type
    tagNWLGSrvcConnStruct = Record
        server  :   pnstr ;
        tree  :   pnstr ;
        serviceType  :   nint ;
        connType  :   pnint ;
        connID  :  ^NWCONN_HANDLE;
    End;
    NWLGSrvcConn = tagNWLGSrvcConnStruct;


Type pNWLGSrvcConn  =  ^NWLGSrvcConn;

(* Type
    tagNWLGScriptInfoStruct = Record
        idx  :   nint ;
        scriptNameLen  :   nint ;
        scriptName  :   pnstr ;
        len  :   nint ;
        line  :   pnstr ;
        scriptLineNum  :   nint ;
        crt  :   nbool ;
        OloginScript  :  ^CLoginScript;
    End;
    NWLGScriptInfo = tagNWLGScriptInfoStruct;


Type pNWLGScriptInfo  =  ^NWLGScriptInfo; *)

{$IFDEF  __BORLANDC__ }
    (* TC pragma *)
{$ELSE}
    (* TC pragma *)
{$ENDIF}



(************************ NWLOGIN API's ********************)


Function NWLoginInit (
    pAccess  :   pNWLGAccessRec ;
    pCompiledVersion  :   pNWVersion ;
    pRuntimeVersion  :   pNWVersion 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWLogin (
    pAccess  :   pNWLGAccessRec ;
    cmdLine  :   pnstr ;
    password  :   pnstr ;
    infoStruct  :   pNWLGStartInfo 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWLoginTerm (
    pAccess  :   pNWLGAccessRec ;
    reserved  :   nflag32 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Procedure NWLoginVersion (
    pRuntimeVersion  :   pNWVersion 
);
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWLGBringLoginToFront : nbool;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWLGDefaultEvtHandler (
    pAccess  :   pNWLGAccessRec ;
    event  :   nint ;
    eventType  :   nint ;
    eventSubType  :   nint ;
    param1  :   nparam ;
    param2  :   nparam ;
    flags  :   nflag32 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWLGDefaultExcptHandler (
    pAccess  :   pNWLGAccessRec ;
    event  :   nint ;
    eventType  :   nint ;
    eventSubType  :   nint ;
    param1  :   nparam ;
    param2  :   nparam ;
    flags  :   nflag32 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* Not implemented Function NWLGDefaultIOHandler (
    pAccess  :   pNWLGAccessRec ;
    ioEvent  :   nint ;
    param1  :   nparam ;
    param2  :   nparam ;
    flags  :   nflag32 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)


Function NWLGGetLoginData (
    identifier  :   nint ;
    itemIndex  :   nint ;
    retvalue  :   nptr ;
    len  :   nint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWLGSetLoginData (
    identifier  :   nint ;
    itemIndex  :   nint ;
    value  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWLGOpenScriptFD (
    fd  :   nint ;
    crt  :   nbool ;
    ccode  :   pnint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Procedure NWLGSetCtrlBreak;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWLGEVTSend (
    deliveryType  :   nint ;
    pAccess  :   pNWLGAccessRec ;
    event  :   nint ;
    eventType  :   nint ;
    eventSubType  :   nint ;
    param1  :   nparam ;
    param2  :   nparam ;
    flags  :   nflag32 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* Not implemented Function NWLGIOEVTSend (
    pAccess  :   pNWLGAccessRec ;
    ioEvent  :   nint ;
    param1  :   nparam ;
    param2  :   nparam ;
    flags  :   nflag32 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)

{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}


{$ENDIF}

