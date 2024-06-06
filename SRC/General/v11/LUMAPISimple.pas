unit LUMAPISimple;

interface

uses Classes, Windows, Forms, MAPI, COMObj, SysUtils, ActiveX, Registry,

     LUMAPITags,

     LUMAPI, LUParser, LUSupport, LUObjects;

type
   ArrayOfByte = array[0..0] of Byte;

type
   PArrayMAPIFileDesc = ^TArrayMAPIFileDesc;
   TArrayMAPIFileDesc = array [0..0] of TMAPIFileDesc;

   PArrayMapiRecipDesc = ^TArrayMapiRecipDesc;
   TArrayMapiRecipDesc = array [0..0] of TMapiRecipDesc;

   PArrayPMapiRecipDesc = ^TArrayPMapiRecipDesc;
   TArrayPMapiRecipDesc = array [0..0] of PMapiRecipDesc;

type
   TMapiRecip = class(TComponent)
   private
   public
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
   end;

type
   TMapiFile = class(TComponent)
   private
      FFileDesc: PMapiFileDesc;
      FMapiFile: TMapiFileDesc;
      FOffset: Integer;
      function GetFlags (const i: Integer): Cardinal;
   public
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      {}
      property FileDesc: PMapiFileDesc write FFileDesc;
      property Flags[const i: Integer]: Cardinal read GetFlags;
   end;

type
   TSimpleMAPISession = class(TCustomMAPISession)
   private
      { Login }
      FPSession: PLHANDLE;
      { Все поля сообщения }
      FSubject: PChar;
      FAddress_ORIG: PChar;
      FAddress_TO: TStringList;
      FAddress_CC: TStringList;
      FAddress_BCC: TStringList;
      FNoteText: TStringList;
      FPathNames: TStringList;
      FFileNames: TStringList;
      {}
      FMessageType: PChar;
      FDateReceived: PChar;
      FMessageFlags: FLAGS;
      { SendMail }
      FlpMessage: TMAPIMessage;
      { ReadMail }
      FMessageID: LPSTR;
      FMessageIDSave: LPSTR;
      FMessageIDSeed: LPSTR;
      FlppMessage: PMapiMessage;
      { FLAGS }
      FFindFlags: FLAGS;
      FReadFlags: FLAGS;
      FLogonFlags: FLAGS;
      {}
      FMapiFile: TMapiFile;
      { ResolveRecip }
      FResolveRecip: PMapiRecipDesc;
      { DetailsRecip }
      FDetailsRecip: TMapiRecipDesc;
      { NewRecips }
      FNewRecips: PMapiRecipDesc;
      FRecips: TMapiRecipDesc;
      FNNewRecips: PULONG;
      FnEditFields: Cardinal;
      FLabels: PChar;
      { Document }
      FDocFileNames: PChar;
      FDocFullPaths: PChar;
      FDocDelimChar: PChar;
      {}
      function GetSession: LHANDLE;
      {}
      function GetDocFullPaths: string;
      procedure SetDocFullPaths(const Value: string);
      function GetDocFileNames: string;
      procedure SetDocFileNames(const Value: string);
      function GetDocDelimChar: char;
      procedure SetDocDelimChar(const Value: char);
      function GetLabels: string;
      procedure SetLabels(const Value: string);
      {}
      function GetAddress_ORIG: string;
      procedure SetAddress_ORIG(const Value: string);
      function GetSubject: string;
      procedure SetSubject(const Value: string);
      function GetMessageType: string;
      procedure SetMessageType(const Value: string);
      function GetDateReceived: string;
      procedure SetDateReceived(const Value: string);
      {}
      procedure Clear;
      {}
      procedure ReadMailWork;
      {}
      function FindMessage(var AMessageIDSeed, AMessageID: PChar): Boolean;
      { ReadMail}
      function MessageFirst (aFindFlags: FLAGS): Boolean;
      function MessageNext (aFindFlags: FLAGS): Boolean;
      function MessageGETID (aFindFlags: FLAGS; AMessageID: LPSTR): Boolean;
      {}
      function ReadMail (aReadFlags: FLAGS): Boolean;
      function SaveMail: Boolean;
      {}
      function DeleteMail: Boolean;
      { SendDocuments }
      function SendDocuments: Boolean;
      { SendMail }
      function SendMail: Boolean;
      { }
      property Session: LHANDLE read GetSession;
      { ReadMail }
      property lppMessage: PMapiMessage read FlppMessage;
      property FindFlags: FLAGS read FFindFlags write FFindFlags;
      property ReadFlags: FLAGS read FReadFlags write FReadFlags;
      property MessageID: LPSTR read FMessageID write FMessageID;
      property MessageIDSave: LPSTR read FMessageIDSave write FMessageIDSave;
      property MessageIDSeed: LPSTR read FMessageIDSeed write FMessageIDSeed;
      { Documents }
      property DocFullPaths: string read GetDocFullPaths write SetDocFullPaths;
      property DocFileNames: string read GetDocFileNames write SetDocFileNames;
      property DocDelimChar: char read GetDocDelimChar write SetDocDelimChar;
      { Все поля сообщения }
      property Subject: string read GetSubject write SetSubject;
      property NoteText: TStringList read FNoteText;
      property Address_ORIG: string read GetAddress_ORIG write SetAddress_ORIG;
      property Address_TO: TStringList read FAddress_TO;
      property Address_CC: TStringList read FAddress_CC;
      property Address_BCC: TStringList read FAddress_BCC;
      property PathNames: TStringList read FPathNames;
      property FileNames: TStringList read FFileNames;
      { служебные }
      property MessageType: string read GetMessageType write SetMessageType;
      property DateReceived: string read GetDateReceived write SetDateReceived;
      property MessageFlags: FLAGS read FMessageFlags write FMessageFlags;
   public
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      { Logon/Logoff }
      function Logon: Boolean; override;
      function Logoff: Boolean; override;
      { ResolveName }
      function ResolveName (const AName: string; ShowDialog: Boolean): Boolean;
      function FreeResolveName: Boolean;
      function DetailsName (const AName: string): Boolean;
      { NewAddress }
      function NewAddress: Boolean;
      function FreeNewRecips: Boolean;
      {}
      function FreeMessage: Boolean;
      {}
      property LogonFlags: FLAGS read FLogonFlags write FLogonFlags;
      { ResolveName }
      property ResolveRecip: PMapiRecipDesc read FResolveRecip;
      property DetailsRecip: TMapiRecipDesc read FDetailsRecip;
      { NewAddress }
      property nEditFields: Cardinal read FnEditFields write FnEditFields;
      property NNewRecips: PULONG read FNNewRecips;
      property NewRecips: PMapiRecipDesc read FNewRecips;
      property Labels : string read GetLabels write SetLabels;
   end;

