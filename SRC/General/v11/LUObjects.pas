{=======================================================}
{ Project:                                              }
{         Delphi VCL Extensions (LU)                    }
{         Copyright (c) 2000 Central Bank Of Russia     }
{ Subject:                                              }
{         ќбьекты                                       }
{ Author:                                               }
{         Lisitsin Y.R.                                 }
{=======================================================}
unit LUObjects;

interface

uses Classes, SysUtils, LUSupport;

   {===========================================================================}
const
   sMonthName:  array [1..12] of string = ('€нварь','февраль','март','апрель',
                                           'май','июнь','июль','август',
                                           'сент€брь','окт€брь','но€брь','декабрь');
   sMonthName0:  array [0..12] of string = ('ѕо всем','€нварь','февраль','март','апрель',
                                           'май','июнь','июль','август',
                                           'сент€брь','окт€брь','но€брь','декабрь');
type
   TObjectType = (otNone, otFile, otDirectory, otUser, otMonth, otEMail, otFTPServer,
                  {}
                  otExchange, otFolder, otInfoStore, otMessage, otMessageFilter, otAttachment,
                  otField, otAddressEntry, otAddressList, otRecipient,
                  otTask, otTasks, otFiles, otMailBox, otUsers, otHomeBox,
                  {}
                  otFormMessage, otReportDeliverMessage, otConfirmationMessage,
                  otInfoMessage, otDataMFOMessage, otErrorMessage
   );

   { TObjects }

   TObjects = class(TComponent)
   private
      FObjectType : TObjectType;
      FTag: Longint;
   public
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      property ObjectType: TObjectType read FObjectType write FObjectType;
      property Tag: Longint read FTag write FTag;
   end;

   { TFile }

   TFile = class(TObjects)
   private
      FTaskName: PChar;
      FFileName: PChar;
      FFileDate: TDateTime;
      FFileSize: Longint;
      //FNDir: Integer;
      function GetFileName: string;
      procedure SetFileName(const Value: string);
      function GetTaskName: string;
      procedure SetTaskName(const Value: string);
   public
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      procedure Clear;
      {}
      property FileName: string read GetFileName write SetFileName;
      property FileDate: TDateTime read FFileDate write FFileDate;
      property FileSize: Longint read FFileSize write FFileSize;
      property TaskName: string read GetTaskName write SetTaskName;
      //property NDir: Integer read FNDir write FNDir;
   end;

   { TMailbox }

   TMailbox = class(TObjects)
   private
      FMailboxName: PChar;
      function GetMailboxName: string;
      procedure SetMailboxName(const Value: string);
   public
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      procedure Clear;
      {}
      property MailboxName: string read GetMailboxName write SetMailboxName;
   end;

   { TFTPServer }

   TFTPServer = class(TObjects)
   private
      FFTPServerName: PChar;
      function GetFTPServerName: string;
      procedure SetFTPServerName(const Value: string);
   public
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      procedure Clear;
      {}
      property FTPServerName: string read GetFTPServerName write SetFTPServerName;
   end;

   { TDirectory }

   TDirectory = class(TObjects)
   private
      FDirectoryName: PChar;
      FDirectoryDate: TDateTime;
      function GetDirectoryName: string;
      procedure SetDirectoryName(const Value: string);
   public
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      procedure Clear;
      {}
      property DirectoryName: string read GetDirectoryName write SetDirectoryName;
      property DirectoryDate: TDateTime read FDirectoryDate write FDirectoryDate;
   end;

   { TUser }

   TUser = class(TObjects)
   private
      FTaskNames: TStringList;
      FUserName: PChar;
      function GetUserName: string;
      procedure SetUserName(const Value: string);
   public
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      procedure Clear;
      {}
      property UserName: string read GetUserName write SetUserName;
      property TaskNames: TStringList read FTaskNames;
   end;

   { TMonth }

   TMonth = class(TObjects)
   private
      FMonth: Integer;
      function GetMonthName: string;
   public
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      procedure Clear;
      {}
      property MonthName: string read GetMonthName;
      property Month: Integer read FMonth write FMonth;
   end;

   { TEMail }

   TEMail = class(TObjects)
   private
      FEMail: PChar;
      FList: TStringList;
      function GetEMail(const AddressType: string): string;
      procedure SetEMail(const AddressType, Value: string);
      procedure WorkEMail(AddressType: string);
      function GetDomain(ADimention: Integer): string;
      function GetUser: string;
      function GetDomainCount: Integer;
      {}
      property List: TStringList read FList;
   public
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      procedure Clear;
      {}
      property EMail[const AddressType: string]: string read GetEMail write SetEMail;
      property Domain[ADimention: Integer]: string read GetDomain;
      property DomainCount: Integer read GetDomainCount;
      property User: string read GetUser;
   end;

