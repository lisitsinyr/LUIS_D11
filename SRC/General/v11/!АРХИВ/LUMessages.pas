{=======================================================}
{ Project:                                              }
{         Delphi VCL Extensions (LU)                    }
{         Copyright (c) 2000 Central Bank Of Russia     }
{ Subject:                                              }
{         Работа с                                      }
{ Author:                                               }
{         Lisitsin Y.R.                                 }
{=======================================================}

unit LUMessages;

interface

uses Classes, SysUtils, Windows,
     LUObjects, LUParser, LUSupport, LUExec, LULog;

type
   TBancomMessages = class(TComponent)
   private
      FFileName: PChar;
      FMemoLog: TFileMemoLog;
      FLogFileName: PChar;
      FSourceStream: TFileStream;
      FSourceParser: TLUParser;
      FMessageStream: TMemoryStream;
      FDestStream: TFileStream;
      FAttachBegin: Longint;
      FAttachEnd: Longint;
      FAttachFile: TStringList;

      FFromAddress: PChar;
      FToAddress: PChar;
      FSubject: PChar;
      FDate: PChar;
      FMessageID: PChar;
      FMailer: PChar;
      FList: TStringList;
      FLUParser: TLUParser;
      FHeaderExist: Boolean;
      function GetFileName: string;
      procedure SetFileName(const Value: string);
      function GetHeader: TStringList;
      function GetFileText(CodeFile: string): TStringList;
      procedure SetFileText(CodeFile: string; Value: TStringList);
      function GetFromAddress: string;
      procedure SetFromAddress(const Value: string);
      function GetToAddress: string;
      procedure SetToAddress(const Value: string);
      function GetSubject: string;
      procedure SetSubject(const Value: string);
      function GetDate: string;
      procedure SetDate(const Value: string);
      function GetMailer: string;
      procedure SetMailer(const Value: string);
      function GetMessageID: string;
      procedure SetMessageID(const Value: string);
      function GetEOF: Boolean;
      {}
      procedure ConvertDos2Win;
      procedure ConvertWin2Dos;
      procedure ProcessFileName;
   public
      constructor Create(AOwner: TComponent); override;
      destructor Destroy; override;
      procedure OpenFileName;
      procedure CloseFileName;
      procedure ReadMessage;
      procedure ExtractToFile(const FileNameDest: string);
      {}
      property FileName: string read GetFileName write SetFileName;
      property Header: TStringList read GetHeader;
      property FileText[CodeFile: string]: TStringList read GetFileText write SetFileText;
      property AttachFile: TStringList read FAttachFile;
      property MemoLog: TFileMemoLog read FMemoLog write FMemoLog;
      {}
      property FromAddress: string read GetFromAddress write SetFromAddress;
      property ToAddress: string read GetToAddress write SetToAddress;
      property Subject: string read GetSubject write SetSubject;
      property Date: string read GetDate write SetDate;
      property Mailer: string read GetMailer write SetMailer;
      property MessageID: string read GetMessageID write SetMessageID;
      property EOF: Boolean read GetEOF;
      {}
      property HeaderExist: Boolean read FHeaderExist;
   end;

implementation

{ TBancomMessages }

constructor TBancomMessages.Create(AOwner: TComponent);
begin
   inherited Create(AOwner);
   {}
   FileName := '';
   FMemoLog := nil;
   FSourceStream := nil;
   FDestStream := nil;
   FromAddress := '';
   ToAddress := '';
   Date := '';
   MessageID := '';
   Mailer := '';
   Subject := '';
   FList := TStringList.Create;
   FSourceParser := TLUParser.Create(nil);
   FLUParser := TLUParser.Create(nil);
   FHeaderExist := False;
   FMessageStream := TMemoryStream.Create;
   FAttachFile := TStringList.Create;
end;

destructor TBancomMessages.Destroy;
begin
   FAttachFile.Free;
   FMessageStream.Free;
   FLUParser.Free;
   FSourceParser.Free;
   FList.Free;
   StrDispose(FSubject);
   StrDispose(FMailer);
   StrDispose(FMessageID);
   StrDispose(FDate);
   StrDispose(FToAddress);
   StrDispose(FFromAddress);
   if Assigned(FSourceStream) then FSourceStream.Free;
   StrDispose(FFileName);
   {}
   inherited Destroy;
end;

{ FileName }

function TBancomMessages.GetFileName: string;
begin
   Result := StrPas(FFileName);
end;
procedure TBancomMessages.SetFileName(const Value: string);
begin
   if FFileName <> nil then StrDispose(FFileName);
   FFileName := StrAlloc(Length(Value)+1);
   StrPCopy(FFileName, Value);
end;

{ Header }

function TBancomMessages.GetHeader: TStringList;
var
  TempStream : TMemoryStream;
begin
   FList.Clear;
   if Assigned(FSourceStream) and HeaderExist then begin
      FSourceStream.Seek(0, soFromBeginning);
      TempStream := TMemoryStream.Create;
      try
         TempStream.CopyFrom(FSourceStream, FLUParser.SourcePos);
         TempStream.Position := 0;
         FList.LoadFromStream(TempStream);
         ConvertDos2Win;
      finally
         TempStream.Free;
      end;
   end;
   Result := FList;
