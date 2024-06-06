(*
 =======================================================
 Copyright (c) 2023
 Author:
     Lisitsin Y.R.
 Project:
     LU_PAS
     Delphi VCL Extensions (LU)
 Module:
     LUThreadYoutube

 =======================================================
*)

unit LUThreadYoutube;

interface

uses
    {}
        Classes, SysUtils, Forms,
    {}
    LUThread, LUThreadProgress;

{ =========================================================================== }
const
    cProgressBarMax = 20;
    cSleep = 500;

(*
{ TThreadYoutube }

type
    TYoutubeThread = class(TProgressThread)
    protected
        procedure Execute; override;

    public
        FStopYouTubeBooleanThread: Boolean;
        FObjectIDStr: string;
    end;
*)

{ TThreadYoutubeNew }

type
    TYoutubeThreadNew = class(TProgressThreadNew)
    protected
        procedure Execute; override;

    public
        FStopYouTubeBooleanThread: Boolean;
        FObjectIDStr: string;
    end;

implementation

(*
{ -------------- }
{ TYoutubeThread }
{ -------------- }

{ TYoutubeThread.Execute }

procedure TYoutubeThread.Execute;
var
    i: Integer;
begin
    for i := 0 to cProgressBarMax do
    begin
        if FStopYouTubeBooleanThread then
        begin
            { Подает сигнал потоку о завершении, }
            { устанавливая для свойства Terminated значение true. }
            Terminate;
            Break;
        end;
        Progress (i);
        Sleep (cSleep);
        Application.ProcessMessages;
    end;
end;
*)

{ ----------------- }
{ TYoutubeThreadNew }
{ ----------------- }

{ TYoutubeThreadNew.Execute }

procedure TYoutubeThreadNew.Execute;
var
    i: Integer;
begin
    for i := 0 to cProgressBarMax do
    begin
        if FStopYouTubeBooleanThread then
        begin
            { Подает сигнал потоку о завершении, }
            { устанавливая для свойства Terminated значение true. }
            Terminate;
            Break;
        end;
        Progress (i);
        Sleep (cSleep);
        Application.ProcessMessages;
    end;
end;

end.