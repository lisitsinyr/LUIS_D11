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
//บ Source module name: NWDPLIB.H                                            บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Library VeRsIoN=1.0.0                                                    บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

(* Inclusion Control *)

{$IFNDEF  NWDPLIB_H }
    {$DEFINE NWDPLIB_H}
    (* Header Includes *)
    {$IFNDEF  NO_NWDP_LIB_H }
    {$IFNDEF  NWDP_LIB_H }
        {$I nwdp_lib.inc}
    {$ENDIF}
    {$ENDIF}
    {$IFNDEF  NO_NWDP_ATR_H }
    {$IFNDEF  NWDP_ATR_H }
        {$I nwdp_atr.inc}
    {$ENDIF}
    {$ENDIF}
    {$IFNDEF  NO_NWDP_AUT_H }
    {$IFNDEF  NWDP_AUT_H }
        {$I nwdp_aut.inc}
    {$ENDIF}
    {$ENDIF}
    {$IFNDEF  NO_NWDP_FLT_H }
    {$IFNDEF  NWDP_FLT_H }
        {$I nwdp_flt.inc}
    {$ENDIF}
    {$ENDIF}
    {$IFNDEF  NO_NWDP_ATT_H }
    {$IFNDEF  NWDP_ATT_H }
        {$I nwdp_att.inc}
    {$ENDIF}
    {$ENDIF}
    {$IFNDEF  NO_NWDP_DOC_H }
    {$IFNDEF  NWDP_DOC_H }
        {$I nwdp_doc.inc}
    {$ENDIF}
    {$ENDIF}
    {$IFNDEF  NO_NWDP_JOB_H }
    {$IFNDEF  NWDP_JOB_H }
        {$I nwdp_job.inc}
    {$ENDIF}
    {$ENDIF}
    {$IFNDEF  NO_NWDP_NSR_H }
    {$IFNDEF  NWDP_NSR_H }
        {$I nwdp_nsr.inc}
    {$ENDIF}
    {$ENDIF}
    {$IFNDEF  NO_NWDP_PRT_H }
    {$IFNDEF  NWDP_PRT_H }
        {$I nwdp_prt.inc}
    {$ENDIF}
    {$ENDIF}
    {$IFNDEF  NO_NWDP_BRK_H }
    {$IFNDEF  NWDP_BRK_H }
        {$I nwdp_brk.inc}
    {$ENDIF}
    {$ENDIF}
    {$IFNDEF  NO_NWDP_SRS_H }
    {$IFNDEF  NWDP_SRS_H }
        {$I nwdp_srs.inc}
    {$ENDIF}
    {$ENDIF}
    {$IFNDEF  NO_NWDP_RES_H }
    {$IFNDEF  NWDP_RES_H }
        {$I nwdp_res.inc}
    {$ENDIF}
    {$ENDIF}
    {$IFNDEF  NO_NWDP_PSM_H }
    {$IFNDEF  NWDP_PSM_H }
        {$I nwdp_psm.inc}
    {$ENDIF}
    {$ENDIF}
    {$IFNDEF  NO_NWDP_ERR_H }
    {$IFNDEF  NWDP_ERR_H }
        {$I nwdp_err.inc}
    {$ENDIF}
    {$ENDIF}
    {$IFNDEF  NO_NWDP_OID_H }
    {$IFNDEF  NWDP_OID_H }
        {$I nwdp_oid.inc}
    {$ENDIF}
    {$ENDIF}
    {$IFNDEF  NO_NWDP_NOT_H }
    {$IFNDEF  NWDP_NOT_H }
        {$I nwdp_not.inc}
    {$ENDIF}
    {$ENDIF}
{$ELSE}
    {$IFDEF  N_DEBUG }
        (* TC error *)
    {$ENDIF}
{$ENDIF}



