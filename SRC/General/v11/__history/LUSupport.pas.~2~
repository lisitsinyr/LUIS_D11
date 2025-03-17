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
   Windows,
   SysUtils,
   IniFiles,
   Registry,
   //DateUtil,
   ShlObj,
   ActiveX,
   ComObj,
   Winsock,
   ShellApi,
   //graphics,

   LUWNet, LMErrLU, LmErrText,

   LUStrUtils,LUVersion,
   U36;

function GetCPUSpeed: DWORD;

{ Работа со словами }
function WordCountNew(const S: string; const WordDelims: TCharSet): Integer;
function WordPositionNew(const N: Integer; const S: string;
                         const WordDelims: TCharSet): Integer;
function ExtractWordNew(N: Integer; const S: string;
                        const WordDelims: TCharSet): string;
function ExtractWordDelimNew(N: Integer; const S: string;
                           const WordDelims: TCharSet; var Delim: Char): string;
function GetParamFromString(ParamName: string; ParamValues: string;
   ParamNames: array of string; WordDelims: TCharSet): string;
function CharFromSet(C: TCharSet): Char;
procedure SetParamToString(ParamName: string; var ParamValues: string;
   ParamNames: array of string; WordDelims: TCharSet; Value: string);

{ Операционная система }
function GetParam(const ParamName,DefaultValue: string): string;
function SearchFile(const FileName,DefaultExt: string): string;
function SearchINIFile(const FileName: string): string;
function SearchEXEFile(const FileName: string): string;
function FileNameWithoutExt(const FileName: string): string;
function CheckDestFileName(const FileName,DestPath: string; NLimit: Integer): string;

function GetDirNameYYMMDD(const RootDir: string; ADate: TDateTime): string;
function GetDirNameYYMM(const RootDir: string; ADate: TDateTime): string;
function IsNT: Boolean;
function IsWinXX: Boolean;
procedure GetOSVersion (var OSVersionInfo: TOSVersionInfo);

function GetTempDir: string;

function GetEnvVar (const EnvVar: string): string;
procedure SetEnvVar (const EnvVar,Value: string);
{}
function DirectoryExists(const Name: string): Boolean;
function ForceDirectories(Dir: string): Boolean;

function GetFileDateTime(const FileName: string): TDateTime;
function GetDeltaDay(const FileName: string): TDateTime;
function GetFileSize(const FileName: string): Integer;
procedure FileLink(const FileName, Arg, DisplayName, Folder: string);
Function CreateFileLink(const FileName, Arg, WorkPath, IconFile, Name, DestPath: string): string;
function FileDelete(const FileName: string): Boolean;
function DirectoryDelete(const DirectoryName: string): Boolean;
function FileCopy (const FileName,DestPathName: string; Overwrite: Boolean):Boolean;
function FileMove (const FileName,DestPathName: string):Boolean;
function File2File (const FileNameS,FileNameD: string; Overwrite: Boolean): Boolean;
function BacCopy (const APathSource,APathDest: string; CheckSize,Log: Boolean; Delta: Integer): Boolean;
function BacCopyS (const APathSource,APathDest: string; CheckSize,Log: Boolean; Delta: Integer): Boolean;
function CheckFile (const APathSource,APathDest: string; Delete,Log: Boolean): Boolean;
procedure CorectFile(const FileName: string; Off: DWORD; Len: Integer; var AData);
{}
function GetINIFileName (const FileName: string): string;
procedure SetKeyReg (const P1,P2,Name,Format,Value: string);
function GetKeyReg (const P1,P2,Name,Format: string): string;
function SaveRegToFile(const FileName,RootKey,Key: string): Boolean;
procedure SetKeyIni (const FileName, GroupName, ParamName, Value: string);
function GetKeyIni (const FileName, GroupName, ParamName: string): string;
{}
function Dos2Win(const s: string): string;
function Win2Dos(const s: string): string;
function Stepen (const a,b: Double): Double;
function DateTimeStr(TimeOnly: Boolean) : string;
{=======================================================================}
function LoadDLL(NameDll: string; var HandleDLL: HModule): Boolean;
function UnLoadDLL(HandleDLL: HModule): Boolean;
function GetFunc(HandleDll: HModule; NameFunc: String; var AddFunc: Pointer): Boolean;
function ErrorString(Error: DWORD): string;
function LastErrorString: string;
{=======================================================================}
function TrimChar(const S: string; C: Char): string;
function TrimCharLeft(const S: string; C: Char): string;
function TrimCharRight(const S: string; C: Char): string;
{=======================================================================}
function GetFolderCU(const AFolderName: string): string;
function GetFolderLM(const AFolderName: string): string;
{=======================================================================}
(*
procedure RescaleImage(Source, Target: TBitmap; aThumbSize: Integer);
*)

function GetLocalIP: string;

function ProgramVersion: string;

function GetFileOwner (FileName: string; var Domain, Username: string): Boolean;
function SetFileOwner (FileName: string; const Domain, Username: string): Boolean;

function SetFileOwner_02(const fileName: string; const domain, username: string): boolean; overload;
function SetFileOwner_02(const fileName: string; userName: string): boolean; overload;

implementation

uses
   LUExec;

const
   RootKeyHKLM = HKEY_LOCAL_MACHINE;
   RootKeyHKCU = HKEY_CURRENT_USER;

type
   PTOKEN_USER = ^TOKEN_USER;
   _TOKEN_USER = record
      User : TSidAndAttributes;
   end;
   TOKEN_USER = _TOKEN_USER;

{ WordCountNew }

function WordCountNew(const S: string; const WordDelims: TCharSet): Integer;
var
   SLen, i: Cardinal;
begin
   Result := 0;
   SLen := Length(S);
   if SLen > 0 then begin
      i := 1;
      while (i <= SLen) do begin
         if (S[I] in WordDelims) then Inc(Result);
         Inc(i);
      end;
      Inc(Result);
   end;
end;

{ WordPositionNew }

function WordPositionNew(const N: Integer; const S: string; const WordDelims: TCharSet): Integer;
var
   SLen, Count, I: Integer;
begin
   SLen := Length(S);
   I := 0;
   if SLen > 0 then begin
      Count := 1;
      i := 1;
      while (I <= SLen) and (Count <> N) do begin
         if (S[I] in WordDelims) then Inc(Count);
         if (S[I] in WordDelims) then Inc(i);
         if Count <> N then
            while (I <= SLen) and not (S[I] in WordDelims) do Inc(I);
      end;
   end;
   Result := i;
end;

{ ExtractWordNew }

function ExtractWordNew(N: Integer; const S: string; const WordDelims: TCharSet): string;
var
   SLen, I, Len: Integer;
