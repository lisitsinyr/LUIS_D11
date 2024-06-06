{***********************************************}
{*          United32.pas for Delphi 4          *}
{*  Copyright(C) 1996-1998 by United Software. *}
{*             All Rights Reserved             *}
{***********************************************}

Unit United32;

Interface
Uses Windows, SysUtils;

Type
 TFixedVersionInfo = Class
  Private
   bApp: Boolean;
   bDLL: Boolean;
   bDebugBuild: Boolean;
   bPreRelease: Boolean;
   bSpecialBuild: Boolean;
   bPrivateBuild: Boolean;
   wMajorVersion: Word;
   wMinorVersion: Word;
   wRelease: Word;
   wBuild: Word;
  Public
   Constructor Create(FileName: String);
   Destructor Destroy; Override;
   Property App: Boolean Read bApp;
   Property DLL: Boolean Read bDLL;
   Property DebugBuild: Boolean Read bDebugBuild;
   Property PreRelease: Boolean Read bPreRelease;
   Property SpecialBuild: Boolean Read bSpecialBuild;
   Property PrivateBuild: Boolean Read bPrivateBuild;
   Property MajorVersion: Word Read wMajorVersion;
   Property MinorVersion: Word Read wMinorVersion;
   Property Release: Word Read wRelease;
   Property Build: Word Read wBuild;
End;

Type
 TBIOSFixedInfo = Class
  Private
   sBIOSName: ShortString;
   sBIOSCopyright: ShortString;
   sBIOSDate: ShortString;
   sBIOSExtendedInfo: ShortString;
  Public
   Constructor Create;
   Destructor Destroy; Override;
   Property BIOSName: ShortString Read sBIOSName;
   Property BIOSCopyright: ShortString Read sBIOSCopyright;
   Property BIOSDate: ShortString Read sBIOSDate;
   Property BIOSExtendedInfo: ShortString Read sBIOSExtendedInfo;
End;

Type
 ProcessFileFunction = Function(Const FileName: String): Boolean;

{File version routines}
Function GetFileVersionFull(FileName: String; Separate: Boolean = False): ShortString;
Function GetFileVersion(FileName: String; Separate: Boolean = False): ShortString;
Function IsDebugBuild(FileName: String): Boolean;
Function IsPreRelease(FileName: String): Boolean;
Function IsSpecialBuild(FileName: String): Boolean;
Function IsPrivateBuild(FileName: String): Boolean;

{BIOS version routines}
Function GetBIOSName: ShortString;
Function GetBIOSCopyright: ShortString;
Function GetBIOSExtendedInfo: ShortString;
Function GetBIOSDate: TDateTime;
Function GetBIOSDateString: ShortString;

{Common routines}
Function ANSISentenceCase(Const Value: String): String;
Function ANSITitleCase(Const Value: String): String;
Function IsSwitchPresent(Switch: String): Boolean;
Function IntToSepStr(Value: Int64): String;
Function OEMToStr(Const Value: String): String;
Function StrToOEM(Const Value: String): String;
Procedure FlashNotify(Handle: HWND);

{File routines}
Function AddSlash(Path: String): String;
Function PathOK(Path: String): Boolean;
Function TruncFileName(Const FileName: String; MaxLength: Integer): String;
Procedure ProcessFiles(AllFilesIfNoWildCard: Boolean; Recursive: Boolean;
                       Path: String; ProcessFile: ProcessFileFunction);

{System routines}
Function GetCurrentComputerName: String;
Function GetCurrentUserName: String;
Function GetWinLangName: String;
Function GetColorBits: Integer;
Function GetDiskSerialNumber(Disk: Char): ShortString;

{Math routines}
Function NOD(A, B: Int64): Int64; Overload;
Function NOD(Const Args: Array Of Int64): Int64; Overload;
Function NOK(A, B: Int64): Int64; Overload;
Function NOK(Const Args: Array Of Int64): Int64; Overload;

Implementation
Const
 TruncFill = '\...';
 AllMask = '*.*';

Constructor TFixedVersionInfo.Create(FileName: String);
Var
 FI: PVSFixedFileInfo;
 InfoSize, VerSize, Dummy: DWORD;
 VerBuf: Pointer;
