(*
//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
//บ (c) 1993 Novell, Inc.	All rights reserved.                              บ
//บ																								  บ
//บ THIS WORK IS SUBJECT TO U.S. AND INTERNATIONAL COPYRIGHT LAWS AND		  บ
//บ TREATIES.																					  บ
//บ																								  บ
//บ NO PART OF THIS WORK MAY BE USED, PRACTICED, PERFORMED, COPIED,			  บ
//บ DISTRIBUTED, REVISED, MODIFIED, TRANSLATED, ABRIDGED, CONDENSED,         บ
//บ EXPANDED, COLLECTED, COMPILED, LINKED, RECAST, TRANSFORMED OR ADAPTED	  บ
//บ WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC.                        บ
//บ																								  บ
//บ ANY USE OR EXPLOITATION OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT บ
//บ THE PERPETRATOR TO CRIMINAL AND CIVIL LIABILITY.								  บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Source module name: NWPS_PKT.H														  บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

{$IFNDEF NWPS_COM_INC}

{$I nwps_com.inc}
{$ENDIF}

{$IFNDEF NWPS_PKT_INC}

{$DEFINE NWPS_PKT_INC}
(**************************************************************************)

(************ Print Server Communication Packet Structures ****************)

(**************************************************************************)

(* These structures are organized in pairs for Request/Reply. They are	  *)

(* Also grouped logically by related operations to be performed			  *)

(**************************************************************************)

{$IFNDEF CMD_LOGIN_TO_PRINT_SERVER}

(* General Commands *)

{$DEFINE CMD_LOGIN_TO_PRINT_SERVER}
Const CMD_LOGIN_TO_PRINT_SERVER = $01;
{$DEFINE CMD_GET_PRINT_SERVER_INFO}
Const CMD_GET_PRINT_SERVER_INFO = $02;
{$DEFINE CMD_DOWN}
Const CMD_DOWN = $03;
{$DEFINE CMD_CANCEL_DOWN}
Const CMD_CANCEL_DOWN = $04;
{$DEFINE CMD_GET_PRINTER_STATUS}
Const CMD_GET_PRINTER_STATUS = $05;
{$DEFINE CMD_STOP_PRINTER}
Const CMD_STOP_PRINTER = $06;
{$DEFINE CMD_START_PRINTER}
Const CMD_START_PRINTER = $07;
{$DEFINE CMD_MOUNT_FORM}
Const CMD_MOUNT_FORM = $08;
{$DEFINE CMD_REWIND_PRINT_JOB}
Const CMD_REWIND_PRINT_JOB = $09;
{$DEFINE CMD_EJECT_PAGE}
Const CMD_EJECT_PAGE = $0A;
{$DEFINE CMD_MARK_PAGE}
Const CMD_MARK_PAGE = $0B;
{$DEFINE CMD_CHANGE_SERVICE_MODE}
Const CMD_CHANGE_SERVICE_MODE = $0C;
{$DEFINE CMD_GET_JOB_STATUS}
Const CMD_GET_JOB_STATUS = $0D;
{$DEFINE CMD_ABORT_JOB}
Const CMD_ABORT_JOB = $0E;
{$DEFINE CMD_SCAN_QUEUE_LIST}
Const CMD_SCAN_QUEUE_LIST = $0F;
{$DEFINE CMD_CHANGE_QUEUE_PRIORITY}
Const CMD_CHANGE_QUEUE_PRIORITY = $10;
{$DEFINE CMD_ADD_QUEUE}
Const CMD_ADD_QUEUE = $11;
{$DEFINE CMD_DELETE_QUEUE}
Const CMD_DELETE_QUEUE = $12;
{$DEFINE CMD_GET_PRINTERS_FOR_QUEUE}
Const CMD_GET_PRINTERS_FOR_QUEUE = $13;
{$DEFINE CMD_SCAN_NOTIFY_LIST}
Const CMD_SCAN_NOTIFY_LIST = $14;
{$DEFINE CMD_CHANGE_NOTIFY}
Const CMD_CHANGE_NOTIFY = $15;
{$DEFINE CMD_ADD_NOTIFY}
Const CMD_ADD_NOTIFY = $16;
{$DEFINE CMD_DELETE_NOTIFY}
Const CMD_DELETE_NOTIFY = $17;
{$DEFINE CMD_ATTACH_TO_FILE_SERVER}
Const CMD_ATTACH_TO_FILE_SERVER = $18;
{$DEFINE CMD_DETACH_FROM_FILE_SERVER}
Const CMD_DETACH_FROM_FILE_SERVER = $19;
{$DEFINE CMD_GET_ATTACHED_SERVERS}
Const CMD_GET_ATTACHED_SERVERS = $1A;

(* NPrinter commands *)

{$DEFINE CMD_GET_RPRINTER}
Const CMD_GET_RPRINTER = $80;
{$DEFINE CMD_CONNECT_RPRINTER}
Const CMD_CONNECT_RPRINTER = $81;
{$DEFINE CMD_SET_REMOTE_MODE}
Const CMD_SET_REMOTE_MODE = $82;
{$DEFINE CMD_SCAN_RPRINTER}
Const CMD_SCAN_RPRINTER = $84;

(* New PServer commands for version 4.0+ *)

{$DEFINE CMD_ADD_FORM}
Const CMD_ADD_FORM = $1D;
{$DEFINE CMD_DISMOUNT_FORM}
Const CMD_DISMOUNT_FORM = $1E;
{$DEFINE CMD_GET_EXT_PRINTER_STATUS}
Const CMD_GET_EXT_PRINTER_STATUS = $1F;

(* Unicode Directory Service commands (version 4.1) *)

{$DEFINE CMD_UDS_LOGIN_TO_PRINT_SERVER}
Const CMD_UDS_LOGIN_TO_PRINT_SERVER = $A1;
{$DEFINE CMD_UDS_SCAN_QUEUE_LIST}
Const CMD_UDS_SCAN_QUEUE_LIST = $AF;
{$DEFINE CMD_UDS_CHANGE_QUEUE_PRIORITY}
Const CMD_UDS_CHANGE_QUEUE_PRIORITY = $B0;
{$DEFINE CMD_UDS_ADD_QUEUE}
Const CMD_UDS_ADD_QUEUE = $B1;
{$DEFINE CMD_UDS_DELETE_QUEUE}
Const CMD_UDS_DELETE_QUEUE = $B2;
{$DEFINE CMD_UDS_GET_PRINTERS_FOR_QUEUE}
Const CMD_UDS_GET_PRINTERS_FOR_QUEUE = $B3;
{$DEFINE CMD_UDS_SCAN_NOTIFY_LIST}
Const CMD_UDS_SCAN_NOTIFY_LIST = $B4;
{$DEFINE CMD_UDS_CHANGE_NOTIFY}
Const CMD_UDS_CHANGE_NOTIFY = $B5;
{$DEFINE CMD_UDS_ADD_NOTIFY}
Const CMD_UDS_ADD_NOTIFY = $B6;
{$DEFINE CMD_UDS_DELETE_NOTIFY}
Const CMD_UDS_DELETE_NOTIFY = $B7;
{$DEFINE CMD_UDS_GET_JOB_ID}
Const CMD_UDS_GET_JOB_ID = $B8;

(* Directory Service commands (version 4.0) *)

{$DEFINE CMD_DS_LOGIN_TO_PRINT_SERVER}
Const CMD_DS_LOGIN_TO_PRINT_SERVER = $D1;
{$DEFINE CMD_DS_SCAN_QUEUE_LIST}
Const CMD_DS_SCAN_QUEUE_LIST = $DF;
{$DEFINE CMD_DS_CHANGE_QUEUE_PRIORITY}
Const CMD_DS_CHANGE_QUEUE_PRIORITY = $E0;
{$DEFINE CMD_DS_ADD_QUEUE}
Const CMD_DS_ADD_QUEUE = $E1;
{$DEFINE CMD_DS_DELETE_QUEUE}
Const CMD_DS_DELETE_QUEUE = $E2;
{$DEFINE CMD_DS_GET_PRINTERS_FOR_QUEUE}
Const CMD_DS_GET_PRINTERS_FOR_QUEUE = $E3;
{$DEFINE CMD_DS_SCAN_NOTIFY_LIST}
Const CMD_DS_SCAN_NOTIFY_LIST = $E4;
{$DEFINE CMD_DS_CHANGE_NOTIFY}
Const CMD_DS_CHANGE_NOTIFY = $E5;
{$DEFINE CMD_DS_ADD_NOTIFY}
Const CMD_DS_ADD_NOTIFY = $E6;
{$DEFINE CMD_DS_DELETE_NOTIFY}
Const CMD_DS_DELETE_NOTIFY = $E7;
{$DEFINE CMD_DS_GET_JOB_ID}
Const CMD_DS_GET_JOB_ID = $E8;
{$ENDIF}


(****************************************************************************)

(*============ Print Server Request/Reply Packet Structures ================*)

(****************************************************************************)

(*===== Generic Request and Reply Structures ===============================
  These are used by many of the commands because all that is needed is the
  Command BYTE or the ReturnCode nuint16. Commented copies are placed 
  strategically in order to fully document both the request and reply for
  each of the commands.
  ==========================================================================*)

Type
    NWPS_ReqstPkt_Other_T = Record
        command  :   nuint8 ;
    End;
    NWPS_ReqstPacket_Other = NWPS_ReqstPkt_Other_T;


Type
    NWPS_ReplyPkt_Other_T = Record
        returnCode  :   nuint16 ;
    End;
    NWPS_ReplyPacket_Other = NWPS_ReplyPkt_Other_T;


(*===== CMD_LOGIN_TO_PRINT_SERVER ==========================================*)

Type
    NWPS_ReqstPkt_LoginToPSrvr_T = Record
        command  :   nuint8 ;
        nServerName  :  Array[0..47] Of  nuint8 ;
        userConnectionNumber  :   nuint16 ;
    End;
    NWPS_ReqstPacket_LoginToPSrvr = NWPS_ReqstPkt_LoginToPSrvr_T;


Type
    NWPS_ReplyPkt_LoginToPSrvr_T = Record
        returnCode  :   nuint16 ;
        accessLevel  :   nuint8 ;
    End;
    NWPS_ReplyPacket_LoginToPSrvr = NWPS_ReplyPkt_LoginToPSrvr_T;


(*===== CMD_GET_PRINT_SERVER_INFO ==========================================*)

(* typedef struct NWPS_ReqstPkt_Other_T {
	nuint8	command;                      
} NWPS_ReqstPacket_Other; *)


Type
    NWPS_ReplyPkt_GetPSrvrInfo_T = Record
        returnCode  :   nuint16 ;
        info  :   NWPS_PSInfo ;
    End;
    NWPS_ReplyPacket_GetPSrvrInfo = NWPS_ReplyPkt_GetPSrvrInfo_T;


(*===== CMD_DOWN ===========================================================*)

Type
    NWPS_ReqstPkt_DownPServer_T = Record
        command  :   nuint8 ;
        doDownNow  :   nuint8 ;
        jobOutcome  :   nuint8 ;
    End;
    NWPS_ReqstPacket_DownPServer = NWPS_ReqstPkt_DownPServer_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_CANCEL_DOWN ====================================================*)

