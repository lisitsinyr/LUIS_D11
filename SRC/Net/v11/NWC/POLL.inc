(****************************************************************************
*                                                                           *
* (C) Unpublished Copyright of Novell, Inc. All Rights Reserved             *
*                                                                           *
*  No part of this file may be duplicayed, revised, translated, localized   *
*  or modified in any manner or compiled, linked or uploaded or downloaded  *
*  to or from any computer system without the prior written consent of      *
*  Novell, Inc.                                                             *
*                                                                           *
*****************************************************************************)


(*
 *   OS specific definitions - DOS
 *)


(*  ---------- DOS Specific definitions *)


{$IFDEF NWDOS}


{$IFNDEF API}

{$DEFINE API}
{$ENDIF}


{$IFNDEF FAR}

{$DEFINE FAR}
{$ENDIF}


{$ENDIF}


(*  ---------- OS/2 Specific definitions *)


{$IFDEF NWOS2}


{$IFNDEF API}

(* TC #define API pascal far _loadds  *)
{$ENDIF}


{$IFNDEF FAR}

Type FAR = far;
{$ENDIF}


{$ENDIF}


(*  ---------- Windows Specific definitions *)


{$IFDEF NWWIN}


{$IFNDEF API}

(* TC #define API pascal far  *)
{$ENDIF}


{$IFNDEF FAR}

Type FAR = far;
{$ENDIF}


{$ENDIF}


(*
 *   End of OS specific definitions
 *)


{$DEFINE NPOLLFILE}
Const NPOLLFILE = 20;

(* Poll masks *)

{$DEFINE POLLIN}
Const POLLIN = 01;
{$DEFINE POLLPRI}
Const POLLPRI = 02;
{$DEFINE POLLOUT}
Const POLLOUT = 04;
{$DEFINE POLLERR}
Const POLLERR = 010;
{$DEFINE POLLHUP}
Const POLLHUP = 020;
{$DEFINE POLLNVAL}
Const POLLNVAL = 040;


(* array of streams to poll *)

pollfd = Record
    fd  :  nint32;
    events  :   short ;
    revents  :   short ;
End;



{$IFNDEF UNIX5_3}


(* I_POLL structure for non-5.3 systems *)

Type  strpoll = Record
     nfds : LongInt;
{$ifdef CPU_808X}
      pollfdp : ^pollfd;
{$else}
      pollfdp : ^pollfd;
{$endif}


{$ENDIF}



{$IFDEF __cplusplus}

(* TC extern C *)
{$ENDIF}


(* TC  int int API poll ( struct pollfd FAR fds [ ] , unsigned long nfds , int timeout );  *)


{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}



