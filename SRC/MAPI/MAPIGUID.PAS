{++

  m a p i g u i d . p a s

  Abstract:

    Automatic conversion of mapiguid.h.

  Comments:

    This source file automatically converted by
    htrans 0.91 beta 1 Copyright (c) 1997 Alexander Staubo

  Revision history:

    18-06-1997 20:53 alex  [Autogenerated]
    18-06-1997 20:53 alex  Retouched for release

--}

unit MapiGuid;

interface

uses
  Windows, SysUtils, ActiveX;

(*
 *  M A P I G U I D . H
 *
 *  Master definitions of all GUID's for MAPI.
 *
 *  When included without INITGUID defined, this header file
 *  defines symbols that reference IIDs elsewhere.
 *
 *  When included with INITGUID defined and a "USES_IID_I..."
 *  statement for each IID used by the subsystem, it generates the
 *  bytes for those actual IIDs into the associated object file.
 *
 *  This range of 256 GUIDs reserved by OLE for MAPI use October 5, 1992.
 *
 *  Copyright 1986-1996 Microsoft Corporation. All Rights Reserved.
 *)

(*
 *  List of GUIDS allocated by MAPI
 *  
 *  0x00020300  IID_IMAPISession
 *  0x00020301  IID_IMAPITable
 *  0x00020302  IID_IMAPIAdviseSink
 *  0x00020303  IID_IMAPIProp
 *  0x00020304  IID_IProfSect
 *  0x00020305  IID_IMAPIStatus
 *  0x00020306  IID_IMsgStore
 *  0x00020307  IID_IMessage
 *  0x00020308  IID_IAttachment
 *  0x00020309  IID_IAddrBook
 *  0x0002030A  IID_IMailUser
 *  0x0002030B  IID_IMAPIContainer
 *  0x0002030C  IID_IMAPIFolder
 *  0x0002030D  IID_IABContainer
 *  0x0002030E  IID_IDistList
 *  0x0002030F  IID_IMAPISup
 *  0x00020310  IID_IMSProvider
 *  0x00020311  IID_IABProvider
 *  0x00020312  IID_IXPProvider
 *  0x00020313  IID_IMSLogon
 *  0x00020314  IID_IABLogon
 *  0x00020315  IID_IXPLogon
 *  0x00020316  IID_IMAPITableData
 *  0x00020317  IID_IMAPISpoolerInit
 *  0x00020318  IID_IMAPISpoolerSession
 *  0x00020319  IID_ITNEF
 *  0x0002031A  IID_IMAPIPropData
 *  0x0002031B  IID_IMAPIControl
 *  0x0002031C  IID_IProfAdmin
 *  0x0002031D  IID_IMsgServiceAdmin
 *  0x0002031E  IID_IMAPISpoolerService
 *  0x0002031F  IID_IMAPIProgress
 *  0x00020320  IID_ISpoolerHook
 *  0x00020321  IID_IMAPIViewContext
 *  0x00020322  IID_IMAPIFormMgr
 *  0x00020323  IID_IEnumMAPIFormProp
 *  0x00020324  IID_IMAPIFormInfo
 *  0x00020325  IID_IProviderAdmin
 *  0x00020327  IID_IMAPIForm
 *  0x00020328  PS_MAPI
 *  0x00020329  PS_PUBLIC_STRINGS
 *  0x0002032A  IID_IPersistMessage
 *  0x0002032B  IID_IMAPIViewAdviseSink
 *  0x0002032C  IID_IStreamDocfile
 *  0x0002032D  IID_IMAPIFormProp
 *  0x0002032E  IID_IMAPIFormContainer
 *  0x0002032F  IID_IMAPIFormAdviseSink
 *  0x00020330  IID_IStreamTnef
 *  0x00020350  IID_IMAPIFormFactory
 *  0x00020370  IID_IMAPIMessageSite
 *  0x00020380  PS_ROUTING_EMAIL_ADDRESSES
 *  0x00020381  PS_ROUTING_ADDRTYPE
 *  0x00020382  PS_ROUTING_DISPLAY_NAME
 *  0x00020383  PS_ROUTING_ENTRYID
 *  0x00020384  PS_ROUTING_SEARCH_KEY
 *  0x00020385  MUID_PROFILE_INSTANCE
 *  
 *  The remaining GUIDs from 0x00020300 to 0x000203FF are reserved by
 *  MAPI for future use.  The current maximum used by MAPI is 0x00020385
 *
 *)