(* typedef struct NWPS_ReqstPkt_Other_T {
	nuint8	command;                      
} NWPS_ReqstPacket_Other; *)


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_GET_PRINTER_STATUS =============================================*)

Type
    NWPS_ReqstPkt_GetPrtStatus_T = Record
        command  :   nuint8 ;
        printerNumber  :   nuint8 ;
    End;
    NWPS_ReqstPacket_GetPrtStatus = NWPS_ReqstPkt_GetPrtStatus_T;


Type
    NWPS_ReplyPkt_GetPrtStatus_T = Record
        returnCode  :   nuint16 ;
        nPrinterStatus  :   nuint8 ;
        deviceStatusCode  :   nuint8 ;
        activeJob  :   nuint8 ;
        queueServiceMode  :   nuint8 ;
        mountedForm  :   nuint16 ;
        formName  :  Array[0..15] Of  nuint8 ;
        printerName  :  Array[0..47] Of  nuint8 ;
    End;
    NWPS_ReplyPacket_GetPrtStatus = NWPS_ReplyPkt_GetPrtStatus_T;


(*===== CMD_STOP_PRINTER ===================================================*)

Type
    NWPS_ReqstPkt_StopPrinter_T = Record
        command  :   nuint8 ;
        printerNumber  :   nuint8 ;
        jobOutcome  :   nuint8 ;
    End;
    NWPS_ReqstPacket_StopPrinter = NWPS_ReqstPkt_StopPrinter_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_START_PRINTER ==================================================*)

