(*++ BUILD Version: 0002    // Increment this if a change has global effects

Copyright (c) 1991-1999  Microsoft Corporation

Module Name:

    lmaccess.h

Abstract:

    This file contains structures, function prototypes, and definitions
    for the NetUser, NetUserModals, NetGroup, NetAccess, and NetLogon API.

Environment:

    User Mode - Win32

Notes:

    You must include NETCONS.H before this file, since this file depends
    on values defined in NETCONS.H.

--*)

unit LMAccess;

interface

uses
  Windows, LMCons;

//
// User Class
//

//
// Function Prototypes - User
//

function NetUserAdd (
   servername: PWideChar;       // IN OPTIONAL
   level: DWord;                // IN
   buf: Pointer;                // IN
   var parm_err: DWord          // OUT OPTIONAL
): NET_API_STATUS; stdcall;

function NetUserEnum (
   servername: PWideChar;       // IN OPTIONAL
   level: DWord;                // IN
   filter: DWord;               // IN
   var bufptr: Pointer;         // OUT
   prefmaxlen: DWord;           // IN
   var entriesread: DWord;      // OUT
   var totalentries: DWord;     // OUT
   var resume_handle: DWord     // IN OPTIONAL
): NET_API_STATUS; stdcall;

function NetUserGetInfo (
   servername: PWideChar;       // IN OPTIONAL
   username: PWideChar;         // IN
   level: DWord;                // IN
   var bufptr: Pointer          // OUT
): NET_API_STATUS; stdcall;

function NetUserSetInfo (
   servername: PWideChar;       // IN OPTIONAL
   username: PWideChar;         // IN
   level: DWord;                // IN
   buf: Pointer;                // IN
   var parm_err: DWord          // OUT OPTIONAL
): NET_API_STATUS; stdcall;

function NetUserDel (
   servername: PWideChar;       // IN OPTIONAL
   username: PWideChar          // IN
): NET_API_STATUS; stdcall;

function NetUserGetGroups (
   servername: PWideChar;       // IN OPTIONAL
   username: PWideChar;         // IN
   level: DWord;                // IN
   var bufptr: Pointer;         // OUT
   prefmaxlen: DWord;           // IN
   var entriesread: DWord;      // OUT
   var totalentries: DWord      // OUT
): NET_API_STATUS; stdcall;

function NetUserSetGroups (
   servername: PWideChar;       // IN OPTIONAL
   username: PWideChar;         // IN
   level: DWord;                // IN
   buf: Pointer;                // IN
   num_entries: DWord           // IN
): NET_API_STATUS; stdcall;

function NetUserGetLocalGroups (
   servername: PWideChar;       // IN OPTIONAL
   username: PWideChar;         // IN
   level: DWord;                // IN
   flags: DWord;                // IN
   var bufptr: Pointer;         // OUT
   prefmaxlen: DWord;           // IN
   var entriesread: DWord;      // OUT
   var totalentries: DWord      // OUT
): NET_API_STATUS; stdcall;

function NetUserModalsGet (
   servername: PWideChar;       // IN OPTIONAL
   level: DWord;                // IN
   var bufptr: Pointer          // OUT
): NET_API_STATUS; stdcall;

function NetUserModalsSet (
   servername: PWideChar;       // IN OPTIONAL
   level: DWord;                // IN
   buf: Pointer;                // IN
   var parm_err: DWord          // OUT OPTIONAL
): NET_API_STATUS; stdcall;

function NetUserChangePassword (
   domainname: PWideChar;       // IN OPTIONAL
   username: PWideChar;         // IN OPTIONAL
   oldpassword: PWideChar;      // IN
   newpassword: PWideChar       // IN
): NET_API_STATUS; stdcall;

//
//  Data Structures - User
//
type
   PUSERINFO0 = ^TUSERINFO0;
   _USER_INFO_0 = packed record
      usri0_name: PWideChar;
   end;
   TUSERINFO0 = _USER_INFO_0;
   {$EXTERNALSYM USER_INFO_0}
   USER_INFO_0 = _USER_INFO_0;

   PUSERINFO1 = ^TUSERINFO1;
   _USER_INFO_1 = packed record
      usri1_name: PWideChar;
      usri1_password: PWideChar;
      usri1_password_age: DWord;
      usri1_priv: DWord;
      usri1_home_dir: PWideChar;
      usri1_comment: PWideChar;
      usri1_flags: DWord;
      usri1_script_path: PWideChar;
   end;
   TUSERINFO1 = _USER_INFO_1;
   {$EXTERNALSYM USER_INFO_1}
   USER_INFO_1 = _USER_INFO_1;

   PUSERINFO2 = ^TUSERINFO2;
   _USER_INFO_2 = packed record
      usri2_name: PWideChar;
      usri2_password: PWideChar;
      usri2_password_age: DWord;
      usri2_priv: DWord;
      usri2_home_dir: PWideChar;
      usri2_comment: PWideChar;
      usri2_flags: DWord;
      usri2_script_path: PWideChar;
      usri2_auth_flags: DWord;
      usri2_full_name: PWideChar;
      usri2_usr_comment: PWideChar;
      usri2_parms: PWideChar;
      usri2_workstations: PWideChar;
      usri2_last_logon: DWord;
      usri2_last_logoff: DWord;
      usri2_acct_expires: DWord;
      usri2_max_storage: DWord;
      usri2_units_per_week: DWord;
      usri2_logon_hours: PByte;
      usri2_bad_pw_count: DWord;
      usri2_num_logons: DWord;
      usri2_logon_server: PWideChar;
      usri2_country_code: DWord;
      usri2_code_page: DWord;
   end;
   TUSERINFO2 = _USER_INFO_2;
   {$EXTERNALSYM USER_INFO_2}
   USER_INFO_2 = _USER_INFO_2;

   PUSERINFO3 = ^TUSERINFO3;
   _USER_INFO_3 = packed record
      usri3_name: PWideChar;
      usri3_password: PWideChar;
      usri3_password_age: DWord;
      usri3_priv: DWord;
      usri3_home_dir: PWideChar;
      usri3_comment: PWideChar;
      usri3_flags: DWord;
      usri3_script_path: PWideChar;
      usri3_auth_flags: DWord;
      usri3_full_name: PWideChar;
      usri3_usr_comment: PWideChar;
      usri3_parms: PWideChar;
      usri3_workstations: PWideChar;
      usri3_last_logon: DWord;
      usri3_last_logoff: DWord;
      usri3_acct_expires: DWord;
      usri3_max_storage: DWord;
      usri3_units_per_week: DWord;
      usri3_logon_hours: PByte;
      usri3_bad_pw_count: DWord;
      usri3_num_logons: DWord;
      usri3_logon_server: PWideChar;
      usri3_country_code: DWord;
      usri3_code_page: DWord;
      usri3_user_id: DWord;
      usri3_primary_group_id: DWord;
      usri3_profile: PWideChar;
      usri3_home_dir_drive: PWideChar;
      usri3_password_expired: DWord;
   end;
   TUSERINFO3 = _USER_INFO_3;
   {$EXTERNALSYM USER_INFO_3}
   USER_INFO_3 = _USER_INFO_3;

   PUSERINFO10 = ^TUSERINFO10;
   _USER_INFO_10 = packed record
      usri10_name: PWideChar;
      usri10_comment: PWideChar;
      usri10_usr_comment: PWideChar;
      usri10_full_name: PWideChar;
   end;
   TUSERINFO10 = _USER_INFO_10;
   {$EXTERNALSYM USER_INFO_10}
   USER_INFO_10 = _USER_INFO_10;

   PUSERINFO11 = ^TUSERINFO11;
   _USER_INFO_11 = packed record
      usri11_name: PWideChar;
      usri11_comment: PWideChar;
      usri11_usr_comment: PWideChar;
      usri11_full_name: PWideChar;
      usri11_priv: DWord;
      usri11_auth_flags: DWord;
      usri11_password_age: DWord;
      usri11_home_dir: PWideChar;
      usri11_parms: PWideChar;
      usri11_last_logon: DWord;
      usri11_last_logoff: DWord;
      usri11_bad_pw_count: DWord;
      usri11_num_logons: DWord;
      usri11_logon_server: PWideChar;
      usri11_country_code: DWord;
      usri11_workstations: PWideChar;
      usri11_max_storage: DWord;
      usri11_units_per_week: DWord;
      usri11_logon_hours: PByte;
      usri11_code_page: DWord;
   end;
   TUSERINFO11 = _USER_INFO_11;
   {$EXTERNALSYM USER_INFO_11}
   USER_INFO_11 = _USER_INFO_11;

   PUSERINFO20 = ^TUSERINFO20;
   _USER_INFO_20 = packed record
      usri20_name: PWideChar;
      usri20_full_name: PWideChar;
      usri20_comment: PWideChar;
      usri20_flags: DWord;
      usri20_user_id: DWord;
   end;
   TUSERINFO20 = _USER_INFO_20;
   {$EXTERNALSYM USER_INFO_20}
   USER_INFO_20 = _USER_INFO_20;

   PUSERINFO21 = ^TUSERINFO21;
   _USER_INFO_21 = packed record
      usri21_password: array [1..ENCRYPTED_PWLEN] of char;
   end;
   TUSERINFO21 = _USER_INFO_21;
   {$EXTERNALSYM USER_INFO_21}
   USER_INFO_21 = _USER_INFO_21;

   PUSERINFO22 = ^TUSERINFO22;
   _USER_INFO_22 = packed record
      usri22_name: PWideChar;
      usri22_password: array [1..ENCRYPTED_PWLEN] of Char;
      usri22_password_age: DWord;
      usri22_priv: DWord;
      usri22_home_dir: PWideChar;
      usri22_comment: PWideChar;
      usri22_flags: DWord;
      usri22_script_path: PWideChar;
      usri22_auth_flags: DWord;
      usri22_full_name: PWideChar;
      usri22_usr_comment: PWideChar;
      usri22_parms: PWideChar;
      usri22_workstations: PWideChar;
      usri22_last_logon: DWord;
      usri22_last_logoff: DWord;
      usri22_acct_expires: DWord;
      usri22_max_storage: DWord;
      usri22_units_per_week: DWord;
      usri22_logon_hours: PByte;
      usri22_bad_pw_count: DWord;
      usri22_num_logons: DWord;
      usri22_logon_server: PWideChar;
      usri22_country_code: DWord;
      usri22_code_page: DWord;
   end;
   TUSERINFO22 = _USER_INFO_22;
   {$EXTERNALSYM USER_INFO_22}
   USER_INFO_22 = _USER_INFO_22;
