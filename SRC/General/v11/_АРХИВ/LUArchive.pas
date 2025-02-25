{=======================================================}
{ Project:                                              }
{         Delphi VCL Extensions (LU)                    }
{         Copyright (c) 2000 Central Bank Of Russia     }
{ Subject:                                              }
{         Работа с архиваторами                         }
{ Author:                                               }
{         Lisitsin Y.R.                                 }
{=======================================================}

unit LUArchive;

interface

uses
   Classes, SysUtils, Windows, StrUtils, FileCtrl, Dialogs, Controls,
   CBLIB, CBERRS,
   LUExec, LULog, LUScanDir, LUSupport;

type
   TArcCommand   = (acAdd, acExtract, acSetKPD, acCheckKPD, acRemoveKPD);
   TTypeArchiver = (taEmpty, taLCK, taARJ);

type
   TCollectionItemKPD2 = class(TCollectionItem)
   private
      FNameSIA: PChar;
      FInfoSIA: PChar;
      FDateCreateKPD: TDateTime;
      FDateEndKPD: TDateTime;
      FResKPD: Integer;
      function GetNameSIA: string;
      procedure SetNameSIA(const Value: string);
      function GetInfoSIA: string;
      procedure SetInfoSIA(const Value: string);
   public
      constructor Create(Collection: TCollection); override;
      destructor Destroy; override;
      property NameSIA: string read GetNameSIA write SetNameSIA;
      property InfoSIA: string read GetInfoSIA write SetInfoSIA;
      property DateCreateKPD: TDateTime read FDateCreateKPD write FDateCreateKPD;
      property DateEndKPD: TDateTime read FDateEndKPD write FDateEndKPD;
      property ResKPD: Integer read FResKPD write FResKPD;
   end;

   TCollectionItemKPD1 = class(TCollectionItem)
   private
      FFileName: PChar;
      FResCode: Integer;
      FNumberKPD: Integer;
      FKPD: TCollection;
      function GetFileName: string;
      procedure SetFileName(const Value: string);
      function GetKPDItem(Index: Integer): TCollectionItemKPD2;
   public
      constructor Create(Collection: TCollection); override;
      destructor Destroy; override;
      property FileName: string read GetFileName write SetFileName;
      property ResCode: Integer read FResCode write FResCode;
      property NumberKPD: Integer read FNumberKPD write FNumberKPD;
      property KPDItem[Index: Integer]: TCollectionItemKPD2 read GetKPDItem;
   end;

type
   TCustomArchive = class(TComponent)
   private
      { Status}
      FStatus: Cardinal;
      FErrors: TStringList;
      FPathName: TStringList;
      FArcName: PChar;
      FFileName: PChar;
      FParamStr: PChar;
      FArcDirName: PChar;
      FArcFileName: PChar;
      FWithSubDir: Boolean;
      FFileMemoLog: TFileMemoLog;
      FScanDirFiles: TScanDirFiles;
      { TempDir }
      FTempDir: PChar;
      {}
      WorkDir: string;
      function GetTempDir: string;
      procedure SetTempDir(const Value: string);
      function GetTempFile: string;
      function GetTempFileRes: string;
      function GetArcName: string;
      procedure SetArcName(const Value: string);
      function GetFileName: string;
      procedure SetFileName(const Value: string);
      function GetParamStr: string;
      procedure SetParamStr(const Value: string);

      function GetArcDirName: string;
      procedure SetArcDirName(const Value: string);

      function GetArcFileName: string;
      procedure SetArcFileName(const Value: string);
      {}
      //function Execute(Command: TARCCommand): Boolean; virtual; abstract;
      {}
      property ScanDirFiles: TScanDirFiles read FScanDirFiles;
   public
      { New }
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      { Function }
      function ErrorString: string;
      { property }
      property FileMemoLog: TFileMemoLog read FFileMemoLog write FFileMemoLog;
      property TempDir: string read GetTempDir write SetTempDir;
      property TempFile: string read GetTempFile;
      property TempFileRes: string read GetTempFileRes;
      property Status: Cardinal read FStatus;
      property PathName: TStringList read FPathName;
      property FileName: string read GetFileName write SetFileName;
      property ArcName: string read GetArcName write SetArcName;
      property ParamStr: string read GetParamStr write SetParamStr;
      property ArcParamStr: string read GetParamStr write SetParamStr;
      property ArcDirName: string read GetArcDirName write SetArcDirName;
      property ArcFileName: string read GetArcFileName write SetArcFileName;
      property WithSubDir: Boolean read FWithSubDir write FWithSubDir;
   end;

   TArcMail = class(TCustomArchive)
   private
      FArcDirNameSIA: PChar;
      FArcDirNameSIRC: PChar;
      FArcDirNamePIA: PChar;
      FArcPIA: PChar;
      FPasswordConfig: PChar;
      FPasswordPIA: PChar;
      FKeyDisk: PChar;
      FResArcMail: TCollection;
      function GetArcPIA: string;
      procedure SetArcPIA(const Value: string);
      function GetPasswordConfig: string;
      procedure SetPasswordConfig(const Value: string);
      function GetPasswordPIA: string;
      procedure SetPasswordPIA(const Value: string);
      function GetKeyDisk: string;
      procedure SetKeyDisk(const Value: string);
      function GetArcDirNameSIA: string;
      procedure SetArcDirNameSIA(const Value: string);
      function GetArcDirNamePIA: string;
      procedure SetArcDirNamePIA(const Value: string);
      function GetArcDirNameSIRC: string;
      procedure SetArcDirNameSIRC(const Value: string);
      function HandleException (E: Exception): Boolean;
      procedure GetResultKPD1(const F: string);
      procedure GetResultKPD2(const F: string);
      function GetResItem(Index: Integer): TCollectionItemKPD1;
      function GetCount: Integer;
      procedure CreateListFileNames(ASourceFiles: string; AWithSubdir: Boolean);
      {}
      function Execute(Command: TARCCommand): Boolean;
      { Property }
      property ArcPIA: string read GetArcPIA write SetArcPIA;
      property ArcDirNameSIA: string read GetArcDirNameSIA write SetArcDirNameSIA;
      property ArcDirNamePIA: string read GetArcDirNamePIA write SetArcDirNamePIA;
      property ArcDirNameSIRC: string read GetArcDirNameSIRC write SetArcDirNameSIRC;
   public
      { New }
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      {}
      function CreateArchiver  (ASourceFiles, ADestArchiveName: string; AArcPIA: string;
                                AWithSubdir: Boolean): Cardinal;
      function ExtractArchiver (ASourceFile, ADestPathName: string): Cardinal;
      function CheckKPD        (ASourceFiles: string; AWithSubdir: Boolean): Cardinal;
      function RemoveKPD: Cardinal;
      function SetKPD          (ASourceFiles: string; AWithSubdir: Boolean): Cardinal;
      {}
      function ExtractArchivers(ASourceFiles, ADestArchiveName: string; AWithSubdir: Boolean): Cardinal;
      {}
      property PasswordConfig: string read GetPasswordConfig write SetPasswordConfig;
      property PasswordPIA: string read GetPasswordPIA write SetPasswordPIA;
      property ResItem[Index: Integer]: TCollectionItemKPD1 read GetResItem;
      property Count: Integer read GetCount;
      property KeyDisk: string read GetKeyDisk write SetKeyDisk;
   end;

   TWinSAED = class(TCustomArchive)
   private
      { cb_getLibVersion }
      Fvmaj: DWORD;
      Fvmin: DWORD;
      Flibtype: DWORD;
      FLIBParams: cb_LIBPARAMS;
      {}
      FResultFunction: Integer;
      {}
      FArcDirNameSIA: PChar;
      FArcDirNameSIRC: PChar;
      FArcDirNamePIA: PChar;
      FArcPIA: PChar;
      FPasswordConfig: PChar;
      FPasswordPIA: PChar;
      FKeyDisk: PChar;
      FResArcMail: TCollection;
      function GetArcPIA: string;
      procedure SetArcPIA(const Value: string);
      function GetPasswordConfig: string;
      procedure SetPasswordConfig(const Value: string);
      function GetPasswordPIA: string;
      procedure SetPasswordPIA(const Value: string);
      function GetKeyDisk: string;
      procedure SetKeyDisk(const Value: string);
      function GetArcDirNameSIA: string;
      procedure SetArcDirNameSIA(const Value: string);
      function GetArcDirNamePIA: string;
      procedure SetArcDirNamePIA(const Value: string);
      function GetArcDirNameSIRC: string;
      procedure SetArcDirNameSIRC(const Value: string);
      function HandleException (E: Exception): Boolean;
      procedure GetResultKPD1;
      procedure GetResultKPD2;
      function GetResItem(Index: Integer): TCollectionItemKPD1;
      function GetCount: Integer;
      {}
      function GetVersion: string;
      function GetCurrentUser: string;
      { Property }
      property ArcPIA: string read GetArcPIA write SetArcPIA;
      property ArcDirNameSIA: string read GetArcDirNameSIA write SetArcDirNameSIA;
      property ArcDirNamePIA: string read GetArcDirNamePIA write SetArcDirNamePIA;
      property ArcDirNameSIRC: string read GetArcDirNameSIRC write SetArcDirNameSIRC;
   public
      { New }
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      {}
      function InitLib (Options: DWORD; const Password: string): integer;
      function InitLibDirect: integer;
      function DoneLib: integer;
      function CreateArchiver  (ASourceFiles, ADestArchiveName: string; AArcPIA: Array Of PChar;
                                AWithSubdir: Boolean): Cardinal;
      function ExtractArchiver (ASourceFile, ADestPathName: string): Cardinal;
      procedure CreateListFileNames(ASourceFiles: string; AWithSubdir: Boolean);
      function CheckKPD: Cardinal;
      function RemoveKPD: Cardinal;
      function SetKPD          (ASourceFiles: string; AWithSubdir: Boolean): Cardinal;
      {}
      function ExtractArchivers(ASourceFiles, ADestArchiveName: string; AWithSubdir: Boolean): Cardinal;
      {}
      procedure SetLIBParams(piaName,siaDir,sircDir,WorkDir: string;
         //piaPasswordFunc: Pcb_PASSWORDFUNC;
         Options: DWORD; const Password: string);
      {}
      property PasswordConfig: string read GetPasswordConfig write SetPasswordConfig;
      property PasswordPIA: string read GetPasswordPIA write SetPasswordPIA;
      property ResItem[Index: Integer]: TCollectionItemKPD1 read GetResItem;
      property Count: Integer read GetCount;
      property KeyDisk: string read GetKeyDisk write SetKeyDisk;
      {}
      property Version: string read GetVersion;
      property CurrentUser: string read GetCurrentUser;
      property ResultFunction: Integer read FResultFunction;
   end;

   TSAES = class(TCustomArchive)
   private
      { cb_getLibVersion }
      Fvmaj: DWORD;
      Fvmin: DWORD;
      Flibtype: DWORD;
      FLIBParams: cb_LIBPARAMS;
      {}
      FResultFunction: Integer;
      {}
      FArcDirNameSIA: PChar;
      FArcDirNameSIRC: PChar;
      FArcDirNamePIA: PChar;
      FArcPIA: PChar;
      FPasswordConfig: PChar;
      FPasswordPIA: PChar;
      FKeyDisk: PChar;
      FResArcMail: TCollection;
      function GetArcPIA: string;
      procedure SetArcPIA(const Value: string);
      function GetPasswordConfig: string;
      procedure SetPasswordConfig(const Value: string);
      function GetPasswordPIA: string;
      procedure SetPasswordPIA(const Value: string);
      function GetKeyDisk: string;
      procedure SetKeyDisk(const Value: string);
      function GetArcDirNameSIA: string;
      procedure SetArcDirNameSIA(const Value: string);
      function GetArcDirNamePIA: string;
      procedure SetArcDirNamePIA(const Value: string);
      function GetArcDirNameSIRC: string;
      procedure SetArcDirNameSIRC(const Value: string);
      function HandleException (E: Exception): Boolean;
      procedure GetResultKPD1;
      procedure GetResultKPD2;
      function GetResItem(Index: Integer): TCollectionItemKPD1;
      function GetCount: Integer;
      {}
      function GetVersion: string;
      function GetCurrentUser: string;
      { Property }
      property ArcPIA: string read GetArcPIA write SetArcPIA;
      property ArcDirNameSIA: string read GetArcDirNameSIA write SetArcDirNameSIA;
      property ArcDirNamePIA: string read GetArcDirNamePIA write SetArcDirNamePIA;
      property ArcDirNameSIRC: string read GetArcDirNameSIRC write SetArcDirNameSIRC;
   public
      { New }
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      {}
      function InitLib (Options: DWORD; const Password: string): integer;
      function InitLibDirect: integer;
      function DoneLib: integer;
      function CreateArchiver  (ASourceFiles, ADestArchiveName: string; AArcPIA: Array Of PChar;
                                AWithSubdir: Boolean): Cardinal;
      function ExtractArchiver (ASourceFile, ADestPathName: string): Cardinal;
      procedure CreateListFileNames(ASourceFiles: string; AWithSubdir: Boolean);
      function CheckKPD: Cardinal;
      function RemoveKPD: Cardinal;
      function SetKPD          (ASourceFiles: string; AWithSubdir: Boolean): Cardinal;
      {}
      function ExtractArchivers(ASourceFiles, ADestArchiveName: string; AWithSubdir: Boolean): Cardinal;
      {}
      procedure SetLIBParams(piaName,siaDir,sircDir,WorkDir: string;
         //piaPasswordFunc: Pcb_PASSWORDFUNC;
         Options: DWORD; const Password: string);
      {}
      property PasswordConfig: string read GetPasswordConfig write SetPasswordConfig;
      property PasswordPIA: string read GetPasswordPIA write SetPasswordPIA;
      property ResItem[Index: Integer]: TCollectionItemKPD1 read GetResItem;
      property Count: Integer read GetCount;
      property KeyDisk: string read GetKeyDisk write SetKeyDisk;
      {}
      property Version: string read GetVersion;
      property CurrentUser: string read GetCurrentUser;
      property ResultFunction: Integer read FResultFunction;
   end;

   TARJ = class(TCustomArchive)
   private
   public
      { New }
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      function Execute(Command: TARCCommand): Boolean;
   end;

