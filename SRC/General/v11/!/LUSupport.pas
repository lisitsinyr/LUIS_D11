(*
 =======================================================
 Copyright (c) 2023
 Author:
     Lisitsin Y.R.
 Project:
     LU_PAS
     Delphi VCL Extensions (LU)
 Module:
    LUSupport
    Unit ���������
 =======================================================
*)

{$WARN SYMBOL_PLATFORM OFF}

unit LUSupport;

interface

uses Windows, SysUtils, IniFiles, Registry, DateUtils, ShlObj, ActiveX,
    ComObj, Winsock, ShellApi,
    LUWNet, LMErrLU, LmErrText, LUStrUtils, LUVersion;

function GetCPUSpeed: DWORD;

{ ������������ ������� }
function SearchFile (const FileName, DefaultExt: string): string;
function SearchINIFile (const FileName: string): string;
function SearchEXEFile (const FileName: string): string;
function FileNameWithoutExt (const FileName: string): string;
function CheckDestFileName (const FileName, DestPath: string;
    NLimit: Integer): string;

function GetDirNameYYMMDD (const RootDir: string; ADate: TDateTime): string;
function GetDirNameYYMM (const RootDir: string; ADate: TDateTime): string;
function IsNT: Boolean;
function IsWinXX: Boolean;
procedure GetOSVersion (var OSVersionInfo: TOSVersionInfo);

function GetTempDir: string;

function GetEnvVar (const EnvVar: string): string;
procedure SetEnvVar (const EnvVar, Value: string);
{ }
function DirectoryExists (const Name: string): Boolean;
function ForceDirectories (Dir: string): Boolean;

function GetFileDateTime (const FileName: string): TDateTime;
function GetDeltaDay (const FileName: string): TDateTime;
function GetFileSize (const FileName: string): Integer;
procedure FileLink (const FileName, Arg, DisplayName, Folder: string);
function CreateFileLink (const FileName, Arg, WorkPath, IconFile, Name,
    DestPath: string): string;
function FileDelete (const FileName: string): Boolean;
function DirectoryDelete (const DirectoryName: string): Boolean;
function FileCopy (const FileName, DestPathName: string;
    Overwrite: Boolean): Boolean;
function FileMove (const FileName, DestPathName: string): Boolean;
function File2File (const FileNameS, FileNameD: string;
    Overwrite: Boolean): Boolean;
(*
function BacCopy (const APathSource, APathDest: string; CheckSize, Log: Boolean;
    Delta: Integer): Boolean;
*)
(*
function BacCopyS (const APathSource, APathDest: string;
    CheckSize, Log: Boolean; Delta: Integer): Boolean;
*)
function CheckFile (const APathSource, APathDest: string;
    Delete, Log: Boolean): Boolean;
procedure CorectFile (const FileName: string; Off: DWORD; Len: Integer;
    var AData);
{ }

{ ������ �� ����������� � ������}

function GetParamFromString (ParamName: string; ParamValues: string;
    ParamNames: array of string; WordDelims: TCharSet): string;
function CharFromSet (C: TCharSet): Char;
procedure SetParamToString (ParamName: string; var ParamValues: string;
    ParamNames: array of string; WordDelims: TCharSet; Value: string);

{ ������ � INI}

function GetINIFileName (const FileName: string): string;
procedure SetKeyIni (const FileName, GroupName, ParamName, Value: string);
function GetKeyIni (const FileName, GroupName, ParamName: string): string;

{ ������ � REG}

procedure SetKeyReg (const P1, P2, Name, Format, Value: string);
function GetKeyReg (const P1, P2, Name, Format: string): string;
function SaveRegToFile (const FileName, RootKey, Key: string): Boolean;



{ }
function Dos2Win (const S: string): string;
function Win2Dos (const S: string): string;
function Stepen (const a, b: Double): Double;
function DateTimeStr (TimeOnly: Boolean): string;
{ ======================================================================= }
function LoadDLL (NameDll: string; var HandleDLL: HModule): Boolean;
function UnLoadDLL (HandleDLL: HModule): Boolean;
function GetFunc (HandleDLL: HModule; NameFunc: string;
    var AddFunc: Pointer): Boolean;
function ErrorString (Error: DWORD): string;
function LastErrorString: string;
{ ======================================================================= }
function TrimChar (const S: string; C: Char): string;
function TrimCharLeft (const S: string; C: Char): string;
function TrimCharRight (const S: string; C: Char): string;
{ ======================================================================= }
function GetFolderCU (const AFolderName: string): string;
function GetFolderLM (const AFolderName: string): string;
{ ======================================================================= }
(*
procedure RescaleImage(Source, Target: TBitmap; aThumbSize: Integer);
*)

function GetLocalIP: string;

function ProgramVersion: string;

function GetFileOwner (FileName: string; var Domain, Username: string): Boolean;
function SetFileOwner (FileName: string;
    const Domain, Username: string): Boolean;

function SetFileOwner_02 (const FileName: string;
    const Domain, Username: string): Boolean; overload;
function SetFileOwner_02 (const FileName: string; Username: string)
    : Boolean; overload;


{ ** Command line routines ** }

(*
{$IFNDEF RX_D4}

function FindCmdLineSwitch (const Switch: string; SwitchChars: TCharSet;
    IgnoreCase: Boolean): Boolean;

{$ENDIF}

function GetCmdLineArg (const Switch: string; SwitchChars: TCharSet): string;
*)

function GetParam (const ParamName, DefaultValue: string): string;

implementation

uses LUExec;

const
    RootKeyHKLM = HKEY_LOCAL_MACHINE;
    RootKeyHKCU = HKEY_CURRENT_USER;

type
    PTOKEN_USER = ^TOKEN_USER;

    _TOKEN_USER = record
        User: TSidAndAttributes;
    end;

    TOKEN_USER = _TOKEN_USER;


{ IsNT }

function IsNT: Boolean;
begin
    Result := (Win32Platform = VER_PLATFORM_WIN32_NT);
end;

function IsWinXX: Boolean;
begin
    Result := (Win32Platform = VER_PLATFORM_WIN32_WINDOWS);
end;

{ GetOSVersion }

procedure GetOSVersion (var OSVersionInfo: TOSVersionInfo);
begin
    OSVersionInfo.dwOSVersionInfoSize := SizeOf (OSVersionInfo);
    GetVersionEx (OSVersionInfo);
end;

{ FileUtils }

{ DirectoryExists }

function DirectoryExists (const Name: string): Boolean;
var
    Code: Integer;
begin
    Code := GetFileAttributes (PChar(name));
    Result := (Code <> - 1) and (FILE_ATTRIBUTE_DIRECTORY and Code <> 0);
end;

{ ForceDirectories }
const
    SCannotCreateDir: string = 'Unable to create directory';