Type
    NWPS_ReqstPkt_StartPrinter_T = Record
        command  :   nuint8 ;
        printerNumber  :   nuint8 ;
    End;
    NWPS_ReqstPacket_StartPrinter = NWPS_ReqstPkt_StartPrinter_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_MOUNT_FORM =====================================================*)

Type
    NWPS_ReqstPkt_MountForm_T = Record
        command  :   nuint8 ;
        printerNumber  :   nuint8 ;
        formNumber  :   nuint8 ;
    End;
    NWPS_ReqstPacket_MountForm = NWPS_ReqstPkt_MountForm_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_REWIND_PRINT_JOB ===============================================*)

Type
    NWPS_ReqstPkt_RewindPJob_T = Record
        command  :   nuint8 ;
        printerNumber  :   nuint8 ;
        byPage  :   nuint8 ;
        relative  :   nuint8 ;
        copyNumber  :   nuint16 ;
        offset  :   nint32 ;
    End;
    NWPS_ReqstPacket_RewindPJob = NWPS_ReqstPkt_RewindPJob_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_EJECT_PAGE =====================================================*)

Type
    NWPS_ReqstPkt_EjectPage_T = Record
        command  :   nuint8 ;
        printerNumber  :   nuint8 ;
    End;
    NWPS_ReqstPacket_EjectPage = NWPS_ReqstPkt_EjectPage_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_MARK_PAGE ======================================================*)

