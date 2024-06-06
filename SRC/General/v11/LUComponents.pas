(*
 =======================================================
 Copyright (c) 2023
 Author:
     Lisitsin Y.R.
 Project:
     LU_PAS
     Delphi VCL Extensions (LU)
 Module:
     LUComponents

 =======================================================
*)

unit LUComponents;

interface

uses
    { }
    Classes, SysUtils, Vcl.ExtCtrls,
    RxCtrls,
    LUObjects;

{ TLUPanel }

type
    TLUPanel = class(TPanel)
    private
        FObjects: TObject;
        FRxProgress: TRxProgress;

    public
        constructor Create (AOwner: TComponent); override;
        destructor Destroy; override;
        property Objects: TObject read FObjects write FObjects;
        property RxProgress: TRxProgress read FRxProgress write FRxProgress;
    end;

implementation

{ TObjects }

constructor TLUPanel.Create (AOwner: TComponent);
begin
    inherited Create (AOwner);
    Objects := nil;
end;

destructor TLUPanel.Destroy;
begin
    inherited Destroy;
end;

end.
