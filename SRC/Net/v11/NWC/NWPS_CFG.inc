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
//บ Source module name: NWPS_CFG.H														  บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

{$IFNDEF NWPS_DEF_INC}

{$I nwps_def.inc}
{$ENDIF}


{$IFNDEF NWPS_CFG_INC}

{$DEFINE NWPS_CFG_INC}
(****************************************************************************)

(*************** CFG - Print Server Configuration Information ***************)

(****************************************************************************)


(*====================== Configuration Attributes ==========================*)

{$DEFINE NWPS_ATTR_CART}
Const NWPS_ATTR_CART = 0;
{$DEFINE NWPS_ATTR_CLASS}
Const NWPS_ATTR_CLASS = 1;
{$DEFINE NWPS_ATTR_CN}
Const NWPS_ATTR_CN = 2;
{$DEFINE NWPS_ATTR_CONF}
Const NWPS_ATTR_CONF = 3;
{$DEFINE NWPS_ATTR_DQUEUE}
Const NWPS_ATTR_DQUEUE = 4;
{$DEFINE NWPS_ATTR_DESC}
Const NWPS_ATTR_DESC = 5;
{$DEFINE NWPS_ATTR_DEVICE}
Const NWPS_ATTR_DEVICE = 6;
{$DEFINE NWPS_ATTR_HOST_DEV}
Const NWPS_ATTR_HOST_DEV = 7;
{$DEFINE NWPS_ATTR_HOST_RES}
Const NWPS_ATTR_HOST_RES = 8;
{$DEFINE NWPS_ATTR_HOST_SER}
Const NWPS_ATTR_HOST_SER = 9;
{$DEFINE NWPS_ATTR_L}
Const NWPS_ATTR_L = 10;
{$DEFINE NWPS_ATTR_MEMORY}
Const NWPS_ATTR_MEMORY = 11;
{$DEFINE NWPS_ATTR_NADD}
Const NWPS_ATTR_NADD = 12;
{$DEFINE NWPS_ATTR_NADD_REST}
Const NWPS_ATTR_NADD_REST = 13;
{$DEFINE NWPS_ATTR_NOTIFY}
Const NWPS_ATTR_NOTIFY = 14;
{$DEFINE NWPS_ATTR_O}
Const NWPS_ATTR_O = 15;
{$DEFINE NWPS_ATTR_OPER}
Const NWPS_ATTR_OPER = 16;
{$DEFINE NWPS_ATTR_OU}
Const NWPS_ATTR_OU = 17;
{$DEFINE NWPS_ATTR_OWNER}
Const NWPS_ATTR_OWNER = 18;
{$DEFINE NWPS_ATTR_PAGE}
Const NWPS_ATTR_PAGE = 19;
{$DEFINE NWPS_ATTR_PJOB}
Const NWPS_ATTR_PJOB = 20;
{$DEFINE NWPS_ATTR_PCTRL}
Const NWPS_ATTR_PCTRL = 21;
{$DEFINE NWPS_ATTR_PRINT_SER}
Const NWPS_ATTR_PRINT_SER = 22;
{$DEFINE NWPS_ATTR_PRINTER}
Const NWPS_ATTR_PRINTER = 23;
{$DEFINE NWPS_ATTR_PRIV_KEY}
Const NWPS_ATTR_PRIV_KEY = 24;
{$DEFINE NWPS_ATTR_PUBL_KEY}
Const NWPS_ATTR_PUBL_KEY = 25;
{$DEFINE NWPS_ATTR_QUEUE}
Const NWPS_ATTR_QUEUE = 26;
{$DEFINE NWPS_ATTR_QUE_DIR}
Const NWPS_ATTR_QUE_DIR = 27;
{$DEFINE NWPS_ATTR_SAP}
Const NWPS_ATTR_SAP = 28;
{$DEFINE NWPS_ATTR_SEE_ALSO}
Const NWPS_ATTR_SEE_ALSO = 29;
{$DEFINE NWPS_ATTR_SERIAL}
Const NWPS_ATTR_SERIAL = 30;
{$DEFINE NWPS_ATTR_SERVER}
Const NWPS_ATTR_SERVER = 31;
{$DEFINE NWPS_ATTR_STAT}
Const NWPS_ATTR_STAT = 32;
{$DEFINE NWPS_ATTR_TYPE}
Const NWPS_ATTR_TYPE = 33;
{$DEFINE NWPS_ATTR_USER}
Const NWPS_ATTR_USER = 34;
{$DEFINE NWPS_ATTR_VERS}
Const NWPS_ATTR_VERS = 35;
{$DEFINE NWPS_ATTR_VOLUME}
Const NWPS_ATTR_VOLUME = 36;
{$DEFINE NWPS_ATTR_ACL}
Const NWPS_ATTR_ACL = 37;

