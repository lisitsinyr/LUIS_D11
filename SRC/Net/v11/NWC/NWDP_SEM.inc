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
//บ Source module name: NWDP_SEM.H                                           บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Library VeRsIoN=1.0.0                                                    บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

(* Inclusion Control *)

{$IFNDEF  NWDP_SEM_H }
    {$DEFINE NWDP_SEM_H}
    (*
   // windows.h is required for the definition of CRITICAL_SECTION.
   *)
    {$IFDEF  N_PLAT_MSW4 }
    {$IFNDEF  _INC_WINDOWS }
        {$DEFINE NOATOM}
        {$DEFINE NOCLIPBOARD}
        {$DEFINE NOCOMM}
        {$DEFINE NODEFERWINDOWPOS}
        {$DEFINE NOGDICAPMASKS}
        {$DEFINE NOKANJI}
        {$DEFINE NOMETAFILE}
        {$DEFINE NOMINMAX}
        {$DEFINE NOOPENFILE}
        {$DEFINE NOPROFILER}
        {$DEFINE NOSOUND}
        {$UNDEF OEMRESOURCE}
        {$UNDEF NOLSTRING}
        {$I windows.inc}
    {$ENDIF}
    {$ENDIF}
    {$IFDEF  N_PLAT_DOS }
        (* TC #define NWDPDeclareSemaphoreMac ( __semaphore )  *)
    {$ELSE} {$IFDEF  N_PLAT_OS2 }
        (* TC #define NWDPDeclareSemaphoreMac ( __semaphore ) nuint32 __semaphore ;  *)
    {$ELSE} {$IFDEF  N_PLAT_MSW3 }
        (* TC #define NWDPDeclareSemaphoreMac ( __semaphore ) nbool8 __semaphore ;  *)
    {$ELSE} {$IFDEF  N_PLAT_MSW4 }
        (* TC #define NWDPDeclareSemaphoreMac ( __semaphore ) CRITICAL_SECTION __semaphore ;  *)
    {$ELSE} {$IFDEF  N_PLAT_NLM }
        (* TC #define NWDPDeclareSemaphoreMac ( __semaphore ) nint32 __semaphore ;  *)
    {$ELSE}
        (* TC error *)
    {$ENDIF}
    {$ENDIF}
    {$ENDIF}
    {$ENDIF}
    {$ENDIF}
{$ELSE}
    {$IFDEF  N_DEBUG }
        (* TC error *)
    {$ENDIF}
{$ENDIF}


