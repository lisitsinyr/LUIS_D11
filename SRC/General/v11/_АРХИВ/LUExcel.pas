{=======================================================}
{ Project:                                              }
{         Delphi VCL Extensions (LU)                    }
{         Copyright (c) 2000 Central Bank Of Russia     }
{ Subject:                                              }
{         Работа с Excel                                }
{ Author:                                               }
{         Lisitsin Y.R.                                 }
{=======================================================}

{
Application
   WorkBooks
      WorkBook
         Sheets
         WorkSheets
            WorkSheet
               Cells (Range)
               Columns (Range)
               Rows (Range)
         Charts
}

unit LUExcel;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  ComObj, Excel97, OleServer;

type
   TLUExcel = class(TComponent)
   private
      FExcelApplication: OleVariant;
      function GetVisible(Source: OleVariant): OleVariant;
      procedure SetVisible(Source: OleVariant; Value: OleVariant);
      { WorkBooks }
      function GetWorkBooks: OleVariant;
      { WorkSheets }
      function GetWorkSheets(Source: OleVariant): OleVariant;
      { Sheets }
      function GetSheets(Source: OleVariant): OleVariant;
      //function GetWorkBook (N: Integer): OleVariant;

      { Columns }
      { Result.ColumnWidth }
      { Result.Font }
      function GetColumns (Source: OleVariant): OleVariant;
      function GetRows (Source: OleVariant): OleVariant;
      { GetRange }
      { Result.Formula }
      { Result.Columns }
      { Result.Borders }
      function GetRange (Source: OleVariant; Cell1,Cell2: OleVariant): OleVariant; overload;
      function GetCells (Source: OleVariant): OleVariant;
      function GetCell (Source: OleVariant; Row,Column: Longint): OleVariant;
      procedure SetCell (Source: OleVariant; Row,Column: Longint; Value: OleVariant);
      function GetLastCell (Source: OleVariant): OleVariant;
      function GetFirstCell (Source: OleVariant): OleVariant;
      function GetActiveWorkBook: OleVariant;
      function GetActiveSheet (Source: Olevariant): OleVariant;
      function GetSheet (Source: Olevariant; Index: OleVariant): OleVariant;
      function GetWorkSheet (Source: Olevariant; Index: OleVariant): OleVariant;
      function GetWorkBook (Index: OleVariant): OleVariant;
    protected
    public
       constructor Create (AOwner: TComponent); override;
       destructor Destroy; override;
       {======================================================================}
       { ExcelApplication }
       procedure StartExcel(AVisible: Boolean);
       procedure StopExcel;
       procedure AutofitColumns;
       procedure AutofitRange(Source: Olevariant);
       { WorkBook }
       function OpenWorkBook (const FileName: string): OleVariant;
       procedure SaveAsWorkBook (WorkBook: OleVariant; const FileName: string);
       procedure SaveWorkBook (WorkBook: OleVariant);
       {
         xlWBATChart = $FFFFEFF3;
         xlWBATLUExcel4IntlMacroSheet = $00000004;
         xlWBATLUExcel4MacroSheet = $00000003;
         xlWBATWorksheet = $FFFFEFB9;
       }
       function NewWorkBook (WBATemplate: Cardinal{XlWBATemplate}): OleVariant;
       {
          xlChart = $FFFFEFF3;
          xlDialogSheet = $FFFFEFEC;
          xlExcel4IntlMacroSheet = $00000004;
          xlExcel4MacroSheet = $00000003;
          xlWorksheet = $FFFFEFB9;
       }
       procedure NewSheet (Source: Olevariant; SheetType: Cardinal{XlSheetType}; NameSheets: array of string);
       procedure SetFormula(Cell: OLEVariant; const Formula: string);
       function GetRangeFromString (Source: OleVariant; Value: string): OleVariant;
       procedure FormatSheet(ANameSheet: string; ASheet: OLEVariant; ACol: array of string);
       {======================================================================}
       property ExcelApplication: OleVariant read FExcelApplication;
       property Visible[Source: Olevariant]: OleVariant read GetVisible write SetVisible;
       property WorkBooks: OleVariant read GetWorkBooks;
       property WorkBook [Index: OleVariant]: OleVariant read GetWorkBook;
       property ActiveWorkBook: OleVariant read GetActiveWorkBook;
       property WorkSheets [Source: Olevariant]: Olevariant read GetWorkSheets;
       property Sheets [Source: Olevariant]: Olevariant read GetSheets;
       property ActiveSheet [Source: Olevariant]: OleVariant read GetActiveSheet;

       property Sheet [Source: Olevariant; Index: OleVariant]: OleVariant read GetSheet;
       property WorkSheet [Source: Olevariant; Index: OleVariant]: OleVariant read GetWorkSheet;

       property Columns [Source: Olevariant]: OleVariant read GetColumns;
       property Rows [Source: Olevariant]: OleVariant read GetRows;
       property Cells [Source: Olevariant]: OleVariant read GetCells;
       property Cell [Source: Olevariant; Row,Column: Longint]: OleVariant read GetCell write SetCell;
       property LastCell [Source: Olevariant]: OleVariant read GetLastCell;
       property FirstCell [Source: Olevariant]: OleVariant read GetFirstCell;
       property Range [Source: Olevariant; Cell1,Cell2: OleVariant]: OleVariant read GetRange;
       {======================================================================}
   end;

