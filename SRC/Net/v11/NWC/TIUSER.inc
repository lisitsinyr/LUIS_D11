(** Copyright (c) 1989  Mentat Inc.
 **)


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


{$IFNDEF _TIUSER_}

{$DEFINE _TIUSER_}

(*
 *   OS Specific Definitions
 *)


(*  ---------- DOS Specific definitions *)


{$IFDEF NWDOS}


{$IFNDEF FAR}

{$DEFINE FAR}
{$ENDIF}


{$IFNDEF API}

{$DEFINE API}
{$ENDIF}


{$IFDEF __cplusplus}

(* TC extern C *)
{$ENDIF}

(* TC  int int t_errno;  *)

{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}


{$ENDIF}


(*  ---------- OS/2 Specific definitions *)


{$IFDEF NWOS2}


{$IFNDEF FAR}

Type FAR = _far;
{$ENDIF}


{$IFNDEF API}

(* TC #define API pascal _far _loadds  *)
{$ENDIF}


{$IFDEF __cplusplus}

(* TC extern C *)
{$ENDIF}

(* TC #define t_errno ( * terrno_func ( ) )  *)
(* TC  int int _far * API terrno_func ( void );  *)

{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}


{$DEFINE MAX_TLI_CONNECTIONS}
Const MAX_TLI_CONNECTIONS = 40;

{$ENDIF}


(*  ---------- Windows Specific definitions *)


{$IFDEF NWWIN}


{$IFNDEF FAR}

Type FAR = far;
{$ENDIF}


{$IFNDEF API}

Type PASCAL = pascal;
(* TC #define API PASCAL FAR  *)
{$ENDIF}


{$IFDEF __cplusplus}

(* TC extern C *)
{$ENDIF}

(* TC #define t_errno ( * terrno_func ( ) )  *)
(* TC  int int far * API terrno_func ( void );  *)

{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}


{$DEFINE MAX_TLI_CONNECTIONS}
Const MAX_TLI_CONNECTIONS = 40;

(*
 *   O_RDWR is defined as different values for various compilers.
 *   The compiler used in the TLI DLLs use the following value.
 *   This value must be used in any program interfacing with TLI.
 *)

{$DEFINE O_RDWR}
Const O_RDWR = $02;

{$ENDIF}


(*
 *   End  of OS Specific Definitions
 *)


{$IFNDEF O_NONBLOCK}

{$DEFINE O_NDELAY}
Const O_NDELAY = $4000;
{$DEFINE O_NONBLOCK}
Const O_NONBLOCK = O_NDELAY;
{$ENDIF}


{$IFNDEF EAGAIN}

{$DEFINE EAGAIN}
Const EAGAIN = 1;
{$ENDIF}


(* Error values *)


{$DEFINE TBADADDR}
Const TBADADDR = 1;
{$DEFINE TBADOPT}
Const TBADOPT = 2;
{$DEFINE TACCES}
Const TACCES = 3;
{$DEFINE TBADF}
Const TBADF = 4;
{$DEFINE TNOADDR}
Const TNOADDR = 5;
{$DEFINE TOUTSTATE}
Const TOUTSTATE = 6;
{$DEFINE TBADSEQ}
Const TBADSEQ = 7;
{$DEFINE TSYSERR}
Const TSYSERR = 8;
{$DEFINE TLOOK}
Const TLOOK = 9;
{$DEFINE TBADDATA}
Const TBADDATA = 10;
{$DEFINE TBUFOVFLW}
Const TBUFOVFLW = 11;
{$DEFINE TFLOW}
Const TFLOW = 12;
{$DEFINE TNODATA}
Const TNODATA = 13;
{$DEFINE TNODIS}
Const TNODIS = 14;
{$DEFINE TNOUDERR}
Const TNOUDERR = 15;
{$DEFINE TBADFLAG}
Const TBADFLAG = 16;
{$DEFINE TNOREL}
Const TNOREL = 17;
{$DEFINE TNOTSUPPORT}
Const TNOTSUPPORT = 18;
{$DEFINE TSTATECHNG}
Const TSTATECHNG = 19;
{$DEFINE TNOSTRUCTYPE}
Const TNOSTRUCTYPE = 20;
{$DEFINE TBADNAME}
Const TBADNAME = 21;
{$DEFINE TBADQLEN}
Const TBADQLEN = 22;
{$DEFINE TADDRBUSY}
Const TADDRBUSY = 23;

(* t_look events *)


{$DEFINE T_LISTEN}
Const T_LISTEN = $0001;
{$DEFINE T_CONNECT}
Const T_CONNECT = $0002;
{$DEFINE T_DATA}
Const T_DATA = $0004;
{$DEFINE T_EXDATA}
Const T_EXDATA = $0008;
{$DEFINE T_DISCONNECT}
Const T_DISCONNECT = $0010;
{$DEFINE T_UDERR}
Const T_UDERR = $0040;
{$DEFINE T_ORDREL}
Const T_ORDREL = $0080;
{$DEFINE T_GODATA}
Const T_GODATA = $0100;
{$DEFINE T_GOEXDATA}
Const T_GOEXDATA = $0200;
{$DEFINE T_EVENTS}
Const T_EVENTS = $0400;
{$DEFINE T_ERROR}
Const T_ERROR = $0500;

(* Flag definitions *)


{$DEFINE T_MORE}
Const T_MORE = $01;
{$DEFINE T_EXPEDITED}
Const T_EXPEDITED = $02;
{$DEFINE T_NEGOTIATE}
Const T_NEGOTIATE = $04;
{$DEFINE T_CHECK}
Const T_CHECK = $08;
{$DEFINE T_DEFAULT}
Const T_DEFAULT = $10;
{$DEFINE T_SUCCESS}
Const T_SUCCESS = $20;
{$DEFINE T_FAILURE}
Const T_FAILURE = $40;

(*   T_event flag values *)


{$DEFINE T_DISABLE}
Const T_DISABLE = 0;
{$DEFINE T_ENABLE}
Const T_ENABLE = 1;
{$DEFINE T_SAME}
Const T_SAME = 2;

(* TC  char char FAR * t_errlist [ ];  *)

(* TC  int int t_nerr;  *)



t_info = Record
    addr  :  nint32;
    options  :  nint32;
    tsdu  :  nint32;
    etsdu  :  nint32;
    connect  :  nint32;
    discon  :  nint32;
    servtype  :  nint32;
End;


(* Service types *)


{$DEFINE T_COTS}
Const T_COTS = 01;
{$DEFINE T_COTS_ORD}
Const T_COTS_ORD = 02;
{$DEFINE T_CLTS}
Const T_CLTS = 03;


netbuf = Record
    maxlen  :  nuint32;
    len  :  nuint32;
    buf  :  ^nint8;
End;


t_bind = Record
    addr  :   netbuf ;
    qlen  :   unsigned ;
End;


t_optmgmt = Record
    opt  :   netbuf ;
    flags  :  nint32;
End;


t_discon = Record
    udata  :   netbuf ;
    reason  :  nint32;
    sequence  :  nint32;
End;


t_call = Record
    addr  :   netbuf ;
    opt  :   netbuf ;
    udata  :   netbuf ;
    sequence  :  nint32;
End;


t_unitdata = Record
    addr  :   netbuf ;
    opt  :   netbuf ;
    udata  :   netbuf ;
End;


t_uderr = Record
    addr  :   netbuf ;
    opt  :   netbuf ;
    error  :  nint32;
End;


(* t_alloc structure types *)


{$DEFINE T_BIND_STR}
Const T_BIND_STR = 1;
{$DEFINE T_OPTMGMT_STR}
Const T_OPTMGMT_STR = 2;
{$DEFINE T_CALL_STR}
Const T_CALL_STR = 3;
{$DEFINE T_DIS_STR}
Const T_DIS_STR = 4;
{$DEFINE T_UNITDATA_STR}
Const T_UNITDATA_STR = 5;
{$DEFINE T_UDERROR_STR}
Const T_UDERROR_STR = 6;
{$DEFINE T_INFO_STR}
Const T_INFO_STR = 7;

(* t_alloc field identifiers *)


{$DEFINE T_ADDR}
Const T_ADDR = $01;
{$DEFINE T_OPT}
Const T_OPT = $02;
{$DEFINE T_UDATA}
Const T_UDATA = $04;

(* #define T_ALL   0x07     *)

{$DEFINE T_ALL}
Const T_ALL = $08;

(* redefine t_alloc types to suit AT&T specs *)


{$DEFINE T_BIND}
Const T_BIND = T_BIND_STR;
{$DEFINE T_CALL}
Const T_CALL = T_CALL_STR;
{$DEFINE T_OPTMGMT}
Const T_OPTMGMT = T_OPTMGMT_STR;
{$DEFINE T_DIS}
Const T_DIS = T_DIS_STR;
{$DEFINE T_UNITDATA}
Const T_UNITDATA = T_UNITDATA_STR;
{$DEFINE T_UDERROR}
Const T_UDERROR = T_UDERROR_STR;
{$DEFINE T_INFO}
Const T_INFO = T_INFO_STR;


(* State values *)


{$DEFINE T_UNINIT}
Const T_UNINIT = 0;
{$DEFINE T_UNBND}
Const T_UNBND = 1;
{$DEFINE T_IDLE}
Const T_IDLE = 2;
{$DEFINE T_OUTCON}
Const T_OUTCON = 3;
{$DEFINE T_INCON}
Const T_INCON = 4;
{$DEFINE T_DATAXFER}
Const T_DATAXFER = 5;
{$DEFINE T_OUTREL}
Const T_OUTREL = 6;
{$DEFINE T_INREL}
Const T_INREL = 7;

(* general purpose defines *)

{$DEFINE T_YES}
Const T_YES = 1;
{$DEFINE T_NO}
Const T_NO = 0;
{$DEFINE T_UNUSED}
Const T_UNUSED = 1;
{$DEFINE T_NULL}
Const T_NULL = 0;
{$DEFINE T_ABSREQ}
Const T_ABSREQ = $8000;


(* ------------------------OSI specific Options-------------------------*)


(* ISO definitions *)


{$DEFINE T_CLASS0}
Const T_CLASS0 = 0;
{$DEFINE T_CLASS1}
Const T_CLASS1 = 1;
{$DEFINE T_CLASS2}
Const T_CLASS2 = 2;
{$DEFINE T_CLASS3}
Const T_CLASS3 = 3;
{$DEFINE T_CLASS4}
Const T_CLASS4 = 4;

(* priorities *)


{$DEFINE T_PRITOP}
Const T_PRITOP = 0;
{$DEFINE T_PRIHIGH}
Const T_PRIHIGH = 1;
{$DEFINE T_PRIMID}
Const T_PRIMID = 2;
{$DEFINE T_PRILOW}
Const T_PRILOW = 3;
{$DEFINE T_PRIDFLT}
Const T_PRIDFLT = 4;

(* protection levels *)


{$DEFINE T_NOPROTECT}
Const T_NOPROTECT = 1;
{$DEFINE T_PASSIVEPROTECT}
Const T_PASSIVEPROTECT = 2;
{$DEFINE T_ACTIVEPROTECT}
Const T_ACTIVEPROTECT = 4;

(* default value for the length of TPDU's *)


{$DEFINE T_LTPDUDFLT}
Const T_LTPDUDFLT = 128;

(* rate structure *)


rate = Record
    targetvalue  :  nint32;
    minacceptvalue  :  nint32;
End;


(* reqvalue structure *)


reqvalue = Record
    called  :   rate ;
    calling  :   rate ;
End;


(* throughput structure *)


thrpt = Record
    maxthrpt  :   reqvalue ;
    avgthrpt  :   reqvalue ;
End;


(* management structure *)


management = Record
    dflt  :   short ;
    ltpdu  :  nint32;
    reastime  :   short ;
    prefclass  :  nint8;
    altclass  :  nint8;
    extform  :  nint8;
    flowctrl  :  nint8;
    checksum  :  nint8;
    netexp  :  nint8;
    netrecptcf  :  nint8;
End;


(* ISO connection-oriented options *)


isoco_options = Record
    throughput  :   thrpt ;
    transdel  :   reqvalue ;
    reserrorrate  :   rate ;
    transffailprob  :   rate ;
    estfailprob  :   rate ;
    relfailprob  :   rate ;
    estdelay  :   rate ;
    reldelay  :   rate ;
    connresil  :   netbuf ;
    protection  :  nuint16;
    priority  :   short ;
    mngmt  :   management ;
    expd  :  nint8;
End;


(* ISO connectionless options *)


isocl_options = Record
    transdel  :   rate ;
    reserrorrate  :   rate ;
    protection  :  nuint16;
    priority  :   short ;
End;


(*---------------------TCP specific Options--------------------------*)


(* TCP Precedence Levels *)


{$DEFINE T_ROUTINE}
Const T_ROUTINE = 0;
{$DEFINE T_PRIORITY}
Const T_PRIORITY = 1;
{$DEFINE T_IMMEDIATE}
Const T_IMMEDIATE = 2;
{$DEFINE T_FLASH}
Const T_FLASH = 3;
{$DEFINE T_OVERRIDEFLASH}
Const T_OVERRIDEFLASH = 4;
{$DEFINE T_CRITIC_ECP}
Const T_CRITIC_ECP = 5;
{$DEFINE T_INETCONTROL}
Const T_INETCONTROL = 6;
{$DEFINE T_NETCONTROL}
Const T_NETCONTROL = 7;

(* TCP security options structure *)


secoptions = Record
    security  :   short ;
    compartment  :   short ;
    handling  :   short ;
    tcc  :  nint32;
End;


(* TCP options *)


tcp_options = Record
    precedence  :   short ;
    timeout  :  nint32;
    max_seg_size  :  nint32;
    secopt  :   secoptions ;
End;


(*----------------------SPX\IPX specific Options-----------------------*)


{$I tispxipx.inc}

(*---------------------end of Options---------------------------------*)


{$IFNDEF NO_PROTOTYPES}


{$IFDEF __cplusplus}

(* TC extern C *)
{$ENDIF}


(* TC  int int API t_accept ( int fd , int resfd , struct t_call FAR * call );  *)

(* TC  char char FAR * API t_alloc ( int fd , int struct_type , int fields );  *)

(* TC  int int API t_bind ( int fd , struct t_bind FAR * req , struct t_bind FAR * ret );  *)

(* TC  int int API t_blocking ( int fd );  *)

(* TC  int int API t_close ( int fd );  *)

(* TC  int int API t_connect ( int fd , struct t_call FAR * sndcall , struct t_call FAR * rcvcall );  *)

(* TC  void void API t_error ( char FAR * errmsg );  *)

(* TC  int int API t_free ( char FAR * ptr , int struct_type );  *)

(* TC  int int API t_getinfo ( int fd , struct t_info FAR * info );  *)

(* TC  int int API t_getstate ( int fd );  *)

(* TC  int int API t_listen ( int fd , struct t_call FAR * call );  *)

(* TC  int int API t_look ( int fd );  *)

(* TC  int int API t_nonblocking ( int fd );  *)

(* TC  int int API t_open ( char FAR * path , int oflag , struct t_info FAR * info );  *)

(* TC  int int API t_optmgmt ( int fd , struct t_optmgmt FAR * req , struct t_optmgmt FAR * ret );  *)

(* TC  int int API t_rcv ( int fd , char FAR * buf , unsigned nbytes , int FAR * flags );  *)

(* TC  int int API t_rcvconnect ( int fd , struct t_call FAR * call );  *)

(* TC  int int API t_rcvdis ( int fd , struct t_discon FAR * discon );  *)

(* TC  int int API t_rcvrel ( int fd );  *)

(* TC  int int API t_rcvudata ( int fd , struct t_unitdata FAR * unitdata , int FAR * flags );  *)

(* TC  int int API t_rcvuderr ( int fd , struct t_uderr FAR * uderr );  *)

(* TC  int int API t_snd ( int fd , char FAR * buf , unsigned nbytes , int flags );  *)

(* TC  int int API t_snddis ( int fd , struct t_call FAR * call );  *)

(* TC  int int API t_sndrel ( int fd );  *)

(* TC  int int API t_sndudata ( int fd , struct t_unitdata FAR * unitdata );  *)

(* TC  int int API t_sync ( int fd );  *)

(* TC  int int API t_unbind ( int fd );  *)


{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}


{$ENDIF}



{$ENDIF}