(*
   _USER_INFO_1003 = packed record
      usri1003_password: PWideChar;

   _USER_INFO_1005 = packed record
      usri1005_priv: DWord;

   _USER_INFO_1006 = packed record
      usri1006_home_dir: PWideChar;

   _USER_INFO_1007 = packed record
      usri1007_comment: PWideChar;

   _USER_INFO_1008 = packed record
      usri1008_flags: DWord;

   _USER_INFO_1009 = packed record
      usri1009_script_path: PWideChar;

   _USER_INFO_1010 = packed record
      usri1010_auth_flags: DWord;

   _USER_INFO_1011 = packed record
      usri1011_full_name: PWideChar;

   _USER_INFO_1012 = packed record
      usri1012_usr_comment: PWideChar;

   _USER_INFO_1013 = packed record
      usri1013_parms: PWideChar;

   _USER_INFO_1014 = packed record
      usri1014_workstations: PWideChar;

   _USER_INFO_1017 = packed record
      usri1017_acct_expires: DWord;

   _USER_INFO_1018 = packed record
      usri1018_max_storage: DWord;

   _USER_INFO_1020 = packed record
     usri1020_units_per_week: DWord;
    LPBYTE  usri1020_logon_hours;

   _USER_INFO_1023 = packed record
      usri1023_logon_server: PWideChar;

   _USER_INFO_1024 = packed record
      usri1024_country_code: DWord;

   _USER_INFO_1025 = packed record
      usri1025_code_page: DWord;

   _USER_INFO_1051 = packed record
      usri1051_primary_group_id: DWord;

   _USER_INFO_1052 = packed record
      usri1052_profile: PWideChar;

   _USER_INFO_1053 = packed record
      usri1053_home_dir_drive: PWideChar;
*)

//
//  Data Structures - User Modals
//

   PUSERMODALSINFO0 = ^TUSERMODALSINFO0;
   _USER_MODALS_INFO_0 = packed record
      usrmod0_min_passwd_len: DWord;
      usrmod0_max_passwd_age: DWord;
      usrmod0_min_passwd_age: DWord;
      usrmod0_force_logoff: DWord;
      usrmod0_password_hist_len: DWord;
   end;
   TUSERMODALSINFO0 = _USER_MODALS_INFO_0;
   {$EXTERNALSYM USER_MODALS_INFO_0}
   USER_MODALS_INFO_0 = _USER_MODALS_INFO_0;

   PUSERMODALSINFO1 = ^TUSERMODALSINFO1;
   _USER_MODALS_INFO_1 = packed record
      usrmod1_role: DWord;
      usrmod1_primary: PWideChar;
   end;
   TUSERMODALSINFO1 = _USER_MODALS_INFO_1;
   {$EXTERNALSYM USER_MODALS_INFO_1}
   USER_MODALS_INFO_1 = _USER_MODALS_INFO_1;

   PUSERMODALSINFO2 = ^TUSERMODALSINFO2;
   _USER_MODALS_INFO_2 = packed record
      usrmod2_domain_name: PWideChar;
      usrmod2_domain_id: PSid;
   end;
   TUSERMODALSINFO2 = _USER_MODALS_INFO_2;
   {$EXTERNALSYM USER_MODALS_INFO_2}
   USER_MODALS_INFO_2 = _USER_MODALS_INFO_2;

   PUSERMODALSINFO3 = ^TUSERMODALSINFO3;
   _USER_MODALS_INFO_3 = packed record
      usrmod3_lockout_duration: DWord;
      usrmod3_lockout_observation_window: DWord;
      usrmod3_lockout_threshold: DWord;
   end;
   TUSERMODALSINFO3 = _USER_MODALS_INFO_3;
   {$EXTERNALSYM USER_MODALS_INFO_3}
   USER_MODALS_INFO_3 = _USER_MODALS_INFO_3;
(*
   _USER_MODALS_INFO_1001 = packed record
      usrmod1001_min_passwd_len: DWord;

   _USER_MODALS_INFO_1002 = packed record
      usrmod1002_max_passwd_age: DWord;

   _USER_MODALS_INFO_1003 = packed record
      usrmod1003_min_passwd_age: DWord;

   _USER_MODALS_INFO_1004 = packed record
      usrmod1004_force_logoff: DWord;

   _USER_MODALS_INFO_1005 = packed record
      usrmod1005_password_hist_len: DWord;

   _USER_MODALS_INFO_1006 = packed record
      usrmod1006_role: DWord;

   _USER_MODALS_INFO_1007 = packed record
      usrmod1007_primary: PWideChar;
*)
//
// Special Values and Constants - User
//

const

