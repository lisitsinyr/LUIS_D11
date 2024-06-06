unit LUTextPrinter;

interface

uses
   Windows, Controls, Dialogs, SysUtils, Classes, WinSpool, Printers, Graphics,
   LUSupport;

type
   PrnRec = record
      case Integer of
         1: (
           Cur: TPoint;
           Finish: TPoint;         { End of the printable area }
           Height: Integer);       { Height of the current line }
         2: (
           Tmp: array[1..32] of Char);
   end;

   TTextPrinter = class(TObject)
   private
      FErrorString: PChar;
      FPrinterNames: TstringList;
      FPrinterOpen: Boolean;
      FNumberOfBytesWritten: DWORD;
      FHandle: THandle;
      FFontDialog: TFontDialog;
      FPrintFile: Text;
      FPrnRec: PrnRec;
      FFont : TFont;
      procedure SetErrorString;
      function GetPrinterNames: TStringList;
      function GetDefaultPrinter: string;
   public
      constructor Create;
      destructor Destroy; override;
      function CaseFont: Boolean;
      { 1 }
      procedure OpenPort(const Port: string);
      procedure ClosePort;
      procedure WriteStringToPort(const Str: string);
      procedure WriteLnStringToPort(const Str: string);
      procedure WriteStringsToPort(TS: TStringList);
      { 2 }
      procedure OpenPrinterName(const PrinterName: string);
      procedure ClosePrinterName;
      procedure WriteStringToPrinter(const Str: string);
      procedure WriteLnStringToPrinter(const Str: string);
      procedure WriteStringsToPrinter(TS: TStringList);
      { 3 }
      procedure OpenPrinterFile;
      procedure ClosePrinterFile;
      procedure WriteStringToPrinterFile(const Str: string);
      procedure WritelnStringToPrinterFile(const Str: string);
      procedure WriteStringsToPrinterFile(TS: TStringList);
      {}
      property NumberOfBytesWritten: DWORD read FNumberOfBytesWritten;
      property FontPrint: TFont read FFont write FFont;
      property PrinterNames: TstringList read GetPrinterNames;
      property DefaultPrinter: string read GetDefaultPrinter;
   end;

function CasePrinter(var aStart,aStop: Integer): Boolean;

implementation

function CasePrinter(var aStart,aStop: Integer): Boolean;
var
   FPrintDialog: TPrintDialog;
begin
   FPrintDialog := TPrintDialog.Create(nil);
   Result := False;
   FPrintDialog.Options := [poPageNums, poSelection];
   FPrintDialog.FromPage := 1;
   FPrintDialog.MinPage := 1;
   FPrintDialog.ToPage := 1{PageControl1.PageCount};
   FPrintDialog.MaxPage := 1{PageControl1.PageCount};
   if FPrintDialog.Execute then begin
      { determine the range the user wants to print }
      with FPrintDialog do begin
         if PrintRange = prAllPages then begin
            aStart := MinPage - 1;
            aStop := MaxPage - 1;
         end else
         if PrintRange = prSelection then begin
            aStart := 1{PageControl1.ActivePage.PageIndex};
            aStop := aStart;
         end else  { PrintRange = prPageNums } begin
            aStart := FromPage - 1;
            aStop := ToPage - 1;
         end;
      end;
      Result := True;
   end;
   FPrintDialog.Free;
end;

{ TTextPrinter }

constructor TTextPrinter.Create;
begin
   inherited Create;
   FPrinterNames := TstringList.Create;
   FFontDialog := TFontDialog.Create(nil);
   FFont := nil;
end;

destructor TTextPrinter.Destroy;
begin
   FFontDialog.Free;
   FPrinterNames.Free;
   if FErrorString <> nil then LocalFree(Integer(FErrorString));
   inherited Destroy;
end;

procedure TTextPrinter.SetErrorString;
begin
   if FErrorString <> nil then LocalFree(Integer(FErrorString));
   FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER or FORMAT_MESSAGE_FROM_SYSTEM,
                 nil, GetLastError(), LANG_USER_DEFAULT,  @FErrorString, 0, nil);
end;

{ Port }

