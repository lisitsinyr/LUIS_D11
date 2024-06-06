(******************************************************************************

  %name: nwfse.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:08:23 1996 %
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


{$IFNDEF  NWFSE_H }
    {$DEFINE NWFSE_H}
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
    Type
        SERVER_AND_VCONSOLE_INFO = Record
            currentServerTime  :   nuint32 ;
            vconsoleVersion  :   nuint8 ;
            vconsoleRevision  :   nuint8 ;
        End;
    (* Get Cache Information *)
    Type
        CACHE_COUNTERS = Record
            readExistingBlockCount  :   nuint32 ;
            readExistingWriteWaitCount  :   nuint32 ;
            readExistingPartialReadCount  :   nuint32 ;
            readExistingReadErrorCount  :   nuint32 ;
            writeBlockCount  :   nuint32 ;
            writeEntireBlockCount  :   nuint32 ;
            getDiskCount  :   nuint32 ;
            getDiskNeedToAllocCount  :   nuint32 ;
            getDiskSomeoneBeatMeCount  :   nuint32 ;
            getDiskPartialReadCount  :   nuint32 ;
            getDiskReadErrorCount  :   nuint32 ;
            getAsyncDiskCount  :   nuint32 ;
            getAsyncDiskNeedToAlloc  :   nuint32 ;
            getAsyncDiskSomeoneBeatMe  :   nuint32 ;
            errorDoingAsyncReadCount  :   nuint32 ;
            getDiskNoReadCount  :   nuint32 ;
            getDiskNoReadAllocCount  :   nuint32 ;
            getDiskNoReadSomeoneBeatMeCount  :   nuint32 ;
            diskWriteCount  :   nuint32 ;
            diskWriteAllocCount  :   nuint32 ;
            diskWriteSomeoneBeatMeCount  :   nuint32 ;
            writeErrorCount  :   nuint32 ;
            waitOnSemaphoreCount  :   nuint32 ;
            allocBlockWaitForSomeoneCount  :   nuint32 ;
            allocBlockCount  :   nuint32 ;
            allocBlockWaitCount  :   nuint32 ;
        End;
    Type
        CACHE_MEM_COUNTERS = Record
            originalNumOfCacheBuffers  :   nuint32 ;
            currentNumOfCacheBuffers  :   nuint32 ;
            cacheDirtyBlockThreshold  :   nuint32 ;
            waitNodeCount  :   nuint32 ;
            waitNodeAllocFailureCount  :   nuint32 ;
            moveCacheNodeCount  :   nuint32 ;
            moveCacheNodeFromAvailCount  :   nuint32 ;
            accelerateCacheNodeWriteCount  :   nuint32 ;
            removeCacheNodeCount  :   nuint32 ;
            removeCacheNodeFromAvailCount  :   nuint32 ;
        End;
    Type
        CACHE_TREND_COUNTERS = Record
            numCacheChecks  :   nuint32 ;
            numCacheHits  :   nuint32 ;
            numDirtyCacheChecks  :   nuint32 ;
            numDirtyCacheHits  :   nuint32 ;
            cacheUsedWhileChecking  :   nuint32 ;
            waitForDirtyBlocksDecreaseCount  :   nuint32 ;
            allocBlockFromAvailCount  :   nuint32 ;
            allocBlockFromLRUCount  :   nuint32 ;
            allocBlockAlreadyWaiting  :   nuint32 ;
            LRUSittingTime  :   nuint32 ;
        End;
    Type
        CACHE_INFO = Record
            maxByteCount  :   nuint32 ;
            minNumOfCacheBuffers  :   nuint32 ;
            minCacheReportThreshold  :   nuint32 ;
            allocWaitingCount  :   nuint32 ;
            numDirtyBlocks  :   nuint32 ;
            cacheDirtyWaitTime  :   nuint32 ;
            cacheMaxConcurrentWrites  :   nuint32 ;
            maxDirtyTime  :   nuint32 ;
            numOfDirCacheBuffers  :   nuint32 ;
            cacheByteToBlockShiftFactor  :   nuint32 ;
        End;
    Type
        NWFSE_CACHE_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            cacheCounters  :   CACHE_COUNTERS ;
            cacheMemCounters  :   CACHE_MEM_COUNTERS ;
            cacheTrendCounters  :   CACHE_TREND_COUNTERS ;
            cacheInformation  :   CACHE_INFO ;
        End;
    (* Get File Server Information *)
    Type
        FSE_SERVER_INFO = Record
            replyCanceledCount  :   nuint32 ;
            writeHeldOffCount  :   nuint32 ;
            writeHeldOffWithDupRequest  :   nuint32 ;
            (* writeHeldOffWithDuplicateRequest *)
            invalidRequestTypeCount  :   nuint32 ;
            beingAbortedCount  :   nuint32 ;
            alreadyDoingReallocCount  :   nuint32 ;
            deAllocInvalidSlotCount  :   nuint32 ;
            deAllocBeingProcessedCount  :   nuint32 ;
            deAllocForgedPacketCount  :   nuint32 ;
            deAllocStillTransmittingCount  :   nuint32 ;
            startStationErrorCount  :   nuint32 ;
            invalidSlotCount  :   nuint32 ;
            beingProcessedCount  :   nuint32 ;
            forgedPacketCount  :   nuint32 ;
            stillTransmittingCount  :   nuint32 ;
            reExecuteRequestCount  :   nuint32 ;
            invalidSequenceNumCount  :   nuint32 ;
            duplicateIsBeingSentAlreadyCnt  :   nuint32 ;
            sentPositiveAcknowledgeCount  :   nuint32 ;
            sentDuplicateReplyCount  :   nuint32 ;
            noMemForStationCtrlCount  :   nuint32 ;
            noAvailableConnsCount  :   nuint32 ;
            reallocSlotCount  :   nuint32 ;
            reallocSlotCameTooSoonCount  :   nuint32 ;
        End;
    Type
        FILE_SERVER_COUNTERS = Record
            tooManyHops  :   nuint16 ;
            unknownNetwork  :   nuint16 ;
            noSpaceForService  :   nuint16 ;
            noReceiveBuffers  :   nuint16 ;
            notMyNetwork  :   nuint16 ;
            netBIOSProgatedCount  :   nuint32 ;
            totalPacketsServiced  :   nuint32 ;
            totalPacketsRouted  :   nuint32 ;
        End;
    Type
        NWFSE_FILE_SERVER_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            NCPStationsInUseCount  :   nuint32 ;
            NCPPeakStationsInUseCount  :   nuint32 ;
            numOfNCPRequests  :   nuint32 ;
            serverUtilization  :   nuint32 ;
            ServerInfo  :   FSE_SERVER_INFO ;
            fileServerCounters  :   FILE_SERVER_COUNTERS ;
        End;
    (* Netware File Systems Information *)
    Type
        FSE_FILE_SYSTEM_INFO = Record
            FATMovedCount  :   nuint32 ;
            FATWriteErrorCount  :   nuint32 ;
            someoneElseDidItCount0  :   nuint32 ;
            someoneElseDidItCount1  :   nuint32 ;
            someoneElseDidItCount2  :   nuint32 ;
            iRanOutSomeoneElseDidItCount0  :   nuint32 ;
            iRanOutSomeoneElseDidItCount1  :   nuint32 ;
            iRanOutSomeoneElseDidItCount2  :   nuint32 ;
            turboFATBuildScrewedUpCount  :   nuint32 ;
            extraUseCountNodeCount  :   nuint32 ;
            extraExtraUseCountNodeCount  :   nuint32 ;
            errorReadingLastFATCount  :   nuint32 ;
            someoneElseUsingThisFileCount  :   nuint32 ;
        End;
    Type
        NWFSE_FILE_SYSTEM_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            fileSystemInfo  :   FSE_FILE_SYSTEM_INFO ;
        End;
    (* User Information *)
    (* status *)
    {$DEFINE FSE_LOGGED_IN}
    Const FSE_LOGGED_IN = $00000001;
    {$DEFINE FSE_BEING_ABORTED}
    Const FSE_BEING_ABORTED = $00000002;
    {$DEFINE FSE_AUDITED}
    Const FSE_AUDITED = $00000004;
    {$DEFINE FSE_NEEDS_SECURITY_CHANGE}
    Const FSE_NEEDS_SECURITY_CHANGE = $00000008;
    {$DEFINE FSE_MAC_STATION}
    Const FSE_MAC_STATION = $00000010;
    {$DEFINE FSE_AUTHENTICATED_TEMPORARY}
    Const FSE_AUTHENTICATED_TEMPORARY = $00000020;
    {$DEFINE FSE_AUDIT_CONNECTION_RECORDED}
    Const FSE_AUDIT_CONNECTION_RECORDED = $00000040;
    {$DEFINE FSE_DSAUDIT_CONNECTION_RECORDED}
    Const FSE_DSAUDIT_CONNECTION_RECORDED = $00000080;
    (* fileWriteFlags *)
    {$DEFINE FSE_WRITE}
    Const FSE_WRITE = 1;
    {$DEFINE FSE_WRITE_ABORTED}
    Const FSE_WRITE_ABORTED = 2;
    (* fileWriteState *)
    {$DEFINE FSE_NOT_WRITING}
    Const FSE_NOT_WRITING = 0;
    {$DEFINE FSE_WRITE_IN_PROGRESS}
    Const FSE_WRITE_IN_PROGRESS = 1;
    {$DEFINE FSE_WRITE_BEING_STOPPED}
    Const FSE_WRITE_BEING_STOPPED = 2;
    Type
        USER_INFO = Record
            connNum  :   nuint32 ;
            useCount  :   nuint32 ;
            connServiceType  :   nuint8 ;
            loginTime  :  Array[0..6] Of  nuint8 ;
            status  :   nuint32 ;
            expirationTime  :   nuint32 ;
            objType  :   nuint32 ;
            transactionFlag  :   nuint8 ;
            logicalLockThreshold  :   nuint8 ;
            recordLockThreshold  :   nuint8 ;
            fileWriteFlags  :   nuint8 ;
            fileWriteState  :   nuint8 ;
            filler  :   nuint8 ;
            fileLockCount  :   nuint16 ;
            recordLockCount  :   nuint16 ;
            totalBytesRead  :  Array[0..5] Of  nuint8 ;
            totalBytesWritten  :  Array[0..5] Of  nuint8 ;
            totalRequests  :   nuint32 ;
            heldRequests  :   nuint32 ;
            heldBytesRead  :  Array[0..5] Of  nuint8 ;
            heldBytesWritten  :  Array[0..5] Of  nuint8 ;
        End;
    Type
        NWFSE_USER_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            userInfo  :   USER_INFO ;
        End;
    (* Packet Burst Information *)
    Type
        PACKET_BURST_INFO = Record
            bigInvalidSlotCount  :   nuint32 ;
            bigForgedPacketCount  :   nuint32 ;
            bigInvalidPacketCount  :   nuint32 ;
            bigStillTransmittingCount  :   nuint32 ;
            stillDoingTheLastRequestCount  :   nuint32 ;
            invalidCtrlRequestCount  :   nuint32 ;
            ctrlInvalidMessageNumCount  :   nuint32 ;
            ctrlBeingTornDownCount  :   nuint32 ;
            bigRepeatTheFileReadCount  :   nuint32 ;
            bigSendExtraCCCount  :   nuint32 ;
            bigReturnAbortMessageCount  :   nuint32 ;
            bigReadInvalidMessageNumCount  :   nuint32 ;
            bigReadDoItOverCount  :   nuint32 ;
            bigReadBeingTornDownCount  :   nuint32 ;
            previousCtrlPacketCount  :   nuint32 ;
            sendHoldOffMessageCount  :   nuint32 ;
            bigReadNoDataAvailableCount  :   nuint32 ;
            bigReadTryingToReadTooMuchCount  :   nuint32 ;
            asyncReadErrorCount  :   nuint32 ;
            bigReadPhysicalReadErrorCount  :   nuint32 ;
            ctrlBadACKFragmentListCount  :   nuint32 ;
            ctrlNoDataReadCount  :   nuint32 ;
            writeDuplicateRequestCount  :   nuint32 ;
            shouldntBeACKingHereCount  :   nuint32 ;
            writeInconsistentPktLengthsCnt  :   nuint32 ;
            firstPacketIsntAWriteCount  :   nuint32 ;
            writeTrashedDuplicateRequestCnt  :   nuint32 ;
            bigWriteInvalidMessageNumCount  :   nuint32 ;
            bigWriteBeingTornDownCount  :   nuint32 ;
            bigWriteBeingAbortedCount  :   nuint32 ;
            zeroACKFragmentCountCount  :   nuint32 ;
            writeCurrentlyTransmittingCount  :   nuint32 ;
            tryingToWriteTooMuchCount  :   nuint32 ;
            writeOutOfMemForCtrlNodesCount  :   nuint32 ;
            writeDidntNeedThisFragmentCount  :   nuint32 ;
            writeTooManyBuffsCheckedOutCnt  :   nuint32 ;
            (* writeTooManyBuffersCheckedOutCount *)
            writeTimeOutCount  :   nuint32 ;
            writeGotAnACKCount  :   nuint32 ;
            writeGotAnACKCount1  :   nuint32 ;
            pollerAbortedTheConnCount  :   nuint32 ;
            maybeHadOutOfOrderWritesCount  :   nuint32 ;
            hadAnOutOfOrderWriteCount  :   nuint32 ;
            movedTheACKBitDownCount  :   nuint32 ;
            bumpedOutOfOrderWriteCount  :   nuint32 ;
            pollerRemovedOldOutOfOrderCount  :   nuint32 ;
            writeDidntNeedButRequestACKCnt  :   nuint32 ;
            (* writeDidntNeedButRequestedACKCount *)
            writeTrashedPacketCount  :   nuint32 ;
            tooManyACKFragmentsCount  :   nuint32 ;
            savedAnOutOfOrderPacketCount  :   nuint32 ;
            connBeingAbortedCount  :   nuint32 ;
        End;
    Type
        NWFSE_PACKET_BURST_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            packetBurstInfo  :   PACKET_BURST_INFO ;
        End;
    (* IPX SPX Information *)
    Type
        IPX_INFO = Record
            IPXSendPacketCount  :   nuint32 ;
            IPXMalformPacketCount  :   nuint16 ;
            IPXGetECBRequestCount  :   nuint32 ;
            IPXGetECBFailCount  :   nuint32 ;
            IPXAESEventCount  :   nuint32 ;
            IPXPostponedAESCount  :   nuint16 ;
            IPXMaxConfiguredSocketCount  :   nuint16 ;
            IPXMaxOpenSocketCount  :   nuint16 ;
            IPXOpenSocketFailCount  :   nuint16 ;
            IPXListenECBCount  :   nuint32 ;
            IPXECBCancelFailCount  :   nuint16 ;
            IPXGetLocalTargetFailCount  :   nuint16 ;
        End;
    Type
        SPX_INFO = Record
            SPXMaxConnsCount  :   nuint16 ;
            SPXMaxUsedConns  :   nuint16 ;
            SPXEstConnReq  :   nuint16 ;
            SPXEstConnFail  :   nuint16 ;
            SPXListenConnectReq  :   nuint16 ;
            SPXListenConnectFail  :   nuint16 ;
            SPXSendCount  :   nuint32 ;
            SPXWindowChokeCount  :   nuint32 ;
            SPXBadSendCount  :   nuint16 ;
            SPXSendFailCount  :   nuint16 ;
            SPXAbortedConn  :   nuint16 ;
            SPXListenPacketCount  :   nuint32 ;
            SPXBadListenCount  :   nuint16 ;
            SPXIncomingPacketCount  :   nuint32 ;
            SPXBadInPacketCount  :   nuint16 ;
            SPXSuppressedPackCount  :   nuint16 ;
            SPXNoSesListenECBCount  :   nuint16 ;
            SPXWatchDogDestSesCount  :   nuint16 ;
        End;
    Type
        NWFSE_IPXSPX_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            IPXInfo  :   IPX_INFO ;
            SPXInfo  :   SPX_INFO ;
        End;
    (* Garbage Collection Information *)
    Type
        NWFSE_GARBAGE_COLLECTION_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            failedAllocRequestCount  :   nuint32 ;
            numOfAllocs  :   nuint32 ;
            noMoreMemAvailableCount  :   nuint32 ;
            numOfGarbageCollections  :   nuint32 ;
            garbageFoundSomeMem  :   nuint32 ;
            garbageNumOfChecks  :   nuint32 ;
        End;
    (* CPU Information *)
    {$DEFINE FSE_CPU_STR_MAX}
    Const FSE_CPU_STR_MAX = 16;
    {$DEFINE FSE_COPROCESSOR_STR_MAX}
    Const FSE_COPROCESSOR_STR_MAX = 48;
    {$DEFINE FSE_BUS_STR_MAX}
    Const FSE_BUS_STR_MAX = 32;
    Type
        CPU_INFO = Record
            pageTableOwnerFlag  :   nuint32 ;
            CPUTypeFlag  :   nuint32 ;
            coProcessorFlag  :   nuint32 ;
            busTypeFlag  :   nuint32 ;
            IOEngineFlag  :   nuint32 ;
            FSEngineFlag  :   nuint32 ;
            nonDedicatedFlag  :   nuint32 ;
        End;
    Type
        NWFSE_CPU_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            numOfCPUs  :   nuint32 ;
            CPUInfo  :   CPU_INFO ;
        End;
    (* Volume Switch Information *)
    Type
        VOLUME_SWITCH_INFO = Record
            readFile  :   nuint32 ;
            writeFile  :   nuint32 ;
            deleteFile  :   nuint32 ;
            renMove  :   nuint32 ;
            openFile  :   nuint32 ;
            createFile  :   nuint32 ;
            createAndOpenFile  :   nuint32 ;
            closeFile  :   nuint32 ;
            scanDeleteFile  :   nuint32 ;
            salvageFile  :   nuint32 ;
            purgeFile  :   nuint32 ;
            migrateFile  :   nuint32 ;
            deMigrateFile  :   nuint32 ;
            createDir  :   nuint32 ;
            deleteDir  :   nuint32 ;
            directoryScans  :   nuint32 ;
            mapPathToDirNum  :   nuint32 ;
            modifyDirEntry  :   nuint32 ;
            getAccessRights  :   nuint32 ;
            getAccessRightsFromIDs  :   nuint32 ;
            mapDirNumToPath  :   nuint32 ;
            getEntryFromPathStrBase  :   nuint32 ;
            getOtherNSEntry  :   nuint32 ;
            getExtDirInfo  :   nuint32 ;
            getParentDirNum  :   nuint32 ;
            addTrusteeR  :   nuint32 ;
            scanTrusteeR  :   nuint32 ;
            delTrusteeR  :   nuint32 ;
            purgeTrust  :   nuint32 ;
            findNextTrustRef  :   nuint32 ;
            scanUserRestNodes  :   nuint32 ;
            addUserRest  :   nuint32 ;
            deleteUserRest  :   nuint32 ;
            rtnDirSpaceRest  :   nuint32 ;
            getActualAvailDskSp  :   nuint32 ;
            cntOwnedFilesAndDirs  :   nuint32 ;
            migFileInfo  :   nuint32 ;
            volMigInfo  :   nuint32 ;
            readMigFileData  :   nuint32 ;
            getVolUsageStats  :   nuint32 ;
            getActualVolUsageStats  :   nuint32 ;
            getDirUsageStats  :   nuint32 ;
            NMFileReadsCount  :   nuint32 ;
            NMFileWritesCount  :   nuint32 ;
            (* nuint32  mapPathToDirectoryNumberOrPhantom; *)
            mapPathToDirNumOrPhantom  :   nuint32 ;
            (* nuint32  stationHasAccessRightsGrantedBelow; *)
            stationHasAccessRgtsGntedBelow  :   nuint32 ;
            (* nuint32  getDataStreamLengthsFromPathStringBase; *)
            gtDataStreamLensFromPathStrBase  :   nuint32 ;
            checkAndGetDirectoryEntry  :   nuint32 ;
            getDeletedEntry  :   nuint32 ;
            getOriginalNameSpace  :   nuint32 ;
            getActualFileSize  :   nuint32 ;
            verifyNameSpaceNumber  :   nuint32 ;
            verifyDataStreamNumber  :   nuint32 ;
            checkVolumeNumber  :   nuint32 ;
            commitFile  :   nuint32 ;
            VMGetDirectoryEntry  :   nuint32 ;
            createDMFileEntry  :   nuint32 ;
            renameNameSpaceEntry  :   nuint32 ;
            logFile  :   nuint32 ;
            releaseFile  :   nuint32 ;
            clearFile  :   nuint32 ;
            setVolumeFlag  :   nuint32 ;
            clearVolumeFlag  :   nuint32 ;
            getOriginalInfo  :   nuint32 ;
            createMigratedDir  :   nuint32 ;
            F3OpenCreate  :   nuint32 ;
            F3InitFileSearch  :   nuint32 ;
            F3ContinueFileSearch  :   nuint32 ;
            F3RenameFile  :   nuint32 ;
            F3ScanForTrustees  :   nuint32 ;
            F3ObtainFileInfo  :   nuint32 ;
            F3ModifyInfo  :   nuint32 ;
            F3EraseFile  :   nuint32 ;
            F3SetDirHandle  :   nuint32 ;
            F3AddTrustees  :   nuint32 ;
            F3DeleteTrustees  :   nuint32 ;
            F3AllocDirHandle  :   nuint32 ;
            F3ScanSalvagedFiles  :   nuint32 ;
            F3RecoverSalvagedFiles  :   nuint32 ;
            F3PurgeSalvageableFile  :   nuint32 ;
            F3GetNSSpecificInfo  :   nuint32 ;
            F3ModifyNSSpecificInfo  :   nuint32 ;
            F3SearchSet  :   nuint32 ;
            F3GetDirBase  :   nuint32 ;
            F3QueryNameSpaceInfo  :   nuint32 ;
            F3GetNameSpaceList  :   nuint32 ;
            F3GetHugeInfo  :   nuint32 ;
            F3SetHugeInfo  :   nuint32 ;
            F3GetFullPathString  :   nuint32 ;
            F3GetEffectiveDirectoryRights  :   nuint32 ;
        End;
    Type
        NWFSE_VOLUME_SWITCH_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            totalLFSCounters  :   nuint32 ;
            CurrentLFSCounters  :   nuint32 ;
            LFSCounters  :  Array[0..127] Of  nuint32 ;
            (* VOLUME_SWITCH_INFO volumeSwitchInfo; *)
            (* Cant return all counters *)
        End;
    (* Get NLM Loaded List *)
    {$DEFINE FSE_NLM_NUMS_RETURNED_MAX}
    Const FSE_NLM_NUMS_RETURNED_MAX = 128;
    Type
        NWFSE_NLM_LOADED_LIST = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            numberNLMsLoaded  :   nuint32 ;
            NLMsInList  :   nuint32 ;
            NLMNums  :  Array[0..FSE_NLM_NUMS_RETURNED_MAX-1] Of  nuint32 ;
        End;
    (* NLM Information *)
    (* 1 is added for the NULL *)
    {$DEFINE FSE_NLM_FILENAME_LEN_MAX}
    Const FSE_NLM_FILENAME_LEN_MAX = 37;
    {$DEFINE FSE_NLM_NAMELEN_MAX}
    Const FSE_NLM_NAMELEN_MAX = 129;
    {$DEFINE FSE_NLM_COPYRIGHTLEN_MAX}
    Const FSE_NLM_COPYRIGHTLEN_MAX = 256;
    Type
        NLM_INFO = Record
            identificationNum  :   nuint32 ;
            flags  :   nuint32 ;
            type1  :   nuint32 ;
            parentID  :   nuint32 ;
            majorVersion  :   nuint32 ;
            minorVersion  :   nuint32 ;
            revision  :   nuint32 ;
            year  :   nuint32 ;
            month  :   nuint32 ;
            day  :   nuint32 ;
            allocAvailableBytes  :   nuint32 ;
            allocFreeCount  :   nuint32 ;
            lastGarbageCollection  :   nuint32 ;
            messageLanguage  :   nuint32 ;
            numOfReferencedPublics  :   nuint32 ;
        End;
    Type
        NWFSE_NLM_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            NLMInfo  :   NLM_INFO ;
        End;
    (* Get Directory Cache Information *)
    Type
        DIR_CACHE_INFO = Record
            minTimeSinceFileDelete  :   nuint32 ;
            absMinTimeSinceFileDelete  :   nuint32 ;
            minNumOfDirCacheBuffers  :   nuint32 ;
            maxNumOfDirCacheBuffers  :   nuint32 ;
            numOfDirCacheBuffers  :   nuint32 ;
            dCMinNonReferencedTime  :   nuint32 ;
            dCWaitTimeBeforeNewBuffer  :   nuint32 ;
            dCMaxConcurrentWrites  :   nuint32 ;
            dCDirtyWaitTime  :   nuint32 ;
            dCDoubleReadFlag  :   nuint32 ;
            mapHashNodeCount  :   nuint32 ;
            spaceRestrictionNodeCount  :   nuint32 ;
            trusteeListNodeCount  :   nuint32 ;
            percentOfVolumeUsedByDirs  :   nuint32 ;
        End;
    Type
        NWFSE_DIR_CACHE_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            dirCacheInfo  :   DIR_CACHE_INFO ;
        End;
    (* Get Operating System Version Information *)
    Type
        NWFSE_OS_VERSION_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            OSMajorVersion  :   nuint8 ;
            OSMinorVersion  :   nuint8 ;
            OSRevisionNum  :   nuint8 ;
            accountingVersion  :   nuint8 ;
            VAPVersion  :   nuint8 ;
            queueingVersion  :   nuint8 ;
            securityRestrictionsLevel  :   nuint8 ;
            bridgingSupport  :   nuint8 ;
            maxNumOfVolumes  :   nuint32 ;
            numOfConnSlots  :   nuint32 ;
            maxLoggedInConns  :   nuint32 ;
            maxNumOfNameSpaces  :   nuint32 ;
            maxNumOfLans  :   nuint32 ;
            maxNumOfMediaTypes  :   nuint32 ;
            maxNumOfProtocols  :   nuint32 ;
            maxMaxSubdirTreeDepth  :   nuint32 ;
            maxNumOfDataStreams  :   nuint32 ;
            maxNumOfSpoolPrinters  :   nuint32 ;
            serialNum  :   nuint32 ;
            applicationNum  :   nuint16 ;
        End;
    (* Get Active Connection List by Type *)
    (* Connection service type *)
    (* NOTE: type 1 is reserved by CLIB for backward compatability *)
    {$DEFINE FSE_NCP_CONNECTION_TYPE}
    Const FSE_NCP_CONNECTION_TYPE = 2;
    {$DEFINE FSE_NLM_CONNECTION_TYPE}
    Const FSE_NLM_CONNECTION_TYPE = 3;
    {$DEFINE FSE_AFP_CONNECTION_TYPE}
    Const FSE_AFP_CONNECTION_TYPE = 4;
    {$DEFINE FSE_FTAM_CONNECTION_TYPE}
    Const FSE_FTAM_CONNECTION_TYPE = 5;
    {$DEFINE FSE_ANCP_CONNECTION_TYPE}
    Const FSE_ANCP_CONNECTION_TYPE = 6;
    Type
        NWFSE_ACTIVE_CONN_LIST = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            activeConnBitList  :  Array[0..511] Of  nuint8 ;
        End;
    (* Get NLM's Resource Tag List *)
    Type
        NWFSE_NLMS_RESOURCE_TAG_LIST = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            totalNumOfResourceTags  :   nuint32 ;
            packetResourceTags  :   nuint32 ;
            resourceTagBuf  :  Array[0..511] Of  nuint8 ;
            (* This packed structure consisting of:
   **
   ** nuint32 number,
   ** nuint32 signature,
   ** nuint32 count,
   ** nuint8 name[] *)
        End;
    (* Active LAN Board List --- 20 *)
    {$DEFINE FSE_MAX_NUM_OF_LANS}
    Const FSE_MAX_NUM_OF_LANS = 64;
    Type
        NWFSE_ACTIVE_LAN_BOARD_LIST = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            MaxNumOfLANs  :   nuint32 ;
            LANLoadedCount  :   nuint32 ;
            boardNums  :  Array[0..FSE_MAX_NUM_OF_LANS-1] Of  nuint32 ;
        End;
    (* LAN Configuration Information *)
    Type
        LAN_CONFIG_INFO = Record
            DriverCFG_MajorVersion  :   nuint8 ;
            DriverCFG_MinorVersion  :   nuint8 ;
            DriverNodeAddress  :  Array[0..5] Of  nuint8 ;
            DriverModeFlags  :   nuint16 ;
            DriverBoardNum  :   nuint16 ;
            DriverBoardInstance  :   nuint16 ;
            DriverMaxSize  :   nuint32 ;
            DriverMaxRecvSize  :   nuint32 ;
            DriverRecvSize  :   nuint32 ;
            Reserved1  :  Array[0..2] Of  nuint32 ;
            DriverCardID  :   nuint16 ;
            DriverMediaID  :   nuint16 ;
            DriverTransportTime  :   nuint16 ;
            DriverReserved  :  Array[0..15] Of  nuint8 ;
            DriverMajorVersion  :   nuint8 ;
            DriverMinorVersion  :   nuint8 ;
            DriverFlags  :   nuint16 ;
            DriverSendRetries  :   nuint16 ;
            DriverLink  :   nuint32 ;
            DriverSharingFlags  :   nuint16 ;
            DriverSlot  :   nuint16 ;
            DriverIOPortsAndLengths  :  Array[0..3] Of  nuint16 ;
            DriverMemDecode0  :   nuint32 ;
            DriverLength0  :   nuint16 ;
            DriverMemDecode1  :   nuint32 ;
            DriverLength1  :   nuint16 ;
            DriverInterrupt  :  Array[0..1] Of  nuint8 ;
            DriverDMAUsage  :  Array[0..1] Of  nuint8 ;
            Reserved2  :  Array[0..2] Of  nuint32 ;
            DriverLogicalName  :  Array[0..17] Of  nuint8 ;
            DriverLinearMem  :  Array[0..1] Of  nuint32 ;
            DriverChannelNum  :   nuint16 ;
            DriverIOReserved  :  Array[0..5] Of  nuint8 ;
        End;
    Type
        NWFSE_LAN_CONFIG_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            LANConfigInfo  :   LAN_CONFIG_INFO ;
        End;
    (* LAN Common Counters Information *)
    Type
        LAN_COMMON_INFO = Record
            notSupportedMask  :   nuint32 ;
            totalTxPacketCount  :   nuint32 ;
            totalRxPacketCount  :   nuint32 ;
            noECBAvailableCount  :   nuint32 ;
            packetTxTooBigCount  :   nuint32 ;
            packetTxTooSmallCount  :   nuint32 ;
            packetRxOverflowCount  :   nuint32 ;
            packetRxTooBigCount  :   nuint32 ;
            packetRxTooSmallCount  :   nuint32 ;
            packetTxMiscErrorCount  :   nuint32 ;
            packetRxMiscErrorCount  :   nuint32 ;
            retryTxCount  :   nuint32 ;
            checksumErrorCount  :   nuint32 ;
            hardwareRxMismatchCount  :   nuint32 ;
            reserved  :  Array[0..49] Of  nuint32 ;
        End;
    Type
        NWFSE_LAN_COMMON_COUNTERS_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            statisticsMajorVersion  :   nuint8 ;
            statisticsMinorVersion  :   nuint8 ;
            numberOfGenericCounters  :   nuint32 ;
            numberOfCounterBlocks  :   nuint32 ;
            customVariableCount  :   nuint32 ;
            NextCounterBlock  :   nuint32 ;
            LANCommonInfo  :   LAN_COMMON_INFO ;
        End;
    (* LAN Custom Counters Information *)
    Type
        NWFSE_LAN_CUSTOM_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            numCustomVar  :   nuint32 ;
            customInfo  :  Array[0..511] Of  nuint8 ;
        End;
    (* LSL Information *)
    Type
        LSL_INFO = Record
            rxBufs  :   nuint32 ;
            rxBufs75PerCent  :   nuint32 ;
            rxBufsCheckedOut  :   nuint32 ;
            rxBufMaxSize  :   nuint32 ;
            maxPhysicalSize  :   nuint32 ;
            lastTimeRxBufAllocated  :   nuint32 ;
            maxNumsOfProtocols  :   nuint32 ;
            maxNumsOfMediaTypes  :   nuint32 ;
            totalTXPackets  :   nuint32 ;
            getECBBfrs  :   nuint32 ;
            getECBFails  :   nuint32 ;
            AESEventCounts  :   nuint32 ;
            postponedEvents  :   nuint32 ;
            ECBCxlFails  :   nuint32 ;
            validBfrsReused  :   nuint32 ;
            enqueuedSendCount  :   nuint32 ;
            totalRXPackets  :   nuint32 ;
            unclaimedPackets  :   nuint32 ;
            StatisticsTableMajorVersion  :   nuint8 ;
            StatisticsTableMinorVersion  :   nuint8 ;
        End;
    Type
        NWFSE_LSL_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            LSLInfo  :   LSL_INFO ;
        End;
    (* LSL Logical Board Statistics *)
    Type
        NWFSE_LSL_LOGICAL_BOARD_STATS = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved0  :   nuint16 ;
            LogTtlTxPackets  :   nuint32 ;
            LogTtlRxPackets  :   nuint32 ;
            LogUnclaimedPackets  :   nuint32 ;
            reserved1  :   nuint32 ;
        End;
    (* objtype *)
    {$DEFINE FSE_ADAPTER_OBJECT}
    Const FSE_ADAPTER_OBJECT = 0;
    {$DEFINE FSE_CHANGER_OBJECT}
    Const FSE_CHANGER_OBJECT = 1;
    {$DEFINE FSE_DEVICE_OBJECT}
    Const FSE_DEVICE_OBJECT = 2;
    {$DEFINE FSE_MEDIA_OBJECT}
    Const FSE_MEDIA_OBJECT = 4;
    {$DEFINE FSE_PARTITION_OBJECT}
    Const FSE_PARTITION_OBJECT = 5;
    {$DEFINE FSE_SLOT_OBJECT}
    Const FSE_SLOT_OBJECT = 6;
    {$DEFINE FSE_HOTFIX_OBJECT}
    Const FSE_HOTFIX_OBJECT = 7;
    {$DEFINE FSE_MIRROR_OBJECT}
    Const FSE_MIRROR_OBJECT = 8;
    {$DEFINE FSE_PARITY_OBJECT}
    Const FSE_PARITY_OBJECT = 9;
    {$DEFINE FSE_VOLUME_SEG_OBJECT}
    Const FSE_VOLUME_SEG_OBJECT = 10;
    {$DEFINE FSE_VOLUME_OBJECT}
    Const FSE_VOLUME_OBJECT = 11;
    {$DEFINE FSE_CLONE_OBJECT}
    Const FSE_CLONE_OBJECT = 12;
    {$DEFINE FSE_MAGAZINE_OBJECT}
    Const FSE_MAGAZINE_OBJECT = 14;
    {$DEFINE FSE_VIRTUAL_DEVICE_OBJECT}
    Const FSE_VIRTUAL_DEVICE_OBJECT = 15;
    {$DEFINE FSE_MAX_OBJECTS}
    Const FSE_MAX_OBJECTS = 128;
    {$DEFINE FSE_UNKNOWN_OBJECT}
    Const FSE_UNKNOWN_OBJECT = $FFFF;
    {$DEFINE FSE_UNKNOWN_OBJECT_TYPE}
    Const FSE_UNKNOWN_OBJECT_TYPE = $FFFF;
    (* mediatype *)
    {$DEFINE FSE_HARD_DISK}
    Const FSE_HARD_DISK = 0;
    {$DEFINE FSE_CDROM_DISK}
    Const FSE_CDROM_DISK = 1;
    {$DEFINE FSE_WORM_DISK}
    Const FSE_WORM_DISK = 2;
    {$DEFINE FSE_TAPE_DEVICE}
    Const FSE_TAPE_DEVICE = 3;
    {$DEFINE FSE_MAGNETO_OPTICAL}
    Const FSE_MAGNETO_OPTICAL = 4;
    (* cartridgetype *)
    {$DEFINE FSE_FIXED_MEDIA}
    Const FSE_FIXED_MEDIA = $00000000;
    {$DEFINE FSE_FLOPPY_5_25}
    Const FSE_FLOPPY_5_25 = $00000001;
    {$DEFINE FSE_FLOPPY_3_5}
    Const FSE_FLOPPY_3_5 = $00000002;
    {$DEFINE FSE_OPTICAL_5_25}
    Const FSE_OPTICAL_5_25 = $00000003;
    {$DEFINE FSE_OPTICAL_3_5}
    Const FSE_OPTICAL_3_5 = $00000004;
    {$DEFINE FSE_TAPE_0_5}
    Const FSE_TAPE_0_5 = $00000005;
    {$DEFINE FSE_TAPE_0_25}
    Const FSE_TAPE_0_25 = $00000006;
    {$DEFINE FSE_TAPE_8_MM}
    Const FSE_TAPE_8_MM = $00000007;
    {$DEFINE FSE_TAPE_4_MM}
    Const FSE_TAPE_4_MM = $00000008;
    {$DEFINE FSE_BERNOULLI_DISK}
    Const FSE_BERNOULLI_DISK = $00000009;
    (* type *)
    (* same as defined below for object types *)
    (* status bits *)
    {$DEFINE FSE_OBJECT_ACTIVATED}
    Const FSE_OBJECT_ACTIVATED = $00000001;
    {$DEFINE FSE_OBJECT_CREATED}
    Const FSE_OBJECT_CREATED = $00000002;
    {$DEFINE FSE_OBJECT_SCRAMBLED}
    Const FSE_OBJECT_SCRAMBLED = $00000004;
    {$DEFINE FSE_OBJECT_RESERVED}
    Const FSE_OBJECT_RESERVED = $00000010;
    {$DEFINE FSE_OBJECT_BEING_IDENTIFIED}
    Const FSE_OBJECT_BEING_IDENTIFIED = $00000020;
    {$DEFINE FSE_OBJECT_MAGAZINE_LOADED}
    Const FSE_OBJECT_MAGAZINE_LOADED = $00000040;
    {$DEFINE FSE_OBJECT_FAILURE}
    Const FSE_OBJECT_FAILURE = $00000080;
    {$DEFINE FSE_OBJECT_REMOVABLE}
    Const FSE_OBJECT_REMOVABLE = $00000100;
    {$DEFINE FSE_OBJECT_READ_ONLY}
    Const FSE_OBJECT_READ_ONLY = $00000200;
    {$DEFINE FSE_OBJECT_IN_DEVICE}
    Const FSE_OBJECT_IN_DEVICE = $00010000;
    {$DEFINE FSE_OBJECT_ACCEPTS_MAGAZINES}
    Const FSE_OBJECT_ACCEPTS_MAGAZINES = $00020000;
    {$DEFINE FSE_OBJECT_IS_IN_A_CHANGER}
    Const FSE_OBJECT_IS_IN_A_CHANGER = $00040000;
    {$DEFINE FSE_OBJECT_LOADABLE}
    Const FSE_OBJECT_LOADABLE = $00080000;
    {$DEFINE FSE_OBJECT_BEING_LOADED}
    Const FSE_OBJECT_BEING_LOADED = $00080000;
    {$DEFINE FSE_OBJECT_DEVICE_LOCK}
    Const FSE_OBJECT_DEVICE_LOCK = $01000000;
    {$DEFINE FSE_OBJECT_CHANGER_LOCK}
    Const FSE_OBJECT_CHANGER_LOCK = $02000000;
    {$DEFINE FSE_OBJECT_REMIRRORING}
    Const FSE_OBJECT_REMIRRORING = $04000000;
    {$DEFINE FSE_OBJECT_SELECTED}
    Const FSE_OBJECT_SELECTED = $08000000;
    (* functionmask *)
    {$DEFINE FSE_RANDOM_READ}
    Const FSE_RANDOM_READ = $0001;
    {$DEFINE FSE_RANDOM_WRITE}
    Const FSE_RANDOM_WRITE = $0002;
    {$DEFINE FSE_RANDOM_WRITE_ONCE}
    Const FSE_RANDOM_WRITE_ONCE = $0004;
    {$DEFINE FSE_SEQUENTIAL_READ}
    Const FSE_SEQUENTIAL_READ = $0008;
    {$DEFINE FSE_SEQUENTIAL_WRITE}
    Const FSE_SEQUENTIAL_WRITE = $0010;
    {$DEFINE FSE_RESET_END_OF_TAPE}
    Const FSE_RESET_END_OF_TAPE = $0020;
    {$DEFINE FSE_SINGLE_FILE_MARK}
    Const FSE_SINGLE_FILE_MARK = $0040;
    {$DEFINE FSE_MULTIPLE_FILE_MARK}
    Const FSE_MULTIPLE_FILE_MARK = $0080;
    {$DEFINE FSE_SINGLE_SET_MARK}
    Const FSE_SINGLE_SET_MARK = $0100;
    {$DEFINE FSE_MULTIPLE_SET_MARK}
    Const FSE_MULTIPLE_SET_MARK = $0200;
    {$DEFINE FSE_SPACE_DATA_BLOCKS}
    Const FSE_SPACE_DATA_BLOCKS = $0400;
    {$DEFINE FSE_LOCATE_DATA_BLOCKS}
    Const FSE_LOCATE_DATA_BLOCKS = $0800;
    {$DEFINE FSE_POSITION_PARTITION}
    Const FSE_POSITION_PARTITION = $1000;
    {$DEFINE FSE_POSITION_MEDIA}
    Const FSE_POSITION_MEDIA = $2000;
    (* controlmask *)
    {$DEFINE FSE_ACTIVATE_DEACTIVE}
    Const FSE_ACTIVATE_DEACTIVE = $0001;
    {$DEFINE FSE_MOUNT_DISMOUNT}
    Const FSE_MOUNT_DISMOUNT = $0002;
    {$DEFINE FSE_SELECT_UNSELECT}
    Const FSE_SELECT_UNSELECT = $0004;
    {$DEFINE FSE_LOCK_UNLOCK}
    Const FSE_LOCK_UNLOCK = $0008;
    {$DEFINE FSE_EJECT}
    Const FSE_EJECT = $0010;
    {$DEFINE FSE_MOVE}
    Const FSE_MOVE = $0020;
    Type
        MEDIA_INFO_DEF = Record
            label1  :  Array[0..63] Of  nuint8 ;
            identificationType  :   nuint32 ;
            identificationTimeStamp  :   nuint32 ;
        End;
    Type
        FSE_MM_OBJ_INFO = Record
            MediaInfo  :   MEDIA_INFO_DEF ;
            mediaType  :   nuint32 ;
            cartridgeType  :   nuint32 ;
            unitSize  :   nuint32 ;
            blockSize  :   nuint32 ;
            capacity  :   nuint32 ;
            preferredUnitSize  :   nuint32 ;
            name  :  Array[0..63] Of  nuint8 ;
            type1  :   nuint32 ;
            status  :   nuint32 ;
            functionMask  :   nuint32 ;
            controlMask  :   nuint32 ;
            parentCount  :   nuint32 ;
            siblingCount  :   nuint32 ;
            childCount  :   nuint32 ;
            specificInfoSize  :   nuint32 ;
            objectUniqueID  :   nuint32 ;
            mediaSlot  :   nuint32 ;
        End;
    Type
        NWFSE_MEDIA_MGR_OBJ_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            fseMMObjInfo  :   FSE_MM_OBJ_INFO ;
        End;
    (* Get Media Manager Objects List
   Get Media Manager Object Children's List  *)
    Type
        NWFSE_MEDIA_MGR_OBJ_LIST = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            nextStartObjNum  :   nuint32 ;
            objCount  :   nuint32 ;
            objs  :  Array[0..FSE_MAX_OBJECTS-1] Of  nuint32 ;
        End;
    (* Get Volume Segment List *)
    {$DEFINE FSE_MAX_NUM_SEGS_RETURNED}
    Const FSE_MAX_NUM_SEGS_RETURNED = 43;
    Type
        VOLUME_SEGMENT = Record
            volumeSegmentDeviceNum  :   nuint32 ;
            volumeSegmentOffset  :   nuint32 ;
            volumeSegmentSize  :   nuint32 ;
        End;
    Type
        NWFSE_VOLUME_SEGMENT_LIST = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            numOfVolumeSegments  :   nuint32 ;
            volumeSegment  :  Array[0..41] Of  VOLUME_SEGMENT ;
        End;
    (* Volume Information by Level *)
    Type
        VOLUME_INFO_BY_LEVEL_DEF = Record
            volumeType  :   nuint32 ;
            statusFlagBits  :   nuint32 ;
            sectorSize  :   nuint32 ;
            sectorsPerCluster  :   nuint32 ;
            volumeSizeInClusters  :   nuint32 ;
            freedClusters  :   nuint32 ;
            subAllocFreeableClusters  :   nuint32 ;
            freeableLimboSectors  :   nuint32 ;
            nonFreeableLimboSectors  :   nuint32 ;
            nonFreeableAvailSubAllocSectors  :   nuint32 ;
            notUsableSubAllocSectors  :   nuint32 ;
            subAllocClusters  :   nuint32 ;
            dataStreamsCount  :   nuint32 ;
            limboDataStreamsCount  :   nuint32 ;
            oldestDeletedFileAgeInTicks  :   nuint32 ;
            compressedDataStreamsCount  :   nuint32 ;
            compressedLimboDataStreamsCount  :   nuint32 ;
            unCompressableDataStreamsCount  :   nuint32 ;
            preCompressedSectors  :   nuint32 ;
            compressedSectors  :   nuint32 ;
            migratedFiles  :   nuint32 ;
            migratedSectors  :   nuint32 ;
            clustersUsedByFAT  :   nuint32 ;
            clustersUsedByDirectories  :   nuint32 ;
            clustersUsedByExtendedDirs  :   nuint32 ;
            totalDirectoryEntries  :   nuint32 ;
            unUsedDirectoryEntries  :   nuint32 ;
            totalExtendedDirectoryExtants  :   nuint32 ;
            unUsedExtendedDirectoryExtants  :   nuint32 ;
            extendedAttributesDefined  :   nuint32 ;
            extendedAttributeExtantsUsed  :   nuint32 ;
            directoryServicesObjectID  :   nuint32 ;
            volumeLastModifiedDateAndTime  :   nuint32 ;
        End;
    Type
        VOLUME_INFO_BY_LEVEL_DEF2 = Record
            volumeActiveCount  :   nuint32 ;
            volumeUseCount  :   nuint32 ;
            mACRootIDs  :   nuint32 ;
            volumeLastModifiedDateAndTime  :   nuint32 ;
            volumeReferenceCount  :   nuint32 ;
            compressionLowerLimit  :   nuint32 ;
            outstandingIOs  :   nuint32 ;
            outstandingCompressionIOs  :   nuint32 ;
            compressionIOsLimit  :   nuint32 ;
        End;
    Type volInfoDef  =   VOLUME_INFO_BY_LEVEL_DEF ;  (* union statement *)
    Type VOLUME_INFO_BY_LEVEL = volInfoDef;
    Type
        NWFSE_VOLUME_INFO_BY_LEVEL = Record
            serverAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            infoLevel  :   nuint32 ;
            volumeInfo  :   VOLUME_INFO_BY_LEVEL ;
        End;
    (* Active Protocol Stacks *)
    {$DEFINE FSE_MAX_NUM_OF_STACKINFO}
    Const FSE_MAX_NUM_OF_STACKINFO = 25;
    Type
        STACK_INFO = Record
            StackNum  :   nuint32 ;
            StackShortName  :  Array[0..15] Of  nuint8 ;
        End;
    Type
        NWFSE_ACTIVE_STACKS = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            maxNumOfStacks  :   nuint32 ;
            stackCount  :   nuint32 ;
            nextStartNum  :   nuint32 ;
            stackInfo  :  Array[0..FSE_MAX_NUM_OF_STACKINFO-1] Of  STACK_INFO ;
        End;
    (* Get Protocol Stack Configuration Information *)
    {$DEFINE FSE_STK_FULL_NAME_STR_LEN_MAX}
    Const FSE_STK_FULL_NAME_STR_LEN_MAX = 256;
    Type
        NWFSE_PROTOCOL_STK_CONFIG_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            configMajorVersionNum  :   nuint8 ;
            configMinorVersionNum  :   nuint8 ;
            stackMajorVersionNum  :   nuint8 ;
            stackMinorVersionNum  :   nuint8 ;
            stackShortName  :  Array[0..15] Of  nuint8 ;
        End;
    (* Get Protocol Stack Statistics Information  *)
    Type
        NWFSE_PROTOCOL_STK_STATS_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            statMajorVersionNum  :   nuint8 ;
            statMinorVersionNum  :   nuint8 ;
            commonCounters  :   nuint16 ;
            validCountersMask  :   nuint32 ;
            totalTxPackets  :   nuint32 ;
            totalRxPackets  :   nuint32 ;
            ignoredRxPackets  :   nuint32 ;
            numCustomCounters  :   nuint16 ;
        End;
    (* Get Protocol Stack Custom Information *)
    Type
        NWFSE_PROTOCOL_CUSTOM_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved0  :   nuint16 ;
            customCount  :   nuint32 ;
            customStruct  :  Array[0..511] Of  nuint8 ;
        End;
    {$DEFINE FSE_STACK_IDS_MAX}
    Const FSE_STACK_IDS_MAX = 128;
    {$DEFINE FSE_NO_FRAME_ID_MAC}
    Const FSE_NO_FRAME_ID_MAC = 0;
    {$DEFINE FSE_APPLE_LOCALTALK}
    Const FSE_APPLE_LOCALTALK = 1;
    {$DEFINE FSE_ETHERNETII_DEC}
    Const FSE_ETHERNETII_DEC = 2;
    {$DEFINE FSE_ETHERNET_802_3_USING_802_2}
    Const FSE_ETHERNET_802_3_USING_802_2 = 3;
    {$DEFINE FSE_TRING_802_5_USING_802_2}
    Const FSE_TRING_802_5_USING_802_2 = 4;
    {$DEFINE FSE_IPX_802_3}
    Const FSE_IPX_802_3 = 5;
    {$DEFINE FSE_TOKEN_PASSING_BUS}
    Const FSE_TOKEN_PASSING_BUS = 6;
    {$DEFINE FSE_IBM_PC_NETWORK_II}
    Const FSE_IBM_PC_NETWORK_II = 7;
    {$DEFINE FSE_GATEWAY_GNET}
    Const FSE_GATEWAY_GNET = 8;
    {$DEFINE FSE_PROTEON_PRONET}
    Const FSE_PROTEON_PRONET = 9;
    {$DEFINE FSE_ENET_802_3_USING_802_2_SNAP}
    Const FSE_ENET_802_3_USING_802_2_SNAP = 10;
    {$DEFINE FSE_TRING_802_5_USE_802_2_SNAP}
    Const FSE_TRING_802_5_USE_802_2_SNAP = 11;
    {$DEFINE FSE_RACORE_FRAME}
    Const FSE_RACORE_FRAME = 12;
    {$DEFINE FSE_ISDN_FRAME}
    Const FSE_ISDN_FRAME = 13;
    {$DEFINE FSE_NOVELL_ARCNET}
    Const FSE_NOVELL_ARCNET = 14;
    {$DEFINE FSE_IBM_PCN2_USING_802_2}
    Const FSE_IBM_PCN2_USING_802_2 = 15;
    {$DEFINE FSE_IBM_PCN2_USING_802_2_SNAP}
    Const FSE_IBM_PCN2_USING_802_2_SNAP = 16;
    {$DEFINE FSE_CORVUS_FRAME}
    Const FSE_CORVUS_FRAME = 17;
    {$DEFINE FSE_HARRIS_ADACOM_FRAME}
    Const FSE_HARRIS_ADACOM_FRAME = 18;
    {$DEFINE FSE_IP_TUNNEL_FRAME}
    Const FSE_IP_TUNNEL_FRAME = 19;
    {$DEFINE FSE_FDDI_USING_802_2}
    Const FSE_FDDI_USING_802_2 = 20;
    {$DEFINE FSE_COMMTEX_FRAME}
    Const FSE_COMMTEX_FRAME = 21;
    {$DEFINE FSE_DATACO_FRAME}
    Const FSE_DATACO_FRAME = 22;
    {$DEFINE FSE_FDDI_USING_802_2_SMAP}
    Const FSE_FDDI_USING_802_2_SMAP = 23;
    {$DEFINE FSE_SDLC_TUNNEL}
    Const FSE_SDLC_TUNNEL = 24;
    {$DEFINE FSE_PC_OFFICE_FRAME}
    Const FSE_PC_OFFICE_FRAME = 25;
    {$DEFINE FSE_HYPERCOMMUNICATIONS}
    Const FSE_HYPERCOMMUNICATIONS = 26;
    {$DEFINE FSE_NOVELL_FRAME}
    Const FSE_NOVELL_FRAME = 27;
    Type
        NWFSE_PROTOCOL_ID_NUMS = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            stackIDCount  :   nuint32 ;
            stackIDs  :  Array[0..FSE_STACK_IDS_MAX-1] Of  nuint32 ;
        End;
    (* Get Media Name by Media Number *)
    {$DEFINE FSE_MEDIA_NAME_LEN_MAX}
    Const FSE_MEDIA_NAME_LEN_MAX = 81;
    Type
        NWFSE_MEDIA_NAME_LIST = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
        End;
    (* Get Loaded Media Number List *)
    {$DEFINE FSE_MEDIA_LIST_MAX}
    Const FSE_MEDIA_LIST_MAX = 32;
    Type
        NWFSE_LOADED_MEDIA_NUM_LIST = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            maxMediaTypes  :   nuint32 ;
            mediaListCount  :   nuint32 ;
            mediaList  :  Array[0..FSE_MEDIA_LIST_MAX-1] Of  nuint32 ;
        End;
    (* Get General Router And SAP Information *)
    Type
        NWFSE_GENERAL_ROUTER_SAP_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            internalRIPSocket  :   nuint32 ;
            internalRouterDownFlag  :   nuint32 ;
            trackOnFlag  :   nuint32 ;
            externalRouterActiveFlag  :   nuint32 ;
            internalSAPSocketNumber  :   nuint32 ;
            replyToNearestServerFlag  :   nuint32 ;
        End;
    (* Get Network Router Information *)
    Type
        NWFSE_NETWORK_ROUTER_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            NetIDNumber  :   nuint32 ;
            HopsToNet  :   nuint16 ;
            NetStatus  :   nuint16 ;
            TimeToNet  :   nuint16 ;
        End;
    (* Get Network Routers Information *)
    Type
        ROUTERS_INFO = Record
            nodeAddress  :  Array[0..5] Of  nuint8 ;
            connectedLAN  :   nuint32 ;
            routeHops  :   nuint16 ;
            routeTime  :   nuint16 ;
        End;
    Type
        NWFSE_NETWORK_ROUTERS_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            NumberOfEntries  :   nuint32 ;
            routersInfo  :  Array[0..35] Of  ROUTERS_INFO ;
        End;
    (* Get Known Networks Information *)
    {$DEFINE FSE_LOCALBIT}
    Const FSE_LOCALBIT = $01;
    {$DEFINE FSE_NETSTARBIT}
    Const FSE_NETSTARBIT = $02;
    {$DEFINE FSE_NETRELIABLEBIT}
    Const FSE_NETRELIABLEBIT = $04;
    {$DEFINE FSE_NETWANBIT}
    Const FSE_NETWANBIT = $10;
    Type
        KNOWN_NET_INFO = Record
            netIDNumber  :   nuint32 ;
            hopsToNet  :   nuint16 ;
            netStatus  :   nuint16 ;
            timeToNet  :   nuint16 ;
        End;
    Type
        NWFSE_KNOWN_NETWORKS_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            numberOfEntries  :   nuint32 ;
            knownNetInfo  :  Array[0..50] Of  KNOWN_NET_INFO ;
        End;
    (* Get Server Information *)
    Type
        NWFSE_SERVER_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            serverAddress  :  Array[0..11] Of  nuint8 ;
            hopsToServer  :   nuint16 ;
        End;
    (* Get Server Sources Information *)
    Type
        SERVERS_SRC_INFO = Record
            serverNode  :  Array[0..5] Of  nuint8 ;
            connectedLAN  :   nuint32 ;
            sourceHops  :   nuint16 ;
        End;
    Type
        NWFSE_SERVER_SRC_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            numberOfEntries  :   nuint32 ;
            serversSrcInfo  :  Array[0..41] Of  SERVERS_SRC_INFO ;
        End;
    Type
        NWFSE_KNOWN_SERVER_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            numberOfEntries  :   nuint32 ;
            data  :  Array[0..511] Of  nuint8 ;
        End;
    {$DEFINE FSE_TYPE_NUMBER}
    Const FSE_TYPE_NUMBER = 0;
    {$DEFINE FSE_TYPE_BOOLEAN}
    Const FSE_TYPE_BOOLEAN = 1;
    {$DEFINE FSE_TYPE_TICKS}
    Const FSE_TYPE_TICKS = 2;
    {$DEFINE FSE_TYPE_BLOCK_SHIFT}
    Const FSE_TYPE_BLOCK_SHIFT = 3;
    {$DEFINE FSE_TYPE_TIME_OFFSET}
    Const FSE_TYPE_TIME_OFFSET = 4;
    {$DEFINE FSE_TYPE_STRING}
    Const FSE_TYPE_STRING = 5;
    {$DEFINE FSE_TYPE_TRIGGER}
    Const FSE_TYPE_TRIGGER = 6;
    {$DEFINE FSE_TYPE_TRIGGER_OFF}
    Const FSE_TYPE_TRIGGER_OFF = $00;
    {$DEFINE FSE_TYPE_TRIGGER_ON}
    Const FSE_TYPE_TRIGGER_ON = $01;
    {$DEFINE FSE_TYPE_TRIGGER_PENDING}
    Const FSE_TYPE_TRIGGER_PENDING = $10;
    {$DEFINE FSE_TYPE_TRIGGER_SUCCESS}
    Const FSE_TYPE_TRIGGER_SUCCESS = $20;
    {$DEFINE FSE_TYPE_TRIGGER_FAILED}
    Const FSE_TYPE_TRIGGER_FAILED = $30;
    (* setCmdFlags *)
    {$DEFINE FSE_STARTUP_ONLY}
    Const FSE_STARTUP_ONLY = $01;
    {$DEFINE FSE_HIDE}
    Const FSE_HIDE = $02;
    {$DEFINE FSE_ADVANCED}
    Const FSE_ADVANCED = $04;
    {$DEFINE FSE_STARTUP_OR_LATER}
    Const FSE_STARTUP_OR_LATER = $08;
    {$DEFINE FSE_NOT_SECURED_CONSOLE}
    Const FSE_NOT_SECURED_CONSOLE = $10;
    (* setCmdCategory    *)
    {$DEFINE FSE_COMMUNICATIONS}
    Const FSE_COMMUNICATIONS = 0;
    {$DEFINE FSE_MEMORY}
    Const FSE_MEMORY = 1;
    {$DEFINE FSE_FILE_CACHE}
    Const FSE_FILE_CACHE = 2;
    {$DEFINE FSE_DIR_CACHE}
    Const FSE_DIR_CACHE = 3;
    {$DEFINE FSE_FILE_SYSTEM}
    Const FSE_FILE_SYSTEM = 4;
    {$DEFINE FSE_LOCKS}
    Const FSE_LOCKS = 5;
    {$DEFINE FSE_TRANSACTION_TRACKING}
    Const FSE_TRANSACTION_TRACKING = 6;
    {$DEFINE FSE_DISK}
    Const FSE_DISK = 7;
    {$DEFINE FSE_TIME}
    Const FSE_TIME = 8;
    {$DEFINE FSE_NCP}
    Const FSE_NCP = 9;
    {$DEFINE FSE_MISCELLANEOUS}
    Const FSE_MISCELLANEOUS = 10;
    {$DEFINE FSE_ERRORS}
    Const FSE_ERRORS = 11;
    Type
        NWFSE_SERVER_SET_CMDS_INFO = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            numberOfSetCommands  :   nuint32 ;
            nextSequenceNumber  :   nuint32 ;
            setCmdType  :   nuint32 ;
            setCmdCategory  :   nuint32 ;
            setCmdFlags  :   nuint32 ;
            (*  The setNameAndValueInfo contains ASCIIZ strings in the following layout:
   **    nuint8 setCmdName[ ];
   **    nuint8 setCmdValue[ ]; *)
            setNameAndValueInfo  :  Array[0..499] Of  nuint8 ;
        End;
    Type
        NWFSE_SERVER_SET_CATEGORIES = Record
            serverTimeAndVConsoleInfo  :   SERVER_AND_VCONSOLE_INFO ;
            reserved  :   nuint16 ;
            numberOfSetCategories  :   nuint32 ;
            nextSequenceNumber  :   nuint32 ;
            categoryName  :  Array[0..511] Of  nuint8 ;
        End;
    Function NWGetCacheInfo (
        conn  :   NWCONN_HANDLE ;
        Var fseCacheInfo  : NWFSE_CACHE_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetFileServerInfo (
        conn  :   NWCONN_HANDLE ;
        Var fseFileServerInfo  : NWFSE_FILE_SERVER_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetNetWareFileSystemsInfo (
        conn  :   NWCONN_HANDLE ;
        Var fseFileSystemInfo  : NWFSE_FILE_SYSTEM_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetUserInfo (
        conn  :   NWCONN_HANDLE ;
        connNum  :   nuint32 ;
        userName  :   pnstr8 ;
        Var fseUserInfo  : NWFSE_USER_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetPacketBurstInfo (
        conn  :   NWCONN_HANDLE ;
        Var fsePacketBurstInfo  : NWFSE_PACKET_BURST_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetIPXSPXInfo (
        conn  :   NWCONN_HANDLE ;
        Var fseIPXSPXInfo  : NWFSE_IPXSPX_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetGarbageCollectionInfo (
        conn  :   NWCONN_HANDLE ;
        Var fseGarbageCollectionInfo  : NWFSE_GARBAGE_COLLECTION_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetCPUInfo (
        conn  :   NWCONN_HANDLE ;
        CPUNum  :   nuint32 ;
        CPUName  :   pnstr8 ;
        numCoprocessor  :   pnstr8 ;
        bus  :   pnstr8 ;
        Var fseCPUInfo  : NWFSE_CPU_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetVolumeSwitchInfo (
        conn  :   NWCONN_HANDLE ;
        startNum  :   nuint32 ;
        Var fseVolumeSwitchInfo  : NWFSE_VOLUME_SWITCH_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetNLMLoadedList (
        conn  :   NWCONN_HANDLE ;
        startNum  :   nuint32 ;
        Var fseNLMLoadedList  : NWFSE_NLM_LOADED_LIST
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetNLMInfo (
        conn  :   NWCONN_HANDLE ;
        NLMNum  :   nuint32 ;
        fileName  :   pnstr8 ;
        NLMname  :   pnstr8 ;
        copyright  :   pnstr8 ;
        Var fseNLMInfo  : NWFSE_NLM_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetDirCacheInfo (
        conn  :   NWCONN_HANDLE ;
        Var fseDirCacheInfo  : NWFSE_DIR_CACHE_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetOSVersionInfo (
        conn  :   NWCONN_HANDLE ;
        Var fseOSVersionInfo  : NWFSE_OS_VERSION_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetActiveConnListByType (
        conn  :   NWCONN_HANDLE ;
        startConnNum  :   nuint32 ;
        connType  :   nuint32 ;
        Var fseActiveConnListByType  : NWFSE_ACTIVE_CONN_LIST
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetNLMsResourceTagList (
        conn  :   NWCONN_HANDLE ;
        NLMNum  :   nuint32 ;
        startNum  :   nuint32 ;
        Var fseNLMsResourceTagList  : NWFSE_NLMS_RESOURCE_TAG_LIST
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetActiveLANBoardList (
        conn  :   NWCONN_HANDLE ;
        startNum  :   nuint32 ;
        Var fseActiveLANBoardList  : NWFSE_ACTIVE_LAN_BOARD_LIST
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetLANConfigInfo (
        conn  :   NWCONN_HANDLE ;
        boardNum  :   nuint32 ;
        Var fseLANConfigInfo  : NWFSE_LAN_CONFIG_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetLANCommonCountersInfo (
        conn  :   NWCONN_HANDLE ;
        boardNum  :   nuint32 ;
        blockNum  :   nuint32 ;
        Var fseLANCommonCountersInfo  : NWFSE_LAN_COMMON_COUNTERS_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetLANCustomCountersInfo (
        conn  :   NWCONN_HANDLE ;
        boardNum  :   nuint32 ;
        startingNum  :   nuint32 ;
        Var fseLANCustomInfo  : NWFSE_LAN_CUSTOM_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetLSLInfo (
        conn  :   NWCONN_HANDLE ;
        Var fseLSLInfo  : NWFSE_LSL_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetLSLLogicalBoardStats (
        conn  :   NWCONN_HANDLE ;
        LANBoardNum  :   nuint32 ;
        Var fseLSLLogicalBoardStats  : NWFSE_LSL_LOGICAL_BOARD_STATS
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetMediaMgrObjInfo (
        conn  :   NWCONN_HANDLE ;
        objNum  :   nuint32 ;
        Var fseMediaMgrObjInfo  : NWFSE_MEDIA_MGR_OBJ_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetMediaMgrObjList (
        conn  :   NWCONN_HANDLE ;
        startNum  :   nuint32 ;
        objType  :   nuint32 ;
        Var fseMediaMgrObjList  : NWFSE_MEDIA_MGR_OBJ_LIST
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetMediaMgrObjChildrenList (
        conn  :   NWCONN_HANDLE ;
        startNum  :   nuint32 ;
        objType  :   nuint32 ;
        parentObjNum  :   nuint32 ;
        Var fseMediaMgrObjList  : NWFSE_MEDIA_MGR_OBJ_LIST
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetVolumeSegmentList (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint32 ;
        Var fseVolumeSegmentList  : NWFSE_VOLUME_SEGMENT_LIST
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetVolumeInfoByLevel (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint32 ;
        infoLevel  :   nuint32 ;
        Var fseVolumeInfo  : NWFSE_VOLUME_INFO_BY_LEVEL
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetActiveProtocolStacks (
        conn  :   NWCONN_HANDLE ;
        startNum  :   nuint32 ;
        Var fseActiveStacks  : NWFSE_ACTIVE_STACKS
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetProtocolStackConfigInfo (
        conn  :   NWCONN_HANDLE ;
        stackNum  :   nuint32 ;
        stackFullName  :   pnstr8 ;
        Var fseProtocolStkConfigInfo  : NWFSE_PROTOCOL_STK_CONFIG_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetProtocolStackStatsInfo (
        conn  :   NWCONN_HANDLE ;
        stackNum  :   nuint32 ;
        Var fseProtocolStkStatsInfo  : NWFSE_PROTOCOL_STK_STATS_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetProtocolStackCustomInfo (
        conn  :   NWCONN_HANDLE ;
        stackNum  :   nuint32 ;
        customStartNum  :   nuint32 ;
        Var fseProtocolStackCustomInfo  : NWFSE_PROTOCOL_CUSTOM_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetProtocolStkNumsByMediaNum (
        conn  :   NWCONN_HANDLE ;
        mediaNum  :   nuint32 ;
        Var fseProtocolStkIDNums  : NWFSE_PROTOCOL_ID_NUMS
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetProtocolStkNumsByLANBrdNum (
        conn  :   NWCONN_HANDLE ;
        LANBoardNum  :   nuint32 ;
        Var fseProtocolStkIDNums  : NWFSE_PROTOCOL_ID_NUMS
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetMediaNameByMediaNum (
        conn  :   NWCONN_HANDLE ;
        mediaNum  :   nuint32 ;
        mediaName  :   pnstr8 ;
        Var fseMediaNameList  : NWFSE_MEDIA_NAME_LIST
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetLoadedMediaNumList (
        conn  :   NWCONN_HANDLE ;
        Var fseLoadedMediaNumList  : NWFSE_LOADED_MEDIA_NUM_LIST
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetGeneralRouterAndSAPInfo (
        conn  :   NWCONN_HANDLE ;
        Var fseGeneralRouterSAPInfo  : NWFSE_GENERAL_ROUTER_SAP_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetNetworkRouterInfo (
        conn  :   NWCONN_HANDLE ;
        networkNum  :   nuint32 ;
        Var fseNetworkRouterInfo  : NWFSE_NETWORK_ROUTER_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetNetworkRoutersInfo (
        conn  :   NWCONN_HANDLE ;
        networkNum  :   nuint32 ;
        startNum  :   nuint32 ;
        Var fseNetworkRoutersInfo  : NWFSE_NETWORK_ROUTERS_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetKnownNetworksInfo (
        conn  :   NWCONN_HANDLE ;
        startNum  :   nuint32 ;
        Var fseKnownNetworksInfo  : NWFSE_KNOWN_NETWORKS_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetServerInfo (
        conn  :   NWCONN_HANDLE ;
        serverType  :   nuint32 ;
        serverName  :   pnstr8 ;
        Var fseServerInfo  : NWFSE_SERVER_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetServerSourcesInfo (
        conn  :   NWCONN_HANDLE ;
        startNum  :   nuint32 ;
        serverType  :   nuint32 ;
        serverName  :   pnstr8 ;
        Var fseServerSrcInfo  : NWFSE_SERVER_SRC_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetKnownServersInfo (
        conn  :   NWCONN_HANDLE ;
        startNum  :   nuint32 ;
        serverType  :   nuint32 ;
        Var fseKnownServerInfo  : NWFSE_KNOWN_SERVER_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetServerSetCommandsInfo (
        conn  :   NWCONN_HANDLE ;
        startNum  :   nuint32 ;
        Var fseServerSetCmdsInfo  : NWFSE_SERVER_SET_CMDS_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetServerSetCategories (
        conn  :   NWCONN_HANDLE ;
        startNum  :   nuint32 ;
        Var fseServerSetCategories  : NWFSE_SERVER_SET_CATEGORIES
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

