(*++ BUILD Version: 0006    // Increment this if a change has global effects

Copyright (c) 1991-1999  Microsoft Corporation

Module Name:

    lmwksta.h

Abstract:

    This file contains structures, function prototypes, and definitions
    for the NetWorkstation and NetWkstaTransport API.

Environment:

    User Mode - Win32
    Portable to any flat, 32-bit environment.  (Uses Win32 typedefs.)
    Requires ANSI C extensions: slash-slash comments, long external names.

Notes:

    You must include NETCONS.H before this file, since this file depends
    on values defined in NETCONS.H.

--*)


unit LMWksta;

interface

uses
  Windows, LMCons;

//
// User Class
//
//#include <lmuseflg.h>                   // Deletion force level flags

//
// Function Prototypes
//


function NetWkstaGetInfo (
   servername: PWideChar; // IN
   level: DWORD;          // IN
   bufptr: Pointer        // OUT
): NET_API_STATUS; stdcall;


function NetWkstaSetInfo (
   servername: PWideChar; // IN
   level: DWORD; // IN
   buffer: Pointer; // IN
   var parm_err: DWORD //  OUT LP: DWORD;
): NET_API_STATUS; stdcall;


function NetWkstaUserGetInfo (
   reserved: PWideChar; // IN
   level: DWORD; // IN
   bufptr: Pointer
): NET_API_STATUS; stdcall;


function NetWkstaUserSetInfo (
   reserved: PWideChar; // IN
   level: DWORD; // IN
   buf: Pointer; //  OUT LPBYTE
   var parm_err //  OUT LP: DWORD; OPTIONAL
): NET_API_STATUS; stdcall;


function NetWkstaUserEnum (
    servername: PWideChar;       //        IN  : PWideChar; OPTIONAL,
    level: DWORD;                //            IN  : DWORD;
    bufptr: Pointer;             //             OUT LPBYTE
    prefmaxlen: DWORD;           //     IN  : DWORD;
    var entriesread: DWORD;      //     OUT LP: DWORD;
    var totalentries: DWORD;     //     OUT LP: DWORD;
    var resumehandle: DWORD      // IN  OUT LP: DWORD; OPTIONAL
): NET_API_STATUS; stdcall;


function NetWkstaTransportAdd (
   servername: PWideChar;        // IN
   level: DWORD;                 // IN
   buf: Pointer;                 // in
   var parm_err: DWORD           //  OUT LP: DWORD;
): NET_API_STATUS; stdcall;


function NetWkstaTransportDel (
   servername: PWideChar;        // IN
   transportname: PWideChar;     // IN
   ucond: DWORD                  //  IN  : DWORD;
): NET_API_STATUS; stdcall;


function NetWkstaTransportEnum (
    servername: PWideChar;       // IN  : PWideChar;  OPTIONAL,
    level: DWORD;                //        IN  : DWORD;
    bufptr: Pointer;             //    OUT LPBYTE
    prefmaxlen: DWORD;           //    IN  : DWORD;
    var entriesread: DWORD;      //        OUT LP: DWORD;
    var totalentries: DWORD;     //        OUT LP: DWORD;
    var resumehandle: DWORD      // IN  OUT LP: DWORD; OPTIONAL
): NET_API_STATUS; stdcall;

//
//  Data Structures
//
type
//
// NetWkstaGetInfo and NetWkstaSetInfo
//

//
// NetWkstaGetInfo only.  System information - guest access
//
PWKSTA_INFO_100 = ^TWKSTA_INFO_100;
_WKSTA_INFO_100 = packed record
    wki100_platform_id   : DWORD;
    wki100_computername  : PWideChar;
    wki100_langroup      : PWideChar;
    wki100_ver_major     : DWORD;
    wki100_ver_minor     : DWORD
end;
TWKSTA_INFO_100 = _WKSTA_INFO_100;
{$EXTERNALSYM WKSTA_INFO_100}
WKSTA_INFO_100 = _WKSTA_INFO_100;

