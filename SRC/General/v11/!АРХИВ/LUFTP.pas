unit LUFTP;

interface

uses
   Classes, NMFTP;

   (*
   !               delete          literal         prompt          send
   ?               debug           ls              put             status
   append          dir             mdelete         pwd             trace
   ascii           disconnect      mdir            quit            type
   bell            get             mget            quote           user
   binary          glob            mkdir           recv            verbose
   bye             hash            mls             remotehelp
   cd              help            mput            rename
   close           lcd             open            rmdir
   *)
   (*
   Allocate
	ChangeDir
	Delete
	DoCommand
	Download
	DownloadRestore
	List
	MakeDirectory
	Mode
	Nlist
	Reinitialize
	RemoveDir
	Rename
	Upload
	UploadAppend
	UploadRestore
	UploadUnique
   *)

type
   TLUFTP = class
   private
      FFTP: TNMFTP;
      FList: TStringList;
      function GetListDir: TStringList;
      procedure SetHost(Value: string);
      procedure ListItem(Listing: String);
   protected
   public
      constructor Create;
      destructor Destroy; override;
      procedure Connect (const UserID,Password: string);
      procedure Disconnect;
      procedure ChangeDir(const DirName: string);
      procedure Upload(const FileName: string);
      procedure UploadUnique(const FileName: string);
      procedure Download(const FileName: string);
      property Host: string write SetHost;
      property ListDir: TStringList read GetListDir;
   end;

implementation

constructor TLUFTP.Create;
begin
   inherited Create;
   FList := TStringList.Create;
   FFTP := TNMFTP.Create(nil);
   FFTP.OnListItem := ListItem;
end;

destructor TLUFTP.Destroy;
begin
   FList.Free;
   FFTP.Free;
   inherited Destroy;
end;

procedure TLUFTP.SetHost(Value: string);
begin
   FFTP.Host := Value;
end;

procedure TLUFTP.Connect (const UserID,Password: string);
begin
   FFTP.UserID := UserID;
   FFTP.Password := Password;
   FFTP.Connect;
end;

procedure TLUFTP.Disconnect;
begin
   FFTP.Disconnect;
end;

function TLUFTP.GetListDir: TStringList;
begin
   FList.Clear;
   FFTP.List;
   Result := FList;
end;

procedure TLUFTP.ListItem(Listing: String);
begin
   FList.Add(Listing);
end;

procedure TLUFTP.ChangeDir(const DirName: string);
begin
   FFTP.ChangeDir(DirName);
end;

procedure TLUFTP.Upload(const FileName: string);
begin
   FFTP.Upload(FileName, FileName);
end;

procedure TLUFTP.UploadUnique(const FileName: string);
begin
   FFTP.UploadUnique(FileName);
end;

procedure TLUFTP.Download(const FileName: string);
begin
   FFTP.Download(FileName, FileName);
end;

end.