begin
   Len := 0;
   SLen := Length(S);
   if SLen > 0 then begin
      I := WordPositionNew(N, S, WordDelims);
      if I > 0 then begin
         { find the end of the current word }
         while (I <= SLen) and not(S[I] in WordDelims) do begin
            { add the I'th character to result }
            Inc(Len);
            SetLength(Result, Len);
            Result[Len] := S[I];
            Inc(I);
         end;
      end;
   end;
   SetLength(Result, Len);
end;

{ ExtractWordNew }

function ExtractWordDelimNew(N: Integer; const S: string; const WordDelims: TCharSet; var Delim: Char): string;
var
   SLen, I, Len: Integer;
begin
   Len := 0;
   SLen := Length(S);
   if SLen > 0 then begin
      I := WordPositionNew(N, S, WordDelims);
      //Pos := I;
      if I > 0 then begin
         { find the end of the current word }
         while (I <= SLen) and not(S[I] in WordDelims) do begin
            { add the I'th character to result }
            Inc(Len);
            SetLength(Result, Len);
            Result[Len] := S[I];
            Inc(I);
         end;
         Delim := S[I];
      end;
   end;
   SetLength(Result, Len);
end;

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
   OSVersionInfo.dwOSVersionInfoSize := SizeOf(OSVersionInfo);
   GetVersionEx(OSVersionInfo);
end;

{ FileUtils }

{ DirectoryExists}

function DirectoryExists(const Name: string): Boolean;
var
  Code: Integer;
begin
  Code := GetFileAttributes(PChar(Name));
  Result := (Code <> -1) and (FILE_ATTRIBUTE_DIRECTORY and Code <> 0);
end;

{ ForceDirectories }
const
   SCannotCreateDir: string = 'Unable to create directory';

function ForceDirectories(Dir: string): Boolean;
begin
  Result := True;
  if Length(Dir) = 0 then
    raise Exception.CreateRes(@SCannotCreateDir);
  Dir := ExcludeTrailingBackslash(Dir);
  if (Length(Dir) < 3) or DirectoryExists(Dir)
    or (ExtractFilePath(Dir) = Dir) then Exit; // avoid 'xyz:\' problem.
  Result := ForceDirectories(ExtractFilePath(Dir)) and CreateDir(Dir);
end;

{ FileLink }

const
   IID_IPersistFile: TGUID = (
      D1:$0000010B;D2:$0000;D3:$0000;D4:($C0,$00,$00,$00,$00,$00,$00,$46));

procedure FileLink(const FileName, Arg, DisplayName, Folder: string);
var
  ShellLink: IShellLink;
  PersistFile: IPersistFile;
  (*
  ItemIDList: PItemIDList;
  FileDestPath: array[0..MAX_PATH] of Char;
  *)
  FileDestPath: string;
  FileNameW: array[0..MAX_PATH] of WideChar;
begin
  CoInitialize(nil);
  try
    OleCheck(CoCreateInstance(CLSID_ShellLink, nil, CLSCTX_SERVER, IID_IShellLinkA, ShellLink));
    try
      OleCheck(ShellLink.QueryInterface(IID_IPersistFile, PersistFile));
      try
        (*
        OleCheck(SHGetSpecialFolderLocation(0, Folder, ItemIDList));
        SHGetPathFromIDList(ItemIDList, FileDestPath);
        StrCat(FileDestPath, PChar('\' + DisplayName + LinkExt));
        *)
        FileDestPath := Folder+'\' + DisplayName + '.lnk';
        ShellLink.SetPath(PChar(FileName));
        ShellLink.SetIconLocation(PChar(FileName), 0);
        ShellLink.SetWorkingDirectory(PChar(ExtractFilePath(FileName)));
        ShellLink.SetArguments(PChar(Arg));
        MultiByteToWideChar(CP_ACP, 0, PChar(FileDestPath), -1, FileNameW, MAX_PATH);
        OleCheck(PersistFile.Save(FileNameW, True));
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

Function CreateFileLink(const FileName, Arg, WorkPath, IconFile, Name, DestPath: string): string;
var
   LShellLink: IShellLink;
   LPersistFile: IPersistFile;
   LFileDestPath: string;
   LFileNameW: array[0..MAX_PATH] of WideChar;
   LDescription: string;
   LFileExt: string;
   //LFileNames: array[0..MAX_PATH] of WideChar;
   //LFileNameS: WideString;
   LFileNameS: string;
   //LVersionInfo: TVersionInfo;
begin
   Result := '';
   CoInitialize(nil);
   try
      OleCheck(CoCreateInstance(CLSID_ShellLink, nil, CLSCTX_SERVER, IID_IShellLinkA, LShellLink));
      try
         OleCheck(LShellLink.QueryInterface(IID_IPersistFile, LPersistFile));
         try
            //LVersionInfo := TVersionInfo.Create(nil);
            //try
            //   LVersionInfo.FileName := FileName;
            //except
            //end;
            LFileExt := ExtractFileExt(FileName);
            if (UpperCase(LFileExt) = '.BAT') then begin
               if IsNT then LFileDestPath := DestPath+'\' + Name + '.lnk'
                       else LFileDestPath := DestPath+'\' + Name + '.pif';
               end
            else
            if (UpperCase(LFileExt) = '.EXE') then begin
               if IsNT then LFileDestPath := DestPath+'\' + Name + '.lnk'
                       else LFileDestPath := DestPath+'\' + Name + '.pif';
               end
            else begin
               if IsNT then LFileDestPath := DestPath+'\' + Name + '.lnk'
                       else LFileDestPath := DestPath+'\' + Name + '.pif';
            end;

            LShellLink.SetPath(PChar(FileName));
            LShellLink.SetIconLocation(PChar(IconFile), 0);
            LShellLink.SetWorkingDirectory(PChar(WorkPath));
            LShellLink.SetArguments(PChar(Arg));
            LShellLink.SetDescription(PChar(LDescription));
            MultiByteToWideChar(CP_ACP, 0, PChar(LFileDestPath), -1, LFileNameW, MAX_PATH);

            //LPersistFile := LShellLink as IPersistFile;

            OleCheck(LPersistFile.Save(LFileNameW, True));

            if IsNT then begin
               SetLength(LFileNameS, MAX_PATH*2+1);
               OleCheck(LPersistFile.GetCurFile(PWideChar(LFileNameS)));
               Result := WideCharToStr(PWideChar(LFileNameS),0);
               end
            else begin
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

function GetFileDateTime(const FileName: string): TDateTime;
var
   FileHandle : Integer;
begin
   Result := 0;
   if FileExists(FileName) then begin
      FileHandle := FileOpen(FileName, fmShareDenyRead);
      Result := FileDateToDateTime(FileGetDate(FileHandle));
      FileClose(FileHandle);
   end;
end;

{ GetDeltaDay }

function GetDeltaDay(const FileName: string): TDateTime;
var
   LFileDate: TDateTime;
begin
   LFileDate := Round(GetFileDateTime(FileName));
   Result := Date - LFileDate;
end;

{ GetFileSize }

function GetFileSize(const FileName: string): Integer;
var
   F: File of Byte;
begin
   Result := 0;
   if FileExists(FileName) then begin
      try
         AssignFile(F, FileName);
         Reset(F);
         Result := FileSize(F);
         CloseFile(F);
      except
         Result := 0;
      end;
   end;
end;

{ FileDelete }

function FileDelete(const FileName: string): Boolean;
begin
   try
      { Clear ReadOnly }
      FileSetAttr(FileName, FileGetAttr(FileName) and (faReadOnly xor $FF));
      if FileExists(FileName) then SysUtils.DeleteFile(FileName);
      Result := True;
   except
      Result := False;
   end;
end;

{ DirectoryDelete }

function DirectoryDelete(const DirectoryName: string): Boolean;
begin
   try
      if DirectoryExists(DirectoryName) then SysUtils.RemoveDir(DirectoryName);
      Result := True;
   except
      Result := False;
   end;
end;

{ File2File }

function File2File (const FileNameS,FileNameD: string; Overwrite: Boolean): Boolean;
var
   FNS,FND : string;
   PNS,PND : string;
begin
   PNS := ExtractFilePath(FileNameS);
   PND := ExtractFilePath(FileNameD);
   FNS := FileNameS;
   FND := FileNameD;

   try
      if not DirectoryExists(PND) then ForceDirectories(PND);
      if Windows.CopyFile(PChar(FNS), PChar(FND), LongBool(not Overwrite)) then begin
         { Clear ReadOnly }
         FileSetAttr(FND, FileGetAttr(FND) and (faReadOnly xor $FF));
         Result := True;
         end
      else begin
         Result := False; // Error Copy!
      end;
   except
      Result := False; // Error Copy!
   end;
end;

{ FileCopy }

function FileCopy (const FileName,DestPathName: string; Overwrite: Boolean): Boolean;
var
   FNS,FND : string;
   LDestPathName: string;
begin
   if Trim(DestPathName) = '' then
      LDestPathName := GetCurrentDir
   else
      LDestPathName := ExpandFileName(DestPathName);
   FNS := FileName;
   FND := IncludeTrailingBackslash(LDestPathName)+ExtractFileName(FileName);
   { New }
   Result := File2File(FNS, FND, Overwrite);
(* Old
   try
      if not DirectoryExists(LDestPathName) then ForceDirectories (LDestPathName);
      if Windows.CopyFile(PChar(FNS), PChar(FND), LongBool(not Overwrite)) then begin
         { Clear ReadOnly }
         FileSetAttr(FND, FileGetAttr(FND) and (faReadOnly xor $FF));
         Result := True;
         end
      else begin
         Result := False; // Error Copy!
      end;
   except
      Result := False; // Error Copy!
   end;
*)
end;

{ FileMove }

function FileMove (const FileName,DestPathName: string): Boolean;
begin
   { Clear ReadOnly }
   FileSetAttr(FileName, FileGetAttr(FileName) and (faReadOnly xor $FF));
   Result := FileCopy(FileName,DestPathName,True);
   if Result then Result := FileDelete (FileName);
end;

{ FileNameWithoutExt }

function FileNameWithoutExt(const FileName: string): string;
var
   LExt: string;
   LFileName: string;
begin
   LExt := ExtractFileExt(FileName);
   LFileName := ExtractFileName(FileName);
   if LExt <> '' then
      Result := Copy(LFileName,1,Pos(LExt,LFileName)-1)
   else
      Result := LFileName;
end;

{ CheckDestFileName }

function CheckDestFileName(const FileName,DestPath: string; NLimit: Integer): string;
var
   LFileName: string;
   LDirName: string;
   LPathName: string;
   i: Integer;
   LN: Integer;
begin
   LN := Length(IntToStr(NLimit));
   LFileName := ExtractFileName(FileName);
   LDirName := DestPath;
   LPathName := IncludeTrailingBackslash(LDirName)+FileNameWithoutExt(LFileName)+
                ExtractFileExt(LFileName);
   if (FileExists(LPathName)) then begin
      i := 0;
      while (FileExists(LPathName)) and (i < NLimit) do begin
         Inc(i);
         LPathName := IncludeTrailingBackslash(LDirName)+FileNameWithoutExt(LFileName)+
                      '~'+AddChar('0',IntToStr(i),LN)+
                      ExtractFileExt(LFileName);
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
  PriorityClass := GetPriorityClass(GetCurrentProcess);
  Priority := GetThreadPriority(GetCurrentThread);

  SetPriorityClass(GetCurrentProcess, REALTIME_PRIORITY_CLASS);
  SetThreadPriority(GetCurrentThread, THREAD_PRIORITY_TIME_CRITICAL);

  Sleep(10);
  asm
    dw  310Fh // rdtsc
    mov TimerLo, eax
    mov TimerHi, edx
  end;
  Sleep(DelayTime);
  asm
    dw  310Fh // rdtsc
    sub eax, TimerLo
    sbb edx, TimerHi
    mov TimerLo, eax
    mov TimerHi, edx
  end;

  SetThreadPriority(GetCurrentThread, Priority);
  SetPriorityClass(GetCurrentProcess, PriorityClass);

  Result := Trunc(TimerLo / (1000.0 * DelayTime));
end;

{ GetDirNameYYMMDD }

function GetDirNameYYMMDD(const RootDir: string; ADate: TDateTime): string;
var
   YY, MM, DD: Word;
   YYs, MMs, DDs: string[4];
begin
   DecodeDate(ADate, YY, MM, DD);
   YYS := AddChar('0',IntToStr(YY),2);
   MMS := AddChar('0',IntToStr(MM),2);
   DDS := AddChar('0',IntToStr(DD),2);
   Result := Format('%s%s\%s\%s', [IncludeTrailingBackslash(RootDir),YYs,MMs,DDs]);
end;

{ GetDirNameYYMM }

function GetDirNameYYMM(const RootDir: string; ADate: TDateTime): string;
var
   YY, MM, DD: Word;
   YYs, MMs, DDs: string[4];
begin
   DecodeDate(ADate, YY, MM, DD);
   YYS := AddChar('0',IntToStr(YY),2);
   MMS := AddChar('0',IntToStr(MM),2);
   DDS := AddChar('0',IntToStr(DD),2);
   Result := Format('%s%s\%s', [IncludeTrailingBackslash(RootDir),YYs,MMs]);
end;

{ GetTempDir }

function GetTempDir: string;
var
   pc: pchar;
begin
   pc := StrAlloc(256);
   GetTempPath(256, pc);
   Result := StrPas(pc);
   StrDispose(pc);
end;

{ GetEnvVar }

function GetEnvVar (const EnvVar: string): string;
var
   BytesNeeded: DWord;
   buffer: array [0..255] of char;
begin
   Result := '';
   BytesNeeded := GetEnvironmentVariable (PChar(EnvVar), nil, 0);
   if bytesNeeded > 0 then begin
      SetLength (Result, bytesNeeded);
      GetEnvironmentVariable (PChar(EnvVar), Buffer, BytesNeeded);
      Result := StrPas(Buffer);
   end;
end;

procedure SetEnvVar (const EnvVar,Value: string);
begin
   SetEnvironmentVariable(PChar(EnvVar), PChar(Value));
end;

{ SetKeyReg }

procedure SetKeyReg (const P1,P2,Name,Format,Value: string);
var
   Reg : TRegistry;
begin
   Reg := TRegistry.Create;
   try
      if UpperCase(P1) = 'HKLM' then Reg.RootKey := HKEY_LOCAL_MACHINE
      else
      if UpperCase(P1) = 'HKCU' then Reg.RootKey := HKEY_CURRENT_USER;
      Reg.OpenKey(P2, True);
      if UpperCase(Format) = 'B' then begin
         if UpperCase(Trim(Value)) = 'TRUE' then Reg.WriteBool(Name, True)
                                         else Reg.WriteBool(Name, False);
         end
      else
      if UpperCase(Format) = 'S'  then Reg.WriteString(Name, Value)
      else
      if UpperCase(Format) = 'SE' then Reg.WriteExpandString(Name, Value)
      else
      if UpperCase(Format) = 'I'  then Reg.WriteInteger(Name, StrToInt(Value))
      else
      if UpperCase(Format) = 'F'  then Reg.WriteFloat(Name, StrToFloat(Value))
      else
      if UpperCase(Format) = 'D'  then Reg.WriteDate(Name, StrToDate(Value))
      else
      if UpperCase(Format) = 'DT' then Reg.WriteDateTime(Name, StrToDateTime(Value))
      else
      if UpperCase(Format) = 'T'  then Reg.WriteTime(Name, StrToTime(Value));
   except
   end;
   Reg.Free;
end;

{ SaveRegToFile }

function SaveRegToFile(const FileName,RootKey,Key: string): Boolean;
var
   LWorkDir: string;
   LProgramName: string;
   LParamStr: string;
   LStatus: Cardinal;
begin
   Result := False;
   LWorkDir := ExtractFileDir(FileName);
   LProgramName := 'regedit.exe';
   LParamStr := '';
   if UpperCase(RootKey) = 'HKLM' then
      LParamStr := '/ea'+' '+FileName+' '+'HKEY_LOCAL_MACHINE\'+Key
   else
   if UpperCase(RootKey) = 'HKCU' then
      LParamStr := '/ea'+' "'+FileName+'" '+'"HKEY_CURRENT_USER\'+Key+'"';
   if LParamStr <> '' then begin
      Result := ExecuteAll(LProgramName, LParamStr, LWorkDir, True, SW_HIDE, LStatus);
   end;
end;

{ GetKeyReg }

function GetKeyReg (const P1,P2,Name,Format: string): string;
var
   Reg : TRegistry;
begin
   Result := '';
   Reg := TRegistry.Create;
   try
      if UpperCase(P1) = 'HKLM' then Reg.RootKey := HKEY_LOCAL_MACHINE
      else
      if UpperCase(P1) = 'HKCU' then Reg.RootKey := HKEY_CURRENT_USER
      else
      if UpperCase(P1) = 'HKCR' then Reg.RootKey := HKEY_CLASSES_ROOT;
      Reg.OpenKeyReadOnly(P2);
      if UpperCase(Format) = 'B' then begin
         if Reg.ReadBool(Name) then Result := 'TRUE'
                               else Result := 'FALSE';
         end
      else
      if UpperCase(Format) = 'S'  then Result := Reg.ReadString(Name)
      else
      if UpperCase(Format) = 'SE' then Result := Reg.ReadString(Name)
      else
      if UpperCase(Format) = 'I'  then Result := IntToStr(Reg.ReadInteger(Name))
      else
      if UpperCase(Format) = 'F'  then Result := FloatToStr(Reg.ReadFloat(Name))
      else
      if UpperCase(Format) = 'D'  then Result := DateToStr(Reg.ReadDate(Name))
      else
      if UpperCase(Format) = 'DT' then Result := DateTimeToStr(Reg.ReadDateTime(Name))
      else
      if UpperCase(Format) = 'T'  then Result := TimeToStr(Reg.ReadTime(Name));
   except
   end;
   Reg.Free;
end;

{ GetParam }

function GetParam(const ParamName,DefaultValue: string): string;
const
   Switch = ['-', '/'];
var
   LParamValue: string;
begin
   Result := DefaultValue;
   if FindCmdLineSwitch(ParamName, Switch, True) then begin
      LParamValue := GetCmdLineArg(ParamName, Switch);
      if LParamValue <> '' then Result := LParamValue;
   end;
end;

{ GetINIFileName }

function GetINIFileName (const FileName: string): string;
var
   WinDir : string;
   P,F,E : string;
   s: string;
   //buffer: array [0..255] of char;
begin
   Result := FileName;
   P := ExtractFileDir (FileName);
   F := ExtractFileName (FileName);
   E := ExtractFileExt (FileName);
   if E = '' then F := F+'.ini';
   if P = '' then begin
      //GetWindowsDirectory(buffer, SizeOf(buffer));
      //s := GetCurrentDir+';'+buffer;
      WinDir := GetEnvVar ('WinDir');
      s := GetCurrentDir+';'+WinDir;
      Result := FileSearch(F, S);
      if Result = '' then Result := IncludeTrailingBackslash(WinDir)+F;
   end;
   Result := ExpandFileName(Result);
end;

{ SetKeyIni }

procedure SetKeyIni (const FileName, GroupName, ParamName, Value: string);
var
   INIFile : TINIFile;
   LFileName: string;

begin
   LFileName := GetINIFileName(FileName);
   if not FileExists(LFileName) then
      LFileName := ExpandFileName(ExtractFileName(FileName));
   INIFile := TINIFile.Create(LFileName);
   INIFile.WriteString(GroupName, ParamName, Value);
   INIFile.Free;
end;

{ GetKeyIni }

function GetKeyIni (const FileName, GroupName, ParamName: string): string;
var
   INIFile : TINIFile;
   LFileName: string;

begin
   LFileName := GetINIFileName(FileName);
   if FileExists(LFileName) then begin
      INIFile := TINIFile.Create(LFileName);
      Result := INIFile.ReadString(GroupName, ParamName, '');
      INIFile.Free;
   end;
end;

{ BacCopy }

function BacCopy (const APathSource,APathDest: string; CheckSize,Log: Boolean; Delta: Integer): Boolean;
var
   PS: string;
   PD: string;
   N: string;
   E: string;
   I: Integer;
   {}
   TS: TSearchRec;
   ResTS : Integer;
   FNS: string;
   DTS: TDateTime;
   InfoS : string;
   {}
   TD: TSearchRec;
   FND: string;
   DTD: TDateTime;
   InfoD : string;
   FC: Boolean;
begin
   PS := ExtractFilePath(ExpandFileName(APathSource));
   PD := ExpandFileName(APathDest);
   N := ExtractFileName(APathSource);
   E := ExtractFileExt(APathSource);
   WriteLN (APathSource,' -> ',APathDest,
      ' (CheckSize=', CheckSize, ')',
      ' (Log=', Log, ')',
      ' (Delta=', Delta, ')'
      );
   Result := True;
   try
      ForceDirectories (APathDest);
      FillChar(TS, SizeOf(TS), $00);
      ResTS := FindFirst(IncludeTrailingBackslash(PS)+N, faAnyFile, TS);
      I := 0;
      while (ResTS = 0) do begin
         if (TS.Attr and faDirectory) = 0 then begin
            { It is File }
            {}
            FNS := IncludeTrailingBackslash(PS)+TS.Name;
            DTS := FileDateToDateTime(TS.Time);
            FND := IncludeTrailingBackslash(PD)+TS.Name;
            if not FileExists (FND) then begin
               InfoD := Format('%-28s  ', ['----------------------------']);
               FC := True;
               InfoD := InfoD + ' N';
               end
            else begin
               FillChar (TD, SizeOf (TD), $00);
               FindFirst (FND, faAnyFile, TD);
               SysUtils.FindClose (TD);
               DTD := FileDateToDateTime (TD.Time);
               InfoD := Format ('%17s %10d  ', [DateTimeToStr(DTD), TD.Size]);
               FileSetAttr(FND, FileGetAttr(FND) and (faReadOnly xor $FF));
               FC := False;
               if ((TS.Time-TD.Time) >= Delta)          then begin
                  FC := True; InfoD := InfoD + ' T';
               end;
               if CheckSize and (TS.Size <> TD.Size) then begin FC := True; InfoD := InfoD + ' S'; end;
            end;

            if FC then begin
               Inc(I);
               InfoS := Format('%3d %-12s %17s %10d',[I,TS.Name,DateTimeToStr(DTS),TS.Size]);
               if Log then WriteLN(InfoS+' '+InfoD);
               if not Windows.CopyFile(PChar(FNS), PChar(FND), LongBool(False)) then begin
                  Result := False;
                  if Log then WriteLN('Error copy!');
               end;
            end;
         end;
         ResTS := FindNext(TS);
      end;
      SysUtils.FindClose(TS);
   except
      Result := False;
   end;
end;

{ BacCopyS }

function BacCopyS (const APathSource,APathDest: string; CheckSize,Log: Boolean; Delta: Integer): Boolean;
var
   PS: string;
   PD: string;
   N: string;
   E: string;
   I: Integer;


   procedure Scan (APS,APD,AN: string);
   var
      LTS: TSearchRec;
      LResTS : Integer;
      LFND: string;
      LFNS: string;
      LDTS: TDateTime;
      LTD: TSearchRec;
      LDTD: TDateTime;
      LInfoD : string;
      LInfoS : string;
      LFC: Boolean;
   begin
      FillChar(LTS, SizeOf(LTS), $00);
      LResTS := FindFirst(IncludeTrailingBackslash(APS)+AN, faAnyFile, LTS);
      while (LResTS = 0) do begin
         if (LTS.Attr and faDirectory) = 0 then begin
            { Это файл }
            LFNS := IncludeTrailingBackslash(APS)+LTS.Name;
            LDTS := FileDateToDateTime(LTS.Time);

            LFND := IncludeTrailingBackslash(APD)+LTS.Name;
            if not FileExists (LFND) then begin
               LInfoD := Format('%-28s  ', ['----------------------------']);
               LInfoD := LInfoD + ' N';
               LFC := True;
               end
            else begin
               FillChar (LTD, SizeOf (LTD), $00);
               FindFirst (LFND, faAnyFile, LTD);
               SysUtils.FindClose (LTD);
               LDTD := FileDateToDateTime (LTD.Time);
               LInfoD := Format ('%17s %10d  ', [DateTimeToStr(LDTD), LTD.Size]);
               FileSetAttr(LFND, FileGetAttr(LFND) and (faReadOnly xor $FF));
               LFC := False;
               if ((LTS.Time-LTD.Time) >= Delta)          then begin
                  LInfoD := LInfoD + ' T';
                  LFC := True;
               end;
               if CheckSize and (LTS.Size <> LTD.Size) then begin
                  LInfoD := LInfoD + ' S';
                  LFC := True;
               end;
            end;
            if LFC then begin
               Inc(I);
               LInfoS := Format('%3d %-12s %17s %10d',[I,LTS.Name,DateTimeToStr(LDTS),LTS.Size]);
               if Log then WriteLN(LInfoS+' '+LInfoD);
               if not Windows.CopyFile(PChar(LFNS), PChar(LFND), LongBool(False)) then begin
                  if Log then WriteLN('Error copy!');
               end;
            end;
            end
         else begin
            { Это каталог }
            if (LTS.Name <> '.') and (LTS.Name <> '..') then begin
               ForceDirectories (IncludeTrailingBackslash(APD)+LTS.Name);
               Scan (IncludeTrailingBackslash(APS)+LTS.Name, IncludeTrailingBackslash(APD)+LTS.Name, AN);
            end;
         end;
         LResTS := FindNext(LTS);
      end;
      SysUtils.FindClose(LTS);
   end;

   procedure ScanFile (APS,APD,AN: string);
   var
      LTS: TSearchRec;
      LResTS : Integer;
      LFND: string;
      LFNS: string;
      LDTS: TDateTime;
      LTD: TSearchRec;
      LDTD: TDateTime;
      LInfoD : string;
      LInfoS : string;
      LFC: Boolean;
   begin
      FillChar(LTS, SizeOf(LTS), $00);
      LResTS := FindFirst(IncludeTrailingBackslash(APS)+AN, faAnyFile, LTS);
      while (LResTS = 0) do begin
         if (LTS.Attr and faDirectory) = 0 then begin
            { Это файл }
            LFNS := IncludeTrailingBackslash(APS)+LTS.Name;
            LDTS := FileDateToDateTime(LTS.Time);

            LFND := IncludeTrailingBackslash(APD)+LTS.Name;
            if not FileExists (LFND) then begin
               LInfoD := Format('%-28s  ', ['----------------------------']);
               LInfoD := LInfoD + ' N';
               LFC := True;
               end
            else begin
               FillChar (LTD, SizeOf (LTD), $00);
               FindFirst (LFND, faAnyFile, LTD);
               SysUtils.FindClose (LTD);
               LDTD := FileDateToDateTime (LTD.Time);
               LInfoD := Format ('%17s %10d  ', [DateTimeToStr(LDTD), LTD.Size]);
               FileSetAttr(LFND, FileGetAttr(LFND) and (faReadOnly xor $FF));
               LFC := False;
               if ((LTS.Time-LTD.Time) >= Delta)          then begin
                  LInfoD := LInfoD + ' T';
                  LFC := True;
               end;
               if CheckSize and (LTS.Size <> LTD.Size) then begin
                  LInfoD := LInfoD + ' S';
                  LFC := True;
               end;
            end;
            if LFC then begin
               ForceDirectories (IncludeTrailingBackslash(APD));
               Inc(I);
               LInfoS := Format('%3d %-12s %17s %10d',[I,LTS.Name,DateTimeToStr(LDTS),LTS.Size]);
               if Log then WriteLN(LInfoS+' '+LInfoD);
               if not Windows.CopyFile(PChar(LFNS), PChar(LFND), LongBool(False)) then begin
                  if Log then WriteLN('Error copy!');
               end;
            end;
            end
         else begin
            { Это каталог }
         end;
         LResTS := FindNext(LTS);
      end;
      SysUtils.FindClose(LTS);
   end;

   procedure ScanDir(APS, APD, AN: string);
   var
      LSR: TSearchRec;
      LFound: Integer;
   begin
      LFound := FindFirst(IncludeTrailingBackslash(APS)+'*.*', faAnyFile, LSR);
      while (LFound = 0) do begin
         if (LSR.Name <> '.') and (LSR.Name <> '..') then begin
            if (LSR.Attr and faDirectory) <> 0 then begin
               { It is Directory }
               if AN <> '' then
                  ScanFile(IncludeTrailingBackslash(APS)+LSR.Name,
                           IncludeTrailingBackslash(APD)+LSR.Name, AN);
               ScanDir(IncludeTrailingBackslash(APS)+LSR.Name,
                       IncludeTrailingBackslash(APD)+LSR.Name, AN);
            end;
         end;
         LFound := FindNext(LSR);
      end;
      SysUtils.FindClose(LSR);
   end;

begin
   PS := ExtractFilePath(ExpandFileName(APathSource));
   PD := ExpandFileName(APathDest);
   N := ExtractFileName(APathSource);
   E := ExtractFileExt(APathSource);
   WriteLN (PS,' -> ',PD, ' (CheckSize=', CheckSize, ')', ' (Log=', Log, ')', ' (Delta=', Delta, ')');
   ForceDirectories (PD);
   I := 0;
   ScanDir (PS, PD, N);
   if N <> '' then ScanFile(IncludeTrailingBackslash(PS), IncludeTrailingBackslash(PD), N);
   Result := True;
end;

{ CheckFile }

function CheckFile (const APathSource,APathDest: string; Delete,Log: Boolean): Boolean;
var
   PS: string;
   PD: string;
   N: string;
   E: string;
   I: Integer;

   procedure ScanFile (APS,APD,AN: string);
   var
      LTS: TSearchRec;
      LResTS : Integer;
      LFND: string;
      LFNS: string;
      LInfoS : string;
   begin
      FillChar(LTS, SizeOf(LTS), $00);
      LResTS := FindFirst(IncludeTrailingBackslash(APS)+AN, faAnyFile, LTS);
      while (LResTS = 0) do begin
         if (LTS.Attr and faDirectory) = 0 then begin
            { Это файл }
            LFNS := IncludeTrailingBackslash(APS)+LTS.Name;
            FileDateToDateTime(LTS.Time);
            LFND := IncludeTrailingBackslash(APD)+LTS.Name;
            if not FileExists (LFND) then begin
               Inc(I);
               LInfoS := Format('%3d %-12s %10d',[I,LTS.Name,LTS.Size]);
               if Log then WriteLN(LInfoS);
               if Delete then FileDelete(LFNS);
            end;
         end;
         LResTS := FindNext(LTS);
      end;
      SysUtils.FindClose(LTS);
   end;

   procedure ScanDir(APS, APD, AN: string);
   var
      LSR: TSearchRec;
      LFound: Integer;
   begin
      LFound := FindFirst(IncludeTrailingBackslash(APS)+'*.*', faAnyFile, LSR);
      while (LFound = 0) do begin
         if (LSR.Name <> '.') and (LSR.Name <> '..') then begin
            if (LSR.Attr and faDirectory) <> 0 then begin
               { It is Directory }
               if AN <> '' then
                  ScanFile(IncludeTrailingBackslash(APS)+LSR.Name,
                           IncludeTrailingBackslash(APD)+LSR.Name, AN);
               ScanDir(IncludeTrailingBackslash(APS)+LSR.Name,
                       IncludeTrailingBackslash(APD)+LSR.Name, AN);
            end;
         end;
         LFound := FindNext(LSR);
      end;
      SysUtils.FindClose(LSR);
   end;

begin
   PS := ExtractFilePath(ExpandFileName(APathSource));
   PD := ExpandFileName(APathDest);
   N := ExtractFileName(APathSource);
   E := ExtractFileExt(APathSource);
   WriteLN (PS,' -> ',PD, ' (Delete=', Delete, ')', ' (Log=', Log, ')');
   I := 0;
   ScanDir (PS, PD, N);
   if N <> '' then ScanFile(IncludeTrailingBackslash(PS), IncludeTrailingBackslash(PD), N);
   Result := True;
end;

{ SearchFile }

function SearchFile(const FileName,DefaultExt: string): string;
var
   Buffer1: PChar;
   Buffer2: PChar;
begin
   Result := FileName;
   if ExtractFileDir(Result) = '' then begin
      if ExtractFileExt(Result) = '' then Result := Result + DefaultExt;
      Buffer1 := StrAlloc(255);
      if SearchPath(nil, PChar(Result), nil, 255, Buffer1, Buffer2) > 0 then
         Result := StrPas(Buffer1)
      else
         Result := '';
      StrDispose(Buffer1);
      end
   else begin
      if ExtractFileExt(Result) = '' then Result := Result + DefaultExt;
      Result := ExpandFileName(Result);
      if not FileExists(Result) then Result := '';
   end;
end;

{ SearchINIFile }

function SearchINIFile(const FileName: string): string;
begin
   Result := SearchFile(FileName, '.ini');
end;

{ SearchEXEFile }

function SearchEXEFile(const FileName: string): string;
begin
   Result := SearchFile(FileName, '.exe');
end;

{ Dos2Win }

function Dos2Win(const s: string): string;
var
   p: PChar;
begin
   p := StrAlloc(Length(s)+1);
   StrPCopy(p, s);
   OEMtoChar(p,p);
   Result := StrPas(p);
   StrDispose(p);
end;

{ Win2Dos }

function Win2Dos(const s: string): string;
var
   p: PChar;
begin
   p := StrAlloc(Length(s)+1);
   StrPCopy(p, s);
   CharToOEM(p,p);
   Result := StrPas(p);
   StrDispose(p);
end;

{ Stepen }

function Stepen (const a,b: Double): Double;
{
А если а<0, но x-чётное, то такая формула:
y:=exp(x*Ln(Abs(a)));
А если а<0, но х-нечётное, то формула такая:
y:=-exp(x*Ln(Abs(a)));
}
begin
   if b > 0 then Result := exp(a*ln(b))
            else Result := exp(a*ln(Abs(b)));
end;

{ DateTimeStr }

function DateTimeStr(TimeOnly: Boolean) : string;
var
   Today : TDateTime;
   hh,nn,ss,ms: word;
   s : string;
begin
   Today := Now;
   DecodeTime(Today,hh,nn,ss,ms);
   s := AddChar('0',IntToStr(ms),3);
   if TimeOnly then
      Result := FormatDateTime('hhmmss'+s,Today)
   else
      Result := FormatDateTime('yyyymmddmmhhmmss'+s,Today);
end;

{==================================================================}
{                                                                  }
{==================================================================}

{ LoadDLL }

function LoadDLL(NameDll: string; var HandleDLL: HModule): Boolean;
begin
   HandleDLL := LoadLibrary(PChar(NameDll));
   Result := (HandleDLL >= HINSTANCE_ERROR);
end;

{ UnLoadDLL }

function UnLoadDLL(HandleDLL: HModule): Boolean;
begin
   Result := FreeLibrary(HandleDLL);
end;

{ GetFunc }

function GetFunc(HandleDll: HModule; NameFunc: String; var AddFunc: Pointer): Boolean;
begin
   try
      AddFunc := GetProcAddress(HandleDll, PChar(NameFunc));
   except
      AddFunc := nil;
   end;
   Result := Assigned(AddFunc);
end;

{ ErrorString }

function ErrorString(Error: DWORD): string;
//var lpMsgBuf: PChar;
begin
   (*
   FormatMessage(
      FORMAT_MESSAGE_ALLOCATE_BUFFER or FORMAT_MESSAGE_FROM_SYSTEM or FORMAT_MESSAGE_IGNORE_INSERTS,
      nil, Error,
      MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
      lpMsgBuf, 0, nil);
   Result := PasStr(lpMsgBuf);
   LocalFree(lpMsgBuf);
   *)
   Result := SysErrorMessage(Error);
end;

{ LastErrorString }

function LastErrorString: string;
begin
   Result := ErrorString(GetLastError);
end;

(*
function CreateObjectProc(NameObj, NameDll: String; CurSetList: PSetList): TObject;
var
   CreateObject: TFuncTask;
   HandleDll: THandle;
begin
   Result:=nil;
   HandleDll:=LoadLibrary(PChar(NameDll));
   if HandleDll >= HINSTANCE_ERROR then begin
      @CreateObject:=GetProcAddress(HandleDll, PChar('Create'));
      if @CreateObject <> nil then
         Result:=TObject(Longint(CreateObject(NameObj, Self.vSetList, CurSetList)))
      else
         MessageDlg('DLL '+NameDll+'havn''t "Create" procedure', mtWarning, [mbOk], 0);
      end
   else
      MessageDlg('Couldn''t load DLL: '+NameDll, mtWarning, [mbOk], 0);
end;
*)

{==================================================================}
{                                                                  }
{==================================================================}

{ Param }

function GetParamFromString(ParamName: string; ParamValues: string;
   ParamNames: array of string; WordDelims: TCharSet): string;
var
   i,j: Integer;
begin
   Result := '';
   j := 0;
   for i:=Low(ParamNames) to High(ParamNames) do begin
      if UpperCase(ParamName) = UpperCase(ParamNames[i]) then begin j := i + 1; Break; end;
   end;
   if j > 0 then begin
      Result := Trim(ExtractWordNew(j, ParamValues, WordDelims));
   end;
end;

{ CharFromSet }

function CharFromSet(C: TCharSet): Char;
var
   i: Byte;
begin
   for i:=0 to 255 do begin
      if Chr(i) in C then begin Result := Chr(i); Break; end;
   end;
end;

{ SetParamToString }

procedure SetParamToString(ParamName: string; var ParamValues: string;
   ParamNames: array of string; WordDelims: TCharSet; Value: string);
var
   i,j: Integer;
   s: string;
   Stroka: string;
begin
   Stroka := ParamValues;
   s := '';
   for i:=Low(ParamNames) to High(ParamNames) do begin
      j := i+1;
      if UpperCase(ParamName) = UpperCase(ParamNames[i]) then
         s := s + Value
      else
         s := s + ExtractWordNew(j, Stroka, WordDelims);
      if i <> High(ParamNames) then s := s + CharFromSet(WordDelims);
   end;
   ParamValues := s;
end;

{ TrimChar }

function TrimChar(const S: string; C: Char): string;
var
  I, L: Integer;
begin
  L := Length(S);
  I := 1;
  while (I <= L) and (S[I] <= C) do Inc(I);
  if I > L then Result := '' else
  begin
    while S[L] <= ' ' do Dec(L);
    Result := Copy(S, I, L - I + 1);
  end;
end;

{ TrimCharLeft }

function TrimCharLeft(const S: string; C: Char): string;
var
  I, L: Integer;
begin
  L := Length(S);
  I := 1;
  while (I <= L) and (S[I] <= C) do Inc(I);
  Result := Copy(S, I, Maxint);
end;

{ TrimCharRight }

function TrimCharRight(const S: string; C: Char): string;
var
  I: Integer;
begin
  I := Length(S);
  while (I > 0) and (S[I] <= C) do Dec(I);
  Result := Copy(S, 1, I);
end;

(*
procedure RescaleImage(Source, Target: TBitmap; aThumbSize: Integer);
// if source is in at least one dimension larger than the thumb size then
// rescale source but keep aspect ratio
var
   NewWidth: Integer;
   NewHeight: Integer;
begin
   if (Source.Width > aThumbSize) or (Source.Height > aThumbSize) then begin
      if Source.Width > Source.Height then begin
         NewWidth := aThumbSize;
         NewHeight := Round(aThumbSize * Source.Height / Source.Width);
         end
      else begin
         NewHeight := aThumbSize;
         NewWidth := Round(aThumbSize * Source.Width / Source.Height);
      end;

      Target.Width := NewWidth;
      Target.Height := NewHeight;
      SetStretchBltMode(Target.Canvas.Handle, HALFTONE);
      StretchBlt(Target.Canvas.Handle, 0, 0, NewWidth, NewHeight,
         Source.Canvas.Handle, 0, 0, Source.Width, Source.Height, SRCCOPY);
      end
   else
      Target.Assign(Source);
end;
*)
(*
REGEDIT4

[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders]
"AppData"="C:\\Documents and Settings\\luis.GU\\Application Data"
"Cookies"="C:\\Documents and Settings\\luis.GU\\Cookies"
"Desktop"="C:\\Documents and Settings\\luis.GU\\Desktop"
"Favorites"="C:\\Documents and Settings\\luis.GU\\Favorites"
"NetHood"="C:\\Documents and Settings\\luis.GU\\NetHood"
"Personal"="C:\\Documents and Settings\\luis.GU\\My Documents"
"PrintHood"="C:\\Documents and Settings\\luis.GU\\PrintHood"
"Recent"="C:\\Documents and Settings\\luis.GU\\Recent"
"SendTo"="C:\\Documents and Settings\\luis.GU\\SendTo"
"Start Menu"="C:\\Documents and Settings\\luis.GU\\Start Menu"
"Templates"="C:\\Documents and Settings\\luis.GU\\Templates"
"Programs"="C:\\Documents and Settings\\luis.GU\\Start Menu\\Programs"
"Startup"="C:\\Documents and Settings\\luis.GU\\Start Menu\\Programs\\Startup"
"Local Settings"="C:\\Documents and Settings\\luis.GU\\Local Settings"
"Local AppData"="C:\\Documents and Settings\\luis.GU\\Local Settings\\Application Data"
"Cache"="C:\\Documents and Settings\\luis.GU\\Local Settings\\Temporary Internet Files"
"History"="C:\\Documents and Settings\\luis.GU\\Local Settings\\History"
"My Pictures"="C:\\Documents and Settings\\luis.GU\\My Documents\\My Pictures"
"Fonts"="C:\\WINDOWS\\Fonts"
"My Music"="C:\\Documents and Settings\\luis.GU\\My Documents\\My Music"
"Administrative Tools"="C:\\Documents and Settings\\luis.GU\\Start Menu\\Programs\\Administrative Tools"
"CD Burning"="C:\\Documents and Settings\\luis.GU\\Local Settings\\Application Data\\Microsoft\\CD Burning"
"My Video"="C:\\Documents and Settings\\luis.GU\\My Documents\\My Videos"

REGEDIT4

[HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders]
"Common AppData"="C:\\Documents and Settings\\All Users\\Application Data"
"Common Programs"="C:\\Documents and Settings\\All Users\\Start Menu\\Programs"
"Common Documents"="C:\\Documents and Settings\\All Users\\Documents"
"Common Desktop"="C:\\Documents and Settings\\All Users\\Desktop"
"Common Start Menu"="C:\\Documents and Settings\\All Users\\Start Menu"
"CommonPictures"="C:\\Documents and Settings\\All Users\\Documents\\My Pictures"
"CommonMusic"="C:\\Documents and Settings\\All Users\\Documents\\My Music"
"CommonVideo"=""
"Common Favorites"="C:\\Documents and Settings\\All Users\\Favorites"
"Common Startup"="C:\\Documents and Settings\\All Users\\Start Menu\\Programs\\Startup"
"Common Administrative Tools"="C:\\Documents and Settings\\All Users\\Start Menu\\Programs\\Administrative Tools"
"Common Templates"="C:\\Documents and Settings\\All Users\\Templates"
"Personal"="C:\\Documents and Settings\\luis.GU\\My Documents\\"

Win98

REGEDIT4

[HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders]
"Desktop"="C:\\WINDOWS\\Рабочий стол"
"Templates"="C:\\WINDOWS\\ShellNew"
"AppData"="C:\\WINDOWS\\Application Data"
"Start Menu"="C:\\WINDOWS\\Главное меню"
"Programs"="C:\\WINDOWS\\Главное меню\\Программы"
"Startup"="C:\\WINDOWS\\Главное меню\\Программы\\Автозагрузка"
"Fonts"="C:\\WINDOWS\\Fonts"
"SendTo"="C:\\WINDOWS\\SendTo"
"Recent"="C:\\WINDOWS\\Recent"
"Favorites"="C:\\WINDOWS\\Избранное"
"Cache"="C:\\WINDOWS\\Temporary Internet Files"
"Cookies"="C:\\WINDOWS\\Cookies"
"History"="C:\\WINDOWS\\History"
"NetHood"="C:\\WINDOWS\\NetHood"
"Personal"="C:\\Мои документы"
"PrintHood"="C:\\WINDOWS\\PrintHood"
"Local AppData"="C:\\WINDOWS\\Local Settings\\Application Data"
"My Pictures"="C:\\Мои документы\\Мои рисунки"
"Administrative Tools"="C:\\WINDOWS\\Главное меню\\Программы\\Администрирование"
*)
function GetFolderCU(const AFolderName: string): string;
var
   LReg: TRegistry;
   s: string;
begin
   s := 'Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders';
   LReg := TRegistry.Create;
   LReg.RootKey := RootKeyHKCU;
   if LReg.OpenKey(s, False) then begin
      Result := LReg.ReadString(AFolderName);
   end;
   LReg.CloseKey;
   LReg.Free;
end;

function GetFolderLM(const AFolderName: string): string;
var
   LReg: TRegistry;
   s: string;
begin
   s := 'SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders';
   LReg := TRegistry.Create;
   LReg.RootKey := RootKeyHKLM;
   if LReg.OpenKey(s, False) then begin
      Result := LReg.ReadString(AFolderName);
   end;
   LReg.CloseKey;
   LReg.Free;
end;

procedure CorectFile(const FileName: string; Off: DWORD; Len: Integer; var AData);
var
   F : File;
   Size, Blocks: Integer;
   Buffer: Pointer;
type
   ArrayOfByte = array[0..0] of Byte;
begin
   try
      AssignFile(F, FileName);
      Reset(F, 1);
      Size := FileSize(F);
      GetMem(Buffer, Size+1);
      if IOResult = 0 then begin
         BlockRead(F, Buffer^, Size, Blocks);
         CloseFile(F);
         AssignFile(F, FileName);
         Rewrite(F, 1);
         Move (AData, ArrayOfByte(Buffer^)[off], Len);
         BlockWrite(F, Buffer^, Size, Blocks);
         CloseFile(F);
      end;
   finally
      FreeMem(Buffer);
   end;
end;

function GetLocalIP: string;
var
   WSAData: TWSAData;
   Host: PHostEnt;
   Buf: array [0..127] of Char;
   //SockAddrIn: TSockAddrIn;
begin
   if WSAStartup ($101, WSAData) = 0 then begin
      if GetHostName(@Buf, 128) = 0 then begin
         Host := GetHostByName (@Buf);
         //Host := GetHostByName (@LocalName[1]);
         if Host <> nil then begin
            Result := iNet_ntoa(PInAddr(Host^.h_addr_list^)^);
            //SockAddrIn.sin_addr.S_addr := Longint(PLongint(Host^.h_addr_list^)^);
            //Result := iNet_ntoa(SockAddrIn.sin_addr);
         end;
      end;
      WSACleanUP;
   end;
end;

// Пример получения имени пользователя и домена под которым работает
// текущий поток или процесс

// Использовать функцию можно так :
   //chDomain:=50;
   //chUser :=50;
   //GetCurrentUserAndDomain(User,chuser,Domain,chDomain)
// Если вам необходимо получить только имя пользователя - используйте GetUserName
// Данный пример можно использовать и для определения - запущен ли процесс
// системой или пользователем.  Учетной записи Localsystem соответствует
// имя пользователя - SYSTEM и домен NT AUTORITY (лучше проверить на практике)

function GetCurrentUserAndDomain (szUser : PChar; var chUser: DWORD; szDomain :PChar; var chDomain : DWORD  ):Boolean;
var
   hToken : THandle;  cbBuf  : Cardinal;  ptiUser : PTOKEN_USER;
   snu    : SID_NAME_USE;
begin
   Result:=false;
   // Получаем маркер доступа текущего потока нашего процесса
   if not OpenThreadToken(GetCurrentThread(),TOKEN_QUERY,true,hToken) then begin
      if GetLastError()<> ERROR_NO_TOKEN then exit;
      // В случее ошибки - получаем маркер доступа нашего процесса.
      if not OpenProcessToken(GetCurrentProcess(),TOKEN_QUERY,hToken) then exit;
   end;

   // Вывываем GetTokenInformation для получения размера буфера
   if not GetTokenInformation(hToken, TokenUser, nil, 0, cbBuf) then
      if GetLastError()<> ERROR_INSUFFICIENT_BUFFER then begin
         CloseHandle(hToken);
         exit;
      end;

   if cbBuf = 0 then exit;

   // Выделяем память под буфер
   GetMem(ptiUser,cbBuf);

   // В случае удачного вызова получим указатель на TOKEN_USER
   if GetTokenInformation(hToken,TokenUser,ptiUser,cbBuf,cbBuf) then begin
      // Ищем имя пользователя и его домен по его SID
      if LookupAccountSid(nil,ptiUser.User.Sid,szUser,chUser,szDomain,chDomain,snu) then Result:=true;
   end;

   // Освобождаем ресурсы
   CloseHandle(hToken);
   FreeMem(ptiUser);
end;

function ProgramVersion: string;
var
    Ver: TVersionInfo;
begin
   Ver := TVersionInfo.Create(nil);
   Ver.FileName := ParamStr(0);
   Result := Ver.FileName+' '+Ver.FileVersion+' '+Ver.FileDate;
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
   GetMem(SecDescr, 1024);
   GetMem(OwnerSID, SizeOf(PSID));
   GetMem(OwnerName, 1024);
   GetMem(DomainName, 1024);
   try
      if not GetFileSecurity(PChar(FileName), OWNER_SECURITY_INFORMATION, SecDescr, 1024, SizeNeeded) then
         Exit;
      if not GetSecurityDescriptorOwner(SecDescr, OwnerSID, OwnerDefault) then
         Exit;
      SizeNeeded := 1024;
      SizeNeeded2 := 1024;
      if not LookupAccountSID(nil, OwnerSID, OwnerName, SizeNeeded, DomainName, SizeNeeded2, OwnerType) then
         Exit;
      Domain := DomainName;
      Username := OwnerName;
   finally
      FreeMem(SecDescr);
      FreeMem(OwnerName);
      FreeMem(DomainName);
   end;
   Result := True;
end;

{ SetFileOwner(FileName }

function SetFileOwner (FileName: string; const Domain, Username: string): Boolean;
var
   SecDescr: PSecurityDescriptor;
   SizeNeeded, SizeNeeded2: DWORD;
   OwnerSID: PSID;
   OwnerDefault: BOOL;
   OwnerName, DomainName: PChar;
   OwnerType: SID_NAME_USE;
   SecurityInformation: SECURITY_INFORMATION;
begin
   Result := False;
   GetMem(SecDescr, 1024);
   GetMem(OwnerSID, SizeOf(PSID));
   GetMem(OwnerName, 1024);
   GetMem(DomainName, 1024);
   try
      if not GetFileSecurity(PChar(FileName), OWNER_SECURITY_INFORMATION, SecDescr, 1024, SizeNeeded) then
         Exit;
      if not GetSecurityDescriptorOwner(SecDescr, OwnerSID, OwnerDefault) then
         Exit;
      SizeNeeded := 1024;
      SizeNeeded2 := 1024;
      if not LookupAccountSID(nil, OwnerSID, OwnerName, SizeNeeded, DomainName, SizeNeeded2, OwnerType) then
         Exit;

      //if not SetSecurityDescriptorOwner(SecDescr, PChar(Username), True) then
      //   Exit;
      //if not SetFileSecurity (PChar(FileName), SecurityInformation,  SecDescr) then
      //   Exit;
   finally
      FreeMem(SecDescr);
      FreeMem(OwnerName);
      FreeMem(DomainName);
   end;
   Result := True;
end;


function DivideUserName_02(s: string; var domain: string; var userName: string): boolean;
var
   i: integer;
begin
   i := Pos('\', s);
   if i <> 0 then begin
      domain := Copy(s, 1, i-1);
      userName := Copy(s, i+1, MaxInt);
      result := true;
   end else begin
      i := Pos('@', s);
      if i <> 0 then begin
         userName := Copy(s, 1, i-1);
         domain := Copy(s, i+1, MaxInt);
         result := true;
      end else begin
         domain := '';
         userName := s;
      end;
      result := false;
   end;
end;

function GetCompName_02: string;
var
   sz: dword;
begin
   SetLength(result, MAX_COMPUTERNAME_LENGTH);
   sz := MAX_COMPUTERNAME_LENGTH+1;
   GetComputerName(PChar(result), sz);
   SetLength(result, sz);
end;

function GetFileOwner_02(const fileName: string; var domain, username: string): boolean; overload;
var
   SecDescr: PSecurityDescriptor;
   SizeNeeded, SizeNeeded2: DWORD;
   OwnerSID: PSID;
   OwnerDefault: BOOL;
   OwnerName, DomainName: PChar;
   OwnerType: SID_NAME_USE;
begin
   result := false;
   GetMem(SecDescr, 1024);
   GetMem(OwnerSID, SizeOf(PSID));
   GetMem(OwnerName, 1024);
   GetMem(DomainName, 1024);
   try
      result := GetFileSecurity(PChar(FileName), OWNER_SECURITY_INFORMATION, SecDescr, 1024, SizeNeeded);
      if not result then exit;
      result := GetSecurityDescriptorOwner(SecDescr, OwnerSID, OwnerDefault);
      if not result then exit;
      SizeNeeded  := 1024;
      SizeNeeded2 := 1024;
      result := LookupAccountSID(nil, OwnerSID, OwnerName, SizeNeeded, DomainName, SizeNeeded2, OwnerType);
      if not result then exit;
      Domain   := DomainName;
      Username := OwnerName;
   finally
      FreeMem(SecDescr);
      FreeMem(OwnerName);
      FreeMem(DomainName);
   end;
   result := true;
end;

function GetFileOwner_02(const fileName: string): string; overload;
var
   domain,user: string;
begin
   if GetFileOwner(fileName, domain, user) then
      result := domain+'\'+user
   else
      result := '<error>';
end;

function ERROR(Res: DWORD): string;
var
    FErrorBufPtr: Pointer;
    FNameBufPtr: Pointer;
    FErrorString: string;

   function CheckNetError(Res: DWORD): string;
   var
      s: string;
      Error: EWin32Error;
   begin
      s := '';
      if (Res <> NERR_Success) {and (Res <> ERROR_MORE_DATA)} then begin
         s := SysAndNetErrorMessage(Res);
         s := Format('Net Error code: %d.'#10'"%s"', [Res, s]);
         //FErrorCode := Res;
      end;
      Result := s;
   end;

begin
   //FErrorBufPtr := AllocMem(ERRORLEN);
   //FNameBufPtr := AllocMem(PROVIDERNAMELEN);
   FErrorString := CheckNetError(res);
   //FErrorString := CheckNetError (WNetGetLastError(FErrorCode, FErrorBufPtr, ERRORLEN, FNameBufPtr, PROVIDERNAMELEN));
end;

function GetUserSID_02(domain,userName: string; var sid: PSid; var sidType: SID_NAME_USE): boolean; overload;
var
   pdomain: pchar;
   size: dword;
   refDomainLen: dword;
   s: string;
begin
   if domain <> '' then pdomain := pchar(domain) else pdomain := nil;
   size := 4096;
   refDomainLen := 0;
   result := LookupAccountName(pdomain, pchar(userName), nil, size, nil,refDomainLen,sidType);
   s := ERROR(GetLastError);
   GetMem(sid, size);
   setlength(domain, refDomainLen);
   result := LookupAccountName(pdomain, pchar(userName), sid, size, @domain[1],refDomainLen,sidType);
end;

function GetUserSID_02(domain,userName: string; var sid: PSid): boolean; overload;
var
   ignoreSidType: SID_NAME_USE;
begin
   result := GetUserSID_02(domain, userName, sid, ignoreSidType);
end;

function GetUserSID_02(userName: string; var sid: PSid; var sidType: SID_NAME_USE): boolean; overload;
var
   domain: string;
begin
   DivideUserName_02(userName, domain,userName);
   result := GetUserSID_02(domain, userName, sid, sidType);
end;

function GetUserSID_02(userName: string; var sid: PSId): boolean; overload;
var
   ignoreSidType: SID_NAME_USE;
begin
   result := GetUserSID_02(userName, sid, ignoreSidType);
end;

function GetUserName_02(sid: PSid; out userName: string): boolean;
var
   name: string;
   nameLen: dword;
   domain: string;
   domainLen: dword;
   sidType: SID_NAME_USE;
begin
   nameLen := 1024;
   setlength(name, nameLen);
   domainLen := 1024;
   setlength(domain, domainLen);
   result := LookupAccountSID(nil, sid, @name[1], nameLen,
                              @domain[1], domainLen, sidType);
   if result then begin
     setlength(name, nameLen);
     setlength(domain, domainLen);
     userName := domain+'\'+name;
   end;
end;

function SetFileOwner_02(const fileName: string; const domain, username: string): boolean; overload;
var
   sd: PSecurityDescriptor;
   ownerSID: PSID;
begin
   result := GetUserSid_02(domain,username,OwnerSID);
   if not result then exit;
   GetMem(sd, 1024);
   try
     result := InitializeSecurityDescriptor(sd, SECURITY_DESCRIPTOR_REVISION);
     result := result and SetSecurityDescriptorOwner(sd, ownerSID, true{?});
     result := result and SetFileSecurity(PChar(fileName), OWNER_SECURITY_INFORMATION, sd);
   finally
     FreeMem(sd);
   end;
end;

function SetFileOwner_02(const fileName: string; userName: string): boolean; overload;
var
   domain: string;
begin
   DivideUserName_02(userName, domain,userName);
   result := SetFileOwner_02(filename, domain, userName);
end;

end.

