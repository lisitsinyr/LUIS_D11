(*      (c) COPYRIGHT 1988-1991 by Novell, Inc.  All Rights Reserved.    *)


{$IFNDEF _DIAG_H}

{$DEFINE _DIAG_H}

{$I nwcaldef.inc}

{$IFNDEF _NXT_H}

{$I nxtd.inc}
{$ENDIF}


(* ------------------- Defines --------------------*)

(* Limits *)

{$DEFINE MAX_NETWORKS}
Const MAX_NETWORKS = 120;
{$DEFINE MAX_SERVERS}
Const MAX_SERVERS = 150;
{$DEFINE MAX_NODES}
Const MAX_NODES = 120;
{$DEFINE MAX_EXCLUSIONS}
Const MAX_EXCLUSIONS = 80;

{$DEFINE MAX_LOCAL_NETWORKS}
Const MAX_LOCAL_NETWORKS = 4;
{$DEFINE MAX_ROUTES}
Const MAX_ROUTES = 47;

{$DEFINE MAX_IPX_PACKET_SIZE}
Const MAX_IPX_PACKET_SIZE = 576;

{$DEFINE MAX_SERVER_NAME_LENGTH}
Const MAX_SERVER_NAME_LENGTH = 16;
{$DEFINE WORKGROUP_NAME_LENGTH}
Const WORKGROUP_NAME_LENGTH = 16;
{$DEFINE OEM_NAME_LENGTH}
Const OEM_NAME_LENGTH = 16;

(* Component IDs *)

{$DEFINE IPX_SPX_COMPONENT}
Const IPX_SPX_COMPONENT = 0;
{$DEFINE BRIDGE_DRIVER_COMPONENT}
Const BRIDGE_DRIVER_COMPONENT = 1;
{$DEFINE SHELL_DRIVER_COMPONENT}
Const SHELL_DRIVER_COMPONENT = 2;
{$DEFINE SHELL_COMPONENT}
Const SHELL_COMPONENT = 3;
{$DEFINE VAP_SHELL_COMPONENT}
Const VAP_SHELL_COMPONENT = 4;
{$DEFINE BRIDGE_COMPONENT}
Const BRIDGE_COMPONENT = 5;
{$DEFINE FILE_SERVER_COMPONENT}
Const FILE_SERVER_COMPONENT = 6;
{$DEFINE NONDEDICATED_IPX_SPX_COMPONENT}
Const NONDEDICATED_IPX_SPX_COMPONENT = 7;
{$DEFINE IPX_ONLY}
Const IPX_ONLY = 8;
{$DEFINE GNMA_DOS_COMPONENT}
Const GNMA_DOS_COMPONENT = 9;
{$DEFINE GNMA_OS2_COMPONENT}
Const GNMA_OS2_COMPONENT = 10;
{$DEFINE NWLITE_SERVER_COMPONENT}
Const NWLITE_SERVER_COMPONENT = 11;
{$DEFINE NWLITE_CACHE_COMPONENT}
Const NWLITE_CACHE_COMPONENT = 12;

{$DEFINE MAX_COMPONENTS}
Const MAX_COMPONENTS = 13;


(* Error Codes *)

{$DEFINE NO_ERRORS}
Const NO_ERRORS = $00;
{$DEFINE COULD_NOT_GET_LOCAL_TARGET}
Const COULD_NOT_GET_LOCAL_TARGET = $FF;
{$DEFINE COULD_NOT_OPEN_SOCKET}
Const COULD_NOT_OPEN_SOCKET = $FE;
{$DEFINE COULD_NOT_BEGIN_CONNECTION}
Const COULD_NOT_BEGIN_CONNECTION = $FD;
{$DEFINE COULD_NOT_ESTABLISH_CONNECTION}
Const COULD_NOT_ESTABLISH_CONNECTION = $FC;
{$DEFINE COULD_NOT_TERMINATE_CONNECTION}
Const COULD_NOT_TERMINATE_CONNECTION = $FB;
{$DEFINE BAD_CONNECTION_ID}
Const BAD_CONNECTION_ID = $FA;
{$DEFINE COULD_NOT_SEND_REQUEST}
Const COULD_NOT_SEND_REQUEST = $F9;
{$DEFINE RECEIVED_REPLY_IN_ERROR}
Const RECEIVED_REPLY_IN_ERROR = $F8;
{$DEFINE NETWORK_NOT_FOUND}
Const NETWORK_NOT_FOUND = $EF;
{$DEFINE NO_RESPONSE_FROM_DESTINATION}
Const NO_RESPONSE_FROM_DESTINATION = $EE;
{$DEFINE RESPONSE_COMPLETION_CODE_BAD}
Const RESPONSE_COMPLETION_CODE_BAD = $ED;
{$DEFINE LIST_SIZE_TOO_SMALL}
Const LIST_SIZE_TOO_SMALL = $EC;
{$DEFINE INTERNAL_LIST_ERROR}
Const INTERNAL_LIST_ERROR = $EB;
{$DEFINE NODE_NOT_FOUND_OR_NO_RESPONSE}
Const NODE_NOT_FOUND_OR_NO_RESPONSE = $EA;
{$DEFINE MEMORY_ALLOCATION_ERROR}
Const MEMORY_ALLOCATION_ERROR = $DF;
{$DEFINE VERSION_DOES_NOT_SUPPORT}
Const VERSION_DOES_NOT_SUPPORT = $DE;


(* ------------------- Structures --------------------*)