{ TSimpleMAPIMessage }

type
   TSimpleMAPIMessage = class(TObjects)
   private
      { поля сообщение }
      FAddress_ORIG: PChar;
      FSubject: PChar;
      FNoteText: TStringList;
      FPathNames: TStringList;
      FFileNames: TStringList;
      FAddress_TO: TStringList;
      FAddress_CC: TStringList;
      FAddress_BCC: TStringList;
      { служебные }
      FMessageID: LPSTR;
      FMessageIDSeed: LPSTR;
      FMessageIDSave: LPSTR;
      {}
      FMessageType: PChar;
      FMessageFlags: FLAGS;
      FTimeReceived: TDateTime;
      FUnread: Boolean;
      function GetAddress_ORIG: string;
      procedure SetAddress_ORIG(const Value: string);
      function GetSubject: string;
      procedure SetSubject(const Value: string);
      function GetMessageType: string;
      procedure SetMessageType(const Value: string);
      function GetUserFieldByName(const FieldsName: string): string;
      procedure SetUserFieldByName(const FieldsName, Value: string);
   public
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      procedure Clear;
      procedure Assign(Source: TPersistent); override;
      { Addresses }
      property Address_ORIG: string read GetAddress_ORIG write SetAddress_ORIG;
      { Subject }
      property Subject: string read GetSubject write SetSubject;
      { Text }
      property NoteText: TStringList read FNoteText;
      {}
      property PathNames: TStringList read FPathNames;
      property FileNames: TStringList read FFileNames;
      property Address_TO: TStringList read FAddress_TO;
      property Address_CC: TStringList read FAddress_CC;
      property Address_BCC: TStringList read FAddress_BCC;
      {}
      property MessageID: LPSTR read FMessageID write FMessageID;
      property MessageIDSeed: LPSTR read FMessageIDSeed write FMessageIDSeed;
      property MessageIDSave: LPSTR read FMessageIDSave write FMessageIDSave;
      {}
      property MessageType: string read GetMessageType write SetMessageType;
      property TimeReceived: TDateTime read FTimeReceived write FTimeReceived;
      property MessageFlags: FLAGS read FMessageFlags write FMessageFlags;
      {}
      property Unread: Boolean read FUnread write FUnread;
      property UserFieldByName[const FieldsName: string]: string read  GetUserFieldByName write SetUserFieldByName;
   end;

{ TSimpleMAPIMessages }

type
   TSimpleMAPIMessages = class(TMAPIObject)
   private
      FSimpleMAPIMessage: TSimpleMAPIMessage;
      FSimpleMAPISession: TSimpleMAPISession;
      FEOF: Boolean;
      function ReadMessage: Boolean;
      function GetCount: Integer;
      function GetMailID: string;
   public
      constructor Create(AOwner: Tcomponent);                 override;
      destructor Destroy;                                     override;
      { ReadMail}
      function GetFirst(aFindFlags, aReadFlags: FLAGS): Boolean;
      function GetNext(aFindFlags, aReadFlags: FLAGS): Boolean;
      function GetID(aFindFlags, aReadFlags: FLAGS; AMeesageID: LPSTR): Boolean;
      function ReadMail(aReadFlags: FLAGS): Boolean;
      function DeleteMail(aMessageID: LPSTR): Boolean;
      function UpdateMail: Boolean;
      {}
      procedure ExtractFiles(const AttachDir: string);
      procedure ExtractFile(const AttachDir, FileName: string);
      procedure DeleteFiles;
      { SendMail }
      function CreateAddressTO(const AddressTO: string): Boolean;
      function FormatSendMail: Boolean;
      function SendMail(SaveMessage: Boolean): Boolean;
      {}
      function ForwardMail(const AddressTO: string): Boolean;
      {}
      procedure WriteMail(const FileName: string);
      procedure FormatMail(const FileName: string);
      procedure FormatMailNew(const FileName: string);
      {}
      property EOF: Boolean read FEOF write FEOF;
      property Count: Integer read GetCount;
      property MailID: string read GetMailID;
      property SimpleMAPIMessage: TSimpleMAPIMessage read FSimpleMAPIMessage;
      property SimpleMAPISession: TSimpleMAPISession read FSimpleMAPISession write FSimpleMAPISession;
   end;

function CheckSimpleMAPI (var CDOVersion,Profile,Mailbox,Status: string): Boolean;
function InitSimpleMapi (const Profile: string): TSimpleMAPISession;
function ResolveAddressWithDialog(const AProfile,AAddress: string; var AResolveAddress: string): Boolean;
function ResolveAddressWithoutDialog(const Profile,Address: string; var AResolveAddress: string): Boolean;

procedure Register;

implementation

uses Dialogs;

function CheckSimpleMAPI (var CDOVersion,Profile,Mailbox,Status: string): Boolean;
var
   SimpleMAPISession: TSimpleMAPISession;
begin
   Result := True;
   Profile := '';
   Mailbox := '';
   Status := '';
   {--------------------------------------------------------------}
   { Init CDO                                                     }
   {--------------------------------------------------------------}
   SimpleMAPISession := TSimpleMAPISession.Create(nil);
   SimpleMAPISession.CaseProfile := False;
   try
      SimpleMAPISession.Logon;
      if SimpleMAPISession.Status = 0 then begin
         Profile := SimpleMAPISession.Profile;
         Mailbox := SimpleMAPISession.Address;
         SimpleMAPISession.Logoff;
         end
      else begin
         Status := SimpleMAPISession.ErrorString;
         Result := False;
      end;
   except
      Status := 'Инициализация SimpleMAPI = False';
      Result := False;
   end;
   SimpleMAPISession.Free;
end;

{ InitSimpleMapi }

function InitSimpleMapi (const Profile: string): TSimpleMAPISession;
begin
   if isConsole then begin
      CoInitialize(nil);
      Result := TSimpleMAPISession.Create(nil);
      end
   else
      Result := TSimpleMAPISession.Create(nil);
   Result.Profile := Profile;
end;

{ ResolveAddress }

