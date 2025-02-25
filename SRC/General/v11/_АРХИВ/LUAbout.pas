{=======================================================}
{ Project:                                              }
{         Delphi VCL Extensions (LU)                    }
{         Copyright (c) 2000 Central Bank Of Russia     }
{ Subject:                                              }
{         О программе                                   }
{ Author:                                               }
{         Lisitsin Y.R.                                 }
{=======================================================}

unit LUAbout;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  ExtCtrls, StdCtrls, Buttons,
  LUVersion;

type
  TFormAbout = class(TForm)
    LabelName: TLabel;
    LabelVer: TLabel;
    LabelAlias: TLabel;
    Label1: TLabel;
    Image1: TImage;
    Label3: TLabel;
    BitBtn1: TBitBtn;
    Label4: TLabel;
    LVersion: TLabel;
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
  private
    { Private declarations }
    Ver: TVersionInfo;
  public
    { Public declarations }
  end;

var
  FormAbout: TFormAbout;

function ExecAbout : Integer;

implementation

{$R *.DFM}

function ExecAbout : Integer;
begin
//   Application.CreateForm(TFormAbout, FormAbout);
   Result := FormAbout.ShowModal;
//   FormAbout.Free;
end;

procedure TFormAbout.FormCreate(Sender: TObject);
begin
   Ver := TVersionInfo.Create(Self);
   Ver.FileName := ParamStr(0);
   LVersion.Caption := Ver.FileVersion;
   LabelAlias.Caption := Ver.CompanyName;
end;

procedure TFormAbout.FormDestroy(Sender: TObject);
begin
   Ver.Free;
end;

end.