const
   L1_0 = 0.393700787401575; {1 см}
   T_B = 0.984251968503937;
   H_F = 0.511811023622047;
   L0_5 = 0.196850393700787;

procedure PageSetupExcel(Sheet: OLEVariant);

procedure Register;

implementation

procedure Register;
begin
   RegisterComponents('Luis', [TLUExcel]);
end;

procedure PageSetupExcel(Sheet: OLEVariant);
begin
try
   Sheet.PageSetup.LeftHeader := '';
   Sheet.PageSetup.CenterHeader := Sheet.Name;
   Sheet.PageSetup.RightHeader := '';
   Sheet.PageSetup.LeftFooter := '';
   Sheet.PageSetup.CenterFooter := '';
   Sheet.PageSetup.RightFooter := '';
   Sheet.PageSetup.LeftMargin := {FLUExcel.Excel}Sheet.Application.InchesToPoints(L0_5);
   Sheet.PageSetup.RightMargin := {FLUExcel.Excel}Sheet.Application.InchesToPoints(L0_5);
   Sheet.PageSetup.TopMargin := {FLUExcel.Excel}Sheet.Application.InchesToPoints(L1_0);
   Sheet.PageSetup.BottomMargin := {FLUExcel.Excel}Sheet.Application.InchesToPoints(L1_0);
   Sheet.PageSetup.HeaderMargin := {FLUExcel.Excel}Sheet.Application.InchesToPoints(L0_5);
   Sheet.PageSetup.FooterMargin := {FLUExcel.Excel}Sheet.Application.InchesToPoints(L0_5);
   Sheet.PageSetup.PrintHeadings := False;
   Sheet.PageSetup.PrintGridlines := False;
   Sheet.PageSetup.PrintComments := xlPrintNoComments;
   Sheet.PageSetup.PrintQuality := 600;
   Sheet.PageSetup.CenterHorizontally := False;
   Sheet.PageSetup.CenterVertically := False;
   Sheet.PageSetup.Orientation := xlLandscape;
   Sheet.PageSetup.Orientation := xlPortrait;
   Sheet.PageSetup.Draft := False;
   Sheet.PageSetup.PaperSize := xlPaperA4;
   Sheet.PageSetup.FirstPageNumber := xlAutomatic;
   Sheet.PageSetup.Order := xlDownThenOver;
   Sheet.PageSetup.BlackAndWhite := False;
   Sheet.PageSetup.Zoom := 100;
except
end;

end;

constructor TLUExcel.Create(AOwner: TComponent);
begin
   inherited Create(AOwner);
   FExcelApplication := unassigned;
end;

destructor TLUExcel.Destroy;
begin
   //StopExcel;
   inherited Destroy;
