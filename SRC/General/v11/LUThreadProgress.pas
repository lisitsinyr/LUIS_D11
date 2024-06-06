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
    Unit поддержки
 =======================================================
*)

unit LUThreadProgress;

interface

uses
    { }
    Classes;

type
    TProgressProc = procedure(aProgress: Integer) of object; // 0 to 100

type
    TTerminateProc = procedure (aObjectID: TObject) of object;

type
    TProgressThread = class(TThread)
    private
        FProgressProc: TProgressProc;
        FTerminateProc: TTerminateProc;
        FProgressValue: Integer;
        procedure SynchedProgress;

    protected
        procedure Progress (aProgress: Integer); virtual;

    public
        constructor Create (aProgressProc: TProgressProc;
            CreateSuspended: Boolean = False); reintroduce; virtual;
        property TerminateProc: TTerminateProc write FTerminateProc;
    end;

implementation

{ TProgressThread }

(*
Вызовите Create, чтобы создать поток в приложении.
Если CreateSuspended имеет значение false,
Execute вызывается сразу после конструктора.
Если CreateSuspended имеет значение true,
Execute не вызывается до тех пор, пока не будет вызван метод Start.
*)

{ TProgressThread.Create }

constructor TProgressThread.Create (aProgressProc: TProgressProc;
    CreateSuspended: Boolean = False);
begin
    inherited Create (CreateSuspended);
    FreeOnTerminate := True;
    FProgressProc := aProgressProc;
end;

{ TProgressThread.Progress }

procedure TProgressThread.Progress (aProgress: Integer);
begin
    FProgressValue := aProgress;
    (*
    Synchronize заставляет вызов, указанный AMethod, выполняться
    с использованием основного потока, что позволяет избежать многопоточных конфликтов.
    Параметр AThread связывает поток вызывающего объекта.

    Выполнение текущего потока приостанавливается, пока метод выполняется в основном потоке.
    *)
    Synchronize (SynchedProgress);
end;

{ TProgressThread.SynchedProgress }

procedure TProgressThread.SynchedProgress;
begin
    if Assigned (FProgressProc) then
        FProgressProc (FProgressValue);
end;

end.
