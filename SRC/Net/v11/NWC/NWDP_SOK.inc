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
//� Source module name: NWDP_SOK.H                                           �
//��������������������������������������������������������������������������͹
//� Library VeRsIoN=1.0.0                                                    �
//��������������������������������������������������������������������������ͼ
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

