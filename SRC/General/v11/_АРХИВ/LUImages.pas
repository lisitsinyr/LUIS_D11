unit LUImages;

interface

uses
  Windows, Graphics, ImgList, Math;

type
  TResamplingFilter = (rfBox, rfTriangle, rfHermite, rfBell, rfSpline,
    rfLanczos3, rfMitchell);

procedure Stretch(NewWidth, NewHeight: Cardinal; Filter: TResamplingFilter;
  Radius: Single; Source: TGraphic; Target: TBitmap);

implementation

threadvar
  // globally used cache for current image (speeds up resampling about 10%)
  CurrentLineR: array of Integer;
  CurrentLineG: array of Integer;
  CurrentLineB: array of Integer;

type
  TRGBInt = record
    R: Integer;
    G: Integer;
    B: Integer;
  end;

  PBGR = ^TBGR;
  TBGR = packed record
    B: Byte;
    G: Byte;
    R: Byte;
  end;

  PPixelArray = ^TPixelArray;
  TPixelArray = array [0..0] of TBGR;

  TBitmapFilterFunction = function (Value: Single): Single;

  PContributor = ^TContributor;
  TContributor = record
   Weight: Integer; // Pixel Weight
   Pixel: Integer;  // Source Pixel
  end;

  TContributors = array of TContributor;
  // list of source pixels contributing to a destination pixel
  TContributorEntry = record
   N: Integer;
   Contributors: TContributors;
  end;

  TContributorList = array of TContributorEntry;

const
  DefaultFilterRadius: array [TResamplingFilter] of Single =
    (0.5, 1.0, 1.0, 1.5, 2.0, 3.0, 2.0);

//==================================================================================================
// Filter functions for stretching of TBitmaps
//==================================================================================================

// f(t) = 2|t|^3 - 3|t|^2 + 1, -1 <= t <= 1

function BitmapHermiteFilter(Value: Single): Single;
begin
  if Value < 0.0 then
    Value := -Value;
  if Value < 1 then
    Result := (2 * Value - 3) * Sqr(Value) + 1
  else
    Result := 0;
end;

//--------------------------------------------------------------------------------------------------

function BitmapBoxFilter(Value: Single): Single;
// This filter is also known as 'nearest neighbour' Filter.
begin
  if (Value > -0.5) and (Value <= 0.5) then
    Result := 1.0
  else
    Result := 0.0;
end;

//--------------------------------------------------------------------------------------------------

// aka 'linear' or 'bilinear' filter

function BitmapTriangleFilter(Value: Single): Single;
begin
  if Value < 0.0 then
    Value := -Value;
  if Value < 1.0 then
    Result := 1.0 - Value
  else
    Result := 0.0;
end;

//--------------------------------------------------------------------------------------------------

function BitmapBellFilter(Value: Single): Single;
begin
  if Value < 0.0 then
    Value := -Value;
  if Value < 0.5 then
    Result := 0.75 - Sqr(Value)
  else
    if Value < 1.5 then
    begin
      Value := Value - 1.5;
      Result := 0.5 * Sqr(Value);
    end
    else
      Result := 0.0;
end;

//--------------------------------------------------------------------------------------------------

// B-spline filter

function BitmapSplineFilter(Value: Single): Single;
var
  Temp: Single;
begin
  if Value < 0.0 then
    Value := -Value;
  if Value < 1.0 then
  begin
    Temp := Sqr(Value);
    Result := 0.5 * Temp * Value - Temp + 2.0 / 3.0;
  end
  else
    if Value < 2.0 then
    begin
      Value := 2.0 - Value;
      Result := Sqr(Value) * Value / 6.0;
    end
    else
      Result := 0.0;
end;

//--------------------------------------------------------------------------------------------------

function BitmapLanczos3Filter(Value: Single): Single;

  function SinC(Value: Single): Single;
  begin
    if Value <> 0.0 then
    begin
      Value := Value * Pi;
      Result := System.Sin(Value) / Value;
    end
    else
      Result := 1.0;
  end;

