{=======================================================}
{ Project:                                              }
{         Delphi VCL Extensions (LU)                    }
{         Copyright (c) 2000 Central Bank Of Russia     }
{ Subject:                                              }
{         MAPI                                          }
{ Author:                                               }
{         Lisitsin Y.R.                                 }
{=======================================================}

unit LUMail;

interface

uses
   SysUtils, WinTypes, ComObj,
   LUSupport, LUExec, LUStrUtils;

function SendMessageOutlook(const aTo,aSubject,aText,aFiles: string): Boolean;
function SendMail(const aTo,aSubject,aText,aFiles: string;
                  const aPowerShell,aScript,aServer,aAddressFROM: string): Boolean;

implementation

const
   cPowerShell = 'C:\Windows\System32\WindowsPowerShell\v1.0\powershell.exe';
   cScript = 'K:\BANCOM\BAT\send.ps1';
   cServer = 'mail.ulnsk.cbr.ru';
   cAddressFROM = 'services@ulnsk.cbr.ru';

   (*
   RunMailer(LAdressTO, 'Вам пришло сообщение из БАНКОМ по форме '+FBANCOMMessage.TaskName+'. Откройте БАНКОМ Клиент');
   *)
   
   (*
   Lbuffer := 'mailto://' + LAdressTO;
   ShellExecute(Application.Handle, nil, PChar(Lbuffer), nil, nil, SW_SHOWNORMAL);
   *)

function SendMessageOutlook(const aTo,aSubject,aText,aFiles: string): Boolean;
const
   olMailItem = 0;
   olByValue = 1;
var
   LOutlookApp, LMailItem, LMyAttachments: OLEVariant;
   i: Integer;
   LFile: string;
begin
   Result := False;
   try
     LOutlookApp := GetActiveOleObject('Outlook.Application');
//WriteLN ('GetActiveOleObject: Outlook.Application');
   except
     LOutlookApp := CreateOleObject('Outlook.Application');
//WriteLN ('GetActiveOleObject: Outlook.Application');
   end;
   try
      LMailItem := LOutlookApp.CreateItem(olMailItem);
      LMailItem.Recipients.Add (aTO);
//WriteLN (aTO);
      LMailItem.Subject := aSubject;
//WriteLN (aSubject);
      LMailItem.Body := aText;
//WriteLN (aText);
      LmyAttachments := LMailItem.Attachments;
      for i:=1 to WordCountNew(aFiles, [';']) do begin
         LFile := UpperCase(Trim(ExtractWordNew(i,aFiles,[';'])));
         if FileExists(LFile) then begin
            LmyAttachments.Add (LFile, olByValue, 1, LFile);
         end;
      end;
//WriteLN ('Send: Begin');
      LMailItem.Send;
//WriteLN ('Send: End');
   finally
      LmyAttachments := VarNull;
      LOutlookApp    := VarNull;
      Result := True;
   end;
//WriteLN ('End');
end;

function SendMail(const aTo,aSubject,aText,aFiles: string;
                  const aPowerShell,aScript,aServer,aAddressFROM: string): Boolean;
var
   s: string;
   LWorkDir: string;
   LSubject: string;
   LStatus: Cardinal;
begin
   Result := False;
   if FileExists(aPowerShell) then begin
      if (aTO <> '') then begin
         LWorkDir := GetCurrentDir;
         LSubject := aSubject;
         s := '-command & '+aScript+' '+aServer+' '+aAddressFROM+' '''+aTO+''' '''+aText+''' '''+LSubject+'''';
         if (Trim(aFiles) <> '') {and FileExists(aFiles)} then begin
            s := s+' '''+aFiles+'''';
         end;
         //WriteLN('start');
         //WriteLN(s);
         WinExecAndWait(aPowerShell, s, LWorkDir, True, SW_HIDE, LStatus, 0, 30, 0);
         //WriteLN('end');
      end;
      Result := (LStatus = 0);
      end
   else begin
   end;
end;

end.
