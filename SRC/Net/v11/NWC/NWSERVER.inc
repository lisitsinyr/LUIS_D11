(******************************************************************************

  %name: nwserver.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:09:12 1996 %
  $Copyright:

  Copyright (c) 1989-1996 Novell, Inc.  All Rights Reserved.                      

  THIS WORK IS  SUBJECT  TO  U.S.  AND  INTERNATIONAL  COPYRIGHT  LAWS  AND
  TREATIES.   NO  PART  OF  THIS  WORK MAY BE  USED,  PRACTICED,  PERFORMED
  COPIED, DISTRIBUTED, REVISED, MODIFIED, TRANSLATED,  ABRIDGED, CONDENSED,
  EXPANDED,  COLLECTED,  COMPILED,  LINKED,  RECAST, TRANSFORMED OR ADAPTED
  WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC. ANY USE OR EXPLOITATION
  OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT THE PERPETRATOR TO
  CRIMINAL AND CIVIL LIABILITY.$

 *****************************************************************************)


{$IFNDEF  NWSERVER_H }
    {$DEFINE NWSERVER_H}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$I npackon.inc}
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    {$DEFINE LNS_CHECK}
    Const LNS_CHECK = 0;
    {$IFNDEF NW_SHORT_NAME_SERVER}
    {$DEFINE NW_SHORT_NAME_SERVER}
    Const NW_SHORT_NAME_SERVER = 0;
    {$ENDIF}
    {$IFNDEF NW_LONG_NAME_SERVER}
    {$DEFINE NW_LONG_NAME_SERVER}
    Const NW_LONG_NAME_SERVER = 1;
    {$ENDIF}
    {$IFNDEF NW_ENCP_SERVER}
    {$DEFINE NW_ENCP_SERVER}
    Const NW_ENCP_SERVER = 1;
    {$ENDIF}
    {$IFNDEF NW_EXTENDED_NCP_SERVER}
    {$DEFINE NW_EXTENDED_NCP_SERVER}
    Const NW_EXTENDED_NCP_SERVER = 1;
    {$ENDIF}
    {$DEFINE VERSION_CHECK}
    Const VERSION_CHECK = 1;
    {$DEFINE NW_2X}
    Const NW_2X = 0;
    {$DEFINE NW_30}
    Const NW_30 = 1;
    {$DEFINE NW_311}
    Const NW_311 = 2;
    {$DEFINE NW_32}
    Const NW_32 = 3;
    {$DEFINE NW_40}
    Const NW_40 = 4;
    Type
        NWLAN_CONFIG = Record
            networdAddress  :  Array[0..3] Of  nuint8 ;
            hostAddress  :  Array[0..5] Of  nuint8 ;
            boardInstalled  :   nuint8 ;
            optionNumber  :   nuint8 ;
            configurationText1  :  Array[0..79] Of  nuint8 ;
            configurationText2  :  Array[0..79] Of  nuint8 ;
        End;
    Type
        SERVER_LAN_IO_STATS = Record
            systemElapsedTime  :   nuint32 ;
            maxRoutingBuffersAvail  :   nuint16 ;
            maxRoutingBuffersUsed  :   nuint16 ;
            routingBuffersInUse  :   nuint16 ;
            totalFileServicePackets  :   nuint32 ;
            fileServicePacketsBuffered  :   nuint16 ;
            invalidConnPacketCount  :   nuint16 ;
            badLogicalConnCount  :   nuint16 ;
            packetsRcvdDuringProcCount  :   nuint16 ;
            reprocessedRequestCount  :   nuint16 ;
            badSequenceNumberPacketCount  :   nuint16 ;
            duplicateReplyCount  :   nuint16 ;
            acknowledgementsSent  :   nuint16 ;
            badRequestTypeCount  :   nuint16 ;
            attachDuringProcCount  :   nuint16 ;
            attachWhileAttachingCount  :   nuint16 ;
            forgedDetachRequestCount  :   nuint16 ;
            badConnNumberOnDetachCount  :   nuint16 ;
            detachDuringProcCount  :   nuint16 ;
            repliesCanceledCount  :   nuint16 ;
            hopCountDiscardCount  :   nuint16 ;
            unknownNetDiscardCount  :   nuint16 ;
            noDGroupBufferDiscardCount  :   nuint16 ;
            outPacketNoBufferDiscardCount  :   nuint16 ;
            IPXNotMyNetworkCount  :   nuint16 ;
            NetBIOSPropagationCount  :   nuint32 ;
            totalOtherPackets  :   nuint32 ;
            totalRoutedPackets  :   nuint32 ;
        End;
    Type
        PHYS_DSK_STATS = Record
            systemElapsedTime  :   nuint32 ;
            diskChannel  :   nuint8 ;
            diskRemovable  :   nuint8 ;
            driveType  :   nuint8 ;
            controllerDriveNumber  :   nuint8 ;
            controllerNumber  :   nuint8 ;
            controllerType  :   nuint8 ;
            driveSize  :   nuint32 ;
            driveCylinders  :   nuint16 ;
            driveHeads  :   nuint8 ;
            sectorsPerTrack  :   nuint8 ;
            driveDefinition  :  Array[0..63] Of  nuint8 ;
            IOErrorCount  :   nuint16 ;
            hotFixStart  :   nuint32 ;
            hotFixSize  :   nuint16 ;
            hotFixBlockAvailable  :   nuint16 ;
            hotFixDisabled  :   nuint8 ;
        End;
    Type
        DSK_CHANNEL_STATS = Record
            systemElapsedTime  :   nuint32 ;
            channelState  :   nuint16 ;
            channelSyncState  :   nuint16 ;
            driverType  :   nuint8 ;
            driverMajorVersion  :   nuint8 ;
            driverMinorVersion  :   nuint8 ;
            driverDescription  :  Array[0..64] Of  nuint8 ;
            IOAddr1  :   nuint16 ;
            IOAddr1Size  :   nuint16 ;
            IOAddr2  :   nuint16 ;
            IOAddr2Size  :   nuint16 ;
            sharedMem1Seg  :  Array[0..2] Of  nuint8 ;
            sharedMem1Ofs  :   nuint16 ;
            sharedMem2Seg  :  Array[0..2] Of  nuint8 ;
            sharedMem2Ofs  :   nuint16 ;
            interrupt1Used  :   nuint8 ;
            interrupt1  :   nuint8 ;
            interrupt2Used  :   nuint8 ;
            interrupt2  :   nuint8 ;
            DMAChannel1Used  :   nuint8 ;
            DMAChannel1  :   nuint8 ;
            DMAChannel2Used  :   nuint8 ;
            DMAChannel2  :   nuint8 ;
            reserved2  :   nuint16 ;
            configDescription  :  Array[0..79] Of  nuint8 ;
        End;
    Type
        DSK_CACHE_STATS = Record
            systemElapsedTime  :   nuint32 ;
            cacheBufferCount  :   nuint16 ;
            cacheBufferSize  :   nuint16 ;
            dirtyCacheBuffers  :   nuint16 ;
            cacheReadRequests  :   nuint32 ;
            cacheWriteRequests  :   nuint32 ;
            cacheHits  :   nuint32 ;
            cacheMisses  :   nuint32 ;
            physicalReadRequests  :   nuint32 ;
            physicalWriteRequests  :   nuint32 ;
            physicalReadErrors  :   nuint16 ;
            physicalWriteErrors  :   nuint16 ;
            cacheGetRequests  :   nuint32 ;
            cacheFullWriteRequests  :   nuint32 ;
            cachePartialWriteRequests  :   nuint32 ;
            backgroundDirtyWrites  :   nuint32 ;
            backgroundAgedWrites  :   nuint32 ;
            totalCacheWrites  :   nuint32 ;
            cacheAllocations  :   nuint32 ;
            thrashingCount  :   nuint16 ;
            LRUBlockWasDirtyCount  :   nuint16 ;
            readBeyondWriteCount  :   nuint16 ;
            fragmentedWriteCount  :   nuint16 ;
            cacheHitOnUnavailCount  :   nuint16 ;
            cacheBlockScrappedCount  :   nuint16 ;
        End;
    Type
        FILESYS_STATS = Record
            systemElapsedTime  :   nuint32 ;
            maxOpenFiles  :   nuint16 ;
            maxFilesOpened  :   nuint16 ;
            currOpenFiles  :   nuint16 ;
            totalFilesOpened  :   nuint32 ;
            totalReadRequests  :   nuint32 ;
            totalWriteRequests  :   nuint32 ;
            currChangedFATSectors  :   nuint16 ;
            totalChangedFATSectors  :   nuint32 ;
            FATWriteErrors  :   nuint16 ;
            fatalFATWriteErrors  :   nuint16 ;
            FATScanErrors  :   nuint16 ;
            maxIndexFilesOpened  :   nuint16 ;
            currOpenIndexedFiles  :   nuint16 ;
            attachedIndexFiles  :   nuint16 ;
            availableIndexFiles  :   nuint16 ;
        End;
    Type
        DRV_MAP_TABLE = Record
            systemElapsedTime  :   nuint32 ;
            SFTSupportLevel  :   nuint8 ;
            logicalDriveCount  :   nuint8 ;
            physicalDriveCount  :   nuint8 ;
            diskChannelTable  :  Array[0..4] Of  nuint8 ;
            pendingIOCommands  :   nuint16 ;
            driveMappingTable  :  Array[0..31] Of  nuint8 ;
            driveMirrorTable  :  Array[0..31] Of  nuint8 ;
            deadMirrorTable  :  Array[0..31] Of  nuint8 ;
            reMirrorDriveNumber  :   nuint8 ;
            reserved  :   nuint8 ;
            reMirrorCurrentOffset  :   nuint32 ;
            SFTErrorTable  :  Array[0..59] Of  nuint16 ;
        End;
    Type
        VERSION_INFO = Record
            serverName  :  Array[0..47] Of  nuint8 ;
            fileServiceVersion  :   nuint8 ;
            fileServiceSubVersion  :   nuint8 ;
            maximumServiceConnections  :   nuint16 ;
            connectionsInUse  :   nuint16 ;
            maxNumberVolumes  :   nuint16 ;
            revision  :   nuint8 ;
            SFTLevel  :   nuint8 ;
            TTSLevel  :   nuint8 ;
            maxConnectionsEverUsed  :   nuint16 ;
            accountVersion  :   nuint8 ;
            VAPVersion  :   nuint8 ;
            queueVersion  :   nuint8 ;
            printVersion  :   nuint8 ;
            virtualConsoleVersion  :   nuint8 ;
            restrictionLevel  :   nuint8 ;
            internetBridge  :   nuint8 ;
            reserved  :  Array[0..59] Of  nuint8 ;
        End;
    (* Defines that are used for the NWCheckNetWareVersion call for values
   that can be returned in the compatibilityFlag nuint8.  *)
    {$DEFINE COMPATIBLE}
    Const COMPATIBLE = $00;
    {$DEFINE VERSION_NUMBER_TOO_LOW}
    Const VERSION_NUMBER_TOO_LOW = $01;
    {$DEFINE SFT_LEVEL_TOO_LOW}
    Const SFT_LEVEL_TOO_LOW = $02;
    {$DEFINE TTS_LEVEL_TOO_LOW}
    Const TTS_LEVEL_TOO_LOW = $04;
    (* structures for NWGetFileServerMiscInfo (2.2 only) *)
    Type
        tNW_MEM_AREAS = Record
            total  :   nuint32 ;
            max  :   nuint32 ;
            cur  :   nuint32 ;
        End;
        NW_DYNAMIC_MEM = tNW_MEM_AREAS;
    Type
        tNW_FS_MISC = Record
            upTime  :   nuint32 ;
            processor  :   nuint8 ;
            reserved  :   nuint8 ;
            numProcs  :   nuint8 ;
            utilization  :   nuint8 ;
            configuredObjs  :   nuint16 ;
            maxObjs  :   nuint16 ;
            curObjs  :   nuint16 ;
            totalMem  :   nuint16 ;
            unusedMem  :   nuint16 ;
            numMemAreas  :   nuint16 ;
            dynamicMem  :  Array[0..2] Of  NW_DYNAMIC_MEM ;
        End;
        NW_FS_INFO = tNW_FS_MISC;
    Function NWGetPhysicalDiskStats (
        conn  :   NWCONN_HANDLE ;
        physicalDiskNum  :   nuint8 ;
        Var statBuffer  : PHYS_DSK_STATS
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetFileSystemStats (
        conn  :   NWCONN_HANDLE ;
        Var statBuffer  : FILESYS_STATS
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetDiskChannelStats (
        conn  :   NWCONN_HANDLE ;
        channelNum  :   nuint8 ;
        Var statBuffer  : DSK_CHANNEL_STATS
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetDiskCacheStats (
        conn  :   NWCONN_HANDLE ;
        Var statBuffer  : DSK_CACHE_STATS
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetFSDriveMapTable (
        conn  :   NWCONN_HANDLE ;
        Var tableBuffer  : DRV_MAP_TABLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetFSLANDriverConfigInfo (
        conn  :   NWCONN_HANDLE ;
        lanBoardNum  :   nuint8 ;
        Var lanConfig  : NWLAN_CONFIG
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetFileServerLANIOStats (
        conn  :   NWCONN_HANDLE ;
        Var statBuffer  : SERVER_LAN_IO_STATS
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCheckConsolePrivileges (
        conn  :   NWCONN_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDownFileServer (
        conn  :   NWCONN_HANDLE ;
        forceFlag  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetFileServerDateAndTime (
        conn  :   NWCONN_HANDLE ;
        dateTimeBuffer  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSetFileServerDateAndTime (
        conn  :   NWCONN_HANDLE ;
        year  :   nuint8 ;
        month  :   nuint8 ;
        day  :   nuint8 ;
        hour  :   nuint8 ;
        minute  :   nuint8 ;
        second  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCheckNetWareVersion (
        conn  :   NWCONN_HANDLE ;
        minVer  :   nuint16 ;
        minSubVer  :   nuint16 ;
        minRev  :   nuint16 ;
        minSFT  :   nuint16 ;
        minTTS  :   nuint16 ;
        compatibilityFlag  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetFileServerVersionInfo (
        conn  :   NWCONN_HANDLE ;
        Var versBuffer  : VERSION_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetFileServerInformation (
        conn  :   NWCONN_HANDLE ;
        serverName  :   pnstr8 ;
        majorVer  :   pnuint8 ;
        minVer  :   pnuint8 ;
        rev  :   pnuint8 ;
        maxConns  :   pnuint16 ;
        maxConnsUsed  :   pnuint16 ;
        connsInUse  :   pnuint16 ;
        numVolumes  :   pnuint16 ;
        SFTLevel  :   pnuint8 ;
        TTSLevel  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetFileServerExtendedInfo (
        conn  :   NWCONN_HANDLE ;
        accountingVer  :   pnuint8 ;
        VAPVer  :   pnuint8 ;
        queueingVer  :   pnuint8 ;
        printServerVer  :   pnuint8 ;
        virtualConsoleVer  :   pnuint8 ;
        securityVer  :   pnuint8 ;
        internetBridgeVer  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function _NWGetFileServerType (
        conn  :   NWCONN_HANDLE ;
        typeFlag  :   nuint16 ;
        serverType  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAttachToFileServer (
        serverName  :   pnstr8 ;
        scopeFlag  :   nuint16 ;
        Var newConnID  : NWCONN_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetFileServerLoginStatus (
        conn  :   NWCONN_HANDLE ;
        loginEnabledFlag  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDetachFromFileServer (
        conn  :   NWCONN_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetFileServerName (
        conn  :   NWCONN_HANDLE ;
        serverName  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLogoutFromFileServer (
        conn  :   NWCONN_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLoginToFileServer (
        conn  :   NWCONN_HANDLE ;
        objName  :   pnstr8 ;
        objType  :   nuint16 ;
        password  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWEnableFileServerLogin (
        conn  :   NWCONN_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDisableFileServerLogin (
        conn  :   NWCONN_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetFileServerDescription (
        conn  :   NWCONN_HANDLE ;
        companyName  :   pnstr8 ;
        revision  :   pnstr8 ;
        revisionDate  :   pnstr8 ;
        copyrightNotice  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetFileServerVersion (
        conn  :   NWCONN_HANDLE ;
        serverVersion  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWAttachToFileServerByConn (
        conn  :   NWCONN_HANDLE ;
        serverName  :   pnstr8 ;
        scopeFlag  :   nuint16 ;
        Var newConnID  : NWCONN_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetNetworkSerialNumber (
        conn  :   NWCONN_HANDLE ;
        serialNum  :   pnuint32 ;
        appNum  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWIsManager (
        conn  :   NWCONN_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* this function is 2.2 specific *)
    Function NWGetFileServerMiscInfo (
        conn  :   NWCONN_HANDLE ;
        Var fsInfo  : NW_FS_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF NWOS2}
    (* Not implemented Function NWLogoutWithLoginID (
        citrixLoginID  :   nuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