implementation

{ TObjects }

constructor TObjects.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   ObjectType := otNone;
   FTag := 0;
end;

destructor TObjects.Destroy;
begin
   inherited Destroy;
end;

{ TFile }

constructor TFile.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   ObjectType := otFile;
   Clear;
end;

destructor TFile.Destroy;
begin
   StrDispose(FTaskName);
   StrDispose(FFileName);
   inherited Destroy;
end;

procedure TFile.Clear;
begin
   FileName := '';
   TaskName := '';
   FileDate := 0;
   FileSize := 0;
end;

function TFile.GetFileName: string;
begin
   Result := StrPas(FFileName);
end;
procedure TFile.SetFileName(const Value: string);
begin
   if FFileName <> nil then StrDispose(FFileName);
   FFileName := StrAlloc(Length(Value)+1);
   StrPCopy(FFileName, Value);
end;

function TFile.GetTaskName: string;
begin
   Result := StrPas(FTaskName);
end;
procedure TFile.SetTaskName(const Value: string);
begin
   if FTaskName <> nil then StrDispose(FTaskName);
   FTaskName := StrAlloc(Length(Value)+1);
   StrPCopy(FTaskName, Value);
end;

{ TMailbox }

constructor TMailbox.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   ObjectType := otMailbox;
   Clear;
end;

destructor TMailbox.Destroy;
begin
   StrDispose(FMailboxName);
   inherited Destroy;
end;

procedure TMailbox.Clear;
begin
   MailboxName := '';
end;

function TMailbox.GetMailboxName: string;
begin
   Result := StrPas(FMailboxName);
end;
procedure TMailbox.SetMailboxName(const Value: string);
begin
   if FMailboxName <> nil then StrDispose(FMailboxName);
   FMailboxName := StrAlloc(Length(Value)+1);
   StrPCopy(FMailboxName, Value);
end;

{ TFTPServer }

constructor TFTPServer.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   ObjectType := otFTPServer;
   Clear;
end;

destructor TFTPServer.Destroy;
begin
   StrDispose(FFTPServerName);
   inherited Destroy;
end;

procedure TFTPServer.Clear;
begin
   FTPServerName := '';
end;

function TFTPServer.GetFTPServerName: string;
begin
   Result := StrPas(FFTPServerName);
end;
procedure TFTPServer.SetFTPServerName(const Value: string);
begin
   if FFTPServerName <> nil then StrDispose(FFTPServerName);
   FFTPServerName := StrAlloc(Length(Value)+1);
   StrPCopy(FFTPServerName, Value);
end;

{ TDirectory }

constructor TDirectory.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   ObjectType := otDirectory;
   Clear;
end;

destructor TDirectory.Destroy;
begin
   StrDispose(FDirectoryName);
   inherited Destroy;
end;

procedure TDirectory.Clear;
begin
   DirectoryName := '';
   DirectoryDate := 0;
end;

function TDirectory.GetDirectoryName: string;
begin
   Result := StrPas(FDirectoryName);
end;
procedure TDirectory.SetDirectoryName(const Value: string);
begin
   if FDirectoryName <> nil then StrDispose(FDirectoryName);
   FDirectoryName := StrAlloc(Length(Value)+1);
   StrPCopy(FDirectoryName, Value);
