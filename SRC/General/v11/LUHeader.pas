(*
 =======================================================
 Copyright (c) 2023
 Author:
     Lisitsin Y.R.
 Project:
     LU_PAS
     Delphi VCL Extensions (LU)
 Module:
     LUHeader
     Работа с Header.exe
 =======================================================
*)

unit LUHeader;

interface

uses Classes, SysUtils, Windows,
    LUObjects, LUParser, LUSupport, LUExec, LULog, LUStrUtils, LUScanDir;

type
    THeaderFile = class(TStringList)
    private
        FFileName: PChar;
        FList: TStringList;
        function GetFileName: string;
        procedure SetFileName (const Value: string);
        procedure ConvertDos2Win;

    public
        constructor Create;
        destructor Destroy; override;
        property FileName: string read GetFileName write SetFileName;
    end;

    TTasks = class(THeaderFile)
        function GetTaskName (Index: Integer): string;
        function GetTaskCaption (Index: Integer): string;
        function GetTaskExist (Value: string): Boolean;

    public
        constructor Create;
        destructor Destroy; override;
        procedure SortTaskCaption;
        procedure SortTaskName;
        function IndexOfTask (const Value: string): Integer;
        property TaskName[index: Integer]: string read GetTaskName;
        property TaskCaption[index: Integer]: string read GetTaskCaption;
        property TaskExist[Value: string]: Boolean read GetTaskExist;
    end;

    TDests = class(THeaderFile)
        function GetDest (Index: Integer): string;
        function GetDestName (Index: Integer): string;
        function GetDestList: TStringList;
        function GetDestExist (Value: string): Boolean;

    public
        constructor Create;
        destructor Destroy; override;
        procedure SortDest;
        procedure SortDestName;
        function IndexOfDest (const Value: string): Integer;
        property Dest[index: Integer]: string read GetDest;
        property DestName[index: Integer]: string read GetDestName;
        property DestList: TStringList read GetDestList;
        property DestExist[Value: string]: Boolean read GetDestExist;
    end;

    TRegObls = class(THeaderFile)
        function GetAbonent (Index: Integer): string;
        function GetKod1 (Index: Integer): string;
        function GetKod2 (Index: Integer): string;
        function GetKod3 (Index: Integer): string;
        function GetKod4 (Index: Integer): string;
        function GetKod5 (Index: Integer): string;
        function GetAbonentName (Index: Integer): string;
        function GetRegionList: TStringList;
        function GetAbonentList: TStringList;
        function GetRegOblExist (Value: string): Boolean;

    public
        constructor Create;
        destructor Destroy; override;
        procedure AddAbonent (Abonent, Kod1, Kod2, Kod3, Kod4, Kod5,
            AbonentName: string);
        function IndexOfAbonent (const Value: string): Integer;
        function IndexOfAbonentName (const Value: string): Integer;
        procedure SortAbonent;
        procedure SortAbonentName;
      { }
        property Abonent[index: Integer]: string read GetAbonent;
        property Kod1[index: Integer]: string read GetKod1;
        property Kod2[index: Integer]: string read GetKod2;
        property Kod3[index: Integer]: string read GetKod3;
        property Kod4[index: Integer]: string read GetKod4;
        property Kod5[index: Integer]: string read GetKod5;
        property AbonentName[index: Integer]: string read GetAbonentName;
        property RegionList: TStringList read GetRegionList;
        property AbonentList: TStringList read GetAbonentList;
        property RegOblExist[Value: string]: Boolean read GetRegOblExist;
    end;

    TFileMessage = class(TComponent)
    private
        FFileName: PChar;
        FFromAddress: PChar;
        FToAddress: PChar;
        FSubject: PChar;
        FDate: PChar;
        FOptions: PChar;
        FCovering: PChar;
        FPathHeader: PChar;
        FLogFileName: PChar;
        FTaskName: PChar;
        FList: TStringList;
        FSourceStream: TFileStream;
        FDestStream: TFileStream;
        FLUParser: TLUParser;
        FHeaderExist: Boolean;
        FTasks: TTasks;
        FDests: TDests;
        FRegObls: TRegObls;
        FMemoLog: TFileMemoLog;
        function GetFileName: string;
        procedure SetFileName (const Value: string);
        function GetPathHeader: string;
        procedure SetPathHeader (const Value: string);
        function GetLogFileName: string;
        procedure SetLogFileName (const Value: string);
        function GetTaskName: string;
        procedure SetTaskName (const Value: string);
        function GetFromAddress: string;
        procedure SetFromAddress (const Value: string);
        function GetToAddress: string;
        procedure SetToAddress (const Value: string);
        function GetSubject: string;
        procedure SetSubject (const Value: string);
        function GetDate: string;
        procedure SetDate (const Value: string);
        function GetOptions: string;
        procedure SetOptions (const Value: string);
        function GetCovering: string;
        procedure SetCovering (const Value: string);
        function GetHeader: TStringList;
        function GetFileText (CodeFile: string): TStringList;
        procedure SetFileText (CodeFile: string; Value: TStringList);
        procedure ConvertDos2Win;
        procedure ConvertWin2Dos;
        procedure ProcessFileName;
        function CreateHeaderTU: Boolean;
        function CreateHeaderGCI: Boolean;
        function GetLogString: string;

    public
        constructor Create (AOwner: TComponent); override;
        destructor Destroy; override;
        procedure OpenFileName;
        procedure CloseFileName;
        procedure ExtractToFile (const FileNameDest: string);
        function CreateHeader: Boolean;
        function CreateConfirmation: Boolean;
      { }
        property PathHeader: string read GetPathHeader write SetPathHeader;
        property FileName: string read GetFileName write SetFileName;
        property LogFileName: string read GetLogFileName write SetLogFileName;
        property HeaderExist: Boolean read FHeaderExist;
      { }
        property Header: TStringList read GetHeader;
        property FileText[CodeFile: string]: TStringList read GetFileText
            write SetFileText;
        property FromAddress: string read GetFromAddress write SetFromAddress;
        property ToAddress: string read GetToAddress write SetToAddress;
        property Subject: string read GetSubject write SetSubject;
        property Date: string read GetDate write SetDate;
        property Options: string read GetOptions write SetOptions;
        property Covering: string read GetCovering write SetCovering;
        property LogString: string read GetLogString;
      { }
        property TaskName: string read GetTaskName write SetTaskName;
      { }
        property MemoLog: TFileMemoLog read FMemoLog write FMemoLog;
    end;

   { TTask }

    TTask = class(TObjects)
    private
        FTaskName: PChar;
        FTaskCaption: PChar;
        FTaskPath: PChar;
        FTaskPathArc: PChar;
        FTaskPathSAED: PChar;
        FTaskFileNameFilter: PChar;
        FTaskDest: PChar;
        FTaskFileType: PChar;
        FTaskDestPIA: PChar;
        FTaskWaitConfirmation: Boolean;
        FTaskCheckHeader: Boolean;
        FTaskCodeFile: PChar;
        FTaskOptions: PChar;
        FTaskFileNameLCK: PChar;

        FNotReadOnly: Integer;

        function GetTaskName: string;
        procedure SetTaskName (const Value: string);
        function GetTaskCaption: string;
        procedure SetTaskCaption (const Value: string);
        function GetTaskPath: string;
        procedure SetTaskPath (const Value: string);
        function GetTaskPathArc: string;
        procedure SetTaskPathArc (const Value: string);
        function GetTaskPathSAED: string;
        procedure SetTaskPathSAED (const Value: string);
        function GetTaskFileNameFilter: string;
        procedure SetTaskFileNameFilter (const Value: string);
        function GetTaskDest: string;
        procedure SetTaskDest (const Value: string);
        function GetTaskFileType: string;
        procedure SetTaskFileType (const Value: string);
        function GetTaskDestPIA: string;
        procedure SetTaskDestPIA (const Value: string);
        function GetTaskOptions: string;
        procedure SetTaskOptions (const Value: string);
        function GetTaskFileNameLCK: string;
        procedure SetTaskFileNameLCK (const Value: string);
        function GetTaskCodeFile: string;
        procedure SetTaskCodeFile (const Value: string);

    public
        constructor Create (AOwner: TComponent); override;
        destructor Destroy; override;
        procedure Clear;
      { }
        procedure ScanFile (Sender: TScanDirFiles; AFileName: string;
            SR: TSearchRec);
        function GetCountFileNotReadOnly (ATaskName: string; ADate: TDateTime;
            APathStore: string; AAPPFiles: TScanDirFiles): Integer;
      { }
        property TaskName: string read GetTaskName write SetTaskName;
        property TaskCaption: string read GetTaskCaption write SetTaskCaption;
        property TaskCodeFile: string read GetTaskCodeFile
            write SetTaskCodeFile;
      { }
        property TaskPath: string read GetTaskPath write SetTaskPath;
        property TaskFileNameFilter: string read GetTaskFileNameFilter
            write SetTaskFileNameFilter;
        property TaskFileType: string read GetTaskFileType
            write SetTaskFileType;
        property TaskDest: string read GetTaskDest write SetTaskDest;
        property TaskDestPIA: string read GetTaskDestPIA write SetTaskDestPIA;
        property TaskWaitConfirmation: Boolean read FTaskWaitConfirmation
            write FTaskWaitConfirmation;
        property TaskOptions: string read GetTaskOptions write SetTaskOptions;
        property TaskPathArc: string read GetTaskPathArc write SetTaskPathArc;
        property TaskCheckHeader: Boolean read FTaskCheckHeader
            write FTaskCheckHeader;
        property TaskPathSAED: string read GetTaskPathSAED
            write SetTaskPathSAED;
        property TaskFileNameLCK: string read GetTaskFileNameLCK
            write SetTaskFileNameLCK;
    end;