//
// NetWkstaGetInfo only.  System information - user access
//
PWKSTA_INFO_101 = ^TWKSTA_INFO_101;
_WKSTA_INFO_101 = packed record
   wki101_platform_id    : DWORD;
   wki101_computername   : PWideChar;
   wki101_langroup       : PWideChar;
   wki101_ver_major      : DWORD;
   wki101_ver_minor      : DWORD;
   wki101_lanroot        : PWideChar;
end;
TWKSTA_INFO_101 = _WKSTA_INFO_101;
{$EXTERNALSYM WKSTA_INFO_101}
WKSTA_INFO_101 = _WKSTA_INFO_101;

//
// NetWkstaGetInfo only.  System information - admin or operator access
//
PWKSTA_INFO_102 = ^TWKSTA_INFO_102;
_WKSTA_INFO_102 = packed record
   wki102_platform_id      : DWORD;
   wki102_computername     : PWideChar;
   wki102_langroup         : PWideChar;
   wki102_ver_major        : DWORD;
   wki102_ver_minor        : DWORD;
   wki102_lanroot          : PWideChar;
   wki102_logged_on_users  : DWORD;
end;
TWKSTA_INFO_102 = _WKSTA_INFO_102;
{$EXTERNALSYM WKSTA_INFO_102}
WKSTA_INFO_102 = _WKSTA_INFO_102;

//
// Down-level NetWkstaGetInfo and NetWkstaSetInfo.
//
// DOS specific workstation information -
//    admin or domain operator access
//
PWKSTA_INFO_302 = ^TWKSTA_INFO_302;
_WKSTA_INFO_302 = packed record
   wki302_char_wait                 : DWORD;
   wki302_collection_time           : DWORD;
   wki302_maximum_collection_count  : DWORD;
   wki302_keep_conn                 : DWORD;
   wki302_keep_search               : DWORD;
   wki302_max_cmds                  : DWORD;
   wki302_num_work_buf              : DWORD;
   wki302_siz_work_buf              : DWORD;
   wki302_max_wrk_cache             : DWORD;
   wki302_sess_timeout              : DWORD;
   wki302_siz_error                 : DWORD;
   wki302_num_alerts                : DWORD;
   wki302_num_services              : DWORD;
   wki302_errlog_sz                 : DWORD;
   wki302_print_buf_time            : DWORD;
   wki302_num_char_buf              : DWORD;
   wki302_siz_char_buf              : DWORD;
   wki302_wrk_heuristics            : PWideChar;
   wki302_mailslots                 : DWORD;
   wki302_num_dgram_buf             : DWORD;
end;
TWKSTA_INFO_302 = _WKSTA_INFO_302;
{$EXTERNALSYM WKSTA_INFO_302}
WKSTA_INFO_302 = _WKSTA_INFO_302;

//
// Down-level NetWkstaGetInfo and NetWkstaSetInfo
//
// OS/2 specific workstation information -
//    admin or domain operator access
//
PWKSTA_INFO_402 = ^TWKSTA_INFO_402;
_WKSTA_INFO_402 = packed record
   wki402_char_wait                 : DWORD;
   wki402_collection_time           : DWORD;
   wki402_maximum_collection_count  : DWORD;
   wki402_keep_conn                 : DWORD;
   wki402_keep_search               : DWORD;
   wki402_max_cmds                  : DWORD;
   wki402_num_work_buf              : DWORD;
   wki402_siz_work_buf              : DWORD;
   wki402_max_wrk_cache             : DWORD;
   wki402_sess_timeout              : DWORD;
   wki402_siz_error                 : DWORD;
   wki402_num_alerts                : DWORD;
   wki402_num_services              : DWORD;
   wki402_errlog_sz                 : DWORD;
   wki402_print_buf_time            : DWORD;
   wki402_num_char_buf              : DWORD;
   wki402_siz_char_buf              : DWORD;
   wki402_wrk_heuristics            : PWideChar;
   wki402_mailslots                 : DWORD;
   wki402_num_dgram_buf             : DWORD;
   wki402_max_threads               : DWORD;
