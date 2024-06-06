{=======================================================}
{ Project:                                              }
{         Delphi VCL Extensions (LU)                    }
{         Copyright (c) 2000 Central Bank Of Russia     }
{ Subject:                                              }
{         TextDataset                                   }
{ Author:                                               }
{         Lisitsin Y.R.                                 }
{=======================================================}

{------------------------------------------------------------------------------------}
{  TreeView that can have bold nodes. You can Bold/Unbold nodes and check whether a  }
{  node is bold. Property Recursive controls changing node's childs state            }
{                                                                                    }
{  Freeware with source code. You may use it for any purposes, but you shall include }
{  the copyright notice below.                                                       }
{                                                                                    }
{  The component is released AS IS. The author helds no responsibility in any case   }
{                                                                                    }
{  (c) 1998 Alexander Rublinetsky (rublin@iname.com)                                 }
{------------------------------------------------------------------------------------}
(*
  tagTVITEMA = packed record
    mask: UINT;
    hItem: HTreeItem;
    state: UINT;
    stateMask: UINT;
    pszText: PAnsiChar;
    cchTextMax: Integer;
    iImage: Integer;
    iSelectedImage: Integer;
    cChildren: Integer;
    lParam: LPARAM;
  end;
*)

unit LUTreeView;

interface

uses
  Windows, CommCtrl, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  ComCtrls,

  LUMAPICDO, LUMAPITags,

  LUObjects;

type
   TLUTreeView = class(TTreeView)
   private
      FRecursive: Boolean;
   protected
      procedure SetNodeState(node: TTreeNode; State: Integer);
      function GetNodeState(node: TTreeNode): Integer;
      procedure SetNodeParam(node: TTreeNode; Value: Longint);
      function GetNodeParam(node: TTreeNode): Longint;
   public
      procedure Bold(node: TTreeNode);
      procedure UnBold(node: TTreeNode);
      function IsBold(node: TTreeNode): Boolean;
      procedure ToggleBold(node: TTreeNode);
      property NodeParam[node: TTreeNode]: LongInt read GetNodeParam write SetNodeParam;
   published
      property Recursive: boolean read FRecursive write FRecursive;
   end;

   TSetIconEvent = procedure(Node: TTreeNode; Expanded: Boolean) of object;

   TLUTreeViewFolders = class(TLUTreeView)
   private
      FCDOSession: TCDOSession;
      FCDOInfoStores: TCDOInfoStores;
      FCDOFolders: TCDOFolders;
      FOnSetIcon: TSetIconEvent;
      procedure GetTreeFolders(TNRoot: TTreeNode);
      procedure GetTreeInfoStores(TNRoot: TTreeNode);
      procedure ExpandTreeNode(TN: TTreeNode);
      procedure CollapseTreeNode(TN: TTreeNode);
   protected
      procedure Expand(Node: TTreeNode); override;
      procedure Collapse(Node: TTreeNode); override;
      procedure Delete(Node: TTreeNode); override;
   public
      procedure CreateTreeViewFolders;
   published
      property CDOSession: TCDOSession read FCDOSession write FCDOSession;
      property CDOInfoStores: TCDOInfoStores read FCDOInfoStores write FCDOInfoStores;
      property CDOFolders: TCDOFolders read FCDOFolders write FCDOFolders;
      property OnSetIcon: TSetIconEvent read FOnSetIcon write FOnSetIcon;
   end;

function FindTreeNode(Items: TTreeNodes; Value: string): TTreeNode;

procedure Register;

implementation

function FindTreeNode(Items: TTreeNodes; Value: string): TTreeNode;
var i: Integer;
begin
   Result := nil;
   for i:=0 to Items.Count-1 do begin
      if Items[i].Text = Value then begin
         Result := Items[i]; Break;
      end;
   end;
end;

procedure TLUTreeView.Bold(node: TTreeNode);
var lev,i: Integer;
begin
   SetNodeState(node, TVIS_BOLD);
   if not FRecursive then Exit;
   lev := node.Level;
   i := node.AbsoluteIndex + 1;
   while (i < Items.Count) and (Items[i].Level > lev) do begin
      SetNodeState(Items[i], TVIS_BOLD);
      inc(i);
   end;
end;

procedure TLUTreeView.UnBold(node: TTreeNode);
var lev,i: Integer;
begin
   SetNodeState(node, 0);
   if not FRecursive then Exit;
   lev := node.Level;
   i := node.AbsoluteIndex + 1;
   while (i < Items.Count) and (Items[i].Level > lev) do begin
      SetNodeState(Items[i], 0);
      inc(i);
   end;
end;

function TLUTreeView.IsBold(node: TTreeNode): Boolean;
var lev,i: Integer;
begin
   Result := ((GetNodeState(node) and TVIS_BOLD) <> 0);
   if not FRecursive then Exit;
   lev := node.Level;
   i := node.AbsoluteIndex + 1;
   while (i < Items.Count) and (Items[i].Level > lev) do begin
      if (GetNodeState(Items[i]) and TVIS_BOLD) <> 0 then begin
         Result:=True;
         Exit;
      end;
      inc(i);
   end;
end;

procedure TLUTreeView.ToggleBold(node: TTreeNode);
begin
   if IsBold(node) then UnBold(node)
                   else Bold(node);
end;

procedure TLUTreeView.SetNodeState(node: TTreeNode; State: Integer);
var
   tvi : TTVItem;
begin
   FillChar(tvi, Sizeof(tvi), 0);
   tvi.hItem := node.ItemID;
   tvi.mask := TVIF_STATE;
   tvi.stateMask := TVIS_BOLD;
   tvi.state := State;
   TreeView_SetItem(node.Handle, tvi);
   if Assigned(OnChange) then OnChange(Self,Node);
end;

function TLUTreeView.GetNodeState(node: TTreeNode): Integer;
var
   tvi : TTVItem;
begin
   FillChar(tvi, Sizeof(tvi), 0);
   tvi.hItem := node.ItemID;
   tvi.mask := TVIF_STATE;
   tvi.stateMask := TVIS_BOLD;
   TreeView_GetItem(Handle, tvi);
   Result := tvi.state;
end;

procedure TLUTreeView.SetNodeParam(node: TTreeNode; Value: Longint);
var
   tvi : TTVItem;
begin
   FillChar(tvi, Sizeof(tvi), 0);
   tvi.hItem := node.ItemID;
   tvi.mask := TVIF_PARAM;
   TreeView_GetItem(Handle, tvi);
   tvi.lParam := Value;
   tvi.mask := TVIF_PARAM;
   TreeView_SetItem(node.Handle, tvi);
   if Assigned(OnChange) then OnChange(Self,Node);
end;

function TLUTreeView.GetNodeParam(node: TTreeNode): Longint;
var
   tvi : TTVItem;
begin
   FillChar(tvi, Sizeof(tvi), 0);
   tvi.hItem := node.ItemID;
   tvi.mask := TVIF_PARAM;
   TreeView_GetItem(Handle, tvi);
   Result := tvi.lParam;
end;

{ TLUTreeViewFolders }

procedure TLUTreeViewFolders.Expand(Node: TTreeNode);
begin
   inherited Expand(Node);
   ExpandTreeNode(Node);
   if Assigned(FOnSetIcon) then FOnSetIcon(Node, True);
end;

procedure TLUTreeViewFolders.Collapse(Node: TTreeNode);
begin
   inherited Collapse(Node);
   CollapseTreeNode(Node);
   if Assigned(FOnSetIcon) then FOnSetIcon(Node, False);
end;

procedure TLUTreeViewFolders.Delete(Node: TTreeNode);
begin
   if Assigned(Node.Data) then begin
      TObjects(Node.Data).Free;
      Node.Data := nil;
   end;
   inherited Delete(Node);
end;

procedure TLUTreeViewFolders.GetTreeFolders(TNRoot: TTreeNode);
var
   CDOFolder: TCDOFolder;
   TN: TTreeNode;
begin
   CDOFolders.GetFirst;
   while not CDOFolders.EOF do begin
      CDOFolder := TCDOFolder.Create(Self);
      CDOFolder.FolderName := CDOFolders.CDOFolder.FolderName;
      CDOFolder.FolderID := CDOFolders.CDOFolder.FolderID;
      CDOFolder.ID := CDOFolders.CDOFolder.ID;
      CDOFolder.StoreID := CDOFolders.CDOFolder.StoreID;
      CDOFolder.Address := '';
      TN := Items.AddChildObject(TNRoot, CDOFolder.FolderName, CDOFolder);
      if Assigned(FOnSetIcon) then FOnSetIcon(TN, False);
      CDOFolders.GetNext;
      Application.ProcessMessages;
   end;
end;

procedure TLUTreeViewFolders.ExpandTreeNode(TN: TTreeNode);
var
   Objects: TObjects;
   i: Integer;
   InfoStore: OleVariant;
   RootFolder: OleVariant;
   Folder: OleVariant;
   s1,s2: string;
begin
   Items.BeginUpdate;
   Objects := TObjects(TN.Data);
   for i:=0 to TN.Count-1 do begin
      if not TN.Item[i].HasChildren then begin
         case Objects.ObjectType of
            otExchange: begin
               s1 := TCDOInfoStore(TN.Item[i].Data).ID;
               InfoStore := CDOSession.objInfoStore[s1];
               RootFolder := InfoStore.RootFolder;
               s1 := RootFolder.ID;
               s2 := RootFolder.StoreID;
               Folder := CDOSession.GetobjFolder(s1, s2);
            end;
            otInfoStore: begin
               Folder := CDOSession.GetobjFolder(TCDOFolder(TN.Item[i].Data).ID,
                                                 TCDOFolder(TN.Item[i].Data).StoreID);
            end;
            otFolder: begin
               Folder := CDOSession.GetobjFolder(TCDOFolder(TN.Item[i].Data).ID,
                                                 TCDOFolder(TN.Item[i].Data).StoreID);

            end;
         end;
         CDOFolders.objFolders := Folder.Folders;

//CDOFolders.debug := True;
//CDOFolders.debugcdofield(CDOFolders.CDOFolder.ID);
//CDOFolders.debug := False;

         GetTreeFolders(TN.Item[i]);
      end;
   end;
   TN.AlphaSort;
   Items.EndUpdate;
end;

procedure TLUTreeViewFolders.CollapseTreeNode(TN: TTreeNode);
var
   i: Integer;
begin
   Items.BeginUpdate;
   for i:=0 to TN.Count-1 do begin
      TN.Item[i].DeleteChildren;
   end;
   Items.EndUpdate;
end;

procedure TLUTreeViewFolders.GetTreeInfoStores(TNRoot: TTreeNode);
var
   TN: TTreeNode;
   CDOInfoStore: TCDOInfoStore;
begin
   CDOInfoStores.GetFirst;
   while not CDOInfoStores.EOF do begin
      CDOInfoStore := TCDOInfoStore.Create(Self);
      CDOInfoStore.InfoStoreName := CDOInfoStores.CDOInfoStore.InfoStoreName;
      CDOInfoStore.ID := CDOInfoStores.CDOInfoStore.ID;
      CDOInfoStore.Flags := CDOInfoStores.CDOInfoStore.Flags;
      {}
      TN := Items.AddChildObject(TNRoot, CDOInfoStore.InfoStoreName, CDOInfoStore);
      if Assigned(FOnSetIcon) then FOnSetIcon(TN, False);
      CDOInfoStores.GetNext;
   end;
end;

procedure TLUTreeViewFolders.CreateTreeViewFolders;
var
   TN: TTreeNode;
   Exchange: TObjects;
begin
   Items.Clear;
   Exchange := TObjects.Create(Self);
   Exchange.ObjectType := otExchange;
   TN := Items.AddChildObject(nil, 'Microsoft Exchange', Exchange);
   if Assigned(FOnSetIcon) then FOnSetIcon(TN, False);
   GetTreeInfoStores(TN);
end;

procedure Register;
begin
   RegisterComponents('Luis', [TLUTreeView]);
   RegisterComponents('Luis', [TLUTreeViewFolders]);
end;

end.