const
    HeaderFileName = 'header.exe';
    HeaderFileNameWIN = 'winheader.exe';
    TaskFileName = 'task.lst';
    DestFileName = 'dest.lst';
    RegOblFileName = 'reg_obl.lst';
   { TaskName }
    sMAILSPR = 'MAILSPR';
    sMAIL = 'MAIL';
    sREPORTMAIL = 'REPORTMAIL';
    sREPORT = 'REPORT';
    sLCK = 'LCK';
    sBADLCK = 'BADLCK';
    sGOODLCK = 'GOODLCK';
    sLISTTER = 'LISTTER';
    sMMFO = 'M+MFO';

function ProgramHeaderExists (const PathHeader: string): Boolean;

implementation

const
    HeaderErrorMinCount = 0;
    HeaderErrorMaxCount = 11;
    HeaderError: array [HeaderErrorMinCount .. HeaderErrorMaxCount]
        of string = ('0 - нормальное завершение',
        '1 - код задачи указан неверно', '2 - отправитель указан неверно',
        '3 - адресат указан неверно', '4 - невозможно открыть журнал',
        '5 - невозможно открыть файл с информацией', '6 - нет места на диске',
        '7 - невозможно открыть файл TASK. LST',
        '8 - невозможно открыть файл REG_OBL. LST',
        '9 - невозможно открыть файл DEST. LST',
        '10 - отсутствует один из параметров',
        '11- не удается выполнить указанную программу');

{ ProgramHeaderExists }

function ProgramHeaderExists (const PathHeader: string): Boolean;
var
    s: string;
begin
    s := IncludeTrailingBackslash (PathHeader);
    Result := FileExists (s + HeaderFileName);
end;

{ TFileMessage }

constructor TFileMessage.Create (AOwner: TComponent);
begin
    inherited Create (AOwner);
    FList := TStringList.Create;
    FSourceStream := nil;
    FDestStream := nil;
    FHeaderExist := False;
    FMemoLog := nil;
    FLUParser := TLUParser.Create (nil);
    FileName := '';
    PathHeader := '';
    TaskName := '';
    LogFileName := '';
   { }
    FromAddress := '';
    ToAddress := '';
    Date := '';
    Subject := '';
    Options := '';
    Covering := '';
    FTasks := TTasks.Create;
    FDests := TDests.Create;
    FRegObls := TRegObls.Create;
end;

