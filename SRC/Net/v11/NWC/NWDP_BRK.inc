(*
//��������������������������������������������������������������������������ͻ
//� (c) 1995-1997 Novell, Inc.  All rights reserved.                         �
//�                                                                          �
//� THIS WORK IS SUBJECT TO U.S. AND INTERNATIONAL COPYRIGHT LAWS AND        �
//� TREATIES.                                                                �
//�                                                                          �
//� NO PART OF THIS WORK MAY BE USED, PRACTICED, PERFORMED, COPIED,          �
//� DISTRIBUTED, REVISED, MODIFIED, TRANSLATED, ABRIDGED, CONDENSED,         �
//� EXPANDED, COLLECTED, COMPILED, LINKED, RECAST, TRANSFORMED OR ADAPTED    �
//� WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC.                        �
//�                                                                          �
//� ANY USE OR EXPLOITATION OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT �
//� THE PERPETRATOR TO CRIMINAL AND CIVIL LIABILITY.                         �
//��������������������������������������������������������������������������͹
//� Source module name: NWDP_BRK.H                                           �
//��������������������������������������������������������������������������͹
//� Library VeRsIoN=1.0.0                                                    �
//��������������������������������������������������������������������������ͼ
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
