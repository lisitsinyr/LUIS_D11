(******************************************************************************
  Source module name:  nwdsevnt.h
  Release Version:    

  %name: nwdsevnt.h %
  %version: 3 %
  %date_modified: Wed Dec 18 12:07:28 1996 %
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


{$IFNDEF _NWDSEVNT_HEADER_}

{$DEFINE _NWDSEVNT_HEADER_}

(*---------------------------------------------------------------------------
 * definitions and functions required to receive event reports
 *)

Const
EP_INLINE = 0;
EP_JOURNAL = 1;
EP_WORK = 2;
Type DSEventPriority = 0..2;


(*---------------------------------------------------------------------------
 * event types
 *)

{$DEFINE DSE_INVALID}
Const DSE_INVALID = 0;
{$DEFINE DSE_CREATE_ENTRY}
Const DSE_CREATE_ENTRY = 1;
{$DEFINE DSE_DELETE_ENTRY}
Const DSE_DELETE_ENTRY = 2;
{$DEFINE DSE_RENAME_ENTRY}
Const DSE_RENAME_ENTRY = 3;
{$DEFINE DSE_MOVE_SOURCE_ENTRY}
Const DSE_MOVE_SOURCE_ENTRY = 4;
{$DEFINE DSE_ADD_VALUE}
Const DSE_ADD_VALUE = 5;
{$DEFINE DSE_DELETE_VALUE}
Const DSE_DELETE_VALUE = 6;
{$DEFINE DSE_CLOSE_STREAM}
Const DSE_CLOSE_STREAM = 7;
{$DEFINE DSE_DELETE_ATTRIBUTE}
Const DSE_DELETE_ATTRIBUTE = 8;
{$DEFINE DSE_SET_BINDERY_CONTEXT}
Const DSE_SET_BINDERY_CONTEXT = 9;
{$DEFINE DSE_CREATE_BINDERY_OBJECT}
Const DSE_CREATE_BINDERY_OBJECT = 10;
{$DEFINE DSE_DELETE_BINDERY_OBJECT}
Const DSE_DELETE_BINDERY_OBJECT = 11;
{$DEFINE DSE_CHECK_SEV}
Const DSE_CHECK_SEV = 12;
{$DEFINE DSE_UPDATE_SEV}
Const DSE_UPDATE_SEV = 13;
{$DEFINE DSE_MOVE_DEST_ENTRY}
Const DSE_MOVE_DEST_ENTRY = 14;
{$DEFINE DSE_DELETE_UNUSED_EXTREF}
Const DSE_DELETE_UNUSED_EXTREF = 15;
{$DEFINE DSE_TRACE}
Const DSE_TRACE = 16;
{$DEFINE DSE_REMOTE_SERVER_DOWN}
Const DSE_REMOTE_SERVER_DOWN = 17;
{$DEFINE DSE_NCP_RETRY_EXPENDED}
Const DSE_NCP_RETRY_EXPENDED = 18;
{$DEFINE DSE_REMOTE_CONN_CLEARED}
Const DSE_REMOTE_CONN_CLEARED = 19;

(*---------------------------------------------------------------------------
 * data structures used for the data associated with events
 *)


Type
    DSETimeStamp = Record
        seconds  :   uint32 ;
        replicaNumber  :   uint16 ;
        event  :   uint16 ;
    End;


(* newDN used for DSE_MOVE_SOURCE_ENTRY and DSE_RENAME_ENTRY,
 * otherwise it is 0
 *)

Type
    DSEEntryInfo = Record
        perpetratorID  :   uint32 ;
        verb  :   uint32 ;
        entryID  :   uint32 ;
        parentID  :   uint32 ;
        classID  :   uint32 ;
        flags  :   uint32 ;
        creationTime  :   DSETimeStamp ;
        dn  :  ^const unicode;
        newDN  :  ^const unicode;
        data  :  Array[0..0] Of nint8;
    End;


(* DSEEntryInfo flag definitions *)

{$DEFINE DSEF_PARTITION_ROOT}
Const DSEF_PARTITION_ROOT = $0001;
{$DEFINE DSEF_EXTREF}
Const DSEF_EXTREF = $0002;
{$DEFINE DSEF_ALIAS}
Const DSEF_ALIAS = $0004;

Type
    DSEValueInfo = Record
        perpetratorID  :   uint32 ;
        verb  :   uint32 ;
        entryID  :   uint32 ;
        attrID  :   uint32 ;
        syntaxID  :   uint32 ;
        classID  :   uint32 ;
        timeStamp  :   DSETimeStamp ;
        size  :   unsigned ;
        data  :  Array[0..0] Of nint8;
    End;


Type
    DSEBinderyObjectInfo = Record
        entryID  :   uint32 ;
        parentID  :   uint32 ;
        type1  :   uint32 ;
        emuObjFlags  :   uint32 ;
        security  :   uint32 ;
        name  :  Array[0..47] Of nint8;
    End;


Type
    DSESEVInfo = Record
        entryID  :   uint32 ;
        retryCount  :   uint32 ;
        valueID  :   uint32 ;
        valueDN  :  Array[0..MAX_DN_CHARS+1-1] Of  unicode ;
        referral  :  Array[0..0] Of nint8;
    End;


Type
    DSETraceInfo = Record
        traceVector1  :   uint32 ;
        traceVector2  :   uint32 ;
        dstime  :   uint32 ;
        milliseconds  :   uint32 ;
        string1  :  Array[0..1023] Of nint8;
    End;


Type
    DSENetAddress = Record
        type1  :   uint32 ;
        length  :   uint32 ;
        data  :  Array[0..0] Of  uint8 ;
    End;


(*---------------------------------------------------------------------------
 * data structures used for contents of the data member of the
 * DSEValueInfo structure.
 *)


Type
    DSEPath = Record
        nameSpaceType  :   uint32 ;
        volumeEntryID  :   uint32 ;
        length  :   uint32 ;
        data  :  Array[0..0] Of  unicode ;
    End;


Type
    DSEReplicaPointer = Record
        serverID  :   uint32 ;
        type1  :   uint32 ;
        number  :   uint32 ;
        replicaRootID  :   uint32 ;
        referral  :  Array[0..0] Of nint8;
    End;


Type
    DSEBackLink = Record
        serverID  :   uint32 ;
        remoteID  :   uint32 ;
    End;


Type
    DSEACL = Record
        entryID  :   uint32 ;
        attrID  :   uint32 ;
        privileges  :   uint32 ;
    End;


Type
    DSETypedName = Record
        entryID  :   uint32 ;
        level  :   uint32 ;
        interval  :   uint32 ;
    End;


Type
    DSEHold = Record
        entryID  :   uint32 ;
        amount  :   uint32 ;
    End;


Type
    DSEEmailAddress = Record
        type1  :   uint32 ;
        length  :   uint32 ;
        address  :  Array[0..0] Of  unicode ;
    End;


Type
    DSEBitString = Record
        numOfBits  :   uint32 ;
        numOfBytes  :   uint32 ;
        data  :  nint8;
    End;


Type
    DSEFaxNumber = Record
        length  :   uint32 ;
        telephoneNumber  :  Array[0..0] Of  unicode ;
        (*   The following field is dword aligned after unicode NULL:
	DSEBitString	parameters;
	*)
    End;


Type
    DSECIList = Record
        numOfStrings  :   uint32 ;
        length1  :   uint32 ;
        string1  :  Array[0..0] Of  unicode ;
    End;


Type
    DSEOctetList = Record
        numOfStrings  :   uint32 ;
        string1  :  Array[0..0] Of  uint8 ;
    End;


Type string1  =  Array[0..0] Of  unicode ;  (* union statement *)
Type DSEValData = string1;


(*
 * End data structures used for contents of the data member of the
 * DSEValueInfo structure.
 *-------------------------------------------------------------------------*)


(* define trace vector category numbers *)

{$DEFINE TV_ON}
Const TV_ON = $00000001;
{$DEFINE TV_AUDIT}
Const TV_AUDIT = $00000002;
{$DEFINE TV_INIT}
Const TV_INIT = $00000004;
{$DEFINE TV_FRAGGER}
Const TV_FRAGGER = $00000008;
{$DEFINE TV_MISC}
Const TV_MISC = $00000010;
{$DEFINE TV_RESNAME}
Const TV_RESNAME = $00000020;
{$DEFINE TV_STREAMS}
Const TV_STREAMS = $00000040;
{$DEFINE TV_LIMBER}
Const TV_LIMBER = $00000080;
{$DEFINE TV_JANITOR}
Const TV_JANITOR = $00000100;
{$DEFINE TV_BACKLINK}
Const TV_BACKLINK = $00000200;
{$DEFINE TV_MERGE}
Const TV_MERGE = $00000400;
{$DEFINE TV_SKULKER}
Const TV_SKULKER = $00000800;
{$DEFINE TV_LOCKING}
Const TV_LOCKING = $00001000;
{$DEFINE TV_SAP}
Const TV_SAP = $00002000;
{$DEFINE TV_SCHEMA}
Const TV_SCHEMA = $00004000;
{$DEFINE TV_COLL}
Const TV_COLL = $00008000;
{$DEFINE TV_INSPECTOR}
Const TV_INSPECTOR = $00010000;
{$DEFINE TV_ERRORS}
Const TV_ERRORS = $00020000;
{$DEFINE TV_PART}
Const TV_PART = $00040000;
{$DEFINE TV_EMU}
Const TV_EMU = $00080000;
{$DEFINE TV_VCLIENT}
Const TV_VCLIENT = $00100000;
{$DEFINE TV_AUTHEN}
Const TV_AUTHEN = $00200000;
{$DEFINE TV_RECMAN}
Const TV_RECMAN = $00400000;
{$DEFINE TV_TIMEVECTOR}
Const TV_TIMEVECTOR = $00800000;
{$DEFINE TV_REPAIR}
Const TV_REPAIR = $01000000;
{$DEFINE TV_DSAGENT}
Const TV_DSAGENT = $02000000;
{$DEFINE TV_ERRET}
Const TV_ERRET = $04000000;
{$DEFINE TV_SYNC_IN}
Const TV_SYNC_IN = $08000000;
{$DEFINE TV_THREADS}
Const TV_THREADS = $10000000;
{$DEFINE TV_MIN}
Const TV_MIN = $20000000;
{$DEFINE TV_CHECK_BIT}
Const TV_CHECK_BIT = $80000000;
{$DEFINE TV_ALL}
Const TV_ALL = $BFFFFFFE;

(*===========================================================================*)


{$ENDIF}