Type
    NWPS_ReqstPkt_MarkPage_T = Record
        command  :   nuint8 ;
        printerNumber  :   nuint8 ;
        markingCharToUse  :   nuint8 ;
    End;
    NWPS_ReqstPacket_MarkPage = NWPS_ReqstPkt_MarkPage_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_CHANGE_SERVICE_MODE ============================================*)

Type
    NWPS_ReqstPkt_ChgServiceMode_T = Record
        command  :   nuint8 ;
        printerNumber  :   nuint8 ;
        newServiceMode  :   nuint8 ;
    End;
    NWPS_ReqstPacket_ChgServiceMode = NWPS_ReqstPkt_ChgServiceMode_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_GET_JOB_STATUS =================================================*)

Type
    NWPS_ReqstPkt_GetPJobStatus_T = Record
        command  :   nuint8 ;
        printerNumber  :   nuint8 ;
    End;
    NWPS_ReqstPacket_GetPJobStatus = NWPS_ReqstPkt_GetPJobStatus_T;


Type
    NWPS_ReplyPkt_GetPJobStatus_T = Record
        returnCode  :   nuint16 ;
        nServerName  :  Array[0..47] Of  nuint8 ;
        queueName  :  Array[0..47] Of  nuint8 ;
        queueJobNumber  :   nuint16 ;
        jobDescription  :  Array[0..49] Of  nuint8 ;
        copiesRequested  :   nuint16 ;
        copySize  :   nuint32 ;
        copiesCompleted  :   nuint16 ;
        bytesIntoCurrentCopy  :   nuint32 ;
        formNumber  :   nuint16 ;
        expandTabs  :   nuint8 ;
    End;
    NWPS_ReplyPacket_GetPJobStatus = NWPS_ReplyPkt_GetPJobStatus_T;


(*===== CMD_ABORT_JOB ======================================================*)

Type
    NWPS_ReqstPkt_AbortPrintJob_T = Record
        command  :   nuint8 ;
        printerNumber  :   nuint8 ;
        jobOutcome  :   nuint8 ;
    End;
    NWPS_ReqstPacket_AbortPrintJob = NWPS_ReqstPkt_AbortPrintJob_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_SCAN_QUEUE_LIST ================================================*)

Type
    NWPS_ReqstPkt_GetQServiced_T = Record
        command  :   nuint8 ;
        printer  :   nuint8 ;
        sequence  :   nuint16 ;
    End;
    NWPS_ReqstPacket_GetQServiced = NWPS_ReqstPkt_GetQServiced_T;


Type
    NWPS_ReplyPkt_GetQServiced_T = Record
        returnCode  :   nuint16 ;
        newSequence  :   nuint16 ;
        nServerName  :  Array[0..47] Of  nuint8 ;
        queueName  :  Array[0..47] Of  nuint8 ;
        priority  :   nuint8 ;
    End;
    NWPS_ReplyPacket_GetQServiced = NWPS_ReplyPkt_GetQServiced_T;


(*===== CMD_CHANGE_QUEUE_PRIORITY ==========================================*)

Type
    NWPS_ReqstPkt_ChgQPriority_T = Record
        command  :   nuint8 ;
        printer  :   nuint8 ;
        nServerName  :  Array[0..47] Of  nuint8 ;
        queueName  :  Array[0..47] Of  nuint8 ;
        priority  :   nuint8 ;
    End;
    NWPS_ReqstPacket_ChgQPriority = NWPS_ReqstPkt_ChgQPriority_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_ADD_QUEUE ======================================================*)