end;

{ FileText }

function TBancomMessages.GetFileText(CodeFile: string): TStringList;
var
  TempStream : TMemoryStream;
begin
   FList.Clear;
   if Assigned(FSourceStream) then begin
      FSourceStream.Seek(FLUParser.SourcePos, soFromBeginning);
      TempStream := TMemoryStream.Create;
      try
         TempStream.CopyFrom(FSourceStream, FSourceStream.Size-FSourceStream.Position);
         TempStream.Position := 0;
         FList.LoadFromStream(TempStream);
         if UpperCase(CodeFile) = 'DOS' then ConvertDos2Win;
      finally
         TempStream.Free;
      end;
   end;
   Result := FList;
end;
procedure TBancomMessages.SetFileText(CodeFile: string; Value: TStringList);
begin
   FDestStream := TFileStream.Create(FileName, fmCreate);
   try
      Value.SaveToStream(FDestStream);
   finally
      FDestStream.Free;
   end;
end;

{ FromAddress }

function TBancomMessages.GetFromAddress: string;
begin
   Result := StrPas(FFromAddress);
end;
procedure TBancomMessages.SetFromAddress(const Value: string);
begin
   if FFromAddress <> nil then StrDispose(FFromAddress);
   FFromAddress := StrAlloc(Length(Value)+1);
   StrPCopy(FFromAddress, Value);
end;

{ ToAddress }

function TBancomMessages.GetToAddress: string;
begin
   Result := StrPas(FToAddress);
end;
procedure TBancomMessages.SetToAddress(const Value: string);
begin
   if FToAddress <> nil then StrDispose(FToAddress);
   FToAddress := StrAlloc(Length(Value)+1);
   StrPCopy(FToAddress, Value);
end;

{ Subject }

function TBancomMessages.GetSubject: string;
begin
   Result := StrPas(FSubject);
end;
procedure TBancomMessages.SetSubject(const Value: string);
begin
   if FSubject <> nil then StrDispose(FSubject);
   FSubject := StrAlloc(Length(Value)+1);
   StrPCopy(FSubject, Value);
end;

{ Date }

function TBancomMessages.GetDate: string;
begin
   Result := StrPas(FDate);
end;
procedure TBancomMessages.SetDate(const Value: string);
begin
   if FDate <> nil then StrDispose(FDate);
   FDate := StrAlloc(Length(Value)+1);
   StrPCopy(FDate, Value);
end;

{ Mailer }

function TBancomMessages.GetMailer: string;
begin
   Result := StrPas(FMailer);
end;
procedure TBancomMessages.SetMailer(const Value: string);
begin
   if FMailer <> nil then StrDispose(FMailer);
   FMailer := StrAlloc(Length(Value)+1);
   StrPCopy(FMailer, Value);
end;

{ MessageID }

function TBancomMessages.GetMessageID: string;
begin
   Result := StrPas(FMessageID);
   Result := ExtractWordNew(2,Result,['<','@']);
end;
procedure TBancomMessages.SetMessageID(const Value: string);
begin
   if FMessageID <> nil then StrDispose(FMessageID);
   FMessageID := StrAlloc(Length(Value)+1);
   StrPCopy(FMessageID, Value);
end;

{ ConvertDos2Win }

procedure TBancomMessages.ConvertDos2Win;
var
   p: PChar;
begin
   p := FList.GetText;
   OEMtoChar(p,p);
   FList.SetText(p);
   if p <> nil then StrDispose(p);
end;

{ ConvertWin2Dos }

procedure TBancomMessages.ConvertWin2Dos;
var
   p: PChar;
begin
   p := FList.GetText;
   CharToOEM(p,p);
   FList.SetText(p);
   if p <> nil then StrDispose(p);
end;

{ ExtractToFile}

procedure TBancomMessages.ExtractToFile(const FileNameDest: string);
var
   LSize: Longint;
   LSourceStream: TFileStream;
   LTempStream : TMemoryStream;
begin
   LSize := FAttachEnd-FAttachBegin;
   if LSize > 0 then begin
      LSourceStream := TFileStream.Create(FileName, fmOpenRead+fmShareDenyWrite);
      LSourceStream.Seek(FAttachBegin, soFromBeginning);
      (*
      try
         FDestStream := TFileStream.Create(FileNameDest, fmCreate);
         FDestStream.CopyFrom(LSourceStream, LSize);
      finally
         FDestStream.Free;
      end;
      *)
      try
         LTempStream := TMemoryStream.Create;
         LTempStream.CopyFrom(LSourceStream, LSize);
         LTempStream.Position := 0;
         FAttachFile.LoadFromStream(LTempStream);
         //if UpperCase(CodeFile) = 'DOS' then ConvertDos2Win;
      finally
         LTempStream.Free;
      end;

      LSourceStream.Free;
   end;
end;

{ OpenFileName }

procedure TBancomMessages.OpenFileName;
begin
   if FileName <> '' then begin
      if Assigned(FSourceStream) then FSourceStream.Free;
      try
         FSourceStream := TFileStream.Create(FileName, fmOpenRead+fmShareDenyWrite);
         FSourceParser.Stream := FSourceStream;
      except
      end;
   end;
