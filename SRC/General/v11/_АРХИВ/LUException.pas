unit LUException;

interface

{ (MAIN.PAS) }

uses Classes, SysUtils, MAPI, Forms, LUVersion, TypInfo, Controls;

//  public    { Public declarations }

var
    UserId: Integer;
    UserName,
    UserLevel: String;
    xVersion: TVersionInfo ;

{$IFNDEF WORKINGBUILD}
var
    xMAPISession: Cardinal;
    xMAPIMessage: TMapiMessage;
    xMAPIRecip: TMapiRecipDesc;
{$ENDIF}

//procedure DoException( Sender: TObject; Error: Exception );
{$IFNDEF WORKINGBUILD}
function GetUnitName( xClass: TClass ): String;
function GetHierarchy( xClass: TObject ): String ;
function GetSubordination( xObject: TObject ): String ;
{$ENDIF}

implementation

//  private   { Private declarations }

{$IFNDEF WORKINGBUILD}
procedure SendMail( MsgTo, MsgSubj, MsgBody: String; ShowError: Boolean);
var err: Integer;
begin
   FillChar( xMAPIRecip, SizeOf(xMAPIRecip), 0 );
   xMAPIRecip.ulRecipClass    := MAPI_TO;
   xMAPIRecip.lpszName        := PChar( MsgTo );
   xMAPIMessage.nRecipCount   := 1;
   xMAPIMessage.lpRecips      := @xMAPIRecip;
   xMAPIMessage.lpszSubject   := PChar( MsgSubj );
   xMAPIMessage.lpszNoteText  := PChar( MsgBody );
   err := MapiSendMail( xMAPISession, 0, xMAPIMessage, 0, 0);
   if ( err <> SUCCESS_SUCCESS ) and ShowError
      then raise Exception.CreateFmt( 'Ошибка MAPI %d', [ err ]);
end;
{$ENDIF}

{$IFNDEF WORKINGBUILD}
function GetUnitName( xClass: TClass ): String;
begin
   try
      Result := '(' + GetTypeData(PTypeInfo(xClass.ClassInfo))^.UnitName + ')';
   except
      Result := '(Not defined)';
   end;
end;

function GetHierarchy( xClass: TObject ): String ;
var ClassRef: TClass;
begin
   Result := xClass.ClassName + GetUnitName( xClass.ClassType ) + #13;
   ClassRef := xClass.ClassParent;
   while ClassRef <> nil do begin
      try
         Result := Result +  ClassRef.ClassName + GetUnitName( ClassRef ) + #13;
         ClassRef := ClassRef.ClassParent;
      except
         ClassRef := nil
      end;
   end;
end;

function GetSubordination( xObject: TObject ): String ;
var xOwner: TComponent;
begin
   Result := 'Not defined';
   if ( xObject is TControl ) then
      with ( xObject as TControl ) do begin
         if Parent = nil then xOwner := Owner else xOwner  := Parent;
         Result  := Name + ': ' + ClassName + GetUnitName( ClassType ) + #13;
      end
   else if ( xObject is TComponent ) then
      with ( xObject as TComponent ) do begin
         xOwner  := Owner;
         Result  := Name + ': ' + ClassName  + GetUnitName( ClassType ) + #13;
      end
   else begin
      if ( xObject is TObject ) then
         Result := xObject.ClassName + GetUnitName( xObject.ClassType ) + #13;
      xOwner := nil;
   end;

   while xOwner <> nil do begin
      try
         if ( xOwner is TControl ) then begin
            with ( xOwner as TControl ) do
               Result  := Result + Name + ': ' + ClassName + GetUnitName( ClassType ) + #13;
            if ( xOwner as TControl ).Parent = nil
               then xOwner := ( xOwner as TControl ).Owner
               else xOwner := ( xOwner as TControl ).Parent;
         end else
         if ( xOwner is TComponent ) then begin
            with ( xOwner as TComponent ) do
               Result  := Result + Name + ': ' + ClassName + GetUnitName( ClassType ) + #13;
            xOwner  := ( xOwner as TComponent ).Owner;
         end else begin
            if ( xOwner is TObject ) then
               Result := Result + xOwner.ClassName + GetUnitName( xOwner.ClassType ) + #13;
            xOwner := nil;
         end;
      except
         xOwner := nil
      end;
   end;
end;
{$ENDIF}

initialization

// Веpсия пpогpаммы
    xVersion   := TVersionInfo.Create( nil );
    xVersion.FileName := Application.ExeName;

//    laVersion.Caption := 'Веpсия ' + xVersion.FileVersion;
//    wfRun.NextStep;
(*
// Подключение почтовой системы.
    if {not ( tbUserUserIsMAPI.Value ) or}
       ( MapiLogon( Application.Handle, nil, nil, MAPI_USE_DEFAULT, 0,
                    @xMAPISession ) <> SUCCESS_SUCCESS )
       then xMAPISession := 0;
*)
finalization
   xVersion.Free;

end.
