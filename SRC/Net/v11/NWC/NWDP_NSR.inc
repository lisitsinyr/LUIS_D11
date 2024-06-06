(*
//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
//บ (c) 1995-1997 Novell, Inc.  All rights reserved.                         บ
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
//บ Source module name: NWDP_NSR.H                                           บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Library VeRsIoN=1.0.0                                                    บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

(* Inclusion Control *)

{$IFNDEF  NWDP_NSR_H }
    {$DEFINE NWDP_NSR_H}
    (* Standard Library Header Includes *)
    (* Header Includes *)
    {$IFNDEF  NWDP_LIB_H }
        {$I nwdp_lib.inc}
    {$ENDIF}
    {$IFNDEF  NWDP_OID_H }
        {$I nwdp_oid.inc}
    {$ENDIF}
    {$IFNDEF  NWDP_ATR_H }
        {$I nwdp_atr.inc}
    {$ENDIF}
    (* Manifest Constant Definitions *)
    (*
   // Object name is 63 characters which is 128 bytes, worst case
   *)
    {$DEFINE NWDP_NSRV_OBJECT_NAME_CHARS}
    Const NWDP_NSRV_OBJECT_NAME_CHARS = 63;
    (* TC #define NWDP_NSRV_OBJECT_NAME_BYTES ( ( NWDP_NSRV_OBJECT_NAME_CHARS + 1 ) * 2 )  *)
    {$IFNDEF  NWDP_NSRV_MAX_DN_CHARS }
        {$DEFINE NWDP_NSRV_MAX_DN_CHARS}
        Const NWDP_NSRV_MAX_DN_CHARS = 256;
        (* TC #define NWDP_NSRV_MAX_DN_BYTES ( ( NWDP_NSRV_MAX_DN_CHARS + 1 ) * 2 )  *)
        {$DEFINE NWDP_NSRV_MAX_TREE_CHARS}
        Const NWDP_NSRV_MAX_TREE_CHARS = 32;
        (* TC #define NWDP_NSRV_MAX_TREE_BYTES ( ( NWDP_NSRV_MAX_TREE_CHARS + 1 ) * 2 )  *)
    {$ENDIF}
    (*
   // Broker creation flags
   *)
    {$DEFINE NWDP_NSRV_FLG_ENABLE_REGIST_SVC}
    Const NWDP_NSRV_FLG_ENABLE_REGIST_SVC = $00000001;
    {$DEFINE NWDP_NSRV_FLG_ENABLE_RESMAN_SVC}
    Const NWDP_NSRV_FLG_ENABLE_RESMAN_SVC = $00000002;
    {$DEFINE NWDP_NSRV_FLG_ENABLE_NOTIFY_SVC}
    Const NWDP_NSRV_FLG_ENABLE_NOTIFY_SVC = $00000004;
    (*
   // Object Removal Flags
   *)
    {$DEFINE NWDP_NSRV_FLG_DONT_DEL_OBJECT}
    Const NWDP_NSRV_FLG_DONT_DEL_OBJECT = $00000001;
    (* Macro Definitions *)
    (* Type Definitions *)
    {$DEFINE N_PACK_1}
    {$I npackon.inc}
    (*
   // Object Types which will be available through this API
   *)
    Const
    NWDP_NSRV_OT_ANY_MASK = -1;
    NWDP_NSRV_OT_BROKER = 1;
    NWDP_NSRV_OT_PRINTER = 2;
    NWDP_NSRV_OT_MANAGER = 4;
    Type NWDPNSrvObjType_T = -1..4;
    NWDPNSrvObjType = NWDPNSrvObjType_T;
    pNWDPNSrvObjType = ^NWDPNSrvObjType_T;
    Type
        NWDPNSrvObjListItem = Record
            objectType  :   NWDPNSrvObjType ;
            objectName16  :  Array[0..NWDP_NSRV_OBJECT_NAME_CHARS+1-1] Of  nchar16 ;
        End;
        pNWDPNSrvObjListItem = ^NWDPNSrvObjListItem;
    {$I npackoff.inc}
    (* Callback Definitions *)
    Type NWDPNSrvObjListCallback = Function (
        accessorRef  :   NWDPAccessorRef ;
        callerDefinedParam  :   nparam ;
        totalCallsToBeMade  :   nint ;
        currentCallCount  :   nint ;
        itemReceivedPtr  :   pNWDPNSrvObjListItem 
    ) : nint;
    (* Global Variable Declarations *)
    (* Function Prototype Declarations *)
    Function NWDPNSrvAddBrokerObject (
        accessorRef  :   NWDPAccessorRef ;
        objectRDN16Ptr  :   pnstr16 ;
        (*
   // The next two parameters may be NULL if
   // NWDP_NSRV_FLG_ENABLE_RESMAN_SVC not present in 
   // 'flags' parameter. 
   *)
        resourceMgrVolObjectRDN16Ptr  :   pnstr16 ;
        resourceMgrDatabasePath16Ptr  :   pnstr16 ;
        nsObjRefPtr  :   pNWDPNSrvObjRef ;
        flags  :   nuint32 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNSrvAddPrinterObject (
        accessorRef  :   NWDPAccessorRef ;
        objectRDN16Ptr  :   pnstr16 ;
        nsObjRefPtr  :   pNWDPNSrvObjRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNSrvAddPSMObject (
        accessorRef  :   NWDPAccessorRef ;
        objectRDN16Ptr  :   pnstr16 ;
        databaseVolObjectRDN16Ptr  :   pnstr16 ;
        nsObjRefPtr  :   pNWDPNSrvObjRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNSrvCompareNDSObjectNames (
        accessorRef  :   NWDPAccessorRef ;
        treeName16Ptr  :   pnstr16 ;
        object1Name16Ptr  :   pnstr16 ;
        object2Name16Ptr  :   pnstr16 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNSrvCreateRef (
        accessorRef  :   NWDPAccessorRef ;
        objectRDN16Ptr  :   pnstr16 ;
        objectType  :   NWDPNSrvObjType ;
        nsObjRefPtr  :   pNWDPNSrvObjRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNSrvDestroyRef (
        accessorRef  :   NWDPAccessorRef ;
        nsObjRefPtr  :   pNWDPNSrvObjRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNSrvGetNativeNDSContext (
        accessorRef  :   NWDPAccessorRef ;
        contextHandlePtr  :   pnuint32 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNSrvListObjects (
        accessorRef  :   NWDPAccessorRef ;
        objectTypeFilter  :   NWDPNSrvObjType ;
        listCallback  :   NWDPNSrvObjListCallback ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNSrvMakeFQNFromObject (
        accessorRef  :   NWDPAccessorRef ;
        objectRDN16Ptr  :   pnstr16 ;
        sizeOfBuffer  :   nuint ;
        fqnBufferPtr  :   pNWDPNSrvFQNBuffer ;
        sizeOfResultPtr  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNSrvModifyAttrs (
        accessorRef  :   NWDPAccessorRef ;
        nsObjRef  :   NWDPNSrvObjRef ;
        modifyRef  :   NWDPAttrSetRef ;
        nsrvOperator  :   NWDPModifyOperatorEnum 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNSrvObjGetAttributeSet (
        accessorRef  :   NWDPAccessorRef ;
        nsObjRef  :   NWDPNSrvObjRef ;
        requestedOidSetRef  :   NWDPOidSetRef ;
        resultAttrSetRefPtr  :   pNWDPAttrSetRef ;
        resultAvpRefPtr  :   pNWDPASAVPRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNSrvQueryRoleMembership (
        accessorRef  :   NWDPAccessorRef ;
        nsObjRef  :   NWDPNSrvObjRef ;
        memberRDN16Ptr  :   pnstr16 ;
        isAManager  :   pnbool ;
        isAnOperator  :   pnbool ;
        isAUser  :   pnbool 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNSrvRemoveObject (
        accessorRef  :   NWDPAccessorRef ;
        nsObjRefPtr  :   pNWDPNSrvObjRef ;
        (*
   // The flag: NWDP_NSRV_FLG_DONT_DEL_OBJECT is intended to cause 
   // only the cleanup of object creation side effects. Actual object
   // deletion in the Name Service is left to the caller. The object must
   // still exist when this call is made.
   *)
        flags  :   nuint32 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNSrvSetNativeNDSContext (
        accessorRef  :   NWDPAccessorRef ;
        contextHandle  :   nuint32 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNSrvValidateObjectRef (
        accessorRef  :   NWDPAccessorRef ;
        objectRef  :   NWDPNSrvObjRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
{$ELSE}
    {$IFDEF  N_DEBUG }
        (* TC error *)
    {$ENDIF}
{$ENDIF}


