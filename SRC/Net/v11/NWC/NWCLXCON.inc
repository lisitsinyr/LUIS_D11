(****************************************************************************

  %name: nwclxcon.h %
  %version: 12 %
  %date_modified: Thu May  1 14:15:31 1997 %
  $Copyright:

  Copyright (c) 1989-1995 Novell, Inc.  All Rights Reserved.

  THIS WORK IS  SUBJECT  TO  U.S.  AND  INTERNATIONAL  COPYRIGHT  LAWS  AND
  TREATIES.   NO  PART  OF  THIS  WORK MAY BE  USED,  PRACTICED,  PERFORMED
  COPIED, DISTRIBUTED, REVISED, MODIFIED, TRANSLATED,  ABRIDGED, CONDENSED,
  EXPANDED,  COLLECTED,  COMPILED,  LINKED,  RECAST, TRANSFORMED OR ADAPTED
  WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC. ANY USE OR EXPLOITATION
  OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT THE PERPETRATOR TO
  CRIMINAL AND CIVIL LIABILITY.$

 ***************************************************************************)


{$IFNDEF  NWCLXCON_H }
    {$DEFINE NWCLXCON_H}
    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
    {$IFNDEF  NWAPIDEF_H }
        {$I nwapidef.inc}
    {$ENDIF}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$I npackon.inc}
    (* Authentication States *)
    {$DEFINE NWCC_AUTHENT_STATE_NONE}
    Const NWCC_AUTHENT_STATE_NONE = $0000;
    {$DEFINE NWCC_AUTHENT_STATE_BIND}
    Const NWCC_AUTHENT_STATE_BIND = $0001;
    {$DEFINE NWCC_AUTHENT_STATE_NDS}
    Const NWCC_AUTHENT_STATE_NDS = $0002;
    (* Broadcast States *)
    {$DEFINE NWCC_BCAST_PERMIT_ALL}
    Const NWCC_BCAST_PERMIT_ALL = $0000;
    {$DEFINE NWCC_BCAST_PERMIT_SYSTEM}
    Const NWCC_BCAST_PERMIT_SYSTEM = $0001;
    {$DEFINE NWCC_BCAST_PERMIT_NONE}
    Const NWCC_BCAST_PERMIT_NONE = $0002;
    {$DEFINE NWCC_BCAST_PERMIT_POLL}
    Const NWCC_BCAST_PERMIT_POLL = $0003;
    (* NDS States *)
    {$DEFINE NWCC_NDS_NOT_CAPABLE}
    Const NWCC_NDS_NOT_CAPABLE = $0000;
    {$DEFINE NWCC_NDS_CAPABLE}
    Const NWCC_NDS_CAPABLE = $0001;
    (* License States *)
    {$DEFINE NWCC_NOT_LICENSED}
    Const NWCC_NOT_LICENSED = $0000;
    {$DEFINE NWCC_CONNECTION_LICENSED}
    Const NWCC_CONNECTION_LICENSED = $0001;
    {$DEFINE NWCC_HANDLE_LICENSED}
    Const NWCC_HANDLE_LICENSED = $0002;
    (* Name Format types *)
    {$DEFINE NWCC_NAME_FORMAT_NDS}
    Const NWCC_NAME_FORMAT_NDS = $0001;
    {$DEFINE NWCC_NAME_FORMAT_BIND}
    Const NWCC_NAME_FORMAT_BIND = $0002;
    {$DEFINE NWCC_NAME_FORMAT_NDS_TREE}
    Const NWCC_NAME_FORMAT_NDS_TREE = $0008;
    (* Transport types *)
    {$DEFINE NWCC_TRAN_TYPE_IPX}
    Const NWCC_TRAN_TYPE_IPX = $00000001;
    {$DEFINE NWCC_TRAN_TYPE_UDP}
    Const NWCC_TRAN_TYPE_UDP = $00000002;
    {$DEFINE NWCC_TRAN_TYPE_DDP}
    Const NWCC_TRAN_TYPE_DDP = $00000003;
    {$DEFINE NWCC_TRAN_TYPE_ASP}
    Const NWCC_TRAN_TYPE_ASP = $00000004;
    {$DEFINE NWCC_TRAN_TYPE_WILD}
    Const NWCC_TRAN_TYPE_WILD = $00008000;
    (* Open States *)
    {$DEFINE NWCC_OPEN_LICENSED}
    Const NWCC_OPEN_LICENSED = $0001;
    {$DEFINE NWCC_OPEN_UNLICENSED}
    Const NWCC_OPEN_UNLICENSED = $0002;
    {$DEFINE NWCC_OPEN_PRIVATE}
    Const NWCC_OPEN_PRIVATE = $0004;
    {$DEFINE NWCC_OPEN_PUBLIC}
    Const NWCC_OPEN_PUBLIC = $0008;
    {$DEFINE NWCC_OPEN_EXISTING_HANDLE}
    Const NWCC_OPEN_EXISTING_HANDLE = $0010;
    (* Scan connection information flags (nuint value) *)
    {$DEFINE NWCC_MATCH_NOT_EQUALS}
    Const NWCC_MATCH_NOT_EQUALS = $0000;
    {$DEFINE NWCC_MATCH_EQUALS}
    Const NWCC_MATCH_EQUALS = $0001;
    {$DEFINE NWCC_RETURN_PUBLIC}
    Const NWCC_RETURN_PUBLIC = $0002;
    {$DEFINE NWCC_RETURN_PRIVATE}
    Const NWCC_RETURN_PRIVATE = $0004;
    {$DEFINE NWCC_RETURN_LICENSED}
    Const NWCC_RETURN_LICENSED = $0008;
    {$DEFINE NWCC_RETURN_UNLICENSED}
    Const NWCC_RETURN_UNLICENSED = $0010;
    (* Reserved Value *)
    {$DEFINE NWCC_RESERVED}
    Const NWCC_RESERVED = $0000;
    (* Values used with Security Flags *)
    (* NOTE: 
Two previously defined security flags have been redefined in order to be
compliant with the ANSI standard maximum length of 31.  Here is a list showing
what the #define was previously, and what it has been redefined to be.
PREVIOUSLY                          CURRENTLY
NWCC_SECURITY_SIGNING_NOT_IN_USE    NWCC_SECUR_SIGNING_NOT_IN_USE
NWCC_SECURITY_LEVEL_SIGN_HEADERS    NWCC_SECUR_LEVEL_SIGN_HEADERS
*)
    {$DEFINE NWCC_SECURITY_SIGNING_NOT_IN_USE}
    Const NWCC_SECURITY_SIGNING_NOT_IN_USE = $00000000;
    {$DEFINE NWCC_SECURITY_SIGNING_IN_USE}
    Const NWCC_SECURITY_SIGNING_IN_USE = $00000001;
    {$DEFINE NWCC_SECURITY_LEVEL_CHECKSUM}
    Const NWCC_SECURITY_LEVEL_CHECKSUM = $00000100;
    {$DEFINE NWCC_SECURITY_LEVEL_SIGN_HEADERS}
    Const NWCC_SECURITY_LEVEL_SIGN_HEADERS = $00000200;
    {$DEFINE NWCC_SECURITY_LEVEL_SIGN_ALL}
    Const NWCC_SECURITY_LEVEL_SIGN_ALL = $00000400;
    {$DEFINE NWCC_SECURITY_LEVEL_ENCRYPT}
    Const NWCC_SECURITY_LEVEL_ENCRYPT = $00000800;
    (* Feature Codes *)
    {$DEFINE NWCC_FEAT_PRIV_CONN}
    Const NWCC_FEAT_PRIV_CONN = $0001;
    {$DEFINE NWCC_FEAT_REQ_AUTH}
    Const NWCC_FEAT_REQ_AUTH = $0002;
    {$DEFINE NWCC_FEAT_SECURITY}
    Const NWCC_FEAT_SECURITY = $0003;
    {$DEFINE NWCC_FEAT_NDS}
    Const NWCC_FEAT_NDS = $0004;
    {$DEFINE NWCC_FEAT_NDS_MTREE}
    Const NWCC_FEAT_NDS_MTREE = $0005;
    {$DEFINE NWCC_FEAT_PRN_CAPTURE}
    Const NWCC_FEAT_PRN_CAPTURE = $0006;
    Type
        tagNWCCTranAddr = Record
            type1  :   nuint32 ;
            len  :   nuint32 ;
            buffer  :   pnuint8 ;
        End;
        NWCCTranAddr = tagNWCCTranAddr;
        pNWCCTranAddr = ^tagNWCCTranAddr;
    Type
        tagNWCCVersion = Record
            major  :   nuint ;
            minor  :   nuint ;
            revision  :   nuint ;
        End;
        NWCCVersion = tagNWCCVersion;
        pNWCCVersion = ^tagNWCCVersion;
    (* Info Types *)
    {$DEFINE NWCC_INFO_NONE}
    Const NWCC_INFO_NONE = 0;
    {$DEFINE NWCC_INFO_AUTHENT_STATE}
    Const NWCC_INFO_AUTHENT_STATE = 1;
    {$DEFINE NWCC_INFO_BCAST_STATE}
    Const NWCC_INFO_BCAST_STATE = 2;
    {$DEFINE NWCC_INFO_CONN_REF}
    Const NWCC_INFO_CONN_REF = 3;
    {$DEFINE NWCC_INFO_TREE_NAME}
    Const NWCC_INFO_TREE_NAME = 4;
    {$DEFINE NWCC_INFO_CONN_NUMBER}
    Const NWCC_INFO_CONN_NUMBER = 5;
    {$DEFINE NWCC_INFO_USER_ID}
    Const NWCC_INFO_USER_ID = 6;
    {$DEFINE NWCC_INFO_SERVER_NAME}
    Const NWCC_INFO_SERVER_NAME = 7;
    {$DEFINE NWCC_INFO_NDS_STATE}
    Const NWCC_INFO_NDS_STATE = 8;
    {$DEFINE NWCC_INFO_MAX_PACKET_SIZE}
    Const NWCC_INFO_MAX_PACKET_SIZE = 9;
    {$DEFINE NWCC_INFO_LICENSE_STATE}
    Const NWCC_INFO_LICENSE_STATE = 10;
    {$DEFINE NWCC_INFO_DISTANCE}
    Const NWCC_INFO_DISTANCE = 11;
    {$DEFINE NWCC_INFO_SERVER_VERSION}
    Const NWCC_INFO_SERVER_VERSION = 12;
    {$DEFINE NWCC_INFO_TRAN_ADDR}
    Const NWCC_INFO_TRAN_ADDR = 13;
    {$DEFINE NWCC_INFO_RETURN_ALL}
    Const NWCC_INFO_RETURN_ALL = $FFFF;
    (* Current Info Version *)
    {$DEFINE NWCC_INFO_VERSION_1}
    Const NWCC_INFO_VERSION_1 = $0001;
    {$DEFINE NWCC_INFO_VERSION_2}
    Const NWCC_INFO_VERSION_2 = $0002;
    (* Should use above definitions instead of this one *)
    {$DEFINE NWCC_INFO_VERSION}
    Const NWCC_INFO_VERSION = NWCC_INFO_VERSION_1;
    Type
        tagNWCCConnInfo = Record
            authenticationState  :   nuint ;
            broadcastState  :   nuint ;
            connRef  :   nuint32 ;
            treeName  :  Array[0..NW_MAX_TREE_NAME_LEN-1] Of  nstr ;
            connNum  :   nuint ;
            userID  :   nuint32 ;
            serverName  :  Array[0..NW_MAX_SERVER_NAME_LEN-1] Of  nstr ;
            NDSState  :   nuint ;
            maxPacketSize  :   nuint ;
            licenseState  :   nuint ;
            distance  :   nuint ;
            serverVersion  :   NWCCVersion ;
            {$IFDEF NWCC_INFO_VERSION_2}
            tranAddr  :   pNWCCTranAddr ;
            {$ENDIF}
        End;
        NWCCConnInfo = tagNWCCConnInfo;
        pNWCCConnInfo = ^tagNWCCConnInfo;
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    Function NWCLXInit (
        reserved1  :   nptr ;
        reserved2  :   nptr 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCLXTerm (
        reserved  :   nptr 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Procedure NWCCGetCLXVersion (
        majorVersion  :   pnuint8 ;
        minorVersion  :   pnuint8 ;
        revisionLevel  :   pnuint8 ;
        betaReleaseLevel  :   pnuint8 
    );
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCOpenConnByName (
        startConnHandle  :   NWCONN_HANDLE ;
        name  :   pnstr8 ;
        nameFormat  :   nuint ;
        openState  :   nuint ;
        tranType  :   nuint ;
        Var pConnHandle  :  NWCONN_HANDLE 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCOpenConnByAddr (
        tranAddr  :   pNWCCTranAddr ;
        openState  :   nuint ;
        reserved  :   nuint ;
        pConnHandle  :   pNWCONN_HANDLE 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCOpenConnByRef (
        connRef  :   nuint32 ;
        openState  :   nuint ;
        reserved  :   nuint ;
        pConnHandle  :   pNWCONN_HANDLE 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCCloseConn (
        connHandle  :   NWCONN_HANDLE 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCSysCloseConnRef (
        connRef  :   nuint32 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCMakeConnPermanent (
        connHandle  :   NWCONN_HANDLE 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCLicenseConn (
        connHandle  :   NWCONN_HANDLE 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCUnlicenseConn (
        connHandle  :   NWCONN_HANDLE 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCGetConnRef (
        connHandle  :   NWCONN_HANDLE ;
        connRef  :   pnuint32 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCGetPrefServerName (
        len  :   nuint ;
        prefServer  :   pnstr 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCSetPrefServerName (
        prefServer  :   pnstr 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCGetPrimConnRef (
        connRef  :   pnuint32 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCSetPrimConn (
        connHandle  :   NWCONN_HANDLE 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCScanConnRefs (
        scanIterator  :   pnuint32 ;
        connRef  :   pnuint32 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCGetConnInfo (
        connHandle  :   NWCONN_HANDLE ;
        infoType  :   nuint ;
        len  :   nuint ;
        buffer  :   nptr 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCGetConnRefInfo (
        connRef  :   nuint32 ;
        infoType  :   nuint ;
        len  :   nuint ;
        buffer  :   nptr 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCGetAllConnInfo (
        connHandle  :   NWCONN_HANDLE ;
        (* connInfoVersion should always be set to NWCC_INFO_VERSION 
         or NWCC_INFO_VERSION_n *)
        connInfoVersion  :   nuint ;
        connInfoBuffer  :   pNWCCConnInfo 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCGetAllConnRefInfo (
        connRef  :   nuint32 ;
        (* connInfoVersion should always be set to NWCC_INFO_VERSION 
         or NWCC_INFO_VERSION_n *)
        connInfoVersion  :   nuint ;
        connInfoBuffer  :   pNWCCConnInfo 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCScanConnInfo (
        scanIterator  :   pnuint32 ;
        scanInfoLevel  :   nuint ;
        scanConnInfo  :   nptr ;
        scanFlags  :   nuint ;
        (* connInfoVersion should always be set to NWCC_INFO_VERSION 
         or NWCC_INFO_VERSION_n *)
        connInfoVersion  :   nuint ;
        returnInfoLevel  :   nuint ;
        returnConnInfo  :   nptr ;
        connReference  :   pnuint32 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCGetConnAddressLength (
        connHandle  :   NWCONN_HANDLE ;
        addrLen  :   pnuint32 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCGetConnRefAddressLength (
        connRef  :   nuint32 ;
        addrLen  :   pnuint32 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCGetConnAddress (
        connHandle  :   NWCONN_HANDLE ;
        bufferLen  :   nuint32 ;
        tranAddr  :   pNWCCTranAddr 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCGetConnRefAddress (
        connRef  :   nuint32 ;
        bufferLen  :   nuint32 ;
        tranAddr  :   pNWCCTranAddr 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCOpenConnByPref (
        tranType  :   nuint ;
        openState  :   nuint ;
        reserved  :   nuint ;
        pConnHandle  :   pNWCONN_HANDLE 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCQueryFeature (
        featureCode  :   nuint 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCGetNumConns (
        maxConns  :   pnuint ;
        publicConns  :   pnuint ;
        myPrivateConns  :   pnuint 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCSetCurrentConnection (
        connHandle  :   NWCONN_HANDLE 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCGetSecurityFlags (
        enabSecurityFlags  :   pnuint32 ;
        prefSecurityFlags  :   pnuint32 ;
        reqSecurityFlags  :   pnuint32 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCSetSecurityFlags (
        prefSecurityFlags  :   nuint32 ;
        reqSecurityFlags  :   nuint32 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCRenegotiateSecurityLevel (
        connHandle  :   NWCONN_HANDLE ;
        securityFlags  :   nuint32 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCCResetRequester (
        keepConnRef  :   pnuint32 ;
        connFlags  :   nuint ;
        firstLocalAlias  :   pnstr 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

