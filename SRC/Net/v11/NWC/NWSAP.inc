(*      COPYRIGHT (c) 1989 by Novell, Inc.  All Rights Reserved.   *)

{$IFNDEF SAP_H}

{$DEFINE SAP_H}

{$IFNDEF _NXT_H}

{$I nxtw.inc}
{$ENDIF}


(*____________________________________________________________________________


     Header file that includes the definitions and structures needed for

     the NETWARE API Service Advertising Protocals Logic

 ___________________________________________________________________________*)



{$IFNDEF TRUE}

{$DEFINE TRUE}
Const TRUE = 1;
{$DEFINE FALSE}
Const FALSE = 0;
{$ENDIF}


{$DEFINE SAP_SOCKET}
Const SAP_SOCKET = $0452;
{$DEFINE SAP_PACKET_TYPE}
Const SAP_PACKET_TYPE = 2;
 ONE_MINUTE = ( 60 * 18 );
{$DEFINE IPX_EVENT_CANCELED}
Const IPX_EVENT_CANCELED = $FC;

{$IFNDEF SUCCESSFUL}

{$DEFINE SUCCESSFUL}
Const SUCCESSFUL = $00;
{$ENDIF}


 FAILURE =( - 1 );
{$DEFINE NOT_SUPPORTED}
Const NOT_SUPPORTED = 1;
{$DEFINE INVALID_QUERY_TYPE}
Const INVALID_QUERY_TYPE = 2;
{$DEFINE PERIODIC_ID_PACKET}
Const PERIODIC_ID_PACKET = 2;
{$DEFINE RESPONSE_ID_PACKET}
Const RESPONSE_ID_PACKET = 4;
{$DEFINE MAX_NUM_APPS}
Const MAX_NUM_APPS = 10;


{$DEFINE OPEN_SAP_SOCKET_ERROR}
Const OPEN_SAP_SOCKET_ERROR = $60;
{$DEFINE TOO_MANY_SERVERS_ON_NODE}
Const TOO_MANY_SERVERS_ON_NODE = $61;
{$DEFINE SAP_MEMORY_ALLOC_ERROR}
Const SAP_MEMORY_ALLOC_ERROR = $62;
{$DEFINE SERVER_ALREADY_ADVERTISING}
Const SERVER_ALREADY_ADVERTISING = $63;
{$DEFINE MULTIPLE_INSTANCES_ON_SOCKET}
Const MULTIPLE_INSTANCES_ON_SOCKET = $64;
{$DEFINE SAP_MEMORY_FREE_ERROR}
Const SAP_MEMORY_FREE_ERROR = $65;
{$DEFINE SAP_MEMORY_UNLOCK_ERROR}
Const SAP_MEMORY_UNLOCK_ERROR = $66;
{$DEFINE SAP_ECB_NOT_CANCELLED}
Const SAP_ECB_NOT_CANCELLED = $67;
{$DEFINE SAP_SERVER_NOT_ADVERTISING}
Const SAP_SERVER_NOT_ADVERTISING = $68;

(*__________________________________________________________________________*)





Type
    SAPHeader = Record
        checksum  :   WORD ;
        length  :   WORD ;
        transportControl  :   BYTE ;
        packetType  :   BYTE ;
        destination  :   IPXAddress ;
        source  :   IPXAddress ;
        SAPPacketType  :   WORD ;
        serverType  :   WORD ;
        serverName  :  Array[0..47] Of  BYTE ;
        serverAddress  :   IPXAddress ;
        interveningNetworks  :   WORD ;
    End;





(*__________________________________________________________________________*)






Type
    SAPQueryPacket = Record
        checksum  :   WORD ;
        length  :   WORD ;
        transportControl  :   BYTE ;
        packetType  :   BYTE ;
        destination  :   IPXAddress ;
        source  :   IPXAddress ;
        queryType  :   WORD ;
        serverType  :   WORD ;
    End;




(*__________________________________________________________________________*)



(* SAP packet *)


Type
    SAP_BUFFER = Record
        theECB  :   ECB ;
        packet  :   SAPHeader ;
    End;




(*__________________________________________________________________________*)




Type
    SAP = Record
        Header  :   IPXHeader ;
        ResponseType  :   WORD ;
        ServerType  :   WORD ;
        ServerName  :  Array[0..47] Of  BYTE ;
        Network  :  Array[0..3] Of  BYTE ;
        Node  :  Array[0..5] Of  BYTE ;
        Socket  :  Array[0..1] Of  BYTE ;
        InterveningNetworks  :   WORD ;
    End;




(*__________________________________________________________________________*)



Type
    SEND_PACKET = Record
        theECB  :   ECB ;
        SAPq  :   SAPQueryPacket ;
    End;



(*__________________________________________________________________________*)




Type
    RECEIVE_PACKET = Record
        theECB  :   ECB ;
        SB  :   SAP ;
    End;


(*____________________________  PROTOTYPES  ________________________________*)


{$IFDEF __cplusplus}

(* TC extern C *)
{$ENDIF}


(* TC  void void far pascal Advertiser ( void );  *)

(* TC  WORD WORD far pascal AdvertiseService (  *)
(* TC  WORD sType ,  *)
(* TC  char far * sName ,  *)
(* TC  WORD far * sSocket );  *)

(* TC  WORD WORD FAR PASCAL QueryServices (  *)
(* TC  WORD qType ,  *)
(* TC  WORD sType ,  *)
(* TC  WORD returnSize ,  *)
(* TC  SAP FAR * serviceBuffer );  *)

(* TC  void void far pascal RespondToLocalQuery ( void );  *)

(* TC  WORD WORD far pascal ShutdownSAP (  *)
(* TC  char far * serverName );  *)


{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}


{$ENDIF}

