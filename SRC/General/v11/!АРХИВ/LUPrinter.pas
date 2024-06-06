unit LUPrinter;

interface

uses
  Classes, Windows, WinSpool, Sysutils, Printers, ShellAPI,
  JclPrint,
  LUSupport;

const
   Switch = ['-', '/'];
   BufferSize = 4096;

type
   TLUPrinter = class(TComponent)
   private
      FWIN: Boolean;
   protected
   public
      constructor Create(AOwner: Tcomponent); override;
      destructor Destroy; override;
      function  OpenPrinter(const PrinterName: string): Boolean; virtual;
      procedure ClosePrinter;                                    virtual;
      procedure WriteString(const Str: string);                  virtual;
      procedure WriteLnString(const Str: string);                virtual;
   published
   end;
   TLUPrinterDirect = class(TLUPrinter)
   private
      FDevMode: PDeviceModeA;
      FPrinterName: string;
      FHandlePrinter: THandle;
   protected
   public
      function  OpenPrinter(const PrinterName: string): Boolean; reintroduce; overload;
      procedure ClosePrinter;                                    reintroduce; overload;
      procedure WriteString(const Str: string);                  reintroduce; overload;
      procedure WriteLnString(const Str: string);                reintroduce; overload;
   published
   end;
   TLUPrinterPort = class(TLUPrinter)
   private
      FPrint: Boolean;
      FPrintFile: Text;
      FNum: Integer;
      FPosition: Integer;
      FBuffer: PByteArray;
      FZ: Boolean;
      function WriteStr (Adr,Len: Integer; ANumMax: Integer): Boolean;
      procedure PrintHex(const AFileName: string; APosition,ANumMax: Integer; AZ: Boolean);
      procedure Print(const AFileName: string);
   protected
   public
      function  OpenPrinter(const Port: string): Boolean;        reintroduce; overload;
      procedure ClosePrinter;                                    reintroduce; overload;
      procedure WriteString(const Str: string);                  reintroduce; overload;
      procedure WriteLnString(const Str: string);                reintroduce; overload;
   published
   end;

   RPrnRec = record
      case Integer of
         1: (
           Cur: TPoint;
           Finish: TPoint;         { End of the printable area }
           Height: Integer);       { Height of the current line }
         2: (
           Tmp: array[1..32] of Char);
   end;
   TLUPrinterPrn = class(TLUPrinterPort)
   private
      FPrinterName: string;
      FPrnRec: RPrnRec;
   protected
   public
      function  OpenPrinter(const PrinterName: string): Boolean;  reintroduce; overload;
      procedure NewPage(var Prn: RPrnRec);
      procedure NewLine(var Prn: RPrnRec);
   published
   end;

//function GetDefaultPrinter: string;
function ExistsPrinter(const PrinterName: string): Boolean;
{ Open/Print/Explore}
procedure ShellFile (const AFileName, AArguments, AVerb: string; AShow: DWORD);
procedure PrintFileDirect (const AFileName, APrinter: string; AWIN: Boolean);
procedure PrintFile (APrint,AWIN,AZ,AHex: Boolean; APosition,ANumMax: Integer;
                     AFileName: string; APort: Integer; APrinter: string);

implementation

procedure ShellFile (const AFileName, AArguments, AVerb: string; AShow: DWORD);
begin
   ShellExecute (0, PChar(AVerb), PChar(ExtractFileName(AFileName)),
                 PChar(AArguments), PChar(ExtractFileDir(AFileName)), AShow);
end;

procedure PrintFile (APrint,AWIN,AZ,AHex: Boolean; APosition,ANumMax: Integer;
                     AFileName: string; APort: Integer; APrinter: string);
var
   FLUPrinter: TLUPrinter;

