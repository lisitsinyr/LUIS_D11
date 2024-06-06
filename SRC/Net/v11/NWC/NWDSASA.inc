(******************************************************************************

  %name: nwdsasa.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:06:48 1996 %
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

{$IFNDEF  NWDSASA_H }
    {$DEFINE NWDSASA_H}
    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$IFNDEF  NWDSDC_H }
        {$I nwdsdc.inc}
    {$ENDIF}
    {$I npackon.inc}
    {$DEFINE SESSION_KEY_SIZE}
    Const SESSION_KEY_SIZE = 16;
    Type NWDS_Session_Key_T  =  Array[0..SESSION_KEY_SIZE-1] Of  nuint8 ;
    Type pNWDS_Session_Key_T  =  ^NWDS_Session_Key_T;
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    Function NWDSAuthenticate (
        conn  :   NWCONN_HANDLE ;
        optionsFlag  :   nflag32 ;
        sessionKey  :   pNWDS_Session_Key_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSAuthenticateConn (
        context  :   NWDSContextHandle ;
        connHandle  :   NWCONN_HANDLE 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSChangeObjectPassword (
        context  :   NWDSContextHandle ;
        optionsFlag  :   nflag32 ;
        objectName  :   pnstr8 ;
        oldPassword  :   pnstr8 ;
        newPassword  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGenerateObjectKeyPair (
        contextHandle  :   NWDSContextHandle ;
        objectName  :   pnstr8 ;
        objectPassword  :   pnstr8 ;
        optionsFlag  :   nflag32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSLogin (
        context  :   NWDSContextHandle ;
        optionsFlag  :   nflag32 ;
        objectName  :   pnstr8 ;
        password  :   pnstr8 ;
        validityPeriod  :   nuint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSLogout (
        context  :   NWDSContextHandle 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSVerifyObjectPassword (
        context  :   NWDSContextHandle ;
        optionsFlag  :   nflag32 ;
        objectName  :   pnstr8 ;
        password  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