Type
    BeginDiagnosticStruct  =   IPXAddress ;

Type
    StructIPXPacket = Record
        data  :  Array[0..MAX_IPX_PACKET_SIZE-sizeof(IPXHeader)-1] Of  BYTE ;
    End;
    IPXPacket = StructIPXPacket;


Type
    StructSPXPacket = Record
        data  :  Array[0..MAX_IPX_PACKET_SIZE-sizeof(SPXHeader)-1] Of  BYTE ;
    End;
    SPXPacket = StructSPXPacket;


Type
    StructExclusionList = Record
        nodeAddress  :  Array[0..5] Of  BYTE ;
    End;
    ExclusionListStruct = StructExclusionList;


Type
    StructExclusionPacket = Record
        numberOfExclusions  :   BYTE ;
        structureArray  :  Array[0..MAX_EXCLUSIONS-1] Of  ExclusionListStruct ;
    End;
    ExclusionPacketStructure = StructExclusionPacket;


Type
    StructAddr = Record
        network  :  Array[0..3] Of  BYTE ;
        node  :  Array[0..5] Of  BYTE ;
    End;
    AddrStruct = StructAddr;


StructDriver = Record
    localNetworkType  :   BYTE ;
    network  :  Array[0..3] Of  BYTE ;
    node  :  Array[0..5] Of  BYTE ;
End;


Type
    StructBridge = Record
        numberOfNets  :   BYTE ;
        bridge  :  Array[0..MAX_LOCAL_NETWORKS-1] Of  StructDriver ;
    End;
    BridgeStruct = StructBridge;


Type
    StructNode = Record
        name  :  Array[0..11] Of nint8;
        target  :   BeginDiagnosticStruct ;
        numberOfComponents  :   BYTE ;
        componentID  :  Array[0..MAX_COMPONENTS-1] Of  BYTE ;
        bridgePtr  :  ^BridgeStruct;
    End;
    NodeStruct = StructNode;


Type
    StructConfigurationResponse = Record
        address  :   AddrStruct ;
        packet : Record
            majorVersion  :   BYTE ;
            minorVersion  :   BYTE ;
            SPXDiagnosticSocket  :   WORD ;
            numberOfComponents  :   BYTE ;
            componentStructure  :  Array[0..MAX_IPX_PACKET_SIZE-sizeof(IPXHeader)-sizeof(AddrStruct)-5-1] Of  BYTE ;
        End;
    End;
    ConfigurationResponseStruct = StructConfigurationResponse;


Type
    StructAllResp = Record
        completionCode  :   BYTE ;
        intervalMarker  :  nint32;
    End;
    AllResponseData = StructAllResp;


Type
    StructIPXSPXVersion = Record
        IPXMajorVersion  :   BYTE ;
        IPXMinorVersion  :   BYTE ;
        SPXMajorVersion  :   BYTE ;
        SPXMinorVersion  :   BYTE ;
    End;
    IPXSPXVersion = StructIPXSPXVersion;


Type
    StructIPXStatistics = Record
        sendPacketCount  :  nint32;
        malformedPacketCount  :   WORD ;
        getECBRequestCount  :  nint32;
        getECBFailureCount  :  nint32;
        AESEventCount  :  nint32;
        postponedAESEventCount  :   WORD ;
        maxConfiguredSocketsCount  :   WORD ;
        maxOpenSocketsCount  :   WORD ;
        openSocketFailureCount  :   WORD ;
        listenECBCount  :  nint32;
        ECBCancelFailureCount  :   WORD ;
        findRouteFailureCount  :   WORD ;
    End;
    IPXStatisticsStruct = StructIPXStatistics;


Type
    StructSPXStatistics = Record
        maxConnectionsCount  :   WORD ;
        maxUsedConnectionsCount  :   WORD ;
        establishConnectionRequest  :   WORD ;
        establishConnectionFailure  :   WORD ;
        listenConnectionRequestCount  :   WORD ;
        listenConnectionFailureCount  :   WORD ;
        sendPacketCount  :  nint32;
        windowChokeCount  :  nint32;
        badSendPacketCount  :   WORD ;
        sendFailureCount  :   WORD ;
        abortConnectionCount  :   WORD ;
        listenPacketCount  :  nint32;
        badListenPacketCount  :   WORD ;
        incomingPacketCount  :  nint32;
        badIncomingPacketCount  :   WORD ;
        suppressedPacketCount  :   WORD ;
        noSessionListenECBCount  :   WORD ;
        watchdogDestroySessionCount  :   WORD ;
    End;
    SPXStatisticsStruct = StructSPXStatistics;


Type
    SPReq = Record
        target  :   BeginDiagnosticStruct ;
        immediateAddress  :  Array[0..5] Of  BYTE ;
        numberOfPackets  :   WORD ;
        timerTickInterval  :   BYTE ;
        packetsPerTickInterval  :   BYTE ;
        packetSize  :   WORD ;
        changeSize  :   WORD ;
    End;
    SendPacketsRequestStruct = SPReq;


Type
    SPResp = Record
        numberOfTransmitErrors  :   WORD ;
    End;
    SendPacketsResponseStruct = SPResp;


Type
    StructStartCountingPackets = Record
        destinationSocket  :   WORD ;
    End;
    StartCountingPacketsStruct = StructStartCountingPackets;


Type
    StructReturnReceivedPacket = Record
        packetsReceived  :   WORD ;
    End;
    ReturnReceivedPacketStruct = StructReturnReceivedPacket;