destructor TFileMessage.Destroy;
begin
    FList.Free;
    if Assigned (FSourceStream) then
        FSourceStream.Free;
    FLUParser.Free;
   { }
    StrDispose (FFileName);
    StrDispose (FPathHeader);
    StrDispose (FTaskName);
    StrDispose (FLogFileName);
   { }
    StrDispose (FFromAddress);
    StrDispose (FToAddress);
    StrDispose (FDate);
    StrDispose (FSubject);
    StrDispose (FOptions);
    StrDispose (FCovering);
   { }
    FTasks.Clear;
    FTasks.Free;
    FDests.Clear;
    FDests.Free;
    FRegObls.Clear;
    FRegObls.Free;
    inherited Destroy;
end;

{ GetHeader }

function TFileMessage.GetHeader: TStringList;
var
    TempStream: TMemoryStream;
begin
    FList.Clear;
    if Assigned (FSourceStream) and HeaderExist then
    begin
        FSourceStream.Seek (0, soFromBeginning);
        TempStream := TMemoryStream.Create;
        try
            TempStream.CopyFrom (FSourceStream, FLUParser.SourcePos);
            TempStream.Position := 0;
            FList.LoadFromStream (TempStream);
            ConvertDos2Win;
        finally
            TempStream.Free;
        end;
    end;
    Result := FList;
end;

function TFileMessage.GetFileText (CodeFile: string): TStringList;
var
    TempStream: TMemoryStream;
begin
    FList.Clear;
    if Assigned (FSourceStream) then
    begin
        FSourceStream.Seek (FLUParser.SourcePos, soFromBeginning);
        TempStream := TMemoryStream.Create;
        try
            if (FSourceStream.Size - FSourceStream.Position) > 0 then
            begin
                TempStream.CopyFrom (FSourceStream,
                    FSourceStream.Size - FSourceStream.Position);
                TempStream.Position := 0;
                FList.LoadFromStream (TempStream);
                if UpperCase (CodeFile) = 'DOS' then
                    ConvertDos2Win;
            end;
        finally
            TempStream.Free;
        end;
    end;
    Result := FList;
end;

procedure TFileMessage.SetFileText (CodeFile: string; Value: TStringList);
begin
    FDestStream := TFileStream.Create (FileName, fmCreate);
    try
        FList.Clear;
        FList.Assign (Value);
        if UpperCase (CodeFile) = 'DOS' then
            ConvertWin2Dos;
        FList.SaveToStream (FDestStream);
    finally
        FDestStream.Free;
    end;
    CreateHeader;
end;

procedure TFileMessage.ConvertDos2Win;
var
    p: PChar;
begin
    p := FList.GetText;
    OEMtoChar (PAnsiChar(p), PWideChar(p));
    FList.SetText (p);
    if p <> nil then
        StrDispose (p);
end;

procedure TFileMessage.ConvertWin2Dos;
var
    p: PChar;
begin
    p := FList.GetText;
    CharToOEM (PWideChar(p), PAnsiChar(p));
    FList.SetText (p);
    if p <> nil then
        StrDispose (p);
end;

procedure TFileMessage.ExtractToFile (const FileNameDest: string);
begin
    if Assigned (FSourceStream) then
    begin
        FSourceStream.Seek (FLUParser.SourcePos, soFromBeginning);
        FDestStream := TFileStream.Create (FileNameDest, fmCreate);
        try
            if (FSourceStream.Size - FSourceStream.Position) > 0 then
                FDestStream.CopyFrom (FSourceStream,
                    FSourceStream.Size - FSourceStream.Position);
        finally
            FDestStream.Free;
        end;
    end;
end;

procedure TFileMessage.OpenFileName;
begin
    if FileName <> '' then
    begin
        if Assigned (FSourceStream) then
            FSourceStream.Free;
        try
            FSourceStream := TFileStream.Create (FileName,
                fmOpenRead + fmShareDenyWrite);
            FLUParser.Stream := FSourceStream;
            ProcessFileName;
        except
        end;
    end;
end;

procedure TFileMessage.CloseFileName;
begin
    if Assigned (FSourceStream) then
    begin
        FSourceStream.Free;
        FSourceStream := nil;
    end;
end;

procedure TFileMessage.ProcessFileName;
var
    TokenString: string;
    NStr: Integer;
    s: string;
begin
    FromAddress := '';
    ToAddress := '';
    Subject := '';
    Options := '';
    Date := '';
    Covering := '';
    NStr := 0;
    FLUParser.NextToken;
   { Check Header }
    FHeaderExist := False;
    if (FLUParser.Token = toSymbol) then
    begin
        TokenString := FLUParser.TokenString;
        s := ExtractWordNew (1, TokenString, [':']);
        if (UpperCase(Trim(s)) = 'FROM') or (UpperCase(Trim(s)) = 'TO') then
        begin
            FHeaderExist := True;
         { }
            while FLUParser.Token <> toEOF do
            begin
                case FLUParser.Token of
                    toSymbol:
                        begin
                            NStr := FLUParser.SourceLine;
                            TokenString := FLUParser.TokenString;
                            s := ExtractWordNew (1, TokenString, [':']);
                            if UpperCase (Trim(s)) = 'FROM' then
                                FromAddress :=
                                    Trim (ExtractWordNew(2,
                                    TokenString, [':']));
                            if UpperCase (Trim(s)) = 'TO' then
                                ToAddress :=
                                    Trim (ExtractWordNew(2,
                                    TokenString, [':']));
                            if UpperCase (Trim(s)) = 'SUBJECT' then
                            begin
                                Subject :=
                                    Trim (ExtractWordNew(2,
                                    TokenString, [':']));
                                TaskName :=
                                    Trim (ExtractWordNew(1, Subject, [';']));
                            end;
                            if UpperCase (Trim(s)) = 'DATE' then
                                Date := Trim
                                    (ExtractWordNew(2, TokenString, [':']));
                            if UpperCase (Trim(s)) = 'OPTIONS' then
                                Options :=
                                    Trim (ExtractWordNew(2,
                                    TokenString, [':']));
                            if UpperCase (Trim(s)) = 'COVERING' then
                                Covering :=
                                    Trim (ExtractWordNew(2,
                                    TokenString, [':']));
                            if Trim (TokenString) = '' then
                                break;
                        end;
                    DChar:
                        begin
                        end;
                end;
                FLUParser.NextToken;
                if (FLUParser.SourceLine - NStr) > 1 then
                    break;
            end;
            OEMtoChar (PAnsiChar(FSubject), PWideChar(FSubject));
            OEMtoChar (PAnsiChar(FDate), PWideChar(FDate));
        end;
    end;
