unit Sign;

interface

uses
  Classes, SysUtils, Radix64,
  {}
  CnvUtils;

type
  Chars = array[0..255] of char;

const
  randomName = 'random.bin';
  se_BadInit = 1;
  se_BadSign = 2;
  se_NoReg = 3;
  se_NoSign = 4;
  se_PrivateKeyMissing = 5;
  se_PrivateKeyError = 6;
  se_DeleteSignError = 7;

  oe_FileMissing = 1;
  oe_PublicBaseMissign = 2;
  oe_UnableToLockFile = 3;

  SignErrors : array[0..7] of String[50] =
    ('',
     'SIGN: Нет датчика случайных чисел',
     'SIGN: ЭЦП ложная',
     'SIGN: ЭЦП не зарегистрирована',
     'SIGN: ЭЦП отсутствует',
     'SIGN: Нет файла с секретным ключом',
     'SIGN: Ошибка в файле с секретным ключом',
     'SIGN: Ошибка удаления ЭЦП');

  OsErrors : array[0..3] of String[50] =
    ('',
     'SIGN: Файл для подписи/проверки не найден',
     'SIGN: Файл с базой открытых ключей не найден',
     'SIGN: Невозможно заблокировать файл');

  { Подпись

  cPrivateDirectory        = 'A:\';
  cPrivateKey              = cPrivateDirectory + 'SIGN.KEY';
  cPublicBase              = cPrivateDirectory + 'PUBL.KEY';
  cRandomFile              = cPrivateDirectory + 'RANDOM.BIN';

  }

type

  { TSign }

  TSignErrorEvent = procedure(Sender : TObject; FileName : TFileName; OS_Error, Sign_Error : Integer) of object;
  TOnInsertDiskEvent = procedure(Sender : TObject; var Continue : Boolean) of object;

  TSign = class(TComponent)
  private
    { Private declarations }
    FOnError : TSignErrorEvent;
    FOnInsertDisk : TOnInsertDiskEvent;
    FPublicBase : TFileName;
    FPrivateKey : TFileName;
    FRandomFile : TFileName;
    FFileName : TFileName;
    FDeleteSign : Boolean;
    FConfirmDisk : Boolean;
    FSignID : String;
    FStrSign : Pointer;
    FRadixSign : String;
    FStrSignLen : Integer;
    FOS_Error : Integer;
    FSign_Error : Integer;
    FantomPrivateKey : TFileName;
    FantomStarted : Boolean;
    FantomStream : TFileStream;
    FCacheStream : TMemoryStream;
    FCachePath  : TFileName;
    function Init : Boolean;
    function InitString: Boolean;
    function GetPrivateKey : TFileName;
    procedure LockFantom;
    procedure UnlockFantom;
    procedure WipeFantom;
    procedure DoError(AFileName : TFileName);
    function DoInsertDisk : Boolean;
    function CopyFile(Source, Dest : TFileName) : Boolean;
    function LoadFile(AFileName : TFileName) : Boolean;
  protected
    { Protected declarations }
  public
    { Public declarations }
    constructor Create(Aowner : TComponent); override;
    destructor Destroy; override;
    procedure CacheKey;
    procedure ClearCache;

    procedure StartSession;
    procedure StopSession;
    { File }
    function PutSign : Boolean;
    function CheckSign : Boolean;
    { Buffer }
    function SignBuffer(Buffer : Pointer; Count : Integer) : Boolean;
    function CheckSignBuffer(Buffer : Pointer; Count : Integer) : boolean; overload;
    function CheckSignBuffer(Buffer : Pointer; Count : Integer; Sign : Pointer; SignLen : Integer) : boolean; overload;
    function CheckSignBuffer(Buffer : Pointer; Count : Integer; Sign : String) : boolean; overload;
    { Hash }
    function HashFile : String;
    function CheckHash(Hash : String) : Boolean;

    function GetTempPath : TFileName;
    property OS_Error : Integer read FOS_Error;
    property Sign_Error : Integer read FSign_Error;
    property SignID : String read FSignID;
    property StrSign : Pointer read FStrSign;
    property RadixSign : String read FRadixSign;
    property StrSignLen : Integer read FStrSignLen;
    {}
    property PublicBase : TFileName read FPublicBase write FPublicBase;
    property PrivateKey : TFileName read FPrivateKey write FPrivateKey;
    property RandomFile : TFileName read FRandomFile write FRandomFile;
    property FileName : TFileName read FFileName write FFileName;
    property DeleteSign : Boolean read FDeleteSign write FDeleteSign;
    property ConfirmDisk : Boolean read FConfirmDisk write FConfirmDisk default True;
    property CachePath : TFileName read FCachePath write FCachePath;
    property OnError : TSignErrorEvent read FOnError write FOnError;
    property OnInsertDisk : TOnInsertDiskEvent read FOnInsertDisk write FOnInsertDisk;
  end; { TSign }

