(******************************************************************************

  %name: nwea.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:08:09 1996 %
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


{$IFNDEF  NWEA_H }
    {$DEFINE NWEA_H}
    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$IFNDEF  NWNAMSPC_H }
        {$I nwnamspc.inc}
    {$ENDIF}
    {$I npackon.inc}
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    {$DEFINE EA_EOF}
    Const EA_EOF = 1;
    {$DEFINE EA_DONE}
    Const EA_DONE = 1;
    {$DEFINE EA_READWRITE}
    Const EA_READWRITE = 0;
    {$DEFINE EA_CREATE}
    Const EA_CREATE = 1;
    {$DEFINE MISSING_EA_KEY}
    Const MISSING_EA_KEY = 200;
    {$DEFINE EA_NOT_FOUND}
    Const EA_NOT_FOUND = 201;
    {$DEFINE INVALID_EA_HANDLE_TYPE}
    Const INVALID_EA_HANDLE_TYPE = 202;
    {$DEFINE EA_NO_KEY_NO_DATA}
    Const EA_NO_KEY_NO_DATA = 203;
    {$DEFINE EA_NUMBER_MISMATCH}
    Const EA_NUMBER_MISMATCH = 204;
    {$DEFINE EXTENT_NUMBER_OUT_OF_RANGE}
    Const EXTENT_NUMBER_OUT_OF_RANGE = 205;
    {$DEFINE EA_BAD_DIR_NUM}
    Const EA_BAD_DIR_NUM = 206;
    {$DEFINE INVALID_EA_HANDLE}
    Const INVALID_EA_HANDLE = 207;
    {$DEFINE EA_POSITION_OUT_OF_RANGE}
    Const EA_POSITION_OUT_OF_RANGE = 208;
    {$DEFINE EA_ACCESS_DENIED}
    Const EA_ACCESS_DENIED = 209;
    {$DEFINE DATA_PAGE_ODD_SIZE}
    Const DATA_PAGE_ODD_SIZE = 210;
    {$DEFINE EA_VOLUME_NOT_MOUNTED}
    Const EA_VOLUME_NOT_MOUNTED = 211;
    {$DEFINE BAD_PAGE_BOUNDARY}
    Const BAD_PAGE_BOUNDARY = 212;
    {$DEFINE INSPECT_FAILURE}
    Const INSPECT_FAILURE = 213;
    {$DEFINE EA_ALREADY_CLAIMED}
    Const EA_ALREADY_CLAIMED = 214;
    {$DEFINE ODD_BUFFER_SIZE}
    Const ODD_BUFFER_SIZE = 215;
    {$DEFINE NO_SCORECARDS}
    Const NO_SCORECARDS = 216;
    {$DEFINE BAD_EDS_SIGNATURE}
    Const BAD_EDS_SIGNATURE = 217;
    {$DEFINE EA_SPACE_LIMIT}
    Const EA_SPACE_LIMIT = 218;
    {$DEFINE EA_KEY_CORRUPT}
    Const EA_KEY_CORRUPT = 219;
    {$DEFINE EA_KEY_LIMIT}
    Const EA_KEY_LIMIT = 220;
    {$DEFINE TALLY_CORRUPT}
    Const TALLY_CORRUPT = 221;
    Type
        NW_EA_HANDLE = Record
            connID  :   NWCONN_HANDLE ;
            rwPosition  :   nuint32 ;
            EAHandle  :   nuint32 ;
            volNumber  :   nuint32 ;
            dirBase  :   nuint32 ;
            keyUsed  :   nuint8 ;
            keyLength  :   nuint16 ;
            key  :  Array[0..255] Of  nuint8 ;
        End;
    Type
        NW_EA_FF_STRUCT = Record
            connID  :   NWCONN_HANDLE ;
            nextKeyOffset  :   nuint16 ;
            nextKey  :   nuint16 ;
            numKeysRead  :   nuint32 ;
            totalKeys  :   nuint32 ;
            EAHandle  :   nuint32 ;
            sequence  :   nuint16 ;
            numKeysInBuffer  :   nuint16 ;
            enumBuffer  :  Array[0..511] Of  nuint8 ;
        End;
    Function NWCloseEA (
        Var EAHandle  : NW_EA_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWFindFirstEA (
        conn  :   NWCONN_HANDLE ;
        Var idxStruct  : NW_IDX;
        Var ffStruct  : NW_EA_FF_STRUCT;
        Var EAHandle  : NW_EA_HANDLE;
        EAName  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWFindNextEA (
        Var ffStruct  : NW_EA_FF_STRUCT;
        Var EAHandle  : NW_EA_HANDLE;
        EAName  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWReadEA (
        Var EAHandle  : NW_EA_HANDLE;
        bufferSize  :   nuint32 ;
        buffer  :   pnuint8 ;
        totalEASize  :   pnuint32 ;
        amountRead  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWWriteEA (
        Var EAHandle  : NW_EA_HANDLE;
        totalWriteSize  :   nuint32 ;
        bufferSize  :   nuint32 ;
        buffer  :   pnuint8 ;
        amountWritten  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetEAHandleStruct (
        conn  :   NWCONN_HANDLE ;
        EAName  :   pnstr8 ;
        Var idxStruct  : NW_IDX;
        Var EAHandle  : NW_EA_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWOpenEA (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        EAName  :   pnstr8 ;
        nameSpace  :   nuint8 ;
        Var EAHandle  : NW_EA_HANDLE
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

