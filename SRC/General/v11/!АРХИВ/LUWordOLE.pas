{=======================================================}
{ Project:                                              }
{         Delphi VCL Extensions (LU)                    }
{         Copyright (c) 2000 Central Bank Of Russia     }
{ Subject:                                              }
{         Работа с Word                                 }
{ Author:                                               }
{         Lisitsin Y.R.                                 }
{=======================================================}

{
object Application
   property Documents (collection object)
      property Count
      function Add([Template, NewTemplate, DocumentType, Visible])
      function Open(FileName[,...]): Document object
      function Open: Document object
      function Close(SaveChanges, OriginalFormat, RouteDocument)
      function Close(SaveChanges, RouteDocument)
      function Close
      function Item(Index)
      function Save: Document or Template object
      function Save(NoPrompt,OriginalFormat): Documents object
      function Save(Comment): Versions object
      Document

         property CustomDocumentProperties
            property Item
               CustomDocumentProperty
                  property Name
                  property Value
            property Count
            function Add



         Sheets
         WorkSheets
            WorkSheet
               Cells (Range)
               Columns (Range)
               Rows (Range)
         Charts
}

unit LUWord;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  ComObj, Word97, Office97, OleServer;


type
   TWord = class(TComponent)
   private
      FWordApplication: OleVariant;
      FWordDocument: OLEVariant;
      function GetVisible(Source: OleVariant): OleVariant;
      procedure SetVisible(Source: OleVariant; Value: OleVariant);
      { Documents }
      function GetDocuments: OleVariant;
      { Document }
      function GetActiveDocument: OleVariant;
      function GetDocument (Index: OleVariant): OleVariant;
      {}
      function GetCustomDocumentProperties(Document: OleVariant): OleVariant;
      function GetCustomDocumentProperty(Document: OleVariant; Index: OleVariant): OleVariant;
    protected
    public
       constructor Create (AOwner: TComponent); override;
       destructor Destroy; override;
       {======================================================================}
       { WordApplication }
       procedure StartWord(AVisible: Boolean);
       procedure StopWord;
       { Document }
       function OpenDocument (const FileName: string): OleVariant;
       procedure SaveAsDocument (Document: OleVariant; const FileName: string);
       procedure SaveDocument (Document: OleVariant);
       procedure PrintDocument (Document: OleVariant);
       function NewDocument (Template: string; NewTemplate: Boolean): OleVariant;
       {======================================================================}
       property WordApplication: OleVariant read FWordApplication;
       property Visible[Source: Olevariant]: OleVariant read GetVisible write SetVisible;
       { Documents }
       property Documents: OleVariant read GetDocuments;
       property Document [Index: OleVariant]: OleVariant read GetDocument;
       property ActiveDocument: OleVariant read GetActiveDocument;
       { DocumentProperties }
       property CustomDocumentProperties [Document: OleVariant]: OleVariant read GetCustomDocumentProperties;
       property CustomDocumentProperty [Document: OleVariant; Index: OleVariant]: OleVariant read GetCustomDocumentProperty;
       {======================================================================}
   end;

procedure Register;

implementation

procedure Register;
begin
   RegisterComponents('Luis', [TWord]);
end;

constructor TWord.Create(AOwner: TComponent);
begin
   inherited Create(AOwner);
   FWordApplication := unassigned;
   FWordDocument := unassigned;
end;

destructor TWord.Destroy;
begin
   StopWord;
   inherited Destroy;
end;

function TWord.GetVisible(Source: OleVariant): OleVariant;
begin
   Result := Source.Visible;
end;

procedure TWord.SetVisible(Source: OleVariant; Value: OleVariant);
var
   LLCID: LCID;
begin
   LLCID := GetUserDefaultLCID;
   Source.Visible := Value;
end;

procedure TWord.StopWord;
begin
   if not VarIsEmpty(FWordApplication) then begin
      FWordApplication.Quit;
      FWordApplication := unassigned;
   end;
end;

procedure TWord.StartWord(AVisible: Boolean);
begin
   if VarIsEmpty(FWordApplication) then begin
      try
         FWordApplication := CreateOleObject('Word.Application');
         //WordApplication.DisplayAlerts := False;
         Visible[WordApplication] := AVisible;
      except
      end;
   end;
end;

{ Documents }

function TWord.GetDocuments: OleVariant;
begin
   Result := WordApplication.Documents;
end;

{ ActiveDocument: Application }

function TWord.GetActiveDocument: OleVariant;
begin
   Result := WordApplication.ActiveDocument;
   FWordDocument := Result;
end;

{ Document }

function TWord.GetDocument (Index: OleVariant): OleVariant;
begin
   Result := WordApplication.Documents[Index];
   Result.Activate;
   FWordDocument := Result;
end;

function TWord.NewDocument(Template: string; NewTemplate: Boolean): OleVariant;
begin
   Result := Documents.Add(Template,NewTemplate);
end;

procedure TWord.SaveAsDocument(Document: OleVariant; const FileName: string);
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
  xlWord2 = $00000010;
  xlWord2FarEast = $0000001B;
  xlWord3 = $0000001D;
  xlWord4 = $00000021;
  xlWord5 = $00000027;
  xlWord7 = $00000027;
  xlWord9795 = $0000002B;
  xlWord4Document = $00000023;
  xlIntlAddIn = $0000001A;
  xlIntlMacro = $00000019;
  xlDocumentNormal = $FFFFEFD1;
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
   try
      //Document.SaveAs(FileName, Document.FileFormat);
      Document.SaveAs(FileName);
   except
   end;
end;

procedure TWord.SaveDocument(Document: OleVariant);
begin
   Document.Save;
end;

function TWord.OpenDocument(const FileName: string): OleVariant;
begin
   Result := Documents.Open(FileName);
   FWordDocument := Result;
end;

function TWord.GetCustomDocumentProperties(Document: OleVariant): OleVariant;
begin
   Result := Document.CustomDocumentProperties;
end;

function TWord.GetCustomDocumentProperty(Document: OleVariant; Index: OleVariant): OleVariant;
begin
   Result := Document.CustomDocumentProperties.Item[Index];
end;

procedure TWord.PrintDocument (Document: OleVariant);
begin
   Document.PrintOut;
end;

end.
