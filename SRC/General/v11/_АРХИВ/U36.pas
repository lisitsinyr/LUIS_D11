unit U36;
{ ќперации в 36-тиричном исчислении }

interface

uses
  SysUtils;

function Str36toDec(S : String) : Int64;
{ ѕреобразование из 36-тиричного представлени€ в дес€тичное число }

function DecTo36(L : Int64; Len : Byte) : String;
{ ѕреобразование из дес€тичного в 36-тиричное }

function MakeName(Number : Integer) : String;
{ —оздание имени HELIO-пакета (EL-файл) с 36-тиричным именем }

implementation

const
  SI = 36;
  Array36 : array[0..35] of char =
    ('0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
     'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
     'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
     'U', 'V', 'W', 'X', 'Y', 'Z');

function Power(N : Int64; E : Byte) : Int64;
begin
   if E = 0 then Power := 1
   else if E = 1 then Power := N
   else Power := N * Power(N, E - 1);
end; { Power }

function ASCII2Dec(Ch :  Char) : Byte;
begin
   if Ch in ['0'..'9'] then ASCII2Dec := Ord(Ch) - 48
   else ASCII2Dec := Ord(Ch) - 55;
end; { ASCII2Dec }

function Str36toDec(S : String) : Int64;
var
   L : Integer;
   I : Integer;
   Res : Int64;
   A : Byte;
begin
   S := UpperCase(S);
   L := Length(S);
   Res := 0;
   for I := L downto 1 do begin
      A := ASCII2Dec(S[L-I+1]);
      Res := Res + A * Power(SI, I-1);
   end;
   Str36toDec := Res;
end; { Str36toDec }

function DecTo36Low(L : Int64) : String;
var
   DivRes, ModRes : Int64;
begin
   DivRes := L div SI;
   ModRes := L mod SI;
   if DivRes >= SI then
      DecTo36Low := DecTo36Low(DivRes) + Array36[ModRes]
   else
   if DivRes > 0 then
      DecTo36Low := Array36[DivRes] + Array36[ModRes]
   else
      DecTo36Low := Array36[ModRes];
end; { DecTo36Low }

function DecTo36(L : Int64; Len : Byte) : String;
var
   S : String;
begin
   S := DecTo36Low(L);
   while Length(S) < Len do S := '0' + S;
   DecTo36 := S;
end; { DecTo36 }

function TimeTo36(DateTime : TDateTime) : string;
var
   Year, Month, Day, Hour, Min, Sec, MSec : Word;
   ltm  :Int64;
begin
   DecodeDate(DateTime, Year, Month, Day);
   DecodeTime(DateTime, Hour, Min, Sec, MSec);
   ltm := MSec div 20 +
          Sec * 50 +
          Min * 50 * 60 +
          Hour * 50 * 60 * 60 +
          Day  * 50 * 60 * 60 * 24 +
          Month * 50 * 60 * 60 * 24 * 32;
   Result := DecTo36(Ltm, 6);
end; { TimeTo36 }

function MakeName(Number : Integer) : String;
begin
   Result := 'EL' + TimeTo36(Now) + '.P' + DecTo36(Number mod 1000, 2);
end; { MakeName }

end.
