(*
//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
//บ (c) 1993 Novell, Inc.	All rights reserved.                              บ
//บ																								  บ
//บ THIS WORK IS SUBJECT TO U.S. AND INTERNATIONAL COPYRIGHT LAWS AND		  บ
//บ TREATIES.																					  บ
//บ																								  บ
//บ NO PART OF THIS WORK MAY BE USED, PRACTICED, PERFORMED, COPIED,			  บ
//บ DISTRIBUTED, REVISED, MODIFIED, TRANSLATED, ABRIDGED, CONDENSED,         บ
//บ EXPANDED, COLLECTED, COMPILED, LINKED, RECAST, TRANSFORMED OR ADAPTED	  บ
//บ WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC.                        บ
//บ																								  บ
//บ ANY USE OR EXPLOITATION OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT บ
//บ THE PERPETRATOR TO CRIMINAL AND CIVIL LIABILITY.								  บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Source module name: NWPSRV.H                                             บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)


(*
//    This header will include ALL the nwpsrv include files. To
//    exclude one or more specific headers, use the following defines:
// 
//       #define NOPS_DEF_INC
//       #define NOPS_ERR_INC
//       #define NOPS_CFG_INC
//       #define NOPS_COM_INC
//       #define NOPS_JOB_INC
//       #define NOPS_PDF_INC
//       #define NOPS_PKT_INC
//       #define NOPS_NLM_INC
*)



(*
//  MODIFICATIONS:
// 
//       July 28, 1993 - Added NWPS_NLM.H inclusion for NLM Library support
*)


{$IFNDEF NWPSRV_INC}

{$DEFINE NWPSRV_INC}

{$IFNDEF NOPS_DEF_INC}

{$I nwps_def.inc}
{$ENDIF}


{$IFNDEF NOPS_ERR_INC}

{$I nwps_err.inc}
{$ENDIF}


{$IFNDEF NOPS_CFG_INC}

{$I nwps_cfg.inc}
{$ENDIF}


{$IFNDEF NOPS_COM_INC}

{$I nwps_com.inc}
{$ENDIF}


{$IFNDEF NOPS_JOB_INC}

{$I nwps_job.inc}
{$ENDIF}


{$IFNDEF NOPS_PDF_INC}

{$I nwps_pdf.inc}
{$ENDIF}


{$IFNDEF NOPS_PKT_INC}

{$I nwps_pkt.inc}
{$ENDIF}


{$IFDEF NWNLM}

{$IFNDEF NOPS_NLM_INC}

{$I nwps_nlm.inc}
{$ENDIF}

{$ENDIF}


{$ENDIF}


