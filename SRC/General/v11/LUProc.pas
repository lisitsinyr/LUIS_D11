(*
 =======================================================
 Copyright (c) 2023
 Author:
     Lisitsin Y.R.
 Project:
     LU_PAS
     Delphi VCL Extensions (LU)
 Module:
     LUProc
     Процедуры
 =======================================================
*)

{$WARN SYMBOL_PLATFORM OFF}

unit LUProc;

interface

uses
    {}
        comctrls, SysUtils, Forms, Windows, Graphics, VCL.Dialogs,
    Classes, Menus, StdCtrls, Controls, Buttons,
    RxToolEdit,
    LUObjects, LUSupport, LUScanDir;

type
    TPopupMenuAction = procedure(Sender: TObject) of object;

type
    TStatApplication = (saBreak, saMain, saTest, saSheduler, saSetup, saAbout,
        saAction, saSend, saRefresh, saViewLog);

var
   { Состояние программы }
    StatApplication: TStatApplication = saTest;

const
    SProcessWork = 'Идет процесс обработки ...';
    SProcessStop = 'Процесс обработки остановлен.';
    SProcessBegin = '********* Начало **********************************';
    SProcessEnd = '********* Конец ***********************************';

procedure SetControl (Control: TObject; AReadOnly: Boolean);
{ }
function GetIniFileName (const IniFileName: string): string;
function ProgramName: string;
function ProcessStop: TStatApplication;
{ ListView }
procedure SetListView (ListView: TListView);
{ TreeView }
procedure SetTreeView (TreeView: TTreeView);
procedure TreeViewCustomDraw (Sender: TCustomTreeView; const ARect: TRect;
    var DefaultDraw: Boolean);
procedure TreeViewCustomDrawItem (Sender: TCustomTreeView; Node: TTreeNode;
    State: TCustomDrawState; var DefaultDraw: Boolean);
procedure TreeViewMouseMove (Sender: TObject; Shift: TShiftState;
    X, Y: Integer);
function GetStrings (TS: TStringList): string;
procedure CreateListFileLog (const LogDir: string; PopupMenuLogs: TPopupMenu;
    ActionViewLogsExecute: TPopupMenuAction);
procedure CreateListFileName (const Path: string; PopupMenuLogs: TPopupMenu;
    ActionViewLogsExecute: TPopupMenuAction);
{ }
procedure CreateListArchiveYear (PopupMenu: TPopupMenu;
    ActionExecute: TPopupMenuAction);

implementation

function GetIniFileName (const IniFileName: string): string;
var
    s: string;
begin
    if ParamCount > 0 then
    begin
        s := IncludeTrailingBackSlash (ParamStr(1)) + IniFileName;
        if not FileExists (s) then
            s := ExpandFileName (IniFileName);
    end else begin
        s := ExpandFileName (IniFileName);
    end;
    Result := s;
end;

function ProgramName: string;
begin
    Result := ExtractFileName (ParamStr(0));
end;

function ProcessStop: TStatApplication;
begin
    Application.ProcessMessages;
    Result := StatApplication;
    if (StatApplication = saBreak) then
        raise Exception.Create (SProcessStop);
end;

procedure SetTreeView (TreeView: TTreeView);
begin
    with TreeView do
    begin
        RightClickSelect := True;
        ShowHint := True;
        readonly := True;
        HideSelection := False;
    end;
end;

procedure SetListView (ListView: TListView);
begin
    with ListView do
    begin
        ShowHint := True;
        readonly := True;
        HideSelection := False;
    end;
end;

procedure TreeViewCustomDraw (Sender: TCustomTreeView; const ARect: TRect;
    var DefaultDraw: Boolean);
begin
    (*
    This event should be used to draw any background colors or images.
    ARect represents the entire client area of the TreeView.
    Use the TreeView's canvas to do the drawing.
    Note that drawing a background bitmap is not really supported by CustomDraw,
    so scrolling can get messy. Best to subclass the TreeView and handle scrolling
    messages.
 *)
    with Sender.Canvas do
    begin
        Brush.Color := clWindow;
        Brush.Style := bsSolid;
        FillRect (ARect);
    end;
    { setting DefaultDraw to false here prevents all calls to OnCustomDrawItem. }
    DefaultDraw := True;
end;

procedure TreeViewCustomDrawItem (Sender: TCustomTreeView; Node: TTreeNode;
    State: TCustomDrawState; var DefaultDraw: Boolean);
var
    //O: TObjects;
    NodeRect: TRect;
    BackColor: Boolean;
