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
//บ Source module name: NWPSPDF0.H														  บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

{$IFDEF __cplusplus}

(* TC extern C *)
{$ENDIF}


(*++++++++++++++++++++++ General Database calls +++++++++++++++++++++*)

(*==================================================================
  Get the Version number stored in the database.  The database
  file/stream is automaticly opened and closed by this call.
  This call returns 0 on success, or non-zero error code on failure.
  ==================================================================*)

Function NWP0PdfGetVersion (
    connID  :   nuint32 ;
    pdfVersion  :   pnuint32 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfGetVersion ( connType , connID , pdfVersion ) NWP0PdfGetVersion ( connID , pdfVersion )  *)

(*==================================================================
  Set the Version number stored in the database.  The database
  file/stream is automaticly opened and closed by this call.
  This call returns 0 on success, or non-zero error code on failure.
  ==================================================================*)

Function NWP0PdfSetVersion (
    connID  :   nuint32 ;
    pdfVersion  :   nuint32 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfSetVersion ( connType , connID , pdfVersion ) NWP0PdfSetVersion ( connID , pdfVersion )  *)

(*++++++++++++++++++++++++++++ Form Calls +++++++++++++++++++++++++++++++++*)

(*==================================================================
  Add a form to the PrintDef database. Forms are independent
  of printers and are unique on each file server or context.
  This call returns 0 on success, or non-zero error code on failure.
  ==================================================================*)

Function NWP0PdfAddForm (
    connID  :   nuint32 ;
    formName  :   pnstr8 ;
    formNumber  :   nuint ;
    formLength  :   nuint ;
    formWidth  :   nuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfAddForm ( connType , connID , formName , formNumber , formLength , formWidth ) NWP0PdfAddForm ( connID , formName , formNumber , formLength , formWidth )  *)

