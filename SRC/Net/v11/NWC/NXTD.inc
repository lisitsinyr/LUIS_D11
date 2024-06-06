(*      (c) COPYRIGHT 1988-1990 by Novell, Inc.  All Rights Reserved.   *)

{$IFNDEF _NXT_H}

{$DEFINE _NXT_H}
(*__________________________________________________________________________
       Definitions and structures  for the Netware API Communications logic
    _________________________________________________________________________*)


{$I nwcaldef.inc}

(* assigned socket types *)


{$DEFINE SOC_DIAGNOSTICS}
{$DEFINE SHORT_LIVED}
Const SHORT_LIVED = $00;
{$DEFINE LONG_LIVED}
Const LONG_LIVED = $FF;
{$DEFINE ENABLE_WATCHDOG}
Const ENABLE_WATCHDOG = $FF;
{$DEFINE DISABLE_WATCHDOG}
Const DISABLE_WATCHDOG = $00;

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

      EsrAddress = Procedure;
Type
    ECB = Record
        linkAddress  :  ^variant;
        EsrAddress1 = EsrAddress;
        inUseFlag  :   BYTE ;
        completionCode  :   BYTE ;
        socketNumber  :   WORD ;
        IPXWorkspace  :  Array[0..3] Of  BYTE ;
        driverWorkspace  :  Array[0..11] Of  BYTE ;
        immediateAddress  :  Array[0..5] Of  BYTE ;
        fragmentCount  :   WORD ;
        fragmentDescriptor  :  Array[0..1] Of  ECBFragment ;
    End;

{$ENDIF}




{$DEFINE SPX_IS_INSTALLED}
Const SPX_IS_INSTALLED = $FF;
{$DEFINE SPX_NOT_INSTALLED}
Const SPX_NOT_INSTALLED = $00;
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


{$IFDEF __cplusplus}

(* TC extern C *)
{$ENDIF}


(* TC  int int IPXCancelEvent ( ECB far * eventControlBlock );  *)


(* TC  void void cdecl IPXCloseSocket ( WORD socketNumber );  *)


(* TC  void void IPXDisconnectFromTarget ( BYTE far * networkAddress );  *)


(* TC  void void IPXGetInternetworkAddress ( BYTE far * networkAddress );  *)


(* TC  WORD WORD cdecl IPXGetIntervalMarker ( void );  *)


(* TC  int int cdecl IPXGetLocalTarget ( BYTE far * networkAddress ,  *)
(* TC  BYTE far * immediateAddress ,  *)
(* TC  int far * transportTime );  *)


(* TC  WORD WORD cdecl IPXGetMaxPacketSize ( void );  *)


(* TC  BYTE BYTE cdecl IPXInitialize ( void );  *)


(* TC  void void IPXListenForPacket ( ECB far * eventControlBlock );  *)


(* TC  int int cdecl IPXOpenSocket ( BYTE far * socketNumber ,  *)
(* TC  BYTE socketType );  *)


(* internal procedure *)

(* TC  int int cdecl _IPXPacket ( ECB far * eventControlBlock ,  *)
(* TC  WORD functionNumber );  *)


(* internal procedure *)

(* TC  void void cdecl _IPXrequest ( WORD timeDelay ,  *)
(* TC  ECB far * eventControlBlock ,  *)
(* TC  WORD functionNumber );  *)


(* TC  void void cdecl IPXRelinquishControl ( void );  *)


(* TC  void void IPXScheduleIPXEvent ( WORD timeUnits ,  *)
(* TC  ECB far * eventControlBlock );  *)


(* internal procedure *)

(* TC  void void IPXScheduleSpecialEvent ( WORD timeUnits ,  *)
(* TC  ECB far * eventControlBlock );  *)


(* TC  void void IPXSendPacket ( ECB far * eventControlBlock );  *)


(* TC  void void cdecl SPXAbortConnection ( WORD connectionID );  *)


(* TC  int int cdecl SPXEstablishConnection ( BYTE retryCount ,  *)
(* TC  BYTE watchDog ,  *)
(* TC  WORD far * connectionID ,  *)
(* TC  ECB far * eventControlBlock );  *)


(* TC  int int SPXGetConnectionStatus ( WORD connectionID ,  *)
(* TC  CONNECTION_INFO far * connectionInfo );  *)


(* TC  int int cdecl SPXInitialize ( BYTE far * majorRevisionNumber ,  *)
(* TC  BYTE far * minorRevisionNumber ,  *)
(* TC  WORD far * maxConnections ,  *)
(* TC  WORD far * availableConnection );  *)


(* TC  void void cdecl SPXListenForConnection ( BYTE retryCount ,  *)
(* TC  BYTE watchDog ,  *)
(* TC  ECB far * eventControlBlock );  *)


(* TC  void void cdecl SPXListenForSequencedPacket ( ECB far * eventControlBlock );  *)


(* internal procedure *)

(* TC  int int cdecl _SPXrequest ( WORD connectionID ,  *)
(* TC  ECB far * eventControlBlock ,  *)
(* TC  WORD functionNumber );  *)


(* TC  void void SPXSendSequencedPacket ( WORD connectionID ,  *)
(* TC  ECB far * eventControlBlock );  *)


(* TC  void void SPXTerminateConnection ( WORD connectionID ,  *)
(* TC  ECB far * eventControlBlock );  *)


{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}


{$ENDIF}

