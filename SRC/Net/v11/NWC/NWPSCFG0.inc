(*
//浜様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様融
//� (c) 1993 Novell, Inc.	All rights reserved.                              �
//�																								  �
//� THIS WORK IS SUBJECT TO U.S. AND INTERNATIONAL COPYRIGHT LAWS AND		  �
//� TREATIES.																					  �
//�																								  �
//� NO PART OF THIS WORK MAY BE USED, PRACTICED, PERFORMED, COPIED,			  �
//� DISTRIBUTED, REVISED, MODIFIED, TRANSLATED, ABRIDGED, CONDENSED,         �
//� EXPANDED, COLLECTED, COMPILED, LINKED, RECAST, TRANSFORMED OR ADAPTED	  �
//� WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC.                        �
//�																								  �
//� ANY USE OR EXPLOITATION OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT �
//� THE PERPETRATOR TO CRIMINAL AND CIVIL LIABILITY.								  �
//麺様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様郵
//� Source module name: NWPSCFG0.H														  �
//藩様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様夕
*)

(****************************************************************************)

(**  N W P 0 C f g x x x x x x x x x	C a l l s  ***************************)

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
) : nint32;
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


Function NWP0CfgAddPrintServer (
    connID  :   nuint32 ;
    pServerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgAddPrintServer ( connType , connID , pServerName ) NWP0CfgAddPrintServer ( connID , pServerName )  *)


Function NWP0CfgDeletePrintServer (
    connID  :   nuint32 ;
    pServerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgDeletePrintServer ( connType , connID , pServerName ) NWP0CfgDeletePrintServer ( connID , pServerName )  *)