(* StartFlag meanings *)

{$DEFINE NWPS_AUTO_START}
Const NWPS_AUTO_START = 1;
{$DEFINE NWPS_USER_START}
Const NWPS_USER_START = 0;

(*==== For operator notification purposes, this means notify job owner =====*)

{$DEFINE NWPS_JOB_OWNER}
Const NWPS_JOB_OWNER = 1;

(*============================== Banner types ==============================*)

{$DEFINE NWPS_BANNER_TEXT}
Const NWPS_BANNER_TEXT = 0;
{$DEFINE NWPS_BANNER_POST}
Const NWPS_BANNER_POST = 1;

(*================ Flags for NWPSCfgGetPrinterDefaults: ====================*)

(* TC #define NWPS_DEFAULT ( nuint ) - 2  *)

(*============================ Printer Types ==============================*)

(* TC #define NWPS_P_ELSEWHERE ( nuint ) - 1  *)
{$DEFINE NWPS_P_OTHER}
Const NWPS_P_OTHER = 0;
{$DEFINE NWPS_P_PAR}
Const NWPS_P_PAR = 1;
{$DEFINE NWPS_P_SER}
Const NWPS_P_SER = 2;
{$DEFINE NWPS_P_XNP}
Const NWPS_P_XNP = 3;
{$DEFINE NWPS_P_APPLE}
Const NWPS_P_APPLE = 4;
{$DEFINE NWPS_P_UNIX}
Const NWPS_P_UNIX = 5;
{$DEFINE NWPS_P_AIO}
Const NWPS_P_AIO = 6;


{$DEFINE NWPS_PORT_1}
Const NWPS_PORT_1 = 0;
{$DEFINE NWPS_PORT_2}
Const NWPS_PORT_2 = 1;
{$DEFINE NWPS_PORT_3}
Const NWPS_PORT_3 = 2;
{$DEFINE NWPS_PORT_4}
Const NWPS_PORT_4 = 3;
{$DEFINE NWPS_PORT_5}
Const NWPS_PORT_5 = 4;
{$DEFINE NWPS_PORT_6}
Const NWPS_PORT_6 = 5;
{$DEFINE NWPS_PORT_7}
Const NWPS_PORT_7 = 6;
{$DEFINE NWPS_PORT_8}
Const NWPS_PORT_8 = 7;
{$DEFINE NWPS_PORT_9}
Const NWPS_PORT_9 = 8;
{$DEFINE NWPS_PORT_10}
Const NWPS_PORT_10 = 9;

(*=================== Possible Print Server status codes ===================*)

{$DEFINE NWPS_RUNNING}
Const NWPS_RUNNING = 0;
{$DEFINE NWPS_GOING_DOWN}
Const NWPS_GOING_DOWN = 1;
{$DEFINE NWPS_DOWN}
Const NWPS_DOWN = 2;
{$DEFINE NWPS_INITIALIZING}
Const NWPS_INITIALIZING = 3;

(*=================== Possible Printer status codes ========================*)

{$DEFINE NWPS_PSTAT_JOB_WAIT}
Const NWPS_PSTAT_JOB_WAIT = 0;
{$DEFINE NWPS_PSTAT_FORM_WAIT}
Const NWPS_PSTAT_FORM_WAIT = 1;
{$DEFINE NWPS_PSTAT_PRINTING}
Const NWPS_PSTAT_PRINTING = 2;
{$DEFINE NWPS_PSTAT_PAUSED}
Const NWPS_PSTAT_PAUSED = 3;
{$DEFINE NWPS_PSTAT_STOPPED}
Const NWPS_PSTAT_STOPPED = 4;
{$DEFINE NWPS_PSTAT_MARK_EJECT}
Const NWPS_PSTAT_MARK_EJECT = 5;
{$DEFINE NWPS_PSTAT_READY_TO_DOWN}
Const NWPS_PSTAT_READY_TO_DOWN = 6;
{$DEFINE NWPS_PSTAT_NOT_CONNECTED}
Const NWPS_PSTAT_NOT_CONNECTED = 7;
{$DEFINE NWPS_PSTAT_PRIVATE}
Const NWPS_PSTAT_PRIVATE = 8;
{$DEFINE NWPS_PSTAT_CONNECTING}
Const NWPS_PSTAT_CONNECTING = 9;

(*======================= Queue service modes ==============================*)

{$DEFINE NWPS_QUEUE_ONLY}
Const NWPS_QUEUE_ONLY = 0;
{$DEFINE NWPS_QUEUE_BEFORE_FORM}
Const NWPS_QUEUE_BEFORE_FORM = 1;
{$DEFINE NWPS_FORM_ONLY}
Const NWPS_FORM_ONLY = 2;
{$DEFINE NWPS_FORM_BEFORE_QUEUE}
Const NWPS_FORM_BEFORE_QUEUE = 3;



(*==================== Serial Port Baud Rates ==============================*)

{$DEFINE NWPS_BAUD_RATE_0300}
Const NWPS_BAUD_RATE_0300 = 0;
{$DEFINE NWPS_BAUD_RATE_0600}
Const NWPS_BAUD_RATE_0600 = 1;
{$DEFINE NWPS_BAUD_RATE_1200}
Const NWPS_BAUD_RATE_1200 = 2;
{$DEFINE NWPS_BAUD_RATE_2400}
Const NWPS_BAUD_RATE_2400 = 3;
{$DEFINE NWPS_BAUD_RATE_4800}
Const NWPS_BAUD_RATE_4800 = 4;
{$DEFINE NWPS_BAUD_RATE_9600}
Const NWPS_BAUD_RATE_9600 = 5;
{$DEFINE NWPS_BAUD_RATE_19200}
Const NWPS_BAUD_RATE_19200 = 6;
{$DEFINE NWPS_BAUD_RATE_38400}
Const NWPS_BAUD_RATE_38400 = 7;

(*==================== Serial Port Data Bits ===============================*)

{$DEFINE NWPS_DATA_BITS_5}
Const NWPS_DATA_BITS_5 = 5;
{$DEFINE NWPS_DATA_BITS_6}
Const NWPS_DATA_BITS_6 = 6;
{$DEFINE NWPS_DATA_BITS_7}
Const NWPS_DATA_BITS_7 = 7;
{$DEFINE NWPS_DATA_BITS_8}
Const NWPS_DATA_BITS_8 = 8;

(*==================== Serial Port Stop Bits ===============================*)

{$DEFINE NWPS_STOP_BITS_1}
Const NWPS_STOP_BITS_1 = 0;
{$DEFINE NWPS_STOP_BITS_1_5}
Const NWPS_STOP_BITS_1_5 = 1;
{$DEFINE NWPS_STOP_BITS_2}
Const NWPS_STOP_BITS_2 = 2;

(*==================== Serial Port Parity Type =============================*)

{$DEFINE NWPS_PARITY_NONE}
Const NWPS_PARITY_NONE = 0;
{$DEFINE NWPS_PARITY_EVEN}
Const NWPS_PARITY_EVEN = 1;
{$DEFINE NWPS_PARITY_ODD}
Const NWPS_PARITY_ODD = 2;

(****************************************************************)

(* Values for AIO Port control as stored in configuration files *)

(****************************************************************)


(*================= Default hardware, board, or port =======================*)

(* TC #define NWPS_AIO_WILDCARD ( - 1 )  *)

(*======================= AIO Port Hardware Types ==========================*)

(* reserved                            0			*)

{$DEFINE NWPS_AIO_COMX_TYPE}
Const NWPS_AIO_COMX_TYPE = 1;
{$DEFINE NWPS_AIO_ARTIC_TYPE}
Const NWPS_AIO_ARTIC_TYPE = 2;
{$DEFINE NWPS_AIO_WNIM_TYPE}
Const NWPS_AIO_WNIM_TYPE = 3;
(* reserved                            4 - 99	*)

(* unused										100		*)

{$DEFINE NWPS_AIO_AVMB1_TYPE}
Const NWPS_AIO_AVMB1_TYPE = 101;
{$DEFINE NWPS_AIO_ANIC_TYPE}
Const NWPS_AIO_ANIC_TYPE = 102;
{$DEFINE NWPS_AIO_WNIC_TYPE}
Const NWPS_AIO_WNIC_TYPE = 103;
{$DEFINE NWPS_AIO_HAYES_TYPE}
Const NWPS_AIO_HAYES_TYPE = 104;
{$DEFINE NWPS_AIO_DIGIXI_TYPE}
Const NWPS_AIO_DIGIXI_TYPE = 105;
{$DEFINE NWPS_AIO_DIGICX_TYPE}
Const NWPS_AIO_DIGICX_TYPE = 106;
{$DEFINE NWPS_AIO_DIGIXM_TYPE}
Const NWPS_AIO_DIGIXM_TYPE = 107;
{$DEFINE NWPS_AIO_DIGIEP_TYPE}
Const NWPS_AIO_DIGIEP_TYPE = 108;
{$DEFINE NWPS_AIO_NPCC_TYPE}
Const NWPS_AIO_NPCC_TYPE = 109;
(* unused										110-		*)


(*========================= AIO Port Baud Rates ============================*)

{$DEFINE NWPS_AIO_BAUD_50}
Const NWPS_AIO_BAUD_50 = 0;
{$DEFINE NWPS_AIO_BAUD_75}
Const NWPS_AIO_BAUD_75 = 1;
{$DEFINE NWPS_AIO_BAUD_110}
Const NWPS_AIO_BAUD_110 = 2;
{$DEFINE NWPS_AIO_BAUD_134p5}
Const NWPS_AIO_BAUD_134p5 = 3;
{$DEFINE NWPS_AIO_BAUD_150}
Const NWPS_AIO_BAUD_150 = 4;
{$DEFINE NWPS_AIO_BAUD_300}
Const NWPS_AIO_BAUD_300 = 5;
{$DEFINE NWPS_AIO_BAUD_600}
Const NWPS_AIO_BAUD_600 = 6;
{$DEFINE NWPS_AIO_BAUD_1200}
Const NWPS_AIO_BAUD_1200 = 7;
{$DEFINE NWPS_AIO_BAUD_1800}
Const NWPS_AIO_BAUD_1800 = 8;
{$DEFINE NWPS_AIO_BAUD_2000}
Const NWPS_AIO_BAUD_2000 = 9;
{$DEFINE NWPS_AIO_BAUD_2400}
Const NWPS_AIO_BAUD_2400 = 10;
{$DEFINE NWPS_AIO_BAUD_3600}
Const NWPS_AIO_BAUD_3600 = 11;
{$DEFINE NWPS_AIO_BAUD_4800}
Const NWPS_AIO_BAUD_4800 = 12;
{$DEFINE NWPS_AIO_BAUD_7200}
Const NWPS_AIO_BAUD_7200 = 13;
{$DEFINE NWPS_AIO_BAUD_9600}
Const NWPS_AIO_BAUD_9600 = 14;
{$DEFINE NWPS_AIO_BAUD_19200}
Const NWPS_AIO_BAUD_19200 = 15;
{$DEFINE NWPS_AIO_BAUD_38400}
Const NWPS_AIO_BAUD_38400 = 16;
{$DEFINE NWPS_AIO_BAUD_57600}
Const NWPS_AIO_BAUD_57600 = 17;
{$DEFINE NWPS_AIO_BAUD_115200}
Const NWPS_AIO_BAUD_115200 = 18;

(*====================== AIO Port Data Bits ================================*)

{$DEFINE NWPS_AIO_DATA_BITS_5}
Const NWPS_AIO_DATA_BITS_5 = 0;
{$DEFINE NWPS_AIO_DATA_BITS_6}
Const NWPS_AIO_DATA_BITS_6 = 1;
{$DEFINE NWPS_AIO_DATA_BITS_7}
Const NWPS_AIO_DATA_BITS_7 = 2;
{$DEFINE NWPS_AIO_DATA_BITS_8}
Const NWPS_AIO_DATA_BITS_8 = 3;

(*====================== AIO Port Stop Bits ================================*)

{$DEFINE NWPS_AIO_STOP_BITS_1}
Const NWPS_AIO_STOP_BITS_1 = 0;
{$DEFINE NWPS_AIO_STOP_BITS_1p5}
Const NWPS_AIO_STOP_BITS_1p5 = 1;
{$DEFINE NWPS_AIO_STOP_BITS_2}
Const NWPS_AIO_STOP_BITS_2 = 2;

(*====================== AIO Port Parity Type ==============================*)

{$DEFINE NWPS_AIO_PARITY_NONE}
Const NWPS_AIO_PARITY_NONE = 0;
{$DEFINE NWPS_AIO_PARITY_ODD}
Const NWPS_AIO_PARITY_ODD = 1;
{$DEFINE NWPS_AIO_PARITY_EVEN}
Const NWPS_AIO_PARITY_EVEN = 2;
{$DEFINE NWPS_AIO_PARITY_MARK}
Const NWPS_AIO_PARITY_MARK = 3;
{$DEFINE NWPS_AIO_PARITY_SPACE}
Const NWPS_AIO_PARITY_SPACE = 4;

(*================== Possible types of print servers =======================*)

{$DEFINE NWPS_TYPE_UNKNOWN}
Const NWPS_TYPE_UNKNOWN = 0;
{$DEFINE NWPS_TYPE_EXE}
Const NWPS_TYPE_EXE = 1;
{$DEFINE NWPS_TYPE_NLM}
Const NWPS_TYPE_NLM = 2;
{$DEFINE NWPS_TYPE_SERVER_VAP}
Const NWPS_TYPE_SERVER_VAP = 3;
{$DEFINE NWPS_TYPE_BRIDGE_VAP}
Const NWPS_TYPE_BRIDGE_VAP = 4;
{$DEFINE NWPS_TYPE_UNIX}
Const NWPS_TYPE_UNIX = 5;

(***************************************************************)

(* Printer configuration structures which make up NWPS_PConfig *)

(***************************************************************)

(*=================== Serial Printer Config Info ===========================*)

Type
    NWPS_Serial_t = Record
        portNumber  :   nuint16 ;
        startFlag  :   nuint16 ;
        (* FALSE - User will start printer	*)
        useInterrupts  :   nuint16 ;
        irqNumber  :   nuint16 ;
        useXonXoff  :   nuint16 ;
        baudRate  :   nuint16 ;
        dataBits  :   nuint16 ;
        stopBits  :   nuint16 ;
        parity  :   nuint16 ;
    End;
    NWPS_Serial = NWPS_Serial_t;


(*=================== Parallel Printer Config Info =========================*)

Type
    NWPS_Parallel_t = Record
        portNumber  :   nuint16 ;
        startFlag  :   nuint16 ;
        (* FALSE - User will start printer	*)
        useInterrupts  :   nuint16 ;
        irqNumber  :   nuint16 ;
    End;
    NWPS_Parallel = NWPS_Parallel_t;


(*=================== AIO Printer Config Info ==============================*)

Type
    NWPS_Aio_t = Record
        reserved1  :   nuint16 ;
        startFlag  :   nuint16 ;
        (* FALSE - User will start printer	*)
        hardwareType  :   nuint16 ;
        boardNumber  :   nuint8 ;
        portNumber  :   nuint8 ;
        useXonXoff  :   nuint8 ;
        aioMgr  :   nuint8 ;
        baudRate  :   nuint16 ;
        dataBits  :   nuint16 ;
        stopBits  :   nuint16 ;
        parity  :   nuint16 ;
    End;
    NWPS_Aio = NWPS_Aio_t;


(*=================== AppleTalk Printer Config Info ========================*)

Type
    NWPS_AppleTalk_t = Record
        netPrinterName  :  Array[0..NWPS_APPLE_NAME_SIZE+2-1] Of nint8;
        (* AppleTalk Network Printer Name *)
        netPrinterType  :  Array[0..NWPS_APPLE_TYPE_SIZE+2-1] Of nint8;
        (* AppleTalk Network Printer Type *)
        netPrinterZone  :  Array[0..NWPS_APPLE_ZONE_SIZE+2-1] Of nint8;
        (* AppleTalk Network Printer Zone *)
        hideFlag  :   nuint16 ;
        errorFlag  :   nuint16 ;
    End;
    NWPS_AppleTalk = NWPS_AppleTalk_t;


(*=================== Unix Printer Config Info =============================*)

Type
    NWPS_Unix_t = Record
        hostName  :  Array[0..NWPS_UNIX_HOST_SIZE+1-1] Of nint8;
        (* Name of the unix host  *)
        hostPrinter  :  Array[0..NWPS_UNIX_PRNT_SIZE+1-1] Of nint8;
        (* Unix printer name  *)
    End;
    NWPS_Unix = NWPS_Unix_t;


Type
    NWPS_PConfig = Record
        printerType  :   nuint16 ;
        currentForm  :   nuint16 ;
        bufferSize  :   nuint16 ;
        serviceMode  :   nuint16 ;
        pollTime  :   nuint16 ;
        bannerType  :   nuint16 ;
        (* TRUE - postscript banner page*)
        length  :   nuint32 ;
        driverName  :  Array[0..8] Of nint8;
        reserved_for_future  :  Array[0..22] Of nint8;
        ser  :   NWPS_Serial ;  (* union statement *)
    End;



Type
    NWPS_Typed_Name = Record
        objectType  :   nuint16 ;
        tName  :   nptr ;
    End;



(*==========================================================================
  The following types are used for the listed attribute:
  - NWPS_Typed_Name (name field is a char*RB Operator, Owner, User
  - NWPS_Typed_Name (name field is a Typed_Name_T*RB Notify
  - Typed_Name_T used for Queue, Printer and Print Server attr. values
  - Octet_String_T used for Printer Configuration attr. value
  - Net_Address_T used for Network Address and Restriction attr. values
  These attributes are defined in the directory services header:
	 nwdsattr.h
  ==========================================================================*)


(*============ internal table of known attribute names =====================*)

(* TC  pnstr8 pnstr8 _attrName [ ];  *)


{$IFDEF  NWPS_CONN_TYPE }
    {$IFDEF NWPS_CONN_TYPE==NWPS_BINDERY_SERVICE}
        {$I nwpscfg0.inc}
    {$ELSE}  {$IFDEF NWPS_CONN_TYPE==NWPS_DIRECTORY_SERVICE}
        {$I nwpscfg1.inc}
    {$ELSE}  {$IFDEF NWPS_CONN_TYPE==NWPS_BINDERY_SERVICE_PRE_40}
        {$I nwpscfg0.inc}
    {$ELSE}  {$IFDEF NWPS_CONN_TYPE==NWPS_BINDERY_SERVICE_ALL}
        {$I nwpscfg0.inc}
    {$ENDIF}
    {$ENDIF}
    {$ENDIF}
    {$ENDIF}
{$ELSE}
    {$I nwpscfgx.inc}
{$ENDIF}


{$ENDIF}