end;

function TFileMessage.GetFileName: string;
begin
    Result := StrPas (FFileName);
end;

procedure TFileMessage.SetFileName (const Value: string);
begin
    if FFileName <> nil then
        StrDispose (FFileName);
    FFileName := StrAlloc (Length(Value) + 1);
    StrPCopy (FFileName, Value);
end;

function TFileMessage.GetPathHeader: string;
begin
    Result := StrPas (FPathHeader);
end;

procedure TFileMessage.SetPathHeader (const Value: string);
begin
    if FPathHeader <> nil then
        StrDispose (FPathHeader);
    FPathHeader := StrAlloc (Length(Value) + 1);
    StrPCopy (FPathHeader, Value);
    if FileExists (IncludeTrailingBackslash(PathHeader) + HeaderFileName) then
    begin
        FTasks.FileName := IncludeTrailingBackslash (Value) + TaskFileName;
        FDests.FileName := IncludeTrailingBackslash (Value) + DestFileName;
        FRegObls.FileName := IncludeTrailingBackslash (Value) + RegOblFileName;
    end;
end;

function TFileMessage.GetLogFileName: string;
begin
    Result := StrPas (FLogFileName);
end;

procedure TFileMessage.SetLogFileName (const Value: string);
begin
    if FLogFileName <> nil then
        StrDispose (FLogFileName);
    FLogFileName := StrAlloc (Length(Value) + 1);
    StrPCopy (FLogFileName, Value);
end;

function TFileMessage.GetTaskName: string;
begin
    Result := StrPas (FTaskName);
end;

procedure TFileMessage.SetTaskName (const Value: string);
begin
    if FTaskName <> nil then
        StrDispose (FTaskName);
    FTaskName := StrAlloc (Length(Value) + 1);
    StrPCopy (FTaskName, Value);
end;

function TFileMessage.GetFromAddress: string;
begin
    Result := StrPas (FFromAddress);
end;

procedure TFileMessage.SetFromAddress (const Value: string);
begin
    if FFromAddress <> nil then
        StrDispose (FFromAddress);
    FFromAddress := StrAlloc (Length(Value) + 1);
    StrPCopy (FFromAddress, Value);
end;

function TFileMessage.GetToAddress: string;
begin
    Result := StrPas (FToAddress);
end;

procedure TFileMessage.SetToAddress (const Value: string);
begin
    if FToAddress <> nil then
        StrDispose (FToAddress);
    FToAddress := StrAlloc (Length(Value) + 1);
    StrPCopy (FToAddress, Value);
end;

function TFileMessage.GetSubject: string;
begin
    Result := StrPas (FSubject);
end;

procedure TFileMessage.SetSubject (const Value: string);
begin
    if FSubject <> nil then
        StrDispose (FSubject);
    FSubject := StrAlloc (Length(Value) + 1);
    StrPCopy (FSubject, Value);
end;

function TFileMessage.GetDate: string;
begin
    Result := StrPas (FDate);
end;

procedure TFileMessage.SetDate (const Value: string);
begin
    if FDate <> nil then
        StrDispose (FDate);
    FDate := StrAlloc (Length(Value) + 1);
    StrPCopy (FDate, Value);
end;

function TFileMessage.GetOptions: string;
begin
    Result := StrPas (FOptions);
end;

procedure TFileMessage.SetOptions (const Value: string);
begin
    if FOptions <> nil then
        StrDispose (FOptions);
    FOptions := StrAlloc (Length(Value) + 1);
    StrPCopy (FOptions, Value);
end;

function TFileMessage.GetCovering: string;
begin
    Result := StrPas (FCovering);
end;

procedure TFileMessage.SetCovering (const Value: string);
begin
    if FCovering <> nil then
        StrDispose (FCovering);
    FCovering := StrAlloc (Length(Value) + 1);
    StrPCopy (FCovering, Value);
end;

function TFileMessage.CreateConfirmation: Boolean;
var
    Stat: Integer;
    Save: string;
    LPathFileName: string;
    LFileName: string;
    s: string;
    i: Integer;
begin
    Stat := 0;
    FList.Clear;
    FList.Add ('                Справка-подтверждение');
    FList.Add ('');
    FList.Add ('');
   { To }
    if (FRegObls.RegOblExist[ToAddress]) then
    begin
        i := FRegObls.IndexOfAbonent (ToAddress);
        FList.Add (Format('ГУ 11%-S %-S', [FRegObls.Kod1[i],
            FormatDateTime('dd.mm.yyyy hh:nn:ss', Now)]))
    end
    else
        Stat := 3;
    FList.Add ('');
    FList.Add ('');
   { Task }
    if FTasks.TaskExist[TaskName] then
    begin
        s := ExtractWordNew (2, TaskName, ['+']);
        s := Copy (s, 2, Length(s) - 1);
        FList.Add (Format('Форма %-S Отчет %-S    (Отчетная дата %-S)',
            [s, '112711112711173', FormatDateTime('dd.mm.yyyy',
            SysUtils.Date)]));
    end
    else
        Stat := 1;
    FList.Add ('');
    FList.Add ('');
    FList.Add ('ГУ:');
    FList.Add ('     Отчет принят');
    FList.Add ('');
    FList.Add ('');
    FList.Add (Format('Конец протокола обработки по: %-s', [ToAddress]));
   { File }
    LFileName := ExtractFileName (FileName);
    LPathFileName := ExpandFileName (FileName);
   { if not FileExists(LPathFileName) then Stat := 5; }
   { Exec Header }
    if Stat = 0 then
    begin
        Save := GetCurrentDir;
        s := ExtractFileDir (LPathFileName);
        ChDir (s);
        ConvertWin2Dos;
        FList.SaveToFile (LFileName);
        ChDir (Save);
        Subject := Format ('%-S; %-S', [TaskName, 'Протокол обработки отчета']);
    end;
    Result := (Stat = 0);
