{=======================================================}
{ Project:                                              }
{         Delphi VCL Extensions (LU)                    }
{         Copyright (c) 2000 Central Bank Of Russia     }
{ Subject:                                              }
{         MAPIDEFS                                      }
{ Author:                                               }
{         Lisitsin Y.R.                                 }
{=======================================================}

unit LUMAPIDefs;

interface

(*
 *  M A P I D E F S . H
 *
 *  Definitions used by MAPI clients and service providers.
 *
 *  Copyright 1986-1996 Microsoft Corporation. All Rights Reserved.
 *)
const
 MAPI_NT_SERVICE      = $00010000;  //* Provider is being loaded in an NT service */

(* Simple data types *

#if !defined (MIDL_PASS) /* MIDL doesn't want to see these */

typedef WORD                WCHAR;

#ifdef UNICODE
typedef WCHAR               TCHAR;
#else
typedef char                TCHAR;
#endif

typedef WCHAR FAR *         LPWSTR;
typedef const WCHAR FAR *   LPCWSTR;
typedef TCHAR FAR *         LPTSTR;
typedef const TCHAR FAR *   LPCTSTR;
typedef BYTE FAR *          LPBYTE;
#endif /* defined MIDL_PASS */

typedef ULONG FAR *         LPULONG;

#ifndef __LHANDLE
 __LHANDLE
typedef unsigned long   LHANDLE, FAR * LPLHANDLE;
#endif

#if !defined(_WINBASE_) && !defined(_FILETIME_)
 _FILETIME_
typedef struct _FILETIME
{
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME, FAR * LPFILETIME;
#endif
*)

(*
 *  This flag is used in many different MAPI calls to signify that
 *  the object opened by the call should be modifiable (MAPI_MODIFY).
 *  If the flag MAPI_MAX_ACCESS is set, the object returned should be
 *  returned at the maximum access level allowed.  An additional
 *  property available on the object (PR_ACCESS_LEVEL) uses the same
 *  MAPI_MODIFY flag to say just what this new access level is.
 *)
const
   MAPI_MODIFY             = $00000001;

(*
 *  The following flags are used to indicate to the client what access
 *  level is permissible in the object. They appear in PR_ACCESS in
 *  message and folder objects as well as in contents and associated
 *  contents tables
 *)

 MAPI_ACCESS_MODIFY                  = 00000001;
 MAPI_ACCESS_READ                    = 00000002;
 MAPI_ACCESS_DELETE                  = 00000004;
 MAPI_ACCESS_CREATE_HIERARCHY        = 00000008;
 MAPI_ACCESS_CREATE_CONTENTS         = 00000010;
 MAPI_ACCESS_CREATE_ASSOCIATED       = 00000020;

(*
 *  The MAPI_UNICODE flag is used in many different MAPI calls to signify
 *  that strings passed through the interface are in Unicode (a 16-bit
 *  character set). The default is an 8-bit character set.
 *
 *  The value fMapiUnicode can be used as the 'normal' value for
 *  that bit, given the application's default character set.
 *)

 MAPI_UNICODE                        = $80000000;

{$ifdef UNICODE}
 fMapiUnicode            = MAPI_UNICODE;
{$else}
 fMapiUnicode            = 0;
{$endif}

//* successful HRESULT */
 hrSuccess               = 0;

//* Recipient types */
 MAPI_ORIG      = 0;           //* Recipient is message originator          */
 MAPI_TO        = 1;           //* Recipient is a primary recipient         */
 MAPI_CC        = 2;           //* Recipient is a copy recipient            */
 MAPI_BCC       = 3;           //* Recipient is blind copy recipient        */
 MAPI_P1        = $10000000;   //* Recipient is a P1 resend recipient       */
 MAPI_SUBMITTED = $80000000;   //* Recipient is already processed         */
 MAPI_AUTHORIZE = 4;           //* recipient is a CMC authorizing user      */
 MAPI_DISCRETE  = $10000000;   //* Recipient is a P1 resend recipient       */

//* Bit definitions for abFlags[0] of ENTRYID */
 MAPI_SHORTTERM          = $80;
 MAPI_NOTRECIP           = $40;
 MAPI_THISSESSION        = $20;
 MAPI_NOW                = $10;
 MAPI_NOTRESERVED        = $08;

//* Bit definitions for abFlags[1] of ENTRYID */
 MAPI_COMPOUND           = $80;

(*
 * Constants for one-off entry ID:
 * The MAPIUID that identifies the one-off provider;
 * the flag that defines whether the embedded strings are Unicode;
 * the flag that specifies whether the recipient gets TNEF or not.
 *)

// MAPI_ONE_OFF_UID { = $81, = $2b, = $1f, = $a4, = $be, = $a3, = $10, = $19, \
//                           = $9d, = $6e, = $00, = $dd, = $01, = $0f, = $54, = $02 }
 MAPI_ONE_OFF_UNICODE        = $8000;
 MAPI_ONE_OFF_NO_RICH_INFO   = $0001;

//* Object type */

 MAPI_STORE       = $00000001;    //* Message Store */
 MAPI_ADDRBOOK    = $00000002;    //* Address Book */
 MAPI_FOLDER      = $00000003;    //* Folder */
 MAPI_ABCONT      = $00000004;    //* Address Book Container */
 MAPI_MESSAGE     = $00000005;    //* Message */
 MAPI_MAILUSER    = $00000006;    //* Individual Recipient */
 MAPI_ATTACH      = $00000007;    //* Attachment */
 MAPI_DISTLIST    = $00000008;    //* Distribution List Recipient */
 MAPI_PROFSECT    = $00000009;    //* Profile Section */
 MAPI_STATUS      = $0000000A;    //* Status Object */
 MAPI_SESSION     = $0000000B;    //* Session */
 MAPI_FORMINFO    = $0000000C;    //* Form Information */


(*
 *  Maximum length of profile names and passwords, not including
 *  the null termination character.
 *)
 cchProfileNameMax   = 64;
 cchProfilePassMax   = 64;


//* Property Types */

const
 MV_FLAG         = $00001000;          //* Multi-value flag */

 PT_UNSPECIFIED  = $00000000;    //* (Reserved for interface use) type doesn't matter to caller */
 PT_NULL         = $00000001;    //* NULL property value */
 PT_I2           = $00000002;    //* Signed 16-bit value */
 PT_LONG         = $00000003;    //* Signed 32-bit value */
 PT_R4           = $00000004;    //* 4-byte floating point */
 PT_DOUBLE       = $00000005;    //* Floating point double */
 PT_CURRENCY     = $00000006;    //* Signed 64-bit int (decimal w/    4 digits right of decimal pt) */
 PT_APPTIME      = $00000007;    //* Application time */
 PT_ERROR        = $0000000A;    //* 32-bit error value */
 PT_BOOLEAN      = $0000000B;    //* 16-bit boolean (non-zero true) */
 PT_OBJECT       = $0000000D;    //* Embedded object in a property */
 PT_I8           = $00000014;    //* 8-byte signed integer */
 PT_STRING8      = $0000001E;    //* Null terminated 8-bit character string */
 PT_UNICODE      = $0000001F;    //* Null terminated Unicode string */
 PT_SYSTIME      = $00000040;    //* FILETIME 64-bit int w/ number of 100ns periods since Jan 1,1601 */
 PT_CLSID        = $00000048;    //* OLE GUID */
 PT_BINARY       = $00000102;    //* Uninterpreted (counted byte array) */

//* Alternate property type names for ease of use */
 PT_SHORT        = PT_I2;
 PT_I4           = PT_LONG;
 PT_FLOAT        = PT_R4;
 PT_R8           = PT_DOUBLE;
 PT_LONGLONG     = PT_I8;

(*
 *  The type of a MAPI-defined string property is indirected, so
 *  that it defaults to Unicode string on a Unicode platform and to
 *  String8 on an ANSI or DBCS platform.
 *
 *  Macros are defined here both for the property type, and for the
 *  field of the property value structure which should be
 *  dereferenced to obtain the string pointer.
 *)

const
{$ifdef  UNICODE}
   PT_TSTRING         = PT_UNICODE;
   PT_MV_TSTRING      = MV_FLAG+PT_UNICODE;
//   LPSZ               = lpszW
//   LPPSZ              = lppszW
//   MVSZ               = MVszW
{$else}
   PT_TSTRING         = PT_STRING8;
   PT_MV_TSTRING      = MV_FLAG+PT_STRING8;
//   LPSZ               = lpszA
//   LPPSZ              = lppszA
//   MVSZ               = MVszA
{$endif}

(* Property Tags
 *
 * By convention, MAPI never uses 0 or FFFF as a property ID.
 * Use as null values, initializers, sentinels, or what have you.
 *)

// PROP_TYPE_MASK          = $0000FFFF) /* Mask for Property type */
// PROP_TYPE(ulPropTag)    ((ulPropTag))&PROP_TYPE_MASK)
// PROP_ID(ulPropTag)      ((ulPropTag))>>16)
// PROP_TAG(ulPropType,ulPropID)   (((ulPropID))<<16)|(ulPropType)))
 PROP_ID_NULL            = 0;
 PROP_ID_INVALID         = $FFFF;
// PR_NULL                 PROP_TAG( PT_NULL, PROP_ID_NULL)
// CHANGE_PROP_TYPE(ulPropTag, ulPropType) = $FFFF0000 & ulPropTag) | ulPropType)


//* Multi-valued Property Types */

 PT_MV_I2         = MV_FLAG+PT_I2;
 PT_MV_LONG       = MV_FLAG+PT_LONG;
 PT_MV_R4         = MV_FLAG+PT_R4;
 PT_MV_DOUBLE     = MV_FLAG+PT_DOUBLE;
 PT_MV_CURRENCY   = MV_FLAG+PT_CURRENCY;
 PT_MV_APPTIME    = MV_FLAG+PT_APPTIME;
 PT_MV_SYSTIME    = MV_FLAG+PT_SYSTIME;
 PT_MV_STRING8    = MV_FLAG+PT_STRING8;
 PT_MV_BINARY     = MV_FLAG+PT_BINARY;
 PT_MV_UNICODE    = MV_FLAG+PT_UNICODE;
 PT_MV_CLSID      = MV_FLAG+PT_CLSID;
 PT_MV_I8         = MV_FLAG+PT_I8;

//* Alternate property type names for ease of use */
 PT_MV_SHORT      = PT_MV_I2;
 PT_MV_I4         = PT_MV_LONG;
 PT_MV_FLOAT      = PT_MV_R4;
 PT_MV_R8         = PT_MV_DOUBLE;
 PT_MV_LONGLONG   = PT_MV_I8;

(*
 *  Property type reserved bits
 *
 *  MV_INSTANCE is used as a flag in table operations to request
 *  that a multi-valued property be presented as a single-valued
 *  property appearing in multiple rows.
 *)

 MV_INSTANCE     = $2000;
 MVI_FLAG        = MV_FLAG + MV_INSTANCE;

implementation

end.

