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
//บ Source module name: NWDP_PSM.H                                           บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Library VeRsIoN=1.0.0                                                    บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

(* Inclusion Control *)

{$IFNDEF  NWDP_PSM_H }
    {$DEFINE NWDP_PSM_H}
    (* Standard Library Header Includes *)
    (* Header Includes *)
    {$IFNDEF  NWDP_ATR_H }
        {$I nwdp_atr.inc}
    {$ENDIF}
    {$IFNDEF  NWDP_SOK_H }
        {$I nwdp_sok.inc}
    {$ENDIF}
    (* Manifest Constant Definitions *)
    (*
   // length definition sizes
   *)
    {$DEFINE NWDP_PSM_MAX_PA_NAME_BYTES}
    Const NWDP_PSM_MAX_PA_NAME_BYTES = 64;
    {$DEFINE NWDP_PSM_MAX_PA_NAME_CHARS}
    Const NWDP_PSM_MAX_PA_NAME_CHARS = 32;
    (* Macro Definitions *)
    (* Type Definitions *)
    {$DEFINE N_PACK_1}
    {$I npackon.inc}
    (*
   // NWDPPsmShutdownType enum
   *)
    Const
    NWDP_SHUTDOWN_DO_CURRENT_JOBS = 0;
    NWDP_SHUTDOWN_IMMEDIATE = 1;
    NWDP_SHUTDOWN_DO_PENDING_JOBS = 2;
    Type NWDPShutdownType = 0..2;
    pNWDPShutdownType = ^NWDPShutdownType;
    (*
   // "Printer Agent" list callback item structure
   *)
    Type
        NWDPPsmPAListItem = Record
            paName16Ptr  :   pnstr16 ;
            phStartup16Ptr  :   pnstr16 ;
            pdsStartup16Ptr  :   pnstr16 ;
            paStateOidPtr  :   pNWDPOid ;
            printerEnabled  :   nbool ;
        End;
        pNWDPPsmPAListItem = ^NWDPPsmPAListItem;
    {$I npackoff.inc}
    (* Callback Definitions *)
    Type NWDPPsmPAListCallback = Function (
        accessorRef  :   NWDPAccessorRef ;
        callerDefinedParam  :   nparam ;
        totalCallsToBeMade  :   nint ;
        currentCallCount  :   nint ;
        itemReceivedPtr  :   pNWDPPsmPAListItem 
    ) : nint;
    (* Global Variable Declarations *)
    (* Function Prototype Declarations *)
    Function NWDPPsmAddPA (
        accessorRef  :   NWDPAccessorRef ;
        psmRef  :   NWDPPsmRef ;
        paName16Ptr  :   pnstr16 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPsmAddPAAndAssignPrinterObj (
        accessorRef  :   NWDPAccessorRef ;
        psmRef  :   NWDPPsmRef ;
        printerFqnPtr  :   pNWDPNSrvFQN 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPsmCancelShutdownPSM (
        accessorRef  :   NWDPAccessorRef ;
        psmRef  :   NWDPPsmRef ;
        reservedPtr  :   pNWDPNameOrOid 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPsmCreateMODObject (
        accessorRef  :   NWDPAccessorRef ;
        psmRef  :   NWDPPsmRef ;
        objectClassPtr  :   pNWDPOid ;
        objectIdentPtr  :   pNWDPObjectIdentification ;
        force  :   nbool ;
        referenceObjectPtr  :   pNWDPObjectIdentification ;
        objectAttrSetRef  :   NWDPAttrSetRef ;
        resultAttrSetRefPtr  :   pNWDPAttrSetRef ;
        resultAvpRefPtr  :   pNWDPASAVPRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPsmCreateRefBasedOnAddr (
        accessorRef  :   NWDPAccessorRef ;
        netAddrPtr  :   pNWDPNetAddress ;
        psmRefPtr  :   pNWDPPsmRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPsmCreateRefBasedOnFQN (
        accessorRef  :   NWDPAccessorRef ;
        psmFqnPtr  :   pNWDPNSrvFQN ;
        psmRefPtr  :   pNWDPPsmRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPsmDeleteMODObject (
        accessorRef  :   NWDPAccessorRef ;
        psmRef  :   NWDPPsmRef ;
        objectClassPtr  :   pNWDPOid ;
        objectIdentPtr  :   pNWDPObjectIdentification 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPsmDestroyRef (
        accessorRef  :   NWDPAccessorRef ;
        psmRefPtr  :   pNWDPPsmRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPsmGetConnectionStatus (
        accessorRef  :   NWDPAccessorRef ;
        psmRef  :   NWDPPsmRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPsmGetFQN (
        accessorRef  :   NWDPAccessorRef ;
        psmRef  :   NWDPPsmRef ;
        sizeOfBuffer  :   nuint ;
        fqnBufferPtr  :   pNWDPNSrvFQNBuffer ;
        sizeOfResultPtr  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPsmGetMODObjectAttrSet (
        accessorRef  :   NWDPAccessorRef ;
        psmRef  :   NWDPPsmRef ;
        objectClassPtr  :   pNWDPOid ;
        objectIdentPtr  :   pNWDPObjectIdentification ;
        requestedOidSetRef  :   NWDPOidSetRef ;
        resultAttrSetRefPtr  :   pNWDPAttrSetRef ;
        avpRefPtr  :   pNWDPASAVPRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPsmListMODObjects (
        accessorRef  :   NWDPAccessorRef ;
        psmRef  :   NWDPPsmRef ;
        objectClassPtr  :   pNWDPOid ;
        selectorPtr  :   pNWDPASSelector ;
        requestedOidSetRef  :   NWDPOidSetRef ;
        listCallback  :   NWDPASMODObjectListCallback ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPsmListPAs (
        accessorRef  :   NWDPAccessorRef ;
        psmRef  :   NWDPPsmRef ;
        filterRef  :   NWDPFilterRef ;
        listCallback  :   NWDPPsmPAListCallback ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPsmModifyMODObjectAttrs (
        accessorRef  :   NWDPAccessorRef ;
        psmRef  :   NWDPPsmRef ;
        objectClassPtr  :   pNWDPOid ;
        objectIdentPtr  :   pNWDPObjectIdentification ;
        modifyRef  :   NWDPAttrSetRef ;
        modifyOperator  :   NWDPModifyOperatorEnum 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPsmRemovePA (
        accessorRef  :   NWDPAccessorRef ;
        psmRef  :   NWDPPsmRef ;
        paName16Ptr  :   pnstr16 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPsmShutdownPA (
        accessorRef  :   NWDPAccessorRef ;
        psmRef  :   NWDPPsmRef ;
        paName16Ptr  :   pnstr16 ;
        reservedPtr  :   pNWDPNameOrOid ;
        shutdownType  :   NWDPShutdownType 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPsmShutdownPSM (
        accessorRef  :   NWDPAccessorRef ;
        psmRef  :   NWDPPsmRef ;
        reservedPtr  :   pNWDPNameOrOid ;
        shutdownType  :   NWDPShutdownType 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPsmStartupPA (
        accessorRef  :   NWDPAccessorRef ;
        psmRef  :   NWDPPsmRef ;
        paName16Ptr  :   pnstr16 ;
        reservedPtr  :   pNWDPNameOrOid 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPsmValidateRef (
        accessorRef  :   NWDPAccessorRef ;
        psmRef  :   NWDPPsmRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
{$ELSE}
    {$IFDEF  N_DEBUG }
        (* TC error *)
    {$ENDIF}
{$ENDIF}



