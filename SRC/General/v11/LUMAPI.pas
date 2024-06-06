{=======================================================}
{ Project:                                              }
{         Delphi VCL Extensions (LU)                    }
{         Copyright (c) 2000 Central Bank Of Russia     }
{ Subject:                                              }
{         MAPI                                          }
{ Author:                                               }
{         Lisitsin Y.R.                                 }
{=======================================================}

unit LUMAPI;

interface

uses Classes, Forms, ActiveX, Windows,
     SysUtils, FileCtrl, Dialogs, Registry, ComObj,
     LULog, LUSupport;

type

   { TMAPIObject }

   TMAPIObject = class(TComponent)
   private
      FErrorProcedure: PChar;          { ErrorProcedure }
      FErrors: TStringList;
      FStatus: Cardinal;
      FFileMemoLog: TFileMemoLog;
      FMAPIShowError: Boolean;
   public
      constructor Create(AOwner: Tcomponent);                 override;
      destructor Destroy;                                     override;
      function MAPIHandleException (E: Exception): string;
      procedure ClearErrors;
      function ErrorString: string;
      procedure ShowError;
      function GetErrorProcedure: string;
      procedure SetErrorProcedure(const Value: string);
      property Status: Cardinal read FStatus write FStatus;
      property Errors: TStringList read FErrors;
   published
      property MAPILog: TFileMemoLog read FFileMemoLog write FFileMemoLog;
      property MAPIShowError: Boolean read FMAPIShowError write FMAPIShowError;
      property ErrorProcedure: string read GetErrorProcedure write SetErrorProcedure;
   end;

   { TCustomMAPISession }

   TCustomMAPISession = class(TMAPIObject)
   private
      FTempDir: PChar;
      FCaseProfile: Boolean;
      FAddress: PChar;
      FProfiles: TStringList;
      FAliasProfiles: TStringList;
      FActive: Boolean;
      FLogonAccess: Boolean;
      function GetTempDir: string;
      procedure SetTempDir(const Value: string);
      function GetProfile: string;
      procedure SetProfile(const Value: string);
      function GetProfiles: TStringList;
      function GetAddress: string;
      procedure SetAddress(const Value: string);
      function GetDefaultProfile: string;
      procedure SetActive(const Value: Boolean);
      procedure SetCaseProfile(const Value: Boolean);
      function CheckMAPI: Boolean;
      function GetAlias (const Profile: string): string;
   protected
      FProfile: PChar;          { Profile }
      FList: TStringList;
      function Logon: Boolean;                                  virtual; abstract;
      function Logoff: Boolean;                                 virtual; abstract;
   public
      FHandle: Longint;        { Window  }
      constructor Create(AOwner: Tcomponent);                   override;
      destructor Destroy;                                       override;
      { Property }
      property Handle: Longint read FHandle;
      property Alias[const Profile: string]: string read GetAlias;
   published
      property DefaultProfile: string read GetDefaultProfile;
      property Active: Boolean read FActive write SetActive;
      property LogonAccess: Boolean read FLogonAccess write FLogonAccess;
      property Profile: string read GetProfile write SetProfile;
      property Profiles: TStringList read GetProfiles;
      property AliasProfiles: TStringList read FAliasProfiles;
      property Address: string read GetAddress write SetAddress;
      property CaseProfile: Boolean read FCaseProfile write SetCaseProfile;
      property TempDir: string read GetTempDir write SetTempDir;
   end;

implementation

const
   MAPIErrorMinCount = 0;
   MAPIErrorMaxCount = 26;
   MAPIError: array [MAPIErrorMinCount..MAPIErrorMaxCount] of string = (
      'SUCCESS_SUCCESS = 0',
      'MAPI_USER_ABORT = 1',
      'MAPI_E_FAILURE = 2',
      'MAPI_E_LOGON_FAILURE = 3',
      'MAPI_E_DISK_FULL = 4',
      'MAPI_E_INSUFFICIENT_MEMORY = 5',
      'MAPI_E_ACCESS_DENIED = 6',
      'MAPI_E = 7',
      'MAPI_E_TOO_MANY_SESSIONS = 8',
      'MAPI_E_TOO_MANY_FILES = 9',
      'MAPI_E_TOO_MANY_RECIPIENTS = 10',
      'MAPI_E_ATTACHMENT_NOT_FOUND = 11',
      'MAPI_E_ATTACHMENT_OPEN_FAILURE = 12',
      'MAPI_E_ATTACHMENT_WRITE_FAILURE = 13',
      'MAPI_E_UNKNOWN_RECIPIENT = 14',
      'MAPI_E_BAD_RECIPTYPE = 15',
      'MAPI_E_NO_MESSAGES = 16',
      'MAPI_E_INVALID_MESSAGE = 17',
      'MAPI_E_TEXT_TOO_LARGE = 18',
      'MAPI_E_INVALID_SESSION = 19',
      'MAPI_E_TYPE_NOT_SUPPORTED = 20',
      'MAPI_E_AMBIGUOUS_RECIPIENT = 21',
      'MAPI_E_MESSAGE_IN_USE = 22',
      'MAPI_E_NETWORK_FAILURE = 23',
      'MAPI_E_INVALID_EDITFIELDS = 24',
      'MAPI_E_INVALID_RECIPS = 25',
      'MAPI_E_NOT_SUPPORTED = 26'
   );



