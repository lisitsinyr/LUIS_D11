{=======================================================}
{ Project:                                              }
{         Delphi VCL Extensions (LU)                    }
{         Copyright (c) 2000 Central Bank Of Russia     }
{ Subject:                                              }
{         Работа с библиотекой CDO                      }
{ Author:                                               }
{         Lisitsin Y.R.                                 }
{=======================================================}

unit LUMAPICDO;

interface

uses {Forms,}
     Classes, ComObj, SysUtils, MAPI, FileCtrl, Windows, StrUtils,
     Variants,
     LUMAPI, LUParser, LUMAPITags, LUMAPITagsName, LUSupport, LUObjects,
     LUStrUtils,
     LULog;

type

   { TCDOField }

   TCDOField = class(TObjects)
   private
      FFieldName: PChar;
      FID: Longint;
      FFieldType: Integer;
      FValue: Variant;
      function GetFieldName: string;
      procedure SetFieldName(const Value: string);
      procedure Clear;
   public
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      { Addresses }
      property FieldName: string read GetFieldName write SetFieldName;
      property FieldType: Integer read FFieldType write FFieldType;
      property Value: Variant read FValue write FValue;
      property ID: Longint read FID write FID;
   end;

   { TCDOMessageFilterItem }

   TCDOMessageFilterItem = class(TObjects)
   private
      FImportance: Longint;
      FAddress_ORIG: PChar;          { Sender }
      FSent: Boolean;
      F_Or: Boolean;
      F_Not: Boolean;
      FSize: Longint;
      FSubject: PChar;
      FRecipients: PChar;
      FNoteText: TStringList;
      FTimeFirst: Variant;
      FTimeLast: Variant;
      FUnread: Boolean;
      FTypeMessageFilter: PChar;
      function GetAddress_ORIG: string;
      procedure SetAddress_ORIG(const Value: string);
      function GetSubject: string;
      procedure SetSubject(const Value: string);
      function GetRecipients: string;
      procedure SetRecipients(const Value: string);
      function GetTypeMessageFilter: string;
      procedure SetTypeMessageFilter(const Value: string);
      procedure Clear;
   public
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      { sender }
      property Address_ORIG: string read GetAddress_ORIG write SetAddress_ORIG;
      { Subject }
      property Subject: string read GetSubject write SetSubject;
      { Text }
      property NoteText: TStringList read FNoteText;
      property Recipients: string read GetRecipients write SetRecipients;
      property TypeMessage: string read GetTypeMessageFilter write SetTypeMessageFilter;
      property Importance: Longint read FImportance write FImportance;
      property Sent: Boolean read FSent write FSent;
      property Size: Longint read FSize write FSize;
      property TimeFirst: Variant read FTimeFirst write FTimeFirst;
      property TimeLast: Variant read FTimeLast write FTimeLast;
      property Unread: Boolean read FUnread write FUnread;
      property _Not: Boolean read F_Not write F_Not;
      property _Or: Boolean read F_Or write F_Or;
   end;

   { TCDOMessage }

   TCDOMessage = class(TObjects)
   private
      FFolderID: PChar;
      FID: PChar;
      FStoreID: PChar;
      FAddress_ORIG: PChar;
      FSubject: PChar;
      FNoteText: TStringList;
      FEncrypted: Boolean;
      FImportance: Longint;
      FSensitivity: Longint;
      FSent: Boolean;
      FSigned: Boolean;
      FSize: Longint;
      FTimeCreated: Variant;
      FTimeExpired: Variant;
      FTimeLastModified: Variant;
      FTimeReceived: Variant;
      FTimeSent: Variant;
      FUnread: Boolean;
      FDeliveryReceipt: Boolean;
      FReadReceipt: Boolean;
      FSubmitted: Boolean;
      FTypeMessage: PChar;
      {}
      FFileNames: TStringList;
      FAddress_TO: TStringList;
      {}
      function GetFolderID: string;
      procedure SetFolderID(const Value: string);
      function GetID: string;
      procedure SetID(const Value: string);
      function GetStoreID: string;
      procedure SetStoreID(const Value: string);
      function GetAddress_ORIG: string;
      procedure SetAddress_ORIG(const Value: string);
      function GetSubject: string;
      procedure SetSubject(const Value: string);
      function GetTypeMessage: string;
      procedure SetTypeMessage(const Value: string);
      procedure Clear;
   public
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      procedure Assign(Source: TPersistent); override;
      { Addresses }
      property Address_ORIG: string read GetAddress_ORIG write SetAddress_ORIG;
      { Subject }
      property Subject: string read GetSubject write SetSubject;
      { Text }
      property NoteText: TStringList read FNoteText;
      {}
      property FileNames: TStringList read FFileNames;
      property Address_TO: TStringList read FAddress_TO;
      {}
      property FolderID: string read GetFolderID write SetFolderID;
      property StoreID: string read GetStoreID write SetStoreID;
      property ID: string read GetID write SetID;
      property TypeMessage: string read GetTypeMessage write SetTypeMessage;
      property Encrypted: Boolean read FEncrypted write FEncrypted;
      property Importance: Longint read FImportance write FImportance;
      property Sensitivity: Longint read FSensitivity write FSensitivity;
      property Sent: Boolean read FSent write FSent;
      property Signed: Boolean read FSigned write FSigned;
      property Size: Longint read FSize write FSize;
      property TimeCreated: Variant read FTimeCreated write FTimeCreated;
      property TimeExpired: Variant read FTimeExpired write FTimeExpired;
      property TimeLastModified: Variant read FTimeLastModified write FTimeLastModified;
      property TimeReceived: Variant read FTimeReceived write FTimeReceived;
      property TimeSent: Variant read FTimeSent write FTimeSent;
      property Unread: Boolean read FUnread write FUnread;
      property DeliveryReceipt: Boolean read FDeliveryReceipt write FDeliveryReceipt;
      property ReadReceipt: Boolean read FReadReceipt write FReadReceipt;
      property Submitted: Boolean read FSubmitted write FSubmitted;
   end;

   { TCDOAddressList }

   TCDOAddressList = class(TObjects)
   private
      FAddressListName: PChar;
      FID: PChar;
      function GetobjAddressListName: string;
      procedure SetAddressListName(const Value: string);
      function GetID: string;
      procedure SetID(const Value: string);
      procedure Clear;
   public
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      { Addresses }
      property AddressListName: string read GetobjAddressListName write SetAddressListName;
      property ID: string read GetID write SetID;
   end;

   { TCDOAddressEntry }

   TCDOAddressEntry = class(TObjects)
   private
      FAddressEntryName: PChar;
      FAddress: PChar;
      FID: PChar;
      FAddressType: PChar;
      function GetAddressEntryName: string;
      procedure SetAddressEntryName(const Value: string);
      function GetID: string;
      procedure SetID(const Value: string);
      function GetAddress: string;
      procedure SetAddress(const Value: string);
      function GetAddressType: string;
      procedure SetAddressType(const Value: string);
      procedure Clear;
   public
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      { Addresses }
      property AddressEntryName: string read GetAddressEntryName write SetAddressEntryName;
      property ID: string read GetID write SetID;
      property Address: string read GetAddress write SetAddress;
      property AddressType: string read GetAddressType write SetAddressType;
   end;

   { TCDORecipient }

   TCDORecipient = class(TObjects)
   private
      FRecipientName: PChar;
      FAddress: PChar;
      FID: PChar;
      FRecipientType: Longint;
      function GetRecipientName: string;
      procedure SetRecipientName(const Value: string);
      function GetID: string;
      procedure SetID(const Value: string);
      function GetAddress: string;
      procedure SetAddress(const Value: string);
      procedure Clear;
   public
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      { Addresses }
      property RecipientName: string read GetRecipientName write SetRecipientName;
      property ID: string read GetID write SetID;
      property Address: string read GetAddress write SetAddress;
      property RecipientType: Longint read FRecipientType write FRecipientType;
   end;

   { TCDOInfoStore }

   TCDOInfoStore = class(TObjects)
   private
      FInfoStoreName: PChar;
      FID: PChar;
      FFlags: Longint;
      function GetInfoStoreName: string;
      procedure SetInfoStoreName(const Value: string);
      function GetID: string;
      procedure SetID(const Value: string);
      procedure Clear;
   public
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      { Addresses }
      property InfoStoreName: string read GetInfoStoreName write SetInfoStoreName;
      property ID: string read GetID write SetID;
      property Flags: Longint read FFlags write FFlags;
   end;

   { TCDOFolder }

   TCDOFolder = class(TObjects)
   private
      FFolderName: PChar;
      FFolderID: PChar;
      FID: PChar;
      FStoreID: PChar;
      FAddress: PChar;
      FFlags: Longint;
      function GetFolderName: string;
      procedure SetFolderName(const Value: string);
      function GetFolderID: string;
      procedure SetFolderID(const Value: string);
      function GetID: string;
      procedure SetID(const Value: string);
      function GetStoreID: string;
      procedure SetStoreID(const Value: string);
      function GetAddress: string;
      procedure SetAddress(const Value: string);
      procedure Clear;
   public
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      { Addresses }
      property FolderName: string read GetFolderName write SetFolderName;
      property FolderID: string read GetFolderID write SetFolderID;
      property ID: string read GetID write SetID;
      property StoreID: string read GetStoreID write SetStoreID;
      property Address: string read GetAddress write SetAddress;
      property Flags: Longint read FFlags write FFlags;
   end;

   { TCDOAttachment }

   TCDOAttachment = class(TObjects)
   private
      FAttachmentName: PChar;
      FPosition: Longint;
      FAttachmentType: Longint;
      function GetAttachmentName: string;
      procedure SetAttachmentName(const Value: string);
      procedure Clear;
   public
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      {}
      property AttachmentName: string read GetAttachmentName write SetAttachmentName;
      property AttachmentType: Longint read FAttachmentType write FAttachmentType;
      property Position: Longint read FPosition write FPosition;
   end;

   TCDOSession = class;
   {}
   TCDOInfoStores = class;
   TCDOFolders = class;
   TCDOMessages = class;
   TCDOAddressLists = class;
   TCDOAddressEntries = class;
   TCDOAttachments = class;
   TCDORecipients = class;
   {}
   //TCDOFields = class;

   TCDOFolderItem = class(TCollectionItem)
   private
      FItem: TCDOFolder;
   public
      property Item: TCDOFolder read FItem write FItem;
   end;

   {===========================================================================}

   { TCDOFields }

   TCDOFields = class(TMAPIObject)
   private
      FobjFields: OleVariant;
      FobjField: OleVariant;
      FCDOField: TCDOField;
      function GetCount: Integer;
      procedure SetobjField(Value: OleVariant);
      function GetFieldByIndex(Index: Longint): TCDOField;
      function GetFieldByTag(PRTag: Longint): TCDOField;
      function GetFieldByName(Name: string): TCDOField;
      {}
   public
      constructor Create(AOwner: Tcomponent);                 override;
      destructor Destroy;                                     override;
      {}
      function AddUserField(FieldName: string; FieldClass: Integer; Value: Variant): Boolean;
      function DeleteUserFields: Boolean;
      {}
      property Count: Integer read GetCount;
      property objFields: OleVariant read FobjFields write FobjFields;
      property objField: OleVariant read FobjField write SetobjField;
      property FieldByName[Name: string]: TCDOField read GetFieldByName;
      property FieldByTag[PRTag: LOngint]: TCDOField read GetFieldByTag;
      property FieldByIndex[Index: Longint]: TCDOField read GetFieldByIndex;
   end;

   { TCDOObject }

   TCDOObjects = class(TMAPIObject)
   private
      FCDOFields: TCDOFields;
      FDebugPath: PChar;
      FDebug: Boolean;
      FDebugStrings: TStringList;
      function GetDebugPath: string;
      procedure SetDebugPath(const Value: string);
   public
      constructor Create(AOwner: Tcomponent);                 override;
      destructor Destroy;                                     override;
      {}
      procedure DebugCDOField(const FileName: string);
      {}
      property CDOFields: TCDOFields read FCDOFields;
   published
      property DebugPath: string read GetDebugPath write SetDebugPath;
      property Debug: Boolean read FDebug write FDebug;
   end;

   { TCDOAddressEntries }

   TReadAddressEntryEvent = procedure(CDOAddressEntries: TCDOAddressEntries) of object;

   TCDOAddressEntries = class(TCDOObjects)
   private
      FobjAddressEntries: OleVariant;
      FobjAddressEntry: OleVariant;
      FCDOAddressEntry : TCDOAddressEntry;
      {}
      FOnReadAddressEntry: TReadAddressEntryEvent;
      function GetCount: Integer;
      procedure SetobjAddressEntry(Value : OleVariant);
      {}
      property objAddressEntry: OleVariant read FobjAddressEntry write SetobjAddressEntry;
   public
      constructor Create(AOwner: Tcomponent);                 override;
      destructor Destroy;                                     override;
      {}
      property Count: Integer read GetCount;
      function EOF: Boolean;
      function GetFirst: Boolean;
      function GetNext: Boolean;
      function GetLast: Boolean;
      function GetPrev: Boolean;
      {}
      procedure ProcessAddressEntries;
      {}
      property objAddressEntries: OleVariant read FobjAddressEntries write FobjAddressEntries;
      property CDOAddressEntry: TCDOAddressEntry read FCDOAddressEntry;
   published
      property OnReadAddressEntry: TReadAddressEntryEvent read FOnReadAddressEntry write FOnReadAddressEntry;
   end;

   { TCDOAddressLists }

   TReadAddressListEvent = procedure(CDOAddressLists: TCDOAddressLists) of object;

   TCDOAddressLists = class(TCDOObjects)
   private
      FIndex: Integer;
      FobjAddressLists: OleVariant;
      FobjAddressList: OleVariant;
      FCDOAddressList : TCDOAddressList;
      {}
      FOnReadAddressList: TReadAddressListEvent;
      function GetCount: Integer;
      procedure SetobjAddressList(Value: OleVariant);
      {}
      property objAddressList: OleVariant read FobjAddressList write SetobjAddressList;
   public
      constructor Create(AOwner: Tcomponent);                 override;
      destructor Destroy;                                     override;
      {}
      property Count: Integer read GetCount;
      function EOF: Boolean;
      function GetFirst: Boolean;
      function GetNext: Boolean;
      function GetLast: Boolean;
      function GetPrev: Boolean;
      {}
      procedure ProcessAddressLists;
      {}
      property objAddressLists: OleVariant read FobjAddressLists write FobjAddressLists;
      property CDOAddressList: TCDOAddressList read FCDOAddressList;
   published
      property OnReadAddressList: TReadAddressListEvent read FOnReadAddressList write FOnReadAddressList;
   end;

   { TCDOInfoStores }

   TReadInfoStoreEvent = procedure(CDOInfoStores: TCDOInfoStores) of object;

   TCDOInfoStores = class(TCDOObjects)
   private
      FIndex: Integer;
      FobjInfoStores: OleVariant;
      FobjInfoStore: OleVariant;
      FRootFolder: OleVariant;
      FCDOInfoStore: TCDOInfoStore;
      {}
      FOnReadInfoStore: TReadInfoStoreEvent;
      function GetCount: Integer;
      procedure SetobjInfoStore(Value: OleVariant);
      {}
      property objInfoStore: OleVariant read FobjInfoStore write SetobjInfoStore;
   public
      constructor Create(AOwner: Tcomponent);                 override;
      destructor Destroy;                                     override;
      { }
      property Count: Integer read GetCount;
      function EOF: Boolean;
      function GetFirst: Boolean;
      function GetNext: Boolean;
      function GetLast: Boolean;
      function GetPrev: Boolean;
      {}
      property objInfoStores: OleVariant read FobjInfoStores write FobjInfoStores;
      property CDOInfoStore: TCDOInfoStore read FCDOInfoStore;
      property RootFolder: OleVariant read FRootFolder;
   published
      property OnReadInfoStore: TReadInfoStoreEvent read FOnReadInfoStore write FOnReadInfoStore;
   end;

   { TCDOFolders }

   TTypeFolder = (tfInbox, tfOutbox);
   TReadFolderEvent = procedure(CDOFolders: TCDOFolders) of object;

   TCDOFolders = class(TCDOObjects)
   private
      FobjFolders: OleVariant;
      FobjFolder: OleVariant;
      FCDOFolder: TCDOFolder;
      {}
      FLevel: Integer;
      FCollectionFolders: TCollection;
      {}
      FOnReadFolder: TReadFolderEvent;
      function GetCount: Integer;
      procedure SetobjFolder(Value: OleVariant);
      {}
      procedure CreateCollectionFolders(CDOInfoStores: TCDOInfoStores);
   public
      constructor Create(AOwner: Tcomponent);                 override;
      destructor Destroy;                                     override;
      {}
      property Count: Integer read GetCount;
      function EOF: Boolean;
      function GetFirst: Boolean;
      function GetNext: Boolean;
      function GetLast: Boolean;
      function GetPrev: Boolean;
      {}
      //function GetFolderByName(Value: string): Boolean;
      function GetFolders(CDOInfoStores: TCDOInfoStores): TCollection;
      procedure ProcessFolders(CDOInfoStores: TCDOInfoStores);
      {}
      property objFolders: OleVariant read FobjFolders write FobjFolders;
      property objFolder: OleVariant read FobjFolder write SetobjFolder;
      property CDOFolder: TCDOFolder read FCDOFolder;
   published
      property OnReadFolder: TReadFolderEvent read FOnReadFolder write FOnReadFolder;
   end;

   { TCDOAttachments }

   TReadAttachmentEvent = procedure(CDOAttachments: TCDOAttachments) of object;

   TCDOAttachments = class(TCDOObjects)
   private
      FobjAttachments: OleVariant;
      FobjAttachment: OleVariant;
      FCDOAttachment: TCDOAttachment;
      FPathNames: TStringList;
      FFileNames: TStringList;
      FAttachmentDir: PChar;
      FAttachmentFileName: PChar;
      {}
      FOnReadAttachment: TReadAttachmentEvent;
      {}
      function GetAttachmentDir: string;
      procedure SetAttachmentDir(const Value: string);
      function GetAttachmentFileName: string;
      procedure SetAttachmentFileName(const Value: string);
      {}
      function GetCount: Integer;
      procedure SetObjAttachments(Value: OleVariant);
      procedure SetobjAttachment(Value: OleVariant);
      procedure ProcessAttachments(const AttachDir, FileName: string);
      {}
      property AttachmentDir: string read GetAttachmentDir write SetAttachmentDir;
      property AttachmentFileName: string read GetAttachmentFileName write SetAttachmentFileName;
      property objAttachments: OleVariant read FobjAttachments write SetobjAttachments;
      property objAttachment: OleVariant read FobjAttachment write SetobjAttachment;
      property OnReadAttachment: TReadAttachmentEvent read FOnReadAttachment write FOnReadAttachment;
   public
      constructor Create(AOwner: Tcomponent);                 override;
      destructor Destroy;                                     override;
      {}
      property Count: Integer read GetCount;
      property CDOAttachment: TCDOAttachment read FCDOAttachment;
      { Attachments }
      property PathNames: TStringList read FPathNames;
      property FileNames: TStringList read FFileNames;
   end;

   { TCDORecipients }

   TReadRecipientEvent = procedure(CDORecipients: TCDORecipients) of object;

   TCDORecipients = class(TCDOObjects)
   private
      FCDORecipient : TCDORecipient;
      FCDOAddressEntry: TCDOAddressEntry;
      {}
      FobjRecipients: OleVariant;
      FAmbiguousNames: OLEVariant;
      FobjRecipient: OleVariant;
      FobjAddressEntry: OleVariant;
      {}
      FAddress_TO: TStringList;
      FAddress_CC: TStringList;
      FAddress_BCC: TStringList;
      {}
      FOnReadRecipient: TReadRecipientEvent;
      function GetCount: Integer;
      procedure SetobjRecipient(Value: OleVariant);
      procedure SetobjRecipients(Value: OleVariant);
      procedure ProcessRecipients;
      function AddRecipient(RecipientName: string; RecipientType: Integer): Boolean;
      {}
      property Count: Integer read GetCount;
      {}
      property Address_TO: TStringList read FAddress_TO;
      property Address_CC: TStringList read FAddress_CC;
      property Address_BCC: TStringList read FAddress_BCC;
      {}
      property OnReadRecipient: TReadRecipientEvent read FOnReadRecipient write FOnReadRecipient;
   public
      constructor Create(AOwner: Tcomponent);                 override;
      destructor Destroy;                                     override;
      {}
      function Resolve: Boolean;
      function AddAddressTO(Address: string): Boolean;
      function AddAddressCC(Address: string): Boolean;
      function AddAddressBCC(Address: string): Boolean;
      function ResolveRecipientAddress(RecipientAddress: string;
         RecipientType: Integer; ShowDialog: Boolean): Boolean;
      {}
      property objAmbiguousNames: OleVariant read FAmbiguousNames write FAmbiguousNames;
      property objRecipients: OleVariant read FobjRecipients write SetobjRecipients;
      property CDORecipient: TCDORecipient read FCDORecipient;
      property CDOAddressEntry: TCDOAddressEntry read FCDOAddressEntry;
      property objRecipient: OleVariant read FobjRecipient write SetobjRecipient;
      property objAddressEntry: OleVariant read FobjAddressEntry write FobjAddressEntry;
   end;

   { TCDOMessageFilter }

   TCDOMessageFilter = class(TCDOObjects)
   private
      FCDOMessageFilterItem: TCDOMessageFilterItem;
      FobjMessageFilter: OleVariant;
      procedure SetobjMessageFilter(Value: OleVariant);
   public
      constructor Create(AOwner: Tcomponent);                 override;
      destructor Destroy;                                     override;
      property CDOMessageFilterItem: TCDOMessageFilterItem read FCDOMessageFilterItem;
      {}
      property objMessageFilter: OleVariant read FobjMessageFilter write SetobjMessageFilter;
   end;

   { TCDOMessages }

   TReadMailMessageEvent = procedure(CDOMailMessages: TCDOMessages) of object;

   TCDOMessages = class(TCDOObjects)
   private
      FobjFolder: OleVariant;
      FobjMessages: OleVariant;
      FobjMessage: OleVariant;
      {}
      FCDOMessageFilter: TCDOMessageFilter;
      FCDOMessage: TCDOMessage;
      FCDOAttachments: TCDOAttachments;
      FCDORecipients: TCDORecipients;
      {}
      FOnReadMailMessage: TReadMailMessageEvent;
      FOnReadAttachment: TReadAttachmentEvent;
      FOnReadRecipient: TReadRecipientEvent;
      {}
      FNewMessage: Boolean;
      {}
      procedure SetobjFolder (Value: OleVariant);
      procedure SetobjMessages (Value: OleVariant);
      procedure SetobjMessage (Value: OleVariant);
      procedure SetOnReadAttachment (OnReadAttachment: TReadAttachmentEvent);
      procedure SetOnReadRecipient (OnReadRecipient: TReadRecipientEvent);
      {}
      function ReadAppointment: Boolean;
      function ReadGroupHeader: Boolean;
      function ReadMeetingItem: Boolean;
      function ReadMessage: Boolean;
      //function ReadMessageFilter: Boolean;
      function GetCount: Integer;
      function GetMailID: string;
      function AddRecipient_obj(AobjMessage: OleVariant; RecipientName: string; RecipientType: Integer): Boolean;
      function CreateAddressTO_obj(AobjMessage: OleVariant; const AddressTO: string): Boolean;
      {}
      property objMessages: OleVariant read FobjMessages write SetobjMessages;
   public
      constructor Create(AOwner: Tcomponent);                 override;
      destructor Destroy;                                     override;
      { ReadMail}
      function EOF: Boolean;
      function GetFirst: Boolean;
      function GetNext: Boolean;
      function GetLast: Boolean;
      function GetPrev: Boolean;
      function ReadMail: Boolean;
      {}
      procedure ExtractFiles(const AttachDir: string);
      procedure ExtractFile(const AttachDir, FileName: string);
      procedure DeleteFiles;
      {}
      function DeleteMail: Boolean;
      function UpdateMail: Boolean;
      function CopyToMail(const FolderID,StoreID: string): Boolean;
      function MoveToMail(const FolderID,StoreID: string): Boolean;
      { SendMail }
      function CreateMail(const MailType: string): Boolean;
      function CreateAddressTO(const AddressTO: string): Boolean;
      //function CreateExcel(const Subject: string): Boolean;

      function FormatSendMail: Boolean;
      function SendMail(SaveMessage: Boolean): Boolean;
      function SendExcel: Boolean;
      function ForwardMail(const AddressTO: string): Boolean;
      function Options(ParentWindow: Longint): Boolean;
      {}
      procedure WriteMail(const FileName: string);
      procedure FormatMail(const FileName: string);
      procedure FormatMailNew(const FileName: string);
      {}
      property Count: Integer read GetCount;
      property MailID: string read GetMailID;
      property objFolder: OleVariant read FobjFolder write SetobjFolder;
      property objMessage: OleVariant read FobjMessage write SetobjMessage;
      {}
      property CDOAttachments: TCDOAttachments read FCDOAttachments;
      property CDORecipients: TCDORecipients read FCDORecipients;
      {}
      property CDOMessageFilter: TCDOMessageFilter read FCDOMessageFilter;
      property CDOMessage: TCDOMessage read FCDOMessage;
   published
      property OnReadMailMessage: TReadMailMessageEvent read FOnReadMailMessage write FOnReadMailMessage;
      property OnReadAttachment: TReadAttachmentEvent read FOnReadAttachment write SetOnReadAttachment;
      property OnReadRecipient: TReadRecipientEvent read FOnReadRecipient write SetOnReadRecipient;
   end;

   { TCDOSession }

   TCDOSession = class(TCustomMAPISession)
   private
      FobjSession: OleVariant;
      FobjCurrentUser: OleVariant;
      FSaveCurrentDir: string;
      function GetSelectName: TStringList;
      function GetCDOVersion: string;
      {}
      function GetobjAddressLists: OLeVariant;
      function GetobjAddressListGAL: OleVariant;
      function GetobjAddressListPAB: OleVariant;
      function GetobjInfoStores: OleVariant;
      function GetobjInfoStore(value: string): OleVariant;
      {}
   protected
      function Logon: Boolean;                                  override;
      function Logoff: Boolean;                                 override;
   public
      constructor Create(AOwner: Tcomponent);                   override;
      destructor Destroy;                                       override;
      { }
      function DeliverNow: Boolean;
      procedure CreateMAPISession;
      {}
      function GetobjFolder(TF: TTypeFolder): OleVariant;          overload;
      function GetobjFolder(Index: Integer): OleVariant;           overload;
      function GetobjFolder(FolderID,StoreID: string): OleVariant; overload;
      function GetobjMessage(const MailID, StoreID: string): OleVariant;
      {}
      property SelectName: TStringList read GetSelectName;
      property CDOVersion: string read GetCDOVersion;
      {}
      property objSession: OleVariant read FobjSession;
      property objAddressLists: OleVariant read GetobjAddressLists;
      property objAddressListGAL: OleVariant read GetobjAddressListGAL;
      property objAddressListPAB: OleVariant read GetobjAddressListPAB;
      property objInfoStores: OLeVariant read GetobjInfoStores;
      property objInfoStore[Value: string]: OleVariant read GetobjInfoStore;
      property objCurrentUser: OleVariant read FobjCurrentUser;
   end;

