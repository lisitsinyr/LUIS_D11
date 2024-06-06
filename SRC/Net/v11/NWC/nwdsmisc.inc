(******************************************************************************

  %name: nwdsmisc.h %
  %version: 4 %
  %date_modified: Tue Nov 18 18:13:16 1997 %
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

{$IFNDEF  NWDSMISC_H }
    {$DEFINE NWDSMISC_H}
    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$IFNDEF  NWDSBUFT_H }
        {$I nwdsbuft.inc}
    {$ENDIF}
    {$IFNDEF  UNICODE_H }
        {$I unicode.inc}
    {$ENDIF}
    {$I npackon.inc}
    {$DEFINE DS_SYNTAX_NAMES}
    Const DS_SYNTAX_NAMES = 0;
    {$DEFINE DS_SYNTAX_DEFS}
    Const DS_SYNTAX_DEFS = 1;
    {$DEFINE DS_STRING}
    Const DS_STRING = $0001;
    {$DEFINE DS_SINGLE_VALUED}
    Const DS_SINGLE_VALUED = $0002;
    {$DEFINE DS_SUPPORTS_ORDER}
    Const DS_SUPPORTS_ORDER = $0004;
    {$DEFINE DS_SUPPORTS_EQUAL}
    Const DS_SUPPORTS_EQUAL = $0008;
    {$DEFINE DS_IGNORE_CASE}
    Const DS_IGNORE_CASE = $0010;
    {$DEFINE DS_IGNORE_SPACE}
    Const DS_IGNORE_SPACE = $0020;
    {$DEFINE DS_IGNORE_DASH}
    Const DS_IGNORE_DASH = $0040;
    {$DEFINE DS_ONLY_DIGITS}
    Const DS_ONLY_DIGITS = $0080;
    {$DEFINE DS_ONLY_PRINTABLE}
    Const DS_ONLY_PRINTABLE = $0100;
    {$DEFINE DS_SIZEABLE}
    Const DS_SIZEABLE = $0200;
    Type
        NDSStatsInfo_T = Record
            statsVersion  :   nuint32 ;
            noSuchEntry  :   nuint32 ;
            localEntry  :   nuint32 ;
            typeReferral  :   nuint32 ;
            aliasReferral  :   nuint32 ;
            requestCount  :   nuint32 ;
            requestDataSize  :   nuint32 ;
            replyDataSize  :   nuint32 ;
            resetTime  :   nuint32 ;
            transportReferral  :   nuint32 ;
            upReferral  :   nuint32 ;
            downReferral  :   nuint32 ;
        End;
        pNDSStatsInfo_T = ^NDSStatsInfo_T;
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    Function NWDSCloseIteration (
        context  :   NWDSContextHandle ;
        iterationHandle  :   nint32 ;
        operation  :   nuint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetSyntaxID (
        context  :   NWDSContextHandle ;
        attrName  :   pnstr8 ;
        syntaxID  :   pnuint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSReadSyntaxes (
        context  :   NWDSContextHandle ;
        infoType  :   nuint32 ;
        allSyntaxes  :   nbool8 ;
        syntaxNames  :   pBuf_T ;
        iterationHandle  :   pnint32 ;
        syntaxDefs  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSReadSyntaxDef (
        context  :   NWDSContextHandle ;
        syntaxID  :   nuint32 ;
        syntaxDef  :   pSyntax_Info_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSReplaceAttrNameAbbrev (
        context  :   NWDSContextHandle ;
        inStr  :   pnstr8 ;
        outStr  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetObjectHostServerAddress (
        context  :   NWDSContextHandle ;
        objectName  :   pnstr8 ;
        serverName  :   pnstr8 ;
        netAddresses  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Procedure NWGetNWNetVersion (
        Var majorVersion  : nuint8;
        Var minorVersion  : nuint8;
        Var revisionLevel  : nuint8;
        Var betaReleaseLevel  : nuint8
    );
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWIsDSServer (
        conn  :   NWCONN_HANDLE ;
        treeName  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetBinderyContext (
        context  :   NWDSContextHandle ;
        connHandle  :   NWCONN_HANDLE ;
        BinderyEmulationContext  :   pnuint8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSRepairTimeStamps (
        context  :   NWDSContextHandle ;
        partitionRoot  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetFileServerUTCTime (
        conn  :   NWCONN_HANDLE ;
        time  :   pnuint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetDSVerInfo (
        conn  :   NWCONN_HANDLE ;
        dsVersion  :   pnuint32 ;
        rootMostEntryDepth  :   pnuint32 ;
        sapName  :   pnstr8 ;
        flags  :   pnuint32 ;
        treeName  :   punicode 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetNDSInfo (
        context  :   NWDSContextHandle ;
        resultBuffer  :   pBuf_T ;
        requestedField  :   nflag32 ;
        data  :   nptr 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSReadNDSInfo (
        connHandle  :   NWCONN_HANDLE ;
        requestedFields  :   nflag32 ;
        resultBuffer  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSSyncReplicaToServer (
        context  :   NWDSContextHandle ;
        serverName  :   pnstr8 ;
        partitionRootName  :   pnstr8 ;
        destServerName  :   pnstr8 ;
        actionFlags  :   nuint32 ;
        delaySeconds  :   nuint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSReloadDS (
        context  :   NWDSContextHandle ;
        serverName  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWNetInit (
        reserved1  :   nptr ;
        reserved2  :   nptr 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWNetTerm (
        reserved  :   nptr 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* Not implemented Function NWDSGetNDSStatistics (
        context  :   NWDSContextHandle ;
        serverName  :   pnstr8 ;
        statsInfoLen  :   nuint ;
        statsInfo  :   pNDSStatsInfo_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWDSResetNDSStatistics (
        context  :   NWDSContextHandle ;
        serverName  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

