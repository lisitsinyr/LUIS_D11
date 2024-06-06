(*
//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
//บ (c) 1997 Novell, Inc.  All rights reserved.                              บ
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
//บ Source module name: NWDP_BKR.H                                           บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Library VeRsIoN=1.0.0                                                    บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

(* Inclusion Control *)

{$IFNDEF  NWDP_BKR_H }
    {$DEFINE NWDP_BKR_H}
    (* Standard Library Header Includes *)
    {$IFNDEF  NTYPES_H }
        {$DEFINE N_INC_NO_OLD_CONSTANTS}
        {$DEFINE N_INC_NO_OLD_MACROS}
        {$I ntypes.inc}
        {$UNDEF N_INC_NO_OLD_MACROS}
        {$UNDEF N_INC_NO_OLD_CONSTANTS}
    {$ENDIF}
    (* Header Includes *)
    (* Manifest Constant Definitions *)
    (* Macro Definitions *)
    (* Type Definitions *)
    Const
    NWDP_SERVICES_SUPPORTED = 0;
    NWDP_SERVICES_ENABLED = 1;
    Type NWDPListServicesEnum = 0..1;
    pNWDPListServicesEnum = ^NWDPListServicesEnum;
    Const
    NWDP_SERVICE_TYPE_SRS = 0;
    NWDP_SERVICE_TYPE_ENS = 1;
    NWDP_SERVICE_TYPE_RMS = 2;
    Type NWDPServiceTypeEnum = 0..2;
    pNWDPServiceTypeEnum = ^NWDPServiceTypeEnum;
    Type
        NWDPBrokerService = Record
            serviceType  :   NWDPServiceTypeEnum ;
            enabledSwitch  :   nbool ;
        End;
        pNWDPBrokerService = ^NWDPBrokerService;
    (* Structure Definitions *)
    (* Global Variable Declarations *)
    (* Function Prototype Declarations *)
{$ELSE}
    {$IFDEF  N_DEBUG }
        (* TC error *)
    {$ENDIF}
{$ENDIF}