end;
TWKSTA_INFO_402 = _WKSTA_INFO_402;
{$EXTERNALSYM WKSTA_INFO_402}
WKSTA_INFO_402 = _WKSTA_INFO_402;

//
// Same-level NetWkstaGetInfo and NetWkstaSetInfo.
//
// NT specific workstation information -
//    admin or domain operator access
//
PWKSTA_INFO_502 = ^TWKSTA_INFO_502;
_WKSTA_INFO_502 = packed record
   wki502_char_wait                               : DWORD;
   wki502_collection_time                         : DWORD;
   wki502_maximum_collection_count                : DWORD;
   wki502_keep_conn                               : DWORD;
   wki502_max_cmds                                : DWORD;
   wki502_sess_timeout                            : DWORD;
   wki502_siz_char_buf                            : DWORD;
   wki502_max_threads                             : DWORD;

   wki502_lock_quota                              : DWORD;
   wki502_lock_increment                          : DWORD;
   wki502_lock_maximum                            : DWORD;
   wki502_pipe_increment                          : DWORD;
   wki502_pipe_maximum                            : DWORD;
   wki502_cache_file_timeout                      : DWORD;
   wki502_dormant_file_limit                      : DWORD;
   wki502_read_ahead_throughput                   : DWORD;

   wki502_num_mailslot_buffers                    : DWORD;
   wki502_num_srv_announce_buffers                : DWORD;
   wki502_max_illegal_datagram_events             : DWORD;
   wki502_illegal_datagram_event_reset_frequency  : DWORD;
   wki502_log_election_packets                    : Longint;

   wki502_use_opportunistic_locking               : Longint;
   wki502_use_unlock_behind                       : Longint;
   wki502_use_close_behind                        : Longint;
   wki502_buf_named_pipes                         : Longint;
   wki502_use_lock_read_unlock                    : Longint;
   wki502_utilize_nt_caching                      : Longint;
   wki502_use_raw_read                            : Longint;
   wki502_use_raw_write                           : Longint;
   wki502_use_write_raw_data                      : Longint;
   wki502_use_encryption                          : Longint;
   wki502_buf_files_deny_write                    : Longint;
   wki502_buf_read_only_files                     : Longint;
   wki502_force_core_create_mode                  : Longint;
   wki502_use_512_byte_max_transfer               : Longint;
end;
TWKSTA_INFO_502 = _WKSTA_INFO_502;
{$EXTERNALSYM WKSTA_INFO_502}
WKSTA_INFO_502 = _WKSTA_INFO_502;


//
// The following info-levels are only valid for NetWkstaSetInfo
//

//
// The following levels are supported on down-level systems (LAN Man 2.x)
// as well as NT systems:
//
PWKSTA_INFO_1010 = ^TWKSTA_INFO_1010;
_WKSTA_INFO_1010 = packed record
   wki1010_char_wait  : DWORD;
end;
TWKSTA_INFO_1010 = _WKSTA_INFO_1010;
{$EXTERNALSYM WKSTA_INFO_1010}
WKSTA_INFO_1010 = _WKSTA_INFO_1010;

PWKSTA_INFO_1011 = ^TWKSTA_INFO_1011;
_WKSTA_INFO_1011 = packed record
   wki1011_collection_time   : DWORD;
end;
TWKSTA_INFO_1011 = _WKSTA_INFO_1011;
{$EXTERNALSYM WKSTA_INFO_1011}
WKSTA_INFO_1011 = _WKSTA_INFO_1011;

PWKSTA_INFO_1012 = ^TWKSTA_INFO_1012;
_WKSTA_INFO_1012 = packed record
   wki1012_maximum_collection_count   : DWORD;
end;
TWKSTA_INFO_1012 = _WKSTA_INFO_1012;
{$EXTERNALSYM WKSTA_INFO_1012}
WKSTA_INFO_1012 = _WKSTA_INFO_1012;

