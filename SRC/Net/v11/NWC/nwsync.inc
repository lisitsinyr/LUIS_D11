(******************************************************************************

  %name: nwsync.h %
  %version: 4 %
  %date_modified: Fri Oct  3 17:59:28 1997 %
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


{$IFNDEF  NWSYNC_H }
    {$DEFINE NWSYNC_H}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$I npackon.inc}
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    Type
        LOGICAL_LOCK = Record
            connNumber  :   nuint16 ;
            taskNumber  :   nuint16 ;
            lockStatus  :   nuint8 ;
        End;
    Type
        LOGICAL_LOCKS = Record
            useCount  :   nuint16 ;
            shareableLockCount  :   nuint16 ;
            locked  :   nuint8 ;
            nextRequest  :   nuint16 ;
            numRecords  :   nuint16 ;
            logicalLock  :  Array[0..127] Of  LOGICAL_LOCK ;
            curRecord  :   nuint16 ;
        End;
    Type
        CONN_LOGICAL_LOCK = Record
            taskNumber  :   nuint16 ;
            lockStatus  :   nuint8 ;
            logicalName  :  Array[0..127] Of  nstr8 ;
        End;
    Type
        CONN_LOGICAL_LOCKS = Record
            nextRequest  :   nuint16 ;
            numRecords  :   nuint16 ;
            records  :  Array[0..507] Of  nuint8 ;
            curOffset  :   nuint16 ;
            curRecord  :   nuint16 ;
        End;
    Type
        PHYSICAL_LOCK = Record
            loggedCount  :   nuint16 ;
            shareableLockCount  :   nuint16 ;
            recordStart  :   nuint32 ;
            recordEnd  :   nuint32 ;
            connNumber  :   nuint16 ;
            taskNumber  :   nuint16 ;
            lockType  :   nuint8 ;
            {$IFDEF N_ARCH_32}
            filler : nuint8;
            filler2 : nuint16;
            {$ENDIF}
        End;
    Type
        PHYSICAL_LOCKS = Record
            nextRequest  :   nuint16 ;
            numRecords  :   nuint16 ;
            locks  :  Array[0..31] Of  PHYSICAL_LOCK ;
            curRecord  :   nuint16 ;
            reserved  :  Array[0..7] Of  nuint8 ;
        End;
    Type
        CONN_PHYSICAL_LOCK = Record
            taskNumber  :   nuint16 ;
            lockType  :   nuint8 ;
            recordStart  :   nuint32 ;
            recordEnd  :   nuint32 ;
        End;
    Type
        CONN_PHYSICAL_LOCKS = Record
            nextRequest  :   nuint16 ;
            numRecords  :   nuint16 ;
            locks  :  Array[0..50] Of  CONN_PHYSICAL_LOCK ;
            curRecord  :   nuint16 ;
            reserved  :  Array[0..21] Of  nuint8 ;
        End;
    Type
        SEMAPHORE = Record
            connNumber  :   nuint16 ;
            taskNumber  :   nuint16 ;
        End;
    Type
        SEMAPHORES = Record
            nextRequest  :   nuint16 ;
            openCount  :   nuint16 ;
            semaphoreValue  :   nuint16 ;
            semaphoreCount  :   nuint16 ;
            semaphores  :  Array[0..169] Of  SEMAPHORE ;
            curRecord  :   nuint16 ;
        End;
    Type
        CONN_SEMAPHORE = Record
            openCount  :   nuint16 ;
            semaphoreValue  :   nuint16 ;
            taskNumber  :   nuint16 ;
            semaphoreName  :  Array[0..127] Of  nstr8 ;
        End;
    Type
        CONN_SEMAPHORES = Record
            nextRequest  :   nuint16 ;
            numRecords  :   nuint16 ;
            records  :  Array[0..507] Of  nuint8 ;
            curOffset  :   nuint16 ;
            curRecord  :   nuint16 ;
        End;
    Function NWScanPhysicalLocksByFile (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        dataStream  :   nuint8 ;
        iterHandle  :   pnint16 ;
        Var lock  : PHYSICAL_LOCK;
        Var locks  : PHYSICAL_LOCKS
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWScanLogicalLocksByConn (
        conn  :   NWCONN_HANDLE ;
        connNum  :   nuint16 ;
        iterHandle  :   pnint16 ;
        Var logicalLock  : CONN_LOGICAL_LOCK;
        Var logicalLocks  : CONN_LOGICAL_LOCKS
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWScanPhysicalLocksByConnFile (
        conn  :   NWCONN_HANDLE ;
        connNum  :   nuint16 ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        dataStream  :   nuint8 ;
        iterHandle  :   pnint16 ;
        Var lock  : CONN_PHYSICAL_LOCK;
        Var locks  : CONN_PHYSICAL_LOCKS
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWScanLogicalLocksByName (
        conn  :   NWCONN_HANDLE ;
        logicalName  :   pnstr8 ;
        iterHandle  :   pnint16 ;
        Var logicalLock  : LOGICAL_LOCK;
        Var logicalLocks  : LOGICAL_LOCKS
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWScanSemaphoresByConn (
        conn  :   NWCONN_HANDLE ;
        connNum  :   nuint16 ;
        iterHandle  :   pnint16 ;
        Var semaphore  : CONN_SEMAPHORE;
        Var semaphores  : CONN_SEMAPHORES
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWScanSemaphoresByName (
        conn  :   NWCONN_HANDLE ;
        semName  :   pnstr8 ;
        iterHandle  :   pnint16 ;
        Var semaphore  : SEMAPHORE;
        Var semaphores  : SEMAPHORES
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSignalSemaphore (
        conn  :   NWCONN_HANDLE ;
        semHandle  :   nuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCloseSemaphore (
        conn  :   NWCONN_HANDLE ;
        semHandle  :   nuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWOpenSemaphore (
        conn  :   NWCONN_HANDLE ;
        semName  :   pnstr8 ;
        initSemHandle  :   nint16 ;
        semHandle  :   pnuint32 ;
        semOpenCount  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWExamineSemaphore (
        conn  :   NWCONN_HANDLE ;
        semHandle  :   nuint32 ;
        semValue  :   pnint16 ;
        semOpenCount  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWWaitOnSemaphore (
        conn  :   NWCONN_HANDLE ;
        semHandle  :   nuint32 ;
        timeOutValue  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

