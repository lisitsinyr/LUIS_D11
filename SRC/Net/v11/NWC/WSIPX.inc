(*       WSIPX.H -- Winsock 2 Extensions for IPX networks
 *
 *  This file contains IPX/SPX specific information for use by
 *  Winsock 2 compabable applications.  Include this file below
 *  WINSOCK.H to enable IPX features in your application.
 *
 *                   Rev 0.3, Feb 23, 1995  
 *)


{$IFNDEF _WSIPX_}

{$DEFINE _WSIPX_}

(* TC pragma *)

(* Transparant sockaddr definition for address family AF_IPX *)


Type
    sockaddr_ipx = Record
        sa_family  :   u_short ;
        sa_netnum  :  Array[0..3] Of  u_char ;
        sa_nodenum  :  Array[0..5] Of  u_char ;
        sa_socket  :  nuint16;
    End;
    SOCKADDR_IPX = sockaddr_ipx;
    PSOCKADDR_IPX = ^sockaddr_ipx;
    FAR = sockaddr_ipx;
    LPSOCKADDR_IPX = ^sockaddr_ipx;




(* Protocol types within protocol family PF_IPX 
 *
 * Protocol family PF_IPX reserves protocol id 0 - 255 for IP-conforming
 * protocol identifiers.
 *
 *)


{$DEFINE NSPROTO_UNSPEC}
Const NSPROTO_UNSPEC = 0;
{$DEFINE NSPROTO_IPX}
Const NSPROTO_IPX = 1000;
{$DEFINE NSPROTO_SPX}
Const NSPROTO_SPX = 1256;
{$DEFINE NSPROTO_SPXII}
Const NSPROTO_SPXII = 1257;

(* Socket options for IPX level NSPROTO_IPX *)


{$DEFINE IPX_CATEGORY}
Const IPX_CATEGORY = NSPROTO_IPX;

{$DEFINE IPX_CHECKSUM}
Const IPX_CHECKSUM = $0001;
{$DEFINE IPX_PRIMARY}
Const IPX_PRIMARY = $0002;
{$DEFINE IPX_TXPKTSIZE}
Const IPX_TXPKTSIZE = $1001;
{$DEFINE IPX_RXPKTSIZE}
Const IPX_RXPKTSIZE = $1002;
{$DEFINE IPX_TXMEDIASIZE}
Const IPX_TXMEDIASIZE = $1003;
{$DEFINE IPX_RXMEDIASIZE}
Const IPX_RXMEDIASIZE = $1004;


(* Socket options for SPX level NSPROTO_SPX *)


{$DEFINE SPX_CATEGORY}
Const SPX_CATEGORY = NSPROTO_SPX;

{$DEFINE SPX_CHECKSUM}
Const SPX_CHECKSUM = IPX_CHECKSUM;
{$DEFINE SPX_PRIMARY}
Const SPX_PRIMARY = IPX_PRIMARY;
{$DEFINE SPX_RAWSPX}
Const SPX_RAWSPX = $0010;
{$DEFINE SPX_TXPKTSIZE}
Const SPX_TXPKTSIZE = IPX_TXPKTSIZE;
{$DEFINE SPX_RXPKTSIZE}
Const SPX_RXPKTSIZE = IPX_RXPKTSIZE;
{$DEFINE SPX_TXMEDIASIZE}
Const SPX_TXMEDIASIZE = IPX_TXMEDIASIZE;
{$DEFINE SPX_RXMEDIASIZE}
Const SPX_RXMEDIASIZE = IPX_RXMEDIASIZE;


(*  net,node,socket portion of IPX header *)


{$DEFINE IPX_NET_SIZE}
Const IPX_NET_SIZE = 4;
{$DEFINE IPX_NODE_SIZE}
Const IPX_NODE_SIZE = 6;
{$DEFINE IPX_SOCKET_SIZE}
Const IPX_SOCKET_SIZE = 2;

(* WSIpxAddr -- Ipx/Spx header net,node address structure *)


Type
    WSIpxAddrStruc = Record
        Net  :   u_long ;
        Node  :  Array[0..IPX_NODE_SIZE-1] Of  u_char ;
        Socket  :   u_short ;
    End;
    WSIpxAddr = WSIpxAddrStruc;
    PWSIpxAddr = ^WSIpxAddrStruc;
    FAR = WSIpxAddrStruc;
    LPWSIpxAddr = ^WSIpxAddrStruc;


