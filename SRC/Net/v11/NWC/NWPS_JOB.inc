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
//บ Source module name: NWPS_JOB.H														  บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

{$IFNDEF NWPS_DEF_INC}

{$I nwps_def.inc}
{$ENDIF}


{$IFNDEF NWPS_JOB_INC}

{$DEFINE NWPS_JOB_INC}
(*********************************************************************)

(*********** PrintCon - Print Job Configuration Information **********)

(*********************************************************************)


(*====================== PrintCon search flags =============================*)

{$DEFINE NWPS_EXTENDED_SEARCH}
Const NWPS_EXTENDED_SEARCH = 0;
{$DEFINE NWPS_SINGLE_SEARCH}
Const NWPS_SINGLE_SEARCH = 1;
{$DEFINE NWPS_LIMITED_SEARCH}
Const NWPS_LIMITED_SEARCH = 2;

(*========================================================================
	Either or both of the following bits may be returned with a given Job
	recordName/recordOwner pair. The first indicates the Job which would
	be returned by NWPSJobGetDefault. The second indicates the Job recorded
	in the database header as a default which is in that database.
  ========================================================================*)

{$DEFINE NWPS_DOMINANT_DEFAULT_JOB}
Const NWPS_DOMINANT_DEFAULT_JOB = $01;
{$DEFINE NWPS_CURRENT_DB_DEFAULT_JOB}
Const NWPS_CURRENT_DB_DEFAULT_JOB = $02;

{$DEFINE NWPS_DBOWNER_PUBLIC}
Const NWPS_DBOWNER_PUBLIC = '(PUBLIC)';
{$DEFINE NWPS_DEVICE_NONE}
Const NWPS_DEVICE_NONE = '(NONE)';
{$DEFINE NWPS_MODE_NONE}
Const NWPS_MODE_NONE = '(NONE)';

(*====================================
	Flags used for printControlFlags in
	the NWPS_ClientRecord structure
  ====================================*)

{$DEFINE NWPS_SUPPRESS_FF}
Const NWPS_SUPPRESS_FF = $0800;
{$DEFINE NWPS_NOTIFY_USER}
Const NWPS_NOTIFY_USER = $1000;
{$DEFINE NWPS_TEXT_MODE}
Const NWPS_TEXT_MODE = $4000;
{$DEFINE NWPS_PRINT_BANNER}
Const NWPS_PRINT_BANNER = $8000;

(*========================================================
  This structure is overlayed on the QMS
  NWQueueJobStruct.clientRecordArea to define a print job.
  It is not used in any of the print services APIs.
  (Formerly called NWPS_PJob.)
  ========================================================*)

Type
    NWPS_ClientRecord = Record
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
        headerFileName  :  Array[0..13] Of  nuint8 ;
        directoryPath  :  Array[0..79] Of  nuint8 ;
    End;


(*=======================================================
  NWPS_Job_Rec is the type of record in the third and
  last section of the PrnConDB database.	Each one of
  these records contains all the fields that make up a
  print job configuration as described in the NetWare 386
  Print Server documentation.
  =======================================================*)

(*======== Flags for the NWPS_Job_Rec structure printJobFlag field =========*)

{$DEFINE NWPS_JOB_EXPAND_TABS}
Const NWPS_JOB_EXPAND_TABS = $00000001;
{$DEFINE NWPS_JOB_NO_FORMFEED}
Const NWPS_JOB_NO_FORMFEED = $00000002;
{$DEFINE NWPS_JOB_NOTIFY}
Const NWPS_JOB_NOTIFY = $00000004;
{$DEFINE NWPS_JOB_PRINT_BANNER}
Const NWPS_JOB_PRINT_BANNER = $00000008;
{$DEFINE NWPS_JOB_AUTO_END}
Const NWPS_JOB_AUTO_END = $00000010;
{$DEFINE NWPS_JOB_TIMEOUT}
Const NWPS_JOB_TIMEOUT = $00000020;

{$DEFINE NWPS_JOB_ENV_DS}
Const NWPS_JOB_ENV_DS = $00000040;
{$DEFINE NWPS_JOB_ENV_MASK}
Const NWPS_JOB_ENV_MASK = $000001C0;

