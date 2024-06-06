unit LUVerba;

interface

uses
  Classes, SysUtils, Windows, Dialogs, Controls,
  //WBothX,
  LUSupport, LUExec;

type
  Chars = array[0..255] of char;
  Chars137 = array[0..137] of char;
  TTypeSprList = (eTypeSprList, sTypeSprList);
const
  oe_UnableToLockFile = 3;

{ TVerbaSign }
type
  TVerbaSignErrorEvent = procedure(Sender : TObject; FileName : TFileName; VerbaError: Integer) of object;
  TVerbaSign = class(TComponent)
  private
    { Private declarations }
    (*
    FPublicBase: PChar;
    FPrivateKey: PChar;
    FFileName: PChar;
    *)
    {}
    FOnError: TVerbaSignErrorEvent;
    FIDName: Chars;
    FDeleteSign: Boolean;
    FSprSignAlias: Chars137;

    FErrorSign: Integer;
    FSignID: String;
    FSignAlias: String;
    FSignStatus: T8bit;
    FSignStatusString: string;

    FVerbaError: T16bit;
    FVerbaErrorBreak: Boolean;
    FSignCount: T8bit;
    FStat_Array: PCheck_Status;
    //FStrSign : Pointer;
    //FRadixSign : String;
    //FStrSignLen : Integer;
    FSprList: pSprList;
    FNum: T16bit;
    //FSorE: Char;
    FVerbaSprList: TStringList;
    //FPInfo: PUSR_KEYS_INFO;
    FInfo: USR_KEYS_INFO;
    FCountKey: T32bit;

    FAbonents: P16bit;
    FAbonentsList: TStringList;
    FNAbonents: T16bit;
    FSeries: array [1..7] of Char;
    FAbonentSender: array [1..11] of Char;
    (*
    function GetPrivateKey: string;
    procedure SetPrivateKey(const Value: string);
    function GetPublicBase: string;
    procedure SetPublicBase(const Value: string);
    function GetFileName: string;
    procedure SetFileName(const Value: string);
    *)
    procedure DoError(AFileName : TFileName);
    { Sign }
    function LUSignInit(const APrivateKey, APublicBase: string) : Boolean;
    function LUSignLogIn(const APrivateKey: string) : Boolean;
    function LUSignLogOut : Boolean;
    function LUInitKey(PrivateKey,slot: string): Boolean;
    function LUResetKeyEx(const Key_ID: string; Flag: Boolean): Boolean;
    function LUResetKey(const Key_ID: string): Boolean;
    function LUGetDrvInfo(Keys_Info: PUSR_KEYS_INFO; n_Key_Slot: P32bit): Boolean;
    { Crypto }
    function LUCryptoInit(const APrivateKey, APublicBase: string): Boolean;
    function GetVerbaErrorString: string;
    function LUGetCryptKeysF(const Key_ID,APrivateKey,APublicBase,File_IN: string): Boolean;
    function LUGetFileSenderID(const Key_ID,APrivateKey,APublicBase,File_IN: string): Boolean;
    {}
    function GetNameSign(Index: Integer): string;
    function GetAliasSign(Index: Integer): string;
    function GetStatusSign(Index: Integer): T8bit;
    {}
    function LUSprList(const Series: string; TypeSprList: TTypeSprList; APrivateKey,APublicBase: string): Boolean;
    function GetKey_ID(Index: Integer): string;
    function GetKey_status(Index: Integer): T8bit;
    function GetKey_type(Index: Integer): T8bit;
    function LUGetAlias(const Key_ID,APrivateKey,APublicBase: string): Boolean;
    function GetSprSignAlias(const Key_ID,APrivateKey,APublicBase: string): string;
    { Sign File }
    function LUSignFile(const Key_ID,APrivateKey, APublicBase,File_IN,File_OUT: string) : Boolean;
    function LUCheck_File_Sign(const Key_ID,APrivateKey,APublicBase,File_IN: string): Boolean;
    { Crypt File }
    function LUEnCryptFile(NodeFrom: T16bit; NodeTo: P16bit; SerTo,Key_ID,APrivateKey,APublicBase,File_IN,File_OUT: string): Boolean;
    function LUDeCryptFile(Abonent: T16bit; Key_ID,APrivateKey,APublicBase,File_IN,File_OUT: string): Boolean;
    {}
    function GetSeries: string;
    function GetAbonentSender: string;
    {}
    function CheckLoadKey(PrivateKey,Key_ID: string): Boolean;
    {}
    property NameSign[Index: Integer]: string read GetNameSign;
    property AliasSign[Index: Integer]: string read GetAliasSign;
    property StatusSign[Index: Integer]: T8bit read GetStatusSign;
    property Key_ID[Index: Integer]: string read GetKey_ID;
    property Key_Status[Index: Integer]: T8bit read GetKey_Status;
    property Key_Type[Index: Integer]: T8bit read GetKey_Type;
  protected
    { Protected declarations }
  public
    { Public declarations }
    constructor Create(Aowner : TComponent); override;
    destructor Destroy; override;
    function GetInfoCryptFile(const Key_ID,APrivateKey,APublicBase,File_IN: string): Boolean;
    {}
    property VerbaError: T16bit read FVerbaError;
    property VerbaErrorString: string read GetVerbaErrorString;
    {}
    //property StrSign : Pointer read FStrSign;
    //property RadixSign : String read FRadixSign;
    //property StrSignLen : Integer read FStrSignLen;
    {}
    (*
    property PublicBase: string read GetPublicBase write SetPublicBase;
    property PrivateKey: string read GetPrivateKey write SetPrivateKey;
    property FileName: string read GetFileName write SetFileName;
    *)
    property IDName: chars read FIDName;
    {}
    property DeleteSign : Boolean read FDeleteSign write FDeleteSign;
    {}
    property OnError : TVerbaSignErrorEvent read FOnError write FOnError;
    {}
    property SignCount:T8bit read FSignCount;
    property SignID: String read FSignID;
    property SignAlias: String read FSignAlias;
    property SignStatus: T8bit read FSignStatus;
    property SignStatusString: String read FSignStatusString;
    property VerbaSprList: TStringList read FVerbaSprList;
    property SprSignAlias[const Key_ID,APrivateKey,APublicBase: string]: String read GetSprSignAlias;
    {}
    property AbonentsList: TStringList read FAbonentsList;

    property NAbonents: T16bit read FNAbonents;
    property Series: string read GetSeries;
    property AbonentSender: string read GetAbonentSender;
  end;