//
//  Bit masks for field usriX_flags of USER_INFO_X (X = 0/1).
//

   UF_SCRIPT                          = $0001;
   UF_ACCOUNTDISABLE                  = $0002;
   UF_HOMEDIR_REQUIRED                = $0008;
   UF_LOCKOUT                         = $0010;
   UF_PASSWD_NOTREQD                  = $0020;
   UF_PASSWD_CANT_CHANGE              = $0040;
   UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED = $0080;

//
// Account type bits as part of usri_flags.
//

   UF_TEMP_DUPLICATE_ACCOUNT       = $0100;
   UF_NORMAL_ACCOUNT               = $0200;
   UF_INTERDOMAIN_TRUST_ACCOUNT    = $0800;
   UF_WORKSTATION_TRUST_ACCOUNT    = $1000;
   UF_SERVER_TRUST_ACCOUNT         = $2000;
   UF_MACHINE_ACCOUNT_MASK = (
      UF_INTERDOMAIN_TRUST_ACCOUNT or
      UF_WORKSTATION_TRUST_ACCOUNT or
      UF_SERVER_TRUST_ACCOUNT
   );
   UF_ACCOUNT_TYPE_MASK = (
      UF_TEMP_DUPLICATE_ACCOUNT or
      UF_NORMAL_ACCOUNT or
      UF_INTERDOMAIN_TRUST_ACCOUNT or
      UF_WORKSTATION_TRUST_ACCOUNT or
      UF_SERVER_TRUST_ACCOUNT
   );
   UF_DONT_EXPIRE_PASSWD           = $10000;
   UF_MNS_LOGON_ACCOUNT            = $20000;
   UF_SMARTCARD_REQUIRED           = $40000;
   UF_TRUSTED_FOR_DELEGATION       = $80000;
   UF_NOT_DELEGATED                = $100000;
   UF_USE_DES_KEY_ONLY             = $200000;
   UF_DONT_REQUIRE_PREAUTH         = $400000;
   UF_SETTABLE_BITS = (
      UF_SCRIPT or
      UF_ACCOUNTDISABLE or
      UF_LOCKOUT or
      UF_HOMEDIR_REQUIRED  or
      UF_PASSWD_NOTREQD or
      UF_PASSWD_CANT_CHANGE or
      UF_ACCOUNT_TYPE_MASK or
      UF_DONT_EXPIRE_PASSWD or
      UF_MNS_LOGON_ACCOUNT or
      UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED or
      UF_SMARTCARD_REQUIRED or
      UF_TRUSTED_FOR_DELEGATION or
      UF_NOT_DELEGATED or
      UF_USE_DES_KEY_ONLY  or
      UF_DONT_REQUIRE_PREAUTH
   );

//
// bit masks for the NetUserEnum filter parameter.
//

   FILTER_TEMP_DUPLICATE_ACCOUNT        = $0001;
   FILTER_NORMAL_ACCOUNT                = $0002;
//    FILTER_PROXY_ACCOUNT              = $0004;
   FILTER_INTERDOMAIN_TRUST_ACCOUNT     = $0008;
   FILTER_WORKSTATION_TRUST_ACCOUNT     = $0010;
   FILTER_SERVER_TRUST_ACCOUNT          = $0020;

//
// bit masks for the NetUserGetLocalGroups flags
//
   LG_INCLUDE_INDIRECT                  = $0001;

//
//  Bit masks for field usri2_auth_flags of USER_INFO_2.
//

   AF_OP_PRINT              = $1;
   AF_OP_COMM               = $2;
   AF_OP_SERVER             = $4;
   AF_OP_ACCOUNTS           = $8;
   AF_SETTABLE_BITS         = (
      AF_OP_PRINT or
      AF_OP_COMM or
      AF_OP_SERVER or
      AF_OP_ACCOUNTS
   );

//
//  UAS role manifests under NETLOGON
//

   UAS_ROLE_STANDALONE      = 0;
   UAS_ROLE_MEMBER          = 1;
   UAS_ROLE_BACKUP          = 2;
   UAS_ROLE_PRIMARY         = 3;

//
//  Values for ParmError for NetUserSetInfo.
//

   USER_NAME_PARMNUM                = 1;
   USER_PASSWORD_PARMNUM            = 3;
   USER_PASSWORD_AGE_PARMNUM        = 4;
   USER_PRIV_PARMNUM                = 5;
   USER_HOME_DIR_PARMNUM            = 6;
   USER_COMMENT_PARMNUM             = 7;
   USER_FLAGS_PARMNUM               = 8;
   USER_SCRIPT_PATH_PARMNUM         = 9;
   USER_AUTH_FLAGS_PARMNUM          = 10;
   USER_FULL_NAME_PARMNUM           = 11;
   USER_USR_COMMENT_PARMNUM         = 12;
   USER_PARMS_PARMNUM               = 13;
   USER_WORKSTATIONS_PARMNUM        = 14;
   USER_LAST_LOGON_PARMNUM          = 15;
   USER_LAST_LOGOFF_PARMNUM         = 16;
   USER_ACCT_EXPIRES_PARMNUM        = 17;
   USER_MAX_STORAGE_PARMNUM         = 18;
   USER_UNITS_PER_WEEK_PARMNUM      = 19;
   USER_LOGON_HOURS_PARMNUM         = 20;
   USER_PAD_PW_COUNT_PARMNUM        = 21;
   USER_NUM_LOGONS_PARMNUM          = 22;
   USER_LOGON_SERVER_PARMNUM        = 23;
   USER_COUNTRY_CODE_PARMNUM        = 24;
   USER_CODE_PAGE_PARMNUM           = 25;
   USER_PRIMARY_GROUP_PARMNUM       = 51;
   USER_PROFILE                     = 52;// ?? Delete when convenient
   USER_PROFILE_PARMNUM             = 52;
   USER_HOME_DIR_DRIVE_PARMNUM      = 53;

