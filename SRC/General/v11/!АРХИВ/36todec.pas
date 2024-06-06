program S36ToDecConvert;

uses
  SysUtils, U36;

var
  Num : Longint;
  NumStr : String;
  Code : Integer;
  Ch : Char;
begin
  if ParamCount < 1 then
  begin
    Writeln('Using: ' + ExtractFileName(ParamStr(0)), ' <36-th value>');
    Halt(1);
  end;
  NumStr := ParamStr(1);
  Writeln('36-number = ', NumStr, ' Decimal number = ', Str36toDec(UpperCase(NumStr)));
end.
