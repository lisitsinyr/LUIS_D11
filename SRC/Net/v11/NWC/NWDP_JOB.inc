(*
//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
//บ (c) 1995-1997 Novell, Inc.  All rights reserved.                         บ
//บ                                                                          บ
//บ THIS WORK IS SUBJECT TO U.S. AND INTERNATIONAL COPYRIGHT LAWS AND        บ
//บ TREATIES.                                                                บ
//บ                                                                          บ
//บ NO PART OF THIS WORK MAY BE USED, PRACTICED, PERFORMED, COPIED,          บ
//บ DISTRIBUTED, REVISED, MODIFIED, TRANSLATED, ABRIDGED, CONDENSED,         บ
//บ EXPANDED, COLLECTED, COMPILED, LINKED, RECAST, TRANSFORMED OR ADAPTED    บ
//บ WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC.                        บ
//บ                                                                          บ
//บ ANY USE OR EXPLOITATION OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT บ
//บ THE PERPETRATOR TO CRIMINAL AND CIVIL LIABILITY.                         บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Source module name: NWDP_JOB.H                                           บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Library VeRsIoN=1.0.0                                                    บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

(* Inclusion Control *)

{$IFNDEF  NWDP_JOB_H }
    {$DEFINE NWDP_JOB_H}
    (* Standard Library Header Includes *)
    (* Header Includes *)
    {$IFNDEF  NWDP_LIB_H }
        {$I nwdp_lib.inc}
    {$ENDIF}
    {$IFNDEF  NWDP_ATR_H }
        {$I nwdp_atr.inc}
    {$ENDIF}
    (* Manifest Constant Definitions *)
    {$DEFINE NWDP_JOB_FLG_DESTROY_REF}
    Const NWDP_JOB_FLG_DESTROY_REF = $00000001;
    {$DEFINE NWDP_JOB_FLG_SET_RETENTION}
    Const NWDP_JOB_FLG_SET_RETENTION = $00000002;
    (* Macro Definitions *)
    (* Type Definitions *)
    (* Global Variable Declarations *)
    (* Function Prototype Declarations *)
    Function NWDPJobCancel (
        accessorRef  :   NWDPAccessorRef ;
        jobRefPtr  :   pNWDPJobRef ;
        flags  :   nuint32 ;
        retentionPeriod  :   nuint32 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPJobCopy (
        accessorRef  :   NWDPAccessorRef ;
        destPrinterRef  :   NWDPPrtRef ;
        srcJobRef  :   NWDPJobRef ;
        destJobRefPtr  :   pNWDPJobRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPJobCreateRef (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        attrSetRef  :   NWDPAttrSetRef ;
        jobRefPtr  :   pNWDPJobRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPJobCreateRefBasedOnJobId (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        jobId  :   nuint32 ;
        jobRefPtr  :   pNWDPJobRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPJobDestroyRef (
        accessorRef  :   NWDPAccessorRef ;
        jobRefPtr  :   pNWDPJobRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPJobGetAttributeSet (
        accessorRef  :   NWDPAccessorRef ;
        jobRef  :   NWDPJobRef ;
        requestedOidSetRef  :   NWDPOidSetRef ;
        resultAttrSetRefPtr  :   pNWDPAttrSetRef ;
        avpRefPtr  :   pNWDPASAVPRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPJobGetId (
        accessorRef  :   NWDPAccessorRef ;
        jobRef  :   NWDPJobRef ;
        jobIdPtr  :   pnuint32 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPJobGetStatus (
        accessorRef  :   NWDPAccessorRef ;
        jobRef  :   NWDPJobRef ;
        resultAttrSetRefPtr  :   pNWDPAttrSetRef ;
        avpRefPtr  :   pNWDPASAVPRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPJobInterrupt (
        accessorRef  :   NWDPAccessorRef ;
        jobRef  :   NWDPJobRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPJobModifyAttrs (
        accessorRef  :   NWDPAccessorRef ;
        jobRef  :   NWDPJobRef ;
        jobModifyRef  :   NWDPAttrSetRef ;
        jobOperator  :   NWDPModifyOperatorEnum ;
        docRef  :   NWDPDocRef ;
        docModifyRef  :   NWDPAttrSetRef ;
        docOperator  :   NWDPModifyOperatorEnum 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPJobMove (
        accessorRef  :   NWDPAccessorRef ;
        destPrinterRef  :   NWDPPrtRef ;
        jobRefPtr  :   pNWDPJobRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPJobPause (
        accessorRef  :   NWDPAccessorRef ;
        jobRef  :   NWDPJobRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPJobPromote (
        accessorRef  :   NWDPAccessorRef ;
        jobRef  :   NWDPJobRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPJobReorder (
        accessorRef  :   NWDPAccessorRef ;
        jobRef  :   NWDPJobRef ;
        referenceJobId  :   nuint32 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPJobResume (
        accessorRef  :   NWDPAccessorRef ;
        jobRef  :   NWDPJobRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPJobSubmit (
        accessorRef  :   NWDPAccessorRef ;
        jobRefPtr  :   pNWDPJobRef ;
        flags  :   nuint32 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPJobValidateRef (
        accessorRef  :   NWDPAccessorRef ;
        jobRef  :   NWDPJobRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
{$ELSE}
    {$IFDEF  N_DEBUG }
        (* TC error *)
    {$ENDIF}
{$ENDIF}


