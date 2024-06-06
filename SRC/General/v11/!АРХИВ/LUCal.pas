{ Календарь с возможностью выбора даты. Красивый и удобный.
  Совершенно свободно взять этот компонент (а также и многие
  другие) можно на сайте: www.chat.ru/~z_ol
  Там же есть большая книга с маленькими хитростями по Delphi,
  с ответами на многие вопросы.

  (c) Владимиров А.М. e-mail: merlin_twi@mail.ru
}

unit LUCal;
interface
uses
  SysUtils, WinTypes, WinProcs, Messages, Dialogs, Classes, Graphics, Controls,
  ExtCtrls, Forms, StdCtrls, Buttons;

Const MinSize = 155;
Type
(********************************************
 Calendar97 Component
********************************************)
  TCalendarButtonStyle = (cbNormal, cbNoBorder, cbStill, cbPush, cbClick);
  TCalendarButton = record
                      aRect  : TRect;
                      aText  : string[20];
                      aStyle : TFontStyles;
                      aColor : TColor;
                      BStyle : TCalendarButtonStyle;
                    end;
  PCalendarButton = ^TCalendarButton;
  TSelectEvent = procedure(Sender: TObject; ADate : TDate) of object;

  TCalendar97 = class(TCustomControl)
  private
    FDate, FStartDate           : TDateTime;
    FCurrentMonth, FCurrentYear : word;
    FButtons                    : TList;
    FTkRect                     : PCalendarButton;
    FOnSelect                   : TSelectEvent;
    FOnCancel                   : TNotifyEvent;
    FCaptionColor, FDateNowColor: TColor;

    procedure SetBounds(ALeft, ATop, AWidth, AHeight: Integer); override;
    procedure MouseMove(Shift: TShiftState; X, Y: Integer); override;
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState; X, Y: Integer); override;
    procedure WMSize(var message: TWMSize); message WM_SIZE;
    procedure CMMouseLeave(var Message: TMessage); message CM_MOUSELEAVE;
    procedure CMFontChanged(var Message: TMessage); message CM_FONTCHANGED;
//    procedure KeyDown(var Key: Word; Shift: TShiftState); override;

    procedure SetDate(aDate: TDateTime);
    procedure CreateButtons;
    procedure DrawButton(P  : PCalendarButton);
    procedure MouseUp(Button: TMouseButton; Shift: TShiftState; X, Y: Integer); override;
    function GetButton(X,Y : integer) : PCalendarButton;
    procedure SetCaptionColor(Value : TColor);
    procedure SetDateNowColor(Value : TColor);
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Paint; override;
  published
  {properties}
    property Align;
    property DragCursor; property DragMode;    property Enabled;
    property Color;      property Font;        property ParentColor;
    property ParentFont; property ParentShowHint;
    property PopupMenu;  property ShowHint;    property TabOrder;
    property TabStop;    property Visible;

    property Date: TDateTime read FDate write SetDate;
  {events}
    property OnEnter;
    property OnExit;
    property OnSelect : TSelectEvent read FOnSelect write FOnSelect;
    property OnCancel : TNotifyEvent read FOnCancel write FOnCancel;
    property CaptionColor : TColor read FCaptionColor write SetCaptionColor default clBlue;
    property DateNowColor : TColor read FDateNowColor write SetDateNowColor default clBlack;
  end;

procedure Register;

implementation
{-------------------------------------------------------------}
{---------------------- TCalendar 97 -------------------------}
{-------------------------------------------------------------}
function Min(i1, i2 : integer) : integer;
begin
   if i1<i2 then result:=i1 else result:=i2;
end;
function Max(i1, i2 : integer) : integer;
begin
   if i1>i2 then result:=i1 else result:=i2;
end;

constructor TCalendar97.Create(AOwner: TComponent);
var d  : word;
begin
   inherited;
   ControlStyle := ControlStyle - [csSetCaption];
   FButtons := TList.Create;
   FDate := SysUtils.Date;
   FTkRect := Nil;
   DecodeDate(FDate, FCurrentYear,FCurrentMonth,d);
   FDateNowColor := clBlack;
   FCaptionColor := clBlue;
end;

destructor TCalendar97.Destroy;
var i : integer;
begin
   for i:=0 to FButtons.Count-1 do FreeMem(FButtons[i], SizeOf(TCalendarButton));
   FButtons.Free;
   inherited;
end;

procedure TCalendar97.SetDate(aDate: TDateTime);
Var d  : word;
begin
   FDate := aDate;
   DecodeDate(FDate, FCurrentYear,FCurrentMonth,d);
   CreateButtons;
   Paint;
end;

