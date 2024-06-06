(******************************************************************************

  %name: nwfile.h %
  %version: 5 %
  %date_modified: Wed Mar 12 09:38:07 1997 %
  $Copyright:

  Copyright (c) 1989-1997 Novell, Inc.  All Rights Reserved.                      

  THIS WORK IS  SUBJECT  TO  U.S.  AND  INTERNATIONAL  COPYRIGHT  LAWS  AND
  TREATIES.   NO  PART  OF  THIS  WORK MAY BE  USED,  PRACTICED,  PERFORMED
  COPIED, DISTRIBUTED, REVISED, MODIFIED, TRANSLATED,  ABRIDGED, CONDENSED,
  EXPANDED,  COLLECTED,  COMPILED,  LINKED,  RECAST, TRANSFORMED OR ADAPTED
  WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC. ANY USE OR EXPLOITATION
  OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT THE PERPETRATOR TO
  CRIMINAL AND CIVIL LIABILITY.$

 *****************************************************************************)


{$IFNDEF  NWFILE_H }
    {$DEFINE NWFILE_H}
    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$I npackon.inc}
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    {$IFNDEF FILE_LOCKS_ONLY}
    Type
        NW_FILE_INFO = Record
            fileName  :  Array[0..13] Of  nstr8 ;
            fileAttributes  :   nuint8 ;
            extendedFileAttributes  :   nuint8 ;
            fileSize  :   nuint32 ;
            creationDate  :   nuint16 ;
            lastAccessDate  :   nuint16 ;
            lastUpdateDateAndTime  :   nuint32 ;
            fileOwnerID  :   nuint32 ;
            lastArchiveDateAndTime  :   nuint32 ;
        End;
    Type
        NW_FILE_INFO2 = Record
            fileAttributes  :   nuint8 ;
            extendedFileAttributes  :   nuint8 ;
            fileSize  :   nuint32 ;
            creationDate  :   nuint16 ;
            lastAccessDate  :   nuint16 ;
            lastUpdateDateAndTime  :   nuint32 ;
            fileOwnerID  :   nuint32 ;
            lastArchiveDateAndTime  :   nuint32 ;
            fileName  :  Array[0..259] Of  nstr8 ;
        End;
    Type
        SEARCH_FILE_INFO = Record
            sequenceNumber  :   nuint16 ;
            reserved  :   nuint16 ;
            fileName  :  Array[0..14] Of  nstr8 ;
            fileAttributes  :   nuint8 ;
            fileMode  :   nuint8 ;
            fileLength  :   nuint32 ;
            createDate  :   nuint16 ;
            accessDate  :   nuint16 ;
            updateDate  :   nuint16 ;
            updateTime  :   nuint16 ;
        End;
    Type
        SEARCH_DIR_INFO = Record
            sequenceNumber  :   nuint16 ;
            reserved1  :   nuint16 ;
            directoryName  :  Array[0..14] Of  nstr8 ;
            directoryAttributes  :   nuint8 ;
            directoryAccessRights  :   nuint8 ;
            createDate  :   nuint16 ;
            createTime  :   nuint16 ;
            owningObjectID  :   nuint32 ;
            reserved2  :   nuint16 ;
            directoryStamp  :   nuint16 ;
        End;
    Type
        CONN_OPEN_FILE = Record
            taskNumber  :   nuint8 ;
            lockType  :   nuint8 ;
            accessControl  :   nuint8 ;
            lockFlag  :   nuint8 ;
            volNumber  :   nuint8 ;
            dirEntry  :   nuint16 ;
            fileName  :  Array[0..13] Of  nstr8 ;
        End;
    Type
        CONN_OPEN_FILES = Record
            nextRequest  :   nuint16 ;
            connCount  :   nuint8 ;
            connInfo  :  Array[0..21] Of  CONN_OPEN_FILE ;
        End;
    Type
        OPEN_FILE_CONN = Record
            taskNumber  :   nuint16 ;
            lockType  :   nuint8 ;
            accessControl  :   nuint8 ;
            lockFlag  :   nuint8 ;
            volNumber  :   nuint8 ;
            parent  :   nuint32 ;
            dirEntry  :   nuint32 ;
            forkCount  :   nuint8 ;
            nameSpace  :   nuint8 ;
            nameLen  :   nuint8 ;
            fileName  :  Array[0..254] Of  nstr8 ;
        End;
    Type
        OPEN_FILE_CONN_CTRL = Record
            nextRequest  :   nuint16 ;
            openCount  :   nuint16 ;
            buffer  :  Array[0..511] Of  nuint8 ;
            curRecord  :   nuint16 ;
        End;
    Type
        CONN_USING_FILE = Record
            connNumber  :   nuint16 ;
            taskNumber  :   nuint16 ;
            lockType  :   nuint8 ;
            accessControl  :   nuint8 ;
            lockFlag  :   nuint8 ;
        End;
    Type
        CONNS_USING_FILE = Record
            nextRequest  :   nuint16 ;
            useCount  :   nuint16 ;
            openCount  :   nuint16 ;
            openForReadCount  :   nuint16 ;
            openForWriteCount  :   nuint16 ;
            denyReadCount  :   nuint16 ;
            denyWriteCount  :   nuint16 ;
            locked  :   nuint8 ;
            forkCount  :   nuint8 ;
            connCount  :   nuint16 ;
            connInfo  :  Array[0..69] Of  CONN_USING_FILE ;
        End;
    {$DEFINE SEEK_FROM_BEGINNING}
    Const SEEK_FROM_BEGINNING = 1;
    {$DEFINE SEEK_FROM_CURRENT_OFFSET}
    Const SEEK_FROM_CURRENT_OFFSET = 2;
    {$DEFINE SEEK_FROM_END}
    Const SEEK_FROM_END = 3;
    (* The following flags are to be used in the createFlag parameter of
   the NWCreateFile call. *)
    {$DEFINE NWCREATE_NEW_FILE}
    Const NWCREATE_NEW_FILE = 1;
    {$DEFINE NWOVERWRITE_FILE}
    Const NWOVERWRITE_FILE = 2;
    Function NWSetCompressedFileSize (
        conn  :   NWCONN_HANDLE ;
        fileHandle  :   NWFILE_HANDLE ;
        reqFileSize  :   nuint32 ;
        resFileSize  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWFileServerFileCopy (
        srcFileHandle  :   NWFILE_HANDLE ;
        dstFileHandle  :   NWFILE_HANDLE ;
        srcOffset  :   nuint32 ;
        dstOffset  :   nuint32 ;
        bytesToCopy  :   nuint32 ;
        bytesCopied  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetFileConnectionID (
        fileHandle  :   NWFILE_HANDLE ;
        Var conn  : NWCONN_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetFileConnRef (
        fileHandle  :   NWFILE_HANDLE ;
        connRef  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWIntFileSearchInitialize ( a , b , c , d , e , f , g , h ) NWFileSearchInitialize ( a , b , c , d , e , f , g )  *)
    Function NWFileSearchInitialize (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        volNum  :   pnuint8 ;
        dirID  :   pnuint16 ;
        iterhandle  :   pnuint16 ;
        accessRights  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWFileSearchContinue ( a , b , c , d , e , f , g ) NWIntFileSearchContinue ( a , b , c , d , e , f , g , 0 )  *)
    Function NWIntFileSearchContinue (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint8 ;
        dirID  :   nuint16 ;
        searchContext  :   nuint16 ;
        searchAttr  :   nuint8 ;
        searchPath  :   pnstr8 ;
        retBuf  :   pnuint8 ;
        augmentFlag  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWScanFileInformation ( a , b , c , d , e , f ) NWIntScanFileInformation ( a , b , c , d , e , f , 0 )  *)
    Function NWIntScanFileInformation (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        filePattern  :   pnstr8 ;
        searchAttr  :   nuint8 ;
        iterhandle  :   pnint16 ;
        Var info  : NW_FILE_INFO;
        augmentFlag  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSetFileInformation (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        fileName  :   pnstr8 ;
        searchAttrs  :   nuint8 ;
        Var info  : NW_FILE_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSetFileInformation2 (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        fileName  :   pnstr8 ;
        searchAttrs  :   nuint8 ;
        Var info  : NW_FILE_INFO2
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWScanFileInformation2 ( a , b , c , d , e , f ) NWIntScanFileInformation2 ( a , b , c , d , e , f , 0 )  *)
    Function NWIntScanFileInformation2 (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        filePattern  :   pnstr8 ;
        searchAttrs  :   nuint8 ;
        iterHandle  :   pnuint8 ;
        Var info  : NW_FILE_INFO2;
        augmentFlag  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSetFileAttributes (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        fileName  :   pnstr8 ;
        searchAttrs  :   nuint8 ;
        newAttrs  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetExtendedFileAttributes2 (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        extAttrs  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWScanConnectionsUsingFile (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        filePath  :   pnstr8 ;
        iterhandle  :   pnint16 ;
        Var fileUse  : CONN_USING_FILE;
        Var fileUsed  : CONNS_USING_FILE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWScanOpenFilesByConn2 (
        conn  :   NWCONN_HANDLE ;
        connNum  :   nuint16 ;
        iterHandle  :   pnint16 ;
        Var openCtrl  : OPEN_FILE_CONN_CTRL;
        Var openFile  : OPEN_FILE_CONN
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWScanOpenFilesByConn (
        conn  :   NWCONN_HANDLE ;
        connNum  :   nuint16 ;
        iterHandle  :   pnint16 ;
        Var openFile  : CONN_OPEN_FILE;
        Var openFiles  : CONN_OPEN_FILES
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSetExtendedFileAttributes2 (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        extAttrs  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWRenameFile (
        conn  :   NWCONN_HANDLE ;
        oldDirHandle  :   NWDIR_HANDLE ;
        oldFileName  :   pnstr8 ;
        searchAttrs  :   nuint8 ;
        newDirHandle  :   NWDIR_HANDLE ;
        newFileName  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWEraseFiles ( a , b , c , d ) NWIntEraseFiles ( a , b , c , d , 0 )  *)
    Function NWIntEraseFiles (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        searchAttrs  :   nuint8 ;
        augmentFlag  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetSparseFileBitMap (
        conn  :   NWCONN_HANDLE ;
        fileHandle  :   nuint32 ;
        flag  :   nint16 ;
        offset  :   nuint32 ;
        blockSize  :   pnuint32 ;
        bitMap  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$ENDIF}
    {$DEFINE NWLOCKS_INCLUDED}
    Function NWLogPhysicalRecord (
        fileHandle  :   NWFILE_HANDLE ;
        recStartOffset  :   nuint32 ;
        recLength  :   nuint32 ;
        lockFlags  :   nuint8 ;
        timeOut  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLockPhysicalRecordSet (
        lockFlags  :   nuint8 ;
        timeOut  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWReleasePhysicalRecordSet : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWClearPhysicalRecordSet : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWReleasePhysicalRecord (
        fileHandle  :   NWFILE_HANDLE ;
        recStartOffset  :   nuint32 ;
        recSize  :   nuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWClearPhysicalRecord (
        fileHandle  :   NWFILE_HANDLE ;
        recStartOffset  :   nuint32 ;
        recSize  :   nuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLockFileLockSet (
        timeOut  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWReleaseFileLockSet : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWClearFileLockSet : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWClearFileLock2 (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWReleaseFileLock2 (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLogFileLock2 (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        lockFlags  :   nuint8 ;
        timeOut  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLogLogicalRecord (
        conn  :   NWCONN_HANDLE ;
        logRecName  :   pnstr8 ;
        lockFlags  :   nuint8 ;
        timeOut  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLockLogicalRecordSet (
        lockFlags  :   nuint8 ;
        timeOut  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWReleaseLogicalRecordSet : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWClearLogicalRecordSet : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWReleaseLogicalRecord (
        conn  :   NWCONN_HANDLE ;
        logRecName  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWClearLogicalRecord (
        conn  :   NWCONN_HANDLE ;
        logRecName  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCloseFile (
        fileHandle  :   NWFILE_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* Not implemented Function NWCreateFile (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        fileName  :   pnstr8 ;
        fileAttrs  :   nuint8 ;
        Var fileHandle  : NWFILE_HANDLE;
        createFlag  :   nflag32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWOpenFile (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        fileName  :   pnstr8 ;
        searchAttr  :   nuint16 ;
        accessRights  :   nuint8 ;
        Var fileHandle  : NWFILE_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWReadFile (
        fileHandle  :   NWFILE_HANDLE ;
        bytesToRead  :   nuint32 ;
        bytesActuallyRead  :   pnuint32 ;
        data  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWWriteFile (
        fileHandle  :   NWFILE_HANDLE ;
        bytesToWrite  :   nuint32 ;
        data  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWCommitFile (
        fileHandle  :   NWFILE_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWGetEOF (
        fileHandle  :   NWFILE_HANDLE ;
        getEOF  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWSetEOF (
        fileHandle  :   NWFILE_HANDLE ;
        setEOF  :   nuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWGetFilePos (
        fileHandle  :   NWFILE_HANDLE ;
        filePos  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWSetFilePos (
        fileHandle  :   NWFILE_HANDLE ;
        mode  :   nuint ;
        filePos  :   nuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    Function NWGetFileDirEntryNumber (
        fileHandle  :   NWFILE_HANDLE ;
        volumeNum  :   pnuint32 ;
        directoryEntry  :   pnuint32 ;
        DOSDirectoryEntry  :   pnuint32 ;
        nameSpace  :   pnuint32 ;
        dataStream  :   pnuint32 ;
        parentDirEntry  :   pnuint32 ;
        parentDOSDirEntry  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetDirectoryEntryNumber (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   nuint8 ;
        volumeNum  :   pnuint32 ;
        directoryEntry  :   pnuint32 ;
        DOSDirectoryEntry  :   pnuint32 ;
        nameSpace  :   pnuint32 ;
        parentDirEntry  :   pnuint32 ;
        parentDOSDirEntry  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetNSFileDirEntryNumber (
        fileHandle  :   NWFILE_HANDLE ;
        nameSpace  :   nuint8 ;
        volumeNum  :   pnuint32 ;
        directoryEntry  :   pnuint32 ;
        dataStream  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