{ Sign }

function CheckVerbaSignFile(AVerbaSign: TVerbaSign; const File_IN,APrivateKey,APublicBase: string; DeleteSign: Boolean; Key_ID: string): Boolean;
function SetVerbaSignFile(AVerbaSign: TVerbaSign; const File_IN,File_OUT,APrivateKey,APublicBase: string; Key_ID: string): Boolean;

{ Crypt }

function VerbaCryptFile(AVerbaCrypt: TVerbaSign; const File_IN,File_OUT, APrivateKey,APublicBase: string;
   const Abonent: T16bit; AbonentTo: array of word; const Series,Key_ID: string): Boolean;
function VerbaDeCryptFile(AVerbaCrypt: TVerbaSign; const File_IN,File_OUT, APrivateKey,APublicBase: string;
   const Abonent: T16bit; Key_ID: string): Boolean;
function VerbaInfoCryptFile(AVerbaCrypt: TVerbaSign; const File_IN,APrivateKey,APublicBase,Key_ID: string): Boolean;

function VerbaSprList(AVerbaCrypt: TVerbaSign; const APrivateKey,APublicBase: string;
   const Series: string; TypeSprList: TTypeSprList): Boolean;

implementation

{ CheckVerbaSignFile }

function CheckVerbaSignFile(AVerbaSign: TVerbaSign; const File_IN,APrivateKey,APublicBase: string; DeleteSign: Boolean; Key_ID: string): Boolean;
begin
   (*
   VerbaSign.PrivateKey := APrivateKey;
   VerbaSign.PublicBase := APublicBase;
   VerbaSign.FileName := AFileName;
   *)
   AVerbaSign.DeleteSign := DeleteSign;
   try
      Result := AVerbaSign.LUCheck_File_Sign(Key_ID,APrivateKey,APublicBase,File_IN);
      Result := (AVerbaSign.FVerbaError = 0) and (AVerbaSign.FSignStatus = 0);
   except
      AVerbaSign.FVerbaError := 600;
      Result := False;
   end;
   if Key_ID <> '' then AVerbaSign.LUResetKey(Key_ID);