end;

function TFileMessage.GetLogString: string;
begin
    Result := '';
    if (LogFileName <> '') and FileExists (LogFileName) then
    begin
        FList.Clear;
        FList.LoadFromFile (LogFileName);
        ConvertDos2Win;
        if FList.Count > 0 then
        begin
            Result := FList.Strings[0];
        end;
    end;
end;

function TFileMessage.CreateHeaderGCI: Boolean;
var
    Stat: Integer;
    Save: string;
    LPathFileName: string;
    LFileName: string;
    s: string;
begin
    Stat := 0;
    FList.Clear;
   { From }
    if (FDests.DestExist[FromAddress]) then
        FList.Add (Format('FROM: %-S', [FromAddress]))
    else
        Stat := 2;
   { To }
    if (FRegObls.RegOblExist[ToAddress]) then
        FList.Add (Format('TO: %-S', [ToAddress]))
    else
        Stat := 3;
   { Task }
    if FTasks.TaskExist[TaskName] then
        FList.Add (Format('SUBJECT: %-S; Протокол обработки отчета',
            [TaskName]))
    else
        Stat := 1;
   { Date }
    FList.Add (Format('DATE: %-S',
        [FormatDateTime('dd.mm.yyyy hh:nn:ss', Now)]));
   { Options }
    FList.Add (Format('OPTIONS: %-S', [Options]));
    FList.Add ('');
   { File }
    LFileName := ExtractFileName (FileName);
    LPathFileName := ExpandFileName (FileName);
    if not FileExists (LPathFileName) then
        Stat := 5;
   { Exec Header }
    if Stat = 0 then
    begin
        Save := GetCurrentDir;
        s := ExtractFileDir (LPathFileName);
        ChDir (s);
        ConvertWin2Dos;
        RenameFile (LFileName, '$$$$$$$$.$$$');
        FList.SaveToFile (LFileName);
        CloseFileName;
        FSourceStream := TFileStream.Create (LFileName, fmOpenReadWrite);
        FSourceStream.Seek (0, soFromEnd);
        FDestStream := TFileStream.Create ('$$$$$$$$.$$$', fmOpenRead);
        if (FDestStream.Size) > 0 then
            FSourceStream.CopyFrom (FDestStream, FDestStream.Size);
        FDestStream.Free;
        FDestStream := nil;
        CloseFileName;
        DeleteFile ('$$$$$$$$.$$$');
        ChDir (Save);
    end;
    Result := (Stat = 0);
end;

function TFileMessage.CreateHeaderTU: Boolean;
var
    Status: Cardinal;
    Save: string;
    ParamStr: string;
    Stat: Integer;
    LPathFileName: string;
    LFileName: string;
   { pID, tID, hWnd: Cardinal; }
    WorkDir: string;
    HeaderExe: string;

    procedure GenerateWinHeader;
    begin
        HeaderExe := IncludeTrailingBackslash (PathHeader) + HeaderFileNameWIN;
      { /H /I c:\header\WinHeader.ini -F G:\Nalogi\DATA\GU\GCI_OUT\R_20071001_000000173_2.nlm -T dan -S S+FPRF }

        ParamStr := ParamStr + ' /H';
        ParamStr := ParamStr + ' /I ' + IncludeTrailingBackslash (PathHeader) +
            'WinHeader.ini';
      { File }
        LFileName := ExtractFileName (FileName);
        LPathFileName := ExpandFileName (FileName);
        if FileExists (LPathFileName) then
            ParamStr := ParamStr + ' /F ' + LPathFileName
        else
            Stat := 5;
      { To }
        if (FDests.DestExist[ToAddress]) or (FRegObls.RegOblExist[ToAddress])
        then
            ParamStr := ParamStr + ' /T ' + LowerCase (ToAddress)
        else
            Stat := 3;
      { Task }
        if FTasks.TaskExist[TaskName] then
        begin
            if UpperCase (TaskName) = 'M+MFO' then
            begin
                ParamStr := ParamStr + ' /S ' + LowerCase (TaskName);
            end else begin
                ParamStr := ParamStr + ' /S ' + TaskName
            end;
        end
        else
            Stat := 1;
      { Options }
        if Options <> '' then
            ParamStr := ParamStr + ' /O ' + Options;
    end;

    procedure GenerateHeader;
    begin
        HeaderExe := IncludeTrailingBackslash (PathHeader) + HeaderFileName;
      { From }
        if (FRegObls.RegOblExist[FromAddress])
        { or (FDests.DestExist[FromAddress]) } then
            ParamStr := ParamStr + ' -i ' + FromAddress
        else
            Stat := 2;
      { Log }
        if LogFileName <> '' then
            ParamStr := ParamStr + ' -l ' + LogFileName;
      { File }
        LFileName := ExtractFileName (FileName);
        LPathFileName := ExpandFileName (FileName);
        if FileExists (LPathFileName) then
            ParamStr := ParamStr + ' -f ' + LFileName
        else
            Stat := 5;
      { To }
        if (FDests.DestExist[ToAddress]) or (FRegObls.RegOblExist[ToAddress])
        then
            ParamStr := ParamStr + ' -t ' + LowerCase (ToAddress)
        else
            Stat := 3;
      { Task }
        if FTasks.TaskExist[TaskName] then
            ParamStr := ParamStr + ' -s ' + TaskName
        else
            Stat := 1;
      { Options }
        if Options <> '' then
            ParamStr := ParamStr + ' -o ' + Options;
    end;