{$IFDEF INITGUID}

{$ENDIF}

{ Derive from IUnknown }
const
  IID_IMAPISession : TGUID = '{00020300-0000-0000-C000-000000000046}';
  strIID_IMAPISession = '{00020300-0000-0000-C000-000000000046}';
const
  IID_IMAPITable : TGUID = '{00020301-0000-0000-C000-000000000046}';
  strIID_IMAPITable = '{00020301-0000-0000-C000-000000000046}';
const
  IID_IMAPIAdviseSink : TGUID = '{00020302-0000-0000-C000-000000000046}';
  strIID_IMAPIAdviseSink = '{00020302-0000-0000-C000-000000000046}';
const
  IID_IMAPIControl : TGUID = '{0002031B-0000-0000-C000-000000000046}';
  strIID_IMAPIControl = '{0002031B-0000-0000-C000-000000000046}';
const
  IID_IProfAdmin : TGUID = '{0002031C-0000-0000-C000-000000000046}';
  strIID_IProfAdmin = '{0002031C-0000-0000-C000-000000000046}';
const
  IID_IMsgServiceAdmin : TGUID = '{0002031D-0000-0000-C000-000000000046}';
  strIID_IMsgServiceAdmin = '{0002031D-0000-0000-C000-000000000046}';
const
  IID_IProviderAdmin : TGUID = '{00020325-0000-0000-C000-000000000046}';
  strIID_IProviderAdmin = '{00020325-0000-0000-C000-000000000046}';
const
  IID_IMAPIProgress : TGUID = '{0002031F-0000-0000-C000-000000000046}';
  strIID_IMAPIProgress = '{0002031F-0000-0000-C000-000000000046}';
{ MAPIProp or derive from MAPIProp }
const
  IID_IMAPIProp : TGUID = '{00020303-0000-0000-C000-000000000046}';
  strIID_IMAPIProp = '{00020303-0000-0000-C000-000000000046}';
const
  IID_IProfSect : TGUID = '{00020304-0000-0000-C000-000000000046}';
  strIID_IProfSect = '{00020304-0000-0000-C000-000000000046}';
const
  IID_IMAPIStatus : TGUID = '{00020305-0000-0000-C000-000000000046}';
  strIID_IMAPIStatus = '{00020305-0000-0000-C000-000000000046}';
const
  IID_IMsgStore : TGUID = '{00020306-0000-0000-C000-000000000046}';
  strIID_IMsgStore = '{00020306-0000-0000-C000-000000000046}';
const
  IID_IMessage : TGUID = '{00020307-0000-0000-C000-000000000046}';
  strIID_IMessage = '{00020307-0000-0000-C000-000000000046}';
const
  IID_IAttachment : TGUID = '{00020308-0000-0000-C000-000000000046}';
  strIID_IAttachment = '{00020308-0000-0000-C000-000000000046}';
const
  IID_IAddrBook : TGUID = '{00020309-0000-0000-C000-000000000046}';
  strIID_IAddrBook = '{00020309-0000-0000-C000-000000000046}';
const
  IID_IMailUser : TGUID = '{0002030A-0000-0000-C000-000000000046}';
  strIID_IMailUser = '{0002030A-0000-0000-C000-000000000046}';
{ MAPIContainer or derive from MAPIContainer }
const
  IID_IMAPIContainer : TGUID = '{0002030B-0000-0000-C000-000000000046}';
  strIID_IMAPIContainer = '{0002030B-0000-0000-C000-000000000046}';
const
  IID_IMAPIFolder : TGUID = '{0002030C-0000-0000-C000-000000000046}';
  strIID_IMAPIFolder = '{0002030C-0000-0000-C000-000000000046}';
const
  IID_IABContainer : TGUID = '{0002030D-0000-0000-C000-000000000046}';
  strIID_IABContainer = '{0002030D-0000-0000-C000-000000000046}';
const
  IID_IDistList : TGUID = '{0002030E-0000-0000-C000-000000000046}';
  strIID_IDistList = '{0002030E-0000-0000-C000-000000000046}';
{ MAPI Support Object }
const
  IID_IMAPISup : TGUID = '{0002030F-0000-0000-C000-000000000046}';
  strIID_IMAPISup = '{0002030F-0000-0000-C000-000000000046}';
{ Provider INIT objects }
const
  IID_IMSProvider : TGUID = '{00020310-0000-0000-C000-000000000046}';
  strIID_IMSProvider = '{00020310-0000-0000-C000-000000000046}';
