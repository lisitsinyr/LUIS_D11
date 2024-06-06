(*
 =======================================================
 Copyright (c) 2023
 Author:
     Lisitsin Y.R.
 Project:
     LU_PAS
     Delphi VCL Extensions (LU)
 Module:
     LUObjects

 =======================================================
*)

unit LUObjects;

interface

uses
    {}
        Classes, SysUtils, Forms,
    {}
    RxCtrls,
    {}
    LUSupport, LUStrUtils, LUThreadProgress;

{ =========================================================================== }
type
    TObjectType = (
        (*
        otExchange, otFolder, otInfoStore, otMessage, otMessageFilter,
        otAttachment, otField, otAddressEntry, otAddressList, otRecipient,
        otFiles, otHomeBox, otFormMessage, otInfoMessage, otErrorMessage,
        *)
        otUsers, 
        otTask, otTasks, 
        otConfirmationMessage, otReportDeliverMessage, otDataMFOMessage,

        otNone, otDirectory, otEMail, otFile, otFTPServer, otMailBox, 
        otMonth, otUser, otYouTubeObject
        );

{ TObjects }

type
    TObjects = class(TComponent)
    private
        FObjectType: TObjectType;
        FTag: Longint;
        FText: PChar;

        function GetText: string;
        procedure SetText (const Value: string);
    public
        constructor Create (AOwner: TComponent); override;
        destructor Destroy; override;
        procedure Clear;
        {}
        property ObjectType: TObjectType read FObjectType write FObjectType;
        property Tag: Longint read FTag write FTag;
        property Text: string read GetText write SetText;
    end;

{ ======================================================= }
{ ��������� �������� }
{ ======================================================= }

{ TObjectsItem }

type
    TObjectsItem = class(TCollectionItem)
    private
        FObjects: TObjects;

    protected
    public
        constructor Create (AOwner: TCollection); override;
        destructor Destroy; override;
        property Objects: TObjects read FObjects;
    end;

{ TObjectsCollection }

type
    TObjectsCollection = class(TCollection)
    private
        function GetItem (Index: Integer): TObjectsItem;
        procedure SetItem (Index: Integer; Value: TObjectsItem);
        function GetObjectsItem (Value: string): TObjectsItem;

    public
        constructor Create;
        function AddObjectsItem: TObjectsItem;
        procedure DeleteObjectsItem (Value: string);
        { }
        property Items[index: Integer]: TObjectsItem read GetItem
            write SetItem; default;
        property ObjectsItem[Value: string]: TObjectsItem
            read GetObjectsItem;
    end;


implementation

{ TObjects }

constructor TObjects.Create (AOwner: TComponent);
begin
    inherited Create (AOwner);
    ObjectType := otNone;
    FTag := 0;
    Clear;
end;

destructor TObjects.Destroy;
begin
    StrDispose (FText);
    inherited Destroy;
end;

procedure TObjects.Clear;
begin
    Text := '';
end;

function TObjects.GetText: string;
begin
    Result := StrPas (FText);
end;

procedure TObjects.SetText (const Value: string);
begin
    if FText <> nil then
        StrDispose (FText);
    FText := StrAlloc (Length(Value) + 1);
    StrPCopy (FText, Value);
end;


{ ------------ }
{ TObjectsItem }
{ ------------ }

{ TObjectsItem.Create }

constructor TObjectsItem.Create (AOwner: TCollection);
begin
    inherited Create (AOwner);
    FObjects := TObjects.Create (nil);
end;

{ TObjectsItem.Destroy }

destructor TObjectsItem.Destroy;
begin
    FObjects.Free;
    inherited Destroy;
end;

{ ------------------ }
{ TObjectsCollection }
{ ------------------ }

{ TObjectsCollection.Create }

constructor TObjectsCollection.Create;
begin
    inherited Create (TObjectsItem);
end;

{ TObjectsCollection.AddObjectsItem }

function TObjectsCollection.AddObjectsItem: TObjectsItem;
begin
    Result := TObjectsItem (inherited Add);
end;

{ TObjectsCollection.GetItem }

function TObjectsCollection.GetItem (Index: Integer)
    : TObjectsItem;
begin
    Result := TObjectsItem (inherited Items[index]);
end;

{ TObjectsCollection.SetItem }

procedure TObjectsCollection.SetItem (Index: Integer; 
    Value: TObjectsItem);
begin
    Items[index].Assign (Value);
end;

{ TObjectsCollection.GetObjectsItem }

function TObjectsCollection.GetObjectsItem (Value: string): TObjectsItem;
var
    i: Integer;
    LText: string;
begin
    { ����� Objects �� Value }
    Result := nil;
    for i:=0 to Count - 1 do
    begin
        LText := Items[i].Objects.Text;
        if LText = Value then
        begin
            Result := Items[i];
            Break;
        end;
    end;
end;

{ TYouTubeObjectsCollection.DeleteObjectsItem }

procedure TObjectsCollection.DeleteObjectsItem (Value: string);
var
    LObjectsItem: TObjectsItem;
begin
    LObjectsItem := ObjectsItem[Value];
    LObjectsItem.Free;
end;

end.
