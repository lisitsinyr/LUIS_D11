(******************************************************************************

  %name:          nwdsdsa.h %
  %version:       4 %
  %date_modified: Fri Mar  7 16:56:12 1997 %
  $Copyright:

  Copyright (c) 1989-1997 Novell, Inc.  All Rights Reserved.                      

  THIS WORK IS  SUBJECT  TO  U.S.  AND  INTERNATIONAL  COPYRIGHT  LAWS  AND
  TREATIES.   NO  PART  OF  THIS  WORK MAY BE  USED,  PRACTICED,  PERFORMED
  COPIED, DISTRIBUTED, REVISED, MODIFIED, TRANSLATED,  ABRIDGED, CONDENSED,
  EXPANDED,  COLLECTED,  COMPILED,  LINKED,  RECAST, TRANSFORMED OR ADAPTED
  WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC. ANY USE OR EXPLOITATION
  OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT THE PERPETRATOR TO
  CRIMINAL AND CIVIL LIABILITY.$

 *****************************************************************************)

{$IFNDEF  NWDSDSA_H }
    {$DEFINE NWDSDSA_H}
    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
    {$IFNDEF  NWDSBUFT_H }
        {$I nwdsbuft.inc}
    {$ENDIF}
    {$IFNDEF  NWDSATTR_H }
        {$I nwdsattr.inc}
    {$ENDIF}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$IFNDEF  UNICODE_H }
        {$I unicode.inc}
    {$ENDIF}
    {$I npackon.inc}
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    Function NWDSAddObject (
        context  :   NWDSContextHandle ;
        objectName  :   pnstr8 ;
        iterationHandle  :   pnint32 ;
        more  :   nbool8 ;
        objectInfo  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSBackupObject (
        context  :   NWDSContextHandle ;
        objectName  :   pnstr8 ;
        iterationHandle  :   pnint32 ;
        objectInfo  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSCompare (
        context  :   NWDSContextHandle ;
        object1  :   pnstr8 ;
        buf  :   pBuf_T ;
        matched  :   pnbool8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetPartitionRoot (
        context  :   NWDSContextHandle ;
        objectName  :   pnstr8 ;
        partitionRoot  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSList (
        context  :   NWDSContextHandle ;
        object1  :   pnstr8 ;
        iterationHandle  :   pnint32 ;
        subordinates  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSListContainers (
        context  :   NWDSContextHandle ;
        object1  :   pnstr8 ;
        iterationHandle  :   pnint32 ;
        subordinates  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSListByClassAndName (
        context  :   NWDSContextHandle ;
        objectName  :   pnstr8 ;
        className  :   pnstr8 ;
        subordinateName  :   pnstr8 ;
        iterationHandle  :   pnint32 ;
        subordinates  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetCountByClassAndName (
        context  :   NWDSContextHandle ;
        objectName  :   pnstr8 ;
        className  :   pnstr8 ;
        subordinateName  :   pnstr8 ;
        count  :   pnint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSMapIDToName (
        context  :   NWDSContextHandle ;
        connHandle  :   NWCONN_HANDLE ;
        objectID  :   nuint32 ;
        object1  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSMapNameToID (
        context  :   NWDSContextHandle ;
        connHandle  :   NWCONN_HANDLE ;
        object1  :   pnstr8 ;
        objectID  :   pnuint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSModifyObject (
        context  :   NWDSContextHandle ;
        objectName  :   pnstr8 ;
        iterationHandle  :   pnint32 ;
        more  :   nbool8 ;
        changes  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSModifyDN (
        context  :   NWDSContextHandle ;
        objectName  :   pnstr8 ;
        newDN  :   pnstr8 ;
        deleteOldRDN  :   nbool8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSModifyRDN (
        context  :   NWDSContextHandle ;
        objectName  :   pnstr8 ;
        newDN  :   pnstr8 ;
        deleteOldRDN  :   nbool8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSMoveObject (
        context  :   NWDSContextHandle ;
        objectName  :   pnstr8 ;
        destParentDN  :   pnstr8 ;
        destRDN  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSRead (
        context  :   NWDSContextHandle ;
        object1  :   pnstr8 ;
        infoType  :   nuint32 ;
        allAttrs  :   nbool8 ;
        attrNames  :   pBuf_T ;
        iterationHandle  :   pnint32 ;
        objectInfo  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSReadObjectInfo (
        context  :   NWDSContextHandle ;
        object1  :   pnstr8 ;
        distinguishedName  :   pnstr8 ;
        objectInfo  :   pObject_Info_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSReadObjectDSIInfo (
        context  :   NWDSContextHandle ;
        object1  :   pnstr8 ;
        infoLength  :   nuint32 ;
        objectInfo  :   nptr 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSRemoveObject (
        context  :   NWDSContextHandle ;
        object1  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSRestoreObject (
        context  :   NWDSContextHandle ;
        objectName  :   pnstr8 ;
        iterationHandle  :   pnint32 ;
        more  :   nbool8 ;
        size  :   nuint32 ;
        objectInfo  :   pnuint8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSSearch (
        context  :   NWDSContextHandle ;
        baseObjectName  :   pnstr8 ;
        scope  :   nint ;
        searchAliases  :   nbool8 ;
        filter  :   pBuf_T ;
        infoType  :   nuint32 ;
        allAttrs  :   nbool8 ;
        attrNames  :   pBuf_T ;
        iterationHandle  :   pnint32 ;
        countObjectsToSearch  :   nint32 ;
        countObjectsSearched  :   pnint32 ;
        objectInfo  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSOpenStream (
        context  :   NWDSContextHandle ;
        objectName  :   pnstr8 ;
        attrName  :   pnstr8 ;
        flags  :   nflag32 ;
        Var fileHandle  : NWFILE_HANDLE
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSWhoAmI (
        context  :   NWDSContextHandle ;
        objectName  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetServerDN (
        context  :   NWDSContextHandle ;
        connHandle  :   NWCONN_HANDLE ;
        serverDN  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetServerAddresses (
        context  :   NWDSContextHandle ;
        connHandle  :   NWCONN_HANDLE ;
        countNetAddress  :   pnuint32 ;
        netAddresses  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSGetServerAddresses2 (
        context  :   NWDSContextHandle ;
        connHandle  :   NWCONN_HANDLE ;
        countNetAddress  :   pnuint32 ;
        netAddresses  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSInspectEntry (
        context  :   NWDSContextHandle ;
        serverName  :   pnstr8 ;
        objectName  :   pnstr8 ;
        errBuffer  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSReadReferences (
        context  :   NWDSContextHandle ;
        serverName  :   pnstr8 ;
        objectName  :   pnstr8 ;
        infoType  :   nuint32 ;
        allAttrs  :   nbool8 ;
        attrNames  :   pBuf_T ;
        timeFilter  :   nuint32 ;
        iterationHandle  :   pnint32 ;
        objectInfo  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSExtSyncList (
        context  :   NWDSContextHandle ;
        objectName  :   pnstr8 ;
        className  :   pnstr8 ;
        subordinateName  :   pnstr8 ;
        iterationHandle  :   pnint32 ;
        timeStamp  :   pTimeStamp_T ;
        onlyContainers  :   nbool ;
        subordinates  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSExtSyncRead (
        context  :   NWDSContextHandle ;
        objectName  :   pnstr8 ;
        infoType  :   nuint32 ;
        allAttrs  :   nbool8 ;
        attrNames  :   pBuf_T ;
        iterationHandle  :   pnint32 ;
        timeStamp  :   pTimeStamp_T ;
        objectInfo  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSExtSyncSearch (
        context  :   NWDSContextHandle ;
        baseObjectName  :   pnstr8 ;
        scope  :   nint ;
        searchAliases  :   nbool8 ;
        filter  :   pBuf_T ;
        timeStamp  :   pTimeStamp_T ;
        infoType  :   nuint32 ;
        allAttrs  :   nbool8 ;
        attrNames  :   pBuf_T ;
        iterationHandle  :   pnint32 ;
        countObjectsToSearch  :   nint32 ;
        countObjectsSearched  :   pnint32 ;
        objectInfo  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSRemSecurityEquiv (
        context  :   NWDSContextHandle ;
        equalFrom  :   pnstr8 ;
        equalTo  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSAddSecurityEquiv (
        context  :   NWDSContextHandle ;
        equalFrom  :   pnstr8 ;
        equalTo  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (*----- NDS Register For Event Function Prototypes -----*)
    {$IFDEF  N_PLAT_NLM }
        (* Not implemented Function NWDSERegisterForEvent (
            priority  :   nint ;
            type1  :   nuint32 ;
            (* TC nint (* handler ) ( nuint32 type , nuint size , nptr data ) *)
        ) : NWDSCCODE;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
        (* Not implemented Function NWDSEUnRegisterForEvent (
            priority  :   nint ;
            type1  :   nuint32 ;
            (* TC nint (* handler ) ( nuint32 type , nuint size , nptr data ) *)
        ) : NWDSCCODE;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
        (* Not implemented Function NWDSEGetLocalEntryName (
            context  :   NWDSContextHandle ;
            entryID  :   nuint32 ;
            objectName  :   pnstr 
        ) : NWDSCCODE;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
        (* Not implemented Function NWDSEConvertEntryName (
            context  :   NWDSContextHandle ;
            const DSEventName  :   punicode ;
            objectName  :   pnstr 
        ) : NWDSCCODE;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
        (* Not implemented Function NWDSEGetLocalAttrName (
            context  :   NWDSContextHandle ;
            attrID  :   nuint32 ;
            name  :   pnstr 
        ) : NWDSCCODE;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
        (* Not implemented Function NWDSEGetLocalClassName (
            context  :   NWDSContextHandle ;
            classID  :   nuint32 ;
            name  :   pnstr 
        ) : NWDSCCODE;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
        (* Not implemented Function NWDSEGetLocalAttrID (
            context  :   NWDSContextHandle ;
            const name  :   pnstr ;
            id  :   pnuint32 
        ) : NWDSCCODE;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
        (* Not implemented Function NWDSEGetLocalClassID (
            context  :   NWDSContextHandle ;
            const name  :   pnstr ;
            id  :   pnuint32 
        ) : NWDSCCODE;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
        (* Not implemented Function NWDSEGetLocalEntryID (
            context  :   NWDSContextHandle ;
            const objectName  :   pnstr ;
            id  :   pnuint32 
        ) : NWDSCCODE;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

