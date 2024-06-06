(*
 =======================================================
 Copyright (C) 2001 YonYon All rights reserved
 Author:
     yonyon@azarasi.net
     http: y7.net/yonyon
 Project:
     LU_PAS
     Delphi VCL Extensions (LU)
 Module:
     ImageComboBox コンポーネント  Version 1.00-2001/05/14
     
 =======================================================
*)

unit ImageComboBox;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls;

type
  TImageIndexRecord = record
    ImageIndex : Integer;
    Depth : Integer;
  end;

  TImageComboList = class(TList)
  published
    procedure Clear; override;
  public
    { Public 宣言 }
  end;

  TImageComboBox = class(TCustomComboBox)
  private
    { Private 宣言 }
    FImageList : TImageComboList;
    FImages : TImageList;
    IListWidth : Integer;

    function GetListWidth : Integer;
    procedure SetListWidth(Value : Integer);

    procedure DeleteItemIndex(var Message : TMessage);
    procedure AddItemIndex(var Message : TMessage);
    procedure InsertItemIndex(var Message : TMessage);
    procedure ClearItemIndex(var Message : TMessage);
    procedure ChangedFont(var Message : TMessage);
    function GetImageIndex(Index : Integer) : Integer;
    procedure SetImageIndex(Index : Integer; Value : Integer);
    function GetDepth(Index : Integer) : Integer;
    procedure SetDepth(Index : Integer; Value : Integer);
    procedure SetImages(Value : TImageList);
  protected
    { Protected 宣言 }
  public
    { Public 宣言 }
    constructor Create(AOwner:TComponent); override;
    destructor Destroy; override;
    procedure DropDown; override;
    property ImageIndex[Index: Integer] : Integer read GetImageIndex write SetImageIndex;
    property Depth[Index: Integer] : Integer read GetDepth write SetDepth;
  published
    { Published 宣言 }
    procedure WndProc(var Message: TMessage); override;
    procedure DrawItem(Index: Integer; Rect: TRect; State: TOwnerDrawState); override;
    property Images: TImageList read FImages write SetImages;
    property ListWidth: Integer read GetListWidth write SetListWidth;

    property Anchors;
    property BiDiMode;
    property Canvas;
    property Color;
    property Constraints;
    property Ctl3D;
    property DragCursor;
    property DragKind;
    property DragMode;
    property DropDownCount;
    property Enabled;
    property Font;
    property ParentBiDiMode;
    property ParentColor;
    property ParentCtl3D;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint;
    property Sorted;
    property TabOrder;
    property TabStop;
    property Visible;
    property OnChange;
    property OnClick;
    property OnDragDrop;
    property OnDragOver;
    property OnDrawItem;
    property OnDropDown;
    property OnEndDock;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnMeasureItem;
    property OnStartDock;
    property OnStartDrag;
    property Items;
  end;

procedure Register;

implementation
{$R IMAGECOMBOBOX.DCR}
{$J+}

{TImageComboList}

procedure TImageComboList.Clear;
var
   i : Integer;
begin
   for i := 0 to Count - 1 do
      Dispose(Items[i]);
   inherited Clear;
end;

{TImageComboBox}

constructor TImageComboBox.Create(AOwner:TComponent);
begin
   inherited Create(AOwner);
   Style := csOwnerDrawFixed;
   FImageList := TImageComboList.Create;
end;

destructor TImageComboBox.Destroy;
begin
   FImageList.Clear;
   FImageList.Free;
   inherited Destroy;
end;

procedure TImageComboBox.DeleteItemIndex(var Message : TMessage);
begin
   FImageList.Delete(Message.WParam);
end;

procedure TImageComboBox.AddItemIndex(var Message : TMessage);
var
   i : ^TImageIndexRecord;
begin
   New(i);
   i.ImageIndex := 0;
   i.Depth := 0;
   FImageList.Add(i);
   if (Items.Count <> 0) and (ItemIndex = - 1) then
      ItemIndex := 0;
end;

procedure TImageComboBox.InsertItemIndex(var Message : TMessage);
var
   i : ^TImageIndexRecord;
begin
   New(i);
   i.ImageIndex := 0;
   i.Depth := 0;
   FImageList.Insert(Message.WParam, i);
   if (Items.Count <> 0) and (ItemIndex = - 1) then
      ItemIndex := 0;
end;

procedure TImageComboBox.ClearItemIndex(var Message : TMessage);
begin
   FImageList.Clear;
end;

procedure TImageComboBox.ChangedFont(var Message : TMessage);
begin
   ItemHeight := -Font.Height;
   if Font.Height < 0 then
      ItemHeight := -Font.Height
   else ItemHeight := Font.Height;
   RecreateWnd;
end;

procedure TImageComboBox.WndProc(var Message: TMessage);
begin
   case Message.Msg of
     CB_DELETESTRING: DeleteItemIndex(Message);
     CB_ADDSTRING:    AddItemIndex(Message);
     CB_INSERTSTRING: InsertItemIndex(Message);
     CB_RESETCONTENT: ClearItemIndex(Message);
     CM_FONTCHANGED:  ChangedFont(Message);
   end;
   inherited WndProc(Message);
end;

function TImageComboBox.GetImageIndex(Index : Integer) : Integer;
var
   i : ^TImageIndexRecord;
begin
   i := FImageList.Items[Index];
   result := i^.ImageIndex;
end;

procedure TImageComboBox.SetImageIndex(Index : Integer; Value : Integer);
var
   i : ^TImageIndexRecord;
begin
   i := FImageList.Items[Index];
   i^.ImageIndex := Value;
end;

function TImageComboBox.GetDepth(Index : Integer) : Integer;
var
   i : ^TImageIndexRecord;
begin
   i := FImageList.Items[Index];
   result := i^.Depth;
end;

procedure TImageComboBox.SetDepth(Index : Integer; Value : Integer);
var
   i : ^TImageIndexRecord;
begin
   i := FImageList.Items[Index];
   i^.Depth := Value;
end;


procedure TImageComboBox.SetImages(Value : TImageList);
begin
   FImages := Value;
end;

procedure TImageComboBox.DrawItem(Index: Integer; Rect: TRect; State: TOwnerDrawState);
begin
   if FImages <> nil then
   begin
      Canvas.FillRect(Rect);
      if DroppedDown then
         Rect.Left := Rect.Left + FImages.Width * Depth[Index];
      FImages.Draw(Canvas,
         Rect.Left, Rect.Top + ItemHeight div 2 - FImages.Height div 2,
         ImageIndex[Index]);
      Rect.Left := Rect.Left + FImages.Width;
   end;
   inherited DrawItem(Index, Rect, State);
end;


function TImageComboBox.GetListWidth : Integer;
begin
   if IListWidth < Width then
      IListWidth := Width;
   result := IListWidth;
end;

procedure TImageComboBox.SetListWidth(Value : Integer);
begin
   if Value > Width then
      IListWidth := Value
   else IListWidth := Width;
end;

procedure TImageComboBox.DropDown;
begin
   Perform(CB_SETDROPPEDWIDTH, IListWidth, 0);
   if Assigned(OnDropDown) then
      OnDropDown(self);
end;

procedure Register;
begin
  RegisterComponents('Luis', [TImageComboBox]);
end;

end.
