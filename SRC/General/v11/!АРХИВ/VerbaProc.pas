{=======================================================}
(* Samples

   { CheckSign }
   if not CheckSignFile(LFileName, FBIKFrom, False) then begin
      FInfoOperation := FInfoOperation+' '+GetErrorSign(FBIKFrom);
      end
   else begin
      FInfoOperation := FInfoOperation+' Ok.';
   end;

   { RemoveSign }
   if not CheckSignFile(LFileName, FBIKFrom, True) then begin
      FInfoOperation := FInfoOperation+' '+GetErrorSign(FBIKFrom);
      end
   else begin
      FInfoOperation := FInfoOperation+' Ok.';
   end;

   { SetSign }
   if not SetSignFile(LFileName, FBIKTo) then begin
      FInfoOperation := FInfoOperation+' '+GetErrorSign(FBIKTo);
      end
   else begin
      FInfoOperation := FInfoOperation+LFileName+' Ok.';
   end;

   { Crypt }
   if not CryptFile(LFileName, FBIKFrom, FBIKTo) then begin
      FInfoOperation := FInfoOperation+' '+GetErrorCrypt(FBIKTo);
      end
   else begin
      FInfoOperation := FInfoOperation+' Ok.';
   end;

   { DECrypt }
   if not DeCryptFile(LFileName, FBIKFrom, FBIKTo) then begin
      FInfoOperation := FInfoOperation+' '+GetErrorCrypt(FBIKFrom);
      end
   else begin
      FInfoOperation := FInfoOperation+' Ok.';
   end;

*)
{=======================================================}
unit VerbaProc;

interface

uses
   Sysutils, LUVerba, Sign, LUSupport;

function CheckSignFile(const FileName,BIK: string; AppSign: Integer; DeleteSign: Boolean): Boolean;
function SetSignFile(const FileName,BIK: string;  AppSign: Integer): Boolean;
function DeCryptFile(const FileName, BIKFrom, BIKTo: string;
   AbonentTos: string): Boolean;
function CryptFile(const FileName, BIKFrom, BIKTo: string;
   AbonentFroms,AbonentToList,Series: string): Boolean;
function GetBIK_FROMPublicBaseSign(const ABIK: string; AppSign: Integer): string;
function GetBIK_FROMPrivateKeySign(const ABIK: string; AppSign: Integer): string;
function GetErrorSign(const ABIK: string; AppSign: Integer): string;
function GetErrorCrypt(const ABIK: string): string;

implementation

var
   FTulaSign: TSign;
   FVerbaSign: TVerbaSign;
   FInfoOperation: string;
const
   PublicBaseTulaSign: string = 'G:\keys\elo';
   PrivateKeyTula: string = 'C:\KEYS\TulaSign';

   PublicBaseVerbaSign: string = 'G:\KEYS\VERBA';
   PrivateKeyVerba: string = 'a:\';

   PrivateKeyVerbaCrypt: string = 'a:\';
   PublicBaseVerbaCrypt: string = 'G:\KEYS\VERBA';

   VerbaSeries: string = '940073';

{ GetBIK_FROMPublicBaseSign }

function GetBIK_FROMPublicBaseSign(const ABIK: string; AppSign: Integer): string;
begin
   case AppSign of
      1: Result := IncludeTrailingBackslash(PublicBaseTulaSign)+Copy(ABIK,6,3)+'.dat';
      2: Result := PublicBaseVerbaSign;
   else
      Result := '';
   end;
end;

{ GetBIK_FROMPrivateKeySign }

function GetBIK_FROMPrivateKeySign(const ABIK: string; AppSign: Integer): string;
begin
   case AppSign of
      1: Result := IncludeTrailingBackslash(PrivateKeyTula)+'sign.key';
      2: Result := PrivateKeyVerba;
   else
      Result := '';
   end;
end;

{ CheckSignFile }

function CheckSignFile(const FileName,BIK: string; AppSign: Integer; DeleteSign: Boolean): Boolean;
var
   LPublicBase: string;
   LPrivateKey: string;
begin
   try
      LPublicBase := GetBIK_FROMPublicBaseSign(BIK, APPSign);
      LPrivateKey := GetBIK_FROMPrivateKeySign(BIK, APPSign);
      case AppSign of
         1: begin
            Result := CheckTulaSignFile(FTulaSign, FileName, LPublicBase, DeleteSign);
            if Result then
               FInfoOperation := FTulaSign.SignID;
         end;
         2: begin
            Result := CheckVerbaSignFile(FVerbaSign, FileName, LPrivateKey, LPublicBase, DeleteSign);
            if Result then
               FInfoOperation := FVerbaSign.SignID+' '+FVerbaSign.SignAlias
            else
               FInfoOperation := 'CheckVerbaSignFile: '+FVerbaSign.VerbaErrorString;
         end;
      end;
   except
      FInfoOperation := 'Не опредена ЭЦП для '+BIK;
      Result := False;
   end;