(*===================================================================
  Find the first print server.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgGetFirstPrintServer (
    connID  :   nuint32 ;
    handle  :   NWPSListHandle ;
    pServerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgGetFirstPrintServer ( connType , connID , handle , pServerName ) NWP0CfgGetFirstPrintServer ( connID , handle , pServerName )  *)

(*===================================================================
  Find the next print server.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgGetNextPrintServer (
    handle  :   NWPSListHandle ;
    pServerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgGetNextPrintServer ( handle , pServerName ) NWP0CfgGetNextPrintServer ( handle , pServerName )  *)

(*===================================================================
  End scanning for print servers.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgEndNextPrintServer (
    handle  :   NWPSListHandle 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgEndNextPrintServer ( handle ) NWP0CfgEndNextPrintServer ( handle )  *)

(*===================================================================
  verify the print server.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgVerifyPrintServer (
    connID  :   nuint32 ;
    pServerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgVerifyPrintServer ( connType , connID , pServerName ) NWP0CfgVerifyPrintServer ( connID , pServerName )  *)

(*===================================================================
  Create a print server attribute in the bindery/directory.
  Attributes that do not exist in the bindery will fail (Sorry).
  See above for the list of legal attributes.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgAddPrintServerAttr (
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    attrID  :   nuint ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgAddPrintServerAttr ( connType , connID , pServerName , attrID , attrValue ) NWP0CfgAddPrintServerAttr ( connID , pServerName , attrID , attrValue )  *)

(*===================================================================
  Delete a print server attribute from the bindery/directory.
  Attributes that do not exist in the bindery will fail (Sorry).
  See above for the list of legal attributes.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgDeletePrintServerAttr (
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    attrID  :   nuint ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgDeletePrintServerAttr ( connType , connID , pServerName , attrID , attrValue ) NWP0CfgDeletePrintServerAttr ( connID , pServerName , attrID , attrValue )  *)

(*===================================================================
  Find the first attribute value in the bindery or directory.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgGetFirstPrintServerAttr (
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    attrID  :   nuint ;
    handle  :   NWPSListHandle ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgGetFirstPrintServerAttr ( connType , connID , pServerName , attrID , handle , attrValue ) NWP0CfgGetFirstPrintServerAttr ( connID , pServerName , attrID , handle , attrValue )  *)

(*===================================================================
  Find the next attribute value in the bindery or directory.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgGetNextPrintServerAttr (
    handle  :   NWPSListHandle ;
    pServerName  :   pnstr8 ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgGetNextPrintServerAttr ( handle , pServerName , attrValue ) NWP0CfgGetNextPrintServerAttr ( handle , pServerName , attrValue )  *)

(*===================================================================
  End scanning for attribute values in the bindery or directory.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgEndNextPrintServerAttr (
    handle  :   NWPSListHandle 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgEndNextPrintServerAttr ( handle ) NWP0CfgEndNextPrintServerAttr ( handle )  *)

(*===================================================================
  Modify an attribute value in the bindery or directory.
  If the attribute is single valued, the AddPrintServerAttr()
  will perform almost the same function.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgModifyPrintServerAttr (
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    attrID  :   nuint ;
    oldValue  :   nptr ;
    newValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgModifyPrintServerAttr ( connType , connID , pServerName , attrID , oldValue , newValue ) NWP0CfgModifyPrintServerAttr ( connID , pServerName , attrID , oldValue , newValue )  *)


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

Function NWP0CfgAddNServer (
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    nServerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgAddNServer ( connType , connID , pServerName , nServerName ) NWP0CfgAddNServer ( connID , pServerName , nServerName )  *)

(*===================================================================
  Delete a file server from the print server's service list.
  Since file servers are context oriented in directory services,
  this call does not make sense and will fail in directory mode.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgDeleteNServer (
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    nServerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgDeleteNServer ( connType , connID , pServerName , nServerName ) NWP0CfgDeleteNServer ( connID , pServerName , nServerName )  *)

(*===================================================================
  Find the first file server from the print server's service list.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

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

Function NWP0CfgAddPrinter (
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    printerName  :   pnstr8 ;
    printerNumber  :   pnuint 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgAddPrinter ( connType , connID , pServerName , printerName , printerNumber ) NWP0CfgAddPrinter ( connID , pServerName , printerName , printerNumber )  *)

(*===================================================================
  Delete a printer from the bindery/directory.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgDeletePrinter (
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    printerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgDeletePrinter ( connType , connID , pServerName , printerName ) NWP0CfgDeletePrinter ( connID , pServerName , printerName )  *)

(*===================================================================
  Find the first printer in the directory/bindery.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgGetFirstPrinter (
    connID  :   nuint32 ;
    handle  :   NWPSListHandle ;
    pServerName  :   pnstr8 ;
    printerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgGetFirstPrinter ( connType , connID , handle , pServerName , printerName ) NWP0CfgGetFirstPrinter ( connID , handle , pServerName , printerName )  *)

(*===================================================================
  Find the next printer in the directory/bindery.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgGetNextPrinter (
    handle  :   NWPSListHandle ;
    pServerName  :   pnstr8 ;
    printerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgGetNextPrinter ( handle , pServerName , printerName ) NWP0CfgGetNextPrinter ( handle , pServerName , printerName )  *)

(*===================================================================
  End scan for printers in the directory/bindery.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgEndNextPrinter (
    handle  :   NWPSListHandle 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgEndNextPrinter ( handle ) NWP0CfgEndNextPrinter ( handle )  *)

(*===================================================================
  Find the printer in the directory/bindery.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgVerifyPrinter (
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    printerName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgVerifyPrinter ( connType , connID , pServerName , printerName ) NWP0CfgVerifyPrinter ( connID , pServerName , printerName )  *)

(*===================================================================
  Add a printer attribute to the bindery/directory.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgAddPrinterAttr (
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    printerName  :   pnstr8 ;
    attrID  :   nuint ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgAddPrinterAttr ( connType , connID , pServerName , printerName , attrID , attrValue ) NWP0CfgAddPrinterAttr ( connID , pServerName , printerName , attrID , attrValue )  *)

(*===================================================================
  Delete a printer attribute from the bindery/directory.
  See AddPrinterAttr for a list of legal bindery attributes.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgDeletePrinterAttr (
    connID  :   nuint32 ;
    pServerName  :   pnstr8 ;
    printerName  :   pnstr8 ;
    attrID  :   nuint ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgDeletePrinterAttr ( connType , connID , pServerName , printerName , attrID , attrValue ) NWP0CfgDeletePrinterAttr ( connID , pServerName , printerName , attrID , attrValue )  *)

(*===================================================================
  Find the first printer attribute in the bindery/directory.
  See AddPrinterAttr for a list of legal bindery attributes.
  attrValue should be a buffer large enough to hold each attribute value.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgGetFirstPrinterAttr (
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


(* TC #define NWPSCfgGetFirstPrinterAttr ( connType , connID , pServerName , printerName , attrID , handle , attrValue ) NWP0CfgGetFirstPrinterAttr ( connID , pServerName , printerName , attrID , handle , attrValue )  *)

(*===================================================================
  Find the next printer attribute in the bindery/directory.
  attrValue should be a buffer large enough to hold each attribute value.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgGetNextPrinterAttr (
    handle  :   NWPSListHandle ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgGetNextPrinterAttr ( handle , printerName , attrValue ) NWP0CfgGetNextPrinterAttr ( handle , attrValue )  *)

(*===================================================================
  End scan for printer attributes in the bindery/directory.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgEndNextPrinterAttr (
    handle  :   NWPSListHandle 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgEndNextPrinterAttr ( handle ) NWP0CfgEndNextPrinterAttr ( handle )  *)

(*===================================================================
  Change a printer attribute in the bindery/directory.
  This function is similar to a add attribute to a single value
  attribute, however, some attributes must be changed in one call.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgModifyPrinterAttr (
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


(* TC #define NWPSCfgModifyPrinterAttr ( connType , connID , pServerName , printerName , attrID , oldValue , newValue ) NWP0CfgModifyPrinterAttr ( connID , pServerName , printerName , attrID , oldValue , newValue )  *)


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

Function NWP0CfgAddPrintQueue (
    connID  :   nuint32 ;
    queueName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgAddPrintQueue ( connType , connID , queueName , volumeName ) NWP0CfgAddPrintQueue ( connID , queueName )  *)

(*===================================================================
  Delete a print queue from the bindery/directory.  Any reference
  to the queue is also removed from Printers and Print Servers
  that are within the same context as the Print Queue.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgDeletePrintQueue (
    connID  :   nuint32 ;
    queueName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgDeletePrintQueue ( connType , connID , queueName ) NWP0CfgDeletePrintQueue ( connID , queueName )  *)

(*===================================================================
  Find the first print queue in the directory/bindery.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgGetFirstPrintQueue (
    connID  :   nuint32 ;
    handle  :   NWPSListHandle ;
    queueName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgGetFirstPrintQueue ( connType , connID , handle , queueName ) NWP0CfgGetFirstPrintQueue ( connID , handle , queueName )  *)

(*===================================================================
  Find the next print queue in the directory/bindery.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgGetNextPrintQueue (
    handle  :   NWPSListHandle ;
    queueName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgGetNextPrintQueue ( handle , queueName ) NWP0CfgGetNextPrintQueue ( handle , queueName )  *)

(*===================================================================
  End scan for print queues in the directory/bindery.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgEndNextPrintQueue (
    handle  :   NWPSListHandle 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgEndNextPrintQueue ( handle ) NWP0CfgEndNextPrintQueue ( handle )  *)

(*===================================================================
  Find the print queue in the directory/bindery.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgVerifyPrintQueue (
    connID  :   nuint32 ;
    queueName  :   pnstr8 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgVerifyPrintQueue ( connType , connID , queueName ) NWP0CfgVerifyPrintQueue ( connID , queueName )  *)

(*===================================================================
  Create or Add a Print Queue attribute to the bindery/directory.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgAddPrintQueueAttr (
    connID  :   nuint32 ;
    queueName  :   pnstr8 ;
    attrID  :   nuint ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgAddPrintQueueAttr ( connType , connID , queueName , attrID , attrValue ) NWP0CfgAddPrintQueueAttr ( connID , queueName , attrID , attrValue )  *)

(*===================================================================
  Delete a Print Queue attribute from the bindery/directory.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgDeletePrintQueueAttr (
    connID  :   nuint32 ;
    queueName  :   pnstr8 ;
    attrID  :   nuint ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgDeletePrintQueueAttr ( connType , connID , queueName , attrID , attrValue ) NWP0CfgDeletePrintQueueAttr ( connID , queueName , attrID , attrValue )  *)

(*===================================================================
  Find the first attribute for the Print Queue.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgGetFirstPrintQueueAttr (
    connID  :   nuint32 ;
    queueName  :   pnstr8 ;
    attrID  :   nuint ;
    handle  :   NWPSListHandle ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgGetFirstPrintQueueAttr ( connType , connID , queueName , attrID , handle , attrValue ) NWP0CfgGetFirstPrintQueueAttr ( connID , queueName , attrID , handle , attrValue )  *)

(*===================================================================
  Find the next attribute for the Print Queue.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgGetNextPrintQueueAttr (
    handle  :   NWPSListHandle ;
    queueName  :   pnstr8 ;
    attrValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgGetNextPrintQueueAttr ( handle , queueName , attrValue ) NWP0CfgGetNextPrintQueueAttr ( handle , queueName , attrValue )  *)

(*===================================================================
  End scan for attributes for the Print Queue.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgEndNextPrintQueueAttr (
    handle  :   NWPSListHandle 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgEndNextPrintQueueAttr ( handle ) NWP0CfgEndNextPrintQueueAttr ( handle )  *)

(*===================================================================
  Modify an attribute for the Print Queue.
  A zero is returned on succecss, or a non-zero error code on failure
  ===================================================================*)

Function NWP0CfgModifyPrintQueueAttr (
    connID  :   nuint32 ;
    queueName  :   pnstr8 ;
    attrID  :   nuint ;
    oldValue  :   nptr ;
    newValue  :   nptr 
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* TC #define NWPSCfgModifyPrintQueueAttr ( connType , connID , queueName , attrID , oldValue , newValue ) NWP0CfgModifyPrintQueueAttr ( connID , queueName , attrID , oldValue , newValue )  *)

{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}


