(*
//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
//บ (c) 1997 Novell, Inc.  All rights reserved.                              บ
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
//บ Source module name: NWDP_NTP.H                                           บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Library VeRsIoN=1.0.0                                                    บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

(* Inclusion Control *)

{$IFNDEF  NWDP_NTP_H }
    {$DEFINE NWDP_NTP_H}
    (* Standard Library Header Includes *)
    {$IFNDEF  NTYPES_H }
        {$DEFINE N_INC_NO_OLD_CONSTANTS}
        {$DEFINE N_INC_NO_OLD_MACROS}
        {$I ntypes.inc}
        {$UNDEF N_INC_NO_OLD_MACROS}
        {$UNDEF N_INC_NO_OLD_CONSTANTS}
    {$ENDIF}
    {$IFNDEF  NWDP_ATT_H }
        {$I nwdp_att.inc}
    {$ENDIF}
    (* Header Includes *)
    (* Manifest Constant Definitions *)
    (* Macro Definitions *)
    (* Type Definitions *)
    Const
    NWDP_PGRM_DLVR_BIND_SUCCESS = 0;
    NWDP_PGRM_DLVR_BIND_ERROR = 1;
    Type NWDPPrgmDlvrBindResultEnum = 0..1;
    pNWDPPrgmDlvrBindResultEnum = ^NWDPPrgmDlvrBindResultEnum;
    Type
        NWDPPrgmDlvrBindArgument = Record
            credentials  :   NWDPCredentials ;
        End;
        pNWDPPrgmDlvrBindArgument = ^NWDPPrgmDlvrBindArgument;
    Type
        NWDPPrgmDlvrBindResult = Record
            rCode  :   NWDPPrgmDlvrBindResultEnum ;
        End;
        pNWDPPrgmDlvrBindResult = ^NWDPPrgmDlvrBindResult;
    Type
        NWDPPrgmDlvrUnbindArgument = Record
            noopArg  :   nuint8 ;
        End;
        pNWDPPrgmDlvrUnbindArgument = ^NWDPPrgmDlvrUnbindArgument;
    Type
        NWDPPrgmDlvrUnbindResult = Record
            noopArg  :   nuint8 ;
        End;
        pNWDPPrgmDlvrUnbindResult = ^NWDPPrgmDlvrUnbindResult;
    Const
    NWDP_PGRM_DLVR_SEND_SUCCESS = 0;
    NWDP_PGRM_DLVR_SEND_ERROR = 1;
    Type NWDPPrgmDlvrSendResultEnum = 0..1;
    pNWDPPrgmDlvrSendResultEnum = ^NWDPPrgmDlvrSendResultEnum;
    Type
        NWDPPrgmDlvrSendItem = Record
            listenerHandle  :   nuint32 ;
            supplierId  :   NWDPOctetString ;
            eventType  :   nuint32 ;
            containingClassOid  :   NWDPObjectIdentifier ;
            containingObjectId  :   NWDPObjectIdentification ;
            filterClassOid  :   NWDPObjectIdentifier ;
            objectClassOid  :   NWDPObjectIdentifier ;
            objectId  :   NWDPObjectIdentification ;
            eventOid  :   NWDPObjectIdentifier ;
            eventAttr  :   NWDPAttribute ;
            message  :   NWDPText ;
            time  :   nuint32 ;
            accountOption  :   NWDPQualifiedName ;
        End;
        pNWDPPrgmDlvrSendItem = ^NWDPPrgmDlvrSendItem;
    Type
        NWDPPrgmDlvrSendArgument = Record
            itemCount  :   nuint ;
            itemPtr  :   pNWDPPrgmDlvrSendItem ;
        End;
        pNWDPPrgmDlvrSendArgument = ^NWDPPrgmDlvrSendArgument;
    Type
        NWDPPrgmDlvrSendResult = Record
            rCode  :   NWDPPrgmDlvrSendResultEnum ;
            failedItems : Record
                itemCount  :   nuint ;
                itemPtr  :   pnuint32 ;
            End;
        End;
        pNWDPPrgmDlvrSendResult = ^NWDPPrgmDlvrSendResult;
    (* Structure Definitions *)
    (* Global Variable Declarations *)
    (* Function Prototype Declarations *)
{$ELSE}
    {$IFDEF  N_DEBUG }
        (* TC error *)
    {$ENDIF}
{$ENDIF}


