{.$A+,B-,C+,D+,E-,F-,G+,H+,I+,J+,K-,L+,M-,N+,O+,P+,Q-,R-,S-,T-,U-,V+,W-,X+,Y+,Z1}
{.$I JEDI.INC}

{A wrapper component for the SHFileOperation function }

unit LUFileOp;
{  Bugs:
    fofConfirmMouse does nothing
    fofWantMappingHandle does nothing
}

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,ShellAPI;

type
  TSHFileOpType=(foCopy,foDelete,foMove,foRename);
  TSHFileOption=(fofAllowUndo,fofConfirmMouse,fofFilesOnly,fofMultiDestFiles,
                 fofNoConfirmation,fofNoConfirmMkDir,fofRenameOnCollision,fofSilent,
                 fofSimpleProgress,fofWantMappingHandle,{fofCreateProgressDlg,}fofNoErrorUI);
  TSHFileOptions=set of TSHFileOption;

  TSHFileOperation = class(TComponent)
  private
    { Private declarations }
    FSourceFiles  :TStrings;
    FDestFiles    :TStrings;
    FOperation    :TSHFileOpType;
    FOptions      :TSHFileOptions;
    FTitle        :string;
    procedure SetSourceFIles(Value:TStrings);
    procedure SetDestFiles(Value:TStrings);
  protected
    { Protected declarations }
    function GetWinHandle:THandle;virtual;
  public
    { Public declarations }
    function Execute:boolean;
    constructor Create(AOwner:TComponent);override;
    destructor Destroy;override;
  published
    { Published declarations }
    property SourceFiles:TStrings read FSourceFiles write SetSourceFiles;
    property DestFiles:TStrings read FDestFiles write SetDestFiles;
    property Operation:TSHFileOpType read FOperation write FOperation default foCopy;
    property Options:TSHFileOptions read FOptions write FOptions default [fofAllowUndo,fofFilesOnly];
    property Title:string read FTitle write FTitle;
  end;

function FileOpRename(const FileS, FileD: string): Boolean;

implementation

function FileOpRename(const FileS, FileD: string): Boolean;
var
   LSHFileOperation: TSHFileOperation;
   LS: TStringlist;
   LD: TStringlist;
begin
   LS := TStringlist.Create;
   LS.Add(FileS);
   LD := TStringlist.Create;
   LD.Add(FileD);
   LSHFileOperation := TSHFileOperation.Create(nil);
   LSHFileOperation.Operation := foRename;
   LSHFileOperation.SourceFiles := LS;
   LSHFileOperation.DestFiles := LD;
   Result := LSHFileOperation.Execute;
   LSHFileOperation.Free;
   LS.Free;
   LD.Free;
end;

{ TSHFileOperation }

constructor TSHFileOperation.Create(AOwner:TComponent);
begin
  FSourceFiles := TStringlist.Create;
  FDestFiles   := TStringlist.Create;
  FOperation := foCopy;
  FOptions := [fofAllowUndo,fofFilesOnly];
  inherited Create(AOwner);
end;

destructor TSHFileOperation.Destroy;
begin
  FSourceFiles.Free;
  FDestFiles.Free;
  inherited Destroy;
end;

{** returns true if no error occurred and user didn't abort }
function TSHFileOperation.Execute:boolean;
const
  aOperation:array[TSHFileOpType] of integer=(FO_COPY,FO_DELETE,FO_MOVE,FO_RENAME);
  aOption:array[TSHFileOption] of integer=(FOF_ALLOWUNDO,FOF_CONFIRMMOUSE,FOF_FILESONLY,FOF_MULTIDESTFILES,
                                            FOF_NOCONFIRMATION,FOF_NOCONFIRMMKDIR,FOF_RENAMEONCOLLISION,
                                            FOF_SILENT,FOF_SIMPLEPROGRESS,FOF_WANTMAPPINGHANDLE,{FOF_CREATEPROGRESSDLG,}FOF_NOERRORUI);
var
  SFOS:TShFileOpStruct;
  i:TSHFileOption;
  j:integer;
  ppFrom,ppTo:string;
begin
  if Length(FSourceFiles.Text) = 0 then
    Exception.Create('No files specified to TSHFileOperation Execute function');

  FillChar(SFOS,sizeof(TShFileOpStruct),#0);

  with SFOS do
  begin
    fAnyOperationsAborted := false;
    fFlags := 0;
    for i := Low(TSHFileOption) to High(TSHFileOption) do    // Iterate
      if i in FOptions then
        fFlags := fFlags or aOption[i];
    hNameMappings := nil; // this is never used ???
    lpszProgressTitle := PChar(FTitle);
    ppFrom := '';
    ppTo := '';
    for j := 0 to FSourceFiles.Count - 1 do
      ppFrom := ppFrom + ExpandFilename(FSourceFiles[j]) + #0;
    ppFrom := ppFrom + #0;
    pFrom := PChar(ppFrom);

    for j := 0 to FDestFiles.Count - 1 do
      ppTo := ppTo + ExpandFilename(FDestFiles[j]) + #0;
    ppTo := ppTo + #0;
    pTo := PChar(ppTo);

    wFunc := aOperation[FOperation];
    Wnd := GetWinHandle; // (Owner as TForm).Handle;
  end;    // with
  Result := SHFileOperation(SFOS) = 0;
  Result := Result and not SFOS.fAnyOperationsAborted;

  if SFOS.hNameMappings <> nil then
  begin
{    PNameMapping := Pointer(SFOS.hNameMappings);
    while PNameMapping <> nil do
    begin
      if (PNameMapping.cchOldPath <> 0) and (PNameMapping.cchNewPath <> 0) then
        FSourceFiles.Add(Format('%s=%s',[PNameMapping.pszOldPath,PNameMapping.pszNewPath]));
      Inc(PNameMapping,sizeof(TSHNameMapping));
    end;
}    
    ShFreeNameMappings(Cardinal(SFOS.hNameMappings));
  end;
end;


{ private }
procedure TSHFileOperation.SetSourceFiles(Value:TStrings);
begin
  FSourceFiles.Assign(Value);
end;

procedure TSHFileOperation.SetDestFiles(Value:TStrings);
begin
  FDestFiles.Assign(Value);
end;

function TSHFileOperation.GetWinHandle: THandle;
begin
  if (Owner is TWinControl) then
    Result := TWinControl(Owner).Handle
  else
    Result := GetFocus;
end;

end.