end;

{ TUser }

constructor TUser.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   FTaskNames := TStringList.Create;
   ObjectType := otUser;
   Clear;
end;

destructor TUser.Destroy;
begin
   StrDispose(FUserName);
   FTaskNames.Free;
   inherited Destroy;
end;

procedure TUser.Clear;
begin
   FTaskNames.Clear;
   UserName := '';
end;

function TUser.GetUserName: string;
begin
   Result := StrPas(FUserName);
end;
procedure TUser.SetUserName(const Value: string);
begin
   if FUserName <> nil then StrDispose(FUserName);
   FUserName := StrAlloc(Length(Value)+1);
   StrPCopy(FUserName, Value);
end;

{ TMonth }

constructor TMonth.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   ObjectType := oTMonth;
   Clear;
end;

destructor TMonth.Destroy;
begin
   inherited Destroy;
end;

procedure TMonth.Clear;
begin
   Month := 0;
end;

function TMonth.GetMonthName: string;
begin
   Result := sMonthName[FMonth];
end;

{ TEMail }

constructor TEMail.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   ObjectType := otEMail;
   FList := TStringList.Create;
   Clear;
end;

destructor TEMail.Destroy;
begin
   StrDispose(FEMail);
   FList.Free;
   inherited Destroy;
end;

procedure TEMail.Clear;
begin
   EMail[''] := '';
   FList.Clear;
end;

procedure TEMail.WorkEMail(AddressType: string);
var
   DomenEMail: string;
   i,j: Integer;
   s,s1: string;
   ts: TStringList;
begin
   FList.Clear;
   s1 := EMail[''];
   if s1 <> '' then begin
      if UpperCase(AddressType) = 'SMTP' then begin
         FList.Add(ExtractWordNew(1, s1, ['@']));
         DomenEMail := ExtractWordNew(2, s1, ['@']);
         j := WordCountNew(DomenEMail, ['.']);
         for i:=1 to j do FList.Add(ExtractWordNew(i, DomenEmail, ['.']));
         end
      else
      if UpperCase(AddressType) = 'EX' then begin
         TS := TStringList.Create;
         j := WordCountNew(s1, ['/','=']);
         i := 1;
         TS.Add('RU');
         while i <= j do begin
            s := UpperCase(ExtractWordNew(i, s1, ['/','=']));
            if s = 'O' then begin
               s := ExtractWordNew(i+1, s1, ['/','=']);
               TS.Add(s);
               end
            else
            if s = 'OU' then begin
               s := ExtractWordNew(i+1, s1, ['/','=']);
               TS.Add(s);
               end
            else
            if s = 'CN' then begin
               s := UpperCase(ExtractWordNew(i+1, s1, ['/','=']));
               if (s <> 'RECIPIENTS') then
                  TS.Add(s);
            end;
            Inc(i);
         end;

         for i:=TS.Count-1 downto 0 do FList.Add(TS.Strings[i]);
         TS.Free;

         end
      else begin
         FList.Add(s1+'('+AddressType+')');
      end;
   end;
end;

function TEMail.GetEMail(const AddressType: string): string;
begin
   Result := StrPas(FEMail);
end;
procedure TEMail.SetEMail(const AddressType,Value: string);
begin
   if FEMail <> nil then StrDispose(FEMail);
   FEMail := StrAlloc(Length(Value)+1);
   StrPCopy(FEMail, Value);
   WorkEMail(AddressType);
end;

function TEMail.GetDomain(ADimention: Integer): string;
var
   i: Integer;
begin
   Result := '';
   if List.Count > 0 then begin
      for i:=List.Count-ADimention to List.Count-1 do begin
         if i > 1 then
            Result := Result + '.'+List.Strings[i]
         else
            Result := Result + List.Strings[i];
      end;
   end;
end;

function TEMail.GetDomainCount: Integer;
begin
   Result := List.Count-1;
end;

function TEMail.GetUser: string;
begin
   Result := '';
   if List.Count > 0 then begin
      Result := List.Strings[0];
   end;
end;

end.