Type
    NWPS_ReqstPkt_AddQToPrtr_T = Record
        command  :   nuint8 ;
        printer  :   nuint8 ;
        nServerName  :  Array[0..47] Of  nuint8 ;
        queueName  :  Array[0..47] Of  nuint8 ;
        priority  :   nuint8 ;
    End;
    NWPS_ReqstPacket_AddQToPrtr = NWPS_ReqstPkt_AddQToPrtr_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_DELETE_QUEUE ===================================================*)

Type
    NWPS_ReqstPkt_DelQFromPrtr_T = Record
        command  :   nuint8 ;
        printer  :   nuint8 ;
        now  :   nuint8 ;
        jobOutcome  :   nuint8 ;
        nServerName  :  Array[0..47] Of  nuint8 ;
        queueName  :  Array[0..47] Of  nuint8 ;
    End;
    NWPS_ReqstPacket_DelQFromPrtr = NWPS_ReqstPkt_DelQFromPrtr_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_GET_PRINTERS_FOR_QUEUE =========================================*)

Type
    NWPS_ReqstPkt_GetPtrsForQ_T = Record
        command  :   nuint8 ;
        nServerName  :  Array[0..47] Of  nuint8 ;
        queueName  :  Array[0..47] Of  nuint8 ;
        maxPrinters  :   nuint8 ;
    End;
    NWPS_ReqstPacket_GetPtrsForQ = NWPS_ReqstPkt_GetPtrsForQ_T;


Type
    NWPS_ReplyPkt_GetPtrsForQ_T = Record
        returnCode  :   nuint16 ;
        numPrinters  :   nuint8 ;
        printers  :  Array[0..254] Of  nuint8 ;
    End;
    NWPS_ReplyPacket_GetPtrsForQ = NWPS_ReplyPkt_GetPtrsForQ_T;


(*===== CMD_SCAN_NOTIFY_LIST ===============================================*)

Type
    NWPS_ReqstPkt_GetNotifyObj_T = Record
        command  :   nuint8 ;
        printer  :   nuint8 ;
        sequenceNumber  :   nuint16 ;
    End;
    NWPS_ReqstPacket_GetNotifyObj = NWPS_ReqstPkt_GetNotifyObj_T;


Type
    NWPS_ReplyPkt_GetNotifyObj_T = Record
        returnCode  :   nuint16 ;
        sequence  :   nuint16 ;
        nServerName  :  Array[0..47] Of  nuint8 ;
        objectName  :  Array[0..47] Of  nuint8 ;
        type1  :   nuint16 ;
        initial  :   nuint16 ;
        repeat1  :   nuint16 ;
    End;
    NWPS_ReplyPacket_GetNotifyObj = NWPS_ReplyPkt_GetNotifyObj_T;


(*===== CMD_CHANGE_NOTIFY ==================================================*)

Type
    NWPS_ReqstPkt_ChgNotifyDel_T = Record
        command  :   nuint8 ;
        printer  :   nuint8 ;
        nServerName  :  Array[0..47] Of  nuint8 ;
        objectName  :  Array[0..47] Of  nuint8 ;
        type1  :   nuint16 ;
        initial  :   nuint16 ;
        repeat1  :   nuint16 ;
    End;
    NWPS_ReqstPacket_ChgNotifyDel = NWPS_ReqstPkt_ChgNotifyDel_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_ADD_NOTIFY =====================================================*)

Type
    NWPS_ReqstPkt_AddNotifyObj_T = Record
        command  :   nuint8 ;
        printer  :   nuint8 ;
        nServerName  :  Array[0..47] Of  nuint8 ;
        objectName  :  Array[0..47] Of  nuint8 ;
        type1  :   nuint16 ;
        initial  :   nuint16 ;
        repeat1  :   nuint16 ;
    End;
    NWPS_ReqstPacket_AddNotifyObj = NWPS_ReqstPkt_AddNotifyObj_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_DELETE_NOTIFY ==================================================*)

Type
    NWPS_ReqstPkt_DelNotifyObj_T = Record
        command  :   nuint8 ;
        printer  :   nuint8 ;
        nServerName  :  Array[0..47] Of  nuint8 ;
        objectName  :  Array[0..47] Of  nuint8 ;
        type1  :   nuint16 ;
    End;
    NWPS_ReqstPacket_DelNotifyObj = NWPS_ReqstPkt_DelNotifyObj_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_ATTACH_TO_FILE_SERVER ==========================================*)

