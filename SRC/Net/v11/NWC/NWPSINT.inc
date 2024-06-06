(*
//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
//บ Copyright (c) Unpublished Work of Novell, Inc.  All rights reserved.	  บ
//บ																								  บ
//บ THIS WORK IS AN UNPUBLISHED WORK AND CONTAINS CONFIDENTIAL, PROPRIETARY  บ
//บ AND TRADE SECRET INFORMATION OF NOVELL, INC.									  บ
//บ																								  บ
//บ ACCESS TO THIS WORK IS RESTRICTED TO (I) NOVELL EMPLOYEES WHO HAVE A	  บ
//บ NEED TO KNOW HOW TO PERFORM TASKS WITHIN THE SCOPE OF THEIR ASSIGNMENTS  บ
//บ AND (II) ENTITIES OTHER THAN NOVELL, INC. WHO HAVE ENTERED INTO			  บ
//บ APPROPRIATE LICENSE AGREEMENTS.                                          บ
//บ																								  บ
//บ NO PART OF THIS WORK MAY BE USED, PRACTICED, PERFORMED, COPIED,			  บ
//บ DISTRIBUTED, REVISED, MODIFIED, TRANSLATED, ABRIDGED, CONDENSED,         บ
//บ EXPANDED, COLLECTED, COMPILED, LINKED, RECAST, TRANSFORMED OR ADAPTED	  บ
//บ WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC.                        บ
//บ																								  บ
//บ ANY USE OR EXPLOITATION OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT บ
//บ THE PERPETRATOR TO CRIMINAL AND CIVIL LIABILITY.								  บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Source module name: NWPSINT.H														  บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)


(*
//   The version of the databases for which the API's work is 4.0.
//   The following definitions are for the Names and Locations of
//   the Bindery files used for the databases.
*)


(*****************************)

(* PrintDef file information *)

(*****************************)


{$DEFINE PDF_LIBRARY_VERSION}
Const PDF_LIBRARY_VERSION = 40;

(*=============================*)

(* Bindery names and locations *)

(*=============================*)

{$IFDEF NWNLM}

{$DEFINE PDF_FILE_NAME}
Const PDF_FILE_NAME = '%s\\SYS:PUBLIC\\PRINTDEF.DAT';
{$DEFINE PDF_FILE_NAME_PRE_40}
Const PDF_FILE_NAME_PRE_40 = '%s\\SYS:PUBLIC\\NET$PRN.DAT';
{$DEFINE PDF_SHORT_FILE_NAME}
Const PDF_SHORT_FILE_NAME = 'SYS:PUBLIC\\PRINTDEF.DAT';
{$DEFINE PDF_SHORT_FILE_NAME_PRE_40}
Const PDF_SHORT_FILE_NAME_PRE_40 = 'SYS:PUBLIC\\NET$PRN.DAT';
{$ELSE}

{$DEFINE PDF_FILE_NAME}
Const PDF_FILE_NAME = '\\\\%s\\SYS\\PUBLIC\\PRINTDEF.DAT';
{$DEFINE PDF_FILE_NAME_PRE_40}
Const PDF_FILE_NAME_PRE_40 = '\\\\%s\\SYS\\PUBLIC\\NET$PRN.DAT';
{$DEFINE PDF_SHORT_FILE_NAME}
Const PDF_SHORT_FILE_NAME = 'SYS:PUBLIC\\PRINTDEF.DAT';
{$DEFINE PDF_SHORT_FILE_NAME_PRE_40}
Const PDF_SHORT_FILE_NAME_PRE_40 = 'SYS:PUBLIC\\NET$PRN.DAT';
{$ENDIF}


(*****************************)

(* PrintCon file information *)

(*****************************)

{$DEFINE JOB_MAJOR_VERSION}
Const JOB_MAJOR_VERSION = nuint8(4);
{$DEFINE JOB_MINOR_VERSION}
Const JOB_MINOR_VERSION = nuint8(1);

{$DEFINE JOB_MAJOR_VERSION_PRE_40}
Const JOB_MAJOR_VERSION_PRE_40 = nuint8(1);
{$DEFINE JOB_MINOR_VERSION_PRE_40}
Const JOB_MINOR_VERSION_PRE_40 = nuint8(1);

(*=============================*)

(* Bindery names and locations *)

(*=============================*)

{$DEFINE JOB_DB_NAME}
Const JOB_DB_NAME = 'PRINTJOB.DAT';
{$DEFINE JOB_BACKUP_NAME}
Const JOB_BACKUP_NAME = 'PRINTJOB.CPY';
{$DEFINE JOB_RENAME_NAME}
Const JOB_RENAME_NAME = 'PRINTJOB.REN';

{$DEFINE JOB_DB_NAME_PRE_40}
Const JOB_DB_NAME_PRE_40 = 'PRINTCON.DAT';
{$DEFINE JOB_BACKUP_NAME_PRE_40}
Const JOB_BACKUP_NAME_PRE_40 = 'PRINTCON.CPY';
{$DEFINE JOB_RENAME_NAME_PRE_40}
Const JOB_RENAME_NAME_PRE_40 = 'PRINTCON.REN';

(*=============================*)

(* Server/sys:Public/file_name *)

(*=============================*)

{$IFDEF NWNLM}

{$DEFINE JOB_PUBLIC_PATH}
Const JOB_PUBLIC_PATH = '%s\\SYS:PUBLIC\\%s';
{$ELSE}

{$DEFINE JOB_PUBLIC_PATH}
Const JOB_PUBLIC_PATH = '\\\\%s\\SYS\\PUBLIC\\%s';
{$ENDIF}


(*===================================*)

(* Server/sys:Mail/User_id/file_name *)

(*===================================*)

{$IFDEF NWNLM}

{$DEFINE JOB_PRIVATE_PATH}
Const JOB_PRIVATE_PATH = '%s\\SYS:MAIL\\%lX\\%s';
{$ELSE}

{$DEFINE JOB_PRIVATE_PATH}
Const JOB_PRIVATE_PATH = '\\\\%s\\SYS\\MAIL\\%lX\\%s';
{$ENDIF}


(*==============================*)

(* Strings used only internally *)

(*==============================*)

{$DEFINE NWPS_DEVICE_NONE_PRE_40}
Const NWPS_DEVICE_NONE_PRE_40 = '(None)';
{$DEFINE NWPS_MODE_NONE_PRE_40}
Const NWPS_MODE_NONE_PRE_40 = '(None)';

(*=======================*)

(* File handle pseudonym *)

(*=======================*)

{$IFDEF NWNLM}

Type NWPS_FILE_HANDLE = int;
{$ELSE}

Type NWPS_FILE_HANDLE = int;
{$ENDIF}


(***********************************************)

(* Print Server Configuration file information *)

(***********************************************)

{$IFDEF NWNLM}

{$DEFINE CFG_PSERVER_DIRECTORY}
Const CFG_PSERVER_DIRECTORY = '%s\\SYS:SYSTEM\\%08lX';
{$DEFINE CFG_FILESERV_FILE}
Const CFG_FILESERV_FILE = '%s\\SYS:SYSTEM\\%08lX\\FILESERV';
{$DEFINE CFG_DESCRIPT_FILE}
Const CFG_DESCRIPT_FILE = '%s\\SYS:SYSTEM\\%08lX\\DESCRIPT';
{$DEFINE CFG_PRINT_FILE}
Const CFG_PRINT_FILE = '%s\\SYS:SYSTEM\\%08lX\\PRINT.%03d';
{$DEFINE CFG_PRINT_INDEX}
Const CFG_PRINT_INDEX = '%s\\SYS:SYSTEM\\%08lX\\PRINT.IDX';
{$DEFINE CFG_QUEUE_FILE}
Const CFG_QUEUE_FILE = '%s\\SYS:SYSTEM\\%08lX\\QUEUE.%03d';
{$DEFINE CFG_NOTIFY_FILE}
Const CFG_NOTIFY_FILE = '%s\\SYS:SYSTEM\\%08lX\\NOTIFY.%03d';
{$ELSE}

{$DEFINE CFG_PSERVER_DIRECTORY}
Const CFG_PSERVER_DIRECTORY = '\\\\%s\\SYS\\SYSTEM\\%08lX';
{$DEFINE CFG_FILESERV_FILE}
Const CFG_FILESERV_FILE = '\\\\%s\\SYS\\SYSTEM\\%08lX\\FILESERV';
{$DEFINE CFG_DESCRIPT_FILE}
Const CFG_DESCRIPT_FILE = '\\\\%s\\SYS\\SYSTEM\\%08lX\\DESCRIPT';
{$DEFINE CFG_PRINT_FILE}
Const CFG_PRINT_FILE = '\\\\%s\\SYS\\SYSTEM\\%08lX\\PRINT.%03d';
{$DEFINE CFG_PRINT_INDEX}
Const CFG_PRINT_INDEX = '\\\\%s\\SYS\\SYSTEM\\%08lX\\PRINT.IDX';
{$DEFINE CFG_QUEUE_FILE}
Const CFG_QUEUE_FILE = '\\\\%s\\SYS\\SYSTEM\\%08lX\\QUEUE.%03d';
{$DEFINE CFG_NOTIFY_FILE}
Const CFG_NOTIFY_FILE = '\\\\%s\\SYS\\SYSTEM\\%08lX\\NOTIFY.%03d';
{$ENDIF}



(*
//  these types are for 3.11 backward compatibilty only 
*)

{$DEFINE NWPS_P_PAR_1}
Const NWPS_P_PAR_1 = 0;
{$DEFINE NWPS_P_PAR_2}
Const NWPS_P_PAR_2 = 1;
{$DEFINE NWPS_P_PAR_3}
Const NWPS_P_PAR_3 = 2;
{$DEFINE NWPS_P_SER_1}
Const NWPS_P_SER_1 = 3;
{$DEFINE NWPS_P_SER_2}
Const NWPS_P_SER_2 = 4;
{$DEFINE NWPS_P_SER_3}
Const NWPS_P_SER_3 = 5;
{$DEFINE NWPS_P_SER_4}
Const NWPS_P_SER_4 = 6;
{$DEFINE NWPS_P_REM_PAR_1}
Const NWPS_P_REM_PAR_1 = 7;
{$DEFINE NWPS_P_REM_PAR_2}
Const NWPS_P_REM_PAR_2 = 8;
{$DEFINE NWPS_P_REM_PAR_3}
Const NWPS_P_REM_PAR_3 = 9;
{$DEFINE NWPS_P_REM_SER_1}
Const NWPS_P_REM_SER_1 = 10;
{$DEFINE NWPS_P_REM_SER_2}
Const NWPS_P_REM_SER_2 = 11;
{$DEFINE NWPS_P_REM_SER_3}
Const NWPS_P_REM_SER_3 = 12;
{$DEFINE NWPS_P_REM_SER_4}
Const NWPS_P_REM_SER_4 = 13;
{$DEFINE NWPS_P_REM_OTHER_1}
Const NWPS_P_REM_OTHER_1 = 14;
{$DEFINE NWPS_P_ELSEWHERE_1}
Const NWPS_P_ELSEWHERE_1 = 15;
{$DEFINE NWPS_P_XNP_1}
Const NWPS_P_XNP_1 = 16;
{$DEFINE NWPS_P_LOC_AIO}
Const NWPS_P_LOC_AIO = 17;
{$DEFINE NWPS_P_REM_AIO}
Const NWPS_P_REM_AIO = 18;

{$DEFINE NWPS_P_APPLE_1}
Const NWPS_P_APPLE_1 = 100;
{$DEFINE NWPS_P_UNIX_1}
Const NWPS_P_UNIX_1 = 200;

(*********************************************************************)


(*
//  printer's Queue Configuration File structure 
*)

Type
    QUEUE = Record
        name  :  Array[0..47] Of nint8;
        priority  :   nuint8 ;
    End;


(*
//  printer's Notify Configuration File structure 
*)

Type
    NOTIFY = Record
        name  :  Array[0..47] Of nint8;
        type1  :   nuint16 ;
        first  :   nuint16 ;
        next  :   nuint16 ;
    End;


(*
//  printer's Configuration File structure 
*)

Type
    PCONFIG = Record
        name  :  Array[0..47] Of nint8;
        printerSubtype  :   nuint16 ;
        useInterrupts  :   nuint16 ;
        irqNumber  :   nuint16 ;
        serviceMode  :   nuint16 ;
        bufferSize  :   nuint16 ;
        baudRate  :   nuint16 ;
        dataBits  :   nuint16 ;
        stopBits  :   nuint16 ;
        parity  :   nuint16 ;
        useXonXoff  :   nuint16 ;
        currentForm  :   nuint16 ;
        (* Version 1.00 stops here *)
        bannerType  :   nuint16 ;
        pollTime  :   nuint16 ;
        station  :  Array[0..9] Of  nuint8 ;
        driverName  :  Array[0..8] Of  nuint8 ;
        yetToBeDesigned  :  Array[0..30] Of  nuint8 ;
        (*			.										such as network printer station *)
        (*			.										restrictions, etc.  The exact   *)
        (*			.										format hasn't been decided yet. *)
        bufferLen  :   nuint32 ;
        buffer  :  Array[0..1023] Of  nuint8 ;
        (*													store their individual info	*)
    End;


{$DEFINE PCONFIG_V100_SIZE}
Const PCONFIG_V100_SIZE = 70;
(* TC #define PCONFIG_V200_SIZE sizeof ( PCONFIG )  *)


(*
//   NWPS_Job_Old_Db_Hdr is the first record in the 4.0 PrnConDB database.
//   It contains the following information about the database:
//     The version number,
//     the number of NWPS_Job_Rec records in PrnConDB,
//     the name of the default print job configuration and
//     the name of the job record owner.
*)

Type
    NWPS_Job_Old_Db_Hdr = Record
        text  :  Array[0..75] Of nint8;
        defaultPJName  :  Array[0..31] Of nint8;
        defaultPJOwner  :  Array[0..255] Of nint8;
        numOfRecords  :   nuint16 ;
        numOfBlocks  :   nuint16 ;
        majorVersion  :   nuint8 ;
        minorVersion  :   nuint8 ;
    End;


(*
//   NWPS_Job_41_Db_Hdr is the first record in the 4.1 PrnConDB database.
//   It contains the following information about the database:
//     The version number,
//     the number of NWPS_Job_Rec records in PrnConDB,
//     the name of the default print job configuration and
//     the name of the job record owner IN UNICODE.
*)

Type
    NWPS_Job_41_Db_Hdr = Record
        text  :  Array[0..75] Of nint8;
        defaultPJName  :  Array[0..31] Of nint8;
        unused  :  Array[0..255] Of nint8;
        numOfRecords  :   nuint16 ;
        numOfBlocks  :   nuint16 ;
        majorVersion  :   nuint8 ;
        minorVersion  :   nuint8 ;
        pJDBOwner  :  Array[0..255] Of  nuint16 ;
    End;


(*
//   NWPS_Job_Name_Rec is the type of record found in the
//   second section of the PrnConDB database.  Each one of
//   these records contains the name of each NWPS_Job_Rec
//   and a pointer to their location in the third section of
//   the database.  There is space set aside in this second
//   section for fifty NWPS_Job_Name_Rec records; if this
//   limit is exceeded then another fifty-record block following
//   the first one is allocated after the third section of the
//   database is moved down to make room for the expansion.
*)

Type
    NWPS_Job_Name_Rec = Record
        printJobName  :  Array[0..NWPS_JOB_NAME_SIZE-1] Of nint8;
        offset  :   nuint32 ;
    End;


(*
// The following structures define the Pre-4.0 PrintCon Database
*)


{$DEFINE NWPS_JOB_IDX_ELEMENTS}
Const NWPS_JOB_IDX_ELEMENTS = 37;

Type
    NWPS_Job_Pre40_Db_Hdr = Record
        header  :  Array[0..54] Of nint8;
        filler  :  Array[0..1] Of nint8;
        copyright  :  Array[0..54] Of nint8;
        filler1  :  Array[0..2] Of nint8;
        fileTag  :   nuint8 ;
        majorVersion  :   nuint8 ;
        minorVersion  :   nuint8 ;
        defaultPJName  :  Array[0..NWPS_JOB_NAME_SIZE-1] Of nint8;
    End;


(*
// The offset field for NWPS_Job_Name_Rec is absolute from the beginning
// of the file for this database.
*)

Type
    NWPS_Job_Pre40_Idx = Record
        node  :  Array[0..NWPS_JOB_IDX_ELEMENTS-1] Of  NWPS_Job_Name_Rec ;
    End;


Type
    NWPS_Job_Pre40_Rec = Record
        targetServer  :  Array[0..47] Of nint8;
        targetQueue  :  Array[0..47] Of nint8;
        tabSize  :   nuint8 ;
        numberOfCopies  :   nuint16 ;
        formName  :  Array[0..12] Of nint8;
        reserve  :  Array[0..26] Of  nuint8 ;
        notifyUserFlag  :   nuint8 ;
        printServerID  :   nuint32 ;
        bannerNameField  :  Array[0..12] Of nint8;
        bannerFileField  :  Array[0..12] Of nint8;
        deviceName  :  Array[0..32] Of nint8;
        modeName  :  Array[0..32] Of nint8;
        bannerFlag  :   nuint8 ;
        bytestreamFlag  :   nuint8 ;
        formfeedFlag  :   nuint8 ;
        timeOut  :   nuint16 ;
        localPrinter  :   nuint8 ;
        autoEndspool  :   nuint8 ;
    End;


(*
// This routine hashes strings for use in searching the databases for 3.11
// stuff.
*)

(* Not implemented Function _NWPSHashFunction (
    string1  :   pnstr8 ;
    hashTableSize  :  nint32
) : nint32;
{$IFDEF N_ARCH_32}
cdecl;
{$ENDIF}  *)


(*
// This is the table used by the 3.11 Hash Function for translation
*)

(* TC  char char _NWPShashTranslateTable [ 256 ];  *)


(*
// NLMs need to know what this struct looks like here, but everyone 
// in the PRINTDEF code needs this.
*)

Type
    Pdf_Hash_Record = Record
        offset  :   nuint32 ;
        length  :   nuint8 ;
    End;
    NWPS_Pdf_Hash_Record = Pdf_Hash_Record;


Type
    EngineInfo = Record
        recName  :  Array[0..32] Of nint8;
        wantUpperCaseRecName  :  Array[0..32] Of nint8;
        upperCaseRecName  :  Array[0..32] Of nint8;
        recNameLen  :   nuint16 ;
        devNameLen  :   nuint16 ;
        tempWord  :   nuint16 ;
        entryOffset  :   nuint32 ;
        deviOffset  :   nuint32 ;
        modeOffset  :   nuint32 ;
        funcOffset  :   nuint32 ;
        tempOffset  :   nuint32 ;
        maxEntries  :   nuint32 ;
        pdfScanIndex  :   nuint32 ;
        modeNumber  :   nuint16 ;
        funcNumber  :   nuint16 ;
        index  :   nuint16 ;
        index2  :   nuint16 ;
        hashTable  :  ^NWPS_Pdf_Hash_Record;
        (*
	// bit array for used form numbers 
	*)
        usedForms  :  Array[0..7] Of  nuint8 ;
        formNumber  :   nuint16 ;
        formWidth  :   nuint16 ;
        formLength  :   nuint16 ;
        funcSize  :   nuint16 ;
        bytesSkipped  :   nuint16 ;
        bufferedBytes  :   nuint16 ;
        readSize  :   nuint16 ;
        (*
	// version variable 
	*)
        version  :   nuint32 ;
        (*
	// add option variables 
	*)
        recSize  :   nuint32 ;
        recOffset  :   nuint32 ;
        indexList  :  ^nuint16;
        pre40IndexList  :  ^nuint32;
        (*
	// delete option variables 
	*)
        offsetList  :  ^nuint32;
        (*
	// Modify option variables 
	*)
        newRecSize  :   nuint32 ;
        newNameLen  :   nuint16 ;
    End;
    EngineInfo_T = EngineInfo;


{$IFDEF NWNLM}

(*
// NWPSGetThreadDataAreaPtr returns the pointer to data needed by
// the NLM versions of the calls.
*)

Type
    NWPS_Malloc_Struct = Record
        next  :  ^NWPS_Malloc_Struct;
        size  :   nuint32 ;
    End;


Type
    NWPSLibraryThreadDataStruct = Record
        next  :  ^NWPSLibraryThreadDataStruct;
        (*
		// Owner Thread Identification
		*)
        threadID  :  nint32;
        (*
		// psnlmmalloc needs the following three fields 
		*)
        clientMemory  :  ^NWPS_Malloc_Struct;
        maxMemAllocation  :   nuint32 ;
        curMemAllocation  :   nuint32 ;
        (*
		// pdf calls need the next three fields		 
		*)
        pdfDatabaseFileDontClose  :  nint32;
        pdfDatabaseFileHandle  :   NWPS_FILE_HANDLE ;
        pdfDatabaseEngineInfo  :   EngineInfo_T ;
        (*
		// cominit needs the following field
		*)
        IPXSocketRTag  :  nint32;
        comListHead  :  ^variant;
        comSemaphoreHdl  :  nint32;
    End;


(* Not implemented Function NWPSGetThreadDataAreaPtr (
    Var threadDataAreaPtr  : NWPSLibraryThreadDataStruct
) : NWCCODE;
{$IFDEF N_ARCH_32}
cdecl;
{$ENDIF}  *)

{$ENDIF}


(*********************************************************************)


(*
//   PrintDef File Structure
//   Header:
//     nuint32 Version Number
//     nuint32 File Size
//     nuint32 Form DataBase Offset
//     nuint32 Device DataBase Offset
//     nuint32 (future offsets)
//     .
//     .
//     .
// 
//   Form DataBase:
//     nuint32 Record Count
//     nuint32 Record Offsets[ count ]
//   Form Records:
//     nuint16    Form Number
//     nuint16    Form Width
//     nuint16    Form Length
//     nuint16    Name Size (including '\0')
//     char    Form Name[Name Size]
//     * padded to the nearest nuint32 *
// 
//   Device DataBase:
//     nuint32 Record Count
//     nuint32 Record Offsets[ count ]
//   Device Records:
//     nuint16    Mode Count
//     nuint16    Function Count
//     nuint16    Name Size (including '\0')
//     nuint32 Mode Offsets[Mode Count]
//     nuint32 Function Offsets[Function Count]
//     char    Device Name[Name Size]
//     * padded to the nearest nuint32 *
//     Mode Records:
//       nuint16	  Function Count
//       nuint16	  Name Size (including '\0')
//       nuint16	  Function Index[Function Count]
//       char	  Mode Name[Name Size]
//       * padded to the nearest nuint32 *
//     Function Records:
//       nuint16	  Function Size
//       nuint16	  Name Size (including '\0')
//       nuint8	  Function String[Function Size]
//       char	  Function Name[Name Size]
//       * padded to the nearest nuint32 *
*)


(*********************************************************************)

(*
//   Print server request codes
*)


(*
//  general commands 
*)

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
{$DEFINE CMD_REWIND_JOB_WITH_ID}
Const CMD_REWIND_JOB_WITH_ID = $1B;
{$DEFINE CMD_ABORT_JOB_WITH_ID}
Const CMD_ABORT_JOB_WITH_ID = $1C;
{$DEFINE CMD_ADD_FORM}
Const CMD_ADD_FORM = $1D;
{$DEFINE CMD_DISMOUNT_FORM}
Const CMD_DISMOUNT_FORM = $1E;
{$DEFINE CMD_GET_EXT_PRINTER_STATUS}
Const CMD_GET_EXT_PRINTER_STATUS = $1F;
{$DEFINE CMD_GET_EXT_JOB_STATUS}
Const CMD_GET_EXT_JOB_STATUS = $20;

(*
//  NPrinter commands 
*)

{$DEFINE CMD_GET_RPRINTER}
Const CMD_GET_RPRINTER = $80;
{$DEFINE CMD_CONNECT_RPRINTER}
Const CMD_CONNECT_RPRINTER = $81;
{$DEFINE CMD_SET_REMOTE_MODE}
Const CMD_SET_REMOTE_MODE = $82;
{$DEFINE CMD_SCAN_RPRINTER}
Const CMD_SCAN_RPRINTER = $84;

(*
//  Directory Service commands 
*)

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

(*
//  XNP Printer commands 
*)

{$DEFINE XNP_ACCEPT_JOB}
Const XNP_ACCEPT_JOB = $00;
{$DEFINE XNP_CLOSE_FILE}
Const XNP_CLOSE_FILE = $01;
{$DEFINE XNP_CREATE_BANNER}
Const XNP_CREATE_BANNER = $02;
{$DEFINE XNP_DECLINE_JOB}
Const XNP_DECLINE_JOB = $03;
{$DEFINE XNP_DEREGISTER}
Const XNP_DEREGISTER = $04;
{$DEFINE XNP_FINISH_JOB}
Const XNP_FINISH_JOB = $05;
{$DEFINE XNP_GET_CONFIG}
Const XNP_GET_CONFIG = $06;
{$DEFINE XNP_OPEN_FILE}
Const XNP_OPEN_FILE = $07;
{$DEFINE XNP_READ_FILE}
Const XNP_READ_FILE = $08;
{$DEFINE XNP_REGISTER}
Const XNP_REGISTER = $09;
{$DEFINE XNP_SEEK_FILE}
Const XNP_SEEK_FILE = $0A;
{$DEFINE XNP_SEND_STATUS}
Const XNP_SEND_STATUS = $0B;
{$DEFINE XNP_WRITE_FILE}
Const XNP_WRITE_FILE = $0C;

(*
//  XNP PServer commands 
*)

{$DEFINE XNP_ABORT_JOB}
Const XNP_ABORT_JOB = $80;
{$DEFINE XNP_GOING_DOWN}
Const XNP_GOING_DOWN = $81;
{$DEFINE XNP_JOB_STATUS}
Const XNP_JOB_STATUS = $82;
{$DEFINE XNP_NEW_JOB}
Const XNP_NEW_JOB = $83;
{$DEFINE XNP_PAUSE_JOB}
Const XNP_PAUSE_JOB = $84;
{$DEFINE XNP_PAUSE_PRINTER}
Const XNP_PAUSE_PRINTER = $85;
{$DEFINE XNP_RECONFIGURE}
Const XNP_RECONFIGURE = $86;
{$DEFINE XNP_REWIND_JOB}
Const XNP_REWIND_JOB = $87;
{$DEFINE XNP_START_JOB}
Const XNP_START_JOB = $88;
{$DEFINE XNP_START_PRINTER}
Const XNP_START_PRINTER = $89;


(*
// From constant.h
*)

(* Buffer Sizes for the following items.
 * Use OBJECT_NAME_SIZE if that is what it is.
 * Don't use USER_NAME_SIZE, SERVER_NAME_SIZE AND DOMAIN_NAME_SIZE
 * unless you have too.  These are all OBJECTS in the bindery.
 * All these sizes include space for the NULL terminator.
*)


{$DEFINE USER_NAME_SIZE}
Const USER_NAME_SIZE = 49;
{$IFNDEF  NWNLM }
    {$DEFINE SERVER_NAME_SIZE}
    Const SERVER_NAME_SIZE = 49;
{$ENDIF}

{$DEFINE OBJECT_NAME_SIZE}
Const OBJECT_NAME_SIZE = 48;

{$IFDEF  N_PLAT_OS2 }
    {$DEFINE PATH_SIZE}
    Const PATH_SIZE = 324;
{$ELSE}
    {$DEFINE PATH_SIZE}
    Const PATH_SIZE = 256;
{$ENDIF}


{$DEFINE PROPERTY_VALUE_SIZE}
Const PROPERTY_VALUE_SIZE = 128;

(*********************************************************************)

(*********************************************************************)


