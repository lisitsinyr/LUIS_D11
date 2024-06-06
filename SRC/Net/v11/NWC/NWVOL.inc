(******************************************************************************

  %name: nwvol.h %
  %version: 4 %
  %date_modified: Fri Mar 14 15:06:32 1997 %
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


{$IFNDEF  NWVOL_H }
    {$DEFINE NWVOL_H}
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
    (* define volume types  *)
    {$DEFINE VINetWare386}
    Const VINetWare386 = 0;
    {$DEFINE VINetWare286}
    Const VINetWare286 = 1;
    {$DEFINE VINetWare386v30}
    Const VINetWare386v30 = 2;
    {$DEFINE VINetWare386v31}
    Const VINetWare386v31 = 3;
    (*    define the extended volume information status flag bits  *)
    {$DEFINE NWSubAllocEnabledBit}
    Const NWSubAllocEnabledBit = $01;
    {$DEFINE NWCompressionEnabledBit}
    Const NWCompressionEnabledBit = $02;
    {$DEFINE NWMigrationEnabledBit}
    Const NWMigrationEnabledBit = $04;
    {$DEFINE NWAuditingEnabledBit}
    Const NWAuditingEnabledBit = $08;
    {$DEFINE NWReadOnlyEnabledBit}
    Const NWReadOnlyEnabledBit = $10;
    {$DEFINE NWPSSEnabledBit}
    Const NWPSSEnabledBit = $80000000;
    Type
        NWOBJ_REST = Record
            objectID  :   nuint32 ;
            restriction  :   nuint32 ;
        End;
    Type
        NWVolumeRestrictions = Record
            numberOfEntries  :   nuint8 ;
            resInfo : Array[0..11] of Record
                objectID  :   nuint32 ;
                restriction  :   nuint32 ;
            End;
        End;
    Type
        NWVOL_RESTRICTIONS = Record
            numberOfEntries  :   nuint8 ;
            resInfo : Array[0..15] of Record
                objectID  :   nuint32 ;
                restriction  :   nuint32 ;
            End;
        End;
    Type
        VOL_STATS = Record
            systemElapsedTime  :   nint32 ;
            volumeNumber  :   nuint8 ;
            logicalDriveNumber  :   nuint8 ;
            sectorsPerBlock  :   nuint16 ;
            startingBlock  :   nuint16 ;
            totalBlocks  :   nuint16 ;
            availableBlocks  :   nuint16 ;
            totalDirectorySlots  :   nuint16 ;
            availableDirectorySlots  :   nuint16 ;
            maxDirectorySlotsUsed  :   nuint16 ;
            isHashing  :   nuint8 ;
            isCaching  :   nuint8 ;
            isRemovable  :   nuint8 ;
            isMounted  :   nuint8 ;
            volumeName  :  Array[0..15] Of  nstr8 ;
        End;
    Type
        ExtendedVolInfo_tag = Record
            volType  :   nuint32 ;
            statusFlag  :   nuint32 ;
            sectorSize  :   nuint32 ;
            sectorsPerCluster  :   nuint32 ;
            volSizeInClusters  :   nuint32 ;
            freeClusters  :   nuint32 ;
            subAllocFreeableClusters  :   nuint32 ;
            freeableLimboSectors  :   nuint32 ;
            nonfreeableLimboSectors  :   nuint32 ;
            availSubAllocSectors  :   nuint32 ;
            nonuseableSubAllocSectors  :   nuint32 ;
            subAllocClusters  :   nuint32 ;
            numDataStreams  :   nuint32 ;
            numLimboDataStreams  :   nuint32 ;
            oldestDelFileAgeInTicks  :   nuint32 ;
            numCompressedDataStreams  :   nuint32 ;
            numCompressedLimboDataStreams  :   nuint32 ;
            numNoncompressibleDataStreams  :   nuint32 ;
            precompressedSectors  :   nuint32 ;
            compressedSectors  :   nuint32 ;
            numMigratedDataStreams  :   nuint32 ;
            migratedSectors  :   nuint32 ;
            clustersUsedByFAT  :   nuint32 ;
            clustersUsedByDirs  :   nuint32 ;
            clustersUsedByExtDirs  :   nuint32 ;
            totalDirEntries  :   nuint32 ;
            unusedDirEntries  :   nuint32 ;
            totalExtDirExtants  :   nuint32 ;
            unusedExtDirExtants  :   nuint32 ;
            extAttrsDefined  :   nuint32 ;
            extAttrExtantsUsed  :   nuint32 ;
            DirectoryServicesObjectID  :   nuint32 ;
            volLastModifiedDateAndTime  :   nuint32 ;
        End;
        NWVolExtendedInfo = ExtendedVolInfo_tag;
    Function NWGetDiskUtilization (
        conn  :   NWCONN_HANDLE ;
        objID  :   nuint32 ;
        volNum  :   nuint8 ;
        usedDirectories  :   pnuint16 ;
        usedFiles  :   pnuint16 ;
        usedBlocks  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetObjDiskRestrictions (
        conn  :   NWCONN_HANDLE ;
        volNumber  :   nuint8 ;
        objectID  :   nuint32 ;
        restriction  :   pnuint32 ;
        inUse  :   pnuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWScanVolDiskRestrictions (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint8 ;
        iterhandle  :   pnuint32 ;
        Var volInfo  : NWVolumeRestrictions
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWScanVolDiskRestrictions2 (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint8 ;
        iterhandle  :   pnuint32 ;
        Var volInfo  : NWVOL_RESTRICTIONS
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWRemoveObjectDiskRestrictions (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint8 ;
        objID  :   nuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWSetObjectVolSpaceLimit (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint16 ;
        objID  :   nuint32 ;
        restriction  :   nuint32 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetVolumeInfoWithHandle (
        conn  :   NWCONN_HANDLE ;
        dirHandle  :   NWDIR_HANDLE ;
        volName  :   pnstr8 ;
        totalBlocks  :   pnuint16 ;
        sectorsPerBlock  :   pnuint16 ;
        availableBlocks  :   pnuint16 ;
        totalDirEntries  :   pnuint16 ;
        availableDirEntries  :   pnuint16 ;
        volIsRemovableFlag  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetVolumeInfoWithNumber (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint16 ;
        volName  :   pnstr8 ;
        totalBlocks  :   pnuint16 ;
        sectorsPerBlock  :   pnuint16 ;
        availableBlocks  :   pnuint16 ;
        totalDirEntries  :   pnuint16 ;
        availableDirEntries  :   pnuint16 ;
        volIsRemovableFlag  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetVolumeName (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint16 ;
        volName  :   pnstr8 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetVolumeNumber (
        conn  :   NWCONN_HANDLE ;
        volName  :   pnstr8 ;
        volNum  :   pnuint16 
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWGetVolumeStats (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint8 ;
        Var volInfo  : VOL_STATS
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF  N_PLAT_NLM }
        Type NWGetExtendedVolumeInfo = NWGetExtendedVolumeInfo2;
    {$ENDIF}
    Function NWGetExtendedVolumeInfo (
        conn  :   NWCONN_HANDLE ;
        volNum  :   nuint16 ;
        Var volInfo  : NWVolExtendedInfo
    ) : NWCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

