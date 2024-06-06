(******************************************************************************

  %name: nwdspart.h %
  %version: 4 %
  %date_modified: Mon Apr 21 11:44:20 1997 %
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

{$IFNDEF  NWDSPART_H }
    {$DEFINE NWDSPART_H}
    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
    {$IFNDEF  NWDSTYPE_H }
        {$I nwdstype.inc}
    {$ENDIF}
    {$IFNDEF  NWDSBUFT_H }
        {$I nwdsbuft.inc}
    {$ENDIF}
    {$IFNDEF  NWDSDC_H }
        {$I nwdsdc.inc}
    {$ENDIF}
    {$I npackon.inc}
    (*---------------------------------------------------------------------------
 * flags which specify partition info output of
 * DSV_LIST_PARTITIONS
 *)
    {$DEFINE DSP_OUTPUT_FIELDS}
    Const DSP_OUTPUT_FIELDS = $00000001;
    {$DEFINE DSP_PARTITION_ID}
    Const DSP_PARTITION_ID = $00000002;
    {$DEFINE DSP_REPLICA_STATE}
    Const DSP_REPLICA_STATE = $00000004;
    {$DEFINE DSP_MODIFICATION_TIMESTAMP}
    Const DSP_MODIFICATION_TIMESTAMP = $00000008;
    {$DEFINE DSP_PURGE_TIME}
    Const DSP_PURGE_TIME = $00000010;
    {$DEFINE DSP_LOCAL_PARTITION_ID}
    Const DSP_LOCAL_PARTITION_ID = $00000020;
    {$DEFINE DSP_PARTITION_DN}
    Const DSP_PARTITION_DN = $00000040;
    {$DEFINE DSP_REPLICA_TYPE}
    Const DSP_REPLICA_TYPE = $00000080;
    {$DEFINE DSP_PARTITION_BUSY}
    Const DSP_PARTITION_BUSY = $00000100;
    {$IFDEF __cplusplus}
    (* TC extern C *)
    {$ENDIF}
    Function NWDSAddPartition (
        context  :   NWDSContextHandle ;
        server  :   pnstr8 ;
        partitionRoot  :   pnstr8 ;
        iterationHandle  :   pnint32 ;
        more  :   nbool8 ;
        objectInfo  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSAddReplica (
        context  :   NWDSContextHandle ;
        server  :   pnstr8 ;
        partitionRoot  :   pnstr8 ;
        replicaType  :   nuint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSChangeReplicaType (
        context  :   NWDSContextHandle ;
        replicaName  :   pnstr8 ;
        server  :   pnstr8 ;
        newReplicaType  :   nuint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSJoinPartitions (
        context  :   NWDSContextHandle ;
        subordinatePartition  :   pnstr8 ;
        flags  :   nflag32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSListPartitions (
        context  :   NWDSContextHandle ;
        iterationHandle  :   pnint32 ;
        server  :   pnstr8 ;
        partitions  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSListPartitionsExtInfo (
        context  :   NWDSContextHandle ;
        iterationHandle  :   pnint32 ;
        server  :   pnstr8 ;
        DSPFlags  :   nflag32 ;
        partitions  :   pBuf_T 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSRemovePartition (
        context  :   NWDSContextHandle ;
        partitionRoot  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSRemoveReplica (
        context  :   NWDSContextHandle ;
        server  :   pnstr8 ;
        partitionRoot  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSSplitPartition (
        context  :   NWDSContextHandle ;
        subordinatePartition  :   pnstr8 ;
        flags  :   nflag32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSPartitionReceiveAllUpdates (
        context  :   NWDSContextHandle ;
        partitionRoot  :   pnstr8 ;
        serverName  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSPartitionSendAllUpdates (
        context  :   NWDSContextHandle ;
        partitionRoot  :   pnstr8 ;
        serverName  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSSyncPartition (
        context  :   NWDSContextHandle ;
        server  :   pnstr8 ;
        partition  :   pnstr8 ;
        seconds  :   nuint32 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDSAbortPartitionOperation (
        context  :   NWDSContextHandle ;
        partitionRoot  :   pnstr8 
    ) : NWDSCCODE;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF __cplusplus}
    (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}

