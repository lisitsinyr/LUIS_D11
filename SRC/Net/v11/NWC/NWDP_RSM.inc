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
//บ Source module name: NWDP_RSM.H                                           บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Library VeRsIoN=1.0.0                                                    บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

(* Inclusion Control *)

{$IFNDEF  NWDP_RSM_H }
    {$DEFINE NWDP_RSM_H}
    (* Standard Library Header Includes *)
    {$IFNDEF  NTYPES_H }
        {$DEFINE N_INC_NO_OLD_CONSTANTS}
        {$DEFINE N_INC_NO_OLD_MACROS}
        {$I ntypes.inc}
        {$UNDEF N_INC_NO_OLD_MACROS}
        {$UNDEF N_INC_NO_OLD_CONSTANTS}
    {$ENDIF}
    (* Header Includes *)
    (* Manifest Constant Definitions *)
    (* Macro Definitions *)
    (* Type Definitions *)
    Const
    NWDP_RES_PRN_DRV = 0;
    NWDP_RES_PRN_DEF = 1;
    NWDP_RES_BANNER_PAGE = 2;
    NWDP_RES_FONT = 3;
    NWDP_RES_GENERIC_RESOURCE = 4;
    Type NWDPResourceTypeEnum = 0..4;
    pNWDPResourceTypeEnum = ^NWDPResourceTypeEnum;
    Const
    NWDP_RES_LIST_PRN_DRV_TYPES = 0;
    NWDP_RES_LIST_PRN_DEF_TYPES = 1;
    NWDP_RES_LIST_PRN_DEF_TYPES_SH = 2;
    NWDP_RES_LIST_BANNER_PAGE_FILES = 3;
    NWDP_RES_LIST_FONT_TYPES = 4;
    NWDP_RES_LIST_PRN_DRV_FILES = 5;
    NWDP_RES_LIST_PRN_DEF_FILE = 6;
    NWDP_RES_LIST_FONT_FILES = 7;
    NWDP_RES_LIST_GENERIC_TYPE = 8;
    NWDP_RES_LIST_GENERIC_FILES = 9;
    Type NWDPResourceListTypeEnum = 0..9;
    pNWDPResourceListTypeEnum = ^NWDPResourceListTypeEnum;
    Const
    NWDP_RES_OS_DOS = 0;
    NWDP_RES_OS_WIN_31 = 1;
    NWDP_RES_OS_WIN_95 = 2;
    NWDP_RES_OS_WIN_NT = 3;
    NWDP_RES_OS_OS_2 = 4;
    NWDP_RES_OS_MAC = 5;
    NWDP_RES_OS_UNIX = 6;
    Type NWDPOSTypeEnum = 0..6;
    pNWDPOSTypeEnum = ^NWDPOSTypeEnum;
    Const
    NWDP_RES_BANNER_ALL = 0;
    NWDP_RES_BANNER_PCL = 1;
    NWDP_RES_BANNER_PS = 2;
    NWDP_RES_BANNER_TXT = 3;
    Type NWDPBannerTypeEnum = 0..3;
    pNWDPBannerTypeEnum = ^NWDPBannerTypeEnum;
    Const
    NWDP_RES_FONT_TRUE_TYPE = 0;
    NWDP_RES_FONT_PS = 1;
    NWDP_RES_FONT_SYSTEM = 2;
    NWDP_RES_FONT_SPD = 3;
    NWDP_RES_FONT_TRUE_DOC = 4;
    Type NWDPFontTypeEnum = 0..4;
    pNWDPFontTypeEnum = ^NWDPFontTypeEnum;
    (* Structure Definitions *)
    (* Global Variable Declarations *)
    (* Function Prototype Declarations *)
{$ELSE}
    {$IFDEF  N_DEBUG }
        (* TC error *)
    {$ENDIF}
{$ENDIF}


