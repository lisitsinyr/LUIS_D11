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
//บ Source module name: NWPS_PDF.H														  บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

{$IFNDEF NWPS_DEF_INC}

{$I nwps_def.inc}
{$ENDIF}


{$IFNDEF NWPS_PDF_INC}

{$DEFINE NWPS_PDF_INC}
(*********************************************************************)

(*********** PrintDef - Printer Definition Information ***************)

(*********************************************************************)


(*========== PrintDef reset string (one for each device) ============*)

{$DEFINE NWPS_RESET_MODE}
Const NWPS_RESET_MODE = '(Re-initialize)';
{$DEFINE NWPS_MAX_FUNC_SIZE}
Const NWPS_MAX_FUNC_SIZE = 256;

Type
    NWPSFuncData_T = Record
        funcSize  :  nint32;
        funcData  :  Array[0..NWPS_MAX_FUNC_SIZE-1] Of  nuint8 ;
    End;
    NWPSPdfFuncData = NWPSFuncData_T;


{$IFDEF __cplusplus}

(* TC extern C *)
{$ENDIF}


(*==================================================================
  Turn on the debug printf messages in the PrintDef program.
  These messages are in English only and are normally not displayed.
  ==================================================================*)

Procedure NWPSPdfDebug (
    flag  :   nuint8 
);
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*=======================================
  Set/Get the date code on an Import File
  =======================================*)

Function NWPSPdfSetImportDate (
    connType  :   nuint ;
    connID  :   nuint32 ;
    fileName  :   pnstr8 ;
    year  :   nuint16 ;
    month  :   nuint16 ;
    day  :   nuint16 ;
    hour  :   nuint16 ;
    minute  :   nuint16 ;
    second  :   nuint16 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSPdfGetImportDate (
    connType  :   nuint ;
    connID  :   nuint32 ;
    fileName  :   pnstr8 ;
    year  :   pnuint16 ;
    month  :   pnuint16 ;
    day  :   pnuint16 ;
    hour  :   pnuint16 ;
    minute  :   pnuint16 ;
    second  :   pnuint16 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*====================================================
// This typedef is for the Managed Import Device calls
// 
// The importManagerParm1 is intended to give context
// to the caller's Import Manager. The other two
// parameters are for reporting progress, e.g. percent
// complete could be calculated: 
//   percentDone = 100 * currentCallCount / totalCallsToBeMade;
// 
// The return code, if non-zero causes the Import to
// abort and the Device remnants deleted. This could be
// useful in implementing a Cancel feature, checking a
// hotkey or mouse button etc. for interruptions.
// 
// The exception to the return code is that when
// totalCallsToBeMade and currentCallCount are equal
// the return code will be ignored. This is the caller's
// opportunity to do screen cleanup etc.
  ====================================================*)

Type NWPSImportManager = Function (
    importManagerParm1  :   nptr ;
    totalCallsToBeMade  :  nint32;
    currentCallCount  :  nint32
) : NWCCODE;


(*=========================================================
  This entry point concludes any NWPSPdfGetFirstxxxxxxx or
  NWPSPdfGetNextxxxxxx calls.
  =========================================================*)

Function NWPSPdfEndNext (
    handle  :   NWPSListHandle 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}


{$IFDEF  NWPS_CONN_TYPE }
    {$IFDEF NWPS_CONN_TYPE==NWPS_BINDERY_SERVICE}
        {$I nwpspdf0.inc}
    {$ELSE}  {$IFDEF NWPS_CONN_TYPE==NWPS_DIRECTORY_SERVICE}
        {$I nwpspdf1.inc}
    {$ELSE}  {$IFDEF NWPS_CONN_TYPE==NWPS_BINDERY_SERVICE_PRE_40}
        {$I nwpspdf2.inc}
    {$ELSE}  {$IFDEF NWPS_CONN_TYPE==NWPS_BINDERY_SERVICE_ALL}
        {$I nwpspdfx.inc}
    {$ENDIF}
    {$ENDIF}
    {$ENDIF}
    {$ENDIF}
{$ELSE}
    {$I nwpspdfx.inc}
{$ENDIF}


{$ENDIF}

