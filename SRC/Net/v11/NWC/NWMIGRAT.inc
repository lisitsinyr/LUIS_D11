(******************************************************************************

  %name: nwmigrat.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:08:32 1996 %
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


{$IFNDEF  NWMIGRAT_H }
    {$DEFINE NWMIGRAT_H}
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
    {$DEFINE MAX_NUM_OF_DATA_STREAMS}
    Const MAX_NUM_OF_DATA_STREAMS = 3;
    {$DEFINE MAX_SIZE_OF_SM_STRING}
    Const MAX_SIZE_OF_SM_STRING = 128;
    {$DEFINE MAX_SIZE_OF_SM_INFO}
    Const MAX_SIZE_OF_SM_INFO = 128;
    {$DEFINE MAX_NUM_OF_SM}
    Const MAX_NUM_OF_SM = 32;
    {$DEFINE ERR_INVALID_SM_ID}
    Const ERR_INVALID_SM_ID = 240;
    {$DEFINE ERR_SM_ALREADY_REGISTERED}
    Const ERR_SM_ALREADY_REGISTERED = 241;
    {$DEFINE ERR_SM_CREATE_FAILED}
    Const ERR_SM_CREATE_FAILED = 242;
    {$DEFINE ERR_SM_CLOSE_FAILED}
    Const ERR_SM_CLOSE_FAILED = 243;
    {$DEFINE ERR_SM_WRITE_NO_SPACE}
    Const ERR_SM_WRITE_NO_SPACE = 244;
    {$DEFINE ERR_SM_WRITE_IO_ERROR}
    Const ERR_SM_WRITE_IO_ERROR = 245;
    {$DEFINE ERR_SM_READ_IO_ERROR}
    Const ERR_SM_READ_IO_ERROR = 246;
    {$DEFINE ERR_SM_OPEN_FAILED}
    Const ERR_SM_OPEN_FAILED = 247;
    {$DEFINE ERR_SM_DELETE_FAILED}
    Const ERR_SM_DELETE_FAILED = 248;
    Type
        SUPPORT_MODULE_INFO = Record
            IOStatus  :   nuint32 ;
            InfoBlockSize  :   nuint32 ;
            AvailSpace  :   nuint32 ;
            UsedSpace  :   nuint32 ;
            (* A length preceded string is followed by SMInfo data *)
            SMInfo  :  Array[0..MAX_SIZE_OF_SM_STRING+MAX_SIZE_OF_SM_INFO-1] Of  nuint8 ;
        End;
    Type
        SUPPORT_MODULE_IDS = Record
            numberOfSMs  :   nuint32 ;
            SMIDs  :  Array[0..MAX_NUM_OF_SM-1] Of  nuint32 ;
        End;
    {$IFDEF  N_PLAT_NLM }
        Type NWMoveFileToDM = NWMoveFileToDM2;
        Type NWMoveFileFromDM = NWMoveFileFromDM2;
        Type NWGetDMFileInfo = NWGetDMFileInfo2;
        Type NWGetDMVolumeInfo = NWGetDMVolumeInfo2;
        Type NWGetDefaultSupportModule = NWGetDefaultSupportModule2;
        Type NWSetDefaultSupportModule = NWSetDefaultSupportModule2;
        Type NWGetDataMigratorInfo = NWGetDataMigratorInfo2;
        Type NWGetSupportModuleInfo = NWGetSupportModuleInfo2;
    {$ENDIF}
    Function NWMoveFileToDM (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        nameSpace  :   nuint8 ;
        supportModuleID  :   nuint32 ;
        saveKeyFlag  :   nuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWMoveFileFromDM (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        nameSpace  :   nuint8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetDMFileInfo (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        path  :   pnstr8 ;
        nameSpace  :   nuint8 ;
        supportModuleID  :   pnuint32 ;
        restoreTime  :   pnuint32 ;
        dataStreams  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetDMVolumeInfo (
        conn  :   NWCONN_HANDLE ;
        volume  :   nuint16 ;
        supportModuleID  :   nuint32 ;
        numberOfFilesMigrated  :   pnuint32 ;
        totalMigratedSize  :   pnuint32 ;
        spaceUsedOnDM  :   pnuint32 ;
        limboSpaceUsedOnDM  :   pnuint32 ;
        spaceMigrated  :   pnuint32 ;
        filesInLimbo  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetSupportModuleInfo (
        conn  :   NWCONN_HANDLE ;
        infomationLevel  :   nuint32 ;
        supportModuleID  :   nuint32 ;
        returnInfo  :   pnuint8 ;
        returnInfoLen  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetDataMigratorInfo (
        conn  :   NWCONN_HANDLE ;
        DMPresentFlag  :   pnuint32 ;
        majorVersion  :   pnuint32 ;
        minorVersion  :   pnuint32 ;
        DMSMRegistered  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetDefaultSupportModule (
        conn  :   NWCONN_HANDLE ;
        supportModuleID  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSetDefaultSupportModule (
        conn  :   NWCONN_HANDLE ;
        supportModuleID  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetSupportModuleCapacity (
        conn  :   NWCONN_HANDLE ;
        luSupportModuleID  :   nuint32 ;
        luVolume  :   nuint32 ;
        luDirectoryBase  :   nuint32 ;
        pluSMBlockSizeInSectors  :   pnuint32 ;
        pluSMTotalBlocks  :   pnuint32 ;
        pluSMUsedBlocks  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