procedure TCalendar97.SetBounds(ALeft, ATop, AWidth, AHeight: Integer);
begin
   if AWidth<MinSize then AWidth:=MinSize;
   if AHeight<MinSize then AHeight:=MinSize;
   inherited SetBounds(ALeft, ATop, AWidth, AHeight);
end;

procedure TCalendar97.WMSize(var message: TWMSize);
begin
   inherited;
   CreateButtons;
end;

procedure TCalendar97.SetCaptionColor(Value : TColor);
begin
   if FCaptionColor<>Value then begin
      FCaptionColor:=Value; CreateButtons; Paint;
   end;
end;

procedure TCalendar97.SetDateNowColor(Value : TColor);
begin
   if FDateNowColor<>Value then begin
      FDateNowColor:=Value; CreateButtons; Paint;
   end;
end;

procedure TCalendar97.CreateButtons;
Var
 P                : PCalendarButton;
 ii,i,j,x,y,dx,dy,W,H, smallH : integer;
 Year, Month, Day : word;
 Cl               : TColor;
 D                : TDateTime;
begin
   Cl:=Font.Color;
   for i:=0 to FButtons.Count-1 do FreeMem(FButtons[i], SizeOf(TCalendarButton));
   FButtons.Clear;
   W:=Width-4; H:=Height-4; x:=2; y:=2;

   // размеры ячеек
   dx:=W div 7; x:=x+((W-(dx*7)) div 2);
   smallH:=Max(H div 8, 16); dy:=(H-5-(smallH*2)) div 7;

   // Заголовок месяца
   GetMem(P, SizeOf(TCalendarButton));
   with P^ do begin
      aRect:=RECT(x+dx+1,y,Width-x-dx-1,y+smallH);
      aText:=FormatSettings.LongMonthNames[FCurrentMonth]+', '+IntToStr(FCurrentYear);
      aStyle:=[fsBold]; aColor:=FCaptionColor; bStyle:=cbNoBorder;
   end;
   FButtons.Add(P);

   // Сегодняшня дата
   GetMem(P, SizeOf(TCalendarButton));
   with P^ do begin
      aRect:=RECT(x,Height-y-smallH,Width-x-dx-1,Height-y);
      aText:='Сегодня: '+DateToStr(Now);
      aStyle:=[]; aColor:=FDateNowColor; bStyle:=cbNormal;
   end;
   FButtons.Add(P);

   // Стрелки
   GetMem(P, SizeOf(TCalendarButton));
   with P^ do begin
      aRect:=RECT(x,y,x+dx,y+smallH);
      aText:='<<'; aStyle:=[fsBold];
      aColor:=clBlack; bStyle:=cbNormal;
   end;
   FButtons.Add(P);
   GetMem(P, SizeOf(TCalendarButton));
   with P^ do begin
      aRect:=RECT(Width-x-dx,y,Width-x,y+smallH);
      aText:='>>'; aStyle:=[fsBold];
      aColor:=clBlack; bStyle:=cbNormal;
   end;
   FButtons.Add(P);
   GetMem(P, SizeOf(TCalendarButton));
   with P^ do begin
      aRect:=RECT(Width-x-dx,Height-y-smallH,Width-x,Height-y);
      aText:='X'; aStyle:=[fsBold];
      aColor:=clRed; bStyle:=cbNormal;
   end;
   FButtons.Add(P);
   inc(y, smallH+3);

   // стартовая дата
   FStartDate := EncodeDate(FCurrentYear, FCurrentMonth, 1);
   ii:=DayOfWeek(FStartDate)-1; if ii=0 then ii:=7;
   FStartDate:=FStartDate-ii+1;

   for i:=0 to 6 do begin
      for j:=0 to 6 do begin
         D:=FStartDate+j+(i-1)*7; DecodeDate(D, Year, Month, Day);
         if (i=0)or((Year=FCurrentYear)and(Month=FCurrentMonth)) then begin
            GetMem(P, SizeOf(TCalendarButton));
            with P^ do begin
               aRect:=RECT(x+j*dx, y+(i*dy), x+j*dx+dx, y+(i*dy)+dy);
               ii:=j+2; if ii>7 then dec(ii,7);
               if ii=1 then aColor:=clRed else aColor:=Cl;
               if i=0 then begin  // дни недели
                  aText:=FormatSettings.ShortDayNames[ii];
                  aStyle:=[fsBold]; bStyle:=cbStill;
               end else begin
                  aText:=IntToStr(Day); aStyle:=[];
                  if D=FDate then bStyle:=cbPush else bStyle:=cbNormal;
               end;
            end;
            FButtons.Add(P);
         end;
      end;
   end;
end;

procedure TCalendar97.DrawButton(P  : PCalendarButton);
Const Format = DT_VCenter or DT_Center or DT_SingleLine;
var R      : TRect;
    Cl     : TColor;
