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
                  property Type (4-текст 3-дата)
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
   TLUWordApplication = class(TComponent)
   private
      FWordApplication: TWordApplication;
      { Documents }
      function GetWordDocuments: Documents;
      { Document }
      function GetActiveDocument: WordDocument;
      function GetWordDocument (Index: OleVariant): WordDocument;
   protected
   public
      constructor Create (AOwner: TComponent); override;
      destructor Destroy; override;
      {======================================================================}
      { WordApplication }
      procedure StartWord(AVisible: Boolean);
      procedure StopWord;
      { Document }
      function OpenDocument (FileName: OLEVariant): WordDocument;
      function NewDocument (Template: OLEVariant; NewTemplate: OLEVariant): WordDocument;
      {======================================================================}
      property WordApplication: TWordApplication read FWordApplication;
      {======================================================================}
      { Documents }
      property WordDocuments: Documents read GetWordDocuments;
      { Document }
      property WordDocument [Index: OleVariant]: WordDocument read GetWordDocument;
      property ActiveDocument: WordDocument read GetActiveDocument;
      {======================================================================}
   end;

   TLUWordDocument = class(TComponent)
   private
      FWordDocument: TWordDocument;
      procedure SetDocument(Value: WordDocument);
      function GetCustomProperties: OleVariant;
      function GetCustomProperty(Index: OleVariant): OleVariant;
      function GetBuiltinProperties: OleVariant;
      function GetBuiltinProperty(Index: OleVariant): OleVariant;
   protected
   public
      constructor Create (AOwner: TComponent); override;
      destructor Destroy; override;
      {======================================================================}
      procedure SaveAsDocument (FileName: OleVariant);
      procedure SaveDocument;
      procedure PrintDocument;
      {======================================================================}
      property WordDocument: TWordDocument read FWordDocument;
      {======================================================================}
      property Document: WordDocument write SetDocument;
      property CustomProperties: OleVariant read GetCustomProperties;
      property CustomProperty [Index: OleVariant]: OleVariant read GetCustomProperty;
      property BuiltinProperties: OleVariant read GetBuiltinProperties;
      property BuiltinProperty [Index: OleVariant]: OleVariant read GetBuiltinProperty;
      {======================================================================}
   end;

procedure Register;

implementation

procedure Register;
begin
   RegisterComponents('Luis', [TLUWordApplication]);
   RegisterComponents('Luis', [TLUWordDocument]);
end;

{ Create }

constructor TLUWordApplication.Create(AOwner: TComponent);
begin
   inherited Create(AOwner);
   FWordApplication := TWordApplication.Create(nil);
end;

{ Destoy }

destructor TLUWordApplication.Destroy;
begin
   StopWord;
   FWordApplication.Free;
   inherited Destroy;
end;

{ StartWord }

procedure TLUWordApplication.StartWord(AVisible: Boolean);
begin
   FWordApplication.Visible := AVisible;
   FWordApplication.Connect;
end;

{ StopWord }

procedure TLUWordApplication.StopWord;
begin
   try
      FWordApplication.Quit;
   except
   end;
end;

{ GetWordDocuments }

function TLUWordApplication.GetWordDocuments: Documents;
begin
   Result := FWordApplication.Documents;
end;

{ GetActiveDocument }

function TLUWordApplication.GetActiveDocument: WordDocument;
begin
   Result := FWordApplication.ActiveDocument;
end;

{ GetWordDocument }

function TLUWordApplication.GetWordDocument (Index: OleVariant): WordDocument;
begin
   Result := FWordApplication.Documents.Item(Index);
end;

{ NewDocument }

function TLUWordApplication.NewDocument(Template: OLEVariant; NewTemplate: OLEVariant): WordDocument;
begin
   WordDocuments.Add(Template,NewTemplate);
end;

{ OpenDocument }

function TLUWordApplication.OpenDocument(FileName: OLEVariant): WordDocument;
begin
   Result := WordDocuments.Open(FileName,
                EmptyParam,EmptyParam,EmptyParam,EmptyParam,EmptyParam,
                EmptyParam,EmptyParam,EmptyParam,EmptyParam);
end;




{ Create }

constructor TLUWordDocument.Create(AOwner: TComponent);
begin
   inherited Create(AOwner);
   FWordDocument := TWordDocument.Create(nil);
end;

{ Destoy }

destructor TLUWordDocument.Destroy;
begin
   FWordDocument.Free;
   inherited Destroy;
end;

{ SetDocument }

procedure TLUWordDocument.SetDocument(Value: WordDocument);
begin
   FWordDocument.ConnectTo(Value);
   FWordDocument.Activate;
end;

{ SaveDocument }

procedure TLUWordDocument.SaveDocument;
begin
   FWordDocument.Save;
end;

{ SaveAsDocument }

procedure TLUWordDocument.SaveAsDocument(FileName: OLEVariant);
(*
  xlAddIn = $00000012;
  xlCSV = $00000006;
  xlCSVMac = $00000016;
  xlCSVMSDOS = $00000018;
  xlCSVWindows = $00000017;

  xlDBF2 = $00000007;
  xlDBF3 = $00000008;
  xlDIF = $00000009;
  xlDBF4 = $0000000B;
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
  xlWK1    = $00000005;
  xlWK1ALL = $0000001F;
  xlWK1FMT = $0000001E;
  xlWK3    = $0000000F;
  xlWK4    = $00000026;
  xlWK3FM3 = $00000020;
  xlWKS    = $00000004;
  xlWorks2FarEast = $0000001C;
  xlWQ1 = $00000022;
  xlWJ3 = $00000028;
  xlWJ3FJ3 = $00000029;
*)
begin
   try
      {Document.SaveAs(FileName, Document.FileFormat);}
      FWordDocument.SaveAs(FileName,
             EmptyParam,EmptyParam,EmptyParam,EmptyParam,EmptyParam,
             EmptyParam,EmptyParam,EmptyParam,EmptyParam,EmptyParam);
   except
   end;
end;

function TLUWordDocument.GetCustomProperties: OleVariant;
begin
   Result := FWordDocument.CustomDocumentProperties;
end;

function TLUWordDocument.GetCustomProperty(Index: OleVariant): OleVariant;
begin
   Result := CustomProperties.Item[Index];
end;

function TLUWordDocument.GetBuiltinProperties: OleVariant;
begin
   Result := FWordDocument.BuiltinDocumentProperties;
end;

function TLUWordDocument.GetBuiltinProperty(Index: OleVariant): OleVariant;
begin
   Result := BuiltinProperties.Item[Index];
end;

procedure TLUWordDocument.PrintDocument;
var
   LDuplex: OLEVariant;
begin
   LDuplex := True;
   (*
   FWordDocument.PrintOut(EmptyParam,EmptyParam,EmptyParam,EmptyParam,
                          EmptyParam,EmptyParam,EmptyParam,EmptyParam,
                          EmptyParam,EmptyParam,EmptyParam,EmptyParam,LDuplex);
   *)
   FWordDocument.PrintOut;
end;

end.