(* TC #define WSIpxNode0To3 ( pIpxAddr ) ( * ( UINT32 * ) ( & ( ( PWSIpxAddr * ) pIpxAddr ) - > Node [ 0 ] )  *)
(* TC #define WSIpxNode4To5 ( pIpxAddr ) ( * ( UINT16 * ) ( & ( ( PWSIpxAddr * ) pIpxAddr ) - > Node [ 3 ] )  *)

(* WSIpxHeader -- IPX header structure when in SOCK_RAW mode *)


Type
    WSIpxHeaderStruc = Record
        Checksum  :   u_short ;
        Length  :   u_short ;
        XportCtl  :   u_char ;
        PktType  :   u_char ;
        DestAddr  :   WSIpxAddr ;
        SrcAddr  :   WSIpxAddr ;
    End;
    WSIpxHeader = WSIpxHeaderStruc;
    PWSIpxHeader = ^WSIpxHeaderStruc;
    FAR = WSIpxHeaderStruc;
    LPWSIpxHeader = ^WSIpxHeaderStruc;


(* Standard IPX packet types *)


{$DEFINE IPXTYPE_UNKNOWN}
Const IPXTYPE_UNKNOWN = $00;
{$DEFINE IPXTYPE_RIP}
Const IPXTYPE_RIP = $01;
{$DEFINE IPXTYPE_ECHO}
Const IPXTYPE_ECHO = $02;
{$DEFINE IPXTYPE_ERROR}
Const IPXTYPE_ERROR = $03;
{$DEFINE IPXTYPE_IPX}
Const IPXTYPE_IPX = $04;
{$DEFINE IPXTYPE_SPX}
Const IPXTYPE_SPX = $05;
{$DEFINE IPXTYPE_NCP}
Const IPXTYPE_NCP = $11;
{$DEFINE IPXTYPE_NETBIOS}
Const IPXTYPE_NETBIOS = $14;
Type IPXTYPE_INTERNET_BROADCAST = IPT_NETBIOS;

(* WSSpxHeader -- SPX Header structure when in SPXL_SPXRAW mode. *)


Type
    WSSpxHeaderStruc = Record
        IpxHdr  :   WSIpxHeader ;
        ConnCtrl  :   u_char ;
        DataStreamType  :   u_char ;
        SrcConnId  :   u_short ;
        DstConnId  :   u_short ;
        SendSeq  :   u_short ;
        AckSeq  :   u_short ;
        AllocNum  :   u_short ;
    End;
    WSSpxHeader = WSSpxHeaderStruc;
    PWSSpxHeader = ^WSSpxHeaderStruc;
    FAR = WSSpxHeaderStruc;
    LPWSSpxHeader = ^WSSpxHeaderStruc;


(* Connection Control Bits *)


{$DEFINE SPX_SYSTEM_PACKET_BIT}
Const SPX_SYSTEM_PACKET_BIT = $80;
{$DEFINE SPX_SEND_ACK_BIT}
Const SPX_SEND_ACK_BIT = $40;
{$DEFINE SPX_ATTENTION_BIT}
Const SPX_ATTENTION_BIT = $20;
{$DEFINE SPX_END_OF_MESSAGE_BIT}
Const SPX_END_OF_MESSAGE_BIT = $10;

(* Data Stream Types.
 *
 * Values in the range 0 - 0xfd are user-definable.
 *)


{$DEFINE SPX_HANG_UP}
Const SPX_HANG_UP = $FE;
{$DEFINE SPX_HANG_UP_ACK}
Const SPX_HANG_UP_ACK = $FF;


(* a sampling of well-known socket types in network hi-lo order.
 * use ntohl() for local representation.
 *)


{$DEFINE IPXSKT_DYNAMIC}
Const IPXSKT_DYNAMIC = $0000;
{$DEFINE IPXSKT_NCP}
Const IPXSKT_NCP = $5104;
{$DEFINE IPXSKT_SAP}
Const IPXSKT_SAP = $5204;
{$DEFINE IPXSKT_RIP}
Const IPXSKT_RIP = $5304;
{$DEFINE IPXSKT_NETBIOS}
Const IPXSKT_NETBIOS = $5504;
{$DEFINE IPXSKT_DIAGNOSTICS}
Const IPXSKT_DIAGNOSTICS = $5604;
{$DEFINE IPXSKT_PING}
Const IPXSKT_PING = $8690;


{$ENDIF}

