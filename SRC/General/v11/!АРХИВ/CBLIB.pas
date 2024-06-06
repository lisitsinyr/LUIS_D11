unit CBLIB;

interface

uses
   Windows, Dialogs, sysutils,
   cberrs, cbnames;

{ ==============================================================================
                       �������� ��������� ������� �����.

  � ������ ����� ����������� ���� ������ � ��������� �������, ������������� �
  ������ ����������.

  ��� �������� ������� ������������ ��������� ������:
    <�������� ������� �� ������� �� ����������>
    <����� �������� �������>
    IN:       <������ �������� ������� ����������>
    OUT:      <������ �������� ���������� - �����������>
    RESULT:   <������ �������� ������������� ��������>
    NOTE:     <��������� �� ������ �������>
    PROGRESS: <������ �������� �������� ������������� ������ �������
               (������ ��� ��������� ��������)>
}
type
   HANDLE = DWORD;
   PArrayOfPChar = ^TArrayOfPChar;
   TArrayOfPChar = array of PChar;
   PArrayOfChar = ^TArrayOfChar;
   TArrayOfChar = array of Char;

const
   SAED32 = 'saed32.dll';

var
   SAED32Module: HModule = 0;

var
   ei: cb_ERRORINFO;
   sei: array [0..256] of char;

const
   cb_SI_NAME_LEN     = 8;
   cb_USER_NAME_LEN   = 40;

const
   cb_PASSWORD_LEN = 20;   // ������������ ����� ������

{==============================================================================
                      ��������� ������, ����, CALLBACK-�������
=================================================================================}
type
   TpassBuf = array [0..cb_PASSWORD_LEN] of char;

var
   FpassDefault: string;
   FpassBuf: TpassBuf;
   FpiaName: array [0..MAX_PATH] of char;
   FuserName: array [0..cb_USER_NAME_LEN] of char; { ��� ������������ �������������� }

type
   Pcb_PASSWORDFUNC = ^cb_PASSWORDFUNC;
   cb_PASSWORDFUNC = function (passBuf: Pointer; piaName: PChar; userName: PChar): Integer;
{ �������� ������� ������� ������ ������������. ���������� ����������� ���
   �������������, ���� ��������� ��� ���������� �� ������.
IN:
  piaName     - ��������� �� ������-�������� ���
  userName    - ��������� �� ������-��� ��������� ���
OUT:
  passBuf     - ����� ��� ������.
                ������ ������ �� ������� ��� cb_PASSWORD_LEN.
RESULT:
  0   - ������ ������.
  !=0 - ������������ ��������� ������� ������.
}

{ ��������� ���������� ����������: }
type
   Pcb_LIBPARAMS = ^cb_LIBPARAMS;
   cb_LIBPARAMS = packed record
      piaName: array [0..MAX_PATH] of char;    { ��� ��� (������ ����) }
      piaPasswordFunc: Pcb_PASSWORDFUNC;       { ��������� �� ������� ������� ������ ��� }
      siaDir: array [0..MAX_PATH] of char;     { ������� �� ��� }
      sircDir: array [0..MAX_PATH] of char;    { ������� �� ���� }
      simpleFile: array [0..MAX_PATH] of char; { ��� ����� ������� ����� (������ ����)}
      logFile: array [0..MAX_PATH] of char;    { ��� LOG-����� }
      logFlags: DWORD;                         { ����� ��������������� �������� cb_LOGF_XX}
      options: DWORD;                          { ����� cb_LPO_XXX }
      reserved: PChar;                         { ���������������, ������ ���� NULL }
   end;

const
   cb_LOGF_ALL    = $FFFFFFFF;  { ��������������� ��� �������� }
   cb_LOGF_NONE   = 0;          { �������� �� ��������������� }

   cb_LPO_DONT_OPEN_DB = 1;     { �� ��������� ������������� �� ���.
                                   ���� �� ������, �� ����������� �������
                                   siaDir � ����������� ��� ��.
                                   (c�. ������ "���� ������ ��� � ����")
                                }

   cb_LPO_DONT_OPEN_DB_SIRC    = 4; { �� ��������� ������������� �� ����.
                                       ���� �� ������, �� ����������� �������
                                       sircDir � ����������� ��� ��.
                                       (c�. ������ "���� ������ ��� � ����")
                                    }
   cb_LPO_USE_VC50_EXCEPTIONS  = 2; { ��� ����������� ������ ������������
                                       ���������� VC++ 5.0
                                       (��. ������ "����������� ������")
                                     }

{ ���� ����, ������� � ��� �������� ��� ������������� � DOS-������� }
type
   dos_ftime = packed record
      time: WORD;
      date: WORD;
   end;
type
   kdate = packed record
      da_year: WORD;   { year }
      da_day: shortint;     { day of the month }
      da_mon: shortint;     { month (1 = Jan) }
   end;

{ �������� ����� }
const
   DOS_FA_RDONLY    = 1;
   DOS_FA_HIDDEN    = 2;
   DOS_FA_SYSTEM    = 4;
   DOS_FA_LABEL     = 8;
   DOS_FA_DIREC     = 16;
   DOS_FA_ARCH      = 32;

{ ��������� ���������� � ���������������� �����:  }
type
   Pcb_ARCHFILEINFO = ^cb_ARCHFILEINFO;
   cb_ARCHFILEINFO = packed record
      fileName: array [0..MAX_PATH] of char;       { ��� ����� (����� �������� �����������) }
      attrib: WORD;                   { ��������� (DOS_FA_XXX) }
      size: DWORD;                    { ������ ����� (�����������)}
      dateTime: dos_ftime;     { ���� ��������� ����������� ����� }
   end;

{ ==========================================================================
                      ����������� ��������� ��������
   ========================================================================== }
const
   { ���� ������� ���������  }
   cb_PFC_PROGRESS     = 1;    { ���������� ��������� ������ ������ }
   cb_PFC_KPD_FOUND    = 2;    { � ����� ��������� ��� }
   cb_PFC_KPD_TESTED   = 3;    { � ����� �������� ���  }

{ ��������� ������, ���� ������� = cb_PFC_PROGRESS: }
type
   Pcb_PFI_PROGRESS = ^cb_PFI_PROGRESS;
   cb_PFI_PROGRESS = packed record
      totalSize: DWORD;            { ����� ����� ������ }
      doneSize: DWORD;             { ������� � ������� ������� }
   end;

{ ��������� ������, ���� ������� =  cb_PFC_KPD_FOUND: }
type
   Pcb_PFI_KPDINFO = ^cb_PFI_KPDINFO;
   cb_PFI_KPDINFO = packed record
      siName: array [0..cb_SI_NAME_LEN] of char;       { ��� �������������� ������������, ���������� ���  }
      userName: array [0..cb_USER_NAME_LEN] of char;   { ��� ������������, ���������� ��� }
      sdate: kdate;                  { ���� �������� ��� }
   end;

const
   TEST_PARAM_LEN = 256;

{ ��������� ������, ���� ������� = cb_PFC_KPD_TESTED: }
type
   Pcb_PFI_KPDTEST = ^cb_PFI_KPDTEST;
   cb_PFI_KPDTEST = packed record
      siName: array [0..cb_SI_NAME_LEN] of char;     { ��� �������������� ������������, ���������� ���  }
      userName: array [0..cb_USER_NAME_LEN] of char;  { ��� ������������, ���������� ��� }
      sdate: kdate;                                    { ���� �������� ��� }
      testResult: WORD;                                { ��������� �������� ��� }
      TestParam: array [0..TEST_PARAM_LEN] of char;    { �������� ���������� �������� ��� }
   end;

type
   cb_PF_PARAMS_Info = packed record
      case Integer of
         0: (progress: cb_PFI_PROGRESS);
         1: (kpdFound: cb_PFI_KPDINFO);
         2: (kpdTested: cb_PFI_KPDTEST);
   end;

   Pcb_PF_PARAMS = ^cb_PF_PARAMS;
   cb_PF_PARAMS = packed record
      cause: Integer;                   { ������� ��������� (��. ��������� PFC_XXX) }
      info: cb_PF_PARAMS_Info;
      fParam: Pointer;               { ��������, ���������� � ���������� ������� ���������� }
   end;

type
   Pcb_PROGRESSFUNC = ^cb_PROGRESSFUNC;
   cb_PROGRESSFUNC = function (params: Pcb_PF_PARAMS): Integer; stdcall;
{ �������� ������� ����������� ��������� ���������� ��������.
IN:
  params   - �������� ���������� ���� ��������� ���������� ��������.
RESULT:
  0 - ��� � �������
  1 - ���������� �������� ��������.
  2 - ���������� ���������� ������ ����� �������� (������ ���� cause=cb_PFC_KPD_FOUND)
}

{ ================================================================================= }
const
   cb_SI_TYPE_SIA   = 1;        { ������� ������������� �������� }
   cb_SI_TYPE_SIRC  = 2;        { ������� ������������� ���������������� ������ }

{ ��������� ���������� �� ��������������: }
type
   Pcb_SI_INFO = ^cb_SI_INFO;
   cb_SI_INFO = packed record
      siaName: array [0..cb_SI_NAME_LEN] of char;    { ��� �������� �������������� }
      userName: array [0..cb_USER_NAME_LEN] of char; { ��� ������������ �������������� }
      sdate: kdate;
      edate: kdate;                              { ���� ������ � ��������� ����� ������������� �� }
      typeINT: Integer;                          { ��� �������������� - cb_SI_TYPE_XXX }
      hDataBase: HANDLE;                  { ���������� ��, � ������� ���������� ���� �� }
   end;

