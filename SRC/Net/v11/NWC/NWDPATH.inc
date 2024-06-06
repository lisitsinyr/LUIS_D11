(******************************************************************************

  %name: nwdpath.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:06:32 1996 %
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


{$IFNDEF  NWDPATH_H }
    {$DEFINE NWDPATH_H}
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
    (* status values for NWGetDriveStatus *)
    {$DEFINE NW_UNMAPPED_DRIVE}
    Const NW_UNMAPPED_DRIVE = $0000;
    {$DEFINE NW_FREE_DRIVE}
    Const NW_FREE_DRIVE = $0000;
    {$DEFINE NW_CDROM_DRIVE}
    Const NW_CDROM_DRIVE = $0400;
    {$DEFINE NW_LOCAL_FREE_DRIVE}
    Const NW_LOCAL_FREE_DRIVE = $0800;
    {$DEFINE NW_LOCAL_DRIVE}
    Const NW_LOCAL_DRIVE = $1000;
    {$DEFINE NW_NETWORK_DRIVE}
    Const NW_NETWORK_DRIVE = $2000;
    {$DEFINE NW_LITE_DRIVE}
    Const NW_LITE_DRIVE = $4000;
    {$DEFINE NW_PNW_DRIVE}
    Const NW_PNW_DRIVE = $4000;
    {$DEFINE NW_NETWARE_DRIVE}
    Const NW_NETWARE_DRIVE = $8000;
    (* return error for NWGetDriveStatus *)
    {$DEFINE NW_INVALID_DRIVE}
    Const NW_INVALID_DRIVE = 15;
    (* defined for pathFormat parameter in NWGetDriveStatus *)
    {$DEFINE NW_FORMAT_NETWARE}
    Const NW_FORMAT_NETWARE = 0;
    {$DEFINE NW_FORMAT_SERVER_VOLUME}
    Const NW_FORMAT_SERVER_VOLUME = 1;
    {$DEFINE NW_FORMAT_DRIVE}
    Const NW_FORMAT_DRIVE = 2;
    {$DEFINE NW_FORMAT_UNC}
    Const NW_FORMAT_UNC = 3;
    Function NWSetDriveBase (
        driveNum  :   nuint16 ;
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        dirPath  :   pnstr8 ;
        driveScope  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSetInitDrive (
        conn  :   NWCONN_HANDLE 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* Not implemented Function NWSetSearchDriveVector (
        vectorBuffer  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    (* Not implemented Function NWGetSearchDriveVector (
        vectorBuffer  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    Function NWDeleteDriveBase (
        driveNum  :   nuint16 ;
        driveScope  :   nuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetPathFromDirectoryBase (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint8 ;
        dirBase  :   nuint32 ;
        namSpc  :   nuint8 ;
        len  :   pnuint8 ;
        pathName  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetPathFromDirectoryEntry (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint8 ;
        dirEntry  :   nuint16 ;
        len  :   pnuint8 ;
        pathName  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetDrivePathConnRef (
        driveNum  :   nuint16 ;
        mode  :   nuint16 ;
        connRef  :   pnuint32 ;
        basePath  :   pnstr8 ;
        driveScope  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetDrivePath (
        driveNum  :   nuint16 ;
        mode  :   nuint16 ;
        Var conn  : NWCONN_HANDLE;
        basePath  :   pnstr8 ;
        driveScope  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetDriveInformation (
        driveNum  :   nuint16 ;
        mode  :   nuint16 ;
        Var conn  : NWCONN_HANDLE;
        Var dirHandle  : NWDIR_HANDLE;
        driveScope  :   pnuint16 ;
        dirPath  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetDriveInfoConnRef (
        driveNum  :   nuint16 ;
        mode  :   nuint16 ;
        connRef  :   pnuint32 ;
        Var dirHandle  : NWDIR_HANDLE;
        driveScope  :   pnuint16 ;
        dirPath  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetDriveStatus (
        driveNum  :   nuint16 ;
        pathFormat  :   nuint16 ;
        status  :   pnuint16 ;
        Var conn  : NWCONN_HANDLE;
        rootPath  :   pnstr8 ;
        relPath  :   pnstr8 ;
        fullPath  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetDriveStatusConnRef (
        driveNum  :   nuint16 ;
        pathFormat  :   nuint16 ;
        status  :   pnuint16 ;
        connRef  :   pnuint32 ;
        rootPath  :   pnstr8 ;
        relPath  :   pnstr8 ;
        fullPath  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetFirstDrive (
        firstDrive  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWParseNetWarePath (
        path  :   pnstr8 ;
        Var conn  : NWCONN_HANDLE;
        Var dirHandle  : NWDIR_HANDLE;
        newPath  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* Not implemented Function NWParseNetWarePathConnRef (
        path  :   pnstr8 ;
        connRef  :   pnuint32 ;
        Var dirHandle  : NWDIR_HANDLE;
        newPath  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    Function NWParsePathConnRef (
        path  :   pnstr8 ;
        serverName  :   pnstr8 ;
        connRef  :   pnuint32 ;
        volName  :   pnstr8 ;
        dirPath  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWParsePath (
        path  :   pnstr8 ;
        serverName  :   pnstr8 ;
        Var conn  : NWCONN_HANDLE;
        volName  :   pnstr8 ;
        dirPath  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWStripServerOffPath (
        path  :   pnstr8 ;
        server  :   pnstr8 
    ) : pnstr8;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCreateUNCPath (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        UNCPath  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