//
// The following level are supported on down-level systems (LAN Man 2.x)
// only:
//
PWKSTA_INFO_1027 = ^TWKSTA_INFO_1027;
_WKSTA_INFO_1027 = packed record
   wki1027_errlog_sz   : DWORD;
end;
TWKSTA_INFO_1027 = _WKSTA_INFO_1027;
{$EXTERNALSYM WKSTA_INFO_1027}
WKSTA_INFO_1027 = _WKSTA_INFO_1027;

PWKSTA_INFO_1028 = ^TWKSTA_INFO_1028;
_WKSTA_INFO_1028 = packed record
   wki1028_print_buf_time   : DWORD;
end;
TWKSTA_INFO_1028 = _WKSTA_INFO_1028;
{$EXTERNALSYM WKSTA_INFO_1028}
WKSTA_INFO_1028 = _WKSTA_INFO_1028;

PWKSTA_INFO_1032 = ^TWKSTA_INFO_1032;
_WKSTA_INFO_1032 = packed record
   wki1032_wrk_heuristics   : DWORD;
end;
TWKSTA_INFO_1032 = _WKSTA_INFO_1032;
{$EXTERNALSYM WKSTA_INFO_1032}
WKSTA_INFO_1032 = _WKSTA_INFO_1032;

//
// The following levels are settable on NT systems, and have no
// effect on down-level systems (i.e. LANMan 2.x) since these
// fields cannot be set on them:
//
PWKSTA_INFO_1013 = ^TWKSTA_INFO_1013;
_WKSTA_INFO_1013 = packed record
   wki1013_keep_conn   : DWORD;
end;
TWKSTA_INFO_1013 = _WKSTA_INFO_1013;
{$EXTERNALSYM WKSTA_INFO_1013}
WKSTA_INFO_1013 = _WKSTA_INFO_1013;

PWKSTA_INFO_1018 = ^TWKSTA_INFO_1018;
_WKSTA_INFO_1018 = packed record
   wki1018_sess_timeout   : DWORD;
end;
TWKSTA_INFO_1018 = _WKSTA_INFO_1018;
{$EXTERNALSYM WKSTA_INFO_1018}
WKSTA_INFO_1018 = _WKSTA_INFO_1018;

PWKSTA_INFO_1023 = ^TWKSTA_INFO_1023;
_WKSTA_INFO_1023 = packed record
   wki1023_siz_char_buf   : DWORD;
end;
TWKSTA_INFO_1023 = _WKSTA_INFO_1023;
{$EXTERNALSYM WKSTA_INFO_1023}
WKSTA_INFO_1023 = _WKSTA_INFO_1023;

PWKSTA_INFO_1033 = ^TWKSTA_INFO_1033;
_WKSTA_INFO_1033 = packed record
   wki1033_max_threads   : DWORD;
end;
TWKSTA_INFO_1033 = _WKSTA_INFO_1033;
{$EXTERNALSYM WKSTA_INFO_1033}
WKSTA_INFO_1033 = _WKSTA_INFO_1033;

//
// The following levels are only supported on NT systems:
//
PWKSTA_INFO_1041 = ^TWKSTA_INFO_1041;
_WKSTA_INFO_1041 = packed record
   wki1041_lock_quota  : DWORD;
end;
TWKSTA_INFO_1041 = _WKSTA_INFO_1041;
{$EXTERNALSYM WKSTA_INFO_1041}
WKSTA_INFO_1041 = _WKSTA_INFO_1041;

PWKSTA_INFO_1042 = ^TWKSTA_INFO_1042;
_WKSTA_INFO_1042 = packed record
   wki1042_lock_increment  : DWORD;
end;
TWKSTA_INFO_1042 = _WKSTA_INFO_1042;
{$EXTERNALSYM WKSTA_INFO_1042}
WKSTA_INFO_1042 = _WKSTA_INFO_1042;

