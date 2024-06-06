(*
 =======================================================
 Copyright (c) 2023
 Author:
     Lisitsin Y.R.
 Project:
     LU_PAS
     Delphi VCL Extensions (LU)
 Module:
     LUObjectsMonth

 =======================================================
*)

unit LUObjectsMonth;

interface

uses
    {}
        Classes, SysUtils, Forms,
    {}
    RxCtrls,
    {}
    LUSupport, LUStrUtils, LUThreadProgress;

{ =========================================================================== }
const
    sMonthName: array [1 .. 12] of string = ('€нварь', 'февраль', 'март',
        'апрель', 'май', 'июнь', 'июль', 'август', 'сент€брь', 'окт€брь',
        'но€брь', 'декабрь');
    sMonthName0: array [0 .. 12] of string = ('ѕо всем', '€нварь', 'февраль',
        'март', 'апрель', 'май', 'июнь', 'июль', 'август', 'сент€брь',
        'окт€брь', 'но€брь', 'декабрь');

{ TMonth }

type
    TMonth = class(TObjects)
    private
        FMonth: Integer;
        function GetMonthName: string;

    public
        constructor Create (AOwner: TComponent); override;
        destructor Destroy; override;
        procedure Clear;
        { }
        property MonthName: string read GetMonthName;
        property Month: Integer read FMonth write FMonth;
    end;

implementation

{ TMonth }

constructor TMonth.Create (AOwner: TComponent);
begin
    inherited Create (AOwner);
    ObjectType := otMonth;
    Clear;
end;

destructor TMonth.Destroy;
begin
    inherited Destroy;
end;

procedure TMonth.Clear;
begin
    Month := 0;
end;

function TMonth.GetMonthName: string;
begin
    Result := sMonthName[FMonth];
end;

end.
