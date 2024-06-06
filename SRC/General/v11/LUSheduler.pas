(*
 =======================================================
 Copyright (c) 2023
 Author:
     Lisitsin Y.R.
 Project:
     LU_PAS
     Delphi VCL Extensions (LU)
 Module:
     LUSheduler
     Sheduler
 =======================================================
*)

unit LUSheduler;

interface

uses Classes, ExtCtrls, SysUtils, LUSupport, StrUtils, LUStrUtils, DateUtils;

type
  TCharSet = set of AnsiChar;

  const
   minNN = 0; maxNN = 59;
   minHH = 0; maxHH = 23;
   minDW = 1; maxDW = 7;
   minMM = 1; maxMM = 12;
   minDD = 1; maxDD = 31;
   DelimPattern: TCharSet = [' '];
   DelimItem: TCharSet = [','];
   DelimItems: TCharSet = ['-'];

type
   TNotifyFileEvent = procedure (Sender: TObject) of object;

type
   TShedulerEvent = class (TCollectionItem)
   private
    { Private declarations }
      FDD: Longint;
      FMM: Longint;
      FDW: Longint;
      FHH: Longint;
      FNN1: Longint;
      FNN2: Longint;
      FList: TStringList;
      FNameEvent: PChar;
      function GetNameEvent: string;
      procedure SetNameEvent (const Value: string);
      function GetDD (Index: Integer): Boolean;
      procedure SetDD (Index: Integer; Value: Boolean);
      function GetMM (Index: Integer): Boolean;
      procedure SetMM (Index: Integer; Value: Boolean);
      function GetDW (Index: Integer): Boolean;
      procedure SetDW (Index: Integer; Value: Boolean);
      function GetHH (Index: Integer): Boolean;
      procedure SetHH (Index: Integer; Value: Boolean);
      function GetNN (Index: Integer): Boolean;
      procedure SetNN (Index: Integer; Value: Boolean);
      procedure CreateList (const Pattern: string; min, max: Integer);
      procedure NewPatterns (const Patterns: string);
      procedure AddPatterns (const Patterns: string);
      function GetXXString (XXName: string): string;
   protected
    { Protected declarations }
      property DD [Index: Integer]: Boolean read GetDD write SetDD;
      property MM [Index: Integer]: Boolean read GetMM write SetMM;
      property DW [Index: Integer]: Boolean read GetDW write SetDW;
      property HH [Index: Integer]: Boolean read GetHH write SetHH;
      property NN [Index: Integer]: Boolean read GetNN write SetNN;
   public
    { Public declarations }
      constructor Create (Collection: TCollection); override;
      destructor Destroy; override;
      property XXString[XXName: string]: string read GetXXString;
      property NameEvent: string read GetNameEvent write SetNameEvent;
   published
    { Published declarations }
   end;

type
   TSheduler = class (TTimer)
   private
      FOnSheduler: TNotifyFileEvent;
      FShedulerEvents: TCollection;
      FNameEvents: TStringList;
      FDTEvents: TDateTime;
      FEnable: Boolean;
      procedure Second (Sender: TObject);
      function GetNameEvents: TStringList;
      function GetShedulerEvent(NameEvent: string): TShedulerEvent;
   protected
      property ShedulerEvents: TCollection read FShedulerEvents;
      procedure CreateNextEvent (Present: TDateTime);
   public
    { Public declarations }
      constructor Create (AOwner: TComponent); override;
      destructor Destroy; override;
      function CreateShedulerEvent: TShedulerEvent;
      procedure AddEvent (const ANameEvent, APatterns: string);
      procedure DeleteEvent (const ANameEvent: string);
      property ShedulerEvent[NameEvent: string]: TShedulerEvent read GetShedulerEvent;
   published
    { Published declarations }
      property OnSheduler: TNotifyFileEvent read FOnSheduler write FOnSheduler;
      property NameEvents: TStringList read GetNameEvents;
      property DTEvents: TDateTime read FDTEvents;
      property Enable: Boolean read FEnable write FEnable;
   end;

procedure Register;

implementation
(*
------------------------------------------------------------------
 NN-NN    HH-HH     DD-DD     MM-MM     DW-DW     [Program]
 NN,NN,.. HH,HH,... DD,DD,... MM,MM,... DW,DW,... [Program]
 *        *         *         *         *         [Program]
------------------------------------------------------------------
*)

