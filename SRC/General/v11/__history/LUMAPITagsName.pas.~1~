{=======================================================}
{ Project:                                              }
{         Delphi VCL Extensions (LU)                    }
{         Copyright (c) 2000 Central Bank Of Russia     }
{ Subject:                                              }
{         MAPITAGSNAME                                  }
{ Author:                                               }
{         Lisitsin Y.R.                                 }
{=======================================================}

unit LUMAPITagsName;

interface

uses LUMAPITags, StrUtils,
    LUStrUtils;

function GetPR_NAME(Value: Longint):string;

implementation

function GetPR_NAME(Value: Longint):string;
var
   s: string;
begin
   s := '';
   case Value of
      PR_ACKNOWLEDGEMENT_MODE                     : s:='ACKNOWLEDGEMENT_MODE';
      PR_ALTERNATE_RECIPIENT_ALLOWED              : s:='ALTERNATE_RECIPIENT_ALLOWED';
      PR_AUTHORIZING_USERS                        : s:='AUTHORIZING_USERS';
      PR_AUTO_FORWARD_COMMENT                     : s:='AUTO_FORWARD_COMMENT';
      PR_AUTO_FORWARD_COMMENT_W                   : s:='AUTO_FORWARD_COMMENT_W';
//      PR_AUTO_FORWARD_COMMENT_A                   : s:='AUTO_FORWARD_COMMENT_A';
      PR_AUTO_FORWARDED                           : s:='AUTO_FORWARDED';
      PR_CONTENT_CONFIDENTIALITY_ALGORITHM_ID     : s:='CONTENT_CONFIDENTIALITY_ALGORITHM_ID';
      PR_CONTENT_CORRELATOR                       : s:='CONTENT_CORRELATOR';
      PR_CONTENT_IDENTIFIER                       : s:='CONTENT_IDENTIFIER';
      PR_CONTENT_IDENTIFIER_W                     : s:='CONTENT_IDENTIFIER_W';
//      PR_CONTENT_IDENTIFIER_A                     : s:='CONTENT_IDENTIFIER_A';
      PR_CONTENT_LENGTH                           : s:='CONTENT_LENGTH';
      PR_CONTENT_RETURN_REQUESTED                 : s:='CONTENT_RETURN_REQUESTED';

      PR_CONVERSATION_KEY                         : s:='CONVERSATION_KEY';

      PR_CONVERSION_EITS                          : s:='CONVERSION_EITS';
      PR_CONVERSION_WITH_LOSS_PROHIBITED          : s:='CONVERSION_WITH_LOSS_PROHIBITED';
      PR_CONVERTED_EITS                           : s:='CONVERTED_EITS';
      PR_DEFERRED_DELIVERY_TIME                   : s:='DEFERRED_DELIVERY_TIME';
      PR_DELIVER_TIME                             : s:='DELIVER_TIME';
      PR_DISCARD_REASON                           : s:='DISCARD_REASON';
      PR_DISCLOSURE_OF_RECIPIENTS                 : s:='DISCLOSURE_OF_RECIPIENTS';
      PR_DL_EXPANSION_HISTORY                     : s:='DL_EXPANSION_HISTORY';
      PR_DL_EXPANSION_PROHIBITED                  : s:='DL_EXPANSION_PROHIBITED';
      PR_EXPIRY_TIME                              : s:='EXPIRY_TIME';
      PR_IMPLICIT_CONVERSION_PROHIBITED           : s:='IMPLICIT_CONVERSION_PROHIBITED';
      PR_IMPORTANCE                               : s:='IMPORTANCE';
      PR_IPM_ID                                   : s:='IPM_ID';
      PR_LATEST_DELIVERY_TIME                     : s:='LATEST_DELIVERY_TIME';
      PR_MESSAGE_CLASS                            : s:='MESSAGE_CLASS';
      PR_MESSAGE_CLASS_W                          : s:='MESSAGE_CLASS_W';
//      PR_MESSAGE_CLASS_A                          : s:='MESSAGE_CLASS_A';
      PR_MESSAGE_DELIVERY_ID                      : s:='MESSAGE_DELIVERY_ID';

      PR_MESSAGE_SECURITY_LABEL                   : s:='MESSAGE_SECURITY_LABEL';
      PR_OBSOLETED_IPMS                           : s:='OBSOLETED_IPMS';
      PR_ORIGINALLY_INTENDED_RECIPIENT_NAME       : s:='ORIGINALLY_INTENDED_RECIPIENT_NAME';
      PR_ORIGINAL_EITS                            : s:='ORIGINAL_EITS';
      PR_ORIGINATOR_CERTIFICATE                   : s:='ORIGINATOR_CERTIFICATE';
      PR_ORIGINATOR_DELIVERY_REPORT_REQUESTED     : s:='ORIGINATOR_DELIVERY_REPORT_REQUESTED';
      PR_ORIGINATOR_RETURN_ADDRESS                : s:='ORIGINATOR_RETURN_ADDRESS';

      PR_PARENT_KEY                               : s:='PARENT_KEY';
      PR_PRIORITY                                 : s:='PRIORITY';

      PR_ORIGIN_CHECK                             : s:='ORIGIN_CHECK';
      PR_PROOF_OF_SUBMISSION_REQUESTED            : s:='PROOF_OF_SUBMISSION_REQUESTED';
      PR_READ_RECEIPT_REQUESTED                   : s:='READ_RECEIPT_REQUESTED';
      PR_RECEIPT_TIME                             : s:='RECEIPT_TIME';
      PR_RECIPIENT_REASSIGNMENT_PROHIBITED        : s:='RECIPIENT_REASSIGNMENT_PROHIBITED';
      PR_REDIRECTION_HISTORY                      : s:='REDIRECTION_HISTORY';
      PR_RELATED_IPMS                             : s:='RELATED_IPMS';
      PR_ORIGINAL_SENSITIVITY                     : s:='ORIGINAL_SENSITIVITY';
      PR_LANGUAGES                                : s:='LANGUAGES';
      PR_LANGUAGES_W                              : s:='LANGUAGES_W';
//      PR_LANGUAGES_A                              : s:='LANGUAGES_A';
      PR_REPLY_TIME                               : s:='REPLY_TIME';
      PR_REPORT_TAG                               : s:='REPORT_TAG';
      PR_REPORT_TIME                              : s:='REPORT_TIME';
      PR_RETURNED_IPM                             : s:='RETURNED_IPM';
      PR_SECURITY                                 : s:='SECURITY';
      PR_INCOMPLETE_COPY                          : s:='INCOMPLETE_COPY';
      PR_SENSITIVITY                              : s:='SENSITIVITY';
      PR_SUBJECT                                  : s:='SUBJECT';
      PR_SUBJECT_W                                : s:='SUBJECT_W';
//      PR_SUBJECT_A                                : s:='SUBJECT_A';
      PR_SUBJECT_IPM                              : s:='SUBJECT_IPM';
      PR_CLIENT_SUBMIT_TIME                       : s:='CLIENT_SUBMIT_TIME';
      PR_REPORT_NAME                              : s:='REPORT_NAME';
      PR_REPORT_NAME_W                            : s:='REPORT_NAME_W';
//      PR_REPORT_NAME_A                            : s:='REPORT_NAME_A';
      PR_SENT_REPRESENTING_SEARCH_KEY             : s:='SENT_REPRESENTING_SEARCH_KEY';
      PR_X400_CONTENT_TYPE                        : s:='X400_CONTENT_TYPE';
      PR_SUBJECT_PREFIX                           : s:='SUBJECT_PREFIX';
      PR_SUBJECT_PREFIX_W                         : s:='SUBJECT_PREFIX_W';
//      PR_SUBJECT_PREFIX_A                         : s:='SUBJECT_PREFIX_A';
      PR_NON_RECEIPT_REASON                       : s:='NON_RECEIPT_REASON';
      PR_RECEIVED_BY_ENTRYID                      : s:='RECEIVED_BY_ENTRYID';
      PR_RECEIVED_BY_NAME                         : s:='RECEIVED_BY_NAME';
      PR_RECEIVED_BY_NAME_W                       : s:='RECEIVED_BY_NAME_W';
//      PR_RECEIVED_BY_NAME_A                       : s:='RECEIVED_BY_NAME_A';
      PR_SENT_REPRESENTING_ENTRYID                : s:='SENT_REPRESENTING_ENTRYID';
      PR_SENT_REPRESENTING_NAME                   : s:='SENT_REPRESENTING_NAME';
      PR_SENT_REPRESENTING_NAME_W                 : s:='SENT_REPRESENTING_NAME_W';
//      PR_SENT_REPRESENTING_NAME_A                 : s:='SENT_REPRESENTING_NAME_A';
      PR_RCVD_REPRESENTING_ENTRYID                : s:='RCVD_REPRESENTING_ENTRYID';
      PR_RCVD_REPRESENTING_NAME                   : s:='RCVD_REPRESENTING_NAME';
      PR_RCVD_REPRESENTING_NAME_W                 : s:='RCVD_REPRESENTING_NAME_W';
//      PR_RCVD_REPRESENTING_NAME_A                 : s:='RCVD_REPRESENTING_NAME_A';
      PR_REPORT_ENTRYID                           : s:='REPORT_ENTRYID';
      PR_READ_RECEIPT_ENTRYID                     : s:='READ_RECEIPT_ENTRYID';
      PR_MESSAGE_SUBMISSION_ID                    : s:='MESSAGE_SUBMISSION_ID';
      PR_PROVIDER_SUBMIT_TIME                     : s:='PROVIDER_SUBMIT_TIME';
      PR_ORIGINAL_SUBJECT                         : s:='ORIGINAL_SUBJECT';
      PR_ORIGINAL_SUBJECT_W                       : s:='ORIGINAL_SUBJECT_W';
