(*
$----------------------------------------------------------------------------$
   $Workfile:   nwsnapin.h  $
   $Revision:   1.33  $
    $Modtime:   01 Apr 1996 15:57:42  $
$----------------------------------------------------------------------------$
   Copyright (c) 1989-1996 Novell, Inc.  All Rights Reserved.

   THIS WORK IS SUBJECT TO U.S. AND INTERNATIONAL COPYRIGHT LAWS AND
   TREATIES. NO PART OF THIS WORK MAY BE USED, PRACTICED, PERFORMED
   COPIED, DISTRIBUTED, REVISED, MODIFIED, TRANSLATED, ABRIDGED, CONDENSED,
   EXPANDED, COLLECTED, COMPILED, LINKED, RECAST, TRANSFORMED OR ADAPTED
   WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC. ANY USE OR EXPLOITATION
   OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT THE PERPETRATOR TO
   CRIMINAL AND CIVIL LIABILITY.$
$----------------------------------------------------------------------------$
*)


{$IFNDEF NWSNAPIN_H}

{$DEFINE NWSNAPIN_H}

{$I ntypes.inc}
{$I nwdsdefs.inc}

{$IFDEF __cplusplus}

(* TC extern C *)
{$ENDIF}


(*-----------------------------------------------------*)

(* Snapin macros for WIN 3.1 and WIN32 Snapin          *)

(*-----------------------------------------------------*)

{$IFDEF WIN32}

Type NWA_SNAPIN_FLAGS = pnuint;
{$DEFINE NWA_SCROLL_DLL}
Const NWA_SCROLL_DLL = 'muscrl32.dll';
{$ELSE}

Type NWA_SNAPIN_CALLBACK = N_EXTERN_LIBRARY;
Type NWA_SNAPIN_FLAGS = pnuint;
{$DEFINE NWA_SCROLL_DLL}
Const NWA_SCROLL_DLL = 'muscroll.dll';
{$ENDIF}




Type NWASnapinObjectProc = Function (
    objName  :   pnstr8 ;
    message  :   nuint16 ;
    param1  :   nparam ;
    param2  :   nparam 
) : NWRCODE;


Type NWASnapinMenuActionProc = Procedure;


Type NWASnapinMenuValidProc = Procedure (
   x :  pnuint   
); 


Type NWAFlatBrowserProc = Function (
    userParam  :   nuint32 ;
    uMsg  :   nuint16 ;
    param1  :   nparam ;
    param2  :   nparam 
) : nuint32;


Type NWAMVEDProc = Function (
    userParam  :   nuint32 ;
    uMsg  :   nuint16 ;
    param1  :   nparam ;
    param2  :   nparam 
) : nuint32;


Type NWASnapinTBButtonEnableProc = Procedure (
    menuID  :   nint ;
    pfEnabled  :   pnbool 
); 


(*--------------------------------------------------------------------*)

(* Snapin MDI Child Callback and MDI Child Window Callback fn typedef *)

(*--------------------------------------------------------------------*)

Type NWASnapinMDIChildProc = Function (
    viewName  :   pnstr8 ;
    message  :   nuint16 ;
    param1  :   nparam ;
    param2  :   nparam 
) : LongInt;



(*------------------------------------------------------------*)

(* SNAPIN Version related defines                             *)

(*------------------------------------------------------------*)

