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
�������� Create, ����� ������� ����� � ����������.
���� CreateSuspended ����� �������� false,
Execute ���������� ����� ����� ������������.
���� CreateSuspended ����� �������� true,
Execute �� ���������� �� ��� ���, ���� �� ����� ������ ����� Start.
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
    Synchronize ���������� �����, ��������� AMethod, �����������
    � �������������� ��������� ������, ��� ��������� �������� ������������� ����������.
    �������� AThread ��������� ����� ����������� �������.

    ���������� �������� ������ ������������������, ���� ����� ����������� � �������� ������.
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