//      PR_ORIGINAL_SUBJECT_A                       : s:='ORIGINAL_SUBJECT_A';
      PR_DISC_VAL                                 : s:='DISC_VAL';
      PR_ORIG_MESSAGE_CLASS                       : s:='ORIG_MESSAGE_CLASS';
      PR_ORIG_MESSAGE_CLASS_W                     : s:='ORIG_MESSAGE_CLASS_W';
//      PR_ORIG_MESSAGE_CLASS_A                     : s:='ORIG_MESSAGE_CLASS_A';
      PR_ORIGINAL_AUTHOR_ENTRYID                  : s:='ORIGINAL_AUTHOR_ENTRYID';
      PR_ORIGINAL_AUTHOR_NAME                     : s:='ORIGINAL_AUTHOR_NAME';
      PR_ORIGINAL_AUTHOR_NAME_W                   : s:='ORIGINAL_AUTHOR_NAME_W';
//      PR_ORIGINAL_AUTHOR_NAME_A                   : s:='ORIGINAL_AUTHOR_NAME_A';
      PR_ORIGINAL_SUBMIT_TIME                     : s:='ORIGINAL_SUBMIT_TIME';
      PR_REPLY_RECIPIENT_ENTRIES                  : s:='REPLY_RECIPIENT_ENTRIES';
      PR_REPLY_RECIPIENT_NAMES                    : s:='REPLY_RECIPIENT_NAMES';
      PR_REPLY_RECIPIENT_NAMES_W                  : s:='REPLY_RECIPIENT_NAMES_W';
//      PR_REPLY_RECIPIENT_NAMES_A                  : s:='REPLY_RECIPIENT_NAMES_A';

      PR_RECEIVED_BY_SEARCH_KEY                   : s:='RECEIVED_BY_SEARCH_KEY';
      PR_RCVD_REPRESENTING_SEARCH_KEY             : s:='RCVD_REPRESENTING_SEARCH_KEY';
      PR_READ_RECEIPT_SEARCH_KEY                  : s:='READ_RECEIPT_SEARCH_KEY';
      PR_REPORT_SEARCH_KEY                        : s:='REPORT_SEARCH_KEY';
      PR_ORIGINAL_DELIVERY_TIME                   : s:='ORIGINAL_DELIVERY_TIME';
      PR_ORIGINAL_AUTHOR_SEARCH_KEY               : s:='ORIGINAL_AUTHOR_SEARCH_KEY';

      PR_MESSAGE_TO_ME                            : s:='MESSAGE_TO_ME';
      PR_MESSAGE_CC_ME                            : s:='MESSAGE_CC_ME';
      PR_MESSAGE_RECIP_ME                         : s:='MESSAGE_RECIP_ME';

      PR_ORIGINAL_SENDER_NAME                     : s:='ORIGINAL_SENDER_NAME';
      PR_ORIGINAL_SENDER_NAME_W                   : s:='ORIGINAL_SENDER_NAME_W';
//      PR_ORIGINAL_SENDER_NAME_A                   : s:='ORIGINAL_SENDER_NAME_A';
      PR_ORIGINAL_SENDER_ENTRYID                  : s:='ORIGINAL_SENDER_ENTRYID';
      PR_ORIGINAL_SENDER_SEARCH_KEY               : s:='ORIGINAL_SENDER_SEARCH_KEY';
      PR_ORIGINAL_SENT_REPRESENTING_NAME          : s:='ORIGINAL_SENT_REPRESENTING_NAME';
      PR_ORIGINAL_SENT_REPRESENTING_NAME_W        : s:='ORIGINAL_SENT_REPRESENTING_NAME_W';
//      PR_ORIGINAL_SENT_REPRESENTING_NAME_A        : s:='ORIGINAL_SENT_REPRESENTING_NAME_A';
      PR_ORIGINAL_SENT_REPRESENTING_ENTRYID       : s:='ORIGINAL_SENT_REPRESENTING_ENTRYID';
      PR_ORIGINAL_SENT_REPRESENTING_SEARCH_KEY    : s:='ORIGINAL_SENT_REPRESENTING_SEARCH_KEY';

      PR_START_DATE                               : s:='START_DATE';
      PR_END_DATE                                 : s:='END_DATE';
      PR_OWNER_APPT_ID                            : s:='OWNER_APPT_ID';
      PR_RESPONSE_REQUESTED                       : s:='RESPONSE_REQUESTED';

      PR_SENT_REPRESENTING_ADDRTYPE               : s:='SENT_REPRESENTING_ADDRTYPE';
      PR_SENT_REPRESENTING_ADDRTYPE_W             : s:='SENT_REPRESENTING_ADDRTYPE_W';
//      PR_SENT_REPRESENTING_ADDRTYPE_A             : s:='SENT_REPRESENTING_ADDRTYPE_A';
      PR_SENT_REPRESENTING_EMAIL_ADDRESS          : s:='SENT_REPRESENTING_EMAIL_ADDRESS';
      PR_SENT_REPRESENTING_EMAIL_ADDRESS_W        : s:='SENT_REPRESENTING_EMAIL_ADDRESS_W';
//      PR_SENT_REPRESENTING_EMAIL_ADDRESS_A        : s:='SENT_REPRESENTING_EMAIL_ADDRESS_A';

      PR_ORIGINAL_SENDER_ADDRTYPE                 : s:='ORIGINAL_SENDER_ADDRTYPE';
      PR_ORIGINAL_SENDER_ADDRTYPE_W               : s:='ORIGINAL_SENDER_ADDRTYPE_W';
//      PR_ORIGINAL_SENDER_ADDRTYPE_A               : s:='ORIGINAL_SENDER_ADDRTYPE_A';
      PR_ORIGINAL_SENDER_EMAIL_ADDRESS            : s:='ORIGINAL_SENDER_EMAIL_ADDRESS';
      PR_ORIGINAL_SENDER_EMAIL_ADDRESS_W          : s:='ORIGINAL_SENDER_EMAIL_ADDRESS_W';
//      PR_ORIGINAL_SENDER_EMAIL_ADDRESS_A          : s:='ORIGINAL_SENDER_EMAIL_ADDRESS_A';

      PR_ORIGINAL_SENT_REPRESENTING_ADDRTYPE      : s:='ORIGINAL_SENT_REPRESENTING_ADDRTYPE';
      PR_ORIGINAL_SENT_REPRESENTING_ADDRTYPE_W    : s:='ORIGINAL_SENT_REPRESENTING_ADDRTYPE_W';
//      PR_ORIGINAL_SENT_REPRESENTING_ADDRTYPE_A    : s:='ORIGINAL_SENT_REPRESENTING_ADDRTYPE_A';
      PR_ORIGINAL_SENT_REPRESENTING_EMAIL_ADDRESS : s:='ORIGINAL_SENT_REPRESENTING_EMAIL_ADDRESS';
      PR_ORIGINAL_SENT_REPRESENTING_EMAIL_ADDRESS_W : s:='ORIGINAL_SENT_REPRESENTING_EMAIL_ADDRESS_W';
//      PR_ORIGINAL_SENT_REPRESENTING_EMAIL_ADDRESS_A : s:='ORIGINAL_SENT_REPRESENTING_EMAIL_ADDRESS_A';

      PR_CONVERSATION_TOPIC                       : s:='CONVERSATION_TOPIC';
      PR_CONVERSATION_TOPIC_W                     : s:='CONVERSATION_TOPIC_W';
//      PR_CONVERSATION_TOPIC_A                     : s:='CONVERSATION_TOPIC_A';
      PR_CONVERSATION_INDEX                       : s:='CONVERSATION_INDEX';

      PR_ORIGINAL_DISPLAY_BCC                     : s:='ORIGINAL_DISPLAY_BCC';
      PR_ORIGINAL_DISPLAY_BCC_W                   : s:='ORIGINAL_DISPLAY_BCC_W';
//      PR_ORIGINAL_DISPLAY_BCC_A                   : s:='ORIGINAL_DISPLAY_BCC_A';
      PR_ORIGINAL_DISPLAY_CC                      : s:='ORIGINAL_DISPLAY_CC';
      PR_ORIGINAL_DISPLAY_CC_W                    : s:='ORIGINAL_DISPLAY_CC_W';
//      PR_ORIGINAL_DISPLAY_CC_A                    : s:='ORIGINAL_DISPLAY_CC_A';
      PR_ORIGINAL_DISPLAY_TO                      : s:='ORIGINAL_DISPLAY_TO';
      PR_ORIGINAL_DISPLAY_TO_W                    : s:='ORIGINAL_DISPLAY_TO_W';
//      PR_ORIGINAL_DISPLAY_TO_A                    : s:='ORIGINAL_DISPLAY_TO_A';

      PR_RECEIVED_BY_ADDRTYPE                     : s:='RECEIVED_BY_ADDRTYPE';
      PR_RECEIVED_BY_ADDRTYPE_W                   : s:='RECEIVED_BY_ADDRTYPE_W';
//      PR_RECEIVED_BY_ADDRTYPE_A                   : s:='RECEIVED_BY_ADDRTYPE_A';
      PR_RECEIVED_BY_EMAIL_ADDRESS                : s:='RECEIVED_BY_EMAIL_ADDRESS';
      PR_RECEIVED_BY_EMAIL_ADDRESS_W              : s:='RECEIVED_BY_EMAIL_ADDRESS_W';
//      PR_RECEIVED_BY_EMAIL_ADDRESS_A              : s:='RECEIVED_BY_EMAIL_ADDRESS_A';

      PR_RCVD_REPRESENTING_ADDRTYPE               : s:='RCVD_REPRESENTING_ADDRTYPE';
      PR_RCVD_REPRESENTING_ADDRTYPE_W             : s:='RCVD_REPRESENTING_ADDRTYPE_W';
//      PR_RCVD_REPRESENTING_ADDRTYPE_A             : s:='RCVD_REPRESENTING_ADDRTYPE_A';
      PR_RCVD_REPRESENTING_EMAIL_ADDRESS          : s:='RCVD_REPRESENTING_EMAIL_ADDRESS';
      PR_RCVD_REPRESENTING_EMAIL_ADDRESS_W        : s:='RCVD_REPRESENTING_EMAIL_ADDRESS_W';
