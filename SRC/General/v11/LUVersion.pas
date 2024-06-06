(*
 =======================================================
 Copyright (c) 2023
 Author:
     Lisitsin Y.R.
 Project:
     LU_PAS
     Delphi VCL Extensions (LU)
 Module:
    LUVersion
    Version
 =======================================================
*)

unit LUVersion;

interface

uses
   Classes, Windows, SysUtils;
(*
1 VERSIONINFO
FILEVERSION 1, 0, 0, 1
PRODUCTVERSION 1, 0, 0, 1
FILEFLAGSMASK VS_FFI_FILEFLAGSMASK
FILEFLAGS VS_FF_PRERELEASE
FILEOS VOS__WINDOWS32
FILETYPE VFT_APP
{
 BLOCK "StringFileInfo"
 {
  BLOCK "041904E3"
  {
   VALUE "CompanyName", "\023# &\021  $ ?> #;LO=>2A:>9 >1;.\000"
   VALUE "FileDescription", "\000"
   VALUE "FileVersion", "1.0.0.1\000"
   VALUE "InternalName", "\000"
   VALUE "LegalCopyright", "\000"
   VALUE "LegalTrademarks", "\000"
   VALUE "OriginalFilename", "\000"
   VALUE "ProductName", "\000"
   VALUE "ProductVersion", "1.0.0.0\000"
   VALUE "Comments", "\000"
  }
 }
 BLOCK "VarFileInfo"
 {
  VALUE "Translation", 1049, 1251
 }
}
*)
type
(*
  PVSFixedFileInfo = ^TVSFixedFileInfo;
  {$EXTERNALSYM tagVS_FIXEDFILEINFO}
  tagVS_FIXEDFILEINFO = packed record
    dwSignature: DWORD;        { e.g. $feef04bd }
    dwStrucVersion: DWORD;     { e.g. $00000042 = "0.42" }
    dwFileVersionMS: DWORD;    { e.g. $00030075 = "3.75" }
    dwFileVersionLS: DWORD;    { e.g. $00000031 = "0.31" }
    dwProductVersionMS: DWORD; { e.g. $00030010 = "3.10" }
    dwProductVersionLS: DWORD; { e.g. $00000031 = "0.31" }
    dwFileFlagsMask: DWORD;    { = $3F for version "0.42" }
    dwFileFlags: DWORD;        { e.g. VFF_DEBUG | VFF_PRERELEASE }
    dwFileOS: DWORD;           { e.g. VOS_DOS_WINDOWS16 }
    dwFileType: DWORD;         { e.g. VFT_DRIVER }
    dwFileSubtype: DWORD;      { e.g. VFT2_DRV_KEYBOARD }
    dwFileDateMS: DWORD;       { e.g. 0 }
    dwFileDateLS: DWORD;       { e.g. 0 }
  end;
*)
   PTransInfo = ^TTransInfo;
   TTransInfo = packed record
      dwLang1: WORD;
      dwLang2: WORD;
   end;

