(******************************************************************************

  %name: nwsm.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:09:16 1996 %
  $Copyright:

  Copyright (c) 1989-1996 Novell, Inc.  All Rights Reserved.

  THIS WORK IS  SUBJECT  TO  U.S.  AND  INTERNATIONAL  COPYRIGHT  LAWS  AND
  TREATIES.   NO  PART  OF  THIS  WORK MAY BE  USED,  PRACTICED,  PERFORMED
  COPIED, DISTRIBUTED, REVISED, MODIFIED, TRANSLATED,  ABRIDGED, CONDENSED,
  EXPANDED,  COLLECTED,  COMPILED,  LINKED,  RECAST, TRANSFORMED OR ADAPTED
  WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC. ANY USE OR EXPLOITATION
  OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT THE PERPETRATOR TO
  CRIMINAL AND CIVIL LIABILITY.$

 *****************************************************************************)

{$IFNDEF  NWSM_H }
    {$DEFINE NWSM_H}
    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
    {$IFNDEF  NWAPIDEF_H }
        {$I nwapidef.inc}
    {$ENDIF}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$IFNDEF  NWNAMSPC_H }
        {$I nwnamspc.inc}
    {$ENDIF}
    {$I npackon.inc}
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    Function NWSMLoadNLM (
        connHandle  :   NWCONN_HANDLE ;
        loadCommand  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSMUnloadNLM (
        connHandle  :   NWCONN_HANDLE ;
        NLMName  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSMMountVolume (
        connHandle  :   NWCONN_HANDLE ;
        volumeName  :   pnstr8 ;
        volumeNumber  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSMDismountVolumeByNumber (
        connHandle  :   NWCONN_HANDLE ;
        volumeNumber  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSMDismountVolumeByName (
        connHandle  :   NWCONN_HANDLE ;
        volumeName  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSMAddNSToVolume (
        connHandle  :   NWCONN_HANDLE ;
        volNumber  :   nuint16 ;
        namspc  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSMSetDynamicCmdStrValue (
        connHandle  :   NWCONN_HANDLE ;
        setCommandName  :   pnstr8 ;
        cmdValue  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSMSetDynamicCmdIntValue (
        connHandle  :   NWCONN_HANDLE ;
        setCommandName  :   pnstr8 ;
        cmdValue  :   nuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSMExecuteNCFFile (
        connHandle  :   NWCONN_HANDLE ;
        NCFFileName  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$I npackoff.inc}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
{$ENDIF}