end;

function TLUExcel.GetVisible(Source: OleVariant): OleVariant;
begin
   Result := Source.Visible;
end;

procedure TLUExcel.SetVisible(Source: OleVariant; Value: OleVariant);
var
   LLCID: LCID;
begin
   LLCID := GetUserDefaultLCID;
   Source.Visible := Value;
end;

procedure TLUExcel.StopExcel;
begin
   if not VarIsEmpty(FExcelApplication) then begin
      FExcelApplication.Application.Quit;
      FExcelApplication := unassigned;
   end;
end;

procedure TLUExcel.StartExcel(AVisible: Boolean);
begin
   (*
   if not VarIsEmpty(FExcel) then
      try
         FExcel := FExcel.GetActiveOleObject('Excel.Application');
      except
         try
            FExcel := CreateOleObject('Excel.Application');
         except
         end;
      end
   else
      try
         FExcel := CreateOleObject('Excel.Application');
      except
      end;
   Visible := AVisible;
   *)
   if VarIsEmpty(FExcelApplication) then begin
      try
         FExcelApplication := CreateOleObject('Excel.Application');
         ExcelApplication.DisplayAlerts := False;
         Visible[ExcelApplication] := AVisible;
      except
      end;
   end;
end;

{ WorkBooks }

function TLUExcel.GetWorkBooks: OleVariant;
begin
   Result := ExcelApplication.WorkBooks;
end;

{ WorkSheets: Application,WorkBook }

function TLUExcel.GetWorkSheets(Source: OleVariant): OleVariant;
begin
   Result := Source.WorkSheets;
end;

{ Sheets: Application,WorkBook }

function TLUExcel.GetSheets(Source: OleVariant): OleVariant;
begin
   Result := Source.Sheets;
end;

{ ActiveWorkBook: Application }

function TLUExcel.GetActiveWorkBook: OleVariant;
begin
   Result := ExcelApplication.ActiveWorkBook;
end;

{ WorkBook }

function TLUExcel.GetWorkBook (Index: OleVariant): OleVariant;
begin
   Result := ExcelApplication.WorkBooks[Index];
   Result.Activate;
end;

function TLUExcel.NewWorkBook(WBATemplate: Cardinal{XlWBATemplate}): OleVariant;
begin
   Result := Workbooks.Add(WBATemplate);
end;

{ ActiveSheet: Application,WorkBook }

function TLUExcel.GetActiveSheet (Source: Olevariant): OleVariant;
begin
   Result := Source.ActiveSheet;
end;

{ WorkSheet: Application,WorkBook }

function TLUExcel.GetWorkSheet (Source: Olevariant; Index: OleVariant): OleVariant;
begin
   Result := Source.WorkSheets[Index];
   Result.Activate;
end;

{ Sheet: Application,WorkBook [N | Name]}

function TLUExcel.GetSheet (Source: Olevariant; Index: OleVariant): OleVariant;
begin
   Result := Source.Sheets[Index];
   Result.Activate;
end;

procedure TLUExcel.NewSheet(Source: Olevariant; SheetType: Cardinal{XlSheetType}; NameSheets: array of string);
var
   i: Integer;
   LWorkSheet: OLeVariant;
begin
   for i:=0 to High(NameSheets) do begin
      LWorkSheet := Source.Sheets.Add({Before},{After},1,SheetType);
      LWorkSheet.Name := NameSheets[i];
   end;
end;

{ GetCell: Application,WorkSheet,Range,Application.Selection }

function TLUExcel.GetCell (Source: OleVariant; Row,Column: Longint): OleVariant;
begin
   Result := Source.Cells[Row,Column];
end;
procedure TLUExcel.SetCell (Source: OleVariant; Row,Column: Longint; Value: OleVariant);
begin
   Source.Cells[Row,Column] := Value;
end;

{ LastCell: Sheet}

function TLUExcel.GetLastCell (Source: OleVariant): OleVariant;
begin
    Result := FirstCell[Source].SpecialCells(xlLastCell);
end;

