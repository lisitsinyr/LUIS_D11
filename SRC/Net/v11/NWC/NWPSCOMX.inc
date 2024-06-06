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
//บ Source module name: NWPSCOMX.H														  บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

{$IFDEF __cplusplus}

(* TC extern C *)
{$ENDIF}


(*====================== Print Server Communications ======================*)

(*---------------------------------------------------------------
  The connType and connID fields are used to determine the context
  in which to run this library.	The connType and connID used by
  NWPSComLoginToPrintServer are used only to acquire rights.
  ---------------------------------------------------------------*)

Function NWPSComAttachToPrintServer (
    connType  :   nuint ;
    connID  :   nuint32 ;
    timeOut  :   nuint ;
    pServerName  :   pnstr8 ;
    spxID  :   NWPS_SPXID_HANDLE 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*---------------------------------------------------------------
  The connType and connID fields are used only to acquire rights.
  The connType and connID used by NWPSComAttachToPrintServer are
  used to determine the context in which to run this library.
  ---------------------------------------------------------------*)

Function NWPSComLoginToPrintServer (
    connType  :   nuint ;
    connID  :   nuint32 ;
    spxID  :   NWPS_SPXID_HANDLE ;
    accessLevel  :   pnuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}



{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}