{$DEFINE NWA_SNAPIN_VER_MAJOR}
Const NWA_SNAPIN_VER_MAJOR = 1;
{$DEFINE NWA_SNAPIN_VER_MINOR}
Const NWA_SNAPIN_VER_MINOR = 1;
{$DEFINE NWA_SNAPIN_VER_REVISION}
Const NWA_SNAPIN_VER_REVISION = 0;
(* TC #define NWA_SNAPIN_VERSION NMake32 ( NMake16 ( NWA_SNAPIN_VER_REVISION , 0 ) , NMake16 ( NWA_SNAPIN_VER_MINOR , NWA_SNAPIN_VER_MAJOR ) )  *)

(*------------------------------------------------------------*)

(* View Names                                                 *)

(*------------------------------------------------------------*)

{$DEFINE NWA_VIEW_CONSOLE}
Const NWA_VIEW_CONSOLE = 'ListMenu';
{$DEFINE NWA_VIEW_BROWSER}
Const NWA_VIEW_BROWSER = 'BROWSER';

(*--------------------------------------------*)

(*   messages from nwadmin to object snapins  *)

(*--------------------------------------------*)

{$DEFINE NWA_MSG_INITSNAPIN}
Const NWA_MSG_INITSNAPIN = $0100;
{$DEFINE NWA_MSG_CLOSESNAPIN}
Const NWA_MSG_CLOSESNAPIN = $0101;
{$DEFINE NWA_MSG_CREATEOBJECT}
Const NWA_MSG_CREATEOBJECT = $0102;
{$DEFINE NWA_MSG_GETPAGECOUNT}
Const NWA_MSG_GETPAGECOUNT = $0103;
{$DEFINE NWA_MSG_REGISTERPAGE}
Const NWA_MSG_REGISTERPAGE = $0104;
{$DEFINE NWA_MSG_RENAME}
Const NWA_MSG_RENAME = $0105;
{$DEFINE NWA_MSG_MODIFY}
Const NWA_MSG_MODIFY = $0106;
{$DEFINE NWA_MSG_QUERYDELETE}
Const NWA_MSG_QUERYDELETE = $0107;
{$DEFINE NWA_MSG_QUERYCOPY}
Const NWA_MSG_QUERYCOPY = $0108;
{$DEFINE NWA_MSG_QUERYMOVE}
Const NWA_MSG_QUERYMOVE = $0109;
{$DEFINE NWA_MSG_GETVALIDOPERATIONS}
Const NWA_MSG_GETVALIDOPERATIONS = $0110;
{$DEFINE NWA_MSG_MPEWCLOSE}
Const NWA_MSG_MPEWCLOSE = $0111;
{$DEFINE NWA_MSG_NOTIFYDELETE}
Const NWA_MSG_NOTIFYDELETE = $0112;
{$DEFINE NWA_MSG_NOTIFYMOVE}
Const NWA_MSG_NOTIFYMOVE = $0113;
{$DEFINE NWA_MSG_NOTIFYRENAME}
Const NWA_MSG_NOTIFYRENAME = $0114;
{$DEFINE NWA_MSG_NOTIFYCREATEOBJECT}
Const NWA_MSG_NOTIFYCREATEOBJECT = $0115;


(*-------------------------------------------------------------------*)

(* Mpew Messages to support Object Create Template, Generic attr     *)

(* details, Multiple Object Details                                  *)

(*-------------------------------------------------------------------*)

{$DEFINE NWA_MSG_QUERYAPPLYTEMPLATE}
Const NWA_MSG_QUERYAPPLYTEMPLATE = $0116;
{$DEFINE NWA_MSG_APPLYTEMPLATE}
Const NWA_MSG_APPLYTEMPLATE = $0117;
{$DEFINE NWA_MSG_MULTIOBJ_COUNT}
Const NWA_MSG_MULTIOBJ_COUNT = $0118;
{$DEFINE NWA_MSG_MULTIOBJ_NAME}
Const NWA_MSG_MULTIOBJ_NAME = $0119;
{$DEFINE NWA_MSG_GENATTR_GETCOUNT}
Const NWA_MSG_GENATTR_GETCOUNT = $011A;
{$DEFINE NWA_MSG_GENATTR_GETATTR}
Const NWA_MSG_GENATTR_GETATTR = $011B;

(*------------------------------------------------------------------------*)

(* Snapin Messages to MDI Child Proc to Clear, Save, and Restore Settings *)

(*------------------------------------------------------------------------*)


{$DEFINE NWA_MSG_MDICHILD_CREATED}
Const NWA_MSG_MDICHILD_CREATED = $011C;
{$DEFINE NWA_MSG_MDICHILD_CLEARSETTINGS}
Const NWA_MSG_MDICHILD_CLEARSETTINGS = $011D;
{$DEFINE NWA_MSG_MDICHILD_SAVESETTINGS}
Const NWA_MSG_MDICHILD_SAVESETTINGS = $011E;
{$DEFINE NWA_MSG_MDICHILD_RESTORE}
Const NWA_MSG_MDICHILD_RESTORE = $011F;


{$DEFINE NWA_MSG_SNAPINMDICHILD_NOTIFY}
Const NWA_MSG_SNAPINMDICHILD_NOTIFY = $160;



(*----------------------------------------------*)

(*    message from snapin page to its parent    *)

(*----------------------------------------------*)

{$DEFINE NWA_WM_SETPAGEMODIFY}
Const NWA_WM_SETPAGEMODIFY = $120;

{$DEFINE NWA_WM_CANCLOSE}
Const NWA_WM_CANCLOSE = $121;

(*--------------------------------------------------------------*)

(* F1 help message to all snapin dialogs                        *)

(* MPEW also sends the same message when Help button is pressed *)

(*--------------------------------------------------------------*)

(* TC #define NWA_WM_F1HELP ( WM_USER + $139 )  *)

{$DEFINE NWA_MENU_BASE}
Const NWA_MENU_BASE = $1000;

(*--------------------------------------------------------------*)

(* Messages passed to Flat Browser Proc                         *)

(*--------------------------------------------------------------*)

{$DEFINE NWA_MSG_FBOBJECT_COUNT}
Const NWA_MSG_FBOBJECT_COUNT = $0200;
{$DEFINE NWA_MSG_FBOBJECT_VALUE}
Const NWA_MSG_FBOBJECT_VALUE = $0201;
{$DEFINE NWA_MSG_FBFILTER_COUNT}
Const NWA_MSG_FBFILTER_COUNT = $0202;
{$DEFINE NWA_MSG_FBFILTER_VALUE}
Const NWA_MSG_FBFILTER_VALUE = $0203;
{$DEFINE NWA_MSG_FBSET_HELP}
Const NWA_MSG_FBSET_HELP = $0204;
{$DEFINE NWA_MSG_FBSET_CAPTION}
Const NWA_MSG_FBSET_CAPTION = $0205;

(*----------------------------------------------*)

(* General message from snapin view to parent   *)

(*----------------------------------------------*)

(* TC #define NWA_MSG_IVEGOTFOCUS ( WM_USER + $140 )  *)

(*----------------------------------------------*)

(* Status Bar messages - snapin view to parent  *)

(*----------------------------------------------*)

(* TC #define NWA_MSG_STATUSBAR_ADDITEM ( WM_USER + $141 )  *)
(* TC #define NWA_MSG_STATUSBAR_SETITEMTEXT ( WM_USER + $142 )  *)

(*----------------------------------------------*)

(* Status Bar messages - parent to snapin view  *)

(*----------------------------------------------*)

Const WM_USER = $0400;
 NWA_MSG_STATUSBAR_ADDPREFITEM =( WM_USER + $143 );
 NWA_MSG_STATUSBAR_NEWACTIVEITEMS = ( WM_USER + $144 );
 NWA_MSG_STATUSBAR_POPULATE =( WM_USER + $145 );
 NWA_MSG_STATUSBAR_QUERYITEMCOUNT =( WM_USER + $146 );
 NWA_MSG_STATUSBAR_QUERYACTIVECOUNT =( WM_USER + $147 );
 NWA_MSG_STATUSBAR_QUERYACTIVEITEMS =( WM_USER + $148 );
 NWA_MSG_STATUSBAR_DBLCLK =( WM_USER + $149 );

(*----------------------------------------------*)

(* ToolBar messages - snapin view to parent     *)

(*----------------------------------------------*)

NWA_MSG_TOOLBAR_ADDITEM =( WM_USER + $14A );
NWA_MSG_TOOLBAR_GETBUTTONSTATE =( WM_USER + $14B );
NWA_MSG_TOOLBAR_GETBUTTONTYPE =( WM_USER + $14C );
NWA_MSG_TOOLBAR_SETBUTTONSTATE =( WM_USER + $14D );

(*----------------------------------------------*)

(* ToolBar messages - parent to snapin view     *)

(*----------------------------------------------*)

 NWA_MSG_TOOLBAR_ADDPREFITEM =( WM_USER + $14E );
 NWA_MSG_TOOLBAR_NEWACTIVEITEMS =( WM_USER + $14F );
 NWA_MSG_TOOLBAR_POPULATE =( WM_USER + $150 );
 NWA_MSG_TOOLBAR_QUERYENABLEBUTTON =( WM_USER + $151 );
 NWA_MSG_TOOLBAR_QUERYACTIVECOUNT =( WM_USER + $152 );
 NWA_MSG_TOOLBAR_QUERYACTIVEITEMS =( WM_USER + $153 );
 NWA_MSG_TOOLBAR_QUERYITEMCOUNT =( WM_USER + $154 );

(*----------------------------------------------------------------*)

(* Flags or-ed to specify options for Flat Browser                *)

(*----------------------------------------------------------------*)

{$DEFINE NWA_FB_BROWSE_PUBLIC}
Const NWA_FB_BROWSE_PUBLIC = $00000001;
{$DEFINE NWA_FB_BROWSE_ROOT}
Const NWA_FB_BROWSE_ROOT = $00000002;
{$DEFINE NWA_FB_SINGLE_SELECT}
Const NWA_FB_SINGLE_SELECT = $00000004;
{$DEFINE NWA_FB_MULTIPLE_SELECT}
Const NWA_FB_MULTIPLE_SELECT = $00000008;
{$DEFINE NWA_FB_NONDS_VOLUMES}
Const NWA_FB_NONDS_VOLUMES = $00000010;
{$DEFINE NWA_FB_EXPAND_VOLUMES}
Const NWA_FB_EXPAND_VOLUMES = $00000020;


(*----------------------------------------------------------------*)

(* edit Types for MVED Control                                    *)

(*----------------------------------------------------------------*)

{$DEFINE NWA_MVED_VALUE_STRING}
Const NWA_MVED_VALUE_STRING = $0000;
{$DEFINE NWA_MVED_VALUE_READONLY}
Const NWA_MVED_VALUE_READONLY = $0001;
{$DEFINE NWA_MVED_VALUE_DISTNAME}
Const NWA_MVED_VALUE_DISTNAME = $0002;
{$DEFINE NWA_MVED_VALUE_DIGITSONLY}
Const NWA_MVED_VALUE_DIGITSONLY = $0004;
{$DEFINE NWA_MVED_VALUE_PRINTABLE}
Const NWA_MVED_VALUE_PRINTABLE = $0005;

(*----------------------------------------------------------------*)

(* Message passed to MVED callback proc                           *)

(*----------------------------------------------------------------*)

{$DEFINE NWA_MSG_MVED_INITCOUNT}
Const NWA_MSG_MVED_INITCOUNT = $300;
{$DEFINE NWA_MSG_MVED_INITVALUE}
Const NWA_MSG_MVED_INITVALUE = $301;




(*----------------------------------------------------------*)

(* return values from snapins to admin and admin to snapin  *)

(*----------------------------------------------------------*)

{$DEFINE NWA_RET_SUCCESS}
Const NWA_RET_SUCCESS = 0;
{$DEFINE NWA_RET_DODEFAULT}
Const NWA_RET_DODEFAULT = 1;
{$DEFINE NWA_RET_SHOWDETAILS}
Const NWA_RET_SHOWDETAILS = 2;
{$DEFINE NWA_RET_CREATEANOTHER}
Const NWA_RET_CREATEANOTHER = 3;
{$DEFINE NWA_RET_USETEMPLATE}
Const NWA_RET_USETEMPLATE = 4;
{$DEFINE NWA_RET_USENOTEMPLATE}
Const NWA_RET_USENOTEMPLATE = 5;


{$DEFINE NWA_ERR_ERROR}
Const NWA_ERR_ERROR = 1;
{$DEFINE NWA_ERR_NO_MEMORY}
Const NWA_ERR_NO_MEMORY = 901;
{$DEFINE NWA_ERR_DUPLICATE_ENTRY}
Const NWA_ERR_DUPLICATE_ENTRY = 902;
{$DEFINE NWA_ERR_UNKNOWN_ERROR}
Const NWA_ERR_UNKNOWN_ERROR = 903;
{$DEFINE NWA_ERR_INVALID_STRING_PARAMETER}
Const NWA_ERR_INVALID_STRING_PARAMETER = 904;
{$DEFINE NWA_ERR_INVALID_BITMAP_PARAMETER}
Const NWA_ERR_INVALID_BITMAP_PARAMETER = 905;
{$DEFINE NWA_ERR_INVALID_BITMAP_POINTER_PARAMETER}
Const NWA_ERR_INVALID_BITMAP_POINTER_PARAMETER = 906;
{$DEFINE NWA_ERR_INSUFFICIENT_STRING_BUFFER}
Const NWA_ERR_INSUFFICIENT_STRING_BUFFER = 907;
{$DEFINE NWA_ERR_CLASSNAME_TABLE_NOT_INITIALIZED}
Const NWA_ERR_CLASSNAME_TABLE_NOT_INITIALIZED = 908;
{$DEFINE NWA_ERR_ATTRNAME_TABLE_NOT_INITIALIZED}
Const NWA_ERR_ATTRNAME_TABLE_NOT_INITIALIZED = 909;
{$DEFINE NWA_ERR_BITMAP_TABLE_NOT_INITIALIZED}
Const NWA_ERR_BITMAP_TABLE_NOT_INITIALIZED = 910;
{$DEFINE NWA_ERR_ALIAS_BITMAP_TABLE_NOT_INITIALIZED}
Const NWA_ERR_ALIAS_BITMAP_TABLE_NOT_INITIALIZED = 911;
{$DEFINE NWA_ERR_CLASSNAME_NOT_FOUND}
Const NWA_ERR_CLASSNAME_NOT_FOUND = 912;
{$DEFINE NWA_ERR_ATTRNAME_NOT_FOUND}
Const NWA_ERR_ATTRNAME_NOT_FOUND = 913;
{$DEFINE NWA_ERR_BITMAP_NOT_FOUND}
Const NWA_ERR_BITMAP_NOT_FOUND = 914;
{$DEFINE NWA_ERR_IS_BAD_STRING_POINTER}
Const NWA_ERR_IS_BAD_STRING_POINTER = 915;
{$DEFINE NWA_ERR_INVALID_PARAMETER}
Const NWA_ERR_INVALID_PARAMETER = 916;
{$DEFINE NWA_ERR_LAUNCH_FBROWSER}
Const NWA_ERR_LAUNCH_FBROWSER = 917;
{$DEFINE NWA_ERR_FUNCTION_FAILED}
Const NWA_ERR_FUNCTION_FAILED = 918;
{$DEFINE NWA_ERR_INVALID_CALLBACK_PROC}
Const NWA_ERR_INVALID_CALLBACK_PROC = 919;
{$DEFINE NWA_ERR_INVALID_MODULE_HANDLE}
Const NWA_ERR_INVALID_MODULE_HANDLE = 920;
{$DEFINE NWA_ERR_INVALID_SNAPIN_VERSION}
Const NWA_ERR_INVALID_SNAPIN_VERSION = 921;
{$DEFINE NWA_ERR_DUPLICATE_TOOLBAR_BUTTON_NAME}
Const NWA_ERR_DUPLICATE_TOOLBAR_BUTTON_NAME = 922;
{$DEFINE NWA_ERR_INVALID_MENUID}
Const NWA_ERR_INVALID_MENUID = 923;
{$DEFINE NWA_ERR_INVALID_INSTANCE_HANDLE}
Const NWA_ERR_INVALID_INSTANCE_HANDLE = 924;
{$DEFINE NWA_ERR_INVALID_STRING_RESOURCE_ID}
Const NWA_ERR_INVALID_STRING_RESOURCE_ID = 925;
{$DEFINE NWA_ERR_INVALID_STRUCT_SIZE}
Const NWA_ERR_INVALID_STRUCT_SIZE = 926;
{$DEFINE NWA_ERR_INVALID_CLASSNAME}
Const NWA_ERR_INVALID_CLASSNAME = 927;
{$DEFINE NWA_ERR_INVALID_SNAPINFLAG}
Const NWA_ERR_INVALID_SNAPINFLAG = 928;
{$DEFINE NWA_ERR_MAX_MDICHILDWINDOWS_EXCEEDED}
Const NWA_ERR_MAX_MDICHILDWINDOWS_EXCEEDED = 929;
{$DEFINE NWA_ERR_INVALID_CLASSTYPE}
Const NWA_ERR_INVALID_CLASSTYPE = 930;
{$DEFINE NWA_ERR_FILE_NOT_FOUND}
Const NWA_ERR_FILE_NOT_FOUND = 931;
{$DEFINE NWA_ERR_ITEM_NOT_FOUND}
Const NWA_ERR_ITEM_NOT_FOUND = 932;
{$DEFINE NWA_ERR_BROWSER_NOT_ACTIVE}
Const NWA_ERR_BROWSER_NOT_ACTIVE = 933;

(*------------------------------------------------------------*)

(* snapins should '|' operations they support and             *)

(* return in response to NWAD_GETVALIDOPERATIONS              *)

(*------------------------------------------------------------*)

{$DEFINE NWA_OP_DSTYPE}
Const NWA_OP_DSTYPE = $00000001;
{$DEFINE NWA_OP_FSTYPE}
Const NWA_OP_FSTYPE = $00000002;
{$DEFINE NWA_OP_CREATE}
Const NWA_OP_CREATE = $00000004;
{$DEFINE NWA_OP_DETAILS}
Const NWA_OP_DETAILS = $00000008;
{$DEFINE NWA_OP_MOVE}
Const NWA_OP_MOVE = $00000010;
{$DEFINE NWA_OP_COPY}
Const NWA_OP_COPY = $00000020;
{$DEFINE NWA_OP_RENAME}
Const NWA_OP_RENAME = $00000040;
{$DEFINE NWA_OP_DELETE}
Const NWA_OP_DELETE = $00000080;
{$DEFINE NWA_OP_USERTEMPLATE}
Const NWA_OP_USERTEMPLATE = $00000100;
{$DEFINE NWA_OP_SEARCH}
Const NWA_OP_SEARCH = $00000200;
{$DEFINE NWA_OP_CONTAINER}
Const NWA_OP_CONTAINER = $00000400;
Type dlgproc = Function ( x:nuint32; y:nuint32; z:nuint32; a:nuint32) : nuint32;

Type
    tagNWAPageStruct = Record
        dlgProc  :   DLGPROC ;
        hDLL  :   HINSTANCE ;
        resName  :   LPSTR ;
        pageTitle  :   LPSTR ;
        initParam  :   LPARAM ;
    End;
    NWAPageStruct = tagNWAPageStruct;


{$DEFINE NWA_MAX_TRANSLATED_NAME}
Const NWA_MAX_TRANSLATED_NAME = 256;
Const NWA_MAX_CLASS_NAME = MAX_SCHEMA_NAME_BYTES;
Const NWA_MAX_CLASS_TYPE = MAX_SCHEMA_NAME_BYTES;
Const NWA_MAX_OBJECT_NAME = MAX_DN_BYTES;
{$DEFINE NWA_DS_OBJECT_TYPE}
Const NWA_DS_OBJECT_TYPE = 'DS';
{$DEFINE NWA_FS_OBJECT_TYPE}
Const NWA_FS_OBJECT_TYPE = 'FS';
{$DEFINE NWA_MAX_PATH_SIZE}
Const NWA_MAX_PATH_SIZE = 324;


(*--------------------------------------------------------------------*)

(* Snapin MDI Child class name max length and dev info max len        *)

(*--------------------------------------------------------------------*)


{$DEFINE NWA_MAX_CLASSNAMELENGTH}
Const NWA_MAX_CLASSNAMELENGTH = 32;
{$DEFINE NWA_MAX_DEVINFOLENGTH}
Const NWA_MAX_DEVINFOLENGTH = 128;


Type
    tagNWASelObject = Record
        objType  :  Array[0..NWA_MAX_CLASS_TYPE-1] Of nint8;
        objClass  :  Array[0..NWA_MAX_CLASS_NAME-1] Of nint8;
        objName  :  Array[0..NWA_MAX_OBJECT_NAME-1] Of nint8;
    End;
    NWASelObject = tagNWASelObject;
    PNWASelObject = ^tagNWASelObject;


(*----------------------------------------------------------------------*)

(* Definitions and structures for snapin toolbar and status bar support *)

(*----------------------------------------------------------------------*)

{$DEFINE TBID_SEPARATOR}
Const TBID_SEPARATOR = 3;

Const
TBUp = 0;
TBDown = 1;
TBIndeterminate = 2;
Type TBState = 0..2;


Const
TBCommand = 0;
TBToggle = 1;
TBUnknown = 2;
Type TBType = 0..2;


Type
    NWAToolBarItemStruct = Record
        lStructSize  :   nuint32 ;
        hResourceDLL  :   HINSTANCE ;
        menuId  :   nint ;
        hintId  :   nint ;
        bitmapId  :   nint ;
        toolTipStrId  :   nint ;
        buttonState  :   TBState ;
        buttonType  :   TBType ;
        fEnabled  :   nbool ;
    End;


Type
    NWAToolBarPrefItemStruct = Record
        lStructSize  :   nuint32 ;
        menuId  :   nint ;
        hResourceDLL  :   HINSTANCE ;
        itemStrId  :   nint ;
        hintStrId  :   nint ;
        bitmapId  :   nint ;
    End;


Type
    NWAStatusBarItemStruct = Record
        lStructSize  :   nuint32 ;
        itemId  :   nint ;
        maxChars  :   nuint ;
        pszText  :   pnstr8 ;
    End;



Type
    NWAStatusBarPrefItemStruct = Record
        lStructSize  :   nuint32 ;
        itemId  :   nint ;
        hResourceDLL  :   HINSTANCE ;
        textResId  :   nint ;
        hintResId  :   nint ;
        maxChars  :   nuint ;
    End;


{$DEFINE TBSNAPINVIEW}
Const TBSNAPINVIEW = 'ToolBarSnapinView';



{$DEFINE NWA_MAX_MENUITEMNAME_LEN}
Const NWA_MAX_MENUITEMNAME_LEN = 64;
{$DEFINE NWA_MAX_MENUITEMHINT_LEN}
Const NWA_MAX_MENUITEMHINT_LEN = 128;

(*-------------------------------------------------------------------*)

(* Snapin Tools menu item struct                                     *)

(*-------------------------------------------------------------------*)

Type
    tagNWAToolsMenuItem = Record
        structSize  :   nuint32 ;
        parentMenuId  :   nuint ;
        menuId  :   nuint ;
        menuOption  :   nuint ;
        szMenuText  :  Array[0..NWA_MAX_MENUITEMNAME_LEN-1] Of nint8;
        szMenuHintText  :  Array[0..NWA_MAX_MENUITEMHINT_LEN-1] Of nint8;
    End;
    NWAToolsMenuItem = tagNWAToolsMenuItem;


(*-------------------------------------------------------------------*)

(* Create MDI Child param structure                                  *)

(*-------------------------------------------------------------------*)

(* Type
    tagNWACreateMDIChildParam = Record
        structSize  :   nuint32 ;
        wndpl  :   WINDOWPLACEMENT ;
    End;
    NWACreateMDIChildParam = tagNWACreateMDIChildParam;*)



(* prototypes *)


(* TC  int FAR PASCAL InitSnapin ( void );  *)

(* TC  void FAR PASCAL PostInitSnapin ( HWND hwndAdmin );  *)

(* TC  void FAR PASCAL ShutDown ( void );  *)

(* TC  nbool FAR PASCAL CanCloseSnapin ( void );  *)


Function NWAGetSelObjectCount (
    lpCount  :   pnint32 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWAGetSelObject (
    index  :   nint32 ;
    selObject  :   PNWASelObject 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWARegisterObjectProc (
    classType  :   pnstr8 ;
    className  :   pnstr8 ;
    developerInfo  :   pnstr8 ;
    hDLL  :   HINSTANCE ;
    proc  :   NWASnapinObjectProc ;
    version  :   nuint32 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWARegisterMenu (
    viewName  :   pnstr8 ;
    menuParentId  :   nuint16 ;
    menuParent  :   pnstr8 ;
    menuOption  :   nuint16 ;
    pmenuID  :   pnuint ;
    menuString  :   pnstr8 ;
    menuHint  :   pnstr8 ;
    menuActionProc  :   NWASnapinMenuActionProc ;
    menuValidProc  :   NWASnapinMenuValidProc ;
    version  :   nuint32 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*------------------------------------------------------------------*)

(*             translation and bitmap table functions               *)

(*------------------------------------------------------------------*)

Function NWAAddClassData (
    pszClassName  :   LPCSTR ;
    pszTranslation  :   LPCSTR ;
    hClassBitmap  :   HBITMAP ;
    hClassAliasBitmap  :   HBITMAP ;
    hClassROBitmap  :   HBITMAP 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWARemoveClassData (
    pszClassName  :   LPCSTR ;
    Var phClassBitmap  : HBITMAP;
    Var phClassAliasBitmap  : HBITMAP;
    Var phClassROBitmap  : HBITMAP
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWAGetTranslatedClassName (
    pszClassName  :   LPCSTR ;
    pszTranslation  :   pnstr8 ;
    nMaxLen  :   nint16 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWAGetClassBitmap (
    pszClassName  :   LPCSTR ;
    Var phBitmap  : HBITMAP
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWAGetClassAliasBitmap (
    pszClassName  :   LPCSTR ;
    Var phBitmap  : HBITMAP
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWAGetClassReadOnlyBitmap (
    pszClassName  :   LPCSTR ;
    Var phBitmap  : HBITMAP
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWAAddPropertyNameTranslation (
    pszPropertyName  :   LPCSTR ;
    pszClassName  :   LPCSTR ;
    pszTranslation  :   LPCSTR 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWAGetTranslatedPropertyName (
    pszPropertyName  :   LPCSTR ;
    pszClassName  :   LPCSTR ;
    pszTranslation  :   pnstr8 ;
    nMaxLen  :   nint16 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWARemovePropertyNameTranslation (
    pszPropertyName  :   LPCSTR ;
    pszClassName  :   LPCSTR 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*------------------------------------------------------------------*)

(*         Launch DS and FS flat browser functions                  *)

(*------------------------------------------------------------------*)

(*  Every call to NWACommonStartUp must be matched by a similar     *)

(*  call to NWACommonShutDown.  These functions need only be called *)

(*  in 16-bit snapins and only if NWALaunchDSFlatBrowser is being   *)

(*  called outside of the NetWare Administrator.  In this event     *)

(*  only the NWCOMNxx.DLL is required to run.                       *)

(*------------------------------------------------------------------*)


Procedure NWACommonStartUp;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}

Procedure NWACommonShutDown;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}



Function NWALaunchDSFlatBrowser (
    hwndParent  :   HWND ;
    userParam  :   nuint32 ;
    contextStr  :   LPSTR ;
    selObjectStr  :   LPCSTR ;
    navObjectStr  :   LPCSTR ;
    selObjectLabel  :   LPCSTR ;
    brwsFlags  :   nuint32 ;
    pfn  :   NWAFlatBrowserProc 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWALaunchFSFlatBrowser (
    hwndParent  :   HWND ;
    userParam  :   nuint32 ;
    dsContextStr  :   LPSTR ;
    fsContextStr  :   LPSTR ;
    selObjectStr  :   LPCSTR ;
    navObjectStr  :   LPCSTR ;
    selObjectLabel  :   LPCSTR ;
    brwsFlags  :   nuint32 ;
    pfn  :   NWAFlatBrowserProc 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*------------------------------------------------------------------*)

(*  Launch MVED functions                                           *)

(*------------------------------------------------------------------*)

Function NWACreateMved (
    hwndParent  :   HWND ;
    userParam  :   nuint32 ;
    idEdit  :   nuint16 ;
    idSpin  :   nuint16 ;
    idButton  :   nuint16 ;
    editType  :   nuint16 ;
    lengthEdit  :   nuint16 ;
    label1  :   LPCSTR ;
    contextStr  :   LPCSTR ;
    brwsFlags  :   nuint32 ;
    pfn  :   NWAMVEDProc 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWAGetMvedCount (
    hwndParent  :   HWND ;
    idEdit  :   nuint32 ;
    pCount  :   pnuint16 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWAGetMvedValue (
    hwndParent  :   HWND ;
    idEdit  :   nuint16 ;
    itemIndex  :   nuint16 ;
    bufSize  :   nuint16 ;
    pValue  :   pnstr 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*------------------------------------------------------------------*)

(*    NWAdmin and Snapin Interface Version Functions                *)

(*------------------------------------------------------------------*)


Function NWAGetNWAdminVersion (
    pVersion  :   pnuint32 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWAGetConsoleWindowHandle : HWND;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}



(*------------------------------------------------------------------*)

(*    NWAdmin ToolBar Function                                      *)

(*------------------------------------------------------------------*)

{$DEFINE NWA_MAX_SNAPIN_BUTTON_NAME}
Const NWA_MAX_SNAPIN_BUTTON_NAME = 64;

Type
    NWAToolBarRegistrationStruct = Record
        lStructSize  :   nuint32 ;
        nameOfSnapinButton  :   pnstr8 ;
        menuId  :   nint ;
        hResourceDLL  :   HINSTANCE ;
        bitmapId  :   nint ;
        textStrId  :   nint ;
        hintStrId  :   nint ;
        toolTipStrId  :   nint ;
        buttonState  :   TBState ;
        buttonType  :   TBType ;
        enableProc  :   NWASnapinTBButtonEnableProc ;
        version  :   nuint32 ;
    End;



Function NWARegisterToolBarButton (
    Var pStruct  : NWAToolBarRegistrationStruct
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWALaunchConfigDialog : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*-------------------------------------------------------------------*)

(* Snapin MDI Child Register and Create Functions                    *)

(*-------------------------------------------------------------------*)


{$DEFINE NWA_MAX_MDICHILDWINDOWS}
Const NWA_MAX_MDICHILDWINDOWS = 12;

Function NWARegisterMDIChildWindow (
    className  :   LPCSTR ;
    developerInfo  :   LPCSTR ;
    hDLL  :   HINSTANCE ;
    classProc  :   NWASnapinMDIChildProc ;
    hClassMenu  :   HMENU ;
    hClassIcon  :   HICON ;
    version  :   nuint32 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}



(* Function NWACreateMDIChildWindow (
    className  :   LPCSTR ;
    windowTitle  :   LPCSTR ;
    Var pHwnd  : HWND;
    Var pcreateParam  : NWACreateMDIChildParam
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}  *)


(*---------------------------------------------------------------------*)

(* Tools menu item enumeration and invocation function                 *)

(*---------------------------------------------------------------------*)

Function NWAGetToolsMenuItemCount (
    viewName  :   pnstr8 ;
    pCount  :   pnuint16 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWAGetToolsMenuItem (
    viewName  :   pnstr8 ;
    itemIndex  :   nuint16 ;
    Var pMenuItem  : NWAToolsMenuItem
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWAProcessToolsMenuItemCommand (
    viewName  :   pnstr8 ;
    menuItem  :   NWAToolsMenuItem 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


Function NWAProcessToolsMenuItemValid (
    viewName  :   pnstr8 ;
    menuItem  :   NWAToolsMenuItem ;
    pFlags  :   pnuint 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*---------------------------------------------------------------------*)

(* Function to query Save Settings menu option                         *)

(*---------------------------------------------------------------------*)

Function NWAGetSaveSettingsOption (
    Var pOptionFlag  : BOOL
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*----------------------------------------------------------------------*)

(* Extended Register Object Proc Function                               *)

(*----------------------------------------------------------------------*)




{$DEFINE NWA_SNAPIN_NORMAL}
Const NWA_SNAPIN_NORMAL = $00000001;
{$DEFINE NWA_SNAPIN_TEMPLATE}
Const NWA_SNAPIN_TEMPLATE = $00000002;
{$DEFINE NWA_SNAPIN_MULTIOBJ}
Const NWA_SNAPIN_MULTIOBJ = $00000003;





{$DEFINE NWA_SNAPIN_DISABLE_PAGESETUP}
Const NWA_SNAPIN_DISABLE_PAGESETUP = $00010000;



Function NWARegisterObjectProcEx (
    classType  :   pnstr8 ;
    className  :   pnstr8 ;
    developInfo  :   pnstr8 ;
    hDLL  :   HINSTANCE ;
    proc  :   NWASnapinObjectProc ;
    version  :   nuint32 ;
    snapinFlag  :   nuint32 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*-----------------------------------------------------------------------*)

(* Get the Tree Name associated with Active Browser                      *)

(*-----------------------------------------------------------------------*)

Function NWAGetTreeName (
    treeName  :   pnstr ;
    defContext  :   pnstr 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}



(*-----------------------------------------------------------------------*)

(* Close NWAdmin application                                             *)

(*-----------------------------------------------------------------------*)

Function NWAExitNWAdmin : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*-----------------------------------------------------------------------*)

(* Get NLS path name based on NWLanguage                                 *)

(*-----------------------------------------------------------------------*)

Function NWAGetNLSFilePath (
    fileName  :   pnstr8 ;
    pathName  :   pnstr8 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*-----------------------------------------------------------------------*)

(* Create a Window pull-down menu in MDI Child Window menu               *)

(*                                                                       *)

(* This interface uses following menu ids for menu items under Window    *)

(* menu. Snapin MDI Child must not use the same ids for any of its menu  *)

(* items in its own menu.                                                *)

(*-----------------------------------------------------------------------*)


Function NWACreateWindowMenu (
    className  :   pnstr8 ;
    hMenu  :   HMENU ;
    menuPos  :   UINT 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}


(*-----------------------------------------------------------------------*)

(* Launch Mpew Details window for an object                              *)

(*-----------------------------------------------------------------------*)

Function NWALaunchDetails (
    classType  :   pnstr8 ;
    className  :   pnstr8 ;
    objName  :   pnstr8 
) : NWRCODE;
{$IFDEF N_ARCH_32}
stdcall;
{$ENDIF}



{$IFDEF __cplusplus}

(* TC } *)
{$ENDIF}



{$ENDIF}