type
   cb_ENUM_SI_FUNC = function (siInfo: cb_SI_INFO; fParam: Pointer): Integer;
{ �������� �������, ���������� ��� ������� �� ��� ������������ ��
   �������� cb_enumSI.
IN:
   siInfo      - ��������� �� ��������� ���������� � ��������� ��������������
   fParam      - ��������, ���������� � ������� cb_enumSI.
OUT:
   0 - ��� � �������
   1 - ���������� ������������ ���������������.
}

type
   Pcb_IA_INFO = ^cb_IA_INFO;
   cb_IA_INFO = packed record
      iaName: array[0..cb_SI_NAME_LEN] of char;     { ��� �������������� }
      userName: array[0..cb_USER_NAME_LEN] of char; { ��� ������������ �������������� }
      sdate: kdate;
      edate: kdate;                            { ���� ������ � ��������� ����� ������������� �� }
      password: array[0..cb_PASSWORD_LEN] of char;  { ������, �� ������� ����� ������ ���,
                                                        ��� "", ���� �� �� ������ ���� ���������� }
   end;

{ ==============================================================================
                               �����/���������
================================================================================= }
function cb_getLibVersion(verMajor: Pointer; verMinor: Pointer; libType: Pointer): Integer;
{ ��������� ������ ����������.
OUT:
  verMajor  - ��������� �� ����������, ������� ������� ����� ������
              ����������.
  verMinor  - ��������� �� ����������, ������� ������� ����� �����������
              ����������.
  libType   - ��������� �� ����������, ������� ������� ��� ����������:
              0 - ������ ������ (����������� �����).
              1 - ������������ ������ (����������� �����).
}

function cb_initLib(const prof: PChar; piaPasswordFunc: cb_PASSWORDFUNC; options: DWORD): Integer;
{ ������������� ����������. ������ ������� ������ ���� ������� �� ������� �������������
   ����� ������� ����������.
IN:
   prof    - profile, must be NULL.
   piaPasswordFunc - ������� ������� ������ ���.
   options - ����� cb_LPO_XXX.

RETURN:
  0     - �����.
  CBERR   - ������.
}

function cb_initLibDirect(const par: Pcb_LIBPARAMS): Integer;
{ ������ ������������� ����������, ��������� ������� ���
   ��������� ����������.
   ������ ������� ������ ���� ������� �� ������� �������������
   ����� ������� ����������.
IN:
  par   - ��������� �� ��������� ���������� ����������
RETURN:
  0     - �����.
  CBERR   - ������.
}

function cb_doneLib: Integer;
{ ��������������� ����������. ������ ���� ������� ����� ��������� ��������
   � ����������� ��� �������������� ������ ��������
}

function cb_getCurrentUser(piaName: PChar; userName: PChar): Integer;
{ ��������� ���������� �������� ������������ ����������
OUT:
  piaName  - �����, � ������� ����� ��������� �������� ���
             �������� ������������.
  userName - �����, � ������� ����� ��������� ��� �������� ������������.
RETURN:
  0     - �����.
  CBERR   - ������.
}

function cb_getLibSettings(par: cb_LIBPARAMS): Integer;
{ ��������� ������� �������� ����������
OUT:
  par   - � ������ ��������� ����� ��������� ��� ������� ���������
          ����������.
          ���������� ����:
            piaName - ��� ����� �������� ���
            siaDir  - ������� �� ���
            sircDir - ������� �� ����
            simpleFile - ��� ����� ������� ����� (������ ����)
            options - ����� cb_LPO_XXX
            logFile - ���� �������
            logFlags - ����� ��������������� ��������
RETURN:
  0     - �����.
  CBERR   - ������.
}

{ ==============================================================================
                          ������� ������ � �������
================================================================================= }
{ ������ � �������� }

function cb_createArchive(const fileName: PChar; method: Integer;
                          users: PArrayOfPChar; userNum: Integer;
                          func: Pcb_PROGRESSFUNC; fParam: Pointer): HANDLE;
{  ������� �����.
IN:
  fileName  - ��� ����� ������������ ������.
  method    - ������� ������: 0 - ���������� (������ ����������� ������)
              9 - ���������� (����� ��������� �������������)
              ������������� ������������ method = 3.
  users     - ������ �������������, ��� ������� ������������
              ������ �����. ������������ ����� ������ ASCIIZ - �����.
  userNum   - ���������� ������������� � ������ users.
  func      - ������� ����������� ��������� �������� (����� ���� NULL).
  fParam    - ��������, ������������ � ������� func.
RESULT:
  ���������� ���������� ������, ������� ����� ������� ��������������
  � ������� ��������� � ����� ������.
  ���������� NULL ��� ������.
NOTE:
  ��������� ��������� ������ � ����������� ���� ������ �
  ��������������, �������������� � ��������� users. ���������
  ��������� ����, � ������� ����� ��������� ���������������� �����.
PROGRESS:
  ����� �������� ��������������� ���������� ������������� (N),
  ��� ������� ������������ ������ �����. ������� func ���������� N+1 ��� �����
  ����� ��������� ���� ������ � ��������� ������������� � � ����� ���� ��������,
  ������ cause = cb_PFC_PROGRESS, info->totalSize = N, info->doneSize = (����������
  ��� ������������ �������������).
}

const
   cb_GIT_RECEIVER   = 1;   { ������� �������� ����������� ������ }
   cb_GIT_CREATOR    = 2;   { ������� �������� ���������� ������ }
   cb_GIT_NOTFOUND   = 256; { ��������� ���������� �� �������� �� ������� }

function cb_getArchiveInfo(const fileName: PChar; needDetails: Boolean;
                           func: cb_ENUM_SI_FUNC; fParam: Pointer): Integer;
{  �������� ���������� �� ��������� ������ � � ��� ���������.
IN:
  fileName  - ��� ����� ������.
OUT:
  needDetails - �������, ����� �� �������� ������ ���������� � �������������,
              ��� �� ���������� ������ �������� �������������� ��������.
  func      - ������� ��������� ���������� � ���������	.
  fParam    - ��������, ������������ � ������� func.
RESULT:
  ���������� ������������� ���������
  CBERR ��� ������.
NOTE:
  ��� ������� �������� ������ ���������� func � ���������� -
  ���������� cb_SI_INFO, � ������� ���� ����� ��������� ���������:
    siaName    - ��� ���
    userName   - ��� ������������ ���
    sdate, edate - ���� ������ � ��������� ����� ������������� ���
    type       - ����� ������ - ����� �������� (cb_GIT_XXX)
    hDataBase  -  ���������� ��, � ������� ���������� ���� ���
  ���� needDetails = FALSE, �� � ���� ��������� ��������� ������
  ���� siaName � type.
}

function cb_openArchive(const fileName: PChar; creator: PChar;
                              func: Pcb_PROGRESSFUNC; fParam: Pointer): HANDLE;
{  ��������� �����. ������ ������ ���� ������ �������.
IN:
  fileName  - ��� ����� ������������ ������.
OUT:
  creator   - ��������� �� �����, � ������� ��� �������� ��������
              ������ ����� �������� ������������� ������������ -
              ��������� �����.
  func      - ������� ����������� ��������� �������� (����� ���� NULL).
  fParam    - ��������, ������������ � ������� func.
RESULT:
  ���������� ���������� ������, ������� ����� ������� ��������������
  � �������� ���������� ������.
  ���������� NULL ��� ������.
NOTE:
  ��� �������� ����������� ����������� �������� ������ �������
  ������������� (�� ��������� ������). ���� �������� ����������
  (���� �� ������������ ��� ������� ������������), ������������ ������.
  ����� �������� ����������� ���� ������� � ������ � ���������� ��
  ������ ���������� (� ���������������) �� ��������� ����.
PROGRESS:
  ����� �������� ��������������� ����� ������. ������� func ���������� ��������� ���
  �� ����� �������������� ������ �� ��������� ����, ������ cause = cb_PFC_PROGRESS,
  info->totalSize = <filesize>, info->doneSize = <decoded size>.
}

function cb_getFirstFile(hArc: HANDLE; info: Pcb_ARCHFILEINFO): Integer;
{  �������� ���������� � ������ ����� ������.
    ������ ������ ���� ������ �������.
IN:
  hArc     - ���������� ������, ���������� �� ������� cb_openArchive.
OUT:
  info     - ��������� �� ���������, � ������� ����� ���������
             ���������� � �����.
RESULT:
  0 - �����.
  1 - ����� ���� (��� ������)
  CBERR - ������.
NOTE:
  ��� ������, ���������� �������� createArchive ������ ���������� 1.
}

function cb_getNextFile(hArc: HANDLE; info: Pcb_ARCHFILEINFO): Integer;
{  �������� ���������� � ��������� ����� ������.
    ������ ��������� ���� ������ �������.
IN:
  hArc     - ���������� ������, ���������� �� ������� cb_openArchive.
OUT:
  info     - ��������� �� ���������, � ������� ����� ���������
             ���������� � �����.
RESULT:
  0 - �����.
  1 - ��� ����� (������ ������ ������ ��������)
  CBERR - ������.
NOTE:
  ��� ������, ���������� �������� createArchive ������ ���������� 1.
}

const
   cb_AAF_SETKPD            =  1;
   cb_AAF_EXCLUDE_BASEDIR   =  2;

