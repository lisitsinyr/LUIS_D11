(*
 =======================================================
 Copyright (c) 2023
 Author:
     Lisitsin Y.R.
 Project:
     LU_PAS
     Delphi VCL Extensions (LU)
 Module:
     LUExec
     Вызов программ
 =======================================================
*)

unit LUExec;

interface

uses
  Windows, SysUtils, ShlObj, ActiveX, ComObj, LUSupport, LUStrUtils, ExecFile;

(* { ShowWindow() Commands }
   SW_HIDE = 0;
   SW_SHOWNORMAL = 1;
   SW_NORMAL = 1;
   SW_SHOWMINIMIZED = 2;
   SW_SHOWMAXIMIZED = 3;
   SW_MAXIMIZE = 3;
   SW_SHOWNOACTIVATE = 4;
   SW_SHOW = 5;
   SW_MINIMIZE = 6;
   SW_SHOWMINNOACTIVE = 7;
   SW_SHOWNA = 8;
   SW_RESTORE = 9;
   SW_SHOWDEFAULT = 10;
   SW_MAX = 10;
*)

procedure RunIt(Path, Parameters: string);
function WinExecAndWait(PathExe, Params, WorkDir: string;
   Wait: Boolean; RunMode: Word; var Status: Cardinal;
   HH,NN,SS: Word): boolean;
function ExecuteShell(PathExe,Params,WorkDir: String; Wait: Boolean; Runmode: Integer; var Status: Cardinal):Boolean;
function ProcessExecuteWait(const FileName, Params, StartDir: string; TimeOut:Word;{Seconds} var pID, tID, hWnd :THandle ):Boolean;
Function WindowFromProcessID( pID: DWORD ): HWND;
Function WindowFromThreadID( tID: DWORD ): HWND;
function IncTime(ATime: TDateTime; Hours, Minutes, Seconds, MSecs: Integer): TDateTime; {From RXLib}
function OpenLink(const LinkFile: string): IPersistFile;

{Function Exec(Path,Params,WorkPath:string; Wait:Boolean; Runmode:integer):boolean; }
{ Выполняет указанную программу с ожиданием ее завершения
  Path - полный путь доступа к файлу.
  Params - параметры
  WorkPath - текущий каталог. Если '' то тот же каталог где EXE
  Wait - ждать завершения программы ?
  RUNMODE - режим запуска (0 - по умолчанию SHOWNORMAL):
    SW_HIDE                Прячет окно и активизирует другое окно.
    SW_MAXIMIZE            Maximizes window.
    SW_MINIMIZE            Минимизирует определенное окно и активизирует следующее.
    SW_RESTORE             В нормальном окне
    SW_SHOW                Активирует окно в его текущем положении и размере
    SW_SHOWDEFAULT         Делает текущее положение нормальным ?
    SW_SHOWMAXIMIZED       Активизирует окно и расширяет его.
    SW_SHOWMINIMIZED       Активизирует окно и минимизирует его.
    SW_SHOWMINNOACTIVE     Минимизирует окно оставляя его активным.
    SW_SHOWNA              Отображает окно в своем текущем состоянии. Активное окно остается активным.
    SW_SHOWNOACTIVATE      Отображает окно в своем последнем размере и позиции. Активное окно остается активным.
    SW_SHOWNORMAL          Активизирует и отображает окно. Если окно минимизируется или расширяется,
                           то Окно восстанавливается в своем исходном размере и позиции.
                           Приложение должно определить этот флаг отображая окно в начале.
P.S.  Особенности выполнения, когда не указан путь доступа к файлу. (клнечно если файл не в текущем каталоге)
      Если wait=false, то производится поиск файла по PATH
      Если wait=true, то поиска не будет и не найдя файла функция вернет false.
}

{ Function ExecDOS2(Path,Params,WorkPath,Title:String; Wait:Boolean; Minimized:Boolean; Runmode:integer):Boolean;}
{ Специально для DOS-программ, создает PIF-файл для его выполнения,
  удаляя в конце.
   Path       Полный путь к файлу
   Params     Параметры
   WorkPath   Рабочая директоря. Если '', то тоже что и у EXE
   Title      Заголовок (часто русские буквы не читаются)
   Wait       ждать окончания выполнения программы ?
   Minimized  Минимизировать окно ?}

function ExecuteAll(PathExe,Params,WorkDir: String; Wait: Boolean; Runmode: Integer; var Status: Cardinal):Boolean;
function CreateLNK (PathExe,Params,WorkDir,PathLnk: string): string;