begin
    FileSetAttr (FileName, FileGetAttr(FileName) and (faReadOnly xor $FF));
   { Create ParamStr }
    ParamStr := '';
    Stat := 0;

    if Length (ExtractFileName(FileName)) > 12 then
    begin
        GenerateWinHeader;
    end else begin
        GenerateWinHeader;
    end;

   { Exec Header }
    if Stat = 0 then
    begin
        Save := GetCurrentDir;
        WorkDir := ExtractFileDir (LPathFileName);
        Status := 0;
        ChDir (WorkDir);

      (*
      { ODBLib }
      Result := ExecWait(HeaderExe+' '+ParamStr, Stat);
 *)

      (*
      { RALib }
      Status := Execute(HeaderExe+' '+ParamStr, WorkDir);
      Result := (Status=0);
 *)

      (*
      { JEDI }
      Result := ExecDOS(HeaderExe, ParamStr, WorkDir, '', True, True, SW_HIDE);
 *)

        Result := ExecuteAll (HeaderExe, ParamStr, WorkDir, True,
            SW_HIDE, Status);

        MemoLog.LogString[tlsProcess, 1] := HeaderExe + ' ' + ParamStr + ' ' +
            WorkDir + ' Status=' + IntToStr (Status);

      (*
      { Luis }
      Result := WinExecAndWaitLog(HeaderExe, ParamStr, SW_SHOWNORMAL{sw_Hide}, Status, MemoLog);
      Result := WinExecAndWait(HeaderExe, ParamStr, sw_Hide, Status);
      if not Result then if Status = 0 then Stat := HeaderErrorMaxCount;
 *)
        ChDir (Save);
    end;
    Result := (Stat = 0);
end;

function TFileMessage.CreateHeader: Boolean;
begin
    Result := False;
    if PathHeader <> '' then
    begin
      { From }
        if (FRegObls.RegOblExist[FromAddress]) then
            Result := CreateHeaderTU
        else if (FDests.DestExist[FromAddress]) then
            Result := CreateHeaderGCI;
    end;
    FHeaderExist := Result;
end;

{ THeaderFile }

constructor THeaderFile.Create;
begin
    inherited Create;
    FList := TStringList.Create;
    FileName := '';
end;

destructor THeaderFile.Destroy;
begin
    StrDispose (FFileName);
    FList.Free;
    inherited Destroy;
end;

function THeaderFile.GetFileName: string;
begin
    Result := StrPas (FFileName);
end;

procedure THeaderFile.SetFileName (const Value: string);
var
    i: Integer;
begin
    if FFileName <> nil then
        StrDispose (FFileName);
    FFileName := StrAlloc (Length(Value) + 1);
    StrPCopy (FFileName, Value);
    if Value <> '' then
    begin
        Clear;
        try
            LoadFromFile (Value);
            ConvertDos2Win;
            for i := 0 to Count - 1 do
                if (Strings[i][1] = '#') or (Trim(Strings[i]) = '') then
                    Delete (i);
        except
        end;
    end;
end;

procedure THeaderFile.ConvertDos2Win;
var
    p: PChar;
begin
    p := GetText;
    OEMtoChar (PAnsiChar(p), PWideChar(p));
    SetText (p);
    if p <> nil then
        StrDispose (p);
end;

{ TTasks }

function sTaskName (List: TStringList; Index1, Index2: Integer): Integer;
var
    s1, s2: string;
begin
    Result := 0;
    s1 := AnsiUpperCase ((List as TTasks).TaskName[Index1]);
    s2 := AnsiUpperCase ((List as TTasks).TaskName[Index2]);
    if s1 < s2 then
        Result := - 1
    else if s1 > s2 then
        Result := 1
    else if s1 = s2 then
        Result := 0;
end;

function sTaskCaption (List: TStringList; Index1, Index2: Integer): Integer;
var
    s1, s2: string;
begin
    Result := 0;
    s1 := AnsiUpperCase ((List as TTasks).TaskCaption[Index1]);
    s2 := AnsiUpperCase ((List as TTasks).TaskCaption[Index2]);
    if s1 < s2 then
        Result := - 1
    else if s1 > s2 then
        Result := 1
    else if s1 = s2 then
        Result := 0;
end;

constructor TTasks.Create;
begin
    inherited Create;
end;

destructor TTasks.Destroy;
begin
    inherited Destroy;
end;

function TTasks.GetTaskName (Index: Integer): string;
begin
    Result := '';
    try
        Result := Trim (Copy(Strings[index], 1, 10));
        Result := Trim (ExtractWordNew(1, Strings[index], [' ']));
    except
    end;
end;

function TTasks.GetTaskCaption (Index: Integer): string;
begin
    Result := '';
    try
        Result := Trim (Copy(Strings[index], 13, 255));
    except
    end;
end;

procedure TTasks.SortTaskName;
begin
    CustomSort (sTaskName);
end;

procedure TTasks.SortTaskCaption;
begin
    CustomSort (sTaskCaption);
end;

function TTasks.IndexOfTask (const Value: string): Integer;
var
    i: Integer;
begin
    i := 0;
    while (i < Count) and (UpperCase(TaskName[i]) <> UpperCase(Value)) do
        Inc (i);
    if (i < Count) then
        Result := i
    else
        Result := - 1;
end;

function TTasks.GetTaskExist (Value: string): Boolean;
begin
    Result := (IndexOfTask(Value) <> - 1);
end;

{ TDests }

function sDest (List: TStringList; Index1, Index2: Integer): Integer;
var
    s1, s2: string;
begin
    Result := 0;
    s1 := AnsiUpperCase ((List as TDests).Dest[Index1]);
    s2 := AnsiUpperCase ((List as TDests).Dest[Index2]);
    if s1 < s2 then
        Result := - 1
    else if s1 > s2 then
        Result := 1
    else if s1 = s2 then
        Result := 0;
end;

function sDestName (List: TStringList; Index1, Index2: Integer): Integer;
var
    s1, s2: string;
begin
    Result := 0;
    s1 := AnsiUpperCase ((List as TDests).DestName[Index1]);
    s2 := AnsiUpperCase ((List as TDests).DestName[Index2]);
    if s1 < s2 then
        Result := - 1
    else if s1 > s2 then
        Result := 1
    else if s1 = s2 then
        Result := 0;
end;

constructor TDests.Create;
begin
    inherited Create;
end;

destructor TDests.Destroy;
begin
    inherited Destroy;
end;

function TDests.GetDest (Index: Integer): string;
begin
    Result := Trim (Copy(Strings[index], 1, 12));
end;

function TDests.GetDestList: TStringList;
var
    i: Integer;
