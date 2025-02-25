{$I-}
unit CNVUtils;

interface

uses
  Windows, Classes, SysUtils, FileCtrl,
  U36;

const
  rs_sysCannotCreateDir = 'Невозможно создать каталог %s';

{ Системные функции }

function GetEnv(zEnvStr : PChar) : String;
{ Получить значение переменной окружения zEnvStr. Пример: GetEnv('COMSPEC') }

function GetTempPath : String;
{ Получить временный путь. Либо переменная окружения TMP или TEMP,  либо текущий каталог }

function GenerateTempName : TFileName;
{ Сгенерировать временное имя (8 символов) без расширения }

function CopyFile(Source, Dest : TFileName) : Boolean;
{ Копирование файла Source в Dest }

function MoveFile(const FileName, DestName: string) : Boolean;
{ Перемещение файла FileName в DestName }

procedure DeleteFiles(const FileMask : TFileName);
{ Удаление файлов, заданных маской FileMask }

procedure WipeFiles(const FileMask : TFileName);
{ Удаление файлов, заданных маской FileMask с предварительной очисткой данных }

procedure SetFileTime(const FileName : TFileName; FileTime : TDateTime);
{ Установить дату/время на файл }

{ Системные функции при работе с БД }

function IsDirectory(const DatabaseName: string): Boolean;
{ True, если имя БД - каталог }

procedure CorrectDBF(FileName : TFileName);
{ Исправление кодовой таблицы в DBF. FileName - может быть маской DOS }

{ Строковые функции }

function Dos2Win(Value: string): string;
{ Преобразование из 866 в 1251 }

function Win2Dos(Value: string): string;
{ Преобразование из 1251 в 866 }

