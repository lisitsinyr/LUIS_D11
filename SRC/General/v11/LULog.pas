(*
 =======================================================
 Copyright (c) 2023
 Author:
     Lisitsin Y.R.
 Project:
     LU_PAS
     Delphi VCL Extensions (LU)
 Module:
     LULog

 =======================================================
*)

unit LULog;

interface

uses System.SysUtils, StrUtils, Windows, Classes, StdCtrls, Controls, FileCtrl,
    LUSupport;

type
    TTypeLogString = (tlsBegin, tlsEnd, tlsInfo, tlsError, tlsWarning,
        tlsProcess, tlsText);
    TTypeLogCODE = (tlcOEM, tlcANSI);

type
    TFileMemoLog = class(TComponent)
    private
        { Private declarations }
        FCountLogStrings: Integer;
        FFileName: PChar;
        FStandardOut: Boolean;
        FLogCODE: TTypeLogCODE;
        FLogEnabled: Boolean;
        FTruncateDays: Integer;
        FLogStringOEM: PChar;
        FLogStringAnsi: PChar;
        FMemoLog: TMemo;
        FLogStrings: TStringList;
        FLogSave: TStringList;
    protected
        { Protected declarations }
        procedure Execute (T: TTypeLogString);
        procedure SetLogString (T: TTypeLogString; TabCount: Integer;
            Value: string);
        procedure SetMemoLog (Value: TMemo);
        procedure TruncateMemo (ATS: TStrings);
        function LogTypeStr (T: TTypeLogString): string;
        function GetLogSave (Filename: string): TStringList;
        function GetLogSaveCurrent: TStringList;
        function GetFileName: string;
        procedure SetFileName (const Value: string);
    public
        constructor Create (AOwner: TComponent); override;
        destructor Destroy; override;
        procedure TruncateLog;
        procedure AddFile (const Filename: string; TabCount: Integer);
        property LogString[T: TTypeLogString; TabCount: Integer]: string
            write SetLogString;
        property LogSave[Filename: string]: TStringList read GetLogSave;
        property LogSaveCurrent: TStringList read GetLogSaveCurrent;
    published
        { Published declarations }
        property NumberOfLogStrings: Integer read FCountLogStrings
            write FCountLogStrings;
        property LogEnabled: Boolean read FLogEnabled write FLogEnabled;
        property Filename: string read GetFileName write SetFileName;
        property TruncateDays: Integer read FTruncateDays write FTruncateDays;
        property MemoLog: TMemo read FMemoLog write SetMemoLog;
        property StandardOut: Boolean read FStandardOut write FStandardOut;
        property LogCODE: TTypeLogCODE read FLogCODE write FLogCODE;
    end;

type
    TLogOutput = (loStandard, loTextFile);
    TLogOutputs = set of TLogOutput;

var
    APPLog: TFileMemoLog;

function GetLogFileName: string;
function GetLogFileNameSufix (const Sufix: string): string;

procedure Register;

implementation

uses LULogView, LUStrUtils;

const
    StlsInfo = 'I';
    StlsError = 'E';
    StlsWarning = 'W';
    StlsBegin = '>';
    StlsEnd = '<';
    StlsProcess = 'P';

function GetLogFileName: string;
begin
    Result := FormatDateTime ('yyyymmdd', Now) + '.log';
end;

function GetLogFileName_yyyymmddhhssms: string;
begin
    Result := FormatDateTime ('yyyymmdd', Now) + '.log';
end;

function GetLogFileNameSufix (const Sufix: string): string;
begin
    Result := FormatDateTime ('yyyymmdd', Now) + Sufix + '.log';
end;

function LogDateStr (TimeOnly: Boolean): string;
var
    LToday: TDateTime;
    hh, nn, ss, ms: word;
    s1: string;
begin
    LToday := Now;
    DecodeTime (LToday, hh, nn, ss, ms);
    s1 := AddChar ('0', IntToStr(ms), 3) + ' ';
    if TimeOnly then begin
        Result := FormatDateTime ('               hh:mm:ss '+s1, LToday);
    end else begin
        Result := FormatDateTime ('dd"/"mm"/"yyyy hh:mm:ss '+s1, LToday);
    end;
end;

constructor TFileMemoLog.Create (AOwner: TComponent);
begin
    inherited Create (AOwner);
    FMemoLog := nil;
    FCountLogStrings := 200;
    FStandardOut := False;
    FTruncateDays := 3;
    FLogEnabled := True;
    FLogCODE := tlcOEM;
    FLogStrings := TStringList.Create;
    FLogSave := TStringList.Create;
    FLogStringOEM := nil;
    FLogStringAnsi := nil;
    Filename := '';
end;

