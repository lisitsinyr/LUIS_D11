(******************************************************************************

  %name: nwnamspc.h %
  %version: 6 %
  %date_modified: Wed May  7 09:57:19 1997 %
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


{$IFNDEF  NWNAMSPC_H }
    {$DEFINE NWNAMSPC_H}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$I npackon.inc}
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    {$IFNDEF SUCCESSFUL}
    {$DEFINE SUCCESSFUL}
    Const SUCCESSFUL = 0;
    {$ENDIF}
    {$DEFINE MORE_NS_TO_READ}
    Const MORE_NS_TO_READ = 0;
    {$DEFINE NO_EXTENDED_NS_INFO}
    Const NO_EXTENDED_NS_INFO = 9;
    {$DEFINE NS_EOF}
    Const NS_EOF = $8910;
    {$DEFINE NW_NS_DOS}
    Const NW_NS_DOS = 0;
    {$DEFINE NW_NS_MAC}
    Const NW_NS_MAC = 1;
    {$DEFINE NW_NS_NFS}
    Const NW_NS_NFS = 2;
    {$DEFINE NW_NS_FTAM}
    Const NW_NS_FTAM = 3;
    {$DEFINE NW_NS_OS2}
    Const NW_NS_OS2 = 4;
    {$DEFINE NW_NS_LONG}
    Const NW_NS_LONG = 4;
    {$DEFINE NW_DS_DOS}
    Const NW_DS_DOS = 0;
    {$DEFINE NW_DS_MAC}
    Const NW_DS_MAC = 1;
    {$DEFINE NW_DS_FTAM}
    Const NW_DS_FTAM = 2;
    Type
        NW_IDX = Record
            volNumber  :   nuint8 ;
            srcNameSpace  :   nuint8 ;
            srcDirBase  :   nuint32 ;
            dstNameSpace  :   nuint8 ;
            dstDirBase  :   nuint32 ;
        End;
    Type
        NW_NS_INFO = Record
            NSInfoBitMask  :   nuint32 ;
            fixedBitMask  :   nuint32 ;
            reservedBitMask  :   nuint32 ;
            extendedBitMask  :   nuint32 ;
            fixedBitsDefined  :   nuint16 ;
            reservedBitsDefined  :   nuint16 ;
            extendedBitsDefined  :   nuint16 ;
            fieldsLenTable  :  Array[0..31] Of  nuint32 ;
            hugeStateInfo  :  Array[0..15] Of  nuint8 ;
            hugeDataLength  :   nuint32 ;
        End;
    Type
        NW_ENTRY_INFO = Record
            spaceAlloc  :   nuint32 ;
            attributes  :   nuint32 ;
            flags  :   nuint16 ;
            dataStreamSize  :   nuint32 ;
            totalStreamSize  :   nuint32 ;
            numberOfStreams  :   nuint16 ;
            creationTime  :   nuint16 ;
            creationDate  :   nuint16 ;
            creatorID  :   nuint32 ;
            modifyTime  :   nuint16 ;
            modifyDate  :   nuint16 ;
            modifierID  :   nuint32 ;
            lastAccessDate  :   nuint16 ;
            archiveTime  :   nuint16 ;
            archiveDate  :   nuint16 ;
            archiverID  :   nuint32 ;
            inheritedRightsMask  :   nuint16 ;
            dirEntNum  :   nuint32 ;
            DosDirNum  :   nuint32 ;
            volNumber  :   nuint32 ;
            EADataSize  :   nuint32 ;
            EAKeyCount  :   nuint32 ;
            EAKeySize  :   nuint32 ;
            NSCreator  :   nuint32 ;
            nameLength  :   nuint8 ;
            entryName  :  Array[0..255] Of  nstr8 ;
        End;
    Type
        _MODIFY_DOS_INFO = Record
            attributes  :   nuint32 ;
            createDate  :   nuint16 ;
            createTime  :   nuint16 ;
            creatorID  :   nuint32 ;
            modifyDate  :   nuint16 ;
            modifyTime  :   nuint16 ;
            modifierID  :   nuint32 ;
            archiveDate  :   nuint16 ;
            archiveTime  :   nuint16 ;
            archiverID  :   nuint32 ;
            lastAccessDate  :   nuint16 ;
            inheritanceGrantMask  :   nuint16 ;
            inheritanceRevokeMask  :   nuint16 ;
            maximumSpace  :   nuint32 ;
        End;
        MODIFY_DOS_INFO = _MODIFY_DOS_INFO;
    Type
        SEARCH_SEQUENCE = Record
            volNumber  :   nuint8 ;
            dirNumber  :   nuint32 ;
            searchDirNumber  :   nuint32 ;
        End;
    Type
        NW_NS_PATH = Record
            srcPath  :   pnstr8 ;
            dstPath  :   pnstr8 ;
            dstPathSize  :   nuint16 ;
        End;
    Type
        NW_NS_OPENCREATE = Record
            openCreateMode  :   nuint8 ;
            searchAttributes  :   nuint16 ;
            reserved  :   nuint32 ;
            createAttributes  :   nuint32 ;
            accessRights  :   nuint16 ;
            NetWareHandle  :   nuint32 ;
            openCreateAction  :   nuint8 ;
        End;
        NW_NS_OPEN = NW_NS_OPENCREATE;
    (* open/create modes *)
    {$DEFINE OC_MODE_OPEN}
    Const OC_MODE_OPEN = $01;
    {$DEFINE OC_MODE_TRUNCATE}
    Const OC_MODE_TRUNCATE = $02;
    {$DEFINE OC_MODE_REPLACE}
    Const OC_MODE_REPLACE = $02;
    {$DEFINE OC_MODE_CREATE}
    Const OC_MODE_CREATE = $08;
    (* open/create results *)
    {$DEFINE OC_ACTION_NONE}
    Const OC_ACTION_NONE = $00;
    {$DEFINE OC_ACTION_OPEN}
    Const OC_ACTION_OPEN = $01;
    {$DEFINE OC_ACTION_CREATE}
    Const OC_ACTION_CREATE = $02;
    {$DEFINE OC_ACTION_TRUNCATE}
    Const OC_ACTION_TRUNCATE = $04;
    {$DEFINE OC_ACTION_REPLACE}
    Const OC_ACTION_REPLACE = $04;
    (* return info mask *)
    {$DEFINE IM_NAME}
    Const IM_NAME = $0001;
    {$DEFINE IM_ENTRY_NAME}
    Const IM_ENTRY_NAME = $0001;
    {$DEFINE IM_SPACE_ALLOCATED}
    Const IM_SPACE_ALLOCATED = $0002;
    {$DEFINE IM_ATTRIBUTES}
    Const IM_ATTRIBUTES = $0004;
    {$DEFINE IM_SIZE}
    Const IM_SIZE = $0008;
    {$DEFINE IM_TOTAL_SIZE}
    Const IM_TOTAL_SIZE = $0010;
    {$DEFINE IM_EA}
    Const IM_EA = $0020;
    {$DEFINE IM_ARCHIVE}
    Const IM_ARCHIVE = $0040;
    {$DEFINE IM_MODIFY}
    Const IM_MODIFY = $0080;
    {$DEFINE IM_CREATION}
    Const IM_CREATION = $0100;
    {$DEFINE IM_OWNING_NAMESPACE}
    Const IM_OWNING_NAMESPACE = $0200;
    {$DEFINE IM_DIRECTORY}
    Const IM_DIRECTORY = $0400;
    {$DEFINE IM_RIGHTS}
    Const IM_RIGHTS = $0800;
    {$DEFINE IM_ALMOST_ALL}
    Const IM_ALMOST_ALL = $0FED;
    {$DEFINE IM_ALL}
    Const IM_ALL = $0FFF;
    {$DEFINE IM_REFERENCE_ID}
    Const IM_REFERENCE_ID = $1000;
    {$DEFINE IM_NS_ATTRIBUTES}
    Const IM_NS_ATTRIBUTES = $2000;
    {$DEFINE IM_DATASTREAM_SIZES}
    Const IM_DATASTREAM_SIZES = $4000;
    {$DEFINE IM_NSS_LARGE_SIZES}
    Const IM_NSS_LARGE_SIZES = $40000000;
    {$DEFINE IM_COMPRESSED_INFO}
    Const IM_COMPRESSED_INFO = $80000000;
    {$DEFINE IM_NS_SPECIFIC_INFO}
    Const IM_NS_SPECIFIC_INFO = $80000000;
    (* access rights attributes *)
    {$IFNDEF AR_READ_ONLY}
    {$DEFINE AR_READ}
    Const AR_READ = $0001;
    {$DEFINE AR_WRITE}
    Const AR_WRITE = $0002;
    {$DEFINE AR_READ_ONLY}
    Const AR_READ_ONLY = $0001;
    {$DEFINE AR_WRITE_ONLY}
    Const AR_WRITE_ONLY = $0002;
    {$DEFINE AR_DENY_READ}
    Const AR_DENY_READ = $0004;
    {$DEFINE AR_DENY_WRITE}
    Const AR_DENY_WRITE = $0008;
    {$DEFINE AR_COMPATIBILITY}
    Const AR_COMPATIBILITY = $0010;
    {$DEFINE AR_WRITE_THROUGH}
    Const AR_WRITE_THROUGH = $0040;
    {$DEFINE AR_OPEN_COMPRESSED}
    Const AR_OPEN_COMPRESSED = $0100;
    {$ENDIF}
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
    (* search attributes *)
    {$IFNDEF SA_HIDDEN}
    {$DEFINE SA_NORMAL}
    Const SA_NORMAL = $0000;
    {$DEFINE SA_HIDDEN}
    Const SA_HIDDEN = $0002;
    {$DEFINE SA_SYSTEM}
    Const SA_SYSTEM = $0004;
    {$DEFINE SA_SUBDIR_ONLY}
    Const SA_SUBDIR_ONLY = $0010;
    {$DEFINE SA_SUBDIR_FILES}
    Const SA_SUBDIR_FILES = $8000;
    {$DEFINE SA_ALL}
    Const SA_ALL = $8006;
    {$ENDIF}
    {$DEFINE NW_TYPE_FILE}
    Const NW_TYPE_FILE = $8000;
    {$DEFINE NW_TYPE_SUBDIR}
    Const NW_TYPE_SUBDIR = $0010;
    {$DEFINE NW_NAME_CONVERT}
    Const NW_NAME_CONVERT = $03;
    {$DEFINE NW_NO_NAME_CONVERT}
    Const NW_NO_NAME_CONVERT = $04;
    (* modify mask - use with MODIFY_DOS_INFO structure *)
    {$DEFINE DM_ATTRIBUTES}
    Const DM_ATTRIBUTES = $0002;
    {$DEFINE DM_CREATE_DATE}
    Const DM_CREATE_DATE = $0004;
    {$DEFINE DM_CREATE_TIME}
    Const DM_CREATE_TIME = $0008;
    {$DEFINE DM_CREATOR_ID}
    Const DM_CREATOR_ID = $0010;
    {$DEFINE DM_ARCHIVE_DATE}
    Const DM_ARCHIVE_DATE = $0020;
    {$DEFINE DM_ARCHIVE_TIME}
    Const DM_ARCHIVE_TIME = $0040;
    {$DEFINE DM_ARCHIVER_ID}
    Const DM_ARCHIVER_ID = $0080;
    {$DEFINE DM_MODIFY_DATE}
    Const DM_MODIFY_DATE = $0100;
    {$DEFINE DM_MODIFY_TIME}
    Const DM_MODIFY_TIME = $0200;
    {$DEFINE DM_MODIFIER_ID}
    Const DM_MODIFIER_ID = $0400;
    {$DEFINE DM_LAST_ACCESS_DATE}
    Const DM_LAST_ACCESS_DATE = $0800;
    {$DEFINE DM_INHERITED_RIGHTS_MASK}
    Const DM_INHERITED_RIGHTS_MASK = $1000;
    {$DEFINE DM_MAXIMUM_SPACE}
    Const DM_MAXIMUM_SPACE = $2000;
    {$IFDEF  N_PLAT_NLM }
        Type NWGetNSLoadedList = NWGetNSLoadedList2;
        Type NWGetNSInfo = NWGetNSInfo2;
    {$ENDIF}
    Function NWGetDirectoryBase (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   nuint8 ;
        path  :   pnstr8 ;
        dstNamSpc  :   nuint8 ;
        Var idxStruct  : NW_IDX
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWScanNSEntryInfo (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   nuint8 ;
        namSpc  :   nuint8 ;
        attrs  :   nuint16 ;
        Var sequence  : SEARCH_SEQUENCE;
        searchPattern  :   pnstr8 ;
        retInfoMask  :   nuint32 ;
        Var entryInfo  : NW_ENTRY_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetNSLoadedList (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint8 ;
        maxListLen  :   nuint8 ;
        NSLoadedList  :   pnuint8 ;
        actualListLen  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetOwningNameSpace (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   nuint8 ;
        path  :   pnstr8 ;
        namSpc  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWOpenCreateNSEntry (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   nuint8 ;
        namSpc  :   nuint8 ;
        path  :   pnstr8 ;
        Var NSOpenCreate  : NW_NS_OPENCREATE;
        Var fileHandle  : NWFILE_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWOpenNSEntry (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   nuint8 ;
        namSpc  :   nuint8 ;
        dataStream  :   nuint8 ;
        path  :   pnstr8 ;
        Var NSOpen  : NW_NS_OPEN;
        Var fileHandle  : NWFILE_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSetLongName (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   nuint8 ;
        namSpc  :   nuint8 ;
        dstPath  :   pnstr8 ;
        dstType  :   nuint16 ;
        longName  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetLongName (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   nuint8 ;
        path  :   pnstr8 ;
        srcNamSpc  :   nuint8 ;
        dstNamSpc  :   nuint8 ;
        longName  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetNSInfo (
        conn  :   NWCONN_HANDLE ;
        Var idxStruct  : NW_IDX;
        Var NSInfo  : NW_NS_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWWriteNSInfo (
        conn  :   NWCONN_HANDLE ;
        Var idxStruct  : NW_IDX;
        Var NSInfo  : NW_NS_INFO;
        data  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWWriteExtendedNSInfo (
        conn  :   NWCONN_HANDLE ;
        Var idxStruct  : NW_IDX;
        Var NSInfo  : NW_NS_INFO;
        data  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWReadNSInfo (
        conn  :   NWCONN_HANDLE ;
        Var idxStruct  : NW_IDX;
        Var NSInfo  : NW_NS_INFO;
        data  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWReadExtendedNSInfo (
        conn  :   NWCONN_HANDLE ;
        Var idxStruct  : NW_IDX;
        Var NSInfo  : NW_NS_INFO;
        data  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetNSPath (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   nuint8 ;
        fileFlag  :   nuint16 ;
        srcNamSpc  :   nuint8 ;
        dstNamSpc  :   nuint8 ;
        Var NSPath  : NW_NS_PATH
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAllocTempNSDirHandle (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   nuint8 ;
        path  :   pnstr8 ;
        namSpc  :   nuint8 ;
        Var newDirHandle  : nuint8
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAllocTempNSDirHandle2 (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   nuint8 ;
        path  :   pnstr8 ;
        namSpc  :   nuint8 ;
        newDirHandle  :   pnuint8 ;
        newNamSpc  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetNSEntryInfo (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   nuint8 ;
        path  :   pnstr8 ;
        srcNamSpc  :   nuint8 ;
        dstNamSpc  :   nuint8 ;
        searchAttrs  :   nuint16 ;
        retInfoMask  :   nuint32 ;
        Var entryInfo  : NW_ENTRY_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWNSGetMiscInfo (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   nuint8 ;
        path  :   pnstr8 ;
        dstNameSpace  :   nuint8 ;
        Var idxStruct  : NW_IDX
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWOpenDataStream (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   nuint8 ;
        fileName  :   pnstr8 ;
        dataStream  :   nuint16 ;
        attrs  :   nuint16 ;
        accessMode  :   nuint16 ;
        NWHandle  :   pnuint32 ;
        Var fileHandle  : NWFILE_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWNSRename (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   nuint8 ;
        namSpc  :   nuint8 ;
        oldName  :   pnstr8 ;
        oldType  :   nuint16 ;
        newName  :   pnstr8 ;
        renameFlag  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSetNSEntryDOSInfo (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   nuint8 ;
        path  :   pnstr8 ;
        namSpc  :   nuint8 ;
        searchAttrs  :   nuint16 ;
        modifyDOSMask  :   nuint32 ;
        Var dosInfo  : MODIFY_DOS_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* Not implemented Function NWGetFullPath (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint8 ;
        dirBase  :   nuint32 ;
        handleFlag  :   nuint16 ;
        srcNamSpc  :   nint ;
        dstNamSpc  :   nint ;
        maxPathLen  :   nuint16 ;
        path  :   pnstr8 ;
        pathType  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    Function NWDeleteNSEntry (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        fileName  :   pnstr8 ;
        nameSpace  :   nuint8 ;
        searchAttr  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWNSGetDefaultNS (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        pbuDefaultNameSpace  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF NWDOS}
    (* TC #define __NWGetCurNS ( a , b , c ) NW_NS_DOS  *)
    Function __NWGetCurNS (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   nuint8 ;
        path  :   pnstr8 
    ) : nuint16;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  
{$ENDIF}


{$IFDEF  N_PLAT_NLM}
    (* Not implemented Function SetCurrentNameSpace (
        newNameSpace  :   nuint8 
    ) : nuint8;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function SetTargetNameSpace (
        newNameSpace  :   nuint8 
    ) : nuint8;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
{$ENDIF}


{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}


{$I npackoff.inc}
{$ENDIF}

