(******************************************************************************

  %name: nwdsfilt.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:07:33 1996 %
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

{$IFNDEF  NWDSFILT_H }
    {$DEFINE NWDSFILT_H}
    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
    {$IFNDEF  NWDSTYPE_H }
        {$I nwdstype.inc}
    {$ENDIF}
    {$IFNDEF  NWDSDC_H }
        {$I nwdsdc.inc}
    {$ENDIF}
    {$IFNDEF  NWDSBUFT_H }
        {$I nwdsbuft.inc}
    {$ENDIF}
    {$I npackon.inc}
    Type
        pFilter_Node_T = ^_filter_node;
        _filter_node = Record
            parent  :  pFilter_node_T;
            left  :  pFilter_node_T;
            right  :  pFilter_node_T;
            value  :   nptr ;
            syntax  :   nuint32 ;
            token  :   nuint16 ;
        End;
        Filter_Node_T = _filter_node;
    {$DEFINE FTOK_END}
    Const FTOK_END = 0;
    {$DEFINE FTOK_OR}
    Const FTOK_OR = 1;
    {$DEFINE FTOK_AND}
    Const FTOK_AND = 2;
    {$DEFINE FTOK_NOT}
    Const FTOK_NOT = 3;
    {$DEFINE FTOK_LPAREN}
    Const FTOK_LPAREN = 4;
    {$DEFINE FTOK_RPAREN}
    Const FTOK_RPAREN = 5;
    {$DEFINE FTOK_AVAL}
    Const FTOK_AVAL = 6;
    {$DEFINE FTOK_EQ}
    Const FTOK_EQ = 7;
    {$DEFINE FTOK_GE}
    Const FTOK_GE = 8;
    {$DEFINE FTOK_LE}
    Const FTOK_LE = 9;
    {$DEFINE FTOK_APPROX}
    Const FTOK_APPROX = 10;
    {$DEFINE FTOK_ANAME}
    Const FTOK_ANAME = 14;
    {$DEFINE FTOK_PRESENT}
    Const FTOK_PRESENT = 15;
    {$DEFINE FTOK_RDN}
    Const FTOK_RDN = 16;
    {$DEFINE FTOK_BASECLS}
    Const FTOK_BASECLS = 17;
    {$DEFINE FTOK_MODTIME}
    Const FTOK_MODTIME = 18;
    {$DEFINE FTOK_VALTIME}
    Const FTOK_VALTIME = 19;
    (* TC #define FBIT_END ( 1L < < FTOK_END )  *)
    (* TC #define FBIT_OR ( 1L < < FTOK_OR )  *)
    (* TC #define FBIT_AND ( 1L < < FTOK_AND )  *)
    (* TC #define FBIT_NOT ( 1L < < FTOK_NOT )  *)
    (* TC #define FBIT_LPAREN ( 1L < < FTOK_LPAREN )  *)
    (* TC #define FBIT_RPAREN ( 1L < < FTOK_RPAREN )  *)
    (* TC #define FBIT_AVAL ( 1L < < FTOK_AVAL )  *)
    (* TC #define FBIT_EQ ( 1L < < FTOK_EQ )  *)
    (* TC #define FBIT_GE ( 1L < < FTOK_GE )  *)
    (* TC #define FBIT_LE ( 1L < < FTOK_LE )  *)
    (* TC #define FBIT_APPROX ( 1L < < FTOK_APPROX )  *)
    (* TC #define FBIT_ANAME ( 1L < < FTOK_ANAME )  *)
    (* TC #define FBIT_PRESENT ( 1L < < FTOK_PRESENT )  *)
    (* TC #define FBIT_RDN ( 1L < < FTOK_RDN )  *)
    (* TC #define FBIT_BASECLS ( 1L < < FTOK_BASECLS )  *)
    (* TC #define FBIT_MODTIME ( 1L < < FTOK_MODTIME )  *)
    (* TC #define FBIT_VALTIME ( 1L < < FTOK_VALTIME )  *)
    (* TC #define FBIT_OPERAND ( FBIT_LPAREN | FBIT_NOT | FBIT_PRESENT | FBIT_RDN | FBIT_BASECLS | FBIT_ANAME | FBIT_MODTIME | FBIT_VALTIME )  *)
    (* TC #define FBIT_RELOP ( FBIT_EQ | FBIT_GE | FBIT_LE | FBIT_APPROX )  *)
    (* TC #define FBIT_BOOLOP ( FBIT_AND | FBIT_OR )  *)
    Type
        Filter_Cursor_T = Record
            fn  :   pFilter_Node_T ;
            level  :   nuint16 ;
            expect  :   nuint32 ;
        End;
        pFilter_Cursor_T = ^Filter_Cursor_T;
        ppFilter_Cursor_T = ^Filter_Cursor_T;
    {$DEFINE FTAG_ITEM}
    Const FTAG_ITEM = 0;
    {$DEFINE FTAG_OR}
    Const FTAG_OR = 1;
    {$DEFINE FTAG_AND}
    Const FTAG_AND = 2;
    {$DEFINE FTAG_NOT}
    Const FTAG_NOT = 3;
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    Function NWDSAddFilterToken (
        cur  :   pFilter_Cursor_T ;
        tok  :   nuint16 ;
        val  :   nptr ;
        syntax  :   nuint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSAllocFilter (
        cur  :   ppFilter_Cursor_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Type freeVal = Procedure (  syntax : nuint32; val : nptr ); 

    Procedure NWDSFreeFilter (
        cur  :   pFilter_Cursor_T ;
        freeVal1 :  freeVal 
    );
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}   

    Function NWDSPutFilter (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        cur  :   pFilter_Cursor_T ;
        freeVal1 : freeVal  
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
       Function NWDSDelFilterToken (
        cur  :   pFilter_Cursor_T ;
        freeVal1 : freeVal  
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF} 
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

