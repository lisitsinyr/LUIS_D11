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
//บ Source module name: NWDP_ATR.H                                           บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Library VeRsIoN=1.0.0                                                    บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

(* Inclusion Control *)

{$IFNDEF  NWDP_ATR_H }
    {$DEFINE NWDP_ATR_H}
    (* Standard Library Header Includes *)
    {$IFNDEF  NWDP_LIB_H }
        {$I nwdp_lib.inc}
    {$ENDIF}
    {$IFNDEF  NWDP_ATT_H }
        {$I nwdp_att.inc}
    {$ENDIF}
    (* Header Includes *)
    (* Manifest Constant Definitions *)
    Const
      NWDP_AS_DEFAULT_SET_SIZE = ( ( nuint ) - 1 );
    (* Macro Definitions *)
    (* Type Definitions *)
    {$DEFINE N_PACK_1}
    {$I npackon.inc}
    Type
        NWDPAttrSetStruct = Record
            attrSet  :   NWDPAttributeSet ;
            reserved1  :   nuint ;
            reserved2  :   nptr ;
            reserved3  :   nuint ;
        End;
        pNWDPAttrSetStruct = ^NWDPAttrSetStruct;
    (*
   // Attribute and Value pointer (AVP) control block
   *)
    Type
        NWDPASAVPStruct = Record
            attrSetRef  :   NWDPAttrSetRef ;
            attrPtr  :   pNWDPAttribute ;
            valuePtr  :   pNWDPAttributeValue ;
        End;
        pNWDPASAVPStruct = ^NWDPASAVPStruct;
    Type
        NWDPASAttributeListItem = Record
            attributeIdPtr  :   pNWDPOid ;
            qualifier  :   nuint32 ;
            avpRef  :   NWDPASAVPRef ;
        End;
        pNWDPASAttributeListItem = ^NWDPASAttributeListItem;
    Type
        NWDPASMODObjectListItem = Record
            objectIdentPtr  :   pNWDPObjectIdentification ;
            attrSetPtr  :   pNWDPAttributeSet ;
            objectClassPtr  :   pNWDPOid ;
        End;
        pNWDPASMODObjectListItem = ^NWDPASMODObjectListItem;
    Type
        NWDPASSelector = Record
            scope  :   nuint ;
            objectIdentSeq  :   NWDPObjectIdentificationSeq ;
            filterRef  :   NWDPFilterRef ;
            timeLimit  :   nint32 ;
            countLimit  :   nint32 ;
        End;
        pNWDPASSelector = ^NWDPASSelector;
    {$I npackoff.inc}
    (* Callback Definitions *)
    Type NWDPASAttributeListCallback = Function (
        accessorRef  :   NWDPAccessorRef ;
        callerDefinedParam  :   nparam ;
        totalCallsToBeMade  :   nint ;
        currentCallCount  :   nint ;
        attributeListItemPtr  :   pNWDPASAttributeListItem 
    ) : nint;
    Type NWDPASAttrValueListCallback = Function (
        accessorRef  :   NWDPAccessorRef ;
        callerDefinedParam  :   nparam ;
        totalCallsToBeMade  :   nint ;
        currentCallCount  :   nint ;
        avpRef  :   NWDPASAVPRef 
    ) : nint;
    Type NWDPASMODObjectListCallback = Function (
        accessorRef  :   NWDPAccessorRef ;
        callerDefinedParam  :   nparam ;
        totalCallsToBeMade  :   nint ;
        currentCallCount  :   nint ;
        objectPtr  :   pNWDPASMODObjectListItem 
    ) : nint;
    (* Global Variable Declarations *)
    (* Function Prototype Declarations *)
    Function NWDPASAddAttribute (
        accessorRef  :   NWDPAccessorRef ;
        avpRef  :   NWDPASAVPRef ;
        attributeIdPtr  :   pNWDPOid ;
        qualifierPtr  :   pnuint32 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPASAddAttrValue (
        accessorRef  :   NWDPAccessorRef ;
        avpRef  :   NWDPASAVPRef ;
        attributeIdPtr  :   pNWDPOid ;
        valuePtr  :   pNWDPAttributeValue 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPASCreateRef (
        accessorRef  :   NWDPAccessorRef ;
        sizeOfAttrSet  :   nuint ;
        attrSetRefPtr  :   pNWDPAttrSetRef ;
        avpRefPtr  :   pNWDPASAVPRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPASCreateRefBasedOnSet (
        accessorRef  :   NWDPAccessorRef ;
        attributeSetPtr  :   pNWDPAttributeSet ;
        attrSetRefPtr  :   pNWDPAttrSetRef ;
        avpRefPtr  :   pNWDPASAVPRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPASListAttributes (
        accessorRef  :   NWDPAccessorRef ;
        avpRef  :   NWDPASAVPRef ;
        listCallback  :   NWDPASAttributeListCallback ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPASListAttrValues (
        accessorRef  :   NWDPAccessorRef ;
        avpRef  :   NWDPASAVPRef ;
        attributeIdPtr  :   pNWDPOid ;
        listCallback  :   NWDPASAttrValueListCallback ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPASMakeAVPRef (
        accessorRef  :   NWDPAccessorRef ;
        attrSetRef  :   NWDPAttrSetRef ;
        avpRef  :   NWDPASAVPRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPASModifyAttrValue (
        accessorRef  :   NWDPAccessorRef ;
        avpRef  :   NWDPASAVPRef ;
        attributeIdPtr  :   pNWDPOid ;
        oldValuePtr  :   pNWDPAttributeValue ;
        newValuePtr  :   pNWDPAttributeValue 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPASReleaseRef (
        accessorRef  :   NWDPAccessorRef ;
        attrSetRefPtr  :   pNWDPAttrSetRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPASRemoveAttribute (
        accessorRef  :   NWDPAccessorRef ;
        avpRef  :   NWDPASAVPRef ;
        attributeIdPtr  :   pNWDPOid 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPASRemoveAttrValue (
        accessorRef  :   NWDPAccessorRef ;
        avpRef  :   NWDPASAVPRef ;
        attributeIdPtr  :   pNWDPOid ;
        valuePtr  :   pNWDPAttributeValue 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPASSetAVPByAttributeId (
        accessorRef  :   NWDPAccessorRef ;
        avpRef  :   NWDPASAVPRef ;
        attributeIdPtr  :   pNWDPOid 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPASSetModifyOperators (
        accessorRef  :   NWDPAccessorRef ;
        avpRef  :   NWDPASAVPRef ;
        operation  :   NWDPModifyOperatorEnum ;
        applyToAll  :   nbool 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPASUseRef (
        accessorRef  :   NWDPAccessorRef ;
        attrSetRef  :   NWDPAttrSetRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPASValidateRef (
        accessorRef  :   NWDPAccessorRef ;
        attrSetRef  :   NWDPAttrSetRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
{$ELSE}
    {$IFDEF  N_DEBUG }
        (* TC error *)
    {$ENDIF}
{$ENDIF}

