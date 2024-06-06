(******************************************************************************

  %name: nwconfig.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:06:05 1996 %
  $Copyright:

  Copyright (c) 1989-1996 Novell, Inc.  All Rights Reserved.                      

  THIS WORK IS  SUBJECT  TO  U.S.  AND  INTERNATIONAL  COPYRIGHT  LAWS  AND
  TREATIES.   NO  PART  OF  THIS  WORK MAY BE  USED,  PRACTICED,  PERFORMED
  COPIED, DISTRIBUTED, REVISED, MODIFIED, TRANSLATED,  ABRIDGED, CONDENSED,
  EXPANDED,  COLLECTED,  COMPILED,  LINKED,  RECAST, TRANSFORMED OR ADAPTED
  WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC. ANY USE OR EXPLOITATION
  OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT THE PERPETRATOR TO
  CRIMINAL AND CIVIL LIABILITY.$

 *****************************************************************************)


{$IFNDEF  NWCONFIG_H }
    {$DEFINE NWCONFIG_H}
    {$I npackon.inc}
    {$DEFINE T_OPTIONAL}
    Const T_OPTIONAL = $80;
    {$DEFINE T_NUMBER}
    Const T_NUMBER = $01;
    {$DEFINE T_INDEX}
    Const T_INDEX = $02;
    {$DEFINE T_STRING}
    Const T_STRING = $03;
    {$DEFINE T_HEX_STRING}
    Const T_HEX_STRING = $04;
    {$DEFINE T_HEX_NUMBER}
    Const T_HEX_NUMBER = $05;
    {$DEFINE T_LONG_NUMBER}
    Const T_LONG_NUMBER = $06;
    {$DEFINE T_LONG_HEX}
    Const T_LONG_HEX = $07;
    {$DEFINE T_SET_1}
    Const T_SET_1 = $10;
    {$DEFINE T_SET_2}
    Const T_SET_2 = $11;
    {$DEFINE T_SET_3}
    Const T_SET_3 = $12;
    {$DEFINE T_SET_4}
    Const T_SET_4 = $13;
    {$DEFINE T_SET_5}
    Const T_SET_5 = $14;
    {$DEFINE T_SET_6}
    Const T_SET_6 = $15;
    {$DEFINE T_SET_7}
    Const T_SET_7 = $16;
    {$DEFINE T_SET_8}
    Const T_SET_8 = $17;
    {$DEFINE T_SET_9}
    Const T_SET_9 = $18;
    {$DEFINE T_SET_10}
    Const T_SET_10 = $19;
    {$DEFINE T_SET_11}
    Const T_SET_11 = $1A;
    {$DEFINE T_SET_12}
    Const T_SET_12 = $1B;
    {$DEFINE T_SET_13}
    Const T_SET_13 = $1C;
    {$DEFINE T_SET_14}
    Const T_SET_14 = $1D;
    {$DEFINE T_SET_15}
    Const T_SET_15 = $1E;
    {$DEFINE T_SET_16}
    Const T_SET_16 = $1F;
    {$DEFINE MAX_PARAMETERS}
    Const MAX_PARAMETERS = 8;
    {$DEFINE MAX_SECTION_NAME_SIZE}
    Const MAX_SECTION_NAME_SIZE = 32;
    {$DEFINE MAX_VALUE_SIZE}
    Const MAX_VALUE_SIZE = 80;
    {$DEFINE MAX_SET_ELEMENTS}
    Const MAX_SET_ELEMENTS = 20;
    Type
        SetTableStruct = Record
            numberOfElements  :  nint32;
            elementCode  :  ^nint32;
            elementName  :  ^nint8;
            elementValue  :  ^nint32;
        End;
    Type
        TypeDefaultStruct = Record
            paramType  :  nint32;
            defaultValue  :  nint32;
        End;
    Type string1  =  ^nint8;  (* union statement *)
    Type PARAMETER_TABLE_TYPE = string1;
           function1 = Procedure( x : ^PARAMETER_TABLE_TYPE );

    Type
        GrammarTableStruct = Record
            keywordCode  :  nint32;
            keyword  :  ^nint8;
            function2 : function1;
            typeDefault  :  Array[0..MAX_PARAMETERS-1] Of  TypeDefaultStruct ;
        End;
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    (* Not implemented Function NWParseConfig (
        configFile  :   PCHAR ;
        sectionName  :   PCHAR ;
        sectionInstance  :   UINT ;
        grammarTableSize  :   UINT ;
        Var grammarTable  : GrammarTableStruct;
        Var setTable  : SetTableStruct
    ) : nint32;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