function ForceDirectories (Dir: string): Boolean;
begin
    Result := True;
    if Length (Dir) = 0 then
        raise Exception.CreateRes (@SCannotCreateDir);
    Dir := ExcludeTrailingBackslash (Dir);
    if (Length(Dir) < 3) or DirectoryExists (Dir) or (ExtractFilePath(Dir) = Dir)
    then
        Exit; { avoid 'xyz:\' problem. }
    Result := ForceDirectories (ExtractFilePath(Dir)) and CreateDir (Dir);
end;

{ FileLink }

const
    IID_IPersistFile: TGUID = (D1: $0000010B; D2: $0000; D3: $0000;
        D4: ($C0, $00, $00, $00, $00, $00, $00, $46));

procedure FileLink (const FileName, Arg, DisplayName, Folder: string);
var
    ShellLink: IShellLink;
    PersistFile: IPersistFile;
  (*
  ItemIDList: PItemIDList;
  FileDestPath: array[0..MAX_PATH] of Char;
 *)
    FileDestPath: string;
    FileNameW: array [0 .. MAX_PATH] of WideChar;
begin
    CoInitialize (nil);
    try
        OleCheck (CoCreateInstance(CLSID_ShellLink, nil, CLSCTX_SERVER,
            IID_IShellLinkA, ShellLink));
        try
            OleCheck (ShellLink.QueryInterface(IID_IPersistFile, PersistFile));
            try
        (*
        OleCheck(SHGetSpecialFolderLocation(0, Folder, ItemIDList));
        SHGetPathFromIDList(ItemIDList, FileDestPath);
        StrCat(FileDestPath, PChar('\' + DisplayName + LinkExt));
 *)
                FileDestPath := Folder + '\' + DisplayName + '.lnk';
                ShellLink.SetPath (PChar(FileName));
                ShellLink.SetIconLocation (PChar(FileName), 0);
                ShellLink.SetWorkingDirectory
                    (PChar(ExtractFilePath(FileName)));
                ShellLink.SetArguments (PChar(Arg));
                MultiByteToWideChar (CP_ACP, 0, PAnsiChar(FileDestPath), - 1,
                    FileNameW, MAX_PATH);
                OleCheck (PersistFile.Save(FileNameW, True));
            finally
                PersistFile := nil;
            end;
        finally
            ShellLink := nil;
        end;
    finally
        CoUninitialize;
    end;
end;

{ CreateFileLink }

function CreateFileLink (const FileName, Arg, WorkPath, IconFile, Name,
    DestPath: string): string;
var
    LShellLink: IShellLink;
    LPersistFile: IPersistFile;
    LFileDestPath: string;
    LFileNameW: array [0 .. MAX_PATH] of WideChar;
    LDescription: string;
    LFileExt: string;
    LFileNameS: string;
begin
    Result := '';
    CoInitialize (nil);
    try
        OleCheck (CoCreateInstance(CLSID_ShellLink, nil, CLSCTX_SERVER,
            IID_IShellLinkA, LShellLink));
        try
            OleCheck (LShellLink.QueryInterface(IID_IPersistFile,
                LPersistFile));
            try
                LFileExt := ExtractFileExt (FileName);
                if (UpperCase(LFileExt) = '.BAT') then
                begin
                    if IsNT then
                        LFileDestPath := DestPath + '\' + name + '.lnk'
                    else
                        LFileDestPath := DestPath + '\' + name + '.pif';
                end else if (UpperCase(LFileExt) = '.EXE') then
                begin
                    if IsNT then
                        LFileDestPath := DestPath + '\' + name + '.lnk'
                    else
                        LFileDestPath := DestPath + '\' + name + '.pif';
                end else begin
                    if IsNT then
                        LFileDestPath := DestPath + '\' + name + '.lnk'
                    else
                        LFileDestPath := DestPath + '\' + name + '.pif';
                end;

                LShellLink.SetPath (PChar(FileName));
                LShellLink.SetIconLocation (PChar(IconFile), 0);
                LShellLink.SetWorkingDirectory (PChar(WorkPath));
                LShellLink.SetArguments (PChar(Arg));
                LShellLink.SetDescription (PChar(LDescription));
                MultiByteToWideChar (CP_ACP, 0, PAnsiChar(LFileDestPath), - 1,
                    LFileNameW, MAX_PATH);
                OleCheck (LPersistFile.Save(LFileNameW, True));

                if IsNT then
                begin
                    SetLength (LFileNameS, MAX_PATH * 2 + 1);
               { ????OleCheck(LPersistFile.GetCurFile(PWideChar(LFileNameS))); }
                    Result := WideCharToStr (PWideChar(LFileNameS), 0);
                end else begin
                    Result := LFileDestPath;
                end;

            finally
                LPersistFile := nil;
            end;
        finally
            LShellLink := nil;
        end;
    finally
        CoUninitialize;
    end;
end;

{ GetFileDateTime }

function GetFileDateTime (const FileName: string): TDateTime;
var
    FileHandle: Integer;
begin
    Result := 0;
    if FileExists (FileName) then
    begin
        FileHandle := FileOpen (FileName, fmShareDenyRead);
        Result := FileDateToDateTime (FileGetDate(FileHandle));
        FileClose (FileHandle);
    end;
end;

{ GetDeltaDay }

function GetDeltaDay (const FileName: string): TDateTime;
var
    LFileDate: TDateTime;
begin
    LFileDate := Round (GetFileDateTime(FileName));
    Result := Date - LFileDate;
end;

{ GetFileSize }

function GetFileSize (const FileName: string): Integer;
var
    F: file of Byte;
begin
    Result := 0;
    if FileExists (FileName) then
    begin
        try
            AssignFile (F, FileName);
            Reset (F);
            Result := FileSize (F);
            CloseFile (F);
        except
            Result := 0;
        end;
    end;
end;

{ FileDelete }

function FileDelete (const FileName: string): Boolean;
begin
    try
      { Clear ReadOnly }
        FileSetAttr (FileName, FileGetAttr(FileName) and (faReadOnly xor $FF));
        if FileExists (FileName) then
            SysUtils.DeleteFile (FileName);
        Result := True;
    except
        Result := False;
    end;
end;

{ DirectoryDelete }

function DirectoryDelete (const DirectoryName: string): Boolean;
begin
    try
        if DirectoryExists (DirectoryName) then
            SysUtils.RemoveDir (DirectoryName);
        Result := True;
    except
        Result := False;
    end;
end;

{ File2File }

function File2File (const FileNameS, FileNameD: string;
    Overwrite: Boolean): Boolean;
var
    FNS, FND: string;
    PNS, PND: string;
begin
    PNS := ExtractFilePath (FileNameS);
    PND := ExtractFilePath (FileNameD);
    FNS := FileNameS;
    FND := FileNameD;

    try
        if not DirectoryExists (PND) then
            ForceDirectories (PND);
        if Windows.CopyFile (PChar(FNS), PChar(FND), LongBool(not Overwrite))
        then
        begin
         { Clear ReadOnly }
            FileSetAttr (FND, FileGetAttr(FND) and (faReadOnly xor $FF));
            Result := True;
        end else begin
            Result := False; { Error Copy! }
        end;
    except
        Result := False; { Error Copy! }
    end;
end;

{ FileCopy }

function FileCopy (const FileName, DestPathName: string;
    Overwrite: Boolean): Boolean;
var
    FNS, FND: string;
    LDestPathName: string;
begin
    if Trim (DestPathName) = '' then
        LDestPathName := GetCurrentDir
    else
        LDestPathName := ExpandFileName (DestPathName);
    FNS := FileName;
    FND := IncludeTrailingBackslash (LDestPathName) +
        ExtractFileName (FileName);
   { New }
    Result := File2File (FNS, FND, Overwrite);
end;

{ FileMove }

function FileMove (const FileName, DestPathName: string): Boolean;
begin
   { Clear ReadOnly }
    FileSetAttr (FileName, FileGetAttr(FileName) and (faReadOnly xor $FF));
    Result := FileCopy (FileName, DestPathName, True);
    if Result then
        Result := FileDelete (FileName);
end;

{ FileNameWithoutExt }

function FileNameWithoutExt (const FileName: string): string;
var
    LExt: string;
    LFileName: string;
begin
    LExt := ExtractFileExt (FileName);
    LFileName := ExtractFileName (FileName);
    if LExt <> '' then
        Result := Copy (LFileName, 1, Pos(LExt, LFileName) - 1)
    else
        Result := LFileName;
end;

{ CheckDestFileName }

function CheckDestFileName (const FileName, DestPath: string;
    NLimit: Integer): string;
var
    LFileName: string;
    LDirName: string;
    LPathName: string;
    i: Integer;
    LN: Integer;
begin
    LN := Length (IntToStr(NLimit));
    LFileName := ExtractFileName (FileName);
    LDirName := DestPath;
    LPathName := IncludeTrailingBackslash (LDirName) +
        FileNameWithoutExt (LFileName) + ExtractFileExt (LFileName);
    if (FileExists(LPathName)) then
    begin
        i := 0;
        while (FileExists(LPathName)) and (i < NLimit) do
        begin
            Inc (i);
            LPathName := IncludeTrailingBackslash (LDirName) +
                FileNameWithoutExt (LFileName) + '~' +
                AddChar ('0', IntToStr(i), LN) + ExtractFileExt (LFileName);
        end;
    end;
    Result := LPathName;
end;

{ GetCPUSpeed }

function GetCPUSpeed: DWORD;
const
    DelayTime = 500;
var
    TimerHi, TimerLo: DWORD;
    PriorityClass, Priority: Integer;
begin
    PriorityClass := GetPriorityClass (GetCurrentProcess);
    Priority := GetThreadPriority (GetCurrentThread);

    SetPriorityClass (GetCurrentProcess, REALTIME_PRIORITY_CLASS);
    SetThreadPriority (GetCurrentThread, THREAD_PRIORITY_TIME_CRITICAL);

    Sleep (10);
    asm
        dw  310Fh { rdtsc }
        mov TimerLo, eax
        mov TimerHi, edx
    end;
    Sleep (DelayTime);
    asm
        dw  310Fh { rdtsc }
        sub eax, TimerLo
        sbb edx, TimerHi
        mov TimerLo, eax
        mov TimerHi, edx
    end;

    SetThreadPriority (GetCurrentThread, Priority);
    SetPriorityClass (GetCurrentProcess, PriorityClass);

    Result := Trunc (TimerLo / (1000.0 * DelayTime));
end;

{ GetDirNameYYMMDD }

function GetDirNameYYMMDD (const RootDir: string; ADate: TDateTime): string;
var
    YY, MM, DD: Word;
    YYs, MMs, DDs: string[4];
begin
    DecodeDate (ADate, YY, MM, DD);
    YYs := AddChar ('0', IntToStr(YY), 2);
    MMs := AddChar ('0', IntToStr(MM), 2);
    DDs := AddChar ('0', IntToStr(DD), 2);
    Result := Format ('%s%s\%s\%s', [IncludeTrailingBackslash(RootDir), YYs,
        MMs, DDs]);
end;

{ GetDirNameYYMM }

function GetDirNameYYMM (const RootDir: string; ADate: TDateTime): string;
var
    YY, MM, DD: Word;
    YYs, MMs, DDs: string[4];
begin
    DecodeDate (ADate, YY, MM, DD);
    YYs := AddChar ('0', IntToStr(YY), 2);
    MMs := AddChar ('0', IntToStr(MM), 2);
    DDs := AddChar ('0', IntToStr(DD), 2);
    Result := Format ('%s%s\%s', [IncludeTrailingBackslash(RootDir), YYs, MMs]);
end;

{ GetTempDir }

function GetTempDir: string;
var
    pc: PChar;
begin
    pc := StrAlloc (256);
    GetTempPath (256, pc);
    Result := StrPas (pc);
    StrDispose (pc);
end;

{ GetEnvVar }

function GetEnvVar (const EnvVar: string): string;
var
    BytesNeeded: DWORD;
    buffer: array [0 .. 255] of Char;
begin
    Result := '';
    BytesNeeded := GetEnvironmentVariable (PChar(EnvVar), nil, 0);
    if BytesNeeded > 0 then
    begin
        SetLength (Result, BytesNeeded);
        GetEnvironmentVariable (PChar(EnvVar), buffer, BytesNeeded);
        Result := StrPas (buffer);
    end;
end;

procedure SetEnvVar (const EnvVar, Value: string);
begin
    SetEnvironmentVariable (PChar(EnvVar), PChar(Value));
end;

{ SetKeyReg }

procedure SetKeyReg (const P1, P2, Name, Format, Value: string);
var
    Reg: TRegistry;
begin
    Reg := TRegistry.Create;
    try
        if UpperCase (P1) = 'HKLM' then
            Reg.RootKey := HKEY_LOCAL_MACHINE
        else if UpperCase (P1) = 'HKCU' then
            Reg.RootKey := HKEY_CURRENT_USER;
        Reg.OpenKey (P2, True);
        if UpperCase (Format) = 'B' then
        begin
            if UpperCase (Trim(Value)) = 'TRUE' then
                Reg.WriteBool (name, True)
            else
                Reg.WriteBool (name, False);
        end else if UpperCase (Format) = 'S' then
            Reg.WriteString (name, Value)
        else if UpperCase (Format) = 'SE' then
            Reg.WriteExpandString (name, Value)
        else if UpperCase (Format) = 'I' then
            Reg.WriteInteger (name, StrToInt(Value))
        else if UpperCase (Format) = 'F' then
            Reg.WriteFloat (name, StrToFloat(Value))
        else if UpperCase (Format) = 'D' then
            Reg.WriteDate (name, StrToDate(Value))
        else if UpperCase (Format) = 'DT' then
            Reg.WriteDateTime (name, StrToDateTime(Value))
        else if UpperCase (Format) = 'T' then
            Reg.WriteTime (name, StrToTime(Value));
    except
    end;
    Reg.Free;
end;

{ SaveRegToFile }

function SaveRegToFile (const FileName, RootKey, Key: string): Boolean;
var
    LWorkDir: string;
    LProgramName: string;
    LParamStr: string;
    LStatus: Cardinal;
begin
    Result := False;
    LWorkDir := ExtractFileDir (FileName);
    LProgramName := 'regedit.exe';
    LParamStr := '';
    if UpperCase (RootKey) = 'HKLM' then
        LParamStr := '/ea' + ' ' + FileName + ' ' + 'HKEY_LOCAL_MACHINE\' + Key
    else if UpperCase (RootKey) = 'HKCU' then
        LParamStr := '/ea' + ' "' + FileName + '" ' + '"HKEY_CURRENT_USER\'
            + Key + '"';
    if LParamStr <> '' then
    begin
        Result := ExecuteAll (LProgramName, LParamStr, LWorkDir, True,
            SW_HIDE, LStatus);
    end;
end;

{ GetKeyReg }

function GetKeyReg (const P1, P2, Name, Format: string): string;
var
    Reg: TRegistry;
begin
    Result := '';
    Reg := TRegistry.Create;
    try
        if UpperCase (P1) = 'HKLM' then
            Reg.RootKey := HKEY_LOCAL_MACHINE
        else if UpperCase (P1) = 'HKCU' then
            Reg.RootKey := HKEY_CURRENT_USER
        else if UpperCase (P1) = 'HKCR' then
            Reg.RootKey := HKEY_CLASSES_ROOT;
        Reg.OpenKeyReadOnly (P2);
        if UpperCase (Format) = 'B' then
        begin
            if Reg.ReadBool (name) then
                Result := 'TRUE'
            else
                Result := 'FALSE';
        end else if UpperCase (Format) = 'S' then
            Result := Reg.ReadString (name)
        else if UpperCase (Format) = 'SE' then
            Result := Reg.ReadString (name)
        else if UpperCase (Format) = 'I' then
            Result := IntToStr (Reg.ReadInteger(name))
        else if UpperCase (Format) = 'F' then
            Result := FloatToStr (Reg.ReadFloat(name))
        else if UpperCase (Format) = 'D' then
            Result := DateToStr (Reg.ReadDate(name))
        else if UpperCase (Format) = 'DT' then
            Result := DateTimeToStr (Reg.ReadDateTime(name))
        else if UpperCase (Format) = 'T' then
            Result := TimeToStr (Reg.ReadTime(name));
    except
    end;
    Reg.Free;
end;


{$IFNDEF RX_D4}

function FindCmdLineSwitch (const Switch: string; SwitchChars: TCharSet;
    IgnoreCase: Boolean): Boolean;
var
    I: Integer;
    S: string;
begin
    for I := 1 to ParamCount do
    begin
        S := ParamStr (I);
        if (SwitchChars = []) or ((S[1] in SwitchChars) and (Length(S) > 1))
        then
        begin
            S := Copy (S, 2, MaxInt);
            if IgnoreCase then
            begin
                if (AnsiCompareText(S, Switch) = 0) then
                begin
                    Result := True;
                    Exit;
                end;
            end else begin
                if (AnsiCompareStr(S, Switch) = 0) then
                begin
                    Result := True;
                    Exit;
                end;
            end;
        end;
    end;
    Result := False;
end;

{$ENDIF RX_D4}

function GetCmdLineArg (const Switch: string; SwitchChars: TCharSet): string;
var
    I: Integer;
    S: string;
begin
    I := 1;
    while I <= ParamCount do
    begin
        S := ParamStr (I);
        if (SwitchChars = []) or ((S[1] in SwitchChars) and (Length(S) > 1))
        then
        begin
            if (AnsiCompareText(Copy(S, 2, MaxInt), Switch) = 0) then
            begin
                Inc (I);
                if I <= ParamCount then
                begin
                    Result := ParamStr (I);
                    if (Result[1] in SwitchChars) then
                        Result := '';
                    Exit;
                end;
            end;
        end;
        Inc (I);
    end;
    Result := '';
end;

{ GetParam }

function GetParam (const ParamName, DefaultValue: string): string;
const
    Switch = ['-', '/'];
var
    LParamValue: string;
begin
    Result := DefaultValue;
    if FindCmdLineSwitch (ParamName, Switch, True) then
    begin
        LParamValue := GetCmdLineArg (ParamName, Switch);
        if LParamValue <> '' then
            Result := LParamValue;
    end;
end;

{ GetINIFileName }

function GetINIFileName (const FileName: string): string;
var
    WinDir: string;
    P, F, E: string;
    S: string;
begin
    Result := FileName;
    P := ExtractFileDir (FileName);
    F := ExtractFileName (FileName);
    E := ExtractFileExt (FileName);
    if E = '' then
        F := F + '.ini';
    if P = '' then
    begin
        WinDir := GetEnvVar ('WinDir');
        S := GetCurrentDir + ';' + WinDir;
        Result := FileSearch (F, S);
        if Result = '' then
            Result := IncludeTrailingBackslash (WinDir) + F;
    end;
    Result := ExpandFileName (Result);
end;

{ SetKeyIni }

procedure SetKeyIni (const FileName, GroupName, ParamName, Value: string);
var
    INIFile: TINIFile;
    LFileName: string;

begin
    LFileName := GetINIFileName (FileName);
    if not FileExists (LFileName) then
        LFileName := ExpandFileName (ExtractFileName(FileName));
    INIFile := TINIFile.Create (LFileName);
    INIFile.WriteString (GroupName, ParamName, Value);
    INIFile.Free;
end;

{ GetKeyIni }

function GetKeyIni (const FileName, GroupName, ParamName: string): string;
var
    INIFile: TINIFile;
    LFileName: string;

begin
    LFileName := GetINIFileName (FileName);
    if FileExists (LFileName) then
    begin
        INIFile := TINIFile.Create (LFileName);
        Result := INIFile.ReadString (GroupName, ParamName, '');
        INIFile.Free;
    end;
end;

(*
{ BacCopy }

function BacCopy (const APathSource, APathDest: string; CheckSize, Log: Boolean;
    Delta: Integer): Boolean;
var
    PS: string;
    PD: string;
    N: string;
    E: string;
    i: Integer;
   { }
    TS: TSearchRec;
    ResTS: Integer;
    FNS: string;
    DTS: TDateTime;
    InfoS: string;
   { }
    TD: TSearchRec;
    FND: string;
    DTD: TDateTime;
    InfoD: string;
    FC: Boolean;
begin
    PS := ExtractFilePath (ExpandFileName(APathSource));
    PD := ExpandFileName (APathDest);
    N := ExtractFileName (APathSource);
    E := ExtractFileExt (APathSource);
    WriteLN (APathSource, ' -> ', APathDest, ' (CheckSize=', CheckSize, ')',
        ' (Log=', Log, ')', ' (Delta=', Delta, ')');
    Result := True;
    try
        ForceDirectories (APathDest);
        FillChar (TS, SizeOf(TS), $00);
        ResTS := FindFirst (IncludeTrailingBackslash(PS) + N, faAnyFile, TS);
        i := 0;
        while (ResTS = 0) do
        begin
            if (TS.Attr and faDirectory) = 0 then
            begin
            { It is File }
            { }
                FNS := IncludeTrailingBackslash (PS) + TS.Name;
                DTS := FileDateToDateTime (TS.Time);
                FND := IncludeTrailingBackslash (PD) + TS.Name;
                if not FileExists (FND) then
                begin
                    InfoD := Format ('%-28s  ',
                        ['----------------------------']);
                    FC := True;
                    InfoD := InfoD + ' N';
                end else begin
                    FillChar (TD, SizeOf(TD), $00);
                    FindFirst (FND, faAnyFile, TD);
                    SysUtils.FindClose (TD);
                    DTD := FileDateToDateTime (TD.Time);
                    InfoD := Format ('%17s %10d  ',
                        [DateTimeToStr(DTD), TD.Size]);
                    FileSetAttr (FND, FileGetAttr(FND) and
                        (faReadOnly xor $FF));
                    FC := False;
                    if ((TS.Time - TD.Time) >= Delta) then
                    begin
                        FC := True;
                        InfoD := InfoD + ' T';
                    end;
                    if CheckSize and (TS.Size <> TD.Size) then
                    begin
                        FC := True;
                        InfoD := InfoD + ' S';
                    end;
                end;

                if FC then
                begin
                    Inc (i);
                    InfoS := Format ('%3d %-12s %17s %10d',
                        [i, TS.Name, DateTimeToStr(DTS), TS.Size]);
                    if Log then
                        WriteLN (InfoS + ' ' + InfoD);
                    if not Windows.CopyFile (PChar(FNS), PChar(FND),
                        LongBool(False)) then
                    begin
                        Result := False;
                        if Log then
                            WriteLN ('Error copy!');
                    end;
                end;
            end;
            ResTS := FindNext (TS);
        end;
        SysUtils.FindClose (TS);
    except
        Result := False;
    end;
end;
*)

(*
{ BacCopyS }

function BacCopyS (const APathSource, APathDest: string;
    CheckSize, Log: Boolean; Delta: Integer): Boolean;
var
    PS: string;
    PD: string;
    N: string;
    E: string;
    i: Integer;

    procedure Scan (APS, APD, AN: string);
    var
        LTS: TSearchRec;
        LResTS: Integer;
        LFND: string;
        LFNS: string;
        LDTS: TDateTime;
        LTD: TSearchRec;
        LDTD: TDateTime;
        LInfoD: string;
        LInfoS: string;
        LFC: Boolean;
    begin
        FillChar (LTS, SizeOf(LTS), $00);
        LResTS := FindFirst (IncludeTrailingBackslash(APS) + AN,
            faAnyFile, LTS);
        while (LResTS = 0) do
        begin
            if (LTS.Attr and faDirectory) = 0 then
            begin
            { ��� ���� }
                LFNS := IncludeTrailingBackslash (APS) + LTS.Name;
                LDTS := FileDateToDateTime (LTS.Time);

                LFND := IncludeTrailingBackslash (APD) + LTS.Name;
                if not FileExists (LFND) then
                begin
                    LInfoD := Format ('%-28s  ',
                        ['----------------------------']);
                    LInfoD := LInfoD + ' N';
                    LFC := True;
                end else begin
                    FillChar (LTD, SizeOf(LTD), $00);
                    FindFirst (LFND, faAnyFile, LTD);
                    SysUtils.FindClose (LTD);
                    LDTD := FileDateToDateTime (LTD.Time);
                    LInfoD := Format ('%17s %10d  ',
                        [DateTimeToStr(LDTD), LTD.Size]);
                    FileSetAttr (LFND, FileGetAttr(LFND) and
                        (faReadOnly xor $FF));
                    LFC := False;
                    if ((LTS.Time - LTD.Time) >= Delta) then
                    begin
                        LInfoD := LInfoD + ' T';
                        LFC := True;
                    end;
                    if CheckSize and (LTS.Size <> LTD.Size) then
                    begin
                        LInfoD := LInfoD + ' S';
                        LFC := True;
                    end;
                end;
                if LFC then
                begin
                    Inc (i);
                    LInfoS := Format ('%3d %-12s %17s %10d',
                        [i, LTS.Name, DateTimeToStr(LDTS), LTS.Size]);
                    if Log then
                        WriteLN (LInfoS + ' ' + LInfoD);
                    if not Windows.CopyFile (PChar(LFNS), PChar(LFND),
                        LongBool(False)) then
                    begin
                        if Log then
                            WriteLN ('Error copy!');
                    end;
                end;
            end else begin
            { ��� ������� }
                if (LTS.Name <> '.') and (LTS.Name <> '..') then
                begin
                    ForceDirectories (IncludeTrailingBackslash(APD) + LTS.Name);
                    Scan (IncludeTrailingBackslash(APS) + LTS.Name,
                        IncludeTrailingBackslash(APD) + LTS.Name, AN);
                end;
            end;
            LResTS := FindNext (LTS);
        end;
        SysUtils.FindClose (LTS);
    end;

    procedure ScanFile (APS, APD, AN: string);
    var
        LTS: TSearchRec;
        LResTS: Integer;
        LFND: string;
        LFNS: string;
        LDTS: TDateTime;
        LTD: TSearchRec;
        LDTD: TDateTime;
        LInfoD: string;
        LInfoS: string;
        LFC: Boolean;
    begin
        FillChar (LTS, SizeOf(LTS), $00);
        LResTS := FindFirst (IncludeTrailingBackslash(APS) + AN,
            faAnyFile, LTS);
        while (LResTS = 0) do
        begin
            if (LTS.Attr and faDirectory) = 0 then
            begin
            { ��� ���� }
                LFNS := IncludeTrailingBackslash (APS) + LTS.Name;
                LDTS := FileDateToDateTime (LTS.Time);

                LFND := IncludeTrailingBackslash (APD) + LTS.Name;
                if not FileExists (LFND) then
                begin
                    LInfoD := Format ('%-28s  ',
                        ['----------------------------']);
                    LInfoD := LInfoD + ' N';
                    LFC := True;
                end else begin
                    FillChar (LTD, SizeOf(LTD), $00);
                    FindFirst (LFND, faAnyFile, LTD);
                    SysUtils.FindClose (LTD);
                    LDTD := FileDateToDateTime (LTD.Time);
                    LInfoD := Format ('%17s %10d  ',
                        [DateTimeToStr(LDTD), LTD.Size]);
                    FileSetAttr (LFND, FileGetAttr(LFND) and
                        (faReadOnly xor $FF));
                    LFC := False;
                    if ((LTS.Time - LTD.Time) >= Delta) then
                    begin
                        LInfoD := LInfoD + ' T';
                        LFC := True;
                    end;
                    if CheckSize and (LTS.Size <> LTD.Size) then
                    begin
                        LInfoD := LInfoD + ' S';
                        LFC := True;
                    end;
                end;
                if LFC then
                begin
                    ForceDirectories (IncludeTrailingBackslash(APD));
                    Inc (i);
                    LInfoS := Format ('%3d %-12s %17s %10d',
                        [i, LTS.Name, DateTimeToStr(LDTS), LTS.Size]);
                    if Log then
                        WriteLN (LInfoS + ' ' + LInfoD);
                    if not Windows.CopyFile (PChar(LFNS), PChar(LFND),
                        LongBool(False)) then
                    begin
                        if Log then
                            WriteLN ('Error copy!');
                    end;
                end;
            end else begin
            { ��� ������� }
            end;
            LResTS := FindNext (LTS);
        end;
        SysUtils.FindClose (LTS);
    end;

    procedure ScanDir (APS, APD, AN: string);
    var
        LSR: TSearchRec;
        LFound: Integer;
    begin
        LFound := FindFirst (IncludeTrailingBackslash(APS) + '*.*',
            faAnyFile, LSR);
        while (LFound = 0) do
        begin
            if (LSR.Name <> '.') and (LSR.Name <> '..') then
            begin
                if (LSR.Attr and faDirectory) <> 0 then
                begin
               { It is Directory }
                    if AN <> '' then
                        ScanFile (IncludeTrailingBackslash(APS) + LSR.Name,
                            IncludeTrailingBackslash(APD) + LSR.Name, AN);
                    ScanDir (IncludeTrailingBackslash(APS) + LSR.Name,
                        IncludeTrailingBackslash(APD) + LSR.Name, AN);
                end;
            end;
            LFound := FindNext (LSR);
        end;
        SysUtils.FindClose (LSR);
    end;

begin
    PS := ExtractFilePath (ExpandFileName(APathSource));
    PD := ExpandFileName (APathDest);
    N := ExtractFileName (APathSource);
    E := ExtractFileExt (APathSource);
    WriteLN (PS, ' -> ', PD, ' (CheckSize=', CheckSize, ')', ' (Log=', Log, ')',
        ' (Delta=', Delta, ')');
    ForceDirectories (PD);
    i := 0;
    ScanDir (PS, PD, N);
    if N <> '' then
        ScanFile (IncludeTrailingBackslash(PS),
            IncludeTrailingBackslash(PD), N);
    Result := True;
end;
*)

{ CheckFile }

function CheckFile (const APathSource, APathDest: string;
    Delete, Log: Boolean): Boolean;
var
    PS: string;
    PD: string;
    N: string;
    E: string;
    i: Integer;

    procedure ScanFile (APS, APD, AN: string);
    var
        LTS: TSearchRec;
        LResTS: Integer;
        LFND: string;
        LFNS: string;
        LInfoS: string;
    begin
        FillChar (LTS, SizeOf(LTS), $00);
        LResTS := FindFirst (IncludeTrailingBackslash(APS) + AN,
            faAnyFile, LTS);
        while (LResTS = 0) do
        begin
            if (LTS.Attr and faDirectory) = 0 then
            begin
            { ��� ���� }
                LFNS := IncludeTrailingBackslash (APS) + LTS.Name;
                FileDateToDateTime (LTS.Time);
                LFND := IncludeTrailingBackslash (APD) + LTS.Name;
                if not FileExists (LFND) then
                begin
                    Inc (i);
                    LInfoS := Format ('%3d %-12s %10d',
                        [i, LTS.Name, LTS.Size]);
                    if Log then
                        WriteLN (LInfoS);
                    if Delete then
                        FileDelete (LFNS);
                end;
            end;
            LResTS := FindNext (LTS);
        end;
        SysUtils.FindClose (LTS);
    end;

    procedure ScanDir (APS, APD, AN: string);
    var
        LSR: TSearchRec;
        LFound: Integer;
    begin
        LFound := FindFirst (IncludeTrailingBackslash(APS) + '*.*',
            faAnyFile, LSR);
        while (LFound = 0) do
        begin
            if (LSR.Name <> '.') and (LSR.Name <> '..') then
            begin
                if (LSR.Attr and faDirectory) <> 0 then
                begin
               { It is Directory }
                    if AN <> '' then
                        ScanFile (IncludeTrailingBackslash(APS) + LSR.Name,
                            IncludeTrailingBackslash(APD) + LSR.Name, AN);
                    ScanDir (IncludeTrailingBackslash(APS) + LSR.Name,
                        IncludeTrailingBackslash(APD) + LSR.Name, AN);
                end;
            end;
            LFound := FindNext (LSR);
        end;
        SysUtils.FindClose (LSR);
    end;

begin
    PS := ExtractFilePath (ExpandFileName(APathSource));
    PD := ExpandFileName (APathDest);
    N := ExtractFileName (APathSource);
    E := ExtractFileExt (APathSource);
    WriteLN (PS, ' -> ', PD, ' (Delete=', Delete, ')', ' (Log=', Log, ')');
    i := 0;
    ScanDir (PS, PD, N);
    if N <> '' then
        ScanFile (IncludeTrailingBackslash(PS),
            IncludeTrailingBackslash(PD), N);
    Result := True;
end;

{ SearchFile }

function SearchFile (const FileName, DefaultExt: string): string;
var
    Buffer1: PChar;
    Buffer2: PChar;
begin
    Result := FileName;
    if ExtractFileDir (Result) = '' then
    begin
        if ExtractFileExt (Result) = '' then
            Result := Result + DefaultExt;
        Buffer1 := StrAlloc (255);
        if SearchPath (nil, PChar(Result), nil, 255, Buffer1, Buffer2) > 0 then
            Result := StrPas (Buffer1)
        else
            Result := '';
        StrDispose (Buffer1);
    end else begin
        if ExtractFileExt (Result) = '' then
            Result := Result + DefaultExt;
        Result := ExpandFileName (Result);
        if not FileExists (Result) then
            Result := '';
    end;
end;

{ SearchINIFile }

function SearchINIFile (const FileName: string): string;
begin
    Result := SearchFile (FileName, '.ini');
end;

{ SearchEXEFile }

function SearchEXEFile (const FileName: string): string;
begin
    Result := SearchFile (FileName, '.exe');
end;

{ Dos2Win }

function Dos2Win (const S: string): string;
var
    P: PChar;
begin
    P := StrAlloc (Length(S) + 1);
    StrPCopy (P, S);
    OEMtoChar (PAnsiChar(P), PWideChar(P));
    Result := StrPas (P);
    StrDispose (P);
end;

{ Win2Dos }

function Win2Dos (const S: string): string;
var
    P: PChar;
begin
    P := StrAlloc (Length(S) + 1);
    StrPCopy (P, S);
    CharToOEM (PWideChar(P), PAnsiChar(P));
    Result := StrPas (P);
    StrDispose (P);
end;

{ Stepen }

function Stepen (const a, b: Double): Double;
{
� ���� �<0, �� x-������, �� ����� �������:
y:=exp(x*Ln(Abs(a)));
� ���� �<0, �� �-��������, �� ������� �����:
y:=-exp(x*Ln(Abs(a)));
}
begin
    if b > 0 then
        Result := exp (a * LN(b))
    else
        Result := exp (a * LN(Abs(b)));
end;

{ DateTimeStr }

function DateTimeStr (TimeOnly: Boolean): string;
var
    Today: TDateTime;
    hh, nn, ss, ms: Word;
    S: string;
begin
    Today := Now;
    DecodeTime (Today, hh, nn, ss, ms);
    S := AddChar ('0', IntToStr(ms), 3);
    if TimeOnly then
        Result := FormatDateTime ('hhmmss' + S, Today)
    else
        Result := FormatDateTime ('yyyymmddmmhhmmss' + S, Today);
end;

{ ================================================================== }
{ }
{ ================================================================== }

{ LoadDLL }

function LoadDLL (NameDll: string; var HandleDLL: HModule): Boolean;
begin
    HandleDLL := LoadLibrary (PChar(NameDll));
    Result := (HandleDLL >= HINSTANCE_ERROR);
end;

{ UnLoadDLL }

function UnLoadDLL (HandleDLL: HModule): Boolean;
begin
    Result := FreeLibrary (HandleDLL);
end;

{ GetFunc }

function GetFunc (HandleDLL: HModule; NameFunc: string;
    var AddFunc: Pointer): Boolean;
begin
    try
        AddFunc := GetProcAddress (HandleDLL, PChar(NameFunc));
    except
        AddFunc := nil;
    end;
    Result := Assigned (AddFunc);
end;

{ ErrorString }

function ErrorString (Error: DWORD): string;
begin
    Result := SysErrorMessage (Error);
end;

{ LastErrorString }

function LastErrorString: string;
begin
    Result := ErrorString (GetLastError);
end;

{ ================================================================== }
{ }
{ ================================================================== }

{ Param }

function GetParamFromString (ParamName: string; ParamValues: string;
    ParamNames: array of string; WordDelims: TCharSet): string;
var
    i, j: Integer;
begin
    Result := '';
    j := 0;
    for i := low(ParamNames) to high(ParamNames) do
    begin
        if UpperCase (ParamName) = UpperCase (ParamNames[i]) then
        begin
            j := i + 1;
            Break;
        end;
    end;
    if j > 0 then
    begin
        Result := Trim (ExtractWordNew(j, ParamValues, WordDelims));
    end;
end;

{ CharFromSet }

function CharFromSet (C: TCharSet): Char;
var
    i: Byte;
begin
    Result  :=  '?';
    for i := 0 to 255 do
    begin
        if Chr (i) in C then
        begin
            Result := Chr (i);
            Break;
        end;
    end;
end;

{ SetParamToString }

procedure SetParamToString (ParamName: string; var ParamValues: string;
    ParamNames: array of string; WordDelims: TCharSet; Value: string);
var
    i, j: Integer;
    S: string;
    Stroka: string;
begin
    Stroka := ParamValues;
    S := '';
    for i := low(ParamNames) to high(ParamNames) do
    begin
        j := i + 1;
        if UpperCase (ParamName) = UpperCase (ParamNames[i]) then
            S := S + Value
        else
            S := S + ExtractWordNew (j, Stroka, WordDelims);
        if i <> high(ParamNames) then
            S := S + CharFromSet (WordDelims);
    end;
    ParamValues := S;
end;

{ TrimChar }

function TrimChar (const S: string; C: Char): string;
var
    i, L: Integer;
begin
    L := Length (S);
    i := 1;
    while (i <= L) and (S[i] <= C) do
        Inc (i);
    if i > L then
        Result := ''
    else
    begin
        while S[L] <= ' ' do
            Dec (L);
        Result := Copy (S, i, L - i + 1);
    end;
end;

{ TrimCharLeft }

function TrimCharLeft (const S: string; C: Char): string;
var
    i, L: Integer;
begin
    L := Length (S);
    i := 1;
    while (i <= L) and (S[i] <= C) do
        Inc (i);
    Result := Copy (S, i, Maxint);
end;

{ TrimCharRight }

function TrimCharRight (const S: string; C: Char): string;
var
    i: Integer;
begin
    i := Length (S);
    while (i > 0) and (S[i] <= C) do
        Dec (i);
    Result := Copy (S, 1, i);
end;

function GetFolderCU (const AFolderName: string): string;
var
    LReg: TRegistry;
    S: string;
begin
    S := 'Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders';
    LReg := TRegistry.Create;
    LReg.RootKey := RootKeyHKCU;
    if LReg.OpenKey (S, False) then
    begin
        Result := LReg.ReadString (AFolderName);
    end;
    LReg.CloseKey;
    LReg.Free;
end;

function GetFolderLM (const AFolderName: string): string;
var
    LReg: TRegistry;
    S: string;
begin
    S := 'SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders';
    LReg := TRegistry.Create;
    LReg.RootKey := RootKeyHKLM;
    if LReg.OpenKey (S, False) then
    begin
        Result := LReg.ReadString (AFolderName);
    end;
    LReg.CloseKey;
    LReg.Free;
end;

procedure CorectFile (const FileName: string; Off: DWORD; Len: Integer;
    var AData);
var
    F: file;
    Size, Blocks: Integer;
    buffer: Pointer;
type
    ArrayOfByte = array [0 .. 0] of Byte;
begin
    try
        AssignFile (F, FileName);
        Reset (F, 1);
        Size := FileSize (F);
        GetMem (buffer, Size + 1);
        if IOResult = 0 then
        begin
            BlockRead (F, buffer^, Size, Blocks);
            CloseFile (F);
            AssignFile (F, FileName);
            Rewrite (F, 1);
            Move (AData, ArrayOfByte(buffer^)[Off], Len);
            BlockWrite (F, buffer^, Size, Blocks);
            CloseFile (F);
        end;
    finally
        FreeMem (buffer);
    end;
end;

function GetLocalIP: string;
var
    WSAData: TWSAData;
    Host: PHostEnt;
    Buf: array [0 .. 127] of Char;
begin
    if WSAStartup ($101, WSAData) = 0 then
    begin
        if GetHostName (@Buf, 128) = 0 then
        begin
            Host := GetHostByName (@Buf);
            if Host <> nil then
            begin
                Result := iNet_ntoa (PInAddr(Host^.h_addr_list^)^);
            end;
        end;
        WSACleanUP;
    end;
end;

(*
 ������ ��������� ����� ������������ � ������ ��� ������� ��������
 ������� ����� ��� �������

 ������������ ������� ����� ��� :
   chDomain:=50;
   chUser :=50;
   GetCurrentUserAndDomain(User,chuser,Domain,chDomain)
 ���� ��� ���������� �������� ������ ��� ������������ - ����������� GetUserName
 ������ ������ ����� ������������ � ��� ����������� - ������� �� �������
 �������� ��� �������������.  ������� ������ Localsystem �������������
 ��� ������������ - SYSTEM � ����� NT AUTORITY (����� ��������� �� ��������)
*)

function GetCurrentUserAndDomain (szUser: PChar; var chUser: DWORD;
    szDomain: PChar; var chDomain: DWORD): Boolean;
var
    hToken: THandle;
    cbBuf: Cardinal;
    ptiUser: PTOKEN_USER;
    snu: SID_NAME_USE;
begin
    Result := False;
   { �������� ������ ������� �������� ������ ������ �������� }
    if not OpenThreadToken (GetCurrentThread(), TOKEN_QUERY, True, hToken) then
    begin
        if GetLastError () <> ERROR_NO_TOKEN then
            Exit;
      { � ������ ������ - �������� ������ ������� ������ ��������. }
        if not OpenProcessToken (GetCurrentProcess(), TOKEN_QUERY, hToken) then
            Exit;
    end;

   { �������� GetTokenInformation ��� ��������� ������� ������ }
    if not GetTokenInformation (hToken, TokenUser, nil, 0, cbBuf) then
        if GetLastError () <> ERROR_INSUFFICIENT_BUFFER then
        begin
            CloseHandle (hToken);
            Exit;
        end;

    if cbBuf = 0 then
        Exit;

   { �������� ������ ��� ����� }
    GetMem (ptiUser, cbBuf);

   { � ������ �������� ������ ������� ��������� �� TOKEN_USER }
    if GetTokenInformation (hToken, TokenUser, ptiUser, cbBuf, cbBuf) then
    begin
      { ���� ��� ������������ � ��� ����� �� ��� SID }
        if LookupAccountSid (nil, ptiUser.User.Sid, szUser, chUser, szDomain,
            chDomain, snu) then
            Result := True;
    end;

   { ����������� ������� }
    CloseHandle (hToken);
    FreeMem (ptiUser);
end;

function ProgramVersion: string;
var
    Ver: TVersionInfo;
begin
    Ver := TVersionInfo.Create (nil);
    Ver.FileName := ParamStr (0);
    Result := Ver.FileName + ' ' + Ver.FileVersion + ' ' + Ver.FileDate;
    Ver.Free;
end;

{ GetFileOwner(FileName }

function GetFileOwner (FileName: string; var Domain, Username: string): Boolean;
var
    SecDescr: PSecurityDescriptor;
    SizeNeeded, SizeNeeded2: DWORD;
    OwnerSID: PSID;
    OwnerDefault: BOOL;
    OwnerName, DomainName: PChar;
    OwnerType: SID_NAME_USE;
begin
    Result := False;
    GetMem (SecDescr, 1024);
    GetMem (OwnerSID, SizeOf(PSID));
    GetMem (OwnerName, 1024);
    GetMem (DomainName, 1024);
    try
        if not GetFileSecurity (PChar(FileName), OWNER_SECURITY_INFORMATION,
            SecDescr, 1024, SizeNeeded) then
            Exit;
        if not GetSecurityDescriptorOwner (SecDescr, OwnerSID, OwnerDefault)
        then
            Exit;
        SizeNeeded := 1024;
        SizeNeeded2 := 1024;
        if not LookupAccountSid (nil, OwnerSID, OwnerName, SizeNeeded,
            DomainName, SizeNeeded2, OwnerType) then
            Exit;
        Domain := DomainName;
        Username := OwnerName;
    finally
        FreeMem (SecDescr);
        FreeMem (OwnerName);
        FreeMem (DomainName);
    end;
    Result := True;
end;

{ SetFileOwner(FileName }

function SetFileOwner (FileName: string;
    const Domain, Username: string): Boolean;
var
    SecDescr: PSecurityDescriptor;
    SizeNeeded, SizeNeeded2: DWORD;
    OwnerSID: PSID;
    OwnerDefault: BOOL;
    OwnerName, DomainName: PChar;
    OwnerType: SID_NAME_USE;
   // SecurityInformation: SECURITY_INFORMATION;
begin
    Result := False;
    GetMem (SecDescr, 1024);
    GetMem (OwnerSID, SizeOf(PSID));
    GetMem (OwnerName, 1024);
    GetMem (DomainName, 1024);
    try
        if not GetFileSecurity (PChar(FileName), OWNER_SECURITY_INFORMATION,
            SecDescr, 1024, SizeNeeded) then
            Exit;
        if not GetSecurityDescriptorOwner (SecDescr, OwnerSID, OwnerDefault)
        then
            Exit;
        SizeNeeded := 1024;
        SizeNeeded2 := 1024;
        if not LookupAccountSid (nil, OwnerSID, OwnerName, SizeNeeded,
            DomainName, SizeNeeded2, OwnerType) then
            Exit;
    finally
        FreeMem (SecDescr);
        FreeMem (OwnerName);
        FreeMem (DomainName);
    end;
    Result := True;
end;

function DivideUserName_02 (S: string; var Domain: string;
    var Username: string): Boolean;
var
    i: Integer;
begin
    i := Pos ('\', S);
    if i <> 0 then
    begin
        Domain := Copy (S, 1, i - 1);
        Username := Copy (S, i + 1, Maxint);
        Result := True;
    end else begin
        i := Pos ('@', S);
        if i <> 0 then
        begin
            Username := Copy (S, 1, i - 1);
            Domain := Copy (S, i + 1, Maxint);
         // result := true;
        end else begin
            Domain := '';
            Username := S;
        end;
        Result := False;
    end;
end;

function GetCompName_02: string;
var
    sz: DWORD;
begin
    SetLength (Result, MAX_COMPUTERNAME_LENGTH);
    sz := MAX_COMPUTERNAME_LENGTH + 1;
    GetComputerName (PChar(Result), sz);
    SetLength (Result, sz);
end;

function GetFileOwner_02 (const FileName: string; var Domain, Username: string)
    : Boolean; overload;
var
    SecDescr: PSecurityDescriptor;
    SizeNeeded, SizeNeeded2: DWORD;
    OwnerSID: PSID;
    OwnerDefault: BOOL;
    OwnerName, DomainName: PChar;
    OwnerType: SID_NAME_USE;
begin
   // result := false;
    GetMem (SecDescr, 1024);
    GetMem (OwnerSID, SizeOf(PSID));
    GetMem (OwnerName, 1024);
    GetMem (DomainName, 1024);
    try
        Result := GetFileSecurity (PChar(FileName), OWNER_SECURITY_INFORMATION,
            SecDescr, 1024, SizeNeeded);
        if not Result then
            Exit;
        Result := GetSecurityDescriptorOwner (SecDescr, OwnerSID, OwnerDefault);
        if not Result then
            Exit;
        SizeNeeded := 1024;
        SizeNeeded2 := 1024;
        Result := LookupAccountSid (nil, OwnerSID, OwnerName, SizeNeeded,
            DomainName, SizeNeeded2, OwnerType);
        if not Result then
            Exit;
        Domain := DomainName;
        Username := OwnerName;
    finally
        FreeMem (SecDescr);
        FreeMem (OwnerName);
        FreeMem (DomainName);
    end;
    Result := True;
end;

function GetFileOwner_02 (const FileName: string): string; overload;
var
    Domain, User: string;
begin
    if GetFileOwner (FileName, Domain, User) then
        Result := Domain + '\' + User
    else
        Result := '<error>';
end;

function Error (Res: DWORD): string;
var
    // FErrorBufPtr: Pointer;
    // FNameBufPtr: Pointer;
    FErrorString: string;

    function CheckNetError (Res: DWORD): string;
    var
        S: string;
      // Error: EWin32Error;
    begin
        S := '';
        if (Res <> NERR_Success){ and (Res <> ERROR_MORE_DATA) } then
        begin
            S := SysAndNetErrorMessage (Res);
            S := Format ('Net Error code: %d.'#10'"%s"', [Res, S]);
        end;
        Result := S;
    end;

begin
    FErrorString := CheckNetError (Res);
end;

function GetUserSID_02 (Domain, Username: string; var Sid: PSID;
    var sidType: SID_NAME_USE): Boolean; overload;
var
    pdomain: PChar;
    Size: DWORD;
    refDomainLen: DWORD;
    S: string;
begin
    if Domain <> '' then
        pdomain := PChar (Domain)
    else
        pdomain := nil;
    Size := 4096;
    refDomainLen := 0;
   // result := LookupAccountName(pdomain, pchar(userName), nil, size, nil,refDomainLen,sidType);
    S := Error (GetLastError);
    GetMem (Sid, Size);
    SetLength (Domain, refDomainLen);
    Result := LookupAccountName (pdomain, PChar(Username), Sid, Size,
        @Domain[1], refDomainLen, sidType);
end;

function GetUserSID_02 (Domain, Username: string; var Sid: PSID)
    : Boolean; overload;
var
    ignoreSidType: SID_NAME_USE;
begin
    Result := GetUserSID_02 (Domain, Username, Sid, ignoreSidType);
end;

function GetUserSID_02 (Username: string; var Sid: PSID;
    var sidType: SID_NAME_USE): Boolean; overload;
var
    Domain: string;
begin
    DivideUserName_02 (Username, Domain, Username);
    Result := GetUserSID_02 (Domain, Username, Sid, sidType);
end;

function GetUserSID_02 (Username: string; var Sid: PSID): Boolean; overload;
var
    ignoreSidType: SID_NAME_USE;
begin
    Result := GetUserSID_02 (Username, Sid, ignoreSidType);
end;

function GetUserName_02 (Sid: PSID; out Username: string): Boolean;
var
    Name: string;
    nameLen: DWORD;
    Domain: string;
    domainLen: DWORD;
    sidType: SID_NAME_USE;
begin
    nameLen := 1024;
    SetLength (name, nameLen);
    domainLen := 1024;
    SetLength (Domain, domainLen);
    Result := LookupAccountSid (nil, Sid, @name[1], nameLen, @Domain[1],
        domainLen, sidType);
    if Result then
    begin
        SetLength (name, nameLen);
        SetLength (Domain, domainLen);
        Username := Domain + '\' + name;
    end;
end;

function SetFileOwner_02 (const FileName: string;
    const Domain, Username: string): Boolean; overload;
var
    sd: PSecurityDescriptor;
    OwnerSID: PSID;
begin
    Result := GetUserSID_02 (Domain, Username, OwnerSID);
    if not Result then
        Exit;
    GetMem (sd, 1024);
    try
        Result := InitializeSecurityDescriptor (sd,
            SECURITY_DESCRIPTOR_REVISION);
        Result := Result and SetSecurityDescriptorOwner (sd, OwnerSID,
            True{ ? });
        Result := Result and SetFileSecurity (PChar(FileName),
            OWNER_SECURITY_INFORMATION, sd);
    finally
        FreeMem (sd);
    end;
end;

function SetFileOwner_02 (const FileName: string; Username: string)
    : Boolean; overload;
var
    Domain: string;
begin
    DivideUserName_02 (Username, Domain, Username);
    Result := SetFileOwner_02 (FileName, Domain, Username);
end;

end.
