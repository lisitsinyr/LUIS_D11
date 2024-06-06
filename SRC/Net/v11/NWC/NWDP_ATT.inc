(*
//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
//บ (c) 1997 Novell, Inc.  All rights reserved.                              บ
//บ                                                                          บ
//บ THIS WORK IS SUBJECT TO U.S. AND INTERNATIONAL COPYRIGHT LAWS AND        บ
//บ TREATIES.                                                                บ
//บ                                                                          บ
//บ NO PART OF THIS WORK MAY BE USED, PRACTICED, PERFORMED, COPIED,          บ
//บ DISTRIBUTED, REVISED, MODIFIED, TRANSLATED, ABRIDGED, CONDENSED,         บ
//บ EXPANDED, COLLECTED, COMPILED, LINKED, RECAST, TRANSFORMED OR ADAPTED    บ
//บ WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC.                        บ
//บ                                                                          บ
//บ ANY USE OR EXPLOITATION OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT บ
//บ THE PERPETRATOR TO CRIMINAL AND CIVIL LIABILITY.                         บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Source module name: NWDP_ATT.H                                           บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Library VeRsIoN=1.0.0                                                    บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

(* Inclusion Control *)

{$IFNDEF  NWDP_ATT_H }
    {$DEFINE NWDP_ATT_H}
    (* Standard Library Header Includes *)
    {$IFNDEF  NTYPES_H }
        {$DEFINE N_INC_NO_OLD_CONSTANTS}
        {$DEFINE N_INC_NO_OLD_MACROS}
        {$I ntypes.inc}
        {$UNDEF N_INC_NO_OLD_MACROS}
        {$UNDEF N_INC_NO_OLD_CONSTANTS}
    {$ENDIF}
    {$IFNDEF  NWDP_TXT_H }
        {$I nwdp_txt.inc}
    {$ENDIF}
    (* Header Includes *)
    (* Manifest Constant Definitions *)
    {$DEFINE NWDP_EVENT_TYPE_VALUE_CHANGE}
    Const NWDP_EVENT_TYPE_VALUE_CHANGE = 0;
    {$DEFINE NWDP_EVENT_TYPE_ERROR}
    Const NWDP_EVENT_TYPE_ERROR = 1;
    {$DEFINE NWDP_EVENT_TYPE_WARNING}
    Const NWDP_EVENT_TYPE_WARNING = 2;
    {$DEFINE NWDP_EVENT_TYPE_REPORT}
    Const NWDP_EVENT_TYPE_REPORT = 3;
    (*
   // The 'oidLength' field of the NWDPOid structure cannot be more
   // than NWDP_OID_MAX_LENGTH.
   *)
    {$DEFINE NWDP_OID_MAX_LENGTH}
    Const NWDP_OID_MAX_LENGTH = 127;
    {$IFNDEF  NWDP_NSRV_MAX_DN_CHARS }
        {$DEFINE NWDP_NSRV_MAX_DN_CHARS}
        Const NWDP_NSRV_MAX_DN_CHARS = 256;
        NWDP_NSRV_MAX_DN_BYTES = ( ( NWDP_NSRV_MAX_DN_CHARS + 1 ) * 2 );
        {$DEFINE NWDP_NSRV_MAX_TREE_CHARS}
        Const NWDP_NSRV_MAX_TREE_CHARS = 32;
        NWDP_NSRV_MAX_TREE_BYTES = ( ( NWDP_NSRV_MAX_TREE_CHARS + 1 ) * 2 );
    {$ENDIF}
    (* Macro Definitions *)
    (* TC #define NWDPOidLenMac ( __oidPtr ) ( ( ( ( pNWDPOid ) ( __oidPtr ) ) - > oidLength ) + sizeof ( ( ( pNWDPOid ) ( __oidPtr ) ) - > asn1Type ) + sizeof ( ( ( pNWDPOid ) ( __oidPtr ) ) - > oidLength ) )  *)
    (* Type Definitions *)
    Type
        NWDPOid = Record
            asn1Type  :   nuint8 ;
            oidLength  :   nuint8 ;
            oid  :  Array[0..NWDP_OID_MAX_LENGTH-1] Of  nuint8 ;
        End;
        pNWDPOid = ^NWDPOid;
    (*
   // The Fully Qualified Name or FQN for NDS consists of the 'dnPtr' field
   // which points to the NetWare 4.x Distinguished Name string component
   // and the optional Tree Name.  If the 'treeOptionPtr' field is NULL then
   // the API which expects the NWDPNSrvFQN will assume the NDS Context
   // has had the DCK_TREE_NAME buffer set previously to correspond.
   *)
    Const
    NWDP_NSRV_SYNTAX_NDS_WITH_TREE = 0;
    Type NWDPNSrvSyntaxEnum = 0..0;
    pNWDPNSrvSyntaxEnum = ^NWDPNSrvSyntaxEnum;
    Type
        NWDPNSrvFQN = Record
            designator  :   NWDPNSrvSyntaxEnum ;
            ndsWithTree : Record  (* union statement *)
                dn16Ptr  :   pnstr16 ;
                treeOption16Ptr  :   pnstr16 ;
            End;
        End;
        pNWDPNSrvFQN = ^NWDPNSrvFQN;
    (*
   // The NWDPNSrvFQNBuffer is intended to be capable of using
   // the least amount of memory. This means that the strings
   // referred to by the 'fqn' structure's pointers are packed into the 
   // ndsWithTree buffer array and any tree name will appear at
   // ndsWithTree[unilen(&ndsWithTree[0])+1].
   *)
    Type
        NWDPNSrvFQNBuffer = Record
            fqn  :   NWDPNSrvFQN ;
            ndsWithTree  :  Array[0..NWDP_NSRV_MAX_DN_CHARS+NWDP_NSRV_MAX_TREE_CHARS+2-1] Of  nchar16 ;  (* union statement *)
        End;
        pNWDPNSrvFQNBuffer = ^NWDPNSrvFQNBuffer;
    {$IFNDEF  nint64_type }
    {$IFNDEF  _NUINT64_DEF }
        {$DEFINE _NUINT64_DEF}
        Type
            nuint64 = Record
                high32  :   nuint32 ;
                low32  :   nuint32 ;
            End;
            pnuint64 = ^nuint64;
    {$ENDIF}
    {$ENDIF}
    Const
    NWDP_AVT_NULL = 0;
    NWDP_AVT_TEXT = 1;
    NWDP_AVT_DESCRIPTIVE_NAME = 2;
    NWDP_AVT_DESCRIPTOR = 3;
    NWDP_AVT_MESSAGE = 4;
    NWDP_AVT_ERROR_MESSAGE = 5;
    NWDP_AVT_SIMPLE_NAME = 6;
    NWDP_AVT_DIST_NAME_STR = 7;
    NWDP_AVT_DIST_NAME_STR_SEQ = 8;
    NWDP_AVT_DELTA_TIME = 9;
    NWDP_AVT_TIME = 10;
    NWDP_AVT_INTEGER = 11;
    NWDP_AVT_INTEGER_SEQ = 12;
    NWDP_AVT_CARDINAL = 13;
    NWDP_AVT_CARDINAL_SEQ = 14;
    NWDP_AVT_POSITIVE_INTEGER = 15;
    NWDP_AVT_INTEGER_RANGE = 16;
    NWDP_AVT_CARDINAL_RANGE = 17;
    NWDP_AVT_MAXIMUM_INTEGER = 18;
    NWDP_AVT_MINIMUM_INTEGER = 19;
    NWDP_AVT_INTEGER_64 = 20;
    NWDP_AVT_INTEGER_64_SEQ = 21;
    NWDP_AVT_CARDINAL_64 = 22;
    NWDP_AVT_CARDINAL_64_SEQ = 23;
    NWDP_AVT_POSITIVE_INTEGER_64 = 24;
    NWDP_AVT_INTEGER_64_RANGE = 25;
    NWDP_AVT_CARDINAL_64_RANGE = 26;
    NWDP_AVT_MAXIMUM_INTEGER_64 = 27;
    NWDP_AVT_MINIMUM_INTEGER_64 = 28;
    NWDP_AVT_REAL = 29;
    NWDP_AVT_REAL_SEQ = 30;
    NWDP_AVT_NON_NEGATIVE_REAL = 31;
    NWDP_AVT_REAL_RANGE = 32;
    NWDP_AVT_NON_NEGATIV_REAL_RANGE = 33;
    NWDP_AVT_BOOLEAN = 34;
    NWDP_AVT_PERCENT = 35;
    NWDP_AVT_OBJECT_IDENTIFIER = 36;
    NWDP_AVT_OBJECT_IDENTIFIER_SEQ = 37;
    NWDP_AVT_NAME_OR_OID = 38;
    NWDP_AVT_NAME_OR_OID_SEQ = 39;
    NWDP_AVT_DISTINGUISHED_NAME = 40;
    NWDP_AVT_RDN_SEQUENCE = 41;
    NWDP_AVT_REALIZATION = 42;
    NWDP_AVT_MEDIUM_DIMENSIONS = 43;
    NWDP_AVT_DIMENSION = 44;
    NWDP_AVT_XY_DIMENSIONS = 45;
    NWDP_AVT_LOCATIONS = 46;
    NWDP_AVT_AREA = 47;
    NWDP_AVT_AREA_SEQ = 48;
    NWDP_AVT_EDGE = 49;
    NWDP_AVT_FONT_REFERENCE = 50;
    NWDP_AVT_CARDINAL_OR_OID = 51;
    NWDP_AVT_OID_CARDINAL_MAP = 52;
    NWDP_AVT_CARDINAL_OR_NAM_OR_OID = 53;
    NWDP_AVT_POSITIVE_INT_OR_OID = 54;
    NWDP_AVT_EVENT_HANDLING_PROFILE = 55;
    NWDP_AVT_OCTET_STRING = 56;
    NWDP_AVT_PRIORITY = 57;
    NWDP_AVT_LOCALE = 58;
    NWDP_AVT_METHOD_DELIVERY_ADDR = 59;
    NWDP_AVT_OBJECT_IDENTIFICATION = 60;
    NWDP_AVT_RESULTS_PROFILE = 61;
    NWDP_AVT_CRITERIA = 62;
    NWDP_AVT_JOB_PASSWORD = 63;
    NWDP_AVT_JOB_LEVEL = 64;
    NWDP_AVT_JOB_CATEGORIES = 65;
    NWDP_AVT_PRINT_CHECKPOINT = 66;
    NWDP_AVT_IGNORED_ATTRIBUTE = 67;
    NWDP_AVT_RESOURCE = 68;
    NWDP_AVT_MEDIUM_SUBSTITUTION = 69;
    NWDP_AVT_FONT_SUBSTITUTION = 70;
    NWDP_AVT_RESOURCE_CONTEXT_SEQ = 71;
    NWDP_AVT_SIDES = 72;
    NWDP_AVT_PAGE_SELECT_SEQ = 73;
    NWDP_AVT_PAGE_MEDIA_SELECT = 74;
    NWDP_AVT_DOCUMENT_CONTENT = 75;
    NWDP_AVT_PAGE_SIZE = 76;
    NWDP_AVT_PRESENTATION_DIRECTION = 77;
    NWDP_AVT_PAGE_ORDER = 78;
    NWDP_AVT_FILE_REFERENCE = 79;
    NWDP_AVT_MEDIUM_SOURCE_SIZE = 80;
    NWDP_AVT_INPUT_TRAY_MEDIUM = 81;
    NWDP_AVT_OUTPUT_BINS_CHARS = 82;
    NWDP_AVT_PAGE_ID_TYPE = 83;
    NWDP_AVT_LEVEL_RANGE = 84;
    NWDP_AVT_CATEGORY_SET = 85;
    NWDP_AVT_NUMBERS_UP_SUPPORTED = 86;
    NWDP_AVT_FINISHING = 87;
    NWDP_AVT_PRT_CONTAINED_OBJ_ID = 88;
    NWDP_AVT_PRT_CONFIG_OBJECT_ID = 89;
    NWDP_AVT_TYPED_NAME = 90;
    NWDP_AVT_NET_ADDRESS = 91;
    NWDP_AVT_XY_DIMENSIONS_VALUE = 92;
    NWDP_AVT_NAME_OR_OID_DIM_MAP = 93;
    NWDP_AVT_PRINTER_STATE_REASON = 94;
    NWDP_AVT_ENUMERATION = 95;
    NWDP_AVT_QUALIFIED_NAME = 96;
    NWDP_AVT_QUALIFIED_NAME_SET = 97;
    NWDP_AVT_COLORANT_SET = 98;
    NWDP_AVT_RESOURCE_PRINTER_ID = 99;
    NWDP_AVT_EVENT_OBJECT_ID = 100;
    NWDP_AVT_QUALIFIED_NAME_MAP = 101;
    NWDP_AVT_FILE_PATH = 102;
    Type NWDPAVTEnum = 0..102;
    pNWDPAVTEnum = ^NWDPAVTEnum;
    Type
        NWDPOctetString = Record
            itemCount  :   nuint ;
            itemPtr  :   pnint8 ;
        End;
        pNWDPOctetString = ^NWDPOctetString;
    Type
        NWDPIntegerOption = Record
            flag  :   nint32 ;
            value  :   nint32 ;
        End;
        pNWDPIntegerOption = ^NWDPIntegerOption;
    Type
        NWDPObjectIdentifier = Record
            oidStructSize  :   nuint ;
            oidStructPtr  :   pNWDPOid ;
        End;
        pNWDPObjectIdentifier = ^NWDPObjectIdentifier;
    Const
    NWDP_NAME_OR_OID_NONE = 0;
    NWDP_NAME_OR_OID_GLOBAL = 1;
    NWDP_NAME_OR_OID_LOCAL = 2;
    Type NWDPNameOrOidEnum = 0..2;
    pNWDPNameOrOidEnum = ^NWDPNameOrOidEnum;
    Type
        NWDPNameOrOid = Record
            designator  :   NWDPNameOrOidEnum ;
            globalForm  :   NWDPObjectIdentifier ;  (* union statement *)
        End;
        pNWDPNameOrOid = ^NWDPNameOrOid;
    Type
        NWDPDistinguishedNameString = Record
            name  :   NWDPText ;
            syntaxOptionPtr  :   pNWDPNameOrOid ;
        End;
        pNWDPDistinguishedNameString = ^NWDPDistinguishedNameString;
    Const
    NWDP_QUALIFIED_NAME_NONE = 0;
    NWDP_QUALIFIED_NAME_SIMPLE = 1;
    NWDP_QUALIFIED_NAME_NDS = 2;
    Type NWDPQualifiedNameEnum = 0..2;
    pNWDPQualifiedNameEnum = ^NWDPQualifiedNameEnum;
    Type
        NWDPNdsName = Record
            object1  :   NWDPText ;
            treeOption  :   NWDPText ;
        End;
        pNWDPNdsName = ^NWDPNdsName;
    Type
        NWDPQualifiedName = Record
            designator  :   NWDPQualifiedNameEnum ;
            simpleName  :   NWDPText ;  (* union statement *)
        End;
        pNWDPQualifiedName = ^NWDPQualifiedName;
    Type
        NWDPQualifiedNameSet = Record
            itemCount  :   nuint ;
            itemPtr  :   pNWDPQualifiedName ;
        End;
        pNWDPQualifiedNameSet = ^NWDPQualifiedNameSet;
    Type
        NWDPDistinguishedNameStrSeq = Record
            itemCount  :   nuint ;
            itemPtr  :   pNWDPDistinguishedNameString ;
        End;
        pNWDPDistinguishedNameStrSeq = ^NWDPDistinguishedNameStrSeq;
    Type
        NWDPIntegerSeq = Record
            itemCount  :   nuint ;
            itemPtr  :   pnint32 ;
        End;
        pNWDPIntegerSeq = ^NWDPIntegerSeq;
    Type
        NWDPCardinalSeq = Record
            itemCount  :   nuint ;
            itemPtr  :   pnuint32 ;
        End;
        pNWDPCardinalSeq = ^NWDPCardinalSeq;
    Type
        NWDPIntegerRange = Record
            lowerBound  :   nint32 ;
            upperBound  :   nint32 ;
        End;
        pNWDPIntegerRange = ^NWDPIntegerRange;
    Type
        NWDPCardinalRange = Record
            lowerBound  :   nuint32 ;
            upperBound  :   nuint32 ;
        End;
        pNWDPCardinalRange = ^NWDPCardinalRange;
    Type
        NWDPCardinal64Range = Record
            lowerBound  :   nuint64 ;
            upperBound  :   nuint64 ;
        End;
        pNWDPCardinal64Range = ^NWDPCardinal64Range;
    Type
        NWDPRealOption = Record
            flag  :   nint32 ;
            value  :   nreal64 ;
        End;
        pNWDPRealOption = ^NWDPRealOption;
    Type
        NWDPRealSet = Record
            itemCount  :   nuint ;
            itemPtr  :   pnreal64 ;
        End;
        pNWDPRealSet = ^NWDPRealSet;
    Type
        NWDPRealRange = Record
            lowerBound  :   nreal64 ;
            upperBound  :   nreal64 ;
        End;
        pNWDPRealRange = ^NWDPRealRange;
    Type
        NWDPObjectIdentifierSet = Record
            itemCount  :   nuint ;
            itemPtr  :   pNWDPObjectIdentifier ;
        End;
        pNWDPObjectIdentifierSet = ^NWDPObjectIdentifierSet;
    Type
        NWDPNameOrOidSet = Record
            itemCount  :   nuint ;
            itemPtr  :   pNWDPNameOrOid ;
        End;
        pNWDPNameOrOidSet = ^NWDPNameOrOidSet;
    Type
        NWDPRDNSequence = Record
            itemCount  :   nuint ;
            itemPtr  :   pNWDPText ;
        End;
        pNWDPRDNSequence = ^NWDPRDNSequence;
    Const
    NWDP_REALIZATION_LOGICAL = 0;
    NWDP_REALIZATION_PHYSICAL = 1;
    NWDP_REALIZATION_LOG_AND_PHYS = 2;
    Type NWDPRealizationEnum = 0..2;
    pNWDPRealizationEnum = ^NWDPRealizationEnum;
    Type
        NWDPXYRealDimensions = Record
            xDimension  :   nreal64 ;
            yDimension  :   nreal64 ;
        End;
        pNWDPXYRealDimensions = ^NWDPXYRealDimensions;
    Const
    NWDP_DIMENSION_NUMERIC = 0;
    NWDP_DIMENSION_NAMED = 1;
    Type NWDPDimValueEnum = 0..1;
    pNWDPDimValueEnum = ^NWDPDimValueEnum;
    Type
        NWDPDimValue = Record
            designator  :   NWDPDimValueEnum ;
            numericValue  :   nreal64 ;  (* union statement *)
        End;
        pNWDPDimValue = ^NWDPDimValue;
    Type
        NWDPDimension = Record
            value  :   NWDPDimValue ;
            toleranceOption  :   NWDPRealOption ;
        End;
        pNWDPDimension = ^NWDPDimension;
    Type
        NWDPXYCardinalDimensions = Record
            xDimension  :   nuint32 ;
            yDimension  :   nuint32 ;
        End;
        pNWDPXYCardinalDimensions = ^NWDPXYCardinalDimensions;
    Const
    NWDP_DIM_XY_REAL = 0;
    NWDP_DIM_XY_NAMED = 1;
    NWDP_DIM_XY_CARDINAL = 2;
    Type NWDPXYDimensionsValueEnum = 0..2;
    pNWDPXYDimensionsValueEnum = ^NWDPXYDimensionsValueEnum;
    Type
        NWDPXYDimensionsValue = Record
            designator  :   NWDPXYDimensionsValueEnum ;
            realValue  :   NWDPXYRealDimensions ;  (* union statement *)
        End;
        pNWDPXYDimensionsValue = ^NWDPXYDimensionsValue;
    Type
        NWDPXYDimensions = Record
            value  :   NWDPXYDimensionsValue ;
            toleranceOption  :   NWDPRealOption ;
        End;
        pNWDPXYDimensions = ^NWDPXYDimensions;
    Const
    NWDP_LOCATION_NUMERIC = 0;
    NWDP_LOCATION_NAMED = 1;
    Type NWDPLocationValueEnum = 0..1;
    pNWDPLocationValueEnum = ^NWDPLocationValueEnum;
    Type
        NWDPLocationValue = Record
            designator  :   NWDPLocationValueEnum ;
            numericValueSeq  :   NWDPRealSet ;  (* union statement *)
        End;
        pNWDPLocationValue = ^NWDPLocationValue;
    Type
        NWDPLocations = Record
            value  :   NWDPLocationValue ;
            toleranceOption  :   NWDPRealOption ;
        End;
        pNWDPLocations = ^NWDPLocations;
    Type
        NWDPArea = Record
            minimumX  :   nreal64 ;
            maximumX  :   nreal64 ;
            minimumY  :   nreal64 ;
            maximumY  :   nreal64 ;
        End;
        pNWDPArea = ^NWDPArea;
    Type
        NWDPAreaSeq = Record
            itemCount  :   nuint ;
            itemPtr  :   pNWDPArea ;
        End;
        pNWDPAreaSeq = ^NWDPAreaSeq;
    Const
    NWDP_EDGE_BOTTOM = 0;
    NWDP_EDGE_RIGHT = 1;
    NWDP_EDGE_TOP = 2;
    NWDP_EDGE_LEFT = 3;
    Type NWDPEdge = 0..3;
    pNWDPEdge = ^NWDPEdge;
    Type
        NWDPEdgeOption = Record
            flag  :   nint32 ;
            value  :   NWDPEdge ;
        End;
        pNWDPEdgeOption = ^NWDPEdgeOption;
    Const
    NWDP_CARDINAL_OR_OID_NUMBER = 0;
    NWDP_CARDINAL_OR_OID_ID = 1;
    Type NWDPCardinalOrOidEnum = 0..1;
    pNWDPCardinalOrOidEnum = ^NWDPCardinalOrOidEnum;
    Type
        NWDPCardinalOrOid = Record
            designator  :   NWDPCardinalOrOidEnum ;
            cardinal  :   nint32 ;  (* union statement *)
        End;
        pNWDPCardinalOrOid = ^NWDPCardinalOrOid;
    Type
        NWDPOidCardinalMap = Record
            oidOption  :   NWDPObjectIdentifier ;
            cardinal  :   nuint32 ;
        End;
        pNWDPOidCardinalMap = ^NWDPOidCardinalMap;
    Const
    NWDP_CARDINAL_OR_NAM_OR_OID_NUM = 0;
    NWDP_CARDINAL_OR_NAME_OR_OID_ID = 1;
    Type NWDPCardinalOrNameOrOidEnum = 0..1;
    pNWDPCardinalOrNameOrOidEnum = ^NWDPCardinalOrNameOrOidEnum;
    Type
        NWDPCardinalOrNameOrOid = Record
            designator  :   NWDPCardinalOrNameOrOidEnum ;
            cardinal  :   nint32 ;  (* union statement *)
        End;
        pNWDPCardinalOrNameOrOid = ^NWDPCardinalOrNameOrOid;
    Const
    NWDP_INT_OR_OID_ID = 0;
    NWDP_INT_OR_OID_NUMBER = 1;
    Type NWDPPositivIntegerOrOidEnum = 0..1;
    pNWDPPositivIntegerOrOidEnum = ^NWDPPositivIntegerOrOidEnum;
    Type
        NWDPPositiveIntegerOrOid = Record
            designator  :   NWDPPositivIntegerOrOidEnum ;
            oid  :   NWDPObjectIdentifier ;  (* union statement *)
        End;
        pNWDPPositiveIntegerOrOid = ^NWDPPositiveIntegerOrOid;
    Type
        NWDPPrtContainedObjectId = Record
            printerName  :   NWDPText ;
            localIdentifier  :   nuint32 ;
        End;
        pNWDPPrtContainedObjectId = ^NWDPPrtContainedObjectId;
    Type
        NWDPPrtContainedObjectIdSet = Record
            itemCount  :   nuint ;
            itemPtr  :   pNWDPPrtContainedObjectId ;
        End;
        pNWDPPrtContainedObjectIdSet = ^NWDPPrtContainedObjectIdSet;
    Type
        NWDPDocumentIdentifier = Record
            jobIdentifier  :   NWDPPrtContainedObjectId ;
            documentNumber  :   nuint32 ;
        End;
        pNWDPDocumentIdentifier = ^NWDPDocumentIdentifier;
    Const
    NWDP_DA_OR_ADDR_AND_OR_DIR_NAME = 0;
    NWDP_DA_DISTINGUISHED_NAME = 1;
    NWDP_DA_TEXT = 2;
    NWDP_DA_OCTET_STRING = 3;
    NWDP_DA_DIST_NAME_STRING = 4;
    NWDP_DA_RPC_ADDRESS = 5;
    NWDP_DA_QUALIFIED_NAME = 6;
    Type NWDPDeliveryAddressEnum = 0..6;
    pNWDPDeliveryAddressEnum = ^NWDPDeliveryAddressEnum;
    Type
        NWDPDeliveryAddress = Record
            designator  :   NWDPDeliveryAddressEnum ;
            mhsAddress  :   NWDPText ;  (* union statement *)
        End;
        pNWDPDeliveryAddress = ^NWDPDeliveryAddress;
    Type
        NWDPPrtConfigObjectId = Record
            printerName  :   NWDPText ;
            qualifiedName  :   NWDPQualifiedName ;
        End;
        pNWDPPrtConfigObjectId = ^NWDPPrtConfigObjectId;
    Type
        NWDPEventObjectId = Record
            name  :   NWDPText ;
            containingClassOid  :   NWDPObjectIdentifier ;
            eventType  :   nint32 ;
        End;
        pNWDPEventObjectId = ^NWDPEventObjectId;
    Type
        NWDPQualifiedNameMap = Record
            primary  :   NWDPQualifiedName ;
            secondary  :   NWDPQualifiedName ;
        End;
        pNWDPQualifiedNameMap = ^NWDPQualifiedNameMap;
    Type
        NWDPPrivAttrCertificate = Record
            itemCount  :   nuint ;
            itemPtr  :   pnint8 ;
        End;
        pNWDPPrivAttrCertificate = ^NWDPPrivAttrCertificate;
    Type
        NWDPPrivileges = Record
            operationPacOption  :   NWDPPrivAttrCertificate ;
            proxyPacOption  :   NWDPPrivAttrCertificate ;
        End;
        pNWDPPrivileges = ^NWDPPrivileges;
    Type
        NWDPDeliveryAddrForMethod = Record
            method  :   NWDPObjectIdentifier ;
            address  :   NWDPDeliveryAddress ;
        End;
        pNWDPDeliveryAddrForMethod = ^NWDPDeliveryAddrForMethod;
    Const
    NWDP_OBJ_ID_NONE = 0;
    NWDP_OBJ_ID_PRT_CONTAIND_OBJ_ID = 1;
    NWDP_OBJ_ID_DOCUMENT_IDENTIFIER = 2;
    NWDP_OBJ_ID_OBJECT_IDENTIFIER = 3;
    NWDP_OBJ_ID_OBJECT_NAME = 4;
    NWDP_OBJ_ID_NAME_OR_OID = 5;
    NWDP_OBJ_ID_SIMPLE_NAME = 6;
    NWDP_OBJ_ID_PRT_CONFIG_OBJ_ID = 7;
    NWDP_OBJ_ID_QUALIFIED_NAME = 8;
    NWDP_OBJ_ID_EVENT_OBJECT_ID = 9;
    Type NWDPObjIdentificationEnum = 0..9;
    pNWDPObjIdentificationEnum = ^NWDPObjIdentificationEnum;
    Type
        NWDPObjectIdentification = Record
            designator  :   NWDPObjIdentificationEnum ;
            prtContainedObjectId  :   NWDPPrtContainedObjectId ;  (* union statement *)
        End;
        pNWDPObjectIdentification = ^NWDPObjectIdentification;
    Type
        NWDPObjectIdentificationSeq = Record
            itemCount  :   nuint ;
            itemPtr  :   pNWDPObjectIdentification ;
        End;
        pNWDPObjectIdentificationSeq = ^NWDPObjectIdentificationSeq;
    Type
        NWDPTypedName = Record
            name  :   NWDPText ;
            level  :   nint32 ;
            interval  :   nint32 ;
        End;
        pNWDPTypedName = ^NWDPTypedName;
    Const
    NWDP_NET_IPX = 0;
    NWDP_NET_IP = 1;
    NWDP_NET_SDLC = 2;
    NWDP_NET_TOKENRING_ETHERNET = 3;
    NWDP_NET_OSI = 4;
    NWDP_NET_APPLETALK = 5;
    NWDP_NET_COUNT = 6;
    Type NWDPNetAddressTypeEnum = 0..6;
    pNWDPNetAddressTypeEnum = ^NWDPNetAddressTypeEnum;
    Type
        NWDPNetAddress = Record
            type1  :   NWDPNetAddressTypeEnum ;
            address  :   NWDPOctetString ;
        End;
        pNWDPNetAddress = ^NWDPNetAddress;
    Type
        NWDPNameOrOidDimensionMap = Record
            nameOrOid  :   NWDPNameOrOid ;
            value  :   NWDPXYCardinalDimensions ;
        End;
        pNWDPNameOrOidDimensionMap = ^NWDPNameOrOidDimensionMap;
    Const
    NWDP_STATE_SEVERITY_OTHER = 1;
    NWDP_STATE_SEVERITY_WARNING = 2;
    NWDP_STATE_SEVERITY_CRITICAL = 3;
    Type NWDPStateSeverityEnum = 0..3;
    pNWDPStateSeverityEnum = ^NWDPStateSeverityEnum;
    Const
    NWDP_TRAINING_OTHER = 1;
    NWDP_TRAINING_UNKNOWN = 2;
    NWDP_TRAINING_UNTRAINED = 3;
    NWDP_TRAINING_TRAINED = 4;
    NWDP_TRAINING_FIELD_SERVICE = 5;
    NWDP_TRAINING_MANAGEMENT = 6;
    Type NWDPTrainingEnum = 0..6;
    pNWDPTrainingEnum = ^NWDPTrainingEnum;
    Type
        NWDPPrinterStateReason = Record
            identifier  :   NWDPNameOrOid ;
            severity  :   NWDPStateSeverityEnum ;
            trainingLevel  :   NWDPTrainingEnum ;
            objectClassOid  :   NWDPObjectIdentifier ;
            objectIdentification  :   NWDPObjectIdentification ;
            time  :   nuint32 ;
            messageOptionPtr  :   pNWDPNameOrOid ;
        End;
        pNWDPPrinterStateReason = ^NWDPPrinterStateReason;
    Const
    NWDP_PERSISTENCE_PERMANENT = 0;
    NWDP_PERSISTENCE_VOLATILE = 1;
    Type NWDPPersistenceEnum = 0..1;
    pNWDPPersistenceEnum = ^NWDPPersistenceEnum;
    Const
    NWDP_ADDR_ITEM_USER = 0;
    NWDP_ADDR_ITEM_SERVER = 1;
    NWDP_ADDR_ITEM_VOLUME = 2;
    NWDP_ADDR_ITEM_ORG_UNIT = 3;
    NWDP_ADDR_ITEM_ORG = 4;
    NWDP_ADDR_ITEM_GROUP = 5;
    NWDP_ADDR_ITEM_DN = 6;
    NWDP_ADDR_ITEM_USR_OR_CONTAINER = 7;
    NWDP_ADDR_ITEM_CASE_EXACT_STR = 8;
    NWDP_ADDR_ITEM_CASE_IGNORE_STR = 9;
    NWDP_ADDR_ITEM_NUMERIC_STR = 10;
    NWDP_ADDR_ITEM_DOS_FILENAME = 11;
    NWDP_ADDR_ITEM_PHONE_NUMBER = 12;
    NWDP_ADDR_ITEM_BOOLEAN = 13;
    NWDP_ADDR_ITEM_INTEGER = 14;
    NWDP_ADDR_ITEM_NET_ADDRESS = 15;
    NWDP_ADDR_ITEM_CHOICE = 16;
    NWDP_ADDR_ITEM_GROUPWISE_USER = 17;
    Type NWDPAddressItemTypeEnum = 0..17;
    pNWDPAddressItemTypeEnum = ^NWDPAddressItemTypeEnum;
    Type
        NWDPAddressItem = Record
            designator  :   NWDPAddressItemTypeEnum ;
            userName  :   NWDPQualifiedName ;  (* union statement *)
        End;
        pNWDPAddressItem = ^NWDPAddressItem;
    Type
        NWDPNotifyDeliveryAddr = Record
            itemCount  :   nuint ;
            itemPtr  :   pNWDPAddressItem ;
        End;
        pNWDPNotifyDeliveryAddr = ^NWDPNotifyDeliveryAddr;
    Const
    NWDP_EVENT_OBJ_OP_NONE = 0;
    NWDP_EVENT_OBJ_OP_ADD_FLAG = 1;
    NWDP_EVENT_OBJ_OP_DELETE_FLAG = 2;
    NWDP_EVENT_OBJ_OP_DELETE_OBJECT = 3;
    Type NWDPEventObjectOperation = 0..3;
    pNWDPEventObjectOperation = ^NWDPEventObjectOperation;
    Const
    NWDP_EVENT_OBJ_TYPE_OBJECT = 0;
    NWDP_EVENT_OBJ_TYPE_FILTER = 1;
    NWDP_EVENT_OBJ_TYPE_DETAIL = 2;
    Type NWDPEventObjectTypeEnum = 0..2;
    pNWDPEventObjectTypeEnum = ^NWDPEventObjectTypeEnum;
    Type
        NWDPEventObjectItem = Record
            designator  :   NWDPEventObjectTypeEnum ;
            filterClassOid  :   NWDPObjectIdentifier ;  (* union statement *)
        End;
        pNWDPEventObjectItem = ^NWDPEventObjectItem;
    Type
        NWDPEventObject = Record
            eventType  :   nuint32 ;
            containingClassOid  :   NWDPObjectIdentifier ;
            containingObjectId  :   NWDPObjectIdentification ;
            opCode  :   NWDPEventObjectOperation ;
            item  :   NWDPEventObjectItem ;
        End;
        pNWDPEventObject = ^NWDPEventObject;
    Type
        NWDPEventObjectSet = Record
            itemCount  :   nuint ;
            itemPtr  :   pNWDPEventObject ;
        End;
        pNWDPEventObjectSet = ^NWDPEventObjectSet;
    Type
        NWDPEventHandlingProfile = Record
            profileId  :   nuint32 ;
            persistence  :   NWDPPersistenceEnum ;
            consumerName  :   NWDPQualifiedName ;
            supplierId  :   NWDPOctetString ;
            languageId  :   nint32 ;
            methodId  :   NWDPNameOrOid ;
            deliveryAddress  :   NWDPNotifyDeliveryAddr ;
            eventObjectSet  :   NWDPEventObjectSet ;
            accountOption  :   NWDPQualifiedName ;
        End;
        pNWDPEventHandlingProfile = ^NWDPEventHandlingProfile;
    Const
    NWDP_LIST_CHOICE_ID = 0;
    NWDP_LIST_CHOICE_FILTER = 1;
    Type NWDPListProfilesChoiceEnum = 0..1;
    pNWDPListProfilesChoiceEnum = ^NWDPListProfilesChoiceEnum;
    Const
    NWDP_LIST_RESULT_COMPLETE = 0;
    NWDP_LIST_RESULT_NO_EVENT_OBJS = 1;
    NWDP_LIST_RESULT_PROFILE_IDS = 2;
    Type NWDPListProfilesResultEnum = 0..2;
    pNWDPListProfilesResultEnum = ^NWDPListProfilesResultEnum;
    Type
        NWDPListProfilesFilter = Record
            consumerNameOption  :   NWDPQualifiedName ;
            methodIdOptionPtr  :   pNWDPNameOrOid ;
            languageId  :   NWDPIntegerOption ;
        End;
        pNWDPListProfilesFilter = ^NWDPListProfilesFilter;
    Type
        NWDPListProfilesChoice = Record
            designator  :   NWDPListProfilesChoiceEnum ;
            profileIdSeq  :   NWDPCardinalSeq ;  (* union statement *)
        End;
        pNWDPListProfilesChoice = ^NWDPListProfilesChoice;
    Const
    NWDP_LIST_EVENT_PROFILES_SPEC = 0;
    NWDP_LIST_EVENT_PROFILES_CONT = 1;
    Type NWDPListProfilesTypeEnum = 0..1;
    pNWDPListProfilesTypeEnum = ^NWDPListProfilesTypeEnum;
    Type
        NWDPListEventProfilesSpec = Record
            supplierAlias  :   NWDPQualifiedName ;
            choice  :   NWDPListProfilesChoice ;
            detail  :   NWDPListProfilesResultEnum ;
            countOption  :   NWDPIntegerOption ;
        End;
        pNWDPListEventProfilesSpec = ^NWDPListEventProfilesSpec;
    Type
        NWDPListEventProfilesCont = Record
            context  :   NWDPOctetString ;
            abort  :   nbool ;
        End;
        pNWDPListEventProfilesCont = ^NWDPListEventProfilesCont;
    Type
        NWDPListProfilesType = Record
            designator  :   NWDPListProfilesTypeEnum ;
            specification  :   NWDPListEventProfilesSpec ;  (* union statement *)
        End;
        pNWDPListProfilesType = ^NWDPListProfilesType;
    Type
        NWDPProfileResultSet = Record
            itemCount  :   nuint ;
            itemPtr  :   pNWDPEventHandlingProfile ;
        End;
        pNWDPProfileResultSet = ^NWDPProfileResultSet;
    Type
        NWDPResultsProfile = Record
            deliveryMethodOption  :   NWDPObjectIdentifier ;
            resultsSetCommentOption  :   NWDPNameOrOid ;
            deliveryAddressOptionPtr  :   pNWDPDeliveryAddress ;
            jobCopies  :   nint32 ;
            outputBinOption  :   NWDPPrtContainedObjectId ;
        End;
        pNWDPResultsProfile = ^NWDPResultsProfile;
    Type
        NWDPCriterionThreshold = Record
            designator  :   NWDPAVTEnum ;
            deltaTime  :   nint32 ;  (* union statement *)
        End;
        pNWDPCriterionThreshold = ^NWDPCriterionThreshold;
    Type
        NWDPCriteria = Record
            type1  :   NWDPObjectIdentifier ;
            threshold  :   NWDPCriterionThreshold ;
        End;
        pNWDPCriteria = ^NWDPCriteria;
    Type
        NWDPJobLevel = Record
            organizationId  :   NWDPObjectIdentifier ;
            level  :   nuint32 ;
        End;
        pNWDPJobLevel = ^NWDPJobLevel;
    Type
        NWDPJobCategories = Record
            organizationId  :   NWDPObjectIdentifier ;
            categories  :   NWDPCardinalSeq ;
        End;
        pNWDPJobCategories = ^NWDPJobCategories;
    Type
        NWDPIgnoredAttributeValue = Record
            designator  :   NWDPAVTEnum ;
            identifier  :   NWDPObjectIdentifier ;  (* union statement *)
        End;
        pNWDPIgnoredAttributeValue = ^NWDPIgnoredAttributeValue;
    Type
        NWDPIgnoredAttrValueSet = Record
            itemCount  :   nuint ;
            itemPtr  :   pNWDPIgnoredAttributeValue ;
        End;
        pNWDPIgnoredAttrValueSet = ^NWDPIgnoredAttrValueSet;
    Type
        NWDPIgnoredAttribute = Record
            documentNumberOption  :   nuint32 ;
            attributeId  :   NWDPObjectIdentifier ;
            values  :   NWDPIgnoredAttrValueSet ;
        End;
        pNWDPIgnoredAttribute = ^NWDPIgnoredAttribute;
    Const
    NWDP_RESOURCE_NAME_OR_OID = 0;
    NWDP_RESOURCE_TEXT = 1;
    Type NWDPResourceEnum = 0..1;
    pNWDPResourceEnum = ^NWDPResourceEnum;
    Type
        NWDPResource = Record
            designator  :   NWDPResourceEnum ;
            nameOrOid  :   NWDPNameOrOid ;  (* union statement *)
        End;
        pNWDPResource = ^NWDPResource;
    Type
        NWDPMediumSubstitution = Record
            original  :   NWDPNameOrOid ;
            substitution  :   NWDPNameOrOid ;
        End;
        pNWDPMediumSubstitution = ^NWDPMediumSubstitution;
    Type
        NWDPFontSubstitution = Record
            original  :   NWDPText ;
            substitution  :   NWDPText ;
        End;
        pNWDPFontSubstitution = ^NWDPFontSubstitution;
    Const
    NWDP_RESOURCE_CONTXT_NAM_OR_OID = 0;
    NWDP_RESOURCE_CONTEXT_TEXT = 1;
    Type NWDPResourceContextEnum = 0..1;
    pNWDPResourceContextEnum = ^NWDPResourceContextEnum;
    Type
        NWDPResourceContext = Record
            designator  :   NWDPResourceContextEnum ;
            objectName  :   NWDPNameOrOid ;  (* union statement *)
        End;
        pNWDPResourceContext = ^NWDPResourceContext;
    Type
        NWDPResourceContextSeq = Record
            itemCount  :   nuint ;
            itemPtr  :   pNWDPResourceContext ;
        End;
        pNWDPResourceContextSeq = ^NWDPResourceContextSeq;
    Const
    NWDP_PAGE_ID_NOMINAL_NUMBER = 0;
    NWDP_PAGE_ID_ALPHANUMERIC = 1;
    NWDP_PAGE_ID_TAG = 2;
    Type NWDPPageIdentifierEnum = 0..2;
    pNWDPPageIdentifierEnum = ^NWDPPageIdentifierEnum;
    Type
        NWDPPageIdentifier = Record
            designator  :   NWDPPageIdentifierEnum ;
            nominalPageNumber  :   nint32 ;  (* union statement *)
        End;
        pNWDPPageIdentifier = ^NWDPPageIdentifier;
    Type
        NWDPPageIdentifierOption = Record
            flag  :   nint32 ;
            value  :   NWDPPageIdentifier ;
        End;
        pNWDPPageIdentifierOption = ^NWDPPageIdentifierOption;
    Type
        NWDPPageSelect = Record
            beginningPage  :   NWDPPageIdentifierOption ;
            endingPage  :   NWDPPageIdentifierOption ;
        End;
        pNWDPPageSelect = ^NWDPPageSelect;
    Type
        NWDPPageSelectSequence = Record
            itemCount  :   nuint ;
            itemPtr  :   pNWDPPageSelect ;
        End;
        pNWDPPageSelectSequence = ^NWDPPageSelectSequence;
    Const
    NWDP_DOC_CONTENT_INCLUDED = 0;
    NWDP_DOC_CONTENT_REFERENCED = 1;
    Type NWDPDocumentContentEnum = 0..1;
    pNWDPDocumentContentEnum = ^NWDPDocumentContentEnum;
    Type
        NWDPDocumentContent = Record
            designator  :   NWDPDocumentContentEnum ;
            includedDocument  :   NWDPOctetString ;  (* union statement *)
        End;
        pNWDPDocumentContent = ^NWDPDocumentContent;
    Const
    NWDP_PAGE_SIZE_ID = 0;
    NWDP_PAGE_SIZE_DIMENSIONS = 1;
    Type NWDPPageSizeEnum = 0..1;
    pNWDPPageSizeEnum = ^NWDPPageSizeEnum;
    Type
        NWDPPageSize = Record
            designator  :   NWDPPageSizeEnum ;
            pageSizeId  :   NWDPObjectIdentifier ;  (* union statement *)
        End;
        pNWDPPageSize = ^NWDPPageSize;
    Const
    NWDP_DIR_TO_RIGHT_TO_BOTTOM = 0;
    NWDP_DIR_TO_LEFT_TO_BOTTOM = 1;
    NWDP_DIR_BIDIRECT_TO_BOTTOM = 2;
    NWDP_DIR_TO_RIGHT_TO_TOP = 3;
    NWDP_DIR_TO_LEFT_TO_TOP = 4;
    NWDP_DIR_BIDIRECT_TO_TOP = 5;
    NWDP_DIR_TO_BOTTOM_TO_RIGHT = 6;
    NWDP_DIR_TO_BOTTOM_TO_LEFT = 7;
    NWDP_DIR_TO_TOP_TO_LEFT = 8;
    NWDP_DIR_TO_TOP_TO_RIGHT = 9;
    Type NWDPPresentatnDirectionEnum = 0..9;
    pNWDPPresentatnDirectionEnum = ^NWDPPresentatnDirectionEnum;
    Const
    NWDP_PAGE_ORDER_UNKNOWN = 0;
    NWDP_PAGE_ORDER_FIRST_TO_LAST = 1;
    NWDP_PAGE_ORDER_LAST_TO_FIRST = 2;
    Type NWDPPageOrderTypeEnum = 0..2;
    pNWDPPageOrderTypeEnum = ^NWDPPageOrderTypeEnum;
    Const
    NWDP_PAGE_ID_TYPE_NUMERIC = 0;
    NWDP_PAGE_ID_TYPE_ALPHANUMERIC = 1;
    NWDP_PAGE_ID_TYPE_TAG = 2;
    Type NWDPPageIdTypeEnum = 0..2;
    pNWDPPageIdTypeEnum = ^NWDPPageIdTypeEnum;
    Const
    NWDP_MEDIA_SELECT_ALL_PAGES = 0;
    NWDP_MEDIA_SELECT_SELECTD_PAGES = 1;
    Type NWDPMediaSelectEnum = 0..1;
    pNWDPMediaSelectEnum = ^NWDPMediaSelectEnum;
    Type
        NWDPMediaSelect = Record
            pageRange  :   NWDPPageSelect ;
            mediumId  :   NWDPNameOrOid ;
        End;
        pNWDPMediaSelect = ^NWDPMediaSelect;
    Type
        NWDPMediaSelectSeq = Record
            itemCount  :   nuint ;
            itemPtr  :   pNWDPMediaSelect ;
        End;
        pNWDPMediaSelectSeq = ^NWDPMediaSelectSeq;
    Type
        NWDPPageMediaSelect = Record
            designator  :   NWDPMediaSelectEnum ;
            mediumForAllPages  :   NWDPNameOrOid ;  (* union statement *)
        End;
        pNWDPPageMediaSelect = ^NWDPPageMediaSelect;
    Const
    NWDP_MEDIUM_SIZE_DISCRETE = 0;
    NWDP_MEDIUM_SIZE_CONTINUOUS = 1;
    Type NWDPMediumSizeEnum = 0..1;
    pNWDPMediumSizeEnum = ^NWDPMediumSizeEnum;
    Type
        NWDPMediumDiscreteSizes = Record
            pageSize  :   NWDPPageSize ;
            longEdgeFeeds  :   nbool ;
            assuredReproductionArea  :   NWDPArea ;
        End;
        pNWDPMediumDiscreteSizes = ^NWDPMediumDiscreteSizes;
    Type
        NWDPMediumContinuousSizes = Record
            sizeRangeAcrossFeedDirection  :   NWDPRealRange ;
            sizeIncrementAcrossFeedDir  :   nreal64 ;
            sizeRangeInFeedDirection  :   NWDPRealRange ;
            sizeIncrementInFeedDir  :   nreal64 ;
            longEdgeFeeds  :   nbool ;
            GenericAssuredReproductionArea  :   NWDPArea ;
        End;
        pNWDPMediumContinuousSizes = ^NWDPMediumContinuousSizes;
    Type
        NWDPMediumSize = Record
            designator  :   NWDPMediumSizeEnum ;
            discreteSizes  :   NWDPMediumDiscreteSizes ;  (* union statement *)
        End;
        pNWDPMediumSize = ^NWDPMediumSize;
    Type
        NWDPMediumSourceSize = Record
            inputTrayOptionPtr  :   pNWDPNameOrOid ;
            mediumSize  :   NWDPMediumSize ;
        End;
        pNWDPMediumSourceSize = ^NWDPMediumSourceSize;
    Type
        NWDPInputTrayMedium = Record
            inputTray  :   NWDPNameOrOid ;
            medium  :   NWDPNameOrOid ;
        End;
        pNWDPInputTrayMedium = ^NWDPInputTrayMedium;
    Const
    NWDP_PAGE_FACE_UNKNOWN = 0;
    NWDP_PAGE_FACE_UP = 1;
    NWDP_PAGE_FACE_DOWN = 2;
    Type NWDPPageOrientationEnum = 0..2;
    pNWDPPageOrientationEnum = ^NWDPPageOrientationEnum;
    Type
        NWDPOutputBinChar = Record
            stackingOrder  :   NWDPPageOrderTypeEnum ;
            orientation  :   NWDPPageOrientationEnum ;
        End;
        pNWDPOutputBinChar = ^NWDPOutputBinChar;
    Type
        NWDPOutBinsCharacteristics = Record
            itemCount  :   nuint ;
            itemPtr  :   pNWDPOutputBinChar ;
        End;
        pNWDPOutBinsCharacteristics = ^NWDPOutBinsCharacteristics;
    Type
        NWDPLevelRange = Record
            organizationId  :   NWDPObjectIdentifier ;
            minimum  :   nint32 ;
            maximum  :   nint32 ;
        End;
        pNWDPLevelRange = ^NWDPLevelRange;
    Type
        NWDPCategorySet = Record
            organizationId  :   NWDPObjectIdentifier ;
            categoryMinimum  :   NWDPCardinalSeq ;
            categoryMaximum  :   NWDPCardinalSeq ;
        End;
        pNWDPCategorySet = ^NWDPCategorySet;
    Const
    NWDP_NUMBERS_UP_CARDINAL = 0;
    NWDP_NUMBERS_UP_NAME_OR_OID = 1;
    NWDP_NUMBERS_UP_CARDINAL_RANGE = 2;
    Type NWDPNumbersUpEnum = 0..2;
    pNWDPNumbersUpEnum = ^NWDPNumbersUpEnum;
    Type
        NWDPNumbersUpSupported = Record
            designator  :   NWDPNumbersUpEnum ;
            cardinal  :   nuint32 ;  (* union statement *)
        End;
        pNWDPNumbersUpSupported = ^NWDPNumbersUpSupported;
    Type
        NWDPCommonParameters = Record
            referenceSizeOptionPtr  :   pNWDPXYDimensions ;
            referenceEdgeOption  :   NWDPEdgeOption ;
            jogEdgeOption  :   NWDPEdgeOption ;
        End;
        pNWDPCommonParameters = ^NWDPCommonParameters;
    Const
    NWDP_STITCHING_NAMED = 0;
    NWDP_STITCHING_PARAMETERS = 1;
    Type NWDPStitchingEnum = 0..1;
    pNWDPStitchingEnum = ^NWDPStitchingEnum;
    Type
        NWDPStitchParameters = Record
            common  :   NWDPCommonParameters ;
            processOffsetOptionPtr  :   pNWDPDimension ;
            headLocationsOptionPtr  :   pNWDPLocations ;
            stitchType  :   NWDPNameOrOid ;
        End;
        pNWDPStitchParameters = ^NWDPStitchParameters;
    Type
        NWDPStitchingSpec = Record
            designator  :   NWDPStitchingEnum ;
            namedStitching  :   NWDPNameOrOid ;  (* union statement *)
        End;
        pNWDPStitchingSpec = ^NWDPStitchingSpec;
    Const
    NWDP_BINDING_NAMED = 0;
    NWDP_BINDING_PARAMETERS = 1;
    Type NWDPBindingEnum = 0..1;
    pNWDPBindingEnum = ^NWDPBindingEnum;
    Type
        NWDPBindParameters = Record
            common  :   NWDPCommonParameters ;
            bindType  :   NWDPNameOrOid ;
            bindColor  :   NWDPNameOrOid ;
        End;
        pNWDPBindParameters = ^NWDPBindParameters;
    Type
        NWDPBindingSpec = Record
            designator  :   NWDPBindingEnum ;
            namedBinding  :   NWDPNameOrOid ;  (* union statement *)
        End;
        pNWDPBindingSpec = ^NWDPBindingSpec;
    Const
    NWDP_TRIMMING_NAMED = 0;
    NWDP_TRIMMING_PARAMETERS = 1;
    Type NWDPTrimmingEnum = 0..1;
    pNWDPTrimmingEnum = ^NWDPTrimmingEnum;
    Type
        NWDPTrimParameters = Record
            common  :   NWDPCommonParameters ;
            trimOffset  :   NWDPDimension ;
            trimDimensions  :   NWDPXYDimensions ;
        End;
        pNWDPTrimParameters = ^NWDPTrimParameters;
    Type
        NWDPTrimmingSpec = Record
            designator  :   NWDPTrimmingEnum ;
            namedTrimming  :   NWDPNameOrOid ;  (* union statement *)
        End;
        pNWDPTrimmingSpec = ^NWDPTrimmingSpec;
    Const
    NWDP_DIE_CUTTING_NAMED = 0;
    NWDP_DIE_CUTTING_PARAMETERS = 1;
    Type NWDPDieCuttingEnum = 0..1;
    pNWDPDieCuttingEnum = ^NWDPDieCuttingEnum;
    Type
        NWDPDieCuttingParameters = Record
            common  :   NWDPCommonParameters ;
            dieCutLocation  :   NWDPXYDimensions ;
            dieCutName  :   NWDPNameOrOid ;
        End;
        pNWDPDieCuttingParameters = ^NWDPDieCuttingParameters;
    Type
        NWDPDieCuttingSpec = Record
            designator  :   NWDPDieCuttingEnum ;
            namedDieCutting  :   NWDPNameOrOid ;  (* union statement *)
        End;
        pNWDPDieCuttingSpec = ^NWDPDieCuttingSpec;
    Const
    NWDP_PUNCHING_NAMED = 0;
    NWDP_PUNCHING_PARAMETERS = 1;
    Type NWDPPunchingEnum = 0..1;
    pNWDPPunchingEnum = ^NWDPPunchingEnum;
    Type
        NWDPPunchParameters = Record
            common  :   NWDPCommonParameters ;
            processOffsetOptionPtr  :   pNWDPDimension ;
            headLocations  :   NWDPLocations ;
            punchDiameterPtr  :   pNWDPDimension ;
        End;
        pNWDPPunchParameters = ^NWDPPunchParameters;
    Type
        NWDPPunchingSpec = Record
            designator  :   NWDPPunchingEnum ;
            namedPunching  :   NWDPNameOrOid ;  (* union statement *)
        End;
        pNWDPPunchingSpec = ^NWDPPunchingSpec;
    Const
    NWDP_PERFORATING_NAMED = 0;
    NWDP_PERFORATING_PARAMETERS = 1;
    Type NWDPPerforatingEnum = 0..1;
    pNWDPPerforatingEnum = ^NWDPPerforatingEnum;
    Type
        NWDPPerfParameters = Record
            common  :   NWDPCommonParameters ;
            headLocations  :   NWDPLocations ;
            perfType  :   NWDPNameOrOid ;
        End;
        pNWDPPerfParameters = ^NWDPPerfParameters;
    Type
        NWDPPerforatingSpec = Record
            designator  :   NWDPPerforatingEnum ;
            namedPerforating  :   NWDPNameOrOid ;  (* union statement *)
        End;
        pNWDPPerforatingSpec = ^NWDPPerforatingSpec;
    Const
    NWDP_SLITTING_NAMED = 0;
    NWDP_SLITTING_PARAMETERS = 1;
    Type NWDPSlittingEnum = 0..1;
    pNWDPSlittingEnum = ^NWDPSlittingEnum;
    Type
        NWDPSlitParameters = Record
            common  :   NWDPCommonParameters ;
            headLocations  :   NWDPLocations ;
        End;
        pNWDPSlitParameters = ^NWDPSlitParameters;
    Type
        NWDPSlittingSpec = Record
            designator  :   NWDPSlittingEnum ;
            namedSlitting  :   NWDPNameOrOid ;  (* union statement *)
        End;
        pNWDPSlittingSpec = ^NWDPSlittingSpec;
    Const
    NWDP_INSERT_NAME = 0;
    NWDP_INSERT_BIN = 1;
    Type NWDPInsertIdEnum = 0..1;
    pNWDPInsertIdEnum = ^NWDPInsertIdEnum;
    Type
        NWDPInsertId = Record
            designator  :   NWDPInsertIdEnum ;
            insertName  :   NWDPNameOrOid ;  (* union statement *)
        End;
        pNWDPInsertId = ^NWDPInsertId;
    Const
    NWDP_INSERT_TOP_SURFACE_TOP = 0;
    NWDP_INSERT_TOP_SURFACE_BOTTOM = 1;
    Type NWDPInsertTopSurfaceEnum = 0..1;
    pNWDPInsertTopSurfaceEnum = ^NWDPInsertTopSurfaceEnum;
    Type
        NWDPInsertSheet = Record
            insertId  :   NWDPInsertId ;
            insertSizeOptionPtr  :   pNWDPXYDimensions ;
            insertEdgeOption  :   NWDPEdgeOption ;
            insertTopSurface  :   NWDPInsertTopSurfaceEnum ;
            insertAfter  :   nuint32 ;
            insertMessageOptionPtr  :   pNWDPNameOrOid ;
        End;
        pNWDPInsertSheet = ^NWDPInsertSheet;
    Type
        NWDPInsertSheetSeq = Record
            itemCount  :   nuint ;
            itemPtr  :   pNWDPInsertSheet ;
        End;
        pNWDPInsertSheetSeq = ^NWDPInsertSheetSeq;
    Type
        NWDPInsertParameters = Record
            referenceEdgeOption  :   NWDPEdgeOption ;
            jogEdgeOption  :   NWDPEdgeOption ;
            insertSheetList  :   NWDPInsertSheetSeq ;
        End;
        pNWDPInsertParameters = ^NWDPInsertParameters;
    Const
    NWDP_INSERT_SPEC_NAMED = 0;
    NWDP_INSERT_SPEC_PARAMETERS = 1;
    Type NWDPInsertSpecEnum = 0..1;
    pNWDPInsertSpecEnum = ^NWDPInsertSpecEnum;
    Type
        NWDPInsertSpec = Record
            designator  :   NWDPInsertSpecEnum ;
            namedInserting  :   NWDPNameOrOid ;  (* union statement *)
        End;
        pNWDPInsertSpec = ^NWDPInsertSpec;
    Const
    NWDP_COVER_SPEC_NAMED = 0;
    NWDP_COVER_SPEC_PARAMETERS = 1;
    Type NWDPCoverSpecEnum = 0..1;
    pNWDPCoverSpecEnum = ^NWDPCoverSpecEnum;
    Type
        NWDPCoverParameters = Record
            common  :   NWDPCommonParameters ;
            frontCoverOptionPtr  :   pNWDPNameOrOid ;
            backCoverOptionPtr  :   pNWDPNameOrOid ;
        End;
        pNWDPCoverParameters = ^NWDPCoverParameters;
    Type
        NWDPCoverSpec = Record
            designator  :   NWDPCoverSpecEnum ;
            namedCovers  :   NWDPNameOrOid ;  (* union statement *)
        End;
        pNWDPCoverSpec = ^NWDPCoverSpec;
    Const
    NWDP_FOLDING_SPEC_NAMED = 0;
    NWDP_FOLDING_SPEC_PARAMETERS = 1;
    Type NWDPFoldingSpecEnum = 0..1;
    pNWDPFoldingSpecEnum = ^NWDPFoldingSpecEnum;
    Type
        NWDPFoldingParameters = Record
            common  :   NWDPCommonParameters ;
            headLocations  :   NWDPLocations ;
        End;
        pNWDPFoldingParameters = ^NWDPFoldingParameters;
    Type
        NWDPFoldingSpec = Record
            designator  :   NWDPFoldingSpecEnum ;
            namedFolding  :   NWDPNameOrOid ;  (* union statement *)
        End;
        pNWDPFoldingSpec = ^NWDPFoldingSpec;
    Type
        NWDPOtherParameters = Record
            common  :   NWDPCommonParameters ;
            processOffsetOptionPtr  :   pNWDPDimension ;
            headLocationsOptionPtr  :   pNWDPLocations ;
            otherParams : Record
                itemCount  :   nuint ;
                itemPtr  :   pnint8 ;
            End;
        End;
        pNWDPOtherParameters = ^NWDPOtherParameters;
    Type
        NWDPOtherFinishingSpec = Record
            finishingOpType  :   NWDPNameOrOid ;
            namedSpecOptionPtr  :   pNWDPNameOrOid ;
            parameters  :   NWDPOtherParameters ;
        End;
        pNWDPOtherFinishingSpec = ^NWDPOtherFinishingSpec;
    Const
    NWDP_FINISHING_PROC_STITCHING = 0;
    NWDP_FINISHING_PROC_BINDING = 1;
    NWDP_FINISHING_PROC_TRIMMING = 2;
    NWDP_FINISHING_PROC_DIE_CUTTING = 3;
    NWDP_FINISHING_PROC_PUNCHING = 4;
    NWDP_FINISHING_PROC_PERFORATING = 5;
    NWDP_FINISHING_PROC_SLITTING = 6;
    NWDP_FINISHING_PROC_INSERT = 7;
    NWDP_FINISHING_PROC_COVER = 8;
    NWDP_FINISHING_PROC_FOLDING = 9;
    NWDP_FINISHING_PROC_OTHER = 10;
    Type NWDPFinishingProcEnum = 0..10;
    pNWDPFinishingProcEnum = ^NWDPFinishingProcEnum;
    Type
        NWDPFinishingProcSpec = Record
            designator  :   NWDPFinishingProcEnum ;
            stitchingSpec  :   NWDPStitchingSpec ;  (* union statement *)
        End;
        pNWDPFinishingProcSpec = ^NWDPFinishingProcSpec;
    Type
        NWDPFinishingProcSpecSeq = Record
            itemCount  :   nuint ;
            itemPtr  :   pNWDPFinishingProcSpec ;
        End;
        pNWDPFinishingProcSpecSeq = ^NWDPFinishingProcSpecSeq;
    Const
    NWDP_FINISHING_SPEC_NAMED = 0;
    NWDP_FINISHING_SPEC_LIST = 1;
    Type NWDPFinishingSpecEnum = 0..1;
    pNWDPFinishingSpecEnum = ^NWDPFinishingSpecEnum;
    Type
        NWDPFinishingSpec = Record
            designator  :   NWDPFinishingSpecEnum ;
            named  :   NWDPNameOrOid ;  (* union statement *)
        End;
        pNWDPFinishingSpec = ^NWDPFinishingSpec;
    Type
        NWDPFinishing = Record
            messageOptionPtr  :   pNWDPNameOrOid ;
            spec  :   NWDPFinishingSpec ;
        End;
        pNWDPFinishing = ^NWDPFinishing;
    Const
    NWDP_IMP_ATTR_PLEX = 0;
    NWDP_IMP_ATTR_NUMBER_UP = 1;
    NWDP_IMP_ATTR_X_IMAGE_SHIFT = 2;
    NWDP_IMP_ATTR_Y_IMAGE_SHIFT = 3;
    NWDP_IMP_ATTR_LOG_PAGE_ORIGIN = 4;
    NWDP_IMP_ATTR_LOG_PAGE_X_OFFSET = 5;
    NWDP_IMP_ATTR_LOG_PAGE_Y_OFFSET = 6;
    NWDP_IMP_ATTR_LOG_PAGE_SCALING = 7;
    Type NWDPImpositionAttrEnum = 0..7;
    pNWDPImpositionAttrEnum = ^NWDPImpositionAttrEnum;
    Type
        NWDPImpositionAttr = Record
            designator  :   NWDPImpositionAttrEnum ;
            plex : Record  (* union statement *)
                itemCount  :   nuint ;
                itemPtr  :   pnint8 ;
            End;
        End;
        pNWDPImpositionAttr = ^NWDPImpositionAttr;
    Const
    NWDP_IMPOSITION_OBJECT = 0;
    NWDP_IMPOSITION_ATTR = 1;
    Type NWDPImpositionEnum = 0..1;
    pNWDPImpositionEnum = ^NWDPImpositionEnum;
    Type
        NWDPImposition = Record
            designator  :   NWDPImpositionEnum ;
            impositionObject  :   NWDPNameOrOid ;  (* union statement *)
        End;
        pNWDPImposition = ^NWDPImposition;
    Type
        NWDPColorantSetDescr = Record
            colorantSetClass  :   NWDPObjectIdentifier ;
            colorantSpecSeq  :   NWDPNameOrOidSet ;
        End;
        pNWDPColorantSetDescr = ^NWDPColorantSetDescr;
    Const
    NWDP_COLORANT_SET_NAME = 0;
    NWDP_COLORANT_SET_DESCR = 1;
    Type NWDPColorantEnum = 0..1;
    pNWDPColorantEnum = ^NWDPColorantEnum;
    Type
        NWDPColorantSet = Record
            designator  :   NWDPColorantEnum ;
            colorantSetName  :   NWDPNameOrOid ;  (* union statement *)
        End;
        pNWDPColorantSet = ^NWDPColorantSet;
    Type
        NWDPResourcePrinterId = Record
            keyName  :   NWDPText ;
            mfrName  :   NWDPText ;
            infFileName  :   NWDPText ;
            osType  :   nint32 ;
        End;
        pNWDPResourcePrinterId = ^NWDPResourcePrinterId;
    Type
        NWDPAttributeValue = Record
            designator  :   NWDPAVTEnum ;
            text  :   NWDPText ;  (* union statement *)
        End;
        pNWDPAttributeValue = ^NWDPAttributeValue;
    Type
        NWDPAttributeValueSet = Record
            itemCount  :   nuint ;
            itemPtr  :   pNWDPAttributeValue ;
        End;
        pNWDPAttributeValueSet = ^NWDPAttributeValueSet;
    Const
    NWDP_MODIFY_OP_NULL = 0;
    NWDP_MODIFY_OP_REPLACE = 1;
    NWDP_MODIFY_OP_ADD_VALUES = 2;
    NWDP_MODIFY_OP_REMOVE_VALUES = 3;
    NWDP_MODIFY_OP_SET_TO_DEFAULT = 4;
    NWDP_MODIFY_OP_REMOVE_ATTRIBUTE = 5;
    Type NWDPModifyOperatorEnum = 0..5;
    pNWDPModifyOperatorEnum = ^NWDPModifyOperatorEnum;
    (* Note: For NDPS, all attribute sets are qualified *)
    Type
        NWDPAttribute = Record
            attributeId  :   NWDPObjectIdentifier ;
            valueSet  :   NWDPAttributeValueSet ;
            qualifier  :   nuint32 ;
        End;
        pNWDPAttribute = ^NWDPAttribute;
    Type
        NWDPAttributeSet = Record
            itemCount  :   nuint ;
            itemPtr  :   pNWDPAttribute ;
        End;
        pNWDPAttributeSet = ^NWDPAttributeSet;
    Const
    NWDP_MATCH_EXACT = 0;
    NWDP_MATCH_CASE_INSENSITIVE = 1;
    NWDP_MATCH_SAME_LETTER = 2;
    NWDP_MATCH_APPROXIMATE = 3;
    Type NWDPSubstrMatchCriteriaEnum = 0..3;
    pNWDPSubstrMatchCriteriaEnum = ^NWDPSubstrMatchCriteriaEnum;
    Type
        NWDPSubStrings = Record
            attributeId  :   NWDPObjectIdentifier ;
            matchCriteria  :   NWDPSubstrMatchCriteriaEnum ;
            initialValueOption  :   NWDPAttributeValue ;
            anyValueSetOption  :   NWDPAttributeValueSet ;
            finalValueOption  :   NWDPAttributeValue ;
        End;
        pNWDPSubStrings = ^NWDPSubStrings;
    Const
    NWDP_PROBLEM_TYPE_STANDARD = 0;
    NWDP_PROBLEM_TYPE_EXTENDED = 1;
    Type NWDPProblemTypeEnum = 0..1;
    pNWDPProblemTypeEnum = ^NWDPProblemTypeEnum;
    Const
    NWDP_ACCESS_WRONG_OBJECT_CLASS = 0;
    NWDP_ACCESS_LACK_ACCESS_RIGHTS = 1;
    NWDP_ACCESS_CANT_INTERRUPT_JOB = 2;
    NWDP_ACCESS_WRONG_OBJECT_STATE = 3;
    NWDP_ACCESS_CLIENT_NOT_BOUND = 4;
    NWDP_ACCESS_NOT_AVAILABLE = 5;
    NWDP_ACCESS_NOTIF_SVC_NOT_CONN = 6;
    NWDP_ACCESS_PDS_NOT_CONNECTED = 7;
    Type NWDPAccessProblemEnum = 0..7;
    pNWDPAccessProblemEnum = ^NWDPAccessProblemEnum;
    Type
        NWDPAccessProblem = Record
            designator  :   NWDPProblemTypeEnum ;
            standardProblem  :   NWDPAccessProblemEnum ;  (* union statement *)
        End;
        pNWDPAccessProblem = ^NWDPAccessProblem;
    Type
        NWDPAccessError = Record
            problem  :   NWDPAccessProblem ;
            objectIdentification  :   NWDPObjectIdentification ;
            messageOptionPtr  :   pNWDPNameOrOid ;
        End;
        pNWDPAccessError = ^NWDPAccessError;
    Const
    NWDP_ATTR_INVALID_SYNTAX = 0;
    NWDP_ATTR_UNDEFINED_TYPE = 1;
    NWDP_ATTR_WRONG_MATCHING = 2;
    NWDP_ATTR_CONSTRAINT_VIOLATED = 3;
    NWDP_ATTR_UNSUPPORTED_TYPE = 4;
    NWDP_ATTR_ILLEGAL_MODIFICATION = 5;
    NWDP_ATTR_CONSIST_W_OTHER_ATTR = 6;
    NWDP_ATTR_UNDEFINED_ATTR_VALUE = 7;
    NWDP_ATTR_UNSUPPORTED_VALUE = 8;
    NWDP_ATTR_INVALID_NONCOMPUL_MOD = 9;
    NWDP_ATTR_PER_JOB_INADMISSIBLE = 10;
    NWDP_ATTR_NOT_MULTI_VALUED = 11;
    NWDP_ATTR_MANDATORY_OMITTED = 12;
    NWDP_ATTR_ILLEGAL_FOR_CLASS = 13;
    Type NWDPAttributeProblemEnum = 0..13;
    pNWDPAttributeProblemEnum = ^NWDPAttributeProblemEnum;
    Type
        NWDPAttributeProblem = Record
            designator  :   NWDPProblemTypeEnum ;
            standardProblem  :   NWDPAttributeProblemEnum ;  (* union statement *)
        End;
        pNWDPAttributeProblem = ^NWDPAttributeProblem;
    Type
        NWDPAttributeProblemItem = Record
            problem  :   NWDPAttributeProblem ;
            attribute  :   NWDPAttribute ;
            messageOptionPtr  :   pNWDPNameOrOid ;
        End;
        pNWDPAttributeProblemItem = ^NWDPAttributeProblemItem;
    Type
        NWDPAttributeError = Record
            problems : Record
                itemCount  :   nuint ;
                itemPtr  :   pNWDPAttributeProblemItem ;
            End;
            objectIdentification  :   NWDPObjectIdentification ;
        End;
        pNWDPAttributeError = ^NWDPAttributeError;
    Const
    NWDP_DOC_ACCESS_NOT_AVAILABLE = 0;
    NWDP_DOC_ACCESS_FIDELI_TIME_EXP = 1;
    NWDP_DOC_ACCESS_DENIED = 2;
    NWDP_DOC_ACCESS_UNKNOWN_DOC = 3;
    NWDP_DOC_ACCESS_NO_DOCS_IN_JOB = 4;
    Type NWDPDocAccessProblemEnum = 0..4;
    pNWDPDocAccessProblemEnum = ^NWDPDocAccessProblemEnum;
    Type
        NWDPDocAccessProblem = Record
            designator  :   NWDPProblemTypeEnum ;
            standardProblem  :   NWDPDocAccessProblemEnum ;  (* union statement *)
        End;
        pNWDPDocAccessProblem = ^NWDPDocAccessProblem;
    Type
        NWDPDocAccessError = Record
            problem  :   NWDPDocAccessProblem ;
            objectIdentification  :   NWDPObjectIdentification ;
            messageOptionPtr  :   pNWDPNameOrOid ;
        End;
        pNWDPDocAccessError = ^NWDPDocAccessError;
    Const
    NWDP_PRINTER_ERROR = 0;
    NWDP_PRINTER_NEEDS_ATTENTION = 1;
    NWDP_PRINTER_NEEDS_KEY_OPERATOR = 2;
    Type NWDPPrinterProblemEnum = 0..2;
    pNWDPPrinterProblemEnum = ^NWDPPrinterProblemEnum;
    Type
        NWDPPrinterProblem = Record
            designator  :   NWDPProblemTypeEnum ;
            standardProblem  :   NWDPPrinterProblemEnum ;  (* union statement *)
        End;
        pNWDPPrinterProblem = ^NWDPPrinterProblem;
    Type
        NWDPPrinterError = Record
            problem  :   NWDPPrinterProblem ;
            objectIdentification  :   NWDPObjectIdentification ;
            messageOptionPtr  :   pNWDPNameOrOid ;
        End;
        pNWDPPrinterError = ^NWDPPrinterError;
    Const
    NWDP_SECURITY_AUTHENTICATION = 0;
    NWDP_SECURITY_CREDENTIALS = 1;
    NWDP_SECURITY_RIGHTS = 2;
    NWDP_SECURITY_INVALID_PAC = 3;
    Type NWDPSecurityProblemEnum = 0..3;
    pNWDPSecurityProblemEnum = ^NWDPSecurityProblemEnum;
    Type
        NWDPSecurityProblem = Record
            designator  :   NWDPProblemTypeEnum ;
            standardProblem  :   NWDPSecurityProblemEnum ;  (* union statement *)
        End;
        pNWDPSecurityProblem = ^NWDPSecurityProblem;
    Type
        NWDPSecurityError = Record
            problem  :   NWDPSecurityProblem ;
            messageOptionPtr  :   pNWDPNameOrOid ;
        End;
        pNWDPSecurityError = ^NWDPSecurityError;
    Const
    NWDP_SELECTION_INVALID_ID = 0;
    NWDP_SELECTION_UNKNOWN_ID = 1;
    NWDP_SELECTION_OBJECT_EXISTS = 2;
    Type NWDPSelectionProblemEnum = 0..2;
    pNWDPSelectionProblemEnum = ^NWDPSelectionProblemEnum;
    Type
        NWDPSelectionProblem = Record
            designator  :   NWDPProblemTypeEnum ;
            standardProblem  :   NWDPSelectionProblemEnum ;  (* union statement *)
        End;
        pNWDPSelectionProblem = ^NWDPSelectionProblem;
    Type
        NWDPSelectionError = Record
            problem  :   NWDPSelectionProblem ;
            objectIdentification  :   NWDPObjectIdentification ;
            attributeOptionPtr  :   pNWDPAttribute ;
            messageOptionPtr  :   pNWDPNameOrOid ;
        End;
        pNWDPSelectionError = ^NWDPSelectionError;
    Const
    NWDP_SERVICE_SERVER_BUSY = 0;
    NWDP_SERVICE_SERVER_UNAVAILABLE = 1;
    NWDP_SERVICE_OPERATION_COMPLEX = 2;
    NWDP_SERVICE_RESOURCE_LIMIT = 3;
    NWDP_SERVICE_UNCLASS_SERVER_ERR = 4;
    NWDP_SERVICE_TOO_MANY_ITEM_LIST = 5;
    NWDP_SERVICE_RESOURCE_NOT_AVAIL = 6;
    NWDP_SERVICE_CANCEL_DOC_SUPPORT = 7;
    NWDP_SERVICE_MODIFY_DOC_SUPPORT = 8;
    NWDP_SERVICE_MULTI_DOC_SUPPORT = 9;
    NWDP_SERVICE_PARM_VAL_SUPPORT = 10;
    NWDP_SERVICE_INVALID_CHECKPOINT = 11;
    NWDP_SERVICE_CONTINUATN_CONTEXT = 12;
    NWDP_SERVICE_PAUSE_LIMIT_EXCEED = 13;
    NWDP_SERVICE_UNSUPPORTED_OP = 14;
    NWDP_SERVICE_NOTIF_SERVICE_ERR = 15;
    Type NWDPServiceProblemEnum = 0..15;
    pNWDPServiceProblemEnum = ^NWDPServiceProblemEnum;
    Type
        NWDPServiceProblem = Record
            designator  :   NWDPProblemTypeEnum ;
            standardProblem  :   NWDPServiceProblemEnum ;  (* union statement *)
        End;
        pNWDPServiceProblem = ^NWDPServiceProblem;
    Type
        NWDPServiceError = Record
            problem  :   NWDPServiceProblem ;
            objectIdentification  :   NWDPObjectIdentification ;
            attributeOptionPtr  :   pNWDPAttribute ;
            libError  :   nuint32 ;
            otherError  :   nuint32 ;
            otherError2  :   nuint32 ;
            messageOptionPtr  :   pNWDPNameOrOid ;
        End;
        pNWDPServiceError = ^NWDPServiceError;
    Const
    NWDP_UPDATE_NO_MODS_ALLOWED = 0;
    NWDP_UPDATE_INSUFFICIENT_RIGHTS = 1;
    NWDP_UPDATE_PREV_OP_INCOMPLETE = 2;
    NWDP_UPDATE_CANCEL_NOT_POSSIBLE = 3;
    Type NWDPUpdateProblemEnum = 0..3;
    pNWDPUpdateProblemEnum = ^NWDPUpdateProblemEnum;
    Type
        NWDPUpdateProblem = Record
            designator  :   NWDPProblemTypeEnum ;
            standardProblem  :   NWDPUpdateProblemEnum ;  (* union statement *)
        End;
        pNWDPUpdateProblem = ^NWDPUpdateProblem;
    Type
        NWDPUpdateError = Record
            problem  :   NWDPUpdateProblem ;
            objectIdentification  :   NWDPObjectIdentification ;
            messageOptionPtr  :   pNWDPNameOrOid ;
        End;
        pNWDPUpdateError = ^NWDPUpdateError;
    Const
    NWDP_ERROR_TYPE_SECURITY = 0;
    NWDP_ERROR_TYPE_SERVICE = 1;
    NWDP_ERROR_TYPE_ACCESS = 2;
    NWDP_ERROR_TYPE_PRINTER = 3;
    NWDP_ERROR_TYPE_SELECTION = 4;
    NWDP_ERROR_TYPE_DOCUMENT_ACCESS = 5;
    NWDP_ERROR_TYPE_ATTRIBUTE = 6;
    NWDP_ERROR_TYPE_UPDATE = 7;
    Type NWDPErrorTypeEnum = 0..7;
    pNWDPErrorTypeEnum = ^NWDPErrorTypeEnum;
    Type
        NWDPErrorReturn = Record
            designator  :   NWDPErrorTypeEnum ;
            securityError  :   NWDPSecurityError ;  (* union statement *)
        End;
        pNWDPErrorReturn = ^NWDPErrorReturn;
    Type
        NWDPCreds = Record
            name  :   NWDPText ;
            password : Record
                itemCount  :   nuint ;
                itemPtr  :   pnint8 ;
            End;
        End;
        pNWDPCreds = ^NWDPCreds;
    Type
        NWDPNdpsCred0 = Record
            serverNamePtr  :   pnstr ;
            connection  :   nuint16 ;
        End;
        pNWDPNdpsCred0 = ^NWDPNdpsCred0;
    Const
    NWDP_CREDENTIALS_SIMPLE = 0;
    NWDP_CREDENTIALS_CERTIFIED = 1;
    NWDP_CREDENTIALS_NDPS_0 = 2;
    Type NWDPCredentialsEnum = 0..2;
    pNWDPCredentialsEnum = ^NWDPCredentialsEnum;
    Type
        NWDPCredentials = Record
            designator  :   NWDPCredentialsEnum ;
            simple  :   NWDPCreds ;  (* union statement *)
        End;
        pNWDPCredentials = ^NWDPCredentials;
    (* Structure Definitions *)
    (* Global Variable Declarations *)
    (* Function Prototype Declarations *)
{$ELSE}
    {$IFDEF  N_DEBUG }
        (* TC error *)
    {$ENDIF}
{$ENDIF}


