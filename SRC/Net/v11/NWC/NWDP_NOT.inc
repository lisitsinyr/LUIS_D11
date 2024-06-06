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
//บ Source module name: NWDP_NOT.H                                           บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Library VeRsIoN=1.0.0                                                    บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

(* Inclusion Control *)

{$IFNDEF  NWDP_NOT_H }
    {$DEFINE NWDP_NOT_H}
    (* Standard Library Header Includes *)
    (* Header Includes *)
    {$IFNDEF  NWDP_LIB_H }
        {$I nwdp_lib.inc}
    {$ENDIF}
    {$IFNDEF  NWDP_ATR_H }
        {$I nwdp_atr.inc}
    {$ENDIF}
    {$IFNDEF  NWDP_NTT_H }
        {$I nwdp_ntt.inc}
    {$ENDIF}
    (* Manifest Constant Definitions *)
    (* Macro Definitions *)
    (* Type Definitions *)
    {$DEFINE N_PACK_1}
    {$I npackon.inc}
    Type
        NWDPNtfyProfileInfo = Record
            persistence  :   NWDPPersistenceEnum ;
            consumerName  :   NWDPQualifiedName ;
            languageId  :   NWDPLanguageId ;
            methodId  :   NWDPNameOrOid ;
            deliveryAddress  :   NWDPNotifyDeliveryAddr ;
            supplierIdOption  :   NWDPOctetString ;
            accountOption  :   NWDPQualifiedName ;
        End;
        pNWDPNtfyProfileInfo = ^NWDPNtfyProfileInfo;
    Type
        NWDPNtfyEventObjectListItem = Record
            eventType  :   nuint32 ;
            containingClassOidPtr  :   pNWDPOid ;
            containingObjectIdPtr  :   pNWDPObjectIdentification ;
            designator  :   NWDPEventObjectTypeEnum ;
            filterClassOidPtr  :   pNWDPOid ;  (* union statement *)
        End;
        pNWDPNtfyEventObjectListItem = ^NWDPNtfyEventObjectListItem;
    Type
        NWDPNtfyGetSupportedListItem = Record
            eventObjectIdPtr  :   pNWDPEventObjectId ;
            eventAttrSetRef  :   NWDPAttrSetRef ;
            eventAvpRef  :   NWDPASAVPRef ;
        End;
        pNWDPNtfyGetSupportedListItem = ^NWDPNtfyGetSupportedListItem;
    {$I npackoff.inc}
    (* Callback Definitions *)
    Type NWDPNtfyEventObjectListCallback = Function (
        accessorRef  :   NWDPAccessorRef ;
        callerDefinedParam  :   nparam ;
        totalCallsToBeMade  :   nint ;
        currentCallCount  :   nint ;
        itemReceivedPtr  :   pNWDPNtfyEventObjectListItem 
    ) : nint;
    Type NWDPNtfyGetSupportedLstCallback = Function (
        accessorRef  :   NWDPAccessorRef ;
        callerDefinedParam  :   nparam ;
        totalCallsToBeMade  :   nint ;
        currentCallCount  :   nint ;
        getSupportedListItemPtr  :   pNWDPNtfyGetSupportedListItem 
    ) : nint;
    Type NWDPNtfyMethodListCallback = Function (
        accessorRef  :   NWDPAccessorRef ;
        callerDefinedParam  :   nparam ;
        totalCallsToBeMade  :   nint ;
        currentCallCount  :   nint ;
        itemReceivedPtr  :   pNWDPNtfyDeliveryMethod 
    ) : nint;
    Type NWDPNtfyProfileListCallback = Function (
        accessorRef  :   NWDPAccessorRef ;
        callerDefinedParam  :   nparam ;
        totalCallsToBeMade  :   nint ;
        currentCallCount  :   nint ;
        profileRef  :   NWDPNtfyProfileRef 
    ) : nint;
    Type NWDPNtfyProgrammaticCallback = Function (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        profileId  :   nint32 ;
        eventReportPtr  :   pNWDPEventReport 
    ) : nint;
    Type NWDPNtfyPromptListCallback = Function (
        accessorRef  :   NWDPAccessorRef ;
        callerDefinedParam  :   nparam ;
        totalCallsToBeMade  :   nint ;
        currentCallCount  :   nint ;
        promptListItemPtr  :   pNWDPNtfyPromptListItem 
    ) : nint;
    (* Global Variable Declarations *)
    (* Function Prototype Declarations *)
    (********************************************
   *
   *  Notification service-related prototypes
   *
   *********************************************)
    Function NWDPNtfyCreateRefBasedOnFQN (
        accessorRef  :   NWDPAccessorRef ;
        brokerFqnPtr  :   pNWDPNSrvFQN ;
        notifyRefPtr  :   pNWDPNtfyRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNtfyDestroyRef (
        accessorRef  :   NWDPAccessorRef ;
        notifyRefPtr  :   pNWDPNtfyRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNtfyValidateRef (
        accessorRef  :   NWDPAccessorRef ;
        notifyRef  :   NWDPNtfyRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (********************************************
   *
   *  Delivery method-related prototypes
   *
   *********************************************)
    Function NWDPNtfyCreateMethodInfoRef (
        accessorRef  :   NWDPAccessorRef ;
        notifyRef  :   NWDPNtfyRef ;
        methodIdPtr  :   pNWDPNameOrOid ;
        languageId  :   NWDPLanguageId ;
        methodInfoRefPtr  :   pNWDPNtfyMethodInfoRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNtfyDestroyMethodInfoRef (
        accessorRef  :   NWDPAccessorRef ;
        methodInfoRefPtr  :   pNWDPNtfyMethodInfoRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNtfyValidateMethodInfoRef (
        accessorRef  :   NWDPAccessorRef ;
        methodInfoRef  :   NWDPNtfyMethodInfoRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNtfyAddMethod (
        accessorRef  :   NWDPAccessorRef ;
        notifyRef  :   NWDPNtfyRef ;
        fileName16Ptr  :   pnstr16 ;
        methodIdPtr  :   pNWDPNameOrOid 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNtfyRemoveMethod (
        accessorRef  :   NWDPAccessorRef ;
        notifyRef  :   NWDPNtfyRef ;
        methodIdPtr  :   pNWDPNameOrOid 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNtfyListMethods (
        accessorRef  :   NWDPAccessorRef ;
        notifyRef  :   NWDPNtfyRef ;
        languageId  :   NWDPLanguageId ;
        listCallback  :   NWDPNtfyMethodListCallback ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNtfyGetDeliveryMethodInfo (
        accessorRef  :   NWDPAccessorRef ;
        methodInfoRef  :   NWDPNtfyMethodInfoRef ;
        Var deliveryMethodPtr  : pNWDPNtfyDeliveryMethod
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNtfyListPrompts (
        accessorRef  :   NWDPAccessorRef ;
        methodInfoRef  :   NWDPNtfyMethodInfoRef ;
        listCallback  :   NWDPNtfyPromptListCallback ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (********************************************
   *
   *  Profile - Event object-related prototypes
   *
   *********************************************)
    (*
// Get Supported Events
*)
    Function NWDPNtfyGetSupportedEvents (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        listCallback  :   NWDPNtfyGetSupportedLstCallback ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (*
// Create Profile Ref's
*)
    Function NWDPNtfyCreateProfileRef (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        profileInfoPtr  :   pNWDPNtfyProfileInfo ;
        profileRefPtr  :   pNWDPNtfyProfileRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNtfyCreateProfileRefBOP (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        profileId  :   nuint32 ;
        profileRefPtr  :   pNWDPNtfyProfileRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (*
// Use & Release Profile Ref's
*)
    Function NWDPNtfyUseProfileRef (
        accessorRef  :   NWDPAccessorRef ;
        profileRef  :   NWDPNtfyProfileRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNtfyReleaseProfileRef (
        accessorRef  :   NWDPAccessorRef ;
        profileRefPtr  :   pNWDPNtfyProfileRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNtfyValidateProfileRef (
        accessorRef  :   NWDPAccessorRef ;
        profileRef  :   NWDPNtfyProfileRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (*
// Event Object Management
*)
    Function NWDPNtfyAddDetailEventObject (
        accessorRef  :   NWDPAccessorRef ;
        profileRef  :   NWDPNtfyProfileRef ;
        eventType  :   nuint32 ;
        containingClassOidPtr  :   pNWDPOid ;
        containingObjectIdOptionPtr  :   pNWDPObjectIdentification ;
        eventOidSetRef  :   NWDPOidSetRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNtfyAddObjectEventObject (
        accessorRef  :   NWDPAccessorRef ;
        profileRef  :   NWDPNtfyProfileRef ;
        eventType  :   nuint32 ;
        containingClassOidPtr  :   pNWDPOid ;
        containingObjectIdOptionPtr  :   pNWDPObjectIdentification 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNtfyAddFilterEventObject (
        accessorRef  :   NWDPAccessorRef ;
        profileRef  :   NWDPNtfyProfileRef ;
        eventType  :   nuint32 ;
        containingClassOidPtr  :   pNWDPOid ;
        containingObjectIdOptionPtr  :   pNWDPObjectIdentification ;
        filterClassOidPtr  :   pNWDPOid 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNtfyRemoveDetailEventObject (
        accessorRef  :   NWDPAccessorRef ;
        profileRef  :   NWDPNtfyProfileRef ;
        eventType  :   nuint32 ;
        containingClassOidPtr  :   pNWDPOid ;
        containingObjectIdOptionPtr  :   pNWDPObjectIdentification 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNtfyRemoveObjectEventObject (
        accessorRef  :   NWDPAccessorRef ;
        profileRef  :   NWDPNtfyProfileRef ;
        eventType  :   nuint32 ;
        containingClassOidPtr  :   pNWDPOid ;
        containingObjectIdOptionPtr  :   pNWDPObjectIdentification 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNtfyRemoveFilterEventObject (
        accessorRef  :   NWDPAccessorRef ;
        profileRef  :   NWDPNtfyProfileRef ;
        eventType  :   nuint32 ;
        containingClassOidPtr  :   pNWDPOid ;
        containingObjectIdOptionPtr  :   pNWDPObjectIdentification ;
        filterClassOidPtr  :   pNWDPOid 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (*
// Event Management
*)
    Function NWDPNtfyAddEvent (
        accessorRef  :   NWDPAccessorRef ;
        profileRef  :   NWDPNtfyProfileRef ;
        eventType  :   nuint32 ;
        containingClassOidPtr  :   pNWDPOid ;
        containingObjectIdOptionPtr  :   pNWDPObjectIdentification ;
        eventOidPtr  :   pNWDPOid 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNtfyRemoveEvent (
        accessorRef  :   NWDPAccessorRef ;
        profileRef  :   NWDPNtfyProfileRef ;
        eventType  :   nuint32 ;
        containingClassOidPtr  :   pNWDPOid ;
        containingObjectIdOptionPtr  :   pNWDPObjectIdentification ;
        eventOidPtr  :   pNWDPOid 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (*
// Add Profile
*)
    Function NWDPNtfyAddProfile (
        accessorRef  :   NWDPAccessorRef ;
        profileRef  :   NWDPNtfyProfileRef ;
        listCallback  :   NWDPNtfyProgrammaticCallback 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (*
// Remove Profile
*)
    Function NWDPNtfyRemoveProfile (
        accessorRef  :   NWDPAccessorRef ;
        profileRef  :   NWDPNtfyProfileRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (*
// Modify Profile
*)
    Function NWDPNtfyModifyProfile (
        accessorRef  :   NWDPAccessorRef ;
        profileRef  :   NWDPNtfyProfileRef 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (*
// List Profiles
*)
    Function NWDPNtfyListProfiles (
        accessorRef  :   NWDPAccessorRef ;
        printerRef  :   NWDPPrtRef ;
        profileChoicePtr  :   pNWDPListProfilesChoice ;
        listCallback  :   NWDPNtfyProfileListCallback ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (*
// Get ProfileId From ProfileRef
*)
    Function NWDPNtfyGetProfileId (
        accessorRef  :   NWDPAccessorRef ;
        profileRef  :   NWDPNtfyProfileRef ;
        profileIdPtr  :   pnuint32 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNtfyGetProfileInfo (
        accessorRef  :   NWDPAccessorRef ;
        profileRef  :   NWDPNtfyProfileRef ;
        profileInfoPtr  :   pNWDPNtfyProfileInfo 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (*
// Modify profile information calls
*)
    Function NWDPNtfySetMethodId (
        accessorRef  :   NWDPAccessorRef ;
        profileRef  :   NWDPNtfyProfileRef ;
        methodIdPtr  :   pNWDPNameOrOid 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNtfySetDeliveryAddress (
        accessorRef  :   NWDPAccessorRef ;
        profileRef  :   NWDPNtfyProfileRef ;
        deliveryAddressPtr  :   pNWDPNotifyDeliveryAddr 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNtfySetSupplierId (
        accessorRef  :   NWDPAccessorRef ;
        profileRef  :   NWDPNtfyProfileRef ;
        supplierIdPtr  :   pNWDPOctetString 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNtfySetLanguageId (
        accessorRef  :   NWDPAccessorRef ;
        profileRef  :   NWDPNtfyProfileRef ;
        languageId  :   NWDPLanguageId 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWDPNtfyListEventObjects (
        accessorRef  :   NWDPAccessorRef ;
        profileRef  :   NWDPNtfyProfileRef ;
        listCallback  :   NWDPNtfyEventObjectListCallback ;
        callerDefinedParam  :   nparam 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (*
// Use NWDPOidListOids to list the events
*)
{$ELSE}
    {$IFDEF  N_DEBUG }
        (* TC error *)
    {$ENDIF}
{$ENDIF}

