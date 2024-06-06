(******************************************************************************

  %name: nwndscon.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:08:52 1996 %
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

{$IFNDEF  NWNDSCON_H }
    {$DEFINE NWNDSCON_H}
    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$DEFINE NWNDS_CONNECTION}
    Const NWNDS_CONNECTION = $0001;
    {$DEFINE NWNDS_LICENSED}
    Const NWNDS_LICENSED = $0002;
    {$DEFINE NWNDS_AUTHENTICATED}
    Const NWNDS_AUTHENTICATED = $0004;
    {$DEFINE NWNDS_PACKET_BURST_AVAIL}
    Const NWNDS_PACKET_BURST_AVAIL = $0001;
    {$DEFINE NWNDS_NEEDED_MAX_IO}
    Const NWNDS_NEEDED_MAX_IO = $0040;
    {$DEFINE SYSTEM_LOCK}
    Const SYSTEM_LOCK = $0;
    {$DEFINE TASK_LOCK}
    Const TASK_LOCK = $4;
    {$DEFINE SYSTEM_DISCONNECT}
    Const SYSTEM_DISCONNECT = $0;
    {$DEFINE TASK_DISCONNECT}
    Const TASK_DISCONNECT = $1;
    {$DEFINE ALLREADY_ATTACHED}
    Const ALLREADY_ATTACHED = $1;
    {$DEFINE ATTACHED_NOT_AUTH}
    Const ATTACHED_NOT_AUTH = $2;
    {$DEFINE ATTACHED_AND_AUTH}
    Const ATTACHED_AND_AUTH = $4;
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    Function NWGetNearestDSConnRef (
        connRef  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetNearestDirectoryService (
        Var connHandle  : NWCONN_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSetDefaultNameContext (
        contextLength  :   nuint16 ;
        context  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetDefaultNameContext (
        bufferSize  :   nuint16 ;
        context  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetConnectionIDFromAddress (
        transType  :   nuint8 ;
        transLen  :   nuint32 ;
        transBuf  :   pnuint8 ;
        Var connHandle  : NWCONN_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetConnectionInfo (
        connHandle  :   NWCONN_HANDLE ;
        connStatus  :   pnuint8 ;
        connType  :   pnuint8 ;
        serverFlags  :   pnuint8 ;
        serverName  :   pnuint8 ;
        transType  :   pnuint8 ;
        transLen  :   pnuint32 ;
        transBuf  :   pnuint8 ;
        distance  :   pnuint16 ;
        maxPacketSize  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetConnectionSlot (
        connType  :   nuint8 ;
        transType  :   nuint8 ;
        transLen  :   nuint32 ;
        transBuf  :   pnuint8 ;
        Var connHandle  : NWCONN_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetPreferredDSServer (
        Var connHandle  : NWCONN_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSetPreferredDSTree (
        length  :   nuint16 ;
        treeName  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetNumConnections (
        numConnections  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetMonitoredConnection (
        Var connHandle  : NWCONN_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSSetMonitoredConnection (
        connHandle  :   NWCONN_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetConnectionIDFromName (
        nameLen  :   nuint32 ;
        name  :   pnuint8 ;
        Var connHandle  : NWCONN_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWIsDSAuthenticated : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSLockConnection (
        connHandle  :   NWCONN_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSUnlockConnection (
        connHandle  :   NWCONN_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetPreferredConnName (
        preferredName  :   pnuint8 ;
        preferredType  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWFreeConnectionSlot (
        connHandle  :   NWCONN_HANDLE ;
        disconnectType  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetNextConnectionID (
        Var connHandle  : NWCONN_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
{$ENDIF}