function CheckTulaSignFile(TulaSign: TSign; const AFileName, APublicBase: string; DeleteSign: Boolean): Boolean;
function SetTulaSignFile(TulaSign: TSign; const AFileName, APrivateKey: string): Boolean;

implementation

function CheckTulaSignFile(TulaSign: TSign; const AFileName, APublicBase: string; DeleteSign: Boolean): Boolean;
begin
   TulaSign.ConfirmDisk := True;
   TulaSign.PrivateKey := '';
   TulaSign.FileName := AFileName;
   TulaSign.PublicBase := APublicBase;
   TulaSign.DeleteSign := DeleteSign;
   TulaSign.StartSession;
   try
      Result := TulaSign.CheckSign;
   except
      Result := False;
   end;
   TulaSign.StopSession;
end;

function SetTulaSignFile(TulaSign: TSign; const AFileName, APrivateKey: string): Boolean;
begin
   TulaSign.ConfirmDisk := True;
   TulaSign.PrivateKey := APrivateKey;
   TulaSign.FileName := AFileName;
   TulaSign.PublicBase := '';
   TulaSign.DeleteSign := False;
   TulaSign.StartSession;
   try
      Result := TulaSign.PutSign;
   except
      Result := False;
   end;
   TulaSign.StopSession;
end;

{ External functions from TSIGN.DLL, PUT_HASH.DLL, CHK_HASH.DLL, STRSIGN.DLL }

{ SignFile functions }

function InitTSign(RandomFile : PChar) : Integer;
stdcall; external 'TSIGN.DLL' name 'InitTSIGN';

procedure DoneTSign;
external 'TSIGN.DLL' name 'DoneTSIGN';

function PutSignFile(PathName, KeyPathName : PChar; Os_Error, Sign_Error : Pointer) : Integer;
stdcall; external 'TSIGN.DLL' name 'PutSignFile';

function CheckSignFile(PathName, BasePathName, SignIdentificator : PChar; DeleteSign : Integer; Os_Error, Sign_Error : Pointer) : Integer;
stdcall; external 'TSIGN.DLL' name 'CheckSignFile';

{ Hash functions }

function InitChk_Hash : Integer;
stdcall; external 'CHK_HASH.DLL' name 'InitCHK_HASH';

function DoneChk_Hash : Integer; stdcall;
external 'CHK_HASH.DLL' name 'DoneCHK_HASH';

function MakeHashFile(PathName, Hash : PChar; Os_Error, Hash_Error : Pointer) : Integer;
stdcall; external 'PUT_HASH.DLL';

function CheckHashFile(PathName, Hash : PChar; Os_Error, Hash_Error : Pointer) : Integer;
stdcall; external 'CHK_HASH.DLL';

{ SignString functions }

function InitStrSign(RandomFile : PChar) : Integer;
stdcall; external 'STRSIGN.DLL' name 'InitStrSIGN';

function DoneStrSign : Integer;
stdcall; external 'STRSIGN.DLL' name 'DoneStrSIGN';

function PutSignString(SourceString : PChar; LenSourceString : Pointer;
                       KeyPathName, SignString : PChar; LenSignString : Pointer;
                       Os_Error, Sign_Error : Pointer) : Integer;
stdcall; external 'STRSIGN.DLL' name 'PutSignString';

function CheckSignString(SourceString : PChar; LenSourceString : Pointer;
                         BasePathName, SignIdentificator : PChar;
                         Os_Error, Sign_Error : Pointer) : Integer;
stdcall; external 'STRSIGN.DLL' name 'CheckSignString';

{ --- TSign --- }

constructor TSign.Create(AOwner : TComponent);
begin
   inherited Create(Aowner);
   ConfirmDisk := True;
end; { TSign.Create }

destructor TSign.Destroy;
begin
   StopSession;
   ClearCache;
   inherited Destroy;
end; { TSign.Destroy }

procedure TSign.DoError(AFileName : TFileName);
begin
   if Assigned(FOnError) then
      FOnError(Self, AFileName, FOS_Error, FSign_Error);
end; { TSign.DoError }