//
// the new infolevel counterparts of the old info level + parmnum
//

   USER_NAME_INFOLEVEL             =
      (PARMNUM_BASE_INFOLEVEL + USER_NAME_PARMNUM);
   USER_PASSWORD_INFOLEVEL         =
      (PARMNUM_BASE_INFOLEVEL + USER_PASSWORD_PARMNUM);
   USER_PASSWORD_AGE_INFOLEVEL     =
      (PARMNUM_BASE_INFOLEVEL + USER_PASSWORD_AGE_PARMNUM);
   USER_PRIV_INFOLEVEL             =
      (PARMNUM_BASE_INFOLEVEL + USER_PRIV_PARMNUM);
   USER_HOME_DIR_INFOLEVEL         =
      (PARMNUM_BASE_INFOLEVEL + USER_HOME_DIR_PARMNUM);
   USER_COMMENT_INFOLEVEL          =
      (PARMNUM_BASE_INFOLEVEL + USER_COMMENT_PARMNUM);
   USER_FLAGS_INFOLEVEL            =
      (PARMNUM_BASE_INFOLEVEL + USER_FLAGS_PARMNUM);
   USER_SCRIPT_PATH_INFOLEVEL      =
      (PARMNUM_BASE_INFOLEVEL + USER_SCRIPT_PATH_PARMNUM);
   USER_AUTH_FLAGS_INFOLEVEL       =
      (PARMNUM_BASE_INFOLEVEL + USER_AUTH_FLAGS_PARMNUM);
   USER_FULL_NAME_INFOLEVEL        =
      (PARMNUM_BASE_INFOLEVEL + USER_FULL_NAME_PARMNUM);
   USER_USR_COMMENT_INFOLEVEL      =
      (PARMNUM_BASE_INFOLEVEL + USER_USR_COMMENT_PARMNUM);
   USER_PARMS_INFOLEVEL            =
      (PARMNUM_BASE_INFOLEVEL + USER_PARMS_PARMNUM);
   USER_WORKSTATIONS_INFOLEVEL     =
      (PARMNUM_BASE_INFOLEVEL + USER_WORKSTATIONS_PARMNUM);
   USER_LAST_LOGON_INFOLEVEL       =
      (PARMNUM_BASE_INFOLEVEL + USER_LAST_LOGON_PARMNUM);
   USER_LAST_LOGOFF_INFOLEVEL      =
      (PARMNUM_BASE_INFOLEVEL + USER_LAST_LOGOFF_PARMNUM);
   USER_ACCT_EXPIRES_INFOLEVEL     =
      (PARMNUM_BASE_INFOLEVEL + USER_ACCT_EXPIRES_PARMNUM);
   USER_MAX_STORAGE_INFOLEVEL      =
      (PARMNUM_BASE_INFOLEVEL + USER_MAX_STORAGE_PARMNUM);
   USER_UNITS_PER_WEEK_INFOLEVEL   =
      (PARMNUM_BASE_INFOLEVEL + USER_UNITS_PER_WEEK_PARMNUM);
   USER_LOGON_HOURS_INFOLEVEL      =
      (PARMNUM_BASE_INFOLEVEL + USER_LOGON_HOURS_PARMNUM);
   USER_PAD_PW_COUNT_INFOLEVEL     =
      (PARMNUM_BASE_INFOLEVEL + USER_PAD_PW_COUNT_PARMNUM);
   USER_NUM_LOGONS_INFOLEVEL       =
      (PARMNUM_BASE_INFOLEVEL + USER_NUM_LOGONS_PARMNUM);
   USER_LOGON_SERVER_INFOLEVEL     =
      (PARMNUM_BASE_INFOLEVEL + USER_LOGON_SERVER_PARMNUM);
   USER_COUNTRY_CODE_INFOLEVEL     =
      (PARMNUM_BASE_INFOLEVEL + USER_COUNTRY_CODE_PARMNUM);
   USER_CODE_PAGE_INFOLEVEL        =
      (PARMNUM_BASE_INFOLEVEL + USER_CODE_PAGE_PARMNUM);
   USER_PRIMARY_GROUP_INFOLEVEL    =
      (PARMNUM_BASE_INFOLEVEL + USER_PRIMARY_GROUP_PARMNUM);
//   USER_POSIX_ID_INFOLEVEL         =
//            (PARMNUM_BASE_INFOLEVEL + USER_POSIX_ID_PARMNUM);
   USER_HOME_DIR_DRIVE_INFOLEVEL         =
      (PARMNUM_BASE_INFOLEVEL + USER_HOME_DIR_DRIVE_PARMNUM);

//
//  For SetInfo call (parmnum 0) when password change not required
//

   NULL_USERSETINFO_PASSWD      = '              ';

   TIMEQ_FOREVER                = $ffffffff;
   USER_MAXSTORAGE_UNLIMITED    = $ffffffff;
   USER_NO_LOGOFF               = $ffffffff;
   UNITS_PER_DAY                = 24;
   UNITS_PER_WEEK               = UNITS_PER_DAY * 7;

//
// Privilege levels (USER_INFO_X field usriX_priv (X = 0/1)).
//

   USER_PRIV_MASK       = $3;
   USER_PRIV_GUEST      = 0;
   USER_PRIV_USER       = 1;
   USER_PRIV_ADMIN      = 2;

//
// user modals related defaults
//

   MAX_PASSWD_LEN       = PWLEN;
   DEF_MIN_PWLEN        = 6;
   DEF_PWUNIQUENESS     = 5;
   DEF_MAX_PWHIST       = 8;
   DEF_MAX_PWAGE        = TIMEQ_FOREVER;        // forever
   DEF_MIN_PWAGE        = $00000000;            // 0 days
   DEF_FORCE_LOGOFF     = $ffffffff;            // never
   DEF_MAX_BADPW        = 0;                    // no limit
   ONE_DAY              = 01*24*3600;           // 01 day

//
// User Logon Validation (codes returned)
//

   VALIDATED_LOGON      = 0;
   PASSWORD_EXPIRED     = 2;
   NON_VALIDATED_LOGON  = 3;
   VALID_LOGOFF         = 1;

//
// parmnum manifests for user modals
//

   MODALS_MIN_PASSWD_LEN_PARMNUM        = 1;
   MODALS_MAX_PASSWD_AGE_PARMNUM        = 2;
   MODALS_MIN_PASSWD_AGE_PARMNUM        = 3;
   MODALS_FORCE_LOGOFF_PARMNUM          = 4;
   MODALS_PASSWD_HIST_LEN_PARMNUM       = 5;
   MODALS_ROLE_PARMNUM                  = 6;
   MODALS_PRIMARY_PARMNUM               = 7;
   MODALS_DOMAIN_NAME_PARMNUM           = 8;
   MODALS_DOMAIN_ID_PARMNUM             = 9;
   MODALS_LOCKOUT_DURATION_PARMNUM      = 10;
   MODALS_LOCKOUT_OBSERVATION_WINDOW_PARMNUM  = 11;
   MODALS_LOCKOUT_THRESHOLD_PARMNUM     = 12;

//
// the new infolevel counterparts of the old info level + parmnum
//

   MODALS_MIN_PASSWD_LEN_INFOLEVEL     =
      (PARMNUM_BASE_INFOLEVEL + MODALS_MIN_PASSWD_LEN_PARMNUM);
   MODALS_MAX_PASSWD_AGE_INFOLEVEL     =
      (PARMNUM_BASE_INFOLEVEL + MODALS_MAX_PASSWD_AGE_PARMNUM);
   MODALS_MIN_PASSWD_AGE_INFOLEVEL     =
      (PARMNUM_BASE_INFOLEVEL + MODALS_MIN_PASSWD_AGE_PARMNUM);
   MODALS_FORCE_LOGOFF_INFOLEVEL       =
      (PARMNUM_BASE_INFOLEVEL + MODALS_FORCE_LOGOFF_PARMNUM);
   MODALS_PASSWD_HIST_LEN_INFOLEVEL    =
      (PARMNUM_BASE_INFOLEVEL + MODALS_PASSWD_HIST_LEN_PARMNUM);
   MODALS_ROLE_INFOLEVEL               =
      (PARMNUM_BASE_INFOLEVEL + MODALS_ROLE_PARMNUM);
   MODALS_PRIMARY_INFOLEVEL            =
      (PARMNUM_BASE_INFOLEVEL + MODALS_PRIMARY_PARMNUM);
   MODALS_DOMAIN_NAME_INFOLEVEL        =
      (PARMNUM_BASE_INFOLEVEL + MODALS_DOMAIN_NAME_PARMNUM);
   MODALS_DOMAIN_ID_INFOLEVEL          =
      (PARMNUM_BASE_INFOLEVEL + MODALS_DOMAIN_ID_PARMNUM);
//
// Group Class
//

//
// Function Prototypes
//

function NetGroupAdd (
   ServerName: PWideChar;       // IN OPTIONAL
   Level: Dword;                // IN
   Buf: Pointer;                // IN
   var Parm_err: DWord          // OUT OPTIONAL
): NET_API_STATUS; stdcall;

function NetGroupAddUser (
   ServerName: PWideChar;       // IN OPTIONAL
   GroupName: PWideChar;        // IN
   UserName: PWideChar          // IN
): NET_API_STATUS; stdcall;

function NetGroupEnum (
   ServerName: PWideChar;       // IN OPTIONAL
   Level: Dword;                // IN
   var Bufptr: Pointer;         // OUT
   PrefMaxLen: DWord;           // IN
   var EntriesRead: DWord;      // OUT
   var TotalEntries: DWord;     // OUT
   var Resume_Handle: DWord     // IN OPTIONAL
): NET_API_STATUS; stdcall;