begin
   with P^ do begin
      //   SetBkMode(Canvas.Handle, TRANSPARENT);
      R:=aRect; Canvas.FillRect(R);
      if bStyle=cbStill then
         DrawEdge(Canvas.Handle, R, BDR_RAISEDOUTER,BF_RECT+BF_ADJUST+BF_SOFT)
      else
      if (bStyle=cbPush)or(bStyle=cbClick) then
         DrawEdge(Canvas.Handle, R, EDGE_SUNKEN,BF_RECT+BF_ADJUST);
      Canvas.Font.Style:=aStyle;
      if length(aText)<>0 then begin
         Cl:=Canvas.Font.Color;
         Canvas.Font.Color:=aColor;
         DrawText(Canvas.Handle, pchar(@aText[1]), length(aText), R,Format);
         Canvas.Font.Color:=Cl;
      end;
   end;
end;

procedure TCalendar97.Paint;
var i  : integer;
    R  : TRect;
begin
   Canvas.Font.Assign(Font);
   if FButtons.Count=0 then CreateButtons;
   inherited;
   Canvas.Brush.Color:=Color; R:=ClientRect;
   Canvas.FillRect(R);
   DrawEdge(Canvas.Handle, R, BDR_RAISEDINNER,BF_RECT);
   for i:=0 to FButtons.Count-1 do DrawButton(FButtons[i]);
   FTkRect:=Nil;
end;

function TCalendar97.GetButton(X,Y : integer) : PCalendarButton;
Var
 i    : integer;
 xy   : TPoint;
begin
   result:=Nil; xy.x:=X; xy.y:=Y;
   for i:=0 to FButtons.Count-1 do
      with PCalendarButton(FButtons[i])^ do
         if PtInRect(aRect, xy)and(bStyle in [cbNormal, cbClick])
         then result:=FButtons[i];
end;

procedure TCalendar97.MouseMove(Shift: TShiftState; X, Y: Integer);
Var P    : PCalendarButton;
begin
   P:=GetButton(X,Y);
   if (P<>FTkRect) then begin
      if FTkRect<>Nil then begin
         if FTkRect^.BStyle=cbClick then FTkRect^.BStyle:=cbNormal;
         DrawButton(FTkRect);
      end;
      FTkRect:=P;
      if FTkRect<>Nil then
         DrawEdge(Canvas.Handle, FTkRect^.aRect, EDGE_RAISED,BF_RECT);
   end;
   inherited;
end;

procedure TCalendar97.CMMouseLeave(var Message: TMessage);
begin
   if FTkRect<>Nil then begin
      if FTkRect^.BStyle=cbClick then FTkRect^.BStyle:=cbNormal;
      DrawButton(FTkRect);
   end;
   FTkRect:=Nil;
   inherited;
end;

procedure TCalendar97.MouseDown;
begin
   if Button=mbRight then begin
      if Assigned(FOnCancel) then FOnCancel(Self);
   end else
      if FTkRect<>Nil then begin
         FTkRect^.BStyle:=cbClick; DrawButton(FTkRect);
      end;
   inherited;
end;

procedure TCalendar97.MouseUp;
Var D  : TDateTime;
    i  : word;
begin
   if FTkRect<>Nil then
      with FTkRect^ do
         if aText<>'' then begin
            case aText[1] of
            'X': if Assigned(FOnCancel) then FOnCancel(Self);
            '<': begin
                 D:=EncodeDate(FCurrentYear, FCurrentMonth, 1)-1;
                 DecodeDate(D, FCurrentYear, FCurrentMonth, i);
                 CreateButtons;
            end;
            '>': begin
                 D:=EncodeDate(FCurrentYear, FCurrentMonth, 28)+5;
                 DecodeDate(D, FCurrentYear, FCurrentMonth, i);
                 CreateButtons;
            end;
            'С': begin
                 FDate:=SysUtils.Date;
                 DecodeDate(FDate, FCurrentYear, FCurrentMonth, i);
                 CreateButtons;
                 if Assigned(FOnSelect) then FOnSelect(Self, FDate);
            end;
            else begin
               FDate:=EncodeDate(FCurrentYear, FCurrentMonth, StrToInt(aText));
               CreateButtons;
               if Assigned(FOnSelect) then FOnSelect(Self, FDate);
            end;
            end;
            Paint;
            MouseMove(Shift,X,Y);
         end;
   inherited;
end;

procedure TCalendar97.CMFontChanged(var Message: TMessage);
begin
   CreateButtons;
   inherited;
end;

procedure Register;
begin
   RegisterComponents('LUIS', [TCalendar97]);
end;

end.
