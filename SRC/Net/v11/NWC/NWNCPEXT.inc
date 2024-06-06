(******************************************************************************

  %name: nwncpext.h %
  %version: 5 %
  %date_modified: Fri May  9 14:58:27 1997 %
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


{$IFNDEF  NWNCPEXT_H }
    {$DEFINE NWNCPEXT_H}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$IFNDEF  NWMISC_H }
        {$I nwmisc.inc}
    {$ENDIF}
    {$I npackon.inc}
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    {$DEFINE BEGIN_SCAN_NCP_EXTENSIONS}
    Const BEGIN_SCAN_NCP_EXTENSIONS = $FFFFFFFF;
    {$DEFINE NW_NCPX_BEGIN_SCAN}
    Const NW_NCPX_BEGIN_SCAN = $FFFFFFFF;
    {$DEFINE MAX_NCP_EXTENSION_NAME_BYTES}
    Const MAX_NCP_EXTENSION_NAME_BYTES = 33;
    {$IFDEF  N_PLAT_NLM }
        Type NWGetNCPExtensionInfo = NWGetNCPExtensionInfo2;
        Type NWScanNCPExtensions = NWScanNCPExtensions2;
        (* TC extern C *)
        (* TC  (  *)
        (* TC  nptr queryData  *)
        (* TC  );  *)
        (* Not implemented Function NWRegisterNCPExtension (
            NCPExtensionName  :   nstr8 ;
            (* TC nuint8 (* NCPExtensionHandler ) ( ;
            Var NCPExtensionClient  : NCPExtensionClient;
            requestData  :   nptr ;
            requestDataLen  :   nuint32 ;
            replyData  :   nptr ;
            replyDataLen  :   pnuint32 
        ) : nint;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
        Type
            NCPExtensionClient  =   NCPExtensionClient ;
        NCPExtensionClient = Record
            connection  :   nuint32 ;
            task  :   nuint32 ;
        End;
        (* Not implemented Function NWRegisterNCPExtensionByID (
            NCPExtensionID  :   nuint32 ;
            NCPExtensionName  :   nstr8 ;
            (* TC nuint8 (* NCPExtensionHandler ) ( ;
            Var NCPExtensionClient  : NCPExtensionClient;
            requestData  :   nptr ;
            requestDataLen  :   nuint32 ;
            replyData  :   nptr ;
            replyDataLen  :   pnuint32 
        ) : nint;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
    {$ENDIF}
    Function NWGetNCPExtensionInfo (
        conn  :   NWCONN_HANDLE ;
        NCPExtensionID  :   nuint32 ;
        NCPExtensionName  :   pnstr8 ;
        majorVersion  :   pnuint8 ;
        minorVersion  :   pnuint8 ;
        revision  :   pnuint8 ;
        queryData  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWNCPExtensionRequest (
        conn  :   NWCONN_HANDLE ;
        NCPExtensionID  :   nuint32 ;
        requestData  :   nptr ;
        requestDataLen  :   nuint16 ;
        replyData  :   nptr ;
        replyDataLen  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWFragNCPExtensionRequest (
        conn  :   NWCONN_HANDLE ;
        NCPExtensionID  :   nuint32 ;
        reqFragCount  :   nuint16 ;
        Var reqFragList  : NW_FRAGMENT;
        replyFragCount  :   nuint16 ;
        Var replyFragList  : NW_FRAGMENT
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWScanNCPExtensions (
        conn  :   NWCONN_HANDLE ;
        NCPExtensionID  :   pnuint32 ;
        NCPExtensionName  :   pnstr8 ;
        majorVersion  :   pnuint8 ;
        minorVersion  :   pnuint8 ;
        revision  :   pnuint8 ;
        queryData  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetNCPExtensionInfoByName (
        conn  :   NWCONN_HANDLE ;
        NCPExtensionName  :   pnstr8 ;
        NCPExtensionID  :   pnuint32 ;
        majorVersion  :   pnuint8 ;
        minorVersion  :   pnuint8 ;
        revision  :   pnuint8 ;
        queryData  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetNCPExtensionsList (
        conn  :   NWCONN_HANDLE ;
        startNCPExtensionID  :   pnuint32 ;
        itemsInList  :   pnuint16 ;
        NCPExtensionIDList  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetNumberNCPExtensions (
        conn  :   NWCONN_HANDLE ;
        numNCPExtensions  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