function NetGroupGetInfo (
   ServerName: PWideChar;       // IN OPTIONAL
   GroupName: PWideChar;        // IN
   Level: Dword;                // IN
   var BufPtr: Pointer          // OUT
): NET_API_STATUS; stdcall;

function NetGroupSetInfo (
   ServerName: PWideChar;       // IN OPTIONAL
   GroupName: PWideChar;        // IN
   Level: Dword;                // IN
   Buf: Pointer;                // IN
   var Parm_err: DWord          // OUT OPTIONAL
): NET_API_STATUS; stdcall;

function NetGroupDel (
   ServerName: PWideChar;       // IN OPTIONAL
   GroupName: PWideChar         // IN
): NET_API_STATUS; stdcall;

function NetGroupDelUser (
   ServerName: PWideChar;       // IN OPTIONAL
   GroupName: PWideChar;        // IN
   UserName: PWideChar          // IN
): NET_API_STATUS; stdcall;

function NetGroupGetUsers (
   ServerName: PWideChar;       // IN OPTIONAL
   GroupName: PWideChar;        // IN
   Level: Dword;                // IN
   var Bufptr: Pointer;         // OUT
   PrefMaxLen: DWord;           // IN
   var EntriesRead: DWord;      // OUT
   var TotalEntries: DWord;     // OUT
   var ResumeHandle: DWord      // IN
): NET_API_STATUS; stdcall;

function NetGroupSetUsers (
   ServerName: PWideChar;       // IN OPTIONAL
   GroupName: PWideChar;        // IN
   Level: Dword;                // IN
   Buf: Pointer;                // IN
   totalentries: DWord          // IN
): NET_API_STATUS; stdcall;

//
//  Data Structures - Group
//
type
   PGROUPINFO0 = ^TGROUPINFO0;
   _GROUP_INFO_0 = packed record
      grpi0_name: PWideChar;
   end;
   TGROUPINFO0 = _GROUP_INFO_0;
   {$EXTERNALSYM GROUP_INFO_0}
   GROUP_INFO_0 = _GROUP_INFO_0;

   PGROUPINFO1 = ^TGROUPINFO1;
   _GROUP_INFO_1 = packed record
      grpi1_name: PWideChar;
      grpi1_comment: PWideChar;
   end;
   TGROUPINFO1 = _GROUP_INFO_1;
   {$EXTERNALSYM GROUP_INFO_1}
   GROUP_INFO_1 = _GROUP_INFO_1;

   PGROUPINFO2 = ^TGROUPINFO2;
   _GROUP_INFO_2 = packed record
      grpi2_name: PWideChar;
      grpi2_comment: PWideChar;
      grpi2_group_id: DWord;
      grpi2_attributes: DWord;
   end;
   TGROUPINFO2 = _GROUP_INFO_2;
   {$EXTERNALSYM GROUP_INFO_2}
   GROUP_INFO_2 = _GROUP_INFO_2;

   PGROUPINFO1002 = ^TGROUPINFO1002;
   _GROUP_INFO_1002 = packed record
      grpi1002_comment: PWideChar;
   end;
   TGROUPINFO1002 = _GROUP_INFO_1002;
   {$EXTERNALSYM GROUP_INFO_1002}
   GROUP_INFO_1002 = _GROUP_INFO_1002;

   PGROUPINFO1005 = ^TGROUPINFO1005;
   _GROUP_INFO_1005 = packed record
      grpi1005_attributes: DWord;
   end;
   TGROUPINFO1005 = _GROUP_INFO_1005;
   {$EXTERNALSYM GROUP_INFO_1005}
   GROUP_INFO_1005 = _GROUP_INFO_1005;

   PGROUPUSERSINFO0 = ^TGROUPUSERSINFO0;
   _GROUP_USERS_INFO_0 = packed record
      grui0_name: PWideChar;
   end;
   TGROUPUSERSINFO0 = _GROUP_USERS_INFO_0;
   {$EXTERNALSYM GROUP_USERS_INFO_0}
   GROUP_USERS_INFO_0 = _GROUP_USERS_INFO_0;

   PGROUPUSERSINFO1 = ^TGROUPUSERSINFO1;
   _GROUP_USERS_INFO_1 = packed record
      grui1_name: PWideChar;
      grui1_attributes: DWord;
   end;
   TGROUPUSERSINFO1 = _GROUP_USERS_INFO_1;
   {$EXTERNALSYM GROUP_USERS_INFO_1}
   GROUP_USERS_INFO_1 = _GROUP_USERS_INFO_1;

//
// Special Values and Constants - Group
//
const
   GROUPIDMASK                 = $8000;      // MSB set if uid refers to a group

//
// Predefined group for all normal users, administrators and guests
// LOCAL is a special group for pinball local security.
//

   GROUP_SPECIALGRP_USERS      = 'USERS';
   GROUP_SPECIALGRP_ADMINS     = 'ADMINS';
   GROUP_SPECIALGRP_GUESTS     = 'GUESTS';
   GROUP_SPECIALGRP_LOCAL      = 'LOCAL';

//
// parmnum manifests for SetInfo calls (only comment is settable)
//

   GROUP_ALL_PARMNUM           = 0;
   GROUP_name_PARMNUM          = 1;
   GROUP_comment_PARMNUM       = 2;
   GROUP_ATTRIBUTES_PARMNUM    = 3;

//
// the new infolevel counterparts of the old info Level: Dword; + parmnum
//

   GROUP_ALL_INFOLEVEL             =
      (PARMNUM_BASE_INFOLEVEL + GROUP_ALL_PARMNUM);
   GROUP_name_INFOLEVEL            =
      (PARMNUM_BASE_INFOLEVEL + GROUP_name_PARMNUM);
   GROUP_comment_INFOLEVEL         =
      (PARMNUM_BASE_INFOLEVEL + GROUP_comment_PARMNUM);
   GROUP_ATTRIBUTES_INFOLEVEL      =
      (PARMNUM_BASE_INFOLEVEL + GROUP_ATTRIBUTES_PARMNUM);
//   GROUP_POSIX_ID_INFOLEVEL        =
//            (PARMNUM_BASE_INFOLEVEL + GROUP_POSIX_ID_PARMNUM);

//
// LocalGroup Class
//

//
// Function Prototypes
//

function NetLocalGroupAdd (
   ServerName: PWideChar;       // IN OPTIONAL
   Level: Dword;                // IN
   Buf: Pointer;                // IN
   var Parm_err: DWord          // OUT OPTIONAL
): NET_API_STATUS; stdcall;

function NetLocalGroupAddMember (
   ServerName: PWideChar;       // IN OPTIONAL
   GroupName: PWideChar;        // IN
   membersid: PSid              // IN
): NET_API_STATUS; stdcall;

function NetLocalGroupEnum (
   ServerName: PWideChar;       // IN OPTIONAL
   Level: Dword;                // IN
   var Bufptr: Pointer;
   PrefMaxLen: DWord;           // IN
   var EntriesRead: DWord;      // OUT
   var TotalEntries: DWord;
   var resume_handle: DWord     // IN OPTIONAL
): NET_API_STATUS; stdcall;

function NetLocalGroupGetInfo (
   ServerName: PWideChar;       // IN OPTIONAL
   GroupName: PWideChar;        // IN
   Level: Dword;                // IN
   var BufPtr: Pointer          // OUT
): NET_API_STATUS; stdcall;

function NetLocalGroupSetInfo (
   ServerName: PWideChar;       // IN OPTIONAL
   GroupName: PWideChar;        // IN
   Level: Dword;                // IN
   Buf: Pointer;                // IN
   var Parm_err: DWord          // OUT OPTIONAL
): NET_API_STATUS; stdcall;

