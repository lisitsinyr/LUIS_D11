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
//บ Source module name: NWPSPDFX.H														  บ
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

Function NWPSPdfGetVersion (
    connType  :   nuint ;
    connID  :   nuint32 ;
    pdfVersion  :   pnuint32 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*==================================================================
  Set the Version number stored in the database.  The database
  file/stream is automaticly opened and closed by this call.
  This call returns 0 on success, or non-zero error code on failure.
  ==================================================================*)

Function NWPSPdfSetVersion (
    connType  :   nuint ;
    connID  :   nuint32 ;
    pdfVersion  :   nuint32 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*=========================================================================
	Set the Context's DCK_NAME_CONTEXT to the Organizational Unit or
	Organization in the Directory where a database already exists, searching
	the Directory toward the [Root] from the given Printer or Print Queue.
  =========================================================================*)

Function NWPSPdfLocateDBAndSetContext (
    contextID  :   nuint32 ;
    printerOrQueueObjectName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*++++++++++++++++++++++++++++ Form Calls +++++++++++++++++++++++++++++++++*)

(*==================================================================
  Add a form to the PrintDef database. Forms are independent
  of printers and are unique on each file server or context.
  This call returns 0 on success, or non-zero error code on failure.
  ==================================================================*)

Function NWPSPdfAddForm (
    connType  :   nuint ;
    connID  :   nuint32 ;
    formName  :   pnstr8 ;
    formNumber  :   nuint ;
    formLength  :   nuint ;
    formWidth  :   nuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Delete a form from the PrintDef database.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSPdfDeleteForm (
    connType  :   nuint ;
    connID  :   nuint32 ;
    formName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Find a Form in the PrintDef database.
  If the user wants to find all the forms, sequence should be
  set to -1 on the first call, and the sequence value will be
  updated when the call returns.
  If the user wants to find a specific Form, the sequence pointer
  should be NULL and the formName should be set to the desired form.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSPdfScanForm (
    connType  :   nuint ;
    connID  :   nuint32 ;
    sequence  :   pnuint32 ;
    formName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Get each Form in turn; these calls obsolete the ScanForm call
  ===================================================================*)

Function NWPSPdfGetFirstForm (
    connType  :   nuint ;
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


Function NWPSPdfGetNextForm (
    handle  :   NWPSListHandle ;
    formName  :   pnstr8 ;
    formNumber  :   pnuint ;
    formLength  :   pnuint ;
    formWidth  :   pnuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*======================================================
  Read the form information from the PrintDef database.
  If the form does not exist, an error code is returned.
  If it does exist, the form's name, number, length and
  width are set and a 0 is returned.
  ======================================================*)

Function NWPSPdfReadForm (
    connType  :   nuint ;
    connID  :   nuint32 ;
    formName  :   pnstr8 ;
    formNumber  :   pnuint ;
    formLength  :   pnuint ;
    formWidth  :   pnuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Update the form information. If you don't want to change the
  name, set newFormName to NULL. If you don't want to change a
  parameter set the value to -1.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSPdfUpdateForm (
    connType  :   nuint ;
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


(*+++++++++++++++++++++++++++ Device Calls ++++++++++++++++++++++++++++++++*)

(*===================================================================
  Add a device to the PrintDef database. The Device is created
  without any Functions or modes.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSPdfAddDevice (
    connType  :   nuint ;
    connID  :   nuint32 ;
    deviceName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Delete a device from the PrintDef database.
  When a Device is deleted, all of the device's Functions and Modes
  are also deleted.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSPdfDeleteDevice (
    connType  :   nuint ;
    connID  :   nuint32 ;
    deviceName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Find a Device in the PrintDef database.
  To find all of the Devices, set sequence to -1 on the first call
  and it will be reset by the call if a Device if found.
  To find a specific Device, set sequence pointer to NULL and set deviceName
  to the desired search name.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSPdfScanDevice (
    connType  :   nuint ;
    connID  :   nuint32 ;
    sequence  :   pnuint32 ;
    deviceName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Get each Device in turn; these calls obsolete the ScanDevice call
  ===================================================================*)

Function NWPSPdfGetFirstDevice (
    connType  :   nuint ;
    connID  :   nuint32 ;
    handle  :   NWPSListHandle ;
    deviceName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSPdfGetNextDevice (
    handle  :   NWPSListHandle ;
    deviceName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Find out how many functions and modes are defined for a device.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSPdfReadDevice (
    connType  :   nuint ;
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    modeCount  :   pnuint ;
    funcCount  :   pnuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Change a Device name in the PrintDef database.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSPdfUpdateDevice (
    connType  :   nuint ;
    connID  :   nuint32 ;
    oldDeviceName  :   pnstr8 ;
    newDeviceName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*+++++++++++++++++++++++++ Mode Calls ++++++++++++++++++++++++++++++++++++*)

(*===================================================================
  Create a new Mode for a specific Device.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSPdfAddMode (
    connType  :   nuint ;
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    modeName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Delete a Mode from a Device.
  When the Mode is deleted, the Functions are left intact.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSPdfDeleteMode (
    connType  :   nuint ;
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    modeName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Find a Mode in the PrintDef database.
  To find all of the Modes, set sequence to -1 on the first call
  and it will be reset by the call if a Mode is found.
  To find a specific Mode, set sequence to NULL and set modeName
  to the desired search name.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSPdfScanMode (
    connType  :   nuint ;
    connID  :   nuint32 ;
    sequence  :   pnuint32 ;
    deviceName  :   pnstr8 ;
    modeName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Get each Mode in turn; these calls obsolete the ScanMode call
  ===================================================================*)

Function NWPSPdfGetFirstMode (
    connType  :   nuint ;
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    handle  :   NWPSListHandle ;
    modeName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSPdfGetNextMode (
    handle  :   NWPSListHandle ;
    modeName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Find information on a defined Mode.
  If the Mode is defined, and funcCount is not NULL, the number
  of functions in the mode is returned in funcCount.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSPdfReadMode (
    connType  :   nuint ;
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    reqModeName  :   pnstr8 ;
    funcCount  :   pnuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Change the name of a Mode.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSPdfUpdateMode (
    connType  :   nuint ;
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    oldModeName  :   pnstr8 ;
    newModeName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}



(*++++++++++++++++++ Mode-Function Grouping Calls +++++++++++++++++++++++++*)

(*====================================================================
  Add a previously defined function to a previously defined mode list.
  A zero is returned on succecss, or a non-zero error code on failure
  ====================================================================*)

Function NWPSPdfAddModeFunction (
    connType  :   nuint ;
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    modeName  :   pnstr8 ;
    funcName  :   pnstr8 ;
    location  :   nuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*==================================================================
  Delete a function from a defined mode list.
  Neither the Mode or Function is deleted from the Device lists.
  A zero is returned on success, or a non-zero error code on failure
  ==================================================================*)

Function NWPSPdfDeleteModeFunction (
    connType  :   nuint ;
    connID  :   nuint32 ;
    sequence  :   nuint32 ;
    deviceName  :   pnstr8 ;
    modeName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Find the name of a Function associated with a Mode.
  To find all of the Functions associated with a Mode, set
  sequence to -1 on the first call and it will be reset by
  the call if a Functions is found.
  To find a specific Function associated with a Mode, set sequence
  to NULL and set functName to the desired search name.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSPdfScanModeFunction (
    connType  :   nuint ;
    connID  :   nuint32 ;
    sequence  :   pnuint32 ;
    deviceName  :   pnstr8 ;
    modeName  :   pnstr8 ;
    funcName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Get each Function in turn; these calls obsolete the ScanModeFunction call
  ===================================================================*)

Function NWPSPdfGetFirstModeFunction (
    connType  :   nuint ;
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    modeName  :   pnstr8 ;
    handle  :   NWPSListHandle ;
    funcName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSPdfGetNextModeFunction (
    handle  :   NWPSListHandle ;
    funcName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*==================================================================
  Find the Modes which use this Function.
  To find all of the Modes associated with a Function, set
  sequence to -1 on the first call and it will be reset by
  the call if a Mode is found.
  A zero is returned on success, or a non-zero error code on failure
  ==================================================================*)

Function NWPSPdfScanFunctionMode (
    connType  :   nuint ;
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

Function NWPSPdfReadModeFunction (
    connType  :   nuint ;
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


(*+++++++++++++++++++++++++++ Function Calls ++++++++++++++++++++++++++++++*)

(*===================================================================
  Add a Function to a Device.
  funcSize should be set to the number of bytes in funcString.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSPdfAddFunction (
    connType  :   nuint ;
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    funcName  :   pnstr8 ;
    funcSize  :   nuint ;
    funcString  :   pnuint8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Delete a function from the Device in the PrintDef database.
  If the Function is refered to in any Mode, the Function
  will be automaticly deleted from the Mode as well.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSPdfDeleteFunction (
    connType  :   nuint ;
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    funcName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Find a Function defined for a specific Device.
  To find all of the Functions associated with a Device, set
  sequence to -1 on the first call and it will be reset by
  the call if a Functions is found.
  To find a specific Function associated with a Device, set sequence
  to NULL and set functName to the desired search name.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSPdfScanFunction (
    connType  :   nuint ;
    connID  :   nuint32 ;
    sequence  :   pnuint32 ;
    deviceName  :   pnstr8 ;
    funcName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Get each Function in turn; these calls obsolete the ScanFunction call
  ===================================================================*)

Function NWPSPdfGetFirstFunction (
    connType  :   nuint ;
    connID  :   nuint32 ;
    deviceName  :   pnstr8 ;
    handle  :   NWPSListHandle ;
    funcName  :   pnstr8 ;
    funcData  :   NWPSPdfFuncData 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSPdfGetNextFunction (
    handle  :   NWPSListHandle ;
    funcName  :   pnstr8 ;
    funcData  :   NWPSPdfFuncData 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Read the byte string associated with a function.
  funcSize should be set equal to the size of the buffer funcString.
  funcSize will be set to the actual size of the byte string if the
  call is successful.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSPdfReadFunction (
    connType  :   nuint ;
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


(*===================================================================
  Change the function string assigned to a function name.
  To change the function's name, set newFuncName to a new name.
  To leave the Function name the same, set newFuncName to NULL.
  To change the function string, set funcSize to the number of
  bytes in the funcString and set funcString to point to the
  new string. To leave the string the same, set funcSize to -1.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSPdfUpdateFunction (
    connType  :   nuint ;
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

Function NWPSPdfImportDevice (
    connType  :   nuint ;
    connID  :   nuint32 ;
    fileName  :   pnstr8 ;
    deviceName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWPSPdfManagedImportDevice (
    connType  :   nuint ;
    connID  :   nuint32 ;
    fileName  :   pnstr8 ;
    deviceName  :   pnstr8 ;
    importManagerFunc  :   NWPSImportManager ;
    importManagerParm1  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}



(*===============================================
  Export a device to a Pdf file from the database
  ===============================================*)

Function NWPSPdfExportDevice (
    connType  :   nuint ;
    connID  :   nuint32 ;
    fileName  :   pnstr8 ;
    deviceName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*=========================================================
  Delete the Directory Services "Printer Control" Attribute
  at the given context.
  =========================================================*)

Function NWPSPdfDeleteDatabase (
    connType  :   nuint ;
    connID  :   nuint32 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}

