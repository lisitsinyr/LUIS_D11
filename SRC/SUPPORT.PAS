(*
 $Log:   F:/home/gm/pvsc/generate/support.pav  $
 *
 *    Rev 1.2   Jan 19 1998 18:44:30   UGEEN
 *
 *
 *    Rev 1.1   Jan 03 1998 11:20:52   UGEEN
 *
*)
unit Support;

interface

uses
   Graphics,SysUtils, Classes, DBIProcs, DBITypes, Controls, WinProcs,
   Forms, Dialogs, StdCtrls, DBIErrs, DB, DBTables, bVars,
   FileCtrl, { DWinSock, WSAPI, } VCLUtils, DBCtrls, StrUtils;

type
  TClient = (ClientRKC, ClientBank);
  TOnLineStatus = (os_NotFound, os_OnLine, os_OffLine);

function getKey(a: integer): longint;

function GetBaseNum(DBName : String; Param : Integer) : String;

function GetNetUserName: string;
{ Return: Novell Netware Login Name }

function PathAPP: String;
{ Return: Path of Application }

function DelSlash(const APath: string): string;

function RecDate(Adate: string):string;

function Dos2Win(Value: string): string;
{ Return: DOS -> WIN for string}

function Win2Dos(Value: string): string;
{ Return: WIN -> DOS for string}

procedure Dos2WinP(Sin: PChar; var Sout: PChar);
{         DOS -> WIN for PChar}

procedure Win2DosP(Sin: PChar; var Sout: PChar);
{         WIN -> DOS for PChar}

