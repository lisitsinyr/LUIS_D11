(*
//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
//บ (c) 1993 Novell, Inc.	All rights reserved.                              บ
//บ																								  บ
//บ THIS WORK IS SUBJECT TO U.S. AND INTERNATIONAL COPYRIGHT LAWS AND		  บ
//บ TREATIES.																					  บ
//บ																								  บ
//บ NO PART OF THIS WORK MAY BE USED, PRACTICED, PERFORMED, COPIED,			  บ
//บ DISTRIBUTED, REVISED, MODIFIED, TRANSLATED, ABRIDGED, CONDENSED,         บ
//บ EXPANDED, COLLECTED, COMPILED, LINKED, RECAST, TRANSFORMED OR ADAPTED	  บ
//บ WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC.                        บ
//บ																								  บ
//บ ANY USE OR EXPLOITATION OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT บ
//บ THE PERPETRATOR TO CRIMINAL AND CIVIL LIABILITY.								  บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Source module name: NWPS_DEF.H														  บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

{$IFNDEF NWPS_DEF_INC}

{$DEFINE NWPS_DEF_INC}


(*
//  My definitions in case someone forgot theirs 
*)

{$IFNDEF NWCCODE}

Type NWCCODE = nuint;
{$ENDIF}


{$IFDEF MAX_DN_BYTES}

Type NWPS_MAX_NAME_SIZE = MAX_DN_BYTES;
{$ELSE}

{$DEFINE NWPS_MAX_NAME_SIZE}
Const NWPS_MAX_NAME_SIZE = 514;
{$ENDIF}


{$IFDEF OBJECT_NAME_SIZE}

Type NWPS_BIND_NAME_SIZE = OBJECT_NAME_SIZE;
{$ELSE}

{$DEFINE NWPS_BIND_NAME_SIZE}
Const NWPS_BIND_NAME_SIZE = 48;
{$ENDIF}


(* {$IFNDEF NWPASCAL}

Type NWPASCAL = N_PASCAL;
{$ENDIF}


{$IFNDEF NWFAR}

Type NWFAR = N_FAR;
{$ENDIF}  *)



{$IFNDEF NWAPI}

(* TC #define NWAPI NWFAR NWPASCAL  *)
{$ENDIF}


{$IFNDEF NWPTR}

(* TC #define NWPTR N_FAR *  *)
{$ENDIF}


{$IFDEF  WIN32 }
    Type NWPS_SPXID_HANDLE = nptr;
{$ELSE}
    Type NWPS_SPXID_HANDLE = nuint16;
{$ENDIF}


(*
// Fix for ntypes
*)

{$IFDEF  N_PLAT_OS2 }
    {$UNDEF N_TYPEDEF_CALLBACK}
    (* TC #define N_TYPEDEF_CALLBACK ( retType , typeName ) typedef retType ( * N_CALLBACK typeName )  *)
{$ENDIF}




(*=====================================
	ConnectionType values used troughout
  =====================================*)

{$DEFINE NWPS_BINDERY_SERVICE}
Const NWPS_BINDERY_SERVICE = 0;
{$DEFINE NWPS_DIRECTORY_SERVICE}
Const NWPS_DIRECTORY_SERVICE = 1;
{$DEFINE NWPS_BINDERY_SERVICE_PRE_40}
Const NWPS_BINDERY_SERVICE_PRE_40 = 2;
(* This value is compile time only *)

{$DEFINE NWPS_BINDERY_SERVICE_ALL}
Const NWPS_BINDERY_SERVICE_ALL = 2;

(*====================
	 Maximum name sizes
  ====================*)

(*===================== PrintCon name sizes ===============================*)

{$DEFINE NWPS_JOB_NAME_SIZE}
Const NWPS_JOB_NAME_SIZE = 32;
{$DEFINE NWPS_BANNER_NAME_SIZE}
Const NWPS_BANNER_NAME_SIZE = 12;
{$DEFINE NWPS_BANNER_FILE_SIZE}
Const NWPS_BANNER_FILE_SIZE = 12;
{$DEFINE NWPS_HEADER_FILE_SIZE}
Const NWPS_HEADER_FILE_SIZE = 12;

(*===================== PrintDef name sizes ===============================*)

{$DEFINE NWPS_FORM_NAME_SIZE}
Const NWPS_FORM_NAME_SIZE = 12;
{$DEFINE NWPS_DEVI_NAME_SIZE}
Const NWPS_DEVI_NAME_SIZE = 32;
{$DEFINE NWPS_MODE_NAME_SIZE}
Const NWPS_MODE_NAME_SIZE = 32;
{$DEFINE NWPS_FUNC_NAME_SIZE}
Const NWPS_FUNC_NAME_SIZE = 32;

(*================== Print Server Configuration Sizes =====================*)

{$DEFINE NWPS_DESCRIPT_SIZE}
Const NWPS_DESCRIPT_SIZE = 128;
{$DEFINE NWPS_APPLE_NAME_SIZE}
Const NWPS_APPLE_NAME_SIZE = 32;
{$DEFINE NWPS_APPLE_TYPE_SIZE}
Const NWPS_APPLE_TYPE_SIZE = 32;
{$DEFINE NWPS_APPLE_ZONE_SIZE}
Const NWPS_APPLE_ZONE_SIZE = 32;
{$DEFINE NWPS_UNIX_HOST_SIZE}
Const NWPS_UNIX_HOST_SIZE = 255;
{$DEFINE NWPS_UNIX_PRNT_SIZE}
Const NWPS_UNIX_PRNT_SIZE = 255;
{$DEFINE NWPS_OTHER_SIZE}
Const NWPS_OTHER_SIZE = 1024;

(*===========================
	 Maximum number of objects
  ===========================*)

(*================================================
	If -1 is used for a Printer or Form number,
	the first available number will be substituted.
  ================================================*)

{$DEFINE NWPS_MAX_PRINTERS}
Const NWPS_MAX_PRINTERS = 255;
{$DEFINE NWPS_MAX_FORMS}
Const NWPS_MAX_FORMS = 255;

(*==== GetFirst, GetNext, and EndNext require the following handle =========*)

Type NWPSListHandle  =   nptr ;

{$IFDEF __cplusplus}

(* TC extern C *)
{$ENDIF}


Procedure NWPSGetLibraryVersion (
    majorVersion  :   pnuint8 ;
    minorVersion  :   pnuint8 ;
    revisionLevel  :   pnuint8 ;
    betaReleaseLevel  :   pnuint8 
);
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


{$IFDEF  NWPS_CONN_TYPE }
    {$IFDEF NWPS_CONN_TYPE==NWPS_BINDERY_SERVICE}
    {$ELSE}  {$IFDEF NWPS_CONN_TYPE==NWPS_DIRECTORY_SERVICE}
        Function NWPSFindNextPeriodInDSName (
            startHere  :   pnstr8 
        ) : pnstr8;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
    {$ELSE}  {$IFDEF NWPS_CONN_TYPE==NWPS_BINDERY_SERVICE_PRE_40}
    {$ELSE}  {$IFDEF NWPS_CONN_TYPE==NWPS_BINDERY_SERVICE_ALL}
    {$ENDIF}
    {$ENDIF}
    {$ENDIF}
    {$ENDIF}
{$ELSE}
    Function NWPSFindNextPeriodInDSName (
        startHere  :   pnstr8 
    ) : pnstr8;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
{$ENDIF}

{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}

{$ENDIF}