PWKSTA_INFO_1043 = ^TWKSTA_INFO_1043;
_WKSTA_INFO_1043 = packed record
   wki1043_lock_maximum  : DWORD;
end;
TWKSTA_INFO_1043 = _WKSTA_INFO_1043;
{$EXTERNALSYM WKSTA_INFO_1043}
WKSTA_INFO_1043 = _WKSTA_INFO_1043;

PWKSTA_INFO_1044 = ^TWKSTA_INFO_1044;
_WKSTA_INFO_1044 = packed record
   wki1044_pipe_increment  : DWORD;
end;
TWKSTA_INFO_1044 = _WKSTA_INFO_1044;
{$EXTERNALSYM WKSTA_INFO_1044}
WKSTA_INFO_1044 = _WKSTA_INFO_1044;

PWKSTA_INFO_1045 = ^TWKSTA_INFO_1045;
_WKSTA_INFO_1045 = packed record
   wki1045_pipe_maximum  : DWORD;
end;
TWKSTA_INFO_1045 = _WKSTA_INFO_1045;
{$EXTERNALSYM WKSTA_INFO_1045}
WKSTA_INFO_1045 = _WKSTA_INFO_1045;

PWKSTA_INFO_1046 = ^TWKSTA_INFO_1046;
_WKSTA_INFO_1046 = packed record
   wki1046_dormant_file_limit  : DWORD;
end;
TWKSTA_INFO_1046 = _WKSTA_INFO_1046;
{$EXTERNALSYM WKSTA_INFO_1046}
WKSTA_INFO_1046 = _WKSTA_INFO_1046;

PWKSTA_INFO_1047 = ^TWKSTA_INFO_1047;
_WKSTA_INFO_1047 = packed record
   wki1047_cache_file_timeout  : DWORD;
end;
TWKSTA_INFO_1047 = _WKSTA_INFO_1047;
{$EXTERNALSYM WKSTA_INFO_1047}
WKSTA_INFO_1047 = _WKSTA_INFO_1047;

PWKSTA_INFO_1048 = ^TWKSTA_INFO_1048;
_WKSTA_INFO_1048 = packed record
   wki1048_use_opportunistic_locking  : Longint
end;
TWKSTA_INFO_1048 = _WKSTA_INFO_1048;
{$EXTERNALSYM WKSTA_INFO_1048}
WKSTA_INFO_1048 = _WKSTA_INFO_1048;

PWKSTA_INFO_1049 = ^TWKSTA_INFO_1049;
_WKSTA_INFO_1049 = packed record
   wki1049_use_unlock_behind  : Longint
end;
TWKSTA_INFO_1049 = _WKSTA_INFO_1049;
{$EXTERNALSYM WKSTA_INFO_1049}
WKSTA_INFO_1049 = _WKSTA_INFO_1049;

PWKSTA_INFO_1050 = ^TWKSTA_INFO_1050;
_WKSTA_INFO_1050 = packed record
   wki1050_use_close_behind  : Longint
end;
TWKSTA_INFO_1050 = _WKSTA_INFO_1050;
{$EXTERNALSYM WKSTA_INFO_1050}
WKSTA_INFO_1050 = _WKSTA_INFO_1050;

PWKSTA_INFO_1051 = ^TWKSTA_INFO_1051;
_WKSTA_INFO_1051 = packed record
   wki1051_buf_named_pipes  : Longint
end;
TWKSTA_INFO_1051 = _WKSTA_INFO_1051;
{$EXTERNALSYM WKSTA_INFO_1051}
WKSTA_INFO_1051 = _WKSTA_INFO_1051;

PWKSTA_INFO_1052 = ^TWKSTA_INFO_1052;
_WKSTA_INFO_1052 = packed record
   wki1052_use_lock_read_unlock  : Longint
end;
TWKSTA_INFO_1052 = _WKSTA_INFO_1052;
{$EXTERNALSYM WKSTA_INFO_1052}
WKSTA_INFO_1052 = _WKSTA_INFO_1052;

