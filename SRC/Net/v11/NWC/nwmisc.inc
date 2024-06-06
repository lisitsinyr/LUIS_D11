(******************************************************************************

  %name: nwmisc.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:08:36 1996 %
  $Copyright:

  Copyright (c) 1989-1995 Novell, Inc.  All Rights Reserved.                      

  THIS WORK IS  SUBJECT  TO  U.S.  AND  INTERNATIONAL  COPYRIGHT  LAWS  AND
  TREATIES.   NO  PART  OF  THIS  WORK MAY BE  USED,  PRACTICED,  PERFORMED
  COPIED, DISTRIBUTED, REVISED, MODIFIED, TRANSLATED,  ABRIDGED, CONDENSED,
  EXPANDED,  COLLECTED,  COMPILED,  LINKED,  RECAST, TRANSFORMED OR ADAPTED
  WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC. ANY USE OR EXPLOITATION
  OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT THE PERPETRATOR TO
  CRIMINAL AND CIVIL LIABILITY.$

 *****************************************************************************)


{$IFNDEF  NWMISC_H }
    {$DEFINE NWMISC_H}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$I npackon.inc}
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    {$IFNDEF NW_SHORT_NAME_SERVER}
    {$DEFINE NW_SHORT_NAME_SERVER}
    Const NW_SHORT_NAME_SERVER = 0;
    {$ENDIF}
    {$IFNDEF NW_LONG_NAME_SERVER}
    {$DEFINE NW_LONG_NAME_SERVER}
    Const NW_LONG_NAME_SERVER = 1;
    {$ENDIF}
    {$IFNDEF NW_ENCP_SERVER}
    {$DEFINE NW_ENCP_SERVER}
    Const NW_ENCP_SERVER = 1;
    {$ENDIF}
    {$IFNDEF NW_EXTENDED_NCP_SERVER}
    {$DEFINE NW_EXTENDED_NCP_SERVER}
    Const NW_EXTENDED_NCP_SERVER = 1;
    {$ENDIF}
    {$IFNDEF _NETX_COM}
    {$DEFINE _NETX_COM}
    Const _NETX_COM = $0001;
    {$DEFINE _NETX_VLM}
    Const _NETX_VLM = $0002;
    {$DEFINE _REDIR_LOADED}
    Const _REDIR_LOADED = $4000;
    {$DEFINE _VLM_LOADED}
    Const _VLM_LOADED = $8000;
    {$ENDIF}
    {$IFDEF N_PLAT_UNIX}
    (* TC #define NWWordSwap ( x ) ( ( nuint16 ) ( ( ( ( nuint16 ) ( ( x ) & 0x00FF ) ) < < 8 ) | ( ( ( nuint16 ) ( ( x ) & 0xFF00 ) ) > > 8 ) ) )  *)
    (* TC #define NWLongSwap ( x ) ( ( nuint32 ) ( ( ( ( nuint32 ) ( ( x ) & 0x000000FFL ) ) < < 24 ) | ( ( ( nuint32 ) ( ( x ) & 0x0000FF00L ) ) < < 8 ) | ( ( ( nuint32 ) ( ( x ) & 0x00FF0000L ) ) > > 8 ) | ( ( ( nuint32 ) ( ( x ) & 0xFF000000L ) ) > > 24 ) ) )  *)
    {$ENDIF}
    Type
        NW_DATE = Record
            day  :   nuint8 ;
            month  :   nuint8 ;
            year  :   nuint16 ;
        End;
    (* hours is a nuint16  so that this structure will be the same length as a dword *)
    Type
        NW_TIME = Record
            seconds  :   nuint8 ;
            minutes  :   nuint8 ;
            hours  :   nuint16 ;
        End;
    Const
    NW_LONG_NAME_REQUESTER = 0;
    NW_SHORT_NAME_REQUESTER = 1;
    NW_ERROR_ON_REQUESTER_TYPE = 2;
    Type NW_REQUESTER_TYPE = 0..2;
    {$IFNDEF NW_FRAGMENT_DEFINED}
    {$DEFINE NW_FRAGMENT_DEFINED}
Type NW_FRAGMENT = Record 
  fragAddress : nptr;
{$ifdef N_PLAT_NLM} 
  fragSize : nuint32;
{$ELSE} {$IFDEF WIN32}
  fragSize : nuint32;
{$else}
   fragSize : nuint16;
{$ENDIF}
{$endif}
End;
{$ENDIF}
    Type
        CONN_TASK = Record
            taskNumber  :   nuint16 ;
            taskState  :   nuint8 ;
        End;
    Type
        CONN_TASK_INFO = Record
            serverVersion  :   nuint16 ;
            lockState  :   nuint8 ;
            waitingTaskNumber  :   nuint16 ;
            recordStart  :   nuint32 ;
            recordEnd  :   nuint32 ;
            volNumber  :   nuint8 ;
            dirEntry  :   nuint32 ;
            nameSpace  :   nuint8 ;
            dirID  :   nuint16 ;
            lockedName  :  Array[0..255] Of  nstr8 ;
            taskCount  :   nuint8 ;
            tasks  :  Array[0..255] Of  CONN_TASK ;
        End;
    Type
        DIR_ENTRY = Record
            volNumber  :   nuint8 ;
            dirEntry  :   nuint32 ;
        End;
    Procedure NWUnpackDateTime (
        dateTime  :   nuint32 ;
        Var sDate  : NW_DATE;
        Var sTime  : NW_TIME
    );
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Procedure NWUnpackDate (
        date  :   nuint16 ;
        Var sDate  : NW_DATE
    );
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Procedure NWUnpackTime (
        time  :   nuint16 ;
        Var sTime  : NW_TIME
    );
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWPackDateTime (
        Var sDate  : NW_DATE;
        Var sTime  : NW_TIME
    ) : nuint32;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWPackDate (
        Var sDate  : NW_DATE
    ) : nuint16;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWPackTime (
        Var sTime  : NW_TIME
    ) : nuint16;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* Avoid using the following three NWConvert{Date/Time} functions,
   they just call the NWUnpack{Date/Time} functions. They are here for
   compatibility reasons only. *)
    Procedure NWConvertDateTime (
        dateTime  :   nuint32 ;
        Var sDate  : NW_DATE;
        Var sTime  : NW_TIME
    );
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Procedure NWConvertDate (
        date  :   nuint16 ;
        Var sDate  : NW_DATE
    );
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Procedure NWConvertTime (
        time  :   nuint16 ;
        Var sTime  : NW_TIME
    );
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWRequest (
        conn  :   NWCONN_HANDLE ;
        function1  :   nuint16 ;
        numReqFrags  :   nuint16 ;
        Var reqFrags  : NW_FRAGMENT;
        numReplyFrags  :   nuint16 ;
        Var replyFrags  : NW_FRAGMENT
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function _NWGetRequesterType (
        Var type1  : NW_REQUESTER_TYPE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFNDEF N_PLAT_UNIX}
    Function NWWordSwap (
        swapWord  :   nuint16 
    ) : nuint16;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLongSwap (
        swapLong  :   nuint32 
    ) : nuint32;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$ENDIF}
    (* Not implemented Function NWInitDBCS : nint16;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    Function NWConvertPathToDirEntry (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        Var dirEntry  : DIR_ENTRY
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetTaskInformationByConn (
        conn  :   NWCONN_HANDLE ;
        connNum  :   nuint16 ;
        Var taskInfo  : CONN_TASK_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetRequesterVersion (
        majorVer  :   pnuint8 ;
        minorVer  :   pnuint8 ;
        revision  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWIsLNSSupportedOnVolume (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function _NWConvertHandle (
        conn  :   NWCONN_HANDLE ;
        accessMode  :   nuint8 ;
        NWHandle  :   pnuint8 ;
        fileSize  :   nuint32 ;
        Var fileHandle  : NWFILE_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWConvertFileHandle (
        fileHandle  :   NWFILE_HANDLE ;
        handleType  :   nuint16 ;
        NWHandle  :   pnuint8 ;
        Var conn  : NWCONN_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWConvertFileHandleConnRef (
        fileHandle  :   NWFILE_HANDLE ;
        handleType  :   nuint16 ;
        NWHandle  :   pnuint8 ;
        connRef  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Procedure _NWConvert4ByteTo6ByteHandle (
        NW4ByteHandle  :   pnuint8 ;
        NW6ByteHandle  :   pnuint8 
    );
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* Not implemented Function NWEndOfJob : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    Function NWCallsInit (
        reserved1  :   nptr ;
        reserved2  :   nptr 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCallsTerm (
        reserved  :   nptr 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetClientType : nuint16;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFNDEF WIN32}
    (* Not implemented Function __NWGetNWCallsState : nuint16;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWSetNetWareErrorMode (
        errorMode  :   nuint8 ;
        prevMode  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWSetEndOfJobStatus (
        endOfJobStatus  :   nuint8 ;
        prevStatus  :   pnuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWFSRequest (
        request  :   nuint32 ;
        inBuf  :   nptr ;
        inLen  :   nuint16 ;
        outBuf  :   nptr ;
        outLen  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
{$ENDIF}


Procedure NWGetNWCallsVersion (
    majorVer  :   pnuint8 ;
    minorVer  :   pnuint8 ;
    revLevel  :   pnuint8 ;
    betaLevel  :   pnuint8 
);
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWConvertHandle (
    conn  :   NWCONN_HANDLE ;
    accessMode  :   nuint8 ;
    NWHandle  :   nptr ;
    handleSize  :   nuint16 ;
    fileSize  :   nuint32 ;
    Var fileHandle  : NWFILE_HANDLE
) : NWCCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(* The stuff below this line may NOT be documented. Use with care. *)

{$IFNDEF  NWOS2 }
{$IFNDEF  WIN32 }
    {$IFNDEF _REGISTERS_DEF}
    {$DEFINE _REGISTERS_DEF}
    Type
        BYTE_REGISTERS = Record
            si  :   nuint16 ;
            ds  :   nuint16 ;
            di  :   nuint16 ;
            es  :   nuint16 ;
            al  :   nuint8 ;
            ah  :   nuint8 ;
            bl  :   nuint8 ;
            bh  :   nuint8 ;
            cl  :   nuint8 ;
            ch  :   nuint8 ;
            dl  :   nuint8 ;
            dh  :   nuint8 ;
        End;
    Type
        WORD_REGISTERS = Record
            si  :   nuint16 ;
            ds  :   nuint16 ;
            di  :   nuint16 ;
            es  :   nuint16 ;
            ax  :   nuint16 ;
            bx  :   nuint16 ;
            cx  :   nuint16 ;
            dx  :   nuint16 ;
            bp  :   nuint16 ;
            flags  :   nuint16 ;
        End;
    Type
        PTR_REGISTERS = Record
            requestBuffer  :   nptr ;
            replyBuffer  :   nptr ;
        End;
    Type
        SEG_OFF_REGISTERS = Record
            ds_si  :   nptr ;
            es_di  :   nptr ;
        End;
    Type w  =   WORD_REGISTERS ;  (* union statement *)
    Type REGISTERS = w;
    {$ENDIF}
    {$IFNDEF USE_DS}
    {$DEFINE USE_DS}
    Const USE_DS = 1;
    {$DEFINE USE_ES}
    Const USE_ES = 2;
    {$DEFINE USE_DOS}
    Const USE_DOS = $80;
    {$ENDIF}
    (* Not implemented Function NWShellRequest (
        Var a  : REGISTERS;
        nuint16  :   
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWVLMRequest (
        callerID  :   nuint16 ;
        destID  :   nuint16 ;
        destFunc  :   nuint16 ;
        Var regs  : REGISTERS;
        mask  :   nuint16 
    ) : nuint16;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
{$ENDIF}
{$ENDIF}


{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}


{$I npackoff.inc}
{$ENDIF}

