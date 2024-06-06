{=======================================================}
{ Project:                                              }
{         Delphi VCL Extensions (LU)                    }
{         Copyright (c) 2000 Central Bank Of Russia     }
{ Subject:                                              }
{         Unit поддержки                                }
{ Author:                                               }
{         Lisitsin Y.R.                                 }
{=======================================================}

unit LUSupport;

interface

uses
   Windows, SysUtils,
   Forms,  
   Dialogs;

procedure SaveWindowState(Form: TForm; Desktop: TIniFile);
procedure LoadWindowState(Form: TForm; Desktop: TIniFile);

procedure SelectDir(Handle: HWND; edPath: string);

function GetFileNode(Items: TTreeNodes; DirName: String): TTreeNode;
function GetFileOutlineNode(Outline: TOutline; DirName: String): TOutlineNode;


implementation

const
  isProjectFormViewer = 'ProjectExplorer';

  ivCreate = 'Create';
  ivVisible = 'Visible';
  ivState = 'State';
  ivTop = 'Top';
  ivLeft = 'Left';
  ivWidth = 'Width';
  ivHeight = 'Height';
  ivMaxLeft = 'MaxLeft';
  ivMaxTop = 'MaxTop';
  ivMaxWidth = 'MaxWidth';
  ivMaxHeight = 'MaxHeight';

procedure SaveWindowState(Form: TForm; Desktop: TIniFile);
var
  WindowPlacement: TWindowPlacement;
begin
   with Form do begin
     if Visible then with Desktop do
     begin
       WriteBool(isProjectFormViewer, ivCreate, True);
       WriteBool(isProjectFormViewer, ivVisible, Visible);
       WriteInteger(isProjectFormViewer, ivState, Ord(WindowState));

       if WindowState in [wsMinimized, wsMaximized] then  { 3.1 only }
       begin
         WindowPlacement.length := SizeOf(WindowPlacement);
         GetWindowPlacement(Handle, @WindowPlacement);
         with WindowPlacement.rcNormalPosition do
         begin
           WriteInteger(isProjectFormViewer, ivLeft, left);
           WriteInteger(isProjectFormViewer, ivTop, top);
           WriteInteger(isProjectFormViewer, ivWidth, right - left);
           WriteInteger(isProjectFormViewer, ivHeight, bottom - top);
           WriteInteger(isProjectFormViewer, ivMaxLeft, WindowPlacement.ptMaxPosition.x);
           WriteInteger(isProjectFormViewer, ivMaxTop, WindowPlacement.ptMaxPosition.y);
           if WindowState = wsMaximized then
           begin
             WriteInteger(isProjectFormViewer, ivMaxWidth, Width);
             WriteInteger(isProjectFormViewer, ivMaxHeight, Height);
           end;
         end;
       end
       else
       begin
         WriteInteger(isProjectFormViewer, ivLeft, Left);
         WriteInteger(isProjectFormViewer, ivTop, Top);
         WriteInteger(isProjectFormViewer, ivWidth, Width);
         WriteInteger(isProjectFormViewer, ivHeight, Height);
       end;
     end;
   end;
end;

procedure LoadWindowState(Form: TForm; Desktop: TIniFile);
var
  X, Y, W, H: Integer;
  //Visible: Boolean;
  //WindowState: TWindowState;
  WindowPlacement: TWindowPlacement;
begin
   with Form do begin
     if Desktop.ReadBool(isProjectFormViewer, ivCreate, False) then with Desktop do
     begin
       Position := poDesigned;
       Visible := ReadBool(isProjectFormViewer, ivVisible, False);
       WindowState := TWindowState(ReadInteger(isProjectFormViewer, ivState, Ord(wsNormal)));
       X := ReadInteger(isProjectFormViewer, ivLeft, Left);
       Y := ReadInteger(isProjectFormViewer, ivTop, Top);
       W := ReadInteger(isProjectFormViewer, ivWidth, Width);
       H := ReadInteger(isProjectFormViewer, ivHeight, Height);

       with WindowPlacement do
       begin
         length := SizeOf(WindowPlacement);
         rcNormalPosition.left := X;
         rcNormalPosition.top := Y;
         rcNormalPosition.right := X + W;
         rcNormalPosition.bottom := Y + H;
         ptMaxPosition.x := ReadInteger(isProjectFormViewer, ivMaxLeft, -GetSystemMetrics(SM_CXFRAME));
         ptMaxPosition.y := ReadInteger(isProjectFormViewer, ivMaxTop, -GetSystemMetrics(SM_CYFRAME));
         case WindowState of
           wsMinimized: showCmd := SW_SHOWMINIMIZED;
           wsMaximized: showCmd := SW_SHOWMAXIMIZED;
           wsNormal: showCmd := SW_NORMAL;
         end;
         flags := 0;
       end;
       SetWindowPlacement(Handle, @WindowPlacement);
       if WindowState = wsMaximized then
       begin
         W := ReadInteger(isProjectFormViewer, ivMaxWidth, Width);
         H := ReadInteger(isProjectFormViewer, ivMaxHeight, Height);
         SetBounds(Left, Top, W, H);
       end;
       Form.Visible := Visible;
     end;
   end;