function IsBitOn (Value: Longint; Bit: Byte): Boolean;
begin
   Result := (Value and (1 shl Bit)) <> 0;
end;

function TurnBitOn (Value: Longint; Bit: Byte): Longint;
begin
   Result := Value or (1 shl Bit);
end;

function TurnBitOff (Value: Longint; Bit: Byte): Longint;
begin
   Result := Value and not (1 shl Bit);
end;

{ TShedulerEvent }

constructor TShedulerEvent.Create (Collection: TCollection);
begin
   inherited Create (Collection);
   NameEvent := '';
   FList := TStringList.Create;
   FDD := 0;
   FMM := 0;
   FDW := 0;
   FHH := 0;
   FNN1 := 0;
   FNN2 := 0;
end;

destructor TShedulerEvent.Destroy;
begin
   FList.Free;
   StrDispose (FNameEvent);
   inherited Destroy;
end;

function TShedulerEvent.GetNameEvent: string;
begin
   try
      Result := StrPas (FNameEvent);
   except
      Result := '';
   end;
end;

procedure TShedulerEvent.SetNameEvent (const Value: string);
begin
   if FNameEvent <> nil then StrDispose (FNameEvent);
   FNameEvent := StrAlloc (Length (Value) + 1);
   StrPCopy (FNameEvent, Value);
end;

function TShedulerEvent.GetDD (Index: Integer): Boolean;
begin
   Result := False;
   if (index >= minDD) and (Index <= maxDD) then Result := IsBitOn (FDD, Index);
end;

procedure TShedulerEvent.SetDD (Index: Integer; Value: Boolean);
begin
   if (index >= minDD) and (Index <= maxDD) then begin
      if Value then FDD := TurnBitOn (FDD, Index)
      else FDD := TurnBitOff (FDD, Index);
   end;
end;

function TShedulerEvent.GetMM (Index: Integer): Boolean;
begin
   Result := False;
   if (index >= minMM) and (Index <= maxMM) then Result := IsBitOn (FMM, Index);
end;

procedure TShedulerEvent.SetMM (Index: Integer; Value: Boolean);
begin
   if (index >= minMM) and (Index <= maxMM) then begin
      if Value then FMM := TurnBitOn (FMM, Index)
      else FMM := TurnBitOff (FMM, Index);
   end;
end;

function TShedulerEvent.GetDW (Index: Integer): Boolean;
begin
   Result := False;
   if (index >= minDW) and (Index <= maxDW) then Result := IsBitOn (FDW, Index);
end;

procedure TShedulerEvent.SetDW (Index: Integer; Value: Boolean);
begin
   if (index >= minDW) and (Index <= maxDW) then begin
      if Value then FDW := TurnBitOn (FDW, Index)
      else FDW := TurnBitOff (FDW, Index);
   end;
end;

function TShedulerEvent.GetHH (Index: Integer): Boolean;
begin
   Result := False;
   if (index >= minHH) and (Index <= maxHH) then Result := IsBitOn (FHH, Index);
end;

procedure TShedulerEvent.SetHH (Index: Integer; Value: Boolean);
begin
   if (index >= minHH) and (Index <= maxHH) then begin
      if Value then FHH := TurnBitOn (FHH, Index)
      else FHH := TurnBitOff (FHH, Index);
   end;
end;

function TShedulerEvent.GetNN (Index: Integer): Boolean;
begin
   Result := False;
   if (index >= minNN) and (Index <= maxNN) then begin
      if (Index <= 31) then Result := IsBitOn (FNN1, Index)
      else Result := IsBitOn (FNN2, Index - 32);
   end;
end;

procedure TShedulerEvent.SetNN (Index: Integer; Value: Boolean);
begin
   if (index >= minNN) and (Index <= maxNN) then begin
      if (Index <= 31) then begin
         if Value then FNN1 := TurnBitOn (FNN1, Index)
         else FNN1 := TurnBitOff (FNN1, Index);
      end
      else begin
         if Value then FNN2 := TurnBitOn (FNN2, Index - 32)
         else FNN2 := TurnBitOff (FNN2, Index - 32);
      end;
   end;
end;

