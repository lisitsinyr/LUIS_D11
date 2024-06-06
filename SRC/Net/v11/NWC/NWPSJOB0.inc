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
//บ Source module name: NWPSJOB0.H														  บ
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


(*==========================================================================
  NWPSJobGetFirstJob, NWPSJobGetNextJob, and NWPSJobEndNextJob are used 
	repetatively to get a list of the print jobs in the printcon database(s).

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
  ==========================================================================*)

Function NWP0JobGetFirstJob (
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


Function NWP0JobGetNextJob (
    handle  :   NWPSListHandle ;
    dbOwner  :   pnstr8 ;
    pJobName  :   pnstr8 ;
    defaultPJ  :   pnuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSJobGetFirstJob ( connType , connID , searchFlag , handle , dbOwner , pJobName , defaultPJ ) NWP0JobGetFirstJob ( connID , searchFlag , handle , dbOwner , pJobName , defaultPJ )  *)

(* TC #define NWPSJobGetNextJob ( handle , dbOwner , pJobName , defaultPJ ) NWP0JobGetNextJob ( handle , dbOwner , pJobName , defaultPJ )  *)

Function NWPSJobEndNextJob (
    handle  :   NWPSListHandle 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}



Function NWP0JobWrite (
    connID  :   nuint32 ;
    dbOwner  :   pnstr8 ;
    pJobName  :   pnstr8 ;
    pJobRecord  :   NWPS_Job_Rec 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSJobWrite ( connType , connID , dbOwner , pJobName , pJobRecord ) NWP0JobWrite ( connID , dbOwner , pJobName , pJobRecord )  *)

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

Function NWP0JobRead (
    connID  :   nuint32 ;
    dbOwner  :   pnstr8 ;
    pJobName  :   pnstr8 ;
    pJobRecord  :   NWPS_Job_Rec 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSJobRead ( connType , connID , dbOwner , pJobName , pJobRecord ) NWP0JobRead ( connID , dbOwner , pJobName , pJobRecord )  *)

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

Function NWP0JobDelete (
    connID  :   nuint32 ;
    dbOwner  :   pnstr8 ;
    pJobName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSJobDelete ( connType , connID , dbOwner , pJobName ) NWP0JobDelete ( connID , dbOwner , pJobName )  *)

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

Function NWP0JobGetDefault (
    connID  :   nuint32 ;
    searchFlag  :   nuint ;
    dbOwner  :   pnstr8 ;
    pJobName  :   pnstr8 ;
    pJobRecord  :   NWPS_Job_Rec 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSJobGetDefault ( connType , connID , searchFlag , dbOwner , pJobName , pJobRecord ) NWP0JobGetDefault ( connID , searchFlag , dbOwner , pJobName , pJobRecord )  *)

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

Function NWP0JobSetDefault (
    connID  :   nuint32 ;
    dbOwner  :   pnstr8 ;
    pJobName  :   pnstr8 ;
    pJobOwner  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSJobSetDefault ( connType , connID , dbOwner , pJobName , pJobOwner ) NWP0JobSetDefault ( connID , dbOwner , pJobName , pJobOwner )  *)

(*=====================================================
	Get Database Version
  =====================================================*)

Function NWP0JobGetDatabaseVersion (
    connID  :   nuint32 ;
    dbOwner  :   pnstr8 ;
    dbVersion  :   pnuint8 ;
    dbRevision  :   pnuint8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSJobGetDatabaseVersion ( connType , connID , dbOwner , dbVersion , dbRevision ) NWP0JobGetDatabaseVersion ( connID , dbOwner , dbVersion , dbRevision )  *)

{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}