Type status  =   BYTE ;

Type
    StructBridgeDriverStatus = Record
        LANBoard  :  Array[0..3] Of  status ;
    End;
    BridgeDriverStatusStruct = StructBridgeDriverStatus;


Type
    StructDriverConf = Record
        networkAddress  :  Array[0..3] Of  BYTE ;
        nodeAddress  :  Array[0..5] Of  BYTE ;
        LANMode  :   BYTE ;
        nodeAddressType  :   BYTE ;
        maxDataSize  :   WORD ;
        reserved1  :   WORD ;
        reserved4  :   BYTE ;
        transportTime  :   WORD ;
        reserved2  :  Array[0..10] Of  BYTE ;
        majorVersion  :   BYTE ;
        minorVersion  :   BYTE ;
        ethernetFlagBits  :   BYTE ;
        selectedConfiguration  :   BYTE ;
        LANDescription  :  Array[0..79] Of  BYTE ;
        IOAddress1  :   WORD ;
        IODecodeRange1  :   WORD ;
        IOAddress2  :   WORD ;
        IODecodeRange2  :   WORD ;
        memoryAddress1  :  Array[0..2] Of  BYTE ;
        memoryDecodeRange1  :   WORD ;
        memoryAddress2  :  Array[0..2] Of  BYTE ;
        memoryDecodeRange2  :   WORD ;
        interruptIsUsed1  :   BYTE ;
        interruptLine1  :   BYTE ;
        interruptIsUsed2  :   BYTE ;
        interruptLine2  :   BYTE ;
        DMAIsUsed1  :   BYTE ;
        DMALine1  :   BYTE ;
        DMAIsUsed2  :   BYTE ;
        DMALine2  :   BYTE ;
        microChannelFlagBits  :   BYTE ;
        reserved3  :   BYTE ;
        textDescription  :  Array[0..79] Of  BYTE ;
    End;
    DriverConfigurationStruct = StructDriverConf;


Type
    StructDriverStat = Record
        driverVersion  :  Array[0..1] Of  BYTE ;
        statisticsVersion  :  Array[0..1] Of  BYTE ;
        totalTxPacketCount  :  nint32;
        totalRxPacketCount  :  nint32;
        noECBAvailableCount  :   WORD ;
        packetTxTooBigCount  :   WORD ;
        packetTxTooSmallCount  :   WORD ;
        packetRxOverflowCount  :   WORD ;
        packetRxTooBigCount  :   WORD ;
        packetRxTooSmallCount  :   WORD ;
        packetTxMiscErrorCount  :   WORD ;
        packetRxMiscErrorCount  :   WORD ;
        retryTxCount  :   WORD ;
        checksumErrorCount  :   WORD ;
        hardwareRxMismatchCount  :   WORD ;
        numberOfCustomVariables  :   WORD ;
        variableData  :  Array[0..494] Of  BYTE ;
        (*  BYTE variableData[1]; *)
    End;
    DriverStatisticsStruct = StructDriverStat;


Type
    StructOSVersion = Record
        machineID  :   BYTE ;
        versionData  :  Array[0..40] Of  BYTE ;
    End;
    OSVersionStruct = StructOSVersion;


Type
    ShellAddressStruct  =   IPXAddress ;

Type
    StructShellStatistics = Record
        shellRequestsCount  :  nint32;
        operatorAbortsCount  :   WORD ;
        operatorRetriesCount  :   WORD ;
        timeoutsCount  :   WORD ;
        writeErrorCount  :   WORD ;
        invalidReplyHeaderCount  :   WORD ;
        invalidSlotCount  :   WORD ;
        invalidSequenceNumberCount  :   WORD ;
        errorReceivingCount  :   WORD ;
        noRouterFoundCount  :   WORD ;
        beingProcessedCount  :   WORD ;
        unknownErrorCount  :   WORD ;
        invalidServerSlotCount  :   WORD ;
        networkGoneCount  :   WORD ;
        reserved1  :   WORD ;
        allocateCannotFindRouteCount  :   WORD ;
        allocateNoSlotsAvailableCount  :   WORD ;
        allocateServerIsDownCount  :   WORD ;
    End;
    ShellStatisticsStruct = StructShellStatistics;


Type
    StructAddressTable = Record
        serverUsed  :   BYTE ;
        orderNumber  :   BYTE ;
        serverNetwork  :  Array[0..3] Of  BYTE ;
        serverNode  :  Array[0..5] Of  BYTE ;
        serverSocket  :   WORD ;
        receivedTimeOut  :   WORD ;
        immediateNode  :  Array[0..5] Of  BYTE ;
        sequenceNumber  :   BYTE ;
        connectionNumber  :   BYTE ;
        connectionOK  :   BYTE ;
        maximumTimeOut  :   WORD ;
        reserved  :  Array[0..4] Of  BYTE ;
    End;
    AddressTableStruct = StructAddressTable;


Type
    StructServerAddressTable = Record
        addressTable  :  Array[0..7] Of  AddressTableStruct ;
    End;
    ServerAddressTableStruct = StructServerAddressTable;


Type
    StructNameTable = Record
        name  :  Array[0..47] Of  BYTE ;
    End;
    NameTableStruct = StructNameTable;


Type
    StructServerNameTable = Record
        nameTable  :  Array[0..7] Of  NameTableStruct ;
    End;
    ServerNameTableStruct = StructServerNameTable;


