
















{$IFNDEF NWSIPX32_H}

{$DEFINE NWSIPX32_H}







{$DEFINE NWSIPX32_API_VERSION}
Const NWSIPX32_API_VERSION = $00000003;









{$DEFINE SIPX_API_EVENT}
Const SIPX_API_EVENT = $00000001;
{$DEFINE SIPX_API_MUX_EVENT}
Const SIPX_API_MUX_EVENT = $00000002;
{$DEFINE SIPX_BLOCKING}
Const SIPX_BLOCKING = $00000003;
{$DEFINE SIPX_POLLING}
Const SIPX_POLLING = $00000004;
{$DEFINE SIPX_USER_EVENT}
Const SIPX_USER_EVENT = $00000005;
{$DEFINE SIPX_CALLBACK}
Const SIPX_CALLBACK = $00000006;












{$DEFINE SIPX_NO_WAIT}
Const SIPX_NO_WAIT = $00000000;
{$DEFINE SIPX_INFINITE_WAIT}
Const SIPX_INFINITE_WAIT = $FFFFFFFF;












{$DEFINE SIPX_ALLOC_MUX_GROUP}
Const SIPX_ALLOC_MUX_GROUP = SIPXMUXGRP_HANDLE($FFFFFFFF);










{$DEFINE SIPX_ALL_SERVERS}
Const SIPX_ALL_SERVERS = $00000001;
{$DEFINE SIPX_NEAREST_SERVER}
Const SIPX_NEAREST_SERVER = $00000002;











{$DEFINE SIPX_CONNECT_NO_WATCHDOG}
Const SIPX_CONNECT_NO_WATCHDOG = $00000001;











{$DEFINE SIPX_ACCEPT_ON_LISTEN_ENDPOINT}
Const SIPX_ACCEPT_ON_LISTEN_ENDPOINT = $00000001;














{$DEFINE SIPX_LISTEN_DELAY_ACCEPT}
Const SIPX_LISTEN_DELAY_ACCEPT = $00000001;
{$DEFINE SIPX_LISTEN_NO_WATCHDOG}
Const SIPX_LISTEN_NO_WATCHDOG = $00000002;













{$DEFINE SIPX_TERM_ABORT}
Const SIPX_TERM_ABORT = $00000001;
{$DEFINE SIPX_TERM_ACKED}
Const SIPX_TERM_ACKED = $00000002;
{$DEFINE SIPX_TERM_REJECT}
Const SIPX_TERM_REJECT = $00000004;
















{$DEFINE SIPX_SNDMSG_PARTIAL}
Const SIPX_SNDMSG_PARTIAL = $00000001;
{$DEFINE SIPX_SNDMSG_DSTRM_TYPE}
Const SIPX_SNDMSG_DSTRM_TYPE = $00000002;
{$DEFINE SIPX_SNDMSG_ATTN}
Const SIPX_SNDMSG_ATTN = $00000004;






















{$DEFINE SIPX_SNDDG_PACKET_TYPE}
Const SIPX_SNDDG_PACKET_TYPE = $00000001;
{$DEFINE SIPX_SNDDG_VERIFY_ROUTE}
Const SIPX_SNDDG_VERIFY_ROUTE = $00000002;
{$DEFINE SIPX_SNDDG_SPECIFIC_ROUTE}
Const SIPX_SNDDG_SPECIFIC_ROUTE = $00000004;
{$DEFINE SIPX_SNDDG_BEST_ROUTE}
Const SIPX_SNDDG_BEST_ROUTE = $00000008;
{$DEFINE SIPX_SNDDG_GENERATE_CHKSUM}
Const SIPX_SNDDG_GENERATE_CHKSUM = $00000010;















{$DEFINE SIPX_RCVMSG_PARTIAL}
Const SIPX_RCVMSG_PARTIAL = $00000001;
{$DEFINE SIPX_RCVMSG_ATTN}
Const SIPX_RCVMSG_ATTN = $00000002;










{$DEFINE SIPX_QUERY_SPECIFIC_ROUTE}
Const SIPX_QUERY_SPECIFIC_ROUTE = $00000001;










