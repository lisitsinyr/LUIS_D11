(*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1991-1999  Microsoft Corporation

Module Name:

    lmapibuf.h

Abstract:

    This file contains information about NetApiBuffer APIs.

Environment:

    User Mode - Win32

Notes:

    You must include LMCONS.H before this file, since this file depends
    on values defined in LMCONS.H.

--*)

unit LMAPIbuf;

interface

uses Windows, LMCons;

//
// Function Prototypes
//

function NetApiBufferAllocate(
   ByteCount: DWORD; // IN
   Buffer: Pointer   // OUT
): NET_API_STATUS; stdcall;

function NetApiBufferFree (
   Buffer: Pointer   // IN
): NET_API_STATUS; stdcall;

function NetApiBufferReallocate(
   OldBuffer: Pointer; // IN OPTIONAL
   NewByteCount: DWORD; // IN
   NewBuffer: Pointer // OUT
): NET_API_STATUS; stdcall;

function NetApiBufferSize(
   Buffer: Pointer;   // IN
   var ByteCount: DWORD // OUT
): NET_API_STATUS; stdcall;

//
// The following private function will go away eventually.
// Call NetApiBufferAllocate instead.
//
function NetapipBufferAllocate (                 // Internal Function
   ByteCount: DWORD; // IN
   Buffer: Pointer   // OUT
): NET_API_STATUS; stdcall;

implementation

function NetApiBufferAllocate; external netapi32;
function NetApiBufferFree; external netapi32;
function NetApiBufferReallocate; external netapi32;
function NetApiBufferSize; external netapi32;
function NetapipBufferAllocate; external netapi32;

end.
