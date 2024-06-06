(******************************************************************************

  %name: nwacct.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:05:07 1996 %
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


{$IFNDEF  NWACCT_H }
    {$DEFINE NWACCT_H}
    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$I npackon.inc}
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    Type
        HOLDS_INFO = Record
            objectID  :   nuint32 ;
            amount  :   nint32 ;
        End;
    Type
        HOLDS_STATUS = Record
            holdsCount  :   nuint16 ;
            holds  :  Array[0..15] Of  HOLDS_INFO ;
        End;
    Function NWGetAccountStatus (
        conn  :   NWCONN_HANDLE ;
        objType  :   nuint16 ;
        objName  :   pnstr8 ;
        balance  :   pnint32 ;
        limit  :   pnint32 ;
        Var holds  : HOLDS_STATUS
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWQueryAccountingInstalled (
        conn  :   NWCONN_HANDLE ;
        installed  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSubmitAccountCharge (
        conn  :   NWCONN_HANDLE ;
        objType  :   nuint16 ;
        objName  :   pnstr8 ;
        serviceType  :   nuint16 ;
        chargeAmt  :   nint32 ;
        holdCancelAmt  :   nint32 ;
        noteType  :   nuint16 ;
        note  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSubmitAccountHold (
        conn  :   NWCONN_HANDLE ;
        objType  :   nuint16 ;
        objName  :   pnstr8 ;
        holdAmt  :   nint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSubmitAccountNote (
        conn  :   NWCONN_HANDLE ;
        objType  :   nuint16 ;
        objName  :   pnstr8 ;
        serviceType  :   nuint16 ;
        noteType  :   nuint16 ;
        note  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