type
   TVersionInfo = class(TComponent)
   private
      FFileName : PChar;
      FInfo: Pointer;
      FInfoSize: DWORD;
      FTmp: DWORD;
      FFileInfo: PVSFixedFileInfo;
      FFileInfoSize: DWORD;
      FTransInfo: PTransInfo;
      FTransInfoSize: DWORD;
      FFileVersion: PChar;
      FCompanyName: PChar;
      FFileDescription: PChar;
      FInternalName: PChar;
      FLegalCopyright: PChar;
      FLegalTrademarks: PChar;
      FOriginalFilename: PChar;
      FProductName: PChar;
      FProductVersion: PChar;
      FComments: PChar;
      FFileDate: TDateTime;
      function GetFileName: string;
      procedure SetFileName(Value: string);
      function GetLangCharSet: string;
      function GetMajor1: Integer;
      function GetMajor2: Integer;
      function GetMinor1: Integer;
      function GetMinor2: Integer;
      function GetLang1: Integer;
      function GetLang2: Integer;
      function GetFileVersion: string;
      function GetFileDate: string;
      function GetCompanyName: string;
      function GetFileDescription: string;
      function GetInternalName: string;
      function GetLegalCopyright: string;
      function GetLegalTrademarks: string;
      function GetOriginalFilename: string;
      function GetProductName: string;
      function GetProductVersion: string;
      function GetComments: string;
      property Lang1 : Integer read GetLang1;
      property Lang2 : Integer read GetLang2;
      property LangCharSet : string read GetLangCharSet;
   public
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      property FileName : string read GetFileName write SetFileName;
      property Major1 : Integer read GetMajor1;
      property Major2 : Integer read GetMajor2;
      property Minor1 : Integer read GetMinor1;
      property Minor2 : Integer read GetMinor2;
      property FileVersion : string read GetFileVersion;
      property FileDate : string read GetFileDate;
      property CompanyName : string read GetCompanyName;
      property FileDescription : string read GetFileDescription;
      property InternalName : string read GetInternalName;
      property LegalCopyright : string read GetLegalCopyright;
      property LegalTrademarks : string read GetLegalTrademarks;
      property OriginalFilename : string read GetOriginalFilename;
      property ProductName : string read GetProductName;
      property ProductVersion : string read GetProductVersion;
      property Comments : string read GetComments;
   end;

var
   VersionInfo: TVersionInfo;

function CreateVersion(const AFileName: string): TVersionInfo;

implementation

function CreateVersion(const AFileName: string): TVersionInfo;
begin
   Result := TVersionInfo.Create(nil);
   Result.FileName := AFileName;
end;

constructor TVersionInfo.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   FFileInfoSize := 0;
   FInfo := nil;
   FFileInfo := nil;
   FileName := '';
end;

destructor TVersionInfo.Destroy;
begin
   if FFileName <> nil then StrDispose(FFileName);
   if FInfoSize > 0 then
      FreeMem(FInfo, FFileInfoSize);
   inherited Destroy;
end;

function TVersionInfo.GetFileName: string;
begin
   Result := StrPas(FFileName);
