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
//บ Source module name: NWPSCFGX.H														  บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

(****************************************************************************)

(**  N W P S C f g x x x x x x x x x	C a l l s  ***************************)

(****************************************************************************)


{$IFDEF __cplusplus}

(* TC extern C *)
{$ENDIF}


(*++++++++++++ calls to make attribute name/number conversions +++++++++++++*)

(*==========================================================
  Convert an attribute name to a print service attribute id.
  If the name can not be mapped, a -1 is returned.
  ==========================================================*)

Function NWPSCfgAttrNameToNumber (
    attrName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*==========================================================
  Convert a print service attribute id to an attribute name.
  if the attribute id is invalid a NULL is returned.
  ==========================================================*)

Function NWPSCfgAttrNumberToName (
    attrID  :   nuint 
) : pnstr8;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Get the default settings for a specified printer type.
  PrinterType should be NWPS_DEFAULT or NWPS_P_xxx.
  SubType is the port number for Parallel and Serial printers.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgGetPrinterDefaults (
    printerType  :   nuint ;
    subtype  :   nuint ;
    pconfig  :   NWPS_PConfig 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===============================================================
  Information stored in the bindery configuration file has a
  different format than NWPS_PConfig.	Those applications needing
  the old format can use these calls to do the conversion.
  ===============================================================*)

Procedure NWPSApiConfigToFileConfig (
    name  :   pnstr8 ;
    apiConfig  :   NWPS_PConfig ;
    fileConfig  :   pnuint8 
);
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Procedure NWPSFileConfigToApiConfig (
    fileConfig  :   pnuint8 ;
    name  :   pnstr8 ;
    length  :   pnuint32 ;
    apiConfig  :   NWPS_PConfig 
);
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*========== calls to change the print server list =========================*)

(*
PSERVER ATTRIBUTE    ATTRIB VALUE	  DEFAULT		 MULTI-VALUED
-----------------    ------------	  -------		 ------------
NWPS_ATTR_ACL			Object_ACL_T	  PServer R/W		  YES
NWPS_ATTR_CN			char[]			  PServer name      NO
NWPS_ATTR_DESC       char[]			  " "               NO
NWPS_ATTR_HOST_DEV	char[]			  (none)            NO
NWPS_ATTR_L          char[]			  (none)            YES
NWPS_ATTR_NADD       Net_Address_T	  (none)            YES
NWPS_ATTR_O          char[]			  (none)            YES
NWPS_ATTR_OPER       NWPS_Typed_Name  current user      YES
NWPS_ATTR_OU			char[]			  (none)            YES
NWPS_ATTR_PRINTER    Typed_Name_T	  (none)            YES
NWPS_ATTR_PRIV_KEY	Octet_String_T   (none)            NO
NWPS_ATTR_PUBL_KEY	Octet_String_T   (none)            NO
NWPS_ATTR_SAP			char[]			  (none)            NO
NWPS_ATTR_SEE_ALSO	char[]			  (none)            YES
NWPS_ATTR_STAT       Integer_T		  NWPS_DOWN         NO
NWPS_ATTR_USER       NWPS_Typed_Name  current OU		  YES
NWPS_ATTR_VERS       char[]			  (none)            NO
*)


(*===================================================================
  Create a new Print Server object in the bindery/directory.
  A default Operator and User is created.  In the bindery the
  operator is SUPERVISOR and the user is group EVERYONE.  In the
  directory the operator is the current user and the user is
  the current Organizational Unit.	A password is also created.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)