function ResolveAddress(const Profile,Address: string; AShow: Boolean; var AResolveAddress: string): Boolean;
var
   LSimpleMAPI: TSimpleMAPISession;
begin
   LSimpleMAPI := InitSimpleMapi (Profile);
   try
      LSimpleMAPI.Logon;
      LSimpleMAPI.ResolveName(Address, AShow);
      if Assigned(LSimpleMAPI.ResolveRecip) then begin
         AResolveAddress := StrPas(LSimpleMAPI.ResolveRecip.lpszName);
         Result := True;
         end
      else begin
         Result := False;
         AResolveAddress := '';
      end;
      LSimpleMAPI.FreeResolveName;
      LSimpleMAPI.Logoff;
   except
      Result := False;
      AResolveAddress := '';
   end;
   LSimpleMAPI.Free;
end;

{ ResolveAddressWithDialog }

function ResolveAddressWithDialog(const AProfile,AAddress: string; var AResolveAddress: string): Boolean;
begin
   Result := ResolveAddress(AProfile,AAddress,True,AResolveAddress);
end;

{ ResolveAddressWithoutDialog }

function ResolveAddressWithoutDialog(const Profile,Address: string; var AResolveAddress: string): Boolean;
begin
   Result := ResolveAddress(Profile,Address,False,AResolveAddress);
end;

{ TMapiRecip }

constructor TMapiRecip.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
end;

destructor TMapiRecip.Destroy;
begin
   inherited Destroy;
end;

{ TMapiFile }

constructor TMapiFile.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   FFileDesc := nil;
end;

destructor TMapiFile.Destroy;
begin
   inherited Destroy;
end;

function TMapiFile.GetFlags (const i: Integer): Cardinal;
begin
   Result := 0;
   if FFileDesc <> nil then begin
      Result := TArrayMAPIFileDesc(FFileDesc^)[i].flFlags;
   end;
end;

{ TSimpleMAPISession }

constructor TSimpleMAPISession.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   FMapiFile := TMapiFile.Create(nil);
   FHandle := Application.Handle;
   {}
   Subject := '';
   MessageType := '';
   DateReceived := '';
   FAddress_TO := TStringList.Create;
   Address_ORIG := '';
   FAddress_CC := TStringList.Create;
   FAddress_BCC := TStringList.Create;
   FNoteText := TStringList.Create;
   FPathNames := TStringList.Create;
   FFileNames := TStringList.Create;
   {=====================================================================}
   { Default Value                                                       }
   {=====================================================================}
   FFindFlags := MAPI_UNREAD_ONLY + MAPI_GUARANTEE_FIFO;
   FReadFlags := MAPI_BODY_AS_FILE;
   FReadFlags := MAPI_PEEK;
   {=====================================================================}
   FMessageIDSeed := StrAlloc(512);
   FMessageID := StrAlloc(512);
   FMessageIDSave := StrAlloc(512);
   FillChar(FMessageID^, 512, 0);
   FillChar(FMessageIDSeed^, 512, 0);
   FillChar(FMessageIDSave^, 512, 0);
   {}
   nEditFields := 4; { 0..4 }
   Labels := 'Добавить';
   DocDelimChar := ';';
   DocFullPaths := '';
   DocFileNames := '';
end;

destructor TSimpleMAPISession.Destroy;
begin
   FMapiFile.Free;
   FAddress_TO.Free;
   StrDispose(FAddress_ORIG);
   FAddress_CC.Free;
   FAddress_BCC.Free;
   FNoteText.Free;
   FPathNames.Free;
   FFileNames.Free;
   StrDispose(FSubject);
   StrDispose(FMessageType);
   StrDispose(FDateReceived);
   StrDispose(FDocFileNames);
   StrDispose(FDocFullPaths);
   StrDispose(FDocDelimChar);
   StrDispose(FLabels);
   StrDispose(FMessageID);
   StrDispose(FMessageIDSave);
   StrDispose(FMessageIDSeed);
   inherited Destroy;
end;

procedure TSimpleMAPISession.Clear;
begin
   Subject := '';
   MessageType := '';
   DateReceived := '';
   Address_ORIG := '';
   FAddress_TO.Clear;
   FAddress_CC.Clear;
   FAddress_BCC.Clear;
   FNoteText.Clear;
   FPathNames.Clear;
   FFileNames.Clear;
end;

function TSimpleMAPISession.GetAddress_ORIG: string;
begin
   try
      Result := StrPas(FAddress_ORIG);
   except
      Result := '';
   end;
end;
procedure TSimpleMAPISession.SetAddress_ORIG(const Value: string);
begin
   if FAddress_ORIG <> nil then StrDispose(FAddress_ORIG);
   FAddress_ORIG := StrAlloc(Length(Value)+1);
   StrPCopy(FAddress_ORIG, Value);
end;

function TSimpleMAPISession.GetSubject: string;
begin
   try
      Result := StrPas(FSubject);
   except
      Result := '';
   end;
end;
procedure TSimpleMAPISession.SetSubject(const Value: string);
begin
   if FSubject <> nil then StrDispose(FSubject);
   FSubject := StrAlloc(Length(Value)+1);
   StrPCopy(FSubject, Value);
end;

function TSimpleMAPISession.GetMessageType: string;
begin
   try
      Result := StrPas(FMessageType);
   except
      Result := '';
   end;
end;
procedure TSimpleMAPISession.SetMessageType(const Value: string);
begin
   if FMessageType <> nil then StrDispose(FMessageType);
   FMessageType := StrAlloc(Length(Value)+1);
   StrPCopy(FMessageType, Value);
end;

function TSimpleMAPISession.GetDateReceived: string;
begin
   try
      Result := StrPas(FDateReceived);
   except
      Result := '';
   end;
end;
procedure TSimpleMAPISession.SetDateReceived(const Value: string);
begin
   if FDateReceived <> nil then StrDispose(FDateReceived);
   FDateReceived := StrAlloc(Length(Value)+1);
   StrPCopy(FDateReceived, Value);
end;

function TSimpleMAPISession.GetSession: LHANDLE;
begin
   Result := LHANDLE(FPSession^);
end;

function TSimpleMAPISession.GetDocDelimChar: Char;
begin
   Result := FDocDelimChar[0];
end;
procedure TSimpleMAPISession.SetDocDelimChar(const Value: char);
begin
   if FDocDelimChar <> nil then StrDispose(FDocDelimChar);
   FDocDelimChar := StrAlloc(2);
   FDocDelimChar[0] := Value;