begin
   { Начало }
   if APort = 0 then begin
      FLUPrinter := TLUPrinterPrn.Create(nil);
      TLUPrinterPrn(FLUPrinter).FPrint := APrint;
      TLUPrinterPrn(FLUPrinter).OpenPrinter(APrinter);
      end
   else begin
      FLUPrinter := TLUPrinterPort.Create(nil);
      TLUPrinterPort(FLUPrinter).FPrint := APrint;
      TLUPrinterPort(FLUPrinter).OpenPrinter('LPT'+IntToStr(APort));
   end;
   FLUPrinter.FWIN := AWIN;
   { Print }
   if AHex then begin
      TLUPrinterPort(FLUPrinter).PrintHex(AFileName,APosition,ANumMax,AZ);
      end
   else begin
      TLUPrinterPort(FLUPrinter).Print(AFileName);
   end;
   { Конец }
   TLUPrinterPort(FLUPrinter).ClosePrinter;
   FLUPrinter.Free;
end;

procedure PrintFileDirect (const AFileName, APrinter: string; AWIN: Boolean);
var
   LSL: TStringList;
   LLUPrinterDirect: TLUPrinterDirect;
begin
   LSL := TStringList.Create;
   LSL.LoadFromFile(AFileName);
   LLUPrinterDirect := TLUPrinterDirect.Create(nil);
   LLUPrinterDirect.FWIN := AWIN;
   if LLUPrinterDirect.FWIN then
      LSL.Text := Win2Dos(LSL.Text);
      //CharToOEM(p,p);
   LLUPrinterDirect.OpenPrinter(APrinter);
   LLUPrinterDirect.WriteString(LSL.Text);
   LLUPrinterDirect.ClosePrinter;
   LLUPrinterDirect.Free;
   LSL.Free;
end;

function ExistsPrinter(const PrinterName: string): Boolean;
begin
   Result := (Printer.Printers.IndexOf(Trim(PrinterName)) >= 0);
end;
(*
{ GetDefaultPrinter }

function GetDefaultPrinter: string;
var
   DefaultPrinter: PChar;
   //LineCur, Port: PChar;
   PrinterInfo: PChar;
   I: Integer;
   Count, NumInfo: DWORD;
   Flags: Integer;
   Level: Byte;
   Buffer: PChar;
begin
   { 1 вариант }
   DefaultPrinter := StrAlloc(79+1);
   GetProfileString('windows', 'device', '', DefaultPrinter, 79);
   Result := StrPas(DefaultPrinter);
   StrDispose(DefaultPrinter);
   Result := ExtractWordNew(1,Result,[',']);
   { 2 вапиант }
   if Win32Platform = VER_PLATFORM_WIN32_NT then begin
      Flags := PRINTER_ENUM_CONNECTIONS or PRINTER_ENUM_LOCAL;
      end
   else begin
      Flags := PRINTER_ENUM_LOCAL or PRINTER_ENUM_DEFAULT;
   end;
   Count := 0;
   Level := 2;
   { check local printers }
   EnumPrinters(Flags, nil, Level, nil, 0, Count, NumInfo);
   if Count > 0 then begin
      GetMem(Buffer, Count);
      { check local printers }
      try
         if EnumPrinters(Flags, nil, Level, Buffer, Count, Count, NumInfo) then begin
            PrinterInfo := Buffer;
            for i:=1 to NumInfo do begin
               if (PPrinterInfo2(PrinterInfo)^.Attributes and PRINTER_ATTRIBUTE_DEFAULT) <> 0 then begin
                  Result := PPrinterInfo2(PrinterInfo)^.pPrinterName;
               end;
               Inc(PrinterInfo, sizeof(TPrinterInfo2));
            end;
         end;
      finally
         FreeMem(Buffer, Count);
      end;
   end;
end;
*)
{ TLUPrinter }

constructor TLUPrinter.Create(AOwner: Tcomponent);
begin
   inherited Create(AOwner);
end;

destructor TLUPrinter.Destroy;
begin
   inherited Destroy;
end;

function TLUPrinter.OpenPrinter(const PrinterName: string): Boolean;
begin
   Result := True;
end;

procedure TLUPrinter.ClosePrinter;
begin
end;

procedure TLUPrinter.WriteString(const Str: string);
begin
end;

procedure TLUPrinter.WriteLnString(const Str: string);
begin
end;


{============================================================================}
{  Printer Direct                                                            }
{============================================================================}

