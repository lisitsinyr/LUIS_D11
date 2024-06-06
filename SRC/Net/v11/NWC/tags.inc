(****************************************************************************
*
* 1995 (C) Unpublished Copyright Novell, Inc. All Rights Reserved.
*
* No part of this file may be duplicated, revised, translated,
* localized or modified in any manner or compiled, linked or 
* uploaded or downloaded to or from any computer system without
* the prior written consent of Novell, Inc.
*
*****************************************************************************)


(*
 * $Source: I:SRC\LSP\OBJECTS/RCS/tags.h $
 * $Log:	tags.h $
 * Revision 1.12  96/08/12  13:53:40  clifwlkr
 * Added new tag define for the maximum units installed flag
 * 
 * Revision 1.11  96/01/18  10:20:41  clifwlkr
 * Added tags for the file server assign stuff
 * 
 * Revision 1.10  95/08/01  13:15:53  clifwlkr
 * Added NLS_LIC_NODAL_REUSE and NLS_LIC_USER_REUSE nls attributes
 * 
 * Revision 1.9  95/03/08  11:03:00  clifwlkr
 * Added internationalization and copyright information
 * 
 * Revision 1.8  95/03/07  12:49:20  clifwlkr
 * Added a tag for the activation key
 * 
 * Revision 1.7  95/02/09  15:50:29  clifwlkr
 * Added the tag size parameter to help avoid over-runs
 * 
 * Revision 1.6  94/11/23  14:04:25  clifwlkr
 * Added binary tag capability
 * 
 * Revision 1.5  94/10/27  13:17:17  clifwlkr
 * Added NLS specific tags
 * 
 * Revision 1.4  94/10/05  09:43:24  clifwlkr
 * Cleaned up memory creep, added additional policy tags, and generally debuged
 * 
 * Revision 1.3  94/09/08  17:05:47  clifwlkr
 * Added tags for the owner information and the assignments
 * 
 * Revision 1.2  94/08/31  20:07:18  clifwlkr
 * Added addtional new line at EOF
 * 
 * Revision 1.1  94/08/03  15:13:51  clifwlkr
 * Initial revision
 * 
 * $EndLog$
 *)


