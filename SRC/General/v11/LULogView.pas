(*
 =======================================================
 Copyright (c) 2023
 Author:
     Lisitsin Y.R.
 Project:
     LU
     Delphi VCL Extensions (LU)
 Module:
     LULogView
     Просмотр журнала
 =======================================================
*)

{$WARN SYMBOL_PLATFORM OFF}

unit LULogView;

interface

uses Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
    StdCtrls, Buttons, ExtCtrls,
    LULog;

type
    TFormLog = class(TForm)
        MemoLog: TMemo;
        procedure FormKeyDown (Sender: TObject; var Key: Word;
          Shift: TShiftState);
    private
        { Private declarations }
    public
        { Public declarations }
        function Execute (const Filename: string; APPLog: TFileMemoLog)
          : Integer;
    end;

var
    FormLog: TFormLog;

procedure ViewLogFile (APPLog: TFileMemoLog; const InitDir: string;
  Filter: string);
procedure ViewFile (APPLog: TFileMemoLog; const Path: string);
function ExecViewLog (const Filename: string; APPLog: TFileMemoLog): Integer;

implementation

{$R *.DFM}
{ ExecViewLog }

function ExecViewLog (const Filename: string; APPLog: TFileMemoLog): Integer;
begin
    Application.CreateForm (TFormLog, FormLog);
    Result := FormLog.Execute (Filename, APPLog);
    FormLog.Free;
end;

{ ViewLogFile }

procedure ViewLogFile (APPLog: TFileMemoLog; const InitDir: string;
  Filter: string);
begin
    ViewFile (APPLog, IncludeTrailingBackslash(InitDir) + Filter{ '*.log' });
end;

{ ViewFile }

procedure ViewFile (APPLog: TFileMemoLog; const Path: string);
var
    LOpenLogFile: TOpenDialog;
begin
    LOpenLogFile := TOpenDialog.Create (nil);
    LOpenLogFile.Filter := 'File(' + ExtractFileName (Path) + ')|' +
      ExtractFileName (Path) + '|';
    LOpenLogFile.FilterIndex := 1;
    LOpenLogFile.DefaultExt := ExtractFileExt (Path);
    LOpenLogFile.InitialDir := ExtractFileDir (Path);
    if LOpenLogFile.Execute then
    begin
        ExecViewLog (LOpenLogFile.Filename, APPLog);
    end;
    LOpenLogFile.Free;
end;

{ TFormLog.Execute }

function TFormLog.Execute (const Filename: string;
  APPLog: TFileMemoLog): Integer;
begin
    with MemoLog do
    begin
        readonly := True;
        TabStop := False;
        WantReturns := False;
        WantTabs := False;
        WordWrap := False;
        ParentColor := True;
        ScrollBars := ssVertical;
        ScrollBars := ssBoth;
        Lines.Clear;
    end;
    Caption := 'Журнал ' + ExtractFileName (Filename);
    if Assigned (APPLog) then
    begin
        { строки только сеансов }
        MemoLog.Lines.Assign (APPLog.LogSave[Filename])
    end else begin
        try
            MemoLog.Lines.LoadFromFile (Filename);
        except
        end;
    end;
    Result := ShowModal;
end;

{ TFormLog.FormKeyDown }

procedure TFormLog.FormKeyDown (Sender: TObject; var Key: Word;
  Shift: TShiftState);
begin
    if Key = Vk_Escape then
        Self.close;
end;

end.