Type
    StructPrimaryServer = Record
        number  :   BYTE ;
    End;
    PrimaryServerStruct = StructPrimaryServer;


Type
    StructShellVersion = Record
        minor  :   BYTE ;
        major  :   BYTE ;
        rev  :   BYTE ;
    End;
    ShellVersionStruct = StructShellVersion;


Type
    StructBridgeStatistics = Record
        tooManyHopsCount  :   WORD ;
        unknownNetworkCount  :   WORD ;
        noSpaceForServiceCount  :   WORD ;
        noReceiveBuffersCount  :   WORD ;
        notMyNetwork  :   WORD ;
        netBIOSPropogateCount  :  nint32;
        totalPacketsServiced  :  nint32;
        totalPacketsRouted  :  nint32;
    End;
    BridgeStatisticsStruct = StructBridgeStatistics;


Type
    StructNumber = Record
        number  :  Array[0..3] Of  BYTE ;
    End;
    NumberStruct = StructNumber;


Type
    StructNodeAddress = Record
        address  :  Array[0..5] Of  BYTE ;
        reserved  :  Array[0..1] Of  BYTE ;
    End;
    NodeAddressStruct = StructNodeAddress;


Type
    StructLocalTables = Record
        localNetworkNumber  :  Array[0..15] Of  NumberStruct ;
        localNodeAddress  :  Array[0..15] Of  NodeAddressStruct ;
    End;
    LocalTablesStruct = StructLocalTables;


Type
    StructNetworkAddress = Record
        address  :  Array[0..3] Of  BYTE ;
    End;
    NetworkAddressStruct = StructNetworkAddress;


Type
    StructAllKnownNetworks = Record
        numberOfNetworkAddresses  :   WORD ;
        networkAddress  :  Array[0..127] Of  NetworkAddressStruct ;
    End;
    AllKnownNetworksStruct = StructAllKnownNetworks;


Type
    StructRoutingInfo = Record
        routerForwardingAddress  :  Array[0..5] Of  BYTE ;
        routerBoardNumber  :   BYTE ;
        reserved  :  Array[0..1] Of  BYTE ;
        routeHops  :   BYTE ;
        routeTime  :   WORD ;
    End;
    RoutingInfoStruct = StructRoutingInfo;


Type
    StructSpecificNetInfo = Record
        networkAddress  :  Array[0..3] Of  BYTE ;
        hopsToNet  :   BYTE ;
        reservedA  :  Array[0..6] Of  BYTE ;
        routeTimeToNet  :   WORD ;
        numberOfKnownRouters  :   WORD ;
        routingInfo  :  Array[0..MAX_ROUTES-1] Of  RoutingInfoStruct ;
    End;
    SpecificNetworkInfoStruct = StructSpecificNetInfo;


Type
    StrSrvrInfo = Record
        serverType  :   WORD ;
        serverName  :  Array[0..47] Of  BYTE ;
    End;
    ServerInfoStruct = StrSrvrInfo;


Type
    StructAllKnownServers = Record
        numberOfServers  :   WORD ;
        serverInfo  :  Array[0..9] Of  ServerInfoStruct ;
    End;
    AllKnownServersStruct = StructAllKnownServers;


Type
    StructRouteSourceInfo = Record
        routeSourceAddress  :  Array[0..5] Of  BYTE ;
        routeHopsToSource  :   WORD ;
        reserved  :  Array[0..1] Of  BYTE ;
    End;
    RouteSourceInfoStruct = StructRouteSourceInfo;


Type
    StrSpecSrvrInfo = Record
        serverInfo  :   ServerInfoStruct ;
        serverAddress  :  Array[0..11] Of  BYTE ;
        hopsToServer  :   WORD ;
        reserved1  :  Array[0..1] Of  BYTE ;
        numberOfRoutes  :   WORD ;
        routeSourceInfo  :  Array[0..MAX_ROUTES-1] Of  RouteSourceInfoStruct ;
    End;
    SpecificServerInfoStruct = StrSpecSrvrInfo;


Type
    StructConnectionStatusBlock = Record
        connectionState  :   BYTE ;
        connectionFlags  :   BYTE ;
        sourceConnectionID  :  Array[0..1] Of  BYTE ;
        destinationConnectionID  :  Array[0..1] Of  BYTE ;
        sequenceNumber  :  Array[0..1] Of  BYTE ;
        acknowledgeNumber  :  Array[0..1] Of  BYTE ;
        allocationNumber  :  Array[0..1] Of  BYTE ;
        remoteAcknowledgeNumber  :  Array[0..1] Of  BYTE ;
        remoteAllocationNumber  :  Array[0..1] Of  BYTE ;
        connectionSocket  :   WORD ;
        immediateAddress  :  Array[0..5] Of  BYTE ;
        destination  :   IPXAddress ;
        retransmissionCount  :  Array[0..1] Of  BYTE ;
        estimatedRoundTripDelay  :  Array[0..1] Of  BYTE ;
        retransmittedPackets  :  Array[0..1] Of  BYTE ;
        suppressedPackets  :  Array[0..1] Of  BYTE ;
    End;
    ConnectionStatusBlock = StructConnectionStatusBlock;



(* Personal NetWare Server Information *)