destructor TFileMemoLog.Destroy;
begin
    StrDispose (FLogStringOEM);
    StrDispose (FLogStringAnsi);
    StrDispose (FFileName);
    FLogStrings.Free;
    FLogSave.Free;
    inherited Destroy;
end;

function TFileMemoLog.GetFileName: string;
begin
    Result := StrPas (FFileName);
end;

procedure TFileMemoLog.SetFileName (const Value: string);
begin
    if FFileName <> nil then
        StrDispose (FFileName);
    FFileName := StrAlloc (Length(Value) + 1);
    StrPCopy (FFileName, Value);
    if (Filename <> '') and FileExists (Filename) then
    begin
        try
            FMemoLog.Lines.LoadFromFile (Filename);
        except
        end;
    end;
end;

function TFileMemoLog.LogTypeStr (T: TTypeLogString): string;
begin
    Result := ' ';
    case T of
        tlsInfo:
            Result := StlsInfo;
        tlsError:
            Result := StlsError;
        tlsWarning:
            Result := StlsWarning;
        tlsBegin:
            Result := StlsBegin;
        tlsEnd:
            Result := StlsEnd;
        tlsProcess:
            Result := StlsProcess;
    end;
    Result := Result + ' ';
end;

procedure TFileMemoLog.SetMemoLog (Value: TMemo);
begin
    FMemoLog := Value;
    if FMemoLog <> nil then
    begin
        with FMemoLog do
        begin
            Clear;
            Align := alClient;
            readonly := True;
            TabStop := False;
            WantReturns := False;
            WantTabs := False;
            WordWrap := False;
            ParentColor := True;
            ScrollBars := ssVertical;
            ScrollBars := ssBoth;
        end;
        if (Filename <> '') and FileExists (Filename) then
        begin
            try
                FMemoLog.Lines.LoadFromFile (Filename);
            except
            end;
        end;
    end;
end;

procedure TFileMemoLog.SetLogString (T: TTypeLogString; TabCount: Integer;
    Value: string);
var
    s: string;
begin
    if T <> tlsText then
        s := StringOfChar (' ', TabCount * 2) + Value
    else
        s := Value;

    if FLogStringOEM <> nil then
        StrDispose (FLogStringOEM);
    FLogStringOEM := StrAlloc (Length(s) + 1);
    StrPCopy (FLogStringOEM, s);

    if FLogStringAnsi <> nil then
        StrDispose (FLogStringAnsi);
    FLogStringAnsi := StrAlloc (Length(s) + 1);
    StrPCopy (FLogStringAnsi, s);

    case FLogCODE of
        tlcOEM:
            CharToOEM (PWideChar(FLogStringAnsi), PAnsiChar(FLogStringAnsi));
        tlcANSI:
            OEMtoChar (PAnsiChar(FLogStringOEM), PWideChar(FLogStringOEM));
    end;
    if LogEnabled then
        Execute (T);
end;

procedure TFileMemoLog.Execute (T: TTypeLogString);
var
    F: TextFile;
    i: Integer;
    s: string;
begin
    { StandardOut }
    if StandardOut and isConsole then
    begin
        FLogStrings.SetText (FLogStringAnsi);
        for i := 0 to FLogStrings.Count - 1 do
        begin
            if T <> tlsText then
                System.WriteLn (LogDateStr(False) + LogTypeStr(T) +
                    FLogStrings.Strings[i])
            else
                System.WriteLn (FLogStrings.Strings[i]);
        end;
    end;

    { Filename }
    if Filename <> '' then
    begin
        s := ExtractFileDir (ExpandFileName(Filename));
        if s <> '' then
            if not DirectoryExists (s) then
                ForceDirectories (s);
        FLogStrings.SetText (FLogStringOEM);
        if not FileExists (Filename) then
            FileClose (FileCreate(Filename));
        AssignFile (F, Filename);
        System.Append (F);
        for i := 0 to FLogStrings.Count - 1 do
        begin
            if T <> tlsText then
                System.WriteLn (F, LogDateStr(False) + LogTypeStr(T) +
                    FLogStrings.Strings[i])
            else
                System.WriteLn (F, FLogStrings.Strings[i]);
        end;
        Flush (F);
        CloseFile (F);
    end;

    { Memo }
    if FMemoLog <> nil then
    begin
        FLogStrings.SetText (FLogStringOEM);
        for i := 0 to FLogStrings.Count - 1 do
        begin
            if T <> tlsText then
                FMemoLog.Lines.Add (LogDateStr(False) + LogTypeStr(T) +
                    FLogStrings.Strings[i])
            else
                FMemoLog.Lines.Add (FLogStrings.Strings[i]);
        end;
    end;
end;

procedure TFileMemoLog.TruncateMemo (ATS: TStrings);
var
    Today, LogDay: TDateTime;
    { Delta: TDateTime; }
    s: string;
    Save: Char;
    i: Longint;
    x: Longint;
    Stop: Boolean;
    yy, mm, dd, hh, nn, ss, ms: word;
