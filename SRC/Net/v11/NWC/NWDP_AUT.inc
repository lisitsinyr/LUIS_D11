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
//บ Source module name: NWDP_AUT.H                                           บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Library VeRsIoN=1.0.0                                                    บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

(* Inclusion Control *)

{$IFNDEF  NWDP_AUT_H }
    {$DEFINE NWDP_AUT_H}
    (* Standard Library Header Includes *)
    {$IFNDEF  NWDP_ATR_H }
        {$I nwdp_atr.inc}
    {$ENDIF}
    (* Header Includes *)
    (* Manifest Constant Definitions *)
    {$DEFINE NWDP_CARDINAL_64_MAX_BYTES}
    Const NWDP_CARDINAL_64_MAX_BYTES = 42;
    (* Macro Definitions *)
    (* Type Definitions *)
    (* Callback Definitions *)
    Type NWDPAUtilAttributeListCallback = Function (
        accessorRef  :   NWDPAccessorRef ;
        callerDefinedParam  :   nparam ;
        totalCallsToBeMade  :   nint ;
        currentCallCount  :   nint ;
        attributePtr  :   pNWDPAttribute 
    ) : nint;
    Type NWDPAUtilAttrValueListCallback = Function (
        accessorRef  :   NWDPAccessorRef ;
        callerDefinedParam  :   nparam ;
        totalCallsToBeMade  :   nint ;
        currentCallCount  :   nint ;
        valuePtr  :   pNWDPAttributeValue 
    ) : nint;
    (* Global Variable Declarations *)
    (* Function Prototype Declarations *)
    Function NWDPAUtilAddAttributeWithValues (
        accessorRef  :   NWDPAccessorRef ;
        destAvpRef  :   NWDPASAVPRef ;
        srcAttributePtr  :   pNWDPAttribute ;
        qualifierPtr  :   pnuint32 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPAUtilAppendAttrSet (
        accessorRef  :   NWDPAccessorRef ;
        destAvpRef  :   NWDPASAVPRef ;
        srcAttrSetPtr  :   pNWDPAttributeSet 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPAUtilAppendAttrValueSet (
        accessorRef  :   NWDPAccessorRef ;
        destAttrValueSetPtr  :   pNWDPAttributeValueSet ;
        srcAttrValueSetPtr  :   pNWDPAttributeValueSet 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPAUtilAsciiToCardinal64 (
        accessorRef  :   NWDPAccessorRef ;
        numericDecimalStringPtr  :   pnstr ;
        valuePtr  :   pNWDPAttributeValue 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPAUtilCardinal64ToAscii (
        accessorRef  :   NWDPAccessorRef ;
        valuePtr  :   pNWDPAttributeValue ;
        useSeparators  :   nbool ;
        sizeOfStringBuffer  :   nuint ;
        stringBufferPtr  :   pnstr ;
        sizeOfResultPtr  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPAUtilCompareDataType (
        accessorRef  :   NWDPAccessorRef ;
        dataType  :   NWDPAVTEnum ;
        data1Ptr  :   nptr ;
        data2Ptr  :   nptr 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPAUtilCompareAttrValue (
        accessorRef  :   NWDPAccessorRef ;
        attrValue1Ptr  :   pNWDPAttributeValue ;
        attrValue2Ptr  :   pNWDPAttributeValue 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPAUtilDupAttribute (
        accessorRef  :   NWDPAccessorRef ;
        destAttributePtr  :   pNWDPAttribute ;
        srcAttributePtr  :   pNWDPAttribute 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPAUtilDupDataType (
        accessorRef  :   NWDPAccessorRef ;
        dataType  :   NWDPAVTEnum ;
        destPtr  :   nptr ;
        srcPtr  :   nptr 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPAUtilDupAttrValue (
        accessorRef  :   NWDPAccessorRef ;
        destAttrValuePtr  :   pNWDPAttributeValue ;
        srcAttrValuePtr  :   pNWDPAttributeValue 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPAUtilFreeAttribute (
        accessorRef  :   NWDPAccessorRef ;
        attributePtr  :   pNWDPAttribute 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPAUtilFreeAttrValueSet (
        accessorRef  :   NWDPAccessorRef ;
        attrValueSetPtr  :   pNWDPAttributeValueSet 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPAUtilFreeDataType (
        accessorRef  :   NWDPAccessorRef ;
        dataType  :   NWDPAVTEnum ;
        dataPtr  :   nptr 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPAUtilFreeAttrValue (
        accessorRef  :   NWDPAccessorRef ;
        attrValuePtr  :   pNWDPAttributeValue 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPAUtilListAttributes (
        accessorRef  :   NWDPAccessorRef ;
        attributeSetPtr  :   pNWDPAttributeSet ;
        listCallback  :   NWDPAUtilAttributeListCallback ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPAUtilListAttrValues (
        accessorRef  :   NWDPAccessorRef ;
        attributePtr  :   pNWDPAttribute ;
        listCallback  :   NWDPAUtilAttrValueListCallback ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPAUtilMergeAttrSet (
        accessorRef  :   NWDPAccessorRef ;
        destAvpRef  :   NWDPASAVPRef ;
        srcAttrSetPtr  :   pNWDPAttributeSet 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPAUtilRemoveAllAttributes (
        accessorRef  :   NWDPAccessorRef ;
        attrSetPtr  :   pNWDPAttributeSet 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
{$ELSE}
    {$IFDEF  N_DEBUG }
        (* TC error *)
    {$ENDIF}
{$ENDIF}

