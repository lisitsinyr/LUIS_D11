(****************************************************************************
*
* 1995 (C) Unpublished Copyright Novell, Inc. All Rights Reserved.
*
* No part of this file may be duplicated, revised, translated,
* localized or modified in any manner or compiled, linked or 
* uploaded or downloaded to or from any computer system without
* the prior written consent of Novell, Inc.
*
*****************************************************************************)


{$IFNDEF  NOVELL_LSAPI_INCLUDED }
    {$DEFINE NOVELL_LSAPI_INCLUDED}
    {$IFDEF WIN95}
    {$IFNDEF WIN32}
    {$DEFINE WIN32}
    {$ENDIF}
    {$IFNDEF _WINDOWS}
    {$DEFINE _WINDOWS}
    {$ENDIF}
    {$ENDIF}
    {$IFDEF MSWIN}
    {$IFNDEF _WINDOWS}
    {$DEFINE _WINDOWS}
    {$ENDIF}
    {$ENDIF}
    {$IFDEF _WINDOWS}
    {$I windows.inc}
    {$ENDIF}
    {$IFDEF  WINAPI }
        {$IFDEF WIN32}
        {$IFDEF _MSC_VER}
        {$IFDEF EXPORT_NLS}
        (* TC #define N_LSAPI_FUNCDEF __declspec ( dllexport ) WINAPI  *)
        {$ELSE}
        (* TC #define N_LSAPI_FUNCDEF __declspec ( dllimport ) WINAPI  *)
        {$ENDIF}
        {$ELSE}
        {$IFDEF EXPORT_NLS}
        (* TC #define N_LSAPI_FUNCDEF WINAPI _export  *)
        {$ELSE}
        (* TC #define N_LSAPI_FUNCDEF WINAPI _import  *)
        {$ENDIF}
        {$ENDIF}
        {$ELSE}
        {$IFDEF EXPORT_NLS}
        (* TC #define N_LSAPI_FUNCDEF WINAPI _export  *)
        {$ELSE}
        Type N_LSAPI_FUNCDEF = WINAPI;
        {$ENDIF}
        {$ENDIF}
    {$ELSE}
        {$DEFINE N_LSAPI_FUNCDEF}
    {$ENDIF}
    {$IFNDEF  FAR }
        {$DEFINE FAR}
    {$ENDIF}
    {$DEFINE LS_SUCCESS}
    Const LS_SUCCESS = $0;
    {$DEFINE LS_BAD_HANDLE}
    Const LS_BAD_HANDLE = $c0001001;
    {$DEFINE LS_INSUFFICIENT_UNITS}
    Const LS_INSUFFICIENT_UNITS = $c0001002;
    {$DEFINE LS_SYSTEM_UNAVAILABLE}
    Const LS_SYSTEM_UNAVAILABLE = $c0001003;
    {$DEFINE LS_LICENSE_TERMINATED}
    Const LS_LICENSE_TERMINATED = $c0001004;
    {$DEFINE LS_AUTHORIZATION_UNAVAILABLE}
    Const LS_AUTHORIZATION_UNAVAILABLE = $c0001005;
    {$DEFINE LS_LICENSE_UNAVAILABLE}
    Const LS_LICENSE_UNAVAILABLE = $c0001006;
    {$DEFINE LS_RESOURCES_UNAVAILABLE}
    Const LS_RESOURCES_UNAVAILABLE = $c0001007;
    {$DEFINE LS_NETWORK_UNAVAILABLE}
    Const LS_NETWORK_UNAVAILABLE = $c0001008;
    {$DEFINE LS_TEXT_UNAVAILABLE}
    Const LS_TEXT_UNAVAILABLE = $80001009;
    {$DEFINE LS_UNKNOWN_STATUS}
    Const LS_UNKNOWN_STATUS = $c000100a;
    {$DEFINE LS_BAD_INDEX}
    Const LS_BAD_INDEX = $c000100b;
    {$DEFINE LS_LICENSE_EXPIRED}
    Const LS_LICENSE_EXPIRED = $8000100c;
    {$DEFINE LS_BUFFER_TOO_SMALL}
    Const LS_BUFFER_TOO_SMALL = $c000100d;
    {$DEFINE LS_BAD_ARG}
    Const LS_BAD_ARG = $c000100e;
    {$DEFINE NLS_TOO_MANY_UNITS}
    Const NLS_TOO_MANY_UNITS = $80004001;
    {$DEFINE NLS_ALREADY_INSTALLED}
    Const NLS_ALREADY_INSTALLED = $C0004002;
    {$DEFINE LS_INFO_NONE}
    Const LS_INFO_NONE = $0;
    {$DEFINE LS_INFO_SYSTEM}
    Const LS_INFO_SYSTEM = $1;
    {$DEFINE LS_INFO_DATA}
    Const LS_INFO_DATA = $2;
    {$DEFINE LS_UPDATE_PERIOD}
    Const LS_UPDATE_PERIOD = $3;
    Type INT32 = long;
    Type UINT32 = nuint32;
    Type LS_STATUS_CODE  =   UINT32 ;
    Type LS_HANDLE  =   UINT32 ;
    Type LS_STR  =  nint8;
    Type LS_UCHAR  =  nuint8;
    Type LS_ULONG  =   UINT32 ;
    Type LS_LONG  =   INT32 ;
    Type LS_VOID  =  variant;
    Type
        tagLS_MSG_DIGEST = Record
            MessageDigest  :  Array[0..15] Of  LS_UCHAR ;
        End;
        LS_MSG_DIGEST = tagLS_MSG_DIGEST;
    Type
        tagLS_CHALLDATA = Record
            SecretIndex  :   LS_ULONG ;
            Random  :   LS_ULONG ;
            MsgDigest  :   LS_MSG_DIGEST ;
        End;
        LS_CHALLDATA = tagLS_CHALLDATA;
    Type
        tagLS_CHALLENGE = Record
            Protocol  :   LS_ULONG ;
            Size  :   LS_ULONG ;
            ChallengeData  :   LS_CHALLDATA ;
        End;
        LS_CHALLENGE = tagLS_CHALLENGE;
    {$DEFINE LS_DEFAULT_UNITS}
    Const LS_DEFAULT_UNITS = $FFFFFFFF;
    {$DEFINE LS_ANY}
    Const LS_ANY = '';
    {$DEFINE LS_ALL}
    Const LS_ALL = 'ALLSERVERS';
    {$DEFINE LS_USE_LAST}
    Const LS_USE_LAST = $0000FFFF;
    {$DEFINE LS_BASIC_PROTOCOL}
    Const LS_BASIC_PROTOCOL = $00000001;
    {$DEFINE LS_OUT_OF_BAND_PROTOCOL}
    Const LS_OUT_OF_BAND_PROTOCOL = $FFFFFFFF;
    Type LS_NULL = NULL;
    {$DEFINE NETWARE_LS}
    Const NETWARE_LS = 'NetWare LS';
    {$DEFINE LS_FIRST}
    Const LS_FIRST = 0;
    {$DEFINE LS_LAST}
    Const LS_LAST = $FFFFFFFF;
    {$IFDEF  __cplusplus }
        (* TC extern C *)
    {$ENDIF}
    (* TC extern C *)
    (* TC  LS_STR FAR * licenseSystem , LS_STR FAR * publisherName ,  *)
    (* TC  LS_STR FAR * productName , LS_STR FAR * version , LS_ULONG totUnitsReserved ,  *)
    (* TC  LS_STR FAR * logComment , LS_CHALLENGE FAR * challenge ,  *)
    (* TC  LS_ULONG FAR * totUnitsGranted , LS_HANDLE FAR * licenseHandle );  *)
    (* TC extern C *)
    (* TC  LS_HANDLE licenseHandle , LS_ULONG totUnitsConsumed ,  *)
    (* TC  LS_STR FAR * logComment );  *)
    (* TC extern C *)
    (* TC  LS_HANDLE licenseHandle );  *)
    (* TC extern C *)
    (* TC  LS_HANDLE licenseHandle , LS_ULONG totUnitsConsumed ,  *)
    (* TC  LS_ULONG totUnitsReserved , LS_STR FAR * logComment ,  *)
    (* TC  LS_CHALLENGE FAR * challenge , LS_ULONG FAR * totUnitsGranted );  *)
    (* TC extern C *)
    (* TC  LS_HANDLE licenseHandle , LS_STATUS_CODE value , LS_STR FAR * buffer ,  *)
    (* TC  LS_ULONG bufferSize );  *)
    (* TC extern C *)
    (* TC  LS_HANDLE licenseHandle , LS_ULONG information , LS_VOID FAR * infoBuffer ,  *)
    (* TC  LS_ULONG bufferSize , LS_ULONG FAR * actualBufferSize );  *)
    (* TC extern C *)
    (* TC  LS_ULONG index , LS_STR FAR * buffer );  *)
    {$IFDEF  __cplusplus }
        (* TC } *)
    {$ENDIF}
{$ENDIF}