const
   ArcMailFileName = 'ArcMail.exe';
   ArcMailWinSAEDFileName = 'WinSaed.exe';

function ExistsFD(const FDD: string): Boolean;
function ProgramArcMailExists(const PathArcMail: string): Boolean;
function ProgramArcMailWinSAEDExists(const PathArcMail: string): Boolean;

implementation

const
   { Archive }
   SCheckKPD = 'Проверка подписи ...';
   SCheckKPDError = 'Ошибка при проверке подписи!';
   SCheckKPDOk = 'Проверка подписи завершена.';
   SRemoveKPD = 'Удаление подписи ...';
   SRemoveKPDError = 'Ошибка при удалении подписи!';
   SRemoveKPDOk = 'Удаление подписи завершено.';
   SSetKPD = 'Установить подпись ...';
   SSetKPDError = 'Ошибка при установке подписи!';
   SSetKPDOk = 'Установка подписи завершена.';
   SCreateArchive = 'Создание архива ';
   SListFiles = 'Список файлов:';
   SCreateArchiveError = 'Ошибка при создании архива!';
   SCreateArchiveOk = 'Создание архива завершено.';
   SDelDir = 'Очистка директории ';
   SArchiveNotAvailable = 'Система архивирования не определена!';
   SExtractArchives = 'Раскрытие архивов ...';
   SExtractArchive = 'Раскрытие архива ';
   SExtractArchiveError = 'Ошибка при раскрытии архива! ';
   SExtractArchiveOk = 'Раскрытие архива завершено.';
   SExtractArchivesOk = 'Раскрытие архивов завершено.';

const
   FileListName: string  = 'fl.txt';
   FileResult  : string  = 'fr.txt';

const
   ArcMailErrorMinCount = 0;
   ArcMailErrorMaxCount = 19;
   ArcMailError: array [ArcMailErrorMinCount..ArcMailErrorMaxCount] of string = (
      '0 - все в порядке',
      '1 - пользователь прервал операцию',
      '2 - КПД у файла нет',
      '3 - СИА не зарегистрирован',
      '4 - введен пароль для ПИА, не закрытого паролем',
      '5 - нет пароля для закрытого паролем ПИА',
      '6 - пароль не верен',
      '7 - не верна дата ИА',
      '8 - не фатальная ошибка ввода/вывода',
      '9 - не найден СИА для проверки',
      '10- не хватает памяти',
      '11- не верна дата КПД',
      '12- не верен КПД СИА',
      '13- не верен КПД файла',
      '14- ошибка записи выходного файла',
      '15- синтаксическая ошибка в опциях',
      '16- фатальная ошибка (нет необходимых программе файлов и т.д.)',
      '17- отсутствует или поврежден конфигурационный файл',
      '18- в дисководе нет ключевой дискеты',
      '19- не удается выполнить указанную программу.'
   );

var
   APPFileMemoLog: TFileMemoLog;

{ ProgramArcMailExists }

function ProgramArcMailExists(const PathArcMail: string): Boolean;
var s: string;
begin
   s := IncludeTrailingBackslash(PathArcMail);
   Result := FileExists(s+ArcMailFileName);
end;

{ ProgramArcMailWinSAEDExists }

function ProgramArcMailWinSAEDExists(const PathArcMail: string): Boolean;
var s: string;
begin
   s := IncludeTrailingBackslash(PathArcMail);
   Result := FileExists(s+ArcMailWinSAEDFileName);
end;

function ExistsFD(const FDD: string): Boolean;
var
   l1,l2,l3,l4: dword;
begin
   Result := GetDiskFreeSpace(PChar(FDD),l1,l2,l3,l4);
end;

{ TCollectionItemKPD1 }

constructor TCollectionItemKPD1.Create(Collection: TCollection);
begin
   inherited Create(Collection);
   FileName := '';
   FKPD := TCollection.Create(TCollectionItemKPD2);
end;

destructor TCollectionItemKPD1.Destroy;
begin
   StrDispose(FFileName);
   FKPD.Free;
   inherited Destroy;
end;

function TCollectionItemKPD1.GetFileName: string;
begin
   Result := StrPas(FFileName);
end;
procedure TCollectionItemKPD1.SetFileName(const Value: string);
begin
   if FFileName <> nil then StrDispose(FFileName);
   FFileName := StrAlloc(Length(Value)+1);
   StrPCopy(FFileName, Value);
end;

function TCollectionItemKPD1.GetKPDItem(Index: Integer): TCollectionItemKPD2;
begin
   Result := TCollectionItemKPD2(FKPD.Items[Index]);
end;

{ TCollectionItemKPD2 }

constructor TCollectionItemKPD2.Create(Collection: TCollection);
begin
   inherited Create(Collection);
   NameSIA := '';
   InfoSIA := '';
end;

destructor TCollectionItemKPD2.Destroy;
begin
   StrDispose(FNameSIA);
   StrDispose(FInfoSIA);
   inherited Destroy;
end;

function TCollectionItemKPD2.GetInfoSIA: string;
begin
   Result := StrPas(FInfoSIA);
end;
procedure TCollectionItemKPD2.SetInfoSIA(const Value: string);
begin
   if FInfoSIA <> nil then StrDispose(FInfoSIA);
   FInfoSIA := StrAlloc(Length(Value)+1);
   StrPCopy(FInfoSIA, Value);
end;

function TCollectionItemKPD2.GetNameSIA: string;
begin
   Result := StrPas(FNameSIA);
end;
procedure TCollectionItemKPD2.SetNameSIA(const Value: string);
begin
   if FNameSIA <> nil then StrDispose(FNameSIA);
   FNameSIA := StrAlloc(Length(Value)+1);
   StrPCopy(FNameSIA, Value);
end;

{ TCustomArchive }

constructor TCustomArchive.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   FErrors := TStringList.Create;
   FPathName := TStringList.Create;
   ArcName := '';
   FileName := '';
   ArcDirName := '';
   ParamStr := '';
   FWithSubDir := False;
   FScanDirFiles := TScanDirFiles.Create;
   { TempDir }
   FTempDir := StrAlloc(255);
   GetTempPath(255, FTempDir);
   TempDir := ExtractFileDir(TempDir);
   TempDir := 'c:\work';
   if not DirectoryExists(TempDir) then ForceDirectories(TempDir);
end;

destructor TCustomArchive.Destroy;
begin
   if FileExists(TempFileRes) then SysUtils.DeleteFile(TempFileRes);
   FScanDirFiles.Free;
   StrDispose(FTempDir);
   StrDispose(FArcName);
   StrDispose(FFileName);
   StrDispose(FParamStr);
   StrDispose(FArcDirName);
   FErrors.Free;
   FPathName.Free;
   inherited Destroy;
end;

function TCustomArchive.ErrorString: string;
begin
   Result := '';
   if (FStatus >= ArcMailErrorMinCount) and (FStatus <= ArcMailErrorMaxCount) then begin
      if FStatus = 0 then Result := ArcMailError[FStatus]
                     else Result := 'Error Archive: '+ArcMailError[FStatus];
      end
   else begin
      if FErrors.Count > 0 then
         if FErrors.Count > 1 then Result := 'Error Archive: '+FErrors.Strings[0]
                              else Result := 'Error Archive: Many Errors';
   end;
end;

function TCustomArchive.GetTempDir: string;
begin
   Result := StrPas(FTempDir);
end;
procedure TCustomArchive.SetTempDir(const Value: string);
begin
   if FTempDir <> nil then StrDispose(FTempDir);
   FTempDir := StrAlloc(Length(Value)+1);
   StrPCopy(FTempDir, Value);
end;

function TCustomArchive.GetTempFile: string;
begin
   Result := IncludeTrailingBackslash(TempDir)+FileListName;
end;

function TCustomArchive.GetTempFileRes: string;
begin
   Result := IncludeTrailingBackslash(TempDir)+FileResult;
end;

function TCustomArchive.GetArcName: string;
begin
   Result := StrPas(FArcName);
end;
procedure TCustomArchive.SetArcName(const Value: string);
begin
   if FArcName <> nil then StrDispose(FArcName);
   FArcName := StrAlloc(Length(Value)+1);
   StrPCopy(FArcName, Value);
end;

function TCustomArchive.GetFileName: string;
begin
   Result := StrPas(FFileName);
end;
procedure TCustomArchive.SetFileName(const Value: string);
begin
   if FFileName <> nil then StrDispose(FFileName);
   FFileName := StrAlloc(Length(Value)+1);
   StrPCopy(FFileName, Value);
end;

function TCustomArchive.GetParamStr: string;
begin
   Result := StrPas(FParamStr);
end;
procedure TCustomArchive.SetParamStr(const Value: string);
begin
   if FParamStr <> nil then StrDispose(FParamStr);
   FParamStr := StrAlloc(Length(Value)+1);
   StrPCopy(FParamStr, Value);
end;

function TCustomArchive.GetArcDirName: string;
begin
   Result := StrPas(FArcDirName);
end;
procedure TCustomArchive.SetArcDirName(const Value: string);
begin
   if FArcDirName <> nil then StrDispose(FArcDirName);
   FArcDirName := StrAlloc(Length(Value)+1);
   StrPCopy(FArcDirName, Value);
end;

function TCustomArchive.GetArcFileName: string;
begin
   Result := StrPas(FArcFileName);
end;
procedure TCustomArchive.SetArcFileName(const Value: string);
begin
   if FArcFileName <> nil then StrDispose(FArcFileName);
   FArcFileName := StrAlloc(Length(Value)+1);
   StrPCopy(FArcFileName, Value);
end;

{ TArcMail }

constructor TArcMail.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   ArcDirNameSIA := '';
   ArcDirNamePIA := '';
   ArcDirNameSIRC := '';
   ArcPIA := '';
   PasswordConfig := '';
   PasswordPIA := '';
   KeyDisk := 'a:\';
   FResArcMail := TCollection.Create(TCollectionItemKPD1);
end;

destructor TArcMail.Destroy;
begin
   FResArcMail.Free;
   StrDispose(FArcDirNameSIA);
   StrDispose(FArcDirNamePIA);
   StrDispose(FArcDirNameSIRC);
   StrDispose(FArcPIA);
   StrDispose(FPasswordConfig);
   StrDispose(FPasswordPIA);
   inherited Destroy;
end;

function TArcMail.HandleException (E: Exception): Boolean;
begin
   Result := True;
   if Result then FErrors.Add(E.Message);
end;

function TArcMail.GetArcPIA: string;
begin
   Result := StrPas(FArcPIA);
end;
procedure TArcMail.SetArcPIA(const Value: string);
begin
   if FArcPIA <> nil then StrDispose(FArcPIA);
   FArcPIA := StrAlloc(Length(Value)+1);
   StrPCopy(FArcPIA, Value);
end;

function TArcMail.GetPasswordConfig: string;
begin
   Result := StrPas(FPasswordConfig);
end;
procedure TArcMail.SetPasswordConfig(const Value: string);
begin
   if FPasswordConfig <> nil then StrDispose(FPasswordConfig);
   FPasswordConfig := StrAlloc(Length(Value)+1);
   StrPCopy(FPasswordConfig, Value);
end;

function TArcMail.GetPasswordPIA: string;
begin
   Result := StrPas(FPasswordPIA);
end;
procedure TArcMail.SetPasswordPIA(const Value: string);
begin
   if FPasswordPIA <> nil then StrDispose(FPasswordPIA);
   FPasswordPIA := StrAlloc(Length(Value)+1);
   StrPCopy(FPasswordPIA, Value);
end;

function TArcMail.GetKeyDisk: string;
begin
   Result := StrPas(FKeyDisk);
end;
procedure TArcMail.SetKeyDisk(const Value: string);
begin
   if FKeyDisk <> nil then StrDispose(FKeyDisk);
   FKeyDisk := StrAlloc(Length(Value)+1);
   StrPCopy(FKeyDisk, Value);
end;

function TArcMail.GetArcDirNameSIA: string;
begin
   Result := StrPas(FArcDirNameSIA);
end;
procedure TArcMail.SetArcDirNameSIA(const Value: string);
begin
   if FArcDirNameSIA <> nil then StrDispose(FArcDirNameSIA);
   FArcDirNameSIA := StrAlloc(Length(Value)+1);
   StrPCopy(FArcDirNameSIA, Value);
end;

function TArcMail.GetArcDirNamePIA: string;
begin
   Result := StrPas(FArcDirNamePIA);
end;
procedure TArcMail.SetArcDirNamePIA(const Value: string);
begin
   if FArcDirNamePIA <> nil then StrDispose(FArcDirNamePIA);
   FArcDirNamePIA := StrAlloc(Length(Value)+1);
   StrPCopy(FArcDirNamePIA, Value);
