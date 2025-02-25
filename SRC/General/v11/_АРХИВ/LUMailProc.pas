unit LUMailProc;

interface

uses
   Sysutils, Classes, MAPI, Dialogs,
   LUSupport, LULog, LUMAPICDO, LUScanDir;

type
   TMailProcedure = class(TComponent)
   private
      FMAPISession: TCDOSession;
      FInputMessages: TCDOMessages;
      FOutputMessages: TCDOMessages;
      FAttachPathName: string;
      FMailActive: Boolean;
   public
      constructor CreateProcedure(AOwner: Tcomponent;
         aCaseProFile: Boolean; aProfile: string; APPLog: TFileMemoLog);
      destructor Destroy; override;
      function LoginUser: Boolean;
      function LogoutUser: Boolean;
      property MAPISession: TCDOSession read FMAPISession;
      property InputMessages: TCDOMessages read FInputMessages;
      property OutputMessages: TCDOMessages read FOutputMessages;
      property MailActive: Boolean read FMailActive;
   end;

var
   FMailProcedure: TMailProcedure;

function SendMessage(const FileName,AddressTo: string;
   aSubject: string; NoteText: TStringList): Integer;

implementation

const
   SCDONotAvailable = 'Система CDO не установлена';

{ SendMessage }

function SendMessage(const FileName,AddressTo: string;
   aSubject: string; NoteText: TStringList): Integer;
var
   LSaveCurrentDir: string;
begin
   if not FMailProcedure.MailActive then begin
      Result := -4;
      MessageDlg(SCDONotAvailable, mtError, [mbOk], 0)
      end
   else begin
      LSaveCurrentDir := GetCurrentDir;
      if (Trim(AddressTo) <> '') and FMailProcedure.MailActive then begin
         try
            FMailProcedure.LoginUser;
         except
         end;
         try
            with FMailProcedure.OutputMessages do begin
               objFolder := FMailProcedure.MAPISession.GetobjFolder(tfOutbox);
               CreateMail('');
               if CDORecipients.ResolveRecipientAddress(AddressTo, MAPI_TO, False) then begin
                  //CDORecipients.AddAddressTO(AddressTo);
                  CDOMessage.NoteText.Clear;
                  if Assigned(NoteText) then CDOMessage.NoteText.Assign(NoteText);
                  CDOMessage.Subject := aSubject;
                  CDOAttachments.PathNames.Clear;
                  if (Trim(FileName) <> '') and FileExists(FileName) then
                     CDOAttachments.PathNames.Add(FileName);
                  SendMail(True);
                  Result := 0;
                  end
               else begin
                  Result := -1;
                  try
                     DeleteMail;
                  except
                  end;
               end;
            end;
         except
            Result := -2;
         end;
         FMailProcedure.LogoutUser;
         end
      else begin
         Result := -3;
      end;
      ChDir(LSaveCurrentDir);
   end;
end;

{ TMailProcedure }

constructor TMailProcedure.CreateProcedure(AOwner: Tcomponent;
   aCaseProFile: Boolean; aProfile: string; APPLog: TFileMemoLog);
begin
   inherited Create(AOwner);
   FMailActive := False;
   FMAPISession := TCDOSession.Create(nil);
   FAttachPathName := FMAPISession.TempDir;
   FMAPISession.MAPILog := APPLog;
   try
      with FMAPISession do begin
         if Status=0 then begin
            CaseProfile := aCaseProfile;
            Profile := aProfile;
            FMailActive := True;
            end
         else begin
            APPLog.LogString[tlsError,1] := SCDONotAvailable;
         end;
      end;
   except
   end;
   FInputMessages := TCDOMessages.Create(nil);
   FInputMessages.MAPILog := APPLog;
   FOutputMessages := TCDOMessages.Create(nil);
   FOutputMessages.MAPILog := APPLog;
end;

destructor TMailProcedure.Destroy;
begin
   FOutputMessages.Free;
   FInputMessages.Free;
   FMAPISession.Free;
   inherited Destroy;
end;

function TMailProcedure.LoginUser: Boolean;
begin
   Result := False;
   if FMailActive then begin
      try
         FMAPISession.Active := True;
      except
      end;
      if FMAPISession.Status = 0 then begin
         // APPLog.LogString[tlsInfo, 1] := 'Outlook version ('+FMAPISession.CDOVersion+')';
         FMAPISession.CaseProfile := False;
         // APPLog.LogString[tlsInfo, 1] := 'Login: ' + FMAPISession.Profile + '/' + FMAPISession.Address;
         Result := True;
         end
      else begin
         FMAPISession.MAPILog.LogString[tlsInfo, 1] := 'Login: Error';
         FMAPISession.MAPILog.LogString[tlsError,1] := FMAPISession.ErrorString;
         Result := False;
      end;
   end;
end;

function TMailProcedure.LogoutUser: Boolean;
begin
   Result := False;
   if FMailActive then begin
      try
         FMAPISession.Active := False;
      except
      end;
      if FMAPISession.Status = 0 then begin
         // APPLog.LogString [tlsInfo, 1] := 'Logout: ' + FMAPISession.Profile + '/' + FMAPISession.Address;
         Result := True;
         end
      else begin
         FMAPISession.MAPILog.LogString[tlsInfo, 1] := 'Logout: Error';
         FMAPISession.MAPILog.LogString[tlsError,1] := FMAPISession.ErrorString;
         Result := False;
      end;
   end;
end;

end.