function TLUExcel.GetFirstCell (Source: OleVariant): OleVariant;
begin
    Result := Cell[Source,1,1];
end;

{ GetCells: Application,WorkSheet,Range,Application.Selection }

function TLUExcel.GetCells (Source: OleVariant): OleVariant;
begin
   Result := Source.Cells;
end;

{ GetRange: Application,WorkSheet,Range,Application.Selection }
{ Можно Cell1 = 'C1' Cell2 =' F25' }
function TLUExcel.GetRange (Source: OleVariant; Cell1,Cell2: OleVariant): OleVariant;
begin
   Result := Source.Range[Cell1, Cell2];
end;

{ GetColumns: Application,WorkSheet,Range,Application.Selection }

function TLUExcel.GetColumns (Source: OleVariant): OleVariant;
begin
   Result := Source.Columns;
end;

{ GetRows: Application,WorkSheet,Range,Application.Selection }

function TLUExcel.GetRows (Source: OleVariant): OleVariant;
begin
   Result := Source.Rows;
end;

procedure TLUExcel.AutofitColumns;
begin
   ExcelApplication.Cells.Select;
   ExcelApplication.Selection.Columns.Autofit;
end;

procedure TLUExcel.AutofitRange(Source: OleVariant);
begin
   Source.Autofit;
end;

procedure TLUExcel.SaveAsWorkBook(WorkBook: OleVariant; const FileName: string);
(*
  xlAddIn = $00000012;
  xlCSV = $00000006;
  xlCSVMac = $00000016;
  xlCSVMSDOS = $00000018;
  xlCSVWindows = $00000017;
  xlDBF2 = $00000007;
  xlDBF3 = $00000008;
  xlDBF4 = $0000000B;
  xlDIF = $00000009;
  xlExcel2 = $00000010;
  xlExcel2FarEast = $0000001B;
  xlExcel3 = $0000001D;
  xlExcel4 = $00000021;
  xlExcel5 = $00000027;
  xlExcel7 = $00000027;
  xlExcel9795 = $0000002B;
  xlExcel4Workbook = $00000023;
  xlIntlAddIn = $0000001A;
  xlIntlMacro = $00000019;
  xlWorkbookNormal = $FFFFEFD1;
  xlSYLK = $00000002;
  xlTemplate = $00000011;
  xlCurrentPlatformText = $FFFFEFC2;
  xlTextMac = $00000013;
  xlTextMSDOS = $00000015;
  xlTextPrinter = $00000024;
  xlTextWindows = $00000014;
  xlWJ2WD1 = $0000000E;
  xlWK1 = $00000005;
  xlWK1ALL = $0000001F;
  xlWK1FMT = $0000001E;
  xlWK3 = $0000000F;
  xlWK4 = $00000026;
  xlWK3FM3 = $00000020;
  xlWKS = $00000004;
  xlWorks2FarEast = $0000001C;
  xlWQ1 = $00000022;
  xlWJ3 = $00000028;
  xlWJ3FJ3 = $00000029;
*)
begin
   WorkBook.SaveAs(FileName, WorkBook.FileFormat);
end;

procedure TLUExcel.SaveWorkBook(WorkBook: OleVariant);
begin
   WorkBook.Save;
end;

function TLUExcel.OpenWorkBook(const FileName: string): OleVariant;
begin
   Result := WorkBooks.Open(FileName);
end;

procedure TLUExcel.SetFormula(Cell: OLEVariant; const Formula: string);
begin
    Cell := Formula;
end;

{ Value = 'C1:F25' }
function TLUExcel.GetRangeFromString (Source: OleVariant; Value: string): OleVariant;
begin
   Result := Source.Range[Value];
end;

procedure TLUExcel.FormatSheet(ANameSheet: string; ASheet: OLEVariant; ACol: array of string);
var
   i: Integer;
begin
   ASheet.Name := ANameSheet;
   for i:=0 to High(ACol) do begin
      Columns[ASheet].Item[i+1].Select;
      ExcelApplication.Selection.NumberFormat := ACol[i];
   end;
end;

end.