begin
  if Value < 0.0 then
    Value := -Value;
  if Value < 3.0 then
    Result := SinC(Value) * SinC(Value / 3.0)
  else
    Result := 0.0;
end;

//--------------------------------------------------------------------------------------------------

function BitmapMitchellFilter(Value: Single): Single;
const
  B = 1.0 / 3.0;
  C = 1.0 / 3.0;
var
  Temp: Single;
begin
  if Value < 0.0 then
    Value := -Value;
  Temp := Sqr(Value);
  if Value < 1.0 then
  begin
    Value := (((12.0 - 9.0 * B - 6.0 * C) * (Value * Temp))
             + ((-18.0 + 12.0 * B + 6.0 * C) * Temp)
             + (6.0 - 2.0 * B));
    Result := Value / 6.0;
  end
  else
    if Value < 2.0 then
    begin
      Value := (((-B - 6.0 * C) * (Value * Temp))
               + ((6.0 * B + 30.0 * C) * Temp)
               + ((-12.0 * B - 48.0 * C) * Value)
               + (8.0 * B + 24.0 * C));
      Result := Value / 6.0;
    end
    else
      Result := 0.0;
end;


const
  FilterList: array [TResamplingFilter] of TBitmapFilterFunction = (
    BitmapBoxFilter,
    BitmapTriangleFilter,
    BitmapHermiteFilter,
    BitmapBellFilter,
    BitmapSplineFilter,
    BitmapLanczos3Filter,
    BitmapMitchellFilter
  );

function IntToByte(Value: Integer): Byte;
begin
  Result := Math.Max(0, Math.Min(255, Value));
end;

function ApplyContributors(N: Integer; Contributors: TContributors): TBGR;
var
  J: Integer;
  RGB: TRGBInt;
  Total,
  Weight: Integer;
  Pixel: Cardinal;
  Contr: ^TContributor;
begin
  RGB.R := 0;
  RGB.G := 0;
  RGB.B := 0;
  Total := 0;
  Contr := @Contributors[0];
  for J := 0 to N - 1 do
  begin
    Weight := Contr.Weight;
    Inc(Total, Weight);
    Pixel := Contr.Pixel;
    Inc(RGB.R, CurrentLineR[Pixel] * Weight);
    Inc(RGB.G, CurrentLineG[Pixel] * Weight);
    Inc(RGB.B, CurrentLineB[Pixel] * Weight);
    Inc(Contr);
  end;

  if Total = 0 then
  begin
    Result.R := IntToByte(RGB.R shr 8);
    Result.G := IntToByte(RGB.G shr 8);
    Result.B := IntToByte(RGB.B shr 8);
  end
  else
  begin
    Result.R := IntToByte(RGB.R div Total);
    Result.G := IntToByte(RGB.G div Total);
    Result.B := IntToByte(RGB.B div Total);
  end;
end;

procedure FillLineCache(N, Delta: Integer; Line: Pointer);
var
  I: Integer;
  Run: PBGR;
begin
  Run := Line;
  for I := 0 to N - 1 do
  begin
    CurrentLineR[I] := Run.R;
    CurrentLineG[I] := Run.G;
    CurrentLineB[I] := Run.B;
    Inc(PByte(Run), Delta);
  end;
end;

procedure DoStretch(Filter: TBitmapFilterFunction; Radius: Single; Source, Target: TBitmap);
var
  ScaleX, ScaleY: Single; // Zoom scale factors
  I, J, K, N: Integer;    // Loop variables
  Center: Single;         // Filter calculation variables
  Width: Single;
  Weight: Integer;        // Filter calculation variables
  Left, Right: Integer;   // Filter calculation variables
  Work: TBitmap;
  ContributorList: TContributorList;
  SourceLine, DestLine: PPixelArray;
  DestPixel: PBGR;
  Delta, DestDelta: Integer;
  SourceHeight, SourceWidth: Integer;
  TargetHeight, TargetWidth: Integer;
