(******************************************************************************

  %name: nwapidef.h %
  %version: 5 %
  %date_modified: Thu Jan 16 15:50:00 1997 %
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


{$IFNDEF  NWAPIDEF_H }
    {$DEFINE NWAPIDEF_H}
    (* Miscellaneous string lengths (constant) *)
    (* NOTE: These max values include a byte for null  *)
    {$DEFINE NW_MAX_USER_NAME_LEN}
    Const NW_MAX_USER_NAME_LEN = 49;
    {$DEFINE NW_MAX_VOLUME_NAME_LEN}
    Const NW_MAX_VOLUME_NAME_LEN = 17;
    {$DEFINE NW_MAX_SERVER_NAME_LEN}
    Const NW_MAX_SERVER_NAME_LEN = 49;
    {$DEFINE NW_MAX_TREE_NAME_LEN}
    Const NW_MAX_TREE_NAME_LEN = 33;
    {$DEFINE NW_MAX_SERVICE_TYPE_LEN}
    Const NW_MAX_SERVICE_TYPE_LEN = 49;
    (* Miscellaneous unicode string sizes in bytes (constant) *)
     NW_MAX_USER_NAME_BYTES = 2 * NW_MAX_USER_NAME_LEN;
    NW_MAX_VOLUME_NAME_BYTES =2 * NW_MAX_VOLUME_NAME_LEN;
    NW_MAX_SERVER_NAME_BYTES =2 * NW_MAX_SERVER_NAME_LEN;
    NW_MAX_TREE_NAME_BYTES =2 * NW_MAX_TREE_NAME_LEN ;
    NW_MAX_SERVICE_TYPE_BYTES =2 * NW_MAX_SERVICE_TYPE_LEN ;
    (* PrintFlags (nuint16 value) *)
    {$DEFINE NW_PRINT_FLAG_RELEASE}
    Const NW_PRINT_FLAG_RELEASE = $0001;
    {$DEFINE NW_PRINT_FLAG_SUPPRESS_FF}
    Const NW_PRINT_FLAG_SUPPRESS_FF = $0002;
    {$DEFINE NW_PRINT_FLAG_TEXT_FILE}
    Const NW_PRINT_FLAG_TEXT_FILE = $0004;
    {$DEFINE NW_PRINT_FLAG_PRINT_BANNER}
    Const NW_PRINT_FLAG_PRINT_BANNER = $0008;
    {$DEFINE NW_PRINT_FLAG_NOTIFY}
    Const NW_PRINT_FLAG_NOTIFY = $0010;
    (* Print string lengths (constant) *)
    {$DEFINE NW_MAX_JOBDESCR_LEN}
    Const NW_MAX_JOBDESCR_LEN = 50;
    {$DEFINE NW_MAX_FORM_NAME_LEN}
    Const NW_MAX_FORM_NAME_LEN = 13;
    {$DEFINE NW_MAX_BANNER_NAME_LEN}
    Const NW_MAX_BANNER_NAME_LEN = 13;
    {$DEFINE NW_MAX_QUEUE_NAME_LEN}
    Const NW_MAX_QUEUE_NAME_LEN = 65;
    (* Client Types : these are returned by NWGetClientType *)
    {$DEFINE NW_NETX_SHELL}
    Const NW_NETX_SHELL = 1;
    {$DEFINE NW_VLM_REQ}
    Const NW_VLM_REQ = 2;
    {$DEFINE NW_CLIENT32}
    Const NW_CLIENT32 = 3;
    {$DEFINE NW_NT_REQ}
    Const NW_NT_REQ = 4;
    {$DEFINE NW_OS2_REQ}
    Const NW_OS2_REQ = 5;
    {$DEFINE NW_NLM_REQ}
    Const NW_NLM_REQ = 6;
{$ENDIF}

