(******************************************************************************

  %name: nwredir.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:09:08 1996 %
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

{$IFNDEF  NWREDIR_H }
    {$DEFINE NWREDIR_H}
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
    {$IFNDEF  NWOS2 }
        {$IFNDEF REDIR_SIGNATURE}
        {$DEFINE REDIR_SIGNATURE}
        Const REDIR_SIGNATURE = 'WN';
        Type
            tNW_REDIR_ENTRY = Record
                index  :   nuint16 ;
                deviceStatus  :   nuint8 ;
                deviceType  :   nuint8 ;
                storedValue  :   nuint16 ;
                localName  :  Array[0..15] Of  nstr8 ;
                networkName  :  Array[0..127] Of  nstr8 ;
            End;
            NW_REDIR_ENTRY = tNW_REDIR_ENTRY;
        {$ENDIF}
        (* obsolete
NWCCODE N_API NWRedirLogin
(
   pnstr8 pbstrServerName,
   pnstr8 pbstrUserName,
   pnstr8 pbstrPassword
);
*)
        (* Not implemented Function NWRedirLogout (
            pbstrServerName  :   pnstr8 
        ) : NWCCODE;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
        (* Not implemented Function NWRedirectDevice (
            pbstrUNCPath  :   pnstr8 ;
            buDevice  :   nuint8 
        ) : NWCCODE;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
        (* Not implemented Function NWCancelRedirection (
            buDevice  :   nuint8 
        ) : NWCCODE;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
        (* Not implemented Function NWGetRedirectionEntry (
            Var entry  : NW_REDIR_ENTRY
        ) : NWCCODE;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
    {$ELSE} {$IFNDEF  WIN32 }
        {$IFNDEF REDIR_SIGNATURE}
        {$DEFINE REDIR_SIGNATURE}
        Const REDIR_SIGNATURE = 'WN';
        Type
            tNW_REDIR_ENTRY = Record
                index  :   nuint16 ;
                deviceStatus  :   nuint8 ;
                deviceType  :   nuint8 ;
                storedValue  :   nuint16 ;
                localName  :  Array[0..15] Of  nstr8 ;
                networkName  :  Array[0..127] Of  nstr8 ;
            End;
            NW_REDIR_ENTRY = tNW_REDIR_ENTRY;
        {$ENDIF}
        (* obsolete
NWCCODE N_API NWRedirLogin
(
   pnstr8 pbstrServerName,
   pnstr8 pbstrUserName,
   pnstr8 pbstrPassword
);
*)
        (* Not implemented Function NWRedirLogout (
            pbstrServerName  :   pnstr8 
        ) : NWCCODE;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
        (* Not implemented Function NWRedirectDevice (
            pbstrUNCPath  :   pnstr8 ;
            buDevice  :   nuint8 
        ) : NWCCODE;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
        (* Not implemented Function NWCancelRedirection (
            buDevice  :   nuint8 
        ) : NWCCODE;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
        (* Not implemented Function NWGetRedirectionEntry (
            Var entry  : NW_REDIR_ENTRY
        ) : NWCCODE;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
    {$ENDIF}
    {$ENDIF}
    Function NWParseUNCPath (
        pbstrUNCPath  :   pnstr8 ;
        Var conn  : NWCONN_HANDLE;
        pbstrServerName  :   pnstr8 ;
        pbstrVolName  :   pnstr8 ;
        pbstrPath  :   pnstr8 ;
        pbstrNWPath  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWParseUNCPathConnRef (
        pbstrUNCPath  :   pnstr8 ;
        pluConnRef  :   pnuint32 ;
        pbstrServerName  :   pnstr8 ;
        pbstrVolName  :   pnstr8 ;
        pbstrPath  :   pnstr8 ;
        pbstrNWPath  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

