unit LUWNet;

interface

uses
  Windows, Messages, SysUtils, Classes,
  Vcl.Graphics, Vcl.Controls, Vcl.Forms, Vcl.Dialogs,
  LMCons, LMErrLU, LMErrText;

const
  DEVICENAMELEN = 80;
  PROVIDERNAMELEN = 80;
  ERRORLEN = 80;

type
  PDeviceName = ^TDeviceName;
  TDeviceName = array [1..DEVICENAMELEN] of Char;

  TLUResource = class
  private
     { 101 }
     FScope: DWord;
     FResType: DWord;
     FDisplayType: DWord;
     FUsage: DWord;
     FLocalName : string;
     FRemoteName : string;
     FComment : string;
     FProvider : string;
     procedure Clear;
     function GetNetResource: TNetResource;
  public
     constructor Create;
     property Scope: DWord read FScope write FScope;
     property ResType: DWord read FResType write FResType;
     property DisplayType: DWord read FDisplayType write FDisplayType;
     property Usage: DWord read FUsage write FUsage;
     property LocalName : string read FLocalName write FLocalName;
     property RemoteName : string read FRemoteName write FRemoteName;
     property Comment : string read FComment write FComment;
     property Provider : string read FProvider write FProvider;
     property NetResource : TNetResource read GetNetResource;
  end;

  TLUResourceItem = class(TCollectionItem)
  private
     FResource: TLUResource;
  public
     property Resource: TLUResource read FResource write FResource;
  end;

  TLUResources = class(TCollection)
  private
    function GetItem(Index: Integer): TLUResourceItem;
    procedure SetItem(Index: Integer; Value: TLUResourceItem);
  protected
  public
    function Add: TLUResourceItem;
    property Items[Index: Integer]: TLUResourceItem read GetItem write SetItem; default;
  end;

  TLUWNet = class(TComponent)
  private
    { Private declarations }
    { Resource }
    FInfoResource: TLUResource;
    FInfoResources: TLUResources;
    FNameResources: TLUResources;
    {}
    FErrorString: string;
    FErrorCode: DWord;
    FBufPtr: Pointer;
    FErrorBufPtr: Pointer;
    FNameBufPtr: Pointer;
    FPrefMaxLen: DWord;
    FEntriesRead: DWord;
    FhEnum: THandle;
  protected
     { Protected declarations }
     { The following functions are used in Windows networking:}
     { MultinetGetConnectionPerformance }
     procedure LUWNetAddConnection2(UserName, Password: PChar; Flags: DWord);
     procedure LUWNetAddConnection3(Owner: HWND; UserName, Password: PChar; Flags: DWord);
     procedure LUWNetUseConnection(Owner: HWND; UserName, Password: PChar; Flags: DWord);
     procedure LUWNetCancelConnection2(ResourceName: string; Flags: DWord; Force: BOOL);
     procedure LUWNetConnectionDialog(Owner: HWND; ResType: DWord);
     procedure LUWNetConnectionDialog1(Owner: HWND);
     procedure LUWNetDisconnectDialog(Owner: HWND; ResType: DWord);
     procedure LUWNetDisconnectDialog1(Owner: HWND);
     procedure LUWNetGetConnection(ResourceName: string);
     procedure LUWNetGetLastError;
     { WNetGetNetworkInformation }
     procedure LUWNetGetProviderName(Network: DWord);
     procedure LUWNetGetNetworkInformation(ProviderName: string);
     { WNetGetResourceInformation }
     { WNetGetResourceParent }
     { WNetGetUniversalName }
     procedure LUWNetGetUser(ResourceName: string);
     procedure LUWNetOpenEnum(Scope, ResType, Usage: DWord);
     procedure LUWNetEnumResource;
     procedure LUWNetCloseEnum;
     procedure LUWNetGetResourceParent;

     { Obsolete Functions }
     { WNetAddConnection }

     procedure GetLastError;
     function CheckNetError(Res: DWORD): string;
  public
    { Public declarations }
    constructor Create (Owner: TComponent); override;
    destructor Destroy; override;
    { User }
    function GetUser(ResourceName: string): string;
    { Connection }
    function GetConnection(ResourceName: string): string;
    procedure AddConnection(Owner: HWND; UserName, Password: string; Flags: DWord);
    procedure UseConnection(Owner: HWND; UserName, Password: string; Flags: DWord);
    procedure CancelConnection(ResourceName: string; Flags: DWord; Force: Bool);
    procedure ConnectionDialog(Owner: HWND);
    procedure DisconnectionDialog(Owner: HWND);
    procedure ConnectionDialog1(Owner: HWND);
    procedure DisconnectionDialog1(Owner: HWND);
    { Resource }
    procedure OpenEnum(Scope, ResType, Usage: DWord);
    function EnumResource: TLUResources;
    procedure CloseEnum;
    procedure GetResourceParent;
    { Provider }
    function GetProviderName(Network: DWord): string;
    procedure GetNetworkInformation(ProviderName: string);
    {}
    property InfoResource: TLUResource read FInfoResource;
    property InfoResources: TLUResources read FInfoResources;
    property NameResources: TLUResources read  FNameResources;
  published
    { Published declarations }
  end;

