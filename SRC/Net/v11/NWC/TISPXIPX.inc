(****************************************************************************
 *
 * (C) Unpublished Copyright of Novell, Inc. All Rights Reserved.
 *
 * No part of this file may be duplicated, revised, translated, localized or
 * modified in any manner or compiled, linked or uploaded or downloaded to or
 * from any computer system without the prior written consent of Novell, Inc
 *
 ***************************************************************************)


(*
  *   SPX/IPX Specific Values and Structures for TLI
  *)


{$IFNDEF _TISPXIPX_}

{$DEFINE _TISPXIPX_}

Type
    ipxaddr_s = Record
        ipxa_net  :  Array[0..3] Of nuint8;
        ipxa_node  :  Array[0..5] Of nuint8;
        ipxa_socket  :  Array[0..1] Of nuint8;
    End;
    IPX_ADDR = ipxaddr_s;


Type
    ipxopt_s = Record
        ipx_type  :  nuint8;
        ipx_pad1  :  Array[0..2] Of nuint8;
        ipx_hops  :  nuint8;
        ipx_pad2  :  Array[0..2] Of nuint8;
    End;
    IPX_OPTS = ipxopt_s;


(*
 *   SPX Options structure (Previous to 4.0 ) 
 *
 *   SPX II option structure, used if t_open("nspx",...) as oppossed to nspx2.
 *)

Type
    spxopt_s = Record
        spx_connectionID  :  Array[0..1] Of nuint8;
        spx_allocationNumber  :  Array[0..1] Of nuint8;
        spx_pad1  :  Array[0..3] Of nuint8;
    End;
    SPX_OPTS = spxopt_s;


Type
    spx_optmgmt = Record
        spxo_retry_count  :  nuint8;
        spxo_watchdog_flag  :  nuint8;
        spxo_min_retry_delay  :  nuint32;
        spxo_pad2  :  Array[0..1] Of nuint8;
    End;
    SPX_OPTMGMT = spx_optmgmt;


(*
 *   SPX Options structure (New to 4.0 and later) 
 *
 *   SPX II option structure, used if t_open("nspx2",...) as oppossed to nspx.
 *   This stucture is used for all option managment settings and inquiries.
 *   Not all members are set/returned in every option management call.
 *   Option managment calls which use this common structure are:
 *
 *   t_getinfo    - returns size of SPX2_OPTIONS (changes as versions change)
 *   t_optmgmt    - sends/returns SPX2_OPTIONS to/from protocol provider 
 *   t_accept     - sends SPX2_OPTIONS structure to protocol provider
 *   t_connect    - sends and, if not O_NDELAY,  returns SPX2_OPTIONS 
 *	  t_rcvconnect - returns SPX2_OPTIONS from the provider
 *   t_listen     - returns SPX2_OPTIONS from the provider
 *)


{$DEFINE OPTIONS_VERSION}
Const OPTIONS_VERSION = 1;

(* Option version history *)