begin
    //O := TObjects (Node.Data);
    DefaultDraw := True;
    with Sender.Canvas do
    begin
        (*
        If DefaultDraw it is true, any of the node's font properties can be
         changed. Note also that when DefaultDraw = True, Windows draws the
        buttons and ignores our font background colors, using instead the
        TreeView's Color property.
         *)
        (*
        Brush.Style := bsSolid;
        if (O.ObjectType = otTask) and (TTask(O).Tag=-1) then begin
            Font.Color := clWindow;
            Brush.Color := clHighlight;
            end
        else begin
            Font.Color := clBlack;
            Brush.Color := clWindow;
        end;
        if (O.ObjectType = otTask) then begin
            if WordCountNew(Node.Text, [' ']) > 1 then begin
                Font.Style := [fsBold];
            end;
        end;
 *)
        { Focused }
        if cdsFocused in State then
        begin
            { Font.Assign(SelectedFontDialog.Font); }
            Font.Color := clWindow;
            Brush.Color := clHighlight;
        end
        else
        { Not Focused and Selected }
            if (cdsSelected in State) then
            begin
                { Font.Assign(SelectedFontDialog.Font); }
                Font.Color := clBlack;
                Brush.Color := clSilver;
            end;
        (*
        DefaultDraw = False means you have to handle all the item drawing yourself,
      including the buttons, lines, images, and text.
 *)
        if not DefaultDraw then
        begin
            { draw the selection rect. }
            if cdsSelected in State then
            begin
                NodeRect := Node.DisplayRect (True);
                FillRect (NodeRect);
            end;
            NodeRect := Node.DisplayRect (False);

            { no bitmap, so paint in the background color. }
            BackColor := False;
            if BackColor then
            begin
                { Brush.Color := clRed; BkgColorDialog.Color }
                Brush.Style := bsSolid;
                FillRect (NodeRect)
            end else begin
                { don't paint over the background bitmap. }
                { Brush.Color := clYellow; BkgColorDialog.Color }
                Brush.Style := bsClear;
            end;

            NodeRect.Left := NodeRect.Left +
                (Node.Level * TTreeView(Sender).Indent);
            (*
            NodeRect.Left now represents the left-most portion of the expand button
            DrawButton(NodeRect, Node);
            NodeRect.Left := NodeRect.Left + TreeViewAll.Indent + FButtonSize;
            NodeRect.Left is now the leftmost portion of the image.
            DrawImage(NodeRect, Node.ImageIndex);
            NodeRect.Left := NodeRect.Left + ImageList.Width    ;
            Now we are finally in a position to draw the text.
 *)
            TextOut (NodeRect.Left, NodeRect.Top, Node.Text);
        end;
    end;
end;

procedure TreeViewMouseMove (Sender: TObject; Shift: TShiftState;
    X, Y: Integer);
var
    TN: TTreeNode;
begin
    TTreeView (Sender).SetFocus;
    TTreeView (Sender).ShowHint := False;
    TN := TTreeView (Sender).GetNodeAt (X, Y);
    if Assigned (TN) and Assigned (TN.Data) then
    begin
        (*
        case TObjects (TN.Data).ObjectType of
            otTask:
                begin
                    TTreeView (Sender).Hint := TTask (TN.Data).TaskCaption;
                    if (ssShift in Shift) and (ssLeft in Shift) then
                    begin
                        TTreeView (Sender).Selected := TTreeView (Sender)
                            .GetNodeAt (X, Y);
                        TTask (TN.Data).Tag := - 1;
                    end;
                    TTreeView (Sender).ShowHint := True;
                end;
        end;
        *)
    end;
end;

function GetStrings (TS: TStringList): string;
var
    i: Integer;
begin
    Result := '';
    for i := 0 to TS.Count - 1 do
    begin
        Result := Result + TS.Strings[i];
        if i < TS.Count - 1 then
            Result := Result + '; ';
    end;
end;

procedure CreateListFileLog (const LogDir: string; PopupMenuLogs: TPopupMenu;
    ActionViewLogsExecute: TPopupMenuAction);
(*
var
   i,j: Integer;
   NewItem: TMenuItem;
   APPFiles: TScanDirFiles;
*)
begin
    (*
    APPFiles := TScanDirFiles.Create;
    APPFiles.DelFile := False;
    APPFiles.Execute(IncludeTrailingBackslash(LogDir)+'*.log', sfDirectory);
    PopupMenuLogs.AutoHotkeys := maManual;
    PopupMenuLogs.Items.Clear;
    i := APPFiles.FileList.Count;
    j := 0;
    while (i > 0) and (j < 7) do begin
        NewItem := TMenuItem.Create(PopupMenuLogs);
        NewItem.Caption := APPFiles.FileList.Strings[i-1];
        NewItem.OnClick := ActionViewLogsExecute;
        PopupMenuLogs.Items.Add(NewItem);
        Dec(i);
        Inc(j);
    end;
    APPFiles.Free;
 *)
    CreateListFileName (IncludeTrailingBackSlash(LogDir) + '*.log',
        PopupMenuLogs, ActionViewLogsExecute);
end;

procedure CreateListFileName (const Path: string; PopupMenuLogs: TPopupMenu;
    ActionViewLogsExecute: TPopupMenuAction);
var
    i, j: Integer;
    NewItem: TMenuItem;
    APPFiles: TScanDirFiles;
begin
    APPFiles := TScanDirFiles.Create;
    APPFiles.DelFile := False;
    APPFiles.Execute (Path, sfDirectory);
    PopupMenuLogs.AutoHotkeys := maManual;
    PopupMenuLogs.Items.Clear;
    i := APPFiles.FileList.Count;
    j := 0;
    while (i > 0) and (j < 7) do
    begin
        NewItem := TMenuItem.Create (PopupMenuLogs);
        NewItem.Caption := APPFiles.FileList.Strings[i - 1];
        NewItem.OnClick := ActionViewLogsExecute;
        PopupMenuLogs.Items.Add (NewItem);
        Dec (i);
        Inc (j);
    end;
    APPFiles.Free;
end;

procedure CreateListArchiveYear (PopupMenu: TPopupMenu;
    ActionExecute: TPopupMenuAction);
var
    i: Integer;
    NewItem: TMenuItem;
    DD, MM, YY: Word;
begin
    PopupMenu.AutoHotkeys := maManual;
    PopupMenu.Items.Clear;
    DecodeDate (Date, YY, MM, DD);
    for i := YY downto YY - 4 do
    begin
        NewItem := TMenuItem.Create (PopupMenu);
        NewItem.Caption := IntToStr (i);
        NewItem.OnClick := ActionExecute;
        PopupMenu.Items.Add (NewItem);
    end;
end;

procedure SetControl (Control: TObject; AReadOnly: Boolean);
begin
   (*
   if (Control is TControl) then begin
      with (Control as TControl) do begin
         Enabled := not ReadOnly;
      end;
   end;
 *)
    if Control is TSpeedButton then
    begin
        with (Control as TSpeedButton) do
        begin
            Enabled := not AReadOnly;
            if AReadOnly then
            begin
                Font.Color := clWindowText;
            end;
        end;
    end;
    if Control is TButton then
    begin
        with (Control as TButton) do
        begin
            Enabled := not AReadOnly;
            if AReadOnly then
            begin
                Font.Color := clWindowText;
            end;
        end;
    end;
    if Control is TMenuItem then
    begin
        with (Control as TMenuItem) do
        begin
            Enabled := not AReadOnly;
            if AReadOnly then
            begin
            end;
        end;
    end;
   { }
    if Control is TEdit then
    begin
        with (Control as TEdit) do
        begin
            Enabled := not AReadOnly;
            readonly := AReadOnly;
            if AReadOnly then
            begin
            { Color := clBtnFace; }
            { Font.Color := clWindowText; }
            end;
        end;
    end;
    if Control is TMemo then
    begin
        with (Control as TMemo) do
        begin
            Enabled := not AReadOnly;
            readonly := AReadOnly;
            if AReadOnly then
            begin
            { Color := clBtnFace; }
            { Font.Color := clWindowText; }
            end;
        end;
    end;
    if Control is TComboBox then
    begin
        with (Control as TComboBox) do
        begin
            Enabled := not AReadOnly;
            Visible := AReadOnly;
            if AReadOnly then
            begin
            { Color := clBtnFace; }
            { Font.Color := clWindowText; }
            end;
        end;
    end;
    if Control is TCheckBox then
    begin
        with (Control as TCheckBox) do
        begin
            Enabled := not AReadOnly;
            { Visible := not AReadOnly; }
            if AReadOnly then
            begin
            { Color := clBtnFace; }
            { Font.Color := clWindowText; }
            end;
        end;
    end;
    if Control is TDirectoryEdit then
    begin
        with (Control as TDirectoryEdit) do
        begin
            Enabled := not AReadOnly;
            if AReadOnly then
            begin
                { Color := clBtnFace; }
                { Font.Color := clWindowText; }
            end;
        end;
    end;
end;

end.