end;

function TArcMail.GetArcDirNameSIRC: string;
begin
   Result := StrPas(FArcDirNameSIRC);
end;
procedure TArcMail.SetArcDirNameSIRC(const Value: string);
begin
   if FArcDirNameSIRC <> nil then StrDispose(FArcDirNameSIRC);
   FArcDirNameSIRC := StrAlloc(Length(Value)+1);
   StrPCopy(FArcDirNameSIRC, Value);
end;

procedure TArcMail.GetResultKPD1(const F: string);
var
   Res: TStringList;
   KPD1 : TCollectionItemKPD1;
   i: Integer;
   s : string;
begin
   if FResArcMail <> nil then FResArcMail.Free;
   FResArcMail := TCollection.Create(TCollectionItemKPD1);
   Res := TStringList.Create;
   try
      Res.LoadFromFile(TempFileRes);
   except
   end;
   i := 0;
   while i < Res.Count do begin
      KPD1 := FResArcMail.Add as TCollectionItemKPD1;
      s := Res.Strings[i+0];
      KPD1.FileName := s;
      s := Res.Strings[i+1];
      try
         KPD1.ResCode := StrToInt(s);
      except
      end;
      s := Res.Strings[i+2];
      try
         KPD1.NumberKPD := StrToInt(s);
      except
      end;
      i := i+3;
   end;
   Res.Free;
end;

procedure TArcMail.GetResultKPD2(const F: string);
var
   Res: TStringList;
   KPD1 : TCollectionItemKPD1;
   KPD2 : TCollectionItemKPD2;
   i,j: Integer;
   s : string;
begin
   if FResArcMail <> nil then FResArcMail.Free;
   FResArcMail := TCollection.Create(TCollectionItemKPD1);
   Res := TStringList.Create;
   Res.LoadFromFile(TempFileRes);
   i := 0;
   while i < Res.Count do begin
      KPD1 := FResArcMail.Add as TCollectionItemKPD1;
      s := Res.Strings[i+0];
      KPD1.FileName := s;
      s := Res.Strings[i+1];
      KPD1.ResCode := StrToInt(s);
      s := Res.Strings[i+2];
      KPD1.NumberKPD := StrToInt(s);
      for j:=0 to KPD1.NumberKPD-1 do begin
         KPD2 := KPD1.FKPD.Add as TCollectionItemKPD2;
         s := Res.Strings[i+3+j];
         KPD2.NameSIA := Copy (s, 1, 8);
         KPD2.InfoSIA := Copy (s, 10, 40);
         KPD2.DateCreateKPD := StrToDate(ReplaceStr(Copy(s, 51, 10), '.', DateSeparator));
         KPD2.DateEndKPD := StrToDate(ReplaceStr(Copy(s, 62, 10), '.', DateSeparator));
         KPD2.ResKPD := StrToInt(Copy(s, 73, 2));
      end;
      i := i+3+KPD1.NumberKPD;
   end;
   Res.Free;
end;

function TArcMail.GetResItem(Index: Integer): TCollectionItemKPD1;
begin
   Result := TCollectionItemKPD1(FResArcMail.Items[Index]);
end;

function TArcMail.GetCount: Integer;
begin
   Result := FResArcMail.Count;
end;

function TArcMail.Execute(Command: TARCCommand): Boolean;
var
   Save : string;
   //WorkDir : string;
   EFileName : string;
   EArcDirName : string;
   EArcFileName : string;
   DefaultParamStr: string;
   i: Integer;
begin
   Save := GetCurrentDir;
   EFileName := ExpandFileName(FileName);
   EArcDirName := ExpandFileName(ArcDirName);
   EArcFileName := ExpandFileName(ArcFileName);
   DefaultParamStr := ' -o'+TempFileRes;
   if PasswordConfig <> '' then DefaultParamStr := DefaultParamStr+' -q'+PasswordConfig;
   if PasswordPIA    <> '' then DefaultParamStr := DefaultParamStr+' -w'+PasswordPIA;
   case Command of
      acAdd: begin
         //ChDir(ExtractFilePath(FileName));
         //WorkDir := GetCurrentDir;
         ChDir(WorkDir);
         if WithSubDir then begin
            ParamStr := 'a'+DefaultParamStr+' -l'+EFileName+' -a'+ArcDirName+' -m'+ArcFileName+' -j'+ArcPIA+' -r';
            end
         else begin
            PathName.SaveToFile(TempFile);
            ParamStr := 'a'+DefaultParamStr+' -c'+TempFile+' -a'+ArcDirName+' -m'+ArcFileName+' -j'+ArcPIA;
         end;
      end;
      acExtract: begin
         ChDir(ArcDirName);
         WorkDir := GetCurrentDir;
         if WithSubDir then begin
            ParamStr := 'u'+DefaultParamStr+' -l'+EArcFileName+' -y'+EArcDirName;
            end
         else begin
            ParamStr := 'u'+DefaultParamStr+' -l'+EArcFileName+' -y'+EArcDirName+' -e';
            ParamStr := 'u'+DefaultParamStr+' -l'+EArcFileName+' -y'+EArcDirName;
         end;
      end;
      acSetKPD: begin
         ChDir(ExtractFilePath(FileName));
         WorkDir := GetCurrentDir;
         if WithSubDir then begin
            ParamStr := 's'+DefaultParamStr+' -l'+EFileName+' -r';
            end
         else begin
            PathName.SaveToFile(TempFile);
            ParamStr := 's'+DefaultParamStr+' -c'+TempFile;
         end;
      end;
      acCheckKPD: begin
         ChDir(ExtractFilePath(FileName));
         WorkDir := GetCurrentDir;
         if WithSubDir then begin
            ParamStr := 't'+DefaultParamStr+' -l'+EFileName+' -r';
            end
         else begin
            PathName.SaveToFile(TempFile);
            ParamStr := 't'+DefaultParamStr+' -c'+TempFile;
         end;
      end;
      acRemoveKPD: begin
         ChDir(ExtractFilePath(FileName));
         WorkDir := GetCurrentDir;
         FileMemoLog.LogString[tlsProcess,1] := 'WorkDir='+WorkDir;
         if WithSubDir then begin
            ParamStr := 'd'+DefaultParamStr+' -l'+EFileName+' -n-1'+' -r';
            end
         else begin
            PathName.SaveToFile(TempFile);
            FileMemoLog.LogString[tlsProcess,1] := 'TempFile='+TempFile;
            for i:=0 to PathName.Count-1 do begin
               FileMemoLog.LogString[tlsProcess,1] := PathName.Strings[i];
            end;
            ParamStr := 'd'+DefaultParamStr+' -c'+TempFile+' -n-1';
         end;
      end;
   end;
   //Result := ExistsFD(KeyDisk);
   Result := True;
   if Result then begin
      FStatus := 0;
      //Result := WinExecAndWait(ArcName, ParamStr, sw_Hide, FStatus);

      //Result := ExecuteAll(ArcName, ParamStr, WorkDir, True, SW_HIDE, FStatus);

      Result := ExecuteShell(ArcName, ParamStr, WorkDir, True, SW_HIDE, FStatus);
      (*
      if not Result then begin
         FileMemoLog.LogString[tlsProcess,1] := 'ERROR!!!';
         FileMemoLog.LogString[tlsProcess,1] := ArcName+' '+ParamStr;
         end
      else begin
         FileMemoLog.LogString[tlsProcess,1] := 'GOOD!!!';
         FileMemoLog.LogString[tlsProcess,1] := ArcName+' '+ParamStr;
      end;
      *)
      if Result then begin
         case Command of
            acAdd: begin
               if Result then GetResultKPD1(TempFileRes);
            end;
            acExtract: begin
               if Result then GetResultKPD2(TempFileRes);
            end;
            acCheckKPD: begin
               if Result then GetResultKPD2(TempFileRes);
            end;
            acSetKPD: begin
            end;
            acRemoveKPD: begin
               if Result then GetResultKPD1(TempFileRes);
            end;
         end;
         end
      else begin
         if FStatus = 0 then FStatus := 19;
         FErrors.Add(ArcMailError[FStatus]);
      end;
      end
   else begin
      FStatus := 18;
      FErrors.Add(ArcMailError[FStatus]);
   end;
   ChDir(Save);
end;

procedure TArcMail.CreateListFileNames(ASourceFiles: string; AWithSubdir: Boolean);
var
   i: Integer;
   s: string;
begin
   PathName.Clear;
   ScanDirFiles.OnFile := nil;
   ScanDirFiles.DelFile := False;
   if AWithSubDir then
      ScanDirFiles.Execute(ASourceFiles, sfDirectories)
   else
      ScanDirFiles.Execute(ASourceFiles, sfDirectory);
   for i:=0 to ScanDirFiles.FileList.Count-1 do begin
      s := ScanDirFiles.FileList.Strings[i];
      FileSetAttr(s, FileGetAttr(s) and (faReadOnly xor $FF));
      Delete(s, 1, Length(ExtractFilePath(ASourceFiles)));
      PathName.Add(s);
   end;
end;

function TArcMail.CheckKPD (ASourceFiles: string; AWithSubdir: Boolean): Cardinal;
var
   i,j: Integer;
begin
   Result := 0;
   WithSubDir := AWithSubDir;
   KeyDisk := 'a:';
   { Arc Directory }
   ArcDirName := '';
   { Arc Filename }
   ArcFileName := '';
   { From }
   FileName := ASourceFiles;
   { Create List of Files }
   CreateListFileNames(ASourceFiles, AWithSubDir);
   {------------------------------------------------------}
   if PathName.Count > 0 then begin
      { Begin CheckKPD }
      if Assigned(FileMemoLog) then begin
         FileMemoLog.LogString[tlsProcess,1] := SCheckKPD;
      end;
      if (not Execute(acCheckKPD)) or (Status <> 0) then begin
         if Assigned(FileMemoLog) then begin
            FileMemoLog.LogCode := tlcAnsi;
            for i:=0 to Count-1 do begin
               FileMemoLog.LogString[tlsError,1] := Format('%-2d %-2d %s',
                  [ResItem[i].ResCode,ResItem[i].NumberKPD,ResItem[i].FileName]);
            end;
            FileMemoLog.LogCode := tlcOEM;
            FileMemoLog.LogString[tlsError,1] := SCheckKPDError;
            FileMemoLog.LogString[tlsError,2] := ErrorString;
         end;
         Result := 1; { Create Archive-file Error! }
         end
      else begin
         if Assigned(FileMemoLog) then begin
            FileMemoLog.LogCode := tlcAnsi;
            for i:=0 to Count-1 do begin
               FileMemoLog.LogString[tlsProcess,1] := Format('%-2d %-2d %s',
                  [ResItem[i].ResCode,ResItem[i].NumberKPD,ResItem[i].FileName]);
               for j:=0 to ResItem[i].NumberKPD-1 do begin
                  FileMemoLog.LogString[tlsProcess,1] := Format('%-2d    %-8s %-40s',// %s %s',
                     [ResItem[i].KPDItem[j].ResKPD,ResItem[i].KPDItem[j].NameSIA,ResItem[i].KPDItem[j].InfoSIA]);
               end;
            end;
            FileMemoLog.LogCode := tlcOEM;
         end;
         Result := 0;
      end;

      { End CheckKPD }
      if Assigned(FileMemoLog) then begin
         FileMemoLog.LogString[tlsProcess,1] := SCheckKPDOk+' Result '+IntToStr(Result);
      end;
   end;
end;

function TArcMail.RemoveKPD: Cardinal;
var
   i: Integer;
begin
   { PathName должен уже быть }
   Result := 0;
   WithSubDir := False;
   KeyDisk := 'a:\';
   if PathName.Count > 0 then begin
      { Begin RemoveKPD }
      if Assigned(FileMemoLog) then begin
         FileMemoLog.LogString[tlsProcess,1] := SRemoveKPD;
      end;
      if (not Execute(acRemoveKPD)) or (Status <> 0) then begin
         if Assigned(FileMemoLog) then begin
            FileMemoLog.LogCode := tlcAnsi;
            for i:=0 to Count-1 do begin
               FileMemoLog.LogString[tlsError,2] := Format('%-2d %-2d %s',
                  [ResItem[i].ResCode, ResItem[i].NumberKPD, ResItem[i].Filename]);
            end;
            FileMemoLog.LogCode := tlcOEM;
            FileMemoLog.LogString[tlsError,2] := SRemoveKPDError;
            FileMemoLog.LogString[tlsError,3] := ErrorString;
            FileMemoLog.LogString[tlsError,3] := ArcName+' '+ParamStr;
         end;
         Result := 1; { Error! }
         end
      else begin
         { Result }
         if Assigned(FileMemoLog) then begin
            FileMemoLog.LogCode := tlcAnsi;
            for i:=0 to Count-1 do begin
               FileMemoLog.LogString[tlsProcess,2] := Format('%-2d %-2d %s',
                  [ResItem[i].ResCode, ResItem[i].NumberKPD, ResItem[i].Filename]);
            end;
            FileMemoLog.LogCode := tlcOEM;
         end;
         Result := 0;
      end;

      { End RemoveKPD }
      if Assigned(FileMemoLog) then begin
         FileMemoLog.LogString[tlsProcess,1] := SRemoveKPDOk+' Result '+IntToStr(Result);
      end;
   end;
end;

