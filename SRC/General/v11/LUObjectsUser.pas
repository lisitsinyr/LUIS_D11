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

{ TUser }

type
    TUser = class(TObjects)
    private
        FTaskNames: TStringList;
        FUserName: PChar;
        function GetUserName: string;
        procedure SetUserName (const Value: string);

    public
        constructor Create (AOwner: TComponent); override;
        destructor Destroy; override;
        procedure Clear;
        { }
        property UserName: string read GetUserName write SetUserName;
        property TaskNames: TStringList read FTaskNames;
    end;

implementation

{ TUser }

constructor TUser.Create (AOwner: TComponent);
begin
    inherited Create (AOwner);
    FTaskNames := TStringList.Create;
    ObjectType := otUser;
    Clear;
end;

destructor TUser.Destroy;
begin
    StrDispose (FUserName);
    FTaskNames.Free;
    inherited Destroy;
end;

procedure TUser.Clear;
begin
    FTaskNames.Clear;
    UserName := '';
end;

function TUser.GetUserName: string;
begin
    Result := StrPas (FUserName);
end;

procedure TUser.SetUserName (const Value: string);
begin
    if FUserName <> nil then
        StrDispose (FUserName);
    FUserName := StrAlloc (Length(Value) + 1);
    StrPCopy (FUserName, Value);
end;

end;
