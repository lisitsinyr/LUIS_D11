{=======================================================}
{ Project:                                              }
{         Delphi VCL Extensions (LU)                    }
{         Copyright (c) 2000 Central Bank Of Russia     }
{ Subject:                                              }
{         Диалоги                                       }
{ Author:                                               }
{         Lisitsin Y.R.                                 }
{=======================================================}

unit LUDialogs;

interface

uses Windows, SysUtils, Classes, Graphics, Forms, Controls, StdCtrls,
  Buttons, ExtCtrls, ComCtrls, LUTreeView, Variants,

  LUMAPICDO,

  ImgList, LUObjects;

type
   TFormOpenFolderExchange = class(TForm)
      ButtonOK: TButton;
      ButtonCancel: TButton;
      Label1: TLabel;
      ImageList1: TImageList;
    LUTreeViewFolders: TLUTreeViewFolders;
      procedure LUTreeViewFoldersSetIcon(Node: TTreeNode; Expanded: Boolean);
      function GetFolderID: string;
      function GetStoreID: string;
      procedure FormActivate(Sender: TObject);
      procedure LUTreeViewFoldersChange(Sender: TObject; Node: TTreeNode);
   private
      { Private declarations }
      Function Execute(CDOSession: TCDOSession;
                       CDOInfoStores: TCDOInfoStores; CDOFolders: TCDOFolders): Integer;
   public
      { Public declarations }
      property FolderID: string read GetFolderID;
      property StoreID: string read GetStoreID;
   end;

   TOpenFolderExchange = class(TComponent)
   private
      { Private declarations }
      FCDOFolders: TCDOFolders;
      FCDOInfoStores: TCDOInfoStores;
      FCDOSession: TCDOSession;
      FFolderID: PChar;
      FStoreID: PChar;
      FFormOpenFolderExchange: TFormOpenFolderExchange;
      procedure SetCDOFolders(Value: TCDOFolders);
      procedure SetCDOInfoStores(Value: TCDOInfoStores);
      procedure SetCDOSession(Value: TCDOSession);
      function GetFolderID: string;
      procedure SetFolderID(const Value: string);
      function GetStoreID: string;
      procedure SetStoreID(const Value: string);
      function GetFolderName: string;
   public
      { Public declarations }
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      function Execute: Integer;
      property FolderID: string read GetFolderID write SetFolderID;
      property StoreID: string read GetStoreID write SetStoreID;
      property FolderName: string read GetFolderName;
   published
      property CDOSession: TCDOSession read FCDOSession write SetCDOSession;
      property CDOFolders: TCDOFolders read FCDOFolders write SetCDOFolders;
      property CDOInfoStores: TCDOInfoStores read FCDOInfoStores write SetCDOInfoStores;
   end;

procedure Register;

implementation

{$R *.DFM}

procedure SetIcon(Node: TTreeNode; Expanded: Boolean);
var L: Longint;
begin
   case TObjects(Node.Data).ObjectType of
      otFolder: begin
         if Expanded then Node.ImageIndex := 2
                     else Node.ImageIndex := 3;
         Node.SelectedIndex := 2;
         Node.StateIndex := -1;
      end;
      otInfoStore: begin
         L := TCDOInfoStore(Node.Data).Flags and $00000004;
         if L <> 0 then Node.ImageIndex := 0
                   else Node.ImageIndex := 1;
         Node.SelectedIndex := 1;
         Node.StateIndex := -1;
      end;
      else begin
         Node.ImageIndex := 4;
         Node.SelectedIndex := 4;
         Node.StateIndex := -1;
      end;
   end;
end;

{ TOpenFolderExchange }

constructor TOpenFolderExchange.Create(AOwner: TComponent);
begin
   inherited Create(AOwner);
   FolderID := '';
   StoreID := '';
   FFormOpenFolderExchange := TFormOpenFolderExchange.Create(Application);
end;

destructor TOpenFolderExchange.Destroy;
begin
   FFormOpenFolderExchange.Free;
   StrDispose(FFolderID);
   StrDispose(FStoreID);
   inherited Destroy;
end;

function TOpenFolderExchange.GetFolderID: string;
begin
   Result := StrPas(FFolderID);
end;
procedure TOpenFolderExchange.SetFolderID(const Value: string);
begin
   if FFolderID <> nil then StrDispose(FFolderID);
   FFolderID := StrAlloc(Length(Value)+1);
   StrPCopy(FFolderID, Value);
end;

