(*
 =======================================================
 Copyright (c) 2023
 Author:
     Lisitsin Y.R.
 Project:
     LU_PAS
     Delphi VCL Extensions (LU)
 Module:
     LUObjectsFTPServer

 =======================================================
*)

unit LUObjectsFTPServer;

interface

uses
    {}
        Classes, SysUtils, Forms,
    {}
    RxCtrls,
    {}
    LUSupport, LUStrUtils, LUThreadProgress;

{ =========================================================================== }
{ TFTPServer }

type
    TFTPServer = class(TObjects)
    private
        FFTPServerName: PChar;
        function GetFTPServerName: string;
        procedure SetFTPServerName (const Value: string);

    public
        constructor Create (AOwner: TComponent); override;
        destructor Destroy; override;
        procedure Clear;
        { }
        property FTPServerName: string read GetFTPServerName
            write SetFTPServerName;
    end;

implementation

{ TFTPServer }

constructor TFTPServer.Create (AOwner: TComponent);
begin
    inherited Create (AOwner);
    ObjectType := otFTPServer;
    Clear;
end;

destructor TFTPServer.Destroy;
begin
    StrDispose (FFTPServerName);
    inherited Destroy;
end;

procedure TFTPServer.Clear;
begin
    FTPServerName := '';
end;

function TFTPServer.GetFTPServerName: string;
begin
    Result := StrPas (FFTPServerName);
end;

procedure TFTPServer.SetFTPServerName (const Value: string);
begin
    if FFTPServerName <> nil then
        StrDispose (FFTPServerName);
    FFTPServerName := StrAlloc (Length(Value) + 1);
    StrPCopy (FFTPServerName, Value);
end;

end;