Type
    StructNLServerInfo = Record
        StructVersion  :   WORD ;
        WorkgroupName  :  Array[0..WORKGROUP_NAME_LENGTH-1] Of  BYTE ;
        WorkgroupID  :   DWORD ;
        ServerName  :  Array[0..MAX_SERVER_NAME_LENGTH-1] Of  BYTE ;
        ServerID  :   DWORD ;
        OEMString  :  Array[0..OEM_NAME_LENGTH-1] Of  BYTE ;
        OEMID  :   WORD ;
        MajorVersion  :   BYTE ;
        MinorVersion  :   BYTE ;
        BetaVersion  :   BYTE ;
        StartMinutes  :   BYTE ;
        StartHours  :   BYTE ;
        StartSeconds  :   BYTE ;
        StartYear  :   WORD ;
        StartDay  :   BYTE ;
        StartMonth  :   BYTE ;
        ServerAddressType  :   BYTE ;
        ServerNetAddr  :  Array[0..3] Of  BYTE ;
        ServerNodeAddr  :  Array[0..5] Of  BYTE ;
        ServerSocket  :  Array[0..1] Of  BYTE ;
        ServerDescription  :  Array[0..49] Of  BYTE ;
        CfgConnections  :   WORD ;
        CfgOpenFiles  :   WORD ;
        CfgClientTasks  :   WORD ;
        CfgDirBuffers  :   WORD ;
        CfgServiceExtensions  :   WORD ;
        CurServiceExtensions  :   WORD ;
        CfgResources  :   WORD ;
        CurResources  :   WORD ;
        CfgDirs  :   WORD ;
        CurDirs  :   WORD ;
        CfgPrns  :   WORD ;
        CurPrns  :   BYTE ;
        SizePrintBuffers  :   WORD ;
        NumReceiveBuffers  :   WORD ;
        RealSizeReceiveBuffers  :   WORD ;
        SizeReceiveBuffers  :   WORD ;
        NumIOBuffers  :   WORD ;
        SizeIOBuffers  :   WORD ;
        ServerTSRSize  :   WORD ;
        AuditingFlag  :   BYTE ;
        ServerFlags  :   BYTE ;
        OperatingSystem  :   BYTE ;
        DosMajorVersion  :   BYTE ;
        DosMinorVersion  :   BYTE ;
        IsShareLoaded  :   BYTE ;
        ServerLoadType  :   BYTE ;
        ModuleFlag  :   DWORD ;
        ScheduleControl  :   DWORD ;
        ServerDiskVector  :   DWORD ;
        RemovableDiskVector  :   DWORD ;
    End;
    NLServerInfoStruct = StructNLServerInfo;



Type
    StructNLServerStats = Record
        TotalPacketsReceived  :   DWORD ;
        BadPackets  :   WORD ;
        PacketsNotProcessedImmediately  :   WORD ;
        LostResponses  :   WORD ;
        PeakConnectionsUsed  :   WORD ;
        PeakOpenFiles  :   WORD ;
        PeakClientTasks  :   WORD ;
        WatchdogPacketsSent  :   WORD ;
        ClientsWatchdogged  :   WORD ;
        ECBRepostsWithNoBuffers  :   WORD ;
        SendPacketWithECBActive  :   WORD ;
        TotalSlistRequests  :   WORD ;
        ServerBusyPackets  :   WORD ;
        ServerBusyPacketsNoBuffers  :   WORD ;
        UnknownRequests  :   WORD ;
        WriteBehindMisses  :   WORD ;
        ReadCacheHits  :   DWORD ;
        ReadCacheMisses  :   DWORD ;
        ReadsTooLarge  :   WORD ;
        CriticalErrors  :   WORD ;
        SavedLargeDOSArea  :   DWORD ;
        SavedSmallDOSArea  :   DWORD ;
        StarvationCounter  :   WORD ;
        WriteBehindHits  :   WORD ;
        CacheBlocksInUse  :   WORD ;
        Reserved  :   DWORD ;
        PacketQueueRuns  :   DWORD ;
        IdleLoopWaitHits  :   DWORD ;
        Int21NotOurs  :   DWORD ;
        TotalInt21Calls  :   DWORD ;
        PasswordFailures  :   WORD ;
        Reserved0  :   WORD ;
    End;
    NLServerStatsStruct = StructNLServerStats;



Type
    StructNLServerCurrentState = Record
        CurConnections  :   WORD ;
        CurOpenFiles  :   WORD ;
        CurClientTasks  :   WORD ;
        CurNumFreeBuffers  :   WORD ;
        CurNumSemaphores  :   WORD ;
    End;
    NLServerCurrentStateStruct = StructNLServerCurrentState;


Type
    StructNLCacheStats = Record
        NLCacheMajorVersion  :   BYTE ;
        NLCacheMinorVersion  :   BYTE ;
        TypeOfMemory  :   WORD ;
        (* 1=Base memory being used *)
        (* 2=Extended memory being used *)
        (* 3=Expanded memory being used *)
        ReadRequests  :   DWORD ;
        ActualReadsToDisk  :   DWORD ;
        WriteRequests  :   DWORD ;
        ActualWritesToDisk  :   DWORD ;
        NumberOfDiskErrors  :   WORD ;
        NumberOfMemoryErrors  :   WORD ;
        CurrentSizeInElements  :   WORD ;
        MaxNumElements  :   WORD ;
        ElementSize  :   WORD ;
        MinNumElements  :   WORD ;
    End;
    NLCacheStatsStruct = StructNLCacheStats;


Type
    StructResponderType = Record
        ResponderType  :   WORD ;
        ResponderMajorVersion  :   BYTE ;
        ResponderMinorVersion  :   BYTE ;
    End;
    ResponderTypeStruct = StructResponderType;