function CheckCDOMAPI (var CDOVersion,Profile,Mailbox,Status: string): Boolean;

procedure Register;

implementation

const
   CDOFileData = 1;
   CDOFileLink = 2;
   CDOOLE = 3;
   CDOEmbeddedMessage = 4;

function CheckCDOMAPI (var CDOVersion,Profile,Mailbox,Status: string): Boolean;
var
   CDOMAPISession: TCDOSession;
begin
   Result := True;
   CDOVersion := '';
   Profile := '';
   Mailbox := '';
   Status := '';
   {--------------------------------------------------------------}
   { Init CDO                                                     }
   {--------------------------------------------------------------}
   try
      CDOMAPISession := TCDOSession.Create(nil);
      if CDOMAPISession.Status = 0 then begin
         CDOVersion := CDOMAPISession.CDOVersion;
         {--------------------------------------------------------------}
         { Подключение к почтовому серверу ...                          }
         {--------------------------------------------------------------}
         CDOMAPISession.CaseProfile := False;
         try
            CDOMAPISession.Active := True;
         except
            Result := False;
         end;
         if CDOMAPISession.Status = 0 then begin
            Profile := CDOMAPISession.Profile;
            Mailbox := CDOMAPISession.Address;
            end
         else begin
            Status := CDOMAPISession.ErrorString;
            Result := False;
         end;
         end
      else begin
         Status := 'CDO Not Available ' + CDOMAPISession.ErrorString;
         Result := False;
      end;
   except
      Status := 'Инициализация CDO = False';
      Result := False;
   end;
   CDOMAPISession.Free;
   //if Status = '' then Status := 'OK.';