function TOpenFolderExchange.GetStoreID: string;
begin
   Result := StrPas(FStoreID);
end;
procedure TOpenFolderExchange.SetStoreID(const Value: string);
begin
   if FStoreID <> nil then StrDispose(FStoreID);
   FStoreID := StrAlloc(Length(Value)+1);
   StrPCopy(FStoreID, Value);
end;

function TOpenFolderExchange.GetFolderName: string;
var
   LobjFolder: OLEVariant;
begin
   Result := '';
   if Assigned(FCDOFolders) and Assigned(FCDOSession) then begin
      CDOFolders.objFolders := UnAssigned;
      CDOSession.MAPIShowError := False;
      if (FolderID <> '') and (StoreID <> '') then begin
         LobjFolder := CDOSession.GetobjFolder(FolderID, StoreID);
         if VarType(LobjFolder) <> VarEmpty then begin
            CDOFolders.objFolders := LobjFolder.Folders;
            CDOFolders.objFolder := LobjFolder;
            Result := CDOFolders.CDOFolder.FolderName;
         end;
      end;
   end;
end;

function TOpenFolderExchange.Execute: Integer;
var
   LobjFolder: OLEVariant;
begin
   Result := mrCancel;
   FolderID := '';
   StoreID := '';
   if Assigned(FCDOFolders) and Assigned(FCDOSession) then begin

      if VarIsEmpty(CDOFolders.objFolders) then begin

         CDOFolders.objFolders := UnAssigned;
         CDOSession.MAPIShowError := False;
         if (FolderID <> '') and (StoreID <> '') then begin
            LobjFolder := CDOSession.GetobjFolder(FolderID, StoreID);
            if not VarIsEmpty(LobjFolder) then CDOFolders.objFolders := LobjFolder.Folders;
         end;

      end;

      CDOInfoStores.objInfoStores := CDOSession.objInfoStores;

      FFormOpenFolderExchange := TFormOpenFolderExchange.Create(Application);

      Result := FFormOpenFolderExchange.Execute(FCDOSession, FCDOInfoStores, FCDOFolders);
      if Result = mrOk then begin
         FolderID := FFormOpenFolderExchange.FolderID;
         StoreID := FFormOpenFolderExchange.StoreID;
      end;

      FFormOpenFolderExchange.Free;

      CDOSession.MAPIShowError := True;
   end;
end;

procedure TOpenFolderExchange.SetCDOFolders(Value: TCDOFolders);
begin
   FCDOFolders := Value;
end;

procedure TOpenFolderExchange.SetCDOInfoStores(Value: TCDOInfoStores);
begin
   FCDOInfoStores := Value;
end;

procedure TOpenFolderExchange.SetCDOSession(Value: TCDOSession);
begin
   FCDOSession := Value;
end;

{ TFormOpenFolderExchange }

Function TFormOpenFolderExchange.Execute(CDOSession: TCDOSession;
   CDOInfoStores: TCDOInfoStores;
   CDOFolders: TCDOFolders): Integer;
begin
   LUTreeViewFolders.CDOSession := CDOSession;
   LUTreeViewFolders.CDOInfoStores := CDOInfoStores;
   LUTreeViewFolders.CDOFolders := CDOFolders;

   LUTreeViewFolders.CreateTreeViewFolders;
   LUTreeViewFolders.Items[0].Expand(False);
   Result := ShowModal;
end;

function TFormOpenFolderExchange.GetFolderID: string;
begin
   Result := TCDOFolder(LUTreeViewFolders.Selected.Data).ID;
end;

function TFormOpenFolderExchange.GetStoreID: string;
begin
   Result := TCDOFolder(LUTreeViewFolders.Selected.Data).StoreID;
end;

procedure TFormOpenFolderExchange.LUTreeViewFoldersSetIcon(Node: TTreeNode;
  Expanded: Boolean);
begin
   SetIcon(Node, Expanded);
end;

procedure TFormOpenFolderExchange.FormActivate(Sender: TObject);
begin
   LUTreeViewFolders.SetFocus;
end;

procedure TFormOpenFolderExchange.LUTreeViewFoldersChange(Sender: TObject;
  Node: TTreeNode);
begin
   if TObjects(Node.Data).ObjectType = otFolder then ButtonOk.Enabled := True
                                                else ButtonOk.Enabled := False;
end;

{ This procedure is used to register this component on the component palette }

procedure Register;
begin
   RegisterComponents('Luis', [TOpenFolderExchange]);
end;

end.