PWKSTA_INFO_1053 = ^TWKSTA_INFO_1053;
_WKSTA_INFO_1053 = packed record
   wki1053_utilize_nt_caching  : Longint
end;
TWKSTA_INFO_1053 = _WKSTA_INFO_1053;
{$EXTERNALSYM WKSTA_INFO_1053}
WKSTA_INFO_1053 = _WKSTA_INFO_1053;

PWKSTA_INFO_1054 = ^TWKSTA_INFO_1054;
_WKSTA_INFO_1054 = packed record
   wki1054_use_raw_read  : Longint
end;
TWKSTA_INFO_1054 = _WKSTA_INFO_1054;
{$EXTERNALSYM WKSTA_INFO_1054}
WKSTA_INFO_1054 = _WKSTA_INFO_1054;

PWKSTA_INFO_1055 = ^TWKSTA_INFO_1055;
_WKSTA_INFO_1055 = packed record
   wki1055_use_raw_write  : Longint
end;
TWKSTA_INFO_1055 = _WKSTA_INFO_1055;
{$EXTERNALSYM WKSTA_INFO_1055}
WKSTA_INFO_1055 = _WKSTA_INFO_1055;

PWKSTA_INFO_1056 = ^TWKSTA_INFO_1056;
_WKSTA_INFO_1056 = packed record
   wki1056_use_write_raw_data  : Longint
end;
TWKSTA_INFO_1056 = _WKSTA_INFO_1056;
{$EXTERNALSYM WKSTA_INFO_1056}
WKSTA_INFO_1056 = _WKSTA_INFO_1056;

PWKSTA_INFO_1057 = ^TWKSTA_INFO_1057;
_WKSTA_INFO_1057 = packed record
   wki1057_use_encryption  : Longint
end;
TWKSTA_INFO_1057 = _WKSTA_INFO_1057;
{$EXTERNALSYM WKSTA_INFO_1057}
WKSTA_INFO_1057 = _WKSTA_INFO_1057;

PWKSTA_INFO_1058 = ^TWKSTA_INFO_1058;
_WKSTA_INFO_1058 = packed record
   wki1058_buf_files_deny_write  : Longint
end;
TWKSTA_INFO_1058 = _WKSTA_INFO_1058;
{$EXTERNALSYM WKSTA_INFO_1058}
WKSTA_INFO_1058 = _WKSTA_INFO_1058;

PWKSTA_INFO_1059 = ^TWKSTA_INFO_1059;
_WKSTA_INFO_1059 = packed record
   wki1059_buf_read_only_files  : Longint
end;
TWKSTA_INFO_1059 = _WKSTA_INFO_1059;
{$EXTERNALSYM WKSTA_INFO_1059}
WKSTA_INFO_1059 = _WKSTA_INFO_1059;

PWKSTA_INFO_1060 = ^TWKSTA_INFO_1060;
_WKSTA_INFO_1060 = packed record
   wki1060_force_core_create_mode  : Longint
end;
TWKSTA_INFO_1060 = _WKSTA_INFO_1060;
{$EXTERNALSYM WKSTA_INFO_1060}
WKSTA_INFO_1060 = _WKSTA_INFO_1060;

PWKSTA_INFO_1061 = ^TWKSTA_INFO_1061;
_WKSTA_INFO_1061 = packed record
   wki1061_use_512_byte_max_transfer  : Longint
end;
TWKSTA_INFO_1061 = _WKSTA_INFO_1061;
{$EXTERNALSYM WKSTA_INFO_1061}
WKSTA_INFO_1061 = _WKSTA_INFO_1061;

PWKSTA_INFO_1062 = ^TWKSTA_INFO_1062;
_WKSTA_INFO_1062 = packed record
   wki1062_read_ahead_throughput  : DWORD;
end;
TWKSTA_INFO_1062 = _WKSTA_INFO_1062;
{$EXTERNALSYM WKSTA_INFO_1062}
WKSTA_INFO_1062 = _WKSTA_INFO_1062;


