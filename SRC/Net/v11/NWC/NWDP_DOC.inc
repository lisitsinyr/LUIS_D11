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
//บ Source module name: NWDP_DOC.H                                           บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Library VeRsIoN=1.0.0                                                    บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

(* Inclusion Control *)

{$IFNDEF  NWDP_DOC_H }
    {$DEFINE NWDP_DOC_H}
    (* Standard Library Header Includes *)
    (* Header Includes *)
    {$IFNDEF  NWDP_LIB_H }
        {$I nwdp_lib.inc}
    {$ENDIF}
    {$IFNDEF  NWDP_ATR_H }
        {$I nwdp_atr.inc}
    {$ENDIF}
    (* Manifest Constant Definitions *)
     Const
      NWDP_DOC_POSITION_LAST = ( ( nuint ) - 1 );
    (* Macro Definitions *)
    (* Type Definitions *)
    (* Callback Definitions *)
    Type NWDPDocTransferFileCallback = Function (
        accessorRef  :   NWDPAccessorRef ;
        callerDefinedParam  :   nparam ;
        totalBytesToBeTransferred  :   nuint32 ;
        currentNumberTransferred  :   nuint32 
    ) : nint;
    (* Global Variable Declarations *)
    (* Function Prototype Declarations *)
    Function NWDPDocCancel (
        accessorRef  :   NWDPAccessorRef ;
        docRef  :   NWDPDocRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPDocCreateRef (
        accessorRef  :   NWDPAccessorRef ;
        jobRef  :   NWDPJobRef ;
        position  :   nuint ;
        attrSetRef  :   NWDPAttrSetRef ;
        docRefPtr  :   pNWDPDocRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPDocCreateRefBasedOnDocId (
        accessorRef  :   NWDPAccessorRef ;
        jobRef  :   NWDPJobRef ;
        docId  :   nuint32 ;
        docRefPtr  :   pNWDPDocRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPDocDestroyRef (
        accessorRef  :   NWDPAccessorRef ;
        docRefPtr  :   pNWDPDocRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPDocGetAttributeSet (
        accessorRef  :   NWDPAccessorRef ;
        docRef  :   NWDPDocRef ;
        requestedOidSetRef  :   NWDPOidSetRef ;
        resultAttrSetRefPtr  :   pNWDPAttrSetRef ;
        avpRefPtr  :   pNWDPASAVPRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPDocGetId (
        accessorRef  :   NWDPAccessorRef ;
        docRef  :   NWDPDocRef ;
        docIdPtr  :   pnuint32 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPDocModifyAttrs (
        accessorRef  :   NWDPAccessorRef ;
        docRef  :   NWDPDocRef ;
        modifyRef  :   NWDPAttrSetRef ;
        docOperator  :   NWDPModifyOperatorEnum 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPDocTransferFile (
        accessorRef  :   NWDPAccessorRef ;
        docRef  :   NWDPDocRef ;
        sourceFilePath16Ptr  :   pnstr16 ;
        progressFunc  :   NWDPDocTransferFileCallback ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPDocValidateRef (
        accessorRef  :   NWDPAccessorRef ;
        docRef  :   NWDPDocRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPDocWriteBuf (
        accessorRef  :   NWDPAccessorRef ;
        docRef  :   NWDPDocRef ;
        bufferPtr  :   nptr ;
        sizeOfBuffer  :   nuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
{$ELSE}
    {$IFDEF  N_DEBUG }
        (* TC error *)
    {$ENDIF}
{$ENDIF}


