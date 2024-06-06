(******************************************************************************

  %name: nwbindry.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:05:42 1996 %
  $Copyright:

  Copyright (c) 1989-1995 Novell, Inc.  All Rights Reserved.                      

  THIS WORK IS  SUBJECT  TO  U.S.  AND  INTERNATIONAL  COPYRIGHT  LAWS  AND
  TREATIES.   NO  PART  OF  THIS  WORK MAY BE  USED,  PRACTICED,  PERFORMED
  COPIED, DISTRIBUTED, REVISED, MODIFIED, TRANSLATED,  ABRIDGED, CONDENSED,
  EXPANDED,  COLLECTED,  COMPILED,  LINKED,  RECAST, TRANSFORMED OR ADAPTED
  WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC. ANY USE OR EXPLOITATION
  OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT THE PERPETRATOR TO
  CRIMINAL AND CIVIL LIABILITY.$

 *****************************************************************************)


{$IFNDEF  NWBINDRY_H }
    {$DEFINE NWBINDRY_H}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    (* Bindery object types (in HIGH-LOW order) *)
    {$DEFINE OT_WILD}
    Const OT_WILD = $FFFF;
    {$DEFINE OT_UNKNOWN}
    Const OT_UNKNOWN = $0000;
    {$DEFINE OT_USER}
    Const OT_USER = $0100;
    {$DEFINE OT_USER_GROUP}
    Const OT_USER_GROUP = $0200;
    {$DEFINE OT_PRINT_QUEUE}
    Const OT_PRINT_QUEUE = $0300;
    {$DEFINE OT_FILE_SERVER}
    Const OT_FILE_SERVER = $0400;
    {$DEFINE OT_JOB_SERVER}
    Const OT_JOB_SERVER = $0500;
    {$DEFINE OT_GATEWAY}
    Const OT_GATEWAY = $0600;
    {$DEFINE OT_PRINT_SERVER}
    Const OT_PRINT_SERVER = $0700;
    {$DEFINE OT_ARCHIVE_QUEUE}
    Const OT_ARCHIVE_QUEUE = $0800;
    {$DEFINE OT_ARCHIVE_SERVER}
    Const OT_ARCHIVE_SERVER = $0900;
    {$DEFINE OT_JOB_QUEUE}
    Const OT_JOB_QUEUE = $0A00;
    {$DEFINE OT_ADMINISTRATION}
    Const OT_ADMINISTRATION = $0B00;
    {$DEFINE OT_NAS_SNA_GATEWAY}
    Const OT_NAS_SNA_GATEWAY = $2100;
    {$DEFINE OT_REMOTE_BRIDGE_SERVER}
    Const OT_REMOTE_BRIDGE_SERVER = $2600;
    {$DEFINE OT_TCPIP_GATEWAY}
    Const OT_TCPIP_GATEWAY = $2700;
    {$DEFINE OT_TREE_NAME}
    Const OT_TREE_NAME = $7802;
    (* Extended bindery object types *)
    {$DEFINE OT_TIME_SYNCHRONIZATION_SERVER}
    Const OT_TIME_SYNCHRONIZATION_SERVER = $2D00;
    {$DEFINE OT_ARCHIVE_SERVER_DYNAMIC_SAP}
    Const OT_ARCHIVE_SERVER_DYNAMIC_SAP = $2E00;
    {$DEFINE OT_ADVERTISING_PRINT_SERVER}
    Const OT_ADVERTISING_PRINT_SERVER = $4700;
    {$DEFINE OT_BTRIEVE_VAP}
    Const OT_BTRIEVE_VAP = $5000;
    {$DEFINE OT_PRINT_QUEUE_USER}
    Const OT_PRINT_QUEUE_USER = $5300;
    (* Bindery object and property flags *)
    {$DEFINE BF_STATIC}
    Const BF_STATIC = $00;
    {$DEFINE BF_DYNAMIC}
    Const BF_DYNAMIC = $01;
    {$DEFINE BF_ITEM}
    Const BF_ITEM = $00;
    {$DEFINE BF_SET}
    Const BF_SET = $02;
    (*********  Bindery object and property security access levels  **********)
    {$DEFINE BS_ANY_READ}
    Const BS_ANY_READ = $00;
    {$DEFINE BS_LOGGED_READ}
    Const BS_LOGGED_READ = $01;
    {$DEFINE BS_OBJECT_READ}
    Const BS_OBJECT_READ = $02;
    {$DEFINE BS_SUPER_READ}
    Const BS_SUPER_READ = $03;
    {$DEFINE BS_BINDERY_READ}
    Const BS_BINDERY_READ = $04;
    {$DEFINE BS_ANY_WRITE}
    Const BS_ANY_WRITE = $00;
    {$DEFINE BS_LOGGED_WRITE}
    Const BS_LOGGED_WRITE = $10;
    {$DEFINE BS_OBJECT_WRITE}
    Const BS_OBJECT_WRITE = $20;
    {$DEFINE BS_SUPER_WRITE}
    Const BS_SUPER_WRITE = $30;
    {$DEFINE BS_BINDERY_WRITE}
    Const BS_BINDERY_WRITE = $40;
    Function NWVerifyObjectPassword (
        conn  :   NWCONN_HANDLE ;
        objName  :   pnstr8 ;
        objType  :   nuint16 ;
        password  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDisallowObjectPassword (
        conn  :   NWCONN_HANDLE ;
        objName  :   pnstr8 ;
        objType  :   nuint16 ;
        disallowedPassword  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWChangeObjectPassword (
        conn  :   NWCONN_HANDLE ;
        objName  :   pnstr8 ;
        objType  :   nuint16 ;
        oldPassword  :   pnstr8 ;
        newPassword  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWReadPropertyValue (
        conn  :   NWCONN_HANDLE ;
        objName  :   pnstr8 ;
        objType  :   nuint16 ;
        propertyName  :   pnstr8 ;
        segmentNum  :   nuint8 ;
        segmentData  :   pnuint8 ;
        moreSegments  :   pnuint8 ;
        flags  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWWritePropertyValue (
        conn  :   NWCONN_HANDLE ;
        objName  :   pnstr8 ;
        objType  :   nuint16 ;
        propertyName  :   pnstr8 ;
        segmentNum  :   nuint8 ;
        segmentData  :   pnuint8 ;
        moreSegments  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAddObjectToSet (
        conn  :   NWCONN_HANDLE ;
        objName  :   pnstr8 ;
        objType  :   nuint16 ;
        propertyName  :   pnstr8 ;
        memberName  :   pnstr8 ;
        memberType  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDeleteObjectFromSet (
        conn  :   NWCONN_HANDLE ;
        objName  :   pnstr8 ;
        objType  :   nuint16 ;
        propertyName  :   pnstr8 ;
        memberName  :   pnstr8 ;
        memberType  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWIsObjectInSet (
        conn  :   NWCONN_HANDLE ;
        objName  :   pnstr8 ;
        objType  :   nuint16 ;
        propertyName  :   pnstr8 ;
        memberName  :   pnstr8 ;
        memberType  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWScanProperty (
        conn  :   NWCONN_HANDLE ;
        objName  :   pnstr8 ;
        objType  :   nuint16 ;
        searchPropertyName  :   pnstr8 ;
        iterHandle  :   pnuint32 ;
        propertyName  :   pnstr8 ;
        propertyFlags  :   pnuint8 ;
        propertySecurity  :   pnuint8 ;
        valueAvailable  :   pnuint8 ;
        moreFlag  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetObjectID (
        conn  :   NWCONN_HANDLE ;
        objName  :   pnstr8 ;
        objType  :   nuint16 ;
        objID  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetObjectDiskSpaceLeft (
        conn  :   NWCONN_HANDLE ;
        objID  :   nuint32 ;
        systemElapsedTime  :   pnuint32 ;
        unusedDiskBlocks  :   pnuint32 ;
        restrictionEnforced  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetObjectName (
        conn  :   NWCONN_HANDLE ;
        objID  :   nuint32 ;
        objName  :   pnstr8 ;
        objType  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWScanObject (
        conn  :   NWCONN_HANDLE ;
        searchName  :   pnstr8 ;
        searchType  :   nuint16 ;
        objID  :   pnuint32 ;
        objName  :   pnstr8 ;
        objType  :   pnuint16 ;
        hasPropertiesFlag  :   pnuint8 ;
        objFlags  :   pnuint8 ;
        objSecurity  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetBinderyAccessLevel (
        conn  :   NWCONN_HANDLE ;
        accessLevel  :   pnuint8 ;
        objID  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCreateProperty (
        conn  :   NWCONN_HANDLE ;
        objName  :   pnstr8 ;
        objType  :   nuint16 ;
        propertyName  :   pnstr8 ;
        propertyFlags  :   nuint8 ;
        propertySecurity  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDeleteProperty (
        conn  :   NWCONN_HANDLE ;
        objName  :   pnstr8 ;
        objType  :   nuint16 ;
        propertyName  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWChangePropertySecurity (
        conn  :   NWCONN_HANDLE ;
        objName  :   pnstr8 ;
        objType  :   nuint16 ;
        propertyName  :   pnstr8 ;
        newPropertySecurity  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCreateObject (
        conn  :   NWCONN_HANDLE ;
        objName  :   pnstr8 ;
        objType  :   nuint16 ;
        objFlags  :   nuint8 ;
        objSecurity  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDeleteObject (
        conn  :   NWCONN_HANDLE ;
        objName  :   pnstr8 ;
        objType  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWRenameObject (
        conn  :   NWCONN_HANDLE ;
        oldObjName  :   pnstr8 ;
        newObjName  :   pnstr8 ;
        objType  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWChangeObjectSecurity (
        conn  :   NWCONN_HANDLE ;
        objName  :   pnstr8 ;
        objType  :   nuint16 ;
        newObjSecurity  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWOpenBindery (
        conn  :   NWCONN_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCloseBindery (
        conn  :   NWCONN_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWScanObjectTrusteePaths (
        conn  :   NWCONN_HANDLE ;
        objID  :   nuint32 ;
        volNum  :   nuint16 ;
        iterHandle  :   pnuint16 ;
        accessRights  :   pnuint8 ;
        dirPath  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetObjectEffectiveRights (
        conn  :   NWCONN_HANDLE ;
        objID  :   nuint32 ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        rightsMask  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetObjectEffectiveRights2 (
        conn  :   NWCONN_HANDLE ;
        objID  :   nuint32 ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        rightsMask  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
{$ENDIF}