begin
    FList.Clear;
    for i := 0 to Count - 1 do
        FList.Add (Dest[i]);
    Result := FList;
end;

function TDests.GetDestName (Index: Integer): string;
begin
    Result := '';
    try
        Result := Trim (Copy(Strings[index], 14, 255));
    except
    end;
end;

procedure TDests.SortDest;
begin
    CustomSort (sDest);
end;

procedure TDests.SortDestName;
begin
    CustomSort (sDestName);
end;

function TDests.IndexOfDest (const Value: string): Integer;
var
    i: Integer;
begin
    i := 0;
    while (i < Count) and (UpperCase(Dest[i]) <> UpperCase(Value)) do
        Inc (i);
    if (i < Count) then
        Result := i
    else
        Result := - 1;
end;

function TDests.GetDestExist (Value: string): Boolean;
begin
    Result := (IndexOfDest(Value) <> - 1);
end;

{ TRegObls }

function sAbonent (List: TStringList; Index1, Index2: Integer): Integer;
var
    s1, s2: string;
begin
    Result := 0;
    s1 := AnsiUpperCase ((List as TRegObls).Abonent[Index1]);
    s2 := AnsiUpperCase ((List as TRegObls).Abonent[Index2]);
    if s1 < s2 then
        Result := - 1
    else if s1 > s2 then
        Result := 1
    else if s1 = s2 then
        Result := 0;
end;

function sAbonentName (List: TStringList; Index1, Index2: Integer): Integer;
var
    s1, s2: string;
begin
    Result := 0;
    s1 := AnsiUpperCase ((List as TRegObls).AbonentName[Index1]);
    s2 := AnsiUpperCase ((List as TRegObls).AbonentName[Index2]);
    if s1 < s2 then
        Result := - 1
    else if s1 > s2 then
        Result := 1
    else if s1 = s2 then
        Result := 0;
end;

constructor TRegObls.Create;
begin
    inherited Create;
end;

destructor TRegObls.Destroy;
begin
    inherited Destroy;
end;

procedure TRegObls.AddAbonent (Abonent, Kod1, Kod2, Kod3, Kod4, Kod5,
    AbonentName: string);
var
    s: string;
begin
    s := '';
    s := s + AddCharR (' ', Abonent, 8);
    s := s + ' ' + AddCharR (' ', Kod1, 2);
    s := s + ' ' + AddCharR (' ', Kod2, 2);
    s := s + ' ' + AddCharR (' ', Kod3, 3);
    s := s + ' ' + AddCharR (' ', Kod4, 6);
    s := s + ' ' + AddCharR (' ', Kod5, 1);
    s := s + ' ' + AddCharR (' ', AbonentName, 255);
    Add (s);
end;

function TRegObls.GetAbonent (Index: Integer): string;
begin
    Result := '';
    try
        Result := Trim (Copy(Strings[index], 1, 8));
    except
    end;
end;

function TRegObls.GetKod1 (Index: Integer): string;
begin
    Result := '';
    try
        Result := Trim (Copy(Strings[index], 10, 2));
    except
    end;
end;

function TRegObls.GetKod2 (Index: Integer): string;
begin
    Result := '';
    try
        Result := Trim (Copy(Strings[index], 13, 2));
    except
    end;
end;

function TRegObls.GetKod3 (Index: Integer): string;
begin
    Result := '';
    try
        Result := Trim (Copy(Strings[index], 16, 3));
    except
    end;
end;

function TRegObls.GetKod4 (Index: Integer): string;
begin
    Result := '';
    try
        Result := Trim (Copy(Strings[index], 20, 6));
    except
    end;
end;

function TRegObls.GetKod5 (Index: Integer): string;
begin
    Result := '';
    try
        Result := Trim (Copy(Strings[index], 27, 1));
    except
    end;
end;

function TRegObls.GetAbonentName (Index: Integer): string;
begin
    Result := '';
    try
        Result := Trim (Copy(Strings[index], 29, 255));
    except
    end;
end;

procedure TRegObls.SortAbonent;
begin
    CustomSort (sAbonent);
end;

procedure TRegObls.SortAbonentName;
begin
    CustomSort (sAbonentName);
end;

function TRegObls.GetRegionList: TStringList;
var
    i: Integer;
begin
    FList.Clear;
    for i := 0 to Count - 1 do
        FList.Add (AbonentName[i]);
    Result := FList;
end;

function TRegObls.GetAbonentList: TStringList;
var
    i: Integer;
begin
    FList.Clear;
    for i := 0 to Count - 1 do
        FList.Add (Abonent[i]);
    Result := FList;
end;

function TRegObls.IndexOfAbonent (const Value: string): Integer;
var
    i: Integer;
begin
    i := 0;
    while (i < Count) and (Abonent[i] <> Value) do
        Inc (i);
    if (i < Count) then
        Result := i
    else
        Result := - 1;
end;

function TRegObls.IndexOfAbonentName (const Value: string): Integer;
var
    i: Integer;
begin
    i := 0;
    while (i < Count) and (UpperCase(AbonentName[i]) <> UpperCase(Value)) do
        Inc (i);
    if (i < Count) then
        Result := i
    else
        Result := - 1;
end;

function TRegObls.GetRegOblExist (Value: string): Boolean;
begin
    Result := (IndexOfAbonent(Value) <> - 1);
end;

{ TTask }

constructor TTask.Create (AOwner: TComponent);
begin
    inherited Create (AOwner);
    ObjectType := otTask;
    Clear;
end;

destructor TTask.Destroy;
begin
    StrDispose (FTaskName);
    StrDispose (FTaskCaption);
    StrDispose (FTaskDest);
    StrDispose (FTaskFileType);
    StrDispose (FTaskDestPIA);
    StrDispose (FTaskOptions);
    StrDispose (FTaskFileNameLCK);
    StrDispose (FTaskCodeFile);
    StrDispose (FTaskPath);
    StrDispose (FTaskPathArc);
    StrDispose (FTaskPathSAED);
    StrDispose (FTaskFileNameFilter);
    inherited Destroy;
end;

