(*    (c) COPYRIGHT 1990,1991 by Novell, Inc.  All Rights Reserved.   *)

{$IFNDEF _NXT_H}

{$DEFINE _NXT_H}
(*_______________________________________________________________________
       Definitions and structures  for the Netware API Communications logic
     _______________________________________________________________________*)


(* assigned socket types *)


{$DEFINE SOC_DIAGNOSTICS}


Type
    IPXAddress = Record
        network  :  Array[0..3] Of  BYTE ;
        node  :  Array[0..5] Of  BYTE ;
        socket  :  Array[0..1] Of  BYTE ;
    End;



Type
    IPXHeader = Record
        checkSum  :   WORD ;
        length  :   WORD ;
        transportControl  :   BYTE ;
        packetType  :   BYTE ;
        destination  :   IPXAddress ;
        source  :   IPXAddress ;
    End;



Type
    SPXHeader = Record
        checksum  :   WORD ;
        length  :   WORD ;
        transportControl  :   BYTE ;
        packetType  :   BYTE ;
        destination  :   IPXAddress ;
        source  :   IPXAddress ;
        connectionControl  :   BYTE ;
        dataStreamType  :   BYTE ;
        sourceConnectionID  :   WORD ;
        destConnectionID  :   WORD ;
        sequenceNumber  :   WORD ;
        acknowledgeNumber  :   WORD ;
        allocationNumber  :   WORD ;
    End;


Type
    CONNECTION_INFO = Record
        connectionState  :   BYTE ;
        connectionFlags  :   BYTE ;
        sourceConnectionID  :   WORD ;
        destinationConnectionID  :   WORD ;
        sequenceNumber  :   WORD ;
        acknowledgeNumber  :   WORD ;
        allocationNumber  :   WORD ;
        remoteAcknowledgeNumber  :   WORD ;
        remoteAllocationNumber  :   WORD ;
        connectionSocket  :   WORD ;
        immediateAddress  :  Array[0..5] Of  BYTE ;
        destination  :   IPXAddress ;
        retransmissionCount  :   WORD ;
        estimatedRoundTripDelay  :   WORD ;
        retransmittedPackets  :   WORD ;
        suppressedPackets  :   WORD ;
    End;



{$IFNDEF ECB_STRUCTURES_DEFINED}

{$DEFINE ECB_STRUCTURES_DEFINED}

Type
    ECBFragment = Record
        address  :  ^variant;
        size  :   WORD ;
    End;

    ESRAddress = Procedure;

Type
    ECB = Record
        linkAddress  :  ^variant;
        esraddress1 : ESRAddress;
        inUseFlag  :   BYTE ;
        completionCode  :   BYTE ;
        socketNumber  :   WORD ;
        IPXWorkspace  :  Array[0..3] Of  BYTE ;
        driverWorkspace  :  Array[0..11] Of  BYTE ;
        immediateAddress  :  Array[0..5] Of  BYTE ;
        fragmentCount  :   WORD ;
        fragmentDescriptor  :  Array[0..4] Of  ECBFragment ;
    End;


Type
    AGLT = Record
        ecb  :   ECB ;
        taskID  :   DWORD ;
        retry  :   WORD ;
        hWnd  :   HANDLE ;
    End;

{$ENDIF}



(* Completion Codes *)


{$IFNDEF SUCCESSFUL}

{$DEFINE SUCCESSFUL}
Const SUCCESSFUL = $00;
{$ENDIF}