end;

{ SetVerbaSignFile }

function SetVerbaSignFile(AVerbaSign: TVerbaSign; const File_IN,File_OUT,APrivateKey,APublicBase: string; Key_ID: string): Boolean;
begin
   (*
   VerbaSign.PrivateKey := APrivateKey;
   VerbaSign.PublicBase := APublicBase;
   VerbaSign.FileName := AFileName;
   *)
   AVerbaSign.DeleteSign := False;
   try
      Result := AVerbaSign.LUSignFile(Key_ID, APrivateKey,APublicBase,File_IN,File_OUT);
   except
      AVerbaSign.FVerbaError := 600;
      Result := False;
   end;
   if Key_ID <> '' then AVerbaSign.LUResetKey(Key_ID);
end;

{ VerbaCryptFile }

function VerbaCryptFile(AVerbaCrypt: TVerbaSign; const File_IN,File_OUT,APrivateKey,APublicBase: string;
   const Abonent: T16bit; AbonentTo: array of word; const Series,Key_ID: string): Boolean;
var
   P: P16bit;
begin
   (*
   VerbaCrypt.PrivateKey := APrivateKey;
   VerbaCrypt.PublicBase := APublicBase;
   VerbaCrypt.FileName := AFileName;
   *)
   P := Addr(AbonentTo);
   try
      Result := AVerbaCrypt.LUEnCryptFile(Abonent, P, Series, Key_ID, APrivateKey,APublicBase, File_IN,File_OUT);
   except
      AVerbaCrypt.FVerbaError := 600;
      Result := False;
   end;
   if Key_ID <> '' then AVerbaCrypt.LUResetKey(Key_ID);
end;

{ VerbaInfoCryptFile }

function VerbaInfoCryptFile(AVerbaCrypt: TVerbaSign; const File_IN,APrivateKey,APublicBase,Key_ID: string): Boolean;
begin
//{?}Writeln('VerbaInfoCryptFile: '+File_IN+'|'+APrivateKey+'|'+APublicBase);
   (*
   VerbaCrypt.PrivateKey := APrivateKey;
   VerbaCrypt.PublicBase := APublicBase;
   VerbaCrypt.FileName := AFileName;
   *)
   try
      Result := AVerbaCrypt.GetInfoCryptFile(Key_ID, APrivateKey,APublicBase,File_IN);
   except
      AVerbaCrypt.FVerbaError := 600;
      Result := False;
   end;
   if Key_ID <> '' then AVerbaCrypt.LUResetKey(Key_ID);
end;

{ VerbaSprList }

function VerbaSprList(AVerbaCrypt: TVerbaSign; const APrivateKey,APublicBase: string;
   const Series: string; TypeSprList: TTypeSprList): Boolean;
begin
   (*
   VerbaCrypt.PrivateKey := APrivateKey;
   VerbaCrypt.PublicBase := APublicBase;
   VerbaCrypt.FileName := '';
   *)
   try
      Result := AVerbaCrypt.LUSprList(Series, TypeSprList, APrivateKey,APublicBase);
   except
      AVerbaCrypt.FVerbaError := 600;
      Result := False;
   end;
