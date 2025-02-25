unit AutoTestScan;

interface

uses LUExcel, LUScandir, SysUtils, FileCtrl;

type
   TAutoTestScan = class
      FExcel: TExcel;
      FScanDirFiles: TScanDirFiles;
   private
     procedure WorkFileXLS(const FileName: string);
   public
      constructor Create;
      destructor Destroy; override;
      procedure Main(const Arg: array of string);
   end;

implementation

constructor TAutoTestScan.Create;
begin
   inherited Create;
   FScanDirFiles := TScanDirFiles.Create;
   FExcel := TExcel.Create(nil);
end;

destructor TAutoTestScan.Destroy;
begin
   FExcel.Free;
   FScanDirFiles.Free;
   inherited Destroy;
end;

procedure TAutoTestScan.WorkFileXLS(const FileName: string);
var
   LWorkBook: OleVariant;
   LWorkSheet: OLEVariant;
   LRange: OLEVariant;
   LValue: string;
   i: Integer;
begin
   with FExcel do begin
      LWorkBook := OpenWorkBook (FileName);
      LWorkSheet := WorkSheet[LWorkBook,1];
      LRange := Range[LWorkSheet, FirstCell[LWorkSheet], LastCell[LWorkSheet]];
      while 
      for i:=1 to LRange.Rows.Count do begin
         LValue := Cell[LRange,i,1].Value;
      end;

      //for i:=1 to 10 do for j:=1 to 10 do Cell[ActiveSheet[Book1],i,j] := i*j;

      LWorkBook.Close;
   end;
end;

procedure TAutoTestScan.Main(const Arg: array of string);
var
   i: Integer;
   s: string;
begin
   if DirectoryExists(Arg[0]) then begin
      FExcel.StartExcel(True);
      FScanDirFiles.DelFile := False;
      FScanDirFiles.OnFile := nil;
      FScanDirFiles.Execute(IncludeTrailingBackslash(Arg[0])+Arg[1], sfDirectory);
      for i:=0 to FScanDirFiles.FileList.Count-1 do begin
         s := FScanDirFiles.FileList.Strings[i];
         if UpperCase(ExtractFileExt(s)) = '.XLS' then WorkFileXLS(s);
      end;
      FExcel.StopExcel;
   end;
end;

end.