end;

{ CloseFileName }

procedure TBancomMessages.CloseFileName;
begin
   if Assigned(FSourceStream) then begin
      FSourceStream.Free;
      FSourceStream := nil;
   end;
end;

procedure TBancomMessages.ReadMessage;
var
   TokenString: string;
   NStr: Integer;
   s: string;
   LSave: Longint;
begin
   FromAddress := '';
   ToAddress := '';
   Subject := '';
   Date := '';
   MessageID := '';
   Mailer := '';
   NStr := 0;
   if FSourceParser.SourcePos = 0 then
      FSourceParser.NextToken;
   { Check Header }
   FHeaderExist := False;
   if (FSourceParser.Token = toSymbol) or (FSourceParser.Token = toSymbolx) then begin
      TokenString := FSourceParser.TokenString;
      while FSourceParser.Token <> toEOF do begin
         TokenString := '';
         case FSourceParser.Token of
            toSymbol: begin
               NStr := FSourceParser.SourceLine;
               TokenString := FSourceParser.TokenString;
               s := Trim(ExtractWordNew(1,TokenString,[':']));
               if UpperCase(Trim(s)) = 'FROM' then
                  FromAddress := Trim(ExtractWordNew(2,TokenString,[':']));
               if UpperCase(Trim(s)) = 'TO' then
                  ToAddress := Trim(ExtractWordNew(2,TokenString,[':']));
               if UpperCase(Trim(s)) = 'SUBJECT' then
                  SUBJECT := Trim(ExtractWordNew(2,TokenString,[':']));
               if UpperCase(Trim(s)) = 'DATE' then
                  DATE := Trim(ExtractWordNew(2,TokenString,[':']));
               if UpperCase(Trim(s)) = 'X-MAILER' then
                  Mailer := Trim(ExtractWordNew(2,TokenString,[':']));
               if UpperCase(Trim(s)) = 'MESSAGE-ID' then
                  MessageID := Trim(ExtractWordNew(2,TokenString,[':']));
               //if Trim(TokenString) = '' then break;
            end;
         end;
         FSourceParser.NextToken;
         if (FSourceParser.SourceLine-NStr) > 1 then break;
      end;

      { Attach File }
      FAttachBegin := FSourceParser.SourcePos;
      while FSourceParser.Token <> toEOF do begin
         TokenString := '';
         case FSourceParser.Token of
            toSymbol: begin
               TokenString := FSourceParser.TokenString;
               if TokenString = #1#1#1#1 then break;
            end;
         end;
         FSourceParser.NextToken;
      end;
      FAttachEnd := FSourceParser.SourcePos;
      {}
      ExtractToFile(IncludeTrailingBackslash(GetTempDir)+MessageID);
   end
end;

function TBancomMessages.GetEOF: Boolean;
begin
   Result := FSourceParser.Token = toEOF;
end;

procedure TBancomMessages.ProcessFileName;
var
   TokenString: string;
   NStr: Integer;
   s: string;
begin
   FromAddress := '';
   ToAddress := '';
   Subject := '';
   Date := '';
   MessageID := '';
   Mailer := '';
   NStr := 0;
   FLUParser.NextToken;
   { Check Header }
   FHeaderExist := False;
   if (FLUParser.Token = toSymbol) then begin
      TokenString := FLUParser.TokenString;
      s := ExtractWordNew(1,TokenString,[':']);
      if UpperCase(Trim(s)) = 'FROM' then begin
         FHeaderExist := True;
         {}
         while FLUParser.Token <> toEOF do begin
            case FLUParser.Token of
               toSymbol: begin
                  NStr := FLUParser.SourceLine;
                  TokenString := FLUParser.TokenString;
                  s := ExtractWordNew(1,TokenString,[':']);
                  if UpperCase(Trim(s)) = 'FROM' then
                     FromAddress := Trim(ExtractWordNew(2,TokenString,[':']));
                  if UpperCase(Trim(s)) = 'TO' then
                     ToAddress := Trim(ExtractWordNew(2,TokenString,[':']));
                  if UpperCase(Trim(s)) = 'SUBJECT' then begin
                     SUBJECT := Trim(ExtractWordNew(2,TokenString,[':']));
                  end;
                  if UpperCase(Trim(s)) = 'DATE' then
                     DATE := Trim(ExtractWordNew(2,TokenString,[':']));
                  if UpperCase(Trim(s)) = 'MESSAGE-ID' then
                     MessageID := Trim(ExtractWordNew(2,TokenString,[':']));
                  if UpperCase(Trim(s)) = 'X-MAILER' then
                     Mailer := Trim(ExtractWordNew(2,TokenString,[':']));
                  if Trim(TokenString) = '' then
                     break;
               end;
               DChar: begin
               end;
            end;
            FLUParser.NextToken;
            if (FLUParser.SourceLine-NStr) > 1 then
               break;
         end;
         OEMToChar(FSubject, FSubject);
         OEMToChar(FDate, FDate);
      end;
   end;
end;

end.