function NetLocalGroupDel (
   ServerName: PWideChar;       // IN OPTIONAL
   GroupName: PWideChar         // IN
): NET_API_STATUS; stdcall;

function NetLocalGroupDelMember (
   ServerName: PWideChar;       // IN OPTIONAL
   GroupName: PWideChar;        // IN
   membersid: PSid              // IN
): NET_API_STATUS; stdcall;

function NetLocalGroupGetMembers (
   ServerName: PWideChar;       // IN OPTIONAL
   localgroupname: PWideChar;   // IN
   Level: Dword;                // IN
   var Bufptr: Pointer;
   PrefMaxLen: DWord;           // IN
   var EntriesRead: DWord;      // OUT
   var TotalEntries: DWord;
   var resume_handle: DWord     // IN
): NET_API_STATUS; stdcall;

function NetLocalGroupSetMembers (
   ServerName: PWideChar;       // IN OPTIONAL
   GroupName: PWideChar;        // IN
   Level: Dword;                // IN
   Buf: Pointer;                // IN
   Totalentries: DWord          // IN
): NET_API_STATUS; stdcall;

function NetLocalGroupAddMembers (
   ServerName: PWideChar;       // IN OPTIONAL
   GroupName: PWideChar;        // IN
   Level: Dword;                // IN
   Buf: Pointer;                // IN
   totalentries: DWord          // IN
): NET_API_STATUS; stdcall;

function NetLocalGroupDelMembers (
   ServerName: PWideChar;       // IN OPTIONAL
   GroupName: PWideChar;        // IN
   Level: Dword;                // IN
   Buf: Pointer;                // IN
   Totalentries: DWord          // IN
): NET_API_STATUS; stdcall;

//
//  Data Structures - LocalGroup
//
type
   PLOCALGROUPINFO0 = ^TLOCALGROUPINFO0;
   _LOCALGROUP_INFO_0 = packed record
      lgrpi0_name: PWideChar;
   end;
   TLOCALGROUPINFO0 = _LOCALGROUP_INFO_0;
   {$EXTERNALSYM LOCALGROUP_INFO_0}
   LOCALGROUP_INFO_0 = _LOCALGROUP_INFO_0;

   PLOCALGROUPINFO1 = ^TLOCALGROUPINFO1;
   _LOCALGROUP_INFO_1  = packed record
      lgrpi1_name: PWideChar;
      lgrpi1_comment: PWideChar;
   end;
   TLOCALGROUPINFO1 = _LOCALGROUP_INFO_1;
   {$EXTERNALSYM LOCALGROUP_INFO_1}
   LOCALGROUP_INFO_1 = _LOCALGROUP_INFO_1;

   PLOCALGROUPINFO1002 = ^TLOCALGROUPINFO1002;
   _LOCALGROUP_INFO_1002  = packed record
      lgrpi1002_comment: PWideChar;
   end;
   TLOCALGROUPINFO1002 = _LOCALGROUP_INFO_1002;
   {$EXTERNALSYM LOCALGROUP_INFO_1002}
   LOCALGROUP_INFO_1002 = _LOCALGROUP_INFO_1002;

   PLOCALGROUPMEMBERSINFO0 = ^TLOCALGROUPMEMBERSINFO0;
   _LOCALGROUP_MEMBERS_INFO_0  = packed record
      lgrmi0_sid: PSid;
   end;
   TLOCALGROUPMEMBERSINFO0 = _LOCALGROUP_MEMBERS_INFO_0;
   {$EXTERNALSYM LOCALGROUP_MEMBERS_INFO_0}
   LOCALGROUP_MEMBERS_INFO_0 = _LOCALGROUP_MEMBERS_INFO_0;

   PLOCALGROUPMEMBERSINFO1 = ^TLOCALGROUPMEMBERSINFO1;
   _LOCALGROUP_MEMBERS_INFO_1  = packed record
      lgrmi1_sid: PSid;
      lgrmi1_sidusage: SID_name_USE;
      lgrmi1_name: PWideChar;
   end;
   TLOCALGROUPMEMBERSINFO1 = _LOCALGROUP_MEMBERS_INFO_1;
   {$EXTERNALSYM LOCALGROUP_MEMBERS_INFO_1}
   LOCALGROUP_MEMBERS_INFO_1 = _LOCALGROUP_MEMBERS_INFO_1;

   PLOCALGROUPMEMBERSINFO2 = ^TLOCALGROUPMEMBERSINFO2;
   _LOCALGROUP_MEMBERS_INFO_2  = packed record
      lgrmi2_sid: PSid;
      lgrmi2_sidusage: SID_name_USE;
      lgrmi2_domainandname: PWideChar;
   end;
   TLOCALGROUPMEMBERSINFO2 = _LOCALGROUP_MEMBERS_INFO_2;
   {$EXTERNALSYM LOCALGROUP_MEMBERS_INFO_2}
   LOCALGROUP_MEMBERS_INFO_2 = _LOCALGROUP_MEMBERS_INFO_2;

   PLOCALGROUPMEMBERSINFO3 = ^TLOCALGROUPMEMBERSINFO3;
   _LOCALGROUP_MEMBERS_INFO_3  = packed record
      lgrmi3_domainandname: PWideChar;
   end;
   TLOCALGROUPMEMBERSINFO3 = _LOCALGROUP_MEMBERS_INFO_3;
   {$EXTERNALSYM LOCALGROUP_MEMBERS_INFO_3}
   LOCALGROUP_MEMBERS_INFO_3 = _LOCALGROUP_MEMBERS_INFO_3;

   PLOCALGROUPUSERSINFO0 = ^TLOCALGROUPUSERSINFO0;
   _LOCALGROUP_USERS_INFO_0  = packed record
      lgrui0_name: PWideChar;
   end;
   TLOCALGROUPUSERSINFO0 = _LOCALGROUP_USERS_INFO_0;
   {$EXTERNALSYM LOCALGROUP_USERS_INFO_0}
   LOCALGROUP_USERS_INFO_0 = _LOCALGROUP_USERS_INFO_0;

const
   LOCALGROUP_name_PARMNUM         = 1;
   LOCALGROUP_comment_PARMNUM      = 2;

//
// Display Information APIs
//

function NetQueryDisplayInformation(
   ServerName: PWideChar;               // IN OPTIONAL
   Level: Dword;                        // IN
   Index: Dword;                        // IN
   EntriesRequested: Dword;             // IN
   PreferredMaximumLength: Dword;       // IN
   var ReturnedEntryCount: Dword;
   var SortedBuffer: Pointer
): NET_API_STATUS; stdcall;

function NetGetDisplayInformationIndex(
   ServerName: PWideChar;               // IN OPTIONAL
   Level: Dword;                        // IN
   Prefix: PWideChar;                   // IN
   var Index: Dword
): NET_API_STATUS; stdcall;

//
// QueryDisplayInformation Levels
//