end;

{ TCDOMessage }

constructor TCDOMessage.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   ObjectType := otMessage;
   FNoteText := TStringList.Create;
   FFileNames := TStringList.Create;
   FAddress_TO := TStringList.Create;
   Clear;
end;

procedure TCDOMessage.Clear;
begin
   FNoteText.Clear;
   FFileNames.Clear;
   FAddress_TO.Clear;
   Address_ORIG := '';
   Subject := '';
   FolderID := '';
   ID := '';
   StoreID := '';
   TypeMessage := '';
   FEncrypted := False;
   FImportance := cdoNormal;
   FSensitivity := cdoNoSensitivity;
   FSent := False;
   FSigned := False;
   FSize := 0;
   FTimeCreated := 0;
   FTimeExpired := 0;
   FTimeLastModified := 0;
   FTimeReceived := 0;
   FTimeSent := 0;
   FUnread := False;
   FDeliveryReceipt := False;
   FReadReceipt := False;
   FSubmitted := False;
end;

destructor TCDOMessage.Destroy;
begin
   StrDispose(FFolderID);
   StrDispose(FID);
   StrDispose(FStoreID);
   StrDispose(FTypeMessage);
   StrDispose(FSubject);
   StrDispose(FAddress_ORIG);
   FNoteText.Free;
   FFileNames.Free;
   FAddress_TO.Free;
   inherited Destroy;
end;

procedure TCDOMessage.Assign(Source: TPersistent);
begin
  if Source is TCDOMessage then begin
     Clear;
     FNoteText.Assign((Source as TCDOMessage).NoteText);
     FFileNames.Assign((Source as TCDOMessage).FileNames);
     FAddress_TO.Assign((Source as TCDOMessage).Address_TO);
     Address_ORIG := (Source as TCDOMessage).Address_ORIG;
     Subject := (Source as TCDOMessage).Subject;
     FolderID := (Source as TCDOMessage).FolderID;
     ID := (Source as TCDOMessage).ID;
     StoreID := (Source as TCDOMessage).StoreID;
     TypeMessage := (Source as TCDOMessage).TypeMessage;
     Encrypted := (Source as TCDOMessage).Encrypted;
     Importance := (Source as TCDOMessage).Importance;
     Sensitivity := (Source as TCDOMessage).Sensitivity;
     Sent := (Source as TCDOMessage).Sent;
     Signed := (Source as TCDOMessage).Signed;
     Size := (Source as TCDOMessage).Size;
     TimeCreated := (Source as TCDOMessage).TimeCreated;
     TimeExpired := (Source as TCDOMessage).TimeExpired;
     TimeLastModified := (Source as TCDOMessage).TimeLastModified;
     TimeReceived := (Source as TCDOMessage).TimeReceived;
     TimeSent := (Source as TCDOMessage).TimeSent;
     Unread := (Source as TCDOMessage).Unread;
     DeliveryReceipt := (Source as TCDOMessage).DeliveryReceipt;
     ReadReceipt := (Source as TCDOMessage).ReadReceipt;
     Submitted := (Source as TCDOMessage).Submitted;
     Exit;
  end;
  inherited Assign(Source);
end;

function TCDOMessage.GetSubject: string;
begin
   Result := StrPas(FSubject);
end;
procedure TCDOMessage.SetSubject(const Value: string);
begin
   if FSubject <> nil then StrDispose(FSubject);
   FSubject := StrAlloc(Length(Value)+1);
   StrPCopy(FSubject, Value);
end;

function TCDOMessage.GetTypeMessage: string;
begin
   Result := StrPas(FTypeMessage);
end;
procedure TCDOMessage.SetTypeMessage(const Value: string);
begin
   if FTypeMessage <> nil then StrDispose(FTypeMessage);
   FTypeMessage := StrAlloc(Length(Value)+1);
   StrPCopy(FTypeMessage, Value);
end;

function TCDOMessage.GetAddress_ORIG: string;
begin
   Result := StrPas(FAddress_ORIG);
end;
procedure TCDOMessage.SetAddress_ORIG(const Value: string);
begin
   if FAddress_ORIG <> nil then StrDispose(FAddress_ORIG);
   FAddress_ORIG := StrAlloc(Length(Value)+1);
   StrPCopy(FAddress_ORIG, Value);
end;

function TCDOMessage.GetFolderID: string;
begin
   Result := StrPas(FFolderID);
end;
procedure TCDOMessage.SetFolderID(const Value: string);
begin
   if FFolderID <> nil then StrDispose(FFolderID);
   FFolderID := StrAlloc(Length(Value)+1);
   StrPCopy(FFolderID, Value);
end;

function TCDOMessage.GetID: string;
begin
   Result := StrPas(FID);
end;
procedure TCDOMessage.SetID(const Value: string);
begin
   if FID <> nil then StrDispose(FID);
   FID := StrAlloc(Length(Value)+1);
   StrPCopy(FID, Value);
end;

function TCDOMessage.GetStoreID: string;
begin
   Result := StrPas(FStoreID);
end;
procedure TCDOMessage.SetStoreID(const Value: string);
begin
   if FStoreID <> nil then StrDispose(FStoreID);
   FStoreID := StrAlloc(Length(Value)+1);
   StrPCopy(FStoreID, Value);
end;

{ TCDOMessageFilterItem }

constructor TCDOMessageFilterItem.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   ObjectType := otMessageFilter;
   FNoteText := TStringList.Create;
   Clear;
end;

procedure TCDOMessageFilterItem.Clear;
begin
   FNoteText.Clear;
   Address_ORIG := '';
   Subject := '';
   Recipients := '';
   TypeMessage := '';
   F_Or := False;
   F_Not := False;
end;

destructor TCDOMessageFilterItem.Destroy;
begin
   StrDispose(FTypeMessageFilter);
   StrDispose(FSubject);
   StrDispose(FRecipients);
   StrDispose(FAddress_ORIG);
   FNoteText.Free;
   inherited Destroy;
end;

function TCDOMessageFilterItem.GetSubject: string;
begin
   Result := StrPas(FSubject);
end;
procedure TCDOMessageFilterItem.SetSubject(const Value: string);
begin
   if FSubject <> nil then StrDispose(FSubject);
   FSubject := StrAlloc(Length(Value)+1);
   StrPCopy(FSubject, Value);
end;

function TCDOMessageFilterItem.GetRecipients: string;
begin
   Result := StrPas(FRecipients);
end;
procedure TCDOMessageFilterItem.SetRecipients(const Value: string);
begin
   if FRecipients <> nil then StrDispose(FRecipients);
   FRecipients := StrAlloc(Length(Value)+1);
   StrPCopy(FRecipients, Value);
end;

function TCDOMessageFilterItem.GetTypeMessageFilter: string;
begin
   Result := StrPas(FTypeMessageFilter);
end;
procedure TCDOMessageFilterItem.SetTypeMessageFilter(const Value: string);
begin
   if FTypeMessageFilter <> nil then StrDispose(FTypeMessageFilter);
   FTypeMessageFilter := StrAlloc(Length(Value)+1);
   StrPCopy(FTypeMessageFilter, Value);
end;

function TCDOMessageFilterItem.GetAddress_ORIG: string;
begin
   Result := StrPas(FAddress_ORIG);
end;
procedure TCDOMessageFilterItem.SetAddress_ORIG(const Value: string);
begin
   if FAddress_ORIG <> nil then StrDispose(FAddress_ORIG);
   FAddress_ORIG := StrAlloc(Length(Value)+1);
   StrPCopy(FAddress_ORIG, Value);
end;

{ TCDOAttachment }

constructor TCDOAttachment.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   ObjectType := otAttachment;
   Clear;
end;

procedure TCDOAttachment.Clear;
begin
   AttachmentName := '';
   AttachmentType := 0;
   Position := 0;
end;

destructor TCDOAttachment.Destroy;
begin
   StrDispose(FAttachmentName);
   inherited Destroy;
end;

function TCDOAttachment.GetAttachmentName: string;
begin
   Result := StrPas(FAttachmentName);
end;
procedure TCDOAttachment.SetAttachmentName(const Value: string);
begin
   if FAttachmentName <> nil then StrDispose(FAttachmentName);
   FAttachmentName := StrAlloc(Length(Value)+1);
   StrPCopy(FAttachmentName, Value);
end;

{ TCDOFolder }

constructor TCDOFolder.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   ObjectType := otFolder;
   Clear;
end;

procedure TCDOFolder.Clear;
begin
   FolderName := '';
   FolderID := '';
   ID := '';
   StoreID := '';
   Address := '';
end;

destructor TCDOFolder.Destroy;
begin
   StrDispose(FFolderName);
   StrDispose(FFolderID);
   StrDispose(FID);
   StrDispose(FStoreID);
   StrDispose(FAddress);
   inherited Destroy;
end;

function TCDOFolder.GetFolderName: string;
begin
   Result := StrPas(FFolderName);
end;
procedure TCDOFolder.SetFolderName(const Value: string);
begin
   if FFolderName <> nil then StrDispose(FFolderName);
   FFolderName := StrAlloc(Length(Value)+1);
   StrPCopy(FFolderName, Value);
end;

function TCDOFolder.GetFolderID: string;
begin
   Result := StrPas(FFolderID);
end;
procedure TCDOFolder.SetFolderID(const Value: string);
begin
   if FFolderID <> nil then StrDispose(FFolderID);
   FFolderID := StrAlloc(Length(Value)+1);
   StrPCopy(FFolderID, Value);
end;

function TCDOFolder.GetID: string;
begin
   Result := StrPas(FID);
end;
procedure TCDOFolder.SetID(const Value: string);
begin
   if FID <> nil then StrDispose(FID);
   FID := StrAlloc(Length(Value)+1);
   StrPCopy(FID, Value);
end;

function TCDOFolder.GetStoreID: string;
begin
   Result := StrPas(FStoreID);
end;
procedure TCDOFolder.SetStoreID(const Value: string);
begin
   if FStoreID <> nil then StrDispose(FStoreID);
   FStoreID := StrAlloc(Length(Value)+1);
   StrPCopy(FStoreID, Value);
end;

function TCDOFolder.GetAddress: string;
begin
   Result := StrPas(FAddress);
end;
procedure TCDOFolder.SetAddress(const Value: string);
begin
   if FAddress <> nil then StrDispose(FAddress);
   FAddress := StrAlloc(Length(Value)+1);
   StrPCopy(FAddress, Value);
end;

{ TCDOAddressEntry }

constructor TCDOAddressEntry.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   ObjectType := otAddressEntry;
   Clear;