{$IFNDEF  NOVELL_NLS_TAGS_H }
    {$DEFINE NOVELL_NLS_TAGS_H}
    {$I lsapi.inc}
    {$DEFINE LS_LIC_TAG_NODE_LEN}
    Const LS_LIC_TAG_NODE_LEN = 8;
    Type
        LSLICTAGTTag = Record
            nodeID  :  Array[0..LS_LIC_TAG_NODE_LEN-1] Of nuint8;
            protocol  :   LS_ULONG ;
            timeInSecs  :   LS_ULONG ;
            milliSecs  :   LS_ULONG ;
        End;
        LS_LIC_TAG_T = LSLICTAGTTag;
    {$DEFINE LS_TCPIP_PROTOCOL}
    Const LS_TCPIP_PROTOCOL = 1;
    (* TC #define LS_TAG_SIZE ( LS_LIC_TAG_NODE_LEN + ( 3 * sizeof ( LS_ULONG ) ) )  *)
    {$IFNDEF  NOVELL_NLS_CERT_H }
        {$DEFINE LSAPI_CERTIFICATE_TAG}
        Const LSAPI_CERTIFICATE_TAG = 1;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSCertificateTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521927 , 100 };  *)
        {$DEFINE LSAPI_PUBLISHER_TAG}
        Const LSAPI_PUBLISHER_TAG = 2;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSPublisherTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521928 , 225 };  *)
        {$DEFINE LSAPI_PRODUCT_TAG}
        Const LSAPI_PRODUCT_TAG = 3;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSProductTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521929 , 59 };  *)
        {$DEFINE LSAPI_VERSION_TAG}
        Const LSAPI_VERSION_TAG = 4;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSVersionTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521929 , 983 };  *)
        {$DEFINE LSAPI_SECRETS_TAG}
        Const LSAPI_SECRETS_TAG = 5;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSSecretsTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521931 , 148 };  *)
        {$DEFINE LSAPI_INSTALLED_UNITS_TAG}
        Const LSAPI_INSTALLED_UNITS_TAG = 6;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSInstalledUnitsTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521932 , 316 };  *)
        {$DEFINE LSAPI_START_DATE_TAG}
        Const LSAPI_START_DATE_TAG = 7;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSStartDateTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521933 , 731 };  *)
        {$DEFINE LSAPI_EXP_DATE_TAG}
        Const LSAPI_EXP_DATE_TAG = 8;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSExpirationDateTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521934 , 25 };  *)
        {$DEFINE LSAPI_LICENSE_ID_TAG}
        Const LSAPI_LICENSE_ID_TAG = 9;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSLicenseIDTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521934 , 894 };  *)
        {$DEFINE LSAPI_DEFAULT_METERED_TAG}
        Const LSAPI_DEFAULT_METERED_TAG = 10;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSDefaultMeteredTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521936 , 74 };  *)
        {$DEFINE LSAPI_ASSIGN_REQUIRED_TAG}
        Const LSAPI_ASSIGN_REQUIRED_TAG = 11;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSAssignmentRequiredTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521937 , 327 };  *)
        {$DEFINE LSAPI_SYSTEM_AREA_TAG}
        Const LSAPI_SYSTEM_AREA_TAG = 12;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSSystemAreaTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521945 , 472 };  *)
        {$DEFINE LSAPI_DEFAULT_UPDATE_TAG}
        Const LSAPI_DEFAULT_UPDATE_TAG = 13;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSDefaultUpdateTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521946 , 372 };  *)
        {$DEFINE LSAPI_DEF_UNITS_TO_CONSUME_TAG}
        Const LSAPI_DEF_UNITS_TO_CONSUME_TAG = 14;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSDefaultUnitsTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521948 , 193 };  *)
        {$DEFINE NLS_USER_INFO}
        Const NLS_USER_INFO = 20;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T NLSUserInfoTag =  *)
        (* TC  { { 137 , 65 , 21 , 75 } , LS_TCPIP_PROTOCOL , 785521983 , 491 };  *)
        {$DEFINE NLS_OWNER}
        Const NLS_OWNER = 25;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T NLSOwnerTag =  *)
        (* TC  { { 137 , 65 , 21 , 75 } , LS_TCPIP_PROTOCOL , 785521987 , 852 };  *)
        {$DEFINE NLS_ASSIGNMENT}
        Const NLS_ASSIGNMENT = 30;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T NLSAssignmentTag =  *)
        (* TC  { { 137 , 65 , 21 , 75 } , LS_TCPIP_PROTOCOL , 785521993 , 467 };  *)
        {$DEFINE NLS_FS_ASSIGNMENT}
        Const NLS_FS_ASSIGNMENT = 31;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T NLSFSAssignmentTag =  *)
        (* TC  { { 137 , 65 , 21 , 75 } , LS_TCPIP_PROTOCOL , 785522032 , 310 };  *)
        {$DEFINE NLS_ACTIVATION_KEY}
        Const NLS_ACTIVATION_KEY = 35;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T NLSActivationKeyTag =  *)
        (* TC  { { 137 , 65 , 21 , 75 } , LS_TCPIP_PROTOCOL , 785521993 , 567 };  *)
        {$DEFINE NLS_SYSTEM_AREA}
        Const NLS_SYSTEM_AREA = 40;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T NLSSystemAreaTag =  *)
        (* TC  { { 137 , 65 , 21 , 75 } , LS_TCPIP_PROTOCOL , 785522031 , 320 };  *)
        {$DEFINE NLS_LIC_CONSUMABLE}
        Const NLS_LIC_CONSUMABLE = 41;
        {$DEFINE NLS_LIC_SHAREABLE}
        Const NLS_LIC_SHAREABLE = 42;
        {$DEFINE NLS_LIC_PP_SECURED}
        Const NLS_LIC_PP_SECURED = 43;
        {$DEFINE NLS_LIC_HW_SECURED}
        Const NLS_LIC_HW_SECURED = 44;
        {$DEFINE NLS_LIC_MAX_UNITS_TO_CONSUME}
        Const NLS_LIC_MAX_UNITS_TO_CONSUME = 45;
        {$DEFINE NLS_LIC_MIN_UNITS_TO_CONSUME}
        Const NLS_LIC_MIN_UNITS_TO_CONSUME = 46;
        {$DEFINE NLS_LIC_NODAL_REUSE}
        Const NLS_LIC_NODAL_REUSE = 47;
        {$DEFINE NLS_LIC_USER_REUSE}
        Const NLS_LIC_USER_REUSE = 48;
        {$DEFINE NLS_FS_ASSIGN_REQ}
        Const NLS_FS_ASSIGN_REQ = 49;
        {$DEFINE NLS_ERR_INSUF_UNITS}
        Const NLS_ERR_INSUF_UNITS = 50;
        {$DEFINE NLS_ERR_LIC_TERM}
        Const NLS_ERR_LIC_TERM = 51;
        {$DEFINE NLS_ERR_LIC_UNAVAIL}
        Const NLS_ERR_LIC_UNAVAIL = 52;
        {$DEFINE NLS_ERR_RES_UNAVAIL}
        Const NLS_ERR_RES_UNAVAIL = 53;
        {$DEFINE NLS_ERR_LIC_EXPIRED}
        Const NLS_ERR_LIC_EXPIRED = 54;
        {$DEFINE NLS_LIC_MAX_UNITS_INSTALLED}
        Const NLS_LIC_MAX_UNITS_INSTALLED = 60;
        {$DEFINE NLS_LIC_CHECK_SUM}
        Const NLS_LIC_CHECK_SUM = 61;
        {$DEFINE NLS_STOP_POLICY}
        Const NLS_STOP_POLICY = 62;
        {$DEFINE NLS_POLICY_MODEL}
        Const NLS_POLICY_MODEL = 63;
        {$DEFINE NLS_DUP_INST_ALLOWED}
        Const NLS_DUP_INST_ALLOWED = 64;
        {$DEFINE NLS_TIME_BOMB}
        Const NLS_TIME_BOMB = 65;
        {$DEFINE NLS_OEM_ID}
        Const NLS_OEM_ID = 66;
    {$ELSE} {$IFDEF  NLS_INCL_TAGS }
        {$DEFINE LSAPI_CERTIFICATE_TAG}
        Const LSAPI_CERTIFICATE_TAG = 1;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSCertificateTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521927 , 100 };  *)
        {$DEFINE LSAPI_PUBLISHER_TAG}
        Const LSAPI_PUBLISHER_TAG = 2;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSPublisherTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521928 , 225 };  *)
        {$DEFINE LSAPI_PRODUCT_TAG}
        Const LSAPI_PRODUCT_TAG = 3;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSProductTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521929 , 59 };  *)
        {$DEFINE LSAPI_VERSION_TAG}
        Const LSAPI_VERSION_TAG = 4;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSVersionTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521929 , 983 };  *)
        {$DEFINE LSAPI_SECRETS_TAG}
        Const LSAPI_SECRETS_TAG = 5;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSSecretsTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521931 , 148 };  *)
        {$DEFINE LSAPI_INSTALLED_UNITS_TAG}
        Const LSAPI_INSTALLED_UNITS_TAG = 6;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSInstalledUnitsTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521932 , 316 };  *)
        {$DEFINE LSAPI_START_DATE_TAG}
        Const LSAPI_START_DATE_TAG = 7;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSStartDateTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521933 , 731 };  *)
        {$DEFINE LSAPI_EXP_DATE_TAG}
        Const LSAPI_EXP_DATE_TAG = 8;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSExpirationDateTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521934 , 25 };  *)
        {$DEFINE LSAPI_LICENSE_ID_TAG}
        Const LSAPI_LICENSE_ID_TAG = 9;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSLicenseIDTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521934 , 894 };  *)
        {$DEFINE LSAPI_DEFAULT_METERED_TAG}
        Const LSAPI_DEFAULT_METERED_TAG = 10;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSDefaultMeteredTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521936 , 74 };  *)
        {$DEFINE LSAPI_ASSIGN_REQUIRED_TAG}
        Const LSAPI_ASSIGN_REQUIRED_TAG = 11;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSAssignmentRequiredTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521937 , 327 };  *)
        {$DEFINE LSAPI_SYSTEM_AREA_TAG}
        Const LSAPI_SYSTEM_AREA_TAG = 12;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSSystemAreaTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521945 , 472 };  *)
        {$DEFINE LSAPI_DEFAULT_UPDATE_TAG}
        Const LSAPI_DEFAULT_UPDATE_TAG = 13;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSDefaultUpdateTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521946 , 372 };  *)
        {$DEFINE LSAPI_DEF_UNITS_TO_CONSUME_TAG}
        Const LSAPI_DEF_UNITS_TO_CONSUME_TAG = 14;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T LSDefaultUnitsTag =  *)
        (* TC  { { 137 , 65 , 21 , 73 } , LS_TCPIP_PROTOCOL , 785521948 , 193 };  *)
        {$DEFINE NLS_USER_INFO}
        Const NLS_USER_INFO = 20;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T NLSUserInfoTag =  *)
        (* TC  { { 137 , 65 , 21 , 75 } , LS_TCPIP_PROTOCOL , 785521983 , 491 };  *)
        {$DEFINE NLS_OWNER}
        Const NLS_OWNER = 25;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T NLSOwnerTag =  *)
        (* TC  { { 137 , 65 , 21 , 75 } , LS_TCPIP_PROTOCOL , 785521987 , 852 };  *)
        {$DEFINE NLS_ASSIGNMENT}
        Const NLS_ASSIGNMENT = 30;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T NLSAssignmentTag =  *)
        (* TC  { { 137 , 65 , 21 , 75 } , LS_TCPIP_PROTOCOL , 785521993 , 467 };  *)
        {$DEFINE NLS_FS_ASSIGNMENT}
        Const NLS_FS_ASSIGNMENT = 31;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T NLSFSAssignmentTag =  *)
        (* TC  { { 137 , 65 , 21 , 75 } , LS_TCPIP_PROTOCOL , 785522032 , 310 };  *)
        {$DEFINE NLS_ACTIVATION_KEY}
        Const NLS_ACTIVATION_KEY = 35;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T NLSActivationKeyTag =  *)
        (* TC  { { 137 , 65 , 21 , 75 } , LS_TCPIP_PROTOCOL , 785521993 , 567 };  *)
        {$DEFINE NLS_SYSTEM_AREA}
        Const NLS_SYSTEM_AREA = 40;
        (* TC  const  *)
        (* TC  LS_LIC_TAG_T NLSSystemAreaTag =  *)
        (* TC  { { 137 , 65 , 21 , 75 } , LS_TCPIP_PROTOCOL , 785522031 , 320 };  *)
        {$DEFINE NLS_LIC_CONSUMABLE}
        Const NLS_LIC_CONSUMABLE = 41;
        {$DEFINE NLS_LIC_SHAREABLE}
        Const NLS_LIC_SHAREABLE = 42;
        {$DEFINE NLS_LIC_PP_SECURED}
        Const NLS_LIC_PP_SECURED = 43;
        {$DEFINE NLS_LIC_HW_SECURED}
        Const NLS_LIC_HW_SECURED = 44;
        {$DEFINE NLS_LIC_MAX_UNITS_TO_CONSUME}
        Const NLS_LIC_MAX_UNITS_TO_CONSUME = 45;
        {$DEFINE NLS_LIC_MIN_UNITS_TO_CONSUME}
        Const NLS_LIC_MIN_UNITS_TO_CONSUME = 46;
        {$DEFINE NLS_LIC_NODAL_REUSE}
        Const NLS_LIC_NODAL_REUSE = 47;
        {$DEFINE NLS_LIC_USER_REUSE}
        Const NLS_LIC_USER_REUSE = 48;
        {$DEFINE NLS_FS_ASSIGN_REQ}
        Const NLS_FS_ASSIGN_REQ = 49;
        {$DEFINE NLS_ERR_INSUF_UNITS}
        Const NLS_ERR_INSUF_UNITS = 50;
        {$DEFINE NLS_ERR_LIC_TERM}
        Const NLS_ERR_LIC_TERM = 51;
        {$DEFINE NLS_ERR_LIC_UNAVAIL}
        Const NLS_ERR_LIC_UNAVAIL = 52;
        {$DEFINE NLS_ERR_RES_UNAVAIL}
        Const NLS_ERR_RES_UNAVAIL = 53;
        {$DEFINE NLS_ERR_LIC_EXPIRED}
        Const NLS_ERR_LIC_EXPIRED = 54;
        {$DEFINE NLS_LIC_MAX_UNITS_INSTALLED}
        Const NLS_LIC_MAX_UNITS_INSTALLED = 60;
        {$DEFINE NLS_LIC_CHECK_SUM}
        Const NLS_LIC_CHECK_SUM = 61;
        {$DEFINE NLS_STOP_POLICY}
        Const NLS_STOP_POLICY = 62;
        {$DEFINE NLS_POLICY_MODEL}
        Const NLS_POLICY_MODEL = 63;
        {$DEFINE NLS_DUP_INST_ALLOWED}
        Const NLS_DUP_INST_ALLOWED = 64;
        {$DEFINE NLS_TIME_BOMB}
        Const NLS_TIME_BOMB = 65;
        {$DEFINE NLS_OEM_ID}
        Const NLS_OEM_ID = 66;
    {$ELSE}
        (* TC extern C *)
    {$ENDIF}
    {$ENDIF}
{$ENDIF}