type
   PNETDISPLAYUSER = ^TNETDISPLAYUSER;
   _NET_DISPLAY_USER  = packed record
      usri1_name: PWideChar;
      usri1_comment: PWideChar;
      usri1_flags: DWord;
      usri1_full_name: PWideChar;
      usri1_user_id: DWord;
      usri1_next_index: DWord;
   end;
   TNETDISPLAYUSER = _NET_DISPLAY_USER;
   {$EXTERNALSYM NET_DISPLAY_USER}
   NET_DISPLAY_USER = _NET_DISPLAY_USER;

   PNETDISPLAYMACHINE = ^TNETDISPLAYMACHINE;
   _NET_DISPLAY_MACHINE  = packed record
      usri2_name: PWideChar;
      usri2_comment: PWideChar;
      usri2_flags: DWord;
      usri2_user_id: DWord;
      usri2_next_index: DWord;
   end;
   TNETDISPLAYMACHINE = _NET_DISPLAY_MACHINE;
   {$EXTERNALSYM NET_DISPLAY_MACHINE}
   NET_DISPLAY_MACHINE = _NET_DISPLAY_MACHINE;

   PNETDISPLAYGROUP = ^TNETDISPLAYGROUP;
   _NET_DISPLAY_GROUP  = packed record
      grpi3_name: PWideChar;
      grpi3_comment: PWideChar;
      grpi3_group_id: DWord;
      grpi3_attributes: DWord;
      grpi3_next_index: DWord;
   end;
   TNETDISPLAYGROUP = _NET_DISPLAY_GROUP;
   {$EXTERNALSYM NET_DISPLAY_GROUP}
   NET_DISPLAY_GROUP = _NET_DISPLAY_GROUP;

//
// Access Class
//

//
// Function Prototypes - Access
//
//
// The NetAccess APIs are only available to downlevel
//

//   NetAccessAdd RxNetAccessAdd

function NetAccessAdd (
   ServerName: PWideChar;       // IN OPTIONAL
   Level: Dword;                // IN
   Buf: Pointer;                // IN
   var Parm_err: DWord          // OUT OPTIONAL
): NET_API_STATUS; stdcall;

//   NetAccessEnum RxNetAccessEnum

function NetAccessEnum (
   ServerName: PWideChar;       // IN OPTIONAL
   BasePath: PWideChar;         // IN
   Recursive: DWord;            // IN
   Level: Dword;                // IN
   var Bufptr: Pointer;
   PrefMaxLen: DWord;           // IN
   var EntriesRead: DWord;
   var TotalEntries: DWord;
   var Resume_Handle: DWord     // IN  OPTIONAL
): NET_API_STATUS; stdcall;

//   NetAccessGetInfo RxNetAccessGetInfo

function NetAccessGetInfo (
   ServerName: PWideChar;       // IN OPTIONAL
   resource: PWideChar;         // IN
   Level: Dword;                // IN
   var BufPtr: Pointer          // OUT
): NET_API_STATUS; stdcall;

//   NetAccessSetInfo RxNetAccessSetInfo

function NetAccessSetInfo (
   ServerName: PWideChar;       // IN OPTIONAL
   Resource: PWideChar;         // IN
   Level: Dword;                // IN
   Buf: Pointer;                // IN
   var Parm_err: DWord          // OUT OPTIONAL
): NET_API_STATUS; stdcall;

//   NetAccessDel RxNetAccessDel

function NetAccessDel (
   ServerName: PWideChar;       // IN OPTIONAL
   resource: PWideChar          // IN
): NET_API_STATUS; stdcall;

//   NetAccessGetUserPerms RxNetAccessGetUserPerms

function NetAccessGetUserPerms (
   ServerName: PWideChar;       // IN OPTIONAL
   UGname: PWideChar;           // IN
   Resource: PWideChar;         // IN
   var Perms: DWord
): NET_API_STATUS; stdcall;

//
// Data Structures - Access
//
type
   PACCESSINFO0 = ^TACCESSINFO0;
   _ACCESS_INFO_0 = packed record
      acc0_resource_name: PWideChar;
   end;
   TACCESSINFO0 = _ACCESS_INFO_0;
   {$EXTERNALSYM ACCESS_INFO_0}
   ACCESS_INFO_0 = _ACCESS_INFO_0;

   PACCESSINFO1 = ^TACCESSINFO1;
   _ACCESS_INFO_1 = packed record
      acc1_resource_name: PWideChar;
      acc1_attr: DWord;
      acc1_count: DWord;
   end;
   TACCESSINFO1 = _ACCESS_INFO_1;
   {$EXTERNALSYM ACCESS_INFO_1}
   ACCESS_INFO_1 = _ACCESS_INFO_1;

   PACCESSINFO1002 = ^TACCESSINFO1002;
   _ACCESS_INFO_1002 = packed record
      acc1002_attr: DWord;
   end;
   TACCESSINFO1002 = _ACCESS_INFO_1002;
   {$EXTERNALSYM ACCESS_INFO_1002}
   ACCESS_INFO_1002 = _ACCESS_INFO_1002;

   PACCESSLIST = ^TACCESSLIST;
   _ACCESS_LIST = packed record
      acl_ugname: PWideChar;
      acl_access: DWord;
   end;
   TACCESSLIST = _ACCESS_LIST;
   {$EXTERNALSYM ACCESS_LIST}
   ACCESS_LIST = _ACCESS_LIST;

//
// Special Values and Constants - Access
//

const

//
// Maximum number of permission entries for each resource.
//
   MAXPERMENTRIES     = 64;

//
//  Bit values for the access permissions.  ACCESS_ALL is a handy
//  way to specify maximum permissions.  These are used in
//  acl_access field of access_list structures.
//
   ACCESS_NONE         = 0;
   ACCESS_READ         = $01;
   ACCESS_WRITE        = $02;
   ACCESS_CREATE       = $04;
   ACCESS_EXEC         = $08;
   ACCESS_DELETE       = $10;
   ACCESS_ATRIB        = $20;
   ACCESS_PERM         = $40;
   ACCESS_GROUP        = $8000;
   ACCESS_ALL          = (
      ACCESS_READ or
      ACCESS_WRITE or
      ACCESS_CREATE or
      ACCESS_EXEC or
      ACCESS_DELETE or
      ACCESS_ATRIB or
      ACCESS_PERM
   );

//
// Bit values for the acc1_attr field of the ACCESS_INFO_1 structure.
//

   ACCESS_AUDIT                = $1;
   ACCESS_SUCCESS_OPEN         = $10;
   ACCESS_SUCCESS_WRITE        = $20;
   ACCESS_SUCCESS_DELETE       = $40;
   ACCESS_SUCCESS_ACL          = $80;
   ACCESS_SUCCESS_MASK         = $F0;
   ACCESS_FAIL_OPEN            = $100;
   ACCESS_FAIL_WRITE           = $200;
   ACCESS_FAIL_DELETE          = $400;
   ACCESS_FAIL_ACL             = $800;
   ACCESS_FAIL_MASK            = $F00;
   ACCESS_FAIL_SHIFT           = 4;

//
// Parmnum value for NetAccessSetInfo.
//

   ACCESS_RESOURCE_name_PARMNUM    = 1;
   ACCESS_ATTR_PARMNUM             = 2;
   ACCESS_COUNT_PARMNUM            = 3;
   ACCESS_ACCESS_LIST_PARMNUM      = 4;

//
// the new infolevel counterparts of the old info Level: Dword; + parmnum
//

   ACCESS_RESOURCE_name_INFOLEVEL  =
      (PARMNUM_BASE_INFOLEVEL + ACCESS_RESOURCE_name_PARMNUM);
   ACCESS_ATTR_INFOLEVEL           =
      (PARMNUM_BASE_INFOLEVEL + ACCESS_ATTR_PARMNUM);
   ACCESS_COUNT_INFOLEVEL          =
      (PARMNUM_BASE_INFOLEVEL + ACCESS_COUNT_PARMNUM);
   ACCESS_ACCESS_LIST_INFOLEVEL    =
      (PARMNUM_BASE_INFOLEVEL + ACCESS_ACCESS_LIST_PARMNUM);

//
// ACCESS_LETTERS defines a letter for each bit position in
// the acl_access field of struct access_list.  Note that some
// bits have a corresponding letter of ' ' (space).
//

   ACCESS_LETTERS      = 'RWCXDAP         ';

//
// Domain Class
//

//
// Function Prototypes - Domain
//

