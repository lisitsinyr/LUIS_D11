unit BDEUtils;

interface

uses
  Windows, Classes, SysUtils, FileCtrl,
  DBIErrs, DB, DBTables,
  CNVUtils,U36;

function GetAliasPath(const AliasName: string): string;
{ Получить DOS-путь по псевдониму }

function GetPath(DatabaseName : String) : TFileName;
{ Получить DOS-путь по имени БД }

function GetFullName(DBName, TableName  : TFileName) : TFileName;
{ Полной имя файла по DatabaseName и TableName }

function CopyStructure(Source, DestDatabaseName, DestName : TFileName; RewriteFile : Boolean) : Boolean;
{ Копирование структуры DBF. Rewrite = True -  перезаписать, если DestName уже существует }

function GetNPos(DatabaseName, SessionName : String; PosChar : Char) : Integer;
{ Получить номер последней обработанной посылки. PosChar - литера посылки: A, B или C }

function GetRabisPosMask(DatabaseName : String; PosCh : Char; SystemDate : TDateTime) : TFileName;
{ Маска поиска для посылок RABIS II
  DatabaseName - Path или Alias
  PosCh - признак типа посылки (A,B,C,V,D...)
  MFO - Свой БИК
  SystemDate - Системная дата
  Используется при импорте посылок
}

implementation

function GetAliasPath(const AliasName: string): string;
var
   SAlias: DBINAME;
   Desc: DBDesc;
   Params: TStrings;
begin
   Result := '';
   StrPLCopy(SAlias, AliasName, SizeOf(SAlias) - 1);
   AnsiToOem(SAlias, SAlias);
   Check(DbiGetDatabaseDesc(SAlias, @Desc));
   if StrIComp(Desc.szDbType, szCFGDBSTANDARD) = 0 then begin
      OemToAnsi(Desc.szPhyName, Desc.szPhyName);
      Result := StrPas(Desc.szPhyName);
      end
   else begin
      Params := TStringList.Create;
      try
         Session.Active := True;
         Session.GetAliasParams(AliasName, Params);
         Result := Params.Values['SERVER NAME'];
      finally
         Params.Free;
      end;
   end;
end; { GetAliasPath }

function GetPath(DatabaseName : String) : TFileName;
begin
   if IsDirectory(DatabaseName) then
      Result := DatabaseName
   else
      Result := GetAliasPath(DatabaseName);
   Result := AddSlash(Result);
end; { GetPath }

function GetFullName(DBName, TableName  : TFileName) : TFileName;
var
   Path : TFileName;
begin
   if IsDirectory(DBName) then
      Path := DBName
   else
      Path := GetAliasPath(DBName);
   Path := AddSlash(Path);
   if Pos('.', UpperCase(TableName)) = 0 then TableName := TableName + '.DBF';
   Result := Path + TableName;
end; { GetFullName }

function CopyStructure(Source, DestDatabaseName, DestName : TFileName; RewriteFile : Boolean) : Boolean;
var
   Path : TFileName;
begin
   if IsDirectory(DestDataBaseName) then
      Path := DestDataBaseName
   else
      Path := GetAliasPath(DestDatabaseName);
   if Path[Length(Path)] <> '\' then Path := Path + '\';
   if not ForceDirectories(Path) then
      raise Exception.CreateFmt(rs_sysCannotCreateDir, [Path]);
   DestName := Path + DestName;
   if FileExists(DestName) and (not RewriteFile) then
      Result := True
   else
      Result := CopyFile(Source, DestName);
end; { CopyStructure }

function GetNPos(DatabaseName, SessionName : String; PosChar : Char) : Integer;
{ Получить номер последней посылки }
var
   S : TStoredProc;
begin
   S := TStoredProc.Create(nil);
   S.DatabaseName := DatabaseName;
   S.SessionName := SessionName;
   S.StoredProcName := 'GETABC';
   with S.Params.CreateParam(ftString, 'PACKET', ptInput) do AsString := PosChar;
   with S.Params.CreateParam(ftInteger, 'NP', ptOutput) do;
   try
      S.Prepare;
      S.ExecProc;
   except
      S.Free;
      Result := -1;
      Exit;
   end; { try }
   Result := S.ParamByName('NP').AsInteger;
   S.Free;
end; { GetNPos }

function GetRabisPosMask(DatabaseName : String; PosCh : Char; SystemDate : TDateTime) : TFileName;
var
   D : String[2];
   Year, Month, Day : Word;
begin
   DecodeDate(SystemDate,  Year, Month, Day);
   if PosCh = 'D' then D := '?' else D := DecTo36(Month, 1);
   D := D + DecTo36(Day, 1);
   Result := GetPath(DatabaseName) + PosCh + D + '?????.???';
end; { GetRabisPosMask }

end.