//      PR_RCVD_REPRESENTING_EMAIL_ADDRESS_A        : s:='RCVD_REPRESENTING_EMAIL_ADDRESS_A';

      PR_ORIGINAL_AUTHOR_ADDRTYPE                 : s:='ORIGINAL_AUTHOR_ADDRTYPE';
      PR_ORIGINAL_AUTHOR_ADDRTYPE_W               : s:='ORIGINAL_AUTHOR_ADDRTYPE_W';
//      PR_ORIGINAL_AUTHOR_ADDRTYPE_A               : s:='ORIGINAL_AUTHOR_ADDRTYPE_A';
      PR_ORIGINAL_AUTHOR_EMAIL_ADDRESS            : s:='ORIGINAL_AUTHOR_EMAIL_ADDRESS';
      PR_ORIGINAL_AUTHOR_EMAIL_ADDRESS_W          : s:='ORIGINAL_AUTHOR_EMAIL_ADDRESS_W';
//      PR_ORIGINAL_AUTHOR_EMAIL_ADDRESS_A          : s:='ORIGINAL_AUTHOR_EMAIL_ADDRESS_A';

      PR_ORIGINALLY_INTENDED_RECIP_ADDRTYPE       : s:='ORIGINALLY_INTENDED_RECIP_ADDRTYPE';
      PR_ORIGINALLY_INTENDED_RECIP_ADDRTYPE_W     : s:='ORIGINALLY_INTENDED_RECIP_ADDRTYPE_W';
//      PR_ORIGINALLY_INTENDED_RECIP_ADDRTYPE_A     : s:='ORIGINALLY_INTENDED_RECIP_ADDRTYPE_A';
      PR_ORIGINALLY_INTENDED_RECIP_EMAIL_ADDRESS  : s:='ORIGINALLY_INTENDED_RECIP_EMAIL_ADDRESS';
      PR_ORIGINALLY_INTENDED_RECIP_EMAIL_ADDRESS_W: s:='ORIGINALLY_INTENDED_RECIP_EMAIL_ADDRESS_W';
//      PR_ORIGINALLY_INTENDED_RECIP_EMAIL_ADDRESS_A: s:='ORIGINALLY_INTENDED_RECIP_EMAIL_ADDRESS_A';

      PR_TRANSPORT_MESSAGE_HEADERS                : s:='TRANSPORT_MESSAGE_HEADERS';
      PR_TRANSPORT_MESSAGE_HEADERS_W              : s:='TRANSPORT_MESSAGE_HEADERS_W';
//      PR_TRANSPORT_MESSAGE_HEADERS_A              : s:='TRANSPORT_MESSAGE_HEADERS_A';

      PR_DELEGATION                               : s:='DELEGATION';

      PR_TNEF_CORRELATION_KEY                     : s:='TNEF_CORRELATION_KEY';

      PR_BODY                                     : s:='BODY';
      PR_BODY_W                                   : s:='BODY_W';
//      PR_BODY_A                                   : s:='BODY_A';
      PR_REPORT_TEXT                              : s:='REPORT_TEXT';
      PR_REPORT_TEXT_W                            : s:='REPORT_TEXT_W';
//      PR_REPORT_TEXT_A                            : s:='REPORT_TEXT_A';
      PR_ORIGINATOR_AND_DL_EXPANSION_HISTORY      : s:='ORIGINATOR_AND_DL_EXPANSION_HISTORY';
      PR_REPORTING_DL_NAME                        : s:='REPORTING_DL_NAME';
      PR_REPORTING_MTA_CERTIFICATE                : s:='REPORTING_MTA_CERTIFICATE';

      PR_RTF_SYNC_BODY_CRC                        : s:='RTF_SYNC_BODY_CRC';
      PR_RTF_SYNC_BODY_COUNT                      : s:='RTF_SYNC_BODY_COUNT';
      PR_RTF_SYNC_BODY_TAG                        : s:='RTF_SYNC_BODY_TAG';
      PR_RTF_SYNC_BODY_TAG_W                      : s:='RTF_SYNC_BODY_TAG_W';
//      PR_RTF_SYNC_BODY_TAG_A                      : s:='RTF_SYNC_BODY_TAG_A';
      PR_RTF_COMPRESSED                           : s:='RTF_COMPRESSED';
      PR_RTF_SYNC_PREFIX_COUNT                    : s:='RTF_SYNC_PREFIX_COUNT';
      PR_RTF_SYNC_TRAILING_COUNT                  : s:='RTF_SYNC_TRAILING_COUNT';
      PR_ORIGINALLY_INTENDED_RECIP_ENTRYID        : s:='ORIGINALLY_INTENDED_RECIP_ENTRYID';

      PR_CONTENT_INTEGRITY_CHECK                  : s:='CONTENT_INTEGRITY_CHECK';
      PR_EXPLICIT_CONVERSION                      : s:='EXPLICIT_CONVERSION';
      PR_IPM_RETURN_REQUESTED                     : s:='IPM_RETURN_REQUESTED';
      PR_MESSAGE_TOKEN                            : s:='MESSAGE_TOKEN';
      PR_NDR_REASON_CODE                          : s:='NDR_REASON_CODE';
      PR_NDR_DIAG_CODE                            : s:='NDR_DIAG_CODE';
      PR_NON_RECEIPT_NOTIFICATION_REQUESTED       : s:='NON_RECEIPT_NOTIFICATION_REQUESTED';
      PR_DELIVERY_POINT                           : s:='DELIVERY_POINT';

      PR_ORIGINATOR_NON_DELIVERY_REPORT_REQUESTED : s:='ORIGINATOR_NON_DELIVERY_REPORT_REQUESTED';
      PR_ORIGINATOR_REQUESTED_ALTERNATE_RECIPIENT : s:='ORIGINATOR_REQUESTED_ALTERNATE_RECIPIENT';
      PR_PHYSICAL_DELIVERY_BUREAU_FAX_DELIVERY    : s:='PHYSICAL_DELIVERY_BUREAU_FAX_DELIVERY';
      PR_PHYSICAL_DELIVERY_MODE                   : s:='PHYSICAL_DELIVERY_MODE';
      PR_PHYSICAL_DELIVERY_REPORT_REQUEST         : s:='PHYSICAL_DELIVERY_REPORT_REQUEST';
      PR_PHYSICAL_FORWARDING_ADDRESS              : s:='PHYSICAL_FORWARDING_ADDRESS';
      PR_PHYSICAL_FORWARDING_ADDRESS_REQUESTED    : s:='PHYSICAL_FORWARDING_ADDRESS_REQUESTED';
      PR_PHYSICAL_FORWARDING_PROHIBITED           : s:='PHYSICAL_FORWARDING_PROHIBITED';
      PR_PHYSICAL_RENDITION_ATTRIBUTES            : s:='PHYSICAL_RENDITION_ATTRIBUTES';
      PR_PROOF_OF_DELIVERY                        : s:='PROOF_OF_DELIVERY';
      PR_PROOF_OF_DELIVERY_REQUESTED              : s:='PROOF_OF_DELIVERY_REQUESTED';
      PR_RECIPIENT_CERTIFICATE                    : s:='RECIPIENT_CERTIFICATE';
      PR_RECIPIENT_NUMBER_FOR_ADVICE              : s:='RECIPIENT_NUMBER_FOR_ADVICE';
      PR_RECIPIENT_NUMBER_FOR_ADVICE_W            : s:='RECIPIENT_NUMBER_FOR_ADVICE_W';
//      PR_RECIPIENT_NUMBER_FOR_ADVICE_A            : s:='RECIPIENT_NUMBER_FOR_ADVICE_A';
      PR_RECIPIENT_TYPE                           : s:='RECIPIENT_TYPE';
      PR_REGISTERED_MAIL_TYPE                     : s:='REGISTERED_MAIL_TYPE';
      PR_REPLY_REQUESTED                          : s:='REPLY_REQUESTED';
      PR_REQUESTED_DELIVERY_METHOD                : s:='REQUESTED_DELIVERY_METHOD';
      PR_SENDER_ENTRYID                           : s:='SENDER_ENTRYID';
      PR_SENDER_NAME                              : s:='SENDER_NAME';
      PR_SENDER_NAME_W                            : s:='SENDER_NAME_W';
//      PR_SENDER_NAME_A                            : s:='SENDER_NAME_A';
      PR_SUPPLEMENTARY_INFO                       : s:='SUPPLEMENTARY_INFO';
      PR_SUPPLEMENTARY_INFO_W                     : s:='SUPPLEMENTARY_INFO_W';
//      PR_SUPPLEMENTARY_INFO_A                     : s:='SUPPLEMENTARY_INFO_A';
      PR_TYPE_OF_MTS_USER                         : s:='TYPE_OF_MTS_USER';
      PR_SENDER_SEARCH_KEY                        : s:='SENDER_SEARCH_KEY';
      PR_SENDER_ADDRTYPE                          : s:='SENDER_ADDRTYPE';
      PR_SENDER_ADDRTYPE_W                        : s:='SENDER_ADDRTYPE_W';
//      PR_SENDER_ADDRTYPE_A                        : s:='SENDER_ADDRTYPE_A';
      PR_SENDER_EMAIL_ADDRESS                     : s:='SENDER_EMAIL_ADDRESS';
      PR_SENDER_EMAIL_ADDRESS_W                   : s:='SENDER_EMAIL_ADDRESS_W';
//      PR_SENDER_EMAIL_ADDRESS_A                   : s:='SENDER_EMAIL_ADDRESS_A';

      PR_CURRENT_VERSION                          : s:='CURRENT_VERSION';
      PR_DELETE_AFTER_SUBMIT                      : s:='DELETE_AFTER_SUBMIT';
      PR_DISPLAY_BCC                              : s:='DISPLAY_BCC';
      PR_DISPLAY_BCC_W                            : s:='DISPLAY_BCC_W';
