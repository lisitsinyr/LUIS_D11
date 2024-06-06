(*
 =======================================================
 Copyright (c) 2023
 Author:
     Lisitsin Y.R.
 Project:
     LU_PAS
     Delphi VCL Extensions (LU)
 Module:
     Execfile
     Âûחמג ןנמדנאלל
 =======================================================
*)

unit Execfile;

{Version 2.0 Update 7/14/96}

interface

uses
  SysUtils, WinTypes, WinProcs, Messages,
  Classes, Graphics, Controls, Forms,
  Dialogs;

type
  TWindowStyle = ( wsNorm, wsMinimize, wsMaximize, wsHide,
  wsMinNoActivate, wsShowNoActivate );
  TWaitStyle = ( wRegular, wSuspend );
  TPriorityClass = ( pcNormal, pcIdle, pcHigh, pcRealTime );
  InString = String[255];
  TExecFile = class(TComponent)
  private
   FStopWaiting: Boolean;
   FMsg: TMsg;
   FAss: Boolean;
   FPriorityClass: TPriorityClass;
   FPriorityValue: Integer;
   FError: Integer;
   FExitCode: Integer;
   FIsWaiting: Boolean;
   FWait: Boolean;
   FWaitStyle: TWaitStyle; {Wait method}
   FOnFail: TNotifyEvent;
   FCommandLine: InString;   {Command Line of Executable File}
   FFParams: InString; {Parameters to send to Executable File}
   FWorkdir: InString;
   FAssFName: String; {Name of associated executable}
   FWindowStyle: TWindowStyle; {Window style for Executable File}
   StartUpInfo: TStartUpInfo;
   ProcessInfo: TProcessInformation;
  protected
   procedure SetWindowStyle( Value: TWindowStyle );
   procedure SetWaitStyle ( Value: TWaitStyle );
   procedure SetPriorityClass ( Value: TPriorityClass );
  public
   function Execute: Boolean;
   function Terminate: Boolean;
   function IsWaiting: Boolean;
   function StopWaiting: Boolean;
   function ErrorCode: LongInt;
  published
   property Associate: Boolean read FAss write FAss;
   property CommandLine: InString read FCommandLine write FCommandLine;
   property Parameters: InString read FFParams write FFParams;
   property WorkDir: InString read FWorkDir write FWorkDir;
   property Priority: TPriorityClass read FPriorityClass write SetPriorityClass default pcNormal;
   property Wait: Boolean read FWait write FWait;
   property WaitStyle: TWaitStyle read FWaitStyle write SetWaitStyle default wRegular;
   property WindowStyle: TWindowStyle read FWindowStyle write SetWindowStyle default wsNorm;
   property OnFail: TNotifyEvent read FOnFail write FOnFail;
  end;

procedure Register;

implementation

uses ShellAPI;


procedure TExecFile.SetWindowStyle(Value : TWindowStyle);
begin FWindowStyle := Value;
end;

procedure TExecFile.SetWaitStyle(Value : TWaitStyle);
begin FWaitStyle := Value;
end;

procedure TExecFile.SetPriorityClass(Value : TPriorityClass);
begin FPriorityClass := Value;
end;

procedure Register;
begin RegisterComponents('Samples', [TExecFile]);
end;

function TExecFile.Execute: Boolean;
var zCommandLine: array[0..512] of Char;
zFAssFName: array[0..255] of Char;
zFAssFDir: array[0..255] of Char;
zFAssFDoc: array[0..255] of Char;
FSuccess: Boolean;
   lpCurrentDirectory: string;
