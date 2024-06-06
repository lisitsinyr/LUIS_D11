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
//บ Source module name: NWDP_OID.H                                           บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Library VeRsIoN=1.0.0                                                    บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

(* Inclusion Control *)

{$IFNDEF  NWDP_OID_H }
    {$DEFINE NWDP_OID_H}
    (* Standard Library Header Includes *)
    (* Header Includes *)
    {$IFNDEF  NWDP_LIB_H }
        {$I nwdp_lib.inc}
    {$ENDIF}
    {$IFNDEF  NWDP_WKO_OGH }
        {$I nwdp_wko.inc}
    {$ENDIF}
    {$IFNDEF  NWDP_ATT_H }
        {$I nwdp_att.inc}
    {$ENDIF}
    (* Manifest Constant Definitions *)
    (*
   // The default oid Set size. 
   *)
    {$DEFINE NWDP_OID_SET_SIZE}
    Const NWDP_OID_SET_SIZE = 8;
    (* Macro Definitions *)
    (* Type Definitions *)
    {$DEFINE N_PACK_1}
    {$I npackon.inc}
    (*
   // Language numbers inside the library
   *)
    Const
    NWDP_LID_DEFAULT = -1;
    NWDP_LID_CANADIAN_FRENCH = 0;
    NWDP_LID_CHINESE = 1;
    NWDP_LID_DANISH = 2;
    NWDP_LID_DUTCH = 3;
    NWDP_LID_ENGLISH = 4;
    NWDP_LID_FINNISH = 5;
    NWDP_LID_FRENCH = 6;
    NWDP_LID_GERMAN = 7;
    NWDP_LID_ITALIAN = 8;
    NWDP_LID_JAPANESE = 9;
    NWDP_LID_KOREAN = 10;
    NWDP_LID_NORWEGIAN = 11;
    NWDP_LID_PORTUGUESE = 12;
    NWDP_LID_RUSSIAN = 13;
    NWDP_LID_SPANISH = 14;
    NWDP_LID_SWEDISH = 15;
    NWDP_LID_CHINESE_TRAD = 16;
    NWDP_LID_POLISH = 17;
    NWDP_LID_PORTUGUESE_PORT = 18;
    NWDP_LID_SPANISH_SPAIN = 19;
    NWDP_LID_HUNGARIAN = 20;
    NWDP_LID_CZECH = 21;
    NWDP_LID_FJP = 98;
    NWDP_LID_FEU = 99;
    Type NWDPLanguageId = -1..99;
    pNWDPLanguageId = ^NWDPLanguageId;
    (*
   // Format Id of the buffer returned by NWDPOidInterpretRef
   // 
   // NWDP_ITPF_STRING              represents a zero terminated single-byte 
   //                                  ASCII string.
   // NWDP_ITPF_NUINT32_AND_STRING  represents a 4 byte unsigned integer 
   //                                  followed immediately by a zero
   //                                  terminated ASCII string.
   *)
    Const
    NWDP_ITPF_STRING = 0;
    NWDP_ITPF_NUINT32_AND_STRING = 1;
    Type NWDPInterpretFormat_T = 0..1;
    NWDPInterpretFormat = NWDPInterpretFormat_T;
    pNWDPInterpretFormat = ^NWDPInterpretFormat_T;
    (*
   // OID Kinds so we know whether the prefix was "id-oc-","id-att-",
   // "id-vc-", or "id-val-" etc.
   *)
    Const
    NWDP_OK_OBJECT_CLASS = 0;
    NWDP_OK_VALUE_CLASS = 1;
    NWDP_OK_ATTRIBUTE = 2;
    NWDP_OK_VALUE = 3;
    Type NWDPOidKind_T = 0..3;
    NWDPOidKind = NWDPOidKind_T;
    pNWDPOidKind = ^NWDPOidKind_T;
    (*
   // List Item definition for NWDPOidListRefValues
   *)
    Type
        NWDPOidValueListItem = Record
            enumValue  :   nint32 ;
            oidInterpretBufferPtr  :   pnuint8 ;
            sizeOfResult  :   nuint ;
            formatId  :   NWDPInterpretFormat ;
        End;
        pNWDPOidValueListItem = ^NWDPOidValueListItem;
    {$I npackoff.inc}
    (* Callback Definitions *)
    Type NWDPOidValueListCallback = Function (
        accessorRef  :   NWDPAccessorRef ;
        callerDefinedParam  :   nparam ;
        totalCallsToBeMade  :   nint ;
        currentCallCount  :   nint ;
        itemReceivedPtr  :   pNWDPOidValueListItem 
    ) : nint;
    Type NWDPOidSetListCallback = Function (
        accessorRef  :   NWDPAccessorRef ;
        callerDefinedParam  :   nparam ;
        totalCallsToBeMade  :   nint ;
        currentCallCount  :   nint ;
        oidPtr  :   pNWDPOid 
    ) : nint;
    (* Global Variable Declarations *)
    (* Function Prototype Declarations *)
    Function NWDPOidCmp (
        accessorRef  :   NWDPAccessorRef ;
        oid1Ptr  :   pNWDPOid ;
        oid2Ptr  :   pNWDPOid 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPOidCreateRefBasedOnASCII (
        accessorRef  :   NWDPAccessorRef ;
        oidASCIIStringPtr  :   pnstr ;
        oidRefPtr  :   pNWDPOidRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPOidCreateRefBasedOnOID (
        accessorRef  :   NWDPAccessorRef ;
        oidPtr  :   pNWDPOid ;
        oidRefPtr  :   pNWDPOidRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPOidCreateRefBasedOnString (
        accessorRef  :   NWDPAccessorRef ;
        oidInterpretPtr  :   pnstr ;
        languageId  :   NWDPLanguageId ;
        oidKind  :   NWDPOidKind ;
        oidRefPtr  :   pNWDPOidRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPOidGetAttrCharacteristics (
        accessorRef  :   NWDPAccessorRef ;
        oidRef  :   NWDPOidRef ;
        attrTypeEnumPtr  :   pNWDPAVTEnum ;
        isMultiValuedPtr  :   pnbool ;
        hasEnumeratedValuesPtr  :   pnbool 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPOidInterpretRef (
        accessorRef  :   NWDPAccessorRef ;
        oidRef  :   NWDPOidRef ;
        languageId  :   NWDPLanguageId ;
        sizeOfBuffer  :   nuint ;
        oidInterpretBufferPtr  :   pnuint8 ;
        sizeOfResultPtr  :   pnuint ;
        formatIdPtr  :   pNWDPInterpretFormat 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPOidInterpretRefAsASCII (
        accessorRef  :   NWDPAccessorRef ;
        oidRef  :   NWDPOidRef ;
        sizeOfBuffer  :   nuint ;
        oidASCIIBufferPtr  :   pnstr ;
        sizeOfResultPtr  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPOidInterpretRefValue (
        accessorRef  :   NWDPAccessorRef ;
        oidRef  :   NWDPOidRef ;
        enumValue  :   nint32 ;
        languageId  :   NWDPLanguageId ;
        sizeOfBuffer  :   nuint ;
        oidInterpretBufferPtr  :   pnuint8 ;
        sizeOfResultPtr  :   pnuint ;
        formatIdPtr  :   pNWDPInterpretFormat 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPOidInterpretRefWithClosest (
        accessorRef  :   NWDPAccessorRef ;
        oidRef  :   NWDPOidRef ;
        languageId  :   NWDPLanguageId ;
        sizeOfBuffer  :   nuint ;
        oidInterpretBufferPtr  :   pnuint8 ;
        sizeOfResultPtr  :   pnuint ;
        formatIdPtr  :   pNWDPInterpretFormat 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPOidListRefValues (
        accessorRef  :   NWDPAccessorRef ;
        oidRef  :   NWDPOidRef ;
        languageId  :   NWDPLanguageId ;
        listCallback  :   NWDPOidValueListCallback ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPOidMakeOidPtrFromOidRef (
        oidRef  :   NWDPOidRef 
    ) : pNWDPOid;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPOidReleaseRef (
        accessorRef  :   NWDPAccessorRef ;
        oidRefPtr  :   pNWDPOidRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPOidValidateRef (
        accessorRef  :   NWDPAccessorRef ;
        oidRef  :   NWDPOidRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (*
// Oid Set calls
*)
    Function NWDPOSAddOid (
        accessorRef  :   NWDPAccessorRef ;
        oidSetRef  :   NWDPOidSetRef ;
        oidPtr  :   pNWDPOid 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPOSCreateRef (
        accessorRef  :   NWDPAccessorRef ;
        sizeOfOidSet  :   nuint ;
        oidSetRefPtr  :   pNWDPOidSetRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPOSListOids (
        accessorRef  :   NWDPAccessorRef ;
        oidSetRef  :   NWDPOidSetRef ;
        listCallback  :   NWDPOidSetListCallback ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPOSReleaseRef (
        accessorRef  :   NWDPAccessorRef ;
        oidSetRefPtr  :   pNWDPOidSetRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPOSRemoveOid (
        accessorRef  :   NWDPAccessorRef ;
        oidSetRef  :   NWDPOidSetRef ;
        oidPtr  :   pNWDPOid 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPOSUseRef (
        accessorRef  :   NWDPAccessorRef ;
        oidSetRef  :   NWDPOidSetRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPOSValidateRef (
        accessorRef  :   NWDPAccessorRef ;
        oidSetRef  :   NWDPOidSetRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
{$ELSE}
    {$IFDEF  N_DEBUG }
        (* TC error *)
    {$ENDIF}
{$ENDIF}