function TArcMail.SetKPD (ASourceFiles: string; AWithSubdir: Boolean): Cardinal;
begin
   Result := 0;
   WithSubDir := AWithSubDir;
   KeyDisk := 'a:\';
   { Arc Directory }
   ArcDirName := '';
   { Arc Filename }
   ArcFileName := '';
   { From }
   FileName := ASourceFiles;
   { Create List of Files }
   CreateListFileNames(ASourceFiles, AWithSubDir);
   if PathName.Count > 0 then begin
      { Begin SetKPD }
      if Assigned(FileMemoLog) then begin
         FileMemoLog.LogString[tlsProcess,1] := SSetKPD;
      end;
      if (not Execute(acSetKPD)) or (Status <> 0) then begin
         if Assigned(FileMemoLog) then begin
            FileMemoLog.LogCode := tlcAnsi;
            FileMemoLog.AddFile(TempFileRes,1);
            FileMemoLog.LogCode := tlcOEM;
            FileMemoLog.LogString[tlsError,2] := SSetKPDError;
            FileMemoLog.LogString[tlsError,3] := ErrorString;
         end;
         Result := 1; { Create Archive-file Error! }
         end
      else begin
         if Assigned(FileMemoLog) then begin
            FileMemoLog.LogCode := tlcAnsi;
            FileMemoLog.AddFile(TempFileRes,1);
            FileMemoLog.LogCode := tlcOEM;
         end;
         Result := 0;
      end;

      { End SetKPD }
      if Assigned(FileMemoLog) then begin
         FileMemoLog.LogString[tlsProcess,1] := SSetKPDOk+' Result '+IntToStr(Result);
      end;
   end;
end;

function TArcMail.CreateArchiver  (ASourceFiles: string;
                                   ADestArchiveName: string; AArcPIA: string; AWithSubdir: Boolean): Cardinal;
var
   i: Integer;
   s1,s2 : string;
begin
   Result := 0;
   { KeyDisk }
   KeyDisk := 'a:\';
   { Arc PIA }
   ArcPIA := AArcPIA;
   WithSubDir := False;
   { Arc Filename }
   ArcFileName := ExtractFileName(ADestArchiveName);
   { From }
   FileName := ASourceFiles;
   { Arc Directory }
   ArcDirName := ExtractFilePath(ADestArchiveName);
   ArcDirName := IncludeTrailingBackslash(TempDir);
   {----------------------------------------------------------}
   if not DirectoryExists(FileName) then begin
      WorkDir := ExtractFilePath(FileName);
      CreateListFileNames(ASourceFiles, AWithSubDir);
      end
   else begin
      { PathName должен быть уже создан }
      WorkDir := FileName;
   end;
   {----------------------------------------------------------}
   if PathName.Count > 0 then begin
      FileMemoLog.LogString[tlsProcess,0] := '---------------------------------------------------';
      FileMemoLog.LogString[tlsProcess,0] := sCreateArchive+' ...';
      FileMemoLog.LogString[tlsProcess,1] := 'Архив: '+IncludeTrailingBackslash(ArcDirName)+ADestArchiveName+'.LCK';
      FileMemoLog.LogString[tlsProcess,1] := sListFiles;
      (*
      for i:=0 to ScanDirFiles.FileList.Count-1 do begin
         FileMemoLog.LogString[tlsProcess,2] := ScanDirFiles.FileList.Strings[i];
      end;
      *)
      for i:=0 to PathName.Count-1 do begin
         FileMemoLog.LogString[tlsProcess,2] := IncludeTrailingBackslash(WorkDir)+PathName.Strings[i];
      end;

      { Create Archive }
      if (not Execute(acAdd)) or (Status <> 0) then begin
         FileMemoLog.LogCode := tlcAnsi;
         FileMemoLog.AddFile(TempFileRes,0);
         FileMemoLog.LogCode := tlcOEM;
         FileMemoLog.LogString[tlsError,1] := SCreateArchiveError;
         FileMemoLog.LogString[tlsError,2] := ErrorString;
         FileMemoLog.LogString[tlsError,2] := ArcName;
         Result := 1; { Create Archive-file Error! }
         end
      else begin
         { Copy to DestPath }
         s1 := '';
         if Count > 0 then s1 := ResItem[0].FileName;
         if S1 = '' then begin
            FileMemoLog.LogString[tlsError,1] := 'Ошибка при при создании архива '+IncludeTrailingBackslash(ArcDirName)+ADestArchiveName+'.LCK';
            Result := 1; { Error not Copy file }
            end
         else begin
            FileMemoLog.LogString[tlsProcess,1] := 'Создание архива зввершено успешно';
            s2 := IncludeTrailingBackslash(WorkDir)+ExtractFileName(s1);
            if UpperCase(S1) = UpperCase(S2) then begin
               Result := 0;
               end
            else begin
               FileMemoLog.LogString[tlsProcess,1] := 'Копирование '+s1+' в '+s2;
               if Windows.CopyFile(PChar(s1), PChar(s2), LongBool(False)) then begin
                  { delete file from TempDir }
                  FileMemoLog.LogString[tlsProcess,1] := 'Удаление '+s1;
                  SysUtils.DeleteFile(s1);
                  FileMemoLog.LogString[tlsProcess,1] := 'Файл '+s1+' удален';
                  Result := 0;
                  end
               else begin
                  if Assigned(FileMemoLog) then begin
                     FileMemoLog.LogString[tlsError,1] := 'Ошибка при копировании файла ';
                     FileMemoLog.LogString[tlsError,1] := s1;
                  end;
                  Result := 1; { Error not Copy file }
               end;
            end;
         end;
      end;
      FileMemoLog.LogString[tlsProcess,0] := '---------------------------------------------------';
   end;
end;

function TArcMail.ExtractArchivers(ASourceFiles, ADestArchiveName: string; AWithSubdir: Boolean): Cardinal;
var
   ScanDir: TScanDirFiles;
   Res: Cardinal;
   i: Integer;
begin
   if Assigned(FileMemoLog) then begin
      FileMemoLog.LogString[tlsProcess,0] := '---------------------------------------------------';
      FileMemoLog.LogString[tlsProcess,0] := SExtractArchives;
   end;
   { ScanDir }
   ScanDir := TScanDirFiles.Create;
   ScanDir.OnFile := nil;
   ScanDir.DelFile := False;
   if AWithSubDir then
      ScanDir.Execute(ASourceFiles, sfDirectories)
   else
      ScanDir.Execute(ASourceFiles, sfDirectory);
   for i:=0 to ScanDir.FileList.Count-1 do begin
      Res := ExtractArchiver(ScanDir.FileList.Strings[i], ADestArchiveName);
   end;
   if Assigned(FileMemoLog) then begin
      FileMemoLog.LogString[tlsProcess,0] := SExtractArchivesOk;
   end;
   { Free }
   Result := ScanDir.Status;
   ScanDir.Free;
end;

function TArcMail.ExtractArchiver (ASourceFile, ADestPathName: string): Cardinal;
var
   s: string;
   i,j: Integer;
begin
   KeyDisk := 'a:\';
   ArcName := ArcName;
   WithSubDir := False;
   ArcDirName := ADestPathName;
   s := ASourceFile;
   ArcFileName := S;
   FileName := IncludeTrailingBackSlash(ADestPathName);

   if Assigned(FileMemoLog) then begin
      FileMemoLog.LogString[tlsProcess,1] := SExtractArchive+' ...';
      FileMemoLog.LogString[tlsProcess,2] := s;
   end;
   if (not Execute(acExtract)) or (Status <> 0) then begin
      if Assigned(FileMemoLog) then begin
         FileMemoLog.LogString[tlsError,1] := SExtractArchiveError;
         FileMemoLog.LogString[tlsError,2] := ErrorString;
         FileMemoLog.LogString[tlsError,3] := ArcName+' '+ParamStr;
      end;
      Result := 1;
      end
   else begin
      { Create PathName }
      PathName.Clear;
      for i:=0 to Count-1 do begin
         s := ResItem[i].FileName;
         PathName.Add(ExtractFileName(s));
      end;
      { FileMemoLog }
      if Assigned(FileMemoLog) then begin
         FileMemoLog.LogString[tlsProcess,1] := SExtractArchiveOk;
         FileMemoLog.LogCode := tlcAnsi;
         for i:=0 to Count-1 do begin
            FileMemoLog.LogString[tlsProcess,2] := Format('%-2d %-2d %s',
               [ResItem[i].ResCode, ResItem[i].NumberKPD, ResItem[i].FileName]);
            for j:=0 to ResItem[i].NumberKPD-1 do begin
               FileMemoLog.LogString[tlsProcess,2] := Format('%-2d    %-8s %-40s',
                  [ResItem[i].KPDItem[j].ResKPD,ResItem[i].KPDItem[j].NameSIA,ResItem[i].KPDItem[j].InfoSIA]);
            end;
         end;
         FileMemoLog.LogCode := tlcOEM;
      end;
      { Delete }
      FileDelete (ASourceFile);
      if Assigned(FileMemoLog) then begin
         FileMemoLog.LogString[tlsProcess,1] := 'Delete  Archive '+ASourceFile+' Ok!';
      end;
   end;
end;

{ TWinSAED }

constructor TWinSAED.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   ArcDirNameSIA := '';
   ArcDirNamePIA := '';
   ArcDirNameSIRC := '';
   ArcPIA := '';
   PasswordConfig := '';
   PasswordPIA := '';
   KeyDisk := 'a:\';
   FResArcMail := TCollection.Create(TCollectionItemKPD1);
end;

destructor TWinSAED.Destroy;
begin
   FResArcMail.Free;
   StrDispose(FArcDirNameSIA);
   StrDispose(FArcDirNamePIA);
   StrDispose(FArcDirNameSIRC);
   StrDispose(FArcPIA);
   StrDispose(FPasswordConfig);
   StrDispose(FPasswordPIA);
   inherited Destroy;
end;

function TWinSAED.HandleException (E: Exception): Boolean;
begin
   Result := True;
   if Result then FErrors.Add(E.Message);
end;

function TWinSAED.GetArcPIA: string;
begin
   Result := StrPas(FArcPIA);
end;
procedure TWinSAED.SetArcPIA(const Value: string);
begin
   if FArcPIA <> nil then StrDispose(FArcPIA);
   FArcPIA := StrAlloc(Length(Value)+1);
   StrPCopy(FArcPIA, Value);
end;

function TWinSAED.GetPasswordConfig: string;
begin
   Result := StrPas(FPasswordConfig);
end;
procedure TWinSAED.SetPasswordConfig(const Value: string);
begin
   if FPasswordConfig <> nil then StrDispose(FPasswordConfig);
   FPasswordConfig := StrAlloc(Length(Value)+1);
   StrPCopy(FPasswordConfig, Value);
end;

function TWinSAED.GetPasswordPIA: string;
begin
   Result := StrPas(FPasswordPIA);
end;
procedure TWinSAED.SetPasswordPIA(const Value: string);
begin
   if FPasswordPIA <> nil then StrDispose(FPasswordPIA);
   FPasswordPIA := StrAlloc(Length(Value)+1);
   StrPCopy(FPasswordPIA, Value);
end;

function TWinSAED.GetKeyDisk: string;
begin
   Result := StrPas(FKeyDisk);
end;
procedure TWinSAED.SetKeyDisk(const Value: string);
begin
   if FKeyDisk <> nil then StrDispose(FKeyDisk);
   FKeyDisk := StrAlloc(Length(Value)+1);
   StrPCopy(FKeyDisk, Value);
end;

function TWinSAED.GetArcDirNameSIA: string;
begin
   Result := StrPas(FArcDirNameSIA);
end;
procedure TWinSAED.SetArcDirNameSIA(const Value: string);
begin
   if FArcDirNameSIA <> nil then StrDispose(FArcDirNameSIA);
   FArcDirNameSIA := StrAlloc(Length(Value)+1);
   StrPCopy(FArcDirNameSIA, Value);
end;

function TWinSAED.GetArcDirNamePIA: string;
begin
   Result := StrPas(FArcDirNamePIA);
end;
procedure TWinSAED.SetArcDirNamePIA(const Value: string);
begin
   if FArcDirNamePIA <> nil then StrDispose(FArcDirNamePIA);
   FArcDirNamePIA := StrAlloc(Length(Value)+1);
   StrPCopy(FArcDirNamePIA, Value);
end;

function TWinSAED.GetArcDirNameSIRC: string;
begin
   Result := StrPas(FArcDirNameSIRC);
end;
procedure TWinSAED.SetArcDirNameSIRC(const Value: string);
begin
   if FArcDirNameSIRC <> nil then StrDispose(FArcDirNameSIRC);
   FArcDirNameSIRC := StrAlloc(Length(Value)+1);
   StrPCopy(FArcDirNameSIRC, Value);
end;

procedure TWinSAED.GetResultKPD1;
var
   Res: TStringList;
   KPD1 : TCollectionItemKPD1;
   i: Integer;
   s : string;
begin
   if FResArcMail <> nil then FResArcMail.Free;
   FResArcMail := TCollection.Create(TCollectionItemKPD1);
   Res := TStringList.Create;
   try
      Res.LoadFromFile(TempFileRes);
   except
   end;
   i := 0;
   while i < Res.Count do begin
      KPD1 := FResArcMail.Add as TCollectionItemKPD1;
      s := Res.Strings[i+0];
      KPD1.FileName := s;
      s := Res.Strings[i+1];
      try
         KPD1.ResCode := StrToInt(s);
      except
      end;
      s := Res.Strings[i+2];
      try
         KPD1.NumberKPD := StrToInt(s);
      except
      end;
      i := i+3;
   end;
   Res.Free;