{$DEFINE SIPX_DEFAULT_SUBNETWORK}
Const SIPX_DEFAULT_SUBNETWORK = $FFFFFFFF;











{$DEFINE SIPX_LISTEN_FOR_DISCONNECT}
Const SIPX_LISTEN_FOR_DISCONNECT = $00000001;
{$DEFINE SIPX_SCHEDULE_TIMER_EVENT}
Const SIPX_SCHEDULE_TIMER_EVENT = $00000002;
{$DEFINE SIPX_SUBNET_STATUS_CHANGE}
Const SIPX_SUBNET_STATUS_CHANGE = $00000003;











{$DEFINE SIPX_API_INFORMATION}
Const SIPX_API_INFORMATION = $00000001;
{$DEFINE SIPX_SOCKET_INFORMATION}
Const SIPX_SOCKET_INFORMATION = $00000002;
{$DEFINE SIPX_CONN_INFORMATION}
Const SIPX_CONN_INFORMATION = $00000003;
{$DEFINE SIPX_NWTCB_INFORMATION}
Const SIPX_NWTCB_INFORMATION = $00000004;









{$DEFINE SIPX_MAX_TRANS_ADDR_LEN}
Const SIPX_MAX_TRANS_ADDR_LEN = 32;










{$DEFINE SIPX_ALLOCATED}
Const SIPX_ALLOCATED = $00000001;
{$DEFINE SIPX_CONNECTING}
Const SIPX_CONNECTING = $00000002;
{$DEFINE SIPX_LISTENING}
Const SIPX_LISTENING = $00000003;
{$DEFINE SIPX_WAITING_ACCEPT}
Const SIPX_WAITING_ACCEPT = $00000004;
{$DEFINE SIPX_CONNECTED}
Const SIPX_CONNECTED = $00000005;
{$DEFINE SIPX_TERMINATING}
Const SIPX_TERMINATING = $00000006;










{$DEFINE SIPX_TCB_ALLOCATED}
Const SIPX_TCB_ALLOCATED = $00000000;
{$DEFINE SIPX_TCB_IN_USE}
Const SIPX_TCB_IN_USE = $00000001;






















{$DEFINE SIPX_CONN_UNSUPPORTED}
Const SIPX_CONN_UNSUPPORTED = $00000000;
{$DEFINE SIPX_CONN_STREAM}
Const SIPX_CONN_STREAM = $00000001;
{$DEFINE SIPX_CONN_MESSAGE}
Const SIPX_CONN_MESSAGE = $00000002;
{$DEFINE SIPX_CONN_LONG_TERM}
Const SIPX_CONN_LONG_TERM = $00000003;
{$DEFINE SIPX_CONN_SHORT_TERM}
Const SIPX_CONN_SHORT_TERM = $00000004;
{$DEFINE SIPX_CONN_FRAGMENT}
Const SIPX_CONN_FRAGMENT = $00000005;
{$DEFINE SIPX_CONN_TRANSPARENT}
Const SIPX_CONN_TRANSPARENT = $00000006;
{$DEFINE SIPX_CONN_UNLIMITED_TSDU}
Const SIPX_CONN_UNLIMITED_TSDU = $FFFFFFFF;














{$DEFINE SIPX_SOCK_STATIC}
Const SIPX_SOCK_STATIC = $00000001;
{$DEFINE SIPX_SOCK_DYNAMIC}
Const SIPX_SOCK_DYNAMIC = $00000002;
{$DEFINE SIPX_SOCK_CHECKSUM}
Const SIPX_SOCK_CHECKSUM = $00000004;










{$DEFINE SIPX_SN_XSUM_FLAG}
Const SIPX_SN_XSUM_FLAG = $00000001;
{$DEFINE SIPX_SN_DEFAULT_FLAG}
Const SIPX_SN_DEFAULT_FLAG = $00000002;
{$DEFINE SIPX_SN_ACTIVE_FLAG}
Const SIPX_SN_ACTIVE_FLAG = $00000004;