end;

function TSimpleMAPISession.GetDocFullPaths: string;
begin
   try
      Result := StrPas(FDocFullPaths);
   except
      Result := '';
   end;
end;
procedure TSimpleMAPISession.SetDocFullPaths(const Value: string);
begin
   if FDocFullPaths <> nil then StrDispose(FDocFullPaths);
   FDocFullPaths := StrAlloc(Length(Value)+1);
   StrPCopy(FDocFullPaths, Value);
end;

function TSimpleMAPISession.GetDocFileNames: string;
begin
   try
      Result := StrPas(FDocFileNames);
   except
      Result := '';
   end;
end;
procedure TSimpleMAPISession.SetDocFileNames(const Value: string);
begin
   if FDocFileNames <> nil then StrDispose(FDocFileNames);
   FDocFileNames := StrAlloc(Length(Value)+1);
   StrPCopy(FDocFileNames, Value);
end;

function TSimpleMAPISession.GetLabels: string;
begin
   try
      Result := StrPas(FLabels);
   except
      Result := '';
   end;
end;
procedure TSimpleMAPISession.SetLabels(const Value: string);
begin
   if FLabels <> nil then StrDispose(FLabels);
   FLabels := StrAlloc(Length(Value)+1);
   StrPCopy(FLabels, Value);
end;

function TSimpleMAPISession.Logon: Boolean;
var
   s: string;
begin
   if Profile = '' then begin
      Profile := DefaultProfile;
   end;
   try
      Status := MAPILogon (FHandle, FProfile, nil, FLogonFlags, 0, @FPSession);
      //Status := MAPILogon (FHandle, 'c:\73lisitsynyr.pro', 'Lozudasa_01', MAPI_LOGON_UI, 0, @FPSession);
      if (Status=SUCCESS_SUCCESS) then begin
         { Address }
         s := Alias[Profile];
         //s := 'luis';
         if ResolveName(s, True) then begin
            Address := ResolveRecip.lpszName;
            FreeResolveName;
         end;
      end;
   except
      Status := 7;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TSimpleMAPISession.Logoff: Boolean;
begin
   try
      Status := MAPILogoff (Session, FHandle, 0, 0);
   except
      Status := 7;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TSimpleMAPISession.NewAddress: Boolean;
begin
   try
      Status := MAPIAddress (Session, FHandle, PChar('Адресная книга'),
                              FnEditFields, FLabels, 0, FRecips,
                              0, 0, @FNNewRecips, FNewRecips);
   except
      Status := 7;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TSimpleMAPISession.FreeNewRecips: Boolean;
begin
   Status := 0;
   if FNewRecips <> nil then Status := MAPIFreeBuffer(FNewRecips);
   Result := (Status=SUCCESS_SUCCESS);
end;

function TSimpleMAPISession.ResolveName (const AName: string; ShowDialog: Boolean): Boolean;
begin
   try
      if ShowDialog then
         Status := MAPIResolveName (Session, FHandle, PChar(AName), MAPI_DIALOG, 0, FResolveRecip)
      else
         Status := MAPIResolveName (Session, FHandle, PChar(AName), 0, 0, FResolveRecip);
   except
      Status := 7;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TSimpleMAPISession.FreeResolveName: Boolean;
begin
   Status := 0;
   if FResolveRecip <> nil then Status := MAPIFreeBuffer(FResolveRecip);
   Result := (Status=SUCCESS_SUCCESS);
end;

function TSimpleMAPISession.DetailsName (const AName: string): Boolean;
begin
   Result := ResolveName (AName, False);
   if Result then begin
      with FDetailsRecip do begin
         ulEIDSize := FResolveRecip.ulEIDSize;
         lpEntryID := FResolveRecip.lpEntryID;
      end;
      try
         Status := MAPIDetails (Session, FHandle, FDetailsRecip, 0, 0);
      except
         Status := 7;
      end;
      Result := (Status=SUCCESS_SUCCESS);
   end;
   FreeResolveName;
end;

function TSimpleMAPISession.FindMessage(var AMessageIDSeed, AMessageID: PChar): Boolean;
begin
   try
      Status := MAPIFindNext (Session, FHandle, nil, AMessageIDSeed, FFindFlags, 0, AMessageID);
   except
      Status := 7;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TSimpleMAPISession.MessageFirst (aFindFlags: FLAGS): Boolean;
begin
   FindFlags := aFindFlags;
   { перед чтением }
   FillChar(FMessageIDSave^, 512, 0);
   FillChar(FMessageIDSeed^, 512, 0);
   Result := FindMessage(FMessageIDSeed, FMessageID);
end;

function TSimpleMAPISession.MessageNext (aFindFlags: FLAGS): Boolean;
begin
   FindFlags := aFindFlags;
   { перед чтением }
   StrCopy(FMessageIDSave, FMessageIDSeed);
   StrCopy(FMessageIDSeed, FMessageID);
   Result := FindMessage(FMessageIDSeed, FMessageID);
end;

function TSimpleMAPISession.MessageGETID (aFindFlags: FLAGS; AMessageID: LPSTR): Boolean;
begin
   FindFlags := aFindFlags;
   StrCopy(FMessageIDSeed, AMessageID);
   Result := FindMessage(FMessageIDSeed, FMessageID);
end;

function TSimpleMAPISession.DeleteMail: Boolean;
begin
   try
      Status := MAPIDeleteMail (Session, FHandle, FMessageID, 0, 0);
   except
      Status := 7;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

procedure TSimpleMAPISession.ReadMailWork;
var
   n: Integer;
   i: Integer;
   LFileDesc: PMapiFileDesc;
   LRecipDesc: PMapiRecipDesc;