end;

{ VerbaDeCryptFile }

function VerbaDeCryptFile(AVerbaCrypt: TVerbaSign; const File_IN,File_OUT,APrivateKey,APublicBase: string; const Abonent: T16bit; Key_ID: string): Boolean;
begin
//{?}Writeln('VerbaDeCryptFile: '+File_IN+'|'+File_OUT+'|'+APrivateKey+'|'+APublicBase+'|'+IntToStr(Abonent)+'|'+Key_ID);
   (*
   VerbaCrypt.PrivateKey := APrivateKey;
   VerbaCrypt.PublicBase := APublicBase;
   VerbaCrypt.FileName := AFileName;
   *)
   try
      Result := AVerbaCrypt.LUDeCryptFile(Abonent,Key_ID, APrivateKey,APublicBase,File_IN,File_OUT);
   except
      AVerbaCrypt.FVerbaError := 600;
      Result := False;
   end;
   if Key_ID <> '' then AVerbaCrypt.LUResetKey(Key_ID);
end;

{ GetErrorString }

function GetErrorString(const Code: Integer): string;
begin
   { Стандартное сообщение }
   Result := WBothX.DecodeERRV0(Code);
   if Result = '' then begin
      { Luis Code }
      case Code of
         600: Result := 'Run-time error';
      else
         Result := Format('Неизвестная ошибка. Код возврата: %d (0x%.8x)',[Code,Code]);
      end;
   end;
end;

{ TVerbaSign }

constructor TVerbaSign.Create(AOwner : TComponent);
begin
   inherited Create(Aowner);
   (*
   FileName := '';
   PrivateKey := '';
   PublicBase := '';
   *)
   FillChar(FIDName, SizeOf(FIDName), 0);
   FVerbaSprList := TStringList.Create;
   FVerbaErrorBreak := False;
   FVerbaError := 0;
   FAbonentsList := TStringList.Create;

//{?}Writeln('TVerbaSign.Create');

end;

destructor TVerbaSign.Destroy;
begin
   FAbonentsList.Free;
   FVerbaSprList.Free;
   (*
   StrDispose(FFileName);
   StrDispose(FPrivateKey);
   StrDispose(FPublicBase);
   *)
   inherited Destroy;
end;

function TVerbaSign.GetVerbaErrorString: string;
begin
   Result := GetErrorString(FVerbaError);
end;
(*
{ PublicBase }

function TVerbaSign.GetPublicBase: string;
begin
   Result := StrPas(FPublicBase);
end;
procedure TVerbaSign.SetPublicBase(const Value: string);
begin
   if FPublicBase <> nil then StrDispose(FPublicBase);
   FPublicBase := StrAlloc(Length(Value)+1);
   StrPCopy(FPublicBase, Value);
end;

{ PrivateKey }

function TVerbaSign.GetPrivateKey: string;
begin
   Result := StrPas(FPrivateKey);
end;
procedure TVerbaSign.SetPrivateKey(const Value: string);
begin
   if FPrivateKey <> nil then StrDispose(FPrivateKey);
   FPrivateKey := StrAlloc(Length(Value)+1);
   StrPCopy(FPrivateKey, Value);
end;

{ FileName }

function TVerbaSign.GetFileName: string;
begin
   Result := StrPas(FFileName);
end;
procedure TVerbaSign.SetFileName(const Value: string);
begin
   if FFileName <> nil then StrDispose(FFileName);
   FFileName := StrAlloc(Length(Value)+1);
   StrPCopy(FFileName, Value);
end;
*)

{ DoError }

procedure TVerbaSign.DoError(AFileName : TFileName);
begin
   if Assigned(FOnError) then
      FOnError(Self, AFileName, FVerbaError);
end;

