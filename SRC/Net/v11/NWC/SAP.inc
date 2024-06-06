(*  COPYRIGHT (c) 1988-1991 by Novell, Inc.  All Rights Reserved.  *)

{$IFNDEF _SAP_H}

{$DEFINE _SAP_H}

(*______________________________________________________________

            Definitions for the NetWare API Service Advertising 
                     Protocols logic
      ______________________________________________________________*)


{$IFNDEF _NXT_H}

{$I nxtd.inc}
{$ENDIF}


(*   #include <stddef.h> *)


{$DEFINE SAP_SOCKET}
Const SAP_SOCKET = $452;
{$DEFINE SAP_PACKET_TYPE}
Const SAP_PACKET_TYPE = 2;
 ONE_MINUTE = ( 60 * 18 );
{$DEFINE IPX_EVENT_CANCELED}
Const IPX_EVENT_CANCELED = $FC;
{$DEFINE NOT_SUPPORTED}
Const NOT_SUPPORTED = 1;
{$DEFINE INVALID_QUERY_TYPE}
Const INVALID_QUERY_TYPE = 2;
{$DEFINE PERIODIC_ID_PACKET}
Const PERIODIC_ID_PACKET = 2;
{$IFNDEF SUCCESSFUL}

{$DEFINE SUCCESSFUL}
Const SUCCESSFUL = $00;
{$ENDIF}

{$IFNDEF FAILURE}

 FAILURE =( - 1 );
{$ENDIF}



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



(* SAP packet *)

Type
    SAP_BUFFER = Record
        theECB  :   ECB ;
        packet  :   SAPHeader ;
    End;



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



Type
    SEND_PACKET = Record
        theECB  :   ECB ;
        SAPq  :   SAPQueryPacket ;
    End;



Type
    RECEIVE_PACKET = Record
        theECB  :   ECB ;
        SB  :   SAP ;
    End;



(* Prototypes *)


{$IFDEF __cplusplus}

(* TC extern C *)
{$ENDIF}


(* TC  void void far cdecl AdvertiseESRHandler ( void );  *)


(* TC  void void far cdecl Advertiser ( ECB far * usedECB );  *)


(* TC  int int AdvertiseService ( WORD ,  *)
(* TC  char * ,  *)
(* TC  BYTE * );  *)


(* TC  int int InitializeSAP ( void );  *)


(* TC  void void cdecl _LoadDS ( void );  *)


(* TC  int int QueryServices ( WORD queryType ,  *)
(* TC  WORD serverType ,  *)
(* TC  WORD returnSize ,  *)
(* TC  SAP * serviceBuffer );  *)


(* TC  void void far cdecl RespondESRHandler ( void );  *)


(* TC  void void far cdecl RespondToLocalQuery ( ECB far * usedRespondECB );  *)


(* TC  int int SetupListenForQuery ( void );  *)


(* TC  int int SetupRespondPacket ( WORD sapPacketType ,  *)
(* TC  char * serverName ,  *)
(* TC  WORD sType ,  *)
(* TC  WORD * sSocket ,  *)
(* TC  SAP_BUFFER * sap );  *)


(* TC  int int ShutdownSAP ( void );  *)


{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}


{$ENDIF}