begin
   Clear;
   Subject := TMapiMessage(lppMessage^).lpszSubject;
   NoteText.Clear;
   NoteText.SetText (TMapiMessage(lppMessage^).lpszNoteText);
   DateReceived := TMapiMessage(lppMessage^).lpszDateReceived;
   MessageType := TMapiMessage(lppMessage^).lpszMessageType;
   MessageFlags := TMapiMessage(lppMessage^).flFlags;
   { Files }
   n := TMapiMessage(lppMessage^).nFileCount;
   PathNames.Clear;
   FileNames.Clear;
   LFileDesc := TMapiMessage(lppMessage^).lpFiles;
   if LFileDesc <> nil then begin
      for i:=1 to n do begin
         PathNames.Add(TArrayMAPIFileDesc(LFileDesc^)[i-1].lpszPathName);
         FileNames.Add(TArrayMAPIFileDesc(LFileDesc^)[i-1].lpszFileName);
      end;
   end;
   { Recip }
   LRecipDesc := lppMessage.lpOriginator;
   Address_ORIG := '';
   if LRecipDesc^.ulRecipClass = MAPI_ORIG then begin
      Address_ORIG := LRecipDesc.lpszName;
   end;
   Address_TO.Clear;
   Address_CC.Clear;
   Address_BCC.Clear;
   n := TMapiMessage(lppMessage^).nRecipCount;
   LRecipDesc := TMapiMessage(lppMessage^).lpRecips;
   if LRecipDesc <> nil then begin
      for i:=1 to n do begin
         if TArrayMapiRecipDesc(LRecipDesc^)[i-1].ulRecipClass = MAPI_TO then begin
            Address_TO.Add(TArrayMapiRecipDesc(LRecipDesc^)[i-1].lpszName);
         end;
         if TArrayMapiRecipDesc(LRecipDesc^)[i-1].ulRecipClass = MAPI_CC then begin
            Address_CC.Add(TArrayMapiRecipDesc(LRecipDesc^)[i-1].lpszName);
         end;
         if TArrayMapiRecipDesc(LRecipDesc^)[i-1].ulRecipClass = MAPI_BCC then begin
            Address_BCC.Add(TArrayMapiRecipDesc(LRecipDesc^)[i-1].lpszName);
         end;
      end;
   end;
end;

function TSimpleMAPISession.ReadMail (aReadFlags: FLAGS): Boolean;
begin
   ReadFlags := aReadFlags;
   try
      Status := MAPIReadMail (Session, FHandle, FMessageID, FReadFlags, 0, FlppMessage);
      ReadMailWork;
   except
      Status := 7;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TSimpleMAPISession.FreeMessage: Boolean;
var
   i: Integer;
begin
   Status := 0;
   for i:=0 to PathNames.Count-1 do begin
      FileDelete(PathNames.Strings[i]);
   end;
   if FlppMessage <> nil then Status := MAPIFreeBuffer(FlppMessage);
   Result := (Status=SUCCESS_SUCCESS);
end;

function TSimpleMAPISession.SaveMail: Boolean;
var
   ArrayMAPIFileDesc: PArrayMAPIFileDesc;
   i: Integer;
   FileDesc: TMAPIFileDesc;
begin
   Move(FlppMessage^, FlpMessage, SizeOf(TMapiMessage));
   TMapiMessage(FlppMessage^).flFlags := MessageFlags;