end;

procedure TCDOAddressEntry.Clear;
begin
   AddressEntryName := '';
   AddressType := '';
   ID := '';
   Address := '';
end;

destructor TCDOAddressEntry.Destroy;
begin
   StrDispose(FAddressEntryName);
   StrDispose(FAddressType);
   StrDispose(FID);
   StrDispose(FAddress);
   inherited Destroy;
end;

function TCDOAddressEntry.GetAddressEntryName: string;
begin
   Result := StrPas(FAddressEntryName);
end;
procedure TCDOAddressEntry.SetAddressEntryName(const Value: string);
begin
   if FAddressEntryName <> nil then StrDispose(FAddressEntryName);
   FAddressEntryName := StrAlloc(Length(Value)+1);
   StrPCopy(FAddressEntryName, Value);
end;

function TCDOAddressEntry.GetAddressType: string;
begin
   Result := StrPas(FAddressType);
end;
procedure TCDOAddressEntry.SetAddressType(const Value: string);
begin
   if FAddressType <> nil then StrDispose(FAddressType);
   FAddressType := StrAlloc(Length(Value)+1);
   StrPCopy(FAddressType, Value);
end;

function TCDOAddressEntry.GetID: string;
begin
   Result := StrPas(FID);
end;
procedure TCDOAddressEntry.SetID(const Value: string);
begin
   if FID <> nil then StrDispose(FID);
   FID := StrAlloc(Length(Value)+1);
   StrPCopy(FID, Value);
end;

function TCDOAddressEntry.GetAddress: string;
begin
   Result := StrPas(FAddress);
end;
procedure TCDOAddressEntry.SetAddress(const Value: string);
begin
   if FAddress <> nil then StrDispose(FAddress);
   FAddress := StrAlloc(Length(Value)+1);
   StrPCopy(FAddress, Value);
end;

{ TCDORecipient }

constructor TCDORecipient.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   ObjectType := otRecipient;
   Clear;
end;

procedure TCDORecipient.Clear;
begin
   RecipientName := '';
   RecipientType := 0;
   ID := '';
   Address := '';
end;

destructor TCDORecipient.Destroy;
begin
   StrDispose(FRecipientName);
   StrDispose(FID);
   StrDispose(FAddress);
   inherited Destroy;
end;

function TCDORecipient.GetRecipientName: string;
begin
   Result := StrPas(FRecipientName);
end;
procedure TCDORecipient.SetRecipientName(const Value: string);
begin
   if FRecipientName <> nil then StrDispose(FRecipientName);
   FRecipientName := StrAlloc(Length(Value)+1);
   StrPCopy(FRecipientName, Value);
end;

function TCDORecipient.GetID: string;
begin
   Result := StrPas(FID);
end;
procedure TCDORecipient.SetID(const Value: string);
begin
   if FID <> nil then StrDispose(FID);
   FID := StrAlloc(Length(Value)+1);
   StrPCopy(FID, Value);
end;

function TCDORecipient.GetAddress: string;
begin
   Result := StrPas(FAddress);
end;
procedure TCDORecipient.SetAddress(const Value: string);
begin
   if FAddress <> nil then StrDispose(FAddress);
   FAddress := StrAlloc(Length(Value)+1);
   StrPCopy(FAddress, Value);
end;

{ TCDOAddressList }

constructor TCDOAddressList.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   ObjectType := otAddressList;
   Clear;
end;

procedure TCDOAddressList.Clear;
begin
   AddressListName := '';
   ID := '';
end;

destructor TCDOAddressList.Destroy;
begin
   StrDispose(FAddressListName);
   StrDispose(FID);
   inherited Destroy;
end;

function TCDOAddressList.GetobjAddressListName: string;
begin
   Result := StrPas(FAddressListName);
end;
procedure TCDOAddressList.SetAddressListName(const Value: string);
begin
   if FAddressListName <> nil then StrDispose(FAddressListName);
   FAddressListName := StrAlloc(Length(Value)+1);
   StrPCopy(FAddressListName, Value);
end;

function TCDOAddressList.GetID: string;
begin
   Result := StrPas(FID);
end;
procedure TCDOAddressList.SetID(const Value: string);
begin
   if FID <> nil then StrDispose(FID);
   FID := StrAlloc(Length(Value)+1);
   StrPCopy(FID, Value);
end;

{ TCDOInfoStore }

constructor TCDOInfoStore.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   ObjectType := otInfoStore;
   Clear;
end;

procedure TCDOInfoStore.Clear;
begin
   InfoStoreName := '';
   ID := '';
end;

destructor TCDOInfoStore.Destroy;
begin
   StrDispose(FInfoStoreName);
   StrDispose(FID);
   inherited Destroy;
end;

function TCDOInfoStore.GetInfoStoreName: string;
begin
   Result := StrPas(FInfoStoreName);
end;
procedure TCDOInfoStore.SetInfoStoreName(const Value: string);
begin
   if FInfoStoreName <> nil then StrDispose(FInfoStoreName);
   FInfoStoreName := StrAlloc(Length(Value)+1);
   StrPCopy(FInfoStoreName, Value);
end;

function TCDOInfoStore.GetID: string;
begin
   Result := StrPas(FID);
end;
procedure TCDOInfoStore.SetID(const Value: string);
begin
   if FID <> nil then StrDispose(FID);
   FID := StrAlloc(Length(Value)+1);
   StrPCopy(FID, Value);
end;

{ TCDOField }

constructor TCDOField.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   ObjectType := otField;
   Clear;
end;

procedure TCDOField.Clear;
begin
   FieldName := '';
   FieldType := 0;
   FID := 0;
   Value := Unassigned;
end;

destructor TCDOField.Destroy;
begin
   StrDispose(FFieldName);
   inherited Destroy;
end;

function TCDOField.GetFieldName: string;
begin
   Result := StrPas(FFieldName);
end;
procedure TCDOField.SetFieldName(const Value: string);
begin
   if FFieldName <> nil then StrDispose(FFieldName);
   FFieldName := StrAlloc(Length(Value)+1);
   StrPCopy(FFieldName, Value);
end;

{ TCDOSession }

constructor TCDOSession.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   CreateMAPISession;
end;

procedure TCDOSession.CreateMAPISession;
begin
   FobjSession := Unassigned;
   if Status = 0 then begin
      FSaveCurrentDir := GetCurrentDir;
      try
         if VarType(FobjSession) <> varDispatch then
            FobjSession := CreateOleObject('MAPI.Session');
      except
         on E: Exception do begin
            FobjSession := Unassigned;
            MAPIHandleException(E);
         end;
      end;
      ChDir(FSaveCurrentDir);
   end;
end;

destructor TCDOSession.Destroy;
begin
   FobjSession := Unassigned;
   inherited Destroy;
end;

function TCDOSession.Logon: Boolean;
begin
   FSaveCurrentDir := GetCurrentDir;
   ClearErrors;
   try
      if CaseProfile then begin
         { Выбор Profile }
         if not LogonAccess then FobjSession.Logon('','',True,True,FHandle,True);
         end
      else begin
         { }
         if Profile = '' then begin
            if DefaultProfile <> '' then
               if not LogonAccess then FobjSession.Logon(DefaultProfile,'',False,True,FHandle,True)
            else
               Status := 997;
            end
         else begin
            if not LogonAccess then FobjSession.Logon(Profile,'',False,True,FHandle,True);
         end;
      end;
      if Status=SUCCESS_SUCCESS then begin
         Profile := FobjSession.Name;
         LogonAccess := True;
         FobjCurrentUser := FobjSession.CurrentUser;
         Address := FobjCurrentUser.Name;
      end;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
   ChDir(FSaveCurrentDir);
end;

function TCDOSession.Logoff: Boolean;
begin
   FSaveCurrentDir := GetCurrentDir;
   ClearErrors;
   if Active then begin
      try
         FobjSession.Logoff;
         // if CaseProfile then Profile := '';
         // Address := '';
      except
         on E: Exception do begin
            MAPIHandleException(E);
         end;
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
   ChDir(FSaveCurrentDir);
end;

function TCDOSession.DeliverNow: Boolean;
begin
   ClearErrors;
   try
      FobjSession.DeliverNow;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOSession.GetSelectName: TStringList;
var
   i: Integer;
   FobjRecipients: OleVariant;
   B: Boolean;
begin
   ClearErrors;
   FList.Clear;
   B := Active;
   if not B then Active := True;
   try
      FobjRecipients := FobjSession.AddressBook(,'Выбор имени адресата',True,True,1,'Кому:','Cc:','Bcc:',0);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   if VarType(FobjRecipients) <> VarEmpty then begin
      for i:=1 to FobjRecipients.Count do begin
          FList.Add(FobjRecipients.Item[i].Name);
      end;
   end;
   if not B then Active := False;
   Result := FList;
end;

function TCDOSession.GetobjAddressLists: OLeVariant;
begin
   Result := UnAssigned;
   ClearErrors;
   try
      Result := FobjSession.AddressLists;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
end;

function TCDOSession.GetobjInfoStores: OleVariant;
begin
   Result := UnAssigned;
   ClearErrors;
   try
      Result := FobjSession.InfoStores;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
end;

{ GetobjFolder }

function TCDOSession.GetobjFolder(TF: TTypeFolder): OleVariant;
begin
   Result := UnAssigned;
   ClearErrors;
   try
      case TF of
         tfInbox: Result := FobjSession.Inbox;
         tfOutbox: Result := FobjSession.Outbox;
      end;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
end;
{ 1.2 }
function TCDOSession.GetobjFolder(Index: Integer): OleVariant;
begin
   Result := UnAssigned;
   ClearErrors;
   try
      Result := objSession.GetDefaultFolder(Index);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
end;
function TCDOSession.GetobjFolder(FolderID,StoreID: string): OleVariant;
begin
   Result := UnAssigned;
   ClearErrors;
   try
      Result := FobjSession.GetFolder(FolderID,StoreID);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
end;

function TCDOSession.GetobjInfoStore(value: string): OleVariant;
begin
   Result := UnAssigned;
   ClearErrors;
   try
      Result := FobjSession.GetInfoStore(Value);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
end;

function TCDOSession.GetobjMessage(const MailID, StoreID: string): OleVariant;
begin
   Result := UnAssigned;
   ClearErrors;
   try
      Result := FobjSession.GetMessage(MailID, StoreID);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
end;

function TCDOSession.GetCDOVersion: string;
begin
   Result := UnAssigned;
   ClearErrors;
   try
      Result := FobjSession.Version;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
end;

function TCDOSession.GetobjAddressListGAL: OleVariant;
begin
   Result := UnAssigned;
   ClearErrors;
   try
      Result := FobjSession.GetobjAddressList(CDOAddressGAL);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
end;

function TCDOSession.GetobjAddressListPAB: OleVariant;
begin
   Result := UnAssigned;
   ClearErrors;
   try
      Result := FobjSession.GetobjAddressList(CDOAddressPAB);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
end;

{ TCDOFields }

constructor TCDOFields.Create(AOwner: TComponent);
begin
   inherited Create(AOwner);
   FCDOField := TCDOField.Create(Self);
   FobjFields := Unassigned;
   FobjField  := Unassigned;
end;

destructor TCDOFields.Destroy;
begin
   inherited Destroy;
end;

function TCDOFields.AddUserField(FieldName: string; FieldClass: Integer; Value: Variant): Boolean;
begin
   ClearErrors;
   try
      objField := objFields.Add(FieldName, FieldClass, Value);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOFields.DeleteUserFields: Boolean;
begin
   ClearErrors;
   try
      objFields.Delete;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOFields.GetCount: Integer;
begin
   try
      Result := FobjFields.Count;
   except
      Result := 0;
   end;
end;

procedure TCDOFields.SetobjField(Value: OleVariant);
begin
   FobjField := Value;
   FCDOField.Clear;
   if not VarIsEmpty(FobjField) then begin
      FCDOField.ID := objField.ID;
      FCDOField.FieldName := objField.Name;
      if FCDOField.FieldName = '' then
         FCDOField.FieldName := GetPR_Name(objField.ID);
      FCDOField.FieldType := objField.Type;
      FCDOField.Value := objField.Value;
   end;
end;

function TCDOFields.GetFieldByIndex(Index: Longint): TCDOField;
begin
   objField := Unassigned;
   try
      objField := FobjFields.Item[Index];
   except
   end;
   Result := FCDOField;
end;

function TCDOFields.GetFieldByTag(PRTag: Longint): TCDOField;
var
   i: Integer;
begin
   objField := Unassigned;
   for i:=1 to FobjFields.Count do begin
      try
         if FobjFields.Item[i].ID = PRTag then begin
            objField := FobjFields.Item[i];
            Break;
         end;
      except
      end;
   end;
   Result := FCDOField;
end;

function TCDOFields.GetFieldByName(Name: string): TCDOField;
begin
   objField := Unassigned;
   try
      objField := FobjFields.Item[Name];
   except
   end;
   Result := FCDOField;
end;

{ TCDOObjects }

constructor TCDOObjects.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   FCDOFields := TCDOFields.Create(Self);
   FDebugStrings := TStringList.Create;
   Debug := False;
   DebugPath := 'debug';
end;

destructor TCDOObjects.Destroy;
begin
   FDebugStrings.Free;
   StrDispose(FDebugPath);
   inherited Destroy;