//      PR_DISPLAY_BCC_A                            : s:='DISPLAY_BCC_A';
      PR_DISPLAY_CC                               : s:='DISPLAY_CC';
      PR_DISPLAY_CC_W                             : s:='DISPLAY_CC_W';
//      PR_DISPLAY_CC_A                             : s:='DISPLAY_CC_A';
      PR_DISPLAY_TO                               : s:='DISPLAY_TO';
      PR_DISPLAY_TO_W                             : s:='DISPLAY_TO_W';
//      PR_DISPLAY_TO_A                             : s:='DISPLAY_TO_A';
      PR_PARENT_DISPLAY                           : s:='PARENT_DISPLAY';
      PR_PARENT_DISPLAY_W                         : s:='PARENT_DISPLAY_W';
//      PR_PARENT_DISPLAY_A                         : s:='PARENT_DISPLAY_A';
      PR_MESSAGE_DELIVERY_TIME                    : s:='MESSAGE_DELIVERY_TIME';
      PR_MESSAGE_FLAGS                            : s:='MESSAGE_FLAGS';
      PR_MESSAGE_SIZE                             : s:='MESSAGE_SIZE';
      PR_PARENT_ENTRYID                           : s:='PARENT_ENTRYID';
      PR_SENTMAIL_ENTRYID                         : s:='SENTMAIL_ENTRYID';
      PR_CORRELATE                                : s:='CORRELATE';
      PR_CORRELATE_MTSID                          : s:='CORRELATE_MTSID';
      PR_DISCRETE_VALUES                          : s:='DISCRETE_VALUES';
      PR_RESPONSIBILITY                           : s:='RESPONSIBILITY';
      PR_SPOOLER_STATUS                           : s:='SPOOLER_STATUS';
      PR_TRANSPORT_STATUS                         : s:='TRANSPORT_STATUS';
      PR_MESSAGE_RECIPIENTS                       : s:='MESSAGE_RECIPIENTS';
      PR_MESSAGE_ATTACHMENTS                      : s:='MESSAGE_ATTACHMENTS';
      PR_SUBMIT_FLAGS                             : s:='SUBMIT_FLAGS';
      PR_RECIPIENT_STATUS                         : s:='RECIPIENT_STATUS';
      PR_TRANSPORT_KEY                            : s:='TRANSPORT_KEY';
      PR_MSG_STATUS                               : s:='MSG_STATUS';
      PR_MESSAGE_DOWNLOAD_TIME                    : s:='MESSAGE_DOWNLOAD_TIME';
      PR_CREATION_VERSION                         : s:='CREATION_VERSION';
      PR_MODIFY_VERSION                           : s:='MODIFY_VERSION';
      PR_HASATTACH                                : s:='HASATTACH';
      PR_BODY_CRC                                 : s:='BODY_CRC';
      PR_NORMALIZED_SUBJECT                       : s:='NORMALIZED_SUBJECT';
      PR_NORMALIZED_SUBJECT_W                     : s:='NORMALIZED_SUBJECT_W';
//      PR_NORMALIZED_SUBJECT_A                     : s:='NORMALIZED_SUBJECT_A';
      PR_RTF_IN_SYNC                              : s:='RTF_IN_SYNC';
      PR_ATTACH_SIZE                              : s:='ATTACH_SIZE';
      PR_ATTACH_NUM                               : s:='ATTACH_NUM';
      PR_PREPROCESS                               : s:='PREPROCESS';

      PR_ORIGINATING_MTA_CERTIFICATE              : s:='ORIGINATING_MTA_CERTIFICATE';
      PR_PROOF_OF_SUBMISSION                      : s:='PROOF_OF_SUBMISSION';

      PR_ENTRYID                                  : s:='ENTRYID';
      PR_OBJECT_TYPE                              : s:='OBJECT_TYPE';
      PR_ICON                                     : s:='ICON';
      PR_MINI_ICON                                : s:='MINI_ICON';
      PR_STORE_ENTRYID                            : s:='STORE_ENTRYID';
      PR_STORE_RECORD_KEY                         : s:='STORE_RECORD_KEY';
      PR_RECORD_KEY                               : s:='RECORD_KEY';
      PR_MAPPING_SIGNATURE                        : s:='MAPPING_SIGNATURE';
      PR_ACCESS_LEVEL                             : s:='ACCESS_LEVEL';
      PR_INSTANCE_KEY                             : s:='INSTANCE_KEY';
      PR_ROW_TYPE                                 : s:='ROW_TYPE';
      PR_ACCESS                                   : s:='ACCESS';

      PR_ROWID                                    : s:='ROWID';
      PR_DISPLAY_NAME                             : s:='DISPLAY_NAME';
      PR_DISPLAY_NAME_W                           : s:='DISPLAY_NAME_W';
//      PR_DISPLAY_NAME_A                           : s:='DISPLAY_NAME_A';
      PR_ADDRTYPE                                 : s:='ADDRTYPE';
      PR_ADDRTYPE_W                               : s:='ADDRTYPE_W';
//      PR_ADDRTYPE_A                               : s:='ADDRTYPE_A';
      PR_EMAIL_ADDRESS                            : s:='EMAIL_ADDRESS';
      PR_EMAIL_ADDRESS_W                          : s:='EMAIL_ADDRESS_W';
//      PR_EMAIL_ADDRESS_A                          : s:='EMAIL_ADDRESS_A';
      PR_COMMENT                                  : s:='COMMENT';
      PR_COMMENT_W                                : s:='COMMENT_W';
//      PR_COMMENT_A                                : s:='COMMENT_A';
      PR_DEPTH                                    : s:='DEPTH';
      PR_PROVIDER_DISPLAY                         : s:='PROVIDER_DISPLAY';
      PR_PROVIDER_DISPLAY_W                       : s:='PROVIDER_DISPLAY_W';
//      PR_PROVIDER_DISPLAY_A                       : s:='PROVIDER_DISPLAY_A';
      PR_CREATION_TIME                            : s:='CREATION_TIME';
      PR_LAST_MODIFICATION_TIME                   : s:='LAST_MODIFICATION_TIME';
      PR_RESOURCE_FLAGS                           : s:='RESOURCE_FLAGS';
      PR_PROVIDER_DLL_NAME                        : s:='PROVIDER_DLL_NAME';
      PR_PROVIDER_DLL_NAME_W                      : s:='PROVIDER_DLL_NAME_W';
//      PR_PROVIDER_DLL_NAME_A                      : s:='PROVIDER_DLL_NAME_A';
      PR_SEARCH_KEY                               : s:='SEARCH_KEY';
      PR_PROVIDER_UID                             : s:='PROVIDER_UID';
      PR_PROVIDER_ORDINAL                         : s:='PROVIDER_ORDINAL';

      PR_FORM_VERSION                             : s:='FORM_VERSION';
      PR_FORM_VERSION_W                           : s:='FORM_VERSION_W';
//      PR_FORM_VERSION_A                           : s:='FORM_VERSION_A';
      PR_FORM_CLSID                               : s:='FORM_CLSID';
      PR_FORM_CONTACT_NAME                        : s:='FORM_CONTACT_NAME';
      PR_FORM_CONTACT_NAME_W                      : s:='FORM_CONTACT_NAME_W';
//      PR_FORM_CONTACT_NAME_A                      : s:='FORM_CONTACT_NAME_A';
      PR_FORM_CATEGORY                            : s:='FORM_CATEGORY';
      PR_FORM_CATEGORY_W                          : s:='FORM_CATEGORY_W';
//      PR_FORM_CATEGORY_A                          : s:='FORM_CATEGORY_A';
      PR_FORM_CATEGORY_SUB                        : s:='FORM_CATEGORY_SUB';
      PR_FORM_CATEGORY_SUB_W                      : s:='FORM_CATEGORY_SUB_W';
//      PR_FORM_CATEGORY_SUB_A                      : s:='FORM_CATEGORY_SUB_A';
      PR_FORM_HOST_MAP                            : s:='FORM_HOST_MAP';
      PR_FORM_HIDDEN                              : s:='FORM_HIDDEN';
      PR_FORM_DESIGNER_NAME                       : s:='FORM_DESIGNER_NAME';
      PR_FORM_DESIGNER_NAME_W                     : s:='FORM_DESIGNER_NAME_W';
//      PR_FORM_DESIGNER_NAME_A                     : s:='FORM_DESIGNER_NAME_A';
      PR_FORM_DESIGNER_GUID                       : s:='FORM_DESIGNER_GUID';
      PR_FORM_MESSAGE_BEHAVIOR                    : s:='FORM_MESSAGE_BEHAVIOR';

      PR_DEFAULT_STORE                            : s:='DEFAULT_STORE';
      PR_STORE_SUPPORT_MASK                       : s:='STORE_SUPPORT_MASK';
      PR_STORE_STATE                              : s:='STORE_STATE';

      PR_IPM_SUBTREE_SEARCH_KEY                   : s:='IPM_SUBTREE_SEARCH_KEY';
      PR_IPM_OUTBOX_SEARCH_KEY                    : s:='IPM_OUTBOX_SEARCH_KEY';
      PR_IPM_WASTEBASKET_SEARCH_KEY               : s:='IPM_WASTEBASKET_SEARCH_KEY';
      PR_IPM_SENTMAIL_SEARCH_KEY                  : s:='IPM_SENTMAIL_SEARCH_KEY';
      PR_MDB_PROVIDER                             : s:='MDB_PROVIDER';
      PR_RECEIVE_FOLDER_SETTINGS                  : s:='RECEIVE_FOLDER_SETTINGS';

      PR_VALID_FOLDER_MASK                        : s:='VALID_FOLDER_MASK';
      PR_IPM_SUBTREE_ENTRYID                      : s:='IPM_SUBTREE_ENTRYID';

      PR_IPM_OUTBOX_ENTRYID                       : s:='IPM_OUTBOX_ENTRYID';
      PR_IPM_WASTEBASKET_ENTRYID                  : s:='IPM_WASTEBASKET_ENTRYID';
      PR_IPM_SENTMAIL_ENTRYID                     : s:='IPM_SENTMAIL_ENTRYID';
      PR_VIEWS_ENTRYID                            : s:='VIEWS_ENTRYID';
      PR_COMMON_VIEWS_ENTRYID                     : s:='COMMON_VIEWS_ENTRYID';
      PR_FINDER_ENTRYID                           : s:='FINDER_ENTRYID';

      PR_CONTAINER_FLAGS                          : s:='CONTAINER_FLAGS';
      PR_FOLDER_TYPE                              : s:='FOLDER_TYPE';
      PR_CONTENT_COUNT                            : s:='CONTENT_COUNT';
      PR_CONTENT_UNREAD                           : s:='CONTENT_UNREAD';
      PR_CREATE_TEMPLATES                         : s:='CREATE_TEMPLATES';
      PR_DETAILS_TABLE                            : s:='DETAILS_TABLE';
      PR_SEARCH                                   : s:='SEARCH';
      PR_SELECTABLE                               : s:='SELECTABLE';
      PR_SUBFOLDERS                               : s:='SUBFOLDERS';
      PR_STATUS                                   : s:='STATUS';
      PR_ANR                                      : s:='ANR';
      PR_ANR_W                                    : s:='ANR_W';
