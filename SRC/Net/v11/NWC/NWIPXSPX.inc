(*    (c) COPYRIGHT 1990,1991 by Novell, Inc.  All Rights Reserved.   *)

(*    This header file will allow you to include one header whether you
      program for DOS or Windows
*)


{$IFDEF  WINDOWS }
    {$I nxtw.inc}
    {$I nwsap.inc}
    {$I nwdiag.inc}
{$ELSE} {$IFDEF  NWWIN }
    {$I nxtw.inc}
    {$I nwsap.inc}
    {$I nwdiag.inc}
{$ELSE}
    {$I nxtd.inc}
    {$I sap.inc}
    {$I diag.inc}
{$ENDIF}
{$ENDIF}