end;

procedure TCDOObjects.DebugCDOField(const FileName: string);
var
   j: Integer;
   s: string;
   d: string;
begin
   if Debug then Begin
      FDEbugStrings.Clear;
      for j:=1 to CDOFields.Count do begin
         try
            s := VarToStr(CDOFields.GetFieldByIndex(j).Value);
         except
            s := 'Значение не определено.';
         end;
         FDEbugStrings.Add('|'+IntToStr(J)+'|'+CDOFields.FieldByIndex[j].FieldName+'|'+S);
      end;
      d := ExpandFileName(DebugPath);
      if not DirectoryExists(D) then ForceDirectories(D);
      FDEbugStrings.SaveToFile(IncludeTrailingBackSlash(D)+FileName);
   end;
end;

function TCDOObjects.GetDebugPath: string;
begin
   Result := StrPas(FDebugPath);
end;
procedure TCDOObjects.SetDebugPath(const Value: string);
begin
   if FDebugPath <> nil then StrDispose(FDebugPath);
   FDebugPath := StrAlloc(Length(Value)+1);
   StrPCopy(FDebugPath, Value);
end;

{ TCDOAddressEntries }

constructor TCDOAddressEntries.Create(AOwner: TComponent);
begin
   inherited Create(AOwner);
   FCDOAddressEntry := TCDOAddressEntry.Create(Self);
   FobjAddressEntries := Unassigned;
   FobjAddressEntry := Unassigned;
end;

destructor TCDOAddressEntries.Destroy;
begin
   inherited Destroy;
end;

procedure TCDOAddressEntries.SetobjAddressEntry(Value : OleVariant);
begin
   FobjAddressEntry := Value;
   FCDOAddressEntry.Clear;
   if not VarIsEmpty(Value) then begin
      CDOFields.objFields := objAddressEntry.Fields;
      FCDOAddressEntry.AddressEntryName := objAddressEntry.Name;
      FCDOAddressEntry.ID := objAddressEntry.ID;
      FCDOAddressEntry.Address := objAddressEntry.Address;
      FCDOAddressEntry.AddressType := objAddressEntry.Type;
      {}
      DebugCDOField(FCDOAddressEntry.ID+'.AddressEntry');
   end;
end;

function TCDOAddressEntries.GetCount: Integer;
begin
   try
      Result := objAddressEntries.Count;
   except
      Result := 0;
   end;
end;

function TCDOAddressEntries.GetFirst: Boolean;
begin
   ClearErrors;
   try
      objAddressEntry := objAddressEntries.GetFirst;
      // if not EOF then
      // if Assigned(FOnReadAddressEntry) then FOnReadAddressEntry(Self);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOAddressEntries.GetNext: Boolean;
begin
   ClearErrors;
   try
      objAddressEntry := objAddressEntries.GetNext;
      // if not EOF then
      // if Assigned(FOnReadAddressEntry) then FOnReadAddressEntry(Self);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOAddressEntries.GetLast: Boolean;
begin
   ClearErrors;
   try
      objAddressEntry := objAddressEntries.GetLast;
      // if not EOF then
      // if Assigned(FOnReadAddressEntry) then FOnReadAddressEntry(Self);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOAddressEntries.GetPrev: Boolean;
begin
   ClearErrors;
   try
      objAddressEntry := objAddressEntries.GetPrevious;
      // if not EOF then
      // if Assigned(FOnReadAddressEntry) then FOnReadAddressEntry(Self);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOAddressEntries.EOF: Boolean;
begin
   Result := VarIsEmpty(FobjAddressEntry);
end;

procedure TCDOAddressEntries.ProcessAddressEntries;
begin
   GetFirst;
   while (not EOF) do begin
      if Assigned(FOnReadAddressEntry) then FOnReadAddressEntry(Self);
      GetNext;
   end;
end;

{ TCDOAddressLists }

constructor TCDOAddressLists.Create(AOwner: TComponent);
begin
   inherited Create(AOwner);
   FCDOAddressList := TCDOAddressList.Create(Self);
   FobjAddressList := Unassigned;
end;

destructor TCDOAddressLists.Destroy;
begin
   inherited Destroy;
end;

function TCDOAddressLists.GetCount: Integer;
begin
   try
      Result := objAddressLists.Count;
   except
      Result := 0;
   end;
end;

procedure TCDOAddressLists.SetobjAddressList(Value: OleVariant);
begin
   FobjAddressList := Value;
   CDOAddressList.Clear;
   if not VarIsEmpty(Value) then begin
      CDOFields.objFields := objAddressList.Fields;
      CDOAddressList.AddressListName := objAddressList.Name;
      CDOAddressList.ID := objAddressList.ID;
      {}
      DebugCDOField(CDOAddressList.ID+'.AddressList');
   end;
end;

function TCDOAddressLists.GetFirst: Boolean;
begin
   FIndex := 1;
   ClearErrors;
   try
      if FIndex <= Count then begin
         objAddressList := objAddressLists.Item[FIndex];
         if Assigned(FOnReadAddressList) then FOnReadAddressList(Self);
         end
      else
         objAddressList := Unassigned;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOAddressLists.GetNext: Boolean;
begin
   Inc(FIndex);
   ClearErrors;
   try
      if FIndex <= Count then begin
         objAddressList := objAddressLists.Item[FIndex];
         if Assigned(FOnReadAddressList) then FOnReadAddressList(Self);
         end
      else
         objAddressList := Unassigned;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOAddressLists.GetLast: Boolean;
begin
   FIndex := Count;
   ClearErrors;
   try
      if FIndex > 0 then begin
         objAddressList := objAddressLists.Item[FIndex];
         if Assigned(FOnReadAddressList) then FOnReadAddressList(Self);
         end
      else
         objAddressList := Unassigned;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOAddressLists.GetPrev: Boolean;
begin
   Dec(FIndex);
   ClearErrors;
   try
      if FIndex > 0 then begin
         objAddressList := objAddressLists.Item[FIndex];
         if Assigned(FOnReadAddressList) then FOnReadAddressList(Self);
         end
      else
         objAddressList := Unassigned;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOAddressLists.EOF: Boolean;
begin
   Result := VarIsEmpty(objAddressList);
end;

procedure TCDOAddressLists.ProcessAddressLists;
var
   i: Integer;
begin
   if (not VarIsEmpty(objAddressLists)) then begin
      for i:=1 to Count do begin
         objAddressList := objAddressLists.Item[i];
         if Assigned(FOnReadAddressList) then FOnReadAddressList(Self);
      end;
   end;
end;

{ TCDOInfoStores }

constructor TCDOInfoStores.Create(AOwner: TComponent);
begin
   inherited Create(AOwner);
   FCDOInfoStore := TCDOInfoStore.Create(Self);
   FobjInfoStore := Unassigned;
   FIndex := 1;
end;

destructor TCDOInfoStores.Destroy;
begin
   inherited Destroy;
end;

function TCDOInfoStores.GetCount: Integer;
begin
   try
      Result := objInfoStores.Count;
   except
      Result := 0;
   end;
end;

procedure TCDOInfoStores.SetobjInfoStore(Value: OleVariant);
begin
   FobjInfoStore := Value;
   CDOInfoStore.Clear;
   if not VarIsEmpty(Value) then begin
      FRootFolder := objInfoStore.RootFolder;
      CDOFields.objFields := objInfoStore.Fields;
      CDOInfoStore.InfoStoreName := objInfoStore.Name;
      CDOInfoStore.ID := objInfoStore.ID;
      CDOInfoStore.Flags := objInfoStore.Fields.Item[PR_RESOURCE_FLAGS].Value;
      {}
      DebugCDOField(CDOInfoStore.ID+'.InfoStore');
   end;
end;

function TCDOInfoStores.GetFirst: Boolean;
begin
   FIndex := 1;
   ClearErrors;
   try
      if FIndex <= Count then begin
         objInfoStore := objInfoStores.Item[FIndex];
         //if Assigned(FOnReadInfoStore) then FOnReadInfoStore(Self);
         end
      else
         objInfoStore := Unassigned;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOInfoStores.GetNext: Boolean;
begin
   Inc(FIndex);
   ClearErrors;
   try
      if FIndex <= Count then begin
         objInfoStore := objInfoStores.Item[FIndex];
         //if Assigned(FOnReadInfoStore) then FOnReadInfoStore(Self);
         end
      else
         objInfoStore := Unassigned;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOInfoStores.GetLast: Boolean;
begin
   FIndex := Count;
   ClearErrors;
   try
      if FIndex > 0 then begin
         objInfoStore := objInfoStores.Item[FIndex];
         //if Assigned(FOnReadInfoStore) then FOnReadInfoStore(Self);
         end
      else
         objInfoStore := Unassigned;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOInfoStores.GetPrev: Boolean;
begin
   Dec(FIndex);
   ClearErrors;
   try
      if FIndex > 0 then begin
         objInfoStore := objInfoStores.Item[FIndex];
         //if Assigned(FOnReadInfoStore) then FOnReadInfoStore(Self);
         end
      else
         objInfoStore := Unassigned;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOInfoStores.EOF: Boolean;
begin
   Result := VarIsEmpty(objInfoStore);
end;

{ TCDOFolders }

constructor TCDOFolders.Create(AOwner: TComponent);
begin
   inherited Create(AOwner);
   FCDOFolder := TCDOFolder.Create(Self);
   FCollectionFolders := TCollection.Create(TCDOFolderItem);
   FobjFolders := Unassigned;
   FobjFolder := Unassigned;
end;

destructor TCDOFolders.Destroy;
begin
   FCollectionFolders.Clear;
   FCollectionFolders.Free;
   inherited Destroy;
end;

function TCDOFolders.GetCount: Integer;
begin
   try
      Result := objFolders.Count;
   except
      Result := 0;
   end;
end;

procedure TCDOFolders.SetObjFolder(Value: OleVariant);
begin
   FobjFolder := Value;
   CDOFolder.Clear;
   if not VarIsEmpty(Value) then begin
      CDOFields.objFields := objFolder.Fields;
      CDOFolder.FolderName := objFolder.Name;
      CDOFolder.FolderID := objFolder.FolderID;
      CDOFolder.ID := objFolder.ID;
      CDOFolder.StoreID := objFolder.StoreID;
      CDOFolder.Address := '';
      try
         CDOFolder.Flags := objFolder.Fields.Item[PR_RESOURCE_FLAGS].Value;
      except
         CDOFolder.Flags := 0;
      end;
      DebugCDOField(CDOFolder.ID+'.Folder');
   end;
end;

function TCDOFolders.GetFirst: Boolean;
begin
   ClearErrors;
   try
      objFolder := objFolders.GetFirst;
      if not EOF then
      if Assigned(FOnReadFolder) then FOnReadFolder(Self);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOFolders.GetNext: Boolean;
begin
   ClearErrors;
   try
      objFolder := objFolders.GetNext;
      if not EOF then
      if Assigned(FOnReadFolder) then FOnReadFolder(Self);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOFolders.GetLast: Boolean;
begin
   ClearErrors;
   try
      objFolder := objFolders.GetLast;
      if not EOF then
      if Assigned(FOnReadFolder) then FOnReadFolder(Self);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOFolders.GetPrev: Boolean;
begin
   ClearErrors;
   try
      objFolder := objFolders.GetPrevious;
      if not EOF then
      if Assigned(FOnReadFolder) then FOnReadFolder(Self);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOFolders.EOF: Boolean;
begin
   Result := VarIsEmpty(objFolder);
end;

procedure TCDOFolders.CreateCollectionFolders(CDOInfoStores: TCDOInfoStores);
var
   i: Integer;

   procedure GetTreeFolders(RootFolder: OleVariant);
   var
      Folders: OleVariant;
      Folder: OleVariant;
      CDOFolder: TCDOFolder;
   begin
      Folders := RootFolder.Folders;
      Folder := Folders.GetFirst;
      while not VarIsEmpty(Folder) do begin
         CDOFolder := TCDOFolder.Create(Self);
         CDOFolder.FolderName := Folder.Name;
         CDOFolder.FolderID := Folder.FolderID;
         CDOFolder.ID := Folder.ID;
         CDOFolder.StoreID := Folder.StoreID;
         CDOFolder.Address := '';
         with FCollectionFolders.Add as TCDOFolderItem do Item := CDOFolder;
         if Folder.Folders.Count > 0 then GetTreeFolders(Folder);
         Folder := Folders.GetNext;
         //Application.ProcessMessages;
      end;
   end;
begin
   FCollectionFolders.Clear;
   if not VarIsEmpty(CDOInfoStores.objInfoStores) then begin
      CDOInfoStores.GetFirst;
      while not CDOInfoStores.EOF do begin
         CDOInfoStores.objInfoStore := CDOInfoStores.objInfoStores.Item[i];
         GetTreeFolders(CDOInfoStores.objInfoStore.RootFolder);
         CDOInfoStores.GetNext;
         //Application.ProcessMessages;
      end;
   end;
end;

function TCDOFolders.GetFolders(CDOInfoStores: TCDOInfoStores): TCollection;
begin
   CreateCollectionFolders(CDOInfoStores);
   Result := FCollectionFolders;
end;

