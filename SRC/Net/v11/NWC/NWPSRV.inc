(*
//浜様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様融
//� (c) 1993 Novell, Inc.	All rights reserved.                              �
//�																								  �
//� THIS WORK IS SUBJECT TO U.S. AND INTERNATIONAL COPYRIGHT LAWS AND		  �
//� TREATIES.																					  �
//�																								  �
//� NO PART OF THIS WORK MAY BE USED, PRACTICED, PERFORMED, COPIED,			  �
//� DISTRIBUTED, REVISED, MODIFIED, TRANSLATED, ABRIDGED, CONDENSED,         �
//� EXPANDED, COLLECTED, COMPILED, LINKED, RECAST, TRANSFORMED OR ADAPTED	  �
//� WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC.                        �
//�																								  �
//� ANY USE OR EXPLOITATION OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT �
//� THE PERPETRATOR TO CRIMINAL AND CIVIL LIABILITY.								  �
//麺様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様郵
//� Source module name: NWPSRV.H                                             �
//藩様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様夕
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


