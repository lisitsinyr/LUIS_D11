(*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1991-1999  Microsoft Corporation

Module Name:

    lmmsg.h

Abstract:

    This file contains structures, function prototypes, and definitions
    for the NetMessage API.

[Environment:]

    User Mode - Win32

[Notes:]

    You must include NETCONS.H before this file, since this file depends
    on values defined in NETCONS.H.

--*)

unit LMMsg;

interface

uses
  Windows, LMCons;

//
// Function Prototypes
//

function NetMessageNameAdd (
   servername: PWideChar;      // in
   msgname: PWideChar          // in
): NET_API_STATUS; stdcall;

function NetMessageNameEnum (
    servername: PWideChar;     // in
    level: DWORD;              // in
    var bufptr: Pointer;       // out
    prefmaxlen: DWORD;         // in
    var entriesread: DWORD;    // out
    var totalentries: DWORD;   // out
    var resume_handle: DWORD   // in/out
): NET_API_STATUS; stdcall;

function NetMessageNameGetInfo (
    servername: PWideChar;    // in
    msgname: PWideChar;       // in
    level: DWORD;             // in
    var bufptr: Pointer
): NET_API_STATUS; stdcall;

function NetMessageNameDel (
    servername: PWideChar;    // in
    msgname: PWideChar        // in
): NET_API_STATUS; stdcall;

function NetMessageBufferSend (
    servername: PWideChar;    // in
    msgname: PWideChar;       // in
    fromname: PWideChar;      // in
    buf: Pointer;             // in
    buflen: DWORD             // in
): NET_API_STATUS; stdcall;

//
//  Data Structures
//

type
    PMSG_INFO_0 = ^TMSG_INFO_0;
    _MSG_INFO_0 = packed record
       msgi0_name: PWideChar;
    end;
    TMSG_INFO_0 = _MSG_INFO_0;

    PMSG_INFO_1 = ^TMSG_INFO_1;
    _MSG_INFO_1 = packed record
       msgi1_name: PWideChar;
       msgi1_forward_flag: DWORD;
       msgi1_forward: PWideChar;
    end;
    TMSG_INFO_1 = _MSG_INFO_1;

//
// Special Values and Constants
//

//
// Values for msgi1_forward_flag.
//

const
   MSGNAME_NOT_FORWARDED   = $00;       // Name not forwarded
   MSGNAME_FORWARDED_TO    = $04;    // Name forward to remote station
   MSGNAME_FORWARDED_FROM  = $10;    // Name forwarded from remote station

implementation

function NetMessageNameAdd; external netapi32;
function NetMessageNameEnum; external netapi32;
function NetMessageNameGetInfo; external netapi32;
function NetMessageNameDel; external netapi32;
function NetMessageBufferSend; external netapi32;

end.