procedure TCDOFolders.ProcessFolders(CDOInfoStores: TCDOInfoStores);

   procedure GetTreeFolders(RootFolder: OleVariant);
   var
      Folders: OleVariant;
   begin
      Folders := RootFolder.Folders;
      objFolder := Folders.GetFirst;
      Inc(FLevel);
      while not EOF do begin
         if objFolder.Folders.Count > 0 then
            GetTreeFolders(objFolder);
         objFolder := Folders.GetNext;
         //Application.ProcessMessages;
      end;
      Dec(FLevel);
   end;

begin
   if not VarIsEmpty(CDOInfoStores.objInfoStores) then begin
      CDOInfoStores.GetFirst;
      while not CDOInfoStores.EOF do begin
         FLevel := 0;
         GetTreeFolders(CDOInfoStores.objInfoStore.RootFolder);
         CDOInfoStores.GetNext;
         //Application.ProcessMessages;
      end;
   end;
end;

(*
function TCDOFolders.GetFolderByName(Value: string): Boolean;
var
   i: Integer;
   F: TCDOFolderItem;
begin
   Result := False;
   FStatus := 0;
   ClearErrors;
   try
      objFolder := objFolders.GetLast;
      CreateCollectionFolders;
      Result := Unassigned;
      for i:=0 to FCollectionFolders.Count-1 do begin
         F := (FCollectionFolders.Items[i] as TCDOFolderItem);
         if AnsiUpperCase(F.Item.FolderName) = AnsiUpperCase(Value) then begin
            objFolder := objSession.GetFolder(F.Item.ID, F.Item.StoreID);
            Break;
         end;
      end;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;
*)

{ TCDOAttachments }

constructor TCDOAttachments.Create(AOwner: TComponent);
begin
   inherited Create(AOwner);
   FCDOAttachment := TCDOAttachment.Create(Self);
   FPathNames := TStringList.Create;
   FFileNames := TStringList.Create;
   FobjAttachments := Unassigned;
   FobjAttachment := Unassigned;
   AttachmentDir := '';
end;

destructor TCDOAttachments.Destroy;
begin
   FFileNames.Free;
   FPathNames.Free;
   StrDispose(FAttachmentDir);
   inherited Destroy;
end;

function TCDOAttachments.GetCount: Integer;
begin
   try
      Result := objAttachments.Count;
   except
      Result := 0;
   end;
end;

procedure TCDOAttachments.SetObjAttachment(Value: OleVariant);
var
   LFileName: string;
   AM: Integer;
begin
   FobjAttachment := Value;
   CDOAttachment.Clear;
   if not VarIsEmpty(Value) then begin
      // FileNames.Clear;
      CDOFields.objFields := objAttachment.Fields;
      CDOAttachment.AttachmentName := objAttachment.Name;
      CDOAttachment.Position := objAttachment.Position;
      CDOAttachment.AttachmentType := objAttachment.Type;
      DebugCDOField(TCDOMessages(Owner).MailID+'.Attachment');
      AM := objAttachment.Fields.Item[PR_ATTACH_METHOD].Value;
      if (AM = ATTACH_BY_VALUE) or (AM = ATTACH_BY_REFERENCE) or
         (AM = ATTACH_BY_REF_RESOLVE) or (AM = ATTACH_BY_REF_ONLY) then begin
         LFileName := objAttachment.Name;
         try
            LFileName := objAttachment.Fields.Item[PR_ATTACH_LONG_FILENAME].Value;
         except
         end;
         FileNames.Add(LFileName);
      end;
   end;
end;

procedure TCDOAttachments.SetObjAttachments(Value: OleVariant);
var
   i: Integer;
begin
   FobjAttachments := Value;
   FFileNames.Clear;
   for i:=1 to Count do begin
      objAttachment := objAttachments.Item[i];
   end;
end;

function TCDOAttachments.GetAttachmentDir: string;
begin
   Result := StrPas(FAttachmentDir);
end;
procedure TCDOAttachments.SetAttachmentDir(const Value: string);
begin
   if FAttachmentDir <> nil then StrDispose(FAttachmentDir);
   FAttachmentDir := StrAlloc(Length(Value)+1);
   StrPCopy(FAttachmentDir, Value);
end;

function TCDOAttachments.GetAttachmentFileName: string;
begin
   Result := StrPas(FAttachmentFileName);
end;
procedure TCDOAttachments.SetAttachmentFileName(const Value: string);
begin
   if FAttachmentFileName <> nil then StrDispose(FAttachmentFileName);
   FAttachmentFileName := StrAlloc(Length(Value)+1);
   StrPCopy(FAttachmentFileName, Value);
end;

procedure TCDOAttachments.ProcessAttachments(const AttachDir, FileName: string);
var
   i: Integer;
   LFileName: string;
   LPathName: string;
   D : string;
   FileHandle : Integer;
   LFileDate: Integer;
begin
   AttachmentDir := AttachDir;
   AttachmentFileName := FileName;
   if AttachDir <> '' then begin
      FFileNames.Clear;
      FPathNames.Clear;
      for i:=1 to Count do begin
         objAttachment := objAttachments.Item[i];
         LFileName := FileNames.Strings[FileNames.Count-1];
         { write file to AttachDir }
         if (FileName = '') or (AnsiUpperCase(FileName) = AnsiUpperCase(LFileName)) then begin
            LPathName := IncludeTrailingBackslash(AttachDir)+LFileName;
            if Assigned(FOnReadAttachment) then FOnReadAttachment(Self);
            try
               objAttachment.WriteToFile(LPathName);
               PathNames.Add(LPathName);
               // set attribute and datetime
               try
                  D := objAttachment.Fields.Item[PR_CREATION_TIME].Value;
                  D := ReplaceStr(D, '.', DateSeparator);
                  LFileDate := DateTimeToFileDate(StrToDateTime(D));
               except
                  LFileDate := DateTimeToFileDate(Now);
               end;
               FileHandle := FileOpen(LPathName, fmOpenReadWrite);
               try
                  FileSetDate(FileHandle, LFileDate);
               except
               end;
               FileClose(FileHandle);
            except
               on E: Exception do begin
                  MAPIHandleException(E);
                  Errors.Add('Error write to file: '+LPathName);
               end;
            end;
         end;
      end;
   end;
end;

{ TCDORecipients }

constructor TCDORecipients.Create(AOwner: TComponent);
begin
   inherited Create(AOwner);
   FCDORecipient := TCDORecipient.Create(Self);
   FCDOAddressEntry := TCDOAddressEntry.Create(Self);
   FobjRecipients := Unassigned;
   FobjRecipient := Unassigned;
   FobjAddressEntry := Unassigned;
   FAddress_TO := TStringList.Create;
   FAddress_CC := TStringList.Create;
   FAddress_BCC := TStringList.Create;
end;

destructor TCDORecipients.Destroy;
begin
   FAddress_BCC.Free;
   FAddress_CC.Free;
   FAddress_TO.Free;
   inherited Destroy;
end;

function TCDORecipients.GetCount: Integer;
begin
   try
      Result := objRecipients.Count;
   except
      Result := 0;
   end;
end;

procedure TCDORecipients.SetObjRecipients(Value: OleVariant);
begin
   FobjRecipients := Value;
   FAddress_TO.Clear;
   FAddress_CC.Clear;
   FAddress_BCC.Clear;
end;

procedure TCDORecipients.SetObjRecipient(Value: OleVariant);
var
   s: string;
begin
   FobjRecipient := Value;
   CDORecipient.Clear;
   if not VarIsEmpty(Value) then begin
      try
         CDORecipient.Address := objRecipient.Address;
         CDORecipient.RecipientName := objRecipient.Name;
         try
            CDORecipient.ID := objRecipient.ID;
         except
         end;
         CDORecipient.RecipientType := objRecipient.Type;
         {}
         try
            objAddressEntry := objRecipient.AddressEntry;
            CDOFields.objFields := objAddressEntry.Fields;
            CDOAddressEntry.AddressEntryName := objAddressEntry.Name;
            CDOAddressEntry.ID := objAddressEntry.ID;
            CDOAddressEntry.Address := objAddressEntry.Address;
            CDOAddressEntry.AddressType := objAddressEntry.Type;
            DebugCDOField(CDOAddressEntry.ID+'.AddressEntry');
         except
         end;
         {}
         s := objRecipient.Name;
         case objRecipient.Type of
            MAPI_TO : Address_TO.Add(s);
            MAPI_CC : Address_CC.Add(s);
            MAPI_BCC: Address_BCC.Add(s);
         end;
      except
         on E: Exception do begin
            MAPIHandleException(E);
         end;
      end;
   end;
end;

procedure TCDORecipients.ProcessRecipients;
var
   i: Integer;
begin
   for i:=1 to Count do begin
      objRecipient := objRecipients.Item[i];
      if Assigned(FOnReadRecipient) then FOnReadRecipient(Self);
   end;
end;

function TCDORecipients.Resolve: Boolean;
begin
   ClearErrors;
   try
      objRecipients.Resolve(False);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
   if Result then begin
      try
         Result := objRecipients.Resolved;
      except
         on E: Exception do begin
            Result := False;
            MAPIHandleException(E);
         end;
      end;
   end;
end;

function TCDORecipients.AddRecipient(RecipientName: string; RecipientType: Integer): Boolean;
var
   LobjRecipient: OleVariant;
begin
   ClearErrors;
   try
      LobjRecipient := objRecipients.Add;
      //LobjRecipient.AddressEntry := Unassigned;
      LobjRecipient.Name := RecipientName;
      LobjRecipient.Type := RecipientType;
      LobjRecipient.Resolve(False); // get MAPI to determine complete e-mail address
      Result := not VarIsEmpty(LobjRecipient.AddressEntry);
      if Result then begin
         case RecipientType of
            MAPI_TO:  Address_TO.Add(REcipientName);
            MAPI_CC:  Address_CC.Add(REcipientName);
            MAPI_BCC: Address_BCC.Add(REcipientName);
         end;
      end;
   except
      on E: Exception do begin
         Result := False;
         MAPIHandleException(E);
         Errors.Add('Not resolve: '+REcipientName);
      end;
   end;
end;

function TCDORecipients.AddAddressTO(Address: string): Boolean;
begin
   Result := AddRecipient(Address, MAPI_TO);
end;

function TCDORecipients.AddAddressCC(Address: string): Boolean;
begin
   Result := AddRecipient(Address, MAPI_CC);
end;

function TCDORecipients.AddAddressBCC(Address: string): Boolean;
begin
   Result := AddRecipient(Address, MAPI_BCC);
end;

function TCDORecipients.ResolveRecipientAddress(RecipientAddress: string;
   RecipientType: Integer; ShowDialog: Boolean): Boolean;
// RecipientType={1|2|3} {To|Cc|Bcc}
var
   LobjRecipient: OleVariant;
   i: Integer;
begin
   Result := False;
   ClearErrors;
   try
      LobjRecipient := objRecipients.Add;
      //LobjRecipient.AmbiguousNames := Unassigned;
      //LobjRecipient.AddressEntry := Unassigned;
      LobjRecipient.Name := RecipientAddress;
      LobjRecipient.Type := RecipientType;
      LobjRecipient.Resolve(ShowDialog); // get MAPI to determine complete e-mail address
      Result := not VarIsEmpty(LobjRecipient.AddressEntry);
      objRecipient := LobjRecipient;
      objAmbiguousNames := Unassigned;
   except
      on E: Exception do begin
         i := 0;
         objAmbiguousNames := LobjRecipient.AmbiguousNames;
         if not VarIsEmpty(objAmbiguousNames) then begin
            i := LobjRecipient.AmbiguousNames.Count;
         end;
         if i > 0 then begin
            Result := True;
            try
               LobjRecipient.Resolve(True);
               Result := not VarIsEmpty(LobjRecipient.AddressEntry);
               objRecipient := LobjRecipient;
               objAmbiguousNames := Unassigned;
            except
               on E: Exception do begin
                  Result := False;
                  MAPIHandleException(E);
                  Errors.Add('Not resolve: '+REcipientAddress);
               end;
            end;
            end
         else begin
            Result := False;
            MAPIHandleException(E);
            Errors.Add('Not resolve: '+REcipientAddress);
         end;
      end;
   end;
end;

{ TCDOMessageFilter }

constructor TCDOMessageFilter.Create(AOwner: TComponent);
begin
   inherited Create(AOwner);
   FCDOMessageFilterItem := TCDOMessageFilterItem.Create(Self);
   FobjMessageFilter := Unassigned;
end;

destructor TCDOMessageFilter.Destroy;
begin
   inherited Destroy;
end;

procedure TCDOMessageFilter.SetobjMessageFilter(Value: OleVariant);
var
   s: string;