function NetGetDCName (
   ServerName: PWideChar;       // IN OPTIONAL
   DomainName: PWideChar;       // IN OPTIONAL
   var BufPtr: Pointer          // OUT
): NET_API_STATUS; stdcall;

function NetGetAnyDCName (
   ServerName: PWideChar;       // IN OPTIONAL
   DomainName: PWideChar;       // IN OPTIONAL
   var BufPtr: Pointer
): NET_API_STATUS; stdcall;

function I_NetLogonControl(
   ServerName: PWideChar;       // IN OPTIONAL
   FunctionCode: DWord;         // IN
   QueryLevel: DWord;           // IN
   var Buffer: Pointer
): NET_API_STATUS; stdcall;

function I_NetLogonControl2(
   ServerName: PWideChar;       // IN OPTIONAL
   FunctionCode: DWord;         // IN
   QueryLevel: DWord;           // IN
   Data: Pointer;               // IN
   var Buffer: Pointer
): NET_API_STATUS; stdcall;

type
   PNTSTATUS = ^NTSTATUS;
   NTSTATUS = Longint;

function NetEnumerateTrustedDomains (
   ServerName: PWideChar;       // IN OPTIONAL
   var DomainNames: PWideChar
): NTSTATUS; stdcall;

//
// Special Values and Constants - Domain
//
const
//
// FunctionCode values for I_NetLogonControl.
//
// NOTE : if you change the following NETLOGON_CONTROL_* values,
// change them in net\svcdlls\logonsrv\logon.idl file also.
//

   NETLOGON_CONTROL_QUERY            = 1; // No-op: just query
   NETLOGON_CONTROL_REPLICATE        = 2; // Force replicate on BDC
   NETLOGON_CONTROL_SYNCHRONIZE      = 3; // Force synchronize on BDC
   NETLOGON_CONTROL_PDC_REPLICATE    = 4; // Force PDC to broadcast change
   NETLOGON_CONTROL_REDISCOVER       = 5; // Force to re-discover trusted domain DCs
   NETLOGON_CONTROL_TC_QUERY         = 6; // Query status of specified trusted channel status
   NETLOGON_CONTROL_TRANSPORT_NOTIFY = 7; // Notify netlogon that a new transport has come online
   NETLOGON_CONTROL_FIND_USER        = 8; // Find named user in a trusted domain
   NETLOGON_CONTROL_CHANGE_PASSWORD  = 9; // Change machine password on a secure channel to a trusted domain

// Debug function codes

   NETLOGON_CONTROL_UNLOAD_NETLOGON_DLL = $FFFB;
   NETLOGON_CONTROL_BACKUP_CHANGE_LOG   = $FFFC;
   NETLOGON_CONTROL_TRUNCATE_LOG        = $FFFD;
   NETLOGON_CONTROL_SET_DBFLAG          = $FFFE;
   NETLOGON_CONTROL_BREAKPOINT          = $FFFF;

//
// Query Level 1 for I_NetLogonControl
//
type
   PNETLOGONINFO1 = ^TNETLOGONINFO1;
   _NETLOGON_INFO_1 = packed record
      netlog1_flags: DWord;
      netlog1_pdc_connection_status:NET_API_STATUS;
   end;
   TNETLOGONINFO1 = _NETLOGON_INFO_1;
   {$EXTERNALSYM NETLOGON_INFO_1}
   NETLOGON_INFO_1 = _NETLOGON_INFO_1;

   PNETLOGONINFO2 = ^TNETLOGONINFO2;
   _NETLOGON_INFO_2 = packed record
      netlog2_flags: DWord;
      netlog2_pdc_connection_status: NET_API_STATUS;
      netlog2_trusted_dc_name: PWideChar;
      netlog2_tc_connection_status: NET_API_STATUS;
   end;
   TNETLOGONINFO2 = _NETLOGON_INFO_2;
   {$EXTERNALSYM NETLOGON_INFO_2}
   NETLOGON_INFO_2 = _NETLOGON_INFO_2;

   PNETLOGONINFO3 = ^TNETLOGONINFO3;
   _NETLOGON_INFO_3 = packed record
      netlog3_flags: DWord;
      netlog3_logon_attempts: DWord;
      netlog3_reserved1: DWord;
      netlog3_reserved2: DWord;
      netlog3_reserved3: DWord;
      netlog3_reserved4: DWord;
      netlog3_reserved5: DWord;
   end;
   TNETLOGONINFO3 = _NETLOGON_INFO_3;
   {$EXTERNALSYM NETLOGON_INFO_3}
   NETLOGON_INFO_3 = _NETLOGON_INFO_3;

   PNETLOGONINFO4 = ^TNETLOGONINFO4;
   _NETLOGON_INFO_4 = packed record
      netlog4_trusted_dc_name: PWideChar;
      netlog4_trusted_domain_name: PWideChar;
   end;
   TNETLOGONINFO4 = _NETLOGON_INFO_4;
   {$EXTERNALSYM NETLOGON_INFO_4}
   NETLOGON_INFO_4 = _NETLOGON_INFO_4;

//
// Values of netlog1_flags
//
const
   NETLOGON_REPLICATION_NEEDED       = $01;  // Database is out of date
   NETLOGON_REPLICATION_IN_PROGRESS  = $02;  // Replication is happening now
   NETLOGON_FULL_SYNC_REPLICATION    = $04;  // full sync replication required/progress
   NETLOGON_REDO_NEEDED              = $08;  // Redo of previous replication needed
   NETLOGON_HAS_IP                   = $10;  // The trusted domain DC has an IP address
   NETLOGON_HAS_TIMESERV             = $20;  // The trusted domain DC runs the Windows Time Service

implementation

function NetUserAdd; external netapi32;
function NetUserEnum; external netapi32;
function NetUserGetInfo; external netapi32;
function NetUserSetInfo; external netapi32;
function NetUserDel; external netapi32;
function NetUserGetGroups; external netapi32;
function NetUserSetGroups; external netapi32;
function NetUserGetLocalGroups; external netapi32;
function NetUserModalsGet; external netapi32;
function NetUserModalsSet; external netapi32;
function NetUserChangePassword; external netapi32;

function NetGroupAdd; external netapi32;
function NetGroupAddUser; external netapi32;
function NetGroupEnum; external netapi32;
function NetGroupGetInfo; external netapi32;
function NetGroupSetInfo; external netapi32;
function NetGroupDel; external netapi32;
function NetGroupDelUser; external netapi32;
function NetGroupGetUsers; external netapi32;
function NetGroupSetUsers; external netapi32;

function NetLocalGroupAdd; external netapi32;
function NetLocalGroupAddMember; external netapi32;
function NetLocalGroupEnum; external netapi32;
function NetLocalGroupGetInfo; external netapi32;
function NetLocalGroupSetInfo; external netapi32;
function NetLocalGroupDel; external netapi32;
function NetLocalGroupDelMember; external netapi32;
function NetLocalGroupGetMembers; external netapi32;
function NetLocalGroupSetMembers; external netapi32;
function NetLocalGroupAddMembers; external netapi32;
function NetLocalGroupDelMembers; external netapi32;

function NetQueryDisplayInformation; external netapi32;
function NetGetDisplayInformationIndex; external netapi32;

function NetAccessAdd; external netapi32;
function NetAccessEnum; external netapi32; {Windows 95/98/Me}
function NetAccessGetInfo; external netapi32;
function NetAccessSetInfo; external netapi32;
function NetAccessDel; external netapi32;
function NetAccessGetUserPerms; external netapi32;

function NetGetDCName; external netapi32;
function NetGetAnyDCName; external netapi32;
function I_NetLogonControl; external netapi32;
function I_NetLogonControl2; external netapi32;
function NetEnumerateTrustedDomains; external netapi32;

end.