//      PR_ANR_A                                    : s:='ANR_A';
      PR_CONTENTS_SORT_ORDER                      : s:='CONTENTS_SORT_ORDER';
      PR_CONTAINER_HIERARCHY                      : s:='CONTAINER_HIERARCHY';
      PR_CONTAINER_CONTENTS                       : s:='CONTAINER_CONTENTS';
      PR_FOLDER_ASSOCIATED_CONTENTS               : s:='FOLDER_ASSOCIATED_CONTENTS';
      PR_DEF_CREATE_DL                            : s:='DEF_CREATE_DL';
      PR_DEF_CREATE_MAILUSER                      : s:='DEF_CREATE_MAILUSER';
      PR_CONTAINER_CLASS                          : s:='CONTAINER_CLASS';
      PR_CONTAINER_CLASS_W                        : s:='CONTAINER_CLASS_W';
//      PR_CONTAINER_CLASS_A                        : s:='CONTAINER_CLASS_A';
      PR_CONTAINER_MODIFY_VERSION                 : s:='CONTAINER_MODIFY_VERSION';
      PR_AB_PROVIDER_ID                           : s:='AB_PROVIDER_ID';
      PR_DEFAULT_VIEW_ENTRYID                     : s:='DEFAULT_VIEW_ENTRYID';
      PR_ASSOC_CONTENT_COUNT                      : s:='ASSOC_CONTENT_COUNT';

      PR_ATTACHMENT_X400_PARAMETERS               : s:='ATTACHMENT_X400_PARAMETERS';
      PR_ATTACH_DATA_OBJ                          : s:='ATTACH_DATA_OBJ';
      PR_ATTACH_DATA_BIN                          : s:='ATTACH_DATA_BIN';
      PR_ATTACH_ENCODING                          : s:='ATTACH_ENCODING';
      PR_ATTACH_EXTENSION                         : s:='ATTACH_EXTENSION';
      PR_ATTACH_EXTENSION_W                       : s:='ATTACH_EXTENSION_W';
//      PR_ATTACH_EXTENSION_A                       : s:='ATTACH_EXTENSION_A';
      PR_ATTACH_FILENAME                          : s:='ATTACH_FILENAME';
      PR_ATTACH_FILENAME_W                        : s:='ATTACH_FILENAME_W';
//      PR_ATTACH_FILENAME_A                        : s:='ATTACH_FILENAME_A';
      PR_ATTACH_METHOD                            : s:='ATTACH_METHOD';
      PR_ATTACH_LONG_FILENAME                     : s:='ATTACH_LONG_FILENAME';
      PR_ATTACH_LONG_FILENAME_W                   : s:='ATTACH_LONG_FILENAME_W';
//      PR_ATTACH_LONG_FILENAME_A                   : s:='ATTACH_LONG_FILENAME_A';
      PR_ATTACH_PATHNAME                          : s:='ATTACH_PATHNAME';
      PR_ATTACH_PATHNAME_W                        : s:='ATTACH_PATHNAME_W';
//      PR_ATTACH_PATHNAME_A                        : s:='ATTACH_PATHNAME_A';
      PR_ATTACH_RENDERING                         : s:='ATTACH_RENDERING';
      PR_ATTACH_TAG                               : s:='ATTACH_TAG';
      PR_RENDERING_POSITION                       : s:='RENDERING_POSITION';
      PR_ATTACH_TRANSPORT_NAME                    : s:='ATTACH_TRANSPORT_NAME';
      PR_ATTACH_TRANSPORT_NAME_W                  : s:='ATTACH_TRANSPORT_NAME_W';
//      PR_ATTACH_TRANSPORT_NAME_A                  : s:='ATTACH_TRANSPORT_NAME_A';
      PR_ATTACH_LONG_PATHNAME                     : s:='ATTACH_LONG_PATHNAME';
      PR_ATTACH_LONG_PATHNAME_W                   : s:='ATTACH_LONG_PATHNAME_W';
//      PR_ATTACH_LONG_PATHNAME_A                   : s:='ATTACH_LONG_PATHNAME_A';
      PR_ATTACH_MIME_TAG                          : s:='ATTACH_MIME_TAG';
      PR_ATTACH_MIME_TAG_W                        : s:='ATTACH_MIME_TAG_W';
//      PR_ATTACH_MIME_TAG_A                        : s:='ATTACH_MIME_TAG_A';
      PR_ATTACH_ADDITIONAL_INFO                   : s:='ATTACH_ADDITIONAL_INFO';

      PR_DISPLAY_TYPE                             : s:='DISPLAY_TYPE';
      PR_TEMPLATEID                               : s:='TEMPLATEID';
      PR_PRIMARY_CAPABILITY                       : s:='PRIMARY_CAPABILITY';

      PR_7BIT_DISPLAY_NAME                        : s:='7BIT_DISPLAY_NAME';
      PR_ACCOUNT                                  : s:='ACCOUNT';
      PR_ACCOUNT_W                                : s:='ACCOUNT_W';
//      PR_ACCOUNT_A                                : s:='ACCOUNT_A';
      PR_ALTERNATE_RECIPIENT                      : s:='ALTERNATE_RECIPIENT';
      PR_CALLBACK_TELEPHONE_NUMBER                : s:='CALLBACK_TELEPHONE_NUMBER';
      PR_CALLBACK_TELEPHONE_NUMBER_W              : s:='CALLBACK_TELEPHONE_NUMBER_W';
//      PR_CALLBACK_TELEPHONE_NUMBER_A              : s:='CALLBACK_TELEPHONE_NUMBER_A';
      PR_CONVERSION_PROHIBITED                    : s:='CONVERSION_PROHIBITED';
      PR_DISCLOSE_RECIPIENTS                      : s:='DISCLOSE_RECIPIENTS';
      PR_GENERATION                               : s:='GENERATION';
      PR_GENERATION_W                             : s:='GENERATION_W';
//      PR_GENERATION_A                             : s:='GENERATION_A';
      PR_GIVEN_NAME                               : s:='GIVEN_NAME';
      PR_GIVEN_NAME_W                             : s:='GIVEN_NAME_W';
//      PR_GIVEN_NAME_A                             : s:='GIVEN_NAME_A';
      PR_GOVERNMENT_ID_NUMBER                     : s:='GOVERNMENT_ID_NUMBER';
      PR_GOVERNMENT_ID_NUMBER_W                   : s:='GOVERNMENT_ID_NUMBER_W';
//      PR_GOVERNMENT_ID_NUMBER_A                   : s:='GOVERNMENT_ID_NUMBER_A';
      PR_BUSINESS_TELEPHONE_NUMBER                : s:='BUSINESS_TELEPHONE_NUMBER';
      PR_BUSINESS_TELEPHONE_NUMBER_W              : s:='BUSINESS_TELEPHONE_NUMBER_W';
//      PR_BUSINESS_TELEPHONE_NUMBER_A              : s:='BUSINESS_TELEPHONE_NUMBER_A';
//      PR_OFFICE_TELEPHONE_NUMBER                  : s:='OFFICE_TELEPHONE_NUMBER';
//      PR_OFFICE_TELEPHONE_NUMBER_W                : s:='OFFICE_TELEPHONE_NUMBER_W';
//      PR_OFFICE_TELEPHONE_NUMBER_A                : s:='OFFICE_TELEPHONE_NUMBER_A';
      PR_HOME_TELEPHONE_NUMBER                    : s:='HOME_TELEPHONE_NUMBER';
      PR_HOME_TELEPHONE_NUMBER_W                  : s:='HOME_TELEPHONE_NUMBER_W';
//      PR_HOME_TELEPHONE_NUMBER_A                  : s:='HOME_TELEPHONE_NUMBER_A';
      PR_INITIALS                                 : s:='INITIALS';
      PR_INITIALS_W                               : s:='INITIALS_W';
//      PR_INITIALS_A                               : s:='INITIALS_A';
      PR_KEYWORD                                  : s:='KEYWORD';
      PR_KEYWORD_W                                : s:='KEYWORD_W';
//      PR_KEYWORD_A                                : s:='KEYWORD_A';
      PR_LANGUAGE                                 : s:='LANGUAGE';
      PR_LANGUAGE_W                               : s:='LANGUAGE_W';
//      PR_LANGUAGE_A                               : s:='LANGUAGE_A';
      PR_LOCATION                                 : s:='LOCATION';
      PR_LOCATION_W                               : s:='LOCATION_W';
//      PR_LOCATION_A                               : s:='LOCATION_A';
      PR_MAIL_PERMISSION                          : s:='MAIL_PERMISSION';
      PR_MHS_COMMON_NAME                          : s:='MHS_COMMON_NAME';
      PR_MHS_COMMON_NAME_W                        : s:='MHS_COMMON_NAME_W';