end;

procedure TWinSAED.GetResultKPD2;
var
   Res: TStringList;
   KPD1 : TCollectionItemKPD1;
   KPD2 : TCollectionItemKPD2;
   i,j: Integer;
   s : string;
begin
   if FResArcMail <> nil then FResArcMail.Free;
   FResArcMail := TCollection.Create(TCollectionItemKPD1);
   Res := TStringList.Create;
   Res.LoadFromFile(TempFileRes);
   i := 0;
   while i < Res.Count do begin
      KPD1 := FResArcMail.Add as TCollectionItemKPD1;
      s := Res.Strings[i+0];
      KPD1.FileName := s;
      s := Res.Strings[i+1];
      KPD1.ResCode := StrToInt(s);
      s := Res.Strings[i+2];
      KPD1.NumberKPD := StrToInt(s);
      for j:=0 to KPD1.NumberKPD-1 do begin
         KPD2 := KPD1.FKPD.Add as TCollectionItemKPD2;
         s := Res.Strings[i+3+j];
         KPD2.NameSIA := Copy (s, 1, 8);
         KPD2.InfoSIA := Copy (s, 10, 40);
         KPD2.DateCreateKPD := StrToDate(ReplaceStr(Copy(s, 51, 10), '.', DateSeparator));
         KPD2.DateEndKPD := StrToDate(ReplaceStr(Copy(s, 62, 10), '.', DateSeparator));
         KPD2.ResKPD := StrToInt(Copy(s, 73, 2));
      end;
      i := i+3+KPD1.NumberKPD;
   end;
   Res.Free;
end;

function TWinSAED.GetResItem(Index: Integer): TCollectionItemKPD1;
begin
   Result := TCollectionItemKPD1(FResArcMail.Items[Index]);
end;

function TWinSAED.GetCount: Integer;
begin
   Result := FResArcMail.Count;
end;

procedure TWinSAED.CreateListFileNames(ASourceFiles: string; AWithSubdir: Boolean);
var
   i: Integer;
   s: string;
begin
   ArcDirName := ExtractFilePath(ASourceFiles);
   PathName.Clear;
   ScanDirFiles.OnFile := nil;
   ScanDirFiles.DelFile := False;
   if AWithSubDir then
      ScanDirFiles.Execute(ASourceFiles, sfDirectories)
   else
      ScanDirFiles.Execute(ASourceFiles, sfDirectory);
   for i:=0 to ScanDirFiles.FileList.Count-1 do begin
      s := ScanDirFiles.FileList.Strings[i];
      FileSetAttr(s, FileGetAttr(s) and (faReadOnly xor $FF));
      Delete(s, 1, Length(ExtractFilePath(ASourceFiles)));
      PathName.Add(s);
   end;
end;

function FUNCProgress(Params: Pcb_PF_PARAMS): integer; stdcall;
var
   n1: DWORD;
   n2: DWORD;
   s1: string;
   s2: string;
   s3: string;
   s: string;
   w: word;
   yyyy: word;
   dd: ShortInt;
   mm: ShortInt;
begin
   Result := 0; // все в порядке
   case Params.cause of
      cb_PFC_PROGRESS: begin
         n1 := Params.info.progress.totalSize;
         n2 := Params.info.progress.doneSize;
         s := Format('%-8d %-8d', [n1,n2]);
         APPFileMemoLog.LogString[tlsProcess,1] := s;
         //if Assigned(Params.fParam) then begin
         //   APPFileMemoLog.LogString[tlsProcess,1] := PChar(Params.fParam^);
         //end;
         {
         Result := 1; // необходимо прервать операцию
         }
         Result := 0; // все в порядке
      end;
      cb_PFC_KPD_FOUND: begin
         s1 := Params.info.kpdFound.siName;
         s2 := Params.info.kpdFound.userName;
         yyyy := Params.info.kpdFound.sdate.da_year;
         dd := Params.info.kpdFound.sdate.da_day;
         mm := Params.info.kpdFound.sdate.da_mon;
         s := Format('%-8s %-40s %-4d %-2d %-2d', [s1,s2,yyyy,mm,dd]);
         APPFileMemoLog.LogString[tlsProcess,1] := s;
         {
         Result := 2; // необходимо пропустить данную часть операции
         Result := 1; // необходимо прервать операцию
         }
         Result := 0; // все в порядке
      end;
      cb_PFC_KPD_TESTED: begin
         s1 := Params.info.kpdTested.siName;
         s2 := Params.info.kpdTested.userName;
         yyyy := Params.info.kpdTested.sdate.da_year;
         dd := Params.info.kpdTested.sdate.da_day;
         mm := Params.info.kpdTested.sdate.da_mon;
         w := Params.info.kpdTested.testResult;
         s3 := Params.info.kpdTested.TestParam;
         s := Format('%-8s %-40s %-4d %-2d %-2d %-4d %s', [s1,s2,yyyy,mm,dd,w,s3]);
         APPFileMemoLog.LogString[tlsProcess,1] := s;
         {
         Result := 1; // необходимо прервать операцию
         }
         Result := 0; // все в порядке
      end;
   end;
end;

function TWinSAED.CheckKPD: Cardinal;
const
   sss: string = 'CheckKBD';
var
   i: Integer;
   LFileName: string;

begin
   Result := 0;
   APPFileMemoLog := nil;
   APPFileMemoLog := FileMemoLog;
   {
      ArcDirName, PathName должен уже быть
      либо после ExtractArchiver
      либо после CreateListFileNames(ASourceFiles, AWithSubDir);
   }
   { Begin CheckKPD }
   FileMemoLog.LogString[tlsProcess,1] := SCheckKPD;
   for i:=0 to PathName.Count-1 do begin
      LFileName := IncludeTrailingBackslash(ArcDirName)+PathName.Strings[i];
      FileMemoLog.LogString[tlsProcess,1] := 'cb_getFileKPDCount... '+LFileName;
      FResultFunction := cb_getFileKPDCount(PChar(LFileName));
      FileMemoLog.LogString[tlsProcess,1] := format('Число КПД: %d', [FResultFunction]);
      FileMemoLog.LogString[tlsProcess,1] := format('code: %d %s', [ei.code,sei]);
      FileMemoLog.LogString[tlsProcess,1] := 'cb_TestFileKPD... '+LFileName;
      FResultFunction := cb_TestFileKPD(PChar(LFileName), @FUNCProgress, @i);
      FileMemoLog.LogString[tlsProcess,1] := format('code: %d %s', [ei.code,sei]);
      if (FResultFunction <> 0) then begin
         FileMemoLog.LogString[tlsError,1] := SCheckKPDError;
         FileMemoLog.LogString[tlsError,1] := ErrorString;
         Result := 1; { Create Archive-file Error! }
      end;
   end;

   { End CheckKPD }
   FileMemoLog.LogString[tlsProcess,1] := SCheckKPDOk+' Result = '+IntToStr(Result);
end;

function TWinSAED.RemoveKPD: Cardinal;
var
   i: Integer;
   LFileName: string;
begin
   Result := 0;
   {
      ArcDirName, PathName должен уже быть
      либо после ExtractArchiver
      либо после CreateListFileNames(ASourceFiles, AWithSubDir);
   }
   { Begin RemoveKPD }
   FileMemoLog.LogString[tlsProcess,1] := sRemoveKPD;
   for i:=0 to PathName.Count-1 do begin
      LFileName := IncludeTrailingBackslash(ArcDirName)+PathName.Strings[i];
      FileMemoLog.LogString[tlsProcess,1] := 'cb_getFileKPDCount... '+LFileName;
      FResultFunction := cb_getFileKPDCount(PChar(LFileName));
      FileMemoLog.LogString[tlsProcess,1] := format('Число КПД: %d', [FResultFunction]);
      FileMemoLog.LogString[tlsProcess,1] := format('code: %d %s', [ei.code,sei]);
      FileMemoLog.LogString[tlsProcess,1] := 'cb_DelFileKPD... '+LFileName;
      FResultFunction := cb_DelFileKPD(PChar(LFileName), -1);
      if (FResultFunction < 0) then begin
         FileMemoLog.LogString[tlsError,1] := SRemoveKPDError;
         FileMemoLog.LogString[tlsError,1] := ErrorString;
         Result := 1; { Error! }
      end;
   end;

   { End RemoveKPD }
   FileMemoLog.LogString[tlsProcess,1] := SRemoveKPDOk+' Result '+IntToStr(Result);
end;

function TWinSAED.SetKPD (ASourceFiles: string; AWithSubdir: Boolean): Cardinal;
begin
   Result := 0;
   APPFileMemoLog := nil;
   if Assigned(FileMemoLog) then begin
      APPFileMemoLog := FileMemoLog;
   end;
   WithSubDir := AWithSubDir;
   KeyDisk := 'a:\';
   { Arc Directory }
   ArcDirName := '';
   { Arc Filename }
   ArcFileName := '';
   { From }
   FileName := ASourceFiles;
   { Create List of Files }
   CreateListFileNames(ASourceFiles, AWithSubDir);
   if PathName.Count > 0 then begin
      { Begin SetKPD }
      FileMemoLog.LogString[tlsProcess,1] := 'cb_SetFileKPD... '+ArcDirName+ArcFileName;
      FResultFunction := cb_SetFileKPD(PChar(ArcDirName+ArcFileName), @FUNCProgress, nil);
      if (FResultFunction <> 0) then begin
         FileMemoLog.LogString[tlsError,2] := SSetKPDError;
         FileMemoLog.LogString[tlsError,3] := ErrorString;
         Result := 1; { Create Archive-file Error! }
      end;

      { End SetKPD }
      FileMemoLog.LogString[tlsProcess,1] := SSetKPDOk+' Result '+IntToStr(Result);
   end;
end;

function TWinSAED.CreateArchiver  (ASourceFiles, ADestArchiveName: string; AArcPIA: Array Of PChar;
                                   AWithSubdir: Boolean): Cardinal;
var
   i: Integer;
   s,s1,s2 : string;
   {}
   hLck: HANDLE;
   Metod: WORD;
   NAbonent: WORD;
   //Params: TArrayOfChar;
   Params: cb_PF_PARAMS;

begin
   Result := 0;
   APPFileMemoLog := nil;
   if Assigned(FileMemoLog) then begin
      APPFileMemoLog := FileMemoLog;
   end;
   WithSubDir := False;
   { Arc Filename }
   ArcFileName := ExtractFileName(ADestArchiveName);
   { From }
   FileName := ASourceFiles;
   { Arc Directory }
   ArcDirName := ExtractFilePath(ADestArchiveName);
   ArcDirName := IncludeTrailingBackslash(TempDir);
   {----------------------------------------------------------}
   if not DirectoryExists(FileName) then begin
      WorkDir := ExtractFilePath(FileName);
      CreateListFileNames(ASourceFiles, AWithSubDir);
      end
   else begin
      { PathName должен быть уже создан }
      WorkDir := FileName;
      //PathName.Assign(ScanDirFiles.FileList);
   end;
   {----------------------------------------------------------}
   if PathName.Count > 0 then begin
      if Assigned(FileMemoLog) then begin
         FileMemoLog.LogString[tlsProcess,0] := '---------------------------------------------------';
         FileMemoLog.LogString[tlsProcess,0] := SCreateArchive+' ...';
         FileMemoLog.LogString[tlsProcess,1] := 'Архив: '+IncludeTrailingBackslash(ArcDirName)+ADestArchiveName+'.LCK';
         FileMemoLog.LogString[tlsProcess,1] := SListFiles;
         (*
         for i:=0 to ScanDirFiles.FileList.Count-1 do begin
            FileMemoLog.LogString[tlsProcess,2] := ScanDirFiles.FileList.Strings[i];
         end;
         *)
         for i:=0 to PathName.Count-1 do begin
            FileMemoLog.LogString[tlsProcess,2] := IncludeTrailingBackslash(WorkDir)+PathName.Strings[i];
         end;
      end;

      { Создание архива }
      Metod := 3;
      NAbonent := 1;
      FileMemoLog.LogString[tlsProcess,0] :=  'cb_createArchive... '+ArcDirName+ArcFileName;

      hLck := cb_createArchive(PChar(ArcDirName+ArcFileName), Metod, @AArcPIA, NAbonent, @FUNCProgress, nil);

      if hLck = 0 then begin
         FileMemoLog.LogString[tlsError,1] := 'Архив не создан!';
         FileMemoLog.LogString[tlsError,2] := ArcName;
         FStatus := 9999999;
         FErrors.Add(format('code: %d %s', [ei.code,sei]));
         Result := 1; { Create Archive-file Error! }
         end
      else begin
         FStatus := 0;

         { Добавление файлов в архив }
         for i:=0 to PathName.Count-1 do begin
            s := IncludeTrailingBackslash(WorkDir)+PathName.Strings[i];
            FileMemoLog.LogString[tlsProcess,0] := 'cb_addFile... '+s;
            cb_addFile(hLck, PChar(s), nil, cb_AAF_SETKPD or cb_AAF_EXCLUDE_BASEDIR, nil, nil);
            FileMemoLog.LogString[tlsProcess,0] := format('cb_addFile code: %d %s', [ei.code,sei]);
         end;
         cb_closeArchive(hLck, nil, nil);
         FileMemoLog.LogString[tlsProcess,0] := format('cb_closeArchive code: %d %s', [ei.code,sei]);
