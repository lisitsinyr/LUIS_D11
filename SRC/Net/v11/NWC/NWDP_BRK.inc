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
//บ Source module name: NWDP_BRK.H                                           บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Library VeRsIoN=1.0.0                                                    บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

(* Inclusion Control *)

{$IFNDEF  NWDP_BRK_H }
    {$DEFINE NWDP_BRK_H}
    (* Standard Library Header Includes *)
    {$IFNDEF  NWDP_LIB_H }
        {$I nwdp_lib.inc}
    {$ENDIF}
    {$IFNDEF  NWDP_BKR_H }
        {$I nwdp_bkr.inc}
    {$ENDIF}
    (* Header Includes *)
    (* Manifest Constant Definitions *)
    (* Macro Definitions *)
    (* Type Definitions *)
    {$DEFINE N_PACK_1}
    {$I npackon.inc}
    (*
   // service list callback item structure
   *)
    Type NWDPServiceListItem  =   NWDPBrokerService ;
    {$I npackoff.inc}
    (* Callback Definitions *)
    Type NWDPBrkServicesListCallback = Function (
        accessorRef  :   NWDPAccessorRef ;
        callerDefinedParam  :   nparam ;
        totalCallsToBeMade  :   nint ;
        currentCallCount  :   nint ;
        itemReceivedPtr  :   pNWDPServiceListItem 
    ) : nint;
    (* Global Variable Declarations *)
    (* Function Prototype Declarations *)
    Function NWDPBrkCreateRefBasedOnFQN (
        accessorRef  :   NWDPAccessorRef ;
        brokerFqnPtr  :   pNWDPNSrvFQN ;
        brokerRefPtr  :   pNWDPBrkRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPBrkDestroyRef (
        accessorRef  :   NWDPAccessorRef ;
        brokerRefPtr  :   pNWDPBrkRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPBrkDisableService (
        accessorRef  :   NWDPAccessorRef ;
        brokerRef  :   NWDPBrkRef ;
        serviceType  :   NWDPServiceTypeEnum 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPBrkEnableService (
        accessorRef  :   NWDPAccessorRef ;
        brokerRef  :   NWDPBrkRef ;
        serviceType  :   NWDPServiceTypeEnum 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPBrkGetConnectionStatus (
        accessorRef  :   NWDPAccessorRef ;
        brokerRef  :   NWDPBrkRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPBrkGetFQN (
        accessorRef  :   NWDPAccessorRef ;
        brokerRef  :   NWDPBrkRef ;
        sizeOfBuffer  :   nuint ;
        fqnBufferPtr  :   pNWDPNSrvFQNBuffer ;
        sizeOfResultPtr  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPBrkListServices (
        accessorRef  :   NWDPAccessorRef ;
        brokerRef  :   NWDPBrkRef ;
        supportedVsEnabledFilter  :   NWDPListServicesEnum ;
        listCallback  :   NWDPBrkServicesListCallback ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPBrkShutdown (
        accessorRef  :   NWDPAccessorRef ;
        brokerRef  :   NWDPBrkRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPBrkValidateRef (
        accessorRef  :   NWDPAccessorRef ;
        brokerRef  :   NWDPBrkRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
{$ELSE}
    {$IFDEF  N_DEBUG }
        (* TC error *)
    {$ENDIF}
{$ENDIF}