//      PR_MHS_COMMON_NAME_A                        : s:='MHS_COMMON_NAME_A';
      PR_ORGANIZATIONAL_ID_NUMBER                 : s:='ORGANIZATIONAL_ID_NUMBER';
      PR_ORGANIZATIONAL_ID_NUMBER_W               : s:='ORGANIZATIONAL_ID_NUMBER_W';
//      PR_ORGANIZATIONAL_ID_NUMBER_A               : s:='ORGANIZATIONAL_ID_NUMBER_A';
      PR_SURNAME                                  : s:='SURNAME';
      PR_SURNAME_W                                : s:='SURNAME_W';
//      PR_SURNAME_A                                : s:='SURNAME_A';
      PR_ORIGINAL_ENTRYID                         : s:='ORIGINAL_ENTRYID';
      PR_ORIGINAL_DISPLAY_NAME                    : s:='ORIGINAL_DISPLAY_NAME';
      PR_ORIGINAL_DISPLAY_NAME_W                  : s:='ORIGINAL_DISPLAY_NAME_W';
//      PR_ORIGINAL_DISPLAY_NAME_A                  : s:='ORIGINAL_DISPLAY_NAME_A';
      PR_ORIGINAL_SEARCH_KEY                      : s:='ORIGINAL_SEARCH_KEY';
      PR_POSTAL_ADDRESS                           : s:='POSTAL_ADDRESS';
      PR_POSTAL_ADDRESS_W                         : s:='POSTAL_ADDRESS_W';
//      PR_POSTAL_ADDRESS_A                         : s:='POSTAL_ADDRESS_A';
      PR_COMPANY_NAME                             : s:='COMPANY_NAME';
      PR_COMPANY_NAME_W                           : s:='COMPANY_NAME_W';
//      PR_COMPANY_NAME_A                           : s:='COMPANY_NAME_A';
      PR_TITLE                                    : s:='TITLE';
      PR_TITLE_W                                  : s:='TITLE_W';
//      PR_TITLE_A                                  : s:='TITLE_A';
      PR_DEPARTMENT_NAME                          : s:='DEPARTMENT_NAME';
      PR_DEPARTMENT_NAME_W                        : s:='DEPARTMENT_NAME_W';
//      PR_DEPARTMENT_NAME_A                        : s:='DEPARTMENT_NAME_A';
      PR_OFFICE_LOCATION                          : s:='OFFICE_LOCATION';
      PR_OFFICE_LOCATION_W                        : s:='OFFICE_LOCATION_W';
//      PR_OFFICE_LOCATION_A                        : s:='OFFICE_LOCATION_A';
      PR_PRIMARY_TELEPHONE_NUMBER                 : s:='PRIMARY_TELEPHONE_NUMBER';
      PR_PRIMARY_TELEPHONE_NUMBER_W               : s:='PRIMARY_TELEPHONE_NUMBER_W';
//      PR_PRIMARY_TELEPHONE_NUMBER_A               : s:='PRIMARY_TELEPHONE_NUMBER_A';
      PR_BUSINESS2_TELEPHONE_NUMBER               : s:='BUSINESS2_TELEPHONE_NUMBER';
      PR_BUSINESS2_TELEPHONE_NUMBER_W             : s:='BUSINESS2_TELEPHONE_NUMBER_W';
//      PR_BUSINESS2_TELEPHONE_NUMBER_A             : s:='BUSINESS2_TELEPHONE_NUMBER_A';
//      PR_OFFICE2_TELEPHONE_NUMBER                 : s:='OFFICE2_TELEPHONE_NUMBER';
//      PR_OFFICE2_TELEPHONE_NUMBER_W               : s:='OFFICE2_TELEPHONE_NUMBER_W';
//      PR_OFFICE2_TELEPHONE_NUMBER_A               : s:='OFFICE2_TELEPHONE_NUMBER_A';
      PR_MOBILE_TELEPHONE_NUMBER                  : s:='MOBILE_TELEPHONE_NUMBER';
      PR_MOBILE_TELEPHONE_NUMBER_W                : s:='MOBILE_TELEPHONE_NUMBER_W';
//      PR_MOBILE_TELEPHONE_NUMBER_A                : s:='MOBILE_TELEPHONE_NUMBER_A';
//      PR_CELLULAR_TELEPHONE_NUMBER                : s:='CELLULAR_TELEPHONE_NUMBER';
//      PR_CELLULAR_TELEPHONE_NUMBER_W              : s:='CELLULAR_TELEPHONE_NUMBER_W';
//      PR_CELLULAR_TELEPHONE_NUMBER_A              : s:='CELLULAR_TELEPHONE_NUMBER_A';
      PR_RADIO_TELEPHONE_NUMBER                   : s:='RADIO_TELEPHONE_NUMBER';
      PR_RADIO_TELEPHONE_NUMBER_W                 : s:='RADIO_TELEPHONE_NUMBER_W';
//      PR_RADIO_TELEPHONE_NUMBER_A                 : s:='RADIO_TELEPHONE_NUMBER_A';
      PR_CAR_TELEPHONE_NUMBER                     : s:='CAR_TELEPHONE_NUMBER';
      PR_CAR_TELEPHONE_NUMBER_W                   : s:='CAR_TELEPHONE_NUMBER_W';
//      PR_CAR_TELEPHONE_NUMBER_A                   : s:='CAR_TELEPHONE_NUMBER_A';
      PR_OTHER_TELEPHONE_NUMBER                   : s:='OTHER_TELEPHONE_NUMBER';
      PR_OTHER_TELEPHONE_NUMBER_W                 : s:='OTHER_TELEPHONE_NUMBER_W';
//      PR_OTHER_TELEPHONE_NUMBER_A                 : s:='OTHER_TELEPHONE_NUMBER_A';
      PR_TRANSMITABLE_DISPLAY_NAME                : s:='TRANSMITABLE_DISPLAY_NAME';
      PR_TRANSMITABLE_DISPLAY_NAME_W              : s:='TRANSMITABLE_DISPLAY_NAME_W';
//      PR_TRANSMITABLE_DISPLAY_NAME_A              : s:='TRANSMITABLE_DISPLAY_NAME_A';
      PR_PAGER_TELEPHONE_NUMBER                   : s:='PAGER_TELEPHONE_NUMBER';
      PR_PAGER_TELEPHONE_NUMBER_W                 : s:='PAGER_TELEPHONE_NUMBER_W';
//      PR_PAGER_TELEPHONE_NUMBER_A                 : s:='PAGER_TELEPHONE_NUMBER_A';
//      PR_BEEPER_TELEPHONE_NUMBER                  : s:='BEEPER_TELEPHONE_NUMBER';
//      PR_BEEPER_TELEPHONE_NUMBER_W                : s:='BEEPER_TELEPHONE_NUMBER_W';
//      PR_BEEPER_TELEPHONE_NUMBER_A                : s:='BEEPER_TELEPHONE_NUMBER_A';
      PR_USER_CERTIFICATE                         : s:='USER_CERTIFICATE';
      PR_PRIMARY_FAX_NUMBER                       : s:='PRIMARY_FAX_NUMBER';
      PR_PRIMARY_FAX_NUMBER_W                     : s:='PRIMARY_FAX_NUMBER_W';
//      PR_PRIMARY_FAX_NUMBER_A                     : s:='PRIMARY_FAX_NUMBER_A';
      PR_BUSINESS_FAX_NUMBER                      : s:='BUSINESS_FAX_NUMBER';
      PR_BUSINESS_FAX_NUMBER_W                    : s:='BUSINESS_FAX_NUMBER_W';
//      PR_BUSINESS_FAX_NUMBER_A                    : s:='BUSINESS_FAX_NUMBER_A';
      PR_HOME_FAX_NUMBER                          : s:='HOME_FAX_NUMBER';
      PR_HOME_FAX_NUMBER_W                        : s:='HOME_FAX_NUMBER_W';
//      PR_HOME_FAX_NUMBER_A                        : s:='HOME_FAX_NUMBER_A';
      PR_COUNTRY                                  : s:='COUNTRY';
      PR_COUNTRY_W                                : s:='COUNTRY_W';
//      PR_COUNTRY_A                                : s:='COUNTRY_A';
//      PR_BUSINESS_ADDRESS_COUNTRY                 : s:='BUSINESS_ADDRESS_COUNTRY';
//      PR_BUSINESS_ADDRESS_COUNTRY_W               : s:='BUSINESS_ADDRESS_COUNTRY_W';
//      PR_BUSINESS_ADDRESS_COUNTRY_A               : s:='BUSINESS_ADDRESS_COUNTRY_A';

      PR_LOCALITY                                 : s:='LOCALITY';
      PR_LOCALITY_W                               : s:='LOCALITY_W';
//      PR_LOCALITY_A                               : s:='LOCALITY_A';
//      PR_BUSINESS_ADDRESS_CITY                    : s:='BUSINESS_ADDRESS_CITY';
//      PR_BUSINESS_ADDRESS_CITY_W                  : s:='BUSINESS_ADDRESS_CITY_W';
//      PR_BUSINESS_ADDRESS_CITY_A                  : s:='BUSINESS_ADDRESS_CITY_A';

      PR_STATE_OR_PROVINCE                        : s:='STATE_OR_PROVINCE';
      PR_STATE_OR_PROVINCE_W                      : s:='STATE_OR_PROVINCE_W';
//      PR_STATE_OR_PROVINCE_A                      : s:='STATE_OR_PROVINCE_A';
//      PR_BUSINESS_ADDRESS_STATE_OR_PROVINCE       : s:='BUSINESS_ADDRESS_STATE_OR_PROVINCE';
//      PR_BUSINESS_ADDRESS_STATE_OR_PROVINCE_W     : s:='BUSINESS_ADDRESS_STATE_OR_PROVINCE_W';
//      PR_BUSINESS_ADDRESS_STATE_OR_PROVINCE_A     : s:='BUSINESS_ADDRESS_STATE_OR_PROVINCE_A';

      PR_STREET_ADDRESS                           : s:='STREET_ADDRESS';
      PR_STREET_ADDRESS_W                         : s:='STREET_ADDRESS_W';
