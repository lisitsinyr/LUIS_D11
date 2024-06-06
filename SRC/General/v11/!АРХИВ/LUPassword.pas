unit LUPassword;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, ExtCtrls;

type
  TFormPassword = class(TForm)
    PanelUserName: TPanel;
    LabelUserName: TLabel;
    EditUserName: TEdit;
    PanelPassword: TPanel;
    LabelPassward: TLabel;
    EditPassword: TEdit;
    PanelButton: TPanel;
    ButtonOK: TButton;
    ButtonCancel: TButton;
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
    function GetUserName: string;
    function GetPassword: string;
  public
    { Public declarations }
    function Execute(ShowUserName,ShowPassword: Boolean; ACaption: string): Boolean;
    property UserName: string read GetUserName;
    property Password: string read GetPassword;
  end;

var
  FormPassword: TFormPassword;

implementation

{$R *.DFM}

function TFormPassword.Execute(ShowUserName,ShowPassword: Boolean; ACaption: string): Boolean;
begin
   Caption := ACaption;
   EditPassword.Text := '';
   PanelUserName.Visible := ShowUserName;
   PanelPassword.Visible := ShowPassword;
   if ShowUserName then ActiveControl := EditUserName
                   else ActiveControl := EditPassword;
   PanelPassword.Top := PanelUserName.Top +
      PanelUserName.Height*(1-Integer(not PanelUserName.Visible));
   PanelButton.Top := PanelUserName.Top +
      PanelUserName.Height*(2-Integer(not PanelUserName.Visible));
   Height := PanelUserName.Height*(1-Integer(not PanelUserName.Visible)) +
             PanelPassword.Height*(1-Integer(not PanelPassword.Visible)) +
             PanelButton.Height*(1-Integer(not PanelButton.Visible)) + 50;
   Result := (ShowModal = mrOk);
end;

function TFormPassword.GetUserName: string;
begin
   Result := EditUserName.Text;
end;

function TFormPassword.GetPassword: string;
begin
   Result := EditPassword.Text;
end;

procedure TFormPassword.FormCreate(Sender: TObject);
begin
   EditUserName.Text := '';
   EditPassword.Text := '';
end;

end.
