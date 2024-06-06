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
//บ Source module name: NWDP_RES.H                                           บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Library VeRsIoN=1.0.0                                                    บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

(* Inclusion Control *)

{$IFNDEF  NWDP_RES_H }
    {$DEFINE NWDP_RES_H}
    (* Standard Library Header Includes *)
    {$IFNDEF _STRUCT_TM}
{$DEFINE _STRUCT_TM}
Type tm = Record
tm_sec : integer;
tm_min : integer;
tm_hour : integer;
tm_mday : integer;
tm_mon : integer;
tm_year : integer;
tm_wday : integer;
tm_yday : integer;
tm_isdst : integer;
End;
{$ENDIF}

    {$IFNDEF  NWDP_LIB_H }
        {$I nwdp_lib.inc}
    {$ENDIF}
    {$IFNDEF  NWDP_RSM_H }
        {$I nwdp_rsm.inc}
    {$ENDIF}
    (* Header Includes *)
    (* Manifest Constant Definitions *)
    (* Macro Definitions *)
    (* Type Definitions *)
    {$DEFINE N_PACK_1}
    {$I npackon.inc}
    (*
// List Resource file input structures
*)
    Type
        NWDPResListFontTypes = Record
            fontType  :   NWDPFontTypeEnum ;
            osType  :   NWDPOSTypeEnum ;
        End;
        pNWDPResListFontTypes = ^NWDPResListFontTypes;
    Type
        NWDPResListDrvFiles = Record
            osType  :   NWDPOSTypeEnum ;
            printerType16Ptr  :   pnstr16 ;
            printerMfr16Ptr  :   pnstr16 ;
            infFileName16Ptr  :   pnstr16 ;
            printerIdPtr  :   pNWDPOctetString ;
        End;
        pNWDPResListDrvFiles = ^NWDPResListDrvFiles;
    Type
        NWDPResListDefFiles = Record
            vendorDir16Ptr  :   pnstr16 ;
            printerType16Ptr  :   pnstr16 ;
            printerMfr16Ptr  :   pnstr16 ;
            infFileName16Ptr  :   pnstr16 ;
            printerIdPtr  :   pNWDPOctetString ;
        End;
        pNWDPResListDefFiles = ^NWDPResListDefFiles;
    Type
        NWDPResListFontFiles = Record
            osType  :   NWDPOSTypeEnum ;
            fontType  :   NWDPFontTypeEnum ;
            fontName16Ptr  :   pnstr16 ;
        End;
        pNWDPResListFontFiles = ^NWDPResListFontFiles;
    Type
        NWDPResUnicodeSet = Record
            setCount  :   nint ;
            setItem16Ptr  :   pnstr16 ;
        End;
        pNWDPResUnicodeSet = ^NWDPResUnicodeSet;
    (*
  // Resource file list callback item types
  *)
    Type
        NWDPResListCallbackItem = Record
            listType  :   NWDPResourceListTypeEnum ;
            ListPrnDrvTypesCB : Record  (* union statement *)
                printerType16Ptr  :   pnstr16 ;
                printerMfr16Ptr  :   pnstr16 ;
                infFileName16Ptr  :   pnstr16 ;
            End;
        End;
        pNWDPResListCallbackItem = ^NWDPResListCallbackItem;
    (*
// Get Resource File Input Argument Types
*)
    Type
        NWDPResGetPrnDrvFile = Record
            osType  :   NWDPOSTypeEnum ;
            driverDirName16Ptr  :   pnstr16 ;
            fileName16Ptr  :   pnstr16 ;
        End;
        pNWDPResGetPrnDrvFile = ^NWDPResGetPrnDrvFile;
    Type
        NWDPResGetPrnDefFile = Record
            vendorDir16Ptr  :   pnstr16 ;
            fileName16Ptr  :   pnstr16 ;
        End;
        pNWDPResGetPrnDefFile = ^NWDPResGetPrnDefFile;
    Type
        NWDPResGetFontFile = Record
            osType  :   NWDPOSTypeEnum ;
            fontType  :   NWDPFontTypeEnum ;
            fileName16Ptr  :   pnstr16 ;
        End;
        pNWDPResGetFontFile = ^NWDPResGetFontFile;
    (*
// Get Resource File Date Input Argument Types
*)
    Type
        NWDPResGetDatePrnDrvFile = Record
            osType  :   NWDPOSTypeEnum ;
            driverDirName16Ptr  :   pnstr16 ;
            fileName16Ptr  :   pnstr16 ;
        End;
        pNWDPResGetDatePrnDrvFile = ^NWDPResGetDatePrnDrvFile;
    Type
        NWDPResGetDatePrnDefFile = Record
            vendorDir16Ptr  :   pnstr16 ;
            fileName16Ptr  :   pnstr16 ;
        End;
        pNWDPResGetDatePrnDefFile = ^NWDPResGetDatePrnDefFile;
    (* getting date of a font file not supported in NDPS MR1 *)
    (*
// Add Resource File Input Argument Types
*)
    Type
        NWDPResAddPrnDrvFile = Record
            osType  :   NWDPOSTypeEnum ;
            driverDirName16Ptr  :   pnstr16 ;
            fileName16Ptr  :   pnstr16 ;
        End;
        pNWDPResAddPrnDrvFile = ^NWDPResAddPrnDrvFile;
    Type
        NWDPResAddPrnDefFile = Record
            vendorDir16Ptr  :   pnstr16 ;
            fileName16Ptr  :   pnstr16 ;
        End;
        pNWDPResAddPrnDefFile = ^NWDPResAddPrnDefFile;
    Type
        NWDPResAddFontFile = Record
            osType  :   NWDPOSTypeEnum ;
            fontType  :   NWDPFontTypeEnum ;
            fontName16Ptr  :   pnstr16 ;
            fileName16Ptr  :   pnstr16 ;
        End;
        pNWDPResAddFontFile = ^NWDPResAddFontFile;
    (*
  // Delete Resource File Input Argument Types
  *)
    Type
        NWDPResDeletePrnDrvFile = Record
            osType  :   NWDPOSTypeEnum ;
            driverDirName16Ptr  :   pnstr16 ;
            fileName16Ptr  :   pnstr16 ;
        End;
        pNWDPResDeletePrnDrvFile = ^NWDPResDeletePrnDrvFile;
    Type
        NWDPResDeletePrnDefFile = Record
            vendorDir16Ptr  :   pnstr16 ;
            fileName16Ptr  :   pnstr16 ;
        End;
        pNWDPResDeletePrnDefFile = ^NWDPResDeletePrnDefFile;
    Type
        NWDPResDeleteFontFile = Record
            osType  :   NWDPOSTypeEnum ;
            fontType  :   NWDPFontTypeEnum ;
            fontName16Ptr  :   pnstr16 ;
            fileName16Ptr  :   pnstr16 ;
        End;
        pNWDPResDeleteFontFile = ^NWDPResDeleteFontFile;
    {$I npackoff.inc}
    (* Callback Definitions *)
    Type NWDPResListCallback = Function (
        accessorRef  :   NWDPAccessorRef ;
        callerDefinedParam  :   nparam ;
        totalCallsToBeMade  :   nint ;
        currentCallCount  :   nint ;
        resListItemPtr  :   pNWDPResListCallbackItem 
    ) : nint;
    (* Global Variable Declarations *)
    (* Function Prototype Declarations *)
    Function NWDPResAddResourceFile (
        accessorRef  :   NWDPAccessorRef ;
        resRef  :   NWDPResRef ;
        resType  :   NWDPResourceTypeEnum ;
        localDirPtr  :   pnstr ;
        addInput  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPResCreateRefBasedOnAddr (
        accessorRef  :   NWDPAccessorRef ;
        addressPtr  :   pNWDPNetAddress ;
        resRefPtr  :   pNWDPResRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPResCreateRefBasedOnFQN (
        accessorRef  :   NWDPAccessorRef ;
        brokerFqnPtr  :   pNWDPNSrvFQN ;
        resRefPtr  :   pNWDPResRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPResCreateRefBasedOnSrsSAP (
        accessorRef  :   NWDPAccessorRef ;
        resRefPtr  :   pNWDPResRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPResDeleteResourceFile (
        accessorRef  :   NWDPAccessorRef ;
        resRef  :   NWDPResRef ;
        resType  :   NWDPResourceTypeEnum ;
        deleteInput  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPResDestroyRef (
        accessorRef  :   NWDPAccessorRef ;
        resRefPtr  :   pNWDPResRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPResGetFQN (
        accessorRef  :   NWDPAccessorRef ;
        resRef  :   NWDPResRef ;
        sizeOfBuffer  :   nuint ;
        fqnBufferPtr  :   pNWDPNSrvFQNBuffer ;
        sizeOfResultPtr  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPResGetResourceFile (
        accessorRef  :   NWDPAccessorRef ;
        resRef  :   NWDPResRef ;
        resType  :   NWDPResourceTypeEnum ;
        localSrcDirPtr  :   pnstr ;
        localDestDirPtr  :   pnstr ;
        getInput  :   nparam ;
        Var fileTimePtr  : time_t
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPResGetResourceFileDate (
        accessorRef  :   NWDPAccessorRef ;
        resRef  :   NWDPResRef ;
        resType  :   NWDPResourceTypeEnum ;
        getDateInput  :   nparam ;
        Var fileTimePtr  : time_t
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPResListResource (
        accessorRef  :   NWDPAccessorRef ;
        resRef  :   NWDPResRef ;
        resListType  :   NWDPResourceListTypeEnum ;
        drivePathPtr  :   pnstr ;
        listInput  :   nparam ;
        listCallback  :   NWDPResListCallback ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPResValidateRef (
        accessorRef  :   NWDPAccessorRef ;
        resRef  :   NWDPResRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
{$ELSE}
    {$IFDEF  N_DEBUG }
        (* TC error *)
    {$ENDIF}
{$ENDIF}


