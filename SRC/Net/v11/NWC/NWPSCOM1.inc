(*
//浜様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様融
//� (c) 1993 Novell, Inc.	All rights reserved.                              �
//�																								  �
//� THIS WORK IS SUBJECT TO U.S. AND INTERNATIONAL COPYRIGHT LAWS AND		  �
//� TREATIES.																					  �
//�																								  �
//� NO PART OF THIS WORK MAY BE USED, PRACTICED, PERFORMED, COPIED,			  �
//� DISTRIBUTED, REVISED, MODIFIED, TRANSLATED, ABRIDGED, CONDENSED,         �
//� EXPANDED, COLLECTED, COMPILED, LINKED, RECAST, TRANSFORMED OR ADAPTED	  �
//� WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC.                        �
//�																								  �
//� ANY USE OR EXPLOITATION OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT �
//� THE PERPETRATOR TO CRIMINAL AND CIVIL LIABILITY.								  �
//麺様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様郵
//� Source module name: NWPSCOM1.H														  �
//藩様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様夕
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

Function NWP1ComAttachToPrintServer (
    connID  :   nuint32 ;
    timeOut  :   nuint ;
    pServerName  :   pnstr8 ;
    spxID  :   NWPS_SPXID_HANDLE 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSComAttachToPrintServer ( connType , connID , timeOut , pServerName , spxID ) NWP1ComAttachToPrintServer ( connID , timeOut , pServerName , spxID )  *)

(*---------------------------------------------------------------
  The connType and connID fields are used only to acquire rights.
  The connType and connID used by NWPSComAttachToPrintServer are
  used to determine the context in which to run this library.
  ---------------------------------------------------------------*)

Function NWP1ComLoginToPrintServer (
    connID  :   nuint32 ;
    spxID  :   NWPS_SPXID_HANDLE ;
    accessLevel  :   pnuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSComLoginToPrintServer ( connType , connID , spxID , accessLevel ) NWP1ComLoginToPrintServer ( connID , spxID , accessLevel )  *)


{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}