function TSign.DoInsertDisk : Boolean;
{ Истина, если пользователь хочет продолжить операцию (нажал "Повторить") }
var
   Continue : Boolean;
begin
   Continue := False;
   if ConfirmDisk and Assigned(FOnInsertDisk) then
      FOnInsertDisk(Self, Continue);
   Result := Continue;
end; { TSign.DoInsertDisk }

function TSign.Init : Boolean;
var
   Rnd : Chars;
begin
   StrPCopy(Rnd, RandomFile);
   FOS_Error := InitTSign(Rnd);
   if (FOS_Error <> 0) then DoError('');
   Result := FOS_Error = 0;
end; { TSign.Init }

function TSign.InitString : Boolean;
var
   Rnd : Chars;
begin
   StrPCopy(Rnd, RandomFile);
   FOS_Error := InitStrSign(Rnd);
   if (FOS_Error <> 0) then DoError('');
   Result := FOS_Error = 0;
end; { TSignInitString }

function TSign.PutSign : Boolean;
var
   S1, S2 : Chars;
   Res : Integer;
begin
   Result := False;
   if Init then begin
      StrPCopy(S1, FileName); StrPCopy(S2, GetPrivateKey);
      UnlockFantom;
      Res := PutSignFile(S1, S2, @FOs_Error, @FSign_Error);
      LockFantom;
      Result := Res = 0;
      if not Result then DoError(FileName);
   end; { if }
   DoneTSign;
end; { TSign.PutSign }

function TSign.CheckSign : Boolean;
var
   S1, S2, SID : Chars;
   Res, DelSign : Integer;
begin
   Result := False;
   if Init then begin
      StrPCopy(S1, FileName); StrPCopy(S2, PublicBase); FillChar(SID, SizeOf(SID), 0);
      if DeleteSign then DelSign := 1 else DelSign := 0;
      Res := CheckSignFile(S1, S2, SID, DelSign, @FOs_Error, @FSign_Error);
      Result := Res = 0;
      if Result then
         FSignID := StrPas(SID)
      else
         DoError(FileName);
   end;
   DoneTSign;
end; { TSign.CheckSign }

function TSign.SignBuffer(Buffer : Pointer; Count: Integer): Boolean;
var
   S1, S2 : Chars;
   Res, SignLen : Integer;
begin
   Result := False;
   if InitString then begin
      if FStrSign <> nil then FreeMem(FStrSign, FStrSignLen);
      StrPCopy(S1, GetPrivateKey); FillChar(S2, SizeOf(S2), 0);
      UnlockFantom;
      Res := PutSignString(PChar(Buffer), @Count, S1, S2, @SignLen, @FOS_Error, @FSign_Error);
      LockFantom;
      Result := Res = 0;
      if Result then begin
         FStrSignLen := SignLen;
         GetMem(FStrSign, FStrSignLen);
         Move(S2, FStrSign^, FStrSignLen);
         FRadixSign := ArmorBinary(FStrSign, FStrSignLen);
         end
      else
         DoError('');
   end; { if }
   DoneStrSign;
end; { TSign.SignBuffer }

function TSign.CheckSignBuffer(Buffer : Pointer; Count: Integer): Boolean;
var
   S, SID : Chars;
   Res : Integer;
begin
   Result := False;
   if InitString then begin
      StrPCopy(S, PublicBase); FillChar(SID, SizeOf(SID), 0);
      Res := CheckSignString(PChar(Buffer), @Count, S, SID, @FOs_Error, @FSign_Error);
      FSignID := StrPas(SID);
      Result := Res = 0;
      if not Result then DoError('');
   end;
   DoneStrSign;
end; { TSign.CheckSigBuffer }

function TSign.CheckSignBuffer(Buffer: Pointer; Count: Integer; Sign : String) : Boolean;
var
   Buf : Chars;
   Len : Integer;
begin
   Len := DeArmorText(Sign, @Buf);
   Result := CheckSignBuffer(Buffer, Count, @Buf, Len);
end; { TSign.CheckSignBuffer }

function TSign.CheckSignBuffer(Buffer: Pointer; Count: Integer;
  Sign: Pointer; SignLen: Integer): boolean;
type
   PArray = ^TArray;
   TArray = array[0..0] of Char;
var
   Buf : PArray;
   BufLen : Integer;
begin
   BufLen := Count + SignLen;
   GetMem(Buf, BufLen);
   Move(Buffer^, Buf^[0], Count);
   Move(Sign^, Buf^[Count], SignLen);
   Result := CheckSignBuffer(Buf, BufLen);
   FreeMem(Buf, Buflen);
