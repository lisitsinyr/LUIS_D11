(*
 =======================================================
 Copyright (c) 2023
 Author:
     Lisitsin Y.R.
 Project:
     LU_PAS
     Delphi VCL Extensions (LU)
 Module:
     LUScanDir
     Сканирование директорий
 =======================================================
*)

{$WARN SYMBOL_PLATFORM OFF}

unit LUScanDir;

interface

uses Windows, Sysutils, Classes,
    LUSupport;

type
    TScanDirFiles = class;
   {
   sfAll              - All Drivers
   sfDisk             - Drive
   sfDirectories      - from CurrentDir
   sfDirectory        - only Current
   sfDirecoriesSelect - Select Directory
 }
    TScanFileFind = (sfAll, sfDisk, sfDirectories, sfDirectory,
        sfDirecoriesSelect);

    TNotifyFileEvent = procedure(Sender: TScanDirFiles; FileName: string;
        SR: TSearchRec) of object;
    TNotifyFileDirectoryEvent = procedure(Sender: TScanDirFiles;
        FileName: string; SR: TSearchRec) of object;

    TScanDirFiles = class
    private
        FFileName: PChar;
        FPathName: PChar;
        FCopyFileDir: PChar;
        FDelDir: Boolean;
        FDelFile: Boolean;
        FCopyFile: Boolean;
        FFileList: TStringList;
        FFileNameList: TStringList;
        FDirectoryList: TStringList;
        FStatus: Integer;
        FFileCountDir: Integer;
        FLevel: Integer;
        FOnFile: TNotifyFileEvent;
        FOnFileDirectory: TNotifyFileDirectoryEvent;
        function GetCopyFileDir: string;
        procedure SetCopyFileDir (const Value: string);
        function GetFileName: string;
        procedure SetFileName (const Value: string);
        function GetPathName: string;
        procedure SetPathName (const Value: string);
        procedure ScanDirFile (Path, Mask: string);
        procedure ScanDir (Path, Mask: string);

    public
        constructor Create;
        destructor Destroy; override;
        procedure Execute (const ScanPathName: string;
            ScanFileFind: TScanFileFind);
        procedure ClearList;
        { }
        property FileList: TStringList read FFileList;
        property FileNameList: TStringList read FFileNameList;
        property DirectoryList: TStringList read FDirectoryList;
        property FileName: string read GetFileName write SetFileName;
        property PathName: string read GetPathName write SetPathName;
        property FileCountDir: Integer read FFileCountDir;
        property Level: Integer read FLevel;
        property Status: Integer read FStatus;
        property CopyFile: Boolean read FCopyFile write FCopyFile;
        property CopyFileDir: string read GetCopyFileDir write SetCopyFileDir;
        property DelFile: Boolean read FDelFile write FDelFile;
        property DelDir: Boolean read FDelDir write FDelDir;
        { }
        property OnFile: TNotifyFileEvent read FOnFile write FOnFile;
        property OnFileDirectory: TNotifyFileDirectoryEvent
            read FOnFileDirectory write FOnFileDirectory;
    end;

procedure DeleteFiles (const FileName: string; ScanFileFind: TScanFileFind);
procedure DeleteDir (const DirectoryName: string);
function GetCountFile (const DirectoryName: string): Integer;
function GetCountFileMask (const DirectoryName, Mask: string): Integer;

implementation

procedure DeleteFiles (const FileName: string; ScanFileFind: TScanFileFind);
var
    ScanDirFiles: TScanDirFiles;
begin
    ScanDirFiles := TScanDirFiles.Create;
    ScanDirFiles.DelFile := True;
    ScanDirFiles.DelDir := False;
    ScanDirFiles.Execute (FileName, ScanFileFind);
    ScanDirFiles.Free;
end;

procedure DeleteDir (const DirectoryName: string);
var
    ScanDirFiles: TScanDirFiles;
begin
    ScanDirFiles := TScanDirFiles.Create;
    ScanDirFiles.DelFile := True;
    ScanDirFiles.DelDir := True;
    ScanDirFiles.Execute (IncludeTrailingBackslash(DirectoryName) + '*.*',
        sfDirectories);
    ScanDirFiles.Free;
end;

function GetCountFile (const DirectoryName: string): Integer;
var
    ScanDirFiles: TScanDirFiles;
begin
    ScanDirFiles := TScanDirFiles.Create;
    ScanDirFiles.DelFile := False;
    ScanDirFiles.DelDir := False;
    ScanDirFiles.Execute (IncludeTrailingBackslash(DirectoryName) + '*.*',
        sfDirectory);
    Result := ScanDirFiles.FFileList.Count;
    ScanDirFiles.Free;
end;

function GetCountFileMask (const DirectoryName, Mask: string): Integer;
var
    ScanDirFiles: TScanDirFiles;
begin
    ScanDirFiles := TScanDirFiles.Create;
    ScanDirFiles.DelFile := False;
    ScanDirFiles.DelDir := False;
    ScanDirFiles.Execute (IncludeTrailingBackslash(DirectoryName) + Mask,
        sfDirectory);
    Result := ScanDirFiles.FFileList.Count;
    ScanDirFiles.Free;
end;

{ TScanDirFiles }

constructor TScanDirFiles.Create;
begin
    inherited Create;
    FStatus := 0;
    FLevel := 0;
    FFileCountDir := 0;
    FFileList := TStringList.Create;
    FFileNameList := TStringList.Create;
    FDirectoryList := TStringList.Create;
    FileName := '';
    PathName := '';
    FDelFile := False;
    FDelDir := False;
    FCopyFile := False;
    CopyFileDir := '';
    FOnFile := nil;
    FOnFileDirectory := nil;