Type
    StructGNMAQueryRequest = Record
        ComponentIDIndex  :   BYTE ;
        RequestType  :   BYTE ;
        ResponderType  :   WORD ;
        ResponderRequest  :   WORD ;
        OtherData  :   WORD ;
    End;
    GNMAQueryRequestStruct = StructGNMAQueryRequest;


Type
    StructGNMAInfo = Record
        GNMAMajorVersion  :   BYTE ;
        GNMAMinorVersion  :   BYTE ;
        GNMANumberOfResponders  :   WORD ;
        type1  :  Array[0..130] Of  ResponderTypeStruct ;
    End;
    GNMAInfoStruct = StructGNMAInfo;


(* MACHINE CONFIGURATION *)

Type
    StructMachineStaticInfo = Record
        StartDate  :   DWORD ;
        StartTime  :   DWORD ;
        OSVerMajor  :   BYTE ;
        OSVerMinor  :   BYTE ;
        OSVersionType  :   WORD ;
        NumberOfSerialPorts  :   BYTE ;
        NumberOfParallelPorts  :   BYTE ;
        FloppyDriveCount  :   BYTE ;
        FloppyDriveType  :   WORD ;
        HardDriveCount  :   BYTE ;
        KeyboardType  :   BYTE ;
        BootVideoType  :   BYTE ;
        DisplayMemory  :   DWORD ;
        MathCoprocessor  :   BYTE ;
        CoprocessorType  :   BYTE ;
        CPUType  :   BYTE ;
        Reserved  :   BYTE ;
        ModelType  :   BYTE ;
        SerialAddress  :  Array[0..3] Of  WORD ;
        ParallelAddress  :  Array[0..3] Of  WORD ;
        PointerDevice  :   BYTE ;
        SystemMemory  :   WORD ;
        MemoryTypes  :   BYTE ;
        BIOSType  :   BYTE ;
        BIOSRev  :  Array[0..1] Of  BYTE ;
        EISA_MCASlots  :   BYTE ;
        EISA_MCAIRQ  :  Array[0..15] Of  BYTE ;
        EISA_CardName  :   BYTE ;
        BusType  :   BYTE ;
        HardDriveType  :  Array[0..3] Of  BYTE ;
        MemTypeFlag  :   BYTE ;
        TotalXMS  :   WORD ;
        AvailableXMS  :   WORD ;
        TotalEMS  :   WORD ;
        AvailableEMS  :   WORD ;
        Reserved0  :  Array[0..21] Of  BYTE ;
    End;
    MachineStaticInfoStruct = StructMachineStaticInfo;


Type
    StructNonremoveableDrives = Record
        DriveNumber  :   BYTE ;
        SectorsPerCluster  :   DWORD ;
        TotalNumberOfClustersPerDrive  :   DWORD ;
        NumberOfAvailableClusters  :   DWORD ;
        BytesPerSector  :   WORD ;
    End;
    NonremoveableDrivesStruct = StructNonremoveableDrives;


Type
    StructMachineDynamicInfo = Record
        CurrentDate  :   DWORD ;
        CurrentTime  :   DWORD ;
        MouseDriver  :   BYTE ;
        Reserved  :  Array[0..36] Of  BYTE ;
        NonremoveableDriveCount  :   BYTE ;
        Drive  :  Array[0..30] Of  NonremoveableDrivesStruct ;
    End;
    MachineDynamicInfoStruct = StructMachineDynamicInfo;


(* PROTOCOL STACK INFORMATION *)

Type
    StructPStackID = Record
        StackId  :   WORD ;
        Name  :  Array[0..17] Of  BYTE ;
    End;
    PStackIDStruct = StructPStackID;


Type
    StructProtocolStackList = Record
        NumberOfStacks  :   BYTE ;
        PSID  :  Array[0..19] Of  PStackIDStruct ;
    End;
    ProtocolStackListStruct = StructProtocolStackList;


Type
    StructProtocolStackConfig = Record
        ConfigMajorVersion  :   BYTE ;
        ConfigMinorVersion  :   BYTE ;
        ProtocolLongName  :  Array[0..41] Of  BYTE ;
        ProtocolShortName  :  Array[0..16] Of  BYTE ;
        StackMajorVersion  :   BYTE ;
        StackMinorVersion  :   BYTE ;
        Reserved  :  Array[0..15] Of  BYTE ;
    End;
    ProtocolStackConfigStruct = StructProtocolStackConfig;


Type
    StructProtocolStackStats = Record
        StatMajorVersion  :   BYTE ;
        StatMinorVersion  :   BYTE ;
        GenericCounters  :   WORD ;
        ValidCountersMask  :   DWORD ;
        TotalTxPackets  :   DWORD ;
        TotalRxPackets  :   DWORD ;
        IgnoredRxPackets  :   DWORD ;
        OtherData  :  Array[0..507] Of  BYTE ;
    End;
    ProtocolStackStatsStruct = StructProtocolStackStats;


(* MLID INFORMATION *)

Type
    StructMLIDID = Record
        MLIDId  :   WORD ;
        Name  :  Array[0..17] Of  BYTE ;
    End;
    MLIDIDStruct = StructMLIDID;


Type
    StructMLIDList = Record
        NumberOfMLIDs  :   BYTE ;
        MLID  :  Array[0..19] Of  MLIDIDStruct ;
    End;
    MLIDListStruct = StructMLIDList;


