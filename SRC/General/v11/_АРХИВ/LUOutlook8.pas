{=======================================================}
{ Project:                                              }
{         Delphi VCL Extensions (LU)                    }
{         Copyright (c) 2000 Central Bank Of Russia     }
{ Subject:                                              }
{         Работа с Excel                                }
{ Author:                                               }
{         Lisitsin Y.R.                                 }
{=======================================================}

unit LUOutlook8;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  ComObj, Outlook8, OleServer;

type
   TOutlook8 = class(TComponent)
   private
      FApplication: OleVariant;
    protected
    public
       constructor Create (AOwner: TComponent); override;
       destructor Destroy; override;
       {======================================================================}
       procedure StartApplication(AVisible: Boolean);
       procedure Logon;
       {======================================================================}
       property Application: OLeVariant read FApplication;
       {======================================================================}
   end;

procedure Register;

implementation

procedure Register;
begin
   RegisterComponents('Luis', [TOutlook8]);
end;

constructor TOutlook8.Create(AOwner: TComponent);
begin
   inherited Create(AOwner);
   FApplication := unassigned;
end;

destructor TOutlook8.destroy;
begin
   if not VarIsEmpty(FApplication) then begin
      FApplication.Quit;
   end;
   inherited Destroy;
end;

procedure TOutlook8.StartApplication(AVisible: Boolean);
begin
   if VarIsEmpty(FApplication) then begin
      try
         FApplication := CreateOleObject('Outlook.Application');
      except
      end;
   end;
end;

procedure TOutlook8.Logon;
begin
   Application.ActiveExplorer;
end;

end.