function cb_addFile(hArc: HANDLE; const srcName: PChar; const dstName: PChar; flags: Integer;
                    func: Pcb_PROGRESSFUNC; fParam: Pointer): Integer;
{ �������� ���� � ����� ������.
IN:
  hArc     - ���������� ������, ���������� �� ������� cb_createArchive.
  srcName  - ��� ������������ �����
  dstName  - ��� �����, ������� ����� ������������ � ����������
             ������.
  flags    - ����� ����������:
    cb_AAF_SETKPD - ��� ���������� ������������� ����������� ���.
              (��� �������� ���� �� ��������)
    cb_AAF_EXCLUDE_BASEDIR - ������������ � �������� ��������� ����� ����� srcName,
              �� �������� �������� ������� �������, ��������� � dstName. ����
              dstName = NULL, �� �� srcName ����������� ��� ��������.

  func      - ������� ����������� ��������� �������� (����� ���� NULL).
  fParam    - ��������, ������������ � ������� func.
RESULT:
  0 - �����.
  CBERR ��� ������.
PROGRESS:
  ����� �������� ��������������� ����� �����. ������� func ���������� ��������� ���
  �� ����� ������������� �����, ������ cause = cb_PFC_PROGRESS,
  info->totalSize = <original filesize>, info->doneSize = <read size>.
}

const
   cb_AEF_TESTKPD           = 1;
   cb_AEF_DELKPD            = 2;
   cb_AEF_ADD_DIR           = 4;
   cb_AEF_FAIL_IF_EXISTS    = 8;
   cb_AEF_GET_FINAL_NAME    = 16;
   cb_AEF_FAIL_ON_BADKPD    = 32;

function cb_extractCurFile(hArc: HANDLE; destName: PChar; flags: Integer;
                           func: Pcb_PROGRESSFUNC; fParam: Pointer): Integer;
{ ������� ������� ���� � ������.
IN:
  hArc     - ���������� ������, ���������� �� ������� cb_openArchive.
  dstName  - ��� �����, � ������� ����� �������� ���������� ������������ �����.
  flags    - ����� ����������:
    cb_AEF_TESTKPD  - ��� ���������� ������������� ��������� ��������� ��� �����.
    cb_AEF_DELKPD   - ��� ���������� ������������� ������� ��������� ��� �����.
    cb_AEF_ADD_DIR  - dstName �������� �� ��� ��������� �����, � �������, � ������� �����
                    �������� ������� �������� ���� ��� ��� ������������ ������.
                    ���� � ������������ ����� ����� ���������� ��������, �� ��� ���������
                    � ��������� �������� dstName.
    cb_AEF_FAIL_IF_EXISTS - ���� ����������� ���� ��� ����������, �� ������������ �������
                    ������. ��� ���������� ����� ����� ���� ����� ������� �����.
    cb_AEF_GET_FINAL_NAME - ����� ���������� ����� ���������� ��� ������ ��� �� ������
                    destName. destName ������ ��������� �� ����� ������������ �������.
                    ������ ���� ����� �������������� ������ ��� ������������� �����
                    AEF_ADD_DIR.
    cb_AEF_FAIL_ON_BADKPD - ������ ������ � cb_AEF_TESTKPD. ���� ��������� ������ ��������
                    ���, ������������ � ����� ���� ������. ��� ���������� ����� �����
                    ������ ��� ���������� � ������� func, � �� ��� �������� �� ������.

  func     - ������� ����������� ��������� (����� ���� NULL).
  fParam   - ��������, ������������ � ������� func.
RESULT:
  0 - �����.
  CBERR ��� ������.
NOTE:
  ���� ���������� ���� cb_AEF_TESTKPD, �� ����� �����������
  ��������� ��� ����� � ���������� �������� ����� �������� �
  ������� func (���������� cb_testFileKPD).
PROGRESS:
  ����� �������� ��������������� ����� �����. ������� func ���������� ��������� ���
  �� ����� ���������������� �����, ������ cause = cb_PFC_PROGRESS,
  info->totalSize = <original filesize>, info->doneSize = <writed size>.
  ��� ����������� ��� func ���������� � ����������� cause = cb_PFC_KPD_FOUND,
  info = <���������� � ���>, ����� � ����������� cause = cb_PFC_KPD_TESTED,
  info = <���������� � ����������� �������� ���>.
}

function cb_closeArchive(hArc: HANDLE; func: Pcb_PROGRESSFUNC; fParam: Pointer): Integer;
{ ������� �����.
IN:
  hArc     - ���������� ������, ���������� �� ������� cb_openArchive
             ��� cb_createArchive.
  func     - ������� ����������� ��������� (����� ���� NULL).
  fParam   - ��������, ������������ � ������� func.
RESULT:
  0 - �����
  CBERR ��� ������.
NOTE:
  ���� ����������� �����, ��������� cb_createArchive, �� ����������
  ����������� ���������� �����, ����������� ����������
  ���������������� ������ � ������������ ����� ���������������
  ����� � ��������� ������.
  ����� ��������� ���� ���������.
  ���� ����������� �����, �������� cb_openArchive, �� ������
  ��������� ��������� ����, � ������� ��������� ���������������
  �����.

  ����� ���������� ���� ������� ���������� hArc ���������� ����������.

PROGRESS:
  ���� ����������� �����, �������� cb_openArchive, �� ������� func �� ����������
  (�.�. ��� ������� ��������).
  ���� ����������� �����, ��������� cb_createArchive:
  ����� �������� ��������������� ����� ������. ������� func ���������� ��������� ���
  �� ����� ����������� ������, ������ cause = cb_PFC_PROGRESS,
  info->totalSize = <archivesize>, info->doneSize = <encoded size>.
}

function cb_abortArchive(hArc: HANDLE): Integer;
{ �������� �������� ������ � ������� ��������� �����.
IN:
  hArc     - ���������� ������, ���������� �� ������� cb_createArchive.
RETURN:
  0 - �����
  CBERR ��� ������.
NOTE:
  ����� ���������� ���� ������� ���������� hArc ���������� ����������.
}

{ =======================================================================
                      ��� ������������� �������������
   ======================================================================= }

function cb_testFileKPD(const fileName: PChar; func: Pcb_PROGRESSFUNC; fParam: Pointer): Integer;
{ ��������� ��� �����.
IN:
  fileName    - ��� ������������ �����.
  func        - ������� ����������� ���������.
  fParam      - ��������, ������������ � ������� func.
RESULT:
  0 - �����.
  CBERR ��� ������.
PROGRESS:
  ����� �������� ��������������� ����� �����. ������� func ���������� ��������� ���
  �� ����� ��������� �����, ������ cause = cb_PFC_PROGRESS,
  info->totalSize = <filesize>, info->doneSize = <read size>.
  ��� ����������� ��� func ���������� � ����������� cause = cb_PFC_KPD_FOUND,
  info = <���������� � ���>, ����� � ����������� cause = cb_PFC_KPD_TESTED,
  info = <���������� � ����������� �������� ���>.
}

function cb_setFileKPD(const fileName: PChar; func: Pcb_PROGRESSFUNC; fParam: Pointer): Integer;
{ ����������� ��� �����.
IN:
  fileName    - ��� ��������������� �����.
  func        - ������� ����������� ��������� (����� ���� NULL).
  fParam      - ��������, ������������ � ������� func.
RESULT:
  0 - �����
  CBERR ��� ������.
PROGRESS:
  ����� �������� ��������������� ����� �����. ������� func ���������� ��������� ���
  �� ����� ��������� �����, ������ cause = cb_PFC_PROGRESS,
  info->totalSize = <filesize>, info->doneSize = <read size>.
}

function cb_delFileKPD(const fileName: PChar; num: Integer): Integer;
{ ������� ��� �����.
IN:
  fileName    - ��� ��������������� �����.
  num         - ���-�� ��������� ��� (� �����).
                ��� -1, ���� ����� ������� ��� ���.
RESULT:
  ���������� ���������� ��������� ��� ���
  CBERR ��� ������.
}

function cb_getFileKPDCount(const fileName: PChar): Integer;
{ �������� ���������� ��� �����.
IN:
  fileName    - ��� ��������������� �����.
RESULT:
  ���������� ���������� ��� ���
  CBERR ��� ������.
}

{ ====================================================================
                     ���� ������ ��� � ����
=======================================================================
  �� �������� � ����� ������ (��) ��.
  ���������� 2 ���� ��:
    - �� ������������ (��������) (���), ������������ ��� �������� ��� ������
      � ������������ ���� ������ ����� ����������
    - �� ���������������� ������ (����), ������������ ��� ��������
      ��� ��������������� (�.�. �� �����������).
  �� ����� ������� ������ �� ������ ����.

  ��� ������������� ���������� ���������� �������������� �������� ��.
  ��� ���� ��� ��, ������������� � �������� ���, ����� ��������� ��� �� ���,
  � ��, ������������� � �������� ����, ����� ��������� ��� �� ����.

  ���� ��� ������������� ���������� (cb_) ������� ����� cb_LPO_DONT_OPEN_DB,
  �� �� ��� �� ����������� �������������. ������� �� ���������� ���� ���������
  �������� cb_dbOpenDatabase.

  ���� ��� ������������� ���������� (cb_) ������� ����� cb_LPO_DONT_OPEN_DB_SIRC,
  �� �� ���� �� ����������� �������������. ������� �� ���������� ���� ���������
  �������� cb_dbOpenDatabase.

  ���� �� �������, ��� ��������� � �������� ������ ��. �������� �� �����������
  �� �������� ������.
}

const
   cb_DB_OM_READ   = 1;  { ������ �������� �� }
   cb_DB_OM_MODIFY = 2;
   cb_DB_OM_CREATE = 3;