{ LUCryptoInit }

function TVerbaSign.LUCryptoInit(const APrivateKey, APublicBase: string): Boolean;
begin
//{?}Writeln('LUCryptoInit: '+APrivateKey+'|'+APublicBase);
   FVerbaError := WBothX.CryptoInit(PChar(APrivateKey), PChar(APublicBase));
   if (FVerbaError <> 0) then DoError('');
   Result := FVerbaError = 0;
//{?}Writeln('LUCryptoInit: ');
end;

{ LUEnCryptFile }

function TVerbaSign.LUEnCryptFile(NodeFrom: T16bit; NodeTo: P16bit; SerTo,Key_ID,APrivateKey,APublicBase,File_IN,File_OUT: string): Boolean;
begin
   Result := False;
   if CheckLoadKey(APrivateKey, Key_ID) then begin // для жесткого диска
      if LUCryptoInit(APrivateKey,APublicBase) then begin
         FVerbaError := WBothX.EnCryptFile(PChar(File_IN),PChar(File_OUT), NodeFrom, NodeTo, PChar(SerTo));
         Result := (FVerbaError = 0);
         if not Result then DoError(File_IN);
      end;
      WBothX.CryptoDone;
   end;
end;

{ LUDeCryptFile }

function TVerbaSign.LUDeCryptFile(Abonent: T16bit; Key_ID,APrivateKey,APublicBase,File_IN,File_OUT: string): Boolean;
begin
//{?}Writeln('VerbaDeCryptFile: '+File_IN+'|'+File_OUT+'|'+APrivateKey+'|'+APublicBase+'|'+IntToStr(Abonent)+'|'+Key_ID);
   Result := False;
   if CheckLoadKey(APrivateKey,Key_ID) then begin  // для жесткого диска
//{?}Writeln('VerbaDeCryptFile: 1');
      if LUCryptoInit(APrivateKey,APublicBase) then begin
//{?}Writeln('VerbaDeCryptFile: 2');
         FVerbaError := WBothX.DeCryptFile(PChar(File_IN),PChar(File_OUT), Abonent);
//{?}Writeln('VerbaDeCryptFile: 3');
         Result := (FVerbaError = 0);
         if not Result then DoError(File_IN);
      end;
      WBothX.CryptoDone;
   end;
end;

function TVerbaSign.GetSeries: string;
var
   LChars : Chars;
begin
   Move(FSeries,LChars,SizeOf(FSeries));
   Result := StrPas(LChars);
end;

function TVerbaSign.GetAbonentSender: string;
var
   LChars : Chars;
begin
   Move(FAbonentSender,LChars,SizeOf(FAbonentSender));
   Result := StrPas(LChars);
end;

{ GetInfoCryptFile }

function TVerbaSign.GetInfoCryptFile(const Key_ID,APrivateKey,APublicBase,File_IN: string): Boolean;
begin
//{?}Writeln('GetInfoCryptFile: '+Key_ID+'|'+APrivateKey+'|'+APublicBase+'|'+File_IN);
   Result := LUGetFileSenderID(Key_ID,APrivateKey,APublicBase,File_IN);
   if Result then Result := LUGetCryptKeysF(Key_ID, APrivateKey,APublicBase,File_IN);
end;

{ LUGetFileSenderID }

