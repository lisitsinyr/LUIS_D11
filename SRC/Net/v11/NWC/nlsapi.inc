(****************************************************************************
*
* 1995 (C) Unpublished Copyright Novell, Inc. All Rights Reserved.
*
* No part of this file may be duplicated, revised, translated,
* localized or modified in any manner or compiled, linked or 
* uploaded or downloaded to or from any computer system without
* the prior written consent of Novell, Inc.
*
*****************************************************************************)


{$IFNDEF  NOVELL_NLSAPI_INCLUDED }
    {$DEFINE NOVELL_NLSAPI_INCLUDED}
    Type LS_LICENSE_ID  =  ^LS_STR;
    Type
        LS_TRANS_ENTRY_TAG = Record
            actionName  :  ^LS_STR;
            time  :   LS_ULONG ;
            actionResult  :   LS_STATUS_CODE ;
            numUnits  :   LS_ULONG ;
            userLoggedMessage  :  ^LS_STR;
        End;
        LS_TRANS_ENTRY = LS_TRANS_ENTRY_TAG;
    {$DEFINE LS_USER_NAME}
    Const LS_USER_NAME = $00000000;
    {$DEFINE LS_FILE_SERVER}
    Const LS_FILE_SERVER = $00000002;
    {$IFDEF  __cplusplus }
        (* TC extern C *)
    {$ENDIF}
    (* TC extern C *)
    (* TC  LS_STR FAR * licenseSystem , LS_STR FAR * serverName , LS_STR FAR * publisher ,  *)
    (* TC  LS_STR FAR * product , LS_STR FAR * version , LS_ULONG maxStrLen ,  *)
    (* TC  LS_STR FAR * installedPublisher , LS_STR FAR * installedProduct ,  *)
    (* TC  LS_STR FAR * installedVersion , LS_LICENSE_ID installedLicID ,  *)
    (* TC  LS_ULONG FAR * numInstalledUnits , LS_ULONG FAR * index );  *)
    (* TC extern C *)
    (* TC  LS_STR FAR * licenseSystem , LS_STR FAR * serverName , LS_STR FAR * publisher ,  *)
    (* TC  LS_STR FAR * product , LS_STR FAR * version , LS_ULONG maxStrLen ,  *)
    (* TC  LS_STR FAR * publisherInUse , LS_STR FAR * productInUse ,  *)
    (* TC  LS_STR FAR * versionInUse , LS_LICENSE_ID licIDInUse ,  *)
    (* TC  LS_ULONG FAR * numUnitsInUse , LS_ULONG FAR * index );  *)
    (* TC extern C *)
    (* TC  LS_STR FAR * licenseSystem , LS_STR FAR * serverName , LS_STR FAR * publisher ,  *)
    (* TC  LS_STR FAR * product , LS_STR FAR * version , LS_ULONG maxStrLen ,  *)
    (* TC  LS_STR FAR * availablePublisher , LS_STR FAR * availableProduct ,  *)
    (* TC  LS_STR FAR * availableVersion , LS_LICENSE_ID availableLicID ,  *)
    (* TC  LS_ULONG FAR * availableUnits , LS_ULONG FAR * index );  *)
    (* TC extern C *)
    (* TC  LS_STR FAR * licenseSystem , LS_STR FAR * serverName , LS_STR FAR * publisher ,  *)
    (* TC  LS_STR FAR * product , LS_STR FAR * version , LS_ULONG maxStrLen ,  *)
    (* TC  LS_STR FAR * publisherInUse , LS_STR FAR * productInUse ,  *)
    (* TC  LS_STR FAR * versionInUse , LS_LICENSE_ID licIDInUse ,  *)
    (* TC  LS_ULONG FAR * unitsInUse , LS_STR FAR * user , LS_ULONG FAR * index );  *)
    (* TC extern C *)
    (* TC  LS_STR FAR * licenseSystem , LS_STR FAR * publisher , LS_STR FAR * product ,  *)
    (* TC  LS_STR FAR * version , LS_LICENSE_ID licenseID , LS_ULONG assignmentType ,  *)
    (* TC  LS_VOID FAR * assignmentInfo , LS_ULONG assigmentInfoLen );  *)
    (* TC extern C *)
    (* TC  LS_STR FAR * licenseSystem , LS_STR FAR * publisher , LS_STR FAR * product ,  *)
    (* TC  LS_STR FAR * version , LS_LICENSE_ID licenseID , LS_ULONG assignmentType ,  *)
    (* TC  LS_VOID FAR * assignmentInfo , LS_ULONG assignmentInfoLen );  *)
    (* TC extern C *)
    (* TC  LS_STR FAR * licenseSystem , LS_STR FAR * publisher , LS_STR FAR * product ,  *)
    (* TC  LS_STR FAR * version , LS_LICENSE_ID licenseID , LS_STR FAR * newOwner );  *)
    (* TC extern C *)
    (* TC  LS_STR FAR * licenseSystem , LS_STR FAR * publisher , LS_STR FAR * product ,  *)
    (* TC  LS_STR FAR * version , LS_STR FAR * userName , LS_ULONG maxStrLen ,  *)
    (* TC  LS_HANDLE FAR * transactionHandle , LS_STR FAR * transactionPublisher ,  *)
    (* TC  LS_STR FAR * transactionProduct , LS_STR FAR * transactionVersion ,  *)
    (* TC  LS_STR FAR * transactionUserName , LS_ULONG FAR * index );  *)
    (* TC extern C *)
    (* TC  LS_HANDLE transactionHandle , LS_TRANS_ENTRY FAR * transactionEntry ,  *)
    (* TC  LS_ULONG FAR * index );  *)
    (* TC extern C *)
    (* TC  LS_STR FAR * licenseSystem , LS_STR FAR * serverName , LS_ULONG licenseLength ,  *)
    (* TC  LS_VOID FAR * licenseCertificate , LS_ULONG passwordLength ,  *)
    (* TC  LS_VOID FAR * activationPassword );  *)
    (* TC extern C *)
    (* TC  LS_STR FAR * licenseSystem , LS_STR FAR * publisherName , LS_STR FAR * productName ,  *)
    (* TC  LS_STR FAR * version , LS_LICENSE_ID licenseID , LS_STR FAR * newServerName );  *)
    (* TC extern C *)
    (* TC  LS_STR FAR * licenseSystem , LS_STR FAR * publisherName , LS_STR FAR * productName ,  *)
    (* TC  LS_STR FAR * version , LS_LICENSE_ID licenseID );  *)
    (* TC extern C *)
    (* TC  LS_STR FAR * licenseSystem , LS_STR FAR * publisherName ,  *)
    (* TC  LS_STR FAR * productName , LS_STR FAR * version , LS_LICENSE_ID licenseID ,  *)
    (* TC  LS_ULONG maxBufferLen , LS_VOID FAR * licenseCertificate ,  *)
    (* TC  LS_ULONG FAR * actualBufferLen );  *)
    (* TC extern C *)
    (* TC  LS_VOID FAR * licenseCertificate , LS_ULONG licenseCertificateLength ,  *)
    (* TC  LS_ULONG maxStringLen , LS_STR FAR * messageString , LS_ULONG FAR * tagNumber );  *)
    (* TC extern C *)
    (* TC  LS_STR FAR * licenseSystem , LS_STR FAR * serverName , LS_STR FAR * publisherName ,  *)
    (* TC  LS_STR FAR * productName , LS_STR FAR * version , LS_ULONG licenseUnits ,  *)
    (* TC  LS_ULONG attributesLength , LS_VOID FAR * licenseAttributes );  *)
    {$IFDEF  __cplusplus }
        (* TC } *)
    {$ENDIF}
{$ENDIF}