begin
  // shortcut variables
  SourceHeight := Source.Height;
  SourceWidth := Source.Width;
  TargetHeight := Target.Height;
  TargetWidth := Target.Width;
  // create intermediate image to hold horizontal zoom
  Work := TBitmap.Create;
  try
    Work.PixelFormat := pf24Bit;
    Work.Height := SourceHeight;
    Work.Width := TargetWidth;
    if SourceWidth = 1 then
      ScaleX := TargetWidth / SourceWidth
    else
      ScaleX := (TargetWidth - 1) / (SourceWidth - 1);
    if SourceHeight = 1 then
      ScaleY := TargetHeight / SourceHeight
    else
      ScaleY := (TargetHeight - 1) / (SourceHeight - 1);

    // pre-calculate filter contributions for a row
    SetLength(ContributorList, TargetWidth);
    // horizontal sub-sampling
    if ScaleX < 1 then
    begin
      // scales from bigger to smaller Width
      Width := Radius / ScaleX;
      for I := 0 to TargetWidth - 1 do
      begin
        ContributorList[I].N := 0;
        Center := I / ScaleX;
        Left := Math.Floor(Center - Width);
        Right := Math.Ceil(Center + Width);
        SetLength(ContributorList[I].Contributors, Right - Left + 1);
        for J := Left to Right do
        begin
          Weight := Round(Filter((Center - J) * ScaleX) * ScaleX * 256);
          if Weight <> 0 then
          begin
            if J < 0 then
              N := -J
            else
              if J >= SourceWidth then
                N := SourceWidth - J + SourceWidth - 1
              else
                N := J;
            K := ContributorList[I].N;
            Inc(ContributorList[I].N);
            ContributorList[I].Contributors[K].Pixel := N;
            ContributorList[I].Contributors[K].Weight := Weight;
          end;
        end;
      end;
    end
    else
    begin
      // horizontal super-sampling
      // scales from smaller to bigger Width
      for I := 0 to TargetWidth - 1 do
      begin
        ContributorList[I].N := 0;
        Center := I / ScaleX;
        Left := Math.Floor(Center - Radius);
        Right := Math.Ceil(Center + Radius);
        SetLength(ContributorList[I].Contributors, Right - Left + 1);
        for J := Left to Right do
        begin
          Weight := Round(Filter(Center - J) * 256);
          if Weight <> 0 then
          begin
            if J < 0 then
              N := -J
            else
              if J >= SourceWidth then
                N := SourceWidth - J + SourceWidth - 1
              else
                N := J;
            K := ContributorList[I].N;
            Inc(ContributorList[I].N);
            ContributorList[I].Contributors[K].Pixel := N;
            ContributorList[I].Contributors[K].Weight := Weight;
          end;
        end;
      end;
    end;

    // now apply filter to sample horizontally from Src to Work

    SetLength(CurrentLineR, SourceWidth);
    SetLength(CurrentLineG, SourceWidth);
    SetLength(CurrentLineB, SourceWidth);
    for K := 0 to SourceHeight - 1 do
    begin
      SourceLine := Source.ScanLine[K];
      FillLineCache(SourceWidth, 3, SourceLine);
      DestPixel := Work.ScanLine[K];
      for I := 0 to TargetWidth - 1 do
        with ContributorList[I] do
        begin
          DestPixel^ := ApplyContributors(N, ContributorList[I].Contributors);
          // move on to next column
          Inc(DestPixel);
        end;
    end;

    // free the memory allocated for horizontal filter weights, since we need
    // the structure again
    for I := 0 to TargetWidth - 1 do
      ContributorList[I].Contributors := nil;
    ContributorList := nil;

    // pre-calculate filter contributions for a column
    SetLength(ContributorList, TargetHeight);
    // vertical sub-sampling
    if ScaleY < 1 then
    begin
      // scales from bigger to smaller height
      Width := Radius / ScaleY;
      for I := 0 to TargetHeight - 1 do
      begin
        ContributorList[I].N := 0;
        Center := I / ScaleY;
        Left := Math.Floor(Center - Width);
        Right := Math.Ceil(Center + Width);
        SetLength(ContributorList[I].Contributors, Right - Left + 1);
        for J := Left to Right do
        begin
          Weight := Round(Filter((Center - J) * ScaleY) * ScaleY * 256);
          if Weight <> 0 then
          begin
            if J < 0 then
              N := -J
            else
              if J >= SourceHeight then
                N := SourceHeight - J + SourceHeight - 1
              else
                N := J;
            K := ContributorList[I].N;
            Inc(ContributorList[I].N);
            ContributorList[I].Contributors[K].Pixel := N;
            ContributorList[I].Contributors[K].Weight := Weight;
          end;
        end;
      end;
    end
    else
    begin
      // vertical super-sampling
      // scales from smaller to bigger height
      for I := 0 to TargetHeight - 1 do
      begin
        ContributorList[I].N := 0;
        Center := I / ScaleY;
        Left := Math.Floor(Center - Radius);
        Right := Math.Ceil(Center + Radius);
        SetLength(ContributorList[I].Contributors, Right - Left + 1);
        for J := Left to Right do
        begin
          Weight := Round(Filter(Center - J) * 256);
          if Weight <> 0 then
          begin
            if J < 0 then
              N := -J
            else
            if J >= SourceHeight then
              N := SourceHeight - J + SourceHeight - 1
            else
              N := J;
            K := ContributorList[I].N;
            Inc(ContributorList[I].N);
            ContributorList[I].Contributors[K].Pixel := N;
            ContributorList[I].Contributors[K].Weight := Weight;
          end;
        end;
      end;
    end;

    // apply filter to sample vertically from Work to Target
    SetLength(CurrentLineR, SourceHeight);
    SetLength(CurrentLineG, SourceHeight);
    SetLength(CurrentLineB, SourceHeight);

    SourceLine := Work.ScanLine[0];
    Delta := Integer(Work.ScanLine[1]) - Integer(SourceLine);
    DestLine := Target.ScanLine[0];
    DestDelta := Integer(Target.ScanLine[1]) - Integer(DestLine);
    for K := 0 to TargetWidth - 1 do
    begin
      DestPixel := Pointer(DestLine);
      FillLineCache(SourceHeight, Delta, SourceLine);
      for I := 0 to TargetHeight - 1 do
        with ContributorList[I] do
        begin
          DestPixel^ := ApplyContributors(N, ContributorList[I].Contributors);
          Inc(Integer(DestPixel), DestDelta);
        end;
      Inc(SourceLine);
      Inc(DestLine);
    end;

    // free the memory allocated for vertical filter weights
    for I := 0 to TargetHeight - 1 do
      ContributorList[I].Contributors := nil;
    // this one is done automatically on exit, but is here for completeness
    ContributorList := nil;

  finally
    Work.Free;
    CurrentLineR := nil;
    CurrentLineG := nil;
    CurrentLineB := nil;
  end;
end;

procedure Stretch(NewWidth, NewHeight: Cardinal; Filter: TResamplingFilter;
  Radius: Single; Source: TGraphic; Target: TBitmap);
var
  Temp: TBitmap;
begin
  if Radius = 0 then
    Radius := DefaultFilterRadius[Filter];

  Temp := TBitmap.Create;
  try
    // To allow Source = Target, the following assignment needs to be done initially
    Temp.Assign(Source);
    Temp.PixelFormat := pf24Bit;

    Target.FreeImage;
    Target.PixelFormat := pf24Bit;
    Target.Width := NewWidth;
    Target.Height := NewHeight;

    DoStretch(FilterList[Filter], Radius, Temp, Target);
  finally
    Temp.Free;
  end;
end;

end.