{$DEFINE SPX_NOT_INSTALLED}
Const SPX_NOT_INSTALLED = $00;
{$DEFINE SPX_INSTALLED}
Const SPX_INSTALLED = $FF;
{$DEFINE SPX_CONNECTION_OK}
Const SPX_CONNECTION_OK = $00;
{$DEFINE SPX_CONNECTION_STARTED}
Const SPX_CONNECTION_STARTED = $00;
{$DEFINE SPX_CONNECTION_ESTABLISHED}
Const SPX_CONNECTION_ESTABLISHED = $00;
{$DEFINE SPX_PACKET_SUCCESSFUL}
Const SPX_PACKET_SUCCESSFUL = $00;
{$DEFINE SPX_SOCKET_NOT_OPENED}
Const SPX_SOCKET_NOT_OPENED = $FF;
{$DEFINE SPX_MALFORMED_PACKET}
Const SPX_MALFORMED_PACKET = $FD;
{$DEFINE SPX_PACKET_OVERFLOW}
Const SPX_PACKET_OVERFLOW = $FD;
{$DEFINE SPX_LISTEN_CANCELED}
Const SPX_LISTEN_CANCELED = $FC;
{$DEFINE SPX_CONNECTION_TABLE_FULL}
Const SPX_CONNECTION_TABLE_FULL = $EF;
{$DEFINE SPX_INVALID_CONNECTION}
Const SPX_INVALID_CONNECTION = $EE;
{$DEFINE SPX_NO_ANSWER_FROM_TARGET}
Const SPX_NO_ANSWER_FROM_TARGET = $ED;
{$DEFINE SPX_CONNECTION_FAILED}
Const SPX_CONNECTION_FAILED = $ED;
{$DEFINE SPX_CONNECTION_TERMINATED}
Const SPX_CONNECTION_TERMINATED = $ED;
{$DEFINE SPX_TERMINATED_POORLY}
Const SPX_TERMINATED_POORLY = $EC;

{$DEFINE NO_MGMT_MEMORY}
Const NO_MGMT_MEMORY = $F0;
{$DEFINE IPXSPX_NOT_INIT}
Const IPXSPX_NOT_INIT = $F1;
{$DEFINE IPX_NOT_INIT}
Const IPX_NOT_INIT = $F1;
{$DEFINE NO_DOS_MEMORY}
Const NO_DOS_MEMORY = $F2;
{$DEFINE NO_FREE_ECB}
Const NO_FREE_ECB = $F3;
{$DEFINE WINLOCK_FAILED}
Const WINLOCK_FAILED = $F4;
{$DEFINE OVER_MAX_LIMIT}
Const OVER_MAX_LIMIT = $F5;
{$DEFINE IPXSPX_PREV_INIT}
Const IPXSPX_PREV_INIT = $F6;

{$DEFINE CANCEL_FAILURE}
Const CANCEL_FAILURE = $F9;
{$DEFINE NO_PATH_TO_DESTINATION_FOUND}
Const NO_PATH_TO_DESTINATION_FOUND = $FA;
{$DEFINE ECB_CANCELLED}
Const ECB_CANCELLED = $FC;
{$DEFINE PACKET_OVERFLOW}
Const PACKET_OVERFLOW = $FD;
{$DEFINE PACKET_UNDELIVERABLE}
Const PACKET_UNDELIVERABLE = $FE;
{$DEFINE SOCKET_NOT_OPEN}
Const SOCKET_NOT_OPEN = $FF;
{$DEFINE TRANSMIT_FAILURE}
Const TRANSMIT_FAILURE = $FF;
{$DEFINE ECB_NOT_IN_USE}
Const ECB_NOT_IN_USE = $FF;
{$DEFINE SOCKET_ALREADY_OPEN}
Const SOCKET_ALREADY_OPEN = $FF;
{$DEFINE IMMEDIATE_ADDRESS_FAILED}
Const IMMEDIATE_ADDRESS_FAILED = $6666;
{$DEFINE IMMEDIATE_ADDRESS_COMPLETE}
Const IMMEDIATE_ADDRESS_COMPLETE = $7777;


(*----------------------------  PROTOTYPES  ----------------------------*)


{$IFDEF __cplusplus}

(* TC extern C *)
{$ENDIF}


(* TC  void void PASCAL CloseIPXWindow ( void );  *)


(* TC  int int FAR PASCAL IPXCancelEvent (  *)
(* TC  DWORD IPXTaskID ,  *)
(* TC  ECB FAR * eventControlBlock );  *)


(* TC  void void FAR PASCAL IPXCloseSocket (  *)
(* TC  DWORD IPXTaskID ,  *)
(* TC  WORD socket );  *)


(* TC  void void FAR PASCAL IPXDisconnectFromTarget (  *)
(* TC  DWORD IPXTaskID ,  *)
(* TC  BYTE FAR * internetAddress );  *)


(* TC  void void FAR PASCAL IPXGetInternetworkAddress (  *)
(* TC  DWORD IPXTaskID ,  *)
(* TC  BYTE FAR * internetAddress );  *)


(* TC  WORD WORD FAR PASCAL IPXGetIntervalMarker (  *)
(* TC  DWORD IPXTaskID );  *)


