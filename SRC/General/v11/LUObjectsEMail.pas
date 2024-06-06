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
{ TEMail }

type
    TEMail = class(TObjects)
    private
        FEMail: PChar;
        FList: TStringList;
        function GetEMail (const AddressType: string): string;
        procedure SetEMail (const AddressType, Value: string);
        procedure WorkEMail (AddressType: string);
        function GetDomain (ADimention: Integer): string;
        function GetUser: string;
        function GetDomainCount: Integer;
        { }
        property List: TStringList read FList;

    public
        constructor Create (AOwner: TComponent); override;
        destructor Destroy; override;
        procedure Clear;
        { }
        property EMail[const AddressType: string]: string read GetEMail
            write SetEMail;
        property Domain[ADimention: Integer]: string read GetDomain;
        property DomainCount: Integer read GetDomainCount;
        property User: string read GetUser;
    end;

implementation

{ ------ }
{ TEMail }
{ ------ }

constructor TEMail.Create (AOwner: TComponent);
begin
    inherited Create (AOwner);
    ObjectType := otEMail;
    FList := TStringList.Create;
    Clear;
end;

destructor TEMail.Destroy;
begin
    StrDispose (FEMail);
    FList.Free;
    inherited Destroy;
end;

procedure TEMail.Clear;
begin
    EMail[''] := '';
    FList.Clear;
end;

procedure TEMail.WorkEMail (AddressType: string);
var
    DomenEMail: string;
    i, j: Integer;
    s, s1: string;
    ts: TStringList;
begin
    FList.Clear;
    s1 := EMail[''];
    if s1 <> '' then
    begin
        if UpperCase (AddressType) = 'SMTP' then
        begin
            FList.Add (ExtractWordNew(1, s1, ['@']));
            DomenEMail := ExtractWordNew (2, s1, ['@']);
            j := WordCountNew (DomenEMail, ['.']);
            for i := 1 to j do
                FList.Add (ExtractWordNew(i, DomenEMail, ['.']));
        end else if UpperCase (AddressType) = 'EX' then
        begin
            ts := TStringList.Create;
            j := WordCountNew (s1, ['/', '=']);
            i := 1;
            ts.Add ('RU');
            while i <= j do
            begin
                s := UpperCase (ExtractWordNew(i, s1, ['/', '=']));
                if s = 'O' then
                begin
                    s := ExtractWordNew (i + 1, s1, ['/', '=']);
                    ts.Add (s);
                end else if s = 'OU' then
                begin
                    s := ExtractWordNew (i + 1, s1, ['/', '=']);
                    ts.Add (s);
                end else if s = 'CN' then
                begin
                    s := UpperCase (ExtractWordNew(i + 1, s1, ['/', '=']));
                    if (s <> 'RECIPIENTS') then
                        ts.Add (s);
                end;
                Inc (i);
            end;

            for i := ts.Count - 1 downto 0 do
                FList.Add (ts.Strings[i]);
            ts.Free;

        end else begin
            FList.Add (s1 + '(' + AddressType + ')');
        end;
    end;
end;

function TEMail.GetEMail (const AddressType: string): string;
begin
    Result := StrPas (FEMail);
end;

procedure TEMail.SetEMail (const AddressType, Value: string);
begin
    if FEMail <> nil then
        StrDispose (FEMail);
    FEMail := StrAlloc (Length(Value) + 1);
    StrPCopy (FEMail, Value);
    WorkEMail (AddressType);
end;

function TEMail.GetDomain (ADimention: Integer): string;
var
    i: Integer;
begin
    Result := '';
    if List.Count > 0 then
    begin
        for i := List.Count - ADimention to List.Count - 1 do
        begin
            if i > 1 then
                Result := Result + '.' + List.Strings[i]
            else
                Result := Result + List.Strings[i];
        end;
    end;
end;

function TEMail.GetDomainCount: Integer;
begin
    Result := List.Count - 1;
end;

function TEMail.GetUser: string;
begin
    Result := '';
    if List.Count > 0 then
    begin
        Result := List.Strings[0];
    end;
end;

end.