begin
   FobjMessageFilter := Value;
   CDOMessageFilterItem.Clear;
   if not VarIsEmpty(Value) then begin
      CDOFields.objFields := objMessageFilter.Fields;
      { Recipients }
      CDOMessageFilterItem.Recipients := objMessageFilter.Recipients;
      { Subject }
      CDOMessageFilterItem.Subject := objMessageFilter.Subject;
      { Notetext}
      try
         s := objMessageFilter.Text;
         CDOMessageFilterItem.NoteText.SetText(PChar(s));
      except
      end;
      try
         CDOMessageFilterItem.Importance := objMessageFilter.Importance;
      except
      end;
      try
         CDOMessageFilterItem.Sent := objMessageFilter.Sent;
      except
      end;
      try
         CDOMessageFilterItem.Size := objMessageFilter.Size;
      except
      end;
      try
         CDOMessageFilterItem.TimeLast := objMessageFilter.TimeLast;
      except
      end;
      try
         CDOMessageFilterItem.TimeFirst := objMessageFilter.TimeFirst;
      except
      end;
      try
         CDOMessageFilterItem.TypeMessage := objMessageFilter.Type;
      except
      end;
      try
         CDOMessageFilterItem.Unread := objMessageFilter.Unread;
      except
      end;
      DebugCDOField('.MessageFilter');
   end;
end;

{ TCDOMessages }

constructor TCDOMessages.Create(AOwner: TComponent);
begin
   inherited Create(AOwner);
   FCDOMessage := TCDOMessage.Create(Self);
   FCDOAttachments := TCDOAttachments.Create(Self);
   FCDORecipients := TCDORecipients.Create(Self);
   FCDOMessageFilter := TCDOMessageFilter.Create(Self);
   FNewMessage := False;
end;

destructor TCDOMessages.Destroy;
begin
   inherited Destroy;
end;

procedure TCDOMessages.SetobjMessages (Value: OleVariant);
begin
   FobjMessages := Value;
   try
      CDOMessageFilter.objMessageFilter := objMessages.Filter;
      CDOMessageFilter.MAPILog := MAPILog;
   except
      CDOMessageFilter.objMessageFilter := Unassigned;
   end;
end;

procedure TCDOMessages.SetobjFolder (Value: OleVariant);
begin
   FobjFolder := Value;
   try
      objMessages := objFolder.Messages;
   except
      objMessages := Unassigned;
   end;
end;

procedure TCDOMessages.SetobjMessage(Value: OleVariant);
begin
   FobjMessage := Value;
   CDOMessage.Clear;
   if not VarIsEmpty(Value) then begin
      FCDOFields.FobjFields := objMessage.Fields;
      {}
      CDORecipients.objRecipients := objMessage.Recipients;
      CDORecipients.MAPILog := MAPILog;
      CDOAttachments.objAttachments := objMessage.Attachments;
      CDOAttachments.MAPILog := MAPILog;
      {}
      ReadMail;
      DebugCDOField(MailID+'.Message');
   end;
end;

procedure TCDOMessages.SetOnReadAttachment (OnReadAttachment: TReadAttachmentEvent);
begin
   FOnReadAttachment := OnReadAttachment;
   CDOAttachments.OnReadAttachment := OnReadAttachment;
end;

procedure TCDOMessages.SetOnReadRecipient (OnReadRecipient: TReadRecipientEvent);
begin
   FOnReadRecipient := OnReadRecipient;
   CDORecipients.OnReadRecipient := OnReadRecipient;
end;

function TCDOMessages.ReadMessage: Boolean;
var
   CM: string;
   s: string;
begin
   ClearErrors;
   { Subject }
   CDOMessage.Subject := objMessage.Subject;
   { Notetext }
   CDOMessage.NoteText.Clear;
   CDOMessage.NoteText.SetText(PChar(VarToStr(objMessage.Text)));
   {}
   CDOMessage.Encrypted := objMessage.Encrypted;
   CDOMessage.Importance := objMessage.Importance;
   CDOMessage.Sent := objMessage.Sent;
   CDOMessage.Signed := objMessage.Signed;
   CDOMessage.Size := objMessage.Size;
   try
      CDOMessage.FolderID := objMessage.FolderID;
   except
   end;
   try
      CDOMessage.StoreID := objMessage.StoreID;
   except
   end;
   try
      CDOMessage.ID := objMessage.ID;
   except
   end;
   try
      CDOMessage.Sensitivity := objMessage.Sensitivity;
   except
   end;
   try
      CDOMessage.TimeCreated := objMessage.TimeCreated;
   except
   end;
   try
      CDOMessage.TimeLastModified := objMessage.TimeLastModified;
   except
   end;
   try
      CDOMessage.TimeReceived := objMessage.TimeReceived;
   except
   end;
   try
      CDOMessage.TimeSent := objMessage.TimeSent;
   except
   end;
   try
      CDOMessage.TimeExpired := objMessage.TimeExpired;
   except
   end;
   CDOMessage.TypeMessage := objMessage.Type;
   CDOMessage.Unread := objMessage.Unread;
   CDOMessage.DeliveryReceipt := objMessage.DeliveryReceipt;
   CDOMessage.ReadReceipt := objMessage.ReadReceipt;
   CDOMessage.Submitted := objMessage.Submitted;
   { Recipients }
   CDOMessage.Address_ORIG := '';
   CM := objMessage.Fields.Item[PR_MESSAGE_CLASS].Value;
   if (UpperCase(ExtractWordNew(2,CM,['.'])) = 'NOTE') or
      (UpperCase(ExtractWordNew(2,CM,['.'])) = 'POST') then begin
      if not FNewMessage then begin
         try
            CDOMessage.Address_ORIG := objMessage.Sender.Name;
            CDORecipients.ProcessRecipients;
         except
            on E: Exception do begin
               MAPIHandleException(E);
            end;
         end;
      end;
      CDOMessage.Address_TO.Assign(CDORecipients.Address_TO);
   end;
   { Attachments }
   CDOAttachments.objAttachments := objMessage.Attachments;
   CDOMessage.FileNames.Assign(CDOAttachments.FileNames);
   {}
   Result := (Status=SUCCESS_SUCCESS);
end;

procedure TCDOMessages.ExtractFiles(const AttachDir: string);
begin
   CDOAttachments.ProcessAttachments(AttachDir, '');
end;

procedure TCDOMessages.ExtractFile(const AttachDir,FileName: string);
begin
   CDOAttachments.ProcessAttachments(AttachDir, FileName);
end;

function TCDOMessages.ReadMail: Boolean;
begin
   Result := False;
   if not EOF then begin
      case objMessage.Class of
         CdoAppointment:   Result := ReadAppointment;
         CdoGroupHeader:   Result := ReadGroupHeader;
         CdoMeetingItem:   Result := ReadMeetingItem;
         //CdoMessageFilter: Result := ReadMessageFilter;
         CdoMsg:           Result := ReadMessage;
      end;
   end;
end;

function TCDOMessages.ReadAppointment: Boolean;
begin
   ClearErrors;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOMessages.ReadGroupHeader: Boolean;
begin
   ClearErrors;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOMessages.ReadMeetingItem: Boolean;
begin
   ClearErrors;
   Result := (Status=SUCCESS_SUCCESS);
end;

//function TCDOMessages.ReadMessageFilter: Boolean;
//begin
//   ClearErrors;
//   Result := (Status=SUCCESS_SUCCESS);
//end;

function TCDOMessages.GetFirst: Boolean;
begin
   //MAPILog.LogString[tlsInfo,0] := 'GetFirst '+GetCurrentDir;
   ClearErrors;
   try
      objMessage := objMessages.GetFirst;
      CDOAttachments.PathNames.Clear;
      if not EOF then
         if Assigned(FOnReadMailMessage) then FOnReadMailMessage(Self);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
   //MAPILog.LogString[tlsInfo,0] := 'GetFirst '+GetCurrentDir;
end;

function TCDOMessages.GetLast: Boolean;
begin
   ClearErrors;
   try
      objMessage := objMessages.GetLast;
      CDOAttachments.PathNames.Clear;
      if not EOF then
         if Assigned(FOnReadMailMessage) then FOnReadMailMessage(Self);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOMessages.GetNext: Boolean;
begin
   ClearErrors;
   try
      objMessage := objMessages.GetNext;
      CDOAttachments.PathNames.Clear;
      if not EOF then
         if Assigned(FOnReadMailMessage) then FOnReadMailMessage(Self);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOMessages.GetPrev: Boolean;
begin
   ClearErrors;
   try
      objMessage := objMessages.GetPrevious;
      CDOAttachments.PathNames.Clear;
      if not EOF then
         if Assigned(FOnReadMailMessage) then FOnReadMailMessage(Self);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOMessages.EOF: Boolean;
begin
   Result := VarIsEmpty(objMessage);
end;

procedure TCDOMessages.DeleteFiles;
var
   i: Integer;
   s: string;
begin
   for i:=0 to CDOAttachments.PathNames.Count-1 do begin
      s := CDOAttachments.PathNames.Strings[i];
      if FileExists(s) then SysUtils.DeleteFile(s);
   end;
end;

procedure TCDOMessages.WriteMail(const FileName: string);
var
   DestStream: TFileStream;

   procedure WriteStream(const s: string; ADestStream: TFileStream);
   var
      PS: PChar;
   begin
      PS := StrAlloc(Length(s)+1); StrPCopy(PS,S);
      ADestStream.WriteBuffer(PS[0], Length(s));
      StrDispose(PS);
   end;

begin
   try
      DestStream := TFileStream.Create(FileName, fmOpenWrite or fmCreate);
   except
      DestStream := nil;
   end;

   if DestStream <> nil then begin
      { }
