(******************************************************************************

  %name:          nwdsdc.h %
  %version:       7 %
  %date_modified: Fri Jun  6 10:17:26 1997 %
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

{$IFNDEF  NWDSDC_H }
    {$DEFINE NWDSDC_H}
    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
    {$IFNDEF  NWDSTYPE_H }
        {$I nwdstype.inc}
    {$ENDIF}
    {$I npackon.inc}
    (* Directory Context Key names *)
    {$DEFINE DCK_FLAGS}
    Const DCK_FLAGS = 1;
    {$DEFINE DCK_CONFIDENCE}
    Const DCK_CONFIDENCE = 2;
    {$DEFINE DCK_NAME_CONTEXT}
    Const DCK_NAME_CONTEXT = 3;
    {$DEFINE DCK_TRANSPORT_TYPE}
    Const DCK_TRANSPORT_TYPE = 4;
    {$DEFINE DCK_REFERRAL_SCOPE}
    Const DCK_REFERRAL_SCOPE = 5;
    {$DEFINE DCK_LAST_CONNECTION}
    Const DCK_LAST_CONNECTION = 8;
    {$DEFINE DCK_LAST_SERVER_ADDRESS}
    Const DCK_LAST_SERVER_ADDRESS = 9;
    {$DEFINE DCK_LAST_ADDRESS_USED}
    Const DCK_LAST_ADDRESS_USED = 10;
    {$DEFINE DCK_TREE_NAME}
    Const DCK_TREE_NAME = 11;
    {$DEFINE DCK_DSI_FLAGS}
    Const DCK_DSI_FLAGS = 12;
    {$DEFINE DCK_NAME_FORM}
    Const DCK_NAME_FORM = 13;
    {$DEFINE DCK_NAME_CACHE_DEPTH}
    Const DCK_NAME_CACHE_DEPTH = 15;
    (* DCK_FLAGS bit values key *)
    {$DEFINE DCV_DEREF_ALIASES}
    Const DCV_DEREF_ALIASES = $00000001;
    {$DEFINE DCV_XLATE_STRINGS}
    Const DCV_XLATE_STRINGS = $00000002;
    {$DEFINE DCV_TYPELESS_NAMES}
    Const DCV_TYPELESS_NAMES = $00000004;
    {$DEFINE DCV_ASYNC_MODE}
    Const DCV_ASYNC_MODE = $00000008;
    {$DEFINE DCV_CANONICALIZE_NAMES}
    Const DCV_CANONICALIZE_NAMES = $00000010;
    {$DEFINE DCV_DEREF_BASE_CLASS}
    Const DCV_DEREF_BASE_CLASS = $00000040;
    {$DEFINE DCV_DISALLOW_REFERRALS}
    Const DCV_DISALLOW_REFERRALS = $00000080;
    (* values for DCK_CONFIDENCE key *)
    {$DEFINE DCV_LOW_CONF}
    Const DCV_LOW_CONF = 0;
    {$DEFINE DCV_MED_CONF}
    Const DCV_MED_CONF = 1;
    {$DEFINE DCV_HIGH_CONF}
    Const DCV_HIGH_CONF = 2;
    MAX_MESSAGE_LEN= ( 63 * 1024 ) ;
    DEFAULT_MESSAGE_LEN = ( 4 * 1024 );
    (* values for DCK_REFERRAL_SCOPE key *)
    {$DEFINE DCV_ANY_SCOPE}
    Const DCV_ANY_SCOPE = 0;
    {$DEFINE DCV_COUNTRY_SCOPE}
    Const DCV_COUNTRY_SCOPE = 1;
    {$DEFINE DCV_ORGANIZATION_SCOPE}
    Const DCV_ORGANIZATION_SCOPE = 2;
    {$DEFINE DCV_LOCAL_SCOPE}
    Const DCV_LOCAL_SCOPE = 3;
    (* values for DCK_DSI_FLAGS key *)
    {$DEFINE DSI_OUTPUT_FIELDS}
    Const DSI_OUTPUT_FIELDS = $00000001;
    {$DEFINE DSI_ENTRY_ID}
    Const DSI_ENTRY_ID = $00000002;
    {$DEFINE DSI_ENTRY_FLAGS}
    Const DSI_ENTRY_FLAGS = $00000004;
    {$DEFINE DSI_SUBORDINATE_COUNT}
    Const DSI_SUBORDINATE_COUNT = $00000008;
    {$DEFINE DSI_MODIFICATION_TIME}
    Const DSI_MODIFICATION_TIME = $00000010;
    {$DEFINE DSI_MODIFICATION_TIMESTAMP}
    Const DSI_MODIFICATION_TIMESTAMP = $00000020;
    {$DEFINE DSI_CREATION_TIMESTAMP}
    Const DSI_CREATION_TIMESTAMP = $00000040;
    {$DEFINE DSI_PARTITION_ROOT_ID}
    Const DSI_PARTITION_ROOT_ID = $00000080;
    {$DEFINE DSI_PARENT_ID}
    Const DSI_PARENT_ID = $00000100;
    {$DEFINE DSI_REVISION_COUNT}
    Const DSI_REVISION_COUNT = $00000200;
    {$DEFINE DSI_REPLICA_TYPE}
    Const DSI_REPLICA_TYPE = $00000400;
    {$DEFINE DSI_BASE_CLASS}
    Const DSI_BASE_CLASS = $00000800;
    {$DEFINE DSI_ENTRY_RDN}
    Const DSI_ENTRY_RDN = $00001000;
    {$DEFINE DSI_ENTRY_DN}
    Const DSI_ENTRY_DN = $00002000;
    {$DEFINE DSI_PARTITION_ROOT_DN}
    Const DSI_PARTITION_ROOT_DN = $00004000;
    {$DEFINE DSI_PARENT_DN}
    Const DSI_PARENT_DN = $00008000;
    {$DEFINE DSI_PURGE_TIME}
    Const DSI_PURGE_TIME = $00010000;
    {$DEFINE DSI_DEREFERENCE_BASE_CLASS}
    Const DSI_DEREFERENCE_BASE_CLASS = $00020000;
    (* values for DCK_NAME_FORM key *)
    {$DEFINE DCV_NF_PARTIAL_DOT}
    Const DCV_NF_PARTIAL_DOT = 1;
    {$DEFINE DCV_NF_FULL_DOT}
    Const DCV_NF_FULL_DOT = 2;
    {$DEFINE DCV_NF_SLASH}
    Const DCV_NF_SLASH = 3;
    Type NWDSContextHandle  =   nuint32 ;
    {$IFDEF  N_PLAT_NLM }
        Type
            NWDSIPXNetworkAddr = Record
                addressType  :   uint32 ;
                addressLength  :   uint32 ;
                address  :  Array[0..11] Of  uint8 ;
            End;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    Function NWDSCreateContext : NWDSContextHandle;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSDuplicateContext (
        oldContext  :   NWDSContextHandle 
    ) : NWDSContextHandle;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSFreeContext (
        context  :   NWDSContextHandle 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetContext (
        context  :   NWDSContextHandle ;
        key  :   nint ;
        value  :   nptr 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSSetContext (
        context  :   NWDSContextHandle ;
        key  :   nint ;
        value  :   nptr 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSCreateContextHandle (
        Var newHandle  : NWDSContextHandle
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSDuplicateContextHandle (
        srcContextHandle  :   NWDSContextHandle ;
        Var destContextHandle  : NWDSContextHandle
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

