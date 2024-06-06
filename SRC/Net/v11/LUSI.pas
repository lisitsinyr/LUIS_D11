unit LUSI;

interface

uses
  Windows, SysUtils, Classes,
  LMCons;

type
  TosVersion = (osUnknown, osWin32s, osWindowsNT, osWindows2000, osWindows95, osWindows98);
  TosVersionType = (ostUnknown, ostWorkstation, ostServer);

type
  TLUSystemInfo = class(TComponent)
  private
    { Private declarations }
    function GetLUReg(Key: DWORD; const SubKey,Param: string): string;
  protected
    { Protected declarations }
    function GetLUComputerName: string;
    procedure SetLUComputerName(Value: string);
    function GetLUSystemDirectory: string;
    function GetLUSystemInfo: TSystemInfo;
    function GetLUUserName: string;
    function GetLUVersion: TosVersion;
    function GetLUVersionType: TosVersionType;
    function GetLUVersionEx: TOSVersionInfo;
    function GetLUOSName: string;
    function GetLUVersionName: string;
    function GetLUWindowsDirectory: string;
    function GetLUDesktop: string;
    function GetLUPrograms: string;
    function GetLUStartMenu: string;
  public
    { Public declarations }
    property ComputerName: string read GetLUComputerName write SetLUComputerName;
    property SystemInfo: TSystemInfo read GetLUSystemInfo;
    property UserName: string read GetLUUserName;
    { OS }
    property Version: TosVersion read GetLUVersion;
    property VersionType: TosVersionType read GetLUVersionType;
    property VersionEX: TOSVersionInfo read GetLUVersionEx;
    property OSName: string read GetLUOSName;
    property VersionName: string read GetLUVersionName;
    property SystemDirectory: string read GetLUSystemDirectory;
    property WindowsDirectory: string read GetLUWindowsDirectory;
    property Desktop: string read GetLUDesktop;
    property Programs: string read GetLUPrograms;
    property StartMenu: string read GetLUStartMenu;
  published
    { Published declarations }
  end;

procedure Register;

implementation

const
   sProductOption = 'SYSTEM\CurrentControlSet\Control\ProductOptions';
   {}
   sShellFolders = 'SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders';
   sPrograms = 'Programs';
   sDesktop  = 'Desktop';
   sStartMenu  = 'Start Menu';
   {}
   sUnknown = 'Unknown';
   sWindows_NT = 'Windows_NT';
   sWindows_2000 = 'Windows_2000';
   sWindows_98 = 'Windows_98';
   sWindows_95 = 'Windows_95';
   sWin32s = 'Win32s';

procedure Register;
begin
  RegisterComponents('LUIS Net', [TLUSystemInfo]);
end;

function TLUSystemInfo.GetLUComputerName: string;
var
   Len: DWord;
begin
   Len := MAX_COMPUTERNAME_LENGTH + 1;
   SetLength (Result, Len);
   GetComputerName(PChar(Result), Len);
   Result := PChar(Result);
end;
procedure TLUSystemInfo.SetLUComputerName(Value: string);
begin
   SetComputerName(PChar(Value));
end;

function TLUSystemInfo.GetLUSystemDirectory: string;
var
   Len: DWord;
begin
   Len := MAX_PATH + 1;
   SetLength (Result, Len);
   GetSystemDirectory(PChar(Result), Len);
   Result := PChar(Result);
end;

function TLUSystemInfo.GetLUWindowsDirectory: string;
var
   Len: DWord;
begin
   Len := MAX_PATH + 1;
   SetLength (Result, Len);
   GetWindowsDirectory(PChar(Result), Len);
   Result := PChar(Result);
end;

function TLUSystemInfo.GetLUSystemInfo: TSystemInfo;
begin
   GetSystemInfo(Result);
end;

function TLUSystemInfo.GetLUUserName: string;
var
   Len: DWord;
begin
   Len := UNLEN + 1;
   SetLength (Result, Len);
   GetUserName(PChar(Result), Len);
   Result := PChar(Result);
