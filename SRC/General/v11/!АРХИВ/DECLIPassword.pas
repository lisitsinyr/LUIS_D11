unit DECLIPassword;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, ExtCtrls;

type
  TFormPassword = class(TForm)
    Bevel1: TBevel;
    Bevel2: TBevel;
    Label1: TLabel;
    DatabaseName: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    B_OK: TButton;
    Button1: TButton;
    E_UserName: TEdit;
    E_Password: TEdit;
  private
    { Private declarations }
  public
    { Public declarations }
    function Execute (Alias: string): Boolean;
  end;

var
  FormPassword: TFormPassword;

implementation

{$R *.DFM}

function TFormPassword.Execute (Alias: string): Boolean;
begin
   E_UserName.Text := '';
   E_Password.Text := '';
   DatabaseName.Caption := Alias;
   Result := (ShowModal = mrOk);
end;

end.
