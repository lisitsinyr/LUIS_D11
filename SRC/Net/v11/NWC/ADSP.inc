(*
 *  Copyright (C) 1993-1995 Novell, Inc.  All Rights Reserved
 *  Copyright (C) 1995 Novell, Inc.  All Rights Reserved
 *
 *  THIS WORK IS SUBJECT TO U.S. AND INTERNATIONAL COPYRIGHT LAWS AND
 *  TREATIES. NO PART OF THIS WORK MAY BE USED, PRACTICED, PERFORMED, 
 *  COPIED, DISTRIBUTED, REVISED, MODIFIED, TRANSLATED, ABRIDGED, 
 *  CONDENSED, EXPANDED, COLLECTED, COMPILED, LINKED, RECAST, TRANSFORMED
 *  OR ADAPTED WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC. ANY
 *  USE OR EXPLOITATION OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT 
 *  THE PERPETRATOR TO CRIMINAL AND CIVIL LIABILITY.
 *  
 *)


(*
 *  Copyright (c) 1987, 1988, 1989 Apple Computer, Inc. 
 *
 *  The information contained herein is subject to change without
 *  notice and  should not be  construed as a commitment by Apple
 *  Computer, Inc. Apple Computer, Inc. assumes no responsibility
 *  for any errors that may appear.
 *
 *  Confidential and Proprietary to Apple Computer, Inc.
 *)


(* @(#)adsp.h: 2.0a4, 1.1; 3/30/89; Copyright 1987-89, Apple Computer, Inc."; *)



{$IFNDEF __ADSP_H__}

{$DEFINE __ADSP_H__}

{$DEFINE ADSP_MAJOR}
Const ADSP_MAJOR = 2;
{$DEFINE ADSP_MINOR}
Const ADSP_MINOR = 0;
{$DEFINE ADSP_REVISION}
Const ADSP_REVISION = 0;

(* ADSP Options *)

Type
    ATAdspOpt = Record
        Major  :  nint8;
        Minor  :  nint8;
        Revision  :  nint8;
        reserved1  :  nuint8;
        TransThresh  :  nuint16;
        TransTimerIntrvl  :   unsigned ;
        reserved2  :  Array[0..117] Of nuint8;
    End;
    ATAdspOpt_t = ATAdspOpt;


{$ENDIF}