(*???????????????????????????????
         { Copy to DestPath }
         s1 := ArcDirName+ArcFileName;
         s2 := ADestArchiveName;
         FileMemoLog.LogString[tlsProcess,0] := 'Copy to DestPath... '+S1+' => '+S2;
         if UpperCase(S1) = UpperCase(S2) then begin
            FileMemoLog.LogString[tlsProcess,1] := 'Файл остается на месте.';
            Result := 0;
            end
         else begin
            if Windows.CopyFile(PChar(s1), PChar(s2), LongBool(False)) then begin
               { delete file from TempDir }
               SysUtils.DeleteFile(s1);
               FileMemoLog.LogString[tlsProcess,1] := 'Файл '+s1+' удален';
               Result := 0;
               end
            else begin
               FileMemoLog.LogString[tlsError,1] := 'Ошибка при копировании файла ';
               FileMemoLog.LogString[tlsError,1] := s1;
               Result := 1; { Ошибка при копировании }
            end;
         end;
????????????????????????????????????????*)
      end;
      {}
      FileMemoLog.LogString[tlsProcess,0] := SCreateArchiveOk+' Result '+IntToStr(Result);
      FileMemoLog.LogString[tlsProcess,0] := '---------------------------------------------------';
   end;
end;

function TWinSAED.ExtractArchiver (ASourceFile, ADestPathName: string): Cardinal;
var
   s: string;
   j: Integer;
   hLck: HANDLE;
   fname: array[0..MAX_PATH] of Char;
   creator: array[0..cb_SI_NAME_LEN+100] of char;
   info: cb_ARCHFILEINFO;
   final: Integer;
begin
   APPFileMemoLog := nil;
   APPFileMemoLog := FileMemoLog;
   KeyDisk := 'a:\';
   ArcName := ArcName;
   WithSubDir := False;
   ArcDirName := ADestPathName;
   s := ASourceFile;
   ArcFileName := S;
   FileName := IncludeTrailingBackSlash(ADestPathName);

   FileMemoLog.LogString[tlsProcess,1] := SExtractArchive+'... '+s;
   FileMemoLog.LogString[tlsProcess,1] := 'cb_OpenArchive...';
   hLck := cb_openArchive(PChar(ASourceFile), creator, @FUNCProgress, PChar('cb_openArchive'));
   if hLck = 0 then begin
      FileMemoLog.LogString[tlsError,1] := SExtractArchiveError;
      FileMemoLog.LogString[tlsError,2] := ErrorString;
      Result := 1;
      end
   else begin
      FileMemoLog.LogString[tlsProcess,1] := Format('Архив был создан абонентом [%s]', [creator]);
      FillChar(Info,SizeOf(Info),1);
      FileMemoLog.LogString[tlsProcess,1] := 'cb_getFirstFile...';
      final := cb_getFirstFile(hLck, @info);
      FileMemoLog.LogString[tlsProcess,1] := format('code: %d %s', [ei.code,sei]);
      { Create PathName }
      PathName.Clear;
      while (final=0) do begin
         s := info.fileName;
         PathName.Add(ExtractFileName(s));
         FileMemoLog.LogString[tlsProcess,1] := Format('cb_extractCurFile... %s', [info.fileName]);
         FillChar(fname,SizeOf(fname),0);
         strcopy(fname, PChar(ArcDirName));
         cb_extractCurFile(hLck, fname,
            cb_AEF_TESTKPD or cb_AEF_DELKPD or
            cb_AEF_ADD_DIR or
            cb_AEF_FAIL_ON_BADKPD,
            @FUNCProgress, nil);
         //cb_extractCurFile(hLck, fname, cb_AEF_TESTKPD or cb_AEF_DELKPD or cb_AEF_ADD_DIR or cb_AEF_FAIL_ON_BADKPD, nil, nil);
         FileMemoLog.LogString[tlsProcess,1] := format('code: %d %s', [ei.code,sei]);
         FillChar(Info,SizeOf(Info),0);
         FileMemoLog.LogString[tlsProcess,1] := 'cb_getNextFile...';
         final := cb_getNextFile(hLck, @info);
         FileMemoLog.LogString[tlsProcess,1] :=format('code: %d %s', [ei.code,sei]);
      end;
      FileMemoLog.LogString[tlsProcess,1] := 'cb_closeArchive...';
      cb_closeArchive(hLck, @FUNCProgress, nil);
      FileMemoLog.LogString[tlsProcess,1] := format('code: %d %s', [ei.code,sei]);
(*
      { Delete Archive }
      FileDelete (ASourceFile);
      FileMemoLog.LogString[tlsProcess,1] := 'Delete  Archive '+ASourceFile+' Ok!';
*)
   end;
end;

function TWinSAED.ExtractArchivers(ASourceFiles, ADestArchiveName: string; AWithSubdir: Boolean): Cardinal;
var
   ScanDir: TScanDirFiles;
   Res: Cardinal;
   i: Integer;
begin
   if Assigned(FileMemoLog) then begin
      FileMemoLog.LogString[tlsProcess,0] := '---------------------------------------------------';
      FileMemoLog.LogString[tlsProcess,0] := SExtractArchives;
   end;
   { ScanDir }
   ScanDir := TScanDirFiles.Create;
   ScanDir.OnFile := nil;
   ScanDir.DelFile := False;
   if AWithSubDir then
      ScanDir.Execute(ASourceFiles, sfDirectories)
   else
      ScanDir.Execute(ASourceFiles, sfDirectory);
   for i:=0 to ScanDir.FileList.Count-1 do begin
      Res := ExtractArchiver(ScanDir.FileList.Strings[i], ADestArchiveName);
   end;
   FileMemoLog.LogString[tlsProcess,0] := SExtractArchivesOk;
   { Free }
   Result := ScanDir.Status;
   ScanDir.Free;
end;

function piaPasswordFunc(passBuf: Pointer; piaName: PChar; userName: PChar): Integer; stdcall;
begin
   if FpassDefault <> '' then begin
      FillChar(passBuf^,SizeOf(TpassBuf),0);
      strcopy(PChar(passBuf), PChar(FpassDefault));
      Result := 0; { пароль введен }
      end
   else begin
      { MessageBox }
   end;
end;

function TWinSAED.InitLib (Options: DWORD; const Password: string): integer;
//var Options: DWORD;
begin
   //Options := cb_LPO_DONT_OPEN_DB or cb_LPO_DONT_OPEN_DB_SIRC;
   //Options := 0;
   if Assigned(FileMemoLog) then begin
      FileMemoLog.LogString[tlsProcess,1] := 'cb_initLib...';
   end;

   FpassDefault := Trim(Password);
   if FpassDefault <> '' then begin
      Result := cb_initLib(nil, @piaPasswordFunc, Options);
      end
   else begin
      Result := cb_initLib(nil, nil, Options);
   end;

   if Assigned(FileMemoLog) then begin
      FileMemoLog.LogString[tlsProcess,1] := format('code: %d %s', [ei.code,sei]);
   end;
end;

function TWinSAED.InitLibDirect: integer;
begin
   if Assigned(FileMemoLog) then begin
      FileMemoLog.LogString[tlsProcess,1] := 'cb_initLibDirect...';
   end;

   Result := cb_initLibDirect(Pcb_LIBPARAMS(@FLIBParams));

   if Assigned(FileMemoLog) then begin
      FileMemoLog.LogString[tlsProcess,1] := format('code: %d %s', [ei.code,sei]);
   end;
end;

function TWinSAED.DoneLib: integer;
begin
   Result := 0;
   if Assigned(FileMemoLog) then begin
      FileMemoLog.LogString[tlsProcess,1] := 'cb_doneLib...';
   end;
   cb_doneLib;
   if Assigned(FileMemoLog) then begin
      FileMemoLog.LogString[tlsProcess,1] := format('code: %d %s', [ei.code,sei]);
   end;
end;

function TWinSAED.GetVersion: string;
begin
   Fvmaj := 0;
   Fvmin := 0;
   Flibtype := 0;
   FResultFunction := cb_getLibVersion(@Fvmaj, @Fvmin, @Flibtype);
   if FResultFunction <> CBERR then begin
      if (Flibtype <> 0) then begin
         Result := Format('Библиотека SAED32 версии %d.%d.%d - %s', [Fvmaj, Fvmin, Flibtype, 'АП']);
         end
      else begin
         Result := Format('Библиотека SAED32 версии %d.%d.%d - %s', [Fvmaj, Fvmin, Flibtype, 'ЦП']);
      end;
      end
   else begin
      Result := format('cb_getLibVersion code: %d %s', [ei.code, sei]);
   end;
end;

procedure TWinSAED.SetLIBParams(piaName,siaDir,sircDir,WorkDir: string;
   //piaPasswordFunc: Pcb_PASSWORDFUNC;
   Options: DWORD; const Password: string);
begin
   FillChar(FLIBParams, SizeOf(FLIBParams), 0);
   { Имя ПИА (полный путь или имя каталога) }
   strcopy(FLIBParams.piaName, PChar(piaName));

   FpassDefault := Trim(Password);
   if FpassDefault <> '' then begin
      FLIBParams.piaPasswordFunc := @piaPasswordFunc;
      end
   else begin
      { Указатель на функцию запроса пароля ПИА. Если NULL, то запрос пароля производится встроенной функцией библиотеки. }
      FLIBParams.piaPasswordFunc := nil;
   end;

   { Каталог БД СИА }
   strcopy(FLIBParams.siaDir, PChar(siaDir));
   { Каталог БД СИРЦ и отдельных СИРЦ }
   strcopy(FLIBParams.sircDir, PChar(sircDir));
   { Имя файла простых чисел (полный путь) }
   strcopy(FLIBParams.simpleFile, PChar(IncludeTrailingBackslash(WorkDir)+'arcmail.dat'));
   { Имя файла журнала. }
   strcopy(FLIBParams.LogFile, PChar(IncludeTrailingBackslash(WorkDir)+'logfile.log'));
   { cb_LOGF_ALL - протоколируются все операции; }
   FLIBParams.logFlags := cb_LOGF_ALL;
   { Опции работы библиотеки cb_LPO_* }
   FLIBParams.options := Options;
   FLIBParams.reserved := nil;
end;

function TWinSAED.GetCurrentUser: string;
var
   piaName: array[0..cb_SI_NAME_LEN+1] of char;
   userName: array[0..cb_USER_NAME_LEN+1] of char;
begin
   FillChar(piaName, SizeOf(piaName), 0);
   FillChar(userName, SizeOf(userName), 0);
   cb_getCurrentUser(piaName, userName);
   Result := Format('%s/%s', [piaName, userName]);
end;

{ TSAES }

constructor TSAES.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
   ArcDirNameSIA := '';
   ArcDirNamePIA := '';
   ArcDirNameSIRC := '';
   ArcPIA := '';
   PasswordConfig := '';
   PasswordPIA := '';
   KeyDisk := 'a:\';
   FResArcMail := TCollection.Create(TCollectionItemKPD1);
end;

destructor TSAES.Destroy;
begin
   FResArcMail.Free;
   StrDispose(FArcDirNameSIA);
   StrDispose(FArcDirNamePIA);
   StrDispose(FArcDirNameSIRC);
   StrDispose(FArcPIA);
   StrDispose(FPasswordConfig);
   StrDispose(FPasswordPIA);
   inherited Destroy;
end;

function TSAES.HandleException (E: Exception): Boolean;
begin
   Result := True;
   if Result then FErrors.Add(E.Message);
end;

function TSAES.GetArcPIA: string;
begin
   Result := StrPas(FArcPIA);
end;
procedure TSAES.SetArcPIA(const Value: string);
begin
   if FArcPIA <> nil then StrDispose(FArcPIA);
   FArcPIA := StrAlloc(Length(Value)+1);
   StrPCopy(FArcPIA, Value);
end;

function TSAES.GetPasswordConfig: string;
begin
   Result := StrPas(FPasswordConfig);
end;
procedure TSAES.SetPasswordConfig(const Value: string);
begin
   if FPasswordConfig <> nil then StrDispose(FPasswordConfig);
   FPasswordConfig := StrAlloc(Length(Value)+1);
   StrPCopy(FPasswordConfig, Value);
end;

function TSAES.GetPasswordPIA: string;
begin
   Result := StrPas(FPasswordPIA);
end;
procedure TSAES.SetPasswordPIA(const Value: string);
begin
   if FPasswordPIA <> nil then StrDispose(FPasswordPIA);
   FPasswordPIA := StrAlloc(Length(Value)+1);
   StrPCopy(FPasswordPIA, Value);
end;

function TSAES.GetKeyDisk: string;
begin
   Result := StrPas(FKeyDisk);
end;
procedure TSAES.SetKeyDisk(const Value: string);
begin
   if FKeyDisk <> nil then StrDispose(FKeyDisk);
   FKeyDisk := StrAlloc(Length(Value)+1);
   StrPCopy(FKeyDisk, Value);
end;

function TSAES.GetArcDirNameSIA: string;
begin
   Result := StrPas(FArcDirNameSIA);
end;
procedure TSAES.SetArcDirNameSIA(const Value: string);
begin
   if FArcDirNameSIA <> nil then StrDispose(FArcDirNameSIA);
   FArcDirNameSIA := StrAlloc(Length(Value)+1);
   StrPCopy(FArcDirNameSIA, Value);
end;

function TSAES.GetArcDirNamePIA: string;
begin
   Result := StrPas(FArcDirNamePIA);