//
// NetWkstaUserGetInfo (local only) and NetWkstaUserEnum -
//     no access restrictions.
//
PWKSTA_USER_INFO_0 = ^TWKSTA_USER_INFO_0;
_WKSTA_USER_INFO_0 = packed record
   wkui0_username  : PWideChar;
end;
TWKSTA_USER_INFO_0 = _WKSTA_USER_INFO_0;
{$EXTERNALSYM WKSTA_USER_INFO_0}
WKSTA_USER_INFO_0 = _WKSTA_USER_INFO_0;

//
// NetWkstaUserGetInfo (local only) and NetWkstaUserEnum -
//     no access restrictions.
//
PWKSTA_USER_INFO_1 = ^TWKSTA_USER_INFO_1;
_WKSTA_USER_INFO_1 = packed record
   wkui1_username      : PWideChar;
   wkui1_logon_domain  : PWideChar;
   wkui1_oth_domains   : PWideChar;
   wkui1_logon_server  : PWideChar;
end;
TWKSTA_USER_INFO_1 = _WKSTA_USER_INFO_1;
{$EXTERNALSYM WKSTA_USER_INFO_1}
WKSTA_USER_INFO_1 = _WKSTA_USER_INFO_1;

//
// NetWkstaUserSetInfo - local access.
//
PWKSTA_USER_INFO_1101 = ^TWKSTA_USER_INFO_1101;
_WKSTA_USER_INFO_1101 = packed record
   wkui1101_oth_domains   : PWideChar;
end;
TWKSTA_USER_INFO_1101 = _WKSTA_USER_INFO_1101;
{$EXTERNALSYM WKSTA_USER_INFO_1101}
WKSTA_USER_INFO_1101 = _WKSTA_USER_INFO_1101;


//
// NetWkstaTransportAdd - admin access
//
PWKSTA_TRANSPORT_INFO_0 = ^TWKSTA_TRANSPORT_INFO_0;
_WKSTA_TRANSPORT_INFO_0 = packed record
   wkti0_quality_of_service  : DWORD;
   wkti0_number_of_vcs       : DWORD;
   wkti0_transport_name      : PWideChar;
   wkti0_transport_address   : PWideChar;
   wkti0_wan_ish             : Longint
end;
TWKSTA_TRANSPORT_INFO_0 = _WKSTA_TRANSPORT_INFO_0;
{$EXTERNALSYM WKSTA_TRANSPORT_INFO_0}
WKSTA_TRANSPORT_INFO_0 = _WKSTA_TRANSPORT_INFO_0;


//
// Special Values and Constants
//
const
//
//  Identifiers for use as NetWkstaSetInfo parmnum parameter
//

//
// One of these values indicates the parameter within an information
// structure that is invalid when ERROR_INVALID_PARAMETER is returned by
// NetWkstaSetInfo.
//

