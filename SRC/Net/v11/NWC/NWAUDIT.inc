(******************************************************************************

  %name: nwaudit.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:05:36 1996 %
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


{$IFNDEF  NWAUDIT_H }
    {$DEFINE NWAUDIT_H}
    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$IFNDEF  NWADEVNT_H }
        {$I nwadevnt.inc}
    {$ENDIF}
    {$I npackon.inc}
    (* Error codes *)
    {$DEFINE ERROR_AUDITING_NOT_INITIALIZED}
    Const ERROR_AUDITING_NOT_INITIALIZED = 224;
    (* bit map sizes *)
    {$DEFINE NW_AUDIT_NUMBER_EVENT_BITS}
    Const NW_AUDIT_NUMBER_EVENT_BITS = 256;
    {$DEFINE NW_AUDIT_NUMBER_EVENT_BITS_TNW}
    Const NW_AUDIT_NUMBER_EVENT_BITS_TNW = 512;
    (* audit ID types *)
    {$DEFINE AUDIT_ID_IS_TRUSTED_NETWARE}
    Const AUDIT_ID_IS_TRUSTED_NETWARE = 2;
    {$DEFINE AUDIT_ID_IS_CONTAINER}
    Const AUDIT_ID_IS_CONTAINER = 1;
    {$DEFINE AUDIT_ID_IS_VOLUME}
    Const AUDIT_ID_IS_VOLUME = 0;
    (* audit flags *)
    {$DEFINE DiscardAuditRcdsOnErrorFlag}
    Const DiscardAuditRcdsOnErrorFlag = $01;
    {$DEFINE ConcurrentVolAuditorAccess}
    Const ConcurrentVolAuditorAccess = $02;
    {$DEFINE DualLevelPasswordsActive}
    Const DualLevelPasswordsActive = $04;
    {$DEFINE BroadcastWarningsToAllUsers}
    Const BroadcastWarningsToAllUsers = $08;
    {$DEFINE LevelTwoPasswordSet}
    Const LevelTwoPasswordSet = $10;
    {$DEFINE ArchiveAuditFileOnErrorFlag}
    Const ArchiveAuditFileOnErrorFlag = $20;
    Type
        tagNWADOpenStatus = Record
            auditingStatus  :   nuint32 ;
            isTrustedNetWare  :   nuint32 ;
            trustedNetWareStatus  :   nuint32 ;
            reserved1  :   nuint32 ;
            reserved2  :   nuint32 ;
            reserved3  :   nuint32 ;
            reserved4  :   nuint32 ;
        End;
        NWADOpenStatus = tagNWADOpenStatus;
        pNWADOpenStatus = ^tagNWADOpenStatus;
    Type
        tagTIMESTAMP = Record
            seconds  :   nuint32 ;
            replicaNumber  :   nuint16 ;
            event  :   nuint16 ;
        End;
        TIMESTAMP = tagTIMESTAMP;
    Type
        tagNWAuditBitMap = Record
            bitMap  :  Array[0..31] Of  nuint8 ;
        End;
        NWAuditBitMap = tagNWAuditBitMap;
        pNWAuditBitMap = ^tagNWAuditBitMap;
    Type
        tagNWAuditBitMapTNW = Record
            bitMap  :  Array[0..63] Of  nuint8 ;
        End;
        NWAuditBitMapTNW = tagNWAuditBitMapTNW;
        pNWAuditBitMapTNW = ^tagNWAuditBitMapTNW;
    Type
        tagNWAuditFileList = Record
            fileCreateDateTime  :  Array[0..15] Of  nuint32 ;
            fileSize  :  Array[0..15] Of  nuint32 ;
        End;
        NWAuditFileList = tagNWAuditFileList;
        pNWAuditFileList = ^tagNWAuditFileList;
    Type
        tagNWConfigHeader = Record
            fileVersionDate  :   nuint16 ;
            auditFlags  :   nuint8 ;
            errMsgDelayMinutes  :   nuint8 ;
            reserved1  :  Array[0..15] Of  nuint8 ;
            auditFileMaxSize  :   nuint32 ;
            auditFileSizeThreshold  :   nuint32 ;
            auditRecordCount  :   nuint32 ;
            historyRecordCount  :   nuint32 ;
            reserved2  :  Array[0..15] Of  nuint8 ;
            reserved3  :  Array[0..2] Of  nuint32 ;
            auditEventBitMap  :  Array[0..31] Of  nuint8 ;
            auditFileCreationDateTime  :   nuint32 ;
            reserved4  :  Array[0..7] Of  nuint8 ;
            auditFlags2  :   nuint16 ;
            fileVersionDate2  :   nuint16 ;
            fileArchiveDays  :   nuint8 ;
            fileArchiveHour  :   nuint8 ;
            numOldAuditFilesToKeep  :   nuint8 ;
            reserved5  :   nuint8 ;
            headerChecksum  :   nuint32 ;
            headerModifiedCounter  :   nuint32 ;
            reserved6  :   nuint32 ;
            (* Trusted NetWare uses the following two fields *)
            newBitMap  :  Array[0..63] Of  nuint8 ;
            reserved7  :  Array[0..63] Of  nuint8 ;
        End;
        NWConfigHeader = tagNWConfigHeader;
        pNWConfigHeader = ^tagNWConfigHeader;
    Type
        tagNWDSContainerConfigHdr = Record
            fileVersionDate  :   nuint16 ;
            auditFlags  :   nuint8 ;
            errMsgDelayMinutes  :   nuint8 ;
            containerID  :   nuint32 ;
            reserved1  :   nuint32 ;
            creationTS  :   TIMESTAMP ;
            bitMap  :   nuint32 ;
            auditFileMaxSize  :   nuint32 ;
            auditFileSizeThreshold  :   nuint32 ;
            auditRecordCount  :   nuint32 ;
            replicaNumber  :   nuint16 ;
            enabledFlag  :   nuint8 ;
            fileArchiveDays  :   nuint8 ;
            fileArchiveHour  :   nuint8 ;
            numOldFilesToKeep  :   nuint8 ;
            numberReplicaEntries  :   nuint16 ;
            auditFileCreationDateTime  :   nuint32 ;
            reserved2  :  Array[0..7] Of  nuint8 ;
            partitionID  :   nuint32 ;
            headerChecksum  :   nuint32 ;
            reserved3  :  Array[0..3] Of  nuint32 ;
            auditDisabledCounter  :   nuint32 ;
            auditEnabledCounter  :   nuint32 ;
            reserved4  :  Array[0..31] Of  nuint8 ;
            hdrModifiedCounter  :   nuint32 ;
            fileResetCounter  :   nuint32 ;
            (* Trusted NetWare uses the following two fields *)
            newBitMap  :  Array[0..63] Of  nuint8 ;
            reserved5  :  Array[0..63] Of  nuint8 ;
        End;
        NWDSContainerConfigHdr = tagNWDSContainerConfigHdr;
        pNWDSContainerConfigHdr = ^tagNWDSContainerConfigHdr;
    Type
        tagNWAuditStatus = Record
            auditingVersionDate  :   nuint16 ;
            auditFileVersionDate  :   nuint16 ;
            auditingEnabledFlag  :   nuint32 ;
            auditFileSize  :   nuint32 ;
            modifiedCounter  :   nuint32 ;
            auditFileMaxSize  :   nuint32 ;
            auditFileSizeThreshold  :   nuint32 ;
            auditRecordCount  :   nuint32 ;
            auditingFlags  :   nuint32 ;
        End;
        NWAuditStatus = tagNWAuditStatus;
        pNWAuditStatus = ^tagNWAuditStatus;
    Type
        tagNWAuditRecord = Record
            recordLength  :   nuint32 ;
            record1  :   pnuint8 ;
        End;
        NWAuditRecord = tagNWAuditRecord;
        pNWAuditRecord = ^tagNWAuditRecord;
    Type
        tagNWADAuditPolicy = Record
            policyVersionDate  :   nuint16 ;
            reserved  :   nuint16 ;
            auditFlags  :  Array[0..3] Of  nuint8 ;
            auditFileMaxSize  :   nuint32 ;
            auditFileThresholdSize  :   nuint32 ;
            fileArchiveDays  :   nuint8 ;
            fileArchiveHour  :   nuint8 ;
            numOldAuditFilesToKeep  :   nuint8 ;
            userRestrictionFlag  :   nuint8 ;
            modifiedCounter  :   nuint32 ;
            auditOverflowFileSize  :   nuint32 ;
            reservedLong  :   nuint32 ;
            auditedEventBitMap  :  Array[0..255] Of  nuint8 ;
        End;
        NWADAuditPolicy = tagNWADAuditPolicy;
        pNWADAuditPolicy = ^tagNWADAuditPolicy;
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    Procedure NWGetNWADVersion (
        majorVersion  :   pnuint8 ;
        minorVersion  :   pnuint8 ;
        revisionLevel  :   pnuint8 ;
        betaReleaseLevel  :   pnuint8 
    );
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* allocate auditHandle for use in other Auditing calls *)
    Function NWADOpen (
        conn  :   NWCONN_HANDLE ;
        auditIDType  :   nuint32 ;
        auditID  :   nuint32 ;
        auditHandle  :   pnptr ;
        openStatus  :   pNWADOpenStatus 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* free auditHandle and NULL the pointer *)
    Function NWADClose (
        auditHandle  :   pnptr 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWGetVolumeAuditStats ( a , b , c , d ) NWADGetStatus ( a , AUDIT_ID_IS_VOLUME , b , c , d )  *)
    (* TC #define NWDSGetContainerAuditStats ( a , b , c , d ) NWADGetStatus ( a , AUDIT_ID_IS_CONTAINER , b , c , d )  *)
    Function NWADGetStatus (
        conn  :   NWCONN_HANDLE ;
        auditIDType  :   nuint32 ;
        auditID  :   nuint32 ;
        auditStatus  :   pNWAuditStatus ;
        bufferSize  :   nuint16 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWGetAuditingFlags ( a , b , c , d ) NWADGetFlags ( a , AUDIT_ID_IS_VOLUME , b , c , d )  *)
    (* TC #define NWDSGetAuditingFlags ( a , b , c , d ) NWADGetFlags ( a , AUDIT_ID_IS_CONTAINER , b , c , d )  *)
    Function NWADGetFlags (
        conn  :   NWCONN_HANDLE ;
        auditIDType  :   nuint32 ;
        auditID  :   nuint32 ;
        auditHandle  :   nptr ;
        flags  :   pnuint8 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWLoginAsVolumeAuditor ( a , b , c , d ) NWADLogin ( a , AUDIT_ID_IS_VOLUME , b , c , d )  *)
    (* TC #define NWDSLoginAsContainerAuditor ( a , b , c , d ) NWADLogin ( a , AUDIT_ID_IS_CONTAINER , b , c , d )  *)
    Function NWADLogin (
        conn  :   NWCONN_HANDLE ;
        auditIDType  :   nuint32 ;
        auditID  :   nuint32 ;
        auditHandle  :   nptr ;
        password  :   pnuint8 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* Type NWInitAuditLevelTwoPassword = NWADInitLevelTwoPassword; *)
    Function NWADInitLevelTwoPassword (
        auditHandle  :   nptr ;
        password  :   pnuint8 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWLogoutAsVolumeAuditor ( a , b , c ) NWADLogout ( a , AUDIT_ID_IS_VOLUME , b , c )  *)
    (* TC #define NWDSLogoutAsContainerAuditor ( a , b , c ) NWADLogout ( a , AUDIT_ID_IS_CONTAINER , b , c )  *)
    Function NWADLogout (
        conn  :   NWCONN_HANDLE ;
        auditIDType  :   nuint32 ;
        auditID  :   nuint32 ;
        auditHandle  :   nptr 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWChangeAuditorPassword ( a , b , c , d , e ) NWADChangePassword ( a , AUDIT_ID_IS_VOLUME , b , c , d , e )  *)
    (* TC #define NWDSChangeAuditorPassword ( a , b , c , d , e ) NWADChangePassword ( a , AUDIT_ID_IS_CONTAINER , b , c , d , e )  *)
    Function NWADChangePassword (
        conn  :   NWCONN_HANDLE ;
        auditIDType  :   nuint32 ;
        auditID  :   nuint32 ;
        auditHandle  :   nptr ;
        newPassword  :   pnuint8 ;
        level  :   nuint8 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWCheckAuditAccess ( a , b ) NWADCheckAccess ( a , AUDIT_ID_IS_VOLUME , b )  *)
    (* TC #define NWDSCheckAuditAccess ( a , b ) NWADCheckAccess ( a , AUDIT_ID_IS_CONTAINER , b )  *)
    Function NWADCheckAccess (
        conn  :   NWCONN_HANDLE ;
        auditIDType  :   nuint32 ;
        auditID  :   nuint32 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWCheckAuditLevelTwoAccess ( a , b , c ) NWADCheckLevelTwoAccess ( a , AUDIT_ID_IS_VOLUME , b , c )  *)
    (* TC #define NWDSCheckAuditLevelTwoAccess ( a , b , c ) NWADCheckLevelTwoAccess ( a , AUDIT_ID_IS_CONTAINER , b , c )  *)
    Function NWADCheckLevelTwoAccess (
        conn  :   NWCONN_HANDLE ;
        auditIDType  :   nuint32 ;
        auditID  :   nuint32 ;
        auditHandle  :   nptr 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWEnableAuditingOnVolume ( a , b , c ) NWADEnable ( a , AUDIT_ID_IS_VOLUME , b , c )  *)
    (* TC #define NWDSEnableAuditingOnContainer ( a , b , c ) NWADEnable ( a , AUDIT_ID_IS_CONTAINER , b , c )  *)
    Function NWADEnable (
        conn  :   NWCONN_HANDLE ;
        auditIDType  :   nuint32 ;
        auditID  :   nuint32 ;
        auditHandle  :   nptr 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWDisableAuditingOnVolume ( a , b , c ) NWADDisable ( a , AUDIT_ID_IS_VOLUME , b , c )  *)
    (* TC #define NWDSDisableAuditingOnContainer ( a , b , c ) NWADDisable ( a , AUDIT_ID_IS_CONTAINER , b , c )  *)
    Function NWADDisable (
        conn  :   NWCONN_HANDLE ;
        auditIDType  :   nuint32 ;
        auditID  :   nuint32 ;
        auditHandle  :   nptr 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWIsUserBeingAudited ( a , b , c , d ) NWADIsObjectAudited ( a , AUDIT_ID_IS_VOLUME , b , d )  *)
    (* TC #define NWDSIsObjectBeingAudited ( a , b , c ) NWADIsObjectAudited ( a , AUDIT_ID_IS_CONTAINER , b , c )  *)
    Function NWADIsObjectAudited (
        conn  :   NWCONN_HANDLE ;
        auditIDType  :   nuint32 ;
        auditID  :   nuint32 ;
        userObjectID  :   nuint32 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWAddAuditProperty ( a , b , c , d ) NWADChangeObjectProperty ( a , AUDIT_ID_IS_VOLUME , b , c , d , 1 )  *)
    (* TC #define NWRemoveAuditProperty ( a , b , c , d ) NWADChangeObjectProperty ( a , AUDIT_ID_IS_VOLUME , b , c , d , 0 )  *)
    (* TC #define NWDSChangeObjectAuditProperty ( a , b , c , d , e ) NWADChangeObjectProperty ( a , AUDIT_ID_IS_CONTAINER , b , c , d , e )  *)
    Function NWADChangeObjectProperty (
        conn  :   NWCONN_HANDLE ;
        auditIDType  :   nuint32 ;
        auditID  :   nuint32 ;
        auditHandle  :   nptr ;
        objectID  :   nuint32 ;
        auditFlag  :   nuint8 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* Volume audit call only *)
    (* TC #define NWReadAuditingBitMap ( a , b , c , d , e ) NWADReadBitMap ( a , b , d , e )  *)
    Function NWADReadBitMap (
        conn  :   NWCONN_HANDLE ;
        auditID  :   nuint32 ;
        Var buffer  : NWAuditBitMap;
        bufferSize  :   nuint16 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWReadAuditConfigHeader ( a , b , c , d , e ) NWADReadConfigHeader ( a , AUDIT_ID_IS_VOLUME , b , c , d , e )  *)
    (* TC #define NWDSReadAuditConfigHeader ( a , b , c , d , e ) NWADReadConfigHeader ( a , AUDIT_ID_IS_CONTAINER , b , c , d , e )  *)
    Function NWADReadConfigHeader (
        conn  :   NWCONN_HANDLE ;
        auditIDType  :   nuint32 ;
        auditID  :   nuint32 ;
        auditHandle  :   nptr ;
        buffer  :   nptr ;
        bufferSize  :   nuint16 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* volume auditing only *)
    (* TC #define NWWriteAuditingBitMap ( a , b , c , d ) NWADWriteBitMap ( a , b , c , d )  *)
    Function NWADWriteBitMap (
        conn  :   NWCONN_HANDLE ;
        auditID  :   nuint32 ;
        auditHandle  :   nptr ;
        Var buffer  : NWAuditBitMap
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWWriteAuditConfigHeader ( a , b , c , d ) NWADWriteConfigHeader ( a , AUDIT_ID_IS_VOLUME , b , c , d )  *)
    (* TC #define NWDSWriteAuditConfigHeader ( a , b , c , d ) NWADWriteConfigHeader ( a , AUDIT_ID_IS_CONTAINER , b , c , d )  *)
    Function NWADWriteConfigHeader (
        conn  :   NWCONN_HANDLE ;
        auditIDType  :   nuint32 ;
        auditID  :   nuint32 ;
        auditHandle  :   nptr ;
        buffer  :   pNWConfigHeader 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWResetAuditingFile ( a , b , c ) NWADResetFile ( a , AUDIT_ID_IS_VOLUME , b , c )  *)
    (* TC #define NWDSResetAuditingFile ( a , b , c ) NWADResetFile ( a , AUDIT_ID_IS_CONTAINER , b , c )  *)
    Function NWADResetFile (
        conn  :   NWCONN_HANDLE ;
        auditIDType  :   nuint32 ;
        auditID  :   nuint32 ;
        auditHandle  :   nptr 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* NWADOpenReadFile will only work with NetWare version 4.10 or newer *)
    Function NWADOpenRecordFile (
        conn  :   NWCONN_HANDLE ;
        auditIDType  :   nuint32 ;
        auditID  :   nuint32 ;
        auditHandle  :   nptr ;
        fileCode  :   nint16 ;
        recordHandle  :   pnptr 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* NWADInitRead will only work with NetWare version 4.10 or newer *)
    Function NWADReadRecord (
        recordHandle  :   nptr ;
        maxSize  :   nuint16 ;
        direction  :   nint16 ;
        buffer  :   pnuint8 ;
        bufferSize  :   pnuint16 ;
        eofFlag  :   pnuint8 ;
        offsetPtr  :   pnuint32 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* NWADInitRead will only work with NetWare version 4.10 or newer *)
    Function NWADCloseRecordFile (
        recordHandle  :   pnptr 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWCloseOldAuditingFile ( a , b , c ) NWADCloseOldFile ( a , AUDIT_ID_IS_VOLUME , b , c )  *)
    (* TC #define NWDSCloseOldAuditingFile ( a , b , c ) NWADCloseOldFile ( a , AUDIT_ID_IS_CONTAINER , b , c )  *)
    Function NWADCloseOldFile (
        conn  :   NWCONN_HANDLE ;
        auditIDType  :   nuint32 ;
        auditID  :   nuint32 ;
        auditHandle  :   nptr 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* TC #define NWDeleteOldAuditingFile ( a , b , c ) NWADDeleteFile ( a , AUDIT_ID_IS_VOLUME , b , c )  *)
    (* TC #define NWDSDeleteOldAuditingFile ( a , b , c ) NWADDeleteFile ( a , AUDIT_ID_IS_CONTAINER , b , c )  *)
    Function NWADDeleteFile (
        conn  :   NWCONN_HANDLE ;
        auditIDType  :   nuint32 ;
        auditID  :   nuint32 ;
        auditHandle  :   nptr 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* NetWare version 4.10 or newer *)
    Function NWADGetFileList (
        conn  :   NWCONN_HANDLE ;
        auditIDType  :   nuint32 ;
        auditID  :   nuint32 ;
        auditHandle  :   nptr ;
        fileList  :   pNWAuditFileList 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWADDeleteOldFile (
        conn  :   NWCONN_HANDLE ;
        auditIDType  :   nuint32 ;
        auditID  :   nuint32 ;
        auditHandle  :   nptr ;
        fileCode  :   nuint32 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* Trusted NetWare and Volume Only *)
    Function NWADRestartVolumeAuditing (
        conn  :   NWCONN_HANDLE ;
        auditIDType  :   nuint32 ;
        auditID  :   nuint32 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* Trusted NetWare Only *)
    Function NWADSetPassword (
        conn  :   NWCONN_HANDLE ;
        auditIDType  :   nuint32 ;
        auditID  :   nuint32 ;
        auditHandle  :   nptr ;
        newPassword  :   pnuint8 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* Trusted NetWare Only *)
    Function NWADAppendExternalRecords (
        conn  :   NWCONN_HANDLE ;
        auditFileObjectID  :   nuint32 ;
        vendorID  :   nuint32 ;
        numberRecords  :   nuint32 ;
        recordsPtr  :   pNWAuditRecord 
    ) : NWRCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

