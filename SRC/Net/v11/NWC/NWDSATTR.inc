(******************************************************************************

  %name: nwdsattr.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:06:53 1996 %
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

{$IFNDEF  NWDSATTR_H }
    {$DEFINE NWDSATTR_H}
    {$IFNDEF  NTYPES_H }
        {$I ntypes.inc}
    {$ENDIF}
    {$IFNDEF  NWDSTYPE_H }
        {$I nwdstype.inc}
    {$ENDIF}
    {$I npackon.inc}
    {$DEFINE TIME_BITMAP_LEN}
    Const TIME_BITMAP_LEN = 42;
    {$DEFINE NUM_POSTAL_ADDRESS_ELEMENTS}
    Const NUM_POSTAL_ADDRESS_ELEMENTS = 6;
    Type CE_String_T  =   pnstr8 ;
    Type Class_Name_T  =   pnstr8 ;
    Type CI_String_T  =   pnstr8 ;
    Type CN_String_T  =   pnstr8 ;
    Type DN_T  =   pnstr8 ;
    Type Integer_T  =   nint32 ;
    Type Boolean_T  =   nuint8 ;
    Type NU_String_T  =   pnstr8 ;
    Type Postal_Address_T  =  Array[0..NUM_POSTAL_ADDRESS_ELEMENTS-1] Of  pnstr8 ;
    Type PR_String_T  =   pnstr8 ;
    Type Secure_Name_T  =   pnstr8 ;
    Type TN_String_T  =   pnstr8 ;
    Type Counter_T  =   nuint32 ;
    Type
        Back_Link_T = Record
            remoteID  :   nuint32 ;
            objectName  :   pnstr8 ;
        End;
        pBack_Link_T = ^Back_Link_T;
    Type
        Bit_String_T = Record
            numOfBits  :   nuint32 ;
            data  :   pnuint8 ;
        End;
        pBit_String_T = ^Bit_String_T;
    Type
        pCI_List_T = ^_ci_list;
        _ci_list = Record
            next  :  pci_list_t;
            s  :   pnstr8 ;
        End;
        CI_List_T = _ci_list;
    Type
        Fax_Number_T = Record
            telephoneNumber  :   pnstr8 ;
            parameters  :   Bit_String_T ;
        End;
        pFax_Number_T = ^Fax_Number_T;
    Type
        Typed_Name_T = Record
            objectName  :   pnstr8 ;
            level  :   nuint32 ;
            interval  :   nuint32 ;
        End;
        pTyped_Name_T = ^Typed_Name_T;
    Type
        Net_Address_T = Record
            addressType  :   nuint32 ;
            addressLength  :   nuint32 ;
            address  :   pnuint8 ;
        End;
        pNet_Address_T = ^Net_Address_T;
    Type
        Object_ACL_T = Record
            protectedAttrName  :   pnstr8 ;
            subjectName  :   pnstr8 ;
            privileges  :   nuint32 ;
        End;
        pObject_ACL_T = ^Object_ACL_T;
    Type
        Octet_String_T = Record
            length  :   nuint32 ;
            data  :   pnuint8 ;
        End;
        pOctet_String_T = ^Octet_String_T;
    Type Stream_T  =   Octet_String_T ;
    Type pStream_T  =   pOctet_String_T ;
    Type
        pOctet_List_T = ^_octet_list;
        _octet_list = Record
            next  :  poctet_list_t;
            length  :   nuint32 ;
            data  :   pnuint8 ;
        End;
        Octet_List_T = _octet_list;
    Type
        Hold_T = Record
            objectName  :   pnstr8 ;
            amount  :   nuint32 ;
        End;
        pHold_T = ^Hold_T;
    Type
        Replica_Pointer_T = Record
            serverName  :   pnstr8 ;
            replicaType  :   nint32 ;
            replicaNumber  :   nint32 ;
            count  :   nuint32 ;
            replicaAddressHint  :  Array[0..0] Of  Net_Address_T ;
        End;
        pReplica_Pointer_T = ^Replica_Pointer_T;
    Type
        EMail_Address_T = Record
            type1  :   nuint32 ;
            address  :   pnstr8 ;
        End;
        pEMail_Address_T = ^EMail_Address_T;
    Type
        Path_T = Record
            nameSpaceType  :   nuint32 ;
            volumeName  :   pnstr8 ;
            path  :   pnstr8 ;
        End;
        pPath_T = ^Path_T;
    Type
        NWDS_TimeStamp_T = Record
            wholeSeconds  :   nuint32 ;
            eventID  :   nuint32 ;
        End;
        pNWDS_TimeStamp_T = ^NWDS_TimeStamp_T;
    Type
        TimeStamp_T = Record
            wholeSeconds  :   nuint32 ;
            replicaNum  :   nuint16 ;
            eventID  :   nuint16 ;
        End;
        pTimeStamp_T = ^TimeStamp_T;
    Type
        Unknown_Attr_T = Record
            attrName  :   pnstr8 ;
            syntaxID  :   nuint32 ;
            valueLen  :   nuint32 ;
            value  :   nptr ;
        End;
        pUnknown_Attr_T = ^Unknown_Attr_T;
    {$I npackoff.inc}
{$ENDIF}