function cb_dbOpenDatabase(const dbName: PChar; mode: Integer; atype: Integer): HANDLE;
{ ������� ��.
IN:
  dbName      - ��� ����� ���� ������.
  mode        - ����� �������� ��:
    cb_DB_OM_READ   - ������� ������ ��� ������ (��� ��������� ������). ����� �����
                   ��������� ������������� ������������� �� ����������� ����������
                   ��� ��������������.
    cb_DB_OM_MODIFY - ������� ��� �����������. �� ��, �������� � ����� ������, �����
                   ��������� ��� �������. � ����� ������ ����������� ������ � ��
                   ������ ������ �������� (������������).
    cb_DB_OM_CREATE - ���������� ����������� ������, �� ��� �������� �� ������� ��
                   ����������. ����� ����, ������ � ���� ������ ����� ���������
                   �������������� dbName, � ��������� �� ����� �������.
  type        - ������ ������������� ���� ������:.
    cb_SI_TYPE_SIA     - ��� ���� ������ ���.
    cb_SI_TYPE_SIRC    - ��� ���� ������ ����.
RESULT:
  ���������� ���������� �� ��� ������.
  NULL ��� ������.
NOTE:
  �� ������� �� 2 ������: *.PKD � *.PKM. � �������� dbName ����� ��������� ����� �� ���,
  � ����� ��� ����� ��� ����������.
}

function cb_dbCloseDatabase(hDB: HANDLE): Integer;
{ ������� ��.
IN:
  hDB     - ���������� ��, ���������� �� ������� cb_dbOpenDatabase.
            ���� NULL, �� ����������� ��� ���� ������, �������� � ��������
            �� ������ ������.
RESULT:
  0 - �����
  CBERR ��� ������.
}

function cb_dbPackDatabase(hDB: HANDLE): Integer;
{ ����� ��.
IN:
  hDB       - ���������� ��, ���������� �� ������� cb_dbOpenDatabase � ������
              DB_OM_MODIFY ��� DB_OM_CREATE.
RESULT:
  0 - �����
  CBERR ��� ������.
}

function cb_dbGetDBHandles(handlesBuffer: HANDLE; handlesNeed: Integer): Integer;
{ �������� ����������� ���� �������� ��.
IN:
  handlesNeed   - ���������� ������������, ������� ����� ���������� � ����� handlesBuffer.
                  ���� 0, �� ����������� �� ����������, ������ ������������ �� ����������.
OUT:
  handlesBuffer - ����� ��� ������������� ������������, �������� �� ����� ���
                  handlesNeed ��������� ���� HANDLE.
RESULT:
  ���������� �������� �� ������ ������ ��.
}

type
   cb_DBINFO = packed record
      dbName: array [0..MAX_PATH] of char;  { ��� ����� ���� ������ ��� ���������� }
      siCount: Integer;                     { ���������� �� � �� }
      openMode: Integer;                    { ����� �������� �� (DB_OM_XXX)   }
      atype: Integer;                       { ��� �������� �� (cb_SI_TYPE_XXX) }
   end;

function cb_dbGetDatabaseInfo(hDB: HANDLE; dbi: cb_DBINFO): Integer;
{ �������� ���������� � ���� ������
IN:
  hDB     - ���������� ��, ���������� �� ������� cb_dbOpenDatabase.
OUT:
  dbi     - ��������� �� ���������, � ������� ����� ��������� ���������� � ��.
RESULT:
  0 - �����
  CBERR ��� ������.
}

function cb_dbDeleteSI(hDB: HANDLE; const siName: PChar): Integer;
{ ������� �� �� ��.
IN:
  hDB       - ���������� ��, ���������� �� ������� cb_dbOpenDatabase � ������
              DB_OM_MODIFY ��� DB_OM_CREATE.
  siName    - ��� ���������� ��.
RESULT:
  0 - �����
  CBERR ��� ������.
}

const
   cb_DB_AM_FAIL_IF_EXISTS    = 1;
   cb_DB_AM_SELECT_NEWEST     = 2;
   cb_DB_AM_OVERWRITE_ALLWAYS = 3;

function cb_dbAddSI(hDB: HANDLE; const siName: PChar; mode: Integer;
                    hDBSrc: HANDLE): Integer;
{ �������� �� � �� �� ����� ��� ������ ��.
IN:
  hDB       - ���������� ��, ���������� �� ������� cb_dbOpenDatabase � ������
              DB_OM_MODIFY ��� DB_OM_CREATE.
  siName    - ��� ������������ ��. ����� ���� ������ ����� ��, ���� ����������
              ������� �� ����� (hDBSrc==NULL), ��� ������ �� �������� �� (hDBSrc!=NULL).
  mode      - ����� ���������� �� (��������, ���� ����������� �� ��� ����������):
    cb_DB_AM_FAIL_IF_EXISTS     - ����������� � ��������� �������� (��. ����).
    cb_DB_AM_SELECT_NEWEST      - �������� �� �� �������� (� ����� ������� ����� ��������)
    cb_DB_AM_OVERWRITE_ALLWAYS  - ������ �������� �����������.

  hDBSrc    - ���������� ��, �� ������� ������� ����������� ��, ���
              NULL, ���� ���� ����������� �� �����.
RESULT:
  0 - �����
  1 - ����������� �� ��� ���������� (��������).
  CBERR ��� ������.
}

function cb_dbExtractSI(hDB: HANDLE; const siName: PChar; dstDir: PChar): Integer;
{ ���������� � ���� ����� �� �� ��.
IN:
  hDB       - ���������� ��, ���������� �� ������� cb_dbOpenDatabase. ���� NULL, ��
              ����� �� ������� �� ���� �������� ��.
  keyName   - ��� ����������� � ���� ��.
  dstDir    - �������, � ������� ����� ���������� ���� ��.
RESULT:
  0 - �����
  CBERR ��� ������.
}

const
   cb_DB_EM_ENUM_ALL        = 1;
   cb_DB_EM_COLLISION_ONLY  = 2;
   cb_DB_EM_FIRST_ONLY      = 3;

function cb_enumSI(hDB: HANDLE; mode: Integer; func: cb_ENUM_SI_FUNC; fParam: Pointer): Integer;
{ ����������� ��� �� � ��.
IN:
  hDB        - ���������� ��, ���������� �� ������� cb_dbOpenDatabase, ��� NULL,
               ���� ������������� �� �� ���� �������� ��.
  mode       - ����� ������������, ���� � ������ �� ���� ����������� ��
               (����� �������� ������ ��� hDB==NULL).
     cb_DB_EM_ENUM_ALL        - ����������� ��� �� � ��� �������� ����������� ��.
     cb_DB_EM_COLLISION_ONLY  - ����������� ������ ����������� ��.
     cb_DB_EM_FIRST_ONLY      - ����������� ������ ������������� �� �
                                ������ �� �� �����������.
  func       - �������, ���������� ��� ������� �����.
  fParam     - ��������, ������������ � ������� func.
RESULT:
  ���������� ���������� ������������� ��.
  CBERR ��� ������.
NOTE:
  ���������� �� � ������ �� ������ ������������, ��������� ��� �������� ���
  ��� ������ ������������� �� �� ����� �������������� � ������������ �������
  �������� ��. ������� ������� �� �� ����� ������ ������ - ������������.
  ����� cb_DB_EM_COLLISION_ONLY ������ ������ ��� ��������� ����� �������� �
  ����� ������.

  ������ �������������� ���� ������ ������ ������� func, ��� �������� � ��������� ���
  ������������� ������������ ��.
}

const
   cb_SIA_DUMP_SIZE  = 113;
   cb_KPD_DUMP_SIZE  = 126;

type
   cb_SI_DETAILS = packed record
      siaName: array[0..cb_SI_NAME_LEN] of char;    { ��� �������� �������������� }
      userName: array[0..cb_USER_NAME_LEN] of char; { ��� ������������ �������������� }
      sdate,edate:kdate;                              { ���� ������ � ��������� ����� ������������� �� }
      atype: Integer;                                 { ��� �������������� - cb_SI_TYPE_XXX }
      hDataBase: HANDLE;                       { ���������� ��, � ������� ���������� ���� �� }
      sircName: array[0..cb_SI_NAME_LEN] of char;   { ��� �������� �������������� �� }
                                                      { (��� "", ���� �� �� ���������������)}
      sircUser: array[0..cb_USER_NAME_LEN] of char; { ��� ������������ �������� �������������� �� }
      regSDate: kdate;                                { ���� ����������� �� }
      regEDate: kdate;                                { ���� ��������� ����������� ��  }
      siaDump: array[0..cb_SIA_DUMP_SIZE] of char;    { �������� ����� �� }
      kpdDump: array[0..cb_KPD_DUMP_SIZE] of char;    { �������� ����� 1-�� ��� }
   end;

const
   cb_GSD_TEST_SIKPD = 1;
   cb_GSD_FROM_FILE  = 2;

function cb_dbGetSIDetails(hDB: HANDLE; const siName: PChar;
                           flags: Integer; sd: cb_SI_DETAILS): Integer;
{ ��������� ��������� ���������� � ��.
IN:
  hDB       - ���������� ��, ���������� �� ������� cb_dbOpenDatabase. ���� NULL, ��
              ����� �� ������� �� ���� �������� ��.
  keyName   - ��� ��, ��������� ���������� � ������� ����� ��������.
  flags     - ����� ��������:
    cb_GSD_TEST_SIKPD - ����� ���������� �������� ��������� ���������� � ��, �����������
              �������� ��� ��. ���� ��� �� �����, ������������ ������ �� ������
              "������ ���".
    cb_CSD_FROM_FILE - ����� �� ������� �� � ��, � siName �������� ������
              ����� ��������������. hDB � ���� ������ ������������.
OUT:
  sd        - ��������� �� ���������, ���������� ���������� � ��.
RESULT:
  0 - �����
  CBERR ��� ������.
}

