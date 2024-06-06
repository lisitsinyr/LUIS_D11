(******************************************************************************

  %name: nwdentry.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:06:21 1996 %
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


{$IFNDEF  NWDENTRY_H }
    {$DEFINE NWDENTRY_H}
    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$IFNDEF  NWDIRECT_H }
        {$I nwdirect.inc}
    {$ENDIF}
    {$I npackon.inc}
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    Type
        NWET_INFO = Record
            entryName  :  Array[0..15] Of  nstr8 ;
            creationDateAndTime  :   nuint32 ;
            ownerID  :   nuint32 ;
            sequenceNumber  :   nuint32 ;
            trusteeList  :  Array[0..19] Of  TRUSTEE_INFO ;
        End;
    Type
        NWFILE_INFO = Record
            updateDateAndTime  :   nuint32 ;
            updatorID  :   nuint32 ;
            fileSize  :   nuint32 ;
            reserved  :  Array[0..43] Of  nuint8 ;
            inheritedRightsMask  :   nuint16 ;
            lastAccessDate  :   nuint16 ;
            reserved2  :  Array[0..27] Of  nuint8 ;
        End;
    Type
        NWDIR_INFO = Record
            lastModifyDateAndTime  :   nuint32 ;
            nextTrusteeEntry  :   nuint32 ;
            reserved  :  Array[0..47] Of  nuint8 ;
            maximumSpace  :   nuint32 ;
            inheritedRightsMask  :   nuint16 ;
            reserved2  :  Array[0..13] Of  nuint8 ;
            volObjectID  :   nuint32 ;
            reserved3  :  Array[0..7] Of  nuint8 ;
        End;
    Type
        NWENTRY_INFO = Record
            sequence  :   nuint32 ;
            parent  :   nuint32 ;
            attributes  :   nuint32 ;
            uniqueID  :   nuint8 ;
            flags  :   nuint8 ;
            nameSpace  :   nuint8 ;
            nameLength  :   nuint8 ;
            name  :  Array[0..11] Of  nuint8 ;
            creationDateAndTime  :   nuint32 ;
            ownerID  :   nuint32 ;
            lastArchiveDateAndTime  :   nuint32 ;
            lastArchiverID  :   nuint32 ;
            file1  :   NWFILE_INFO ;  (* union statement *)
        End;
    Type
        NW_EXT_FILE_INFO = Record
            sequence  :   nuint32 ;
            parent  :   nuint32 ;
            attributes  :   nuint32 ;
            uniqueID  :   nuint8 ;
            flags  :   nuint8 ;
            nameSpace  :   nuint8 ;
            nameLength  :   nuint8 ;
            name  :  Array[0..11] Of  nuint8 ;
            creationDateAndTime  :   nuint32 ;
            ownerID  :   nuint32 ;
            lastArchiveDateAndTime  :   nuint32 ;
            lastArchiverID  :   nuint32 ;
            updateDateAndTime  :   nuint32 ;
            lastUpdatorID  :   nuint32 ;
            dataForkSize  :   nuint32 ;
            dataForkFirstFAT  :   nuint32 ;
            nextTrusteeEntry  :   nuint32 ;
            reserved  :  Array[0..35] Of  nuint8 ;
            inheritedRightsMask  :   nuint16 ;
            lastAccessDate  :   nuint16 ;
            deletedFileTime  :   nuint32 ;
            deletedDateAndTime  :   nuint32 ;
            deletorID  :   nuint32 ;
            reserved2  :  Array[0..15] Of  nuint8 ;
            otherForkSize  :  Array[0..1] Of  nuint32 ;
        End;
    {$DEFINE TR_NONE}
    Const TR_NONE = $0000;
    {$DEFINE TR_READ}
    Const TR_READ = $0001;
    {$DEFINE TR_WRITE}
    Const TR_WRITE = $0002;
    {$DEFINE TR_OPEN}
    Const TR_OPEN = $0004;
    {$DEFINE TR_DIRECTORY}
    Const TR_DIRECTORY = $0004;
    {$DEFINE TR_CREATE}
    Const TR_CREATE = $0008;
    {$DEFINE TR_DELETE}
    Const TR_DELETE = $0010;
    {$DEFINE TR_ERASE}
    Const TR_ERASE = $0010;
    {$DEFINE TR_OWNERSHIP}
    Const TR_OWNERSHIP = $0020;
    {$DEFINE TR_ACCESS_CTRL}
    Const TR_ACCESS_CTRL = $0020;
    {$DEFINE TR_FILE_SCAN}
    Const TR_FILE_SCAN = $0040;
    {$DEFINE TR_SEARCH}
    Const TR_SEARCH = $0040;
    {$DEFINE TR_FILE_ACCESS}
    Const TR_FILE_ACCESS = $0040;
    {$DEFINE TR_MODIFY}
    Const TR_MODIFY = $0080;
    {$DEFINE TR_ALL}
    Const TR_ALL = $01FB;
    {$DEFINE TR_SUPERVISOR}
    Const TR_SUPERVISOR = $0100;
    {$DEFINE TR_NORMAL}
    Const TR_NORMAL = $00FB;
    {$IFNDEF MModifyNameBit}
    {$DEFINE MModifyNameBit}
    Const MModifyNameBit = $0001;
    {$DEFINE MFileAttributesBit}
    Const MFileAttributesBit = $0002;
    {$DEFINE MCreateDateBit}
    Const MCreateDateBit = $0004;
    {$DEFINE MCreateTimeBit}
    Const MCreateTimeBit = $0008;
    {$DEFINE MOwnerIDBit}
    Const MOwnerIDBit = $0010;
    {$DEFINE MLastArchivedDateBit}
    Const MLastArchivedDateBit = $0020;
    {$DEFINE MLastArchivedTimeBit}
    Const MLastArchivedTimeBit = $0040;
    {$DEFINE MLastArchivedIDBit}
    Const MLastArchivedIDBit = $0080;
    {$DEFINE MLastUpdatedDateBit}
    Const MLastUpdatedDateBit = $0100;
    {$DEFINE MLastUpdatedTimeBit}
    Const MLastUpdatedTimeBit = $0200;
    {$DEFINE MLastUpdatedIDBit}
    Const MLastUpdatedIDBit = $0400;
    {$DEFINE MLastAccessedDateBit}
    Const MLastAccessedDateBit = $0800;
    {$DEFINE MInheritedRightsMaskBit}
    Const MInheritedRightsMaskBit = $1000;
    {$DEFINE MMaximumSpaceBit}
    Const MMaximumSpaceBit = $2000;
    {$ENDIF}
    Function NWDeleteTrustee (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        dirPath  :   pnstr8 ;
        objID  :   nuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAddTrustee (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        objID  :   nuint32 ;
        rightsMask  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWScanDirEntryInfo ( a , b , c , d , e , f ) NWIntScanDirEntryInfo ( a , b , c , d , e , f , 0 )  *)
    Function NWIntScanDirEntryInfo (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        attrs  :   nuint16 ;
        iterHandle  :   pnuint32 ;
        searchPattern  :   pnuint8 ;
        Var entryInfo  : NWENTRY_INFO;
        augmentFlag  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWScanForTrustees ( a , b , c , d , e , f ) NWIntScanForTrustees ( a , b , c , d , e , f , 0 )  *)
    Function NWIntScanForTrustees (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        iterHandle  :   pnuint32 ;
        numOfEntries  :   pnuint16 ;
        Var entryTrusteeInfo  : NWET_INFO;
        augmentFlag  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWMoveDirEntry ( a , b , c , d , e , f ) NWIntMoveDirEntry ( a , b , c , d , e , f , 0 )  *)
    Function NWIntMoveDirEntry (
        conn  :   NWCONN_HANDLE ;
        searchAttrs  :   nuint8 ;
        srcDirHandle  :   NWDIR_HANDLE ;
        srcPath  :   pnstr8 ;
        dstDirHandle  :   NWDIR_HANDLE ;
        dstPath  :   pnstr8 ;
        augmentFlag  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSetDirEntryInfo (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        searchAttrs  :   nuint8 ;
        iterHandle  :   nuint32 ;
        changeBits  :   nuint32 ;
        Var newEntryInfo  : NWENTRY_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWScanExtendedInfo ( a , b , c , d , e , f ) NWIntScanExtendedInfo ( a , b , c , d , e , f , 0 )  *)
    Function NWIntScanExtendedInfo (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        attrs  :   nuint8 ;
        iterHandle  :   pnuint32 ;
        searchPattern  :   pnstr8 ;
        Var entryInfo  : NW_EXT_FILE_INFO;
        augmentFlag  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetEffectiveRights (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        effectiveRights  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

