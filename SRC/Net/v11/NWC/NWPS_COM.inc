(*
//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
//บ (c) 1993 Novell, Inc.	 All rights reserved.										บ
//บ																								  บ
//บ THIS WORK IS SUBJECT TO U.S. AND INTERNATIONAL COPYRIGHT LAWS AND		  บ
//บ TREATIES.																						บ
//บ																								  บ
//บ NO PART OF THIS WORK MAY BE USED, PRACTICED, PERFORMED, COPIED,				บ
//บ DISTRIBUTED, REVISED, MODIFIED, TRANSLATED, ABRIDGED, CONDENSED,         บ
//บ EXPANDED, COLLECTED, COMPILED, LINKED, RECAST, TRANSFORMED OR ADAPTED		บ
//บ WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC.                        บ
//บ																								  บ
//บ ANY USE OR EXPLOITATION OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT บ
//บ THE PERPETRATOR TO CRIMINAL AND CIVIL LIABILITY.									บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Source module name: NWPS_COM.H															บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

{$IFNDEF NWPS_DEF_INC}

{$I nwps_def.inc}
{$ENDIF}



{$IFNDEF NWPS_COM_INC}

{$DEFINE NWPS_COM_INC}
(*********************************************************************)

(*********** COM - Pserver Transport Interface ***********************)

(*********************************************************************)


(*========= Client privilege levels from the Print Server ================= *)

{$DEFINE NWPS_LIMITED}
Const NWPS_LIMITED = 0;
{$DEFINE NWPS_USER}
Const NWPS_USER = 1;
{$DEFINE NWPS_OPERATOR}
Const NWPS_OPERATOR = 2;

(*========================== Job Outcomes ================================= *)

{$DEFINE NWPS_PLACE_ON_HOLD}
Const NWPS_PLACE_ON_HOLD = 0;
{$DEFINE NWPS_RETURN_TO_QUEUE}
Const NWPS_RETURN_TO_QUEUE = 1;
{$DEFINE NWPS_THROW_AWAY}
Const NWPS_THROW_AWAY = 2;

(*=================== Network Printer Status codes ======================== *)

{$DEFINE NWPS_PRINTER_RUNNING}
Const NWPS_PRINTER_RUNNING = 0;
{$DEFINE NWPS_PRINTER_OFFLINE}
Const NWPS_PRINTER_OFFLINE = 1;
{$DEFINE NWPS_PRINTER_PAPER_OUT}
Const NWPS_PRINTER_PAPER_OUT = 2;
{$DEFINE NWPS_CONNECTION_LOST}
Const NWPS_CONNECTION_LOST = 4;

(*===== Network Printer and Extended Network Printer Info flags ============*)

{$DEFINE NWPS_PRINTER_SHARED}
Const NWPS_PRINTER_SHARED = 0;
{$DEFINE NWPS_PRINTER_PRIVATE}
Const NWPS_PRINTER_PRIVATE = 1;

(*=== Print Server info structure returned by NWPSComGetPrintServerInfo ====*)

Type
    NWPS_PSInfo = Record
        status  :   nuint8 ;
        numPrinters  :   nuint8 ;
        numModes  :   nuint8 ;
        majorVersion  :   nuint8 ;
        minorVersion  :   nuint8 ;
        revision  :   nuint8 ;
        serialNumber  :  Array[0..3] Of  nuint8 ;
        serverType  :   nuint8 ;
        nameServiceMode  :   nuint8 ;
        futureUse  :  Array[0..7] Of  nuint8 ;
    End;


(*==============================================
  Network Printer information structure returned
  by NWPSComRequestNetworkPrinter()
  ==============================================*)

Type
    NWPS_NInfo = Record
        printerType  :   nuint16 ;
        useInterrupts  :   nuint16 ;
        irqNumber  :   nuint16 ;
        numBlocks  :   nuint16 ;
        useXonXoff  :   nuint16 ;
        baudRate  :   nuint16 ;
        dataBits  :   nuint16 ;
        stopBits  :   nuint16 ;
        parity  :   nuint16 ;
        socket  :   nuint16 ;
    End;


(*===============================================
  Network Printer status structure used to report
  the current status to the print server.
  (Not used in any API calls)
  ===============================================*)

Type
    NWPS_NStatus = Record
        printerNumber  :   nuint8 ;
        needBlocks  :   nuint8 ;
        finishedBlocks  :   nuint8 ;
        status  :   nuint8 ;
        inSideBand  :   nuint8 ;
    End;


(*======================================================
  Data types sent by the PServer to a Network printer.
  The first byte of every print server to printer packet
  will have one of these codes in it.
  (Not used in any API calls)
  ======================================================*)

{$DEFINE NWPS_DST_DATA}
Const NWPS_DST_DATA = nuint8(0);
{$DEFINE NWPS_DST_FLUSH}
Const NWPS_DST_FLUSH = nuint8(1);
{$DEFINE NWPS_DST_PAUSE}
Const NWPS_DST_PAUSE = nuint8(2);
{$DEFINE NWPS_DST_START}
Const NWPS_DST_START = nuint8(3);
{$DEFINE NWPS_DST_SIDEBAND}
Const NWPS_DST_SIDEBAND = nuint8(4);
{$DEFINE NWPS_DST_NEW_JOB}
Const NWPS_DST_NEW_JOB = nuint8(5);
{$DEFINE NWPS_DST_RELEASE}
Const NWPS_DST_RELEASE = nuint8(6);
{$DEFINE NWPS_DST_RECLAIM}
Const NWPS_DST_RECLAIM = nuint8(7);
{$DEFINE NWPS_DST_EOJ}
Const NWPS_DST_EOJ = nuint8(8);



(*
// The following conditional includes pick up the varying definitions
// of NWPSComAttachToPrintServer and NWPSComLoginToPrintServer.  Since
// the majority of the NWPSComxxxxx calls are unaffected by the
// distinction between connections and their types the prototype were
// kept in this file.  This is an exception compared to the other
// major groups of supported calls.
*)

{$IFDEF  NWPS_CONN_TYPE }
    {$IFDEF NWPS_CONN_TYPE==NWPS_BINDERY_SERVICE}
        {$I nwpscom0.inc}
    {$ELSE}  {$IFDEF NWPS_CONN_TYPE==NWPS_DIRECTORY_SERVICE}
        {$I nwpscom1.inc}
    {$ELSE}  {$IFDEF NWPS_CONN_TYPE==NWPS_BINDERY_SERVICE_PRE_40}
        {$I nwpscom0.inc}
    {$ELSE}  {$IFDEF NWPS_CONN_TYPE==NWPS_BINDERY_SERVICE_ALL}
        {$I nwpscom0.inc}
    {$ENDIF}
    {$ENDIF}
    {$ENDIF}
    {$ENDIF}
{$ELSE}
    {$I nwpscomx.inc}
{$ENDIF}


{$IFDEF __cplusplus}

(* TC extern C *)
{$ENDIF}


(*====================== Print Server Communications ======================*)


Function NWPSComAbortPrintJob (
    spxID  :   NWPS_SPXID_HANDLE ;
    printerID  :   nuint ;
    jobOutcome  :   nuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComAddNotifyObject (
    spxID  :   NWPS_SPXID_HANDLE ;
    printerID  :   nuint ;
    nServerName  :   pnstr8 ;
    objectName  :   pnstr8 ;
    objectType  :   nuint ;
    notifyDelay  :   nuint ;
    notifyInterval  :   nuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComAddQueueToPrinter (
    spxID  :   NWPS_SPXID_HANDLE ;
    printerID  :   nuint ;
    nServerName  :   pnstr8 ;
    queueName  :   pnstr8 ;
    priority  :   nuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComAttachPServerToNServer (
    spxID  :   NWPS_SPXID_HANDLE ;
    nServerName  :   pnstr8 ;
    password  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComCancelDownRequest (
    spxID  :   NWPS_SPXID_HANDLE 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComChangeNotifyInterval (
    spxID  :   NWPS_SPXID_HANDLE ;
    printerID  :   nuint ;
    nServerName  :   pnstr8 ;
    objectName  :   pnstr8 ;
    objectType  :   nuint ;
    notifyDelay  :   nuint ;
    notifyInterval  :   nuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComChangeQueuePriority (
    spxID  :   NWPS_SPXID_HANDLE ;
    printerID  :   nuint ;
    nServerName  :   pnstr8 ;
    queueName  :   pnstr8 ;
    priority  :   nuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComChangeServiceMode (
    spxID  :   NWPS_SPXID_HANDLE ;
    printerName  :   nuint ;
    serviceMode  :   nuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComDeleteNotifyObject (
    spxID  :   NWPS_SPXID_HANDLE ;
    printerID  :   nuint ;
    nServerName  :   pnstr8 ;
    objectName  :   pnstr8 ;
    objectType  :   nuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComDeleteQueueFromPrinter (
    spxID  :   NWPS_SPXID_HANDLE ;
    printerID  :   nuint ;
    nServerName  :   pnstr8 ;
    queueName  :   pnstr8 ;
    detach  :   nuint ;
    jobOutcome  :   nuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComDetachFromPrintServer (
    spxID  :   NWPS_SPXID_HANDLE 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComDetachPServerFromNServer (
    spxID  :   NWPS_SPXID_HANDLE ;
    nServerName  :   pnstr8 ;
    detach  :   nuint ;
    jobOutcome  :   nuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComDownPrintServer (
    spxID  :   NWPS_SPXID_HANDLE ;
    immediate  :   nuint ;
    jobOutcome  :   nuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComEjectForm (
    spxID  :   NWPS_SPXID_HANDLE ;
    printerID  :   nuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComGetAttachedNServers (
    spxID  :   NWPS_SPXID_HANDLE ;
    sequence  :   pnuint ;
    nServerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComGetNotifyObject (
    spxID  :   NWPS_SPXID_HANDLE ;
    printerID  :   nuint ;
    sequence  :   pnuint ;
    nServerName  :   pnstr8 ;
    objectName  :   pnstr8 ;
    objectType  :   pnuint ;
    notifyDelay  :   pnuint ;
    notifyInterval  :   pnuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComGetPrintersServicingQ (
    spxID  :   NWPS_SPXID_HANDLE ;
    nServerName  :   pnstr8 ;
    queueName  :   pnstr8 ;
    maxPrinters  :   nuint ;
    actualPrinters  :   pnuint ;
    printerArray  :   pnuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComGetPrinterStatus (
    spxID  :   NWPS_SPXID_HANDLE ;
    printerID  :   nuint ;
    status  :   pnuint ;
    troubleCode  :   pnuint ;
    active  :   pnuint ;
    serviceMode  :   pnuint ;
    formNumber  :   pnuint ;
    formName  :   pnstr8 ;
    printerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComGetExtPrinterStatus (
    spxID  :   NWPS_SPXID_HANDLE ;
    printerID  :   nuint ;
    primaryStatus  :   pnstr8 ;
    primaryLevel  :   pnuint ;
    secondaryStatus  :   pnstr8 ;
    secondaryLevel  :   pnuint ;
    activeJobCount  :   pnuint ;
    serviceMode  :   pnuint ;
    formsMounted  :   pnuint ;
    formList  :   pnuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComGetPrintJobStatus (
    spxID  :   NWPS_SPXID_HANDLE ;
    printerID  :   nuint ;
    nServerName  :   pnstr8 ;
    queueName  :   pnstr8 ;
    jobID  :   pnuint32 ;
    jobDescription  :   pnstr8 ;
    copies  :   pnuint ;
    printJobSize  :   pnuint32 ;
    copiesDone  :   pnuint ;
    bytesDone  :   pnuint32 ;
    formNumber  :   pnuint ;
    textFlag  :   pnuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComGetPrintServerInfo (
    spxID  :   NWPS_SPXID_HANDLE ;
    psInfo  :   NWPS_PSInfo ;
    size  :   nuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComGetQueuesServiced (
    spxID  :   NWPS_SPXID_HANDLE ;
    printerID  :   nuint ;
    sequence  :   pnuint ;
    nServerName  :   pnstr8 ;
    queueName  :   pnstr8 ;
    priority  :   pnuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComMarkTopOfForm (
    spxID  :   NWPS_SPXID_HANDLE ;
    printerID  :   nuint ;
    mark  :  nint8
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComPrintServerRequest (
    spxID  :   NWPS_SPXID_HANDLE ;
    reqBuffer  :   nptr ;
    reqSize  :  nint32;
    repBuffer  :   nptr ;
    repSize  :  nint32
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComRewindPrintJob (
    spxID  :   NWPS_SPXID_HANDLE ;
    printerID  :   nuint ;
    byPage  :   nuint ;
    relative  :   nuint ;
    copy  :   nuint ;
    offset  :   nuint32 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComSetMountedForm (
    spxID  :   NWPS_SPXID_HANDLE ;
    printerID  :   nuint ;
    formNumber  :   nuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComStartPrinter (
    spxID  :   NWPS_SPXID_HANDLE ;
    printerID  :   nuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComStopPrinter (
    spxID  :   NWPS_SPXID_HANDLE ;
    printerID  :   nuint ;
    jobOutcome  :   nuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*================== Network Printer Calls ===============================*)

Function NWPSComGetNextRemotePrinter (
    spxID  :   NWPS_SPXID_HANDLE ;
    printerID  :   pnuint ;
    printerType  :   pnuint ;
    printerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComRequestRemotePrinter (
    spxID  :   NWPS_SPXID_HANDLE ;
    printerID  :   nuint ;
    info  :   NWPS_NInfo 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSComSetRemoteMode (
    spxID  :   NWPS_SPXID_HANDLE ;
    printerID  :   nuint ;
    newMode  :   nuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}


{$ENDIF}


