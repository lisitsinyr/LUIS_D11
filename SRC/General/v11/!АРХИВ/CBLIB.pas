unit CBLIB;

interface

uses
   Windows, Dialogs, sysutils,
   cberrs, cbnames;

{ ==============================================================================
                       Описание структуры данного файла.

  В данном файле перечислены типы данных и прототипы функций, реализованных в
  данной библиотеке.

  При описании функции используется следующая модель:
    <прототип функции со списком ее параметров>
    <общее описание функции>
    IN:       <секция описания входных параметров>
    OUT:      <секция описания параметров - результатов>
    RESULT:   <секция описания возвращаемого значения>
    NOTE:     <замечания по работе функции>
    PROGRESS: <секция описания временых характеристик работы функции
               (только для медленных операций)>
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
   cb_PASSWORD_LEN = 20;   // максимальная длина пароля

{==============================================================================
                      Структуры данных, типы, CALLBACK-функции
=================================================================================}
type
   TpassBuf = array [0..cb_PASSWORD_LEN] of char;

var
   FpassDefault: string;
   FpassBuf: TpassBuf;
   FpiaName: array [0..MAX_PATH] of char;
   FuserName: array [0..cb_USER_NAME_LEN] of char; { имя пользователя идентификатора }

type
   Pcb_PASSWORDFUNC = ^cb_PASSWORDFUNC;
   cb_PASSWORDFUNC = function (passBuf: Pointer; piaName: PChar; userName: PChar): Integer;
{ Прототип функции запроса пароля пользователя. Вызывается библиотекой при
   инициализации, если указанный ПИА зашифрован на пароле.
IN:
  piaName     - указатель на строку-название ПИА
  userName    - указатель на строку-имя владельца ПИА
OUT:
  passBuf     - буфер для пароля.
                Пароль должен не длиннее чем cb_PASSWORD_LEN.
RESULT:
  0   - пароль введен.
  !=0 - пользователь отказался вводить пароль.
}

{ Структура параметров библиотеки: }
type
   Pcb_LIBPARAMS = ^cb_LIBPARAMS;
   cb_LIBPARAMS = packed record
      piaName: array [0..MAX_PATH] of char;    { имя ПИА (полный путь) }
      piaPasswordFunc: Pcb_PASSWORDFUNC;       { указатель на функцию запроса пароля ПИА }
      siaDir: array [0..MAX_PATH] of char;     { каталог БД СИА }
      sircDir: array [0..MAX_PATH] of char;    { каталог БД СИРЦ }
      simpleFile: array [0..MAX_PATH] of char; { имя файла простых чисел (полный путь)}
      logFile: array [0..MAX_PATH] of char;    { имя LOG-файла }
      logFlags: DWORD;                         { флаги протоколируемых операций cb_LOGF_XX}
      options: DWORD;                          { опции cb_LPO_XXX }
      reserved: PChar;                         { зарезервировано, должно быть NULL }
   end;

const
   cb_LOGF_ALL    = $FFFFFFFF;  { Протоколируются все операции }
   cb_LOGF_NONE   = 0;          { Операции не протоколируются }

   cb_LPO_DONT_OPEN_DB = 1;     { Не загружать автоматически БД СИА.
                                   Если не указан, то сканируется каталог
                                   siaDir и открываются все БД.
                                   (cм. раздел "Базы данных СИА и СИРЦ")
                                }

   cb_LPO_DONT_OPEN_DB_SIRC    = 4; { Не загружать автоматически БД СИРЦ.
                                       Если не указан, то сканируется каталог
                                       sircDir и открываются все БД.
                                       (cм. раздел "Базы данных СИА и СИРЦ")
                                    }
   cb_LPO_USE_VC50_EXCEPTIONS  = 2; { Для диагностики ошибок использовать
                                       исключения VC++ 5.0
                                       (см. раздел "Диагностика ошибок")
                                     }

{ Типы даты, времени и ряд констант для совместимости с DOS-версией }
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

{ Атрибуты файла }
const
   DOS_FA_RDONLY    = 1;
   DOS_FA_HIDDEN    = 2;
   DOS_FA_SYSTEM    = 4;
   DOS_FA_LABEL     = 8;
   DOS_FA_DIREC     = 16;
   DOS_FA_ARCH      = 32;

{ Структура информации о заархивированном файле:  }
type
   Pcb_ARCHFILEINFO = ^cb_ARCHFILEINFO;
   cb_ARCHFILEINFO = packed record
      fileName: array [0..MAX_PATH] of char;       { имя файла (может включать подкаталоги) }
      attrib: WORD;                   { аттрибуты (DOS_FA_XXX) }
      size: DWORD;                    { размер файла (изначальный)}
      dateTime: dos_ftime;     { дата последней модификации файла }
   end;

{ ==========================================================================
                      Отображение прогресса операций
   ========================================================================== }
const
   { типы событий прогресса  }
   cb_PFC_PROGRESS     = 1;    { обработана очередная порция данных }
   cb_PFC_KPD_FOUND    = 2;    { в файле обнаружен КПД }
   cb_PFC_KPD_TESTED   = 3;    { в файле проверен КПД  }

{ Структура данных, если событие = cb_PFC_PROGRESS: }
type
   Pcb_PFI_PROGRESS = ^cb_PFI_PROGRESS;
   cb_PFI_PROGRESS = packed record
      totalSize: DWORD;            { общий объем работы }
      doneSize: DWORD;             { сделано к данному моменту }
   end;

{ Структура данных, если событие =  cb_PFC_KPD_FOUND: }
type
   Pcb_PFI_KPDINFO = ^cb_PFI_KPDINFO;
   cb_PFI_KPDINFO = packed record
      siName: array [0..cb_SI_NAME_LEN] of char;       { имя идентификатора пользователя, создавшего КПД  }
      userName: array [0..cb_USER_NAME_LEN] of char;   { имя пользователя, создавшего КПД }
      sdate: kdate;                  { дата создания КПД }
   end;

const
   TEST_PARAM_LEN = 256;

{ Структура данных, если событие = cb_PFC_KPD_TESTED: }
type
   Pcb_PFI_KPDTEST = ^cb_PFI_KPDTEST;
   cb_PFI_KPDTEST = packed record
      siName: array [0..cb_SI_NAME_LEN] of char;     { имя идентификатора пользователя, создавшего КПД  }
      userName: array [0..cb_USER_NAME_LEN] of char;  { имя пользователя, создавшего КПД }
      sdate: kdate;                                    { дата создания КПД }
      testResult: WORD;                                { результат проверки КПД }
      TestParam: array [0..TEST_PARAM_LEN] of char;    { параметр результата проверки КПД }
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
      cause: Integer;                   { событие прогресса (см. константы PFC_XXX) }
      info: cb_PF_PARAMS_Info;
      fParam: Pointer;               { параметр, переданный в вызывающую функцию библиотеки }
   end;

type
   Pcb_PROGRESSFUNC = ^cb_PROGRESSFUNC;
   cb_PROGRESSFUNC = function (params: Pcb_PF_PARAMS): Integer; stdcall;
{ Прототип функции отображения прогресса длительных операций.
IN:
  params   - параметр очередного шага прогресса длительной операции.
RESULT:
  0 - все в порядке
  1 - необходимо прервать операцию.
  2 - необходимо пропустить данную часть операции (только если cause=cb_PFC_KPD_FOUND)
}

{ ================================================================================= }
const
   cb_SI_TYPE_SIA   = 1;        { сетевой идентификатор абонента }
   cb_SI_TYPE_SIRC  = 2;        { сетевой идентификатор регистрационного центра }

{ Структура информации об идентификаторе: }
type
   Pcb_SI_INFO = ^cb_SI_INFO;
   cb_SI_INFO = packed record
      siaName: array [0..cb_SI_NAME_LEN] of char;    { имя сетевого идентификатора }
      userName: array [0..cb_USER_NAME_LEN] of char; { имя пользователя идентификатора }
      sdate: kdate;
      edate: kdate;                              { дата начала и окончания срока использования СИ }
      typeINT: Integer;                          { тип идентификатора - cb_SI_TYPE_XXX }
      hDataBase: HANDLE;                  { дескриптор БД, в которой расположен этот СИ }
   end;

type
   cb_ENUM_SI_FUNC = function (siInfo: cb_SI_INFO; fParam: Pointer): Integer;
{ Прототип функции, вызываемой для каждого СИ при перечислении СИ
   функцией cb_enumSI.
IN:
   siInfo      - указатель на структуру информации о найденном идентификаторе
   fParam      - параметр, переданный в функцию cb_enumSI.
OUT:
   0 - все в порядке
   1 - прекратить перечисление идентификаторов.
}

type
   Pcb_IA_INFO = ^cb_IA_INFO;
   cb_IA_INFO = packed record
      iaName: array[0..cb_SI_NAME_LEN] of char;     { имя идентификатора }
      userName: array[0..cb_USER_NAME_LEN] of char; { имя пользователя идентификатора }
      sdate: kdate;
      edate: kdate;                            { дата начала и окончания срока использования ИА }
      password: array[0..cb_PASSWORD_LEN] of char;  { пароль, на котором будет закрыт ПИА,
                                                        или "", если ПИ не должен быть зашифрован }
   end;

{ ==============================================================================
                               старт/окончание
================================================================================= }
function cb_getLibVersion(verMajor: Pointer; verMinor: Pointer; libType: Pointer): Integer;
{ Получение версии библиотеки.
OUT:
  verMajor  - указатель на переменную, которая получит номер версии
              библиотеки.
  verMinor  - указатель на переменную, которая получит номер модификации
              библиотеки.
  libType   - указатель на переменную, которая получит тип библиотеки:
              0 - полная версия (центральный пункт).
              1 - ограниченная версия (абонентский пункт).
}

function cb_initLib(const prof: PChar; piaPasswordFunc: cb_PASSWORDFUNC; options: DWORD): Integer;
{ Инициализация библиотеки. Данная функция должна быть вызвана до первого использования
   любой функции библиотеки.
IN:
   prof    - profile, must be NULL.
   piaPasswordFunc - функция запроса пароля ПИА.
   options - флаги cb_LPO_XXX.

RETURN:
  0     - успех.
  CBERR   - ошибка.
}

function cb_initLibDirect(const par: Pcb_LIBPARAMS): Integer;
{ Прямая инициализация библиотеки, позволяет указать все
   параметры библиотеки.
   Данная функция должна быть вызвана до первого использования
   любой функции библиотеки.
IN:
  par   - указатель на структуру параметров библиотеки
RETURN:
  0     - успех.
  CBERR   - ошибка.
}

function cb_doneLib: Integer;
{ Деинициализация библиотеки. Должна быть вызвана после последней операции
   с библиотекой для предотвращения утечки ресурсов
}

function cb_getCurrentUser(piaName: PChar; userName: PChar): Integer;
{ Получение аттрибутов текущего пользователя библиотеки
OUT:
  piaName  - буфер, в котором будет размещено название ПИА
             текущего пользователя.
  userName - буфер, в котором будет размещено имя текущего пользователя.
RETURN:
  0     - успех.
  CBERR   - ошибка.
}

function cb_getLibSettings(par: cb_LIBPARAMS): Integer;
{ Получение текущих настроек библиотеки
OUT:
  par   - в данной структуре будут размещены все текущие параметры
          библиотеки.
          Определены поля:
            piaName - имя файла текущего ПИА
            siaDir  - каталог БД СИА
            sircDir - каталог БД СИРЦ
            simpleFile - имя файла простых чисел (полный путь)
            options - опции cb_LPO_XXX
            logFile - файл журнала
            logFlags - флаги протоколируемых операций
RETURN:
  0     - успех.
  CBERR   - ошибка.
}

{ ==============================================================================
                          Функции работы с файлами
================================================================================= }
{ работа с архивами }

function cb_createArchive(const fileName: PChar; method: Integer;
                          users: PArrayOfPChar; userNum: Integer;
                          func: Pcb_PROGRESSFUNC; fParam: Pointer): HANDLE;
{  Создает архив.
IN:
  fileName  - имя файла создаваемого архива.
  method    - степень сжатия: 0 - наименьшая (просто копирование файлов)
              9 - наибольшая (самое медленное архивирование)
              Рекомендуется использовать method = 3.
  users     - список пользователей, для которых предназначен
              данный архив. Представляет собой массив ASCIIZ - строк.
  userNum   - количество пользователей в списке users.
  func      - функция отображения прогресса операции (может быть NULL).
  fParam    - параметр, передаваемый в функцию func.
RESULT:
  Возвращает дескриптор архива, который будет позднее использоваться
  в функции занесения в архив файлов.
  Возвращает NULL при ошибке.
NOTE:
  Создается заголовок архива и вычисляются коды обмена с
  пользователями, перечисленными в параметре users. Создается
  временный файл, в котором будет размещены заархивированные файлы.
PROGRESS:
  Время операции пропорционально количеству пользователей (N),
  для которых предназначен данный архив. Функция func вызывается N+1 раз после
  перед созданием кода обмена с очередным пользователем и в конце всей операции,
  причем cause = cb_PFC_PROGRESS, info->totalSize = N, info->doneSize = (количество
  уже обработанных пользователей).
}

const
   cb_GIT_RECEIVER   = 1;   { абонент является получателем архива }
   cb_GIT_CREATOR    = 2;   { абонент является создателем архива }
   cb_GIT_NOTFOUND   = 256; { детальная информация об абоненте не найдена }

function cb_getArchiveInfo(const fileName: PChar; needDetails: Boolean;
                           func: cb_ENUM_SI_FUNC; fParam: Pointer): Integer;
{  Получить информацию об абонентах архива и о его создателе.
IN:
  fileName  - имя файла архива.
OUT:
  needDetails - признак, нужно ли получать полную информацию о пользователях,
              или же достаточно только названия идентификатора абонента.
  func      - функция получения информации о абонентах	.
  fParam    - параметр, передаваемый в функцию func.
RESULT:
  количество перечисленных абонентов
  CBERR при ошибке.
NOTE:
  Для каждого абонента архива вызывается func с параметром -
  структурой cb_SI_INFO, в которой поля имеют следующую трактовку:
    siaName    - имя СИА
    userName   - имя пользователя СИА
    sdate, edate - дата начала и окончания срока использования СИА
    type       - набор флагов - типов абонента (cb_GIT_XXX)
    hDataBase  -  дескриптор БД, в которой расположен этот СИА
  Если needDetails = FALSE, то в этой структуре заполнены только
  поля siaName и type.
}

function cb_openArchive(const fileName: PChar; creator: PChar;
                              func: Pcb_PROGRESSFUNC; fParam: Pointer): HANDLE;
{  Открывает архив. Делает первый файл архива текущим.
IN:
  fileName  - имя файла открываемого архива.
OUT:
  creator   - указатель на буфер, в котором при успешном открытии
              архива будет размещен идентификатор пользователя -
              создателя файла.
  func      - функция отображения прогресса операции (может быть NULL).
  fParam    - параметр, передаваемый в функцию func.
RESULT:
  Возвращает дескриптор архива, который будет позднее использоваться
  в функциях извлечения файлов.
  Возвращает NULL при ошибке.
NOTE:
  При открытии проверяется возможность открытия архива текущим
  пользователем (из заголовка архива). Если открытие невозможно
  (файл не предназначен для данного пользователя), возвращается ошибка.
  После открытия вычисляется коды доступа к архиву и информация из
  архива копируется (с раскодированием) во временный файл.
PROGRESS:
  Время операции пропорционально длине архива. Функция func вызывается несколько раз
  во время раскодирования архива во временный файл, причем cause = cb_PFC_PROGRESS,
  info->totalSize = <filesize>, info->doneSize = <decoded size>.
}

function cb_getFirstFile(hArc: HANDLE; info: Pcb_ARCHFILEINFO): Integer;
{  Получает информацию о первом файле архива.
    Делает первый файл архива текущим.
IN:
  hArc     - дескриптор архива, полученный от функции cb_openArchive.
OUT:
  info     - указатель на структуру, в которой будет размещена
             информация о файле.
RESULT:
  0 - успех.
  1 - архив пуст (нет файлов)
  CBERR - ошибка.
NOTE:
  Для архива, созданного функцией createArchive всегда возвращает 1.
}

function cb_getNextFile(hArc: HANDLE; info: Pcb_ARCHFILEINFO): Integer;
{  Получает информацию о следующем файле архива.
    Делает следующий файл архива текущим.
IN:
  hArc     - дескриптор архива, полученный от функции cb_openArchive.
OUT:
  info     - указатель на структуру, в которой будет размещена
             информация о файле.
RESULT:
  0 - успех.
  1 - нет файла (список файлов архива исчерпан)
  CBERR - ошибка.
NOTE:
  Для архива, созданного функцией createArchive всегда возвращает 1.
}

const
   cb_AAF_SETKPD            =  1;
   cb_AAF_EXCLUDE_BASEDIR   =  2;

function cb_addFile(hArc: HANDLE; const srcName: PChar; const dstName: PChar; flags: Integer;
                    func: Pcb_PROGRESSFUNC; fParam: Pointer): Integer;
{ Добавить файл в конец архива.
IN:
  hArc     - дескриптор архива, полученный от функции cb_createArchive.
  srcName  - имя добавляемого файла
  dstName  - имя файла, которое будет фигурировать в оглавлении
             архива.
  flags    - опции добавления:
    cb_AAF_SETKPD - при добавлении автоматически проставлять КПД.
              (сам исходный файл не меняется)
    cb_AAF_EXCLUDE_BASEDIR - использовать в качестве архивного имени файла srcName,
              из которого исключен базовый каталог, указанный в dstName. Если
              dstName = NULL, то из srcName исключаются все каталоги.

  func      - функция отображения прогресса операции (может быть NULL).
  fParam    - параметр, передаваемый в функцию func.
RESULT:
  0 - успех.
  CBERR при ошибке.
PROGRESS:
  Время операции пропорционально длине файла. Функция func вызывается несколько раз
  во время архивирования файла, причем cause = cb_PFC_PROGRESS,
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
{ Извлечь текущий файл в архива.
IN:
  hArc     - дескриптор архива, полученный от функции cb_openArchive.
  dstName  - имя файла, в который будет записана информация извлекаемого файла.
  flags    - опции добавления:
    cb_AEF_TESTKPD  - при извлечении автоматически проверять последний КПД файла.
    cb_AEF_DELKPD   - при извлечении автоматически удалять последний КПД файла.
    cb_AEF_ADD_DIR  - dstName содержит не имя конечного файла, а каталог, в котором будет
                    размещен текущий архивный файл под его оригинальным именем.
                    Если в оригинальном имени файла существуют каталоги, то они создаются
                    в указанном каталоге dstName.
    cb_AEF_FAIL_IF_EXISTS - если извлекаемый файл уже существует, то возвращается признак
                    ошибки. При отсутствии этого флага файл будет замещен новым.
    cb_AEF_GET_FINAL_NAME - после извлечения файла разместить его полное имя по адресу
                    destName. destName должен указывать на буфер достаточного размера.
                    Данный флаг может использоваться только при использовании флага
                    AEF_ADD_DIR.
    cb_AEF_FAIL_ON_BADKPD - только вместе с cb_AEF_TESTKPD. Если произошла ошибка проверки
                    КПД, возвращаться с кодом этой ошибки. При отсутствии этого флага
                    ошибки КПД передаются в функцию func, а на код возврата не влияют.

  func     - функция отображения прогресса (может быть NULL).
  fParam   - параметр, передаваемый в функцию func.
RESULT:
  0 - успех.
  CBERR при ошибке.
NOTE:
  Если установлен флаг cb_AEF_TESTKPD, то будет проверяться
  последний КПД файла и результаты проверки будут переданы в
  функцию func (аналогично cb_testFileKPD).
PROGRESS:
  Время операции пропорционально длине файла. Функция func вызывается несколько раз
  во время разархивирования файла, причем cause = cb_PFC_PROGRESS,
  info->totalSize = <original filesize>, info->doneSize = <writed size>.
  При обнаружении КПД func вызывается с параметрами cause = cb_PFC_KPD_FOUND,
  info = <информация о КПД>, затем с параметрами cause = cb_PFC_KPD_TESTED,
  info = <информация о результатах проверки КПД>.
}

function cb_closeArchive(hArc: HANDLE; func: Pcb_PROGRESSFUNC; fParam: Pointer): Integer;
{ Закрыть архив.
IN:
  hArc     - дескриптор архива, полученный от функции cb_openArchive
             или cb_createArchive.
  func     - функция отображения прогресса (может быть NULL).
  fParam   - параметр, передаваемый в функцию func.
RESULT:
  0 - успех
  CBERR при ошибке.
NOTE:
  Если закрывается архив, созданный cb_createArchive, то происходит
  кодирование временного файла, содержащего информацию
  заархивированных файлов и конкатенацию этого закодированного
  файла к заголовку архива.
  Затем временный файл удаляется.
  Если закрывается архив, открытый cb_openArchive, то просто
  удаляется временный файл, в котором находился раскодированный
  архив.

  После выполнения этой функции дескриптор hArc становится невалидным.

PROGRESS:
  Если закрывается архив, открытый cb_openArchive, то функция func не вызывается
  (т.к. это быстрая операция).
  Если закрывается архив, созданный cb_createArchive:
  Время операции пропорционально длине архива. Функция func вызывается несколько раз
  во время кодирования архива, причем cause = cb_PFC_PROGRESS,
  info->totalSize = <archivesize>, info->doneSize = <encoded size>.
}

function cb_abortArchive(hArc: HANDLE): Integer;
{ Прервать создание архива и удалить созданные файлы.
IN:
  hArc     - дескриптор архива, полученный от функции cb_createArchive.
RETURN:
  0 - успех
  CBERR при ошибке.
NOTE:
  После выполнения этой функции дескриптор hArc становится невалидным.
}

{ =======================================================================
                      Код подтверждения достоверности
   ======================================================================= }

function cb_testFileKPD(const fileName: PChar; func: Pcb_PROGRESSFUNC; fParam: Pointer): Integer;
{ Проверить КПД файла.
IN:
  fileName    - имя проверяемого файла.
  func        - функция отображения прогресса.
  fParam      - параметр, передаваемый в функцию func.
RESULT:
  0 - успех.
  CBERR при ошибке.
PROGRESS:
  Время операции пропорционально длине файла. Функция func вызывается несколько раз
  во время обработки файла, причем cause = cb_PFC_PROGRESS,
  info->totalSize = <filesize>, info->doneSize = <read size>.
  При обнаружении КПД func вызывается с параметрами cause = cb_PFC_KPD_FOUND,
  info = <информация о КПД>, затем с параметрами cause = cb_PFC_KPD_TESTED,
  info = <информация о результатах проверки КПД>.
}

function cb_setFileKPD(const fileName: PChar; func: Pcb_PROGRESSFUNC; fParam: Pointer): Integer;
{ Простановка КПД файла.
IN:
  fileName    - имя обрабатываемого файла.
  func        - функция отображения прогресса (может быть NULL).
  fParam      - параметр, передаваемый в функцию func.
RESULT:
  0 - успех
  CBERR при ошибке.
PROGRESS:
  Время операции пропорционально длине файла. Функция func вызывается несколько раз
  во время обработки файла, причем cause = cb_PFC_PROGRESS,
  info->totalSize = <filesize>, info->doneSize = <read size>.
}

function cb_delFileKPD(const fileName: PChar; num: Integer): Integer;
{ Удалить КПД файла.
IN:
  fileName    - имя обрабатываемого файла.
  num         - кол-во удаляемых КПД (с конца).
                или -1, если нужно удалить все КПД.
RESULT:
  Возвращает количество удаленных КПД или
  CBERR при ошибке.
}

function cb_getFileKPDCount(const fileName: PChar): Integer;
{ Получить количество КПД файла.
IN:
  fileName    - имя обрабатываемого файла.
RESULT:
  Возвращает количество КПД или
  CBERR при ошибке.
}

{ ====================================================================
                     Базы данных СИА и СИРЦ
=======================================================================
  СИ хранятся в базах данных (БД) СИ.
  Существует 2 типа СИ:
    - СИ пользователя (абонента) (СИА), используемый для проверки КПД файлов
      и формирования кода обмена между абонентами
    - СИ регистрационного центра (СИРЦ), используемый для проверки
      КПД идентификаторов (т.е. их подлинности).
  БД может хранить только СИ одного типа.

  При инициализации библиотеки происходит автоматическое открытие БД.
  При этом все БД, расположенные в каталоге СИА, будут загружены как БД СИА,
  а БД, расположенные в каталоге СИРЦ, будут загружены как БД СИРЦ.

  Если при инициализации библиотеки (cb_) указать опцию cb_LPO_DONT_OPEN_DB,
  то БД СИА не загружаются автоматически. Поэтому их необходимо явно загрузить
  функцией cb_dbOpenDatabase.

  Если при инициализации библиотеки (cb_) указать опцию cb_LPO_DONT_OPEN_DB_SIRC,
  то БД СИРЦ не загружаются автоматически. Поэтому их необходимо явно загрузить
  функцией cb_dbOpenDatabase.

  Если БД открыта, она участвует в процессе поиска СИ. Закрытая БД исключается
  из процесса поиска.
}

const
   cb_DB_OM_READ   = 1;  { режимы открытия БД }
   cb_DB_OM_MODIFY = 2;
   cb_DB_OM_CREATE = 3;

function cb_dbOpenDatabase(const dbName: PChar; mode: Integer; atype: Integer): HANDLE;
{ Открыть БД.
IN:
  dbName      - имя файла базы данных.
  mode        - режим открытия БД:
    cb_DB_OM_READ   - открыть только для чтения (для получения ключей). Такой режим
                   позволяет одновременное использование БД несколькими процессами
                   или пользователями.
    cb_DB_OM_MODIFY - открыть для модификации. СИ БД, открытой в таком режиме, можно
                   добавлять или удалять. В таком режиме допускается работа с БД
                   только одного процесса (пользователя).
    cb_DB_OM_CREATE - аналогичен предыдущему режиму, но при открытии БД очищает ее
                   содержимое. Кроме того, только в этом режиме можно указывать
                   несуществующее dbName, и указанная БД будет создана.
  type        - способ использования базы данных:.
    cb_SI_TYPE_SIA     - это база данных СИА.
    cb_SI_TYPE_SIRC    - это база данных СИРЦ.
RESULT:
  Возвращает дескриптор БД при успехе.
  NULL при ошибке.
NOTE:
  БД состоит из 2 файлов: *.PKD и *.PKM. В качестве dbName можно указывать любой из них,
  а также имя файла без расширения.
}

function cb_dbCloseDatabase(hDB: HANDLE): Integer;
{ Закрыть БД.
IN:
  hDB     - дескриптор БД, полученный от функции cb_dbOpenDatabase.
            Если NULL, то закрываются все базы данных, открытые в процессе
            на данный момент.
RESULT:
  0 - успех
  CBERR при ошибке.
}

function cb_dbPackDatabase(hDB: HANDLE): Integer;
{ Сжать БД.
IN:
  hDB       - дескриптор БД, полученный от функции cb_dbOpenDatabase в режиме
              DB_OM_MODIFY или DB_OM_CREATE.
RESULT:
  0 - успех
  CBERR при ошибке.
}

function cb_dbGetDBHandles(handlesBuffer: HANDLE; handlesNeed: Integer): Integer;
{ Получить дескрипторы всех открытых БД.
IN:
  handlesNeed   - количество дескрипторов, которое может вместиться в буфер handlesBuffer.
                  Если 0, то дескрипторы не копируются, только возвращается их количество.
OUT:
  handlesBuffer - буфер для запрашиваемых дескрипторов, размером не менее чем
                  handlesNeed элементов типа HANDLE.
RESULT:
  Количество открытых на данный момент БД.
}

type
   cb_DBINFO = packed record
      dbName: array [0..MAX_PATH] of char;  { имя файла базы данных без расширения }
      siCount: Integer;                     { количество СИ в БД }
      openMode: Integer;                    { режим открытия БД (DB_OM_XXX)   }
      atype: Integer;                       { тип хранимых СИ (cb_SI_TYPE_XXX) }
   end;

function cb_dbGetDatabaseInfo(hDB: HANDLE; dbi: cb_DBINFO): Integer;
{ Получить информацию о базе данных
IN:
  hDB     - дескриптор БД, полученный от функции cb_dbOpenDatabase.
OUT:
  dbi     - указатель на структуру, в которой будет размещена информация о БД.
RESULT:
  0 - успех
  CBERR при ошибке.
}

function cb_dbDeleteSI(hDB: HANDLE; const siName: PChar): Integer;
{ Удалить СИ из БД.
IN:
  hDB       - дескриптор БД, полученный от функции cb_dbOpenDatabase в режиме
              DB_OM_MODIFY или DB_OM_CREATE.
  siName    - имя удаляемого СИ.
RESULT:
  0 - успех
  CBERR при ошибке.
}

const
   cb_DB_AM_FAIL_IF_EXISTS    = 1;
   cb_DB_AM_SELECT_NEWEST     = 2;
   cb_DB_AM_OVERWRITE_ALLWAYS = 3;

function cb_dbAddSI(hDB: HANDLE; const siName: PChar; mode: Integer;
                    hDBSrc: HANDLE): Integer;
{ Добавить СИ в БД из файла или другой БД.
IN:
  hDB       - дескриптор БД, полученный от функции cb_dbOpenDatabase в режиме
              DB_OM_MODIFY или DB_OM_CREATE.
  siName    - имя добавляемого СИ. Может быть именем файла СИ, если добавление
              ведется из файла (hDBSrc==NULL), или именем СИ исходной БД (hDBSrc!=NULL).
  mode      - режим добавления СИ (действия, если одноименный СИ уже существует):
    cb_DB_AM_FAIL_IF_EXISTS     - завершаться с признаком коллизии (см. ниже).
    cb_DB_AM_SELECT_NEWEST      - выбирать из СИ новейший (с более поздней датой создания)
    cb_DB_AM_OVERWRITE_ALLWAYS  - всегда заменять добавляемым.

  hDBSrc    - дескриптор БД, из которой берется добавляемый СИ, или
              NULL, если ключ добавляется из файла.
RESULT:
  0 - успех
  1 - одноименный СИ уже существует (коллизия).
  CBERR при ошибке.
}

function cb_dbExtractSI(hDB: HANDLE; const siName: PChar; dstDir: PChar): Integer;
{ Записывает в файл копию СИ из БД.
IN:
  hDB       - дескриптор БД, полученный от функции cb_dbOpenDatabase. Если NULL, то
              поиск СИ ведется во всех открытых БД.
  keyName   - имя копируемого в файл СИ.
  dstDir    - каталог, в котором будет расположен файл СИ.
RESULT:
  0 - успех
  CBERR при ошибке.
}

const
   cb_DB_EM_ENUM_ALL        = 1;
   cb_DB_EM_COLLISION_ONLY  = 2;
   cb_DB_EM_FIRST_ONLY      = 3;

function cb_enumSI(hDB: HANDLE; mode: Integer; func: cb_ENUM_SI_FUNC; fParam: Pointer): Integer;
{ Перечислить все СИ в БД.
IN:
  hDB        - дескриптор БД, полученный от функции cb_dbOpenDatabase, или NULL,
               если перечисляются СИ во всех открытых БД.
  mode       - режим перечисления, если в разных БД есть одноименные СИ
               (имеет значение только при hDB==NULL).
     cb_DB_EM_ENUM_ALL        - перечислять все СИ и все варианты совпадающих СИ.
     cb_DB_EM_COLLISION_ONLY  - перечислять только совпадающие СИ.
     cb_DB_EM_FIRST_ONLY      - перечислять только несовпадающие СИ и
                                первый СИ из совпадающих.
  func       - функция, вызываемая для каждого ключа.
  fParam     - параметр, передаваемый в функцию func.
RESULT:
  Возвращает количество перечисленных СИ.
  CBERR при ошибке.
NOTE:
  Совпадение СИ в разных БД крайне нежелательно, поскольку при проверке КПД
  или другом использовании СИ их поиск осуществляется в произвольном порядке
  перебора БД. Поэтому который из СИ будет найден первым - неопределено.
  Режим cb_DB_EM_COLLISION_ONLY служит именно для отыскания таких коллизий в
  базах данных.

  НЕЛЬЗЯ модифицировать базу данных внутри функции func, это приведет к неполному или
  неправильному перечислению СИ.
}

const
   cb_SIA_DUMP_SIZE  = 113;
   cb_KPD_DUMP_SIZE  = 126;

type
   cb_SI_DETAILS = packed record
      siaName: array[0..cb_SI_NAME_LEN] of char;    { имя сетевого идентификатора }
      userName: array[0..cb_USER_NAME_LEN] of char; { имя пользователя идентификатора }
      sdate,edate:kdate;                              { дата начала и окончания срока использования СИ }
      atype: Integer;                                 { тип идентификатора - cb_SI_TYPE_XXX }
      hDataBase: HANDLE;                       { дескриптор БД, в которой расположен этот СИ }
      sircName: array[0..cb_SI_NAME_LEN] of char;   { имя сетевого идентификатора РЦ }
                                                      { (или "", если СИ не зарегистрирован)}
      sircUser: array[0..cb_USER_NAME_LEN] of char; { имя пользователя сетевого идентификатора РЦ }
      regSDate: kdate;                                { дата регистрации СИ }
      regEDate: kdate;                                { дата окончания регистрации СИ  }
      siaDump: array[0..cb_SIA_DUMP_SIZE] of char;    { бинарный образ СИ }
      kpdDump: array[0..cb_KPD_DUMP_SIZE] of char;    { бинарный образ 1-го КПД }
   end;

const
   cb_GSD_TEST_SIKPD = 1;
   cb_GSD_FROM_FILE  = 2;

function cb_dbGetSIDetails(hDB: HANDLE; const siName: PChar;
                           flags: Integer; sd: cb_SI_DETAILS): Integer;
{ Получение детальной информации о СИ.
IN:
  hDB       - дескриптор БД, полученный от функции cb_dbOpenDatabase. Если NULL, то
              поиск СИ ведется во всех открытых БД.
  keyName   - имя СИ, детальную информацию о котором нужно получить.
  flags     - флаги операции:
    cb_GSD_TEST_SIKPD - кроме выполнения операции получения информации о СИ, выполняется
              проверка КПД СИ. Если КПД не верен, возвращается ошибка из класса
              "Ошибки КПД".
    cb_CSD_FROM_FILE - поиск СИ ведется не в БД, а siName является именем
              файла идентификатора. hDB в этом случае игнорируется.
OUT:
  sd        - указатель на структуру, получающую информацию о СИ.
RESULT:
  0 - успех
  CBERR при ошибке.
}

{ ====================================================================
                       Создание / обработка ИА.
======================================================================= }

function cb_createIA(const cki: Pcb_IA_INFO; const piDir: PChar;
                     const siDir: PChar): Integer;
{ Создать идентификаторы пользователя.
IN:
  cki         - указатель на структуру с параметрами идентификаторов.
  piDir       - каталог размещения ПИ (с оконечным '\')
  siDir       - каталог размещения СИ  (с оконечным '\')
RESULT:
  0 - успех
  CBERR при ошибке.
NOTE:
  ПИ получит расширение .SK, а СИ - .PK
}

function cb_getPIAInfo(const piaFile: PChar; info: cb_IA_INFO): Integer;
{ Получить информацию о ПИА.
IN:
  piaFile     - файл, в котором хранится ПИА
OUT:
  info        - структура, в которой будет размещена информация
                о ПИА. Поле password этой структуры будет установлено
                в "", если ПИА не закрыт на пароле, или
                в НЕ "", если ПИА закрыт на пароле.
RESULT:
  0 - успех
  CBERR при ошибке.
}

function cb_changePIAPassword(const piaFile: PChar;
                              const oldPassword: PChar;
                              const newPassword: PChar): Integer;
{ Сменить пароль ПИА.
IN:
  piaFile     - файл, в котором хранится ПИА
  oldPassword - старый пароль ПИА ("" при отсутствии пароля) (до 20 символов),
  newPassword - новый пароль ПИА ("", если пароль снимается) (до 20 символов)
RESULT:
  0 - успех
  1 - пароль не верен
  CBERR при ошибке.
}

function cb_dropSICaches: Integer;
{  Сбрасывает кэши СИ. Используется, если известно, что содержимое
    БД на диске изменилось и необходимо им воспользоваться.
}

{ ====================================================================
                     Работа с областями памяти
======================================================================= }

function cb_createMemoryFile(dataPtr: Pointer; staticLimit: DWORD;
                             dynamicLimit: DWORD; size: DWORD;
                             nameBuf: PChar): Integer;
{ Создать псевдофайл в памяти.
IN:
  dataPtr     - указатель на блок памяти, в котором хранится начальное
                содержимое файла.
  staticLimit - максимальный размер файла, который может уместиться в блоке dataPtr.
  dynamicLimit- максимальный размер файла, который может быть достигнут за счет
                динамического резервирования памяти.
                (должно быть dynamicLimit >=staticLimit)
  size        - начальная длина файла. (должно быть size <=staticLimit)
OUT:
  nameBuf  - буфер, в котором будет размещено имя, под которым
             будет известен этот псевдофайл. Имя будет иметь формат,
             подобный данному: \\.\$MEM$\123
RESULT:
  0 - успех
  CBERR при ошибке.
NOTE:
  Файл приобретает начальный размер size. Затем, если во время файловых операций присходит
  увеличение размера файла, добавляемые байты (до staticLimit) размещаются в блоке
  dataPtr по адресу dataPtr+size.
  Если размер файла превысил staticLimit, и dynamicLimit > staticLimit, то создается
  динамический блок памяти, где и размещаются очередные добавляемые байты.
  Попытки увеличить объем файла более чем dynamicLimit возвращают код ошибки
  - ошибка записи. При чтении файла за этими пределами возникает ошибка чтения.
}

function cb_getMemoryFileInfo(const name: PChar; curSize: DWORD; dynPtr: Pointer; dynSize: DWORD): Integer;
{ Получить информацию о динамическом блоке псевдофайла в памяти.
IN:
  name     - имя псевдофайла, полученное от функции cb_createMemoryFile.
OUT:
  curSize  - текущий размер файла.
  dataPtr  - после выполнения будет содержать указатель на
             динамический блок памяти.
  dynSize  - после выполнения будет содержать длину динамического
             блока памяти.
RESULT:
  0 - успех
  CBERR при ошибке.
NOTE:
  Если что у файла динамического блока нет (curSize<=staticLimit), то
  dataPtr будет равен NULL, а dynSize = 0.
  Помните, что полученная информация о динамическом блоке может изменится при
  последующей записи в файл.
}

function cb_setMemoryFileSize(const name: PChar; size: DWORD): Integer;
{
{ Изменить длину псевдофайла (расширить или урезать).
IN:
  name    - имя псевдофайла, полученное от функции cb_createMemoryFile.
  size    - новый размер файла.
RESULT:
  0 - успех
  CBERR при ошибке.
}

function cb_closeMemoryFile(const name: PChar): Integer;
{ Удаляет псевдофайл в памяти.
IN:
  name    - имя псевдофайла, полученное от функции createMemoryFile.
RESULT:
  0 - успех
  CBERR при ошибке.
NOTE:
  Если псевдофайл содержал динамический блок, то он освобождается.
}

{ ==============================================================================
                     многопотоковость (multithreading)
================================================================================= }

function cb_createSession: DWORD {HANDLE};

function cb_linkSession(hSession: HANDLE): Integer;

function cb_unlinkSession: Integer;

function cb_freeSession(hSession: HANDLE): Integer;

{
  Базы данных являются глобальными объектами в процессе, поэтому одновременая их
  модификация из нескольких потоков управления (threads) может вызвать непредсказуемые
  результаты.
  Следует также разрешать ситуации одновременной модификации и чтения (поиска СИ) базы
  данных.

}

{ ==============================================================================
                           Обработка ошибок
=================================================================================

  Для диагностики ошибочных ситуаций в каждой функции предусмотрен код возврата,
  символизирующий ошибку. Как правило, это NULL (если тип возвращаемого значения
  функции - указатель) или CBERR (если тип возвращаемого значения - целое число).
  Если функция не имеет зарезервированного признака ошибки, то она не может вызывать
  ошибочную ситуацию.

  При получении признака ошибки можно получить расширенную информацию об ошибке.
  (cм. функцию cb_getErrorInfo()).

  Если данная библиотека используется в программе, разработанной на Visual C++ 5.0,
  то возможен альтернативный способ обработки ошибок. Если указана опция
  cb_LPO_USE_VC50_EXCEPTIONS во время инициализации библиотеки, то при возникновении
  ошибки выбрасывается исключение в виде класса ErrEx.

  Подробное описание кодов ошибок, класса ErrEx и структуры cb_ERRORINFO находится
  в файле CBERRS.H
}

function cb_getErrorInfo(ei: Pcb_ERRORINFO): Integer;
{ Копирует информацию об последней ошибке в указанную структуру.
OUT:
  ei    - указатель на структуру cb_ERRORINFO, где будет размещена копия
          информации о последней ошибке.
}

function cb_getErrorString(code: WORD; strBuf: PChar; bufSize: DWORD): Integer;
{ Получить текстовую информацию об ошибке.
IN:
  code    - код ошибки (значение поля code структуры cb_ERRORINFO).
OUT:
  strBuf  - указатель на буфер, в котором будет размещена строка,
            описывающая ошибку.
  bufSize - размер буфера. Рекомендуется не менее 128 символов.
RESULT:
  Длина полученной строки или 0 при ошибке.
}

{ ==============================================================================
                           Работа с журналом
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
{ Добавляет массив строк в журнал (если он ведется).
IN:
  str      - добавляемая строка.
  severity - тип события (константа acd_LOGSEVERITY_)
RESULT:
  0 - успех
  ERR при ошибке.
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
//                             старт/окончание
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
//                        Функции работы с файлами
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
//                    Код подтверждения достоверности
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
//                   Базы данных СИА и СИРЦ
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
//                     Создание / обработка ИА.
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
//                   Работа с областями памяти
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
//                   многопотоковость (multithreading)
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
//                         Обработка ошибок
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
//                         Работа с журналом
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