end; { TSign.CheckSignBuffer }

function TSign.HashFile : String;
var
   S1, S2 : Chars;
   Res : Integer;
begin
   FillChar(S2, SizeOf(S2), 0);
   if InitChk_Hash = 0 then begin
      StrPCopy(S1, FileName);
      Res := MakeHashFile(S1, S2, @OS_Error, @Sign_Error);
      if Res <> 0 then DoError(FileName);
   end;
   Result := StrPas(S2);
   DoneChk_Hash;
end; { TSign.HashFile }

function TSign.CheckHash(Hash: String): Boolean;
var
   S1, S2 : Chars;
   Res : Integer;
begin
   Result := False;
   if InitChk_Hash = 0 then begin
      StrPCopy(S1, FileName); StrPCopy(S2, Hash);
      Res := CheckHashFile(S1, S2, @OS_Error, @Sign_Error);
      if Res <> 0 then DoError(FileName);
      Result := Res = 0;
   end; { if }
   DoneChk_Hash;
end; { TSign.CheckHash }

procedure TSign.LockFantom;
{ Схватить ключ только если произведен запуск StartSession }
begin
   if FantomStarted then begin
      if FantomStream <> nil then FantomStream.Free;
      FantomStream := TFileStream.Create(FantomPrivateKey, fmOpenRead + fmShareExclusive);
   end;
end; { TSign.LockFantom }

procedure TSign.UnlockFantom;
begin
   if FantomStream <> nil then begin
      FantomStream.Free;
      FantomStream := nil;
   end;
end; { TSign.UnlockFantom }

procedure TSign.WipeFantom;
{ Уничтожение ключа }
begin
   if not FantomStarted then Exit;
   UnlockFantom;
   WipeFiles(FantomPrivateKey);
end; { TSign.WipeFantom }

function TSign.GetPrivateKey : TFileName;
begin
   if FantomStarted then
      Result := FantomPrivateKey
   else
      Result := PrivateKey;
end; { TSign.GetPrivateKey }

function TSign.LoadFile(AFileName : TFileName) : Boolean;
begin
   Result := True;
   try
      FCacheStream.LoadFromFile(AFileName);
   except
      Result := False;
   end;
end; { TSign.LoadFile }

procedure TSign.CacheKey;
var
   Cont, Res : Boolean;
begin
   if FCacheStream <> nil then ClearCache;
   FCacheStream := TMemoryStream.Create;
   repeat
      Cont := False;
      Res := LoadFile(PrivateKey);
      if not Res then Cont := DoInsertDisk;
   until not Cont;
   if not Res then begin
      FOS_Error := oe_UnableToLockFile;
      ClearCache;
      DoError('');
   end;
end; { TSign.CacheKey }

procedure TSign.ClearCache;
begin
   if FCacheStream <> nil then begin
      FCacheStream.Free;
      FCacheStream := nil;
   end;
end; { TSign.ClearCache }

function TSign.CopyFile(Source, Dest : TFileName) : Boolean;
var
   S : TMemoryStream;
begin
   Result := True;
   S := TMemoryStream.Create;
   try
      S.LoadFromFile(Source);
      S.SaveToFile(Dest);
   except
      Result := False;
   end;
   S.Free;
end; { TSign.CopyFile }

function TSign.GetTempPath : TFileName;
begin
   if CachePath <> '' then
      Result := CachePath
   else
      Result := CnvUtils.GetTempPath;
end; { TSign.GetTempPath }

procedure TSign.StartSession;
{ Копировать приватный ключ на жесткий диск и схватить его мертво }
var
   Cont : Boolean;
begin
   FOS_Error := 0; FSign_Error := 0;
   if not FantomStarted then begin
      FantomPrivateKey := AddSlash(GetTempPath) + GenerateTempName + '.~tmp';
      if FCacheStream <> nil then begin
         FCacheStream.SaveToFile(FantomPrivateKey);
         FantomStarted := True;
         end
      else begin
         repeat
            Cont := False;
            FantomStarted := CopyFile(PrivateKey, FantomPrivateKey);
            if not FantomStarted then Cont := DoInsertDisk;
         until not Cont;
      end;
      if not FantomStarted then begin
         FOS_Error := oe_UnableToLockFile;
         DoError('');
      end;
      LockFantom;
   end;
end; { TSign.StartSession }

procedure TSign.StopSession;
begin
   UnlockFantom;
   WipeFantom;
   FantomStarted := False;
   //FOS_Error := 0; FSign_Error := 0;
end; { TSign.StopSession }

end.