{ ====================================================================
                       �������� / ��������� ��.
======================================================================= }

function cb_createIA(const cki: Pcb_IA_INFO; const piDir: PChar;
                     const siDir: PChar): Integer;
{ ������� �������������� ������������.
IN:
  cki         - ��������� �� ��������� � ����������� ���������������.
  piDir       - ������� ���������� �� (� ��������� '\')
  siDir       - ������� ���������� ��  (� ��������� '\')
RESULT:
  0 - �����
  CBERR ��� ������.
NOTE:
  �� ������� ���������� .SK, � �� - .PK
}

function cb_getPIAInfo(const piaFile: PChar; info: cb_IA_INFO): Integer;
{ �������� ���������� � ���.
IN:
  piaFile     - ����, � ������� �������� ���
OUT:
  info        - ���������, � ������� ����� ��������� ����������
                � ���. ���� password ���� ��������� ����� �����������
                � "", ���� ��� �� ������ �� ������, ���
                � �� "", ���� ��� ������ �� ������.
RESULT:
  0 - �����
  CBERR ��� ������.
}

function cb_changePIAPassword(const piaFile: PChar;
                              const oldPassword: PChar;
                              const newPassword: PChar): Integer;
{ ������� ������ ���.
IN:
  piaFile     - ����, � ������� �������� ���
  oldPassword - ������ ������ ��� ("" ��� ���������� ������) (�� 20 ��������),
  newPassword - ����� ������ ��� ("", ���� ������ ���������) (�� 20 ��������)
RESULT:
  0 - �����
  1 - ������ �� �����
  CBERR ��� ������.
}

function cb_dropSICaches: Integer;
{  ���������� ���� ��. ������������, ���� ��������, ��� ����������
    �� �� ����� ���������� � ���������� �� ���������������.
}

{ ====================================================================
                     ������ � ��������� ������
======================================================================= }

function cb_createMemoryFile(dataPtr: Pointer; staticLimit: DWORD;
                             dynamicLimit: DWORD; size: DWORD;
                             nameBuf: PChar): Integer;
{ ������� ���������� � ������.
IN:
  dataPtr     - ��������� �� ���� ������, � ������� �������� ���������
                ���������� �����.
  staticLimit - ������������ ������ �����, ������� ����� ���������� � ����� dataPtr.
  dynamicLimit- ������������ ������ �����, ������� ����� ���� ��������� �� ����
                ������������� �������������� ������.
                (������ ���� dynamicLimit >=staticLimit)
  size        - ��������� ����� �����. (������ ���� size <=staticLimit)
OUT:
  nameBuf  - �����, � ������� ����� ��������� ���, ��� �������
             ����� �������� ���� ����������. ��� ����� ����� ������,
             �������� �������: \\.\$MEM$\123
RESULT:
  0 - �����
  CBERR ��� ������.
NOTE:
  ���� ����������� ��������� ������ size. �����, ���� �� ����� �������� �������� ���������
  ���������� ������� �����, ����������� ����� (�� staticLimit) ����������� � �����
  dataPtr �� ������ dataPtr+size.
  ���� ������ ����� �������� staticLimit, � dynamicLimit > staticLimit, �� ���������
  ������������ ���� ������, ��� � ����������� ��������� ����������� �����.
  ������� ��������� ����� ����� ����� ��� dynamicLimit ���������� ��� ������
  - ������ ������. ��� ������ ����� �� ����� ��������� ��������� ������ ������.
}

function cb_getMemoryFileInfo(const name: PChar; curSize: DWORD; dynPtr: Pointer; dynSize: DWORD): Integer;
{ �������� ���������� � ������������ ����� ����������� � ������.
IN:
  name     - ��� �����������, ���������� �� ������� cb_createMemoryFile.
OUT:
  curSize  - ������� ������ �����.
  dataPtr  - ����� ���������� ����� ��������� ��������� ��
             ������������ ���� ������.
  dynSize  - ����� ���������� ����� ��������� ����� �������������
             ����� ������.
RESULT:
  0 - �����
  CBERR ��� ������.
NOTE:
  ���� ��� � ����� ������������� ����� ��� (curSize<=staticLimit), ��
  dataPtr ����� ����� NULL, � dynSize = 0.
  �������, ��� ���������� ���������� � ������������ ����� ����� ��������� ���
  ����������� ������ � ����.
}

function cb_setMemoryFileSize(const name: PChar; size: DWORD): Integer;
{
{ �������� ����� ����������� (��������� ��� �������).
IN:
  name    - ��� �����������, ���������� �� ������� cb_createMemoryFile.
  size    - ����� ������ �����.
RESULT:
  0 - �����
  CBERR ��� ������.
}

function cb_closeMemoryFile(const name: PChar): Integer;
{ ������� ���������� � ������.
IN:
  name    - ��� �����������, ���������� �� ������� createMemoryFile.
RESULT:
  0 - �����
  CBERR ��� ������.
NOTE:
  ���� ���������� �������� ������������ ����, �� �� �������������.
}

{ ==============================================================================
                     ���������������� (multithreading)
================================================================================= }

function cb_createSession: DWORD {HANDLE};

function cb_linkSession(hSession: HANDLE): Integer;

function cb_unlinkSession: Integer;

function cb_freeSession(hSession: HANDLE): Integer;

{
  ���� ������ �������� ����������� ��������� � ��������, ������� ������������ ��
  ����������� �� ���������� ������� ���������� (threads) ����� ������� ���������������
  ����������.
  ������� ����� ��������� �������� ������������� ����������� � ������ (������ ��) ����
  ������.

}

{ ==============================================================================
                           ��������� ������
=================================================================================

  ��� ����������� ��������� �������� � ������ ������� ������������ ��� ��������,
  ��������������� ������. ��� �������, ��� NULL (���� ��� ������������� ��������
  ������� - ���������) ��� CBERR (���� ��� ������������� �������� - ����� �����).
  ���� ������� �� ����� ������������������ �������� ������, �� ��� �� ����� ��������
  ��������� ��������.

  ��� ��������� �������� ������ ����� �������� ����������� ���������� �� ������.
  (c�. ������� cb_getErrorInfo()).

  ���� ������ ���������� ������������ � ���������, ������������� �� Visual C++ 5.0,
  �� �������� �������������� ������ ��������� ������. ���� ������� �����
  cb_LPO_USE_VC50_EXCEPTIONS �� ����� ������������� ����������, �� ��� �������������
  ������ ������������� ���������� � ���� ������ ErrEx.

  ��������� �������� ����� ������, ������ ErrEx � ��������� cb_ERRORINFO ���������
  � ����� CBERRS.H
}

function cb_getErrorInfo(ei: Pcb_ERRORINFO): Integer;
{ �������� ���������� �� ��������� ������ � ��������� ���������.
OUT:
  ei    - ��������� �� ��������� cb_ERRORINFO, ��� ����� ��������� �����
          ���������� � ��������� ������.
}

function cb_getErrorString(code: WORD; strBuf: PChar; bufSize: DWORD): Integer;
{ �������� ��������� ���������� �� ������.
IN:
  code    - ��� ������ (�������� ���� code ��������� cb_ERRORINFO).
OUT:
  strBuf  - ��������� �� �����, � ������� ����� ��������� ������,
            ����������� ������.
  bufSize - ������ ������. ������������� �� ����� 128 ��������.
RESULT:
  ����� ���������� ������ ��� 0 ��� ������.
}

{ ==============================================================================
                           ������ � ��������
   ============================================================================== }
const
   acd_LOGSEVERITY_ERROR       = 1;
   acd_LOGSEVERITY_INFORMATION = 2;
   acd_LOGSEVERITY_WARNING     = 3;

   acd_LOGCODE_SUCCESS         = 4096;
   acd_LOGCODE_STANDARDBASE    = 4096;
   acd_LOGCODE_USERBASE        = $10000;

function cb_addLogStrings(typeID: BYTE; const msg: PChar;
                          strCount: Integer = 1): Integer;
{ ��������� ������ ����� � ������ (���� �� �������).
IN:
  str      - ����������� ������.
  severity - ��� ������� (��������� acd_LOGSEVERITY_)
RESULT:
  0 - �����
  ERR ��� ������.
}

type
   Pcb_getLibVersion = ^Tcb_getLibVersion;
   Tcb_getLibVersion = function (verMajor: Pointer; verMinor: Pointer; libType: Pointer): Integer;
   stdcall;

   Pcb_initLib = ^Tcb_initLib;
   Tcb_initLib = function (const prof: PChar; piaPasswordFunc: cb_PASSWORDFUNC; options: DWORD): Integer;
   stdcall;

   Pcb_initLibDirect = ^Tcb_initLibDirect;
   Tcb_initLibDirect = function (const par: Pcb_LIBPARAMS): Integer;
   stdcall;

   Pcb_doneLib = ^Tcb_doneLib;
   Tcb_doneLib = function: Integer;
   stdcall;

   Pcb_getCurrentUser = ^Tcb_getCurrentUser;
   Tcb_getCurrentUser = function (piaName: PChar; userName: PChar): Integer;
   stdcall;

   Pcb_getLibSettings = ^Tcb_getLibSettings;
   Tcb_getLibSettings = function (par: cb_LIBPARAMS): Integer;
   stdcall;

   Pcb_createArchive = ^Tcb_createArchive;
   Tcb_createArchive = function (const fileName: PChar; method: Integer;
                                 users: PArrayOfPChar; userNum: Integer;
                                 func: Pcb_PROGRESSFUNC; fParam: Pointer): HANDLE;
   stdcall;

   Pcb_getArchiveInfo = ^Tcb_getArchiveInfo;
   Tcb_getArchiveInfo = function (const fileName: PChar; needDetails: Boolean;
                                  func: cb_ENUM_SI_FUNC; fParam: Pointer): Integer;
   stdcall;

   Pcb_openArchive = ^Tcb_openArchive;
   Tcb_openArchive = function (const fileName: PChar; creator: PChar;
                               func: Pcb_PROGRESSFUNC; fParam: Pointer): HANDLE;
   stdcall;

   Pcb_getFirstFile = ^Tcb_getFirstFile;
   Tcb_getFirstFile = function (hArc: HANDLE; info: Pcb_ARCHFILEINFO): Integer;
   stdcall;

   Pcb_getNextFile = ^Tcb_getNextFile;
   Tcb_getNextFile = function (hArc: HANDLE; info: Pcb_ARCHFILEINFO): Integer;
   stdcall;

   Pcb_addFile = ^Tcb_addFile;
   Tcb_addFile = function (hArc: HANDLE; const srcName: PChar; const dstName: PChar;
                           flags: Integer;
                           func: Pcb_PROGRESSFUNC; fParam: Pointer): Integer;
   stdcall;

   Pcb_extractCurFile = ^Tcb_extractCurFile;
   Tcb_extractCurFile = function (hArc: HANDLE; destName: PChar; flags: Integer;
                                  func: Pcb_PROGRESSFUNC; fParam: Pointer): Integer;
   stdcall;

   Pcb_closeArchive = ^Tcb_closeArchive;
   Tcb_closeArchive = function (hArc: HANDLE; func: Pcb_PROGRESSFUNC; fParam: Pointer): Integer;
   stdcall;

   Pcb_abortArchive = ^Tcb_abortArchive;
   Tcb_abortArchive = function (hArc: HANDLE): Integer;
   stdcall;

   Pcb_testFileKPD = ^Tcb_testFileKPD;
   Tcb_testFileKPD = function (const fileName: PChar; func: Pcb_PROGRESSFUNC; fParam: Pointer): Integer;
   stdcall;

   Pcb_setFileKPD = ^Tcb_setFileKPD;
   Tcb_setFileKPD = function (const fileName: PChar; func: Pcb_PROGRESSFUNC; fParam: Pointer): Integer;
   stdcall;

   Pcb_delFileKPD = ^Tcb_delFileKPD;
   Tcb_delFileKPD = function (const fileName: PChar; num: Integer): Integer;
   stdcall;

   Pcb_getFileKPDCount = ^Tcb_getFileKPDCount;
   Tcb_getFileKPDCount = function (const fileName: PChar): Integer;
   stdcall;

   Pcb_dbOpenDatabase = ^Tcb_dbOpenDatabase;
   Tcb_dbOpenDatabase = function (const dbName: PChar; mode: Integer; atype: Integer): HANDLE;
   stdcall;

   Pcb_dbCloseDatabase = ^Tcb_dbCloseDatabase;
   Tcb_dbCloseDatabase = function (hDB: HANDLE): Integer;
   stdcall;             

   Pcb_dbPackDatabase = ^Tcb_dbPackDatabase;
   Tcb_dbPackDatabase = function (hDB: HANDLE): Integer;
   stdcall;

   Pcb_dbGetDBHandles = ^Tcb_dbGetDBHandles;
   Tcb_dbGetDBHandles = function (handlesBuffer: HANDLE; handlesNeed: Integer): Integer;
   stdcall;

   Pcb_dbGetDatabaseInfo = ^Tcb_dbGetDatabaseInfo;
   Tcb_dbGetDatabaseInfo = function (hDB: HANDLE; dbi: cb_DBINFO): Integer;
   stdcall;

   Pcb_dbDeleteSI = ^Tcb_dbDeleteSI;
   Tcb_dbDeleteSI = function (hDB: HANDLE; const siName: PChar): Integer;
   stdcall;

   Pcb_dbAddSI = ^Tcb_dbAddSI;
   Tcb_dbAddSI = function (hDB: HANDLE; const siName: PChar; mode: Integer;
                           hDBSrc: HANDLE): Integer;
   stdcall;

   Pcb_dbExtractSI = ^Tcb_dbExtractSI;
   Tcb_dbExtractSI = function (hDB: HANDLE; const siName: PChar; dstDir: PChar): Integer;
   stdcall;

   Pcb_enumSI = ^Tcb_enumSI;
   Tcb_enumSI = function (hDB: HANDLE; mode: Integer; func: cb_ENUM_SI_FUNC; fParam: Pointer): Integer;
   stdcall;

   Pcb_dbGetSIDetails = ^Tcb_dbGetSIDetails;
   Tcb_dbGetSIDetails = function (hDB: HANDLE; const siName: PChar;
                                  flags: Integer; sd: cb_SI_DETAILS): Integer;
   stdcall;

   Pcb_createIA = ^Tcb_createIA;
   Tcb_createIA = function (const cki: Pcb_IA_INFO; const piDir: PChar; const siDir: PChar): Integer;
   stdcall;

   Pcb_getPIAInfo = ^Tcb_getPIAInfo;
   Tcb_getPIAInfo = function (const piaFile: PChar; info: cb_IA_INFO): Integer;
   stdcall;

   Pcb_changePIAPassword = ^Tcb_changePIAPassword;
   Tcb_changePIAPassword = function (const piaFile: PChar;
                                     const oldPassword: PChar;
                                     const newPassword: PChar): Integer;
   stdcall;

   Pcb_dropSICaches = ^Tcb_dropSICaches;
   Tcb_dropSICaches = function: Integer;
   stdcall;

   Pcb_createMemoryFile = ^Tcb_createMemoryFile;
   Tcb_createMemoryFile = function (dataPtr: Pointer; staticLimit: DWORD;
                                    dynamicLimit: DWORD; size: DWORD;
                                    nameBuf: PChar): Integer;
   stdcall;

   Pcb_getMemoryFileInfo = ^Tcb_getMemoryFileInfo;
   Tcb_getMemoryFileInfo = function (const name: PChar; curSize: DWORD; dynPtr: Pointer; dynSize: DWORD): Integer;
   stdcall;

   Pcb_setMemoryFileSize = ^Tcb_setMemoryFileSize;
   Tcb_setMemoryFileSize = function (const name: PChar; size: DWORD): Integer;
   stdcall;

   Pcb_closeMemoryFile = ^Tcb_closeMemoryFile;
   Tcb_closeMemoryFile = function (const name: PChar): Integer;
   stdcall;

   Pcb_createSession = ^Tcb_createSession;
   Tcb_createSession = function: HANDLE;
   stdcall;

   Pcb_linkSession = ^Tcb_linkSession;
   Tcb_linkSession = function (hSession: HANDLE): Integer;
   stdcall;

   Pcb_unlinkSession = ^Tcb_unlinkSession;
   Tcb_unlinkSession = function : Integer;
   stdcall;

   Pcb_freeSession = ^Tcb_freeSession;
   Tcb_freeSession = function (hSession: HANDLE): Integer;
   stdcall;

   Pcb_getErrorInfo = ^Tcb_getErrorInfo;
   Tcb_getErrorInfo = function (ei: Pcb_ERRORINFO): Integer;
   stdcall;

   Pcb_getErrorString = ^Tcb_getErrorString;
   Tcb_getErrorString = function (code: WORD; strBuf: PChar; bufSize: DWORD): Integer;
   stdcall;

   Pcb_addLogStrings = ^Tcb_addLogStrings;
   Tcb_addLogStrings = function (typeID: BYTE; const msg: PChar; strCount: Integer = 1): Integer;
   stdcall;

var
   Fcb_getLibVersion: Tcb_getLibVersion;
   Fcb_initLib: Tcb_initLib;
   Fcb_initLibDirect: Tcb_initLibDirect;
   Fcb_doneLib: Tcb_doneLib;
   Fcb_getCurrentUser: Tcb_getCurrentUser;
   Fcb_getLibSettings: Tcb_getLibSettings;
   Fcb_createArchive: Tcb_createArchive;
   Fcb_getArchiveInfo: Tcb_getArchiveInfo;
   Fcb_openArchive: Tcb_openArchive;
   Fcb_getFirstFile: Tcb_getFirstFile;
   Fcb_getNextFile: Tcb_getNextFile;
   Fcb_addFile: Tcb_addFile;
   Fcb_extractCurFile: Tcb_extractCurFile;
   Fcb_closeArchive: Tcb_closeArchive;
   Fcb_abortArchive: Tcb_abortArchive;
   Fcb_testFileKPD: Tcb_testFileKPD;
   Fcb_setFileKPD: Tcb_setFileKPD;
   Fcb_delFileKPD: Tcb_delFileKPD;
   Fcb_getFileKPDCount: Tcb_getFileKPDCount;
   Fcb_dbOpenDatabase: Tcb_dbOpenDatabase;
   Fcb_dbCloseDatabase: Tcb_dbCloseDatabase;
   Fcb_dbPackDatabase: Tcb_dbPackDatabase;
   Fcb_dbGetDBHandles: Tcb_dbGetDBHandles;
   Fcb_dbGetDatabaseInfo: Tcb_dbGetDatabaseInfo;
   Fcb_dbDeleteSI: Tcb_dbDeleteSI;
   Fcb_dbAddSI: Tcb_dbAddSI;
   Fcb_dbExtractSI: Tcb_dbExtractSI;
   Fcb_enumSI: Tcb_enumSI;
   Fcb_dbGetSIDetails: Tcb_dbGetSIDetails;
   Fcb_createIA: Tcb_createIA;
   Fcb_getPIAInfo: Tcb_getPIAInfo;
   Fcb_changePIAPassword: Tcb_changePIAPassword;
   Fcb_dropSICaches: Tcb_dropSICaches;
   Fcb_createMemoryFile: Tcb_createMemoryFile;
   Fcb_getMemoryFileInfo: Tcb_getMemoryFileInfo;
   Fcb_setMemoryFileSize: Tcb_setMemoryFileSize;
   Fcb_closeMemoryFile: Tcb_closeMemoryFile;
   Fcb_createSession: Tcb_createSession;
   Fcb_linkSession: Tcb_linkSession;
   Fcb_unlinkSession: Tcb_unlinkSession;
   Fcb_freeSession: Tcb_freeSession;
   Fcb_getErrorInfo: Tcb_getErrorInfo;
   Fcb_getErrorString: Tcb_getErrorString;
   Fcb_addLogStrings: Tcb_addLogStrings;

implementation

function LoadDLL(NameDll: string): HModule;
begin
   Result := LoadLibrary(PChar(NameDll));
   if Result < HINSTANCE_ERROR then begin
      MessageDlg('Couldn''t load DLL: '+NameDll, mtWarning, [mbOk], 0);
   end;
end;

function GetProcAddressDLL(HandleDll: HModule; NameFunc: String): Pointer;
begin
   Result := GetProcAddress(HandleDll, PChar(NameFunc));
   if Result = nil then begin
      MessageDlg('DLL '+SAED32+'havn''t '+NameFunc+' procedure', mtWarning, [mbOk], 0);
   end;
end;

procedure InitSAED32;
begin
   SAED32Module := LoadDLL(SAED32);
end;

function CheckError(ResultFun: Integer): Integer;
begin
   FillChar(ei,SizeOf(ei),0);
   FillChar(sei,SizeOf(sei),0);
   Result := ResultFun;
   if ResultFun = CBERR then begin
      cb_getErrorInfo(@ei);
      cb_getErrorString(ei.code, @sei, SizeOf(sei));
   end;
end;

// ==============================================================================
//                             �����/���������
//===============================================================================
function cb_initLib(const prof: PChar; piaPasswordFunc: cb_PASSWORDFUNC; options: DWORD): Integer;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_initLib = nil then @Fcb_initLib := GetProcAddressDLL(SAED32Module, ncb_initLib);
   if @Fcb_initLib <> nil then
      Result := CheckError(Fcb_initLib(prof, piaPasswordFunc, options))
   else
      Result := CBERR;
end;

function cb_initLibDirect;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_initLibDirect = nil then @Fcb_initLibDirect := GetProcAddressDLL(SAED32Module, ncb_initLibDirect);
   if @Fcb_initLibDirect <> nil then begin
      Result := CheckError(Fcb_initLibDirect(par));
      end
   else
      Result := CBERR;
end;

function cb_doneLib;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_doneLib = nil then @Fcb_doneLib := GetProcAddressDLL(SAED32Module, ncb_doneLib);
   if @Fcb_doneLib <> nil then
      Result := CheckError(Fcb_doneLib())
   else
      Result := CBERR;
end;

function cb_getCurrentUser;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_getCurrentUser = nil then @Fcb_getCurrentUser := GetProcAddressDLL(SAED32Module, ncb_getCurrentUser);
   if @Fcb_getCurrentUser <> nil then
      Result := CheckError(Fcb_getCurrentUser(piaName, userName))
   else
      Result := CBERR;
end;

function cb_getLibSettings;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_getLibSettings = nil then @Fcb_getLibSettings := GetProcAddressDLL(SAED32Module, ncb_getLibSettings);
   if @Fcb_getLibSettings <> nil then
      Result := CheckError(Fcb_getLibSettings(par))
   else
      Result := CBERR;
end;

function cb_getLibVersion;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_getLibVersion = nil then @Fcb_getLibVersion := GetProcAddressDLL(SAED32Module, ncb_getLibVersion);
   if @Fcb_getLibVersion <> nil then begin
      Result := Fcb_getLibVersion(verMajor, verMinor, libType);
      Result := CheckError(Result);
      end
   else
      Result := CBERR;
end;

//==============================================================================
//                        ������� ������ � �������
//==============================================================================
function cb_createArchive(const fileName: PChar; method: Integer;
                          users: PArrayOfPChar; userNum: Integer;
                          func: Pcb_PROGRESSFUNC; fParam: Pointer): HANDLE;
var
   FException: Exception;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_createArchive = nil then
      @Fcb_createArchive := GetProcAddressDLL(SAED32Module, ncb_createArchive);
   if @Fcb_createArchive <> nil then begin
      Result := Fcb_createArchive(fileName, method, users, userNum, func, fParam);
   end;
end;

function cb_getArchiveInfo;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_getArchiveInfo = nil then @Fcb_getArchiveInfo := GetProcAddressDLL(SAED32Module, ncb_getArchiveInfo);
   if @Fcb_getArchiveInfo <> nil then
      Result := CheckError(Fcb_getArchiveInfo(fileName, needDetails, func, fParam))
   else
      Result := CBERR;
end;

function cb_openArchive;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_openArchive = nil then @Fcb_openArchive := GetProcAddressDLL(SAED32Module, ncb_openArchive);
   if @Fcb_openArchive <> nil then begin
      Result := Fcb_openArchive(fileName, creator, func, fParam);
      CheckError(0);
      end
   else begin
      Result := 0;
      CheckError(CBEC_USERCLASS_BASE);
   end;
end;

function cb_getFirstFile;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_getFirstFile = nil then @Fcb_getFirstFile := GetProcAddressDLL(SAED32Module, ncb_getFirstFile);
   if @Fcb_getFirstFile <> nil then
      Result := CheckError(Fcb_getFirstFile(hArc, info))
   else
      Result := CBERR;
end;

function cb_getNextFile;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_getNextFile = nil then @Fcb_getNextFile := GetProcAddressDLL(SAED32Module, ncb_getNextFile);
   if @Fcb_getNextFile <> nil then
      Result := CheckError(Fcb_getNextFile(hArc, info))
   else
      Result := CBERR;
end;

function cb_addFile(hArc: HANDLE; const srcName: PChar; const dstName: PChar; flags: Integer;
                    func: Pcb_PROGRESSFUNC; fParam: Pointer): Integer;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_addFile = nil then @Fcb_addFile := GetProcAddressDLL(SAED32Module, ncb_addFile);
   if @Fcb_addFile <> nil then begin
      try
         Result := CheckError(Fcb_addFile(hArc, srcName, dstName, flags, func, fParam))
      except
         Result := CBERR;
      end;
      end
   else
      Result := CBERR;
end;

function cb_extractCurFile;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_extractCurFile = nil then @Fcb_extractCurFile := GetProcAddressDLL(SAED32Module, ncb_extractCurFile);
   if @Fcb_extractCurFile <> nil then
      Result := CheckError(Fcb_extractCurFile(hArc, destName, flags, func, fParam))
   else
      Result := CBERR;
end;

function cb_closeArchive;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_closeArchive = nil then @Fcb_closeArchive := GetProcAddressDLL(SAED32Module, ncb_closeArchive);
   if @Fcb_closeArchive <> nil then begin
      try
         Result := CheckError(Fcb_closeArchive(hArc, func, fParam))
      except
         Result := CBERR;
      end;
      end
   else
      Result := CBERR;
end;

function cb_abortArchive;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_abortArchive = nil then @Fcb_abortArchive := GetProcAddressDLL(SAED32Module, ncb_abortArchive);
   if @Fcb_abortArchive <> nil then
      Result := CheckError(Fcb_abortArchive(hArc))
   else
      Result := CBERR;
end;

// =======================================================================
//                    ��� ������������� �������������
// =======================================================================
function cb_testFileKPD(const fileName: PChar; func: Pcb_PROGRESSFUNC; fParam: Pointer): Integer;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_testFileKPD = nil then @Fcb_testFileKPD := GetProcAddressDLL(SAED32Module, ncb_testFileKPD);
   if @Fcb_testFileKPD <> nil then
      Result := CheckError(Fcb_testFileKPD(fileName, func, fParam))
   else
      Result := CBERR;
end;

function cb_setFileKPD;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_setFileKPD = nil then @Fcb_setFileKPD := GetProcAddressDLL(SAED32Module, ncb_setFileKPD);
   if @Fcb_setFileKPD <> nil then
      Result := CheckError(Fcb_setFileKPD(fileName, func, fParam))
   else
      Result := CBERR;
end;

function cb_delFileKPD;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_delFileKPD = nil then @Fcb_delFileKPD := GetProcAddressDLL(SAED32Module, ncb_delFileKPD);
   if @Fcb_delFileKPD <> nil then
      Result := CheckError(Fcb_delFileKPD(fileName, num))
   else
      Result := CBERR;
end;

function cb_getFileKPDCount;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_getFileKPDCount = nil then @Fcb_getFileKPDCount := GetProcAddressDLL(SAED32Module, ncb_getFileKPDCount);
   if @Fcb_getFileKPDCount <> nil then
      Result := CheckError(Fcb_getFileKPDCount(fileName))
   else
      Result := CBERR;
end;

// ====================================================================
//                   ���� ������ ��� � ����
//=====================================================================
function cb_dbOpenDatabase;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_dbOpenDatabase = nil then @Fcb_dbOpenDatabase := GetProcAddressDLL(SAED32Module, ncb_dbOpenDatabase);
   if @Fcb_dbOpenDatabase <> nil then
      Result := CheckError(Fcb_dbOpenDatabase(dbName, mode, atype))
   else
      Result := 0;
end;

function cb_dbCloseDatabase;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_dbCloseDatabase = nil then @Fcb_dbCloseDatabase := GetProcAddressDLL(SAED32Module, ncb_dbCloseDatabase);
   if @Fcb_dbCloseDatabase <> nil then
      Result := CheckError(Fcb_dbCloseDatabase(hDB))
   else
      Result := CBERR;
end;

function cb_dbPackDatabase;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_dbPackDatabase = nil then @Fcb_dbPackDatabase := GetProcAddressDLL(SAED32Module, ncb_dbPackDatabase);
   if @Fcb_dbPackDatabase <> nil then
      Result := CheckError(Fcb_dbPackDatabase(hDB))
   else
      Result := CBERR;
end;

function cb_dbGetDBHandles;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_dbGetDBHandles = nil then @Fcb_dbGetDBHandles := GetProcAddressDLL(SAED32Module, ncb_dbGetDBHandles);
   if @Fcb_dbGetDBHandles <> nil then
      Result := CheckError(Fcb_dbGetDBHandles(handlesBuffer, handlesNeed))
   else
      Result := CBERR;
end;

function cb_dbGetDatabaseInfo;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_dbGetDatabaseInfo = nil then @Fcb_dbGetDatabaseInfo := GetProcAddressDLL(SAED32Module, ncb_dbGetDatabaseInfo);
   if @Fcb_dbGetDatabaseInfo <> nil then
      Result := CheckError(Fcb_dbGetDatabaseInfo(hDB, dbi))
   else
      Result := CBERR;
end;

function cb_dbDeleteSI;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_dbDeleteSI = nil then @Fcb_dbDeleteSI := GetProcAddressDLL(SAED32Module, ncb_dbDeleteSI);
   if @Fcb_dbDeleteSI <> nil then
      Result := CheckError(Fcb_dbDeleteSI(hDB, siName))
   else
      Result := CBERR;
end;

function cb_dbAddSI;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_dbAddSI = nil then @Fcb_dbAddSI := GetProcAddressDLL(SAED32Module, ncb_dbAddSI);
   if @Fcb_dbAddSI <> nil then
      Result := CheckError(Fcb_dbAddSI(hDB, siName, mode, hDBSrc))
   else
      Result := CBERR;
end;

function cb_dbExtractSI;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_dbExtractSI = nil then @Fcb_dbExtractSI := GetProcAddressDLL(SAED32Module, ncb_dbExtractSI);
   if @Fcb_dbExtractSI <> nil then
      Result := CheckError(Fcb_dbExtractSI(hDB, siName, dstDir))
   else
      Result := CBERR;
end;

function cb_enumSI;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_enumSI = nil then @Fcb_enumSI := GetProcAddressDLL(SAED32Module, ncb_enumSI);
   if @Fcb_enumSI <> nil then
      Result := CheckError(Fcb_enumSI(hDB, mode, func, fParam))
   else
      Result := CBERR;
end;

function cb_dbGetSIDetails;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_dbGetSIDetails = nil then @Fcb_dbGetSIDetails := GetProcAddressDLL(SAED32Module, ncb_dbGetSIDetails);
   if @Fcb_dbGetSIDetails <> nil then
      Result := CheckError(Fcb_dbGetSIDetails(hDB, siName, flags, sd))
   else
      Result := CBERR;
end;

// ====================================================================
//                     �������� / ��������� ��.
//=====================================================================
function cb_createIA;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_createIA = nil then @Fcb_createIA := GetProcAddressDLL(SAED32Module, ncb_createIA);
   if @Fcb_createIA <> nil then
      Result := CheckError(Fcb_createIA(cki, piDir, siDir))
   else
      Result := CBERR;
end;

function cb_getPIAInfo;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_getPIAInfo = nil then @Fcb_getPIAInfo := GetProcAddressDLL(SAED32Module, ncb_getPIAInfo);
   if @Fcb_getPIAInfo <> nil then
      Result := CheckError(Fcb_getPIAInfo(piaFile, info))
   else
      Result := CBERR;
end;

function cb_changePIAPassword;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_changePIAPassword = nil then @Fcb_changePIAPassword := GetProcAddressDLL(SAED32Module, ncb_changePIAPassword);
   if @Fcb_changePIAPassword <> nil then
      Result := CheckError(Fcb_changePIAPassword(piaFile, oldPassword, newPassword))
   else
      Result := CBERR;
end;

function cb_dropSICaches;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_dropSICaches = nil then @Fcb_dropSICaches := GetProcAddressDLL(SAED32Module, ncb_dropSICaches);
   if @Fcb_dropSICaches <> nil then
      Result := CheckError(Fcb_dropSICaches())
   else
      Result := CBERR;
end;

// ====================================================================
//                   ������ � ��������� ������
//=====================================================================
function cb_createMemoryFile;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_createMemoryFile = nil then @Fcb_createMemoryFile := GetProcAddressDLL(SAED32Module, ncb_createMemoryFile);
   if @Fcb_createMemoryFile <> nil then
      Result := CheckError(Fcb_createMemoryFile(dataPtr, staticLimit, dynamicLimit, size, nameBuf))
   else
      Result := CBERR;
end;

function cb_getMemoryFileInfo;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_getMemoryFileInfo = nil then @Fcb_getMemoryFileInfo := GetProcAddressDLL(SAED32Module, ncb_getMemoryFileInfo);
   if @Fcb_getMemoryFileInfo <> nil then
      Result := CheckError(Fcb_getMemoryFileInfo(name, curSize, dynPtr, dynSize))
   else
      Result := CBERR;
end;

function cb_setMemoryFileSize;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_setMemoryFileSize = nil then @Fcb_setMemoryFileSize := GetProcAddressDLL(SAED32Module, ncb_setMemoryFileSize);
   if @Fcb_setMemoryFileSize <> nil then
      Result := CheckError(Fcb_setMemoryFileSize(name, size))
   else
      Result := CBERR;
end;

function cb_closeMemoryFile;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_closeMemoryFile = nil then @Fcb_closeMemoryFile := GetProcAddressDLL(SAED32Module, ncb_closeMemoryFile);
   if @Fcb_closeMemoryFile <> nil then
      Result := CheckError(Fcb_closeMemoryFile(name))
   else
      Result := CBERR;
end;


// ==============================================================================
//                   ���������������� (multithreading)
//===============================================================================
function cb_createSession;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_createSession = nil then @Fcb_createSession := GetProcAddressDLL(SAED32Module, ncb_createSession);
   if @Fcb_createSession <> nil then
      Result := CheckError(Fcb_createSession())
   else
      Result := 0;
end;

function cb_linkSession;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_linkSession = nil then @Fcb_linkSession := GetProcAddressDLL(SAED32Module, ncb_linkSession);
   if @Fcb_linkSession <> nil then
      Result := CheckError(Fcb_linkSession(hSession))
   else
      Result := CBERR;
end;

function cb_unlinkSession;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_unlinkSession = nil then @Fcb_unlinkSession := GetProcAddressDLL(SAED32Module, ncb_unlinkSession);
   if @Fcb_unlinkSession <> nil then
      Result := CheckError(Fcb_unlinkSession())
   else
      Result := CBERR;
end;

function cb_freeSession;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_freeSession = nil then @Fcb_freeSession := GetProcAddressDLL(SAED32Module, ncb_freeSession);
   if @Fcb_freeSession <> nil then
      Result := CheckError(Fcb_freeSession(hSession))
   else
      Result := CBERR;
end;

// ==============================================================================
//                         ��������� ������
//===============================================================================
function cb_getErrorInfo;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_getErrorInfo = nil then @Fcb_getErrorInfo := GetProcAddressDLL(SAED32Module, ncb_getErrorInfo);
   if @Fcb_getErrorInfo <> nil then
      Result := Fcb_getErrorInfo(ei)
   else
      Result := CBERR;
end;

function cb_getErrorString;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_getErrorString = nil then @Fcb_getErrorString := GetProcAddressDLL(SAED32Module, ncb_getErrorString);
   if @Fcb_getErrorString <> nil then
      Result := Fcb_getErrorString(code, strBuf, bufSize)
   else
      Result := CBERR;
end;


// ==============================================================================
//                         ������ � ��������
// ==============================================================================
function cb_addLogStrings;
begin
   Result := 0;
   InitSAED32;
   if @Fcb_addLogStrings = nil then @Fcb_addLogStrings := GetProcAddressDLL(SAED32Module, ncb_addLogStrings);
   if @Fcb_addLogStrings <> nil then
      Result := CheckError(Fcb_addLogStrings(typeID, msg, strCount))
   else
      Result := CBERR;
end;

initialization

   FpassDefault := '';

finalization

   if SAED32Module <> 0 then FreeLibrary(SAED32Module);

end.