end;

procedure SelectDir(Handle: HWND; edPath: string);
const
  Title = 'Please select directory where application will be installed';
var
   dn: array [0..MAX_PATH] of char;
   BI: TBrowseInfo;
   R: PItemIDList;
   d: string;
begin
   //inherited;
   With bi do begin
      hwndOwner := Handle;
      pidlRoot := nil;
      pszDisplayName := dn;
      lpszTitle := PChar(Title);
      ulFlags :=  BIF_RETURNFSANCESTORS + BIF_RETURNONLYFSDIRS;
      lpfn := nil;
      lParam := 1;
      iImage := 0;
   end;
   r := shBrowseForFolder(bi);
   If r = nil then exit;
   Win32Check(SHGetPathFromIDList(r, dn));
   d := ExcludeTrailingBackSlash(StrPas(dn));
   If DirectoryExists(d) then
      If MessageDlg(Format('Folder ''%s'' doesn''t exists. Do you wish to create it?',
         [d]), mtWarning, [mbYes, mbNo], 0) = mrYes then edPath := d;
end;

const
{$IFDEF WIN32}
  FileNotFound = 18;
{$ELSE}
  FileNotFound = -18;
{$ENDIF}

function GetFileNode(Items: TTreeNodes; DirName: String): TTreeNode;
var
   i: Integer;
   s,s1,s2: string;
   TS: TStringList;
   LNodeDir: TTreeNode;
   NodeDir: TTreeNode;

   function FindFileNode(N1: TTreeNode; Value: string; Level: Integer): TTreeNode;
   var
      N2: TTreeNode;
   begin
      Result := nil;
      if Assigned(N1) then begin
         N2 := N1.GetFirstChild;
         while (Assigned(N2) and (N2.Text <> Value) and (N2.Level <= Level)) do begin
            if N2.HasChildren then FindFileNode(N2, Value, Level);
            N2 := N1.GetNextChild(N2);
         end;
         if (Assigned(N2) and (N2.Text = Value)) then begin
            Result := N2;
            Exit;
         end;
      end;
   end;

begin
   TS := TStringList.Create;
   s1 := ExtractFileName(DirName);
   s2 := ExtractFileDir(DirName);
   while s1 <> '' do begin
      TS.Add(s1);
      s1 := ExtractFileName(S2);
      s2 := ExtractFileDir(S2);
   end;
   LNodeDir := Items.GetFirstNode;
   NodeDir := nil;
   for i:=TS.Count-1 downto 0 do begin
      s := TS.Strings[i];
      LNodeDir := FindFileNode(LNodeDir, s, TS.Count-i+1);
      if Assigned(LNodeDir) then
         NodeDir := LNodeDir
      else begin
         if not Assigned(NodeDir) then
            NodeDir := Items.AddChild(NodeDir, s2);
         NodeDir := Items.AddChild(NodeDir, s);
      end;
   end;
   TS.Free;
   Result := NodeDir;
end;

function GetFileOutlineNode(Outline: TOutline; DirName: String): TOutlineNode;
var
   i: Integer;
   s,s1,s2: string;
   TS: TStringList;
   LNodeDir: TOutlineNode;
   NodeDir: TOutlineNode;

   function FindFileOutlineNode(N1: TOutlineNode; Value: string; Level: Cardinal): TOutlineNode;
   var
      N2: TOutlineNode;
      I2: Integer;
   begin
      Result := nil;
      if Assigned(N1) then begin
         I2 := N1.GetFirstChild;
         N2 := Outline.Items[I2];
         while (Assigned(N2) and (N2.Text <> Value) and (N2.Level <= Level)) do begin
            if N2.HasItems then FindFileOutlineNode(N2, Value, Level);
            I2 := N1.GetNextChild(I2);
            N2 := nil;
            if I2 > 0 then N2 := Outline.Items[I2];
         end;
         if (Assigned(N2) and (N2.Text = Value)) then begin
            Result := N2;
            Exit;
         end;
      end;
   end;

begin
   TS := TStringList.Create;
   s1 := ExtractFileName(DirName);
   s2 := ExtractFileDir(DirName);
   while s1 <> '' do begin
      TS.Add(s1);
      s1 := ExtractFileName(S2);
      s2 := ExtractFileDir(S2);
   end;
   LNodeDir := nil;
   if Outline.ItemCount > 0 then LNodeDir := Outline.Items[1];
   NodeDir := nil;
   for i:=TS.Count-1 downto 0 do begin
      s := TS.Strings[i];
      LNodeDir := FindFileOutlineNode(LNodeDir, s, TS.Count-i+1);
      if Assigned(LNodeDir) then
         NodeDir := LNodeDir
      else begin
         if not Assigned(NodeDir) then
            NodeDir := Outline.Items[Outline.AddChild(0, s2)];
         NodeDir := Outline.Items[Outline.AddChild(NodeDir.Index, s)];
      end;
   end;
   TS.Free;
   Result := NodeDir;
end;


end.