end;
procedure TSAES.SetArcDirNamePIA(const Value: string);
begin
   if FArcDirNamePIA <> nil then StrDispose(FArcDirNamePIA);
   FArcDirNamePIA := StrAlloc(Length(Value)+1);
   StrPCopy(FArcDirNamePIA, Value);
end;

function TSAES.GetArcDirNameSIRC: string;
begin
   Result := StrPas(FArcDirNameSIRC);
end;
procedure TSAES.SetArcDirNameSIRC(const Value: string);
begin
   if FArcDirNameSIRC <> nil then StrDispose(FArcDirNameSIRC);
   FArcDirNameSIRC := StrAlloc(Length(Value)+1);
   StrPCopy(FArcDirNameSIRC, Value);
end;

procedure TSAES.GetResultKPD1;
var
   Res: TStringList;
   KPD1 : TCollectionItemKPD1;
   i: Integer;
   s : string;
begin
   if FResArcMail <> nil then FResArcMail.Free;
   FResArcMail := TCollection.Create(TCollectionItemKPD1);
   Res := TStringList.Create;
   try
      Res.LoadFromFile(TempFileRes);
   except
   end;
   i := 0;
   while i < Res.Count do begin
      KPD1 := FResArcMail.Add as TCollectionItemKPD1;
      s := Res.Strings[i+0];
      KPD1.FileName := s;
      s := Res.Strings[i+1];
      try
         KPD1.ResCode := StrToInt(s);
      except
      end;
      s := Res.Strings[i+2];
      try
         KPD1.NumberKPD := StrToInt(s);
      except
      end;
      i := i+3;
   end;
   Res.Free;
end;

procedure TSAES.GetResultKPD2;
var
   Res: TStringList;
   KPD1 : TCollectionItemKPD1;
   KPD2 : TCollectionItemKPD2;
   i,j: Integer;
   s : string;
begin
   if FResArcMail <> nil then FResArcMail.Free;
   FResArcMail := TCollection.Create(TCollectionItemKPD1);
   Res := TStringList.Create;
   Res.LoadFromFile(TempFileRes);
   i := 0;
   while i < Res.Count do begin
      KPD1 := FResArcMail.Add as TCollectionItemKPD1;
      s := Res.Strings[i+0];
      KPD1.FileName := s;
      s := Res.Strings[i+1];
      KPD1.ResCode := StrToInt(s);
      s := Res.Strings[i+2];
      KPD1.NumberKPD := StrToInt(s);
      for j:=0 to KPD1.NumberKPD-1 do begin
         KPD2 := KPD1.FKPD.Add as TCollectionItemKPD2;
         s := Res.Strings[i+3+j];
         KPD2.NameSIA := Copy (s, 1, 8);
         KPD2.InfoSIA := Copy (s, 10, 40);
         KPD2.DateCreateKPD := StrToDate(ReplaceStr(Copy(s, 51, 10), '.', DateSeparator));
         KPD2.DateEndKPD := StrToDate(ReplaceStr(Copy(s, 62, 10), '.', DateSeparator));
         KPD2.ResKPD := StrToInt(Copy(s, 73, 2));
      end;
      i := i+3+KPD1.NumberKPD;
   end;
   Res.Free;
end;

function TSAES.GetResItem(Index: Integer): TCollectionItemKPD1;
begin
   Result := TCollectionItemKPD1(FResArcMail.Items[Index]);
end;

function TSAES.GetCount: Integer;
begin
   Result := FResArcMail.Count;
end;

procedure TSAES.CreateListFileNames(ASourceFiles: string; AWithSubdir: Boolean);
var
   i: Integer;
   s: string;
begin
   ArcDirName := ExtractFilePath(ASourceFiles);
   PathName.Clear;
   ScanDirFiles.OnFile := nil;
   ScanDirFiles.DelFile := False;
   if AWithSubDir then
      ScanDirFiles.Execute(ASourceFiles, sfDirectories)
   else
      ScanDirFiles.Execute(ASourceFiles, sfDirectory);
   for i:=0 to ScanDirFiles.FileList.Count-1 do begin
      s := ScanDirFiles.FileList.Strings[i];
      FileSetAttr(s, FileGetAttr(s) and (faReadOnly xor $FF));
      Delete(s, 1, Length(ExtractFilePath(ASourceFiles)));
      PathName.Add(s);
   end;
end;

function FUNCProgressSAES(Params: Pcb_PF_PARAMS): integer; stdcall;
var
   n1: DWORD;
   n2: DWORD;
   s1: string;
   s2: string;
   s3: string;
   s: string;
   w: word;
   yyyy: word;
   dd: ShortInt;
   mm: ShortInt;
begin
   Result := 0; // все в порядке
   case Params.cause of
      cb_PFC_PROGRESS: begin
         n1 := Params.info.progress.totalSize;
         n2 := Params.info.progress.doneSize;
         s := Format('%-8d %-8d', [n1,n2]);
         APPFileMemoLog.LogString[tlsProcess,1] := s;
         //if Assigned(Params.fParam) then begin
         //   APPFileMemoLog.LogString[tlsProcess,1] := PChar(Params.fParam^);
         //end;
         {
         Result := 1; // необходимо прервать операцию
         }
         Result := 0; // все в порядке
      end;
      cb_PFC_KPD_FOUND: begin
         s1 := Params.info.kpdFound.siName;
         s2 := Params.info.kpdFound.userName;
         yyyy := Params.info.kpdFound.sdate.da_year;
         dd := Params.info.kpdFound.sdate.da_day;
         mm := Params.info.kpdFound.sdate.da_mon;
         s := Format('%-8s %-40s %-4d %-2d %-2d', [s1,s2,yyyy,mm,dd]);
         APPFileMemoLog.LogString[tlsProcess,1] := s;
         {
         Result := 2; // необходимо пропустить данную часть операции
         Result := 1; // необходимо прервать операцию
         }
         Result := 0; // все в порядке
      end;
      cb_PFC_KPD_TESTED: begin
         s1 := Params.info.kpdTested.siName;
         s2 := Params.info.kpdTested.userName;
         yyyy := Params.info.kpdTested.sdate.da_year;
         dd := Params.info.kpdTested.sdate.da_day;
         mm := Params.info.kpdTested.sdate.da_mon;
         w := Params.info.kpdTested.testResult;
         s3 := Params.info.kpdTested.TestParam;
         s := Format('%-8s %-40s %-4d %-2d %-2d %-4d %s', [s1,s2,yyyy,mm,dd,w,s3]);
         APPFileMemoLog.LogString[tlsProcess,1] := s;
         {
         Result := 1; // необходимо прервать операцию
         }
         Result := 0; // все в порядке
      end;
   end;
end;

function TSAES.CheckKPD: Cardinal;
const
   sss: string = 'CheckKBD';
var
   i: Integer;
   LFileName: string;

begin
   Result := 0;
   APPFileMemoLog := nil;
   APPFileMemoLog := FileMemoLog;
   {
      ArcDirName, PathName должен уже быть
      либо после ExtractArchiver
      либо после CreateListFileNames(ASourceFiles, AWithSubDir);
   }
   { Begin CheckKPD }
   FileMemoLog.LogString[tlsProcess,1] := SCheckKPD;
   for i:=0 to PathName.Count-1 do begin
      LFileName := IncludeTrailingBackslash(ArcDirName)+PathName.Strings[i];
      FileMemoLog.LogString[tlsProcess,1] := 'cb_getFileKPDCount... '+LFileName;
      FResultFunction := cb_getFileKPDCount(PChar(LFileName));
      FileMemoLog.LogString[tlsProcess,1] := format('Число КПД: %d', [FResultFunction]);
      FileMemoLog.LogString[tlsProcess,1] := format('code: %d %s', [ei.code,sei]);
      FileMemoLog.LogString[tlsProcess,1] := 'cb_TestFileKPD... '+LFileName;
      FResultFunction := cb_TestFileKPD(PChar(LFileName), @FUNCProgressSAES, @i);
      FileMemoLog.LogString[tlsProcess,1] := format('code: %d %s', [ei.code,sei]);
      if (FResultFunction <> 0) then begin
         FileMemoLog.LogString[tlsError,1] := SCheckKPDError;
         FileMemoLog.LogString[tlsError,1] := ErrorString;
         Result := 1; { Create Archive-file Error! }
      end;
   end;

   { End CheckKPD }
   FileMemoLog.LogString[tlsProcess,1] := SCheckKPDOk+' Result = '+IntToStr(Result);
end;

function TSAES.RemoveKPD: Cardinal;
var
   i: Integer;
   LFileName: string;
begin
   Result := 0;
   {
      ArcDirName, PathName должен уже быть
      либо после ExtractArchiver
      либо после CreateListFileNames(ASourceFiles, AWithSubDir);
   }
   { Begin RemoveKPD }
   FileMemoLog.LogString[tlsProcess,1] := sRemoveKPD;
   for i:=0 to PathName.Count-1 do begin
      LFileName := IncludeTrailingBackslash(ArcDirName)+PathName.Strings[i];
      FileMemoLog.LogString[tlsProcess,1] := 'cb_getFileKPDCount... '+LFileName;
      FResultFunction := cb_getFileKPDCount(PChar(LFileName));
      FileMemoLog.LogString[tlsProcess,1] := format('Число КПД: %d', [FResultFunction]);
      FileMemoLog.LogString[tlsProcess,1] := format('code: %d %s', [ei.code,sei]);
      FileMemoLog.LogString[tlsProcess,1] := 'cb_DelFileKPD... '+LFileName;
      FResultFunction := cb_DelFileKPD(PChar(LFileName), -1);
      if (FResultFunction < 0) then begin
         FileMemoLog.LogString[tlsError,1] := SRemoveKPDError;
         FileMemoLog.LogString[tlsError,1] := ErrorString;
         Result := 1; { Error! }
      end;
   end;

   { End RemoveKPD }
   FileMemoLog.LogString[tlsProcess,1] := SRemoveKPDOk+' Result '+IntToStr(Result);
end;

function TSAES.SetKPD (ASourceFiles: string; AWithSubdir: Boolean): Cardinal;
begin
   Result := 0;
   APPFileMemoLog := nil;
   if Assigned(FileMemoLog) then begin
      APPFileMemoLog := FileMemoLog;
   end;
   WithSubDir := AWithSubDir;
   KeyDisk := 'a:\';
   { Arc Directory }
   ArcDirName := '';
   { Arc Filename }
   ArcFileName := '';
   { From }
   FileName := ASourceFiles;
   { Create List of Files }
   CreateListFileNames(ASourceFiles, AWithSubDir);
   if PathName.Count > 0 then begin
      { Begin SetKPD }
      FileMemoLog.LogString[tlsProcess,1] := 'cb_SetFileKPD... '+ArcDirName+ArcFileName;
      FResultFunction := cb_SetFileKPD(PChar(ArcDirName+ArcFileName), @FUNCProgressSAES, nil);
      if (FResultFunction <> 0) then begin
         FileMemoLog.LogString[tlsError,2] := SSetKPDError;
         FileMemoLog.LogString[tlsError,3] := ErrorString;
         Result := 1; { Create Archive-file Error! }
      end;

      { End SetKPD }
      FileMemoLog.LogString[tlsProcess,1] := SSetKPDOk+' Result '+IntToStr(Result);
   end;
end;

function TSAES.CreateArchiver  (ASourceFiles, ADestArchiveName: string; AArcPIA: Array Of PChar;
                                   AWithSubdir: Boolean): Cardinal;
var
   i: Integer;
   s,s1,s2 : string;
   {}
   hLck: HANDLE;
   Metod: WORD;
   NAbonent: WORD;
   //Params: TArrayOfChar;
   Params: cb_PF_PARAMS;

begin
   Result := 0;
   APPFileMemoLog := nil;
   if Assigned(FileMemoLog) then begin
      APPFileMemoLog := FileMemoLog;
   end;
   WithSubDir := False;
   { Arc Filename }
   ArcFileName := ExtractFileName(ADestArchiveName);
   { From }
   FileName := ASourceFiles;
   { Arc Directory }
   ArcDirName := ExtractFilePath(ADestArchiveName);
   ArcDirName := IncludeTrailingBackslash(TempDir);
   {----------------------------------------------------------}
   if not DirectoryExists(FileName) then begin
      WorkDir := ExtractFilePath(FileName);
      CreateListFileNames(ASourceFiles, AWithSubDir);
      end
   else begin
      { PathName должен быть уже создан }
      WorkDir := FileName;
      //PathName.Assign(ScanDirFiles.FileList);
   end;
   {----------------------------------------------------------}
   if PathName.Count > 0 then begin
      if Assigned(FileMemoLog) then begin
         FileMemoLog.LogString[tlsProcess,0] := '---------------------------------------------------';
         FileMemoLog.LogString[tlsProcess,0] := SCreateArchive+' ...';
         FileMemoLog.LogString[tlsProcess,1] := 'Архив: '+IncludeTrailingBackslash(ArcDirName)+ADestArchiveName+'.LCK';
         FileMemoLog.LogString[tlsProcess,1] := SListFiles;
         (*
         for i:=0 to ScanDirFiles.FileList.Count-1 do begin
            FileMemoLog.LogString[tlsProcess,2] := ScanDirFiles.FileList.Strings[i];
         end;
         *)
         for i:=0 to PathName.Count-1 do begin
            FileMemoLog.LogString[tlsProcess,2] := IncludeTrailingBackslash(WorkDir)+PathName.Strings[i];
         end;
      end;

      { Создание архива }
      Metod := 3;
      NAbonent := 1;
      FileMemoLog.LogString[tlsProcess,0] :=  'cb_createArchive... '+ArcDirName+ArcFileName;

      hLck := cb_createArchive(PChar(ArcDirName+ArcFileName), Metod, @AArcPIA, NAbonent, @FUNCProgressSAES, nil);

      if hLck = 0 then begin
         FileMemoLog.LogString[tlsError,1] := 'Архив не создан!';
         FileMemoLog.LogString[tlsError,2] := ArcName;
         FStatus := 9999999;
         FErrors.Add(format('code: %d %s', [ei.code,sei]));
         Result := 1; { Create Archive-file Error! }
         end
      else begin
         FStatus := 0;

         { Добавление файлов в архив }
         for i:=0 to PathName.Count-1 do begin
            s := IncludeTrailingBackslash(WorkDir)+PathName.Strings[i];
            FileMemoLog.LogString[tlsProcess,0] := 'cb_addFile... '+s;
            cb_addFile(hLck, PChar(s), nil, cb_AAF_SETKPD or cb_AAF_EXCLUDE_BASEDIR, nil, nil);
            FileMemoLog.LogString[tlsProcess,0] := format('cb_addFile code: %d %s', [ei.code,sei]);
         end;
         cb_closeArchive(hLck, nil, nil);
         FileMemoLog.LogString[tlsProcess,0] := format('cb_closeArchive code: %d %s', [ei.code,sei]);