{ OpenPrinter }

function TLUPrinterDirect.OpenPrinter(const PrinterName: string): Boolean;
var
   LDocInfo1: TDocInfo1;
   LPrinterDefaults: TPrinterDefaults;
begin
   GetMem(FDevMode, SizeOf(TDeviceMode));
   FillChar(FDevMode^,SizeOf(TDeviceMode), $00);
   if ExistsPrinter(PrinterName) then
      FPrinterName := PrinterName
   else
      //FPrinterName := GetDefaultPrinter;
      FPrinterName := GetDefaultPrinterName;
   with LPrinterDefaults do begin
      pDatatype := 'Raw';
      pDevMode := FDevMode;
      pDevMode := nil;
      DesiredAccess := PRINTER_ACCESS_USE;
   end;
   FDevMode.dmOrientation := 2;
   if WinSpool.OpenPrinter(PChar(FPrinterName), FHandlePrinter, @LPrinterDefaults) then begin
      with LDocInfo1 do begin
         pDocName := PChar('Printing Text File ...');
         pOutputFile := nil;
         pDataType := 'RAW';
      end;
      WinSpool.StartDocPrinter(FHandlePrinter, 1, @LDocInfo1);
      WinSpool.StartPagePrinter(FHandlePrinter);
      Result := True;
      end
   else begin
      Writeln('error ' + IntToStr(GetLastError));
      Result := False;
   end;
end;

{ ClosePrinter }

procedure TLUPrinterDirect.ClosePrinter;
begin
   FreeMem(FDevMode);
   WinSpool.EndPagePrinter(FHandlePrinter);
   WinSpool.EndDocPrinter(FHandlePrinter);
   WinSpool.ClosePrinter(FHandlePrinter);
end;

{ WriteString }

procedure TLUPrinterDirect.WriteString(const Str: string);
var
   N: DWORD;
begin
   WinSpool.WritePrinter(FHandlePrinter, PChar(Str), Length(Str), N);
end;

{ WriteLnString }