end;

destructor TScanDirFiles.Destroy;
begin
    StrDispose (FFileName);
    StrDispose (FPathName);
    StrDispose (FCopyFileDir);
    FFileList.Free;
    FFileNameList.Free;
    FDirectoryList.Free;
    inherited Destroy;
end;

function TScanDirFiles.GetFileName: string;
begin
    Result := StrPas (FFileName);
end;

procedure TScanDirFiles.SetFileName (const Value: string);
begin
    if FFileName <> nil then
        StrDispose (FFileName);
    FFileName := StrAlloc (Length(Value) + 1);
    StrPCopy (FFileName, Value);
end;

function TScanDirFiles.GetPathName: string;
begin
    Result := StrPas (FPathName);
end;

procedure TScanDirFiles.SetPathName (const Value: string);
begin
    if FPathName <> nil then
        StrDispose (FPathName);
    FPathName := StrAlloc (Length(Value) + 1);
    StrPCopy (FPathName, Value);
end;

function TScanDirFiles.GetCopyFileDir: string;
begin
    Result := StrPas (FCopyFileDir);
end;

procedure TScanDirFiles.SetCopyFileDir (const Value: string);
begin
    if FCopyFileDir <> nil then
        StrDispose (FCopyFileDir);
    FCopyFileDir := StrAlloc (Length(Value) + 1);
    StrPCopy (FCopyFileDir, Value);
end;

procedure TScanDirFiles.ScanDirFile (Path, Mask: string);
var
    SR: TSearchRec;
    Found: Integer;
    Attr: Integer;
    s: string;
begin
    Attr := faAnyFile;
    s := IncludeTrailingBackslash (Path) + Mask;
    Found := FindFirst (s, Attr, SR);
    Inc (FLevel);
    while (Found = 0) do
    begin
        if (SR.Name <> '.') and (SR.Name <> '..') then
        begin
            PathName := Path;
            FileName := SR.Name;
            s := IncludeTrailingBackslash (Path) + SR.Name;
            if (SR.Attr and faDirectory) = 0 then
            begin
            { It is File }
                FFileList.Add (s);
                FFileNameList.Add (SR.Name);
                Inc (FFileCountDir);
                if Assigned (FOnFile) and (FStatus = 0) then
                    FOnFile (Self, s, SR);
                if DelFile then
                    FileDelete (s);
                if CopyFile then
                    FileCopy (s, CopyFileDir, True);
            end else begin
                FDirectoryList.Add (s);
                if Assigned (FOnFileDirectory) and (FStatus = 0) then
                    FOnFileDirectory (Self, s, SR);
            end;
        end;
        Found := FindNext (SR);
    end;
    Dec (FLevel);
    Sysutils.FindClose (SR);
end;

procedure TScanDirFiles.ScanDir (Path, Mask: string);
var
    SR: TSearchRec;
    Found: Integer;
    Attr: Integer;
    s: string;
begin
    Attr := faAnyFile;
    s := IncludeTrailingBackslash (Path) + '*.*';
    Found := FindFirst (s, Attr, SR);
    while (Found = 0) do
    begin
        if (SR.Name <> '.') and (SR.Name <> '..') then
        begin
            PathName := Path;
            FileName := SR.Name;
            s := IncludeTrailingBackslash (Path) + SR.Name;
            if (SR.Attr and faDirectory) <> 0 then
            begin
            { It is Directory }
                Inc (FLevel);
                FFileCountDir := 0;
                if Mask <> '' then
                    ScanDirFile (s, Mask);
                ScanDir (s, Mask);
                if DelDir then
                    DirectoryDelete (s);
                Dec (FLevel);
            end;
        end;
        Found := FindNext (SR);
    end;
    Sysutils.FindClose (SR);
end;

procedure TScanDirFiles.ClearList;
begin
    FFileList.Clear;
    FFileNameList.Clear;
    FDirectoryList.Clear;
end;

procedure TScanDirFiles.Execute (const ScanPathName: string;
    ScanFileFind: TScanFileFind);
var
    Path, Mask: string;
begin
    FStatus := 0;
    FFileCountDir := 0;
    FileName := '';
    ClearList;
    PathName := ExtractFileDir (ScanPathName);
   { }
    Path := ExtractFileDir (ScanPathName);
    Mask := ExtractFileName (ScanPathName);
   {
   sfAll              - All Drivers
   sfDisk             - Drive
   sfDirectories      - from CurrentDir
   sfDirectory        - only Current
   sfDirecoriesSelect - Select Directory
 }
    case ScanFileFind of
        sfDirectory:
            begin
                if DirectoryExists (PathName) then
                begin
                    FLevel := 0;
                    ScanDirFile (Path, Mask);
                    if DelDir then
                        DirectoryDelete (Path);
                end;
            end;
        sfDirectories:
            begin
                if DirectoryExists (PathName) then
                begin
                    FLevel := 0;
                    ScanDir (Path, Mask);
                    FLevel := 0;
                    ScanDirFile (Path, Mask);
                    if DelDir then
                        DirectoryDelete (Path);
                end;
            end;
        sfAll:
            begin
            end;
        sfDisk:
            begin
            end;
        sfDirecoriesSelect:
            begin
            end;
    end;
end;

(*
{ This procedure is used to register this component on the component palette }

procedure Register;
begin
   RegisterComponents('Luis', [TScanDirFiles]);
end;
*)

end.
