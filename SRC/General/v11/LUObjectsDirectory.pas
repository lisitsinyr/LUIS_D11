(*
 =======================================================
 Copyright (c) 2023
 Author:
     Lisitsin Y.R.
 Project:
     LU_PAS
     Delphi VCL Extensions (LU)
 Module:
     LUObjects

 =======================================================
*)

unit LUObjects;

interface

uses
    {}
        Classes, SysUtils, Forms,
    {}
    RxCtrls,
    {}
    LUSupport, LUStrUtils, LUThreadProgress;

{ =========================================================================== }

{ TDirectory }

type
    TDirectory = class(TObjects)
    private
        FDirectoryName: PChar;
        FDirectoryDate: TDateTime;
        function GetDirectoryName: string;
        procedure SetDirectoryName (const Value: string);

    public
        constructor Create (AOwner: TComponent); override;
        destructor Destroy; override;
        procedure Clear;
        { }
        property DirectoryName: string read GetDirectoryName
            write SetDirectoryName;
        property DirectoryDate: TDateTime read FDirectoryDate
            write FDirectoryDate;
    end;

implementation

{ TDirectory }

constructor TDirectory.Create (AOwner: TComponent);
begin
    inherited Create (AOwner);
    ObjectType := otDirectory;
    Clear;
end;

destructor TDirectory.Destroy;
begin
    StrDispose (FDirectoryName);
    inherited Destroy;
end;

procedure TDirectory.Clear;
begin
    DirectoryName := '';
    DirectoryDate := 0;
end;

function TDirectory.GetDirectoryName: string;
begin
    Result := StrPas (FDirectoryName);
end;

procedure TDirectory.SetDirectoryName (const Value: string);
begin
    if FDirectoryName <> nil then
        StrDispose (FDirectoryName);
    FDirectoryName := StrAlloc (Length(Value) + 1);
    StrPCopy (FDirectoryName, Value);
end;

end.