Type
    StructMLIDConfiguration = Record
        Signature  :  Array[0..25] Of  BYTE ;
        ConfigTableMajorVersion  :   BYTE ;
        ConfigTableMinorVersion  :   BYTE ;
        NodeAddress  :  Array[0..5] Of  BYTE ;
        ModeFlags  :   WORD ;
        BoardNumber  :   WORD ;
        BoardInstance  :   WORD ;
        MaxPacketSize  :   WORD ;
        BestDataSize  :   WORD ;
        WorstDataSize  :   WORD ;
        NICLongName  :  Array[0..41] Of  BYTE ;
        NICShortName  :  Array[0..9] Of  BYTE ;
        FrameTypeString  :  Array[0..41] Of  BYTE ;
        Reserved  :   WORD ;
        FrameTypeID  :   WORD ;
        TransportTime  :   WORD ;
        SourceRouteHandler  :   DWORD ;
        LookAheadSize  :   WORD ;
        LineSpeed  :   WORD ;
        QueueDepth  :   WORD ;
        Reserved0  :  Array[0..5] Of  BYTE ;
        DriverMajorVersion  :   BYTE ;
        DriverMinorVersion  :   BYTE ;
        Flags  :  Array[0..1] Of  BYTE ;
        SendRetries  :   WORD ;
        ConfigTableLink  :   DWORD ;
        SharingFlags  :  Array[0..1] Of  BYTE ;
        Slot  :   WORD ;
        IOAddress1  :   WORD ;
        IORange1  :   WORD ;
        IOAddress2  :   WORD ;
        IORange2  :   WORD ;
        MemoryAddress1  :   DWORD ;
        MemorySize1  :   WORD ;
        MemoryAddress2  :   DWORD ;
        MemorySize2  :   WORD ;
        IntLine1  :   BYTE ;
        IntLine2  :   BYTE ;
        DMALine1  :   BYTE ;
        DMALine2  :   BYTE ;
        OtherData  :  Array[0..327] Of  BYTE ;
    End;
    MLIDConfigurationStruct = StructMLIDConfiguration;


Type
    StructMLIDStatistics = Record
        DriverStatMajorVersion  :   BYTE ;
        DriverStatMinorVersion  :   BYTE ;
        NumberGenericCounters  :   WORD ;
        ValidCountersMask  :   DWORD ;
        TotalTxRequest  :   DWORD ;
        TotalRxRequest  :   DWORD ;
        NoECBAvailableCount  :   DWORD ;
        TooBigTxRequest  :   DWORD ;
        TooSmallTxRequest  :   DWORD ;
        RxOverflowCount  :   DWORD ;
        RxTooBigCount  :   DWORD ;
        RxTooSmallCount  :   DWORD ;
        TxMiscCount  :   DWORD ;
        RxMiscCount  :   DWORD ;
        TxRetryCount  :   DWORD ;
        RxChecksumErrorCount  :   DWORD ;
        RxMismatchCount  :   DWORD ;
        OtherData  :  Array[0..467] Of  BYTE ;
    End;
    MLIDStatisticsStruct = StructMLIDStatistics;


(* LSL INFORMATION *)

Type
    StructLSLStatistics = Record
        StatMajorVersion  :   BYTE ;
        StatMinorVersion  :   BYTE ;
        GenericCounters  :   WORD ;
        ValidCountersMask  :   DWORD ;
        TotalTxPackets  :   DWORD ;
        GetECBRequests  :   DWORD ;
        GetECBFailures  :   DWORD ;
        AESEventsCount  :   DWORD ;
        PostponedEvents  :   DWORD ;
        CancelAESFailures  :   DWORD ;
        Reserved0  :   DWORD ;
        Reserved1  :   DWORD ;
        TotalRxPackets  :   DWORD ;
        UnclaimedPackets  :   DWORD ;
        OtherData  :  Array[0..479] Of  BYTE ;
    End;
    LSLStatisticsStruct = StructLSLStatistics;


Type
    StructLSLConfiguration = Record
        ConfigMajorVersion  :   BYTE ;
        ConfigMinorVersion  :   BYTE ;
        Reserved  :   DWORD ;
        Reserved0  :   DWORD ;
        LSLMajorVersion  :   BYTE ;
        LSLMinorVersion  :   BYTE ;
        MaxBoardsNumber  :   WORD ;
        MaxStacksNumber  :   WORD ;
        Reserved1  :  Array[0..11] Of  BYTE ;
    End;
    LSLConfigurationStruct = StructLSLConfiguration;


Type
    StructLSLNetCfgPath = Record
        NetCfgPath  :  Array[0..127] Of  BYTE ;
    End;
    LSLNetCfgPathStruct = StructLSLNetCfgPath;



(* ------------------- Prototypes --------------------*)


{$IFDEF __cplusplus}

(* TC extern C *)
{$ENDIF}


(* TC  int int AbortSendingPackets (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber );  *)


(* TC  int int BeginDiagnostics (  *)
(* TC  BeginDiagnosticStruct * destination ,  *)
(* TC  WORD * connectionID ,  *)
(* TC  BYTE * componentList );  *)


(* TC  int int EndDiagnostics (  *)
(* TC  WORD connectionID );  *)


(* TC  BYTE BYTE FindComponentOffset (  *)
(* TC  BYTE * componentList ,  *)
(* TC  BYTE componentID );  *)


(* TC  int int GetAllKnownNetworks (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  WORD nextNetworkOffset ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  AllKnownNetworksStruct * ResponseData );  *)