(*
   { PathNames / FileNames }
   GetMem(ArrayMAPIFileDesc, SizeOf(TMAPIFileDesc)*PathNames.Count);
   for i:=0 to PathNames.Count-1 do begin
      with FileDesc do begin
         ulReserved := 0;
         flFlags := 0;
         nPosition := StrLen(VNoteText)-Cardinal(PathNames.Count)+Cardinal(i);
         lpszPathName := PChar(PathNames.Strings[i]);
         lpszFileName := PChar(FileNames.Strings[i]);
         lpFileType := nil;
      end;
      Move(FileDesc, ArrayMAPIFileDesc[i], SizeOf(TMAPIFileDesc));
   end;

   with FlpMessage do begin
      nFileCount := PathNames.Count;     { # of file attachments                  }
      { Attachment descriptors }
      lpFiles := PMAPIFileDesc(ArrayMAPIFileDesc);
   end;
*)
   try
      Status := MAPISaveMail (Session, FHandle, FlppMessage^, MAPI_NEW_SESSION, 0, FMessageID);
   except
      Status := 7;
   end;
   Result := (Status=SUCCESS_SUCCESS);
(*
   FreeMem(ArrayMAPIFileDesc);
*)
end;

function TSimpleMAPISession.SendDocuments: Boolean;
begin
   try
      Status := MAPISendDocuments (FHandle, FDocDelimChar, FDocFullPaths,FDocFileNames, 0);
   except
      Status := 7;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TSimpleMAPISession.SendMail: Boolean;
var
   i,j,m: Integer;
   VNoteText: PChar;
   Recip_ORIG: PMapiRecipDesc;
   ArrayMAPIRecipDesc: PArrayMAPIRecipDesc;
   ArrayPMAPIRecipDesc: PArrayPMAPIRecipDesc;
   FileDesc: TMAPIFileDesc;
   ArrayMAPIFileDesc: PArrayMAPIFileDesc;
begin
   Errors.Clear;

   { Address_ORIG }
   Recip_ORIG := nil;
   Result := ResolveName (Address_ORIG, False);
   if Result then begin
      FResolveRecip.ulRecipClass := MAPI_ORIG;
      Recip_ORIG := FResolveRecip;
      end
   else Errors.Add('Not resolve Address_ORIG: '+Address_ORIG);

   { Recips }

   j := 0;
   m := Address_TO.Count+Address_CC.Count+Address_BCC.Count;
   GetMem(ArrayMAPIRecipDesc, SizeOf(TMAPIRecipDesc)*m);
   GetMem(ArrayPMAPIRecipDesc, SizeOf(PMAPIRecipDesc)*m);
   { Address_TO }
   for i:=0 to Address_TO.Count-1 do begin
      Result := ResolveName (Address_TO.Strings[i], False);
      if Result then begin
         FResolveRecip.ulRecipClass := MAPI_TO;
         ArrayMAPIRecipDesc[j] := TMAPIRecipDesc(FResolveRecip^);
         ArrayPMAPIRecipDesc[j] := FResolveRecip;
         Inc(j);
         end
      else Errors.Add('Not resolve Address_TO: '+Address_TO.Strings[i]);
   end;
   { Address_CC }
   for i:=0 to Address_CC.Count-1 do begin
      Result := ResolveName (Address_CC.Strings[i], False);
      if Result then begin
         FResolveRecip.ulRecipClass := MAPI_CC;
         ArrayMAPIRecipDesc[j] := TMAPIRecipDesc(FResolveRecip^);
         ArrayPMAPIRecipDesc[j] := FResolveRecip;
         Inc(j);
         end
      else Errors.Add('Not resolve Address_CC: '+Address_CC.Strings[i]);
   end;
   { Address_BCC }
   for i:=0 to Address_BCC.Count-1 do begin
      Result := ResolveName (Address_BCC.Strings[i], False);
      if Result then begin
         FResolveRecip.ulRecipClass := MAPI_BCC;
         ArrayMAPIRecipDesc[j] := TMAPIRecipDesc(FResolveRecip^);
         ArrayPMAPIRecipDesc[j] := FResolveRecip;
         Inc(j);
         end
      else Errors.Add('Not resolve Address_BCC: '+Address_BCC.Strings[i]);
   end;
   VNoteText := StrAlloc(StrLen(NoteText.GetText)+2+Cardinal(PathNames.Count)+1);
   StrCopy(VNoteText, NoteText.GetText);
   StrCat(VNoteText, PChar(#13#10 + StringOfChar(' ',PathNames.Count)));

   { PathNames / FileNames }
   GetMem(ArrayMAPIFileDesc, SizeOf(TMAPIFileDesc)*PathNames.Count);
   for i:=0 to PathNames.Count-1 do begin
      with FileDesc do begin
         ulReserved := 0;
         flFlags := 0;
         nPosition := StrLen(VNoteText)-Cardinal(PathNames.Count)+Cardinal(i);
         lpszPathName := PChar(PathNames.Strings[i]);
         //if i < FileNames.Count then
         lpszFileName := PChar(FileNames.Strings[i]);
         lpFileType := nil;
      end;
      Move(FileDesc, ArrayMAPIFileDesc[i], SizeOf(TMAPIFileDesc));
   end;

   Result := (Errors.Count=0);

   { SendMail }
   if Result then begin
      with FlpMessage do begin
         ulReserved := 0;                  { Reserved for future use (M.B. 0)       }
         lpszSubject := FSubject;          { Message Subject                        }
         lpszNoteText := VNoteText;        { Message Text                           }
         lpszMessageType := nil;           { Message Class                          }
         lpszDateReceived := nil;          { in YYYY/MM/DD HH:MM format             }
         lpszConversationID := nil;        { conversation thread ID                 }
         flFlags := 0;                     { unread,return receipt                  }
         lpOriginator := Recip_ORIG;       { Originator descriptor                  }
         nRecipCount := j;                 { Number of recipients                   }
         { Recipient descriptors  }
         lpRecips := PMAPIRecipDesc(ArrayMAPIRecipDesc);
         nFileCount := PathNames.Count;     { # of file attachments                  }
         { Attachment descriptors }
         lpFiles := PMAPIFileDesc(ArrayMAPIFileDesc);
      end;
      try
         Status := MAPISendMail (Session, FHandle, FlpMessage, 0, 0);
      except
         Status := 7;
      end;
      Result := (Status=SUCCESS_SUCCESS);
   end;

   { Freemem }
   StrDispose(VNoteText);
   FResolveRecip := Recip_ORIG;
   FreeResolveName;
   for i:=0 to j-1 do begin
      FResolveRecip := ArrayPMAPIRecipDesc[i];
      FreeResolveName;
   end;
   FreeMem(ArrayMAPIRecipDesc);
   FreeMem(ArrayMAPIFileDesc);
end;

{ TSimpleMAPIMessage }

constructor TSimpleMAPIMessage.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   ObjectType := otMessage;
   FNoteText := TStringList.Create;
   FPathNames := TStringList.Create;
   FFileNames := TStringList.Create;
   FAddress_TO := TStringList.Create;
   FAddress_CC := TStringList.Create;
   FAddress_BCC := TStringList.Create;
   FMessageIDSave := StrAlloc(512);
   FMessageIDSeed := StrAlloc(512);
   FMessageID := StrAlloc(512);
   FillChar(FMessageID^, 512, 0);
   FillChar(FMessageIDSeed^, 512, 0);
   FillChar(FMessageIDSave^, 512, 0);
   Clear;
end;

procedure TSimpleMAPIMessage.Clear;
begin
   FNoteText.Clear;
   FPathNames.Clear;
   FFileNames.Clear;
   FAddress_TO.Clear;
   FAddress_CC.Clear;
   FAddress_BCC.Clear;
   Address_ORIG := '';
   Subject := '';
   MessageType := '';
   FTimeReceived := 0;
   FMessageFlags := 0;
   FUnread := False;
end;

destructor TSimpleMAPIMessage.Destroy;
begin
   StrDispose(FMessageID);
   StrDispose(FMessageIDSeed);
   StrDispose(FMessageIDSave);
   StrDispose(FMessageType);
   StrDispose(FSubject);
   StrDispose(FAddress_ORIG);
   FNoteText.Free;
   FPathNames.Free;
   FFileNames.Free;
   FAddress_TO.Free;
   FAddress_CC.Free;
   FAddress_BCC.Free;
   inherited Destroy;
end;

procedure TSimpleMAPIMessage.Assign(Source: TPersistent);
begin
   if Source is TSimpleMAPIMessage then begin
      Clear;
      StrCopy(FMessageID, (Source as TSimpleMAPIMessage).MessageID);
      StrCopy(FMessageIDSeed, (Source as TSimpleMAPIMessage).MessageIDSeed);
      StrCopy(FMessageIDSave, (Source as TSimpleMAPIMessage).MessageIDSave);
      FNoteText.Assign((Source as TSimpleMAPIMessage).NoteText);
      FPathNames.Assign((Source as TSimpleMAPIMessage).PathNames);
      FFileNames.Assign((Source as TSimpleMAPIMessage).FileNames);
      FAddress_TO.Assign((Source as TSimpleMAPIMessage).Address_TO);
      FAddress_CC.Assign((Source as TSimpleMAPIMessage).Address_CC);
      FAddress_BCC.Assign((Source as TSimpleMAPIMessage).Address_BCC);
      Address_ORIG := (Source as TSimpleMAPIMessage).Address_ORIG;
      Subject := (Source as TSimpleMAPIMessage).Subject;
      MessageType := (Source as TSimpleMAPIMessage).MessageType;
      MessageFlags := (Source as TSimpleMAPIMessage).MessageFlags;
      TimeReceived := (Source as TSimpleMAPIMessage).TimeReceived;
      Unread := (Source as TSimpleMAPIMessage).Unread;
      Exit;
   end;
   inherited Assign(Source);
end;

function TSimpleMAPIMessage.GetUserFieldByName(const FieldsName: string): string;
begin
   Result := '';
   Result := NoteText.Values[FieldsName];
end;

procedure TSimpleMAPIMessage.SetUserFieldByName(const FieldsName, Value: string);
begin
end;

function TSimpleMAPIMessage.GetSubject: string;
begin
   Result := StrPas(FSubject);
end;
procedure TSimpleMAPIMessage.SetSubject(const Value: string);
begin
   if FSubject <> nil then StrDispose(FSubject);
   FSubject := StrAlloc(Length(Value)+1);
   StrPCopy(FSubject, Value);
end;

function TSimpleMAPIMessage.GetMessageType: string;
begin
   Result := StrPas(FMessageType);
end;
procedure TSimpleMAPIMessage.SetMessageType(const Value: string);
begin
   if FMessageType <> nil then StrDispose(FMessageType);
   FMessageType := StrAlloc(Length(Value)+1);
   StrPCopy(FMessageType, Value);
end;

function TSimpleMAPIMessage.GetAddress_ORIG: string;
begin
   Result := StrPas(FAddress_ORIG);
end;
procedure TSimpleMAPIMessage.SetAddress_ORIG(const Value: string);
begin
   if FAddress_ORIG <> nil then StrDispose(FAddress_ORIG);
   FAddress_ORIG := StrAlloc(Length(Value)+1);
   StrPCopy(FAddress_ORIG, Value);
end;

{ TSimpleMAPIMessages }

constructor TSimpleMAPIMessages.Create(AOwner: TComponent);
begin
   inherited Create(AOwner);
   FSimpleMAPIMessage := TSimpleMAPIMessage.Create(Self);
end;

destructor TSimpleMAPIMessages.Destroy;
begin
   inherited Destroy;
end;

function TSimpleMAPIMessages.ReadMessage: Boolean;
var
   d,m,y,h,mm: Word;
   LDate: TDateTime;
   LTime: TDateTime;
   LTimeReceived: TDateTime;
   s: string;
begin
   SimpleMAPIMessage.Clear;
   ClearErrors;
   { Subject }
   SimpleMAPIMessage.Subject := SimpleMAPISession.Subject;
   { Notetext }
   SimpleMAPIMessage.NoteText.Clear;
   SimpleMAPIMessage.NoteText.SetText(PChar(VarToStr(SimpleMAPISession.NoteText.Text)));
   {}
   try
      d := StrToInt(ExtractWordNew(3, SimpleMAPISession.DateReceived, [' ','/',':']));
   except
      d := 0;
   end;
   try
      m := StrToInt(ExtractWordNew(2, SimpleMAPISession.DateReceived, [' ','/',':']));
   except
      m := 0;
   end;
   try
      y := StrToInt(ExtractWordNew(1, SimpleMAPISession.DateReceived, [' ','/',':']));
   except
      y := 0;
   end;
   try
      h := StrToInt(ExtractWordNew(4, SimpleMAPISession.DateReceived, [' ','/',':']));
   except
      h := 0;
   end;
   try
      mm := StrToInt(ExtractWordNew(5, SimpleMAPISession.DateReceived, [' ','/',':']));
   except
      mm := 0;
   end;
   SimpleMAPIMessage.TimeReceived := EncodeDate(y,m,d)+EncodeTime(h,mm,0,0);
   SimpleMAPIMessage.MessageFlags := SimpleMAPISession.MessageFlags;
   { Recipients }
   SimpleMAPIMessage.Address_ORIG := SimpleMAPISession.Address_ORIG;
   SimpleMAPIMessage.Address_TO.Assign(SimpleMAPISession.Address_TO);
   SimpleMAPIMessage.Address_CC.Assign(SimpleMAPISession.Address_CC);
   SimpleMAPIMessage.Address_BCC.Assign(SimpleMAPISession.Address_BCC);
   { Attachments }
   SimpleMAPIMessage.PathNames.Assign(SimpleMAPISession.PathNames);
   SimpleMAPIMessage.FileNames.Assign(SimpleMAPISession.FileNames);
   {}
   SimpleMAPIMessage.Unread := (SimpleMAPISession.MessageFlags = 5);
   Result := (Status=SUCCESS_SUCCESS);
end;

procedure TSimpleMAPIMessages.ExtractFiles(const AttachDir: string);
var
   i: Integer;
begin
   for i:=0 to SimpleMAPIMessage.PathNames.Count-1 do begin
      File2File(SimpleMAPIMessage.PathNames.Strings[i],
         IncludeTrailingBackslash(AttachDir)+SimpleMAPIMessage.FileNames.Strings[i], True);
   end;
   SimpleMAPIMessage.PathNames.Clear;
   for i:=0 to SimpleMAPIMessage.FileNames.Count-1 do begin
      SimpleMAPIMessage.PathNames.Add(IncludeTrailingBackslash(AttachDir)+SimpleMAPIMessage.FileNames.Strings[i]);
   end;
end;

procedure TSimpleMAPIMessages.ExtractFile(const AttachDir, FileName: string);
var
   i: Integer;
begin
   for i:=0 to SimpleMAPIMessage.PathNames.Count-1 do begin
      if UpperCase(SimpleMAPIMessage.FileNames.Strings[i]) = UpperCase(FileName) then begin
         File2File(SimpleMAPIMessage.PathNames.Strings[i],
            IncludeTrailingBackslash(AttachDir)+SimpleMAPIMessage.FileNames.Strings[i], True);
      end;
   end;
end;

function TSimpleMAPIMessages.ReadMail(aReadFlags: FLAGS): Boolean;
begin
   Result := False;
   if not EOF then begin
      { после чтения }
      StrCopy(SimpleMAPIMessage.MessageID,     SimpleMAPISession.MessageID);
      StrCopy(SimpleMAPIMessage.MessageIDSeed, SimpleMAPISession.MessageIDSeed);
      StrCopy(SimpleMAPIMessage.MessageIDSave, SimpleMAPISession.MessageIDSeed);
      SimpleMAPISession.ReadMail(aReadFlags);
      ReadMessage;
   end;
end;

function TSimpleMAPIMessages.GetFirst(aFindFlags, aReadFlags: FLAGS): Boolean;
begin
   ClearErrors;
   try
      { Читать письмо}
      EOF := not SimpleMAPISession.MessageFirst(aFindFlags);
      ReadMail(aReadFlags);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TSimpleMAPIMessages.GetNext(aFindFlags, aReadFlags: FLAGS): Boolean;
begin
   ClearErrors;
   try
      { Читать письмо}
      EOF := not SimpleMAPISession.MessageNext(aFindFlags);
      ReadMail(aReadFlags);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TSimpleMAPIMessages.GetID(aFindFlags, aReadFlags: FLAGS; AMeesageID: LPSTR): Boolean;
begin
   ClearErrors;
   try
      { Читать письмо}
      EOF := not SimpleMAPISession.MessageGETID(aFindFlags, AMeesageID);
      ReadMail(aReadFlags);
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

function TSimpleMAPIMessages.DeleteMail(aMessageID: LPSTR): Boolean;
begin
   ClearErrors;
   try
      StrCopy(SimpleMAPISession.MessageIDSeed, SimpleMAPISession.MessageIDSave);
      StrCopy(SimpleMAPISession.MessageID, aMessageID);
      SimpleMAPISession.DeleteMail;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

procedure TSimpleMAPIMessages.DeleteFiles;
var
   i: Integer;
   s: string;
begin
   for i:=0 to SimpleMAPIMessage.PathNames.Count-1 do begin
      s := SimpleMAPIMessage.PathNames.Strings[i];
      if FileExists(s) then SysUtils.DeleteFile(s);
   end;
end;

procedure TSimpleMAPIMessages.WriteMail(const FileName: string);

   procedure WriteStream(const s: string; ADestStream: TFileStream);
   var
      PS: PChar;
   begin
      PS := StrAlloc(Length(s)+1); StrPCopy(PS,S);
      ADestStream.WriteBuffer(PS[0], Length(s));
      StrDispose(PS);
   end;

var
   DestStream: TFileStream;
begin
   //SimpleMAPI//
(*
   try
      DestStream := TFileStream.Create(FileName, fmOpenWrite or fmCreate);
   except
      DestStream := nil;
   end;
   if DestStream <> nil then begin
      (*
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
*)
end;

procedure TSimpleMAPIMessages.FormatMail(const FileName: string);
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
   //SimpleMAPI//
(*
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
*)
end;

procedure TSimpleMAPIMessages.FormatMailNew(const FileName: string);
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
   //SimpleMAPI//
(*
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
*)
end;

function TSimpleMAPIMessages.UpdateMail: Boolean;
begin
   ClearErrors;
   try
                     (*
                     { Письмо прочитано }
                     //TMapiMessage(SimpleSession.lppMessage^).flFlags := 0;
                     SimpleSession.flFlags := 0;
                     SimpleSession.PathNames.Clear;
                     LStatus := SimpleSession.SaveMail;
                     *)
      SimpleMAPISession.MessageFlags := SimpleMAPIMessage.MessageFlags;
      SimpleMAPISession.SaveMail;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

{ CreateAddressTO }

function TSimpleMAPIMessages.CreateAddressTO(const AddressTO: string): Boolean;
var
   i: Integer;
   s: string;
begin
   Result := False;
   for i:=1 to WordCountNew(AddressTO,[',',';']) do begin
      Result := True;
      s := ExtractWordNew(i, AddressTO, [',',';']);
      if i = 1 then
         SimpleMAPIMessage.Address_TO.Add(s)
      else
         SimpleMAPIMessage.Address_CC.Add(s);
   end;
end;

function TSimpleMAPIMessages.ForwardMail(const AddressTO: string): Boolean;
var
   LobjMessage: OleVariant;
   LobjRecipient: OLEVariant;
   LNoteText: PChar;
   LNote: TStringList;
   s: string;
begin
   ClearErrors;
   //SimpleMAPI//
   (*
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
      LNote.SetText(LNoteText);
      LNote.Insert(0, '');
      LNote.Insert(0, '');
      LNote.Insert(0, 'Тема:  '+CDOMessage.Subject);
      s := StrPas(CDOMessage.Address_TO.GetText);
      Delete(s, Length(s)-1, 2);
      LNote.Insert(0, 'Кому:  '+S);
      LNote.Insert(0, 'Отправлено:  '+VarToStr(CDOMessage.TimeSent));
      LNote.Insert(0, 'От: '+CDOMessage.Address_ORIG);
      LNote.Insert(0, '-----Исходное сообщение-----');
      LNote.Insert(0, '');
      LobjMessage.Text := StrPas(LNote.GetText);
      StrDispose(LNoteText);
      LNote.Free;
       if CreateAddressTO_obj(LobjMessage, AddressTO) then begin
          LobjMessage.Send(False, False, 0); // showDialog:=False
       end;

   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   *)
   Result := (Status=SUCCESS_SUCCESS);
end;

function TSimpleMAPIMessages.GetMailID: string;
var
   s: string;
begin
   Result := '';
end;

function TSimpleMAPIMessages.GetCount: Integer;
begin
   Result := 0;
end;

function TSimpleMAPIMessages.FormatSendMail: Boolean;
var
   i: Integer;
   LNoteText: PChar;
   LName: string;
   LSource: string;
   LPosition: Longint;
begin
   ClearErrors;
   { From }
   SimpleMAPISession.Address_ORIG := SimpleMAPIMessage.Address_ORIG;
   { TO }
   SimpleMAPISession.Address_TO.Assign(SimpleMAPIMessage.Address_TO);
   { CC }
   SimpleMAPISession.Address_CC.Assign(SimpleMAPIMessage.Address_CC);
   { BCC }
   SimpleMAPISession.Address_BCC.Assign(SimpleMAPIMessage.Address_BCC);
   { Subject }
   SimpleMAPISession.Subject := SimpleMAPIMessage.Subject;
   { Note }
   SimpleMAPISession.NoteText.Assign(SimpleMAPIMessage.NoteText);
   { Attachments }
   SimpleMAPISession.PathNames.Assign(SimpleMAPIMessage.PathNames);
   SimpleMAPISession.FileNames.Assign(SimpleMAPIMessage.FileNames);
   Result := UpdateMail;
end;

function TSimpleMAPIMessages.SendMail(SaveMessage: Boolean): Boolean;
begin
   FormatSendMail;
   try
      SimpleMAPISession.SendMail;
   except
      on E: Exception do begin
         MAPIHandleException(E);
      end;
   end;
   Result := (Status=SUCCESS_SUCCESS);
end;

{ This procedure is used to register this component on the component palette }

procedure Register;
begin
  RegisterComponents('Luis', [TSimpleMAPISession]);
end;

end.