function Char2String(AChar: array of char): string;
{ Return: Stroka from array of char (end = '00'}

procedure String2Char(AString: string; Var AChar: array of char);
{         arrray of char from string }

function Pad(S : string; Len : Integer) : string;
function PadCh(S : string; Ch : Char; Len : Integer) : string;
function LeftPadCh(S : string; Ch : Char; Len : Integer) : string;
function LeftPad(S : string; Len : Integer) : string;
(*
function HexPtr(P : Pointer) : string;
  {-Return hex string for pointer}
*)
function DeleteChars1(S : string) : string;


function HexB(B : Byte) : string;
  {-Return hex string for byte}

function HexW(W : Word) : string;
  {-Return hex string for word}

function HexL(L : LongInt) : string;
  {-Return hex string for longint}


function BinaryB(B : Byte) : string;
  {-Return binary string for byte}

function BinaryW(W : Word) : string;
  {-Return binary string for word}

function BinaryL(L : LongInt) : string;
  {-Return binary string for longint}

function MyFindComponent(Owner: Tcomponent; const AName: string): TComponent;

procedure EditComponent(Owner: Tcomponent; const AName: string; AReadOnly: Boolean);

procedure EditComponentView(Owner: Tcomponent; const AName: string; AView: Boolean);

procedure SetAttrDBCtrl(Owner: Tcomponent; const AName: string; AReadOnly: Boolean);

procedure SetErrorDBCtrl(Sender: TObject; AError,ASelect: Boolean);

function FormatDateString(Picture, ADate: string): string;

function FormatDate(Picture: string; ADate: TDateTime): string;

function NewEncodeDate(AYY,AMM,ADD: word): TDateTime;

function FormatLongDate1(ADate: TDateTime): string;

function FormatTime(Picture: string; ATime: TDateTime): string;

(*
function GetKey(AHostAddr: Longint): Longint;
{ Generate Key for tDocument }
function GetHostAddrL: Longint;
{ Address local host }
function GetHostAddr: string;
{ Address local host }
*)

function GetProtectedKey(MFO, LS : Longint) : Integer;
{ Вычисление защитного разряда }

function CheckProtectedKey(MFO, LS : Longint; Client : TClient) : Boolean;
{ Проверка защитного разряда }

function GetMfo5String(Amfo5: Longint): string;

function RegionFromMFO9(Amfo9: Longint): Integer;


procedure CutFile(AFileIn, AFileOut: string; ABegin: Longint; WEOF: Boolean);
procedure CutFileMiddle(AFileIn, AFileOut: string; ABegin, ACount: Longint; WEOF: Boolean);
procedure CopyFileText(AFileIn, AFileOut: string; WEOF: Boolean);

procedure MoveFile(APathIn, APathOut, AFileName: string);
procedure CopyFile(APathIn, APathOut, AFileName: string);
procedure AddFile(AFileIn, AFileAdd: string);


procedure ErrorMessageBox(ErrorText : String);
{ DialogBox с сообщением ErrorText и кнопкой OK }

function MessageBox(Text, Caption : String; Flags : Word) : Integer;
{ Аналог стандартного MessageBox без Pchar }

function InformixDateTime(DateTime : TDateTime) : String;
{ Правильная дата для Informix }

function ODBCString(const AStr : string) : String;
{ Правильная string для ODBC }

function SystemOnLine(DatabaseName : TFileName; SystemCode : Integer; UserID : Integer; var SystemDate : TDateTime) : Integer;
{  0 - система не работает
   1 - система работает
  -1 - система не включена в обработку
}

procedure SetOnLine(DatabaseName : TFileName; System : Integer; UserID : Integer; TurnOn : Boolean);

function GetSystemStatus(DatabaseName : TFileName; SystemID, UserID : Integer; var SystemDate : TDateTime) : TOnLineStatus;

procedure SetSystemStatus(DatabaseName : TFileName; SystemID, UserID : Integer; TurnOn : Boolean);


function ODBDate : TDateTime;
{ Возвращает дату работы ОДБ или 0 в случае неудачи }

function Age(Date : TDateTime) : Longint;
{ Возвращает возраст в днях }

function GetDateTime(ADate: TDateTime): TDateTime;
{ Return : Дата + текущее время }

function LeadingZero(L : Longint; Len : Byte) : String;
{ Дополнение ведущими нулями }

function MakeAccount(Mask : Longint; DT : TDateTime; MFO, MyMFO : Longint) : longint{TAccountStr};
{ Вычисление счета }

function CreateStringForNumber(Value:Extended):PChar;
{ Пропись суммы Return : For Close - StrDispose }

function UpcaseRus(ACh: Char): char;
{ Upcase русских символов }

procedure FormatString(const Value: string; Len: Integer;
                       var Buf: array of string);

procedure FormatStringP(const Value: PChar; Len: Integer;
                       var Buf: array of string);

function GetFileNameTemp: string;
{ Имя вркменного файла }

function GetMonth(DT : TDateTime) : Integer;
{ Месяц из даты }

function CreateDir(const APathName : string): Boolean;
{ Создание директории }

function CreateDirDate(const APathName : string; ADate: TDateTime): string;
{ Создание директории по дате }

function CheckAccountBS(AAccount: Longint): Boolean;
{ Проверка счета на БС1 и БС2 }

function GetTypeBankShort(ATypeBank: Integer): string;
{ Тип банка по коду }

function GetCityTypeName(ACityType: Integer): string;
{ Тип города по коду }

procedure NullString(var AString);

function NumberFiles(const APath,AShablon : string): Integer;
{ Число файлов по шаблону }

procedure LoadNameFiles(const APath,AShablon : string; var AList: TStringList);
{ Загрузить имена файлов по шаблону }

procedure SetLockMode(AWait: Boolean);
{ Установить режим блокировки }

procedure LockTable(ATableName: string; AMode: Boolean);
{ блокировать таблицу }

type
  TErrorQuery = class(TQuery)
    constructor Create(Owner : TComponent); override;
    function GetMessage(ErrorNum : Integer) : String;
    function GetSystemMessage(SystemError, SystemID : Integer) : String;
    function TranslateTo(ErrorNum, SystemID : Integer) : Integer;
    function GetErrorsBySystem(SystemID : Integer) : TQuery;
  private
    function GetFieldName(SystemID : Integer) : String;
  end; { TErrorQuery }

const
   HostAddrL : Longint = 0;
   HostAddr  : string  = '';

implementation

type
  Long =
    record
      LowWord, HighWord : Word;
    end;
const
  Digits : array[0..$F] of Char = '0123456789ABCDEF';

function DelSlash(const APath: string): string;
begin
   Result := APath;
   if APath[Length(APath)] = '\' then
      SetLength(Result,Length(APath)-1);
end;

{ --- TErrorQuery --- }

constructor TErrorQuery.Create(Owner : TComponent);
begin
  inherited Create(Owner);
  DatabaseName := bGMDatabaseName;
end; { TErrorWuery }

function TErrorQuery.GetMessage(ErrorNum : Integer) : String;
var
  rc : Longint;
begin
  GetMessage := '';
  Close; SQL.Clear;
  SQL.Add('Select * from ' + ErrorsTableName +
          ' where ErrorCode = ' + IntToStr(ErrorNum));
  try
    Open;
  except
    Exit;
  end;
  rc := RecordCount;
  if rc <> 0 then
    GetMessage := FieldByName('ErrorName').AsString
  else
    GetMessage := '';
end; { TErrorQuery.GetMessage }

function TErrorQuery.GetSystemMessage(SystemError, SystemID : Integer) : String;
var
  FieldName : String[12];
  rc : Longint;
begin
  GetSystemMessage := '';
  FieldName := GetFieldName(SystemID);
  if FieldName = '' then Exit;
  Close; SQL.Clear;
  SQL.Add('Select * from ' + ErrorsTableName +
          ' where ' + FieldName + ' = ' + IntToStr(SystemError) +
          ' order by ErrorCode');
  try
    Open;
  except
    Exit;
  end;
  rc := RecordCount;
  First;
  if rc <> 0 then
    GetSystemMessage := FieldByName('ErrorName').AsString
  else
    GetSystemMessage := '';
end; { TErrorQuery.GetSystemMessage }

function TErrorQuery.TranslateTo(ErrorNum, SystemID : Integer) : Integer;
var
  FieldName : String[12];
  rc : Longint;
begin
  TranslateTo := -1;
  FieldName := GetFieldName(SystemID);
  if FieldName = '' then Exit;
  Close; SQL.Clear;
  SQL.Add('Select * from ' + ErrorsTableName +
          ' where ErrorCode = ' + IntToStr(ErrorNum));
  try
    Open;
  except
    Exit;
  end;
  rc := RecordCount;
  if rc <> 0 then
    TranslateTo := FieldByName(FieldName).AsInteger
  else
    TranslateTo := -1;
end; { TErrorQuery.TranslateTo }

function TErrorQuery.GetErrorsBySystem(SystemID : Integer) : TQuery;
var
  Q : TQuery;
  FieldName : String[12];
begin
  GetErrorsBySystem := nil;
  FieldName := GetFieldName(SystemID);
  if FieldName = '' then Exit;
  Q := TQuery.Create(nil);
  Q.DatabaseName := bGMDatabaseName;
  Q.SQL.Add('Select * from ' + ErrorsTableName +
            ' where ' + FieldName + ' <> 0');
  try
    Q.Open;
  except
    Q.Free;
    Q := nil;
  end;
  GetErrorsBySystem := Q;
end; { TErrorQuery.GetErrorsBySystem }

function TErrorQuery.GetFieldName(SystemID : Integer) : String;
begin
  case SystemId of
    idSpacard : GetFieldName := 'ErrorSpacard';
    idElsimer : GetFieldName := 'ErrorElsimer';
    else
      GetFieldName := '';
  end; { case }
end; { TErrorQuery.GetFieldName }

{ --- }

function GetBaseNum(DBName : String; Param : Integer) : String;
var
  S : TStoredProc;
begin
  S := TStoredProc.Create(nil);
  S.DatabaseName := DBName;
  S.StoredProcName := 'GETBASENUM';
  with S.Params.CreateParam(ftInteger, 'BASEID', ptInput) do
    AsInteger := Param;
  with S.Params.CreateParam(ftString, 'BN', ptOutput) do;
  try
    S.Prepare;
    S.ExecProc;
  except
    S.Free;
    Exit;
  end; { try }
  Result := S.ParamByName('BN').AsString;
  S.Free;
end; { GetBaseNum }

function RecDate(Adate: string):string;
var
   dd,mm,gg: string[2];
begin
   dd := Copy(Adate,1,2);
   mm := Copy(Adate,3,2);
   gg := Copy(Adate,5,2);
   RecDate := mm+'/'+dd+'/'+gg;
end;

function PathAPP: String;
begin
   PathAPP := ExtractFilePath(ExpandFileName(ParamStr(0)));
end;

function Dos2Win(Value: string): string;
var
   s: array[byte] of Char;
begin
   StrPCopy(s, Value);
   OemToAnsi(s,s);
   Result := StrPas(s);
end;

function Win2Dos(Value: string): string;
var
   s: array[byte] of Char;
begin
   StrPCopy(s, Value);
   AnsiToOem(s,s);
   Result := StrPas(s);
end;

procedure Dos2WinP(Sin: PChar; var Sout: PChar);
begin
   OemToAnsi(sin,sout);
end;

procedure Win2DosP(Sin: PChar; var Sout: PChar);
begin
   AnsiToOem(sin,sout);
end;

function Char2String(AChar: array of char): string;
var
   s : string;
   l : Integer;
begin
   l := SizeOF(AChar);
   Move (AChar, s[1], l);
   SetLength(s,l);
   Result := s;
end;

procedure String2Char(AString: string; Var AChar: array of char);
var
   l : Byte;
begin
   FillChar(AChar, SizeOF(AChar), ' ');
   l := Length(AString);
   if (l > 0) and (l <= SizeOF(AChar)) then
      Move (AString[1], AChar[SizeOf(AChar)-l], l);
end;

function PadCh(S : string; Ch : Char; Len : Integer) : string;
 {-Return a string right-padded to length len with ch}
begin
   Result := AddCharR(Ch, S, Len);
end;

function Pad(S : string; Len : Integer) : string;
{-Return a string right-padded to length len with blanks}
begin
(*
   Result := PadCh(S, ' ', Len);
*)
   Result := LeftStr(S, Len);
end;

function LeftPadCh(S : string; Ch : Char; Len : Integer) : string;
{-Return a string left-padded to length len with ch}
begin
   Result := AddChar(Ch, S, Len);
end;

function LeftPad(S : string; Len : Integer) : string;
{-Return a string left-padded to length len with blanks}
begin
(*
   Result := LeftPadCh(S, ' ', Len);
*)
   Result := RightStr(S, Len);
end;

function DeleteChars1(S : string) : string;
var
   SLen,i,j : Integer;
begin
   Result := '';
   SLen := Length(S);
   i := 1;
   j := 0;
   while (i <= SLen) do begin
      Inc(j);
      SetLength(Result,j);
      if (S[i] >= ' ') then Result[j] := S[i]
                       else Result[j] := ' ';
      Inc(i);
   end;
end;

function HexB(B : Byte) : string;
  {-Return hex string for byte}
begin
  {HexB[0] := #2;}
  SetLength(Result, 2);
  HexB[1] := Digits[B shr 4];
  HexB[2] := Digits[B and $F];
end;

function HexW(W : Word) : string;
  {-Return hex string for word}
begin
  {HexW[0] := #4;}
  SetLength(Result, 4);
  HexW[1] := Digits[hi(W) shr 4];
  HexW[2] := Digits[hi(W) and $F];
  HexW[3] := Digits[lo(W) shr 4];
  HexW[4] := Digits[lo(W) and $F];
end;

function HexL(L : LongInt) : string;
  {-Return hex string for LongInt}
begin
  with Long(L) do
    HexL := HexW(HighWord)+HexW(LowWord);
end;
(*
function HexPtr(P : Pointer) : string;
  {-Return hex string for pointer}
begin
  HexPtr := HexW(Seg(P^))+':'+HexW(Ofs(P^));
end;
*)
function BinaryB(B : Byte) : string;
  {-Return binary string for byte}
var
  I, N : Word;
begin
  N := 1;
  {BinaryB[0] := #8;}
  SetLength(Result,8);
  for I := 7 downto 0 do begin
    Result[N] := Digits[Ord(B and (1 shl I) <> 0)]; {0 or 1}
    Inc(N);
  end;
end;

function BinaryW(W : Word) : string;
  {-Return binary string for word}
var
  I, N : Word;
begin
  N := 1;
  {BinaryW[0] := #16;}
  SetLength(Result,16);
  for I := 15 downto 0 do begin
    Result[N] := Digits[Ord(W and (1 shl I) <> 0)]; {0 or 1}
    Inc(N);
  end;
end;

function BinaryL(L : LongInt) : string;
  {-Return binary string for LongInt}
var
  I : LongInt;
  N : Byte;
begin
  N := 1;
  {BinaryL[0] := #32;}
  SetLength(Result,32);
  for I := 31 downto 0 do begin
    Result[N] := Digits[Ord(L and LongInt(1 shl I) <> 0)]; {0 or 1}
    Inc(N);
  end;
end;

function MyFindComponent(Owner: Tcomponent; const AName: string): TComponent;
var
  I: Integer;
begin
   if (AName <> '') and (Owner.ComponentCount > 0) then begin
      for I := 0 to Owner.ComponentCount - 1 do begin
         Result := Owner.Components[I];
         if CompareText(UpperCase(Result.Name), UpperCase(AName)) = 0 then Exit;
      end;
   end;
   Result := nil;
end;

procedure EditComponent(Owner: Tcomponent; const AName: string; AReadOnly: Boolean);
var
  I: Integer;
  E: TComponent;
begin
   if (AName <> '') and (Owner.ComponentCount > 0) then begin
      for I := 0 to Owner.ComponentCount - 1 do begin
         E := Owner.Components[I];
         if CompareText(UpperCase(E.Name), UpperCase(AName)) = 0 then begin
            if E is TEdit then begin
               TEdit(E).ReadOnly := AReadOnly;
               if AReadOnly then begin
                  TEdit(E).AutoSelect := False;
                  TEdit(E).TabStop := False;
                  end
               else begin
                  TEdit(E).AutoSelect := True;
                  TEdit(E).TabStop := True;
               end;
            end;

            if E is TMemo then begin
               TMemo(E).ReadOnly := AReadOnly;
               if AReadOnly then begin
                  TMemo(E).TabStop := False;
                  end
               else begin
                  TMemo(E).TabStop := True;
               end;
            end;
            
         end;
      end;
   end;
end;

procedure SetAttrDBCtrl(Owner: Tcomponent; const AName: string; AReadOnly: Boolean);
var
  E: TComponent;
begin
   if (AName <> '') then begin
      E := Owner.FindComponent(AName);
      if Assigned(E) then begin
         if E is TDBEdit then begin
            TDBEdit(E).ReadOnly := AReadOnly;
            TDBEdit(E).AutoSelect := not AReadOnly;
            TDBEdit(E).TabStop := not AReadOnly;
            if AReadOnly then TDBEdit(E).Color := cl3DLight
                         else TDBEdit(E).Color := clWindow;
         end;
         if E is TDBMemo then begin
            TDBMemo(E).ReadOnly := AReadOnly;
            TDBMemo(E).TabStop := not AReadOnly;
            if AReadOnly then TDBMemo(E).Color := cl3DLight
                         else TDBMemo(E).Color := clWindow;
         end;
      end;
   end;
end;

procedure SetErrorDBCtrl(Sender: TObject; AError,ASelect: Boolean);
begin
   if Sender is TDBEdit then begin
      with (Sender as TDBEdit) do begin
         if AError then begin
            Font.Color := clWhite;
            Color      := clRed;
            end
         else begin
            Font.Color := clBlack;
            if ASelect then Color := clYellow
                       else Color := clWhite;
         end;
      end;
   end;
   if Sender is TEdit then begin
      with (Sender as TEdit) do begin
         if AError then begin
            Font.Color := clWhite;
            Color := clRed;
            end
         else begin
            Font.Color := clBlack;
            Color :=  clWhite;
         end;
      end;
   end;
   if Sender is TDBMemo then begin
      with (Sender as TDBMemo) do begin
         if AError then begin
            Font.Color := clWhite;
            Color := clRed;
            end
         else begin
            Font.Color := clBlack;
            Color :=  clWhite;
         end;
      end;
   end;
end;

procedure EditComponentView(Owner: Tcomponent; const AName: string; AView: Boolean);
var
  I: Integer;
  E: TComponent;
begin
   if (AName <> '') and (Owner.ComponentCount > 0) then begin
      for I := 0 to Owner.ComponentCount - 1 do begin
         E := Owner.Components[I];
         if CompareText(UpperCase(E.Name), UpperCase(AName)) = 0 then begin
            TControl(E).Visible := AView;
         end;
      end;
   end;
end;

function FormatDateString(Picture, ADate: string): string;

   function ExtractFromPicture(APicture, S: string; Ch : Char): string;
   var
      Tmp  : string;
      TLen : Integer;
      PLen : Integer;
      J    : Integer;
      {Date1: TDateTime;}
      d,m,y: word;
   begin
      PLen := Length(APicture);
      J := Pos(Upcase(Ch), UpperCase(APicture));
      if j > 0 then begin
         TLen := 0;
         while (Upcase(APicture[J]) = Upcase(Ch)) and (J <= PLen) do begin
            if S[J] <> ' ' then begin
               Inc(TLen);
               SetLength(TMP, TLen);
               Tmp[TLen] := S[J];
            end;
            Inc(J);
         end;
         Result := TMP;
         end
      else begin
         DecodeDate(SysUtils.Date, y,m,d);
         case Ch of
            'm': Result := IntToStr(m);
            'd': Result := IntToStr(d);
            'y': Result := IntToStr(y);
         end;
      end;
   end;

begin
   Result := ExtractFromPicture(Picture, ADate, 'd')+DateSeparator+
             ExtractFromPicture(Picture, ADate, 'm')+DateSeparator+
             ExtractFromPicture(Picture, ADate, 'y');
end;

function NewEncodeDate(AYY,AMM,ADD: word): TDateTime;
var S : string;
begin
   Result := EncodeDate(AYY,AMM,ADD);
   S      := DateToStr(Result);
   Result := StrToDate(S);
end;

function FormatDate(Picture: string; ADate: TDateTime): string;
var
   Tmp  : string;
   PLen : Byte;
   d,m,y: word;
   J,i  : Integer;
   Adr  : Byte;
   Ch : Char;

begin
   Result := '';
   DecodeDate(ADate, y,m,d);
   PLen := Length(Picture);
   J := 1;
   while (J <= PLen) do begin
      Ch := Upcase(Picture[J]);
      Adr := J;
      while (Upcase(Picture[J]) = Ch) and (J <= PLen) do Inc(j);
      i := j - Adr;
      case Ch of
         'M': Tmp := IntToStr(M);
         'D': Tmp := IntToStr(D);
         'Y': Tmp := IntToStr(Y);
      else
         Tmp := Copy(Picture, Adr, i);
      end;
      if Length(Tmp) < i then
         Tmp := LeftPadCh(Tmp, '0', i);
      if Length(Tmp) > i then
         Tmp := Copy(Tmp, Length(Tmp)-i+1, i);
      Result := Result + Tmp;
   end;
end;

function FormatLongDate1(ADate: TDateTime): string;
const
   NameM : array [1..12] of string[20] = (
   'января','февраля','марта','апреля','мая','июня',
   'июля','августа','сентября','октября','ноября','декабря');
var
   d,m,y: word;
begin
   DecodeDate(ADate, y,m,d);
   Result := IntToStr(d)+' '+NameM[m]+' '+IntToStr(y)+' г.';;
end;

function FormatTime(Picture: string; ATime: TDateTime): string;
var
   Tmp  : string;
   PLen : Byte;
   h,m,s,ms: word;
   J,I  : Integer;
   Adr  : Byte;
   Ch : Char;

begin
   Result := '';
   DecodeTime(ATime, h,m,s,ms);
   PLen := Length(Picture);
   J := 1;
   while (J <= PLen) do begin
      Ch := Upcase(Picture[J]);
      Adr := J;
      while (Upcase(Picture[J]) = Ch) and (J <= PLen) do Inc(j);
      i := j - Adr;
      case Ch of
         'H': Tmp := IntToStr(H);
         'M': Tmp := IntToStr(M);
         'S': Tmp := IntToStr(S);
      else
         Tmp := Copy(Picture, Adr, i);
      end;
      if Length(Tmp) < i then
         Tmp := LeftPadCh(Tmp, '0', i);
      if Length(Tmp) > i then
         Tmp := Copy(Tmp, Length(Tmp)-i+1, i);
      Result := Result + Tmp;
   end;
end;

(*
function GetKey(AHostAddr: Longint): Longint;
begin
   Result := (GetHostAddrL and $FFFF0000) or Random($FFFF);
end;

function GetHostAddrL: Longint;
var
   ClientSocket1 : TBasicClientSocket;
   AddrHosts     : in_addr;
begin
   Result := 0;
   ClientSocket1 := TBasicClientSocket.Create(nil);
   try
      with ClientSocket1 do begin
         Address := 'localhost';
         Port    := 'echo';
         TimeOut := 30;
         {
         OnConnect := MyOnConnect;
         OnRead := MyOnRead;
         OnWrite := MyOnWrite;
         OnDisconnect := MyOnDisconnect;
         OnTimeOut := MyOnTimeOut;
         }
         Open( TStreamSocket );
         AddrHosts := LookupAddrByName(LocalHost);
         Result := AddrHosts.S_addr;
      end;
   except
      on E : ESockError do ShowMessage(E.Message);
   end;
   ClientSocket1.Free;
end;

function GetHostAddr: string;
var
   ClientSocket1 : TBasicClientSocket;
begin
   Result := '';
   ClientSocket1 := TBasicClientSocket.Create(nil);
   try
      with ClientSocket1 do begin
         Address := 'localhost';
         Port    := 'echo';
         TimeOut := 30;
         {
         OnConnect := MyOnConnect;
         OnRead := MyOnRead;
         OnWrite := MyOnWrite;
         OnDisconnect := MyOnDisconnect;
         OnTimeOut := MyOnTimeOut;
         }
         Open( TStreamSocket );
         Result := LookupAddrByNameStr(LocalHost);
      end;
   except
      on E : ESockError do ShowMessage(E.Message);
   end;
   ClientSocket1.Free;
end;

*)

const
  Mask : string[12] = '713371371371';

function GetProtectedKey(MFO, LS : Longint) : Integer;
var
  S : String;
  I : Word;
  Sum : Longint;
begin
  S := LeadingZero((MFO div 1000) mod 100, 3) + LeadingZero(LS, 9);
  Sum := 0;
  for I := 1 to Length(S) do
    Sum := Sum + (Ord(Mask[I])-48)*(Ord(S[I])-48);
  GetProtectedKey := (Sum * 3) mod 10;
end; { GetProtectedKey }

function CheckProtectedKey(MFO, LS : Longint; Client : TClient) : Boolean;
var
  S : String;
  I : Word;
  Sum : Longint;
begin
  Sum := 0;
  if (Client = ClientBank) then
    S := LeadingZero(MFO mod 1000, 3)
  else
    S := LeadingZero((MFO div 1000) mod 100, 3);
  S := S + LeadingZero(LS, 9);
  for I := 1 to Length(S) do
    Sum := Sum + (Ord(Mask[I])-48)*(Ord(S[I])-48);
  CheckProtectedKey := (Sum mod 10) = 0;
end; { CheckProtectedKey }

function GetMfo5String(Amfo5: Longint): string;
   function GetNumber(Ch: Char): integer;
   begin
      Result := 0;
      if Ch in ['0'..'9'] then Result := Ord(Ch) and $0F;
   end;
var
   s  : string;
   key: byte;
begin
   s := IntToStr(Amfo5);
   { ABCDE }
   { KEY = mod(A + B*3 + C*7 + D + E*3)*7, 10)     }
   { 79000                                         }
   { (7 + 9*3 + 0*7 + 0 + 0*3 ) * 7 = 34 * 7 = 238 }
   { KEY =                                       8 }
   key := ((GetNumber(s[1]) + GetNumber(s[2])*3 + GetNumber(s[3])*7 +
            GetNumber(s[4]) + GetNumber(s[5])*3)*7) mod 10;
   result := S + Chr(key or $30) + '000';
end;

function RegionFromMFO9(Amfo9: Longint): Integer;
begin
   Result := (AMFO9 div 100000) mod 100;
end;

procedure CopyFile(APathIn, APathOut, AFileName: string);
var
   FromF : file;
   ToF   : file;
   NumRead, NumWritten: Integer;
   Buf   : array[1..2048] of Char;
   FM    : Byte;
begin
   if APathIn <> APathOut then begin
      FM := FileMode;
      AssignFile(FromF, DelSlash(APathIn)+'\'+AFileName);
      FileMode := 0;  { Set file access to read only }
      Reset(FromF, 1);
      AssignFile(ToF, DelSlash(APathOut)+'\'+AFileName);
      FileMode := 1;  { Set file access to write only }
      Rewrite(ToF, 1);
      NumWritten := 0;
      repeat
         BlockRead(FromF, Buf, SizeOf(Buf), NumRead);
         if (Buf[NumRead] = #26) then Dec(NumRead);
         BlockWrite(ToF, Buf, NumRead, NumWritten);
      until (NumRead = 0) or (NumWritten <> NumRead);
      System.CloseFile(FromF);
      System.CloseFile(ToF);
      FileMode := FM;
   end;
end;

procedure CopyFileText(AFileIn, AFileOut: string; WEOF: Boolean);
var
   FromF: file;
   ToF  : file;
   NumRead, NumWritten: Integer;
   Buf: array[1..2048] of Char;
   FM : Byte;

   procedure WriteEOF;
   begin
      Buf[1] := #26;
      BlockWrite(ToF, Buf, 1, NumWritten);
   end;
   procedure WriteEOD;
   begin
      Buf[1] := #13;
      Buf[2] := #10;
      BlockWrite(ToF, Buf, 2, NumWritten);
   end;

begin
   if AFileIn <> AFileOut then begin
      FM := FileMode;
      AssignFile(FromF, AFileIn);
      FileMode := 0;  { Set file access to read only }
      Reset(FromF, 1);
      AssignFile(ToF, AFileOut);
      FileMode := 1;  { Set file access to write only }
      Rewrite(ToF, 1);
      NumWritten := 0;
      repeat
         BlockRead(FromF, Buf, SizeOf(Buf), NumRead);
         if NumRead > 0 then begin
            if (Buf[NumRead] = #26) then Dec(NumRead);
            BlockWrite(ToF, Buf, NumRead, NumWritten);
         end;
      until (NumRead = 0) or (NumWritten <> NumRead);
      if Buf[NumWritten] <> #10 then WriteEOD;
      if WEOF then WriteEOF;

      System.CloseFile(FromF);
      System.CloseFile(ToF);
      FileMode := FM;
   end;
end;

procedure AddFile(AFileIn, AFileAdd: string);
var
   FromF: file;
   ToF  : file;
   NumRead, NumWritten: Integer;
   Buf  : array[1..2048] of Char;
   FM   : Byte;
begin
   {$I-}
   if AFileIn <> AFileAdd then begin
      FM := FileMode;
      AssignFile(ToF, AFileIn);
      (*
      FileMode := 0;  { Set file access to read only }
      FileMode := 1;  { Set file access to write only }
      FileMode := 2;  { Set file access to read/write only }
      *)
      FileMode := 2;  { Set file access to read/write only }
      System.Reset(ToF, 1);
      System.Seek(ToF, FileSize(ToF));
      AssignFile(FromF, AFileAdd);
      Reset(FromF, 1);
      repeat
         BlockRead(FromF, Buf, SizeOf(Buf), NumRead);
         if (Buf[NumRead] = #26) then Dec(NumRead);
         BlockWrite(ToF, Buf, NumRead, NumWritten);
      until (NumRead = 0) or (NumWritten <> NumRead);
      System.CloseFile(FromF);
      System.CloseFile(ToF);
      FileMode := FM;
   end;
   {$I+}
end;

procedure CutFile(AFileIn, AFileOut: string; ABegin: Longint; WEOF: Boolean);
var
   FromF: file;
   ToF  : file;
   NumRead, NumWritten: Integer;
   Buf: array[1..2048] of Char;
   FM : Byte;

   procedure WriteEOF;
   begin
      Buf[1] := #26;
      BlockWrite(ToF, Buf, 1, NumWritten);
   end;
   procedure WriteEOD;
   begin
      Buf[1] := #13;
      Buf[2] := #10;
      BlockWrite(ToF, Buf, 2, NumWritten);
   end;

begin
   if AFileIn <> AFileOut then begin
      FM := FileMode;
      AssignFile(FromF, AFileIn);
      FileMode := 0;  { Set file access to read only }
      Reset(FromF, 1);
      Seek(FromF, ABegin);
      AssignFile(ToF, AFileOut);
      FileMode := 1;  { Set file access to write only }
      Rewrite(ToF, 1);
      repeat
         BlockRead(FromF, Buf, SizeOf(Buf), NumRead);
         if NumRead > 0 then begin
            if (Buf[NumRead] = #26) then Dec(NumRead);
            BlockWrite(ToF, Buf, NumRead, NumWritten);
         end;
      until (NumRead = 0) or (NumWritten <> NumRead);
      if Buf[NumWritten] <> #10 then WriteEOD;
      if WEOF then WriteEOF;
      System.CloseFile(FromF);
      System.CloseFile(ToF);
      FileMode := FM;
   end;
end;

procedure CutFileMiddle(AFileIn, AFileOut: string; ABegin, ACount: Longint; WEOF: Boolean);
var
   FromF: file;
   ToF  : file;
   NumRead, NumWritten, Num1: Integer;
   Buf: array[1..2048] of Char;
   FM : Byte;

   procedure WriteEOF;
   begin
      Buf[1] := #26;
      BlockWrite(ToF, Buf, 1, NumWritten);
   end;

begin
   if AFileIn <> AFileOut then begin
      FM := FileMode;
      AssignFile(FromF, AFileIn);
      FileMode := 0;  { Set file access to read only }
      Reset(FromF, 1);
      Seek(FromF, ABegin);
      AssignFile(ToF, AFileOut);
      FileMode := 1;  { Set file access to write only }
      Rewrite(ToF, 1);
      Num1 := ACount;
      repeat
         BlockRead(FromF, Buf, SizeOf(Buf), NumRead);
         if SizeOf(Buf) > Num1 then begin
            BlockWrite(ToF, Buf, Num1, NumWritten);
            if WEOF then WriteEOF;
            System.CloseFile(FromF);
            System.CloseFile(ToF);
            FileMode := FM;
            Exit;
            end
         else begin
            BlockWrite(ToF, Buf, NumRead, NumWritten);
            Dec(Num1, NumRead);
         end;
      until (NumRead = 0) or (NumWritten <> NumRead);
      if WEOF then WriteEOF;
      System.CloseFile(FromF);
      System.CloseFile(ToF);
      FileMode := FM;
   end;
end;

procedure MoveFile(APathIn, APathOut, AFileName: string);
Var
   F1: file;
   FM : Byte;
   s: string;
begin
   if FileExists (DelSlash(APathIn)+'\'+AFileName) then begin
      FM := FileMode;
      AssignFile(F1, DelSlash(APathIn)+'\'+AFileName);
      FileMode := 0;  { Set file access to read only }
      Reset(F1, 1);
      if FileSize(F1) <> 0 then begin
         System.CloseFile(F1);
         CopyFile(APathIn, APathOut, AFileName);
         end
      else
         System.CloseFile(F1);
      FileMode := FM;
      S := DelSlash(APathIn)+'\'+AFileName;
      SysUtils.DeleteFile (s);
   end;
end;

procedure ErrorMessageBox(ErrorText : String);
{ DialogBox с сообщением ErrorText и кнопкой OK }
begin
  MessageDlg(ErrorText, mtError, [mbOK], 0);
end; { ErrorMessageBox }

function MessageBox(Text, Caption : String; Flags : Word) : Integer;
{ Аналог стандартного MessageBox без Pchar }
var
  PText, PCaption : PChar;
begin
  GetMem(PText, Length(Text)+1); GetMem(PCaption, Length(Caption)+1);
  StrPCopy(PText, Text); StrPCopy(PCaption, Caption);
  Result := Application.MessageBox(PText, PCaption, Flags);
  FreeMem(PText, Length(Text)+1); FreeMem(PCaption, Length(Caption)+1);
end; { MessagesBox }

function InformixDateTime(DateTime : TDateTime) : String;
{ Правильная дата для Informix }
begin
(*
  case ServerType of
    Informix  : Result := FormatDateTime('yyyy-mm-dd hh:mm:ss', DateTime);
    Oracle    : Result := FormatDateTime('yyyy-mm-dd hh:mm:ss', DateTime);
    Interbase : Result := FormatDateTime('dd-mmm-yyyy hh:mm:ss', DateTime);
  else
    Result := DateTimeToStr(DateTime);
  end; { case }
  *)
end; { InformixDateTime }

function ODBCString(const AStr : string) : String;
{ Правильная string для ODBC }
begin
   if AStr = '' then Result := '' else Result := AStr;
end;

function SystemOnLine(DatabaseName : TFileName; SystemCode : Integer; UserID : Integer; var SystemDate : TDateTime) : Integer;
var
  Q : TQuery;
  rc : Longint;
begin
  SystemOnLine := stNotFound;
  if SystemCode = 0 then
  begin
    SystemOnLine := stOnLine;
    Exit;
  end;
  Q := TQuery.Create(nil);
  Q.DataBaseName := DatabaseName;
  Q.SQL.Add('SELECT * from ' + SystemTableName);
  Q.SQL.Add('Where (SystemCode=:SystemCode)and(UserID=:UserID)');
  Q.ParamByName('SystemCode').AsInteger := SystemCode;
  Q.ParamByName('UserID').AsInteger := UserID;
  try
    Q.Open;
  except
    Q.Free;
    Exit;
  end;
  rc := Q.RecordCount;
  if rc = 0 then
    Result := stNotFound
  else begin
    Result := Q.FieldByName('OnLine_').AsInteger;
    SystemDate := Q.FieldByName('DATEOPEN').AsDateTime;
  end;
  Q.Free;
end; { SystemOnLine }

procedure SetOnLine(DatabaseName : TFileName; System : Integer; UserID : Integer; TurnOn : Boolean);
var
  Q : TQuery;
  rc : Longint;
begin
  Q := TQuery.Create(nil);
  Q.DatabaseName := DataBaseName;
  Q.SQL.Add('Select * from ' + SystemTableName);
  Q.SQL.Add('Where (SystemCode=:System)and(UserID=:UserID)');
  Q.ParamByName('System').AsInteger := System;
  Q.ParamByName('UserID').AsInteger := UserID;
  try
    Q.Open;
  except
    Q.Free;                  
    Exit;
  end;
  rc := Q.RecordCount;
  Q.Close;
  Q.SQL.Clear;
  if rc > 0 then
  begin
    Q.SQL.Add('Update ' + SystemTableName);
    Q.SQL.Add('Set Online_=:OnLine_, DateOpen=:DateOpen');
    Q.SQL.Add('Where (SystemCode=:SystemCode)and(UserID=:UserID)');
  end
  else begin
    Q.SQL.Add('Insert into ' + SystemTableName);
    Q.SQL.Add('(SystemCode,UserID,OnLine_,DateOpen)');
    Q.SQL.Add('Values(:SystemCode,:UserID,:OnLine_,:DateOpen)');
  end;
  Q.ParamByName('SystemCode').AsInteger := System;
  Q.ParamByName('UserID').AsInteger := UserID;
  Q.ParamByName('DateOpen').AsDateTime := Now;
  Q.ParamByName('OnLine_').AsInteger := Ord(TurnOn);
  try
    Q.ExecSQL;
  finally
    Q.Free;
  end;
end; { SetOnLine }

function GetSystemStatus(DatabaseName : TFileName; SystemID, UserID : Integer; var SystemDate : TDateTime) : TOnLineStatus;
var
  Q : TQuery;
begin
  SystemDate := 0;
  if SystemID = 0 then { Gate }
  begin
    Result := os_OnLine;
    Exit;
  end;
  Q := TQuery.Create(nil);
  Q.DataBaseName := DatabaseName;
  Q.SQL.Add('SELECT * from ' + SystemTableName);
  Q.SQL.Add('Where (SystemCode=:SystemCode)and(UserID=:UserID)');
  Q.ParamByName('SystemCode').AsInteger := SystemID;
  Q.ParamByName('UserID').AsInteger := UserID;
  try
    Q.Open;
  except
    Result := os_NotFound;
    Q.Free;
    Exit;
  end;
  if Q.RecordCount > 0 then
  begin
    if Q.FieldByName('OnLine_').AsInteger = stOnLine then
      Result := os_OnLine
    else
      Result := os_OffLine;
    SystemDate := Q.FieldByName('DATEOPEN').AsDateTime;
  end
  else
    Result := os_NotFound;
  Q.Free;
end; { GetSystemStatus }

procedure SetSystemStatus(DatabaseName : TFileName; SystemID, UserID : Integer; TurnOn : Boolean);
var
  Q : TQuery;
  rc : Longint;
begin
  Q := TQuery.Create(nil);
  Q.DatabaseName := DataBaseName;
  Q.SQL.Add('Select * from ' + SystemTableName);
  Q.SQL.Add('Where (SystemCode=:System)and(UserID=:UserID)');
  Q.ParamByName('System').AsInteger := SystemID;
  Q.ParamByName('UserID').AsInteger := UserID;
  try
    Q.Open;
  except
    Q.Free;
    Exit;
  end;
  rc := Q.RecordCount;
  Q.Close;
  Q.SQL.Clear;
  if rc > 0 then
  begin
    Q.SQL.Add('Update ' + SystemTableName);
    Q.SQL.Add('Set Online_=:OnLine_, DateOpen=:DateOpen');
    Q.SQL.Add('Where (SystemCode=:SystemCode)and(UserID=:UserID)');
  end
  else begin
    Q.SQL.Add('Insert into ' + SystemTableName);
    Q.SQL.Add('(SystemCode,UserID,OnLine_,DateOpen)');
    Q.SQL.Add('Values(:SystemCode,:UserID,:OnLine_,:DateOpen)');
  end;
  Q.ParamByName('SystemCode').AsInteger := SystemID;
  Q.ParamByName('UserID').AsInteger := UserID;
  Q.ParamByName('DateOpen').AsDateTime := Now;
  Q.ParamByName('OnLine_').AsInteger := Ord(TurnOn);
  try
    Q.ExecSQL;
  finally
    Q.Free;
  end;
end; { SetSystemStatus }

function ODBDate : TDateTime;
var
  Q : TQuery;
  rc : longint;
  Done : Boolean;
begin
  ODBDate := 0;
  Q := TQuery.Create(nil);
  Q.DatabaseName := BufferDatabaseName;
  Q.SQL.Add('Select * from "' + EXCHANGETableName + '"');
  repeat
    Done := True;
    try
      Q.Open;
    except
      on E: EDBEngineError do
      begin
        case E.Errors[0].ErrorCode of
          DBIERR_NONE : ;
          DBIERR_FILEBUSY, DBIERR_FILELOCKED : Done := False;
        end; { case }
      end; { on }
    end;
  until Done;
  rc := Q.RecordCount;
  if rc <> 0 then
    ODBDate := Q.FieldByName('Date_odb').AsDateTime;
  Q.Free;
end; { ODBDate }

function Age(Date : TDateTime) : Longint;
{ Возраст в днях }
begin
  Result := Trunc(Now - Date);
end; { Age }

function GetDateTime(ADate: TDateTime): TDateTime;
var s : string;
begin
   S := DateToStr(ADate);
   Result := StrToDate(S) + SysUtils.Time;
end;

function LeadingZero(L : Longint; Len : Byte) : String;
begin
  Result := IntToStr(L);
  while Length(Result) < Len do Result := '0' + Result;
end; { LeadingZero }

function GetMonth(DT : TDateTime) : Integer;
var
  Year, Month, Day : Word;
begin
  DecodeDate(DT, Year, Month, Day);
  Result := Month;
end;

function MakeAccount(Mask : Longint; DT : TDateTime; MFO, MyMFO : Longint) : longint{TAccountStr};
{ Вычисление счета }
var
  xx, zz, y : Longint;
  R : Longint;
begin
  zz := (MFO div 100000) mod 100;
  if Odd(GetMonth(DT)) then xx := 1 else xx := 2;
  R := Mask + (xx * 1000000) + zz;
  y := GetProtectedKey(MyMFO, R);
  {
  Result := IntToStr(R + (y * 100));
  }
  Result := R + (y * 100);
end; { TGenerate.MakeAccount }

function CreateStringForNumber(Value:Extended):PChar;

type
 Chars20 = array[0..20] of Char;

const

 Numerical : array [0..4] of array [0..9] of Chars20 = (
  ('','один ','два ','три ','четыре ','пять ','шесть ','семь ','восемь ','девять '),
  ('','','двадцать ','тридцать ','сорок ','пятьдесят ','шестьдесят ','семьдесят ','восемьдесят ','девяносто '),
  ('','сто ','двести ','триста ','четыреста ','пятьсот ','шестьсот ','семьсот ','восемьсот ','девятьсот '),
  ('десять ','одиннадцать ','двенадцать ','тринадцать ','четырнадцать ','пятнадцать ',
  'шестнадцать ','семнадцать ','восемнадцать ','девятнадцать '),
  ('','одна ','две ','три ','четыре ','пять ','шесть ','семь ','восемь ','девять ')
 );

 Cent : array [0..2] of Chars20 = (' копейка',' копейки',' копеек');

 Dollar : array [0..3] of array [0..2] of Chars20 = (
  ('рубль ','рубля ','рублей '),
  ('тысяча ','тысячи ','тысяч '),
  ('миллион ','миллиона ','миллионов '),
  ('миллиард ','миллиарда ','миллиардов '));

function Declension(R2,R1:Integer): Integer;
begin
   result := 2;
   if R2 = 1 then Exit;
   if R1 = 1 then result := 0;
   if (R1 > 1) and (R1<5) then result := 1;
end;

function GetRankFromNumeric(FloatRec:TFloatRec;var Pointer:Integer): Integer;
var
 Pos : Integer;
begin
 result := 0;
 Pos := Pointer;
 Dec(Pointer);
 if FloatRec.Exponent - Pos < 0 then Exit;
 if StrLen(FloatRec.Digits) <= (FloatRec.Exponent - Pos) then Exit;
 result := Integer(FloatRec.Digits[FloatRec.Exponent - Pos])-$30;
end;

  var
   FloatRec : TFloatRec;
   Exp,Dv,R1,R2,R3 : Integer;
   Cents : array [0..3] of Char;
   HaveDollar : Boolean;
  type
   TCharArray = array[0..32000] of Char;
  begin
   FloatToDecimal(FloatRec,Value,fvExtended,15,2);
   result := StrAlloc(500);
   result[0] := Chr(0);
   Exp := FloatRec.Exponent;
   if (Exp > 12) or (Exp < -1) then Exit;
   HaveDollar := Exp > 0;
   Exp := 12;
   while Exp>0 do  begin
    R3 := GetRankFromNumeric(FloatRec,Exp);
    R2 := GetRankFromNumeric(FloatRec,Exp);
    R1 := GetRankFromNumeric(FloatRec,Exp);
    Dv := Exp div 3;
    StrCat(result,Numerical[2][R3]);
    if R2 <> 1 then begin
     StrCat(result,Numerical[1][R2]);
     if Dv <> 1 then StrCat(result,Numerical[0][R1])
     else            StrCat(result,Numerical[4][R1]);
    end else
    begin
     StrCat(result,Numerical[3][R1]);
    end;
    if (R3<>0) or (R2<>0) or (R1<>0) or ((Dv = 0) and HaveDollar)
     then StrCat(result,Dollar[Dv][Declension(R2,R1)]);
   end;
   StrCopy(Cents,'00');
   Exp := 0;
   R2 := GetRankFromNumeric(FloatRec,Exp);
   R1 := GetRankFromNumeric(FloatRec,Exp);
   Cents[0] := Chr(R2+$30);
   Cents[1] := Chr(R1+$30);
   StrCat(result,Cents);
   StrCat(result,Cent[Declension(R2,R1)]);

   Result[0] := UpcaseRus(Result[0]);

end;

function UpcaseRus(ACh: Char): char;
begin
   Result := Chr(Ord(ACh)-32);
end;

procedure FormatString(const Value: string; Len: Integer;
                       var Buf: array of string);
var
   i,k,m,LenP: Integer;
begin
   { Clear }
   for i:=Low(Buf) to High(Buf) do Buf[i] := '';
   k := 1;
   i := Low(Buf);
   LenP := Length(Value);
   {}
   if LenP-k > Len then
      m := Len
   else
      m := LenP-k;
   while (k < LenP) do begin
      if m < Len then begin
         { остаток }
         Buf[i] := Copy(Value, k, m+1);
         Inc(k,m+1);
         end
      else begin
         while (not (Value[k+m] in [
            ' ','!','"','&','(',')','*','+',',','-','.','/',
            ':',';','<','=','>','?','[','\',']','_'
         ])) and (m > 0) do Dec(m);
         if (m > 0) then begin
            { нашли }
            Buf[i] := Copy(Value, k, m+1);
            Inc(k,m+1);
            end
         else begin
            Buf[i] := Copy(Value, k, Len);
            Inc(k,Len);
         end;
      end;
      Buf[i] := Pad(Buf[i], Len);
      Inc(i);
      {}
      if LenP-k > Len then
         m := Len
      else
         m := LenP-k;
   end;
end;

procedure FormatStringP(const Value: PChar; Len: Integer;
                       var Buf: array of string);
var
   i,k,m,LenP: Integer;
   b : char;
   s : string;
begin
   { Clear }
   for i:=Low(Buf) to High(Buf) do Buf[i] := '';
   k := 0;
   i := Low(Buf);
   LenP := StrLen(Value);
   if LenP-k > Len then
      m := Len
   else
      m := LenP-k;
   while (k < LenP-1) do begin
      if m < Len then begin
         { остаток }
         SetLength(S,m);
         Move(Value[k], S[1], m);
         {S[0] := Chr(m);}
         Buf[i] := S;
         Inc(k,m);
         end
      else begin
         b := Value[k+m];
         while (not (b in [
            ' ','!','"','&','(',')','*','+',',','-','.','/',
            ':',';','<','=','>','?','[','\',']','_'])) and (m > 0) do begin
            Dec(m);
            b := Value[k+m];
         end;
         if (m > 0) then begin
            { нашли }
            SetLength(S,m+1);
            Move(Value[k], S[1], m+1);
            {S[0] := Chr(m+1);}
            Buf[i] := S;
            Inc(k,m+1);
            end
         else begin
            { не нашли }
            SetLength(S,Len);
            Move(Value[k], S[1], Len);
            {S[0] := Chr(Len);}
            Buf[i] := S;
            Inc(k,Len);
         end;
      end;
      Buf[i] := Pad(Buf[i], Len);
      Inc(i);
      if LenP-k > Len then
         m := Len
      else
         m := LenP-k;
   end;
end;

function GetNetUserName: string;
var
   NetConf : SysConfig;
   NetName : DBIUSERName;
begin
  DbiGetSysConfig(NetConf);
  NetName := NetConf.szUserName;
  Result := StrPas(NetName);
end;

function GetFileNameTemp: string;
var
   h,m,s,ms: word;
begin
   Delay(1000);
   DecodeTime(SysUtils.Time, h,m,s,ms);
   Result := Copy(HexW(h),3,2)+Copy(HexW(m),3,2)+Copy(HexW(s),3,2)+Copy(HexW(ms),3,2);
end;

function CreateDir(const APathName : string): Boolean;
begin
   Result := False;
   if DirectoryExists(APathName) then Result := True
   else begin
      try
         ForceDirectories(APathName);
         if DirectoryExists(APathName) then Result := True;
      except
      end;
   end;
end;

function CreateDirDate(const APathName : string; ADate: TDateTime): string;
var
   NamePathR : string;
   NamePathW : string;
   yy,mm,dd: word;
begin
   DecodeDate(ADate,yy,mm,dd);
   NamePathR := APathName;
   NamePathW := NamePathR + '\' +
                LeftPadCh(IntToStr(yy),'0',4)+'\'+
                LeftPadCh(IntToStr(mm),'0',2)+'\'+
                LeftPadCh(IntToStr(dd),'0',2);
   if CreateDir(NamePathW) then
      Result := NamePathW
   else
      Result := NamePathR;
end;

function CheckAccountBS(AAccount: Longint): Boolean;
var
   Query1: TQuery;
   A     : Integer;
begin
   Result := False;
   Query1 := TQuery.Create(nil);
   with Query1 do begin
      DatabaseName := bGMDataBaseName;
      SQL.Clear;
      SQL.Add('select * from taccount where account = :BS1 or account = :BS2');
      A := (AAccount mod 1000000) div 10000;
      ParamByName('bs1').AsInteger := A;
      A := (AAccount mod 1000000) div 1000;
      ParamByName('bs2').AsInteger := A;
      Open;
      if not EOF then begin
         Result := True;
      end;
      Close;
   end;
   Query1.Free;
end;

function GetTypeBankShort(ATypeBank: Integer): string;
var
   Query1: TQuery;
begin
   Result := '';
   Query1 := TQuery.Create(nil);
   with Query1 do begin
      Close;
      DatabaseName := bGMDataBaseName;
      SQL.Clear;
      SQL.Add('select * from tbanktypes where banktype = :typebank');
      ParamByName('typebank').AsInteger := ATypeBank;
      Open;
      if not EOF then begin
         Result := Query1.FieldByName('shortname').AsString;
      end;
      Close;
   end;
   Query1.Free;
end;

function GetCityTypeName(ACityType: Integer): string;
var
   Q : TQuery;
begin
   Result := '';
   Q := TQuery.Create(nil);
   Q.DatabaseName := bGMDataBaseName;
   Q.Close;
   Q.SQL.Clear;
   Q.SQL.Add('select * from '+tCityTypesName);
   Q.SQL.Add('where citytype=:citytype ');
   Q.ParamByName('citytype').AsInteger := ACityType;
   Q.Open;
   if not Q.EOF then begin
      Result := Q.FieldByName('nametype').AsString;
   end;
   Q.Close;
   Q.Free;
end;

procedure SetLockMode(AWait: Boolean);
var
   Q : TQuery;
begin
   Q := TQuery.Create(nil);
   Q.DatabaseName := bGMDataBaseName;
   Q.Close;
   Q.SQL.Clear;
   if AWait then
      Q.SQL.Add('set lock mode to wait')
   else
      Q.SQL.Add('set lock mode to not wait');
   Q.ExecSQL;
   Q.Free;
end;

procedure LockTable(ATableName: string; AMode: Boolean);
var
   Q : TQuery;
begin
   Q := TQuery.Create(nil);
   Q.DatabaseName := bGMDataBaseName;
   Q.Close;
   Q.SQL.Clear;
   if AMode then
      Q.SQL.Add('lock table '+ATableName+' in exclusive mode')
   else
      Q.SQL.Add('lock table '+ATableName+' in share mode');
   Q.ExecSQL;
   Q.Free;
end;

procedure NullString(var AString);
var
   i,j : Integer;
begin
   j := Length(String(AString));
   for i:=0 to j+1 do String(AString)[j] := #0;
end;

function NumberFiles(const APath,AShablon : string): Integer;
var
   DosEr      : Integer;
   SearchRec  : TSearchRec;
   F          : File;
   Done       : Boolean;
begin
   Result := 0;
   DosEr := FindFirst(APath+'\'+AShablon, faArchive, SearchRec);
   while (DosEr = 0) do begin
      AssignFile(F, APath+'\'+SearchRec.Name);
      repeat
         try
            Reset(F,1);
            Done := True;
         except
            Done := False;
         end;
      until (Done);
      if FileSize(F) > 0 then Inc(Result);
      CloseFile(F);
      DosEr := FindNext(SearchRec);
   end;
   SysUtils.FindClose(SearchRec);
end;

procedure LoadNameFiles(const APath,AShablon : string; var AList: TStringList);
var
   DosEr      : Integer;
   SearchRec  : TSearchRec;
   F          : File;
   Done       : Boolean;
   FM         : Byte;
begin
   DosEr := FindFirst(APath+'\'+AShablon, faArchive, SearchRec);
   while (DosEr = 0) do begin
      FM := FileMode;   { Save FileMode }
      AssignFile(F, APath+'\'+SearchRec.Name);
      FileMode := $42;  { Set file access to read only }
      repeat
         try
            Reset(F,1);
            FileMode := FM; { Restore FileMode }
            Done := True;
         except
            Done := False;
         end;
      until (Done);
      if FileSize(F) > 0 then AList.Add(SearchRec.Name);
      CloseFile(F);
      DosEr := FindNext(SearchRec);
   end;
   SysUtils.FindClose(SearchRec);
end;

function getKey(a: integer): longint;
begin
   Result := Random(60000);
end;

begin
  Randomize;
  DecimalSeparator := '.';
end.