function GetNameKeyProfiles: string;
begin
   if IsNT then
      Result := 'SOFTWARE\Microsoft\Windows NT\CurrentVersion\Windows Messaging Subsystem\Profiles'
   else
      Result := 'SOFTWARE\Microsoft\Windows Messaging Subsystem\Profiles';
end;

function GetNameKeyWMS: string;
begin
   if IsNT then
      Result := 'SOFTWARE\Microsoft\Windows Messaging Subsystem'
   else
      Result := 'SOFTWARE\Microsoft\Windows Messaging Subsystem';
end;

{ TMAPIObject }

constructor TMAPIObject.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   FErrors := TStringList.Create;
   FFileMemoLog := nil;
   ErrorProcedure := '';
   ClearErrors;
   FMAPIShowError := False;
end;

destructor TMAPIObject.Destroy;
begin
   StrDispose(FErrorProcedure);
   FErrors.Free;
   inherited Destroy;
end;

procedure TMAPIObject.ClearErrors;
begin
   FStatus := 0;
   FErrors.Clear;
end;

function TMAPIObject.ErrorString: string;
begin
   if (FStatus > MAPIErrorMinCount) and (FStatus <= MAPIErrorMaxCount) then
      Result := 'Error MAPI: '+MAPIError[FStatus]
   else begin
      Result := FErrors.Text;
   end;
end;

function TMAPIObject.GetErrorProcedure: string;
begin
   Result := StrPas(FErrorProcedure);
end;
procedure TMAPIObject.SetErrorProcedure(const Value: string);
begin
   if FErrorProcedure <> nil then StrDispose(FErrorProcedure);
   FErrorProcedure := StrAlloc(Length(Value)+1);
   StrPCopy(FErrorProcedure, Value);
end;

procedure TMAPIObject.ShowError;
begin
   MessageDlg(ErrorString, mtError, [mbOK], 0);
end;

function TMAPIObject.MAPIHandleException (E: Exception): string;
begin
   Result := E.Message;
   if (E is EOLEError) then begin
      Result := 'EOLEError '+Result;
      if Pos('E_ACCESSDENIED', Result) > 0 then
         FStatus := 997
      else begin
         FStatus := 995;
      end;
      end
   else
   if (E is EOLESysError) then begin
      Result := 'EOLESysError '+Result;
      FStatus := 998;
      end
   else
   if (E is EOLEException) then begin
      Result := 'EOLEException '+Result;
      FStatus := EOLEException(E).ErrorCode;
      if FStatus = 0 then FStatus := 996;
      end
   else begin
      FStatus := 999;
      Result := 'исключительная операция не обработана';
   end;
   Result := 'MAPIHandleException: '+IntToStr(FStatus)+' - '+Result;
   FErrors.Add(Result);
   if Assigned(MAPILog) then MAPILog.LogString [tlsError, 0] := ErrorString;
   if FMAPIShowError then ShowError;
end;

{ TCustomMAPISession }

constructor TCustomMAPISession.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   ClearErrors;
   FProfiles := TStringList.Create;
   FAliasProfiles := TStringList.Create;
   FList := TStringList.Create;
   if isConsole then CoInitialize(nil);
   if isConsole {or (csDesigning in ComponentState)} then begin
      FHandle := 0;
      end
   else begin
      FHandle := Application.Handle;
   end;
   FActive := False;
   FCaseProfile := True;
   Profile := '';
   Address := '';
   {}
   FTempDir := StrAlloc(255);
   GetTempPath(255, FTempDir);
   if not DirectoryExists(TempDir) then ForceDirectories(TempDir);
   {}
   if not CheckMAPI then FStatus := 995;
   {}
   LogonAccess := False;
end;

destructor TCustomMAPISession.Destroy;
begin
   FProfiles.Free;
   FAliasProfiles.Free;
   FList.Free;
   StrDispose(FProfile);
   StrDispose(FAddress);
   StrDispose(FTempDir);
   inherited Destroy;
end;

function TCustomMAPISession.GetTempDir: string;
begin
   Result := Trim(StrPas(FTempDir));
end;
procedure TCustomMAPISession.SetTempDir(const Value: string);
begin
   if FTempDir <> nil then StrDispose(FTempDir);
   FTempDir := StrAlloc(Length(Value)+1);
   StrPCopy(FTempDir, Value);
end;