begin
    Save := FormatSettings.DateSeparator;
    FormatSettings.DateSeparator := '/';
    Today := Now;
    s := DateTimeToStr (Today);
    i := 0;
    Stop := False;
    while (i < ATS.Count) and (not Stop) do
    begin
        s := ExtractWordNew (1, ATS.Strings[i], [' ']) + ' ' +
            ExtractWordNew (2, ATS.Strings[i], [' ']);
        s := ReplaceStr (s, '.', FormatSettings.DateSeparator);
        try
            ms := StrToInt (ExtractWordNew(2, ATS.Strings[i], [' ']));
        except
            ms := 0;
        end;
        try
            LogDay := StrToDateTime (s) + EncodeTime (0, 0, 0, ms);
        except
            LogDay := 0;
        end;
        if LogDay <> 0 then
        begin
            DecodeDate (Today - TruncateDays, yy, mm, dd);
            DecodeTime (Today - TruncateDays, hh, nn, ss, ms);
            { Delta := EncodeDate(yy,mm,dd)+EncodeTime(hh,nn,ss,ms); }
            x := Trunc (Today) - Trunc (LogDay);
            if x > TruncateDays - 1 then
                { if LogDay < Delta then }
                ATS.Delete (i)
            else
            begin
                Stop := True;
                i := ATS.Count;
            end;
        end else begin
            ATS.Delete (i);
        end;
    end;
    FormatSettings.DateSeparator := Save;
end;

procedure TFileMemoLog.TruncateLog;
var
    ts: TStringList;
begin
    ts := TStringList.Create;
    ts.Sorted := False;
    ts.Duplicates := dupAccept;

    { Filename }
    if FileExists (Filename) then
    begin
        ts.Clear;
        try
            ts.LoadFromFile (Filename);
        except
        end;
        TruncateMemo (ts);
        try
            ts.SaveToFile (Filename);
        except
        end;
    end;

    { Memo }
    if FMemoLog <> nil then
    begin
        ts.Clear;
        ts.Assign (FMemoLog.Lines);
        TruncateMemo (ts);
        FMemoLog.Clear;
        FMemoLog.Lines.Assign (ts);
    end;
    ts.Free;
end;

procedure TFileMemoLog.AddFile (const Filename: string; TabCount: Integer);
var
    F: TextFile;
    s: string;
begin
    if FileExists (Filename) then
    begin
        AssignFile (F, Filename);
        System.Reset (F);
        while not EOF (F) do
        begin
            ReadLn (F, s);
            LogString[tlsInfo, TabCount] := s;
        end;
        CloseFile (F);
    end;
end;

function TFileMemoLog.GetLogSave (Filename: string): TStringList;
var
    TSIn: TStringList;
    ProcessEnd: Boolean;
    IB, IE, i, J, IP: Integer;
    Ch: string;

begin
    FLogSave.Clear;
    if FileExists (Filename) then
    begin
        TSIn := TStringList.Create;
        TSIn.LoadFromFile (Filename);
        if TSIn.Count > 0 then
        begin
            i := 0;
            IB := 0;
            IP := 0;
            Ch := ExtractWordNew (4, TSIn.Strings[i], [' ']);
            ProcessEnd := False;
            while not ProcessEnd do
            begin
                if Ch = StlsBegin then
                begin
                    if IB < i then
                    begin
                        { нет символа конца }
                        Ch := StlsEnd;
                        Dec (i);
                    end else begin
                        IB := i;
                        IP := 0;
                    end;
                end;
                if Ch = StlsEnd then
                begin
                    if (i < TSIn.Count) then
                        IE := i
                    else
                    begin
                        IE := i - 1;
                        ProcessEnd := True;
                    end;
                    { Copy strings }
                    if IP > 0 then
                        for J := IB to IE do
                            FLogSave.Add (TSIn.Strings[J]);
                    IB := IE + 1;
                end;
                if Ch = StlsError then
                    Inc (IP);
                if Ch = StlsWarning then
                    Inc (IP);
                if Ch = StlsProcess then
                    Inc (IP);
                { Next string }
                Inc (i);
                if (i < TSIn.Count) then
                    Ch := ExtractWordNew (4, TSIn.Strings[i], [' '])
                else
                    Ch := StlsEnd;
            end;
        end;
        TSIn.Free;
    end;
    Result := FLogSave;
end;

function TFileMemoLog.GetLogSaveCurrent: TStringList;
begin
    Result := LogSave[Filename];
end;

{ This procedure is used to register this component on the component palette }

procedure Register;
begin
    RegisterComponents ('Luis', [TFileMemoLog]);
end;

end.
