(******************************************************************************

  %name: nwdel.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:06:16 1996 %
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


{$IFNDEF  NWDEL_H }
    {$DEFINE NWDEL_H}
    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
    {$IFNDEF  NWCALDEF_H }
        {$I nwcaldef.inc}
    {$ENDIF}
    {$I npackon.inc}
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    Type
        NWDELETED_INFO = Record
            sequence  :   nuint32 ;
            parent  :   nuint32 ;
            attributes  :   nuint32 ;
            uniqueID  :   nuint8 ;
            flags  :   nuint8 ;
            nameSpace  :   nuint8 ;
            nameLength  :   nuint8 ;
            name  :  Array[0..255] Of  nuint8 ;
            creationDateAndTime  :   nuint32 ;
            ownerID  :   nuint32 ;
            lastArchiveDateAndTime  :   nuint32 ;
            lastArchiverID  :   nuint32 ;
            updateDateAndTime  :   nuint32 ;
            updatorID  :   nuint32 ;
            fileSize  :   nuint32 ;
            reserved  :  Array[0..43] Of  nuint8 ;
            inheritedRightsMask  :   nuint16 ;
            lastAccessDate  :   nuint16 ;
            deletedTime  :   nuint32 ;
            deletedDateAndTime  :   nuint32 ;
            deletorID  :   nuint32 ;
            reserved3  :  Array[0..15] Of  nuint8 ;
        End;
    Function NWPurgeDeletedFile (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        iterHandle  :   nuint32 ;
        volNum  :   nuint32 ;
        dirBase  :   nuint32 ;
        fileName  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWRecoverDeletedFile (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        iterHandle  :   nuint32 ;
        volNum  :   nuint32 ;
        dirBase  :   nuint32 ;
        delFileName  :   pnstr8 ;
        rcvrFileName  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWScanForDeletedFiles (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        iterHandle  :   pnuint32 ;
        volNum  :   pnuint32 ;
        dirBase  :   pnuint32 ;
        Var entryInfo  : NWDELETED_INFO
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWPurgeErasedFiles (
        conn  :   NWCONN_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWRestoreErasedFile (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        dirPath  :   pnstr8 ;
        oldName  :   pnstr8 ;
        newName  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

