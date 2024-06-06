(*
 =======================================================
 Copyright (c) 2023
 Author:
     Lisitsin Y.R.
 Project:
     LU_PAS
     Delphi VCL Extensions (LU)
 Module:
     LUObjectsFile

 =======================================================
*)

unit LUObjectsFile;

interface

uses
    {}
        Classes, SysUtils, Forms,
    {}
    RxCtrls,
    {}
    LUSupport, LUStrUtils, LUThreadProgress;

{ TFile }

type
    TFile = class(TObjects)
    private
        FTaskName: PChar;
        FFileName: PChar;
        FFileDate: TDateTime;
        FFileSize: Longint;
        function GetFileName: string;
        procedure SetFileName (const Value: string);
        function GetTaskName: string;
        procedure SetTaskName (const Value: string);

    public
        constructor Create (AOwner: TComponent); override;
        destructor Destroy; override;
        procedure Clear;
        { }
        property FileName: string read GetFileName write SetFileName;
        property FileDate: TDateTime read FFileDate write FFileDate;
        property FileSize: Longint read FFileSize write FFileSize;
        property TaskName: string read GetTaskName write SetTaskName;
    end;

implementation

{ TFile }

constructor TFile.Create (AOwner: TComponent);
begin
    inherited Create (AOwner);
    ObjectType := otFile;
    Clear;
end;

destructor TFile.Destroy;
begin
    StrDispose (FTaskName);
    StrDispose (FFileName);
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
    Result := StrPas (FFileName);
end;

procedure TFile.SetFileName (const Value: string);
begin
    if FFileName <> nil then
        StrDispose (FFileName);
    FFileName := StrAlloc (Length(Value) + 1);
    StrPCopy (FFileName, Value);
end;

function TFile.GetTaskName: string;
begin
    Result := StrPas (FTaskName);
end;

procedure TFile.SetTaskName (const Value: string);
begin
    if FTaskName <> nil then
        StrDispose (FTaskName);
    FTaskName := StrAlloc (Length(Value) + 1);
    StrPCopy (FTaskName, Value);
end;

end.