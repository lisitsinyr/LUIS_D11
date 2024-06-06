(******************************************************************************

  %name: nwdsconn.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:07:08 1996 %
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

{$IFNDEF  NWDSCONN_H }
    {$DEFINE NWDSCONN_H}
    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$IFNDEF  NWDSDC_H }
        {$I nwdsdc.inc}
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    Function NWDSOpenConnToNDSServer (
        context  :   NWDSContextHandle ;
        serverName  :   pnstr8 ;
        connHandle  :   pNWCONN_HANDLE 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetDefNameContext (
        context  :   NWDSContextHandle ;
        nameContextLen  :   nuint ;
        nameContext  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSSetDefNameContext (
        context  :   NWDSContextHandle ;
        nameContextLen  :   nuint ;
        nameContext  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetMonitoredConnRef (
        context  :   NWDSContextHandle ;
        connRef  :   pnuint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSOpenMonitoredConn (
        context  :   NWDSContextHandle ;
        connHandle  :   pNWCONN_HANDLE 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSScanConnsForTrees (
        context  :   NWDSContextHandle ;
        numOfPtrs  :   nuint ;
        numOfTrees  :   pnuint ;
        treeBufPtrs  :   ppnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSScanForAvailableTrees (
        context  :   NWDSContextHandle ;
        connHandle  :   NWCONN_HANDLE ;
        scanFilter  :   pnstr ;
        scanIndex  :   pnint32 ;
        treeName  :   pnstr 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSReturnBlockOfAvailableTrees (
        context  :   NWDSContextHandle ;
        connHandle  :   NWCONN_HANDLE ;
        scanFilter  :   pnstr ;
        lastBlocksString  :   pnstr ;
        endBoundString  :   pnstr ;
        maxTreeNames  :   nuint32 ;
        arrayOfNames  :   ppnstr ;
        numberOfTrees  :   pnuint32 ;
        totalUniqueTrees  :   pnuint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSCanDSAuthenticate (
        context  :   NWDSContextHandle 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
{$ENDIF}