procedure Register;

implementation

procedure Register;
begin
  RegisterComponents('LUIS Net', [TLUWNet]);
end;

{ --TLUResource-- }

constructor TLUResource.Create;
begin
   Clear;
end;

procedure TLUResource.Clear;
begin
   FScope := 0;
   FResType := 0;
   FDisplayType := 0;
   FUsage := 0;
   LocalName := '';
   RemoteName := '';
   Comment := '';
   Provider := '';
end;

function TLUResource.GetNetResource: TNetResource;
begin
   with Result do begin
      dwScope := FScope;
      dwType := FResType;
      dwDisplayType := FDisplayType;
      dwUsage := FUsage;
      lpLocalName := PChar(FLocalName);
      lpRemoteName := PChar(FRemoteName);
      lpComment := PChar(FComment);
      lpProvider := PChar(FProvider);
   end;
end;

{ --TLUResources-- }

function TLUResources.GetItem(Index: Integer): TLUResourceItem;
begin
   Result := TLUResourceItem(inherited GetItem(Index));
end;

procedure TLUResources.SetItem(Index: Integer; Value: TLUResourceItem);
begin
   inherited SetItem(Index, Value);
end;

function TLUResources.Add: TLUResourceItem;
begin
   Result := TLUResourceItem(inherited Add);
end;

{ TLUWNet }

constructor TLUWNet.Create (Owner: TComponent);
begin
   inherited Create (Owner);
   { Resource }
   FInfoResource := TLUResource.Create;
   FInfoResources := TLUResources.Create(TLUResourceItem);
   FNameResources := TLUResources.Create(TLUResourceItem);
end;

destructor TLUWNet.Destroy;
begin
   { Resource }
   FInfoResource.Free;
   FInfoResources.Free;
   FNameResources.Free;
   inherited Destroy;
end;

function TLUWNet.CheckNetError(Res: DWORD): string;
var
   s: string;
   Error: EWin32Error;