function TVerbaSign.LUGetFileSenderID(const Key_ID,APrivateKey,APublicBase,File_IN: string): Boolean;
begin
//{?}Writeln('LUGetFileSenderID: '+Key_ID+'|'+APrivateKey+'|'+APublicBase+'|'+File_IN);
   Result := False;
   FillChar(FAbonentSender, SizeOf(FAbonentSender), #0);
   if CheckLoadKey(APrivateKey,Key_ID) then begin
      if LUCryptoInit(APrivateKey,APublicBase) then begin
         FVerbaError := WBothX.GetFileSenderID(PChar(File_IN), @FAbonentSender);
         Result := (FVerbaError = 0);
         if not Result then DoError(File_IN);
      end;
      WBothX.CryptoDone;
   end;
end;

{ LUGetCryptKeysF }

function TVerbaSign.LUGetCryptKeysF(const Key_ID,APrivateKey,APublicBase,File_IN: string): Boolean;
var
   i: Integer;
   s: string;
begin
   FillChar(FSeries, SizeOf(FSeries), #0);
   Result := False;
   if CheckLoadKey(APrivateKey,Key_ID) then begin
      if LUCryptoInit(APrivateKey,APublicBase) then begin
         FAbonentsList.Clear;
         FNAbonents := 0;
         FVerbaError := WBothX.GetCryptKeysF(PChar(File_IN), @FNAbonents, @FAbonents, @FSeries);
         Result := (FVerbaError = 0);
         if not Result then DoError(File_IN);
         if Result then begin
            for i:=1 to FNAbonents do begin
               s := IntToStr(AT16Bit(FAbonents^)[i-1]);
               FAbonentsList.Add(s);
            end;
         end;
         FreeMemory(FAbonents);
      end;
      WBothX.CryptoDone;
   end;
end;

{ LUSprList }

function TVerbaSign.LUSprList(const Series: string; TypeSprList: TTypeSprList; APrivateKey,APublicBase: string): Boolean;
var
   i: Integer;
   s: string;
begin
   FVerbaSprList.Clear;
   Result := False;
   if LUCryptoInit(APrivateKey,APublicBase) then begin
      FSprList := nil;
      case TypeSprList of
         eTypeSprList: FVerbaError := WBothX.SprList(PChar(APublicBase),PChar(Series),@FSprList,@FNum,'E');
         sTypeSprList: FVerbaError := WBothX.SprList(PChar(APublicBase),PChar(Series),@FSprList,@FNum,'S');
      end;
      Result := (FVerbaError = 0);
      if not Result then DoError('')
      else begin
         for i:=0 to FNum-1 do begin
            s := IntToStr(Key_Type[i])+' '+IntToStr(Key_Status[i])+' '+Key_ID[i];
            FVerbaSprList.Add(s);
         end;
      end;
      FreeMemory(FSprList);
   end;
   WBothX.CryptoDone;
end;

{ LUGetAlias }

function TVerbaSign.LUGetAlias(const Key_ID,APrivateKey,APublicBase: string): Boolean;
begin
   Result := False;
   if LUCryptoInit(APrivateKey,APublicBase) then begin
      FillChar(FSprSignAlias, SizeOf(FSprSignAlias), 0);
      FVerbaError := WBothX.GetAlias(PChar(APublicBase),PChar(Key_ID),@FSprSignAlias);
      Result := (FVerbaError = 0);
   end;
   WBothX.CryptoDone;
end;

function TVerbaSign.GetSprSignAlias(const Key_ID,APrivateKey,APublicBase: string): string;
begin
   if LUGetAlias(Key_ID,APrivateKey,APublicBase) then
      Result := FSprSignAlias
   else
      Result := 'Error';
end;

{ LUSignInit }

function TVerbaSign.LUSignInit(const APrivateKey, APublicBase: string): Boolean;
begin
   FVerbaError := WBothX.SignInit(PChar(APrivateKey), PChar(APublicBase));
   if (FVerbaError <> 0) then DoError('');
   Result := FVerbaError = 0;
end;

{ LUInitKey }

function TVerbaSign.LUInitKey(PrivateKey,slot: string): Boolean;
begin
//{?}Writeln('LUInitKey: '+PrivateKey+'|'+slot);
   FVerbaError := WBothX.InitKey(PChar(PrivateKey), PChar(slot));
   if (FVerbaError <> 0) then DoError('');
   Result := FVerbaError = 0;
//{?}Writeln('LUInitKey: ');
end;

{ LUResetKeyEx }

function TVerbaSign.LUResetKeyEx(const Key_ID: string; Flag: Boolean): Boolean;
begin
   FVerbaError := WBothX.ResetKeyEx(PChar(Key_ID), Flag);
   if (FVerbaError <> 0) then DoError('');
   Result := FVerbaError = 0;
end;

{ LUResetKey }

function TVerbaSign.LUResetKey(const Key_ID: string): Boolean;
begin
   FVerbaError := WBothX.ResetKey(PChar(Key_ID));
   if (FVerbaError <> 0) then DoError('');
   Result := FVerbaError = 0;
end;

{ LUGetDrvInfo }

function TVerbaSign.LUGetDrvInfo(Keys_Info: PUSR_KEYS_INFO; n_Key_Slot: P32bit): Boolean;
begin
   FVerbaError := WBothX.GetDrvInfo(Keys_Info, n_Key_Slot);
   if (FVerbaError <> 0) then DoError('');
   Result := FVerbaError = 0;
end;

{ LUSignLogIn }

function TVerbaSign.LUSignLogIn(const APrivateKey: string): Boolean;
begin
   FVerbaError := WBothX.SignLogIn(PChar(APrivateKey));
   if (FVerbaError <> 0) then DoError('');
   Result := FVerbaError = 0;
end;

{ LUSignLogOut }

function TVerbaSign.LUSignLogOut: Boolean;
begin
   FVerbaError := WBothX.SignLogOut();
   if (FVerbaError <> 0) then DoError('');
   Result := FVerbaError = 0;
end;

{ LUSignFile }

function TVerbaSign.LUSignFile(const Key_ID,APrivateKey,APublicBase,File_IN,File_OUT: string): Boolean;
begin
   Result := False;
   if CheckLoadKey(APrivateKey, Key_ID) then begin
      if LUSignInit(APrivateKey,APublicBase) then begin
         FillChar(FIDName, SizeOf(FIDName), 0);
         FVerbaError := WBothX.SignFile(PChar(File_IN),PChar(File_OUT), FIDName);
         Result := (FVerbaError = 0);
         if not Result then DoError(File_IN);
      end;
      WBothX.SignDone;
   end;
end;

{ GetNameSign }

function TVerbaSign.GetNameSign(Index: Integer): string;
var
   LChars : Chars;
begin
   FillChar(LChars,SizeOf(LChars), $00);
   Move(WBothX.ACheck_Status(FStat_Array^)[Index].Name, LChars, NAME_LEN);
   Result := StrPas(LChars);
end;

{ GetAliasSign }

function TVerbaSign.GetAliasSign(Index: Integer): string;
var
   LChars : Chars;
begin
   FillChar(LChars,SizeOf(LChars), $00);
   Move(WBothX.ACheck_Status(FStat_Array^)[Index].Alias, LChars, ALIAS_LEN);
   Result := Dos2Win(StrPas(LChars));
end;

{ GetStatusSign }

function TVerbaSign.GetStatusSign(Index: Integer): T8bit;
begin
   Result := WBothX.ACheck_Status(FStat_Array^)[Index].Status;
end;

{ GetKey_ID }

function TVerbaSign.GetKey_ID(Index: Integer): string;
var
   LChars : Chars;
begin
   FillChar(LChars,SizeOf(LChars), $00);
   Move(WBothX.ASprList(FSprList^)[Index].key_id, LChars, LFX_ID_LENGTH);
   Result := StrPas(LChars);
end;

{ GetKey_status }

function TVerbaSign.GetKey_status(Index: Integer): T8bit;
begin
   Result := WBothX.ASprList(FSprList^)[Index].Key_Status;
end;

{ GetKey_type }

function TVerbaSign.GetKey_type(Index: Integer): T8bit;
begin
   Result := WBothX.ASprList(FSprList^)[Index].Key_type;
end;

{ CheckLoadKey }

function TVerbaSign.CheckLoadKey(PrivateKey,Key_ID: string): Boolean;

   procedure Exec_asrkeyw;
   var
      Lasrkeyw: string;
      Status: Cardinal;
   begin
      Lasrkeyw := SearchEXEFile('asrkeyw.exe');
      ExecuteAll(Lasrkeyw,'',GetCurrentDir,True,SW_SHOW,Status);
   end;
var
   LDrive : string;
begin
//{?}Writeln('CheckLoadKey: '+PrivateKey+'|'+Key_ID);
   Result := False;
   LDrive := ExtractFileDrive(PrivateKey);
   if (LDrive <> '') and ((UpperCase(LDrive) <> 'A:') and (UpperCase(LDrive) <> 'B:')) then begin
      Result := True;
      end
   else begin
      FVerbaErrorBreak :=  False;
      while (not Result) and (not FVerbaErrorBreak) do begin
         if Key_ID <> '' then begin
            FVerbaError := 0;
            Result :=  LUInitKey(PrivateKey, Key_ID)
            end
         else begin
            FVerbaError := 0;
            Result :=  LUInitKey(PrivateKey, Key_ID)
         end;
         case FVerbaError of
            NO_ERROR:        Result := True;  // без ошибок
            E_REDEFINE:      Result := True;  // повторная загрузка ключей
            //E_NO_FREE_SLOTS: Result := True;  // все слоты загружены
            E_DRIVER,4098:   Exec_asrkeyw;    // asrkeyw.exe
            E_GK:            Exec_asrkeyw;    // asrkeyw.exe
         else
            if MessageDlg('Установите ключевой диск Вербы', mtWarning, [mbOk{,mbCancel}], 0) = mrCancel then
               FVerbaErrorBreak :=  True;
         end;
      end;
   end;
   LUGetDrvInfo(@FInfo, @FCountKey);
end;

{ LUCheck_File_Sign }

function TVerbaSign.LUCheck_File_Sign(const Key_ID,APrivateKey,APublicBase,File_IN: string): Boolean;
var
   LSID : Chars;
   LDelSign : T16bit;
   LSummaStatus: Integer;
   i: Integer;
begin
   Result := False;
   if CheckLoadKey(APrivateKey,Key_ID) then begin
      if LUSignInit(APrivateKey,APublicBase) then begin
         FillChar(LSID, SizeOf(LSID), 0);
         if DeleteSign then LDelSign := 1 else LDelSign := 0;
         FStat_Array := nil;
         if LUSignLogIn(APrivateKey) then begin
            FVerbaError := WBothX.Check_File_Sign(PChar(File_IN), @FSignCount, @FStat_Array);
            Result := (FVerbaError = 0);
            if Result then begin
               LSummaStatus := 0;
               FErrorSign := -1;
               for i:=0 to FSignCount-1 do begin
                  LSummaStatus := LSummaStatus + StatusSign[i];
                  FSignStatus := StatusSign[i];
                  FSignID := NameSign[i];
                  FSignAlias := AliasSign[i];
                  FSignStatusString := WBothX.DecodeStatus(StatusSign[i]);
                  if StatusSign[i] > 0 then FErrorSign := i;
               end;

               Result := (LSummaStatus=0);
               if Result then begin
                  if DeleteSign then begin
                     FVerbaError := WBothX.DelSign(PChar(File_IN), $FF);
                     Result := (FVerbaError = 0);
                  end;
                  end
               else begin
                  FSignStatus := StatusSign[FErrorSign];
                  FSignID := NameSign[FErrorSign];
                  FSignAlias := AliasSign[FErrorSign];
                  FSignStatusString := WBothX.DecodeStatus(StatusSign[FErrorSign]);
               end;

            end;
            FreeMemory(FStat_Array);
         end;
         if not Result then DoError(File_IN);
      end;
      WBothX.SignDone;
   end;
end;

end.
