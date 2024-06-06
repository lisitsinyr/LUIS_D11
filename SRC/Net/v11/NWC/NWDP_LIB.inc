(*
//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
//บ (c) 1995-1997 Novell, Inc.  All rights reserved.                         บ
//บ                                                                          บ
//บ THIS WORK IS SUBJECT TO U.S. AND INTERNATIONAL COPYRIGHT LAWS AND        บ
//บ TREATIES.                                                                บ
//บ                                                                          บ
//บ NO PART OF THIS WORK MAY BE USED, PRACTICED, PERFORMED, COPIED,          บ
//บ DISTRIBUTED, REVISED, MODIFIED, TRANSLATED, ABRIDGED, CONDENSED,         บ
//บ EXPANDED, COLLECTED, COMPILED, LINKED, RECAST, TRANSFORMED OR ADAPTED    บ
//บ WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC.                        บ
//บ                                                                          บ
//บ ANY USE OR EXPLOITATION OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT บ
//บ THE PERPETRATOR TO CRIMINAL AND CIVIL LIABILITY.                         บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Source module name: NWDP_LIB.H                                           บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Library VeRsIoN=1.0.0                                                    บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

(* Inclusion Control *)

{$IFNDEF  NWDP_LIB_H }
    {$DEFINE NWDP_LIB_H}
    (* Standard Library Header Includes *)
    {$IFNDEF  NTYPES_H }
        {$DEFINE N_INC_NO_OLD_CONSTANTS}
        {$I ntypes.inc}
        {$UNDEF N_INC_NO_OLD_CONSTANTS}
    {$ENDIF}
    (* Header Includes *)
    {$IFNDEF  NWDP_WKO_OGH }
        {$I nwdp_wko.inc}
    {$ENDIF}
    {$IFNDEF  NWDP_ATT_H }
        {$I nwdp_att.inc}
    {$ENDIF}
    (* Manifest Constant Definitions *)
    {$DEFINE NWDP_LIBRARY_MAJOR_VERSION}
    Const NWDP_LIBRARY_MAJOR_VERSION = 1;
    {$DEFINE NWDP_LIBRARY_MINOR_VERSION}
    Const NWDP_LIBRARY_MINOR_VERSION = 0;
    {$DEFINE NWDP_LIBRARY_BUGFIX_REVISION}
    Const NWDP_LIBRARY_BUGFIX_REVISION = 0;
    {$DEFINE NWDP_LIBRARY_PREREL_VERSION}
    Const NWDP_LIBRARY_PREREL_VERSION = 0;
    (*
// For use with NWDPLibSetArtificialMemLimit to turn off this feature
*)
    {$DEFINE NWDP_MEM_LIMIT_NONE}
    Const NWDP_MEM_LIMIT_NONE = $FFFFFFFF;
    (* Macro Definitions *)
    (*
// Convenience access to Unicode Table Handles used internally
// by the Library
*)
    (* TC #define NWDPLocalToUnicodeHandleMac ( __accRef ) ( ( ( NWDPAccessorRef ) ( __accRef ) ) - > cADBPtr - > localToUnicodeHandle )  *)
    (* TC #define NWDPUnicodeToLocalHandleMac ( __accRef ) ( ( ( NWDPAccessorRef ) ( __accRef ) ) - > cADBPtr - > unicodeToLocalHandle )  *)
    (* TC #define NWDPMonocaseHandleMac ( __accRef ) ( ( ( NWDPAccessorRef ) ( __accRef ) ) - > cADBPtr - > monocaseHandle )  *)
    {$IFNDEF  NWDPAccessorRef }
        Type NWDPAccessorRef = ^NWDPAccessorData;
        Type NWDPBrkRef = nptr;
        Type NWDPDocRef = nptr;
        Type NWDPFileRef = nptr;
        Type NWDPFilterRef = nptr;
        Type NWDPJobRef = nptr;
        Type NWDPNSrvObjRef = nptr;
        NWDPOidRef = ^NWDPOidStruct;
        Type NWDPOidSetRef = pNWDPObjectIdentifierSet;
      (* ct Type NWDPAttrSetRef = pNWDPAttrSetStruct;
        Type NWDPASAVPRef = pNWDPASAVPStruct; *)
        Type NWDPPrtRef = nptr;
        Type NWDPSrsRef = nptr;
        Type NWDPPsmRef = nptr;
        Type NWDPResRef = nptr;
        Type NWDPNtfyRef = nptr;
        Type NWDPNtfyMethodInfoRef = nptr;
        Type NWDPNtfyProfileRef = pNWDPEventHandlingProfile;
    {$ENDIF}
     pNWDPAccessorRef NWDPAccessorRef; 
     pNWDPBrkRef = ^NWDPBrkRef;
     pNWDPDocRef = ^NWDPDocRef;
     pNWDPFileRef = ^NWDPFileRef;
     pNWDPFilterRef = ^NWDPFilterRef;
     pNWDPJobRef = ^NWDPJobRef;
     pNWDPNSrvObjRef = ^NWDPNSrvObjRef;
     pNWDPOidRef = ^NWDPOidRef;
     pNWDPOidSetRef = ^NWDPOidSetRef;
     pNWDPAttrSetRef = ^NWDPAttrSetRef;
     pNWDPASAVPRef = ^NWDPASAVPRef;
     pNWDPPrtRef = ^NWDPPrtRef;
     pNWDPSrsRef = ^NWDPSrsRef;
     pNWDPPsmRef = ^NWDPPsmRef;
     pNWDPResRef = ^NWDPResRef;
     pNWDPNtfyRef = ^NWDPNtfyRef;
     pNWDPNtfyMethodInfoRef = ^NWDPNtfyMethodInfoRef;
     pNWDPNtfyProfileRef = ^NWDPNtfyProfileRef;
    {$IFDEF  N_PLAT_MSW }
        {$IFDEF  N_PLAT_MSW3 }
            (* TC #define __NWDPLibDefineTaskIdMac nuint __taskId = ( nuint ) ( HANDLE ) GetCurrentTask ( ) ; nuint __subTaskId = 0 ;  *)
        {$ELSE} {$IFDEF  N_PLAT_MSW4 }
            (* TC #define __NWDPLibDefineTaskIdMac nuint __taskId = ( nuint ) ( HANDLE ) GetCurrentThread ( ) ; nuint __subTaskId = 0 ;  *)
        {$ENDIF}
        {$ENDIF}
        {$IFNDEF  MESSAGE_BOX }
            {$IFDEF  __cplusplus }
                (* TC #define MESSAGE_BOX ( a , b ) : : MessageBox ( 0 , ( LPSTR ) ( a ) , ( LPSTR ) ( b ) , MB_OK )  *)
            {$ELSE}
                (* TC #define MESSAGE_BOX ( a , b ) MessageBox ( 0 , ( LPSTR ) ( a ) , ( LPSTR ) ( b ) , MB_OK )  *)
            {$ENDIF}
        {$ENDIF}
    {$ELSE} {$IFDEF  N_PLAT_NLM }
        (* TC #define __NWDPLibDefineTaskIdMac nuint __taskId = ( nuint ) GetThreadGroupID ( ) ; nuint __subTaskId = ( nuint ) GetThreadID ( ) ;  *)
    {$ELSE}
        (*
   // This works for DOS, OS/2 and UNIX
   *)
        (* TC #define __NWDPLibDefineTaskIdMac nuint __taskId = ( nuint ) getpid ( ) ; nuint __subTaskId = 0 ;  *)
    {$ENDIF}
    {$ENDIF}
    {$IFDEF  N_DEBUG }
        {$IFDEF  N_PLAT_MSW }
        {$ELSE}
        {$ENDIF}
    {$ELSE}
        {$IFDEF  N_PLAT_MSW }
            (* TC #define NWDPLibInitMac ( __accRefPtr ) { NWDPInitCode __retCode ; __NWDPLibDefineTaskIdMac ; __retCode = NWDPLibInit ( NWDP_LIBRARY_MAJOR_VERSION , NWDP_LIBRARY_MINOR_VERSION , NWDP_LIBRARY_BUGFIX_REVISION , NWDP_LIBRARY_PREREL_VERSION , __taskId , __subTaskId , __accRefPtr , NULL , NULL , NULL , NULL ) ; if ( __retCode < 0 ) exit ( __retCode ) ; }  *)
        {$ELSE}
            (* TC #define NWDPLibInitMac ( __accRefPtr ) { NWDPInitCode __retCode ; __NWDPLibDefineTaskIdMac ; __retCode = NWDPLibInit ( NWDP_LIBRARY_MAJOR_VERSION , NWDP_LIBRARY_MINOR_VERSION , NWDP_LIBRARY_BUGFIX_REVISION , NWDP_LIBRARY_PREREL_VERSION , __taskId , __subTaskId , __accRefPtr , NULL , NULL , NULL , NULL ) ; if ( __retCode < 0 ) exit ( __retCode ) ; }  *)
        {$ENDIF}
    {$ENDIF}
    (* Type Definitions *)
    {$DEFINE N_PACK_1}
    {$I npackon.inc}
    Type
        CommonAccessorData_T = Record
            localToUnicodeHandle  :   nptr ;
            unicodeToLocalHandle  :   nptr ;
            monocaseHandle  :   nptr ;
        End;
        NWDPCommonAccessorData = CommonAccessorData_T;
        pNWDPCommonAccessorData = ^CommonAccessorData_T;
  (* ct  Type
        AccessorRef_T = Record
            libError  :   nuint32 ;
            otherError  :   nuint32 ;
            otherError2  :   nuint32 ;
            otherErrorStrPtr  :   pnstr8 ;
            otherNDPSErrorReturnPtr  :   pNWDPErrorReturn ;
            errorLine  :   nuint32 ;
            errorModule  :   pnstr8 ;
            wellKnownOidRefs  :   NWDPOidRef ;
            cADBPtr  :   pNWDPCommonAccessorData ;
        End;
        NWDPAccessorData = AccessorRef_T;
        pNWDPAccessorData = ^AccessorRef_T; *)
    (*
   // Values returned for NWDPLibInit
   *)
    Const
    NWDP_IC_SUCCESS = 0;
    NWDP_IC_WARN_REPEAT_ID = 2;
    NWDP_IC_WARN_VER_OBSOLETE = 3;
    NWDP_IC_ERR_NO_MEMORY = -2;
    NWDP_IC_ERR_NO_ACCESSOR = -3;
    NWDP_IC_ERR_WRONG_MAJOR_VERSION = -4;
    NWDP_IC_ERR_OLD_MINOR_VERSION = -5;
    NWDP_IC_ERR_OLD_REVISION = -6;
    NWDP_IC_ERR_IS_PRERELEASE = -7;
    NWDP_IC_ERR_OLD_PRERELEASE = -8;
    NWDP_IC_ERR_NWCALLS_INIT = -9;
    NWDP_IC_ERR_UNICODE_INIT = -10;
    NWDP_IC_ERR_WINDOW_CREATE = -11;
    NWDP_IC_ERR_MISMATCHED_DLL = -12;
    NWDP_IC_ERR_MISMATCHED_SUBLIB = -13;
    NWDP_IC_ERR_RPC_WINSOCK_INIT = -14;
    Type NWDPInitCode_T = -14..3;
    NWDPInitCode = NWDPInitCode_T;
    pNWDPInitCode = ^NWDPInitCode_T;
    {$I npackoff.inc}
    (* Structure Definitions *)
    (* Global Variable Declarations *)
    (* Function Prototype Declarations *)
    Function NWDPLibInit (
        expectedMajorVersion  :   nuint ;
        expectedMinorVersion  :   nuint ;
        expectedBuxfixRevision  :   nuint ;
        expectedPrereleaseVersion  :   nuint ;
        taskId  :   nuint ;
        subTaskId  :   nuint ;
        accessorRefPtr  :   pNWDPAccessorRef ;
        returnedMajorVersionPtr  :   pnuint ;
        returnedMinorVersionPtr  :   pnuint ;
        returnedBugfixRevisionPtr  :   pnuint ;
        returnedPrereleaseVersionPtr  :   pnuint 
    ) : NWDPInitCode;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPLibTerm (
        accessorRefPtr  :   pNWDPAccessorRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPLibSetArtificialIODelay (
        accessorRef  :   NWDPAccessorRef ;
        milliseconds  :   nuint32 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (*
// W A R N I N G : Using these routines is not recommended except
// for applications which are consumers of this library for other
// reasons.
// 
// All memory allocated with these routines is automatically freed
// when NWDPLibTerm is called.
*)
    Function NWDPLibMalloc (
        accessorRef  :   NWDPAccessorRef ;
        resultMemPtr  :   pnptr ;
        szMem  :   nint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPLibFree (
        accessorRef  :   NWDPAccessorRef ;
        memPtr  :   nptr 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPLibRealloc (
        accessorRef  :   NWDPAccessorRef ;
        resultMemPtr  :   pnptr ;
        sourceMemPtr  :   nptr ;
        szMem  :   nint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPLibCalloc (
        accessorRef  :   NWDPAccessorRef ;
        resultMemPtr  :   pnptr ;
        numElements  :   nint ;
        szMem  :   nint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (*
// This is identical to NWDPLibMalloc except for the N_PLAT_NLM case
// where a non-blocking call to __qmalloc is done instead of malloc.
*)
    Function NWDPLibQMalloc (
        accessorRef  :   NWDPAccessorRef ;
        resultMemPtr  :   pnptr ;
        szMem  :   nint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPLibSetArtificialMemLimit (
        accessorRef  :   NWDPAccessorRef ;
        mallocsBeforeMallocFail  :   nuint32 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
{$ELSE}
    {$IFDEF  N_DEBUG }
        (* TC error *)
    {$ENDIF}
{$ENDIF}


