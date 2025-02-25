unit Radix64;

interface

uses SysUtils;

{$H+}

const
   ArmorTable : array [0..63] of char = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/';

var deArmorTable: array [0..255] of ShortInt;

procedure FillDeArmorTable;
function ArmorBinary(in_buffer:Pointer; Len : Cardinal):string;
function DeArmorText(in_str:string;Out_Buf:Pointer):Cardinal;
function DeArmorBufferLen(In_str:string):Cardinal;

implementation

procedure FillDeArmorTable;
var i:byte;
begin
   FillChar(deArmorTable,SizeOf(deArmorTable),-1);
   for i:=Low(ArmorTable) to High(ArmorTable) do deArmorTable[Ord(ArmorTable[i])]:=i;
end;

function ArmorBinary(in_buffer:Pointer; Len : Cardinal):string;
var
   i:integer;
   pch:PChar;
begin
   Result:='';
   pch:=PChar(in_buffer);
   for i:=0 to Len div 3 - 1 do begin
      Result:=Result+ArmorTable[ord((pch+3*i  )^) shr 2 and $3F];
      Result:=Result+ArmorTable[ord((pch+3*i  )^) shl 4 and $30 +
                                ord((pch+3*i+1)^) shr 4 and $0F];
      Result:=Result+ArmorTable[ord((pch+3*i+1)^) shl 2 and $3C +
                                ord((pch+3*i+2)^) shr 6 and $03];
      Result:=Result+ArmorTable[ord((pch+3*i+2)^)       and $3F];
   end;
   case Len mod 3 of
      1: begin
         Result:=Result+ArmorTable[ord((pch+Len-1)^) shr 2 and $3F];
         Result:=Result+ArmorTable[ord((pch+Len-1)^) shl 4 and $30];
      end;
      2: begin
         Result:=Result+ArmorTable[ord((pch+Len-2)^) shr 2 and $3F];
         Result:=Result+ArmorTable[ord((pch+Len-2)^) shl 4 and $30 +
                                   ord((pch+Len-1)^) shr 4 and $0F];
         Result:=Result+ArmorTable[ord((pch+Len-1)^) shl 2 and $3C];
      end;
   end; {case}
end;

function DeArmorText(in_str:string;Out_Buf:Pointer):Cardinal;
var
   i,j:integer;
   pch:PChar;
begin
   j:=0;
   pch:=PChar(Out_Buf);
   for i:=0 to Length(in_str) div 4 - 1 do begin
      (pch+j)^ := Chr(DeArmorTable[ord(in_str[4*i+1])] shl 2 and $FC +
                  DeArmorTable[ord(in_str[4*i+2])] shr 4 and $03 );
      inc(j);
      (pch+j)^ := Chr(DeArmorTable[ord(in_str[4*i+2])] shl 4 and $F0 +
                  DeArmorTable[ord(in_str[4*i+3])] shr 2 and $0F );
      inc(j);
      (pch+j)^ := Chr(DeArmorTable[ord(in_str[4*i+3])] shl 6 and $C0 +
                  DeArmorTable[ord(in_str[4*i+4])]               );
      inc(j);
   end;
   case Length(in_str) mod 4 of
      2: begin
         (pch+j)^ := Chr(DeArmorTable[ord(in_str[Length(in_str)-1])] shl 2 and $FC +
                     DeArmorTable[ord(in_str[Length(in_str)  ])] shr 4 and $03 );
         inc(j);
      end;
      3: begin
         (pch+j)^ := Chr(DeArmorTable[ord(in_str[Length(in_str)-2])] shl 2 and $FC +
                     DeArmorTable[ord(in_str[Length(in_str)-1])] shr 4 and $03 );
         inc(j);
         (pch+j)^ := Chr(DeArmorTable[ord(in_str[Length(in_str)-1])] shl 4 and $F0 +
                     DeArmorTable[ord(in_str[Length(in_str)  ])] shr 2 and $0F );
         inc(j);
      end;
   end; {case}
   Result:=j;
end;

function DeArmorBufferLen(In_str:string):Cardinal;
begin
   Result:=(Length(in_str) div 4)*3 + Length(in_str) mod 4 - ord(Length(in_str) mod 4 > 0);
end;

initialization
   FillDeArmorTable;
end.