{$DEFINE SIPX_SN_VIRTUAL_LAN}
Const SIPX_SN_VIRTUAL_LAN = $00000000;
{$DEFINE SIPX_SN_ETHERNET_II}
Const SIPX_SN_ETHERNET_II = $00000002;
{$DEFINE SIPX_SN_ETHERNET_802_2}
Const SIPX_SN_ETHERNET_802_2 = $00000003;
{$DEFINE SIPX_SN_TOKEN_RING}
Const SIPX_SN_TOKEN_RING = $00000004;
{$DEFINE SIPX_SN_ETHERNET_802_3}
Const SIPX_SN_ETHERNET_802_3 = $00000005;
{$DEFINE SIPX_SN_802_4}
Const SIPX_SN_802_4 = $00000006;
{$DEFINE SIPX_SN_NOVELL_PCN2}
Const SIPX_SN_NOVELL_PCN2 = $00000007;
{$DEFINE SIPX_SN_GNET}
Const SIPX_SN_GNET = $00000008;
{$DEFINE SIPX_SN_PRONET_10}
Const SIPX_SN_PRONET_10 = $00000009;
{$DEFINE SIPX_SN_ETHERNET_SNAP}
Const SIPX_SN_ETHERNET_SNAP = $0000000a;
{$DEFINE SIPX_SN_TOKEN_RING_SNAP}
Const SIPX_SN_TOKEN_RING_SNAP = $0000000b;
{$DEFINE SIPX_SN_LANPAC_II}
Const SIPX_SN_LANPAC_II = $0000000c;
{$DEFINE SIPX_SN_ISDN}
Const SIPX_SN_ISDN = $0000000d;
{$DEFINE SIPX_SN_NOVELL_RX_NET}
Const SIPX_SN_NOVELL_RX_NET = $0000000e;
{$DEFINE SIPX_SN_IBM_PCN2_802_2}
Const SIPX_SN_IBM_PCN2_802_2 = $0000000f;
{$DEFINE SIPX_SN_IBM_PCN2_SNAP}
Const SIPX_SN_IBM_PCN2_SNAP = $00000010;
{$DEFINE SIPX_SN_OMNINET_4}
Const SIPX_SN_OMNINET_4 = $00000011;
{$DEFINE SIPX_SN_3270_COAXA}
Const SIPX_SN_3270_COAXA = $00000012;
{$DEFINE SIPX_SN_IP}
Const SIPX_SN_IP = $00000013;
{$DEFINE SIPX_SN_FDDI_802_2}
Const SIPX_SN_FDDI_802_2 = $00000014;
{$DEFINE SIPX_SN_IVDALN_802_9}
Const SIPX_SN_IVDALN_802_9 = $00000015;
{$DEFINE SIPX_SN_DATACO_OSI}
Const SIPX_SN_DATACO_OSI = $00000016;
{$DEFINE SIPX_SN_FDDI_SNAP}
Const SIPX_SN_FDDI_SNAP = $00000017;
{$DEFINE SIPX_SN_TYPE_UNKNOWN}
Const SIPX_SN_TYPE_UNKNOWN = $FFFFFFFF;