Begin
 InfoSize := GetFileVersionInfoSize(PChar(FileName), Dummy);
 If InfoSize <> 0 Then
  Begin
   GetMem(VerBuf, InfoSize);
   Try
    If GetFileVersionInfo(PChar(FileName), Dummy, InfoSize, VerBuf) Then
     If VerQueryValue(VerBuf, '\', Pointer(FI), VerSize) Then
      With FI^ Do
       Begin
        bApp := (dwFileType And VFT_APP) <> 0;
        bDLL := (dwFileType And VFT_DLL) <> 0;
        bDebugBuild := (dwFileFlags And VS_FF_DEBUG) <> 0;
        bPreRelease := (dwFileFlags And VS_FF_PRERELEASE) <> 0;
        bSpecialBuild := (dwFileFlags And VS_FF_SPECIALBUILD) <> 0;
        bPrivateBuild := (dwFileFlags And VS_FF_PRIVATEBUILD) <> 0;
        wMajorVersion := dwFileVersionMS Shr 16;
        wMinorVersion := dwFileVersionMS And $FFFF;
        wRelease := dwFileVersionLS Shr 16;
        wBuild := dwFileVersionLS And $FFFF;
       End;
   Finally
    FreeMem(VerBuf);
   End;
  End;
End;

Destructor TFixedVersionInfo.Destroy;
Begin
 Inherited;
End;

{File version routines}
Function GetFileVersionFull(FileName: String; Separate: Boolean = False): ShortString;
Const
 sPreRelease = ' Pre-Release';
 sDebugBuild = ' Debug';
 sSpecialBuild = ' Special';
 sPrivateBuild = ' Private';
Var
 bDBuild, bPRelease, bSBuild, bPBuild: Boolean;
 TempString: String;
Begin
 Result := GetFileVersion(FileName, Separate);
 bPRelease := IsPreRelease(FileName);
 bDBuild := IsDebugBuild(FileName);
 bSBuild := IsSpecialBuild(FileName);
 bPBuild := IsPrivateBuild(FileName);
 If bDBuild Or bPRelease Or bSBuild Or bPBuild Then
  Begin
   Result := Result + ' (';
   TempString := '';
   If bPRelease Then TempString := TempString + sPreRelease;
   If bDBuild Then TempString := TempString + sDebugBuild;
   If bSBuild Then TempString := TempString + sSpecialBuild;
   If bPBuild Then TempString := TempString + sPrivateBuild;
    Result := Result + Trim(TempString);
   If Not Separate Then
    Result := Result + ' build)' Else
    Result := Result + ')';
  End;
End;

Function GetFileVersion(FileName: String; Separate: Boolean = False): ShortString;
Var
 FixedVersionInfo: TFixedVersionInfo;
 FormatString: String;
Begin
 Result := '';
 FixedVersionInfo := TFixedVersionInfo.Create(FileName);
 Try
  If Not Separate Then
   FormatString := '%d.%d.%d.%d' Else
   FormatString := '%d.%d (Build %d.%d)';
  With FixedVersionInfo Do
   Result := Format(FormatString, [MajorVersion, MinorVersion,
                                   Release, Build]);
 Finally
  FixedVersionInfo.Free;
 End;
End;

Function IsDebugBuild(FileName: String): Boolean;
Var
 FixedVersionInfo: TFixedVersionInfo;
Begin
 FixedVersionInfo := TFixedVersionInfo.Create(FileName);
 Try
  Result := FixedVersionInfo.DebugBuild;
 Finally
  FixedVersionInfo.Free;
 End;
End;

Function IsPreRelease(FileName: String): Boolean;
Var
 FixedVersionInfo: TFixedVersionInfo;
Begin
 FixedVersionInfo := TFixedVersionInfo.Create(FileName);
 Try
  Result := FixedVersionInfo.PreRelease;
 Finally
  FixedVersionInfo.Free;
 End;
End;

Function IsSpecialBuild(FileName: String): Boolean;
Var
 FixedVersionInfo: TFixedVersionInfo;
Begin
 FixedVersionInfo := TFixedVersionInfo.Create(FileName);
 Try
  Result := FixedVersionInfo.SpecialBuild;
 Finally
  FixedVersionInfo.Free;
 End;
End;

Function IsPrivateBuild(FileName: String): Boolean;
Var
 FixedVersionInfo: TFixedVersionInfo;
Begin
 FixedVersionInfo := TFixedVersionInfo.Create(FileName);
 Try
  Result := FixedVersionInfo.PrivateBuild;
 Finally
  FixedVersionInfo.Free;
 End;
End;

Constructor TBIOSFixedInfo.Create;
Begin
 sBIOSName := String(PChar(Ptr($FE061)));
 sBIOSCopyright := String(PChar(Ptr($FE091)));
 sBIOSDate := String(PChar(Ptr($FFFF5)));
 sBIOSExtendedInfo := String(PChar(Ptr($FEC71)));
End;

Destructor TBIOSFixedInfo.Destroy;
Begin
 Inherited;
End;

{BIOS version routines}
Function GetBIOSName: ShortString;
Var
 BIOSFixedInfo: TBIOSFixedInfo;
Begin
 BIOSFixedInfo := TBIOSFixedInfo.Create;
 Try
  Result := BIOSFixedInfo.BIOSName;
 Finally
  BIOSFixedInfo.Free;
 End;
End;

Function GetBIOSCopyright: ShortString;
Var
 BIOSFixedInfo: TBIOSFixedInfo;
Begin
 BIOSFixedInfo := TBIOSFixedInfo.Create;
 Try
  Result := BIOSFixedInfo.BIOSCopyright;
 Finally
  BIOSFixedInfo.Free;
 End;
End;

Function GetBIOSExtendedInfo: ShortString;
Var
 BIOSFixedInfo: TBIOSFixedInfo;
Begin
 BIOSFixedInfo := TBIOSFixedInfo.Create;
 Try
  Result := BIOSFixedInfo.BIOSExtendedInfo;
 Finally
  BIOSFixedInfo.Free;
 End;
End;

Function GetBIOSDate: TDateTime;
Var
 OldShortDateFormat: String;
 OldDateSeparator: Char;
 BIOSFixedInfo: TBIOSFixedInfo;
Begin
 BIOSFixedInfo := TBIOSFixedInfo.Create;
 OldShortDateFormat := ShortDateFormat;
 OldDateSeparator := DateSeparator;
 Try
  DateSeparator := '/';
  ShortDateFormat := 'm' + DateSeparator + 'd' + DateSeparator + 'y';
  Result := StrToDate(BIOSFixedInfo.BIOSDate);
 Finally
  BIOSFixedInfo.Free;
  ShortDateFormat := OldShortDateFormat;
  DateSeparator := OldDateSeparator;
 End;
End;

Function GetBIOSDateString: ShortString;
Begin
 Result := DateToStr(GetBIOSDate);
End;

{Common routines}
Function ANSISentenceCase(Const Value: String): String;
Var
 I: Integer;
Begin
 Result := ANSILowerCase(Value);
 I := 1;
 While Result[I] = ' ' Do
  Begin
   Inc(I);
  End;
 Result[I] := ANSIUpperCase(Result[I])[1];
End;

Function ANSITitleCase(Const Value: String): String;
Var
 I: Integer;
Begin
 Result := ANSILowerCase(Value);
 I := 0;
 Repeat
  Inc(I);
  If (Result[I] = ' ') Then Continue;
  Result[I] := ANSIUpperCase(Result[I])[1];
  While Result[I] <> ' ' Do
   Begin
    Inc(I);
    If I = Length(Result) Then Break;
   End;
 Until I = Length(Result);
End;

Function IsSwitchPresent(Switch: String): Boolean;
Var
 I: Integer;
Begin
 Result := False;
 Switch := ANSIUpperCase(Switch);
 For I := 1 To ParamCount Do If ANSIUpperCase(ParamStr(I)) = Switch Then Result := True;
End;

Function IntToSepStr(Value: Int64): String;
Begin
 If Value <> 0 Then
  Result := FormatFloat('#,', Value) Else
  Result := '0';
End;

Function OEMToStr(Const Value: String): String;
Var
 P: Pointer;
Begin
 P := Pointer(Value);
 OEMToChar(P, PChar(Value));
 Result := Value;
End;

Function StrToOEM(Const Value: String): String;
Var
 P: Pointer;
Begin
 P := Pointer(Value);
 CharToOEM(P, PChar(Value));
 Result := Value;
End;

Procedure FlashNotify(Handle: HWND);
Begin
 FlashWindow(Handle, True);
End;

{File routines}
Function AddSlash(Path: String): String;
Begin
 Result := Path;
 If Path[Length(Path)] <> '\' Then Result := Result + '\';
End;

Function PathOK(Path: String): Boolean;
Var
 SearchRec: TSearchRec;
Begin
 Result := False;
 If Path = '' Then Exit;
 Path := AddSlash(Path);
 Result := FindFirst(Path + '*.*', faDirectory, SearchRec) = 0;
End;

Function TruncFileName(Const FileName: String; MaxLength: Integer): String;
Var
 CommonPart: String;
 NumToCopy: Integer;
Begin
 If MaxLength >= Length(FileName) Then
  Begin
   Result := FileName;
   Exit;
  End;
 CommonPart := ExtractFileDrive(FileName) + TruncFill;
 NumToCopy := MaxLength - Length(CommonPart);
 Result := CommonPart + Copy(FileName, Length(FileName) - NumToCopy + 1, NumToCopy);
End;

Procedure ProcessFiles(AllFilesIfNoWildCard: Boolean; Recursive: Boolean;
                       Path: String; ProcessFile: ProcessFileFunction);
Var
 FullPath: String;

 Function Recurse(Recursive: Boolean; Var Path: String; Const Mask: String): Boolean;
 Var
  SRec: TSearchRec;
  RetVal: Integer;
  OldLen: Integer;
 Begin
  Recurse := True;
  OldLen := Length(Path);
  RetVal := FindFirst(Path + Mask, faAnyFile, SRec);
  While RetVal = 0 Do
   Begin
    If (SRec.Attr And (faDirectory Or faVolumeID)) = 0 Then
     If Not ProcessFile(Path + SRec.Name) Then
      Begin
       Result := False;
       Break;
      End;
     RetVal := FindNext(SRec);
   End;
  FindClose(SRec);
  If (Not Result) Or (Not Recursive) Then Exit;
  RetVal := FindFirst(Path + AllMask, faAnyFile, SRec);
  While RetVal = 0 Do
   Begin
    If (SRec.Attr And faDirectory) <> 0 Then
     If (SRec.Name <> '.') And (SRec.Name <> '..') Then
      Begin
       Path := Path + SRec.Name + '\';
       If Not Recurse(Recursive, Path, Mask) Then
        Begin
         Result := False;
         Break;
        End;
       Delete(Path, OldLen + 1, 255);
      End;
     RetVal := FindNext(SRec);
    End;
  FindClose(SRec);
 End; {Recurse}

Begin
 If Path[Length(Path)] = '\' Then
  If AllFilesIfNoWildCard Then
   Path := Path + AllMask Else Exit;
 FullPath := ExtractFilePath(Path);
 Recurse(Recursive, FullPath, ExtractFileName(Path));
End;

{System routines}
Function GetCurrentComputerName: String;
Var
 CName: PChar;
 iSize: DWORD;
begin
 iSize := MAX_COMPUTERNAME_LENGTH + 1;
 GetMem(CName, iSize);
 GetComputerName(CName, iSize);
 Result := Trim(StrPas(CName));
 FreeMem(CName);
End;

Function GetCurrentUserName: String;
Var
 UName: PChar;
 iSize: DWORD;
begin
 iSize := SizeOf(ShortString);
 GetMem(UName, iSize);
 GetUserName(UName, iSize);
 Result := Trim(StrPas(UName));
 FreeMem(UName);
End;

Function GetWinLangName: String;
Var
 WinLangName: Array[0..255] Of Char;
Begin
 VerLanguageName(GetSystemDefaultLangID, WinLangName, 255);
 Result := StrPas(WinLangName);
End;

Function GetColorBits: Integer;
Var
 H: hDC;
Begin
 H := GetDC(0);
 Try
  Result := (GetDeviceCaps(H, PLANES) * GetDeviceCaps(H, BITSPIXEL));
 Finally
  ReleaseDC(0, H);
 End;
End;

Function GetDiskSerialNumber(Disk: Char): ShortString;
Var
 VolumeSerialNumber, MaximumComponentLength, FileSystemFlags: DWORD;
Begin
 GetVolumeInformation(PChar(Disk + ':\'), Nil, 0, @VolumeSerialNumber,                       MaximumComponentLength,
                      FileSystemFlags, Nil, 0);
 Result := IntToHex(HiWord(VolumeSerialNumber), 4) +
                  '-' + IntToHex(LoWord(VolumeSerialNumber), 4);
End;

{Math routines}
Function NOD(A, B: Int64): Int64;
Begin
 While A <> B Do
  If A > B Then A := A - B Else B := B - A;
 Result := A;
End;

Function NOD(Const Args: Array Of Int64): Int64;
Var
 I: Integer;
Begin
 Result := Args[0];
 For I := 1 To High(Args) Do
  Result := NOD(NOD(Args[I-1], Args[I]), Result);
End;

Function NOK(A, B: Int64): Int64;
Begin
 Result := (A * B) Div NOD(A, B);
End;

Function NOK(Const Args: Array Of Int64): Int64;
Var
 I: Integer;
Begin
 Result := Args[0];
 For I := 1 To High(Args) Do
  Result := NOK(NOK(Args[I-1], Args[I]), Result);
End;

Initialization

Finalization

End.