function TShedulerEvent.GetXXString (XXName: string): string;
var
   i: Integer;
begin
   Result := '';
   for i:=0 to 31 do begin
      if UpperCase(XXName) = 'DD' then if DD[i] then Result := Result+AddChar(' ',IntToStr(i),2)+',';
      if UpperCase(XXName) = 'MM' then if MM[i] then Result := Result+AddChar(' ',IntToStr(i),2)+',';
      if UpperCase(XXName) = 'DW' then if DW[i] then Result := Result+AddChar(' ',IntToStr(i),2)+',';
      if UpperCase(XXName) = 'HH' then if HH[i] then Result := Result+AddChar(' ',IntToStr(i),2)+',';
      if UpperCase(XXName) = 'NN' then if NN[i] then Result := Result+AddChar(' ',IntToStr(i),2)+',';
   end;
   Delete(Result,Length(Result),1);
end;

procedure TShedulerEvent.CreateList (const Pattern: string; min, max: Integer);
var
   i, j, WCount, i11, i12: Integer;
   S1, S11, S12: string;
begin
   FList.Clear;
   if (Pattern = '*') then for j:=min to max do FList.Add (IntToStr (j))
   else begin
      WCount := WordCount (Pattern, DelimItem, False);
      for i := 1 to WCount do begin
         s1 := ExtractWord (i, Pattern, DelimItem, False);
         s11 := ExtractWord (1, S1, DelimItems, False);
         s12 := ExtractWord (2, S1, DelimItems, False);
         try
            i11 := StrToInt (s11);
            if i11 > max then i11 := max;
         except
            i11 := -1;
         end;
         try
            i12 := StrToInt (s12);
            if i12 > max then i12 := max;
         except
            i12 := i11;
         end;
         for j := i11 to i12 do FList.Add (IntToStr (j));
      end;
   end;
end;

procedure TShedulerEvent.NewPatterns (const Patterns: string);
begin
   FDD := 0;
   FMM := 0;
   FDW := 0;
   FHH := 0;
   FNN1 := 0;
   FNN2 := 0;
   AddPatterns (Patterns);
end;

procedure TShedulerEvent.AddPatterns (const Patterns: string);
var
   i: Integer;
begin
   { NN }
   CreateList (ExtractWordNew (1, Patterns, DelimPattern), minNN, maxNN);
   for i:=0 to FList.Count-1 do NN[StrToInt(FList.Strings [i])] := True;
   { HH }
   CreateList (ExtractWordNew (2, Patterns, DelimPattern), minHH, maxHH);
   for i:=0 to FList.Count-1 do HH[StrToInt(FList.Strings [i])] := True;
   { DD }
   CreateList (ExtractWordNew (3, Patterns, DelimPattern), minDD, maxDD);
   for i:=0 to FList.Count-1 do DD[StrToInt(FList.Strings [i])] := True;
   { MM }
   CreateList (ExtractWordNew (4, Patterns, DelimPattern), minMM, maxMM);
   for i:=0 to FList.Count-1 do MM[StrToInt(FList.Strings [i])] := True;
   { DW }
   CreateList (ExtractWordNew (5, Patterns, DelimPattern), minDW, maxDW);
   for i:=0 to FList.Count-1 do DW[StrToInt(FList.Strings [i])] := True;
end;

{ TSheduler }

constructor TSheduler.Create (AOwner: TComponent);
begin
   inherited Create (AOwner);
   Interval := 1000;
   OnSheduler := nil;
   OnTimer := Second;
   FShedulerEvents := TCollection.Create (TShedulerEvent);
   FNameEvents := TStringList.Create;
   FEnable := True;
end;

destructor TSheduler.Destroy;
begin
   FShedulerEvents.Free;
   FNameEvents.Free;
   inherited Destroy;
end;

procedure TSheduler.Second (Sender: TObject);
var
   Present: TDateTime;
   Year, Month, Day, DayWeek, Hour, Min, Sec, MSec: Word;
   i: Integer;
   Event: TShedulerEvent;