(* TC  int int GetAllKnownServers (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  WORD numberServersToSkip ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  AllKnownServersStruct * ResponseData );  *)


(* TC  int int GetBridgeDriverConfiguration (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  BYTE LANBoardNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  DriverConfigurationStruct * ResponseData );  *)


(* TC  int int GetBridgeDriverStatistics (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  BYTE LANBoardNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  DriverStatisticsStruct * ResponseData );  *)


(* TC  int int GetBridgeDriverStatus (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  BridgeDriverStatusStruct * ResponseData );  *)


(* TC  int int GetBridgeStatistics (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  BridgeStatisticsStruct * ResponseData );  *)


(* TC  int int GetDiagnosticResponse (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE * buffer1 ,  *)
(* TC  WORD size1 ,  *)
(* TC  BYTE * buffer2 ,  *)
(* TC  WORD size2 );  *)


(* TC  int int GetDiagnosticStatus (  *)
(* TC  WORD connectionID );  *)


(* TC  int int GetGNMAInfo (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  GNMAInfoStruct * ResponseData );  *)


(* TC  int int GetIPXSPXVersion (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  IPXSPXVersion * ResponseData );  *)


(* TC  int int GetIPXStatistics (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  IPXStatisticsStruct * ResponseData );  *)


(* TC  int int GetLocalTables (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  LocalTablesStruct * ResponseData );  *)


(* TC  int int GetLSLConfiguration (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  LSLConfigurationStruct * ResponseData );  *)


(* TC  int int GetLSLStatistics (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  LSLStatisticsStruct * ResponseData );  *)


(* TC  int int GetMachineStaticInfo (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  MachineStaticInfoStruct * ResponseData );  *)


(* TC  int int GetMachineDynamicInfo (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  MachineDynamicInfoStruct * ResponseData );  *)


(* TC  int int GetMLIDConfiguration (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  WORD MlidId ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  MLIDConfigurationStruct * ResponseData );  *)


(* TC  int int GetMLIDList (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  MLIDListStruct * ResponseData );  *)


(* TC  int int GetMLIDStatistics (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  WORD MlidId ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  MLIDStatisticsStruct * ResponseData );  *)


(* TC  int int GetNetCfgPath (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  LSLNetCfgPathStruct * ResponseData );  *)


(* TC  int int GetNLCacheStats (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  NLCacheStatsStruct * ResponseData );  *)


(* TC  int int GetNLServerCurrentState (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  NLServerCurrentStateStruct * ResponseData );  *)


(* TC  int int GetNLServerInfo (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  NLServerInfoStruct * ResponseData );  *)


(* TC  int int GetNLServerStats (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  NLServerStatsStruct * ResponseData );  *)


(* TC  int int GetOSVersionInfo (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  OSVersionStruct * ResponseData );  *)


(* TC  int int GetPrimaryServerNumber (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  PrimaryServerStruct * ResponseData );  *)


(* TC  int int GetProtocolStackConfiguration (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  WORD stackID ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  ProtocolStackConfigStruct * ResponseData );  *)


(* TC  int int GetProtocolStackList (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  ProtocolStackListStruct * ResponseData );  *)


(* TC  int int GetProtocolStackStatistics (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  WORD stackID ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  ProtocolStackStatsStruct * ResponseData );  *)


(* TC  int int GetRemoteSPXSocket (  *)
(* TC  BeginDiagnosticStruct * destination ,  *)
(* TC  BYTE * cList );  *)


(* TC  int int GetServerAddressTable (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  ServerAddressTableStruct * ResponseData );  *)


(* TC  int int GetServerNameTable (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  ServerNameTableStruct * ResponseData );  *)


(* TC  int int GetShellAddress (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  ShellAddressStruct * ResponseData );  *)


(* TC  int int GetShellDriverConfiguration (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  DriverConfigurationStruct * ResponseData );  *)


(* TC  int int GetShellDriverStatistics (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  DriverStatisticsStruct * ResponseData );  *)


(* TC  int int GetShellStatistics (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  ShellStatisticsStruct * ResponseData );  *)


(* TC  int int GetShellVersionInfo (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  ShellVersionStruct * ResponseData );  *)


(* TC  int int GetSpecificNetworkInfo (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  BYTE * networkAddress ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  SpecificNetworkInfoStruct * ResponseData );  *)


(* TC  int int GetSpecificServerInfo (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  ServerInfoStruct * Server ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  SpecificServerInfoStruct * ResponseData );  *)


(* TC  int int GetSPXStatistics (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  SPXStatisticsStruct * ResponseData );  *)


(* TC  int int SendSPXPacket (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE * buffer1 ,  *)
(* TC  WORD size1 );  *)


(* TC  int int StartCountingPkts (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  StartCountingPacketsStruct * ResponseData );  *)


(* TC  int int StartSendingPktsTimed (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  SendPacketsRequestStruct * RequestData ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  SendPacketsResponseStruct * ResponseData ,  *)
(* TC  WORD Ticks );  *)


(* TC  int int ReinitializeRouterTables (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  BYTE * authorizationCode ,  *)
(* TC  AllResponseData * Response );  *)


(* TC  int int ReturnReceivedPacketCount (  *)
(* TC  WORD connectionID ,  *)
(* TC  BYTE componentNumber ,  *)
(* TC  AllResponseData * Response ,  *)
(* TC  ReturnReceivedPacketStruct * ResponseData );  *)


{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}


{$ENDIF}