function AddSlash(Dir : TFileName) : TFileName;
{ Добавить "\" к каталогу Dir }

function LeadingZero(L : Longint; Len : Byte) : String;
{ Выход - строка с лидирующими нулями до длины Len. Пример: LeadingZero(123, 7) = '0000123'; }

function AddLeftZero(S : String; Len : Byte) : String;
{ Дополнение строки S лидирующими нулями до длины Len }

function Pad(S : String; Len : Integer) : String;
{ Дополнение строки S пробелами до длины Len }

function TimeToString(T : TDateTime) : String;
{ Время Т в формат чч:мм. Для посылок Рабис }

{ Функции Рабис }

function GetPosName(Ch : Char; NPos : Integer; MFOA, MFOB : Longint;
                    ClientID : Integer; SystemDate : TDateTime) : TFileName;
{ Сформировать имя посылки по заданным реквизитам. Используется при экспорте посылок }

function GetErrorPosMask(ZName : TFileName) : TFileName;
{ Определение маски для ошибочных посылок внутри посылки Z }

function XorStr(Str1, Str2: String): String;
{ "смешивание" последовательностей операцией XOR }

implementation

function GetEnv(zEnvStr : PChar) : String;
const
   Size = 256;
var
   Buffer : array[0..Size-1] of char;
begin
   GetEnvironmentVariable(zEnvStr, @Buffer, Size);
   Result := StrPas(Buffer);
end; { GetEnv }

function GetTempPath : String;
const
   Size = 255;
var
   P : array[0..Size] of Char;
   Res : DWORD;
begin
   Res := Windows.GetTempPath(Size+1, P);
   if Res = 0 then Result := ''
              else Result := StrPas(P);
end; { GetTempPath }

function TrimString(S : string; Len : Integer) : String;
begin
   Result := Copy(S, Length(S) - Len + 1, Len);
end; { TrimString }

function GenerateTempName : TFileName;
begin
   Randomize;
   Result := TrimString(IntToHex(Random(High(Cardinal)), 4), 4) +
             TrimString(IntToHex(Windows.GetTickCount, 4), 4);
end; { GenarateTempName }

function CopyFile(Source, Dest : TFileName) : Boolean;
var
   S, D : PChar;
begin
   S := StrAlloc(200);
   D := StrAlloc(200);
   S := StrPCopy(S, Source);
   D := StrPCopy(D, Dest);
   Result := Windows.CopyFile(S, D, False);
   StrDispose(S);
   StrDispose(D);
end; { CopyFile }

function HasAttr(const FileName: string; Attr: Word): Boolean;
begin
   Result := (FileGetAttr(FileName) and Attr) = Attr;
end; { HasAttr }

function MoveFile(const FileName, DestName: string) : Boolean;
var
   Destination: string;
begin
   Destination := ExpandFileName(DestName);
   Result := RenameFile(FileName, Destination);
   if not Result then begin
      Result := (not HasAttr(FileName, SysUtils.faReadOnly)) and
                CopyFile(FileName, Destination) and
                DeleteFile(FileName);
   end; { if }
end; { MoveFile }

procedure DeleteFiles(const FileMask : TFileName);
var
   SR : TSearchRec;
   DosError : Integer;
   Path : TFileName;
begin
   Path := ExtractFilePath(FileMask);
   DosError := FindFirst(FileMask, faArchive, SR);
   while DosError = 0 do begin
      DeleteFile(Path + SR.Name);
      DosError := FindNext(SR);
   end; { while }
   FindClose(SR);
end; { DeleteFiles }

procedure WipeFile(FileName : TFileName);
var
   F : TFileStream;
   Buffer : Pointer;
   Size : Longint;
begin
   F := TFileStream.Create(FileName, fmOpenWrite + fmShareExclusive);
   Size := F.Size;
   GetMem(Buffer, Size);
   FillChar(Buffer^, Size, 0);
   F.WriteBuffer(Buffer^, Size);
   F.Free;
   DeleteFile(FileName);
end; { WipeFile }

procedure WipeFiles(const Filemask : TFileName);
var
   SR : TSearchRec;
   DosError : Integer;
   Path : TFileName;
begin
   Path := ExtractFilePath(FileMask);
   DosError := FindFirst(FileMask, faArchive, SR);
   while DosError = 0 do begin
      try
         WipeFile(Path + SR.Name);
      except
      end;
      DosError := FindNext(SR);
   end; { while }
   FindClose(SR);
end; { WipeFiles }

procedure SetFileTime(const FileName : TFileName; FileTime : TDateTime);
var
   FHandle, Code : Integer;
begin
   FHandle := FileOpen(FileName, fmOpenReadWrite + fmShareExclusive);
   if FHandle > 0 then begin
      Code := FileSetDate(FHandle, DateTimeToFileDate(FileTime));
      if Code <> 0 then begin
         { Error }
      end;
      FileClose(FHandle);
   end; { if }
end; { SetFileTime }

function IsDirectory(const DatabaseName: string): Boolean;
var
   I: Integer;
begin
   Result := True;
   if (DatabaseName = '') then Exit;
   I := 1;
   while I <= Length(DatabaseName) do begin
      if DatabaseName[I] in [':','\'] then Exit;
      Inc(I);
   end;
   Result := False;
end; { IsDirectory }


procedure Correct(FileName : TFileName);
{ Исправление кодовой таблицы в DBF }
type
   THeader = array[0..31] of byte;
var
   F : File;
   Header : THeader;
   Blocks, OldMode : Integer;
begin
   AssignFile(F, FileName);
   OldMode := FileMode;
   FileMode := fmOpenReadWrite + fmShareDenyWrite;
   try
      Reset(F, 1);
      if IOResult = 0 then begin
         BlockRead(F, Header, SizeOf(Header), Blocks);
         if not (Header[$1D] in [$00, $26]) then begin
            Header[$1D] := $26;
            Seek(F, 0);
            BlockWrite(F, Header, SizeOf(Header), Blocks);
         end; { if }
         CloseFile(F);
         IOResult; { Clear IOResult flag }
      end; { if }
   finally
      FileMode := OldMode;
   end; { try }
end; { Correct }

procedure CorrectDBF(FileName : TFileName);
var
   SR : TSearchRec;
   DosError : Integer;
begin
   DosError := FindFirst(FileName, faArchive, SR);
   while DosError = 0 do begin
      Correct(ExtractFilePath(FileName) + SR.Name);
      DosError := FindNext(SR);
   end; { while }
   FindClose(SR);
end; { CorrectDBF }

function Dos2Win(Value: string): string;
var
   P : PChar;
begin
   GetMem(P, Length(Value) + 1);
   try
      StrPCopy(P, Value);
      //OemToAnsi(PWideChar(P), PAnsiChar(P));
      Result := P;
   finally
      FreeMem(P, Length(Value) + 1);
   end;
end; { Dos2Win }

function Win2Dos(Value: string): string;
var
   P : PChar;
begin
   GetMem(P, Length(Value) + 1);
   try
      StrPCopy(P, Value);
      //AnsiToOem(P, P);
      Result := P;
   finally
      FreeMem(P, Length(Value) + 1);
   end;
end; { Win2Dos }

function AddSlash(Dir : TFileName) : TFileName;
begin
   if (Length(Dir) > 0) and (Dir[Length(Dir)] <> '\') then Dir := Dir + '\';
   Result := Dir;
end; { AddSlash }

function LeadingZero(L : Longint; Len : Byte) : String;
begin
   Result := IntToStr(L);
   while Length(Result) < Len do Result := '0' + Result;
end; { LeadingZero }

function AddLeftZero(S : String; Len : Byte) : String;
begin
   S := Trim(S);
   if Length(S) > 0 then while Length(S) < Len do S := '0' + S;
   Result := S;
end; { AddLeftZero }

function Pad(S : String; Len : Integer) : String;
begin
   while Length(S) < Len do S := S + ' ';
   Result := S;
end; { Pad }

function TimeToString(T : TDateTime) : String;
var
   H, M, S, S100 : Word;
begin
   DecodeTime(T, H, M, S, S100);
   Result := LeadingZero(H, 2) + ':' + LeadingZero(M, 2);
end; { TimeToString }

function GetNum(MFO : Longint) : String;
begin
   if (MFO mod 1000) > 10 then Result := LeadingZero(MFO mod 1000, 3)
                          else Result := LeadingZero((MFO div 1000) mod 100, 3);
end; { GetNum }

function GetPosName(Ch : Char; NPos : Integer; MFOA, MFOB : Longint;
                    ClientID : Integer; SystemDate : TDateTime) : TFileName;
{ Сформировать имя посылки }
var
   Year, Month, Day : Word;
   S : String[3];
begin
   DecodeDate(SystemDate, Year, Month, Day);
   if ClientID = 0 then S := GetNum(MFOA) else S := LeadingZero(ClientID, 3);
   Result := Ch + DecTo36(Month, 1) + DecTo36(Day, 1) + DecTo36(NPos, 2) +
             S + '.' + GetNum(MFOB);
end; { GetPosName }

function GetErrorPosMask(ZName : TFileName) : TFileName;
var
   BankNum, RkcNum : String[3];
begin
   RkcNum := Copy(ZName, 5, 3);
   BankNum := Copy(ZName, 10, 3);
   Result := '?????' + BankNum + '.' + RkcNum;
end; { GetErrorPosMask }

function XorStr(Str1, Str2: String): String;
var i: Integer;
begin
   if Length(Str1)<>Length(Str2) then Result := ''
   else begin
      SetLength(Result, Length(Str1));
      For i:=1 to Length(Str1) do begin
         Result[i] := Chr(Ord(Str1[i]) xor Ord(Str2[i]));
      end;
   end;
end; {StrXorMix}

end.
