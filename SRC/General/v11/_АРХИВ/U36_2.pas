(*
$Log:   N:/Project4/Archives/UtilComp/U36.PAS.v  $
 * 
 *    Rev 1.0   02 Feb 2000 16:49:24   ugeen
 *  
 * 
 *    Rev 1.1   Sep 24 1998 20:39:58   UGEEN
 *  
*)
unit U36;

interface

{ Copyright (C) 1988,93 Koshelev's Computer Club }

function Str36toDec(S : String) : Longint;

function DecTo36(L : Longint; Len : Byte) : String;

function DecToHex(L : Longint; Len : Byte) : String;

function DecStrTo36(L : String; Len : Byte) : String;

implementation

uses
  SysUtils;

const
  SI = 36;
  Array36 : array[0..35] of char =
    ('0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
     'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
     'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
     'U', 'V', 'W', 'X', 'Y', 'Z');

function Power(N : Longint; E : Byte) : Longint;
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

function Str36toDec(S : String) : Longint;
var
  L : Integer;
  I : Integer;
  Res : Longint;
  A : Byte;
begin
  L := Length(S);
  Res := 0;
  for I := L downto 1 do
  begin
    A := ASCII2Dec(S[L-I+1]);
    Res := Res + A * Power(SI, I-1);
  end;
  Str36toDec := Res;
end; { Str36toDec }

function DecTo36Low(L : Longint) : String;
{ Сформировать строку в 36-ом виде из L }
var
  DivRes, ModRes : Longint;
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

function DecStrTo36Low(L : String) : String;
{ Сформировать строку в 36-ом виде из L }
var
  DivRes, ModRes : Longint;
  Value, ModD, DivD : Double;
begin
  Result := '';
  try
    Value := StrToFloat(L);
  except
    Exit;
  end;
  DivRes := Trunc(Value/SI);
  DivD := DivRes;
  ModRes := Trunc(Value - (DivD * SI));
  if DivRes >= SI then
    Result := DecStrTo36Low(IntToStr(DivRes)) + Array36[ModRes]
  else
    if DivRes > 0 then
      Result := Array36[DivRes] + Array36[ModRes]
    else
      Result := Array36[ModRes];
end; { DecTo36Low }

function DecTo36(L : Longint; Len : Byte) : String;
{ Сформировать строку в 36-ом виде из L }
var
  S : String;
begin
  S := DecTo36Low(L);
  while Length(S) < Len do S := '0' + S;
  DecTo36 := S;
end; { DecTo36 }

function DecStrTo36(L : String; Len : Byte) : String;
var
  S : String;
begin
  S := DecStrTo36Low(L);
  while Length(S) < Len do S := '0' + S;
  Result := S;
end;

function DecToHex(L : Longint; Len : Byte) : String;
const
  HexArr : array[0..$F] of Char =
    ('0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
     'a', 'b', 'c', 'd', 'e', 'f');
var
  Res : String;
  I : Byte;
  LL : Longint;
begin
  LL := L;
  Res := HexArr[LL and $F];
  for I := 1 to 7 do
  begin
    LL := LL shr 4;
    Res := HexArr[LL and $F] + Res;
  end;
  while (Length(Res) > 0) and (Res[1] = '0') do Delete(Res, 1, 1);
  while Length(Res) < Len do Res := '0' + Res;
  DecToHex := Res;
end; { DecToHex }

end.
