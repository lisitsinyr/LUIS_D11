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
//บ Source module name: NWPSJOBX.H														  บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

{$IFDEF __cplusplus}

(* TC extern C *)
{$ENDIF}


(*================================================================
  NWPSJobInit: Initializes a print job record with default values.
  ================================================================*)

Function NWPSJobInit (
    pJobRecord  :   NWPS_Job_Rec 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*=============================================================
  NWPSJobSet: Sets a print job record with defined values.
  The pJobRecord should have been set to 0 before this call and
  any name that is not defined will be left as '\0'.
  =============================================================*)

Function NWPSJobSet (
    connType  :   nuint ;
    pJobRecord  :   NWPS_Job_Rec ;
    formName  :   pnstr8 ;
    deviceName  :   pnstr8 ;
    modeName  :   pnstr8 ;
    bannerLowerName  :   pnstr8 ;
    bannerUpperName  :   pnstr8 ;
    bindNServer  :   pnstr8 ;
    bindQueue  :   pnstr8 ;
    bindPserver  :   pnstr8 ;
    dsUseQueueName  :   nuint ;
    dsObjectName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*########################### OBSOLETE ##############################
  ##### USE CORRESPONDING GETFIRST/GETNEXT/ENDNEXT TRIO INSTEAD #####
  ###################################################################
	NOTE: This call is inefficient and has been obsoleted
	by the creation of the NWPSJobGetFirstJob, NWPSJobGetNextJob,
	and NWPSJobEndNextJob trio of calls defined below. This
	call remains only for backward compatibility's sake. 

	NWPSJobScan is used repetatively to get a list of
  the print jobs in the printcon database(s).

  -PJSequence needs to be set to -1 to indicate the
  beginning of the search (i.e. the first time
  NWPSJobScan is called).
  -SearchFlag specifies whether to search all the public
  databases (NWPS_EXTENDED_SEARCH), to use only the
  specified database (NWPS_SINGLE_SEARCH), or to use
	the DbOwner's database and the first public database after that
	if they are different (NWPS_LIMITED_SEARCH).
  -DbOwner specifies the search start point and returns
  the directory object name, or bindery user name of
  the owner.
  -PJobName returns the name of the next print job
  record found.
  -DefaultPJ will be TRUE if the job is the current
  user's default print job, otherwise it is FALSE.

  If the function is successful in finding a next record,
  the return value of the function is 0, else an error code
  is returned.
  ###################################################################*)

Function NWPSJobScan (
    connType  :   nuint ;
    connID  :   nuint32 ;
    pJSequence  :   pnuint ;
    searchFlag  :   nuint ;
    dbOwner  :   pnstr8 ;
    pJobName  :   pnstr8 ;
    defaultPJ  :   pnuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}



Function NWPSJobGetFirstJob (
    connType  :   nuint ;
    connID  :   nuint32 ;
    searchFlag  :   nuint ;
    handle  :   NWPSListHandle ;
    dbOwner  :   pnstr8 ;
    pJobName  :   pnstr8 ;
    defaultPJ  :   pnuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSJobGetNextJob (
    handle  :   NWPSListHandle ;
    dbOwner  :   pnstr8 ;
    pJobName  :   pnstr8 ;
    defaultPJ  :   pnuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSJobEndNextJob (
    handle  :   NWPSListHandle 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*================================================================
  NWPSJobWrite is used both to create and modify
  records in the printcon database.

  -DbOwner is used to specify the location of the
  database to modify.  This field must be specified.
  -PJobName contains the name of the NWPS_Job_Rec to
  be written.
  If a record with the same name already exists in
  the database then it is overwritten with the data
  in the buffer pointed to by -pJobRecord, otherwise
  a new record is created in the database.

  The function returns a 0 if successful, otherwise an error code.
  ================================================================*)

Function NWPSJobWrite (
    connType  :   nuint ;
    connID  :   nuint32 ;
    dbOwner  :   pnstr8 ;
    pJobName  :   pnstr8 ;
    pJobRecord  :   NWPS_Job_Rec 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*======================================================
  NWPSJobRead searches for a record in the
  printcon database.

  -DbOwner specifies the database to read from.
  -PJobName contains the name of the print job to find.
  If the function is successful in finding the specified
  record, the buffer pointed to by -pJobRecord is filled
  with the contents of the record found

  The return value is 0 if the function is successful,
  otherwise an error code is returned.
  ======================================================*)

Function NWPSJobRead (
    connType  :   nuint ;
    connID  :   nuint32 ;
    dbOwner  :   pnstr8 ;
    pJobName  :   pnstr8 ;
    pJobRecord  :   NWPS_Job_Rec 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*================================================
  NWPSJobDelete removes a record from the
  printcon database.
  -DbOwner specifies the database where the print
  job is defined.
  -PJobName is the name of the NWPS_Job_Rec to be
  deleted from the database and is required.

  The function returns a 0 if it is successful,
  otherwise it returns the pertinent error code.
  If the print job does not exist in the database,
  success is returned.
  ================================================*)

Function NWPSJobDelete (
    connType  :   nuint ;
    connID  :   nuint32 ;
    dbOwner  :   pnstr8 ;
    pJobName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*================================================
  NWPSJobGetDefault gets the name and/or
  contents of the default NWPS_Job_Rec record in
  the PrnConDB database.

  -SearchFlag specifies whether to do look only
  in the specified database (NWPS_SINGLE_SEARCH),
  to look in all the public databases until
  a default is found (NWPS_EXTENDED_SEARCH), or to
	look in only the first public database found
	(NWPS_LIMITED_SEARCH);

  -DbOwner specifies the start point of the search
  for a default print job. And returns the actual
  location where the default print job was found.
  -PJobName returns the name of the default 
  print job.
  -PJobRecord returns the print job information.

  The return value is 0 of the call is successful,
  otherwise an error code is returned.
  ================================================*)

Function NWPSJobGetDefault (
    connType  :   nuint ;
    connID  :   nuint32 ;
    searchFlag  :   nuint ;
    dbOwner  :   pnstr8 ;
    pJobName  :   pnstr8 ;
    pJobRecord  :   NWPS_Job_Rec 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*=====================================================
  NWPSJobSetDefault sets the default NWPS_Job_Rec
  record in either the user or one of the public
  printcon databases.

  -DbOwner specifies the database to set/reset the
  default print job.
  -PJobName should contain the name of the NWPS_Job_Rec
  to be set as the system's default.  If PJobName is
  NULL or empty, the current default is erased.
  -PJobOwner is similar to dbOwner, but it specifies
  where the print job is defined. No attempt is made
  to verify that the print job exists in the
  pjobOwner database.

  The function returns a 0 if successful otherwise an
  error code.
  =====================================================*)

Function NWPSJobSetDefault (
    connType  :   nuint ;
    connID  :   nuint32 ;
    dbOwner  :   pnstr8 ;
    pJobName  :   pnstr8 ;
    pJobOwner  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*=====================================================
	Delete Database is a way to delete the Directory
	attribute and the corresponding file which could not
	be found out by ordinary means.	There is no corres-
	ponding way to delete the Bindery database since
	there is no mechanism implicit in the interface to
	specify whether the PUBLIC or private database should
	be deleted.
  =====================================================*)

Function NWPSJobDeleteDatabase (
    connType  :   nuint ;
    connID  :   nuint32 ;
    dbOwner  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*=====================================================
	Get Database Version
  =====================================================*)

Function NWPSJobGetDatabaseVersion (
    connType  :   nuint ;
    connID  :   nuint32 ;
    dbOwner  :   pnstr8 ;
    dbVersion  :   pnuint8 ;
    dbRevision  :   pnuint8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}