end;

{ SetSignFile }

function SetSignFile(const FileName,BIK: string;  AppSign: Integer): Boolean;
var
   LPublicBase: string;
   LPrivateKey: string;
begin
   try
      LPublicBase := GetBIK_FROMPublicBaseSign(BIK,AppSign);
      LPrivateKey := GetBIK_FROMPrivateKeySign(BIK,AppSign);
      case AppSign of
         1: begin
            Result := SetTulaSignFile(FTulaSign, FileName, LPrivateKey);
            if Result then
               FInfoOperation := '';
         end;
         2: begin
            Result := SetVerbaSignFile(FVerbaSign, FileName, LPrivateKey, LPublicBase);
            if Result then
               FInfoOperation := ''
            else
               FInfoOperation := 'SetVerbaSignFile: '+FVerbaSign.VerbaErrorString;
         end;
      end;
   except
      FInfoOperation := 'Не опредена ЭЦП для '+BIK;
      Result := False;
   end;
end;

{ DeCryptFile }

function DeCryptFile(const FileName,BIKFrom,BIKTo: string;
   AbonentTos: string): Boolean;
var
   LAbonentTo: Word;
   LAbonentTos: string;
   LPrivateKey: string;
   LPublicBase: string;
   i: Integer;
begin
   LPrivateKey := PrivateKeyVerbaCrypt;
   LPublicBase := PublicBaseVerbaCrypt;
   FInfoOperation := '';
   try
      LAbonentTo := StrToInt(AbonentTos);
      FInfoOperation := 'To: '+AbonentTos;
   except
      LAbonentTo := 0;
   end;
   VerbaInfoCryptFile(FVerbaSign, FileName, LPrivateKey, LPublicBase);
   FInfoOperation := FInfoOperation+' '+FVerbaSign.Series+' '+FVerbaSign.AbonentSender;
   for i:=0 to FVerbaSign.AbonentsList.Count-1 do
      FInfoOperation := FInfoOperation+' '+FVerbaSign.AbonentsList[i];
   Result := VerbaDeCryptFile(FVerbaSign, FileName, LPrivateKey, LPublicBase, LAbonentTo);
   if Result then
      FInfoOperation := FInfoOperation + ' '
   else
      FInfoOperation := FInfoOperation+' '+'VerbaDeCryptFile: '+FVerbaSign.VerbaErrorString;
end;

{ CryptFile }

function CryptFile(const FileName,BIKFrom,BIKTo: string;
   AbonentFroms,AbonentToList,Series: string): Boolean;
var
   LAbonentFrom: Word;
   LAbonentTo: array of Word;
   LAbonentToOne: string;
   s: string;
   i,j,k: Integer;
   LPrivateKey: string;
   LPublicBase: string;
begin
   LPrivateKey := PrivateKeyVerbaCrypt;
   LPublicBase := PublicBaseVerbaCrypt;
   SetLength(LAbonentTo,WordCountNew(AbonentToList,[','])+1);
   j := 0;
   s := '';
   for i:=1 to WordCountNew(AbonentToList,[',']) do begin
      try
         LAbonentToOne := ExtractWordNew(i,AbonentToList,[',']);
         k := StrToInt(LAbonentToOne);
         LAbonentTo[j] := k;
         Inc(j);
         s := s+LAbonentToOne+' ';
      except
      end;
   end;
   LAbonentTo[j] := 0;
   try
      LAbonentFrom := StrToInt(AbonentFroms);
   except
      LAbonentFrom := 0;
   end;
   FInfoOperation := 'From: '+AbonentFroms+' To: '+s;
   Result := VerbaCryptFile(FVerbaSign, FileName, LPrivateKey, LPublicBase, LAbonentFrom, LAbonentTo, Series);
   LAbonentTo := nil;
   if Result then
      FInfoOperation := ''
   else
      FInfoOperation := 'VerbaCryptFile: '+FVerbaSign.VerbaErrorString;
end;

{ GetErrorSign }

function GetErrorSign(const ABIK: string; AppSign: Integer): string;
begin
   case AppSign of
      1: begin
         if FTulaSign.OS_Error   > 0 then Result := OsErrors[FTulaSign.OS_Error];
         if FTulaSign.Sign_Error > 0 then Result := SignErrors[FTulaSign.Sign_Error];
      end;
      2: begin
         Result := FVerbaSign.VerbaErrorString;
      end;
   else
      Result := '';
   end;
end;

{ GetErrorCrypt }

function GetErrorCrypt(const ABIK: string): string;
begin
   Result := FVerbaSign.VerbaErrorString;
end;

initialization
   FVerbaSign := TVerbaSign.Create(nil);
   FTulaSign := TSign.Create(nil);

finalization
   FVerbaSign.Free;
   FTulaSign.Free;

end.