{$DEFINE NWPS_JOB_DS_PRINTER}
Const NWPS_JOB_DS_PRINTER = $00000200;
{$DEFINE NWPS_JOB_PRINTER_MASK}
Const NWPS_JOB_PRINTER_MASK = $00000E00;
{$DEFINE NWPS_JOB_HOSTPRINT}
Const NWPS_JOB_HOSTPRINT = $00001000;

(*=========================== Default Flags ================================*)

Const NWPS_JOB_DEFAULT = ( NWPS_JOB_PRINT_BANNER OR NWPS_JOB_AUTO_END );
{$DEFINE NWPS_JOB_DEFAULT_COPIES}
Const NWPS_JOB_DEFAULT_COPIES = 1;
{$DEFINE NWPS_JOB_DEFAULT_TAB}
Const NWPS_JOB_DEFAULT_TAB = 8;

Type
    NWPS_Job_Rec = Record
        printJobFlag  :   nuint32 ;
        (* 0: File type: 0=Byte stream 1=Text*)
        (* 1: Suppress formfeed:  0=No 1=Yes *)
        (* 2: Notify when done:   0=No 1=Yes *)
        (* 3: Print banner:		  0=No 1=Yes *)
        (* 4: Auto endcap:		  0=No 1=Yes *)
        (* 5: Enable timeout:	  0=No 1=Yes *)
        (* 8-6: Environment:                 *)
        (*     000=Bindary						 *)
        (*     001=Directory Services        *)
        (* 11-9: Destination Type:           *)
        (*     000=Queue_Name					 *)
        (*     001=Printer_Name              *)
        (* 12: HostPrint or Normal: 0=Normal *)
        (* 31-13: Unused							 *)
        copies  :   nuint16 ;
        timeOutCount  :   nuint16 ;
        tabSize  :   nuint8 ;
        localPrinter  :   nuint8 ;
        formName  :  Array[0..NWPS_FORM_NAME_SIZE+2-1] Of nint8;
        name  :  Array[0..NWPS_BANNER_NAME_SIZE+2-1] Of nint8;
        bannerName  :  Array[0..NWPS_BANNER_FILE_SIZE+2-1] Of nint8;
        device  :  Array[0..NWPS_DEVI_NAME_SIZE+2-1] Of nint8;
        mode  :  Array[0..NWPS_MODE_NAME_SIZE+2-1] Of nint8;
        nonDS : Record  (* union statement *)
            (* pad structures on even boundries *)
            nServer  :  Array[0..NWPS_BIND_NAME_SIZE+2-1] Of nint8;
            printQueue  :  Array[0..NWPS_BIND_NAME_SIZE+2-1] Of nint8;
            printServer  :  Array[0..NWPS_BIND_NAME_SIZE+2-1] Of nint8;
        End;
        reserved  :  Array[0..389] Of  nuint8 ;
    End;



(*===========================================================
	DBOwner values and their meanings-
	---------------------------------
	NULL		 : Use the current user. No return possible.
	Empty     : Use the current user. Return real object name.
	UserName  : Use the specified user.
	DS Object : Use the specified DS object.
  ===========================================================*)


{$IFDEF  NWPS_CONN_TYPE }
    {$IFDEF NWPS_CONN_TYPE==NWPS_BINDERY_SERVICE}
        {$I nwpsjob0.inc}
    {$ELSE}  {$IFDEF NWPS_CONN_TYPE==NWPS_DIRECTORY_SERVICE}
        {$I nwpsjob1.inc}
    {$ELSE}  {$IFDEF NWPS_CONN_TYPE==NWPS_BINDERY_SERVICE_PRE_40}
        {$I nwpsjob2.inc}
    {$ELSE}  {$IFDEF NWPS_CONN_TYPE==NWPS_BINDERY_SERVICE_ALL}
        {$I nwpsjobx.inc}
    {$ENDIF}
    {$ENDIF}
    {$ENDIF}
    {$ENDIF}
{$ELSE}
    {$I nwpsjobx.inc}
{$ENDIF}


{$ENDIF}