(* TC #define SIPX_SUCCESS ( x ) ! ( ( ( nuint32 ) ( x ) ) & 0x80000000 )  *)
(* TC #define SIPX_ERROR ( x ) ( ( ( ( nuint32 ) ( x ) ) & 0x80000000 ) ! = 0 )  *)









{$DEFINE SIPX_SUCCESSFUL}
Const SIPX_SUCCESSFUL = $00000000;
{$DEFINE SIPX_PENDING}
Const SIPX_PENDING = $00000001;

{$DEFINE SIPX_ACCESS_DENIED}
Const SIPX_ACCESS_DENIED = $80000001;
{$DEFINE SIPX_ACCESS_VIOLATION}
Const SIPX_ACCESS_VIOLATION = $80000002;
{$DEFINE SIPX_CANCELED}
Const SIPX_CANCELED = $80000003;
{$DEFINE SIPX_CONNECTION_ABORTED}
Const SIPX_CONNECTION_ABORTED = $80000004;
{$DEFINE SIPX_CANNOT_CANCEL}
Const SIPX_CANNOT_CANCEL = $80000005;
{$DEFINE SIPX_CONNECTION_TERMINATED}
Const SIPX_CONNECTION_TERMINATED = $80000006;
{$DEFINE SIPX_INSUFFICIENT_RESOURCES}
Const SIPX_INSUFFICIENT_RESOURCES = $80000007;
{$DEFINE SIPX_INVALID_SUBNETWORK_HANDLE}
Const SIPX_INVALID_SUBNETWORK_HANDLE = $80000008;
{$DEFINE SIPX_DATA_OVERFLOW}
Const SIPX_DATA_OVERFLOW = $80000009;
{$DEFINE SIPX_INVALID_CONNECTION_HANDLE}
Const SIPX_INVALID_CONNECTION_HANDLE = $8000000A;
{$DEFINE SIPX_INVALID_FRAGMENT_COUNT}
Const SIPX_INVALID_FRAGMENT_COUNT = $8000000B;
{$DEFINE SIPX_INVALID_FRAGMENT_LIST}
Const SIPX_INVALID_FRAGMENT_LIST = $8000000C;
{$DEFINE SIPX_INVALID_HANDLE}
Const SIPX_INVALID_HANDLE = $8000000D;
{$DEFINE SIPX_INVALID_IOCTL_BUFFER_LEN}
Const SIPX_INVALID_IOCTL_BUFFER_LEN = $8000000E;
{$DEFINE SIPX_INVALID_IOCTL_FUNCTION}
Const SIPX_INVALID_IOCTL_FUNCTION = $8000000F;
{$DEFINE SIPX_INVALID_INFO_TYPE}
Const SIPX_INVALID_INFO_TYPE = $80000010;
{$DEFINE SIPX_INVALID_MUX_GROUP_HANDLE}
Const SIPX_INVALID_MUX_GROUP_HANDLE = $80000012;
{$DEFINE SIPX_INVALID_NETWORK_ADDRESS}
Const SIPX_INVALID_NETWORK_ADDRESS = $80000013;
{$DEFINE SIPX_INVALID_NWTCB}
Const SIPX_INVALID_NWTCB = $80000014;
{$DEFINE SIPX_INVALID_NWTCB_FLAGS}
Const SIPX_INVALID_NWTCB_FLAGS = $80000015;
{$DEFINE SIPX_INVALID_PARAMETER}
Const SIPX_INVALID_PARAMETER = $80000016;
{$DEFINE SIPX_INVALID_PARAMETER_MIX}
Const SIPX_INVALID_PARAMETER_MIX = $80000017;
{$DEFINE SIPX_INVALID_QUERY_TYPE}
Const SIPX_INVALID_QUERY_TYPE = $80000018;
{$DEFINE SIPX_INVALID_SERVICE_TYPE}
Const SIPX_INVALID_SERVICE_TYPE = $80000019;
{$DEFINE SIPX_INVALID_SOCKET_HANDLE}
Const SIPX_INVALID_SOCKET_HANDLE = $8000001A;
{$DEFINE SIPX_INVALID_STATE}
Const SIPX_INVALID_STATE = $8000001B;
{$DEFINE SIPX_INVALID_SYNC_TYPE}
Const SIPX_INVALID_SYNC_TYPE = $8000001C;
{$DEFINE SIPX_INVALID_TRANSPORT_EVENT}
Const SIPX_INVALID_TRANSPORT_EVENT = $8000001D;
{$DEFINE SIPX_MEMORY_LOCK_ERROR}
Const SIPX_MEMORY_LOCK_ERROR = $8000001E;
{$DEFINE SIPX_NO_SUBNETS_BOUND_TO_IPX}
Const SIPX_NO_SUBNETS_BOUND_TO_IPX = $8000001F;
{$DEFINE SIPX_NO_RESPONSE_FROM_TARGET}
Const SIPX_NO_RESPONSE_FROM_TARGET = $80000020;
{$DEFINE SIPX_NO_ROUTE_TO_TARGET}
Const SIPX_NO_ROUTE_TO_TARGET = $80000021;
{$DEFINE SIPX_SERVICE_NOT_ACTIVE}
Const SIPX_SERVICE_NOT_ACTIVE = $80000022;
{$DEFINE SIPX_NWTCB_IN_USE}
Const SIPX_NWTCB_IN_USE = $80000023;
{$DEFINE SIPX_PARTIAL_SERVER_INFO}
Const SIPX_PARTIAL_SERVER_INFO = $80000024;
{$DEFINE SIPX_REQUEST_NOT_PENDING}
Const SIPX_REQUEST_NOT_PENDING = $80000025;
{$DEFINE SIPX_SOCKET_IN_USE}
Const SIPX_SOCKET_IN_USE = $80000026;
{$DEFINE SIPX_UNSUCCESSFUL}
Const SIPX_UNSUCCESSFUL = $80000027;
{$DEFINE SIPX_INTERNAL_ERROR}
Const SIPX_INTERNAL_ERROR = $80000028;
{$DEFINE SIPX_SERVICE_ALREADY_ACTIVE}
Const SIPX_SERVICE_ALREADY_ACTIVE = $80000029;
{$DEFINE SIPX_INVALID_SERVICE_NAME}
Const SIPX_INVALID_SERVICE_NAME = $8000002A;
{$DEFINE SIPX_CHECKSUM_NOT_SUPPORTED}
Const SIPX_CHECKSUM_NOT_SUPPORTED = $8000002B;
{$DEFINE SIPX_PRIMITIVE_NOT_SUPPORTED}
Const SIPX_PRIMITIVE_NOT_SUPPORTED = $8000002C;








Const
TA_IPX_SPX = 1;
TA_COUNT = 2;
Type TAG_TRANSPORT_ADDR_TYPE = 0..2;
TRANSPORT_ADDR_TYPE = TAG_TRANSPORT_ADDR_TYPE;







Type
    TAG_IPXADDR = Record
        NANet  :  Array[0..3] Of  nuint8 ;
        NANode  :  Array[0..5] Of  nuint8 ;
        NASocket  :  Array[0..1] Of  nuint8 ;
    End;
    IPXADDR = TAG_IPXADDR;
    PIPXADDR = ^TAG_IPXADDR;










Type
    TAG_NETADDR = Record
        NAType  :   nuint32 ;
        NALength  :   nuint32 ;
        NAGenAddress  :  Array[0..SIPX_MAX_TRANS_ADDR_LEN-1] Of  nuint8 ;  (* union statement *)
    End;
    NETADDR = TAG_NETADDR;
    PNETADDR = ^TAG_NETADDR;







Type
    TAG_FRAGMENT = Record
        FAddress  :   nptr ;
        FLength  :   nuint32 ;
    End;
    FRAGMENT = TAG_FRAGMENT;
    PFRAGMENT = ^TAG_FRAGMENT;







Type
    SIPXSOCK_HANDLE  =  ^TAG_NWSOCKET_CONTEXT;
    PSIPXSOCK_HANDLE  =  ^TAG_NWSOCKET_CONTEXT;






Type
    SIPXCONN_HANDLE  =  ^TAG_NWCONNECT_CONTEXT;
    PSIPXCONN_HANDLE  =  ^TAG_NWCONNECT_CONTEXT;






Type SIPXSUBNET_HANDLE  =   nuint32 ;






Type
    SIPXMUXGRP_HANDLE  =  ^TAG_NWMUXGRP_CONTEXT;
    PSIPXMUXGRP_HANDLE  =  ^TAG_NWMUXGRP_CONTEXT;






Type
    TAG_NWTCB = Record
        TCBNext  :  ^TAG_NWTCB;
        TCBPrevious  :  ^TAG_NWTCB;
        TCBSockHandle  :   SIPXSOCK_HANDLE ;
        TCBConnHandle  :   SIPXCONN_HANDLE ;
        TCBClientContext  :   nptr ;
        TCBTransportEvent  :   nuint32 ;
        TCBTimeout  :   nuint32 ;  (* union statement *)
        TCBFinalStatus  :   nuint32 ;
        TCBBytesTransferred  :   nuint32 ;
        TCBFlags  :   nflag32 ;
        TCBRemoteAddress  :   NETADDR ;
        TCBSubnetworkHandle  :   SIPXSUBNET_HANDLE ;
        TCBMsgSequenceNumber  :   nuint32 ;
        TCBPacketType  :   nuint8 ;
        TCBDataStreamType  :   nuint8 ;
        TCBReserved  :  Array[0..1] Of  nuint8 ;
        TCBFragmentCount  :   nuint32 ;
        TCBFragmentList  :   PFRAGMENT ;
    End;
    NWTCB = TAG_NWTCB;
    PNWTCB = ^TAG_NWTCB;
    PPNWTCB = ^TAG_NWTCB;













Type
    TAG_SIPX_SUBNET_INFO = Record
        SNSubnetworkHandle  :   SIPXSUBNET_HANDLE ;
        SNMaxNsduSize  :   nuint32 ;
        SNNetAddress  :   NETADDR ;
        SNFlags  :   nflag32 ;
        SNSubnetworkType  :   nuint32 ;
        Reserved  :  Array[0..3] Of  nuint32 ;
    End;
    SIPX_SUBNET_INFO = TAG_SIPX_SUBNET_INFO;
    PSIPX_SUBNET_INFO = ^TAG_SIPX_SUBNET_INFO;



Type
    TAG_SIPX_API_INFO = Record
        AIApiVersion  :   nuint32 ;
        AIIpxVersion  :   nuint32 ;
        AISpxVersion  :   nuint32 ;
        Reserved  :  Array[0..3] Of  nuint32 ;
        AISubnetCount  :   nuint32 ;
        AISubnetInfo  :  Array[0..0] Of  SIPX_SUBNET_INFO ;
    End;
    SIPX_API_INFO = TAG_SIPX_API_INFO;
    PSIPX_API_INFO = ^TAG_SIPX_API_INFO;







Type
    TAG_SIPX_SOCKET_INFO = Record
        SIIpxVersion  :   nuint32 ;
        SIAttributeFlags  :   nflag32 ;
        SISocketNumber  :   nuint16 ;
        SIReserved  :   nuint16 ;
        SIPacketType  :   nuint32 ;
        SISubnetworkHandle  :   SIPXSUBNET_HANDLE ;
        Reserved  :  Array[0..3] Of  nuint32 ;
    End;
    SIPX_SOCKET_INFO = TAG_SIPX_SOCKET_INFO;
    PSIPX_SOCKET_INFO = ^TAG_SIPX_SOCKET_INFO;






Type
    TAG_SIPX_CONN_INFO = Record
        CISpxVersion  :   nuint32 ;
        CIState  :   nuint32 ;
        CIDataStreamType  :   nuint32 ;
        CIConnectionProfile  :   nuint32 ;
        CIInputMode  :   nuint32 ;
        CIStreamingTimer  :   nuint32 ;
        CIRetryCount  :   nuint32 ;
        CISocketHandle  :   SIPXSOCK_HANDLE ;
        CIMaxTsduSize  :   nuint32 ;
        CIOutputMode  :   nuint32 ;
        Reserved  :  Array[0..2] Of  nuint32 ;
    End;
    SIPX_CONN_INFO = TAG_SIPX_CONN_INFO;
    PSIPX_CONN_INFO = ^TAG_SIPX_CONN_INFO;






Type
    TAG_SIPX_NWTCB_INFO = Record
        NWIState  :   nuint32 ;
        NWIEventType  :   nuint32 ;
        NWIEventInfo  :   nuint32 ;
        Reserved  :  Array[0..3] Of  nuint32 ;
    End;
    SIPX_NWTCB_INFO = TAG_SIPX_NWTCB_INFO;
    PSIPX_NWTCB_INFO = ^TAG_SIPX_NWTCB_INFO;













Type
    TAG_SIPX_SERVICE_INFO = Record
        SIServerType  :   nuint16 ;
        SIServerName  :  Array[0..47] Of  nstr8 ;
        SINetwork  :  Array[0..3] Of  nuint8 ;
        SINode  :  Array[0..5] Of  nuint8 ;
        SISocket  :  Array[0..1] Of  nuint8 ;
        SIHops  :   nuint16 ;
    End;
    SIPX_SERVICE_INFO = TAG_SIPX_SERVICE_INFO;
    PSIPX_SERVICE_INFO = ^TAG_SIPX_SERVICE_INFO;





(* Not implemented Function NWSipxAcceptConnection (
    pNwtcb  :   PNWTCB ;
    hAcceptHandle  :   SIPXCONN_HANDLE 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)


(* Not implemented Function NWSipxAcceptConnectionEx (
    pNwtcb  :   PNWTCB ;
    pAcceptHandle  :   PSIPXCONN_HANDLE 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)


(* Not implemented Function NWSipxAdvertiseService (
    serviceType  :   nuint16 ;
    pServerName  :   pnstr8 ;
    hSockHandle  :   SIPXSOCK_HANDLE 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxAllocControlBlock (
    syncType  :   nuint32 ;
    pEventInfo  :   nptr ;
    ppNwtcb  :   PPNWTCB 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxCancelAdvertiseService (
    serviceType  :   nuint16 ;
    pServerName  :   pnstr8 ;
    hSockHandle  :   SIPXSOCK_HANDLE 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxCancelPendingRequest (
    pNwtcb  :   PNWTCB 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxChangeControlBlock (
    syncType  :   nuint32 ;
    pEventInfo  :   nptr ;
    pNwtcb  :   PNWTCB 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxCloseConnectionEndpoint (
    hConnHandle  :   SIPXCONN_HANDLE 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxCloseSocket (
    hSockHandle  :   SIPXSOCK_HANDLE 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxEstablishConnection (
    pNwtcb  :   PNWTCB 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxFreeControlBlock (
    pNwtcb  :   PNWTCB 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxFreeInformation (
    pInfoStruct  :   nptr 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxGetInformation (
    infoType  :   nuint32 ;
    hHandle  :   nptr ;
    ppInfoStruct  :   pnptr ;
    pInfoStructLen  :   pnuint32 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxGetInternetAddress (
    hSockHandle  :   SIPXSOCK_HANDLE ;
    pNetAddress  :   PNETADDR 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxGetMaxNsduSize (
    hSockHandle  :   SIPXSOCK_HANDLE 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxGetMaxTsduSize (
    hConnHandle  :   SIPXCONN_HANDLE 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxListenForConnection (
    pNwtcb  :   PNWTCB 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxOpenConnectionEndpoint (
    hSubnetworkHandle  :   SIPXSUBNET_HANDLE ;
    pSocket  :   pnuint16 ;
    pConnHandle  :   PSIPXCONN_HANDLE 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxOpenSocket (
    SocketAttributes  :   nflag32 ;
    hSubnetworkHandle  :   SIPXSUBNET_HANDLE ;
    pSocket  :   pnuint16 ;
    pSockHandle  :   PSIPXSOCK_HANDLE 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxPoll (
    pNwtcb  :   PNWTCB 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxQueryServices (
    queryType  :   nuint16 ;
    serviceType  :   nuint16 ;
    pNwtcb  :   PNWTCB 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxReceiveDatagram (
    pNwtcb  :   PNWTCB 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxReceiveMessage (
    pNwtcb  :   PNWTCB 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxRegisterForTransportEvent (
    pNwtcb  :   PNWTCB 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxSendDatagram (
    pNwtcb  :   PNWTCB 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxSendMessage (
    pNwtcb  :   PNWTCB 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxSetInformation (
    infoType  :   nuint32 ;
    hHandle  :   nptr ;
    pInfoStruct  :   nptr 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxTerminateConnection (
    pNwtcb  :   PNWTCB 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxWaitForSingleEvent (
    pNwtcb  :   PNWTCB ;
    timeOut  :   nuint32 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)



(* Not implemented Function NWSipxWaitForMultipleEvents (
    muxGroupHandle  :   SIPXMUXGRP_HANDLE ;
    timeOut  :   nuint32 ;
    ppNwtcb  :   PPNWTCB 
) : nuint32;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)





{$ENDIF}




