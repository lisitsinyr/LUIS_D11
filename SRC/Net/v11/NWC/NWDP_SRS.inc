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
//บ Source module name: NWDP_SRS.H                                           บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Library VeRsIoN=1.0.0                                                    บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

(* Inclusion Control *)

{$IFNDEF  NWDP_SRS_H }
    {$DEFINE NWDP_SRS_H}
    (* Standard Library Header Includes *)
    {$IFNDEF  NWDP_LIB_H }
        {$I nwdp_lib.inc}
    {$ENDIF}
    (* Header Includes *)
    (* Manifest Constant Definitions *)
    {$IFNDEF  OT_ADVERTISING_NDPS_SVC_REGSTRY }
        {$IFDEF  _CLIENT32_ }
            (* Client32 values are Lo-Hi ordered *)
            {$DEFINE OT_ADVERTISING_NDPS_SVC_REGSTRY}
            Const OT_ADVERTISING_NDPS_SVC_REGSTRY = $0282;
        {$ELSE}
            (* traditional values are Hi-Lo ordered *)
            {$DEFINE OT_ADVERTISING_NDPS_SVC_REGSTRY}
            Const OT_ADVERTISING_NDPS_SVC_REGSTRY = $8202;
        {$ENDIF}
    {$ENDIF}
    (*
   // length definition sizes
   *)
    {$DEFINE NWDP_SRS_MAX_NAME_SIZE}
    Const NWDP_SRS_MAX_NAME_SIZE = 64;
    {$DEFINE NWDP_SRS_MAX_ADDRESS_LEN}
    Const NWDP_SRS_MAX_ADDRESS_LEN = 128;
    {$DEFINE NWDP_SRS_MAX_INFO_SIZE}
    Const NWDP_SRS_MAX_INFO_SIZE = 128;
    (* Macro Definitions *)
    (* Type Definitions *)
    {$DEFINE N_PACK_1}
    {$I npackon.inc}
    (*
   // server type enum
   *)
    Const
    NWDP_SRS_SERVERTYPE_ALL = 0;
    NWDP_SRS_SERVERTYPE_PA = 1;
    NWDP_SRS_SERVERTYPE_NTS = 2;
    NWDP_SRS_SERVERTYPE_RMS = 3;
    NWDP_SRS_SERVERTYPE_NPH = 4;
    Type NWDPSrsServerType = 0..4;
    pNWDPSrsServerType = ^NWDPSrsServerType;
    (*
   // info item definition
   *)
    Const
    NWDP_INFO_ITEM_INT8 = 0;
    NWDP_INFO_ITEM_INT16 = 1;
    NWDP_INFO_ITEM_INT32 = 2;
    NWDP_INFO_ITEM_BOOL = 3;
    NWDP_INFO_ITEM_STRING = 4;
    NWDP_INFO_ITEM_OCTET_STR = 5;
    Type NWDPInfoItemEnum = 0..5;
    pNWDPInfoItemEnum = ^NWDPInfoItemEnum;
    Type
        NWDPInfoItem = Record
            designator  :   NWDPInfoItemEnum ;
            uInt8  :   nuint8 ;  (* union statement *)
        End;
        pNWDPInfoItem = ^NWDPInfoItem;
    (*
   // server list callback item structure
   *)
    Type
        NWDPServerListItem = Record
            serverName  :   NWDPText ;
            serverType  :   NWDPSrsServerType ;
            address  :   NWDPNetAddress ;
            infoCount  :   nuint ;
            infoPtr  :   pNWDPInfoItem ;
        End;
        pNWDPServerListItem = ^NWDPServerListItem;
    {$I npackoff.inc}
    (* Callback Definitions *)
    Type NWDPSrsServersListCallback = Function (
        accessorRef  :   NWDPAccessorRef ;
        callerDefinedParam  :   nparam ;
        totalCallsToBeMade  :   nint ;
        currentCallCount  :   nint ;
        itemReceivedPtr  :   pNWDPServerListItem 
    ) : nint;
    (* Global Variable Declarations *)
    (* Function Prototype Declarations *)
    Function NWDPSrsCreateRefBasedOnAddr (
        accessorRef  :   NWDPAccessorRef ;
        netAddrPtr  :   pNWDPNetAddress ;
        srsRefPtr  :   pNWDPSrsRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPSrsCreateRefBasedOnFQN (
        accessorRef  :   NWDPAccessorRef ;
        brokerFqnPtr  :   pNWDPNSrvFQN ;
        srsRefPtr  :   pNWDPSrsRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPSrsCreateRefBasedOnSAP (
        accessorRef  :   NWDPAccessorRef ;
        srsRefPtr  :   pNWDPSrsRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPSrsDeregisterServer (
        accessorRef  :   NWDPAccessorRef ;
        serviceRef  :   NWDPSrsRef ;
        serverType  :   NWDPSrsServerType ;
        serverNamePtr  :   pNWDPText ;
        addressPtr  :   pNWDPNetAddress 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPSrsDestroyRef (
        accessorRef  :   NWDPAccessorRef ;
        srsRefPtr  :   pNWDPSrsRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPSrsGetConnectionStatus (
        accessorRef  :   NWDPAccessorRef ;
        srsRef  :   NWDPSrsRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPSrsGetFQN (
        accessorRef  :   NWDPAccessorRef ;
        serviceRef  :   NWDPSrsRef ;
        sizeOfBuffer  :   nuint ;
        fqnBufferPtr  :   pNWDPNSrvFQNBuffer ;
        sizeOfResultPtr  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPSrsListServers (
        accessorRef  :   NWDPAccessorRef ;
        srsRef  :   NWDPSrsRef ;
        serverType  :   NWDPSrsServerType ;
        listCallback  :   NWDPSrsServersListCallback ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPSrsRegisterServer (
        accessorRef  :   NWDPAccessorRef ;
        serviceRef  :   NWDPSrsRef ;
        serverType  :   NWDPSrsServerType ;
        serverNamePtr  :   pNWDPText ;
        addressPtr  :   pNWDPNetAddress ;
        infoCount  :   nuint ;
        infoPtr  :   pNWDPInfoItem 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPSrsValidateRef (
        accessorRef  :   NWDPAccessorRef ;
        srsRef  :   NWDPSrsRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
{$ELSE}
    {$IFDEF  N_DEBUG }
        (* TC error *)
    {$ENDIF}
{$ENDIF}

