(******************************************************************************

  %name: nwdssch.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:08:00 1996 %
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

{$IFNDEF  NWDSSCH_H }
    {$DEFINE NWDSSCH_H}
    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
    {$IFNDEF  NWDSTYPE_H }
        {$I nwdstype.inc}
    {$ENDIF}
    {$IFNDEF  NWDSBUFT_H }
        {$I nwdsbuft.inc}
    {$ENDIF}
    {$IFNDEF  NWDSATTR_H }
        {$I nwdsattr.inc}
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    Function NWDSDefineAttr (
        context  :   NWDSContextHandle ;
        attrName  :   pnstr8 ;
        attrDef  :   pAttr_Info_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSDefineClass (
        context  :   NWDSContextHandle ;
        className  :   pnstr8 ;
        classInfo  :   pClass_Info_T ;
        classItems  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSListContainableClasses (
        context  :   NWDSContextHandle ;
        parentObject  :   pnstr8 ;
        iterationHandle  :   pnint32 ;
        containableClasses  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSModifyClassDef (
        context  :   NWDSContextHandle ;
        className  :   pnstr8 ;
        optionalAttrs  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSReadAttrDef (
        context  :   NWDSContextHandle ;
        infoType  :   nuint32 ;
        allAttrs  :   nbool8 ;
        attrNames  :   pBuf_T ;
        iterationHandle  :   pnint32 ;
        attrDefs  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSReadClassDef (
        context  :   NWDSContextHandle ;
        infoType  :   nuint32 ;
        allClasses  :   nbool8 ;
        classNames  :   pBuf_T ;
        iterationHandle  :   pnint32 ;
        classDefs  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSRemoveAttrDef (
        context  :   NWDSContextHandle ;
        attrName  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSRemoveClassDef (
        context  :   NWDSContextHandle ;
        className  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSSyncSchema (
        context  :   NWDSContextHandle ;
        server  :   pnstr8 ;
        seconds  :   nuint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
{$ENDIF}

