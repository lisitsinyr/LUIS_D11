program DecTo36Convert;

uses
  SysUtils, U36;

var
  Num : Double;
  NumStr : String;
  Code : Longint;
begin
  if ParamCount < 1 then
  begin
    Writeln('Using: ' + ExtractFileName(ParamStr(0)), ' <Decimal value>');
    Halt(1);
  end;
  NumStr := ParamStr(1);
  Val(NumStr, Num, Code);
  if Code <> 0 then
  begin
    Writeln('Invalid number: ', NumStr);
    Halt(1);
  end;
  Writeln('Decimal number = ', NumStr, ' 36-number = ', DecStrTo36(NumStr, 1));
end.