(*===================================================================
  Delete a form from the PrintDef database.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0PdfDeleteForm (
    connID  :   nuint32 ;
    formName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfDeleteForm ( connType , connID , formName ) NWP0PdfDeleteForm ( connID , formName )  *)

(*===================================================================
  Find a Form in the PrintDef database.
  If the user wants to find all the forms, sequence should be
  set to -1 on the first call, and the sequence value will be
  updated when the call returns.
  If the user wants to find a specific Form, the sequence pointer
  should be NULL and the formName should be set to the desired form.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0PdfScanForm (
    connID  :   nuint32 ;
    sequence  :   pnuint32 ;
    formName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfScanForm ( connType , connID , sequence , formName ) NWP0PdfScanForm ( connID , sequence , formName )  *)

(*===================================================================
  Get each Form in turn; these calls obsolete the ScanForm call
  ===================================================================*)

Function NWP0PdfGetFirstForm (
    connID  :   nuint32 ;
    handle  :   NWPSListHandle ;
    formName  :   pnstr8 ;
    formNumber  :   pnuint ;
    formLength  :   pnuint ;
    formWidth  :   pnuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWP0PdfGetNextForm (
    handle  :   NWPSListHandle ;
    formName  :   pnstr8 ;
    formNumber  :   pnuint ;
    formLength  :   pnuint ;
    formWidth  :   pnuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfGetFirstForm ( connType , connID , handlee , formName , N , L , W ) NWP0PdfGetFirstForm ( connID , handle , formName , N , L , W )  *)
(* Type NWPSPdfGetNextForm = NWP0PdfGetNextForm; *)

(*======================================================
  Read the form information from the PrintDef database.
  If the form does not exist, an error code is returned.
  If it does exist, the form's name, number, length and
  width are set and a 0 is returned.
  ======================================================*)

Function NWP0PdfReadForm (
    connID  :   nuint32 ;
    formName  :   pnstr8 ;
    formNumber  :   pnuint ;
    formLength  :   pnuint ;
    formWidth  :   pnuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfReadForm ( connType , connID , formName , formNumber , formLength , formWidth ) NWP0PdfReadForm ( connID , formName , formNumber , formLength , formWidth )  *)

(*===================================================================
  Update the form information. If you don't want to change the
  name, set newFormName to NULL. If you don't want to change a
  parameter set the value to -1.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0PdfUpdateForm (
    connID  :   nuint32 ;
    oldFormName  :   pnstr8 ;
    newFormName  :   pnstr8 ;
    formNumber  :   nuint ;
    formLength  :   nuint ;
    formWidth  :   nuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfUpdateForm ( connType , connID , oldFormName , newFormName , formNumber , formLength , formWidth ) NWP0PdfUpdateForm ( connID , oldFormName , newFormName , formNumber , formLength , formWidth )  *)

(*+++++++++++++++++++++++++++ Device Calls ++++++++++++++++++++++++++++++++*)

(*===================================================================
  Add a device to the PrintDef database. The Device is created
  without any Functions or modes.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0PdfAddDevice (
    connID  :   nuint32 ;
    deviceName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfAddDevice ( connType , connID , deviceName ) NWP0PdfAddDevice ( connID , deviceName )  *)

(*===================================================================
  Delete a device from the PrintDef database.
  When a Device is deleted, all of the device's Functions and Modes
  are also deleted.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0PdfDeleteDevice (
    connID  :   nuint32 ;
    deviceName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfDeleteDevice ( connType , connID , deviceName ) NWP0PdfDeleteDevice ( connID , deviceName )  *)

(*===================================================================
  Find a Device in the PrintDef database.
  To find all of the Devices, set sequence to -1 on the first call
  and it will be reset by the call if a Device if found.
  To find a specific Device, set sequence pointer to NULL and set deviceName
  to the desired search name.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0PdfScanDevice (
    connID  :   nuint32 ;
    sequence  :   pnuint32 ;
    deviceName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfScanDevice ( connType , connID , sequence , deviceName ) NWP0PdfScanDevice ( connID , sequence , deviceName )  *)

(*===================================================================
  Get each Device in turn; these calls obsolete the ScanDevice call
  ===================================================================*)

Function NWP0PdfGetFirstDevice (
    connID  :   nuint32 ;
    handle  :   NWPSListHandle ;
    deviceName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWP0PdfGetNextDevice (
    handle  :   NWPSListHandle ;
    deviceName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfGetFirstDevice ( connType , connID , handle , deviceName ) NWP0PdfGetFirstDevice ( connID , handle , deviceName )  *)
(* Type NWPSPdfGetNextDevice = NWP0PdfGetNextDevice; *)

(*===================================================================
  Find out how many functions and modes are defined for a device.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0PdfReadDevice (
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    modeCount  :   pnuint ;
    funcCount  :   pnuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfReadDevice ( connType , connID , deviceName , modeCount , funcCount ) NWP0PdfReadDevice ( connID , deviceName , modeCount , funcCount )  *)

(*===================================================================
  Change a Device name in the PrintDef database.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0PdfUpdateDevice (
    connID  :   nuint32 ;
    oldDeviceName  :   pnstr8 ;
    newDeviceName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfUpdateDevice ( connType , connID , oldDeviceName , newDeviceName ) NWP0PdfUpdateDevice ( connID , oldDeviceName , newDeviceName )  *)

(*+++++++++++++++++++++++++ Mode Calls ++++++++++++++++++++++++++++++++++++*)

(*===================================================================
  Create a new Mode for a specific Device.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0PdfAddMode (
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    modeName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfAddMode ( connType , connID , deviceName , modeName ) NWP0PdfAddMode ( connID , deviceName , modeName )  *)

(*===================================================================
  Delete a Mode from a Device.
  When the Mode is deleted, the Functions are left intact.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0PdfDeleteMode (
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    modeName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfDeleteMode ( connType , connID , deviceName , modeName ) NWP0PdfDeleteMode ( connID , deviceName , modeName )  *)


Function NWP0PdfScanMode (
    connID  :   nuint32 ;
    sequence  :   pnuint32 ;
    deviceName  :   pnstr8 ;
    modeName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfScanMode ( connType , connID , sequence , deviceName , modeName ) NWP0PdfScanMode ( connID , sequence , deviceName , modeName )  *)

(*===================================================================
  Get each Mode in turn; these calls obsolete the ScanMode call
  ===================================================================*)

Function NWP0PdfGetFirstMode (
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    handle  :   NWPSListHandle ;
    modeName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWP0PdfGetNextMode (
    handle  :   NWPSListHandle ;
    modeName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfGetFirstMode ( connType , connID , deviceName , handle , modeName ) NWP0PdfGetFirstMode ( connID , deviceName , handle , modeName )  *)
(* Type NWPSPdfGetNextMode = NWP0PdfGetNextMode; *)

(*===================================================================
  Find information on a defined Mode.
  If the Mode is defined, and funcCount is not NULL, the number
  of functions in the mode is returned in funcCount.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0PdfReadMode (
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    reqModeName  :   pnstr8 ;
    funcCount  :   pnuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfReadMode ( connType , connID , deviceName , reqModeName , funcCount ) NWP0PdfReadMode ( connID , deviceName , reqModeName , funcCount )  *)

(*===================================================================
  Change the name of a Mode.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0PdfUpdateMode (
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    oldModeName  :   pnstr8 ;
    newModeName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfUpdateMode ( connType , connID , deviceName , oldModeName , newModeName ) NWP0PdfUpdateMode ( connID , deviceName , oldModeName , newModeName )  *)


(*++++++++++++++++++ Mode-Function Grouping Calls +++++++++++++++++++++++++*)

(*====================================================================
  Add a previously defined function to a previously defined mode list.
  A zero is returned on succecss, or a non-zero error code on failure
  ====================================================================*)

Function NWP0PdfAddModeFunction (
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    modeName  :   pnstr8 ;
    funcName  :   pnstr8 ;
    location  :   nuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfAddModeFunction ( connType , connID , deviceName , modeName , funcName , location ) NWP0PdfAddModeFunction ( connID , deviceName , modeName , funcName , location )  *)

(*==================================================================
  Delete a function from a defined mode list.
  Neither the Mode or Function is deleted from the Device lists.
  A zero is returned on success, or a non-zero error code on failure
  ==================================================================*)

Function NWP0PdfDeleteModeFunction (
    connID  :   nuint32 ;
    sequence  :   nuint32 ;
    deviceName  :   pnstr8 ;
    modeName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfDeleteModeFunction ( connType , connID , sequence , deviceName , modeName ) NWP0PdfDeleteModeFunction ( connID , sequence , deviceName , modeName )  *)

(*===================================================================
  Find the name of a Function associated with a Mode.
  To find all of the Functions associated with a Mode, set
  sequence to -1 on the first call and it will be reset by
  the call if a Functions is found.
  To find a specific Function associated with a Mode, set sequence
  to NULL and set functName to the desired search name.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0PdfScanModeFunction (
    connID  :   nuint32 ;
    sequence  :   pnuint32 ;
    deviceName  :   pnstr8 ;
    modeName  :   pnstr8 ;
    funcName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfScanModeFunction ( connType , connID , sequence , deviceName , modeName , funcName ) NWP0PdfScanModeFunction ( connID , sequence , deviceName , modeName , funcName )  *)

(*===================================================================
  Get each Function in turn; these calls obsolete the ScanModeFunction call
  ===================================================================*)

Function NWP0PdfGetFirstModeFunction (
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    modeName  :   pnstr8 ;
    handle  :   NWPSListHandle ;
    funcName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWP0PdfGetNextModeFunction (
    handle  :   NWPSListHandle ;
    funcName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfGetFirstModeFunction ( connType , connID , deviceName , modeName , handle , funcName ) NWP0PdfGetFirstModeFunction ( connID , deviceName , modeName , handle , funcName )  *)
(* Type NWPSPfdGetNextModeFunction = NWP0PfdGetNextModeFunction; *)

(*==================================================================
  Find the Modes which use this Function.
  To find all of the Modes associated with a Function, set
  sequence to -1 on the first call and it will be reset by
  the call if a Mode is found.
  A zero is returned on success, or a non-zero error code on failure
  ==================================================================*)

Function NWP0PdfScanFunctionMode (
    connID  :   nuint32 ;
    funcSequence  :   pnuint32 ;
    modeSequence  :   pnuint32 ;
    deviName  :   pnstr8 ;
    modeName  :   pnstr8 ;
    funcName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfScanFunctionMode ( connType , connID , funcSequence , modeSequence , deviName , modeName , funcName ) NWP0PdfScanFunctionMode ( connID , funcSequence , modeSequence , deviName , modeName , funcName )  *)

(*=================================================================
  Read the actual function values associated with a mode.
  On the first call, funcOffset should be set to 0, and funcSize
  should be set to the size of the buffer pointed to by funcBuffer.
  On return funcSize will contain the actual number of bytes copied
  to the funcBuffer and the return value will be 0.
  A zero is returned if there is any data after the specified
  funcOffset (start point).  A failure code is retuned if
  there is an error or if funcOffset is greater than the
  available number of bytes.
  =================================================================*)

Function NWP0PdfReadModeFunction (
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    modeName  :   pnstr8 ;
    (*-------- no function name because this is a mode group ----------------*)
    funcOffset  :   nuint ;
    funcSize  :   pnuint ;
    funcString  :   pnuint8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}




(* TC #define NWPSPdfReadModeFunction ( connType , connID , deviceName , modeName , funcOffset , funcSize , funcString ) NWP0PdfReadModeFunction ( connID , deviceName , modeName , funcOffset , funcSize , funcString )  *)

(*+++++++++++++++++++++++++++ Function Calls ++++++++++++++++++++++++++++++*)

(*===================================================================
  Add a Function to a Device.
  funcSize should be set to the number of bytes in funcString.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0PdfAddFunction (
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    funcName  :   pnstr8 ;
    funcSize  :   nuint ;
    funcString  :   pnuint8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfAddFunction ( connType , connID , deviceName , funcName , funcSize , funcString ) NWP0PdfAddFunction ( connID , deviceName , funcName , funcSize , funcString )  *)

(*===================================================================
  Delete a function from the Device in the PrintDef database.
  If the Function is refered to in any Mode, the Function
  will be automaticly deleted from the Mode as well.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0PdfDeleteFunction (
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    funcName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfDeleteFunction ( connType , connID , deviceName , funcName ) NWP0PdfDeleteFunction ( connID , deviceName , funcName )  *)

(*===================================================================
  Find a Function defined for a specific Device.
  To find all of the Functions associated with a Device, set
  sequence to -1 on the first call and it will be reset by
  the call if a Functions is found.
  To find a specific Function associated with a Device, set sequence
  to NULL and set functName to the desired search name.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0PdfScanFunction (
    connID  :   nuint32 ;
    sequence  :   pnuint32 ;
    deviceName  :   pnstr8 ;
    funcName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfScanFunction ( connType , connID , sequence , deviceName , funcName ) NWP0PdfScanFunction ( connID , sequence , deviceName , funcName )  *)

(*===================================================================
  Get each Function in turn; these calls obsolete the ScanFunction call
  ===================================================================*)

Function NWP0PdfGetFirstFunction (
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    handle  :   NWPSListHandle ;
    funcName  :   pnstr8 ;
    funcData  :   NWPSPdfFuncData 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWP0PdfGetNextFunction (
    handle  :   NWPSListHandle ;
    funcName  :   pnstr8 ;
    funcData  :   NWPSPdfFuncData 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfGetFirstFunction ( connType , connID , deviceName , handle , funcName , funcData ) NWP0PdfGetFirstFunction ( connID , deviceName , handle , funcName , funcData )  *)
(* Type NWPSPfdGetNextFunction = NWP0PfdGetNextFunction; *)

(*===================================================================
  Read the byte string associated with a function.
  funcSize should be set equal to the size of the buffer funcString.
  funcSize will be set to the actual size of the byte string if the
  call is successful.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0PdfReadFunction (
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    funcName  :   pnstr8 ;
    funcOffset  :   nuint ;
    funcSize  :   pnuint ;
    funcString  :   pnuint8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}




(* TC #define NWPSPdfReadFunction ( connType , connID , deviceName , funcName , funcOffset , funcSize , funcString ) NWP0PdfReadFunction ( connID , deviceName , funcName , funcOffset , funcSize , funcString )  *)

(*===================================================================
  Change the function string assigned to a function name.
  To change the function's name, set newFuncName to a new name.
  To leave the Function name the same, set newFuncName to NULL.
  To change the function string, set funcSize to the number of
  bytes in the funcString and set funcString to point to the
  new string. To leave the string the same, set funcSize to -1.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0PdfUpdateFunction (
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    oldFuncName  :   pnstr8 ;
    newFuncName  :   pnstr8 ;
    funcSize  :   nuint ;
    funcString  :   pnuint8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfUpdateFunction ( connType , connID , deviceName , oldFuncName , newFuncName , funcSize , funcString ) NWP0PdfUpdateFunction ( connID , deviceName , oldFuncName , newFuncName , funcSize , funcString )  *)

(*++++++++++++++++++++ Import and Export Functions ++++++++++++++++++++++++*)

(*-----------------------------------------------------
  The path name for a PDF file should have
  one of the following formats:
	 "\\<file server>\<volume>\<path>\<file name>[.PDF]"
	 "<volume>:<path>\<file name>[.PDF]"
	 NULL to create the file ".\<device name>[.PDF]"
  Every PDF import/export file also has a date code
  associated with it.  The date is always set when the
  file is created.
  -----------------------------------------------------*)

(*===========================================
  Import a device from a file to the database
  ===========================================*)

Function NWP0PdfManagedImportDevice (
    connID  :   nuint32 ;
    fileName  :   pnstr8 ;
    deviceName  :   pnstr8 ;
    importManagerFunc  :   NWPSImportManager ;
    importManagerParm1  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfImportDevice ( connType , connID , fileName , deviceName ) NWP0PdfManagedImportDevice ( connID , fileName , deviceName , NULL , NULL )  *)

(* TC #define NWPSPdfManagedImportDevice ( connType , connID , fileName , deviceName , importManagerFunc , importManagerParm1 ) NWP0PdfManagedImportDevice ( connID , fileName , deviceName , importManagerFunc , importManagerParm1 )  *)

(*===============================================
  Export a device to a Pdf file from the database
  ===============================================*)

Function NWP0PdfExportDevice (
    connID  :   nuint32 ;
    fileName  :   pnstr8 ;
    deviceName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfExportDevice ( connType , connID , fileName , deviceName ) NWP0PdfExportDevice ( connID , fileName , deviceName )  *)

(*=========================================================
  Delete the Directory Services "Printer Control" Attribute
  at the given context.
  =========================================================*)

Function NWP0PdfDeleteDatabase (
    connID  :   nuint32 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSPdfDeleteDatabase ( connType , connID ) NWP0PdfDeleteDatabase ( connID )  *)

{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}

