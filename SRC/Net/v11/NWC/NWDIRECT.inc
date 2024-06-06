(******************************************************************************

  %name: nwdirect.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:06:27 1996 %
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


{$IFNDEF  NWDIRECT_H }
    {$DEFINE NWDIRECT_H}
    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
    {$IFNDEF  NWAPIDEF_H }
        {$I nwapidef.inc}
    {$ENDIF}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$I npackon.inc}
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    Type
        DIR_SPACE_INFO = Record
            totalBlocks  :   nuint32 ;
            availableBlocks  :   nuint32 ;
            purgeableBlocks  :   nuint32 ;
            notYetPurgeableBlocks  :   nuint32 ;
            totalDirEntries  :   nuint32 ;
            availableDirEntries  :   nuint32 ;
            reserved  :   nuint32 ;
            sectorsPerBlock  :   nuint8 ;
            volLen  :   nuint8 ;
            volName  :  Array[0..NW_MAX_VOLUME_NAME_LEN-1] Of  nuint8 ;
        End;
    (* Trustee Access Rights in a network directory *)
    (* NOTE: TA_OPEN is obsolete in 3.x *)
    {$IFNDEF TA_NONE}
    {$DEFINE TA_NONE}
    Const TA_NONE = $00;
    {$DEFINE TA_READ}
    Const TA_READ = $01;
    {$DEFINE TA_WRITE}
    Const TA_WRITE = $02;
    {$DEFINE TA_OPEN}
    Const TA_OPEN = $04;
    {$DEFINE TA_CREATE}
    Const TA_CREATE = $08;
    {$DEFINE TA_DELETE}
    Const TA_DELETE = $10;
    {$DEFINE TA_OWNERSHIP}
    Const TA_OWNERSHIP = $20;
    {$DEFINE TA_SEARCH}
    Const TA_SEARCH = $40;
    {$DEFINE TA_MODIFY}
    Const TA_MODIFY = $80;
    {$DEFINE TA_ALL}
    Const TA_ALL = $FB;
    {$ENDIF}
    Type
        TRUSTEE_INFO = Record
            objectID  :   nuint32 ;
            objectRights  :   nuint16 ;
        End;
    Type
        NW_LIMIT_LIST = Record
            numEntries  :   nuint8 ;
            list : Array[0..101] of Record
                level  :   nuint8 ;
                max  :   nuint32 ;
                current  :   nuint32 ;
            End;
        End;
    Function NWAddTrusteeToDirectory (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        trusteeID  :   nuint32 ;
        rightsMask  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDeleteTrusteeFromDirectory (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        objID  :   nuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetEffectiveDirectoryRights (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        rightsMask  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWModifyMaximumRightsMask (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        revokeRightsMask  :   nuint8 ;
        grantRightsMask  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWScanDirectoryForTrustees (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        searchPath  :   pnstr8 ;
        iterHandle  :   pnuint16 ;
        dirName  :   pnstr8 ;
        dirDateTime  :   pnuint32 ;
        ownerID  :   pnuint32 ;
        trusteeIDs  :   pnuint32 ;
        trusteeRights  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWScanDirectoryForTrustees2 (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        searchPath  :   pnstr8 ;
        iterHandle  :   pnuint32 ;
        dirName  :   pnstr8 ;
        dirDateTime  :   pnuint32 ;
        ownerID  :   pnuint32 ;
        Var trusteeList  : TRUSTEE_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWScanDirectoryInformation ( a , b , c , d , e , f , g , h ) NWIntScanDirectoryInformation ( a , b , c , d , e , f , g , h , 0 )  *)
    Function NWIntScanDirectoryInformation (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        searchPath  :   pnstr8 ;
        iterHandle  :   pnuint16 ;
        dirName  :   pnstr8 ;
        dirDateTime  :   pnuint32 ;
        ownerID  :   pnuint32 ;
        rightsMask  :   pnuint8 ;
        augmentFlag  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWScanDirectoryInformation2 ( a , b , c , d , e , f , g , h ) NWIntScanDirectoryInformation2 ( a , b , c , d , e , f , g , h , 0 )  *)
    Function NWIntScanDirectoryInformation2 (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        searchPath  :   pnstr8 ;
        sequence  :   pnuint8 ;
        dirName  :   pnstr8 ;
        dirDateTime  :   pnuint32 ;
        ownerID  :   pnuint32 ;
        rightsMask  :   pnuint8 ;
        augmentFlag  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSetDirectoryInformation (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        dirDateTime  :   nuint32 ;
        ownerID  :   nuint32 ;
        rightsMask  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSaveDirectoryHandle (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        saveBuffer  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWRestoreDirectoryHandle (
        conn  :   NWCONN_HANDLE ;
        saveBuffer  :   pnstr8 ;
        Var newDirHandle  : NWDIR_HANDLE;
        rightsMask  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAllocPermanentDirectoryHandle (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        dirPath  :   pnstr8 ;
        Var newDirHandle  : NWDIR_HANDLE;
        effectiveRights  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAllocTemporaryDirectoryHandle (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        dirPath  :   pnstr8 ;
        Var newDirHandle  : NWDIR_HANDLE;
        rightsMask  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDeallocateDirectoryHandle (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSetDirectoryHandlePath (
        conn  :   NWCONN_HANDLE ;
        sourceDirHandle  :   NWDIR_HANDLE ;
        dirPath  :   pnstr8 ;
        destDirHandle  :   NWDIR_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetDirectoryHandlePath (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        dirPath  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCreateDirectory (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        dirPath  :   pnstr8 ;
        accessMask  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDeleteDirectory (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        dirPath  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWRenameDirectory (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        oldName  :   pnstr8 ;
        newName  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSetDirSpaceLimit (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        spaceLimit  :   nuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetDirSpaceLimitList (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        returnBuf  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetDirSpaceInfo (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        volNum  :   nuint16 ;
        Var spaceInfo  : DIR_SPACE_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFNDEF TF_READ_ONLY}
    {$DEFINE TF_NORMAL}
    Const TF_NORMAL = $0000;
    {$DEFINE TF_READ_ONLY}
    Const TF_READ_ONLY = $0001;
    {$DEFINE TF_HIDDEN}
    Const TF_HIDDEN = $0002;
    {$DEFINE TF_SYSTEM}
    Const TF_SYSTEM = $0004;
    {$DEFINE TF_EXECUTE_ONLY}
    Const TF_EXECUTE_ONLY = $0008;
    {$DEFINE TF_DIRECTORY}
    Const TF_DIRECTORY = $0010;
    {$DEFINE TF_NEEDS_ARCHIVED}
    Const TF_NEEDS_ARCHIVED = $0020;
    {$DEFINE TF_EXECUTE_CONFIRM}
    Const TF_EXECUTE_CONFIRM = $0040;
    {$DEFINE TF_SHAREABLE}
    Const TF_SHAREABLE = $0080;
    {$DEFINE TF_LOW_SEARCH_BIT}
    Const TF_LOW_SEARCH_BIT = $0100;
    {$DEFINE TF_MID_SEARCH_BIT}
    Const TF_MID_SEARCH_BIT = $0200;
    {$DEFINE TF_HI_SEARCH_BIT}
    Const TF_HI_SEARCH_BIT = $0400;
    {$DEFINE TF_PRIVATE}
    Const TF_PRIVATE = $0800;
    {$DEFINE TF_TRANSACTIONAL}
    Const TF_TRANSACTIONAL = $1000;
    {$DEFINE TF_INDEXED}
    Const TF_INDEXED = $2000;
    {$DEFINE TF_READ_AUDIT}
    Const TF_READ_AUDIT = $4000;
    {$DEFINE TF_WRITE_AUDIT}
    Const TF_WRITE_AUDIT = $8000;
    {$DEFINE TF_PURGE}
    Const TF_PURGE = $10000;
    {$DEFINE TF_RENAME_INHIBIT}
    Const TF_RENAME_INHIBIT = $20000;
    {$DEFINE TF_DELETE_INHIBIT}
    Const TF_DELETE_INHIBIT = $40000;
    {$DEFINE TF_COPY_INHIBIT}
    Const TF_COPY_INHIBIT = $80000;
    {$DEFINE TF_AUDITING_BIT}
    Const TF_AUDITING_BIT = $00100000;
    {$ENDIF}
    (* DIRECTORY ATTRIBUTES *)
    {$DEFINE TD_HIDDEN}
    Const TD_HIDDEN = TF_HIDDEN;
    {$DEFINE TD_SYSTEM}
    Const TD_SYSTEM = TF_SYSTEM;
    {$DEFINE TD_PURGE}
    Const TD_PURGE = TF_PURGE;
    {$DEFINE TD_PRIVATE}
    Const TD_PRIVATE = TF_PRIVATE;
    {$DEFINE TD_VISIBLE}
    Const TD_VISIBLE = TF_PRIVATE;
    {$DEFINE TD_RENAME_INHIBIT}
    Const TD_RENAME_INHIBIT = TF_RENAME_INHIBIT;
    {$DEFINE TD_DELETE_INHIBIT}
    Const TD_DELETE_INHIBIT = TF_DELETE_INHIBIT;
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