procedure TLUPrinterDirect.WriteLnString(const Str: string);
begin
   WriteString(Str);
   WriteString(#13#10);
end;

{============================================================================}
{  Printer Port                                                              }
{============================================================================}

{ OpenPrinter }

function TLUPrinterPort.OpenPrinter(const Port: string): Boolean;
begin
   try
      if FPrint then begin
         AssignFile(FPrintFile, Port);
         Rewrite(FPrintFile);
      end;
   except
   end;
   Result := True;
end;

{ ClosePrinter }

procedure TLUPrinterPort.ClosePrinter;
begin
   try
      if FPrint then CloseFile(FPrintFile);
   except
   end;
end;

{ WriteString }

procedure TLUPrinterPort.WriteString(const Str: string);
begin
   try
      if FPrint then Write(FPrintFile, Str)
                else Write(Str);
   except
   end;
end;

{ WriteLnString }

procedure TLUPrinterPort.WriteLnString(const Str: string);
begin
   try
      if FPrint then Writeln(FPrintFile, Str)
                else Writeln(Str);
   except
   end;
end;

{ WriteStr }

function TLUPrinterPort.WriteStr (Adr,Len: Integer; ANumMax: Integer): Boolean;
var
   s0: string;
   s1: string;
   s2: string;
   s3: string;
   i: Integer;
   iZap: Integer;
begin
   Result := False;
   { Addr }
   s0 := IntToHex(FPosition, 8);
   s1 := '';
   s2 := '';
   iZap := 1;
   for i:=1 to Len do begin
      iZap := i;
      { Bytes }
      if FZ then begin
         s1 := s1+IntToHex(Byte(FBuffer^[Adr+i-1]), 2);
         end
      else begin
         if i = 9 then s1 := s1+' |';
         s1 := s1+' '+IntToHex(Byte(FBuffer^[Adr+i-1]), 2);
      end;
      { Chars }
      s3 := ' ';
      s3[1] := Char(Byte(FBuffer^[Adr+i-1]));
      //CharToOEM(PChar(s3),PChar(s3));
      if Byte(FBuffer^[Adr+i-1]) > 31 then
         s2 := s2+s3
      else
         s2 := s2+'.';
      Inc(FNum);
      if FNum >= ANumMax then begin Result := True; Break; end;
   end;
   { Dobor }
   for i:=iZap+1 to 16 do begin
      if FZ then begin
         end
      else begin
         if i = 9 then s1 := s1+' |';
         s1 := s1+'   ';
      end;
      s2 := s2+' ';
   end;

   if FZ then
      WriteLNString(s1)
   else
      WriteLNString(s0+':'+s1+' '+s2);

   Inc(FPosition, iZap);
end;

procedure TLUPrinterPort.PrintHex(const AFileName: string; APosition,ANumMax: Integer; AZ: Boolean);
var
   LSourceStream: TFileStream;
   LBufferRead: Integer;
   LDone: Boolean;
   Lmod16: Integer;
   Ldiv16: Integer;
   j: Integer;
begin
   FZ := AZ;
   FPosition := APosition;
   FNum := 0;
   LSourceStream := TFileStream.Create(AFileName, fmOpenRead+fmShareDenyWrite);
   LSourceStream.Position := APosition;
   GetMem(FBuffer, BufferSize);
   LDone := False;
   repeat
      LBufferRead := LSourceStream.Read(FBuffer^, BufferSize);
      Ldiv16 := LBufferRead div 16;
      Lmod16 := LBufferRead mod 16;
      for j:=1 to Ldiv16 do begin
         if not LDone then LDone := WriteStr((j-1)*16,16,ANumMax);
      end;
      if (not LDone) and (Lmod16 > 0) then WriteStr((Ldiv16)*16,Lmod16,ANumMax);
   until (LBufferRead = 0) or (LDone);
   FreeMem(FBuffer);
   LSourceStream.Free;
   if FZ then WriteLNString('');
end;

procedure TLUPrinterPort.Print(const AFileName: string);
var
   LText: TextFile;
   s: string;
begin
   AssignFile(LText, AFileName);
   Reset(LText);
   repeat
      Readln(LText,s);
      WriteLNString(s);
   until EOF(LText);
   CloseFile(LText);
end;

{============================================================================}
{  Printer Prn                                                              }
{============================================================================}

{ OpenPrinter }

function TLUPrinterPrn.OpenPrinter(const PrinterName: string): Boolean;
begin
   if ExistsPrinter(PrinterName) then
      FPrinterName := PrinterName
   else
      //FPrinterName := GetDefaultPrinter;
      FPrinterName := GetDefaultPrinterName;
   Printer.PrinterIndex := Printer.Printers.IndexOf(Trim(PrinterName));
   AssignPrn(FPrintFile);
   Rewrite(FPrintFile);
   { assigns Font settings to the canvas }
   //Printer.Canvas.Font.Name := 'Courier New';
   //Printer.Canvas.Font.Size := 20;
   if FWIN then
      Printer.Canvas.Font.Charset := OEM_CHARSET
   else
      Printer.Canvas.Font.Charset := RUSSIAN_CHARSET;
   FPrnRec := RPrnRec(TTextRec(FPrintFile).UserData);
   Result := True;
end;

{ NewPage }

procedure TLUPrinterPrn.NewPage(var Prn: RPrnRec);
begin
   with Prn do begin
      Cur.X := 0;
      Cur.Y := 0;
      Printer.NewPage;
   end;
end;

{ NewLine }

procedure TLUPrinterPrn.NewLine(var Prn: RPrnRec);

   function CharHeight: Word;
   var
      Metrics: TTextMetric;
   begin
      GetTextMetrics(Printer.Canvas.Handle, Metrics);
      Result := Metrics.tmHeight;
   end;

begin
   with Prn do begin
      Cur.X := 0;
      if Height = 0 then
         Inc(Cur.Y, CharHeight)
      else
         Inc(Cur.Y, Height);
      if Cur.Y > (Finish.Y - (Height * 2)) then NewPage(Prn);
      Height := 0;
   end;
end;

end.
