(*
 =======================================================
 Copyright (c) 2023
 Author:
     Lisitsin Y.R.
 Project:
     LU_PAS
     Delphi VCL Extensions (LU)
 Module:
     LUObjectsMailbox

 =======================================================
*)

unit LUObjectsMailbox;

interface

uses
    {}
        Classes, SysUtils, Forms,
    {}
    RxCtrls,
    {}
    LUSupport, LUStrUtils, LUThreadProgress;

{ TMailbox }

type
    TMailbox = class(TObjects)
    private
        FMailboxName: PChar;
        function GetMailboxName: string;
        procedure SetMailboxName (const Value: string);

    public
        constructor Create (AOwner: TComponent); override;
        destructor Destroy; override;
        procedure Clear;
        { }
        property MailboxName: string read GetMailboxName write SetMailboxName;
    end;

implementation

{ TMailbox }

constructor TMailbox.Create (AOwner: TComponent);
begin
    inherited Create (AOwner);
    ObjectType := otMailBox;
    Clear;
end;

destructor TMailbox.Destroy;
begin
    StrDispose (FMailboxName);
    inherited Destroy;
end;

procedure TMailbox.Clear;
begin
    MailboxName := '';
end;

function TMailbox.GetMailboxName: string;
begin
    Result := StrPas (FMailboxName);
end;

procedure TMailbox.SetMailboxName (const Value: string);
begin
    if FMailboxName <> nil then
        StrDispose (FMailboxName);
    FMailboxName := StrAlloc (Length(Value) + 1);
    StrPCopy (FMailboxName, Value);
end;

end.