Type
    NWPS_ReqstPkt_AttachPSrvNSrv_T = Record
        command  :   nuint8 ;
        nServerName  :  Array[0..47] Of  nuint8 ;
        password  :  Array[0..127] Of  nuint8 ;
    End;
    NWPS_ReqstPacket_AttachPSrvNSrv = NWPS_ReqstPkt_AttachPSrvNSrv_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_DETACH_FROM_FILE_SERVER ========================================*)

Type
    NWPS_ReqstPkt_DetachPServer_T = Record
        command  :   nuint8 ;
        immediately  :   nuint8 ;
        jobOutcome  :   nuint8 ;
        nServerName  :  Array[0..47] Of  nuint8 ;
    End;
    NWPS_ReqstPacket_DetachPServer = NWPS_ReqstPkt_DetachPServer_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_GET_ATTACHED_SERVERS ===========================================*)

Type
    NWPS_ReqstPkt_GetAttachdSrvr_T = Record
        command  :   nuint8 ;
        sequenceNumber  :   nuint8 ;
    End;
    NWPS_ReqstPacket_GetAttachdSrvr = NWPS_ReqstPkt_GetAttachdSrvr_T;


Type
    NWPS_ReplyPkt_GetAttachdSrvr_T = Record
        returnCode  :   nuint16 ;
        sequenceNumber  :   nuint8 ;
        nServerName  :  Array[0..47] Of  nuint8 ;
    End;
    NWPS_ReplyPacket_GetAttachdSrvr = NWPS_ReplyPkt_GetAttachdSrvr_T;


(*===== CMD_GET_RPRINTER ===================================================*)

Type
    NWPS_ReqstPkt_GetNPrinter_T = Record
        command  :   nuint8 ;
        lastPrinterNumber  :   nuint8 ;
    End;
    NWPS_ReqstPacket_GetNPrinter = NWPS_ReqstPkt_GetNPrinter_T;


Type
    NWPS_ReplyPkt_GetNPrinter_T = Record
        returnCode  :   nuint16 ;
        printerNumber  :   nuint8 ;
        printerType  :   nuint16 ;
        printerName  :  Array[0..47] Of  nuint8 ;
    End;
    NWPS_ReplyPacket_GetNPrinter = NWPS_ReplyPkt_GetNPrinter_T;


(*===== CMD_CONNECT_RPRINTER ===============================================*)

Type
    NWPS_ReqstPkt_ReqstNPrinter_T = Record
        command  :   nuint8 ;
        printerNumber  :   nuint8 ;
    End;
    NWPS_ReqstPacket_ReqstNPrinter = NWPS_ReqstPkt_ReqstNPrinter_T;


Type
    NWPS_ReplyPkt_ReqstNPrinter_T = Record
        returnCode  :   nuint16 ;
        info  :   NWPS_NInfo ;
    End;
    NWPS_ReplyPacket_ReqstNPrinter = NWPS_ReplyPkt_ReqstNPrinter_T;


(*===== CMD_SET_REMOTE_MODE ================================================*)

Type
    NWPS_ReqstPkt_SetNPrintrMode_T = Record
        command  :   nuint8 ;
        printerNumber  :   nuint8 ;
        mode  :   nuint8 ;
    End;
    NWPS_ReqstPacket_SetNPrintrMode = NWPS_ReqstPkt_SetNPrintrMode_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*******************************************************
 ** The packets below were added with the 4.0 PServer **
 *******************************************************)

(*===== CMD_SCAN_RPRINTER ===================================================*)

Type
    NWPS_ReqstPkt_ScanNPrinter_T = Record
        command  :   nuint8 ;
        lastPrinterNumber  :   nuint8 ;
    End;
    NWPS_ReqstPacket_ScanNPrinter = NWPS_ReqstPkt_ScanNPrinter_T;


Type
    NWPS_ReplyPkt_ScanNPrinter_T = Record
        returnCode  :   nuint16 ;
        printerNumber  :   nuint8 ;
        printerType  :   nuint16 ;
        printerName  :  Array[0..47] Of  nuint8 ;
        extendedConfigLength  :   nuint8 ;
        extendedConfig  :  Array[0..99] Of  nuint8 ;
    End;
    NWPS_ReplyPacket_ScanNPrinter = NWPS_ReplyPkt_ScanNPrinter_T;


(*===== CMD_ADD_FORM =======================================================*)