const
  IID_IABProvider : TGUID = '{00020311-0000-0000-C000-000000000046}';
  strIID_IABProvider = '{00020311-0000-0000-C000-000000000046}';
const
  IID_IXPProvider : TGUID = '{00020312-0000-0000-C000-000000000046}';
  strIID_IXPProvider = '{00020312-0000-0000-C000-000000000046}';
{ Provider LOGON Objects }
const
  IID_IMSLogon : TGUID = '{00020313-0000-0000-C000-000000000046}';
  strIID_IMSLogon = '{00020313-0000-0000-C000-000000000046}';
const
  IID_IABLogon : TGUID = '{00020314-0000-0000-C000-000000000046}';
  strIID_IABLogon = '{00020314-0000-0000-C000-000000000046}';
const
  IID_IXPLogon : TGUID = '{00020315-0000-0000-C000-000000000046}';
  strIID_IXPLogon = '{00020315-0000-0000-C000-000000000046}';
{ IMAPITable-in-memory Table Data Object }
const
  IID_IMAPITableData : TGUID = '{00020316-0000-0000-C000-000000000046}';
  strIID_IMAPITableData = '{00020316-0000-0000-C000-000000000046}';
{ MAPI Spooler Init Object (internal) }
const
  IID_IMAPISpoolerInit : TGUID = '{00020317-0000-0000-C000-000000000046}';
  strIID_IMAPISpoolerInit = '{00020317-0000-0000-C000-000000000046}';
{ MAPI Spooler Session Object (internal) }
const
  IID_IMAPISpoolerSession : TGUID = '{00020318-0000-0000-C000-000000000046}';
  strIID_IMAPISpoolerSession = '{00020318-0000-0000-C000-000000000046}';
{ MAPI TNEF Object Interface }
const
  IID_ITNEF : TGUID = '{00020319-0000-0000-C000-000000000046}';
  strIID_ITNEF = '{00020319-0000-0000-C000-000000000046}';
{ IMAPIProp-in-memory Property Data Object }
const
  IID_IMAPIPropData : TGUID = '{0002031A-0000-0000-C000-000000000046}';
  strIID_IMAPIPropData = '{0002031A-0000-0000-C000-000000000046}';
{ MAPI Spooler Hook Object }
const
  IID_ISpoolerHook : TGUID = '{00020320-0000-0000-C000-000000000046}';
  strIID_ISpoolerHook = '{00020320-0000-0000-C000-000000000046}';
{ MAPI Spooler Service Object }
const
  IID_IMAPISpoolerService : TGUID = '{0002031E-0000-0000-C000-000000000046}';
  strIID_IMAPISpoolerService = '{0002031E-0000-0000-C000-000000000046}';
{ MAPI forms, form manager, etc. }
const
  IID_IMAPIViewContext : TGUID = '{00020321-0000-0000-C000-000000000046}';
  strIID_IMAPIViewContext = '{00020321-0000-0000-C000-000000000046}';
const
  IID_IMAPIFormMgr : TGUID = '{00020322-0000-0000-C000-000000000046}';
  strIID_IMAPIFormMgr = '{00020322-0000-0000-C000-000000000046}';
const
  IID_IEnumMAPIFormProp : TGUID = '{00020323-0000-0000-C000-000000000046}';
  strIID_IEnumMAPIFormProp = '{00020323-0000-0000-C000-000000000046}';
const
  IID_IMAPIFormInfo : TGUID = '{00020324-0000-0000-C000-000000000046}';
  strIID_IMAPIFormInfo = '{00020324-0000-0000-C000-000000000046}';
const
  IID_IMAPIForm : TGUID = '{00020327-0000-0000-C000-000000000046}';
  strIID_IMAPIForm = '{00020327-0000-0000-C000-000000000046}';
{ Well known guids for name<->id mappings }

