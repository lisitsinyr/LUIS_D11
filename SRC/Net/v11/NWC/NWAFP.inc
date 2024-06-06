(******************************************************************************

  %name: nwafp.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:05:19 1996 %
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


{$IFNDEF  NWAFP_H }
    {$DEFINE NWAFP_H}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$I npackon.inc}
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    (** This is the structure that the application expects to see. Note that the
    long name and short name will be null terminated, and one extra byte has
    been added to long name and short name to assure word alignment **)
    Type
        AFPFILEINFO = Record
            entryID  :   nuint32 ;
            parentID  :   nuint32 ;
            attributes  :   nuint16 ;
            dataForkLength  :   nuint32 ;
            resourceForkLength  :   nuint32 ;
            numOffspring  :   nuint16 ;
            creationDate  :   nuint16 ;
            accessDate  :   nuint16 ;
            modifyDate  :   nuint16 ;
            modifyTime  :   nuint16 ;
            backupDate  :   nuint16 ;
            backupTime  :   nuint16 ;
            finderInfo  :  Array[0..31] Of  nuint8 ;
            longName  :  Array[0..33] Of  nstr8 ;
            ownerID  :   nuint32 ;
            shortName  :  Array[0..13] Of  nstr8 ;
            accessPrivileges  :   nuint16 ;
            proDOSInfo  :  Array[0..5] Of  nuint8 ;
        End;
        NW_AFP_FILE_INFO = AFPFILEINFO;
    (** This is the structure that is actually returned from the NCP call **)
    Type
        RECPKT_AFPFILEINFO = Record
            entryID  :   nuint32 ;
            parentID  :   nuint32 ;
            attributes  :   nuint16 ;
            dataForkLength  :   nuint32 ;
            resourceForkLength  :   nuint32 ;
            numOffspring  :   nuint16 ;
            creationDate  :   nuint16 ;
            accessDate  :   nuint16 ;
            modifyDate  :   nuint16 ;
            modifyTime  :   nuint16 ;
            backupDate  :   nuint16 ;
            backupTime  :   nuint16 ;
            finderInfo  :  Array[0..31] Of  nuint8 ;
            longName  :  Array[0..31] Of  nstr8 ;
            ownerID  :   nuint32 ;
            shortName  :  Array[0..11] Of  nstr8 ;
            accessPrivileges  :   nuint16 ;
            proDOSInfo  :  Array[0..5] Of  nuint8 ;
        End;
    Type
        AFPSETINFO = Record
            attributes  :   nuint16 ;
            creationDate  :   nuint16 ;
            accessDate  :   nuint16 ;
            modifyDate  :   nuint16 ;
            modifyTime  :   nuint16 ;
            backupDate  :   nuint16 ;
            backupTime  :   nuint16 ;
            finderInfo  :  Array[0..31] Of  nuint8 ;
            proDOSInfo  :  Array[0..5] Of  nuint8 ;
        End;
        NW_AFP_SET_INFO = AFPSETINFO;
    (* the following are the constants that can be used for requestMasks
   in NWAFPScanFileInformation and NWAFPGetFileInformation.
*)
    {$IFNDEF AFP_GET_ATTRIBUTES}
    {$DEFINE AFP_GET_ATTRIBUTES}
    Const AFP_GET_ATTRIBUTES = $0001;
    {$DEFINE AFP_GET_PARENT_ID}
    Const AFP_GET_PARENT_ID = $0002;
    {$DEFINE AFP_GET_CREATE_DATE}
    Const AFP_GET_CREATE_DATE = $0004;
    {$DEFINE AFP_GET_ACCESS_DATE}
    Const AFP_GET_ACCESS_DATE = $0008;
    {$DEFINE AFP_GET_MODIFY_DATETIME}
    Const AFP_GET_MODIFY_DATETIME = $0010;
    {$DEFINE AFP_GET_BACKUP_DATETIME}
    Const AFP_GET_BACKUP_DATETIME = $0020;
    {$DEFINE AFP_GET_FINDER_INFO}
    Const AFP_GET_FINDER_INFO = $0040;
    {$DEFINE AFP_GET_LONG_NAME}
    Const AFP_GET_LONG_NAME = $0080;
    {$DEFINE AFP_GET_ENTRY_ID}
    Const AFP_GET_ENTRY_ID = $0100;
    {$DEFINE AFP_GET_DATA_LEN}
    Const AFP_GET_DATA_LEN = $0200;
    {$DEFINE AFP_GET_RESOURCE_LEN}
    Const AFP_GET_RESOURCE_LEN = $0400;
    {$DEFINE AFP_GET_NUM_OFFSPRING}
    Const AFP_GET_NUM_OFFSPRING = $0800;
    {$DEFINE AFP_GET_OWNER_ID}
    Const AFP_GET_OWNER_ID = $1000;
    {$DEFINE AFP_GET_SHORT_NAME}
    Const AFP_GET_SHORT_NAME = $2000;
    {$DEFINE AFP_GET_ACCESS_RIGHTS}
    Const AFP_GET_ACCESS_RIGHTS = $4000;
    {$DEFINE AFP_GET_PRO_DOS_INFO}
    Const AFP_GET_PRO_DOS_INFO = $8000;
    {$DEFINE AFP_GET_ALL}
    Const AFP_GET_ALL = $ffff;
    {$ENDIF}
    (*
  The following constants are used for NWAFPSetFileInformation
*)
    {$IFNDEF AFP_SET_ATTRIBUTES}
    {$DEFINE AFP_SET_ATTRIBUTES}
    Const AFP_SET_ATTRIBUTES = $0001;
    {$DEFINE AFP_SET_CREATE_DATE}
    Const AFP_SET_CREATE_DATE = $0004;
    {$DEFINE AFP_SET_ACCESS_DATE}
    Const AFP_SET_ACCESS_DATE = $0008;
    {$DEFINE AFP_SET_MODIFY_DATETIME}
    Const AFP_SET_MODIFY_DATETIME = $0010;
    {$DEFINE AFP_SET_BACKUP_DATETIME}
    Const AFP_SET_BACKUP_DATETIME = $0020;
    {$DEFINE AFP_SET_FINDER_INFO}
    Const AFP_SET_FINDER_INFO = $0040;
    {$DEFINE AFP_SET_PRO_DOS_INFO}
    Const AFP_SET_PRO_DOS_INFO = $8000;
    {$ENDIF}
    {$IFNDEF AFP_SA_HIDDEN}
    {$DEFINE AFP_SA_NORMAL}
    Const AFP_SA_NORMAL = $0000;
    {$DEFINE AFP_SA_HIDDEN}
    Const AFP_SA_HIDDEN = $0100;
    {$DEFINE AFP_SA_SYSTEM}
    Const AFP_SA_SYSTEM = $0200;
    {$DEFINE AFP_SA_SUBDIR}
    Const AFP_SA_SUBDIR = $0400;
    {$DEFINE AFP_SA_FILES}
    Const AFP_SA_FILES = $0800;
    {$DEFINE AFP_SA_ALL}
    Const AFP_SA_ALL = $0F00;
    {$ENDIF}
    Function NWAFPAllocTemporaryDirHandle (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint16 ;
        AFPEntryID  :   nuint32 ;
        AFPPathString  :   pnstr8 ;
        Var dirHandle  : NWDIR_HANDLE;
        accessRights  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAFPCreateDirectory (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint16 ;
        AFPEntryID  :   nuint32 ;
        finderInfo  :   pnuint8 ;
        AFPPathString  :   pnstr8 ;
        newAFPEntryID  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAFPCreateFile (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint16 ;
        AFPEntryID  :   nuint32 ;
        delExistingFile  :   nuint8 ;
        finderInfo  :   pnuint8 ;
        AFPPathString  :   pnstr8 ;
        newAFPEntryID  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAFPDelete (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint16 ;
        AFPEntryID  :   nuint32 ;
        AFPPathString  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAFPGetEntryIDFromName (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint16 ;
        AFPEntryID  :   nuint32 ;
        AFPPathString  :   pnstr8 ;
        newAFPEntryID  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAFPGetEntryIDFromHandle (
        conn  :   NWCONN_HANDLE ;
        NWHandle  :   pnuint8 ;
        volNum  :   pnuint16 ;
        AFPEntryID  :   pnuint32 ;
        forkIndicator  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAFPGetEntryIDFromPathName (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        AFPEntryID  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAFPGetFileInformation (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint16 ;
        AFPEntryID  :   nuint32 ;
        reqMask  :   nuint16 ;
        AFPPathString  :   pnstr8 ;
        structSize  :   nuint16 ;
        Var AFPFileInfo  : NW_AFP_FILE_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAFPDirectoryEntry (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAFPOpenFileFork (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint16 ;
        AFPEntryID  :   nuint32 ;
        forkIndicator  :   nuint8 ;
        accessMode  :   nuint8 ;
        AFPPathString  :   pnstr8 ;
        fileID  :   pnuint32 ;
        forkLength  :   pnuint32 ;
        NWHandle  :   pnuint8 ;
        Var DOSFileHandle  : NWFILE_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAFPRename (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint16 ;
        AFPSourceEntryID  :   nuint32 ;
        AFPDestEntryID  :   nuint32 ;
        AFPSrcPath  :   pnstr8 ;
        AFPDstPath  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAFPScanFileInformation (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint16 ;
        AFPEntryID  :   nuint32 ;
        AFPLastSeenID  :   pnuint32 ;
        searchMask  :   nuint16 ;
        reqMask  :   nuint16 ;
        AFPPathString  :   pnstr8 ;
        structSize  :   nuint16 ;
        Var AFPFileInfo  : NW_AFP_FILE_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAFPSetFileInformation (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint16 ;
        AFPBaseID  :   nuint32 ;
        reqMask  :   nuint16 ;
        AFPPathString  :   pnstr8 ;
        structSize  :   nuint16 ;
        Var AFPSetInfo  : NW_AFP_SET_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAFPSupported (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAFPASCIIZToLenStr (
        pbstrDstStr  :   pnstr8 ;
        pbstrSrcStr  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