//      PR_STREET_ADDRESS_A                         : s:='STREET_ADDRESS_A';
//      PR_BUSINESS_ADDRESS_STREET                  : s:='BUSINESS_ADDRESS_STREET';
//      PR_BUSINESS_ADDRESS_STREET_W                : s:='BUSINESS_ADDRESS_STREET_W';
//      PR_BUSINESS_ADDRESS_STREET_A                : s:='BUSINESS_ADDRESS_STREET_A';

      PR_POSTAL_CODE                              : s:='POSTAL_CODE';
      PR_POSTAL_CODE_W                            : s:='POSTAL_CODE_W';
//      PR_POSTAL_CODE_A                            : s:='POSTAL_CODE_A';
//      PR_BUSINESS_ADDRESS_POSTAL_CODE             : s:='BUSINESS_ADDRESS_POSTAL_CODE';
//      PR_BUSINESS_ADDRESS_POSTAL_CODE_W           : s:='BUSINESS_ADDRESS_POSTAL_CODE_W';
//      PR_BUSINESS_ADDRESS_POSTAL_CODE_A           : s:='BUSINESS_ADDRESS_POSTAL_CODE_A';

      PR_POST_OFFICE_BOX                          : s:='POST_OFFICE_BOX';
      PR_POST_OFFICE_BOX_W                        : s:='POST_OFFICE_BOX_W';
//      PR_POST_OFFICE_BOX_A                        : s:='POST_OFFICE_BOX_A';
//      PR_BUSINESS_ADDRESS_POST_OFFICE_BOX         : s:='BUSINESS_ADDRESS_POST_OFFICE_BOX';
//      PR_BUSINESS_ADDRESS_POST_OFFICE_BOX_W       : s:='BUSINESS_ADDRESS_POST_OFFICE_BOX_W';
//      PR_BUSINESS_ADDRESS_POST_OFFICE_BOX_A       : s:='BUSINESS_ADDRESS_POST_OFFICE_BOX_A';

      PR_TELEX_NUMBER                             : s:='TELEX_NUMBER';
      PR_TELEX_NUMBER_W                           : s:='TELEX_NUMBER_W';
//      PR_TELEX_NUMBER_A                           : s:='TELEX_NUMBER_A';
      PR_ISDN_NUMBER                              : s:='ISDN_NUMBER';
      PR_ISDN_NUMBER_W                            : s:='ISDN_NUMBER_W';
//      PR_ISDN_NUMBER_A                            : s:='ISDN_NUMBER_A';
      PR_ASSISTANT_TELEPHONE_NUMBER               : s:='ASSISTANT_TELEPHONE_NUMBER';
      PR_ASSISTANT_TELEPHONE_NUMBER_W             : s:='ASSISTANT_TELEPHONE_NUMBER_W';
//      PR_ASSISTANT_TELEPHONE_NUMBER_A             : s:='ASSISTANT_TELEPHONE_NUMBER_A';
      PR_HOME2_TELEPHONE_NUMBER                   : s:='HOME2_TELEPHONE_NUMBER';
      PR_HOME2_TELEPHONE_NUMBER_W                 : s:='HOME2_TELEPHONE_NUMBER_W';
//      PR_HOME2_TELEPHONE_NUMBER_A                 : s:='HOME2_TELEPHONE_NUMBER_A';
      PR_ASSISTANT                                : s:='ASSISTANT';
      PR_ASSISTANT_W                              : s:='ASSISTANT_W';
//      PR_ASSISTANT_A                              : s:='ASSISTANT_A';
      PR_SEND_RICH_INFO                           : s:='SEND_RICH_INFO';

      PR_WEDDING_ANNIVERSARY                      : s:='WEDDING_ANNIVERSARY';
      PR_BIRTHDAY                                 : s:='BIRTHDAY';

      PR_HOBBIES                                  : s:='HOBBIES';
      PR_HOBBIES_W                                : s:='HOBBIES_W';
//      PR_HOBBIES_A                                : s:='HOBBIES_A';

      PR_MIDDLE_NAME                              : s:='MIDDLE_NAME';
      PR_MIDDLE_NAME_W                            : s:='MIDDLE_NAME_W';
//      PR_MIDDLE_NAME_A                            : s:='MIDDLE_NAME_A';

      PR_DISPLAY_NAME_PREFIX                      : s:='DISPLAY_NAME_PREFIX';
      PR_DISPLAY_NAME_PREFIX_W                    : s:='DISPLAY_NAME_PREFIX_W';
//      PR_DISPLAY_NAME_PREFIX_A                    : s:='DISPLAY_NAME_PREFIX_A';

      PR_PROFESSION                               : s:='PROFESSION';
      PR_PROFESSION_W                             : s:='PROFESSION_W';
//      PR_PROFESSION_A                             : s:='PROFESSION_A';

      PR_PREFERRED_BY_NAME                        : s:='PREFERRED_BY_NAME';
      PR_PREFERRED_BY_NAME_W                      : s:='PREFERRED_BY_NAME_W';
//      PR_PREFERRED_BY_NAME_A                      : s:='PREFERRED_BY_NAME_A';

      PR_SPOUSE_NAME                              : s:='SPOUSE_NAME';
      PR_SPOUSE_NAME_W                            : s:='SPOUSE_NAME_W';
//      PR_SPOUSE_NAME_A                            : s:='SPOUSE_NAME_A';

      PR_COMPUTER_NETWORK_NAME                    : s:='COMPUTER_NETWORK_NAME';
      PR_COMPUTER_NETWORK_NAME_W                  : s:='COMPUTER_NETWORK_NAME_W';
//      PR_COMPUTER_NETWORK_NAME_A                  : s:='COMPUTER_NETWORK_NAME_A';

      PR_CUSTOMER_ID                              : s:='CUSTOMER_ID';
      PR_CUSTOMER_ID_W                            : s:='CUSTOMER_ID_W';
//      PR_CUSTOMER_ID_A                            : s:='CUSTOMER_ID_A';

      PR_TTYTDD_PHONE_NUMBER                      : s:='TTYTDD_PHONE_NUMBER';
      PR_TTYTDD_PHONE_NUMBER_W                    : s:='TTYTDD_PHONE_NUMBER_W';
//      PR_TTYTDD_PHONE_NUMBER_A                    : s:='TTYTDD_PHONE_NUMBER_A';

      PR_FTP_SITE                                 : s:='FTP_SITE';
      PR_FTP_SITE_W                               : s:='FTP_SITE_W';
//      PR_FTP_SITE_A                               : s:='FTP_SITE_A';

      PR_GENDER                                   : s:='GENDER';

      PR_MANAGER_NAME                             : s:='MANAGER_NAME';
      PR_MANAGER_NAME_W                           : s:='MANAGER_NAME_W';
//      PR_MANAGER_NAME_A                           : s:='MANAGER_NAME_A';

      PR_NICKNAME                                 : s:='NICKNAME';
      PR_NICKNAME_W                               : s:='NICKNAME_W';
//      PR_NICKNAME_A                               : s:='NICKNAME_A';

      PR_PERSONAL_HOME_PAGE                       : s:='PERSONAL_HOME_PAGE';
      PR_PERSONAL_HOME_PAGE_W                     : s:='PERSONAL_HOME_PAGE_W';
//      PR_PERSONAL_HOME_PAGE_A                     : s:='PERSONAL_HOME_PAGE_A';


      PR_BUSINESS_HOME_PAGE                       : s:='BUSINESS_HOME_PAGE';
      PR_BUSINESS_HOME_PAGE_W                     : s:='BUSINESS_HOME_PAGE_W';
//      PR_BUSINESS_HOME_PAGE_A                     : s:='BUSINESS_HOME_PAGE_A';

      PR_CONTACT_VERSION                          : s:='CONTACT_VERSION';
      PR_CONTACT_ENTRYIDS                         : s:='CONTACT_ENTRYIDS';

      PR_CONTACT_ADDRTYPES                        : s:='CONTACT_ADDRTYPES';
      PR_CONTACT_ADDRTYPES_W                      : s:='CONTACT_ADDRTYPES_W';
//      PR_CONTACT_ADDRTYPES_A                      : s:='CONTACT_ADDRTYPES_A';

      PR_CONTACT_DEFAULT_ADDRESS_INDEX            : s:='CONTACT_DEFAULT_ADDRESS_INDEX';

      PR_CONTACT_EMAIL_ADDRESSES                  : s:='CONTACT_EMAIL_ADDRESSES';
      PR_CONTACT_EMAIL_ADDRESSES_W                : s:='CONTACT_EMAIL_ADDRESSES_W';
//      PR_CONTACT_EMAIL_ADDRESSES_A                : s:='CONTACT_EMAIL_ADDRESSES_A';

      PR_COMPANY_MAIN_PHONE_NUMBER                : s:='COMPANY_MAIN_PHONE_NUMBER';
      PR_COMPANY_MAIN_PHONE_NUMBER_W              : s:='COMPANY_MAIN_PHONE_NUMBER_W';
//      PR_COMPANY_MAIN_PHONE_NUMBER_A              : s:='COMPANY_MAIN_PHONE_NUMBER_A';

      PR_CHILDRENS_NAMES                          : s:='CHILDRENS_NAMES';
      PR_CHILDRENS_NAMES_W                        : s:='CHILDRENS_NAMES_W';
//      PR_CHILDRENS_NAMES_A                        : s:='CHILDRENS_NAMES_A';

      PR_HOME_ADDRESS_CITY                        : s:='HOME_ADDRESS_CITY';
      PR_HOME_ADDRESS_CITY_W                      : s:='HOME_ADDRESS_CITY_W';
