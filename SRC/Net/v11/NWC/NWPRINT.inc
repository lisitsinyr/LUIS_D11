(******************************************************************************

  %name: nwprint.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:09:01 1996 %
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


{$IFNDEF  NWPRINT_H }
    {$DEFINE NWPRINT_H}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$I npackon.inc}
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    {$DEFINE LPT1}
    Const LPT1 = 1;
    {$DEFINE LPT2}
    Const LPT2 = 2;
    {$DEFINE LPT3}
    Const LPT3 = 3;
    {$DEFINE LPT4}
    Const LPT4 = 4;
    {$DEFINE LPT5}
    Const LPT5 = 5;
    {$DEFINE LPT6}
    Const LPT6 = 6;
    {$DEFINE LPT7}
    Const LPT7 = 7;
    {$DEFINE LPT8}
    Const LPT8 = 8;
    {$DEFINE LPT9}
    Const LPT9 = 9;
    {$DEFINE START_CAPTURE}
    Const START_CAPTURE = 1;
    {$DEFINE END_CAPTURE}
    Const END_CAPTURE = 2;
    {$DEFINE CANCEL_CAPTURE}
    Const CANCEL_CAPTURE = 3;
    {$DEFINE GET_PRINT_JOB_FLAGS}
    Const GET_PRINT_JOB_FLAGS = 4;
    {$DEFINE SET_PRINT_JOB_FLAGS}
    Const SET_PRINT_JOB_FLAGS = 5;
    {$DEFINE GET_BANNER_USER_NAME}
    Const GET_BANNER_USER_NAME = 6;
    {$DEFINE SET_BANNER_USER_NAME}
    Const SET_BANNER_USER_NAME = 7;
    {$DEFINE GET_PRINTER_SETUP_STRING}
    Const GET_PRINTER_SETUP_STRING = 8;
    {$DEFINE SET_PRINTER_SETUP_STRING}
    Const SET_PRINTER_SETUP_STRING = 9;
    {$DEFINE GET_PRINTER_RESET_STRING}
    Const GET_PRINTER_RESET_STRING = 10;
    {$DEFINE SET_PRINTER_RESET_STRING}
    Const SET_PRINTER_RESET_STRING = 11;
    Type
        PrintJobStruct = Record
            clientStation  :   nuint8 ;
            clientTask  :   nuint8 ;
            clientID  :   nuint32 ;
            targetServerID  :   nuint32 ;
            targetExecutionTime  :  Array[0..5] Of  nuint8 ;
            jobEntryTime  :  Array[0..5] Of  nuint8 ;
            jobNumber  :   nuint16 ;
            formType  :   nuint16 ;
            jobPosition  :   nuint8 ;
            jobControlFlags  :   nuint8 ;
            jobFileName  :  Array[0..13] Of  nuint8 ;
            jobFileHandle  :  Array[0..5] Of  nuint8 ;
            servicingServerStation  :   nuint8 ;
            servicingServerTask  :   nuint8 ;
            servicingServerID  :   nuint32 ;
            jobDescription  :  Array[0..49] Of  nuint8 ;
            clientJobInfoVer  :   nuint8 ;
            tabSize  :   nuint8 ;
            numberCopies  :   nuint16 ;
            printFlags  :   nuint16 ;
            maxLines  :   nuint16 ;
            maxChars  :   nuint16 ;
            formName  :  Array[0..15] Of  nuint8 ;
            reserved  :  Array[0..5] Of  nuint8 ;
            bannerUserName  :  Array[0..12] Of  nuint8 ;
            bannerFileName  :  Array[0..12] Of  nuint8 ;
            bannerHeaderFileName  :  Array[0..13] Of  nuint8 ;
            filePathName  :  Array[0..79] Of  nuint8 ;
        End;
    Type
        NWPrintJobStruct = Record
            clientStation  :   nuint32 ;
            clientTask  :   nuint32 ;
            clientID  :   nuint32 ;
            targetServerID  :   nuint32 ;
            targetExecutionTime  :  Array[0..5] Of  nuint8 ;
            jobEntryTime  :  Array[0..5] Of  nuint8 ;
            jobNumber  :   nuint32 ;
            formType  :   nuint16 ;
            jobPosition  :   nuint16 ;
            jobControlFlags  :   nuint16 ;
            jobFileName  :  Array[0..13] Of  nuint8 ;
            jobFileHandle  :   nuint32 ;
            servicingServerStation  :   nuint32 ;
            servicingServerTask  :   nuint32 ;
            servicingServerID  :   nuint32 ;
            jobDescription  :  Array[0..49] Of  nuint8 ;
            clientJobInfoVer  :   nuint8 ;
            tabSize  :   nuint8 ;
            numberCopies  :   nuint16 ;
            printFlags  :   nuint16 ;
            maxLines  :   nuint16 ;
            maxChars  :   nuint16 ;
            formName  :  Array[0..15] Of  nuint8 ;
            reserved  :  Array[0..5] Of  nuint8 ;
            bannerUserName  :  Array[0..12] Of  nuint8 ;
            bannerFileName  :  Array[0..12] Of  nuint8 ;
            bannerHeaderFileName  :  Array[0..13] Of  nuint8 ;
            filePathName  :  Array[0..79] Of  nuint8 ;
        End;
    Type
        PRINTER_STATUS = Record
            printerHalted  :   nuint8 ;
            printerOffline  :   nuint8 ;
            currentFormType  :   nuint8 ;
            redirectedPrinter  :   nuint8 ;
        End;
    Type
        NWCAPTURE_FLAGSRW = Record
            jobDescription  :  Array[0..49] Of  nuint8 ;
            (* VLM returns or sets only 12 characters *)
            (* plus the NULL -- a total of 13 nuint8's   *)
            jobControlFlags  :   nuint8 ;
            tabSize  :   nuint8 ;
            numCopies  :   nuint16 ;
            printFlags  :   nuint16 ;
            maxLines  :   nuint16 ;
            maxChars  :   nuint16 ;
            formName  :  Array[0..12] Of  nuint8 ;
            reserved  :  Array[0..8] Of  nuint8 ;
            formType  :   nuint16 ;
            bannerText  :  Array[0..12] Of  nuint8 ;
            reserved2  :   nuint8 ;
            flushCaptureTimeout  :   nuint16 ;
            flushCaptureOnClose  :   nuint8 ;
        End;
    Type NWCAPTURE_FLAGS1 = NWCAPTURE_FLAGSRW;
    Type
        NWCAPTURE_FLAGSRO = Record
            connID  :   NWCONN_HANDLE ;
            queueID  :   nuint32 ;
            setupStringMaxLen  :   nuint16 ;
            resetStringMaxLen  :   nuint16 ;
            LPTCaptureFlag  :   nuint8 ;
            fileCaptureFlag  :   nuint8 ;
            timingOutFlag  :   nuint8 ;
            inProgress  :   nuint8 ;
            printQueueFlag  :   nuint8 ;
            printJobValid  :   nuint8 ;
            queueName  :  Array[0..64] Of  nstr8 ;
        End;
    Type NWCAPTURE_FLAGS2 = NWCAPTURE_FLAGSRO;
    Type
        NWCAPTURE_FLAGSRO3 = Record
            connRef  :   nuint32 ;
            queueID  :   nuint32 ;
            setupStringMaxLen  :   nuint16 ;
            resetStringMaxLen  :   nuint16 ;
            LPTCaptureFlag  :   nuint8 ;
            fileCaptureFlag  :   nuint8 ;
            timingOutFlag  :   nuint8 ;
            inProgress  :   nuint8 ;
            printQueueFlag  :   nuint8 ;
            printJobValid  :   nuint8 ;
            queueName  :  Array[0..64] Of  nstr8 ;
        End;
    Type NWCAPTURE_FLAGS3 = NWCAPTURE_FLAGSRO3;
    {$IFDEF N_PLAT_OS2}
    {$DEFINE N_APIPIPE}
    Const N_APIPIPE = '\\PIPE\\NWSPOOL\\API';
    {$DEFINE NET_SPOOL_SEG}
    Const NET_SPOOL_SEG = '\\sharemem\\nwspool\\seg1';
    {$DEFINE NET_SPOOL_SEM1}
    Const NET_SPOOL_SEM1 = '\\sem\\nwspool\\sem1';
    {$DEFINE NET_SPOOL_SEM2}
    Const NET_SPOOL_SEM2 = '\\sem\\nwspool\\sem2';
    {$DEFINE NET_SPOOL_SEM3}
    Const NET_SPOOL_SEM3 = '\\sem\\nwspool\\sem3';
    Type
        SpoolFlagsStruct = Record
            targetServerID  :   nuint32 ;
            targetExecutionTime  :  Array[0..5] Of  nuint8 ;
            jobDescription  :  Array[0..49] Of  nuint8 ;
            jobControlFlags  :   nuint8 ;
            tabSize  :   nuint8 ;
            numberCopies  :   nuint16 ;
            printFlags  :   nuint16 ;
            maxLines  :   nuint16 ;
            maxChars  :   nuint16 ;
            formName  :  Array[0..15] Of  nuint8 ;
            reserved1  :  Array[0..5] Of  nuint8 ;
            formType  :   nuint16 ;
            bannerFileName  :  Array[0..12] Of  nuint8 ;
            reserved2  :   nuint8 ;
            (* The following fields can be gotten, but not set *)
            connID  :   NWCONN_HANDLE ;
            queueID  :   nuint32 ;
            setupStringMaxLength  :   nuint16 ;
            resetStringMaxLength  :   nuint16 ;
        End;
    Type
        _NWPipeStruct = Record
            fwCommand  :   nuint16 ;
            idSession  :   nuint16 ;
            idQueue  :   nuint32 ;
            idConnection  :   nuint16 ;
            idDevice  :   nuint16 ;
            fwMode  :   nuint16 ;
            fwScope  :   nuint16 ;
            cbBufferLength  :   nuint16 ;
            fbValidBuffer  :   nuint8 ;
            nwsSpoolFlags  :   SpoolFlagsStruct ;
            szBannerUserName  :  Array[0..12] Of  nuint8 ;
            rc  :   nuint16 ;
        End;
        NWPipeStruct = _NWPipeStruct;
    (* Not implemented Function NWSpoolGetPrintJobFlags (
        deviceID  :   nuint16 ;
        Var flagsBuffer  : SpoolFlagsStruct;
        mode  :   nuint16 ;
        scope  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWSpoolSetPrintJobFlags (
        deviceID  :   nuint16 ;
        Var flagsBuffer  : SpoolFlagsStruct;
        unused  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWSpoolGetPrinterSetupString (
        deviceID  :   nuint16 ;
        bufferLen  :   pnuint16 ;
        buffer  :   pnstr8 ;
        mode  :   nuint16 ;
        scope  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWSpoolSetPrinterSetupString (
        deviceID  :   nuint16 ;
        bufferLen  :   nuint16 ;
        buffer  :   pnstr8 ;
        scope  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWSpoolGetPrinterResetString (
        deviceID  :   nuint16 ;
        bufferLen  :   pnuint16 ;
        buffer  :   pnstr8 ;
        mode  :   nuint16 ;
        scope  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWSpoolSetPrinterResetString (
        deviceID  :   nuint16 ;
        bufferLen  :   nuint16 ;
        buffer  :   pnstr8 ;
        scope  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    Type
        CaptureFlagsStruct = Record
            status  :   nuint8 ;
            flags  :   nuint8 ;
            tabSize  :   nuint8 ;
            serverPrinter  :   nuint8 ;
            numberCopies  :   nuint8 ;
            formType  :   nuint8 ;
            reserved  :   nuint8 ;
            bannerText  :  Array[0..12] Of  nuint8 ;
            reserved2  :   nuint8 ;
            localLPTDevice  :   nuint8 ;
            captureTimeOutCount  :   nuint16 ;
            captureOnDeviceClose  :   nuint8 ;
        End;
    (* Not implemented Function NWGetPrinterDefaults (
        status  :   pnuint8 ;
        flags  :   pnuint8 ;
        tabSize  :   pnuint8 ;
        serverPrinter  :   pnuint8 ;
        numberCopies  :   pnuint8 ;
        formType  :   pnuint8 ;
        bannerText  :   pnstr8 ;
        localLPTDevice  :   pnuint8 ;
        captureTimeOutCount  :   pnuint16 ;
        captureOnDeviceClose  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWSetPrinterDefaults (
        flags  :   nuint8 ;
        tabSize  :   nuint8 ;
        serverPrinter  :   nuint8 ;
        numberCopies  :   nuint8 ;
        formType  :   nuint8 ;
        bannerText  :   pnstr8 ;
        localLPTDevice  :   nuint8 ;
        captureTimeOutCount  :   nuint16 ;
        captureOnDeviceClose  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWStartLPTCapture (
        deviceID  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWGetLPTCaptureStatus (
        Var conn  : NWCONN_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWStartFileCapture (
        conn  :   NWCONN_HANDLE ;
        LPTDevice  :   nuint8 ;
        dirhandle  :   NWDIR_HANDLE ;
        filePath  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
{$ENDIF}


(* Not implemented Function NWSpoolStartCapture (
    deviceID  :   nuint16 ;
    queueID  :   nuint32 ;
    conn  :   NWCONN_HANDLE ;
    scope  :   nuint16 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)


Function NWSpoolEndCapture (
    deviceID  :   nuint16 ;
    scope  :   nuint16 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWSpoolCancelCapture (
    deviceID  :   nuint16 ;
    scope  :   nuint16 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWSpoolGetBannerUserName (
    username  :   pnstr8 ;
    mode  :   nuint16 ;
    scope  :   pnuint16 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWSpoolSetBannerUserName (
    username  :   pnstr8 ;
    scope  :   nuint16 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWGetPrinterStatus (
    conn  :   NWCONN_HANDLE ;
    printerNumber  :   nuint16 ;
    Var status  : PRINTER_STATUS
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWStartQueueCapture (
    conn  :   NWCONN_HANDLE ;
    LPTDevice  :   nuint8 ;
    queueID  :   nuint32 ;
    queueName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWGetCaptureStatus (
    LPTDevice  :   nuint8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWFlushCapture (
    LPTDevice  :   nuint8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWEndCapture (
    LPTDevice  :   nuint8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWCancelCapture (
    LPTDevice  :   nuint8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWGetBannerUserName (
    userName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWSetBannerUserName (
    userName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWGetCaptureFlags (
    LPTDevice  :   nuint8 ;
    Var captureFlags1  : NWCAPTURE_FLAGS1;
    Var captureFlags2  : NWCAPTURE_FLAGS2
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWGetCaptureFlagsConnRef (
    LPTDevice  :   nuint8 ;
    Var captureFlags1  : NWCAPTURE_FLAGS1;
    Var captureFlags3  : NWCAPTURE_FLAGS3
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWSetCaptureFlags (
    conn  :   NWCONN_HANDLE ;
    LPTDevice  :   nuint8 ;
    Var captureFlags1  : NWCAPTURE_FLAGS1
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWGetPrinterStrings (
    LPTDevice  :   nuint8 ;
    setupStringLen  :   pnuint16 ;
    setupString  :   pnstr8 ;
    resetStringLen  :   pnuint16 ;
    resetString  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWSetPrinterStrings (
    LPTDevice  :   nuint8 ;
    setupStringLen  :   nuint16 ;
    setupString  :   pnstr8 ;
    resetStringLen  :   nuint16 ;
    resetString  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWGetMaxPrinters (
    numPrinters  :   pnuint16 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}


{$I npackoff.inc}
{$ENDIF}