end;

function TLUSystemInfo.GetLUVersionEx: TOSVersionInfo;
begin
   Result.dwOSVersionInfoSize := SizeOf(TOSVersionInfo);
   GetVersionEx(Result);
end;

function TLUSystemInfo.GetLUOSName: string;
begin
   Result := sUnknown;
   case Version of
      osWindowsNT   : Result := sWindows_NT;
      osWindows2000 : Result := sWindows_2000;
      osWindows98   : Result := sWindows_98;
      osWindows95   : Result := sWindows_95;
      osWin32s      : Result := sWin32s;
   end;
end;

function TLUSystemInfo.GetLUVersionType: TosVersionType;
var
   szProductType: string;
begin
   szProductType := GetLUReg (HKEY_LOCAL_MACHINE, sProductOption, 'ProductType');
   if UpperCase(szProductType) = 'WINNT' then Result := ostWorkstation
   else
   if UpperCase(szProductType) = 'SERVERNT' then Result := ostServer
   else
   Result := ostUnknown;
end;

function TLUSystemInfo.GetLUReg(Key: DWORD; const SubKey,Param: string): string;
var
   hkWMS: HKEY;
   ValueBuf: array[0..255] of char;
   dwBufLen : DWord;
begin
   Result := '';
   RegOpenKeyEx(Key, PChar(SubKey), 0, KEY_QUERY_VALUE, hkWMS);
   RegQueryValueEx(hkWMS, PChar(Param), nil, nil, @ValueBuf, @dwBufLen);
   Result := StrPas(ValueBuf);
   RegCloseKey(hkWMS);
end;

function TLUSystemInfo.GetLUDesktop: string;
begin
   Result := GetLUReg (HKEY_CURRENT_USER, sShellFolders, sDesktop);
end;

function TLUSystemInfo.GetLUPrograms: string;
begin
   Result := GetLUReg (HKEY_CURRENT_USER, sShellFolders, sPrograms);
end;

function TLUSystemInfo.GetLUStartMenu: string;
begin
   Result := GetLUReg (HKEY_CURRENT_USER, sShellFolders, sStartMenu);
end;

function TLUSystemInfo.GetLUVersion: TosVersion;
var
   OSVersionInfo: TOSVersionInfo;
//   dwVersion : DWord;
//   dwMajorVersion : DWord;
//   dwMinorVersion : DWord;
//   dwBuild : DWord;
begin
   (*
   dwVersion := GetVersion;
   dwMajorVersion := Lo(Lo(dwVersion and $0000FFFF));
   dwMinorVersion := Hi(Lo(dwVersion and $0000FFFF));
   if dwVersion < $80000000 then
      dwBuild := (dwVersion shr 16)
   else
   if dwMajorVersion < 4 then
      dwBuild := (dwVersion shr 16) and $8000
   else
      dwBuild := 0;
   *)
   Result := osUnknown;
   OSVersionInfo := VersionEx;
   with OSVersionInfo do begin
      case dwPlatformId of
         VER_PLATFORM_WIN32_NT: begin
            if (dwMajorVersion <= 4 ) then Result := osWindowsNT;
            if (dwMajorVersion = 5 ) then Result := osWindows2000;
         end;
         VER_PLATFORM_WIN32_WINDOWS: begin
            if ((dwMajorVersion > 4) or ((dwMajorVersion = 4) and (dwMinorVersion > 0))) then
               Result := osWindows98
            else
               Result := osWindows95;
         end;
         VER_PLATFORM_WIN32s: begin
            Result := osWin32s;
         end;
      end;
   end;
end;

function TLUSystemInfo.GetLUVersionName: string;
var
   OSVersionInfo: TOSVersionInfo;
begin
   OSVersionInfo := VersionEx;
   with OSVersionInfo do begin
      Result := Format('Version %d.%d %s (Build %d)', [dwMajorVersion,dwMinorVersion,szCSDVersion,dwBuildNumber]);
   end;
end;

end.
