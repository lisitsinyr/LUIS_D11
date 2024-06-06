(*
 =======================================================
 Copyright (c) 2023
 Author:
     Lisitsin Y.R.
 Project:
     LU_PAS
     Delphi VCL Extensions (LU)
 Module:
     LUImageList
     
 =======================================================
*)

unit LUImageList;

interface

uses
  Windows, Messages, SysUtils, Classes, Controls, ShellAPI, Graphics,
  ImgList;

type
  TShellImageList = class(TImageList)
  private
    { Private declarations }
    procedure   LinkToShell(ImgType : DWORD);
  protected
    { Protected declarations }
  public
    { Public declarations }
    constructor CreateLargeList;
    constructor CreateSmallList;
  published
    { Published declarations }
  end;

function  GetFileIcon(const FileName : string; LargeIcon : boolean) : Integer;

implementation

{
   ¬догонку забавное замечание : с большим удивлением обнаружил, что, по крайней
   мере дл€ Win95, существование файла вовсе не об€зательно. ћожно написать
   GetFileIcon('NonExistFileName.txt', False) и преспокойно получить иконку,
   ассоциированную с текстовым файлом 8-)
}

function  GetFileIcon(const FileName : string; LargeIcon : boolean) : Integer;
var
   fext, aName : string;
   sfi: TSHFileInfo;
   flags: integer;
   shFlags: integer;
begin
   aName := ExtractFileName(FileName);
   Flags := FILE_ATTRIBUTE_NORMAL;
   shFlags := SHGFI_USEFILEATTRIBUTES;
   if aName ='' then begin                        { it's a folder or a drive }
      Flags := Flags or FILE_ATTRIBUTE_DIRECTORY;
      fext  := '$FOLDER';
      aName := '$FOLDER$';  { bogus name }
      if (Length(FileName) = 3) and (Pos(':\', FileName) = 2) then begin
         { it's a drive }
         fext := FileName;   aName := FileName;
         shFlags := 0;
      end;
      end
   else
      fext := ExtractFileExt(FileName);
   SHGetFileInfo(PChar(aName), Flags, sfi, sizeof(sfi),
                 SHGFI_DISPLAYNAME or SHGFI_ICON or SHGFI_TYPENAME
                 or SHGFI_SYSICONINDEX or SHGFI_DISPLAYNAME or shFlags);
   Result := sfi.iIcon
end;

procedure TShellImageList.LinkToShell(ImgType : DWORD);
var
   sfi   : TSHFileInfo;
begin
   Handle := SHGetFileInfo('', 0, sfi, SizeOf(TSHFileInfo),
                                      SHGFI_SYSICONINDEX or ImgType);
   ShareImages  := TRUE;
   BlendColor   := clHighlight;
   DrawingStyle := dsTransparent;
end;

constructor TShellImageList.CreateLargeList;
begin
   inherited CreateSize(32, 32);
   ShareImages := True;
   LinkToShell(SHGFI_LARGEICON);
end;

constructor TShellImageList.CreateSmallList;
begin
   inherited CreateSize(16, 16);
   ShareImages := True;
   LinkToShell(SHGFI_SMALLICON);
end;

end.