function TCustomMAPISession.CheckMAPI: Boolean;
var
   OSVersionInfo: TOSVersionInfo;
   hkWMS: HKEY;
   hkWMSUser: HKEY;
   MAPIValueSize: Longint;
   MAPIValueBuf: array[0..8] of char;
   rType: Longint;
   s : string;
begin
   Result := False;
   OSVersionInfo.dwOSVersionInfoSize := SizeOf(OSVersionInfo);
   GetVersionEx(OSVersionInfo);
   if (OSVersionInfo.dwMajorVersion > 3) or
      ((OSVersionInfo.dwMajorVersion = 3) and (OSVersionInfo.dwMinorVersion > 51)) then begin
      { Exist WMS }
      s := GetNameKeyWMS;
      MAPIValueSize := sizeof(MAPIValueBuf);
      if RegOpenKeyEx(HKEY_LOCAL_MACHINE, PChar(s), 0, KEY_READ, hkWMS) <> ERROR_SUCCESS then Exit;
      if RegQueryValueEx(hkWMS, 'OLEMessaging', nil, @rType, @MAPIValueBuf, @MAPIValueSize) <> ERROR_SUCCESS then Exit;
      RegCloseKey(hkWMS);
      if not ((MAPIValueBuf[0] = '1') and (MAPIValueBuf[1] = #0)) then Exit;
      { Exist Default Profile}
      s := GetNameKeyProfiles;
      if RegOpenKeyEx(HKEY_CURRENT_USER, PChar(s), 0, KEY_READ, hkWMSUser) <> ERROR_SUCCESS then Exit;
      RegCloseKey(hkWMSUser);
      Result := True;
      end
   else begin
      { Win 3.11 }
      if GetProfileInt('Mail', 'MAPI', 0) = 0 then Exit;
      Result := True;
   end;
   GetProfiles;
   Profile := GetDefaultProfile;
end;

function TCustomMAPISession.GetProfiles: TStringList;
var
   Reg : TRegistry;
   TS1,TS2 : TStringList;
   i,j: Integer;
   s1,s2 : string;
begin
   { Get Profiles}
   FProfiles.Clear;
   TS1 := TStringList.Create;
   TS2 := TStringList.Create;
   Reg := TRegistry.Create;
   with Reg do begin
      RootKey := HKEY_CURRENT_USER;
      s1 := GetNameKeyProfiles;
      OpenKey(s1, False);
      GetKeyNames(TS1);
      CloseKey;
      for i:=0 to TS1.Count-1 do begin
         if OpenKey(s1+'\'+TS1.Strings[i], False) then begin
            GetKeyNames(TS2);
            CloseKey;
            for j:=0 to TS2.Count-1 do begin
               if OpenKey(s1+'\'+TS1.Strings[i]+'\'+TS2.Strings[j], False) then begin

                  s2 := ReadString('001e6750');
                  if Trim(s2) <> '' then FProfiles.Add(Trim(S2));

                  s2 := ReadString('001e6603');
                  if Trim(s2) <> '' then FAliasProfiles.Add(Trim(S2));

               end;
               CloseKey;
            end;
         end;
         CloseKey;
      end;
   end;
   TS1.Free;
   TS2.Free;
   Reg.Free;
   Result := FProfiles;
end;

function TCustomMAPISession.GetAlias (const Profile: string): string;
var
   i: Integer;
begin
   Result := '';
   for i:=0 to Profiles.Count-1 do begin
      if UpperCase(Profile) = UpperCase(Profiles[i]) then begin
         Result := AliasProfiles[i];
      end;
   end;
end;

function TCustomMAPISession.GetDefaultProfile: string;
var
   Reg : TRegistry;
begin
   { Get DefaultProfile }
   Reg := TRegistry.Create;
   with Reg do begin
      RootKey := HKEY_CURRENT_USER;
      OpenKey(GetNameKeyProfiles, False);
      Result := ReadString('DefaultProfile');
      CloseKey;
   end;
   Reg.Free;
end;

function TCustomMAPISession.GetProfile: string;
begin
   Result := StrPas(FProfile);
end;
procedure TCustomMAPISession.SetProfile(const Value: string);
begin
   if FProfile <> nil then StrDispose(FProfile);
   FProfile := StrAlloc(Length(Value)+1);
   StrPCopy(FProfile, Value);
end;

function TCustomMAPISession.GetAddress: string;
begin
   Result := StrPas(FAddress);
end;
procedure TCustomMAPISession.SetAddress(const Value: string);
begin
   if FAddress <> nil then StrDispose(FAddress);
   FAddress := StrAlloc(Length(Value)+1);
   StrPCopy(FAddress, Value);
end;

procedure TCustomMAPISession.SetActive(const Value: Boolean);
begin
   if Value then begin
      FActive := Logon;
      end
   else begin
      if Active then Logoff;
      FActive := Value;
   end;
end;

procedure TCustomMAPISession.SetCaseProfile(const Value: Boolean);
begin
   if Value then Profile := '';
   FCaseProfile := Value;
end;

end.