//      PR_HOME_ADDRESS_CITY_A                      : s:='HOME_ADDRESS_CITY_A';

      PR_HOME_ADDRESS_COUNTRY                     : s:='HOME_ADDRESS_COUNTRY';
      PR_HOME_ADDRESS_COUNTRY_W                   : s:='HOME_ADDRESS_COUNTRY_W';
//      PR_HOME_ADDRESS_COUNTRY_A                   : s:='HOME_ADDRESS_COUNTRY_A';

      PR_HOME_ADDRESS_POSTAL_CODE                 : s:='HOME_ADDRESS_POSTAL_CODE';
      PR_HOME_ADDRESS_POSTAL_CODE_W               : s:='HOME_ADDRESS_POSTAL_CODE_W';
//      PR_HOME_ADDRESS_POSTAL_CODE_A               : s:='HOME_ADDRESS_POSTAL_CODE_A';

      PR_HOME_ADDRESS_STATE_OR_PROVINCE           : s:='HOME_ADDRESS_STATE_OR_PROVINCE';
      PR_HOME_ADDRESS_STATE_OR_PROVINCE_W         : s:='HOME_ADDRESS_STATE_OR_PROVINCE_W';
//      PR_HOME_ADDRESS_STATE_OR_PROVINCE_A         : s:='HOME_ADDRESS_STATE_OR_PROVINCE_A';

      PR_HOME_ADDRESS_STREET                      : s:='HOME_ADDRESS_STREET';
      PR_HOME_ADDRESS_STREET_W                    : s:='HOME_ADDRESS_STREET_W';
//      PR_HOME_ADDRESS_STREET_A                    : s:='HOME_ADDRESS_STREET_A';

      PR_HOME_ADDRESS_POST_OFFICE_BOX             : s:='HOME_ADDRESS_POST_OFFICE_BOX';
      PR_HOME_ADDRESS_POST_OFFICE_BOX_W           : s:='HOME_ADDRESS_POST_OFFICE_BOX_W';
//      PR_HOME_ADDRESS_POST_OFFICE_BOX_A           : s:='HOME_ADDRESS_POST_OFFICE_BOX_A';

      PR_OTHER_ADDRESS_CITY                       : s:='OTHER_ADDRESS_CITY';
      PR_OTHER_ADDRESS_CITY_W                     : s:='OTHER_ADDRESS_CITY_W';
//      PR_OTHER_ADDRESS_CITY_A                     : s:='OTHER_ADDRESS_CITY_A';

      PR_OTHER_ADDRESS_COUNTRY                    : s:='OTHER_ADDRESS_COUNTRY';
      PR_OTHER_ADDRESS_COUNTRY_W                  : s:='OTHER_ADDRESS_COUNTRY_W';
//      PR_OTHER_ADDRESS_COUNTRY_A                  : s:='OTHER_ADDRESS_COUNTRY_A';

      PR_OTHER_ADDRESS_POSTAL_CODE                : s:='OTHER_ADDRESS_POSTAL_CODE';
      PR_OTHER_ADDRESS_POSTAL_CODE_W              : s:='OTHER_ADDRESS_POSTAL_CODE_W';
//      PR_OTHER_ADDRESS_POSTAL_CODE_A              : s:='OTHER_ADDRESS_POSTAL_CODE_A';

      PR_OTHER_ADDRESS_STATE_OR_PROVINCE          : s:='OTHER_ADDRESS_STATE_OR_PROVINCE';
      PR_OTHER_ADDRESS_STATE_OR_PROVINCE_W        : s:='OTHER_ADDRESS_STATE_OR_PROVINCE_W';
//      PR_OTHER_ADDRESS_STATE_OR_PROVINCE_A        : s:='OTHER_ADDRESS_STATE_OR_PROVINCE_A';

      PR_OTHER_ADDRESS_STREET                     : s:='OTHER_ADDRESS_STREET';
      PR_OTHER_ADDRESS_STREET_W                   : s:='OTHER_ADDRESS_STREET_W';
//      PR_OTHER_ADDRESS_STREET_A                   : s:='OTHER_ADDRESS_STREET_A';

      PR_OTHER_ADDRESS_POST_OFFICE_BOX            : s:='OTHER_ADDRESS_POST_OFFICE_BOX';
      PR_OTHER_ADDRESS_POST_OFFICE_BOX_W          : s:='OTHER_ADDRESS_POST_OFFICE_BOX_W';
//      PR_OTHER_ADDRESS_POST_OFFICE_BOX_A          : s:='OTHER_ADDRESS_POST_OFFICE_BOX_A';

      PR_STORE_PROVIDERS                          : s:='STORE_PROVIDERS';
      PR_AB_PROVIDERS                             : s:='AB_PROVIDERS';
      PR_TRANSPORT_PROVIDERS                      : s:='TRANSPORT_PROVIDERS';

      PR_DEFAULT_PROFILE                          : s:='DEFAULT_PROFILE';
      PR_AB_SEARCH_PATH                           : s:='AB_SEARCH_PATH';
      PR_AB_DEFAULT_DIR                           : s:='AB_DEFAULT_DIR';
      PR_AB_DEFAULT_PAB                           : s:='AB_DEFAULT_PAB';

      PR_FILTERING_HOOKS                          : s:='FILTERING_HOOKS';
      PR_SERVICE_NAME                             : s:='SERVICE_NAME';
      PR_SERVICE_NAME_W                           : s:='SERVICE_NAME_W';
//      PR_SERVICE_NAME_A                           : s:='SERVICE_NAME_A';
      PR_SERVICE_DLL_NAME                         : s:='SERVICE_DLL_NAME';
      PR_SERVICE_DLL_NAME_W                       : s:='SERVICE_DLL_NAME_W';
//      PR_SERVICE_DLL_NAME_A                       : s:='SERVICE_DLL_NAME_A';
      PR_SERVICE_ENTRY_NAME                       : s:='SERVICE_ENTRY_NAME';
      PR_SERVICE_UID                              : s:='SERVICE_UID';
      PR_SERVICE_EXTRA_UIDS                       : s:='SERVICE_EXTRA_UIDS';
      PR_SERVICES                                 : s:='SERVICES';
      PR_SERVICE_SUPPORT_FILES                    : s:='SERVICE_SUPPORT_FILES';
      PR_SERVICE_SUPPORT_FILES_W                  : s:='SERVICE_SUPPORT_FILES_W';
//      PR_SERVICE_SUPPORT_FILES_A                  : s:='SERVICE_SUPPORT_FILES_A';
      PR_SERVICE_DELETE_FILES                     : s:='SERVICE_DELETE_FILES';
      PR_SERVICE_DELETE_FILES_W                   : s:='SERVICE_DELETE_FILES_W';
//      PR_SERVICE_DELETE_FILES_A                   : s:='SERVICE_DELETE_FILES_A';
      PR_AB_SEARCH_PATH_UPDATE                    : s:='AB_SEARCH_PATH_UPDATE';
      PR_PROFILE_NAME                             : s:='PROFILE_NAME';
//      PR_PROFILE_NAME_A                           : s:='PROFILE_NAME_A';
      PR_PROFILE_NAME_W                           : s:='PROFILE_NAME_W';

      PR_IDENTITY_DISPLAY                         : s:='IDENTITY_DISPLAY';
      PR_IDENTITY_DISPLAY_W                       : s:='IDENTITY_DISPLAY_W';
//      PR_IDENTITY_DISPLAY_A                       : s:='IDENTITY_DISPLAY_A';
      PR_IDENTITY_ENTRYID                         : s:='IDENTITY_ENTRYID';
      PR_RESOURCE_METHODS                         : s:='RESOURCE_METHODS';
      PR_RESOURCE_TYPE                            : s:='RESOURCE_TYPE';
      PR_STATUS_CODE                              : s:='STATUS_CODE';
      PR_IDENTITY_SEARCH_KEY                      : s:='IDENTITY_SEARCH_KEY';
      PR_OWN_STORE_ENTRYID                        : s:='OWN_STORE_ENTRYID';
      PR_RESOURCE_PATH                            : s:='RESOURCE_PATH';
      PR_RESOURCE_PATH_W                          : s:='RESOURCE_PATH_W';
//      PR_RESOURCE_PATH_A                          : s:='RESOURCE_PATH_A';
      PR_STATUS_STRING                            : s:='STATUS_STRING';
      PR_STATUS_STRING_W                          : s:='STATUS_STRING_W';
//      PR_STATUS_STRING_A                          : s:='STATUS_STRING_A';
      PR_X400_DEFERRED_DELIVERY_CANCEL            : s:='X400_DEFERRED_DELIVERY_CANCEL';
      PR_HEADER_FOLDER_ENTRYID                    : s:='HEADER_FOLDER_ENTRYID';
      PR_REMOTE_PROGRESS                          : s:='REMOTE_PROGRESS';
      PR_REMOTE_PROGRESS_TEXT                     : s:='REMOTE_PROGRESS_TEXT';
      PR_REMOTE_PROGRESS_TEXT_W                   : s:='REMOTE_PROGRESS_TEXT_W';
//      PR_REMOTE_PROGRESS_TEXT_A                   : s:='REMOTE_PROGRESS_TEXT_A';
      PR_REMOTE_VALIDATE_OK                       : s:='REMOTE_VALIDATE_OK';

      PR_CONTROL_FLAGS                            : s:='CONTROL_FLAGS';
      PR_CONTROL_STRUCTURE                        : s:='CONTROL_STRUCTURE';
      PR_CONTROL_TYPE                             : s:='CONTROL_TYPE';
      PR_DELTAX                                   : s:='DELTAX';
      PR_DELTAY                                   : s:='DELTAY';
      PR_XPOS                                     : s:='XPOS';
      PR_YPOS                                     : s:='YPOS';
      PR_CONTROL_ID                               : s:='CONTROL_ID';
      PR_INITIAL_DETAILS_PANE                     : s:='INITIAL_DETAILS_PANE';
   end;
   if s = '' then Result := D2H(Value, 8)
             else Result := 'PR_'+s;
end;

end.