Type
    NWPS_ReqstPkt_AddForm_T = Record
        command  :   nuint8 ;
        printerNumber  :   nuint8 ;
        formNumber  :   nuint8 ;
    End;
    NWPS_ReqstPacket_AddForm = NWPS_ReqstPkt_AddForm_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_DISMOUNT_FORM ==================================================*)

Type
    NWPS_ReqstPkt_DismountForm_T = Record
        command  :   nuint8 ;
        printerNumber  :   nuint8 ;
        formNumber  :   nuint8 ;
    End;
    NWPS_ReqstPacket_DisMountForm = NWPS_ReqstPkt_DismountForm_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;                   
} NWPS_ReplyPacket_Other; *)


(*===== CMD_GET_EXT_PRINTER_STATUS =========================================*)

Type
    NWPS_ReqstPkt_GetExPrtStatus_T = Record
        command  :   nuint8 ;
        printerNumber  :   nuint8 ;
    End;
    NWPS_ReqstPacket_GetExPrtStatus = NWPS_ReqstPkt_GetExPrtStatus_T;


Type
    NWPS_ReplyPkt_GetExPrtStatus_T = Record
        returnCode  :   nuint16 ;
        primaryPrinterStatus  :  Array[0..59] Of nint8;
        errorStatus1  :   nuint8 ;
        secondaryPrinterStatus  :  Array[0..59] Of nint8;
        errorStatus2  :   nuint8 ;
        activeJobCount  :   nuint8 ;
        queueServiceMode  :   nuint8 ;
        mountedFormCount  :   nuint16 ;
        mountedFormNumber  :  Array[0..19] Of  nuint16 ;
    End;
    NWPS_ReplyPacket_GetExPrtStatus = NWPS_ReplyPkt_GetExPrtStatus_T;


(*===== CMD_DS_LOGIN_TO_PRINT_SERVER =======================================*)

Type
    NWPS_ReqstPkt_DSLoginToPSrvr_T = Record
        command  :   nuint8 ;
        userName  :  Array[0..511] Of  nuint8 ;
    End;
    NWPS_ReqstPacket_DSLoginToPSrvr = NWPS_ReqstPkt_DSLoginToPSrvr_T;


Type
    NWPS_ReplyPkt_DSLoginToPSrvr_T = Record
        returnCode  :   nuint16 ;
        accessLevel  :   nuint8 ;
    End;
    NWPS_ReplyPacket_DSLoginToPSrvr = NWPS_ReplyPkt_DSLoginToPSrvr_T;


(*===== CMD_DS_SCAN_QUEUE_LIST =============================================*)

Type
    NWPS_ReqstPkt_DSGetQServiced_T = Record
        command  :   nuint8 ;
        printer  :   nuint8 ;
        sequence  :   nuint16 ;
    End;
    NWPS_ReqstPacket_DSGetQServiced = NWPS_ReqstPkt_DSGetQServiced_T;


Type
    NWPS_ReplyPkt_DSGetQServiced_T = Record
        returnCode  :   nuint16 ;
        newSequence  :   nuint16 ;
        priority  :   nuint8 ;
        queue  :  Array[0..511] Of  nuint8 ;
    End;
    NWPS_ReplyPacket_DSGetQServiced = NWPS_ReplyPkt_DSGetQServiced_T;


(*===== CMD_DS_CHANGE_QUEUE_PRIORITY =======================================*)

Type
    NWPS_ReqstPkt_DSChgQPriority_T = Record
        command  :   nuint8 ;
        printer  :   nuint8 ;
        priority  :   nuint8 ;
        queue  :  Array[0..511] Of  nuint8 ;
    End;
    NWPS_ReqstPacket_DSChgQPriority = NWPS_ReqstPkt_DSChgQPriority_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_DS_ADD_QUEUE ===================================================*)

Type
    NWPS_ReqstPkt_DSAddQToPrtr_T = Record
        command  :   nuint8 ;
        printer  :   nuint8 ;
        priority  :   nuint8 ;
        queue  :  Array[0..511] Of  nuint8 ;
    End;
    NWPS_ReqstPacket_DSAddQToPrtr = NWPS_ReqstPkt_DSAddQToPrtr_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_DS_DELETE_QUEUE ================================================*)