end;
procedure TVersionInfo.SetFileName(Value: string);
begin
   if FFileName <> nil then StrDispose(FFileName);
   FFileName := StrAlloc(Length(Value)+1);
   StrPCopy(FFileName, Value);
   if Value = '' then Exit;
   { Get the size of the FileVersionInformatioin }
   if FInfoSize > 0 then
      FreeMem(FInfo, FFileInfoSize);
   FInfoSize := GetFileVersionInfoSize(FFileName, FTmp);
   { If InfoSize = 0, then the file may not exist, or }
   { it may not have file version information in it. }
   if FInfoSize = 0 then
      raise Exception.Create('Can''t get file version information for '+ FileName);
   { Allocate memory for the file version information }
   GetMem(FInfo, FInfoSize);
   { Get the information }
   GetFileVersionInfo(FFileName, 0, FInfoSize, FInfo);
   FFileDate := FileDateToDateTime(FileAge(Value));
   { Query the information for the version }
   VerQueryValue(FInfo, '\', Pointer(FFileInfo), FFileInfoSize);
   { Query }
   VerQueryValue(FInfo, '\VarFileInfo\Translation', pointer(FTransInfo), FTransInfoSize);
   { Query }
   VerQueryValue(FInfo, PChar('\StringFileInfo\'+LangCharSet+'\'+'FileVersion'), pointer(FFileVersion), FTmp);
   VerQueryValue(FInfo, PChar('\StringFileInfo\'+LangCharSet+'\'+'CompanyName'), pointer(FCompanyName), FTmp);
   VerQueryValue(FInfo, PChar('\StringFileInfo\'+LangCharSet+'\'+'FileDescription'), pointer(FFileDescription), FTmp);
   VerQueryValue(FInfo, PChar('\StringFileInfo\'+LangCharSet+'\'+'InternalName'), pointer(FInternalName), FTmp);
   VerQueryValue(FInfo, PChar('\StringFileInfo\'+LangCharSet+'\'+'LegalCopyright'), pointer(FLegalCopyright), FTmp);
   VerQueryValue(FInfo, PChar('\StringFileInfo\'+LangCharSet+'\'+'LegalTrademarks'), pointer(FLegalTrademarks), FTmp);
   VerQueryValue(FInfo, PChar('\StringFileInfo\'+LangCharSet+'\'+'OriginalFilename'), pointer(FOriginalFilename), FTmp);
   VerQueryValue(FInfo, PChar('\StringFileInfo\'+LangCharSet+'\'+'ProductName'), pointer(FProductName), FTmp);
   VerQueryValue(FInfo, PChar('\StringFileInfo\'+LangCharSet+'\'+'ProductVersion'), pointer(FProductVersion), FTmp);
   VerQueryValue(FInfo, PChar('\StringFileInfo\'+LangCharSet+'\'+'Comments'), pointer(FComments), FTmp);
end;

function TVersionInfo.GetMajor1: Integer;
begin
   try
      Result := FFileInfo.dwFileVersionMS shr 16;
   except
      Result := 0;
   end;
end;

function TVersionInfo.GetMajor2: Integer;
begin
   try
      Result := FFileInfo.dwFileVersionMS and $FFFF;
   except
      Result := 0;
   end;
end;

function TVersionInfo.GetMinor1: Integer;
begin
   try
      Result := FFileInfo.dwFileVersionLS shr 16;
   except
      Result := 0;
   end;
end;

function TVersionInfo.GetMinor2: Integer;
begin
   try
      Result := FFileInfo.dwFileVersionLS and $FFFF;
   except
      Result := 0;
   end;
end;

function TVersionInfo.GetLang1: Integer;
begin
   try
      Result := FTransInfo.dwLang1;
   except
      Result := 0;
   end;
end;

function TVersionInfo.GetLang2: Integer;
begin
   try
      Result := FTransInfo.dwLang2;
   except
      Result := 0;
   end;
end;

function TVersionInfo.GetLangCharSet: string;
begin
   try
      Result := IntToHex(Lang1,4)+IntToHex(Lang2,4);
   except
      Result :='';
   end;
end;

function TVersionInfo.GetFileVersion: string;
begin
   try
      Result := StrPas(FFileVersion);
   except
      Result :='';
   end;
end;

function TVersionInfo.GetFileDate: string;
begin
   try
      Result := DateTimeToStr(FFileDate);
   except
      Result :='';
   end;
end;

function TVersionInfo.GetCompanyName: string;
begin
   try
      Result := StrPas(FCompanyName);
   except
      Result :='';
   end;
end;

function TVersionInfo.GetFileDescription: string;
begin
   try
      Result := StrPas(FFileDescription);
   except
      Result :='';
   end;
end;

function TVersionInfo.GetInternalName: string;
begin
   try
      Result := StrPas(FInternalName);
   except
      Result :='';
   end;
end;

function TVersionInfo.GetLegalCopyright: string;
begin
   try
      Result := StrPas(FLegalCopyright);
   except
      Result :='';
   end;
end;

function TVersionInfo.GetLegalTrademarks: string;
begin
   try
      Result := StrPas(FLegalTrademarks);
   except
      Result :='';
   end;
end;

function TVersionInfo.GetOriginalFilename: string;
begin
   try
      Result := StrPas(FOriginalFilename);
   except
      Result :='';
   end;
end;

function TVersionInfo.GetProductName: string;
begin
   try
      Result := StrPas(FProductName);
   except
      Result :='';
   end;
end;

function TVersionInfo.GetProductVersion: string;
begin
   try
      Result := StrPas(FProductVersion);
   except
      Result :='';
   end;
end;

function TVersionInfo.GetComments: string;
begin
   try
      Result := StrPas(FComments);
   except
      Result :='';
   end;
end;

end.