WKSTA_PLATFORM_ID_PARMNUM              = $100;
WKSTA_COMPUTERNAME_PARMNUM             = $1;
WKSTA_LANGROUP_PARMNUM                 = $2;
WKSTA_VER_MAJOR_PARMNUM                = $4;
WKSTA_VER_MINOR_PARMNUM                = $5;
WKSTA_LOGGED_ON_USERS_PARMNUM          = $6;
WKSTA_LANROOT_PARMNUM                  = $7;
WKSTA_LOGON_DOMAIN_PARMNUM             = $8;
WKSTA_LOGON_SERVER_PARMNUM             = $9;
WKSTA_CHARWAIT_PARMNUM                 = $10;  // Supported by down-level.
WKSTA_CHARTIME_PARMNUM                 = $11;  // Supported by down-level.
WKSTA_CHARCOUNT_PARMNUM                = $12;  // Supported by down-level.
WKSTA_KEEPCONN_PARMNUM                 = $13;
WKSTA_KEEPSEARCH_PARMNUM               = $14;
WKSTA_MAXCMDS_PARMNUM                  = $15;
WKSTA_NUMWORKBUF_PARMNUM               = $16;
WKSTA_MAXWRKCACHE_PARMNUM              = $17;
WKSTA_SESSTIMEOUT_PARMNUM              = $18;
WKSTA_SIZERROR_PARMNUM                 = $19;
WKSTA_NUMALERTS_PARMNUM                = $20;
WKSTA_NUMSERVICES_PARMNUM              = $21;
WKSTA_NUMCHARBUF_PARMNUM               = $22;
WKSTA_SIZCHARBUF_PARMNUM               = $23;
WKSTA_ERRLOGSZ_PARMNUM                 = $27;  // Supported by down-level.
WKSTA_PRINTBUFTIME_PARMNUM             = $28;  // Supported by down-level.
WKSTA_SIZWORKBUF_PARMNUM               = $29;
WKSTA_MAILSLOTS_PARMNUM                = $30;
WKSTA_NUMDGRAMBUF_PARMNUM              = $31;
WKSTA_WRKHEURISTICS_PARMNUM            = $32;  // Supported by down-level.
WKSTA_MAXTHREADS_PARMNUM               = $33;

WKSTA_LOCKQUOTA_PARMNUM                = $41;
WKSTA_LOCKINCREMENT_PARMNUM            = $42;
WKSTA_LOCKMAXIMUM_PARMNUM              = $43;
WKSTA_PIPEINCREMENT_PARMNUM            = $44;
WKSTA_PIPEMAXIMUM_PARMNUM              = $45;
WKSTA_DORMANTFILELIMIT_PARMNUM         = $46;
WKSTA_CACHEFILETIMEOUT_PARMNUM         = $47;
WKSTA_USEOPPORTUNISTICLOCKING_PARMNUM  = $48;
WKSTA_USEUNLOCKBEHIND_PARMNUM          = $49;
WKSTA_USECLOSEBEHIND_PARMNUM           = $50;
WKSTA_BUFFERNAMEDPIPES_PARMNUM         = $51;
WKSTA_USELOCKANDREADANDUNLOCK_PARMNUM  = $52;
WKSTA_UTILIZENTCACHING_PARMNUM         = $53;
WKSTA_USERAWREAD_PARMNUM               = $54;
WKSTA_USERAWWRITE_PARMNUM              = $55;
WKSTA_USEWRITERAWWITHDATA_PARMNUM      = $56;
WKSTA_USEENCRYPTION_PARMNUM            = $57;
WKSTA_BUFFILESWITHDENYWRITE_PARMNUM    = $58;
WKSTA_BUFFERREADONLYFILES_PARMNUM      = $59;
WKSTA_FORCECORECREATEMODE_PARMNUM      = $60;
WKSTA_USE512BYTESMAXTRANSFER_PARMNUM   = $61;
WKSTA_READAHEADTHRUPUT_PARMNUM         = $62;


//
// One of these values indicates the parameter within an information
// structure that is invalid when ERROR_INVALID_PARAMETER is returned by
// NetWkstaUserSetInfo.
//

WKSTA_OTH_DOMAINS_PARMNUM              = $101;


//
// One of these values indicates the parameter within an information
// structure that is invalid when ERROR_INVALID_PARAMETER is returned by
// NetWkstaTransportAdd.
//

TRANSPORT_QUALITYOFSERVICE_PARMNUM     = $201;
TRANSPORT_NAME_PARMNUM                 = $202;

implementation

function NetWkstaGetInfo       ; external netapi32;
function NetWkstaSetInfo       ; external netapi32;
function NetWkstaUserGetInfo   ; external netapi32;
function NetWkstaUserSetInfo   ; external netapi32;
function NetWkstaUserEnum      ; external netapi32;
function NetWkstaTransportAdd  ; external netapi32;
function NetWkstaTransportDel  ; external netapi32;
function NetWkstaTransportEnum ; external netapi32;

end.




