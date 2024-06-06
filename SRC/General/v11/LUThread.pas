(*
 =======================================================
 Copyright (c) 2023
 Author:
     Lisitsin Y.R.
 Project:
     LU_PAS
     Delphi VCL Extensions (LU)
 Module:
    LUThread
    
 =======================================================
*)

unit LUThread;

interface

uses
    { }
    System.Classes;

{ LU begin ================================================ }
type
    TProgressProc = procedure(aProgress: Integer) of object;  { 0 to 100} 
    TTerminateProc = procedure (aObjectID: TObject) of object;
{ LU end ================================================ }

type
    TProgressThreadNew = class(TThread)

    { LU begin ================================================ }
    private
        FProgressProc: TProgressProc;
        FTerminateProc: TTerminateProc;
        FProgressValue: Integer;
        procedure SynchedProgress;
    { LU end ================================================ }

    protected
    { LU begin ================================================ }
        procedure Progress (aProgress: Integer); virtual;
    { LU end ================================================ }
    { DELPHI begin ================================================ }
        procedure Execute; override;
    { DELPHI end ================================================ }

    { LU begin ================================================ }
    public
        constructor Create (aProgressProc: TProgressProc;
            CreateSuspended: Boolean = False); reintroduce; virtual;
        property TerminateProc: TTerminateProc write FTerminateProc;
    { LU end ================================================}
    end;

implementation

{ DELPHI begin
  Important: Methods and properties of objects in visual components can only be
  used in a method called using Synchronize, for example,

      Synchronize(UpdateCaption);

  and UpdateCaption could look like,

    procedure YoutubeDownload.UpdateCaption;
    begin
      Form1.Caption := 'Updated in a thread';
    end;

    or

    Synchronize(
      procedure
      begin
        Form1.Caption := 'Updated in thread via an anonymous method'
      end
      )
    );

  where an anonymous method is passed.

  Similarly, the developer can call the Queue method with similar parameters as
  above, instead passing another TThread class as the first parameter, putting
  the calling thread in a queue with the other thread.
DELPHI end}

{ LU begin ================================================ }
(*
Вызовите Create, чтобы создать поток в приложении.
Если CreateSuspended имеет значение false,
Execute вызывается сразу после конструктора.
Если CreateSuspended имеет значение true,
Execute не вызывается до тех пор, пока не будет вызван метод Start.
*)

{ TProgressThread.Create }

constructor TProgressThreadNew.Create (aProgressProc: TProgressProc;
    CreateSuspended: Boolean = False);
begin
    inherited Create (CreateSuspended);
    FreeOnTerminate := True;
    FProgressProc := aProgressProc;
end;

{ TProgressThread.Progress }

procedure TProgressThreadNew.Progress (aProgress: Integer);
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

procedure TProgressThreadNew.SynchedProgress;
begin
    if Assigned (FProgressProc) then
        FProgressProc (FProgressValue);
end;
{ LU end ================================================ }

{ DELPHI begin ================================================ }
{ TProgressThread.Execute }

procedure TProgressThreadNew.Execute;
begin
    NameThreadForDebugging ('YoutubeThread');
    { Place thread code here }
end;
{ DELPHI end ================================================ }

end.