{  The name of MAPI's property set  }
const
  PS_MAPI : TGUID = '{00020328-0000-0000-C000-000000000046}';
  strPS_MAPI = '{00020328-0000-0000-C000-000000000046}';
{  The name of the set of public strings  }
const
  PS_PUBLIC_STRINGS : TGUID = '{00020329-0000-0000-C000-000000000046}';
  strPS_PUBLIC_STRINGS = '{00020329-0000-0000-C000-000000000046}';
{ MAPI forms, form manager, (cont) }
const
  IID_IPersistMessage : TGUID = '{0002032A-0000-0000-C000-000000000046}';
  strIID_IPersistMessage = '{0002032A-0000-0000-C000-000000000046}';
{ IMAPIViewAdviseSink }
const
  IID_IMAPIViewAdviseSink : TGUID = '{0002032B-0000-0000-C000-000000000046}';
  strIID_IMAPIViewAdviseSink = '{0002032B-0000-0000-C000-000000000046}';
{ Message Store OpenProperty }
const
  IID_IStreamDocfile : TGUID = '{0002032C-0000-0000-C000-000000000046}';
  strIID_IStreamDocfile = '{0002032C-0000-0000-C000-000000000046}';
{ IMAPIFormProp }
const
  IID_IMAPIFormProp : TGUID = '{0002032D-0000-0000-C000-000000000046}';
  strIID_IMAPIFormProp = '{0002032D-0000-0000-C000-000000000046}';
{ IMAPIFormContainer }
const
  IID_IMAPIFormContainer : TGUID = '{0002032E-0000-0000-C000-000000000046}';
  strIID_IMAPIFormContainer = '{0002032E-0000-0000-C000-000000000046}';
{ IMAPIFormAdviseSink }
const
  IID_IMAPIFormAdviseSink : TGUID = '{0002032F-0000-0000-C000-000000000046}';
  strIID_IMAPIFormAdviseSink = '{0002032F-0000-0000-C000-000000000046}';
{ TNEF OpenProperty }
const
  IID_IStreamTnef : TGUID = '{00020330-0000-0000-C000-000000000046}';
  strIID_IStreamTnef = '{00020330-0000-0000-C000-000000000046}';
{ IMAPIFormFactory }
const
  IID_IMAPIFormFactory : TGUID = '{00020350-0000-0000-C000-000000000046}';
  strIID_IMAPIFormFactory = '{00020350-0000-0000-C000-000000000046}';
{ IMAPIMessageSite }
const
  IID_IMAPIMessageSite : TGUID = '{00020370-0000-0000-C000-000000000046}';
  strIID_IMAPIMessageSite = '{00020370-0000-0000-C000-000000000046}';
{ Well known guids routing property sets.
   Usefull when writing applications that route documents
   (i.e. Workflow) across gateways.  Gateways that speak MAPI
   should convert the properties found in the follow property
   sets appropriately. }

{  PS_ROUTING_EMAIL_ADDRESSES:  Addresses that need converting at gateways, etc. }
const
  PS_ROUTING_EMAIL_ADDRESSES : TGUID = '{00020380-0000-0000-C000-000000000046}';
  strPS_ROUTING_EMAIL_ADDRESSES = '{00020380-0000-0000-C000-000000000046}';
{  PS_ROUTING_ADDRTYPE:  Address types that need converting at gateways, etc. }
const
  PS_ROUTING_ADDRTYPE : TGUID = '{00020381-0000-0000-C000-000000000046}';
  strPS_ROUTING_ADDRTYPE = '{00020381-0000-0000-C000-000000000046}';
{  PS_ROUTING_DISPLAY_NAME:  Display Name that corresponds to the other props }
const
  PS_ROUTING_DISPLAY_NAME : TGUID = '{00020382-0000-0000-C000-000000000046}';
  strPS_ROUTING_DISPLAY_NAME = '{00020382-0000-0000-C000-000000000046}';
{  PS_ROUTING_ENTRYID:  (optional) EntryIDs that need converting at gateways, etc. }
const
  PS_ROUTING_ENTRYID : TGUID = '{00020383-0000-0000-C000-000000000046}';
  strPS_ROUTING_ENTRYID = '{00020383-0000-0000-C000-000000000046}';
{  PS_ROUTING_SEARCH_KEY:  (optional) search keys that need converting at gateways, etc. }
const
  PS_ROUTING_SEARCH_KEY : TGUID = '{00020384-0000-0000-C000-000000000046}';
  strPS_ROUTING_SEARCH_KEY = '{00020384-0000-0000-C000-000000000046}';
{  MUID_PROFILE_INSTANCE
    Well known section in a profile which contains a property (PR_SEARCH_KEY) which is unique
    for any given profile.  Applications and providers can depend on this value as being
    different for each unique profile. }
const
  MUID_PROFILE_INSTANCE : TGUID = '{00020385-0000-0000-C000-000000000046}';
  strMUID_PROFILE_INSTANCE = '{00020385-0000-0000-C000-000000000046}';

implementation

end.