Function NWPSCfgAddPrintServer (
    connType  :   nuint ;
    connID  :   nuint32 ;
    pServerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Delete a Print Server. Any configuration information is also
  removed from the bindery/directory.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgDeletePrintServer (
    connType  :   nuint ;
    connID  :   nuint32 ;
    pServerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*########################### OBSOLETE ##############################
  ##### USE CORRESPONDING GETFIRST/GETNEXT/ENDNEXT TRIO INSTEAD #####
  ###################################################################
  NOTE: This call is inefficient and has been obsoleted
  by the creation of the NWPSCfgGetFirstPrintServer, 
  NWPSCfgGetNextPrintServer, and NWPSCfgEndNextPrintServer trio of 
  calls defined below. This call remains only for backward 
  compatibility's sake. 

  Find a print server.
  To find all the defined print servers, sequence should be set
  to -1 on the first call and the call will update the number.
  To verify a print server name, set sequence to NULL and
  PServerName to the name you want to find.
  A zero is returned on succecss, or a non-zero error code on failure
  ###################################################################*)

Function NWPSCfgScanPrintServer (
    connType  :   nuint ;
    connID  :   nuint32 ;
    sequence  :   pnuint32 ;
    pServerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Find the first print server.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgGetFirstPrintServer (
    connType  :   nuint ;
    connID  :   nuint32 ;
    handle  :   NWPSListHandle ;
    pServerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Find the next print server.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgGetNextPrintServer (
    handle  :   NWPSListHandle ;
    pServerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  End scanning for print servers.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgEndNextPrintServer (
    handle  :   NWPSListHandle 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  verify the print server.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgVerifyPrintServer (
    connType  :   nuint ;
    connID  :   nuint32 ;
    pServerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Create a print server attribute in the bindery/directory.
  Attributes that do not exist in the bindery will fail (Sorry).
  See above for the list of legal attributes.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgAddPrintServerAttr (
    connType  :   nuint ;
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    attrID  :   nuint ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Delete a print server attribute from the bindery/directory.
  Attributes that do not exist in the bindery will fail (Sorry).
  See above for the list of legal attributes.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgDeletePrintServerAttr (
    connType  :   nuint ;
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    attrID  :   nuint ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*########################### OBSOLETE ##############################
  ##### USE CORRESPONDING GETFIRST/GETNEXT/ENDNEXT TRIO INSTEAD #####
  ###################################################################
  NOTE: This call is inefficient and has been obsoleted
  by the creation of the NWPSCfgGetFirstPrintServerAttr, 
  NWPSCfgGetNextPrintServerAttr, and NWPSCfgEndNextPrintServerAttr 
  trio of calls defined below. This call remains only for backward 
  compatibility's sake. 

  Find an attribute value in the bindery or directory.
  On the first call, sequence should be set to -1, attrID is set
  to identify the attribute to read and attrValue is a pointer
  to the buffer to write the attribute value to.
  A zero is returned on succecss, or a non-zero error code on failure
  ###################################################################*)

Function NWPSCfgScanPrintServerAttr (
    connType  :   nuint ;
    connID  :   nuint32 ;
    sequence  :   pnuint32 ;
    pServerName  :   pnstr8 ;
    attrID  :   nuint ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Find the first attribute value in the bindery or directory.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgGetFirstPrintServerAttr (
    connType  :   nuint ;
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    attrID  :   nuint ;
    handle  :   NWPSListHandle ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Find the next attribute value in the bindery or directory.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgGetNextPrintServerAttr (
    handle  :   NWPSListHandle ;
    pServerName  :   pnstr8 ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  End scanning for attribute values in the bindery or directory.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgEndNextPrintServerAttr (
    handle  :   NWPSListHandle 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}



(*===================================================================
  Modify an attribute value in the bindery or directory.
  If the attribute is single valued, the AddPrintServerAttr()
  will perform almost the same function.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgModifyPrintServerAttr (
    connType  :   nuint ;
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    attrID  :   nuint ;
    oldValue  :   nptr ;
    newValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}



(* calls to change the file server list *)

(*
FSERVER ATTRIBUTE    ATTRIB VALUE	  DEFAULT		 MULTI-VALUED
-----------------    ------------	  -------		 ------------
(none)
*)

(*===================================================================
  Add a new file server for the print server to use.	Since print
  servers are context oriented in directory services, this call
  does not make sense and will fail in directory services mode.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgAddNServer (
    connType  :   nuint ;
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    nServerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Delete a file server from the print server's service list.
  Since file servers are context oriented in directory services,
  this call does not make sense and will fail in directory mode.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgDeleteNServer (
    connType  :   nuint ;
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    nServerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*########################### OBSOLETE ##############################
  ##### USE CORRESPONDING GETFIRST/GETNEXT/ENDNEXT TRIO INSTEAD #####
  ###################################################################
  NOTE: This call is inefficient and has been obsoleted
  by the creation of the NWPSCfgGetFirstNServer, 
  NWPSCfgGetNextNServer, and NWPSCfgEndNextNServer trio of 
  calls defined below. This call remains only for backward 
  compatibility's sake. 

  Find a file server from the print server's service list.
  Since file servers are context oriented in directory services,
  this call does not make sense and will fail in directory mode.
  On the first call sequence should be set to -1 and the routine
  will change the number before returning.  To verify a specific
  file server is in the serivce list, set sequence to NULL and
  set fserveName before making the call.
  A zero is returned on succecss, or a non-zero error code on failure
  ###################################################################*)

Function NWPSCfgScanNServer (
    connType  :   nuint ;
    connID  :   nuint32 ;
    sequence  :   pnuint32 ;
    pServerName  :   pnstr8 ;
    nServerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}



Function NWPSCfgGetFirstNServer (
    connType  :   nuint ;
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    handle  :   NWPSListHandle ;
    nServerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Find the next file server from the print server's service list.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgGetNextNServer (
    handle  :   NWPSListHandle ;
    nServerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  End scanning file servers from the print server's service list.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgEndNextNServer (
    handle  :   NWPSListHandle 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Find the file server from the print server's service list.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgVerifyNServer (
    connType  :   nuint ;
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    nServerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}



(* calls to change the printer configuration *)

(*
PRINTER ATTRIBUTE    ATTRIB VALUE	  DEFAULT		 MULTI-VALUED
-----------------    ------------	  -------		 ------------
NWPS_ATTR_ACL			Object_ACL_T	  printer R/W		  YES
NWPS_ATTR_CART       char[]			  (none)            YES
NWPS_ATTR_CN			char[]			  printer name      NO
NWPS_ATTR_CONF       Octet_String_T   LPT1				  NO
NWPS_ATTR_DESC       char[]			  " "               NO
NWPS_ATTR_DQUEUE		char[]			  (none)            NO
NWPS_ATTR_HOST_DEV	char[]			  (none)            NO
NWPS_ATTR_L          char[]			  (none)            YES
NWPS_ATTR_MEMORY		Integer_T		  (none)            NO
NWPS_ATTR_NADD       Net_Address_T	  (none)            YES
NWPS_ATTR_NADD_REST	Net_Address_T	  (none)            YES
NWPS_ATTR_NOTIFY		NWPS_Typed_Name  Job Owner         YES
NWPS_ATTR_O          char[]			  (none)            YES
NWPS_ATTR_OPER       NWPS_Typed_Name  current user      YES
NWPS_ATTR_OU			char[]			  (none)            YES
NWPS_ATTR_OWNER		NWPS_Typed_Name  current user      YES
NWPS_ATTR_PAGE       char[]			  (none)            YES
NWPS_ATTR_PRINT_SER	Typed_Name_T	  pServer/number	  NO
NWPS_ATTR_QUEUE		Typed_Name_T	  (none)            YES
NWPS_ATTR_SEE_ALSO	char[]			  (none)            YES
NWPS_ATTR_SERIAL		char[]			  (none)            YES
NWPS_ATTR_STAT       Integer_T	 NWPS_PSTAT_NOT_CONNECTED	NO
NWPS_ATTR_TYPE(faces)char[]			  (none)            YES
*)


(*===================================================================
  Create a new printer object.
  Printer number is required for bindery identification only.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgAddPrinter (
    connType  :   nuint ;
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    printerName  :   pnstr8 ;
    printerNumber  :   pnuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Delete a printer from the bindery/directory.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgDeletePrinter (
    connType  :   nuint ;
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    printerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*########################### OBSOLETE ##############################
  ##### USE CORRESPONDING GETFIRST/GETNEXT/ENDNEXT TRIO INSTEAD #####
  ###################################################################
  NOTE: This call is inefficient and has been obsoleted
  by the creation of the NWPSCfgGetFirstPrinter, 
  NWPSCfgGetNextPrinter, and NWPSCfgEndNextPrinter trio of 
  calls defined below. This call remains only for backward 
  compatibility's sake. 

  Find a printer in the directory/bindery.  To find all of the
  printers and their configurations, set sequence to -1 before
  the first call and the routine will update the number before
  returning.  To verify the existance of a specific printer,
  set sequence to NULL and set the name in the PConfig strucutre.
  A zero is returned on succecss, or a non-zero error code on failure
  ###################################################################*)

Function NWPSCfgScanPrinter (
    connType  :   nuint ;
    connID  :   nuint32 ;
    sequence  :   pnuint32 ;
    pServerName  :   pnstr8 ;
    printerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Find the first printer in the directory/bindery.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgGetFirstPrinter (
    connType  :   nuint ;
    connID  :   nuint32 ;
    handle  :   NWPSListHandle ;
    pServerName  :   pnstr8 ;
    printerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Find the next printer in the directory/bindery.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgGetNextPrinter (
    handle  :   NWPSListHandle ;
    pServerName  :   pnstr8 ;
    printerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  End scan for printers in the directory/bindery.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgEndNextPrinter (
    handle  :   NWPSListHandle 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Find the printer in the directory/bindery.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgVerifyPrinter (
    connType  :   nuint ;
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    printerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Add a printer attribute to the bindery/directory.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgAddPrinterAttr (
    connType  :   nuint ;
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    printerName  :   pnstr8 ;
    attrID  :   nuint ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Delete a printer attribute from the bindery/directory.
  See AddPrinterAttr for a list of legal bindery attributes.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgDeletePrinterAttr (
    connType  :   nuint ;
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    printerName  :   pnstr8 ;
    attrID  :   nuint ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*########################### OBSOLETE ##############################
  ##### USE CORRESPONDING GETFIRST/GETNEXT/ENDNEXT TRIO INSTEAD #####
  ###################################################################
  NOTE: This call is inefficient and has been obsoleted
  by the creation of the NWPSCfgGetFirstPrinterAttr, 
  NWPSCfgGetNextPrinterAttr, and NWPSCfgEndNextPrinterAttr trio of 
  calls defined below. This call remains only for backward 
  compatibility's sake. 

  Find a printer attribute in the bindery/directory.
  See AddPrinterAttr for a list of legal bindery attributes.
  To find the first value of a multi-valued attribute, set sequence
  to -1 before making the call.	Sequence is updated internally 
  in preparation for each call. attrValue should be a buffer large
  enough to hold each attribute value.
  A zero is returned on succecss, or a non-zero error code on failure
  ###################################################################*)

Function NWPSCfgScanPrinterAttr (
    connType  :   nuint ;
    connID  :   nuint32 ;
    sequence  :   pnuint32 ;
    pServerName  :   pnstr8 ;
    printerName  :   pnstr8 ;
    attrID  :   nuint ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Find the first printer attribute in the bindery/directory.
  See AddPrinterAttr for a list of legal bindery attributes.
  attrValue should be a buffer large enough to hold each attribute value.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgGetFirstPrinterAttr (
    connType  :   nuint ;
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    printerName  :   pnstr8 ;
    attrID  :   nuint ;
    handle  :   NWPSListHandle ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Find the next printer attribute in the bindery/directory.
  attrValue should be a buffer large enough to hold each attribute value.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgGetNextPrinterAttr (
    handle  :   NWPSListHandle ;
    printerName  :   pnstr8 ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  End scan for printer attributes in the bindery/directory.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgEndNextPrinterAttr (
    handle  :   NWPSListHandle 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Change a printer attribute in the bindery/directory.
  This function is similar to a add attribute to a single value
  attribute, however, some attributes must be changed in one call.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgModifyPrinterAttr (
    connType  :   nuint ;
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    printerName  :   pnstr8 ;
    attrID  :   nuint ;
    oldValue  :   nptr ;
    newValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}



(* calls to change a printer's queue list *)

(*
QUEUE ATTRIBUTE		ATTRIB VALUE	  DEFAULT		 MULTI-VALUED
-----------------    ------------	  -------		 ------------
NWPS_ATTR_ACL			Object_ACL_T	  queue R/W         YES
NWPS_ATTR_CN			char[]			  printer name      NO
NWPS_ATTR_DESC       char[]			  " "               NO
NWPS_ATTR_DEVICE		char[]			  (none)            YES
NWPS_ATTR_HOST_RES	char[]			  (none)            NO
NWPS_ATTR_HOST_SER	char[]			  NetWare Server	  NO
NWPS_ATTR_L          char[]			  (none)            YES
NWPS_ATTR_NADD       Net_Address_T	  (none)            YES
NWPS_ATTR_O          char[]			  (none)            YES
NWPS_ATTR_OPER       NWPS_Typed_Name  current user      YES
NWPS_ATTR_OU			char[]			  (none)            YES
NWPS_ATTR_QUE_DIR    char[]			  <Vol>:\QUEUE\<ID>.QDR  YES
NWPS_ATTR_SEE_ALSO	char[]			  (none)            YES
NWPS_ATTR_SERVER		char[]			  (none)            YES
NWPS_ATTR_USER       NWPS_Typed_Name  current OU		  YES
NWPS_ATTR_VOLUME		char[]			  Volume            NO
*)


(*===================================================================
  Add a print queue to the bindery/directory.  In bindery mode,
  the volumeName is automatically assigned.	In both modes,
  default values are added for the following fields;
		Description, Queue Directory, Operator, User and Volume.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgAddPrintQueue (
    connType  :   nuint ;
    connID  :   nuint32 ;
    queueName  :   pnstr8 ;
    volumeName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Delete a print queue from the bindery/directory.  Any reference
  to the queue is also removed from Printers and Print Servers
  that are within the same context as the Print Queue.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgDeletePrintQueue (
    connType  :   nuint ;
    connID  :   nuint32 ;
    queueName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*########################### OBSOLETE ##############################
  ##### USE CORRESPONDING GETFIRST/GETNEXT/ENDNEXT TRIO INSTEAD #####
  ###################################################################
  NOTE: This call is inefficient and has been obsoleted
  by the creation of the NWPSCfgGetFirstPrintQueue, 
  NWPSCfgGetNextPrintQueue, and NWPSCfgEndNextPrintQueue trio of 
  calls defined below. This call remains only for backward 
  compatibility's sake. 

  Find a print queue in the directory/bindery.
  On the first call, sequence should be set to -1 and the function
  will change it for subsequent calls.
  A zero is returned on succecss, or a non-zero error code on failure
  ###################################################################*)

Function NWPSCfgScanPrintQueue (
    connType  :   nuint ;
    connID  :   nuint32 ;
    sequence  :   pnuint32 ;
    queueName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Find the first print queue in the directory/bindery.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgGetFirstPrintQueue (
    connType  :   nuint ;
    connID  :   nuint32 ;
    handle  :   NWPSListHandle ;
    queueName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Find the next print queue in the directory/bindery.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgGetNextPrintQueue (
    handle  :   NWPSListHandle ;
    queueName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  End scan for print queues in the directory/bindery.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgEndNextPrintQueue (
    handle  :   NWPSListHandle 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Find the print queue in the directory/bindery.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgVerifyPrintQueue (
    connType  :   nuint ;
    connID  :   nuint32 ;
    queueName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Create or Add a Print Queue attribute to the bindery/directory.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgAddPrintQueueAttr (
    connType  :   nuint ;
    connID  :   nuint32 ;
    queueName  :   pnstr8 ;
    attrID  :   nuint ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Delete a Print Queue attribute from the bindery/directory.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgDeletePrintQueueAttr (
    connType  :   nuint ;
    connID  :   nuint32 ;
    queueName  :   pnstr8 ;
    attrID  :   nuint ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*########################### OBSOLETE ##############################
  ##### USE CORRESPONDING GETFIRST/GETNEXT/ENDNEXT TRIO INSTEAD #####
  ###################################################################
  NOTE: This call is inefficient and has been obsoleted
  by the creation of the NWPSCfgGetFirstPrintQueueAttr, 
  NWPSCfgGetNextPrintQueueAttr, and NWPSCfgEndNextPrintQueueAttr trio 
  of calls defined below. This call remains only for backward 
  compatibility's sake. 

  Find an attribute for the Print Queue.
  A zero is returned on succecss, or a non-zero error code on failure
  ###################################################################*)

Function NWPSCfgScanPrintQueueAttr (
    connType  :   nuint ;
    connID  :   nuint32 ;
    sequence  :   pnuint32 ;
    queueName  :   pnstr8 ;
    attrID  :   nuint ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Find the first attribute for the Print Queue.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgGetFirstPrintQueueAttr (
    connType  :   nuint ;
    connID  :   nuint32 ;
    queueName  :   pnstr8 ;
    attrID  :   nuint ;
    handle  :   NWPSListHandle ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Find the next attribute for the Print Queue.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgGetNextPrintQueueAttr (
    handle  :   NWPSListHandle ;
    queueName  :   pnstr8 ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  End scan for attributes for the Print Queue.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgEndNextPrintQueueAttr (
    handle  :   NWPSListHandle 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*===================================================================
  Modify an attribute for the Print Queue.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWPSCfgModifyPrintQueueAttr (
    connType  :   nuint ;
    connID  :   nuint32 ;
    queueName  :   pnstr8 ;
    attrID  :   nuint ;
    oldValue  :   nptr ;
    newValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}


