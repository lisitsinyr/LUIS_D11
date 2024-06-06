(*
//��������������������������������������������������������������������������ͻ
//� (c) 1995-1997 Novell, Inc.  All rights reserved.                         �
//�                                                                          �
//� THIS WORK IS SUBJECT TO U.S. AND INTERNATIONAL COPYRIGHT LAWS AND        �
//� TREATIES.                                                                �
//�                                                                          �
//� NO PART OF THIS WORK MAY BE USED, PRACTICED, PERFORMED, COPIED,          �
//� DISTRIBUTED, REVISED, MODIFIED, TRANSLATED, ABRIDGED, CONDENSED,         �
//� EXPANDED, COLLECTED, COMPILED, LINKED, RECAST, TRANSFORMED OR ADAPTED    �
//� WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC.                        �
//�                                                                          �
//� ANY USE OR EXPLOITATION OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT �
//� THE PERPETRATOR TO CRIMINAL AND CIVIL LIABILITY.                         �
//��������������������������������������������������������������������������͹
//� Source module name: NWDP_FLT.H                                           �
//��������������������������������������������������������������������������͹
//� Library VeRsIoN=1.0.0                                                    �
//��������������������������������������������������������������������������ͼ
*)

(* Inclusion Control *)

{$IFNDEF  NWDP_FLT_H }
    {$DEFINE NWDP_FLT_H}
    (* Standard Library Header Includes *)
    {$IFNDEF  NWDP_ATR_H }
        {$I nwdp_atr.inc}
    {$ENDIF}
    {$IFNDEF  NWDP_ATT_H }
        {$I nwdp_att.inc}
    {$ENDIF}
    (* Header Includes *)
    (* Manifest Constant Definitions *)
    (* Macro Definitions *)
    (* Type Definitions *)
    {$DEFINE N_PACK_1}
    {$I npackon.inc}
    Const
    NWDP_FLT_DELIM_AND = 1;
    NWDP_FLT_DELIM_OR = 2;
    NWDP_FLT_DELIM_NOT = 3;
    NWDP_FLT_DELIM_LPAREN = 9;
    NWDP_FLT_DELIM_RPAREN = 10;
    NWDP_FLT_DELIM_END = 11;
    Type NWDPFilterDelimiter = 0..11;
    pNWDPFilterDelimiter = ^NWDPFilterDelimiter;
    Const
    NWDP_FLT_MATCH_EQUAL = 0;
    NWDP_FLT_MATCH_GE = 2;
    NWDP_FLT_MATCH_LE = 3;
    NWDP_FLT_MATCH_PRESENT = 4;
    NWDP_FLT_MATCH_SUBSET = 5;
    NWDP_FLT_MATCH_SUPERSET = 6;
    NWDP_FLT_MATCH_NON_DISJOINT = 7;
    Type NWDPFilterAttrSetMatch = 0..7;
    pNWDPFilterAttrSetMatch = ^NWDPFilterAttrSetMatch;
    {$I npackoff.inc}
    (* Structure Definitions *)
    (* Global Variable Declarations *)
    (* Function Prototype Declarations *)
    Function NWDPFltCreateRef (
        accessorRef  :   NWDPAccessorRef ;
        filterRefPtr  :   pNWDPFilterRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPFltDestroyRef (
        accessorRef  :   NWDPAccessorRef ;
        filterRefPtr  :   pNWDPFilterRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPFltAppendDelimiter (
        accessorRef  :   NWDPAccessorRef ;
        filterRef  :   NWDPFilterRef ;
        delimiter  :   NWDPFilterDelimiter 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPFltAppendAttrSetMatch (
        accessorRef  :   NWDPAccessorRef ;
        filterRef  :   NWDPFilterRef ;
        avpRef  :   NWDPASAVPRef ;
        matchFlag  :   NWDPFilterAttrSetMatch 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPFltAppendSubstringMatch (
        accessorRef  :   NWDPAccessorRef ;
        filterRef  :   NWDPFilterRef ;
        attrSubstringMatchPtr  :   pNWDPSubStrings 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPFltValidateRef (
        accessorRef  :   NWDPAccessorRef ;
        filterRef  :   NWDPFilterRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
{$ELSE}
    {$IFDEF  N_DEBUG }
        (* TC error *)
    {$ENDIF}
{$ENDIF}