begin
   if FEnable then begin
      Present := Now;
      DecodeTime (Present, Hour, Min, Sec, MSec);
      { Check List Sheduler }
      if Sec = 0 then begin
         DecodeDate (Present, Year, Month, Day);
         DayWeek := DayOfWeek (Present);
         Dec(DayWeek); if DayWeek = 0 then DayWeek := 7;
         for i:=0 to ShedulerEvents.Count-1 do begin
            Event := TShedulerEvent (ShedulerEvents.Items [i]);
            if (Event.DD [Day] or Event.DW [DayWeek]) and Event.MM [Month] and Event.HH [Hour] and Event.NN [Min] then begin
               if Assigned (FOnSheduler) then FOnSheduler (Event);
            end;
         end;
      end;
   end;
end;

procedure TSheduler.CreateNextEvent (Present: TDateTime);
var
   Year, Month, Day, DayWeek, Hour, Min, Sec, MSec: Word;
   i: Integer;
   Event: TShedulerEvent;
   D, T: TDateTime;
   maxDDWork: Integer;
begin
   DecodeDate (Present, Year, Month, Day);
   DecodeTime (Present, Hour, Min, Sec, MSec);
   Inc (Min);
   FNameEvents.Clear;
   { Year }
   for Year:=Year to Year+1 do begin
      { Month }
      for Month:=Month to maxMM do begin
         MaxDDWork := DateUtils.DaysInMonth (Present);
         { Day of Month }
         for Day:=Day to maxDDWork do begin
            DayWeek := DayOfWeek (EncodeDate(Year,Month,Day));
            Dec(DayWeek); if DayWeek = 0 then DayWeek := 7;
            { Hour }
            for Hour:=Hour to maxHH do begin
               { Min }
               for Min:=Min to maxNN do begin
                  { Check List Sheduler }
                  for i:=0 to ShedulerEvents.Count-1 do begin
                     Event := TShedulerEvent (ShedulerEvents.Items [i]);
                     if (Event.DD [Day] and Event.DW [DayWeek]) and
                        Event.MM [Month] and Event.HH [Hour] and Event.NN [Min] then begin
                        FNameEvents.Add (Event.NameEvent);
                     end;
                  end;
                  if FNameEvents.Count > 0 then break;
               end;
               if FNameEvents.Count = 0 then Min := MinNN else break;
            end;
            if FNameEvents.Count = 0 then Hour := MinHH else break;
         end;
         if FNameEvents.Count = 0 then Day := MinDD else break;
      end;
      if FNameEvents.Count = 0 then Month := MinMM else break;
   end;
   if FNameEvents.Count > 0 then begin
      D := EncodeDate (Year, Month, Day);
      T := EncodeTime (Hour, Min, 0, 0);
      FDTEvents := D + T;
   end
   else begin
      FDTEvents := Present;
   end;
end;

function TSheduler.GetNameEvents: TStringList;
begin
   CreateNextEvent (Now);
   Result := FNameEvents;
end;

function TSheduler.CreateShedulerEvent: TShedulerEvent;
begin
   Result := TShedulerEvent (ShedulerEvents.Add);
end;

procedure TSheduler.AddEvent (const ANameEvent, APatterns: string);
var
   i: Integer;
   Event: TShedulerEvent;
begin
   i := 0;
   Event := nil;
   while (i < ShedulerEvents.Count) and (Event.NameEvent <> ANameEvent) do begin
      Event := TShedulerEvent (ShedulerEvents.Items [i]);
      Inc (i);
   end;
   if (Event.NameEvent = ANameEvent) then Event.AddPatterns (APatterns)
   else begin
      with CreateShedulerEvent do begin
         NameEvent := ANameEvent;
         NewPatterns (APatterns);
      end;
   end;
end;

procedure TSheduler.DeleteEvent (const ANameEvent: string);
var
   Event: TShedulerEvent;
begin
   Event := ShedulerEvent[ANameEvent];
   if Assigned(Event) then Event.Free;
end;

function TSheduler.GetShedulerEvent(NameEvent: string): TShedulerEvent;
var
   i: Integer;
begin
   Result := nil;
   for i:=0 to ShedulerEvents.Count-1 do begin
      Result := TShedulerEvent (ShedulerEvents.Items [i]);
      if Result.NameEvent = NameEvent then Break
                                      else Result := nil;
   end;
end;

{ This procedure is used to register this component on the component palette }

procedure Register;
begin
   RegisterComponents('Luis', [TSheduler]);
end;

end.