//      WriteStream('PR_ENTRYID:'#13#10, DestStream);
//      WriteStream(objMessage.Fields.Item[PR_ENTRYID].Value+#13#10#13#10, DestStream);;
      { }
      WriteStream('FROM:'#13#10, DestStream);
      WriteStream(CDOMessage.Address_ORIG+#13#10#13#10, DestStream);
      { }
      if CDORecipients.Address_TO.Count > 0 then begin
         WriteStream('TO:'#13#10, DestStream);
         CDORecipients.Address_TO.SaveToStream(DestStream);
         WriteStream(#13#10, DestStream);
      end;
      { }
      if CDORecipients.Address_CC.Count > 0 then begin
         WriteStream('CC:'#13#10, DestStream);
         CDORecipients.Address_CC.SaveToStream(DestStream);
         WriteStream(#13#10, DestStream);
      end;
      { }
      if CDORecipients.Address_BCC.Count > 0 then begin
         WriteStream('BCC:'#13#10, DestStream);
         CDORecipients.Address_BCC.SaveToStream(DestStream);
         WriteStream(#13#10, DestStream);
      end;
      { }
      WriteStream('SUBJECT:'#13#10, DestStream);
      WriteStream(CDOMessage.Subject+#13#10#13#10, DestStream);
      {
      WriteStream('TimeCreated:  ', DestStream);
      WriteStream(DateTimeToStr(objMessage.TimeCreated)+#13#10, DestStream);
      WriteStream('TimeReceived: ', DestStream);
      WriteStream(DateTimeToStr(objMessage.TimeReceived)+#13#10, DestStream);
      WriteStream('TimeSent:     ', DestStream);
      WriteStream(DateTimeToStr(objMessage.TimeSent)+#13#10, DestStream);
      }
      if CDOMessage.NoteText.Count > 0 then begin
         WriteStream('TEXT:'#13#10, DestStream);
         CDOMessage.NoteText.SaveToStream(DestStream);
         WriteStream(#13#10, DestStream);
      end;
      if CDOAttachments.FileNames.Count > 0 then begin
         WriteStream('ATTACHFILES:'#13#10, DestStream);
         CDOAttachments.FileNames.SaveToStream(DestStream);
         WriteStream(#13#10, DestStream);
      end;
      DestStream.Free;
   end;
end;

procedure TCDOMessages.FormatMail(const FileName: string);
var
   Parse: TLUParser;
   SourceStream: TFileStream;
   T : TStringList;
   MailFrom : TStringList;
   MailTo : TStringList;
   MailSubject : TStringList;
   MailText : TStringList;
   Token: string;
   s : string;

begin
   SourceStream := TFileStream.Create(FileName, fmOpenRead);
   Parse := TLUParser.Create(nil);
   Parse.Stream := SourceStream;
   MailFrom := TStringList.Create;
   MailTo := TStringList.Create;
   MailSubject := TStringList.Create;
   MailText := TStringList.Create;
   T := MailText;
   { WinCode }
   Parse.WinCode := False;
   while Parse.Token <> toEOF do begin
      Token := Parse.TokenString;
      if not Parse.WinCode then
         OEMToChar(PChar(Token), PChar(Token));
      case Parse.Token of
         toSymbol: begin
            if AnsiUpperCase(Trim(Token)) = 'SUBJECT:' then
               T := MailSubject
            else
            if AnsiUpperCase(Trim(Token)) = 'TEXT:' then
               T := MailText
            else
            if AnsiUpperCase(Trim(Token)) = 'FROM:' then
               T := MailFrom
            else
            if AnsiUpperCase(Trim(Token)) = 'TO:' then
               T := MailTo
            else
               if T <> nil then T.Add(Token);
         end;
      else begin
         if T <> nil then T.Add(Token);
      end;
      end;
      Parse.NextToken;
   end;
   if MailSubject.Count > 0 then begin
      CDOMessage.Subject := StrPas(MailSubject.GetText);
   end;
   if MailText.Count > 0 then begin
      CDOMessage.NoteText.SetText(MailText.GetText);
   end;
   if MailFrom.Count > 0 then begin
      s := T.Strings[0];
      CDOMessage.Address_ORIG := s;
   end;
   if MailTo.Count > 0 then begin
      s := T.Strings[0];
      CDORecipients.Address_TO.Add(s);
   end;
   MailTo.Free;
   MailFrom.Free;
   MailSubject.Free;
   MailText.Free;
   Parse.Free;
   SourceStream.Free;
end;

procedure TCDOMessages.FormatMailNew(const FileName: string);
var
   Parse: TLUParser;
   SourceStream: TFileStream;
   T           : PChar;
   MailFrom    : PChar;
   MailTo      : PChar;
   MailSubject : PChar;
   MailText    : PChar;
   Token: string;

begin
   SourceStream := TFileStream.Create(FileName, fmOpenRead);
   Parse := TLUParser.Create(nil);
   Parse.Stream := SourceStream;
   MailFrom := StrAlloc(High(Smallint));
   StrPCopy(MailFrom, '');
   MailTo := StrAlloc(High(Smallint));
   StrPCopy(MailTo, '');
   MailSubject := StrAlloc(High(Smallint));
   StrPCopy(MailSubject, '');
   MailText := StrAlloc(High(Smallint));
   StrPCopy(MailText, '');
   T := MailText;
   { WinCode }
   Parse.WinCode := False;
   while Parse.Token <> toEOF do begin
      Token := Parse.TokenString;
      if not Parse.WinCode then
         OEMToChar(PChar(Token), PChar(Token));
      case Parse.Token of
         toSymbol: begin
            if AnsiUpperCase(Trim(Token)) = 'SUBJECT:' then
               T := MailSubject
            else
            if AnsiUpperCase(Trim(Token)) = 'TEXT:' then
               T := MailText
            else
            if AnsiUpperCase(Trim(Token)) = 'FROM:' then
               T := MailFrom
            else
            if AnsiUpperCase(Trim(Token)) = 'TO:' then
               T := MailTo
            else begin
               if T <> nil then begin
                  StrCat(T, PChar(Token));
               end;
            end;
         end;
      else begin
         if T <> nil then StrCat(T, PChar(Token));
      end;
      end;
      Parse.NextToken;
   end;
   if StrLen(MailSubject) > 0 then begin
      CDOMessage.Subject := StrPas(MailSubject);
   end;
   if StrLen(MailText) > 0 then begin
      CDOMessage.NoteText.SetText(MailText);
   end;
   if StrLen(MailFrom) > 0 then begin
      CDOMessage.Address_ORIG := StrPas(MailFrom);
   end;
   if StrLen(MailTo) > 0 then begin
      CDOREcipients.Address_TO.SetText(MailTo);
   end;
   StrDispose(MailTo);
   StrDispose(MailFrom);
   StrDispose(MailSubject);
   StrDispose(MailText);
   Parse.Free;
   SourceStream.Free;
end;

function TCDOMessages.DeleteMail: Boolean;
begin
   ClearErrors;
   try
      objMessage.Delete(False);
      CDOAttachments.PathNames.Clear;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOMessages.Options(ParentWindow: Longint): Boolean;
begin
   ClearErrors;
   try
      objMessage.Options(ParentWindow);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOMessages.UpdateMail: Boolean;
begin
   ClearErrors;
   try
      objMessage.Update(True, False);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOMessages.CopyToMail(const FolderID,StoreID: string): Boolean;
var
   LobjMessage: OleVariant;
begin
   ClearErrors;
   try
      LobjMessage := objMessage.CopyTo(FolderID,StoreID);
      LobjMessage.Update(True, False);
      objMessage := LobjMessage;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

{ CreateAddressTO }

function TCDOMessages.CreateAddressTO(const AddressTO: string): Boolean;
var
   i: Integer;
   s: string;
begin
   Result := False;
   for i:=1 to WordCountNew(AddressTO,[',',';']) do begin
      Result := True;
      s := ExtractWordNew(i, AddressTO, [',',';']);
      if i = 1 then
         CDORecipients.AddAddressTO(s)
      else
         CDORecipients.AddAddressCC(s);
   end;
end;

function TCDOMessages.AddRecipient_obj(AobjMessage: OleVariant; RecipientName: string; RecipientType: Integer): Boolean;
var
   LobjRecipient: OleVariant;
begin
   try
      LobjRecipient := AobjMessage.Recipients.Add;
      //LobjRecipient.AddressEntry := Unassigned;
      LobjRecipient.Name := RecipientName;
      LobjRecipient.Type := RecipientType;
      LobjRecipient.Resolve(False); // get MAPI to determine complete e-mail address
      Result := not VarIsEmpty(LobjRecipient.AddressEntry);
   except
      on E: Exception do begin
         Result := False;
         MAPIHandleException(E);
         Errors.Add('Not resolve: '+REcipientName);
      end;
   end;
end;

{ CreateAddressTO_obj }

function TCDOMessages.CreateAddressTO_obj(AobjMessage: OleVariant; const AddressTO: string): Boolean;
var
   i: Integer;
   s: string;
begin
   Result := False;
   for i:=1 to WordCountNew(AddressTO,[',',';']) do begin
      s := ExtractWordNew(i, AddressTO, [',',';']);
      if i = 1 then
         Result := AddRecipient_obj(AobjMessage,s, MAPI_TO)
      else
         Result := AddRecipient_obj(AobjMessage,s, MAPI_CC);
   end;
end;

function TCDOMessages.ForwardMail(const AddressTO: string): Boolean;
var
   LobjMessage: OleVariant;
   LobjRecipient: OLEVariant;
   LNoteText: PChar;
   LNote: TStringList;
   s: string;
begin
   ClearErrors;
   try
      LobjMessage := objMessage.Forward;
      LobjMessage.Update(True, False);
      { Subject }
      LobjMessage.Subject := 'FW: '+CDOMessage.Subject;
      { Note }
      LNote := TStringList.Create;
      LNoteText := StrAlloc(StrLen(CDOMessage.NoteText.GetText)+2+
                   Cardinal(CDOAttachments.PathNames.Count)+1);
      StrCopy(LNoteText, CDOMessage.NoteText.GetText);
      StrCat(LNoteText, PChar(#13#10 + StringOfChar(' ',CDOAttachments.PathNames.Count)));
      //LobjMessage.Text := StrPas(LNoteText);
      LNote.SetText(LNoteText);
      LNote.Insert(0, '');
      LNote.Insert(0, '');
      LNote.Insert(0, 'Тема:	'+CDOMessage.Subject);
      s := StrPas(CDOMessage.Address_TO.GetText);
      Delete(s, Length(s)-1, 2);
      LNote.Insert(0, 'Кому:	'+S);
      LNote.Insert(0, 'Отправлено:	'+VarToStr(CDOMessage.TimeSent));
      LNote.Insert(0, 'От:	'+CDOMessage.Address_ORIG);
      LNote.Insert(0, '-----Исходное сообщение-----');
      LNote.Insert(0, '');
      LobjMessage.Text := StrPas(LNote.GetText);
      StrDispose(LNoteText);
      LNote.Free;

      (*
      LobjRecipient := LobjMessage.Recipients.Add;
      LobjRecipient.Name := AddressTo;
      LobjRecipient.Type := MAPI_TO;
      LobjRecipient.Resolve(False); // get MAPI to determine complete e-mail address
      if not VarIsEmpty(LobjRecipient.AddressEntry) then begin
         try
            LobjMessage.Send(False, False, 0); // showDialog:=False
         except
            on E: Exception do begin
               MAPIHandleException(E);
            end;
         end;
       end;
       *)
       if CreateAddressTO_obj(LobjMessage, AddressTO) then begin
          LobjMessage.Send(False, False, 0); // showDialog:=False
       end;


   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOMessages.MoveToMail(const FolderID,StoreID: string): Boolean;
var
   LobjMessage: OleVariant;
begin
   ClearErrors;
   if (FolderID <> '') and (StoreID <> '') then begin
      try
         LobjMessage := objMessage.MoveTo(FolderID,StoreID);
         LobjMessage.Update(True, False);
         objMessage := LobjMessage;
      except
         on E: Exception do begin
            MAPIHandleException(E);
         end;
      end;
      end
   else begin
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOMessages.GetMailID: string;
var
   s: string;
begin
   try
      s := objMessage.ID;
      Result := Copy(s,Length(s)-15,16);
   except
      Result := '';
   end;
end;

function TCDOMessages.GetCount: Integer;
begin
   try
      Result := objMessages.Count;
   except
      Result := 0;
   end;
end;

function TCDOMessages.CreateMail(const MailType: string): Boolean;
// IPM.Note
// IPM.Document.Excel.Sheet.8
var
   LobjMessage: OleVariant;
begin
   FNewMessage := True;
   ClearErrors;
   try
      if Trim(MailType) = '' then
         LobjMessage := objFolder.Messages.Add('','','IPM.Note',CdoNormal)
      else
         LobjMessage := objFolder.Messages.Add('','',MailType,CdoNormal);
      LobjMessage.Update(True, False);
      objMessage := LobjMessage;
      CDOAttachments.PathNames.Clear;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;
(*
function TCDOMessages.CreateExcel(const Subject: string): Boolean;
var
   LobjMessage: OleVariant;
begin
   ClearErrors;
   try
      LobjMessage := objFolder.Messages.Add(Subject,'','IPM.Document.Excel.Sheet.8');
      LobjMessage.Update(True, False);
      objMessage := LobjMessage;
      CDOAttachments.PathNames.Clear;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;
*)
function TCDOMessages.FormatSendMail: Boolean;
var
   i: Integer;
   LNoteText: PChar;
   LName: string;
   LSource: string;
   LPosition: Longint;
begin
   (*
    .Subject = "Used car wanted"
    .Text = "Wanted: Used car in good condition with low mileage."
    .ConversationTopic = .Subject
    .ConversationIndex = Util_GetEightByteTimeStamp() ' utility
    .TimeReceived = Time
    .TimeSent = .TimeReceived
    .Sent = True
    .Submitted = False
    .Unread = True
    .Update ' .Send is not used for posting to a folder
   *)

   ClearErrors;
   objMessage.DeliveryReceipt := CDOMessage.DeliveryReceipt;
   objMessage.ReadReceipt := CDOMessage.ReadReceipt;
   objMessage.Encrypted := CDOMessage.Encrypted;
   objMessage.Importance := CDOMessage.Importance;
   try
      objMessage.Sensitivity := CDOMessage.Sensitivity;
   except
   end;

   objMessage.Unread := CDOMessage.Unread;
   objMessage.Unread := True;
   objMessage.Sent := CDOMessage.Sent;
   objMessage.Sent := False;
   objMessage.Submitted := CDOMessage.Submitted;
   objMessage.Submitted := False;
   objMessage.Signed := CDOMessage.Signed;

   try
      objMessage.TimeCreated := VarFromDateTime(Now);
   except
   end;
   try
      objMessage.TimeReceived := objMessage.TimeCreated;
   except
   end;
   try
      objMessage.TimeSent := objMessage.TimeCreated;
   except
   end;

   { From }
   try
      objMessage.Sender.Name := CDOMessage.Address_ORIG;
   except
   end;
   try
      objMessage.Sender := objMessage.Session.CurrentUser;
   except
   end;

   { Subject }
   objMessage.Subject := CDOMessage.Subject;

   { Note }
   LNoteText := StrAlloc(StrLen(CDOMessage.NoteText.GetText)+2+
                Cardinal(CDOAttachments.PathNames.Count)+1);
   StrCopy(LNoteText, CDOMessage.NoteText.GetText);
   StrCat(LNoteText, PChar(#13#10 + StringOfChar(' ',CDOAttachments.PathNames.Count)));
   objMessage.Text := StrPas(LNoteText);
   StrDispose(LNoteText);

   { Attachments }
   for i:=0 to CDOAttachments.PathNames.Count-1 do begin
      if i < CDOAttachments.FileNames.Count then
         LName := CDOAttachments.FileNames.Strings[i]
      else
         LName := ExtractFileName(CDOAttachments.PathNames.Strings[i]);
      LSource := CDOAttachments.PathNames.Strings[i];
      LPosition := StrLen(LNoteText)-Cardinal(CDOAttachments.PathNames.Count)+Cardinal(i);
      try
         CDOAttachments.objAttachment := objMessage.Attachments.Add(LName,LPosition,CDOFileData,LSource);
      except
         on E: Exception do begin
            MAPIHandleException(E);
            Errors.Add('Not found file '+CDOAttachments.PathNames.Strings[i]);
         end;
      end;
   end;
   Result := UpdateMail;
end;

function TCDOMessages.SendMail(SaveMessage: Boolean): Boolean;
begin
   FormatSendMail;
   try
      objMessage.Send(SaveMessage, False, 0); // showDialog:=False
      CDOAttachments.PathNames.Clear;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TCDOMessages.SendExcel: Boolean;
begin
   FormatSendMail;
   UpdateMail;
   Result := (Status=SUCCESS_SUCCESS);
end;

{ This procedure is used to register this component on the component palette }

procedure Register;
begin
   { CDO Libbrary }
   RegisterComponents('Luis', [TCDOSession]);
   RegisterComponents('Luis', [TCDOMessages]);
   RegisterComponents('Luis', [TCDOFolders]);
   RegisterComponents('Luis', [TCDOInfoStores]);
   RegisterComponents('Luis', [TCDOAddressLists]);
   RegisterComponents('Luis', [TCDOAddressEntries]);
end;

end.