(* TC  int int FAR PASCAL IPXGetLocalTarget (  *)
(* TC  DWORD IPXTaskID ,  *)
(* TC  BYTE FAR * destination ,  *)
(* TC  BYTE FAR * immediateAddress ,  *)
(* TC  int FAR * transportTime );  *)


(* TC  WORD WORD FAR PASCAL IPXGetLocalTargetAsync (  *)
(* TC  AGLT FAR * listenAGLT ,  *)
(* TC  AGLT FAR * sendAGLT ,  *)
(* TC  BYTE FAR * destAddr );  *)


(* TC  WORD WORD FAR PASCAL IPXGetMaxPacketSize ( void );  *)


(* TC  WORD WORD FAR PASCAL IPXGetRetryCount ( void );  *)


(* TC  int int FAR PASCAL IPXInitialize (  *)
(* TC  DWORD FAR * IPXTaskID ,  *)
(* TC  WORD maxECBs ,  *)
(* TC  WORD maxPacketSize );  *)


(* TC  int int FAR PASCAL IPXSPXDeinit ( DWORD IPXTaskID );  *)


(* TC  void void FAR PASCAL IPXListenForPacket (  *)
(* TC  DWORD IPXTaskID ,  *)
(* TC  ECB FAR * eventControlBlock );  *)


(* TC  int int FAR PASCAL IPXOpenSocket (  *)
(* TC  DWORD IPXTaskID ,  *)
(* TC  WORD FAR * socket ,  *)
(* TC  BYTE socketType );  *)


(* TC  void void FAR PASCAL IPXRelinquishControl ( void );  *)


(* TC  void void FAR PASCAL IPXScheduleIPXEvent (  *)
(* TC  DWORD IPXTaskID ,  *)
(* TC  WORD timeDelay ,  *)
(* TC  ECB FAR * eventControlBlock );  *)


(* TC  void void FAR PASCAL IPXSendPacket (  *)
(* TC  DWORD IPXTaskID ,  *)
(* TC  ECB FAR * eventControlBlock );  *)


(* TC  void void FAR PASCAL IPXYield ( void );  *)


(* TC  BOOL BOOL PASCAL SetUpIPXWindow ( void );  *)


(* TC  void void FAR PASCAL SPXAbortConnection (  *)
(* TC  WORD SPXConnID );  *)


(* TC  int int FAR PASCAL SPXEstablishConnection (  *)
(* TC  DWORD IPXTaskID ,  *)
(* TC  BYTE retryCount ,  *)
(* TC  BYTE watchDog ,  *)
(* TC  WORD FAR * SPXConnID ,  *)
(* TC  ECB FAR * eventControlBlock );  *)


(* TC  int int FAR PASCAL SPXGetConnectionStatus (  *)
(* TC  DWORD IPXTaskID ,  *)
(* TC  WORD SPXConnID ,  *)
(* TC  CONNECTION_INFO FAR * connectionInfo );  *)


(* TC  int int FAR PASCAL SPXInitialize (  *)
(* TC  DWORD FAR * IPXTaskID ,  *)
(* TC  WORD maxECBs ,  *)
(* TC  WORD maxPacketSize ,  *)
(* TC  BYTE FAR * majorRevisionNumber ,  *)
(* TC  BYTE FAR * minorRevisionNumber ,  *)
(* TC  WORD FAR * maxConnections ,  *)
(* TC  WORD FAR * availableConnections );  *)


(* TC  void void FAR PASCAL SPXListenForConnection (  *)
(* TC  DWORD IPXTaskID ,  *)
(* TC  BYTE retryCount ,  *)
(* TC  BYTE watchDog ,  *)
(* TC  ECB FAR * eventControlBlock );  *)


(* TC  void void FAR PASCAL SPXListenForSequencedPacket (  *)
(* TC  DWORD IPXTaskID ,  *)
(* TC  ECB FAR * eventControlBlock );  *)


(* TC  void void FAR PASCAL SPXSendSequencedPacket (  *)
(* TC  DWORD IPXTaskID ,  *)
(* TC  WORD SPXConnID ,  *)
(* TC  ECB FAR * eventControlBlock );  *)


(* TC  void void FAR PASCAL SPXTerminateConnection (  *)
(* TC  DWORD IPXTaskID ,  *)
(* TC  WORD SPXConnID ,  *)
(* TC  ECB FAR * eventControlBlock );  *)


{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}


{$ENDIF}

