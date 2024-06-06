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
//� Source module name: NWDP_NTT.H                                           �
//��������������������������������������������������������������������������͹
//� Library VeRsIoN=1.0.0                                                    �
//��������������������������������������������������������������������������ͼ
*)

(* Inclusion Control *)

{$IFNDEF  NWDP_NTT_H }
    {$DEFINE NWDP_NTT_H}
    (* Standard Library Header Includes *)
    {$IFNDEF  NTYPES_H }
        {$DEFINE N_INC_NO_OLD_CONSTANTS}
        {$I ntypes.inc}
        {$UNDEF N_INC_NO_OLD_CONSTANTS}
    {$ENDIF}
    (* Header Includes *)
    {$IFNDEF  NWDP_NTO_H }
        {$I nwdp_nto.inc}
    {$ENDIF}
    (* Manifest Constant Definitions *)
    {$DEFINE NWDP_NTFY_MAX_PROMPT_CHARS}
    Const NWDP_NTFY_MAX_PROMPT_CHARS = 31;
     NWDP_NTFY_MAX_PROMPT_BYTES = ( ( NWDP_NTFY_MAX_PROMPT_CHARS + 1 ) * 2 );
    (* Macro Definitions *)
    (* Type Definitions *)
    {$DEFINE N_PACK_1}
    {$I npackon.inc}
    Type
        NWDPNtfyDeliveryMethod = Record
            methodId  :   NWDPNameOrOid ;
            methodName16Ptr  :   pnstr16 ;
            methodVersion16Ptr  :   pnstr16 ;
            fileName16Ptr  :   pnstr16 ;
            adminSubmitProfileFlag  :   nbool ;
        End;
        pNWDPNtfyDeliveryMethod = ^NWDPNtfyDeliveryMethod;
    Type
        NWDPNtfyPromptListItem = Record
            prompt16  :  Array[0..NWDP_NTFY_MAX_PROMPT_CHARS+1-1] Of  nchar16 ;
            addressItem  :   NWDPDeliveryAddrItem ;
        End;
        pNWDPNtfyPromptListItem = ^NWDPNtfyPromptListItem;
    {$I npackoff.inc}
    (* Structure Definitions *)
    (* Global Variable Declarations *)
    (* Function Prototype Declarations *)
{$ELSE}
    {$IFDEF  N_DEBUG }
        (* TC error *)
    {$ENDIF}
{$ENDIF}