procedure TTask.Clear;
begin
    TaskName := '';
    TaskCaption := '';
    TaskDest := '';
    TaskFileType := '';
    TaskDestPIA := '';
    TaskOptions := '';
    TaskFileNameLCK := '';
    TaskCodeFile := '';
    TaskPath := '';
    TaskPathArc := '';
    TaskPathSAED := '';
    TaskFileNameFilter := '';
    TaskWaitConfirmation := True;
    TaskCheckHeader := True;
end;

function TTask.GetTaskName: string;
begin
    Result := StrPas (FTaskName);
end;

procedure TTask.SetTaskName (const Value: string);
begin
    if FTaskName <> nil then
        StrDispose (FTaskName);
    FTaskName := StrAlloc (Length(Value) + 1);
    StrPCopy (FTaskName, Value);
end;

function TTask.GetTaskCaption: string;
begin
    Result := StrPas (FTaskCaption);
end;

procedure TTask.SetTaskCaption (const Value: string);
begin
    if FTaskCaption <> nil then
        StrDispose (FTaskCaption);
    FTaskCaption := StrAlloc (Length(Value) + 1);
    StrPCopy (FTaskCaption, Value);
end;

function TTask.GetTaskDest: string;
begin
    Result := StrPas (FTaskDest);
end;

procedure TTask.SetTaskDest (const Value: string);
begin
    if FTaskDest <> nil then
        StrDispose (FTaskDest);
    FTaskDest := StrAlloc (Length(Value) + 1);
    StrPCopy (FTaskDest, Value);
end;

function TTask.GetTaskFileType: string;
begin
    Result := StrPas (FTaskFileType);
end;

procedure TTask.SetTaskFileType (const Value: string);
begin
    if FTaskFileType <> nil then
        StrDispose (FTaskFileType);
    FTaskFileType := StrAlloc (Length(Value) + 1);
    StrPCopy (FTaskFileType, Value);
end;

function TTask.GetTaskDestPIA: string;
begin
    Result := StrPas (FTaskDestPIA);
end;

procedure TTask.SetTaskDestPIA (const Value: string);
begin
    if FTaskDestPIA <> nil then
        StrDispose (FTaskDestPIA);
    FTaskDestPIA := StrAlloc (Length(Value) + 1);
    StrPCopy (FTaskDestPIA, Value);
end;

function TTask.GetTaskOptions: string;
begin
    Result := StrPas (FTaskOptions);
end;

procedure TTask.SetTaskOptions (const Value: string);
begin
    if FTaskOptions <> nil then
        StrDispose (FTaskOptions);
    FTaskOptions := StrAlloc (Length(Value) + 1);
    StrPCopy (FTaskOptions, Value);
end;

function TTask.GetTaskFileNameLCK: string;
begin
    Result := StrPas (FTaskFileNameLCK);
end;

procedure TTask.SetTaskFileNameLCK (const Value: string);
begin
    if FTaskFileNameLCK <> nil then
        StrDispose (FTaskFileNameLCK);
    FTaskFileNameLCK := StrAlloc (Length(Value) + 1);
    StrPCopy (FTaskFileNameLCK, Value);
end;

function TTask.GetTaskCodeFile: string;
begin
    Result := StrPas (FTaskCodeFile);
end;

procedure TTask.SetTaskCodeFile (const Value: string);
begin
    if FTaskCodeFile <> nil then
        StrDispose (FTaskCodeFile);
    FTaskCodeFile := StrAlloc (Length(Value) + 1);
    StrPCopy (FTaskCodeFile, Value);
end;

function TTask.GetTaskPath: string;
begin
    Result := StrPas (FTaskPath);
end;

procedure TTask.SetTaskPath (const Value: string);
begin
    if FTaskPath <> nil then
        StrDispose (FTaskPath);
    FTaskPath := StrAlloc (Length(Value) + 1);
    StrPCopy (FTaskPath, Value);
end;

function TTask.GetTaskPathArc: string;
begin
    Result := StrPas (FTaskPathArc);
end;

procedure TTask.SetTaskPathArc (const Value: string);
begin
    if FTaskPathArc <> nil then
        StrDispose (FTaskPathArc);
    FTaskPathArc := StrAlloc (Length(Value) + 1);
    StrPCopy (FTaskPathArc, Value);
end;

function TTask.GetTaskPathSAED: string;
begin
    Result := StrPas (FTaskPathSAED);
end;

procedure TTask.SetTaskPathSAED (const Value: string);
begin
    if FTaskPathSAED <> nil then
        StrDispose (FTaskPathSAED);
    FTaskPathSAED := StrAlloc (Length(Value) + 1);
    StrPCopy (FTaskPathSAED, Value);
end;

function TTask.GetTaskFileNameFilter: string;
begin
    Result := StrPas (FTaskFileNameFilter);
end;

procedure TTask.SetTaskFileNameFilter (const Value: string);
begin
    if FTaskFileNameFilter <> nil then
        StrDispose (FTaskFileNameFilter);
    FTaskFileNameFilter := StrAlloc (Length(Value) + 1);
    StrPCopy (FTaskFileNameFilter, Value);
end;

procedure TTask.ScanFile (Sender: TScanDirFiles; AFileName: string;
    SR: TSearchRec);
begin
    if FileGetAttr (AFileName) and faReadOnly = 0 then
    begin
        Inc (FNotReadOnly);
    end;
end;

function TTask.GetCountFileNotReadOnly (ATaskName: string; ADate: TDateTime;
    APathStore: string; AAPPFiles: TScanDirFiles): Integer;
var
    LPathStore: string;
    LWild: string;

begin
    LWild := '*.*';
    AAPPFiles.OnFile := ScanFile;
    FNotReadOnly := 0;
    LPathStore := IncludeTrailingBackslash (GetDirNameYYMMDD(APathStore, ADate))
        + ATaskName;
    if ATaskName = 'MAILSPR' then
    begin
        AAPPFiles.Execute (IncludeTrailingBackslash(LPathStore) + LWild,
            sfDirectories);
    end else begin
        AAPPFiles.Execute (IncludeTrailingBackslash(LPathStore) + LWild,
            sfDirectory);
    end;
    AAPPFiles.OnFile := nil;
    Result := FNotReadOnly;
end;

end.
