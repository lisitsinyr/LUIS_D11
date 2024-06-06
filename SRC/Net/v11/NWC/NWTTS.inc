(******************************************************************************

  %name: nwtts.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:07:23 1996 %
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


{$IFNDEF  NWTTS_H }
    {$DEFINE NWTTS_H}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$I npackon.inc}
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    Type
        TTS_STATS = Record
            systemElapsedTime  :   nuint32 ;
            TTS_Supported  :   nuint8 ;
            TTS_Enabled  :   nuint8 ;
            TTS_VolumeNumber  :   nuint16 ;
            TTS_MaxOpenTransactions  :   nuint16 ;
            TTS_MaxTransactionsOpened  :   nuint16 ;
            TTS_CurrTransactionsOpen  :   nuint16 ;
            TTS_TotalTransactions  :   nuint32 ;
            TTS_TotalWrites  :   nuint32 ;
            TTS_TotalBackouts  :   nuint32 ;
            TTS_UnfilledBackouts  :   nuint16 ;
            TTS_DiskBlocksInUse  :   nuint16 ;
            TTS_FATAllocations  :   nuint32 ;
            TTS_FileSizeChanges  :   nuint32 ;
            TTS_FilesTruncated  :   nuint32 ;
            numberOfTransactions  :   nuint8 ;
            connTask : Array[0..234] of Record
                connNumber  :   nuint8 ;
                taskNumber  :   nuint8 ;
            End;
        End;
    Function NWTTSAbortTransaction (
        conn  :   NWCONN_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWTTSBeginTransaction (
        conn  :   NWCONN_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWTTSIsAvailable (
        conn  :   NWCONN_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWTTSGetControlFlags (
        conn  :   NWCONN_HANDLE ;
        controlFlags  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWTTSSetControlFlags (
        conn  :   NWCONN_HANDLE ;
        controlFlags  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWTTSEndTransaction (
        conn  :   NWCONN_HANDLE ;
        transactionNum  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWTTSTransactionStatus (
        conn  :   NWCONN_HANDLE ;
        transactionNum  :   nuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWTTSGetProcessThresholds (
        conn  :   NWCONN_HANDLE ;
        logicalLockLevel  :   pnuint8 ;
        physicalLockLevel  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWTTSSetProcessThresholds (
        conn  :   NWCONN_HANDLE ;
        logicalLockLevel  :   nuint8 ;
        physicalLockLevel  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWTTSGetConnectionThresholds (
        conn  :   NWCONN_HANDLE ;
        logicalLockLevel  :   pnuint8 ;
        physicalLockLevel  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWTTSSetConnectionThresholds (
        conn  :   NWCONN_HANDLE ;
        logicalLockLevel  :   nuint8 ;
        physicalLockLevel  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWEnableTTS (
        conn  :   NWCONN_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDisableTTS (
        conn  :   NWCONN_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetTTSStats (
        conn  :   NWCONN_HANDLE ;
        Var ttsStats  : TTS_STATS
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