(*???????????????????????????????
         { Copy to DestPath }
         s1 := ArcDirName+ArcFileName;
         s2 := ADestArchiveName;
         FileMemoLog.LogString[tlsProcess,0] := 'Copy to DestPath... '+S1+' => '+S2;
         if UpperCase(S1) = UpperCase(S2) then begin
            FileMemoLog.LogString[tlsProcess,1] := 'Файл остается на месте.';
            Result := 0;
            end
         else begin
            if Windows.CopyFile(PChar(s1), PChar(s2), LongBool(False)) then begin
               { delete file from TempDir }
               SysUtils.DeleteFile(s1);
               FileMemoLog.LogString[tlsProcess,1] := 'Файл '+s1+' удален';
               Result := 0;
               end
            else begin
               FileMemoLog.LogString[tlsError,1] := 'Ошибка при копировании файла ';
               FileMemoLog.LogString[tlsError,1] := s1;
               Result := 1; { Ошибка при копировании }
            end;
         end;
????????????????????????????????????????*)
      end;
      {}
      FileMemoLog.LogString[tlsProcess,0] := SCreateArchiveOk+' Result '+IntToStr(Result);
      FileMemoLog.LogString[tlsProcess,0] := '---------------------------------------------------';
   end;
end;

function TSAES.ExtractArchiver (ASourceFile, ADestPathName: string): Cardinal;
var
   s: string;
   j: Integer;
   hLck: HANDLE;
   fname: array[0..MAX_PATH] of Char;
   creator: array[0..cb_SI_NAME_LEN+100] of char;
   info: cb_ARCHFILEINFO;
   final: Integer;
begin
   APPFileMemoLog := nil;
   APPFileMemoLog := FileMemoLog;
   KeyDisk := 'a:\';
   ArcName := ArcName;
   WithSubDir := False;
   ArcDirName := ADestPathName;
   s := ASourceFile;
   ArcFileName := S;
   FileName := IncludeTrailingBackSlash(ADestPathName);

   FileMemoLog.LogString[tlsProcess,1] := SExtractArchive+'... '+s;
   FileMemoLog.LogString[tlsProcess,1] := 'cb_OpenArchive...';
   hLck := cb_openArchive(PChar(ASourceFile), creator, @FUNCProgressSAES, PChar('cb_openArchive'));
   if hLck = 0 then begin
      FileMemoLog.LogString[tlsError,1] := SExtractArchiveError;
      FileMemoLog.LogString[tlsError,2] := ErrorString;
      Result := 1;
      end
   else begin
      FileMemoLog.LogString[tlsProcess,1] := Format('Архив был создан абонентом [%s]', [creator]);
      FillChar(Info,SizeOf(Info),1);
      FileMemoLog.LogString[tlsProcess,1] := 'cb_getFirstFile...';
      final := cb_getFirstFile(hLck, @info);
      FileMemoLog.LogString[tlsProcess,1] := format('code: %d %s', [ei.code,sei]);
      { Create PathName }
      PathName.Clear;
      while (final=0) do begin
         s := info.fileName;
         PathName.Add(ExtractFileName(s));
         FileMemoLog.LogString[tlsProcess,1] := Format('cb_extractCurFile... %s', [info.fileName]);
         FillChar(fname,SizeOf(fname),0);
         strcopy(fname, PChar(ArcDirName));
         cb_extractCurFile(hLck, fname,
            cb_AEF_TESTKPD or cb_AEF_DELKPD or
            cb_AEF_ADD_DIR or
            cb_AEF_FAIL_ON_BADKPD,
            @FUNCProgressSAES, nil);
         //cb_extractCurFile(hLck, fname, cb_AEF_TESTKPD or cb_AEF_DELKPD or cb_AEF_ADD_DIR or cb_AEF_FAIL_ON_BADKPD, nil, nil);
         FileMemoLog.LogString[tlsProcess,1] := format('code: %d %s', [ei.code,sei]);
         FillChar(Info,SizeOf(Info),0);
         FileMemoLog.LogString[tlsProcess,1] := 'cb_getNextFile...';
         final := cb_getNextFile(hLck, @info);
         FileMemoLog.LogString[tlsProcess,1] :=format('code: %d %s', [ei.code,sei]);
      end;
      FileMemoLog.LogString[tlsProcess,1] := 'cb_closeArchive...';
      cb_closeArchive(hLck, @FUNCProgressSAES, nil);
      FileMemoLog.LogString[tlsProcess,1] := format('code: %d %s', [ei.code,sei]);
(*
      { Delete Archive }
      FileDelete (ASourceFile);
      FileMemoLog.LogString[tlsProcess,1] := 'Delete  Archive '+ASourceFile+' Ok!';
*)
   end;
end;

function TSAES.ExtractArchivers(ASourceFiles, ADestArchiveName: string; AWithSubdir: Boolean): Cardinal;
var
   ScanDir: TScanDirFiles;
   Res: Cardinal;
   i: Integer;
begin
   if Assigned(FileMemoLog) then begin
      FileMemoLog.LogString[tlsProcess,0] := '---------------------------------------------------';
      FileMemoLog.LogString[tlsProcess,0] := SExtractArchives;
   end;
   { ScanDir }
   ScanDir := TScanDirFiles.Create;
   ScanDir.OnFile := nil;
   ScanDir.DelFile := False;
   if AWithSubDir then
      ScanDir.Execute(ASourceFiles, sfDirectories)
   else
      ScanDir.Execute(ASourceFiles, sfDirectory);
   for i:=0 to ScanDir.FileList.Count-1 do begin
      Res := ExtractArchiver(ScanDir.FileList.Strings[i], ADestArchiveName);
   end;
   FileMemoLog.LogString[tlsProcess,0] := SExtractArchivesOk;
   { Free }
   Result := ScanDir.Status;
   ScanDir.Free;
end;

function piaPasswordFuncSAES(passBuf: Pointer; piaName: PChar; userName: PChar): Integer; stdcall;
begin
   if FpassDefault <> '' then begin
      FillChar(passBuf^,SizeOf(TpassBuf),0);
      strcopy(PChar(passBuf), PChar(FpassDefault));
      Result := 0; { пароль введен }
      end
   else begin
      { MessageBox }
   end;
end;

function TSAES.InitLib (Options: DWORD; const Password: string): integer;
//var Options: DWORD;
begin
   //Options := cb_LPO_DONT_OPEN_DB or cb_LPO_DONT_OPEN_DB_SIRC;
   //Options := 0;
   if Assigned(FileMemoLog) then begin
      FileMemoLog.LogString[tlsProcess,1] := 'cb_initLib...';
   end;

   FpassDefault := Trim(Password);
   if FpassDefault <> '' then begin
      Result := cb_initLib(nil, @piaPasswordFuncSAES, Options);
      end
   else begin
      Result := cb_initLib(nil, nil, Options);
   end;

   if Assigned(FileMemoLog) then begin
      FileMemoLog.LogString[tlsProcess,1] := format('code: %d %s', [ei.code,sei]);
   end;
end;

function TSAES.InitLibDirect: integer;
begin
   if Assigned(FileMemoLog) then begin
      FileMemoLog.LogString[tlsProcess,1] := 'cb_initLibDirect...';
   end;

   Result := cb_initLibDirect(Pcb_LIBPARAMS(@FLIBParams));

   if Assigned(FileMemoLog) then begin
      FileMemoLog.LogString[tlsProcess,1] := format('code: %d %s', [ei.code,sei]);
   end;
end;

function TSAES.DoneLib: integer;
begin
   Result := 0;
   if Assigned(FileMemoLog) then begin
      FileMemoLog.LogString[tlsProcess,1] := 'cb_doneLib...';
   end;
   cb_doneLib;
   if Assigned(FileMemoLog) then begin
      FileMemoLog.LogString[tlsProcess,1] := format('code: %d %s', [ei.code,sei]);
   end;
end;

function TSAES.GetVersion: string;
begin
   Fvmaj := 0;
   Fvmin := 0;
   Flibtype := 0;
   FResultFunction := cb_getLibVersion(@Fvmaj, @Fvmin, @Flibtype);
   if FResultFunction <> CBERR then begin
      if (Flibtype <> 0) then begin
         Result := Format('Библиотека SAED32 версии %d.%d.%d - %s', [Fvmaj, Fvmin, Flibtype, 'АП']);
         end
      else begin
         Result := Format('Библиотека SAED32 версии %d.%d.%d - %s', [Fvmaj, Fvmin, Flibtype, 'ЦП']);
      end;
      end
   else begin
      Result := format('cb_getLibVersion code: %d %s', [ei.code, sei]);
   end;
end;

procedure TSAES.SetLIBParams(piaName,siaDir,sircDir,WorkDir: string;
   //piaPasswordFunc: Pcb_PASSWORDFUNC;
   Options: DWORD; const Password: string);
begin
   FillChar(FLIBParams, SizeOf(FLIBParams), 0);
   { Имя ПИА (полный путь или имя каталога) }
   strcopy(FLIBParams.piaName, PChar(piaName));

   FpassDefault := Trim(Password);
   if FpassDefault <> '' then begin
      FLIBParams.piaPasswordFunc := @piaPasswordFuncSAES;
      end
   else begin
      { Указатель на функцию запроса пароля ПИА. Если NULL, то запрос пароля производится встроенной функцией библиотеки. }
      FLIBParams.piaPasswordFunc := nil;
   end;

   { Каталог БД СИА }
   strcopy(FLIBParams.siaDir, PChar(siaDir));
   { Каталог БД СИРЦ и отдельных СИРЦ }
   strcopy(FLIBParams.sircDir, PChar(sircDir));
   { Имя файла простых чисел (полный путь) }
   strcopy(FLIBParams.simpleFile, PChar(IncludeTrailingBackslash(WorkDir)+'arcmail.dat'));
   { Имя файла журнала. }
   strcopy(FLIBParams.LogFile, PChar(IncludeTrailingBackslash(WorkDir)+'logfile.log'));
   { cb_LOGF_ALL - протоколируются все операции; }
   FLIBParams.logFlags := cb_LOGF_ALL;
   { Опции работы библиотеки cb_LPO_* }
   FLIBParams.options := Options;
   FLIBParams.reserved := nil;
end;

function TSAES.GetCurrentUser: string;
var
   piaName: array[0..cb_SI_NAME_LEN+1] of char;
   userName: array[0..cb_USER_NAME_LEN+1] of char;
begin
   FillChar(piaName, SizeOf(piaName), 0);
   FillChar(userName, SizeOf(userName), 0);
   cb_getCurrentUser(piaName, userName);
   Result := Format('%s/%s', [piaName, userName]);
end;

{ TARJ }

constructor TARJ.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
end;

destructor TARJ.Destroy;
begin
   inherited Destroy;
end;

function TARJ.Execute(Command: TARCCommand): Boolean;
var
   Save : string;
begin
   Save := GetCurrentDir;
   case Command of
      acAdd: begin
         ChDir(ExtractFilePath(FileName));
         PathName.SaveToFile(TempFile);
         if WithSubDir then begin
            ParamStr := 'a'+' -r'+' '+ArcDirName+ArcFileName+' '+ExtractFilename(FileName);
            end
         else begin
            ParamStr := 'a'      +' '+ArcDirName+ArcFileName+' '+ExtractFilename(FileName);
         end;
      end;
      acExtract: begin
         ChDir(ArcDirName);
         if WithSubDir then begin
            ParamStr := 'x'+' -y'+' '+ArcFileName;
            end
         else begin
            ParamStr := 'e'+' -y'+' '+ArcFileName;
         end;
      end;
   end;
   //Result := WinExecAndWait(ArcName, ParamStr, sw_Hide, FStatus);

   //function WinExecAndWait(PathExe, Params, WorkDir: string; Wait: Boolean; RunMode: Word; var Status: Cardinal): boolean;
   Result := WinExecAndWait(ArcName, ParamStr, GetCurrentDir, True, sw_Hide, FStatus,0,0,0);

   FErrors.Add(ArcMailError[FStatus]);
   ChDir(Save);
end;

end.