begin
Result := False;
FillChar(StartupInfo,Sizeof(StartupInfo),#0);
StartupInfo.cb := Sizeof(StartupInfo);
StartupInfo.dwFlags := STARTF_USESHOWWINDOW;

If FWindowStyle = wsNorm then StartupInfo.wShowWindow := SW_SHOWNORMAL;
If FWindowStyle = wsMinimize then StartupInfo.wShowWindow := SW_SHOWMINIMIZED;
If FWindowStyle = wsMaximize then StartupInfo.wShowWindow := SW_SHOWMAXIMIZED;
If FWindowStyle = wsHide then StartupInfo.wShowWindow := SW_HIDE;
If FWindowStyle = wsMinNoActivate then StartupInfo.wShowWindow := SW_SHOWMINNOACTIVE;
If FWindowStyle = wsShowNoActivate then StartupInfo.wShowWindow := SW_SHOWNA;

If FPriorityClass = pcHigh then FPriorityValue := HIGH_PRIORITY_CLASS;
If FPriorityClass = pcIdle then FPriorityValue := IDLE_PRIORITY_CLASS;
If FPriorityClass = pcNormal then FPriorityValue := NORMAL_PRIORITY_CLASS;
If FPriorityClass = pcRealTime then FPriorityValue := REALTIME_PRIORITY_CLASS;

StrPCopy(zCommandLine,FCommandLine+' '+FFParams);
lpCurrentDirectory := WorkDir;

FSuccess := CreateProcess(nil,
      zCommandLine,           { pointer to command line string }
      nil,                    { pointer to process security attributes }
      nil,                    { pointer to thread security attributes }
      false,                  { handle inheritance flag }
      CREATE_NEW_CONSOLE or   { creation flags }
      FPriorityValue,
      nil,                    { pointer to new environment block }
      PChar(lpCurrentDirectory),  { pointer to current directory name  }
      StartupInfo,            { pointer to STARTUPINFO }
      ProcessInfo);

If not FSuccess then begin
 If FAss then begin StrPCopy(zFAssFDoc,FCommandLine);
  If findExecutable(zFAssFDoc,zFAssFDir,zFAssFName)<32 then begin
   FError := GetLastError(); If Assigned(FOnFail) then FOnFail(Self);
   Result := False; exit;
  end else begin FAssFName := zFAssFName;
   StrPCopy(zCommandLine,FAssFName+' '+FCommandLine+' '+FFParams);
   lpCurrentDirectory := WorkDir;
   FSuccess := CreateProcess(nil,
      zCommandLine,           { pointer to command line string }
      nil,                    { pointer to process security attributes }
      nil,                    { pointer to thread security attributes }
      false,                  { handle inheritance flag }
      CREATE_NEW_CONSOLE or   { creation flags }
      FPriorityValue,
      nil,                    { pointer to new environment block }
      PChar(lpCurrentDirectory),  { pointer to current directory name  }
      StartupInfo,            { pointer to STARTUPINFO }
      ProcessInfo);
  end
 end;
end;

If FSuccess then begin
  If FWait then begin FIsWaiting := True; FStopWaiting := False;
   If FWaitStyle = wRegular then begin
    repeat
     While PeekMessage(FMsg,0,0,0,PM_REMOVE) do begin
     If FMsg.Message = WM_QUIT then halt(FMsg.wParam);
     TranslateMessage(FMsg); DispatchMessage(FMsg); end;
     If WaitforSingleObject(ProcessInfo.hProcess,0)<>WAIT_TIMEOUT then begin
     FStopWaiting := True; Application.ProcessMessages; end;
     Until FStopWaiting; end
   else begin
   WaitForSingleObject(ProcessInfo.hProcess,INFINITE); end;
  FIsWaiting := False; Result:= True; end;
end else begin
 FError := GetLastError(); If Assigned(FOnFail) then FOnFail(Self);
 Result := False;
end;
CloseHandle(ProcessInfo.hThread);
CloseHandle(ProcessInfo.hProcess);
end;

function TExecFile.Terminate: Boolean;
begin
Result := False;
{$IFDEF VER100}
GetExitCodeProcess(ProcessInfo.hProcess,FExitCode);
If TerminateProcess(ProcessInfo.hProcess,FExitCode) then Result := True;
{$ELSE}
GetExitCodeProcess(ProcessInfo.hProcess,Cardinal(FExitCode));
If TerminateProcess(ProcessInfo.hProcess,Cardinal(FExitCode)) then Result := True;
{$ENDIF}
end;

function TExecFile.IsWaiting: Boolean;
begin
Result := FIsWaiting;
end;

function TExecFile.StopWaiting: Boolean;
begin
FStopWaiting := True;
Result := True;
end;

function TExecFile.ErrorCode: LongInt;
begin
Result := FError;
end;

end.
