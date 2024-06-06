(******************************************************************************

  %name: nwqms.h %
  %version: 4 %
  %date_modified: Wed Dec 18 12:09:04 1996 %
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


{$IFNDEF  NWQMS_H }
    {$DEFINE NWQMS_H}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$I npackon.inc}
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    {$DEFINE QF_AUTO_START}
    Const QF_AUTO_START = $08;
    {$DEFINE QF_ENTRY_RESTART}
    Const QF_ENTRY_RESTART = $10;
    {$DEFINE QF_ENTRY_OPEN}
    Const QF_ENTRY_OPEN = $20;
    {$DEFINE QF_USER_HOLD}
    Const QF_USER_HOLD = $40;
    {$DEFINE QF_OPERATOR_HOLD}
    Const QF_OPERATOR_HOLD = $80;
    {$DEFINE QS_CANT_ADD_JOBS}
    Const QS_CANT_ADD_JOBS = $01;
    {$DEFINE QS_SERVERS_CANT_ATTACH}
    Const QS_SERVERS_CANT_ATTACH = $02;
    {$DEFINE QS_CANT_SERVICE_JOBS}
    Const QS_CANT_SERVICE_JOBS = $04;
    (*
This struct is taken from NLM platform in the nwqueue.h file.  This
structure is the format for a print queue only.  Other queue types
might have different structures.  Used with the clientRecordArea field
in some of the structures listed below.
*)
    Type
        QueuePrintJobStruct = Record
            versionNumber  :   nuint8 ;
            tabSize  :   nuint8 ;
            numberOfCopies  :   nuint16 ;
            printControlFlags  :   nuint16 ;
            maxLinesPerPage  :   nuint16 ;
            maxCharsPerLine  :   nuint16 ;
            formName  :  Array[0..12] Of  nuint8 ;
            reserve  :  Array[0..8] Of  nuint8 ;
            bannerNameField  :  Array[0..12] Of  nuint8 ;
            bannerFileField  :  Array[0..12] Of  nuint8 ;
            bannerFileName  :  Array[0..13] Of  nuint8 ;
            directoryPath  :  Array[0..79] Of  nuint8 ;
        End;
    Type
        QueueJobStruct = Record
            clientStation  :   nuint8 ;
            clientTask  :   nuint8 ;
            clientID  :   nuint32 ;
            targetServerID  :   nuint32 ;
            targetExecutionTime  :  Array[0..5] Of  nuint8 ;
            jobEntryTime  :  Array[0..5] Of  nuint8 ;
            jobNumber  :   nuint16 ;
            jobType  :   nuint16 ;
            jobPosition  :   nuint8 ;
            jobControlFlags  :   nuint8 ;
            jobFileName  :  Array[0..13] Of  nuint8 ;
            jobFileHandle  :  Array[0..5] Of  nuint8 ;
            servicingServerStation  :   nuint8 ;
            servicingServerTask  :   nuint8 ;
            servicingServerID  :   nuint32 ;
            jobDescription  :  Array[0..49] Of  nuint8 ;
            clientRecordArea  :  Array[0..151] Of  nuint8 ;
        End;
    Type
        ReplyJobStruct = Record
            clientStation  :   nuint8 ;
            clientTask  :   nuint8 ;
            clientID  :   nuint32 ;
            targetServerID  :   nuint32 ;
            targetExecutionTime  :  Array[0..5] Of  nuint8 ;
            jobEntryTime  :  Array[0..5] Of  nuint8 ;
            jobNumber  :   nuint16 ;
            jobType  :   nuint16 ;
            jobPosition  :   nuint8 ;
            jobControlFlags  :   nuint8 ;
            jobFileName  :  Array[0..13] Of  nuint8 ;
            jobFileHandle  :  Array[0..5] Of  nuint8 ;
            servicingServerStation  :   nuint8 ;
            servicingServerTask  :   nuint8 ;
            servicingServerID  :   nuint32 ;
        End;
    Type
        NWQueueJobStruct = Record
            clientStation  :   nuint32 ;
            clientTask  :   nuint32 ;
            clientID  :   nuint32 ;
            targetServerID  :   nuint32 ;
            targetExecutionTime  :  Array[0..5] Of  nuint8 ;
            jobEntryTime  :  Array[0..5] Of  nuint8 ;
            jobNumber  :   nuint32 ;
            jobType  :   nuint16 ;
            jobPosition  :   nuint16 ;
            jobControlFlags  :   nuint16 ;
            jobFileName  :  Array[0..13] Of  nuint8 ;
            jobFileHandle  :   nuint32 ;
            servicingServerStation  :   nuint32 ;
            servicingServerTask  :   nuint32 ;
            servicingServerID  :   nuint32 ;
            jobDescription  :  Array[0..49] Of  nuint8 ;
            clientRecordArea  :  Array[0..151] Of  nuint8 ;
        End;
    Type
        NWReplyJobStruct = Record
            clientStation  :   nuint32 ;
            clientTask  :   nuint32 ;
            clientID  :   nuint32 ;
            targetServerID  :   nuint32 ;
            targetExecutionTime  :  Array[0..5] Of  nuint8 ;
            jobEntryTime  :  Array[0..5] Of  nuint8 ;
            jobNumber  :   nuint32 ;
            jobType  :   nuint16 ;
            jobPosition  :   nuint16 ;
            jobControlFlags  :   nuint16 ;
            jobFileName  :  Array[0..13] Of  nuint8 ;
            jobFileHandle  :   nuint32 ;
            servicingServerStation  :   nuint32 ;
            servicingServerTask  :   nuint32 ;
            servicingServerID  :   nuint32 ;
        End;
    Type
        QueueJobListReply = Record
            totalQueueJobs  :   nuint32 ;
            replyQueueJobNumbers  :   nuint32 ;
            jobNumberList  :  Array[0..249] Of  nuint32 ;
        End;
    Function NWCreateQueueFile (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        Var job  : QueueJobStruct;
        Var fileHandle  : NWFILE_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCreateQueueFile2 (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        Var job  : NWQueueJobStruct;
        Var fileHandle  : NWFILE_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCloseFileAndStartQueueJob (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        jobNumber  :   nuint16 ;
        fileHandle  :   NWFILE_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCloseFileAndStartQueueJob2 (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        jobNumber  :   nuint32 ;
        fileHandle  :   NWFILE_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCloseFileAndAbortQueueJob (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        jobNumber  :   nuint16 ;
        fileHandle  :   NWFILE_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCloseFileAndAbortQueueJob2 (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        jobNumber  :   nuint32 ;
        fileHandle  :   NWFILE_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWRemoveJobFromQueue (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        jobNumber  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWRemoveJobFromQueue2 (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        jobNumber  :   nuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetQueueJobList (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        jobCount  :   pnuint16 ;
        jobList  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetQueueJobList2 (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        queueStartPos  :   nuint32 ;
        Var job  : QueueJobListReply
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWReadQueueJobEntry (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        jobNumber  :   nuint16 ;
        Var job  : QueueJobStruct
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWReadQueueJobEntry2 (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        jobNumber  :   nuint32 ;
        Var job  : NWQueueJobStruct
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetQueueJobFileSize (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        jobNumber  :   nuint16 ;
        fileSize  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetQueueJobFileSize2 (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        jobNumber  :   nuint32 ;
        fileSize  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWChangeQueueJobEntry (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        Var job  : QueueJobStruct
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWChangeQueueJobEntry2 (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        Var job  : NWQueueJobStruct
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWChangeQueueJobPosition (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        jobNumber  :   nuint16 ;
        newJobPos  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWChangeQueueJobPosition2 (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        jobNumber  :   nuint32 ;
        newJobPos  :   nuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWServiceQueueJob (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        targetJobType  :   nuint16 ;
        Var job  : QueueJobStruct;
        Var fileHandle  : NWFILE_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWServiceQueueJob2 (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        targetJobType  :   nuint16 ;
        Var job  : NWQueueJobStruct;
        Var fileHandle  : NWFILE_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAbortServicingQueueJob (
        conn  :   NWCONN_HANDLE ;
        QueueID  :   nuint32 ;
        JobNumber  :   nuint16 ;
        fileHandle  :   NWFILE_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAbortServicingQueueJob2 (
        conn  :   NWCONN_HANDLE ;
        QueueID  :   nuint32 ;
        JobNumber  :   nuint32 ;
        fileHandle  :   NWFILE_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWChangeToClientRights (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        jobNumber  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWChangeToClientRights2 (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        jobNumber  :   nuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWFinishServicingQueueJob (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        jobNumber  :   nuint16 ;
        fileHandle  :   NWFILE_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWFinishServicingQueueJob2 (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        jobNumber  :   nuint32 ;
        fileHandle  :   NWFILE_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetPrinterQueueID (
        conn  :   NWCONN_HANDLE ;
        printerNum  :   nuint16 ;
        queueID  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCreateQueue (
        conn  :   NWCONN_HANDLE ;
        queueName  :   pnstr8 ;
        queueType  :   nuint16 ;
        dirPath  :   nuint8 ;
        path  :   pnstr8 ;
        queueID  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDestroyQueue (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWReadQueueCurrentStatus (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        queueStatus  :   pnuint8 ;
        numberOfJobs  :   pnuint16 ;
        numberOfServers  :   pnuint16 ;
        serverIDlist  :   pnuint32 ;
        serverConnList  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWReadQueueCurrentStatus2 (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        queueStatus  :   pnuint32 ;
        numberOfJobs  :   pnuint32 ;
        numberOfServers  :   pnuint32 ;
        serverIDlist  :   pnuint32 ;
        serverConnList  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSetQueueCurrentStatus (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        queueStatus  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSetQueueCurrentStatus2 (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        queueStatus  :   nuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWReadQueueServerCurrentStatus (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        serverID  :   nuint32 ;
        serverConn  :   nuint16 ;
        statusRec  :   nptr 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWReadQueueServerCurrentStatus2 (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        serverID  :   nuint32 ;
        serverConn  :   nuint32 ;
        statusRec  :   nptr 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAttachQueueServerToQueue (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDetachQueueServerFromQueue (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWRestoreQueueServerRights (
        conn  :   NWCONN_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSetQueueServerCurrentStatus (
        conn  :   NWCONN_HANDLE ;
        queueID  :   nuint32 ;
        statusRec  :   nptr 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

