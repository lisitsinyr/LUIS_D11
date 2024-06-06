(*
 =======================================================
 Copyright (c) 2023
 Author:
     Lisitsin Y.R.
 Project:
     LU_PAS
     Delphi VCL Extensions (LU)
 Module:
     LUSplash
     Splash
 =======================================================
*)

unit LUSplash;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  ExtCtrls, ComCtrls, StdCtrls, Buttons;

type
  TFormSplash = class(TForm)
    PanelText: TPanel;
    ProgressBar: TProgressBar;
    PanelCaption: TPanel;
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure FormKeyDown(Sender: TObject; var Key: Word;
      Shift: TShiftState);
  private
    { Private declarations }
    procedure SetSplashText(Value: string);
    procedure SetSplashCaption(Value: string);
    procedure SetSplashProgressBarStep(AMin,AMax,Value: Longint);
  public
    { Public declarations }
    ProcessBreak: Boolean;
    procedure StepIt;
    property SplashText: string write SetSplashText;
    property SplashCaption: string write SetSplashCaption;
    property SplashProgressBarStep[AMin,AMax: Longint]: Longint write SetSplashProgressBarStep;
  end;

  TSplash = class(TProgressBar)
  private
    { Private declarations }
    procedure SetSplashProgressBarStep(AMin,AMax,Value: Longint);
  public
    { Public declarations }
    ProcessBreak: Boolean;
    constructor Create(AOwner: TComponent);  override;
    procedure HideSplash;
    property SplashProgressBarStep[AMin,AMax: Longint]: Longint write SetSplashProgressBarStep;
  end;

var
  FormSplash: TFormSplash;
  Splash: TSplash;

implementation

{$R *.DFM}

procedure TFormSplash.FormCreate(Sender: TObject);
begin
   PanelCaption.Visible := False;
   ProgressBar.Visible := False;
   ProcessBreak := False;
end;

procedure TFormSplash.FormDestroy(Sender: TObject);
begin
    ;
end;

procedure TFormSplash.SetSplashText (Value: string);
begin
   ProcessBreak := False;
   if Trim(Value) <> '' then begin
      PanelText.Caption := Value;
      PanelText.Visible := True;
      Show;
      end
   else begin
      PanelText.Visible := False;
      Hide;
   end;
   Update;
end;

procedure TFormSplash.SetSplashCaption (Value: string);
begin
   if Trim(Value) <> '' then begin
      PanelCaption.Caption := Value;
      PanelCaption.Visible := True;
      end
   else begin
      PanelCaption.Visible := False;
   end;
   Update;
end;

procedure TFormSplash.SetSplashProgressBarStep(AMin,AMax,Value: Longint);
begin
   if Value <> 0 then begin
      ProgressBar.Min := AMin;
      ProgressBar.Max := AMax;
      ProgressBar.Step := Value;
      ProgressBar.Visible := True;
      end
   else begin
      ProgressBar.Position := 0;
      ProgressBar.Visible := False;
   end;
   Update;
end;

procedure TFormSplash.StepIt;
begin
   ProgressBar.StepIt;
   Update;
end;

procedure TFormSplash.FormKeyDown(Sender: TObject; var Key: Word;
  Shift: TShiftState);
begin
   if Key = VK_ESCAPE then ProcessBreak := True;
end;

{ TSplash }

constructor TSplash.Create(AOwner: TComponent);
begin
   inherited Create(AOwner);
   Visible := False;
end;

procedure TSplash.SetSplashProgressBarStep(AMin,AMax,Value: Longint);
begin
   if Value <> 0 then begin
      Min := AMin;
      Max := AMax;
      Step := Value;
      Visible := True;
      end
   else begin
      Position := 0;
      Visible := False;
   end;
end;

procedure TSplash.HideSplash;
begin
   Position := 0;
   Visible := False;
end;

(*
procedure TSplash.StepIt;
begin
   StepIt;
   Update;
end;
*)

end.
