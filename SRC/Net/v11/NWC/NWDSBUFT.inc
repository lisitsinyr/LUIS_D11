(******************************************************************************

  %name :          %
  %version :       %
  %date_modified : %
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

{$IFNDEF  NWDSBUFT_H }
    {$DEFINE NWDSBUFT_H}
    {$IFNDEF _STRUCT_TM}
{$DEFINE _STRUCT_TM}
Type tm = Record
tm_sec : integer;
tm_min : integer;
tm_hour : integer;
tm_mday : integer;
tm_mon : integer;
tm_year : integer;
tm_wday : integer;
tm_yday : integer;
tm_isdst : integer;
End;
{$ENDIF}

    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
    {$IFNDEF  NWDSTYPE_H }
        {$I nwdstype.inc}
    {$ENDIF}
    {$IFNDEF  NWDSDC_H }
        {$I nwdsdc.inc}
    {$ENDIF}
    {$IFNDEF  NWDSDEFS_H }
        {$I nwdsdefs.inc}
    {$ENDIF}
    {$I npackon.inc}
    {$DEFINE INPUT_BUFFER}
    Const INPUT_BUFFER = $00000001;
    Type
        Buf_T = Record
            operation  :   nuint32 ;
            flags  :   nuint32 ;
            maxLen  :   nuint32 ;
            curLen  :   nuint32 ;
            lastCount  :   pnuint8 ;
            curPos  :   pnuint8 ;
            data  :   pnuint8 ;
        End;
        pBuf_T = ^Buf_T;
        ppBuf_T = ^Buf_T;
    Type
        Object_Info_T = Record
            objectFlags  :   nuint32 ;
            subordinateCount  :   nuint32 ;
            modificationTime  :   time_t ;
            baseClass  :  Array[0..135] Of nint8;
        End;
        pObject_Info_T = ^Object_Info_T;
    Type
        Asn1ID_T = Record
            length  :   nuint32 ;
            data  :  Array[0..MAX_ASN1_NAME-1] Of  nuint8 ;
        End;
        pAsn1ID_T = ^Asn1ID_T;
    Type
        Attr_Info_T = Record
            attrFlags  :   nuint32 ;
            attrSyntaxID  :   nint32 ;
            attrLower  :   nint32 ;
            attrUpper  :   nint32 ;
            asn1ID  :   Asn1ID_T ;
        End;
        pAttr_Info_T = ^Attr_Info_T;
    Type
        Class_Info_T = Record
            classFlags  :   nuint32 ;
            asn1ID  :   Asn1ID_T ;
        End;
        pClass_Info_T = ^Class_Info_T;
    Type
        Syntax_Info_T = Record
            ID  :   nuint32 ;
            defStr  :  Array[0..135] Of nint8;
            flags  :   nflag16 ;
        End;
        pSyntax_Info_T = ^Syntax_Info_T;
    (* TC #define NWDSPutClassName ( c , b , n ) NWDSPutClassItem ( c , b , n )  *)
    (* TC #define NWDSPutSyntaxName ( c , b , n ) NWDSPutClassItem ( c , b , n )  *)
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    Function NWDSAllocBuf (
        size  :   size_t ;
        buf  :   ppBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSComputeAttrValSize (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        syntaxID  :   nuint32 ;
        attrValSize  :   pnuint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSFreeBuf (
        buf  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetAttrCount (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        attrCount  :   pnuint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetAttrDef (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        attrName  :   pnstr8 ;
        attrInfo  :   pAttr_Info_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetAttrName (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        attrName  :   pnstr8 ;
        attrValCount  :   pnuint32 ;
        syntaxID  :   pnuint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetAttrVal (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        syntaxID  :   nuint32 ;
        attrVal  :   nptr 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
(*
    function NWDSGetAttrValModTime (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        timeStamp : pTimeStamp_T;
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}

    function NWDSGetAttrValFlags (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        valueFlags: pnuint32
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
*)
    Function NWDSGetClassDef (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        className  :   pnstr8 ;
        classInfo  :   pClass_Info_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetClassDefCount (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        classDefCount  :   pnuint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetClassItem (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        itemName  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetClassItemCount (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        itemCount  :   pnuint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetObjectCount (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        objectCount  :   pnuint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetObjectName (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        objectName  :   pnstr8 ;
        attrCount  :   pnuint32 ;
        objectInfo  :   pObject_Info_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* Not implemented Function NWDSGetObjectNameAndInfo (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        objectName  :   pnstr8 ;
        attrCount  :   pnuint32 ;
        objectInfo  :   ppnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    Function NWDSGetDSIInfo (
        context  :   NWDSContextHandle ;
        buf  :   nptr ;
        bufLen  :   nuint32 ;
        infoFlag  :   nuint32 ;
        data  :   nptr 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetPartitionInfo (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        partitionName  :   pnstr8 ;
        replicaType  :   pnuint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetReplicaReferenceRootID (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        replicaRootID  :   pnuint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetServerName (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        serverName  :   pnstr8 ;
        partitionCount  :   pnuint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetPartitionExtInfoPtr (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        infoPtr  :   ppnstr8 ;
        infoPtrEnd  :   ppnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetPartitionExtInfo (
        context  :   NWDSContextHandle ;
        infoPtr  :   pnstr8 ;
        limit  :   pnstr8 ;
        infoFlag  :   nflag32 ;
        length  :   pnuint32 ;
        data  :   nptr 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetSyntaxCount (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        syntaxCount  :   pnuint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetSyntaxDef (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        syntaxName  :   pnstr8 ;
        syntaxDef  :   pSyntax_Info_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSInitBuf (
        context  :   NWDSContextHandle ;
        operation  :   nuint32 ;
        buf  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSPutAttrName (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        attrName  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSPutAttrVal (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        syntaxID  :   nuint32 ;
        attrVal  :   nptr 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSPutAttrNameAndVal (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        attrName  :   pnstr8 ;
        syntaxID  :   nuint32 ;
        attrVal  :   nptr 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSPutChange (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        changeType  :   nuint32 ;
        attrName  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSPutChangeAndVal (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        changeType  :   nuint32 ;
        attrName  :   pnstr8 ;
        syntaxID  :   nuint32 ;
        attrVal  :   nptr 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSPutClassItem (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T ;
        itemName  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSBeginClassItem (
        context  :   NWDSContextHandle ;
        buf  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