begin
   s := '';
   if (Res <> NERR_Success) {and (Res <> ERROR_MORE_DATA)} then begin
      s := SysAndNetErrorMessage(Res);
      s := Format('Net Error code: %d.'#10'"%s"', [Res, s]);
      Error := EWin32Error.CreateFmt('Net Error code: %d.'#10'"%s"', [Res, s]);
      Error.ErrorCode := Res;
      raise Error;
      FErrorCode := Res;
   end;
   Result := s;
end;

{ Private }

procedure TLUWNet.LUWNetGetUser(ResourceName: string);
begin
   FBufPtr := nil;
   FPrefMaxLen := UNLEN + 1;
   FBufPtr := AllocMem(FPrefMaxLen);
   FErrorString := CheckNetError(WNetGetUser(PChar(ResourceName), FBufPtr, FPrefMaxLen));
   GetLastError;
end;

procedure TLUWNet.LUWNetGetConnection(ResourceName: string);
begin
   FBufPtr := nil;
   FPrefMaxLen := DEVICENAMELEN + 1;
   FBufPtr := AllocMem(FPrefMaxLen);
   FErrorString := CheckNetError(WNetGetConnection(PChar(ResourceName), FBufPtr, FPrefMaxLen));
   GetLastError;
end;

procedure TLUWNet.LUWNetOpenEnum(Scope, ResType, Usage: DWord);
begin
   FErrorString := CheckNetError(WNetOpenEnum(Scope, ResType, Usage, FBufPtr, FhEnum));
   GetLastError;
end;

procedure TLUWNet.LUWNetCloseEnum;
begin
   FErrorString := CheckNetError(WNetCloseEnum(FhEnum));
   GetLastError;
end;

procedure TLUWNet.LUWNetEnumResource;
begin
   FPrefMaxLen := 16384;
   FEntriesRead := $FFFFFFFF; { -1 }
   FBufPtr := AllocMem(FPrefMaxLen);
   FErrorString := CheckNetError(WNetEnumResource(FhEnum, FEntriesRead, FBufPtr, FPrefMaxLen));
   GetLastError;
end;

procedure TLUWNet.LUWNetAddConnection2(UserName, Password: PChar; Flags: DWord);
var
   NR : TNetResource;
begin
   NR := InfoResource.NetResource;
   FErrorString := CheckNetError(WNetAddConnection2(NR, Password, UserName, Flags));
   GetLastError;
end;

procedure TLUWNet.LUWNetAddConnection3(Owner: HWND; UserName, Password: PChar; Flags: DWord);
var
   NR : TNetResource;
begin
   NR := InfoResource.NetResource;
   FErrorString := CheckNetError(WNetAddConnection3(Owner, NR, Password, UserName, Flags));
   GetLastError;
end;

procedure TLUWNet.LUWNetUseConnection(Owner: HWND; UserName, Password: PChar; Flags: DWord);
var
   NR : TNetResource;
   Res : DWord;
begin
   NR := InfoResource.NetResource;
   FPrefMaxLen := 16384;
   FBufPtr := AllocMem(FPrefMaxLen);
   FErrorString := CheckNetError(WNetUseConnection(Owner, NR, UserName, Password,
                   Flags, FBufPtr, FPrefMaxLen, Res));
   GetLastError;
end;

procedure TLUWNet.LUWNetCancelConnection2(ResourceName: string; Flags: DWord; Force: BOOL);
begin
   FErrorString := CheckNetError(WNetCancelConnection2(PChar(ResourceName), Flags, Force));
   GetLastError;
end;

procedure TLUWNet.LUWNetConnectionDialog(Owner: HWND; ResType: DWord);
begin
   FErrorString := CheckNetError(WNetConnectionDialog(Owner, ResType));
   GetLastError;
end;

procedure TLUWNet.LUWNetDisconnectDialog(Owner: HWND; ResType: DWord);
begin
   FErrorString := CheckNetError(WNetDisconnectDialog(Owner, ResType));
   GetLastError;
end;

procedure TLUWNet.LUWNetConnectionDialog1(Owner: HWND);
var
   NR : TNetResource;
   ConnectDlgStruct : TConnectDlgStruct;
begin
   NR := InfoResource.NetResource;
   with ConnectDlgStruct do begin
      cbStructure := SizeOf(TConnectDlgStruct);
      hwndOwner := Owner;
      lpConnRes := @NR;
      dwFlags := CONNDLG_PERSIST;
      dwDevNum := 0;
   end;
   FErrorString := CheckNetError(WNetConnectionDialog1(ConnectDlgStruct));
   GetLastError;
end;

procedure TLUWNet.LUWNetDisconnectDialog1(Owner: HWND);
var
   NR : TNetResource;
   DiscDlgStruct : TDiscDlgStruct;
begin
   NR := InfoResource.NetResource;
   with DiscDlgStruct do begin
      cbStructure := SizeOf(TConnectDlgStruct);
      hwndOwner := Owner;
      lpLocalName := NR.lpLocalName;
      lpRemoteName := NR.lpRemoteName;
      dwFlags := CONNDLG_PERSIST;
   end;
   FErrorString := CheckNetError(WNetDisconnectDialog1(DiscDlgStruct));
   GetLastError;
end;

procedure TLUWNet.LUWNetGetLastError;
begin
   FErrorBufPtr := AllocMem(ERRORLEN);
   FNameBufPtr := AllocMem(PROVIDERNAMELEN);
   FErrorString := CheckNetError(WNetGetLastError(FErrorCode, FErrorBufPtr, ERRORLEN,
                                 FNameBufPtr, PROVIDERNAMELEN));
end;

procedure TLUWNet.LUWNetGetProviderName(Network: DWord);
begin
   FPrefMaxLen := PROVIDERNAMELEN;
   FBufPtr := AllocMem(FPrefMaxLen);
   FErrorString := CheckNetError(WNetGetProviderName(Network, FBufPtr, FPrefMaxLen));
   GetLastError;
end;

procedure TLUWNet.LUWNetGetNetworkInformation(ProviderName: string);
begin
   FPrefMaxLen := PROVIDERNAMELEN;
   FBufPtr := AllocMem(FPrefMaxLen);
   FErrorString := CheckNetError(WNetGetNetworkInformation(PChar(ProviderName), TNetInfoStruct(FBufPtr^)));
   GetLastError;
end;

procedure TLUWNet.LUWNetGetResourceParent;
var
   NR : TNetResource;
begin
   NR := InfoResource.NetResource;
   FPrefMaxLen := SizeOf(TNetResource);
   FBufPtr := AllocMem(FPrefMaxLen);
   FErrorString := CheckNetError(WNetGetResourceParent(@NR, FBufPtr, FPrefMaxLen));
   GetLastError;
end;

{ Public }

function TLUWNet.GetUser(ResourceName: string): string;
var
   PData: PChar;
begin
   LUWNetGetUser(ResourceName);
   if FBufPtr <> nil then begin
      PData := PChar(FBufPtr);
      Result := StrPas(PData);
      FreeMem(FBufPtr);
      FBufPtr := nil;
      end
   else begin
      Result := FErrorString;
   end;
end;

function TLUWNet.GetConnection(ResourceName: string): string;
var
   PData: PChar;
begin
   LUWNetGetConnection(ResourceName);
   if FBufPtr <> nil then begin
      PData := PChar(FBufPtr);
      Result := StrPas(PData);
      FreeMem(FBufPtr);
      FBufPtr := nil;
      end
   else begin
      Result := FErrorString;
   end;
end;

procedure TLUWNet.OpenEnum(Scope, ResType, Usage: DWord);
begin
   if Scope <> RESOURCE_GLOBALNET then begin
      FBufPtr := nil;
   end;
   LUWNetOpenEnum(Scope, ResType, Usage);
end;

procedure TLUWNet.CloseEnum;
begin
   LUWNetCloseEnum;
end;

function TLUWNet.EnumResource: TLUResources;
var
   PData: PNetResource;
   i: Integer;
begin
   FNameResources.Clear;
   LUWNetEnumResource;
   if FBufPtr <> nil then begin
      PData := PNetResource(FBufPtr);
      for i:=1 to FEntriesRead do begin
         with FNameResources.Add do begin
            Resource := TLUResource.Create;
            Resource.Scope := PData^.dwScope;
            Resource.ResType := PData^.dwType;
            Resource.DisplayType := PData^.dwDisplayType;
            Resource.Usage := PData^.dwUsage;
            Resource.LocalName := StrPas(PData^.lpLocalName);
            Resource.RemoteName := StrPas(PData^.lpRemoteName);
            Resource.Comment := StrPas(PData^.lpComment);
            Resource.Provider := StrPas(PData^.lpProvider);
         end;
         Inc(PData);
      end;
      FreeMem(FBufPtr);
   end;
   Result := FNameResources;
end;

procedure TLUWNet.AddConnection(Owner: HWND; UserName, Password: string; Flags: DWord);
var
   PPassword : PChar;
begin
   if Trim(Password) = '' then PPassword := nil
                          else PPassword := PChar(Password);
   if Owner = 0 then begin
      LUWNetAddConnection2(PPassword, PChar(UserName), Flags);
      end
   else begin
      LUWNetAddConnection3(Owner, PPassword, PChar(UserName), Flags);
   end;
end;

procedure TLUWNet.UseConnection(Owner: HWND; UserName, Password: string; Flags: DWord);
var
   PPassword : PChar;
begin
   if Trim(Password) = '' then PPassword := nil
                          else PPassword := PChar(Password);
   LUWNetUseConnection(Owner, PPassword, PChar(UserName), Flags);
   if FBufPtr <> nil then begin
      FreeMem(FBufPtr);
   end;
end;

procedure TLUWNet.CancelConnection(ResourceName: string; Flags: DWord; Force: Bool);
begin
   LUWNetCancelConnection2(ResourceName, Flags, Force);
end;

procedure TLUWNet.ConnectionDialog(Owner: HWND);
begin
   LUWNetConnectionDialog(Owner, RESOURCETYPE_DISK);
end;

procedure TLUWNet.DisconnectionDialog(Owner: HWND);
begin
   LUWNetDisconnectDialog(Owner, RESOURCETYPE_DISK);
end;

procedure TLUWNet.ConnectionDialog1(Owner: HWND);
begin
   LUWNetConnectionDialog1(Owner);
end;

procedure TLUWNet.DisconnectionDialog1(Owner: HWND);
begin
   LUWNetDisconnectDialog1(Owner);
end;

procedure TLUWNet.GetLastError;
begin
   if FErrorCode = ERROR_EXTENDED_ERROR then begin
      LUWNetGetLastError;
      if FErrorBufPtr <> nil then FreeMem(FErrorBufPtr);
      if FNameBufPtr <> nil then FreeMem(FNameBufPtr);
   end;
end;

function TLUWNet.GetProviderName(Network: DWord): string;
var
   PData: PChar;
begin
   LUWNetGetProviderName(Network);
   if FBufPtr <> nil then begin
      PData := PChar(FBufPtr);
      Result := StrPas(PData);
      FreeMem(FBufPtr);
      FBufPtr := nil;
      end
   else begin
      Result := FErrorString;
   end;
end;

procedure TLUWNet.GetNetworkInformation(ProviderName: string);
var
   PData: PNetInfoStruct;
begin
   LUWNetGetNetWorkInformation(ProviderName);
   if FBufPtr <> nil then begin
      PData := PNetInfoStruct(FBufPtr);
      FreeMem(FBufPtr);
      FBufPtr := nil;
   end;
end;

procedure TLUWNet.GetResourceParent;
var
   PData: PNetResource;
begin
   LUWNetGetResourceParent;
   if FBufPtr <> nil then begin
      PData := PNetResource(FBufPtr);
      FreeMem(FBufPtr);
      FBufPtr := nil;
   end;
end;

end.