procedure TTextPrinter.OpenPort(const Port: string);
begin
   // 'LPT1'
   FPrinterOpen := False;
   FHandle := CreateFile(PChar(UpperCase(Port)), GENERIC_READ or GENERIC_WRITE, FILE_SHARE_READ
                                 or FILE_SHARE_WRITE, nil, OPEN_EXISTING, 0, 0);
   if FHandle = INVALID_HANDLE_VALUE then begin
      SetErrorString;
      raise Exception.Create(FErrorString);
      end
   else
      FPrinterOpen := True;
end;

procedure TTextPrinter.ClosePort;
begin
   FPrinterOpen := False;
   CloseHandle(FHandle);
end;

procedure TTextPrinter.WriteStringToPort(const Str: string);
var
   OEMStr: PChar;
   NumberOfBytesToWrite: DWORD;
begin
   if not FPrinterOpen then Exit;
   NumberOfBytesToWrite := Length(Str);
   OEMStr := PChar(LocalAlloc(LMEM_FIXED, NumberOfBytesToWrite + 1));
   try
      CharToOem(PChar(Str), OEMStr);
      if not WriteFile(FHandle, OEMStr^, NumberOfBytesToWrite, FNumberOfBytesWritten, nil) then begin
         SetErrorString;
         raise Exception.Create(FErrorString);
      end;
   finally
      LocalFree(Integer(OEMStr));
   end;
end;

