(*
 =======================================================
 Copyright (c) 2023
 Author:
     Lisitsin Y.R.
 Project:
     LU_PAS
     Delphi VCL Extensions (LU)
 Module:
     LUCliboard
     Процедуры
 =======================================================
*)

unit LUCliboard;

interface

uses
    {}
        ComCtrls, SysUtils, Forms, Windows, Graphics, VCL.Dialogs, Messages,
    Classes, Menus, StdCtrls, Controls, Buttons, VCL.Clipbrd,
    {}
    RxToolEdit,
    {}
    LUObjects, LUSupport, LUScanDir;

{ Cliboard }
{ ----------------------------------- }
{ 01. }
{ ----------------------------------- }
const
    // WM_CLIPBOARDUPDATE is not defined in the Messages unit of all supported
    // versions of Delphi, so we defined it here for safety.
    WM_CLIPBOARDUPDATE = $031D;
const
    cUserKernelLib = 'user32.dll';
var
    (*
    Flag indicating if the new style clipboard format listener API is
    available on the current OS.
 *)
    fUseNewAPI: Boolean = False;
    (*
    Handle of next clipboard viewer handle in chain. Used only when old
    clipboard viewer API is in use, i.e. when fUseNewAPI is False.
    *)
    fNextCBViewWnd: HWND = 0;
    (*
    References to AddClipboardFormatListener and
    RemoveClipboardFormatListenerAPI functions. These references are nil if
    the functions are not supported by the OS, i.e. if fUseNewAPI is False.
    *)
    fAddClipboardFormatListener: function(HWND: HWND): BOOL; stdcall;
    fRemoveClipboardFormatListener: function(HWND: HWND): BOOL; stdcall;
    (*
    References to SetClipboardViewer and ChangeClipboardChain API functions.
    These references is are if the newer clipboard format listener API is
    available, i.e. if fUseNewAPI is True.
    *)
    fSetClipboardViewer: function(hWndNewViewer: HWND): HWND; stdcall;
    fChangeClipboardChain: function(hWndRemove, hWndNewNext: HWND)
        : BOOL; stdcall;

{ Cliboard }
{ ----------------------------------- }
{ 01. }
{ ----------------------------------- }
procedure Load_required_API_functions_01 (Handle: Cardinal);
{ Message handlers }
procedure WMClipboardUpdate (var Msg: TMessage); // message WM_CLIPBOARDUPDATE;
procedure WMChangeCBChain (var Msg: TMessage); // message WM_CHANGECBCHAIN;
procedure WMDrawClipboard (var Msg: TMessage); // message WM_DRAWCLIPBOARD;

implementation

procedure Load_required_API_functions_01 (Handle: Cardinal);
begin
    (*
    Load required API functions: 1st try to load modern clipboard listener API
    functions. If that fails try to load old-style clipboard viewer API
    functions. This should never fail, but we raise an exception if the
    impossible happens!
    *)
    fAddClipboardFormatListener :=
        GetProcAddress (GetModuleHandle(cUserKernelLib),
        'AddClipboardFormatListener');
    fRemoveClipboardFormatListener :=
        GetProcAddress (GetModuleHandle(cUserKernelLib),
        'RemoveClipboardFormatListener');
    fUseNewAPI := Assigned (fAddClipboardFormatListener) and
        Assigned (fRemoveClipboardFormatListener);
    if not fUseNewAPI then
    begin
        fSetClipboardViewer := GetProcAddress (GetModuleHandle(cUserKernelLib),
            'SetClipboardViewer');
        fChangeClipboardChain :=
            GetProcAddress (GetModuleHandle(cUserKernelLib),
            'ChangeClipboardChain');
        Assert (Assigned(fSetClipboardViewer) and
            Assigned(fChangeClipboardChain));
    end;
    if fUseNewAPI then
    begin
        { Register window as clipboard listener }
        if not fAddClipboardFormatListener (Handle) then
            RaiseLastOSError;
        { On early Delphis use RaiseLastWin32Error instead }
    end else begin
        { Register window as clipboard viewer, storing handle of next window in chain }
        fNextCBViewWnd := fSetClipboardViewer (Handle);
    end;
end;

procedure WMChangeCBChain (var Msg: TMessage);
begin
    Assert (not fUseNewAPI);
    { Windows is detaching a clipboard viewer }
    if HWND (Msg.WParam) = fNextCBViewWnd then
        { window being detached is next one: record new "next" window }
        fNextCBViewWnd := HWND (Msg.LParam)
    else if fNextCBViewWnd <> 0 then
        { window being detached is not next: pass message along }
        SendMessage (fNextCBViewWnd, Msg.Msg, Msg.WParam, Msg.LParam);
end;

procedure WMClipboardUpdate (var Msg: TMessage);
begin
    { Clipboard content changed: enable paste button if text is on clipboard }
    // btnPaste.Enabled := Clipboard.HasFormat(CF_TEXT);
end;

procedure WMDrawClipboard (var Msg: TMessage);
begin
    Assert (not fUseNewAPI);
    { Clipboard content changed }
    { enable paste button if text on clipboard }
    // btnPaste.Enabled := Clipboard.HasFormat(CF_TEXT);
    { pass on message to any next window in viewer chain }
    if fNextCBViewWnd <> 0 then
        SendMessage (fNextCBViewWnd, Msg.Msg, Msg.WParam, Msg.LParam);
end;


end.
