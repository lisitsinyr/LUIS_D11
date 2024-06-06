(*
//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
//บ (c) 1995-1997 Novell, Inc.  All rights reserved.                         บ
//บ                                                                          บ
//บ THIS WORK IS SUBJECT TO U.S. AND INTERNATIONAL COPYRIGHT LAWS AND        บ
//บ TREATIES.                                                                บ
//บ                                                                          บ
//บ NO PART OF THIS WORK MAY BE USED, PRACTICED, PERFORMED, COPIED,          บ
//บ DISTRIBUTED, REVISED, MODIFIED, TRANSLATED, ABRIDGED, CONDENSED,         บ
//บ EXPANDED, COLLECTED, COMPILED, LINKED, RECAST, TRANSFORMED OR ADAPTED    บ
//บ WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC.                        บ
//บ                                                                          บ
//บ ANY USE OR EXPLOITATION OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT บ
//บ THE PERPETRATOR TO CRIMINAL AND CIVIL LIABILITY.                         บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Source module name: NWDP_PRT.H                                           บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Library VeRsIoN=1.0.0                                                    บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

(* Inclusion Control *)

{$IFNDEF  NWDP_PRT_H }
    {$DEFINE NWDP_PRT_H}
    (* Standard Library Header Includes *)
    {$IFNDEF  NWDP_LIB_H }
        {$I nwdp_lib.inc}
    {$ENDIF}
    {$IFNDEF  NWDP_NSR_H }
        {$I nwdp_nsr.inc}
    {$ENDIF}
    {$IFNDEF  NWDP_OID_H }
        {$I nwdp_oid.inc}
    {$ENDIF}
    {$IFNDEF  NWDP_PSM_H }
        {$I nwdp_psm.inc}
    {$ENDIF}
    {$IFNDEF  NWDP_RES_H }
        {$I nwdp_res.inc}
    {$ENDIF}
    (* Header Includes *)
    (* Manifest Constant Definitions *)
    (*
   // length definition sizes
   *)
    {$IFNDEF  NWDP_PRT_MAX_NAME_CHARS }
        {$DEFINE NWDP_PRT_MAX_NAME_CHARS}
        Const NWDP_PRT_MAX_NAME_CHARS = 63;
        (* TC #define NWDP_PRT_MAX_NAME_BYTES ( ( NWDP_PRT_MAX_NAME_CHARS + 1 ) * 2 )  *)
        {$DEFINE NWDP_PRT_MAX_CONFIG_NAME_CHARS}
        Const NWDP_PRT_MAX_CONFIG_NAME_CHARS = 31;
        (* TC #define NWDP_PRT_MAX_CONFIG_NAME_BYTES ( ( NWDP_PRT_MAX_CONFIG_NAME_CHARS + 1 ) * 2 )  *)
        {$DEFINE NWDP_PRT_MAX_LABEL_CHARS}
        Const NWDP_PRT_MAX_LABEL_CHARS = 31;
        (* TC #define NWDP_PRT_MAX_LABEL_BYTES ( ( NWDP_PRT_MAX_LABEL_CHARS + 1 ) * 2 )  *)
        {$DEFINE NWDP_PRT_MAX_PORT_CHARS}
        Const NWDP_PRT_MAX_PORT_CHARS = 8;
        (* TC #define NWDP_PRT_MAX_PORT_BYTES ( ( NWDP_PRT_MAX_PORT_CHARS + 1 ) * 2 )  *)
        {$DEFINE NWDP_PRT_MAX_DRIVER_CHARS}
        Const NWDP_PRT_MAX_DRIVER_CHARS = 31;
        (* TC #define NWDP_PRT_MAX_DRIVER_BYTES ( ( NWDP_PRT_MAX_DRIVER_CHARS + 1 ) * 2 )  *)
        {$DEFINE NWDP_PRT_MAX_DESCRIPTION_CHARS}
        Const NWDP_PRT_MAX_DESCRIPTION_CHARS = 127;
        (* TC #define NWDP_PRT_MAX_DESCRIPTION_BYTES ( ( NWDP_PRT_MAX_DESCRIPTION_CHARS + 1 ) * 2 )  *)
        {$DEFINE NWDP_PRT_MAX_LOCATION_CHARS}
        Const NWDP_PRT_MAX_LOCATION_CHARS = 127;
        (* TC #define NWDP_PRT_MAX_LOCATION_BYTES ( ( NWDP_PRT_MAX_LOCATION_CHARS + 1 ) * 2 )  *)
    {$ENDIF}
    {$IFDEF  N_PLAT_MSW }
        {$IFNDEF  NWDP_PRT_INSTALLED_LIST_CHG_MSG }
            {$DEFINE NWDP_PRT_INSTALLED_LIST_CHG_MSG}
            Const NWDP_PRT_INSTALLED_LIST_CHG_MSG = 'NDPS Installed Printer List Changed';
        {$ENDIF}
    {$ENDIF}
    (*
   // flag bits for NWDPPrtAddInstalledPrinter
   *)
    {$DEFINE NWDP_PRT_FLG_NO_REF}
    Const NWDP_PRT_FLG_NO_REF = $00000001;
    {$DEFINE NWDP_PRT_FLG_CONVERT_REF}
    Const NWDP_PRT_FLG_CONVERT_REF = $00000002;
    (* TC #define NWDP_PRT_REF_TYPE_ANY ( NWDP_PRT_REF_TYPE_INSTALLED | NWDP_PRT_REF_TYPE_NAMED | NWDP_PRT_REF_TYPE_CONVENIENCE )  *)
    (* Macro Definitions *)
    (* Type Definitions *)
    {$DEFINE N_PACK_1}
    {$I npackon.inc}
    {$IFNDEF  _NWDP_PRT_REF_TYPE }
        {$DEFINE _NWDP_PRT_REF_TYPE}
        Const
        NWDP_PRT_REF_TYPE_INSTALLED = 1;
        NWDP_PRT_REF_TYPE_NAMED = 2;
        NWDP_PRT_REF_TYPE_CONVENIENCE = 4;
        Type NWDPPrtRefTypeEnum = 0..4;
        pNWDPPrtRefTypeEnum = ^NWDPPrtRefTypeEnum;
    {$ENDIF}
    Const
    NWDP_PRT_CFG_FILE_TYPE_PDS = 0;
    NWDP_PRT_CFG_FILE_TYPE_PH = 1;
    Type NWDPPrtConfigFileTypeEnum = 0..1;
    pNWDPPrtConfigFileTypeEnum = ^NWDPPrtConfigFileTypeEnum;
    (*
   // local printers callback item structure
   *)
    Type
        NWDPPrtInstalledListItem = Record
            defaultPrinter  :   nbool ;
            name16  :  Array[0..NWDP_PRT_MAX_NAME_CHARS+1-1] Of  nchar16 ;
            driver16  :  Array[0..NWDP_PRT_MAX_DRIVER_CHARS+1-1] Of  nchar16 ;
            label16  :  Array[0..NWDP_PRT_MAX_LABEL_CHARS+1-1] Of  nchar16 ;
            port16  :  Array[0..NWDP_PRT_MAX_PORT_CHARS+1-1] Of  nchar16 ;
        End;
        pNWDPPrtInstalledListItem = ^NWDPPrtInstalledListItem;
    (*
   // global printers callback item structure
   *)
    Type
        NWDPPrtGlobalListItem = Record
            printerName16  :  Array[0..NWDP_PRT_MAX_NAME_CHARS+1-1] Of  nchar16 ;
            description16  :  Array[0..NWDP_PRT_MAX_DESCRIPTION_CHARS+1-1] Of  nchar16 ;
            location16  :  Array[0..NWDP_PRT_MAX_LOCATION_CHARS+1-1] Of  nchar16 ;
            printerType  :   NWDPPrtRefTypeEnum ;
            convenience : Record  (* union statement *)
                address  :   NWDPNetAddress ;
            End;
        End;
        pNWDPPrtGlobalListItem = ^NWDPPrtGlobalListItem;
    (*
   // Printer Job-list callback item
   *)
    Type
        NWDPPrtJobListItem = Record
            jobId  :   nuint32 ;
            jobPosition  :   nuint32 ;
            jobName16Ptr  :   pnstr16 ;
            jobOwner16Ptr  :   pnstr16 ;
            jobSize  :   nuint32 ;
            numDocs  :   nuint ;
            jobPriority  :   nuint ;
            submitTime  :   nuint32 ;
            jobStateOidPtr  :   pNWDPOid ;
        End;
        pNWDPPrtJobListItem = ^NWDPPrtJobListItem;
    Const
    NWDP_PRT_SCHEDULED_JOBS = 0;
    NWDP_PRT_RETAINED_JOBS = 1;
    Type NWDPPrtJobTypeEnum = 0..1;
    pNWDPPrtJobTypeEnum = ^NWDPPrtJobTypeEnum;
    Const
    NWDP_PRT_DRV_OVERWRITE_ALL = 1;
    NWDP_PRT_DRV_OVERWRITE_IF_NEWER = 2;
    NWDP_PRT_DRV_OVERWRITE_DONT = 3;
    NWDP_PRT_DRV_INTERVENE_EACH_CPY = 4;
    NWDP_PRT_DRV_INTERVENE_OVRWRITE = 5;
    NWDP_PRT_DRV_INTERVENE_OVRW_NEW = 6;
    Type NWDPPrtDrvDownloadOptionEnum = 0..6;
    pNWDPPrtDrvDownloadOptionEnum = ^NWDPPrtDrvDownloadOptionEnum;
    (*
   // These actions affect only the disposition of the current file
   // for which there is intervention.
   *)
    Const
    NWDP_PRT_DRV_RETAIN_ORIGINAL = 0;
    NWDP_PRT_DRV_COPY_FILE = 1;
    Type NWDPPrtDrvDownloadActionEnum = 0..1;
    pNWDPPrtDrvDownloadActionEnum = ^NWDPPrtDrvDownloadActionEnum;
    {$I npackoff.inc}
    (* Callback Definitions *)
    Type NWDPPrtDownloadInterventionCB = Function (
        accessorRef  :   NWDPAccessorRef ;
        callerDefinedParam  :   nparam ;
        totalCallsToBeMade  :   nint ;
        currentCallCount  :   nint ;
        filenameToBeCopiedPtr  :   pnstr ;
        toBeCopiedFileDate  :   nint32 ;
        originalFileDate  :   nint32 ;
        currentDownloadOptionPtr  :   pNWDPPrtDrvDownloadOptionEnum ;
        actionToBeTakenPtr  :   pNWDPPrtDrvDownloadActionEnum 
    ) : nint;
    Type NWDPPrtGlobalListCallback = Function (
        accessorRef  :   NWDPAccessorRef ;
        callerDefinedParam  :   nparam ;
        totalCallsToBeMade  :   nint ;
        currentCallCount  :   nint ;
        itemReceivedPtr  :   pNWDPPrtGlobalListItem 
    ) : nint;
    Type NWDPPrtInstalledListCallback = Function (
        accessorRef  :   NWDPAccessorRef ;
        callerDefinedParam  :   nparam ;
        totalCallsToBeMade  :   nint ;
        currentCallCount  :   nint ;
        itemReceivedPtr  :   pNWDPPrtInstalledListItem 
    ) : nint;
    (*
   // Job Configuration callback item is an ASCII string
   *)
    Type NWDPPrtJobConfigListCallback = Function (
        accessorRef  :   NWDPAccessorRef ;
        callerDefinedParam  :   nparam ;
        totalCallsToBeMade  :   nint ;
        currentCallCount  :   nint ;
        itemReceived16Ptr  :   pnstr16 
    ) : nint;
    Type NWDPPrtJobListCallback = Function (
        accessorRef  :   NWDPAccessorRef ;
        callerDefinedParam  :   nparam ;
        totalCallsToBeMade  :   nint ;
        currentCallCount  :   nint ;
        itemReceivedPtr  :   pNWDPPrtJobListItem 
    ) : nint;
    (* Global Variable Declarations *)
    (* Function Prototype Declarations *)
    Function NWDPPrtAddInstalledPrinter (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        jobConfigName16Ptr  :   pnstr16 ;
        label16Ptr  :   pnstr16 ;
        localPrinterRefPtr  :   pNWDPPrtRef ;
        flags  :   nuint32 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtAddInstalledPrtWConfig (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        jobConfigRef  :   NWDPAttrSetRef ;
        docConfigRef  :   NWDPAttrSetRef ;
        label16Ptr  :   pnstr16 ;
        localPrinterRefPtr  :   pNWDPPrtRef ;
        flags  :   nuint32 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtAddJobConfig (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        jobConfigName16Ptr  :   pnstr16 ;
        jobConfigRef  :   NWDPAttrSetRef ;
        docConfigRef  :   NWDPAttrSetRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtAddPrinterObjToPA (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        printerFqnPtr  :   pNWDPNSrvFQN 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtChangeMedia (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        trayNumber  :   nuint32 ;
        mediumValuePtr  :   pNWDPNameOrOid 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtControl (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        actionOidPtr  :   pNWDPOid 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtCreateMODObject (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        objectClassPtr  :   pNWDPOid ;
        objectIdentPtr  :   pNWDPObjectIdentification ;
        force  :   nbool ;
        referenceObjectPtr  :   pNWDPObjectIdentification ;
        objectAttrSetRef  :   NWDPAttrSetRef ;
        resultAttrSetRefPtr  :   pNWDPAttrSetRef ;
        resultAvpRefPtr  :   pNWDPASAVPRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtCreateRefBasedOnAddr (
        accessorRef  :   NWDPAccessorRef ;
        netAddrPtr  :   pNWDPNetAddress ;
        paName16Ptr  :   pnstr16 ;
        printerRefPtr  :   pNWDPPrtRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtCreateRefBasedOnFQN (
        accessorRef  :   NWDPAccessorRef ;
        printerFqnPtr  :   pNWDPNSrvFQN ;
        printerRefPtr  :   pNWDPPrtRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtCreateRefBasedOnLabel (
        accessorRef  :   NWDPAccessorRef ;
        label16Ptr  :   pnstr16 ;
        printerRefPtr  :   pNWDPPrtRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtCreateRefBasedOnPort (
        accessorRef  :   NWDPAccessorRef ;
        port16Ptr  :   pnstr16 ;
        printerRefPtr  :   pNWDPPrtRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtCreateRefBasedOnPSM (
        accessorRef  :   NWDPAccessorRef ;
        psmRef  :   NWDPPsmRef ;
        paName16Ptr  :   pnstr16 ;
        printerRefPtr  :   pNWDPPrtRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtDeleteAllJobs (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        reservedPtr  :   pNWDPNameOrOid 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtDeleteMODObject (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        objectClassPtr  :   pNWDPOid ;
        objectIdentPtr  :   pNWDPObjectIdentification 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtDriverDownload (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        optionalResourceRef  :   NWDPResRef ;
        optionalDriverIdPtr  :   pNWDPResListDrvFiles ;
        downloadOption  :   NWDPPrtDrvDownloadOptionEnum ;
        sourcePathOptionPtr  :   pnstr ;
        callback  :   NWDPPrtDownloadInterventionCB ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtGetAttributeSet (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        requestedOidSetRef  :   NWDPOidSetRef ;
        resultAttrSetRefPtr  :   pNWDPAttrSetRef ;
        avpRefPtr  :   pNWDPASAVPRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtGetDefaultPrinter (
        accessorRef  :   NWDPAccessorRef ;
        printerRefPtr  :   pNWDPPrtRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtGetDriverKeyName (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        sizeOfBuffer  :   nuint ;
        driverKeyNameBuffer16Ptr  :   pnstr16 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtGetDriverName (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        sizeOfBuffer  :   nuint ;
        driverNameBuffer16Ptr  :   pnstr16 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtGetFQN (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        sizeOfBuffer  :   nuint ;
        fqnBufferPtr  :   pNWDPNSrvFQNBuffer ;
        sizeOfResultPtr  :   pnuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtGetJobConfig (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        sizeOfJobConfigNameBuffer  :   nuint ;
        jobConfigName16Ptr  :   pnstr16 ;
        sizeOfResultNamePtr  :   pnuint ;
        jobConfigRefPtr  :   pNWDPAttrSetRef ;
        jobAvpRefPtr  :   pNWDPASAVPRef ;
        docConfigRefPtr  :   pNWDPAttrSetRef ;
        docAvpRefPtr  :   pNWDPASAVPRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtGetLabel (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        sizeOfBuffer  :   nuint ;
        label16Ptr  :   pnstr16 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtGetMODObjectAttrSet (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        objectClassPtr  :   pNWDPOid ;
        objectIdentPtr  :   pNWDPObjectIdentification ;
        requestedOidSetRef  :   NWDPOidSetRef ;
        resultAttrSetRefPtr  :   pNWDPAttrSetRef ;
        resultAvpRefPtr  :   pNWDPASAVPRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtGetPort (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        sizeOfBuffer  :   nuint ;
        portBuffer16Ptr  :   pnstr16 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtGetPrinterInfo (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        infoItemPtr  :   pNWDPPrtGlobalListItem 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtGetRefType (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        refTypeFlagsPtr  :   pnuint32 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtGetStatus (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        resultAttrSetRefPtr  :   pNWDPAttrSetRef ;
        avpRefPtr  :   pNWDPASAVPRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtJobCopy (
        accessorRef  :   NWDPAccessorRef ;
        destPrinterRef  :   NWDPPrtRef ;
        srcPrinterRef  :   NWDPPrtRef ;
        jobId  :   nuint32 ;
        destJobRefPtr  :   pNWDPJobRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtJobMove (
        accessorRef  :   NWDPAccessorRef ;
        destPrinterRef  :   NWDPPrtRef ;
        srcPrinterRef  :   NWDPPrtRef ;
        jobId  :   nuint32 ;
        destJobRefPtr  :   pNWDPJobRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtListGlobalPrinters (
        accessorRef  :   NWDPAccessorRef ;
        filterRef  :   NWDPFilterRef ;
        printerTypeFilter  :   NWDPPrtRefTypeEnum ;
        listCallback  :   NWDPPrtGlobalListCallback ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtListInstalledPrinters (
        accessorRef  :   NWDPAccessorRef ;
        listCallback  :   NWDPPrtInstalledListCallback ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtListJobConfigs (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        listCallback  :   NWDPPrtJobConfigListCallback ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtListJobs (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        jobType  :   NWDPPrtJobTypeEnum ;
        filterRef  :   NWDPFilterRef ;
        listCallback  :   NWDPPrtJobListCallback ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtListMODObjects (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        objectClassPtr  :   pNWDPOid ;
        selectorPtr  :   pNWDPASSelector ;
        requestedOidSetRef  :   NWDPOidSetRef ;
        listCallback  :   NWDPASMODObjectListCallback ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtModifyAttrs (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        modifyRef  :   NWDPAttrSetRef ;
        prtOperator  :   NWDPModifyOperatorEnum 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtModifyMODObjectAttrs (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        objectClassPtr  :   pNWDPOid ;
        objectIdentPtr  :   pNWDPObjectIdentification ;
        modifyRef  :   NWDPAttrSetRef ;
        modifyOperator  :   NWDPModifyOperatorEnum 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtReleaseRef (
        accessorRef  :   NWDPAccessorRef ;
        printerRefPtr  :   pNWDPPrtRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtRemoveInstalledPrinter (
        accessorRef  :   NWDPAccessorRef ;
        printerRefPtr  :   pNWDPPrtRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtRemoveJobConfig (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        jobConfigName16Ptr  :   pnstr16 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtRemovePrinterObjFromPA (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        printerFqnPtr  :   pNWDPNSrvFQN 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtRenameJobConfig (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        oldJobConfigName16Ptr  :   pnstr16 ;
        newJobConfigName16Ptr  :   pnstr16 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtResyncWithNameService (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtSetDefaultPrinter (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtSetLabel (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        label16Ptr  :   pnstr16 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtShutdownPA (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        reservedPtr  :   pNWDPNameOrOid ;
        shutdownType  :   NWDPShutdownType 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtStartupPA (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        reservedPtr  :   pNWDPNameOrOid 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtSyncInstalledPrinters (
        accessorRef  :   NWDPAccessorRef ;
        osRegistryTakesPrecedence  :   nbool 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtUseRef (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPPrtValidateRef (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        refType  :   NWDPPrtRefTypeEnum 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
{$ELSE}
    {$IFDEF  N_DEBUG }
        (* TC error *)
    {$ENDIF}
{$ENDIF}