{$IFDEF OPTIONS_VERSION==1}
    (* TC #define OPTIONS_SIZE ( 13 * sizeof ( long ) )  *)
{$ENDIF}


Type
    spx2_options = Record
        versionNumber  :  nuint32;
        spxIIOptionNegotiate  :  nuint32;
        spxIIRetryCount  :  nuint32;
        spxIIMinimumRetryDelay  :  nuint32;
        spxIIMaximumRetryDelta  :  nuint32;
        spxIIWatchdogTimeout  :  nuint32;
        spxIIConnectTimeout  :  nuint32;
        spxIILocalWindowSize  :  nuint32;
        spxIIRemoteWindowSize  :  nuint32;
        spxIIConnectionID  :  nuint32;
        spxIIInboundPacketSize  :  nuint32;
        spxIIOutboundPacketSize  :  nuint32;
        spxIISessionFlags  :  nuint32;
    End;
    SPX2_OPTIONS = spx2_options;



(* SPX and SPX II Option Management values *)


{$DEFINE SPX_WATCHDOG_OFF}
Const SPX_WATCHDOG_OFF = 0;
 SPX_WATCHDOG_ON = ! SPX_WATCHDOG_OFF;
Type SPX_WATCHDOG_DEFAULT = SPX_WATCHDOG_ON;

(* SPX options only above here *)


{$DEFINE SPX_RETRY_MIN}
Const SPX_RETRY_MIN = 3;
{$DEFINE SPX_RETRY_MAX}
Const SPX_RETRY_MAX = 50;
{$DEFINE SPX_RETRY_DEFAULT}
Const SPX_RETRY_DEFAULT = 10;

(* SPX II options only below here *)


{$DEFINE SPX_WATCHDOG_TIMEOUT_MIN}
Const SPX_WATCHDOG_TIMEOUT_MIN = 3000;
{$DEFINE SPX_WATCHDOG_TIMEOUT_MAX}
Const SPX_WATCHDOG_TIMEOUT_MAX = 300000;
{$DEFINE SPX_WATCHDOG_TIMEOUT_DEFAULT}
Const SPX_WATCHDOG_TIMEOUT_DEFAULT = 60000;

{$DEFINE SPX_MIN_RETRY_DELAY_MIN}
Const SPX_MIN_RETRY_DELAY_MIN = 1;
{$DEFINE SPX_MIN_RETRY_DELAY_MAX}
Const SPX_MIN_RETRY_DELAY_MAX = 60000;
{$DEFINE SPX_MIN_RETRY_DELAY_DEFAULT}
Const SPX_MIN_RETRY_DELAY_DEFAULT = 0;

{$DEFINE SPX_MAX_RETRY_DELTA_MIN}
Const SPX_MAX_RETRY_DELTA_MIN = 1000;
{$DEFINE SPX_MAX_RETRY_DELTA_MAX}
Const SPX_MAX_RETRY_DELTA_MAX = 60000;
{$DEFINE SPX_MAX_RETRY_DELTA_DEFAULT}
Const SPX_MAX_RETRY_DELTA_DEFAULT = 5000;

{$DEFINE SPX_OPTION_NEGOTIATE_OFF}
Const SPX_OPTION_NEGOTIATE_OFF = 0;
SPX_OPTION_NEGOTIATE_ON =! SPX_OPTION_NEGOTIATE_OFF;
Type SPX_OPTION_NEGOTIATE_DEFAULT = SPX_OPTION_NEGOTIATE_ON;

{$DEFINE SPX_CONNECT_TIMEOUT_MIN}
Const SPX_CONNECT_TIMEOUT_MIN = 1000;
{$DEFINE SPX_CONNECT_TIMEOUT_MAX}
Const SPX_CONNECT_TIMEOUT_MAX = 120000;
{$DEFINE SPX_CONNECT_TIMEOUT_DEFAULT}
Const SPX_CONNECT_TIMEOUT_DEFAULT = 0;

{$DEFINE SPX_LOCAL_WINDOW_SIZE_MIN}
Const SPX_LOCAL_WINDOW_SIZE_MIN = 1;
{$DEFINE SPX_LOCAL_WINDOW_SIZE_MAX}
Const SPX_LOCAL_WINDOW_SIZE_MAX = 8;
{$DEFINE SPX_LOCAL_WINDOW_SIZE_DEFAULT}
Const SPX_LOCAL_WINDOW_SIZE_DEFAULT = 0;

{$DEFINE SPX2_SF_NONE}
Const SPX2_SF_NONE = $00;
{$DEFINE SPX2_SF_IPX_CHECKSUM}
Const SPX2_SF_IPX_CHECKSUM = $01;
{$DEFINE SPX2_SF_SPX2_SESSION}
Const SPX2_SF_SPX2_SESSION = $02;



(* Misc. byte aligned data access macros *)


{$IFNDEF BE16_TO_U16}

(* TC #define BE16_TO_U16 ( a ) ( ( ( ( u16 ) ( ( u8 * ) a ) [ 0 ] < < ( u16 ) 8 ) | ( ( u16 ) ( ( u8 * ) a ) [ 1 ] & 0xFF ) ) & ( u16 ) 0xFFFF )  *)
(* TC #define BE32_TO_U32 ( a ) ( ( ( ( u32 ) ( ( u8 * ) a ) [ 0 ] & 0xFF ) < < ( u32 ) 24 ) | ( ( ( u32 ) ( ( u8 * ) a ) [ 1 ] & 0xFF ) < < ( u32 ) 16 ) | ( ( ( u32 ) ( ( u8 * ) a ) [ 2 ] & 0xFF ) < < ( u32  *)
(* TC #define U16_TO_BE16 ( u , a ) ( ( ( ( u8 * ) a ) [ 0 ] = ( u8 ) ( ( u ) > > 8 ) ) , ( ( ( u8 * ) a ) [ 1 ] = ( u8 ) ( u ) ) )  *)
(* TC #define U32_TO_BE32 ( u , a ) ( ( ( ( u8 * ) a ) [ 0 ] = ( u8 ) ( ( u ) > > 24 ) ) , ( ( ( u8 * ) a ) [ 1 ] = ( u8 ) ( ( u ) > > 16 ) ) , ( ( ( u8 * ) a ) [ 2 ] = ( u8 ) ( ( u ) > > 8 ) ) , ( ( ( u8 * ) a ) [ 3 ] = (  *)
{$ENDIF}


(* T_DISCONNECT reason codes for SPX *)


{$DEFINE TLI_SPX_CONNECTION_FAILED}
Const TLI_SPX_CONNECTION_FAILED = $ed;
{$DEFINE TLI_SPX_CONNECTION_TERMINATED}
Const TLI_SPX_CONNECTION_TERMINATED = $ec;
{$DEFINE TLI_SPX_MALFORMED_PACKET}
Const TLI_SPX_MALFORMED_PACKET = $fe;
{$DEFINE TLI_SPX_PACKET_OVERFLOW}
Const TLI_SPX_PACKET_OVERFLOW = $fd;
{$DEFINE TLI_SPX_UNREACHABLE_DEST}
Const TLI_SPX_UNREACHABLE_DEST = $70;

(* t_rcvuderr uderr.error codes for IPX *)


{$DEFINE TLI_IPX_MALFORMED_ADDRESS}
Const TLI_IPX_MALFORMED_ADDRESS = $fe;
{$DEFINE TLI_IPX_PACKET_OVERFLOW}
Const TLI_IPX_PACKET_OVERFLOW = $fd;

{$ENDIF}



