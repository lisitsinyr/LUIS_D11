{=======================================================}
{ Project:                                              }
{         Delphi VCL Extensions (LU)                    }
{         Copyright (c) 2000 Central Bank Of Russia     }
{ Subject:                                              }
{         MAPITAGS                                      }
{ Author:                                               }
{         Lisitsin Y.R.                                 }
{=======================================================}

unit LUMAPITags;

interface

uses LUMAPIDefs;

(*
 *  M A P I T A G S . H
 *
 *  Property tag definitions for standard properties of MAPI
 *  objects.
 *
 *  The following ranges should be used for all property IDs. Note that
 *  property IDs for objects other than messages and recipients should
 *  all fall in the range $3000 to $3FFF:
 *
 *  From    To      Kind of property
 *  --------------------------------
 *  0001    0BFF    MAPI_defined envelope property
 *  0C00    0DFF    MAPI_defined per-recipient property
 *  0E00    0FFF    MAPI_defined non-transmittable property
 *  1000    2FFF    MAPI_defined message content property
 *
 *  3000    3FFF    MAPI_defined property (usually not message or recipient0000;
 *
 *  4000    57FF    Transport-defined envelope property
 *  5800    5FFF    Transport-defined per-recipient property
 *  6000    65FF    User-defined non-transmittable property
 *  6600    67FF    Provider-defined internal non-transmittable property
 *  6800    7BFF    Message class-defined content property
 *  7C00    7FFF    Message class-defined non-transmittable
 *                  property
 *
 *  8000    FFFE    User-defined Name-to-id mapped property
 *
 *  The 3000-3FFF range is further subdivided as follows:
 *
 *  From    To      Kind of property
 *  --------------------------------
 *  3000    33FF    Common property such as display name+ entry ID
 *  3400    35FF    Message store object
 *  3600    36FF    Folder or AB container
 *  3700    38FF    Attachment
 *  3900    39FF    Address book object
 *  3A00    3BFF    Mail user
 *  3C00    3CFF    Distribution list
 *  3D00    3DFF    Profile section
 *  3E00    3FFF    Status object
 *
 *  Copyright 1986-1996 Microsoft Corporation. All Rights Reserved.
 *)


//* Determine if a property is transmittable. */

// FIsTransmittable(ulPropTag) \
//    ((PROP_ID (ulPropTag) <  (ULONG)$0E000000; || \
//    (PROP_ID (ulPropTag)  >= (ULONG)$80000000; || \
//    ((PROP_ID (ulPropTag) >= (ULONG)$10000000; && (PROP_ID (ulPropTag) < (ULONG)$60000000;) || \
//    ((PROP_ID (ulPropTag) >= (ULONG)$68000000; && (PROP_ID (ulPropTag) < (ULONG)$7C000000;})

const
   CdoAddressEntries = 21;
   CdoAddressEntry   = 8;
   CdoAddressFilter  = 9;
   CdoAddressList    = 7;
   CdoAddressLists   = 20;
   CdoAppointment    = 26;
   CdoAttachment     = 5;
   CdoAttachments    = 18;
   CdoField          = 6;
   CdoFields         = 19;
   CdoFolder         = 2;
   CdoFolders        = 15;
   CdoGroupHeader    = 25;
   CdoInfoStore      = 1;
   CdoInfoStores     = 14;
   CdoMeetingItem    = 27;
   CdoMsg            = 3;
   CdoMessageFilter  = 10;
   CdoMessages       = 16;
   CdoRecipient      = 4;
   CdoRecipients     = 17;
   CdoRecurrencePattern = 28;
   CdoSession        = 0;

   CDOAddressGAL     = 0;
   CDOAddressPAB     = 1;

   CDODefaultFolderCalendar      = 0;
   CDODefaultFolderInbox         = 1;
   CDODefaultFolderOutbox        = 2;
   CDODefaultFolderSentItems     = 3;
   CDODefaultFolderDeletedItems  = 4;
   CDODefaultFolderContacts      = 5;
   CDODefaultFolderJournal       = 6;
   CDODefaultFolderNotes         = 7;
   CDODefaultFolderTasks         = 8;

   vbString = 8;
   vbInteger = 2;
   vbBoolean = 11;
   vbDate = 7;
   vbLong = 3;

   { Sensitivity }
   cdoNoSensitivity = 0;
   cdoPersonal = 1;
   cdoPrivate = 2;
   cdoConfidential = 3;

   { Impotance }

   cdoLow = 0;
   cdoNormal = 1;
   cdoHigh = 2;

(* IAttach attachment methods: PR_ATTACH_METHOD values *)

   NO_ATTACHMENT           = $00000000;
   ATTACH_BY_VALUE         = $00000001;
   ATTACH_BY_REFERENCE     = $00000002;
   ATTACH_BY_REF_RESOLVE   = $00000003;
   ATTACH_BY_REF_ONLY      = $00000004;
   ATTACH_EMBEDDED_MSG     = $00000005;
   ATTACH_OLE              = $00000006;

(* Object type *)

   MAPI_STORE      = $00000001;    (* Message Store *)
   MAPI_ADDRBOOK   = $00000002;    (* Address Book *)
   MAPI_FOLDER     = $00000003;    (* Folder *)
   MAPI_ABCONT     = $00000004;    (* Address Book Container *)
   MAPI_MESSAGE    = $00000005;    (* Message *)
   MAPI_MAILUSER   = $00000006;    (* Individual Recipient *)
   MAPI_ATTACH     = $00000007;    (* Attachment *)
   MAPI_DISTLIST   = $00000008;    (* Distribution List Recipient *)
   MAPI_PROFSECT   = $00000009;    (* Profile Section *)
   MAPI_STATUS     = $0000000A;    (* Status Object *)
   MAPI_SESSION    = $0000000B;    (* Session *)
   MAPI_FORMINFO   = $0000000C;    (* Form Information *)

//
//  Message envelope properties
//

 PR_ACKNOWLEDGEMENT_MODE                     = PT_LONG+      $00010000;
 PR_ALTERNATE_RECIPIENT_ALLOWED              = PT_BOOLEAN+   $00020000;
 PR_AUTHORIZING_USERS                        = PT_BINARY+    $00030000;
 PR_AUTO_FORWARD_COMMENT                     = PT_TSTRING+   $00040000;
 PR_AUTO_FORWARD_COMMENT_W                   = PT_UNICODE+   $00040000;
 PR_AUTO_FORWARD_COMMENT_A                   = PT_STRING8+   $00040000;
 PR_AUTO_FORWARDED                           = PT_BOOLEAN+   $00050000;
 PR_CONTENT_CONFIDENTIALITY_ALGORITHM_ID     = PT_BINARY+    $00060000;
 PR_CONTENT_CORRELATOR                       = PT_BINARY+    $00070000;
 PR_CONTENT_IDENTIFIER                       = PT_TSTRING+   $00080000;
 PR_CONTENT_IDENTIFIER_W                     = PT_UNICODE+   $00080000;
 PR_CONTENT_IDENTIFIER_A                     = PT_STRING8+   $00080000;
 PR_CONTENT_LENGTH                           = PT_LONG+      $00090000;
 PR_CONTENT_RETURN_REQUESTED                 = PT_BOOLEAN+   $000A0000;

 PR_CONVERSATION_KEY                         = PT_BINARY+    $000B0000;

 PR_CONVERSION_EITS                          = PT_BINARY+    $000C0000;
 PR_CONVERSION_WITH_LOSS_PROHIBITED          = PT_BOOLEAN+   $000D0000;
 PR_CONVERTED_EITS                           = PT_BINARY+    $000E0000;
 PR_DEFERRED_DELIVERY_TIME                   = PT_SYSTIME+   $000F0000;
 PR_DELIVER_TIME                             = PT_SYSTIME+   $00100000;
 PR_DISCARD_REASON                           = PT_LONG+      $00110000;
 PR_DISCLOSURE_OF_RECIPIENTS                 = PT_BOOLEAN+   $00120000;
 PR_DL_EXPANSION_HISTORY                     = PT_BINARY+    $00130000;
 PR_DL_EXPANSION_PROHIBITED                  = PT_BOOLEAN+   $00140000;
 PR_EXPIRY_TIME                              = PT_SYSTIME+   $00150000;
 PR_IMPLICIT_CONVERSION_PROHIBITED           = PT_BOOLEAN+   $00160000;
 PR_IMPORTANCE                               = PT_LONG+      $00170000;
 PR_IPM_ID                                   = PT_BINARY+    $00180000;
 PR_LATEST_DELIVERY_TIME                     = PT_SYSTIME+   $00190000;
 PR_MESSAGE_CLASS                            = PT_TSTRING+   $001A0000;
 PR_MESSAGE_CLASS_W                          = PT_UNICODE+   $001A0000;
 PR_MESSAGE_CLASS_A                          = PT_STRING8+   $001A0000;
 PR_MESSAGE_DELIVERY_ID                      = PT_BINARY+    $001B0000;

 PR_MESSAGE_SECURITY_LABEL                   = PT_BINARY+    $001E0000;
 PR_OBSOLETED_IPMS                           = PT_BINARY+    $001F0000;
 PR_ORIGINALLY_INTENDED_RECIPIENT_NAME       = PT_BINARY+    $00200000;
 PR_ORIGINAL_EITS                            = PT_BINARY+    $00210000;
 PR_ORIGINATOR_CERTIFICATE                   = PT_BINARY+    $00220000;
 PR_ORIGINATOR_DELIVERY_REPORT_REQUESTED     = PT_BOOLEAN+   $00230000;
 PR_ORIGINATOR_RETURN_ADDRESS                = PT_BINARY+    $00240000;

 PR_PARENT_KEY                               = PT_BINARY+    $00250000;
 PR_PRIORITY                                 = PT_LONG+      $00260000;

 PR_ORIGIN_CHECK                             = PT_BINARY+    $00270000;
 PR_PROOF_OF_SUBMISSION_REQUESTED            = PT_BOOLEAN+   $00280000;
 PR_READ_RECEIPT_REQUESTED                   = PT_BOOLEAN+   $00290000;
 PR_RECEIPT_TIME                             = PT_SYSTIME+   $002A0000;
 PR_RECIPIENT_REASSIGNMENT_PROHIBITED        = PT_BOOLEAN+   $002B0000;
 PR_REDIRECTION_HISTORY                      = PT_BINARY+    $002C0000;
 PR_RELATED_IPMS                             = PT_BINARY+    $002D0000;
 PR_ORIGINAL_SENSITIVITY                     = PT_LONG+      $002E0000;
 PR_LANGUAGES                                = PT_TSTRING+   $002F0000;
 PR_LANGUAGES_W                              = PT_UNICODE+   $002F0000;
 PR_LANGUAGES_A                              = PT_STRING8+   $002F0000;
 PR_REPLY_TIME                               = PT_SYSTIME+   $00300000;
 PR_REPORT_TAG                               = PT_BINARY+    $00310000;
 PR_REPORT_TIME                              = PT_SYSTIME+   $00320000;
 PR_RETURNED_IPM                             = PT_BOOLEAN+   $00330000;
 PR_SECURITY                                 = PT_LONG+      $00340000;
 PR_INCOMPLETE_COPY                          = PT_BOOLEAN+   $00350000;
 PR_SENSITIVITY                              = PT_LONG+      $00360000;
 PR_SUBJECT                                  = PT_TSTRING+   $00370000;
 PR_SUBJECT_W                                = PT_UNICODE+   $00370000;
 PR_SUBJECT_A                                = PT_STRING8+   $00370000;
 PR_SUBJECT_IPM                              = PT_BINARY+    $00380000;
 PR_CLIENT_SUBMIT_TIME                       = PT_SYSTIME+   $00390000;
 PR_REPORT_NAME                              = PT_TSTRING+   $003A0000;
 PR_REPORT_NAME_W                            = PT_UNICODE+   $003A0000;
 PR_REPORT_NAME_A                            = PT_STRING8+   $003A0000;
 PR_SENT_REPRESENTING_SEARCH_KEY             = PT_BINARY+    $003B0000;
 PR_X400_CONTENT_TYPE                        = PT_BINARY+    $003C0000;
 PR_SUBJECT_PREFIX                           = PT_TSTRING+   $003D0000;
 PR_SUBJECT_PREFIX_W                         = PT_UNICODE+   $003D0000;
 PR_SUBJECT_PREFIX_A                         = PT_STRING8+   $003D0000;
 PR_NON_RECEIPT_REASON                       = PT_LONG+      $003E0000;
 PR_RECEIVED_BY_ENTRYID                      = PT_BINARY+    $003F0000;
 PR_RECEIVED_BY_NAME                         = PT_TSTRING+   $00400000;
 PR_RECEIVED_BY_NAME_W                       = PT_UNICODE+   $00400000;
 PR_RECEIVED_BY_NAME_A                       = PT_STRING8+   $00400000;
 PR_SENT_REPRESENTING_ENTRYID                = PT_BINARY+    $00410000;
 PR_SENT_REPRESENTING_NAME                   = PT_TSTRING+   $00420000;
 PR_SENT_REPRESENTING_NAME_W                 = PT_UNICODE+   $00420000;
 PR_SENT_REPRESENTING_NAME_A                 = PT_STRING8+   $00420000;
 PR_RCVD_REPRESENTING_ENTRYID                = PT_BINARY+    $00430000;
 PR_RCVD_REPRESENTING_NAME                   = PT_TSTRING+   $00440000;
 PR_RCVD_REPRESENTING_NAME_W                 = PT_UNICODE+   $00440000;
 PR_RCVD_REPRESENTING_NAME_A                 = PT_STRING8+   $00440000;
 PR_REPORT_ENTRYID                           = PT_BINARY+    $00450000;
 PR_READ_RECEIPT_ENTRYID                     = PT_BINARY+    $00460000;
 PR_MESSAGE_SUBMISSION_ID                    = PT_BINARY+    $00470000;
 PR_PROVIDER_SUBMIT_TIME                     = PT_SYSTIME+   $00480000;
 PR_ORIGINAL_SUBJECT                         = PT_TSTRING+   $00490000;
 PR_ORIGINAL_SUBJECT_W                       = PT_UNICODE+   $00490000;
 PR_ORIGINAL_SUBJECT_A                       = PT_STRING8+   $00490000;
 PR_DISC_VAL                                 = PT_BOOLEAN+   $004A0000;
 PR_ORIG_MESSAGE_CLASS                       = PT_TSTRING+   $004B0000;
 PR_ORIG_MESSAGE_CLASS_W                     = PT_UNICODE+   $004B0000;
 PR_ORIG_MESSAGE_CLASS_A                     = PT_STRING8+   $004B0000;
 PR_ORIGINAL_AUTHOR_ENTRYID                  = PT_BINARY+    $004C0000;
 PR_ORIGINAL_AUTHOR_NAME                     = PT_TSTRING+   $004D0000;
 PR_ORIGINAL_AUTHOR_NAME_W                   = PT_UNICODE+   $004D0000;
 PR_ORIGINAL_AUTHOR_NAME_A                   = PT_STRING8+   $004D0000;
 PR_ORIGINAL_SUBMIT_TIME                     = PT_SYSTIME+   $004E0000;
 PR_REPLY_RECIPIENT_ENTRIES                  = PT_BINARY+    $004F0000;
 PR_REPLY_RECIPIENT_NAMES                    = PT_TSTRING+   $00500000;
 PR_REPLY_RECIPIENT_NAMES_W                  = PT_UNICODE+   $00500000;
 PR_REPLY_RECIPIENT_NAMES_A                  = PT_STRING8+   $00500000;

 PR_RECEIVED_BY_SEARCH_KEY                   = PT_BINARY+    $00510000;
 PR_RCVD_REPRESENTING_SEARCH_KEY             = PT_BINARY+    $00520000;
 PR_READ_RECEIPT_SEARCH_KEY                  = PT_BINARY+    $00530000;
 PR_REPORT_SEARCH_KEY                        = PT_BINARY+    $00540000;
 PR_ORIGINAL_DELIVERY_TIME                   = PT_SYSTIME+   $00550000;
 PR_ORIGINAL_AUTHOR_SEARCH_KEY               = PT_BINARY+    $00560000;

 PR_MESSAGE_TO_ME                            = PT_BOOLEAN+   $00570000;
 PR_MESSAGE_CC_ME                            = PT_BOOLEAN+   $00580000;
 PR_MESSAGE_RECIP_ME                         = PT_BOOLEAN+   $00590000;

 PR_ORIGINAL_SENDER_NAME                     = PT_TSTRING+   $005A0000;
 PR_ORIGINAL_SENDER_NAME_W                   = PT_UNICODE+   $005A0000;
 PR_ORIGINAL_SENDER_NAME_A                   = PT_STRING8+   $005A0000;
 PR_ORIGINAL_SENDER_ENTRYID                  = PT_BINARY+    $005B0000;
 PR_ORIGINAL_SENDER_SEARCH_KEY               = PT_BINARY+    $005C0000;
 PR_ORIGINAL_SENT_REPRESENTING_NAME          = PT_TSTRING+   $005D0000;
 PR_ORIGINAL_SENT_REPRESENTING_NAME_W        = PT_UNICODE+   $005D0000;
 PR_ORIGINAL_SENT_REPRESENTING_NAME_A        = PT_STRING8+   $005D0000;
 PR_ORIGINAL_SENT_REPRESENTING_ENTRYID       = PT_BINARY+    $005E0000;
 PR_ORIGINAL_SENT_REPRESENTING_SEARCH_KEY    = PT_BINARY+    $005F0000;

 PR_START_DATE                               = PT_SYSTIME+   $00600000;
 PR_END_DATE                                 = PT_SYSTIME+   $00610000;
 PR_OWNER_APPT_ID                            = PT_LONG+      $00620000;
 PR_RESPONSE_REQUESTED                       = PT_BOOLEAN+   $00630000;

 PR_SENT_REPRESENTING_ADDRTYPE               = PT_TSTRING+   $00640000;
 PR_SENT_REPRESENTING_ADDRTYPE_W             = PT_UNICODE+   $00640000;
 PR_SENT_REPRESENTING_ADDRTYPE_A             = PT_STRING8+   $00640000;
 PR_SENT_REPRESENTING_EMAIL_ADDRESS          = PT_TSTRING+   $00650000;
 PR_SENT_REPRESENTING_EMAIL_ADDRESS_W        = PT_UNICODE+   $00650000;
 PR_SENT_REPRESENTING_EMAIL_ADDRESS_A        = PT_STRING8+   $00650000;

 PR_ORIGINAL_SENDER_ADDRTYPE                 = PT_TSTRING+   $00660000;
 PR_ORIGINAL_SENDER_ADDRTYPE_W               = PT_UNICODE+   $00660000;
 PR_ORIGINAL_SENDER_ADDRTYPE_A               = PT_STRING8+   $00660000;
 PR_ORIGINAL_SENDER_EMAIL_ADDRESS            = PT_TSTRING+   $00670000;
 PR_ORIGINAL_SENDER_EMAIL_ADDRESS_W          = PT_UNICODE+   $00670000;
 PR_ORIGINAL_SENDER_EMAIL_ADDRESS_A          = PT_STRING8+   $00670000;

 PR_ORIGINAL_SENT_REPRESENTING_ADDRTYPE      = PT_TSTRING+   $00680000;
 PR_ORIGINAL_SENT_REPRESENTING_ADDRTYPE_W    = PT_UNICODE+   $00680000;
 PR_ORIGINAL_SENT_REPRESENTING_ADDRTYPE_A    = PT_STRING8+   $00680000;
 PR_ORIGINAL_SENT_REPRESENTING_EMAIL_ADDRESS = PT_TSTRING+   $00690000;
 PR_ORIGINAL_SENT_REPRESENTING_EMAIL_ADDRESS_W   = PT_UNICODE+   $00690000;
 PR_ORIGINAL_SENT_REPRESENTING_EMAIL_ADDRESS_A   = PT_STRING8+   $00690000;

 PR_CONVERSATION_TOPIC                       = PT_TSTRING+   $00700000;
 PR_CONVERSATION_TOPIC_W                     = PT_UNICODE+   $00700000;
 PR_CONVERSATION_TOPIC_A                     = PT_STRING8+   $00700000;
 PR_CONVERSATION_INDEX                       = PT_BINARY+    $00710000;

 PR_ORIGINAL_DISPLAY_BCC                     = PT_TSTRING+   $00720000;
 PR_ORIGINAL_DISPLAY_BCC_W                   = PT_UNICODE+   $00720000;
 PR_ORIGINAL_DISPLAY_BCC_A                   = PT_STRING8+   $00720000;
 PR_ORIGINAL_DISPLAY_CC                      = PT_TSTRING+   $00730000;
 PR_ORIGINAL_DISPLAY_CC_W                    = PT_UNICODE+   $00730000;
 PR_ORIGINAL_DISPLAY_CC_A                    = PT_STRING8+   $00730000;
 PR_ORIGINAL_DISPLAY_TO                      = PT_TSTRING+   $00740000;
 PR_ORIGINAL_DISPLAY_TO_W                    = PT_UNICODE+   $00740000;
 PR_ORIGINAL_DISPLAY_TO_A                    = PT_STRING8+   $00740000;

 PR_RECEIVED_BY_ADDRTYPE                     = PT_TSTRING+   $00750000;
 PR_RECEIVED_BY_ADDRTYPE_W                   = PT_UNICODE+   $00750000;
 PR_RECEIVED_BY_ADDRTYPE_A                   = PT_STRING8+   $00750000;
 PR_RECEIVED_BY_EMAIL_ADDRESS                = PT_TSTRING+   $00760000;
 PR_RECEIVED_BY_EMAIL_ADDRESS_W              = PT_UNICODE+   $00760000;
 PR_RECEIVED_BY_EMAIL_ADDRESS_A              = PT_STRING8+   $00760000;

 PR_RCVD_REPRESENTING_ADDRTYPE               = PT_TSTRING+   $00770000;
 PR_RCVD_REPRESENTING_ADDRTYPE_W             = PT_UNICODE+   $00770000;
 PR_RCVD_REPRESENTING_ADDRTYPE_A             = PT_STRING8+   $00770000;
 PR_RCVD_REPRESENTING_EMAIL_ADDRESS          = PT_TSTRING+   $00780000;
 PR_RCVD_REPRESENTING_EMAIL_ADDRESS_W        = PT_UNICODE+   $00780000;
 PR_RCVD_REPRESENTING_EMAIL_ADDRESS_A        = PT_STRING8+   $00780000;

 PR_ORIGINAL_AUTHOR_ADDRTYPE                 = PT_TSTRING+   $00790000;
 PR_ORIGINAL_AUTHOR_ADDRTYPE_W               = PT_UNICODE+   $00790000;
 PR_ORIGINAL_AUTHOR_ADDRTYPE_A               = PT_STRING8+   $00790000;
 PR_ORIGINAL_AUTHOR_EMAIL_ADDRESS            = PT_TSTRING+   $007A0000;
 PR_ORIGINAL_AUTHOR_EMAIL_ADDRESS_W          = PT_UNICODE+   $007A0000;
 PR_ORIGINAL_AUTHOR_EMAIL_ADDRESS_A          = PT_STRING8+   $007A0000;

 PR_ORIGINALLY_INTENDED_RECIP_ADDRTYPE       = PT_TSTRING+   $007B0000;
 PR_ORIGINALLY_INTENDED_RECIP_ADDRTYPE_W     = PT_UNICODE+   $007B0000;
 PR_ORIGINALLY_INTENDED_RECIP_ADDRTYPE_A     = PT_STRING8+   $007B0000;
 PR_ORIGINALLY_INTENDED_RECIP_EMAIL_ADDRESS  = PT_TSTRING+   $007C0000;
 PR_ORIGINALLY_INTENDED_RECIP_EMAIL_ADDRESS_W    = PT_UNICODE+   $007C0000;
 PR_ORIGINALLY_INTENDED_RECIP_EMAIL_ADDRESS_A    = PT_STRING8+   $007C0000;

 PR_TRANSPORT_MESSAGE_HEADERS                =PT_TSTRING+    $007D0000;
 PR_TRANSPORT_MESSAGE_HEADERS_W              =PT_UNICODE+    $007D0000;
 PR_TRANSPORT_MESSAGE_HEADERS_A              =PT_STRING8+    $007D0000;

 PR_DELEGATION                               =PT_BINARY+     $007E0000;

 PR_TNEF_CORRELATION_KEY                     =PT_BINARY+     $007F0000;

//*
//*  Message content properties
//*

 PR_BODY                                     = PT_TSTRING+   $10000000;
 PR_BODY_W                                   = PT_UNICODE+   $10000000;
 PR_BODY_A                                   = PT_STRING8+   $10000000;
 PR_REPORT_TEXT                              = PT_TSTRING+   $10010000;
 PR_REPORT_TEXT_W                            = PT_UNICODE+   $10010000;
 PR_REPORT_TEXT_A                            = PT_STRING8+   $10010000;
 PR_ORIGINATOR_AND_DL_EXPANSION_HISTORY      = PT_BINARY+    $10020000;
 PR_REPORTING_DL_NAME                        = PT_BINARY+    $10030000;
 PR_REPORTING_MTA_CERTIFICATE                = PT_BINARY+    $10040000;

//*  Removed PR_REPORT_ORIGIN_AUTHENTICATION_CHECK with DCR 3865+ use PR_ORIGIN_CHECK */

 PR_RTF_SYNC_BODY_CRC                        = PT_LONG+      $10060000;
 PR_RTF_SYNC_BODY_COUNT                      = PT_LONG+      $10070000;
 PR_RTF_SYNC_BODY_TAG                        = PT_TSTRING+   $10080000;
 PR_RTF_SYNC_BODY_TAG_W                      = PT_UNICODE+   $10080000;
 PR_RTF_SYNC_BODY_TAG_A                      = PT_STRING8+   $10080000;
 PR_RTF_COMPRESSED                           = PT_BINARY+    $10090000;
 PR_RTF_SYNC_PREFIX_COUNT                    = PT_LONG+      $10100000;
 PR_RTF_SYNC_TRAILING_COUNT                  = PT_LONG+      $10110000;
 PR_ORIGINALLY_INTENDED_RECIP_ENTRYID        = PT_BINARY+    $10120000;

//*
//*  Reserved $1100-$1200
//*


//*
//*  Message recipient properties
//*

 PR_CONTENT_INTEGRITY_CHECK                  = PT_BINARY+    $0C000000;
 PR_EXPLICIT_CONVERSION                      = PT_LONG+      $0C010000;
 PR_IPM_RETURN_REQUESTED                     = PT_BOOLEAN+   $0C020000;
 PR_MESSAGE_TOKEN                            = PT_BINARY+    $0C030000;
 PR_NDR_REASON_CODE                          = PT_LONG+      $0C040000;
 PR_NDR_DIAG_CODE                            = PT_LONG+      $0C050000;
 PR_NON_RECEIPT_NOTIFICATION_REQUESTED       = PT_BOOLEAN+   $0C060000;
 PR_DELIVERY_POINT                           = PT_LONG+      $0C070000;

 PR_ORIGINATOR_NON_DELIVERY_REPORT_REQUESTED = PT_BOOLEAN+   $0C080000;
 PR_ORIGINATOR_REQUESTED_ALTERNATE_RECIPIENT = PT_BINARY+    $0C090000;
 PR_PHYSICAL_DELIVERY_BUREAU_FAX_DELIVERY    = PT_BOOLEAN+   $0C0A0000;
 PR_PHYSICAL_DELIVERY_MODE                   = PT_LONG+      $0C0B0000;
 PR_PHYSICAL_DELIVERY_REPORT_REQUEST         = PT_LONG+      $0C0C0000;
 PR_PHYSICAL_FORWARDING_ADDRESS              = PT_BINARY+    $0C0D0000;
 PR_PHYSICAL_FORWARDING_ADDRESS_REQUESTED    = PT_BOOLEAN+   $0C0E0000;
 PR_PHYSICAL_FORWARDING_PROHIBITED           = PT_BOOLEAN+   $0C0F0000;
 PR_PHYSICAL_RENDITION_ATTRIBUTES            = PT_BINARY+    $0C100000;
 PR_PROOF_OF_DELIVERY                        = PT_BINARY+    $0C110000;
 PR_PROOF_OF_DELIVERY_REQUESTED              = PT_BOOLEAN+   $0C120000;
 PR_RECIPIENT_CERTIFICATE                    = PT_BINARY+    $0C130000;
 PR_RECIPIENT_NUMBER_FOR_ADVICE              = PT_TSTRING+   $0C140000;
 PR_RECIPIENT_NUMBER_FOR_ADVICE_W            = PT_UNICODE+   $0C140000;
 PR_RECIPIENT_NUMBER_FOR_ADVICE_A            = PT_STRING8+   $0C140000;
 PR_RECIPIENT_TYPE                           = PT_LONG+      $0C150000;
 PR_REGISTERED_MAIL_TYPE                     = PT_LONG+      $0C160000;
 PR_REPLY_REQUESTED                          = PT_BOOLEAN+   $0C170000;
 PR_REQUESTED_DELIVERY_METHOD                = PT_LONG+      $0C180000;
 PR_SENDER_ENTRYID                           = PT_BINARY+    $0C190000;
 PR_SENDER_NAME                              = PT_TSTRING+   $0C1A0000;
 PR_SENDER_NAME_W                            = PT_UNICODE+   $0C1A0000;
 PR_SENDER_NAME_A                            = PT_STRING8+   $0C1A0000;
 PR_SUPPLEMENTARY_INFO                       = PT_TSTRING+   $0C1B0000;
 PR_SUPPLEMENTARY_INFO_W                     = PT_UNICODE+   $0C1B0000;
 PR_SUPPLEMENTARY_INFO_A                     = PT_STRING8+   $0C1B0000;
 PR_TYPE_OF_MTS_USER                         = PT_LONG+      $0C1C0000;
 PR_SENDER_SEARCH_KEY                        = PT_BINARY+    $0C1D0000;
 PR_SENDER_ADDRTYPE                          = PT_TSTRING+   $0C1E0000;
 PR_SENDER_ADDRTYPE_W                        = PT_UNICODE+   $0C1E0000;
 PR_SENDER_ADDRTYPE_A                        = PT_STRING8+   $0C1E0000;
 PR_SENDER_EMAIL_ADDRESS                     = PT_TSTRING+   $0C1F0000;
 PR_SENDER_EMAIL_ADDRESS_W                   = PT_UNICODE+   $0C1F0000;
 PR_SENDER_EMAIL_ADDRESS_A                   = PT_STRING8+   $0C1F0000;

//*
//*  Message non-transmittable properties
//*

//*
//* The two tags+ PR_MESSAGE_RECIPIENTS and PR_MESSAGE_ATTACHMENTS+
//* are to be used in the exclude list passed to
//* IMessage::CopyTo when the caller wants either the recipients or attachments
//* of the message to not get copied.  It is also used in the ProblemArray
//* return from IMessage::CopyTo when an error is encountered copying them
//*

 PR_CURRENT_VERSION                          = PT_I8+        $0E000000;
 PR_DELETE_AFTER_SUBMIT                      = PT_BOOLEAN+   $0E010000;
 PR_DISPLAY_BCC                              = PT_TSTRING+   $0E020000;
 PR_DISPLAY_BCC_W                            = PT_UNICODE+   $0E020000;
 PR_DISPLAY_BCC_A                            = PT_STRING8+   $0E020000;
 PR_DISPLAY_CC                               = PT_TSTRING+   $0E030000;
 PR_DISPLAY_CC_W                             = PT_UNICODE+   $0E030000;
 PR_DISPLAY_CC_A                             = PT_STRING8+   $0E030000;
 PR_DISPLAY_TO                               = PT_TSTRING+   $0E040000;
 PR_DISPLAY_TO_W                             = PT_UNICODE+   $0E040000;
 PR_DISPLAY_TO_A                             = PT_STRING8+   $0E040000;
 PR_PARENT_DISPLAY                           = PT_TSTRING+   $0E050000;
 PR_PARENT_DISPLAY_W                         = PT_UNICODE+   $0E050000;
 PR_PARENT_DISPLAY_A                         = PT_STRING8+   $0E050000;
 PR_MESSAGE_DELIVERY_TIME                    = PT_SYSTIME+   $0E060000;
 PR_MESSAGE_FLAGS                            = PT_LONG+      $0E070000;
 PR_MESSAGE_SIZE                             = PT_LONG+      $0E080000;
 PR_PARENT_ENTRYID                           = PT_BINARY+    $0E090000;
 PR_SENTMAIL_ENTRYID                         = PT_BINARY+    $0E0A0000;
 PR_CORRELATE                                = PT_BOOLEAN+   $0E0C0000;
 PR_CORRELATE_MTSID                          = PT_BINARY+    $0E0D0000;
 PR_DISCRETE_VALUES                          = PT_BOOLEAN+   $0E0E0000;
 PR_RESPONSIBILITY                           = PT_BOOLEAN+   $0E0F0000;
 PR_SPOOLER_STATUS                           = PT_LONG+      $0E100000;
 PR_TRANSPORT_STATUS                         = PT_LONG+      $0E110000;
 PR_MESSAGE_RECIPIENTS                       = PT_OBJECT+    $0E120000;
 PR_MESSAGE_ATTACHMENTS                      = PT_OBJECT+    $0E130000;
 PR_SUBMIT_FLAGS                             = PT_LONG+      $0E140000;
 PR_RECIPIENT_STATUS                         = PT_LONG+      $0E150000;
 PR_TRANSPORT_KEY                            = PT_LONG+      $0E160000;
 PR_MSG_STATUS                               = PT_LONG+      $0E170000;
 PR_MESSAGE_DOWNLOAD_TIME                    = PT_LONG+      $0E180000;
 PR_CREATION_VERSION                         = PT_I8+        $0E190000;
 PR_MODIFY_VERSION                           = PT_I8+        $0E1A0000;
 PR_HASATTACH                                = PT_BOOLEAN+   $0E1B0000;
 PR_BODY_CRC                                 = PT_LONG+      $0E1C0000;
 PR_NORMALIZED_SUBJECT                       = PT_TSTRING+   $0E1D0000;
 PR_NORMALIZED_SUBJECT_W                     = PT_UNICODE+   $0E1D0000;
 PR_NORMALIZED_SUBJECT_A                     = PT_STRING8+   $0E1D0000;
 PR_RTF_IN_SYNC                              = PT_BOOLEAN+   $0E1F0000;
 PR_ATTACH_SIZE                              = PT_LONG+      $0E200000;
 PR_ATTACH_NUM                               = PT_LONG+      $0E210000;
 PR_PREPROCESS                               = PT_BOOLEAN+   $0E220000;

//* PR_ORIGINAL_DISPLAY_TO+ _CC+ and _BCC moved to transmittible range 03/09/95 */

 PR_ORIGINATING_MTA_CERTIFICATE              = PT_BINARY+    $0E250000;
 PR_PROOF_OF_SUBMISSION                      = PT_BINARY+    $0E260000;

//
// The range of non-message and non-recipient property IDs ($3000 - $3FFF0000; is
// further broken down into ranges to make assigning new property IDs easier.
//
//  From    To      Kind of property
//  --------------------------------
//  3000    32FF    MAPI_defined common property
//  3200    33FF    MAPI_defined form property
//  3400    35FF    MAPI_defined message store property
//  3600    36FF    MAPI_defined Folder or AB Container property
//  3700    38FF    MAPI_defined attachment property
//  3900    39FF    MAPI_defined address book property
//  3A00    3BFF    MAPI_defined mailuser property
//  3C00    3CFF    MAPI_defined DistList property
//  3D00    3DFF    MAPI_defined Profile Section property
//  3E00    3EFF    MAPI_defined Status property
//  3F00    3FFF    MAPI_defined display table property
//

//
//  Properties common to numerous MAPI objects.
//
//  Those properties that can appear on messages are in the
//  non-transmittable range for messages. They start at the high
//  end of that range and work down.
//
//  Properties that never appear on messages are defined in the common
//  property range (see above0000;.
//

//
// properties that are common to multiple objects (including message objects0000;
// -- these ids are in the non-transmittable range
//

 PR_ENTRYID                                  = PT_BINARY+    $0FFF0000;
 PR_OBJECT_TYPE                              = PT_LONG+      $0FFE0000;
 PR_ICON                                     = PT_BINARY+    $0FFD0000;
 PR_MINI_ICON                                = PT_BINARY+    $0FFC0000;
 PR_STORE_ENTRYID                            = PT_BINARY+    $0FFB0000;
 PR_STORE_RECORD_KEY                         = PT_BINARY+    $0FFA0000;
 PR_RECORD_KEY                               = PT_BINARY+    $0FF90000;
 PR_MAPPING_SIGNATURE                        = PT_BINARY+    $0FF80000;
 PR_ACCESS_LEVEL                             = PT_LONG+      $0FF70000;
 PR_INSTANCE_KEY                             = PT_BINARY+    $0FF60000;
 PR_ROW_TYPE                                 = PT_LONG+      $0FF50000;
 PR_ACCESS                                   = PT_LONG+      $0FF40000;

//
// properties that are common to multiple objects (usually not including message objects0000;
// -- these ids are in the transmittable range
//

 PR_ROWID                                    = PT_LONG+      $30000000;
 PR_DISPLAY_NAME                             = PT_TSTRING+   $30010000;
 PR_DISPLAY_NAME_W                           = PT_UNICODE+   $30010000;
 PR_DISPLAY_NAME_A                           = PT_STRING8+   $30010000;
 PR_ADDRTYPE                                 = PT_TSTRING+   $30020000;
 PR_ADDRTYPE_W                               = PT_UNICODE+   $30020000;
 PR_ADDRTYPE_A                               = PT_STRING8+   $30020000;
 PR_EMAIL_ADDRESS                            = PT_TSTRING+   $30030000;
 PR_EMAIL_ADDRESS_W                          = PT_UNICODE+   $30030000;
 PR_EMAIL_ADDRESS_A                          = PT_STRING8+   $30030000;
 PR_COMMENT                                  = PT_TSTRING+   $30040000;
 PR_COMMENT_W                                = PT_UNICODE+   $30040000;
 PR_COMMENT_A                                = PT_STRING8+   $30040000;
 PR_DEPTH                                    = PT_LONG+      $30050000;
 PR_PROVIDER_DISPLAY                         = PT_TSTRING+   $30060000;
 PR_PROVIDER_DISPLAY_W                       = PT_UNICODE+   $30060000;
 PR_PROVIDER_DISPLAY_A                       = PT_STRING8+   $30060000;
 PR_CREATION_TIME                            = PT_SYSTIME+   $30070000;
 PR_LAST_MODIFICATION_TIME                   = PT_SYSTIME+   $30080000;
 PR_RESOURCE_FLAGS                           = PT_LONG+      $30090000;
 PR_PROVIDER_DLL_NAME                        = PT_TSTRING+   $300A0000;
 PR_PROVIDER_DLL_NAME_W                      = PT_UNICODE+   $300A0000;
 PR_PROVIDER_DLL_NAME_A                      = PT_STRING8+   $300A0000;
 PR_SEARCH_KEY                               = PT_BINARY+    $300B0000;
 PR_PROVIDER_UID                             = PT_BINARY+    $300C0000;
 PR_PROVIDER_ORDINAL                         = PT_LONG+      $300D0000;

//
//  MAPI Form properties
//

 PR_FORM_VERSION                             =PT_TSTRING+    $33010000;
 PR_FORM_VERSION_W                           =PT_UNICODE+    $33010000;
 PR_FORM_VERSION_A                           =PT_STRING8+    $33010000;
 PR_FORM_CLSID                               =PT_CLSID+      $33020000;
 PR_FORM_CONTACT_NAME                        =PT_TSTRING+    $33030000;
 PR_FORM_CONTACT_NAME_W                      =PT_UNICODE+    $33030000;
 PR_FORM_CONTACT_NAME_A                      =PT_STRING8+    $33030000;
 PR_FORM_CATEGORY                            =PT_TSTRING+    $33040000;
 PR_FORM_CATEGORY_W                          =PT_UNICODE+    $33040000;
 PR_FORM_CATEGORY_A                          =PT_STRING8+    $33040000;
 PR_FORM_CATEGORY_SUB                        =PT_TSTRING+    $33050000;
 PR_FORM_CATEGORY_SUB_W                      =PT_UNICODE+    $33050000;
 PR_FORM_CATEGORY_SUB_A                      =PT_STRING8+    $33050000;
 PR_FORM_HOST_MAP                            =PT_MV_LONG+    $33060000;
 PR_FORM_HIDDEN                              =PT_BOOLEAN+    $33070000;
 PR_FORM_DESIGNER_NAME                       =PT_TSTRING+    $33080000;
 PR_FORM_DESIGNER_NAME_W                     =PT_UNICODE+    $33080000;
 PR_FORM_DESIGNER_NAME_A                     =PT_STRING8+    $33080000;
 PR_FORM_DESIGNER_GUID                       =PT_CLSID+      $33090000;
 PR_FORM_MESSAGE_BEHAVIOR                    =PT_LONG+       $330A0000;

//
//  Message store properties
//

 PR_DEFAULT_STORE                            = PT_BOOLEAN+   $34000000;
 PR_STORE_SUPPORT_MASK                       = PT_LONG+      $340D0000;
 PR_STORE_STATE                              = PT_LONG+      $340E0000;

 PR_IPM_SUBTREE_SEARCH_KEY                   = PT_BINARY+    $34100000;
 PR_IPM_OUTBOX_SEARCH_KEY                    = PT_BINARY+    $34110000;
 PR_IPM_WASTEBASKET_SEARCH_KEY               = PT_BINARY+    $34120000;
 PR_IPM_SENTMAIL_SEARCH_KEY                  = PT_BINARY+    $34130000;
 PR_MDB_PROVIDER                             = PT_BINARY+    $34140000;
 PR_RECEIVE_FOLDER_SETTINGS                  = PT_OBJECT+    $34150000;

 PR_VALID_FOLDER_MASK                        = PT_LONG+      $35DF0000;
 PR_IPM_SUBTREE_ENTRYID                      = PT_BINARY+    $35E00000;

 PR_IPM_OUTBOX_ENTRYID                       = PT_BINARY+    $35E20000;
 PR_IPM_WASTEBASKET_ENTRYID                  = PT_BINARY+    $35E30000;
 PR_IPM_SENTMAIL_ENTRYID                     = PT_BINARY+    $35E40000;
 PR_VIEWS_ENTRYID                            = PT_BINARY+    $35E50000;
 PR_COMMON_VIEWS_ENTRYID                     = PT_BINARY+    $35E60000;
 PR_FINDER_ENTRYID                           = PT_BINARY+    $35E70000;

// Proptags $35E8-$35FF reserved for folders "guaranteed" by PR_VALID_FOLDER_MASK */

//
//  Folder and AB Container properties
//

 PR_CONTAINER_FLAGS                          = PT_LONG+      $36000000;
 PR_FOLDER_TYPE                              = PT_LONG+      $36010000;
 PR_CONTENT_COUNT                            = PT_LONG+      $36020000;
 PR_CONTENT_UNREAD                           = PT_LONG+      $36030000;
 PR_CREATE_TEMPLATES                         = PT_OBJECT+    $36040000;
 PR_DETAILS_TABLE                            = PT_OBJECT+    $36050000;
 PR_SEARCH                                   = PT_OBJECT+    $36070000;
 PR_SELECTABLE                               = PT_BOOLEAN+   $36090000;
 PR_SUBFOLDERS                               = PT_BOOLEAN+   $360A0000;
 PR_STATUS                                   = PT_LONG+      $360B0000;
 PR_ANR                                      = PT_TSTRING+   $360C0000;
 PR_ANR_W                                    = PT_UNICODE+   $360C0000;
 PR_ANR_A                                    = PT_STRING8+   $360C0000;
 PR_CONTENTS_SORT_ORDER                      = PT_MV_LONG+   $360D0000;
 PR_CONTAINER_HIERARCHY                      = PT_OBJECT+    $360E0000;
 PR_CONTAINER_CONTENTS                       = PT_OBJECT+    $360F0000;
 PR_FOLDER_ASSOCIATED_CONTENTS               = PT_OBJECT+    $36100000;
 PR_DEF_CREATE_DL                            = PT_BINARY+    $36110000;
 PR_DEF_CREATE_MAILUSER                      = PT_BINARY+    $36120000;
 PR_CONTAINER_CLASS                          = PT_TSTRING+   $36130000;
 PR_CONTAINER_CLASS_W                        = PT_UNICODE+   $36130000;
 PR_CONTAINER_CLASS_A                        = PT_STRING8+   $36130000;
 PR_CONTAINER_MODIFY_VERSION                 = PT_I8+        $36140000;
 PR_AB_PROVIDER_ID                           = PT_BINARY+    $36150000;
 PR_DEFAULT_VIEW_ENTRYID                     = PT_BINARY+    $36160000;
 PR_ASSOC_CONTENT_COUNT                      = PT_LONG+      $36170000;

// Reserved $36C0-$36FF */

//
//  Attachment properties
//

 PR_ATTACHMENT_X400_PARAMETERS               = PT_BINARY+    $37000000;
 PR_ATTACH_DATA_OBJ                          = PT_OBJECT+    $37010000;
 PR_ATTACH_DATA_BIN                          = PT_BINARY+    $37010000;
 PR_ATTACH_ENCODING                          = PT_BINARY+    $37020000;
 PR_ATTACH_EXTENSION                         = PT_TSTRING+   $37030000;
 PR_ATTACH_EXTENSION_W                       = PT_UNICODE+   $37030000;
 PR_ATTACH_EXTENSION_A                       = PT_STRING8+   $37030000;
 PR_ATTACH_FILENAME                          = PT_TSTRING+   $37040000;
 PR_ATTACH_FILENAME_W                        = PT_UNICODE+   $37040000;
 PR_ATTACH_FILENAME_A                        = PT_STRING8+   $37040000;
 PR_ATTACH_METHOD                            = PT_LONG+      $37050000;
 PR_ATTACH_LONG_FILENAME                     = PT_TSTRING+   $37070000;
 PR_ATTACH_LONG_FILENAME_W                   = PT_UNICODE+   $37070000;
 PR_ATTACH_LONG_FILENAME_A                   = PT_STRING8+   $37070000;
 PR_ATTACH_PATHNAME                          = PT_TSTRING+   $37080000;
 PR_ATTACH_PATHNAME_W                        = PT_UNICODE+   $37080000;
 PR_ATTACH_PATHNAME_A                        = PT_STRING8+   $37080000;
 PR_ATTACH_RENDERING                         = PT_BINARY+    $37090000;
 PR_ATTACH_TAG                               = PT_BINARY+    $370A0000;
 PR_RENDERING_POSITION                       = PT_LONG+      $370B0000;
 PR_ATTACH_TRANSPORT_NAME                    = PT_TSTRING+   $370C0000;
 PR_ATTACH_TRANSPORT_NAME_W                  = PT_UNICODE+   $370C0000;
 PR_ATTACH_TRANSPORT_NAME_A                  = PT_STRING8+   $370C0000;
 PR_ATTACH_LONG_PATHNAME                     = PT_TSTRING+   $370D0000;
 PR_ATTACH_LONG_PATHNAME_W                   = PT_UNICODE+   $370D0000;
 PR_ATTACH_LONG_PATHNAME_A                   = PT_STRING8+   $370D0000;
 PR_ATTACH_MIME_TAG                          = PT_TSTRING+   $370E0000;
 PR_ATTACH_MIME_TAG_W                        = PT_UNICODE+   $370E0000;
 PR_ATTACH_MIME_TAG_A                        = PT_STRING8+   $370E0000;
 PR_ATTACH_ADDITIONAL_INFO                   = PT_BINARY+    $370F0000;

//
//  AB Object properties
//

 PR_DISPLAY_TYPE                             = PT_LONG+      $39000000;
 PR_TEMPLATEID                               = PT_BINARY+    $39020000;
 PR_PRIMARY_CAPABILITY                       = PT_BINARY+    $39040000;

//
//  Mail user properties
//

 PR_7BIT_DISPLAY_NAME                        = PT_STRING8+   $39FF0000;
 PR_ACCOUNT                                  = PT_TSTRING+   $3A000000;
 PR_ACCOUNT_W                                = PT_UNICODE+   $3A000000;
 PR_ACCOUNT_A                                = PT_STRING8+   $3A000000;
 PR_ALTERNATE_RECIPIENT                      = PT_BINARY+    $3A010000;
 PR_CALLBACK_TELEPHONE_NUMBER                = PT_TSTRING+   $3A020000;
 PR_CALLBACK_TELEPHONE_NUMBER_W              = PT_UNICODE+   $3A020000;
 PR_CALLBACK_TELEPHONE_NUMBER_A              = PT_STRING8+   $3A020000;
 PR_CONVERSION_PROHIBITED                    = PT_BOOLEAN+   $3A030000;
 PR_DISCLOSE_RECIPIENTS                      = PT_BOOLEAN+   $3A040000;
 PR_GENERATION                               = PT_TSTRING+   $3A050000;
 PR_GENERATION_W                             = PT_UNICODE+   $3A050000;
 PR_GENERATION_A                             = PT_STRING8+   $3A050000;
 PR_GIVEN_NAME                               = PT_TSTRING+   $3A060000;
 PR_GIVEN_NAME_W                             = PT_UNICODE+   $3A060000;
 PR_GIVEN_NAME_A                             = PT_STRING8+   $3A060000;
 PR_GOVERNMENT_ID_NUMBER                     = PT_TSTRING+   $3A070000;
 PR_GOVERNMENT_ID_NUMBER_W                   = PT_UNICODE+   $3A070000;
 PR_GOVERNMENT_ID_NUMBER_A                   = PT_STRING8+   $3A070000;
 PR_BUSINESS_TELEPHONE_NUMBER                = PT_TSTRING+   $3A080000;
 PR_BUSINESS_TELEPHONE_NUMBER_W              = PT_UNICODE+   $3A080000;
 PR_BUSINESS_TELEPHONE_NUMBER_A              = PT_STRING8+   $3A080000;
 PR_OFFICE_TELEPHONE_NUMBER                  = PR_BUSINESS_TELEPHONE_NUMBER;
 PR_OFFICE_TELEPHONE_NUMBER_W                = PR_BUSINESS_TELEPHONE_NUMBER_W;
 PR_OFFICE_TELEPHONE_NUMBER_A                = PR_BUSINESS_TELEPHONE_NUMBER_A;
 PR_HOME_TELEPHONE_NUMBER                    = PT_TSTRING+   $3A090000;
 PR_HOME_TELEPHONE_NUMBER_W                  = PT_UNICODE+   $3A090000;
 PR_HOME_TELEPHONE_NUMBER_A                  = PT_STRING8+   $3A090000;
 PR_INITIALS                                 = PT_TSTRING+   $3A0A0000;
 PR_INITIALS_W                               = PT_UNICODE+   $3A0A0000;
 PR_INITIALS_A                               = PT_STRING8+   $3A0A0000;
 PR_KEYWORD                                  = PT_TSTRING+   $3A0B0000;
 PR_KEYWORD_W                                = PT_UNICODE+   $3A0B0000;
 PR_KEYWORD_A                                = PT_STRING8+   $3A0B0000;
 PR_LANGUAGE                                 = PT_TSTRING+   $3A0C0000;
 PR_LANGUAGE_W                               = PT_UNICODE+   $3A0C0000;
 PR_LANGUAGE_A                               = PT_STRING8+   $3A0C0000;
 PR_LOCATION                                 = PT_TSTRING+   $3A0D0000;
 PR_LOCATION_W                               = PT_UNICODE+   $3A0D0000;
 PR_LOCATION_A                               = PT_STRING8+   $3A0D0000;
 PR_MAIL_PERMISSION                          = PT_BOOLEAN+   $3A0E0000;
 PR_MHS_COMMON_NAME                          = PT_TSTRING+   $3A0F0000;
 PR_MHS_COMMON_NAME_W                        = PT_UNICODE+   $3A0F0000;
 PR_MHS_COMMON_NAME_A                        = PT_STRING8+   $3A0F0000;
 PR_ORGANIZATIONAL_ID_NUMBER                 = PT_TSTRING+   $3A100000;
 PR_ORGANIZATIONAL_ID_NUMBER_W               = PT_UNICODE+   $3A100000;
 PR_ORGANIZATIONAL_ID_NUMBER_A               = PT_STRING8+   $3A100000;
 PR_SURNAME                                  = PT_TSTRING+   $3A110000;
 PR_SURNAME_W                                = PT_UNICODE+   $3A110000;
 PR_SURNAME_A                                = PT_STRING8+   $3A110000;
 PR_ORIGINAL_ENTRYID                         = PT_BINARY+    $3A120000;
 PR_ORIGINAL_DISPLAY_NAME                    = PT_TSTRING+   $3A130000;
 PR_ORIGINAL_DISPLAY_NAME_W                  = PT_UNICODE+   $3A130000;
 PR_ORIGINAL_DISPLAY_NAME_A                  = PT_STRING8+   $3A130000;
 PR_ORIGINAL_SEARCH_KEY                      = PT_BINARY+    $3A140000;
 PR_POSTAL_ADDRESS                           = PT_TSTRING+   $3A150000;
 PR_POSTAL_ADDRESS_W                         = PT_UNICODE+   $3A150000;
 PR_POSTAL_ADDRESS_A                         = PT_STRING8+   $3A150000;
 PR_COMPANY_NAME                             = PT_TSTRING+   $3A160000;
 PR_COMPANY_NAME_W                           = PT_UNICODE+   $3A160000;
 PR_COMPANY_NAME_A                           = PT_STRING8+   $3A160000;
 PR_TITLE                                    = PT_TSTRING+   $3A170000;
 PR_TITLE_W                                  = PT_UNICODE+   $3A170000;
 PR_TITLE_A                                  = PT_STRING8+   $3A170000;
 PR_DEPARTMENT_NAME                          = PT_TSTRING+   $3A180000;
 PR_DEPARTMENT_NAME_W                        = PT_UNICODE+   $3A180000;
 PR_DEPARTMENT_NAME_A                        = PT_STRING8+   $3A180000;
 PR_OFFICE_LOCATION                          = PT_TSTRING+   $3A190000;
 PR_OFFICE_LOCATION_W                        = PT_UNICODE+   $3A190000;
 PR_OFFICE_LOCATION_A                        = PT_STRING8+   $3A190000;
 PR_PRIMARY_TELEPHONE_NUMBER                 = PT_TSTRING+   $3A1A0000;
 PR_PRIMARY_TELEPHONE_NUMBER_W               = PT_UNICODE+   $3A1A0000;
 PR_PRIMARY_TELEPHONE_NUMBER_A               = PT_STRING8+   $3A1A0000;
 PR_BUSINESS2_TELEPHONE_NUMBER               = PT_TSTRING+   $3A1B0000;
 PR_BUSINESS2_TELEPHONE_NUMBER_W             = PT_UNICODE+   $3A1B0000;
 PR_BUSINESS2_TELEPHONE_NUMBER_A             = PT_STRING8+   $3A1B0000;
 PR_OFFICE2_TELEPHONE_NUMBER                 = PR_BUSINESS2_TELEPHONE_NUMBER;
 PR_OFFICE2_TELEPHONE_NUMBER_W               = PR_BUSINESS2_TELEPHONE_NUMBER_W;
 PR_OFFICE2_TELEPHONE_NUMBER_A               = PR_BUSINESS2_TELEPHONE_NUMBER_A;
 PR_MOBILE_TELEPHONE_NUMBER                  = PT_TSTRING+   $3A1C0000;
 PR_MOBILE_TELEPHONE_NUMBER_W                = PT_UNICODE+   $3A1C0000;
 PR_MOBILE_TELEPHONE_NUMBER_A                = PT_STRING8+   $3A1C0000;
 PR_CELLULAR_TELEPHONE_NUMBER                = PR_MOBILE_TELEPHONE_NUMBER;
 PR_CELLULAR_TELEPHONE_NUMBER_W              = PR_MOBILE_TELEPHONE_NUMBER_W;
 PR_CELLULAR_TELEPHONE_NUMBER_A              = PR_MOBILE_TELEPHONE_NUMBER_A;
 PR_RADIO_TELEPHONE_NUMBER                   = PT_TSTRING+   $3A1D0000;
 PR_RADIO_TELEPHONE_NUMBER_W                 = PT_UNICODE+   $3A1D0000;
 PR_RADIO_TELEPHONE_NUMBER_A                 = PT_STRING8+   $3A1D0000;
 PR_CAR_TELEPHONE_NUMBER                     = PT_TSTRING+   $3A1E0000;
 PR_CAR_TELEPHONE_NUMBER_W                   = PT_UNICODE+   $3A1E0000;
 PR_CAR_TELEPHONE_NUMBER_A                   = PT_STRING8+   $3A1E0000;
 PR_OTHER_TELEPHONE_NUMBER                   = PT_TSTRING+   $3A1F0000;
 PR_OTHER_TELEPHONE_NUMBER_W                 = PT_UNICODE+   $3A1F0000;
 PR_OTHER_TELEPHONE_NUMBER_A                 = PT_STRING8+   $3A1F0000;
 PR_TRANSMITABLE_DISPLAY_NAME                = PT_TSTRING+   $3A200000;
 PR_TRANSMITABLE_DISPLAY_NAME_W              = PT_UNICODE+   $3A200000;
 PR_TRANSMITABLE_DISPLAY_NAME_A              = PT_STRING8+   $3A200000;
 PR_PAGER_TELEPHONE_NUMBER                   = PT_TSTRING+   $3A210000;
 PR_PAGER_TELEPHONE_NUMBER_W                 = PT_UNICODE+   $3A210000;
 PR_PAGER_TELEPHONE_NUMBER_A                 = PT_STRING8+   $3A210000;
 PR_BEEPER_TELEPHONE_NUMBER                  = PR_PAGER_TELEPHONE_NUMBER;
 PR_BEEPER_TELEPHONE_NUMBER_W                = PR_PAGER_TELEPHONE_NUMBER_W;
 PR_BEEPER_TELEPHONE_NUMBER_A                = PR_PAGER_TELEPHONE_NUMBER_A;
 PR_USER_CERTIFICATE                         = PT_BINARY+    $3A220000;
 PR_PRIMARY_FAX_NUMBER                       = PT_TSTRING+   $3A230000;
 PR_PRIMARY_FAX_NUMBER_W                     = PT_UNICODE+   $3A230000;
 PR_PRIMARY_FAX_NUMBER_A                     = PT_STRING8+   $3A230000;
 PR_BUSINESS_FAX_NUMBER                      = PT_TSTRING+   $3A240000;
 PR_BUSINESS_FAX_NUMBER_W                    = PT_UNICODE+   $3A240000;
 PR_BUSINESS_FAX_NUMBER_A                    = PT_STRING8+   $3A240000;
 PR_HOME_FAX_NUMBER                          = PT_TSTRING+   $3A250000;
 PR_HOME_FAX_NUMBER_W                        = PT_UNICODE+   $3A250000;
 PR_HOME_FAX_NUMBER_A                        = PT_STRING8+   $3A250000;
 PR_COUNTRY                                  = PT_TSTRING+   $3A260000;
 PR_COUNTRY_W                                = PT_UNICODE+   $3A260000;
 PR_COUNTRY_A                                = PT_STRING8+   $3A260000;
 PR_BUSINESS_ADDRESS_COUNTRY                 = PR_COUNTRY;
 PR_BUSINESS_ADDRESS_COUNTRY_W               = PR_COUNTRY_W;
 PR_BUSINESS_ADDRESS_COUNTRY_A               = PR_COUNTRY_A;

 PR_LOCALITY                                 = PT_TSTRING+   $3A270000;
 PR_LOCALITY_W                               = PT_UNICODE+   $3A270000;
 PR_LOCALITY_A                               = PT_STRING8+   $3A270000;
 PR_BUSINESS_ADDRESS_CITY                    = PR_LOCALITY;
 PR_BUSINESS_ADDRESS_CITY_W                  = PR_LOCALITY_W;
 PR_BUSINESS_ADDRESS_CITY_A                  = PR_LOCALITY_A;

 PR_STATE_OR_PROVINCE                        = PT_TSTRING+   $3A280000;
 PR_STATE_OR_PROVINCE_W                      = PT_UNICODE+   $3A280000;
 PR_STATE_OR_PROVINCE_A                      = PT_STRING8+   $3A280000;
 PR_BUSINESS_ADDRESS_STATE_OR_PROVINCE       = PR_STATE_OR_PROVINCE;
 PR_BUSINESS_ADDRESS_STATE_OR_PROVINCE_W     = PR_STATE_OR_PROVINCE_W;
 PR_BUSINESS_ADDRESS_STATE_OR_PROVINCE_A     = PR_STATE_OR_PROVINCE_A;

 PR_STREET_ADDRESS                           = PT_TSTRING+   $3A290000;
 PR_STREET_ADDRESS_W                         = PT_UNICODE+   $3A290000;
 PR_STREET_ADDRESS_A                         = PT_STRING8+   $3A290000;
 PR_BUSINESS_ADDRESS_STREET                  = PR_STREET_ADDRESS;
 PR_BUSINESS_ADDRESS_STREET_W                = PR_STREET_ADDRESS_W;
 PR_BUSINESS_ADDRESS_STREET_A                = PR_STREET_ADDRESS_A;

 PR_POSTAL_CODE                              = PT_TSTRING+   $3A2A0000;
 PR_POSTAL_CODE_W                            = PT_UNICODE+   $3A2A0000;
 PR_POSTAL_CODE_A                            = PT_STRING8+   $3A2A0000;
 PR_BUSINESS_ADDRESS_POSTAL_CODE             = PR_POSTAL_CODE;
 PR_BUSINESS_ADDRESS_POSTAL_CODE_W           = PR_POSTAL_CODE_W;
 PR_BUSINESS_ADDRESS_POSTAL_CODE_A           = PR_POSTAL_CODE_A;

 PR_POST_OFFICE_BOX                          = PT_TSTRING+   $3A2B0000;
 PR_POST_OFFICE_BOX_W                        = PT_UNICODE+   $3A2B0000;
 PR_POST_OFFICE_BOX_A                        = PT_STRING8+   $3A2B0000;
 PR_BUSINESS_ADDRESS_POST_OFFICE_BOX         = PR_POST_OFFICE_BOX;
 PR_BUSINESS_ADDRESS_POST_OFFICE_BOX_W       = PR_POST_OFFICE_BOX_W;
 PR_BUSINESS_ADDRESS_POST_OFFICE_BOX_A       = PR_POST_OFFICE_BOX_A;

 PR_TELEX_NUMBER                             = PT_TSTRING+   $3A2C0000;
 PR_TELEX_NUMBER_W                           = PT_UNICODE+   $3A2C0000;
 PR_TELEX_NUMBER_A                           = PT_STRING8+   $3A2C0000;
 PR_ISDN_NUMBER                              = PT_TSTRING+   $3A2D0000;
 PR_ISDN_NUMBER_W                            = PT_UNICODE+   $3A2D0000;
 PR_ISDN_NUMBER_A                            = PT_STRING8+   $3A2D0000;
 PR_ASSISTANT_TELEPHONE_NUMBER               = PT_TSTRING+   $3A2E0000;
 PR_ASSISTANT_TELEPHONE_NUMBER_W             = PT_UNICODE+   $3A2E0000;
 PR_ASSISTANT_TELEPHONE_NUMBER_A             = PT_STRING8+   $3A2E0000;
 PR_HOME2_TELEPHONE_NUMBER                   = PT_TSTRING+   $3A2F0000;
 PR_HOME2_TELEPHONE_NUMBER_W                 = PT_UNICODE+   $3A2F0000;
 PR_HOME2_TELEPHONE_NUMBER_A                 = PT_STRING8+   $3A2F0000;
 PR_ASSISTANT                                = PT_TSTRING+   $3A300000;
 PR_ASSISTANT_W                              = PT_UNICODE+   $3A300000;
 PR_ASSISTANT_A                              = PT_STRING8+   $3A300000;
 PR_SEND_RICH_INFO                           = PT_BOOLEAN+   $3A400000;

 PR_WEDDING_ANNIVERSARY                      = PT_SYSTIME+ $3A410000;
 PR_BIRTHDAY                                 = PT_SYSTIME+ $3A420000;

 PR_HOBBIES                                  = PT_TSTRING+ $3A430000;
 PR_HOBBIES_W                                = PT_UNICODE+ $3A430000;
 PR_HOBBIES_A                                = PT_STRING8+ $3A430000;

 PR_MIDDLE_NAME                              = PT_TSTRING+ $3A440000;
 PR_MIDDLE_NAME_W                            = PT_UNICODE+ $3A440000;
 PR_MIDDLE_NAME_A                            = PT_STRING8+ $3A440000;

 PR_DISPLAY_NAME_PREFIX                      = PT_TSTRING+ $3A450000;
 PR_DISPLAY_NAME_PREFIX_W                    = PT_UNICODE+ $3A450000;
 PR_DISPLAY_NAME_PREFIX_A                    = PT_STRING8+ $3A450000;

 PR_PROFESSION                               = PT_TSTRING+ $3A460000;
 PR_PROFESSION_W                             = PT_UNICODE+ $3A460000;
 PR_PROFESSION_A                             = PT_STRING8+ $3A460000;

 PR_PREFERRED_BY_NAME                        = PT_TSTRING+ $3A470000;
 PR_PREFERRED_BY_NAME_W                      = PT_UNICODE+ $3A470000;
 PR_PREFERRED_BY_NAME_A                      = PT_STRING8+ $3A470000;

 PR_SPOUSE_NAME                              = PT_TSTRING+ $3A480000;
 PR_SPOUSE_NAME_W                            = PT_UNICODE+ $3A480000;
 PR_SPOUSE_NAME_A                            = PT_STRING8+ $3A480000;

 PR_COMPUTER_NETWORK_NAME                    = PT_TSTRING+ $3A490000;
 PR_COMPUTER_NETWORK_NAME_W                  = PT_UNICODE+ $3A490000;
 PR_COMPUTER_NETWORK_NAME_A                  = PT_STRING8+ $3A490000;

 PR_CUSTOMER_ID                              = PT_TSTRING+ $3A4A0000;
 PR_CUSTOMER_ID_W                            = PT_UNICODE+ $3A4A0000;
 PR_CUSTOMER_ID_A                            = PT_STRING8+ $3A4A0000;

 PR_TTYTDD_PHONE_NUMBER                      = PT_TSTRING+ $3A4B0000;
 PR_TTYTDD_PHONE_NUMBER_W                    = PT_UNICODE+ $3A4B0000;
 PR_TTYTDD_PHONE_NUMBER_A                    = PT_STRING8+ $3A4B0000;

 PR_FTP_SITE                                 = PT_TSTRING+ $3A4C0000;
 PR_FTP_SITE_W                               = PT_UNICODE+ $3A4C0000;
 PR_FTP_SITE_A                               = PT_STRING8+ $3A4C0000;

 PR_GENDER                                   = PT_SHORT+ $3A4D0000;

 PR_MANAGER_NAME                             = PT_TSTRING+ $3A4E0000;
 PR_MANAGER_NAME_W                           = PT_UNICODE+ $3A4E0000;
 PR_MANAGER_NAME_A                           = PT_STRING8+ $3A4E0000;

 PR_NICKNAME                                 = PT_TSTRING+ $3A4F0000;
 PR_NICKNAME_W                               = PT_UNICODE+ $3A4F0000;
 PR_NICKNAME_A                               = PT_STRING8+ $3A4F0000;

 PR_PERSONAL_HOME_PAGE                       = PT_TSTRING+ $3A500000;
 PR_PERSONAL_HOME_PAGE_W                     = PT_UNICODE+ $3A500000;
 PR_PERSONAL_HOME_PAGE_A                     = PT_STRING8+ $3A500000;


 PR_BUSINESS_HOME_PAGE                       = PT_TSTRING+ $3A510000;
 PR_BUSINESS_HOME_PAGE_W                     = PT_UNICODE+ $3A510000;
 PR_BUSINESS_HOME_PAGE_A                     = PT_STRING8+ $3A510000;

 PR_CONTACT_VERSION                          = PT_CLSID+ $3A520000;
 PR_CONTACT_ENTRYIDS                         = PT_MV_BINARY+ $3A530000;

 PR_CONTACT_ADDRTYPES                        = PT_MV_TSTRING+ $3A540000;
 PR_CONTACT_ADDRTYPES_W                      = PT_MV_UNICODE+ $3A540000;
 PR_CONTACT_ADDRTYPES_A                      = PT_MV_STRING8+ $3A540000;

 PR_CONTACT_DEFAULT_ADDRESS_INDEX            = PT_LONG+ $3A550000;

 PR_CONTACT_EMAIL_ADDRESSES                  = PT_MV_TSTRING+ $3A560000;
 PR_CONTACT_EMAIL_ADDRESSES_W                = PT_MV_UNICODE+ $3A560000;
 PR_CONTACT_EMAIL_ADDRESSES_A                = PT_MV_STRING8+ $3A560000;

 PR_COMPANY_MAIN_PHONE_NUMBER                = PT_TSTRING+ $3A570000;
 PR_COMPANY_MAIN_PHONE_NUMBER_W              = PT_UNICODE+ $3A570000;
 PR_COMPANY_MAIN_PHONE_NUMBER_A              = PT_STRING8+ $3A570000;

 PR_CHILDRENS_NAMES                          = PT_MV_TSTRING+ $3A580000;
 PR_CHILDRENS_NAMES_W                        = PT_MV_UNICODE+ $3A580000;
 PR_CHILDRENS_NAMES_A                        = PT_MV_STRING8+ $3A580000;

 PR_HOME_ADDRESS_CITY                        = PT_TSTRING+ $3A590000;
 PR_HOME_ADDRESS_CITY_W                      = PT_UNICODE+ $3A590000;
 PR_HOME_ADDRESS_CITY_A                      = PT_STRING8+ $3A590000;

 PR_HOME_ADDRESS_COUNTRY                     = PT_TSTRING+ $3A5A0000;
 PR_HOME_ADDRESS_COUNTRY_W                   = PT_UNICODE+ $3A5A0000;
 PR_HOME_ADDRESS_COUNTRY_A                   = PT_STRING8+ $3A5A0000;

 PR_HOME_ADDRESS_POSTAL_CODE                 = PT_TSTRING+ $3A5B0000;
 PR_HOME_ADDRESS_POSTAL_CODE_W               = PT_UNICODE+ $3A5B0000;
 PR_HOME_ADDRESS_POSTAL_CODE_A               = PT_STRING8+ $3A5B0000;

 PR_HOME_ADDRESS_STATE_OR_PROVINCE           = PT_TSTRING+ $3A5C0000;
 PR_HOME_ADDRESS_STATE_OR_PROVINCE_W         = PT_UNICODE+ $3A5C0000;
 PR_HOME_ADDRESS_STATE_OR_PROVINCE_A         = PT_STRING8+ $3A5C0000;

 PR_HOME_ADDRESS_STREET                      = PT_TSTRING+ $3A5D0000;
 PR_HOME_ADDRESS_STREET_W                    = PT_UNICODE+ $3A5D0000;
 PR_HOME_ADDRESS_STREET_A                    = PT_STRING8+ $3A5D0000;

 PR_HOME_ADDRESS_POST_OFFICE_BOX             = PT_TSTRING+ $3A5E0000;
 PR_HOME_ADDRESS_POST_OFFICE_BOX_W           = PT_UNICODE+ $3A5E0000;
 PR_HOME_ADDRESS_POST_OFFICE_BOX_A           = PT_STRING8+ $3A5E0000;

 PR_OTHER_ADDRESS_CITY                       = PT_TSTRING+ $3A5F0000;
 PR_OTHER_ADDRESS_CITY_W                     = PT_UNICODE+ $3A5F0000;
 PR_OTHER_ADDRESS_CITY_A                     = PT_STRING8+ $3A5F0000;

 PR_OTHER_ADDRESS_COUNTRY                    = PT_TSTRING+ $3A600000;
 PR_OTHER_ADDRESS_COUNTRY_W                  = PT_UNICODE+ $3A600000;
 PR_OTHER_ADDRESS_COUNTRY_A                  = PT_STRING8+ $3A600000;

 PR_OTHER_ADDRESS_POSTAL_CODE                = PT_TSTRING+ $3A610000;
 PR_OTHER_ADDRESS_POSTAL_CODE_W              = PT_UNICODE+ $3A610000;
 PR_OTHER_ADDRESS_POSTAL_CODE_A              = PT_STRING8+ $3A610000;

 PR_OTHER_ADDRESS_STATE_OR_PROVINCE          = PT_TSTRING+ $3A620000;
 PR_OTHER_ADDRESS_STATE_OR_PROVINCE_W        = PT_UNICODE+ $3A620000;
 PR_OTHER_ADDRESS_STATE_OR_PROVINCE_A        = PT_STRING8+ $3A620000;

 PR_OTHER_ADDRESS_STREET                     = PT_TSTRING+ $3A630000;
 PR_OTHER_ADDRESS_STREET_W                   = PT_UNICODE+ $3A630000;
 PR_OTHER_ADDRESS_STREET_A                   = PT_STRING8+ $3A630000;

 PR_OTHER_ADDRESS_POST_OFFICE_BOX            = PT_TSTRING+ $3A640000;
 PR_OTHER_ADDRESS_POST_OFFICE_BOX_W          = PT_UNICODE+ $3A640000;
 PR_OTHER_ADDRESS_POST_OFFICE_BOX_A          = PT_STRING8+ $3A640000;


//
//  Profile section properties
//

 PR_STORE_PROVIDERS                          = PT_BINARY+    $3D000000;
 PR_AB_PROVIDERS                             = PT_BINARY+    $3D010000;
 PR_TRANSPORT_PROVIDERS                      = PT_BINARY+    $3D020000;

 PR_DEFAULT_PROFILE                          = PT_BOOLEAN+   $3D040000;
 PR_AB_SEARCH_PATH                           = PT_MV_BINARY+ $3D050000;
 PR_AB_DEFAULT_DIR                           = PT_BINARY+    $3D060000;
 PR_AB_DEFAULT_PAB                           = PT_BINARY+    $3D070000;

 PR_FILTERING_HOOKS                          = PT_BINARY+    $3D080000;
 PR_SERVICE_NAME                             = PT_TSTRING+   $3D090000;
 PR_SERVICE_NAME_W                           = PT_UNICODE+   $3D090000;
 PR_SERVICE_NAME_A                           = PT_STRING8+   $3D090000;
 PR_SERVICE_DLL_NAME                         = PT_TSTRING+   $3D0A0000;
 PR_SERVICE_DLL_NAME_W                       = PT_UNICODE+   $3D0A0000;
 PR_SERVICE_DLL_NAME_A                       = PT_STRING8+   $3D0A0000;
 PR_SERVICE_ENTRY_NAME                       = PT_STRING8+   $3D0B0000;
 PR_SERVICE_UID                              = PT_BINARY+    $3D0C0000;
 PR_SERVICE_EXTRA_UIDS                       = PT_BINARY+    $3D0D0000;
 PR_SERVICES                                 = PT_BINARY+    $3D0E0000;
 PR_SERVICE_SUPPORT_FILES                    = PT_MV_TSTRING+ $3D0F0000;
 PR_SERVICE_SUPPORT_FILES_W                  = PT_MV_UNICODE+ $3D0F0000;
 PR_SERVICE_SUPPORT_FILES_A                  = PT_MV_STRING8+ $3D0F0000;
 PR_SERVICE_DELETE_FILES                     = PT_MV_TSTRING+ $3D100000;
 PR_SERVICE_DELETE_FILES_W                   = PT_MV_UNICODE+ $3D100000;
 PR_SERVICE_DELETE_FILES_A                   = PT_MV_STRING8+ $3D100000;
 PR_AB_SEARCH_PATH_UPDATE                    = PT_BINARY+     $3D110000;
 PR_PROFILE_NAME                             = PT_TSTRING+   $3D120000;
 PR_PROFILE_NAME_A                           = PT_STRING8+   $3D120000;
 PR_PROFILE_NAME_W                           = PT_UNICODE+   $3D120000;

//
//  Status object properties
//

 PR_IDENTITY_DISPLAY                         = PT_TSTRING+   $3E000000;
 PR_IDENTITY_DISPLAY_W                       = PT_UNICODE+   $3E000000;
 PR_IDENTITY_DISPLAY_A                       = PT_STRING8+   $3E000000;
 PR_IDENTITY_ENTRYID                         = PT_BINARY+    $3E010000;
 PR_RESOURCE_METHODS                         = PT_LONG+      $3E020000;
 PR_RESOURCE_TYPE                            = PT_LONG+      $3E030000;
 PR_STATUS_CODE                              = PT_LONG+      $3E040000;
 PR_IDENTITY_SEARCH_KEY                      = PT_BINARY+    $3E050000;
 PR_OWN_STORE_ENTRYID                        = PT_BINARY+    $3E060000;
 PR_RESOURCE_PATH                            = PT_TSTRING+   $3E070000;
 PR_RESOURCE_PATH_W                          = PT_UNICODE+   $3E070000;
 PR_RESOURCE_PATH_A                          = PT_STRING8+   $3E070000;
 PR_STATUS_STRING                            = PT_TSTRING+   $3E080000;
 PR_STATUS_STRING_W                          = PT_UNICODE+   $3E080000;
 PR_STATUS_STRING_A                          = PT_STRING8+   $3E080000;
 PR_X400_DEFERRED_DELIVERY_CANCEL            = PT_BOOLEAN+   $3E090000;
 PR_HEADER_FOLDER_ENTRYID                    = PT_BINARY+    $3E0A0000;
 PR_REMOTE_PROGRESS                          = PT_LONG+      $3E0B0000;
 PR_REMOTE_PROGRESS_TEXT                     = PT_TSTRING+   $3E0C0000;
 PR_REMOTE_PROGRESS_TEXT_W                   = PT_UNICODE+   $3E0C0000;
 PR_REMOTE_PROGRESS_TEXT_A                   = PT_STRING8+   $3E0C0000;
 PR_REMOTE_VALIDATE_OK                       = PT_BOOLEAN+   $3E0D0000;

//
// Display table properties
//

 PR_CONTROL_FLAGS                            = PT_LONG+      $3F000000;
 PR_CONTROL_STRUCTURE                        = PT_BINARY+    $3F010000;
 PR_CONTROL_TYPE                             = PT_LONG+      $3F020000;
 PR_DELTAX                                   = PT_LONG+      $3F030000;
 PR_DELTAY                                   = PT_LONG+      $3F040000;
 PR_XPOS                                     = PT_LONG+      $3F050000;
 PR_YPOS                                     = PT_LONG+      $3F060000;
 PR_CONTROL_ID                               = PT_BINARY+    $3F070000;
 PR_INITIAL_DETAILS_PANE                     = PT_LONG+      $3F080000;

//
// Secure property id range
//

 PROP_ID_SECURE_MIN                          = $67F0;
 PROP_ID_SECURE_MAX                          = $67FF;

implementation

end.