implementation

{$B-}

Type
   TEnumData = Record
      hW: HWND;
      pID: DWORD;
   End;

function GetTempDir: string;
var
   PC: PChar;
begin
   { TempDir }
   PC := StrAlloc(256);
   GetTempPath(256, PC);
   Result := ExcludeTrailingBackslash(StrPas(PC));
   StrDispose(PC);
end;

procedure RunIt(Path, Parameters: string);
var
   P: TProcessInformation;
   S: TStartUpInfo;
begin
   FillChar(S, SizeOf(S), #0);
   FillChar(P, SizeOf(P), #0);
   S.CB:=SizeOf(S);
   CreateProcess(nil, PChar(Path+' '+Parameters), nil, nil, False, 0,
                      GetEnvironmentStrings, nil, S, P);
   CloseHandle(p.hProcess);
end;

function WinExecAndWait(PathExe, Params, WorkDir: string;
   Wait: Boolean; RunMode: Word; var Status: Cardinal;
   HH,NN,SS: Word): boolean;
var
   lpCommandLine: string;
   lpProcessInformation: TProcessInformation;
   lpStartupInfo: TStartUpInfo;
   bInheritHandles: Boolean;
   dwCreationFlags: DWORD;
   lpCurrentDirectory: string;
   PEnvironmentStrings: PChar;
   LStatus: DWORD;

   FTimeout: TDateTime;

   procedure SetTimeout(HH,NN,SS: Word);
   begin
      FTimeout := 0;
      if (HH>0) or (NN>0) or (SS>0) then begin
         try
            FTimeout := Now + EncodeTime(HH,NN,SS,0);
         except
         end
      end;
   end;

   function Timeouted: Boolean;
   begin
      Result := (FTimeout > 0) and (Now > FTimeout);
   end;

begin
   SetTimeout(HH,NN,SS);
   lpCommandLine := PathExe+' '+Params;
   { STARTUPINFO }
   FillChar(lpStartupInfo, SizeOf(TStartupInfo), #0);
   GetStartupInfo(lpStartupInfo);
   lpStartupInfo.CB := SizeOf(TStartupInfo);
   lpStartupInfo.dwFlags := STARTF_USESHOWWINDOW;
   lpStartupInfo.wShowWindow := RunMode;
   { ProcessInformation }
   FillChar(lpProcessInformation, SizeOf(TProcessInformation), #0);
   {}
   bInheritHandles := True;
   {}
   dwCreationFlags := 0;
   {}
   lpCurrentDirectory := WorkDir;
   PEnvironmentStrings := GetEnvironmentStrings;
   {}
   CreateProcess(nil,
                 PChar(lpCommandLine),       { pointer to command line string }
                 nil,                        { pointer to process security attributes }
                 nil,                        { pointer to thread security attributes }
                 bInheritHandles,            { handle inheritance flag }
                 dwCreationFlags,            { creation flags }
                 PEnvironmentStrings,        { pointer to new environment block  }
                 PChar(lpCurrentDirectory),  { pointer to current directory name  }
                 lpStartupInfo,              { pointer to STARTUPINFO }
                 lpProcessInformation);      { pointer to PROCESS_INFORMATION }
   {}
   if lpProcessInformation.hProcess = 0 then begin
      Result := False;
      FreeEnvironmentStrings(PEnvironmentStrings);
      Exit;
   end;
   if Wait then begin
      {}
      GetExitCodeProcess(lpProcessInformation.hProcess, LStatus);
      Repeat
         { Application.ProcessMessages; }
         GetExitCodeProcess(lpProcessInformation.hProcess, LStatus);
      until {Application.Terminated or } Timeouted or (LStatus <> STILL_ACTIVE);
      if Timeouted then begin
         { Kill process }
         LStatus := 999;
         TerminateProcess(lpProcessInformation.hProcess, LStatus);
         Status := LStatus;
         Result := False;
         end
      else begin
         Status := LStatus;
         Result := True;
      end;
      FreeEnvironmentStrings(PEnvironmentStrings);
      CloseHandle(lpProcessInformation.hProcess);
      end
   else begin
      Result := True;
      CloseHandle(lpProcessInformation.hProcess);
   end;
end;

function IncTime(ATime: TDateTime; Hours, Minutes, Seconds, MSecs: Integer): TDateTime;
begin
   Result := ATime + (Hours div 24) + (((Hours mod 24) * 3600000 +
             Minutes * 60000 + Seconds * 1000 + MSecs) / MSecsPerDay);
   if Result < 0 then Result := Result + 1;
end;

Function EnumProc (hw: HWND; Var data: TEnumData): Bool; stdcall;
Var
   pID: DWORD;
Begin
   Result := True;
   If (GetWindowLong(hw, GWL_HWNDPARENT) = 0) and
      (IsWindowVisible( hw ) or IsIconic(hw)) and
      ( (GetWindowLong(hw, GWL_EXSTYLE) and (WS_EX_WINDOWEDGE or WS_EX_APPWINDOW))<>0) Then Begin
      GetWindowThreadProcessID( hw, @pID );
      If pID = data.pID Then Begin
         data.hW := hW;
         Result := False;
      End; { If }
   End; { If }
End; { EnumProc }

Function EnumProcThread( hw: HWND; Var data: TEnumData ): Bool; stdcall;
Begin
   Result := True;
   If (GetWindowLong(hw, GWL_HWNDPARENT) = 0) and
      (IsWindowVisible( hw ) or IsIconic(hw)) and
      ( (GetWindowLong(hw, GWL_EXSTYLE) and (WS_EX_WINDOWEDGE or WS_EX_APPWINDOW))<>0) Then Begin
      data.hW := hW;
      Result := False;
   End; { If }
End; { EnumProc }

{ For MSDOS FileName=''}
function ProcessExecuteWait(const FileName, Params, StartDir: string;
                            TimeOut: Word; var pID, tID, hWnd: THandle): Boolean;
var
   lpProcessInformation: TProcessInformation;
   lpStartupInfo: TStartupInfo;
   StartTime: TDateTime;
   Data: TEnumData;
   TimeOutWait: TDateTime;
begin
   TimeOutWait := IncTime(0, 0, 0, TimeOut, 0);
   GetStartupInfo(lpStartupInfo);
   lpStartupInfo.dwFlags := 0;
   pID  := 0;
   tID  := 0;
   hWnd := 0;
   Result := CreateProcess(PChar(FileName),PChar(Params),nil,nil,False,0,nil,
                           PChar(StartDir),lpStartupInfo,lpProcessInformation);
   if Result then begin
      StartTime  := Time;
      pID := lpProcessInformation.dwProcessId;
      tID := lpProcessInformation.dwThreadId;
      Data.pID := pID;
      Data.hW :=0;
      hWnd := 0;
      while  Data.hW = 0 do begin
         { Application.ProcessMessages; }
         sleep(10);
         EnumThreadWindows( tID, @EnumProc, longint(@data) );
         if (Time-StartTime) > TimeOutWait then Data.hW := 1{0};
      end;
      hWnd := Data.hW;
   end;
end;

Function WindowFromProcessID (pID: DWORD): HWND;
Var
   data: TEnumData;
Begin
   data.pID := pID;
   data.hW := 0;
   EnumWindows (@EnumProc, longint(@data));
   Result := data.hW;
End; { WindowFromProcessID }

Function WindowFromThreadID( tID: DWORD ): HWND;
Var
   data: TEnumData;
Begin
   data.hW := 0;
   EnumThreadWindows (tID, @EnumProcThread, longint(@data));
   Result := data.hW;
End; { WindowFromThreadID }

(*
Function Exec(Path,Params,WorkPath:string; Wait:Boolean; Runmode:integer):boolean;
var
   startUpInfo : TStartupInfo;
   processInfo : TProcessInformation;
   exeCmd      : string;
   Res: Boolean;
begin
   result := true;
   if wait then begin
      exeCmd := path + ' ' + params;
      FillChar(startUpInfo, SizeOf(startUpInfo), Chr(0));
      StartUpInfo.cb := SizeOf( StartUpInfo );
      StartUpInfo.dwFlags     := STARTF_USESHOWWINDOW;
      StartUpInfo.wShowWindow := runmode;
      if WorkPath <> '' then begin
         Result := CreateProcess(nil, PChar(exeCmd), nil, nil, false,
            CREATE_NEW_CONSOLE or NORMAL_PRIORITY_CLASS, nil,
            PChar(WorkPath), startUpInfo, processInfo);
         end
      else begin
         Result := CreateProcess(nil, PChar(exeCmd), nil, nil, false,
            CREATE_NEW_CONSOLE or NORMAL_PRIORITY_CLASS, nil, nil, startUpInfo, processInfo);
      end;
      WaitForSingleObject(processInfo.hProcess, INFINITE);
      end
   else begin
      result:=ShellExecute(Application.Handle,'open',pchar(path),pchar(params),pchar(WorkPath),RunMode)>32;
   end;
end;
*)

Function CreatePif(PathExe,Params,WorkDir,PathLnk:String): string;
var f       : file;
    a       : string;
    i       : integer;
begin
  a:=
  {0000} #0#120#84#69#83#84#68#79#126#49#32#32#32#32#32#32#32#32#32#32+
  {0010} #32#32+
  {0012} #32#32+
  {0014} #32#32+
  {--------------------------------------------------------------------}
  {0016} #32#32#32#32#32#32#128#2#0#0#68#58#92#116#101+
  #115#116#100#111#115#112#114#111#103#114#97#109#116#104#105#110+
  #103#46#101#120#101#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0+
  #0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#16#0#101#58#92#116#101#109#112+
  #0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0+
  #0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#45#101#120+
  #32#100#58#92#116#101#115#116#32#100#58#92#42#46#42#0#0#0#0#0+
  #0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0+
  #0#0#0#0#0#0#0#0#0#0#0#1#0#255#25#80#0#0#7#0#0#0#0#0#0#0#0#0#0+
  #0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0+
  #0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0+
  #0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0+
  #0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#77#73+
  #67#82#79#83#79#70#84#32#80#73#70#69#88#0#135#1#0#0#113#1#87#73+
  #78#68#79#87#83#32#51#56#54#32#51#46#48#0#5#2#157#1#104#0#128+
  #2#0#0#100#0#50#0#255#255#0#0#255#255#0#0#2#0#2#0#159#0#0#0#0+
  #0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#45#101#120#32#100#58#92#116#101+
  #115#116#32#100#58#92#42#46#42#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0+
  #0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#87+
  #73#78#68#79#87#83#32#86#77#77#32#52#46#48#0#255#255#27#2#172+
  #1#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0+
  #0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0+
  #0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#80#73#70+
  #77#71#82#46#68#76#76#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0+
  #0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0+
  #0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#2#0#0#0#0#0#0#0#0#0+
  #0#0#0#0#129#0#0#0#0#0#0#0#0#0#0#0#1#0#0#0#5#0#25#0#3#0#200#0+
  #232#3#2#0#10#0#1#0#0#0#0#0#0#0#28#0#0#0#0#0#0#0#8#0#12#0#84#101+
  #114#109#105#110#97#108#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0+
  #0#0#0#0#0#76#117#99#105#100#97#32#67#111#110#115#111#108#101+
  #0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#3#0#0#0#80#0#25#0#128+
  #2#44#1#0#0#0#0#22#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0+
  #0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0+
  #0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0+
  #0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#1#0;
  i:=length(PathLnk);
  if i>30 then i:=30;
  move(PathLnk[1],a[$02+1],i);

  if length(pathExe)>63 then pathExe:=copy(pathExe,1,63);
  pathExe:=pathExe+#0;
  move(pathExe[1],a[$24+1],length(pathExe));

  if length(params)>63 then params:=copy(params,1,63);
  params:=params+#0;
  move(params[1],a[$a5+1],length(params));
  move(params[1],a[$1c5+1],length(params));

  if length(workDir)>63 then workDir:=copy(workDir,1,63);
  workDir:=workDir+#0;
  move(workDir[1],a[$65+1],length(workDir));

  a[$1af+1]:=#$12;
  (*
  if minimized then
     a[$1af+1]:=#$12
  else
     a[$1af+1]:=#$2;
  *)
  assignfile(f,pathLnk);
  rewrite(f,1);
  i:=ioresult;
  blockwrite(f,a[1],length(a), i);
  closefile(f);
end;

function CreateLNK(PathExe,Params,WorkDir,PathLnk: string): string;
var
   IObject: IUnknown;
   SLink: IShellLink;
   PFile: IPersistFile;
begin
   Result := '';
   IObject := CreateComObject(CLSID_ShellLink);
   SLink := IObject As IShellLink;
   PFile := IObject As IPersistFile;
   SLink.SetPath(PChar(PathExe));
   SLink.SetArguments(PChar(Params));
   SLink.SetWorkingDirectory(PChar(WorkDir));
   PFile.Save(PWChar(WideString(PathLnk)),FALSE);
end;

function CreateLink(const CmdLine, Args, WorkDir, LinkFile: string): IPersistFile;
var
   LinkInterface  : IUnknown;
   ShellLink   : IShellLink;
   PFile   : IPersistFile;
   WideFile  : WideString;
begin
   LinkInterface := CreateComObject(CLSID_SHELLLINK);
   ShellLink := LinkInterface as IShellLink;
   PFile := LinkInterface as IPersistFile;
   with ShellLink do begin
      SetPath(PChar(CmdLine));
      SetArguments(PChar(Args));
      SetWorkingDirectory(PChar(WorkDir));
   end;
   WideFile := LinkFile;
   PFile.Save(PWChar(WideFile), False);
   Result := PFile;
end;

function ExecDOSWXX(PathExe,Params,WorkDir,PathLnk: string; Wait: Boolean; RunMode: Integer;
   var Status: Cardinal): Boolean;
var
   f: Text;
   TempBat: string;
   s: string;
begin
   { TempBat }
   TempBat := IncludeTrailingBackslash(GetTempDir)+'$temp$.bat';
   AssignFile (F, TempBat);
   Rewrite (F);
   s := ExtractFileDrive(WorkDir);
   WriteLN (F, s);
   s := 'cd '+ReplaceSTR(WorkDir, s, '')+'';
   WriteLN (F, s);
   WriteLN (F, ''+PathExe+''+' '+Params);
   CloseFile (F);
   { LnkPath }
   { CreateLNK(TempBat, '', WorkDir, PathLnk); }
   CreatePif(TempBat, '', WorkDir, PathLnk);
   { Exec }
   Result := WinExecAndWait (PathLnk, '', WorkDir, Wait, RunMode, Status,0,0,0);
   { Application.ProcessMessages; }
   if not wait then sleep(1000); { we must wait one second for Windows to read file }
   DeleteFile (TempBat);
   DeleteFile (PathLnk);
end;

function ExecuteAll(PathExe,Params,WorkDir: String; Wait: Boolean; Runmode: Integer; var Status: Cardinal):Boolean;
var
   OSVersionInfo: TOSVersionInfo;
   LExecFile: TExecFile;
begin
   {
   OSVersionInfo.dwPlatformId:
   VER_PLATFORM_WIN32s          Win32s on Windows 3.1.
   VER_PLATFORM_WIN32_WINDOWS Win32 on Windows 95.
   VER_PLATFORM_WIN32_NT   Win32 on Windows NT.
   }
   GetOsVersion(OSVersionInfo);
   if OSVersionInfo.dwPlatformId = VER_PLATFORM_WIN32_NT then begin
      Result := WinExecAndWait (PathExe, Params, WorkDir, Wait, RunMode, Status,0,0,0);
      end
   else begin
      (*
      s := IncludeTrailingBackslash(GetTempDir);
      Result := ExecDOSWXX(PathExe,Params,WorkDir,
                           IncludeTrailingBackslash(s)+'$temp$.pif',
                           Wait, RunMode, Status);
      *)
      LExecFile := TExecFile.Create(nil);
      LExecFile.Wait := True;
      LExecFile.CommandLine := PathExe;
      LExecFile.Parameters := Params;
      LExecFile.WorkDir := WorkDir;
      Result := LExecFile.Execute;
      LExecFile.Free;
      Status := 0;
   end;
end;

function ExecuteShell(PathExe,Params,WorkDir: String; Wait: Boolean; Runmode: Integer; var Status: Cardinal):Boolean;
var
   Shell: string;
   ShellArg: string;
begin
   Shell := GetEnvVar('ComSpec');
   ShellArg := '/c ';
   Result := WinExecAndWait (Shell, ShellArg+PathExe+' '+Params, WorkDir, Wait, RunMode, Status,0,0,0);
end;

function OpenLink(const LinkFile: string): IPersistFile;
var
   LinkInterface  : IUnknown;
   ShellLink   : IShellLink;
   PFile   : IPersistFile;
   WideFile  : WideString;
   s: string;
   Buffer: PChar;
   PInfo: WIN32_FIND_DATA;
begin
   Buffer := StrAlloc(256);
   LinkInterface := CreateComObject(CLSID_SHELLLINK);
   ShellLink := LinkInterface as IShellLink;
   PFile := LinkInterface as IPersistFile;
   WideFile := LinkFile;
   PFile.Load(PWChar(WideFile), 0);
   with ShellLink do begin
      GetArguments(Buffer, 256);
      s := StrPas(Buffer);
      GetDescription(Buffer, 256);
      s := StrPas(Buffer);
      GetPath(Buffer, 256, PInfo, SLGP_UNCPRIORITY);
      s := StrPas(Buffer);
      GetWorkingDirectory(Buffer, 256);
      s := StrPas(Buffer);
   end;
   Result := PFile;
   StrDispose(Buffer);
end;

end.