procedure TTextPrinter.WriteLnStringToPort(const Str: string);
begin
   WriteStringToPort(Str);
   WriteStringToPort(#13#10);
end;

procedure TTextPrinter.WriteStringsToPort(TS: TStringList);
var
   i: Integer;
begin
   for i:=0 to TS.Count-1 do WritelnStringToPort(TS.Strings[i]);
end;

{ PrinterName   (Borland/Inprise FAQ N714) }

function TTextPrinter.CaseFont: Boolean;
begin
   Result := False;
   FFontDialog.Device := fdBoth;
   if FFontDialog.Execute then begin
      FFont := FFontDialog.Font;
      Result := True;
   end;
end;

procedure TTextPrinter.OpenPrinterName(const PrinterName: string);
var
   DocInfo1: TDocInfo1;
begin
   FPrinterOpen := False;
   if not OpenPrinter(PChar(PrinterName), FHandle, nil) then begin
     ShowMessage('error ' + IntToStr(GetLastError));
     Exit;
   end;
   with DocInfo1 do begin
      pDocName := PChar('Printing Text File ...');
      pOutputFile := nil;
      pDataType := 'RAW';
   end;
   StartDocPrinter(FHandle, 1, @DocInfo1);
   StartPagePrinter(FHandle);
   FPrinterOpen := True;
end;

procedure TTextPrinter.ClosePrinterName;
begin
   EndPagePrinter(FHandle);
   EndDocPrinter(FHandle);
   ClosePrinter(FHandle);
   FPrinterOpen := False;
end;

procedure TTextPrinter.WriteStringToPrinter(const Str: string);
var
   N: DWORD;
begin
   WritePrinter(FHandle, PChar(Str), Length(Str), N);
end;

procedure TTextPrinter.WriteLnStringToPrinter(const Str: string);
begin
   WriteStringToPrinter(Str);
   WriteStringToPrinter(#13#10);
end;

procedure TTextPrinter.WriteStringsToPrinter(TS: TStringList);
var
   i: Integer;
begin
   for i:=0 to TS.Count-1 do WritelnStringToPrinter(TS.Strings[i]);
end;

function TTextPrinter.GetPrinterNames: TStringList;
var
   //LineCur, Port: PChar;
   Buffer, PrinterInfo: PChar;
   I: Integer;
   Count, NumInfo: DWORD;
   Flags: Integer;
   Level: Byte;
begin
   FPrinterNames.Clear;
   Result := FPrinterNames;
   try
      if Win32Platform = VER_PLATFORM_WIN32_NT then begin
         Flags := PRINTER_ENUM_CONNECTIONS or PRINTER_ENUM_LOCAL;
         end
      else begin
         Flags := PRINTER_ENUM_LOCAL;
      end;
      Count := 0;
      Level := 5;
      EnumPrinters(Flags, nil, Level, nil, 0, Count, NumInfo);
      if Count = 0 then Exit;
      GetMem(Buffer, Count);
      try
         if not EnumPrinters(Flags, nil, Level, Buffer, Count, Count, NumInfo) then Exit;
         PrinterInfo := Buffer;
         for I := 0 to NumInfo - 1 do begin
            with PPrinterInfo5(PrinterInfo)^ do begin
               Result.Add(pPrinterName);
               Inc(PrinterInfo, sizeof(TPrinterInfo5));
            end;
         end;
      finally
         FreeMem(Buffer, Count);
      end;
   except
      raise;
   end;
end;

function TTextPrinter.GetDefaultPrinter: string;
var
   DefaultPrinter: PChar;
   //LineCur, Port: PChar;
   Buffer, PrinterInfo: PChar;
   I: Integer;
   Count, NumInfo: DWORD;
   Flags: Integer;
   Level: Byte;
begin
   { 1 }
   DefaultPrinter := StrAlloc(79+1);
   GetProfileString('windows', 'device', '', DefaultPrinter, SizeOf(DefaultPrinter) - 1);
   Result := StrPas(DefaultPrinter);
   StrDispose(DefaultPrinter);
   Result := ExtractWordNew(1,Result,[',']);
   { 2 }
   if Win32Platform = VER_PLATFORM_WIN32_NT then begin
      Flags := PRINTER_ENUM_CONNECTIONS or PRINTER_ENUM_LOCAL;
      end
   else begin
      Flags := PRINTER_ENUM_LOCAL;
   end;
   Count := 0;
   Level := 2;
   EnumPrinters(Flags, nil, Level, nil, 0, Count, NumInfo);
   if Count = 0 then Exit;
   GetMem(Buffer, Count);
   try
      if not EnumPrinters(Flags, nil, Level, Buffer, Count, Count, NumInfo) then Exit;
      PrinterInfo := Buffer;
      for I := 0 to NumInfo-1 do begin
         with PPrinterInfo2(PrinterInfo)^ do begin
            if (Attributes and PRINTER_ATTRIBUTE_DEFAULT) <> 0 then begin
               Result := pPrinterName;
            end;
            Inc(PrinterInfo, sizeof(TPrinterInfo2));
         end;
      end;
   finally
      FreeMem(Buffer, Count);
   end;
end;

{ PrinterFile }

{ Start a new line on the current page, if no more lines left start a new page. }

procedure NewPage(var Prn: PrnRec);
begin
   with Prn do begin
      Cur.X := 0;
      Cur.Y := 0;
      Printer.NewPage;
   end;
end;

procedure NewLine(var Prn: PrnRec);

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

procedure TTextPrinter.OpenPrinterFile;
begin
   AssignPrn(FPrintFile);   {assigns PrintText to the printer}
   Rewrite(FPrintFile);     {creates and opens the output file}
   if Assigned(FFont) then
      Printer.Canvas.Font := FFont;  {assigns Font settings to the canvas}
   FPrinterOpen := True;
   FPrnRec := PrnRec(TTextRec(FPrintFile).UserData);
end;

procedure TTextPrinter.ClosePrinterFile;
begin
   if FPrinterOpen then CloseFile(FPrintFile); {Closes the printer variable}
   FPrinterOpen := False;
end;

procedure TTextPrinter.WriteStringToPrinterFile(const Str: string);
begin
   Write(FPrintFile, Str);
   (*
   with Printer do begin
      NewLine(FPrnRec);
      Canvas.TextOut(FPrnRec.Cur.x, FPrnRec.Cur.y, Str);
   end;
   *)
end;

procedure TTextPrinter.WritelnStringToPrinterFile(const Str: string);
begin
   WriteStringToPrinterFile(Str+#13#10);
end;

procedure TTextPrinter.WriteStringsToPrinterFile(TS: TStringList);
var
   I: Integer;
begin
   for i:=0 to TS.Count-1 do begin
      WritelnStringToPrinterFile(TS[i]);
   end;
end;


end.

