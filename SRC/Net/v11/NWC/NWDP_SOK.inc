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
//บ Source module name: NWDP_SOK.H                                           บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Library VeRsIoN=1.0.0                                                    บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

(* Inclusion Control *)

{$IFNDEF  NWDP_SOK_H }
    {$DEFINE NWDP_SOK_H}
    (* Standard Library Header Includes *)
    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
    (* Manifest Constant Definitions *)
    (*
   // Well-known IPX/SPX Sockets (Raw values do not use.)
   *)
    {$DEFINE NWDP_PSM_AND_PA_SOCKET}
    Const NWDP_PSM_AND_PA_SOCKET = $90B2;
    {$DEFINE NWDP_BROKER_SRVC_SOCKET}
    Const NWDP_BROKER_SRVC_SOCKET = $90B3;
    {$DEFINE NWDP_SRVC_REGISTRY_SOCKET}
    Const NWDP_SRVC_REGISTRY_SOCKET = $90B4;
    {$DEFINE NWDP_EVENT_NOTIFY_SOCKET}
    Const NWDP_EVENT_NOTIFY_SOCKET = $90B5;
    {$DEFINE NWDP_RESOURCE_MGMT_SOCKET}
    Const NWDP_RESOURCE_MGMT_SOCKET = $90B6;
    (*
   // Well-known IPX/SPX Sockets (HiLo order)
   *)
    (* TC #define NWDP_PSM_AND_PA_SOCKET_HILO NSwapHiLo16 ( NWDP_PSM_AND_PA_SOCKET )  *)
    (* TC #define NWDP_BROKER_SRVC_SOCKET_HILO NSwapHiLo16 ( NWDP_BROKER_SRVC_SOCKET )  *)
    (* TC #define NWDP_SRVC_REGISTRY_SOCKET_HILO NSwapHiLo16 ( NWDP_SRVC_REGISTRY_SOCKET )  *)
    (* TC #define NWDP_EVENT_NOTIFY_SOCKET_HILO NSwapHiLo16 ( NWDP_EVENT_NOTIFY_SOCKET )  *)
    (* TC #define NWDP_RESOURCE_MGMT_SOCKET_HILO NSwapHiLo16 ( NWDP_RESOURCE_MGMT_SOCKET )  *)
    (*
   // Well-known IPX/SPX Sockets (LoHi order)
   *)
    (* TC #define NWDP_PSM_AND_PA_SOCKET_LOHI NSwapLoHi16 ( NWDP_PSM_AND_PA_SOCKET )  *)
    (* TC #define NWDP_BROKER_SRVC_SOCKET_LOHI NSwapLoHi16 ( NWDP_BROKER_SRVC_SOCKET )  *)
    (* TC #define NWDP_SRVC_REGISTRY_SOCKET_LOHI NSwapLoHi16 ( NWDP_SRVC_REGISTRY_SOCKET )  *)
    (* TC #define NWDP_EVENT_NOTIFY_SOCKET_LOHI NSwapLoHi16 ( NWDP_EVENT_NOTIFY_SOCKET )  *)
    (* TC #define NWDP_RESOURCE_MGMT_SOCKET_LOHI NSwapLoHi16 ( NWDP_RESOURCE_MGMT_SOCKET )  *)
{$ELSE}
    {$IFDEF  N_DEBUG }
        (* TC error *)
    {$ENDIF}
{$ENDIF}