Type
    NWPS_ReqstPkt_DSDelQFromPrtr_T = Record
        command  :   nuint8 ;
        printer  :   nuint8 ;
        now  :   nuint8 ;
        jobOutcome  :   nuint8 ;
        queue  :  Array[0..511] Of  nuint8 ;
    End;
    NWPS_ReqstPacket_DSDelQFromPrtr = NWPS_ReqstPkt_DSDelQFromPrtr_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_DS_GET_PRINTERS_FOR_QUEUE ======================================*)

Type
    NWPS_ReqstPkt_DSGetPtrsForQ_T = Record
        command  :   nuint8 ;
        maxPrinters  :   nuint8 ;
        queue  :  Array[0..511] Of  nuint8 ;
    End;
    NWPS_ReqstPacket_DSGetPtrsForQ = NWPS_ReqstPkt_DSGetPtrsForQ_T;


Type
    NWPS_ReplyPkt_DSGetPtrsForQ_T = Record
        returnCode  :   nuint16 ;
        numPrinters  :   nuint8 ;
        printers  :  Array[0..254] Of  nuint8 ;
    End;
    NWPS_ReplyPacket_DSGetPtrsForQ = NWPS_ReplyPkt_DSGetPtrsForQ_T;


(*===== CMD_DS_SCAN_NOTIFY_LIST ============================================*)

Type
    NWPS_ReqstPkt_DSGetNotifyObj_T = Record
        command  :   nuint8 ;
        printer  :   nuint8 ;
        sequenceNumber  :   nuint16 ;
    End;
    NWPS_ReqstPacket_DSGetNotifyObj = NWPS_ReqstPkt_DSGetNotifyObj_T;


Type
    NWPS_ReplyPkt_DSGetNotifyObj_T = Record
        returnCode  :   nuint16 ;
        sequence  :   nuint16 ;
        type1  :   nuint16 ;
        initial  :   nuint16 ;
        repeat1  :   nuint16 ;
        name  :  Array[0..511] Of  nuint8 ;
    End;
    NWPS_ReplyPacket_DSGetNotifyObj = NWPS_ReplyPkt_DSGetNotifyObj_T;


(*===== CMD_DS_CHANGE_NOTIFY ===============================================*)

Type
    NWPS_ReqstPkt_DSChgNotifyDel_T = Record
        command  :   nuint8 ;
        printer  :   nuint8 ;
        type1  :   nuint16 ;
        initial  :   nuint16 ;
        repeat1  :   nuint16 ;
        name  :  Array[0..511] Of  nuint8 ;
    End;
    NWPS_ReqstPacket_DSChgNotifyDel = NWPS_ReqstPkt_DSChgNotifyDel_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_DS_ADD_NOTIFY ==================================================*)

Type
    NWPS_ReqstPkt_DSAddNotifyObj_T = Record
        command  :   nuint8 ;
        printer  :   nuint8 ;
        type1  :   nuint16 ;
        initial  :   nuint16 ;
        repeat1  :   nuint16 ;
        name  :  Array[0..511] Of  nuint8 ;
    End;
    NWPS_ReqstPacket_DSAddNotifyObj = NWPS_ReqstPkt_DSAddNotifyObj_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_DS_DELETE_NOTIFY ===============================================*)

Type
    NWPS_ReqstPkt_DSDelNotifyObj_T = Record
        command  :   nuint8 ;
        printer  :   nuint8 ;
        type1  :   nuint16 ;
        name  :  Array[0..511] Of  nuint8 ;
    End;
    NWPS_ReqstPacket_DSDelNotifyObj = NWPS_ReqstPkt_DSDelNotifyObj_T;


(* typedef struct NWPS_ReplyPkt_Other_T {
	nuint16	returnCode;
} NWPS_ReplyPacket_Other; *)


(*===== CMD_DS_GET_JOB_ID ==================================================*)

Type
    NWPS_ReqstPkt_DSGetJobID_T = Record
        command  :   nuint8 ;
        printer  :   nuint8 ;
    End;
    NWPS_ReqstPacket_DSGetJobID = NWPS_ReqstPkt_DSGetJobID_T;


Type
    NWPS_ReplyPkt_DSGetJobID_T = Record
        returnCode  :   nuint16 ;
        queueNameFormat  :   nuint16 ;
        jobID  :   nuint32 ;
        binderyFormat : Record  (* union statement *)
            NWServerName  :  Array[0..47] Of  nuint8 ;
            name  :  Array[0..47] Of  nuint8 ;
        End;
    End;
    NWPS_ReplyPacket_DSGetJobID = NWPS_ReplyPkt_DSGetJobID_T;


{$ENDIF}

