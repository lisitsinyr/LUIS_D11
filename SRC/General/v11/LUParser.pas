(*
 =======================================================
 Copyright (c) 2023
 Author:
     Lisitsin Y.R.
 Project:
     LU_PAS
     Delphi VCL Extensions (LU)
 Module:
     LUParser
     Парсер
 =======================================================
*)

unit LUParser;

interface

uses Classes, Consts, SysUtils;

type
    TSetOfChar = set of Char;

const
    toSymbolx = Char (6);
    EOFChar = Char (0);
    DChar = Char (13);
    AChar = Char (10);
    TabChar = Char (8);
    Char01 = Char (1);
    HideChars: TSetOfChar = [#1 .. #31];
    ALLChars: TSetOfChar = [#1, #32 .. #255];
    WINChars: TSetOfChar = ['A' .. 'Z', 'a' .. 'z', '0' .. '9', '_', ' ', '.',
        '/', ':', '\', '=', '[', ']', ')', '(', '"', ';', ',', '%', '-',
        #192 .. #255{ WIN Russian }
        ];
    DOSChars: TSetOfChar = ['A' .. 'Z', 'a' .. 'z', '0' .. '9', '_', ' ', '.',
        '/', ':', '\', '=', '[', ']', ')', '(', '"', ';', ',', '%', '-',
        #128 .. #177, #224 .. #241{ DOS Russian }
        ];

{ TParser }

type
    TLUParser = class(TComponent)
    private
        FStream: TStream;
        FOrigin: Longint;
        FBuffer: PChar;
        FBufPtr: PChar;
        FBufEnd: PChar;
        FSourcePtr: PChar;
        FSourceEnd: PChar;
        FTokenPtr: PChar;
        FStringPtr: PChar;
        FSourceLine: Integer;
        FSaveChar: Char;
        FToken: Char;
        FTokenChar: Char;
        FChars: TSetOfChar;
        FWinCode: Boolean;
        procedure ReadBuffer;
        procedure SkipBlanks;
        procedure SetWinCode (Value: Boolean);
        procedure SetStream (Value: TStream);
        function GetSourcePos: Longint;

    public
        constructor Create (AOwner: TComponent); override;
        destructor Destroy; override;
        procedure CheckToken (T: Char);
        procedure CheckTokenSymbol (const S: string);
        procedure Error (const Ident: string);
        procedure ErrorFmt (const Ident: string; const Args: array of const);
        procedure ErrorStr (const Message: string);
        procedure HexToBinary (Stream: TStream);
        function NextToken: Char;
        function TokenComponentIdent: string;
        function TokenFloat: Extended;
        function TokenInt: Longint;
        function TokenString: string;
        function TokenSymbolIs (const S: string): Boolean;
        property SourcePos: Longint read GetSourcePos;
        property SourceLine: Integer read FSourceLine;
        property Token: Char read FToken;
        property TokenChar: Char read FTokenChar;
    { }
        property Stream: TStream read FStream write SetStream;
        property Chars: TSetOfChar read FChars write FChars;
        property WinCode: Boolean read FWinCode write SetWinCode;
    end;

procedure BinToHex (Buffer, Text: PChar; BufSize: Integer); assembler;
function HexToBin (Text, Buffer: PChar; BufSize: Integer): Integer; assembler;

procedure Register;

implementation

{ TParser }

const
    ParseBufSize = 4096;
    CharsHex: set of Char = ['0' .. '9', 'A' .. 'F', 'a' .. 'f'];
    CharsDec: set of Char = ['0' .. '9', '.', 'e', 'E', '+', '-'];

procedure BinToHex (Buffer, Text: PChar; BufSize: Integer); assembler;
asm
    PUSH    ESI
    PUSH    EDI
    MOV     ESI,EAX
    MOV     EDI,EDX
    MOV     EDX,0
    JMP     @@1
@@0:    DB      '0123456789ABCDEF'
@@1:    LODSB
    MOV     DL,AL
    AND     DL,0FH
    MOV     AH,@@0.Byte[EDX]
    MOV     DL,AL
    SHR     DL,4
    MOV     AL,@@0.Byte[EDX]
    STOSW
    DEC     ECX
    JNE     @@1
    POP     EDI
    POP     ESI
end;

function HexToBin (Text, Buffer: PChar; BufSize: Integer): Integer; assembler;
asm
    PUSH    ESI
    PUSH    EDI
    PUSH    EBX
    MOV     ESI,EAX
    MOV     EDI,EDX
    MOV     EBX,EDX
    MOV     EDX,0
    JMP     @@1
@@0:    DB       0, 1, 2, 3, 4, 5, 6, 7, 8, 9,-1,-1,-1,-1,-1,-1
    DB      -1,10,11,12,13,14,15,-1,-1,-1,-1,-1,-1,-1,-1,-1
    DB      -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
    DB      -1,10,11,12,13,14,15
@@1:    LODSW
    CMP     AL,'0'
    JB      @@2
    CMP     AL,'f'
    JA      @@2
    MOV     DL,AL
    MOV     AL,@@0.Byte[EDX-'0']
    CMP     AL,-1
    JE      @@2
    SHL     AL,4
    CMP     AH,'0'
    JB      @@2
    CMP     AH,'f'
    JA      @@2
    MOV     DL,AH
    MOV     AH,@@0.Byte[EDX-'0']
    CMP     AH,-1
    JE      @@2
    OR      AL,AH
    STOSB
    DEC     ECX
    JNE     @@1
@@2:    MOV     EAX,EDI
    SUB     EAX,EBX
    POP     EBX
    POP     EDI
    POP     ESI
end;

constructor TLUParser.Create (AOwner: TComponent);
begin
    inherited Create (AOwner);
    FStream := nil;
    GetMem (FBuffer, ParseBufSize);
    WinCode := True;
    FChars := ALLChars;
   { }
    FTokenPtr := nil;
    FOrigin := 0;
   { NextToken; }
end;

destructor TLUParser.Destroy;
begin
    if FBuffer <> nil then
    begin
        FreeMem (FBuffer, ParseBufSize);
    end;
    inherited Destroy;
end;

procedure TLUParser.SetStream (Value: TStream);
begin
    FStream := Value;
   { Clear }
    FBuffer[0] := EOFChar;
    FBufPtr := FBuffer;
    FBufEnd := FBuffer + ParseBufSize;
    FSourcePtr := FBuffer;
    FSourceEnd := FBuffer;
    FTokenPtr := FBuffer;
    FSourceLine := 1;
   { }
    FOrigin := 0;
end;

procedure TLUParser.SetWinCode (Value: Boolean);
begin
    FWinCode := Value;
    if Value then
        FChars := WINChars
    else
        FChars := DOSChars;
end;

procedure TLUParser.CheckToken (T: Char);
begin
    if Token <> T then
    begin
        case T of
            toSymbol:
                Error ('SIdentifierExpected');
            #2:
                Error ('SStringExpected');
         { System.Classes.toString: Error('SStringExpected'); }
            toInteger, toFloat:
                Error ('SNumberExpected');
            else
                ErrorFmt ('SCharExpected', [T]);
        end;
    end;
end;

procedure TLUParser.CheckTokenSymbol (const S: string);
begin
    if not TokenSymbolIs (S) then
        ErrorFmt ('SSymbolExpected', [S]);
end;

procedure TLUParser.Error (const Ident: string);
begin
    ErrorStr (Ident);
end;

procedure TLUParser.ErrorFmt (const Ident: string; const Args: array of const);
begin
    ErrorStr (Format(Ident, Args));
end;

procedure TLUParser.ErrorStr (const Message: string);
begin
    raise EParserError.CreateFmt ('SParseError', [message, FSourceLine]);
end;

procedure TLUParser.HexToBinary (Stream: TStream);
var
    Count: Integer;
    Buffer: array [0 .. 255] of Char;
begin
    SkipBlanks;
    while FSourcePtr^ <> '}' do
    begin
        Count := HexToBin (FSourcePtr, Buffer, SizeOf(Buffer));
        if Count = 0 then
            Error ('SInvalidBinary');
        Stream.Write (Buffer, Count);
        Inc (FSourcePtr, Count * 2);
        SkipBlanks;
    end;
    NextToken;
end;

procedure TLUParser.SkipBlanks;
begin
    while True do
    begin
        case FSourcePtr^ of
            EOFChar:
                begin
                    ReadBuffer;
                    if FSourcePtr^ = EOFChar then
                        Exit;
                    Continue;
                end;
            AChar:
                begin
                    Inc (FSourceLine);
                end;
            TabChar, DChar:
                Exit;
            Char01, #32 .. #255:
                Exit;
        end;
        Inc (FSourcePtr);
    end;
end;

function TLUParser.NextToken: Char;
var
    I: Integer;
    P, S: PChar;
begin
    SkipBlanks;
    P := FSourcePtr;
    FTokenPtr := P;
    if P^ in FChars then
    begin
        Inc (P);
        while P^ in FChars do
            Inc (P);
      { toSymbol }
        FTokenChar := P^;
        Result := toSymbol;
    end else begin
        case P^ of
            '#', '''':
                begin
                    S := P;
                    while True do
                    begin
                        case P^ of
                            '#':
                                begin
                                    Inc (P);
                                    I := 0;
                                    while P^ in ['0' .. '9'] do
                                    begin
                                        I := I * 10 + (Ord(P^) - Ord('0'));
                                        Inc (P);
                                    end;
                                    S^ := Chr (I);
                                    Inc (S);
                                end;
                            '''':
                                begin
                                    Inc (P);
                                    while True do
                                    begin
                                        case P^ of
                                        EOFChar, AChar, DChar:
                                        Error ('SInvalidString');
                                        '''':
                                        begin
                                        Inc (P);
                                        if P^ <> '''' then
                                        Break;
                                        end;
                                        end;
                                        S^ := P^;
                                        Inc (S);
                                        Inc (P);
                                    end;
                                end;
                            else
                                Break;
                        end;
                    end;
                    FStringPtr := S;
            { toString }
                    Result := toString[1];
                end;
            '$':
                begin
                    Inc (P);
                    while P^ in CharsHex do
                        Inc (P);
            { toInteger }
                    Result := toInteger;
                end;
            '-', '0' .. '9':
                begin
                    Inc (P);
                    while P^ in ['0' .. '9'] do
                        Inc (P);
            { toInteger }
                    Result := toInteger;
                    while P^ in CharsDec do
                    begin
                        Inc (P);
               { toFloat }
                        Result := toFloat;
                    end;
                end;
            else
                Result := P^; { ???? }
                FTokenChar := P^;
                if Result <> toEOF then
                begin

                    Result := toSymbolx; { ???? }

                    Inc (P);
                end;
        end;
    end;
    FSourcePtr := P;
    FToken := Result;
end;

procedure TLUParser.ReadBuffer;
var
    Count: Integer;
begin
    Inc (FOrigin, FSourcePtr - FBuffer);
    FSourceEnd[0] := FSaveChar;
    Count := FBufPtr - FSourcePtr;
    if Count <> 0 then
        Move (FSourcePtr[0], FBuffer[0], Count);
    FBufPtr := FBuffer + Count;
    Inc (FBufPtr, FStream.Read(FBufPtr[0], FBufEnd - FBufPtr));
    FSourcePtr := FBuffer;
    FSourceEnd := FBufPtr;
    if FSourceEnd = FBufEnd then
    begin
        FSourceEnd := LineStart (FBuffer, FSourceEnd - 1);
        if FSourceEnd = FBuffer then
            Error ('SLineTooLong');
    end;
    FSaveChar := FSourceEnd[0];
    FSourceEnd[0] := EOFChar;
end;

function TLUParser.GetSourcePos: Longint;
begin
    Result := FOrigin + (FTokenPtr - FBuffer);
end;

function TLUParser.TokenFloat: Extended;
begin
    Result := StrToFloat (TokenString);
end;

function TLUParser.TokenInt: Longint;
begin
    Result := StrToInt (TokenString);
end;

function TLUParser.TokenString: string;
var
    L: Integer;
begin
    if FToken = toString then
        L := FStringPtr - FTokenPtr
    else
        L := FSourcePtr - FTokenPtr;
    SetString (Result, FTokenPtr, L);
end;

function TLUParser.TokenSymbolIs (const S: string): Boolean;
begin
    Result := (Token = toSymbol) and (CompareText(S, TokenString) = 0);
end;

function TLUParser.TokenComponentIdent: string;
var
    P: PChar;
begin
    CheckToken (toSymbol);
    P := FSourcePtr;
    while P^ = '.' do
    begin
        Inc (P);
        if not (P^ in FChars) then
            Error ('SIdentifierExpected');
        repeat
            Inc (P)
        until not (P^ in FChars);
    end;
    FSourcePtr := P;
    Result := TokenString;
end;

{ This procedure is used to register this component on the component palette }

procedure Register;
begin
   { Parser }
    RegisterComponents ('Luis', [TLUParser]);
end;

end.
