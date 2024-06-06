(******************************************************************************

  %name: nwconnec.h %
  %version: 5 %
  %date_modified: Fri Oct  3 17:52:34 1997 %
  $Copyright:

  Copyright (c) 1989-1995 Novell, Inc.  All Rights Reserved.                      

  THIS WORK IS  SUBJECT  TO  U.S.  AND  INTERNATIONAL  COPYRIGHT  LAWS  AND
  TREATIES.   NO  PART  OF  THIS  WORK MAY BE  USED,  PRACTICED,  PERFORMED
  COPIED, DISTRIBUTED, REVISED, MODIFIED, TRANSLATED,  ABRIDGED, CONDENSED,
  EXPANDED,  COLLECTED,  COMPILED,  LINKED,  RECAST, TRANSFORMED OR ADAPTED
  WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC. ANY USE OR EXPLOITATION
  OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT THE PERPETRATOR TO
  CRIMINAL AND CIVIL LIABILITY.$

 *****************************************************************************)


{$IFNDEF  NWCONNECT_H }
    {$DEFINE NWCONNECT_H}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$I npackon.inc}
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    {$DEFINE C_SNAMESIZE}
    Const C_SNAMESIZE = 48;
    Type
        CONNECT_INFO = Record
            connID  :   NWCONN_HANDLE ;
            connectFlags  :   nuint16 ;
            sessionID  :   nuint16 ;
            connNumber  :   nuint16 ;
            serverAddr  :  Array[0..11] Of  nuint8 ;
            serverType  :   nuint16 ;
            serverName  :  Array[0..C_SNAMESIZE-1] Of  nstr8 ;
            clientType  :   nuint16 ;
            clientName  :  Array[0..C_SNAMESIZE-1] Of  nstr8 ;
        End;
    Type
        CONN_USE = Record
            systemElapsedTime  :   nuint32 ;
            bytesRead  :  Array[0..5] Of  nuint8 ;
            bytesWritten  :  Array[0..5] Of  nuint8 ;
            totalRequestPackets  :   nuint32 ;
        End;
    Type
        tNWINET_ADDR = Record
            networkAddr  :  Array[0..3] Of  nuint8 ;
            netNodeAddr  :  Array[0..5] Of  nuint8 ;
            socket  :   nuint16 ;
            connType  :   nuint16 ;
        End;
        NWINET_ADDR = tNWINET_ADDR;
    {$DEFINE CONNECTION_AVAILABLE}
    Const CONNECTION_AVAILABLE = $0001;
    {$DEFINE CONNECTION_PRIVATE}
    Const CONNECTION_PRIVATE = $0002;
    {$DEFINE CONNECTION_LOGGED_IN}
    Const CONNECTION_LOGGED_IN = $0004;
    {$DEFINE CONNECTION_LICENSED}
    Const CONNECTION_LICENSED = $0004;
    {$DEFINE CONNECTION_BROADCAST_AVAILABLE}
    Const CONNECTION_BROADCAST_AVAILABLE = $0008;
    {$DEFINE CONNECTION_ABORTED}
    Const CONNECTION_ABORTED = $0010;
    {$DEFINE CONNECTION_REFUSE_GEN_BROADCAST}
    Const CONNECTION_REFUSE_GEN_BROADCAST = $0020;
    {$DEFINE CONNECTION_BROADCASTS_DISABLED}
    Const CONNECTION_BROADCASTS_DISABLED = $0040;
    {$DEFINE CONNECTION_PRIMARY}
    Const CONNECTION_PRIMARY = $0080;
    {$DEFINE CONNECTION_NDS}
    Const CONNECTION_NDS = $0100;
    {$DEFINE CONNECTION_PNW}
    Const CONNECTION_PNW = $4000;
    {$DEFINE CONNECTION_AUTHENTICATED}
    Const CONNECTION_AUTHENTICATED = $8000;
    (* the following are for NWGetConnInfo *)
    (* ALL is VLM, OS2 and NT - NOT NETX *)
    {$DEFINE NW_CONN_TYPE}
    Const NW_CONN_TYPE = 1;
    {$DEFINE NW_CONN_BIND}
    Const NW_CONN_BIND = $0031;
    {$DEFINE NW_CONN_NDS}
    Const NW_CONN_NDS = $0032;
    {$DEFINE NW_CONN_PNW}
    Const NW_CONN_PNW = $0033;
    {$DEFINE NW_AUTHENTICATED}
    Const NW_AUTHENTICATED = 3;
    {$DEFINE NW_PBURST}
    Const NW_PBURST = 4;
    {$DEFINE NW_VERSION}
    Const NW_VERSION = 8;
    {$DEFINE NW_HARD_COUNT}
    Const NW_HARD_COUNT = 9;
    {$DEFINE NW_CONN_NUM}
    Const NW_CONN_NUM = 13;
    {$DEFINE NW_TRAN_TYPE}
    Const NW_TRAN_TYPE = 15;
    {$DEFINE NW_TRAN_IPX}
    Const NW_TRAN_IPX = $0021;
    {$DEFINE NW_TRAN_TCP}
    Const NW_TRAN_TCP = $0022;
    {$DEFINE NW_SESSION_ID}
    Const NW_SESSION_ID = $8000;
    {$DEFINE NW_SERVER_ADDRESS}
    Const NW_SERVER_ADDRESS = $8001;
    {$DEFINE NW_SERVER_NAME}
    Const NW_SERVER_NAME = $8002;
    (* End of new connection model calls. *)
    Function NWGetConnInfo (
        connHandle  :   NWCONN_HANDLE ;
        type1  :   nuint16 ;
        pData  :   nptr 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLockConnection (
        connHandle  :   NWCONN_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetConnectionUsageStats (
        connHandle  :   NWCONN_HANDLE ;
        connNumber  :   nuint16 ;
        Var pStatusBuffer  : CONN_USE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetConnectionInformation (
        connHandle  :   NWCONN_HANDLE ;
        connNumber  :   nuint16 ;
        pObjName  :   pnstr8 ;
        pObjType  :   pnuint16 ;
        pObjID  :   pnuint32 ;
        pLoginTime  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetInternetAddress (
        connHandle  :   NWCONN_HANDLE ;
        connNumber  :   nuint16 ;
        pInetAddr  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetInetAddr (
        connHandle  :   NWCONN_HANDLE ;
        connNum  :   nuint16 ;
        Var pInetAddr  : NWINET_ADDR
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Procedure NWGetMaximumConnections (
        pMaxConns  :   pnuint16 
    );
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetConnectionList (
        Mode  :   nuint16 ;
        Var connListBuffer  : NWCONN_HANDLE;
        connListSize  :   nuint16 ;
        pNumConns  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetConnectionStatus (
        connHandle  :   NWCONN_HANDLE ;
        Var pConnInfo  : CONNECT_INFO;
        connInfoSize  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetConnectionNumber (
        connHandle  :   NWCONN_HANDLE ;
        connNumber  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWClearConnectionNumber (
        connHandle  :   NWCONN_HANDLE ;
        connNumber  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetDefaultConnRef (
        pConnReference  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetDefaultConnectionID (
        Var pConnHandle  : NWCONN_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWGetConnectionID ( a , b , c , d ) NWGetConnectionHandle ( a , b , c , d )  *)
    Function NWGetConnectionHandle (
        pServerName  :   pnuint8 ;
        reserved1  :   nuint16 ;
        Var pConnHandle  : NWCONN_HANDLE;
        reserved2  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSetPrimaryConnectionID (
        connHandle  :   NWCONN_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetPrimaryConnectionID (
        Var pConnHandle  : NWCONN_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetObjectConnectionNumbers (
        connHandle  :   NWCONN_HANDLE ;
        pObjName  :   pnstr8 ;
        objType  :   nuint16 ;
        pNumConns  :   pnuint16 ;
        pConnHandleList  :   pnuint16 ;
        maxConns  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetConnListFromObject (
        connHandle  :   NWCONN_HANDLE ;
        objID  :   nuint32 ;
        searchConnNum  :   nuint32 ;
        pConnListLen  :   pnuint16 ;
        pConnList  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFNDEF NWOS2}
    Function NWIsIDInUse (
        connHandle  :   NWCONN_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* Not implemented Function NWGetPreferredServer (
        Var pConnHandle  : NWCONN_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWSetPreferredServer (
        connHandle  :   NWCONN_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    {$ELSE}
    (* Not implemented Function NWResetConnectionConfig (
        flags  :   nuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

