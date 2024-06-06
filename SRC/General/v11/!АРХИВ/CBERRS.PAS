unit CBERRS;

interface

uses
   Windows;

const
   CBERR = -1;
   cb_MAX_ERR_PARAM = 256;

type
   Pcb_ERRORINFO = ^cb_ERRORINFO;
   cb_ERRORINFO = packed record
      code: DWORD;
      winCode: DWORD;
      param: array[0..cb_MAX_ERR_PARAM] of char;
   end;

   (* Полностью аналогичен использованию cb_ERRORINFO *)
   ErrEx = class
   public
      code: DWORD;
      winCode: DWORD;
      param: array[0..cb_MAX_ERR_PARAM] of char;
      //class procedure ErrEx(acode: DWORD); overload;
      //class procedure ErrEx(acode: DWORD; const aparam: PChar);overload;
      //class procedure ErrEx(acode: DWORD; awinCode: Integer); overload;
      //class procedure ErrEx(acode: DWORD; const aparam: PChar; awinCode: Integer);overload;
   end;

(* ===============   Классификация ошибок: ============ *)
const
   //CBERRCLASS(e)        = ((e)&$FF00);

   (*  1. Ошибки устройств и носителей. *)
   CBEC_DEVICE          = $100;

   CBE_INITDEVICE       = (CBEC_DEVICE+1);   (* Ошибка инициализации устройства *)
   CBE_DEVICE           = (CBEC_DEVICE+2);   (* Ошибка устройства *)
   CBE_MEDIA            = (CBEC_DEVICE+3);   (* Нет носителя ( Вставьте носитель в устройство %% ) *)
   CBE_NOT_FORMAT       = (CBEC_DEVICE+5);   (* Носитель не форматирован *)
   CBE_NOT_RESPOND      = (CBEC_DEVICE+6);   (* Устройство не отвечает *)
   CBE_BUSY             = (CBEC_DEVICE+7);   (* Устройство занято *)

   (*  2. Файловые ошибки *)
   CBEC_FILE            = $200;

   CBE_NOSPACE          = (CBEC_FILE+1);    (* Нет места на устройстве *)
   CBE_OPEN             = (CBEC_FILE+2);    (* Ошибка открытия *)
   CBE_WRITE            = (CBEC_FILE+3);    (* Ошибка записи *)
   CBE_READ             = (CBEC_FILE+4);    (* Ошибка чтения *)
   CBE_CREATE           = (CBEC_FILE+5);    (* Ошибка создания *)
   CBE_DELETE           = (CBEC_FILE+6);    (* Ошибка удаления *)
   CBE_RENAME           = (CBEC_FILE+7);    (* Ошибка переименования *)
   CBE_ACCESS           = (CBEC_FILE+8);    (* Ошибка доступа (sharing/locking/network) *)
   CBE_ALREADY_EXIST    = (CBEC_FILE+9);    (* Файл уже существует *)
   CBE_UNDEFIO          = (CBEC_FILE+10);   (* Неклассифицируемая ошибка В/В *)
   CBE_MKDIR            = (CBEC_FILE+11);   (* Ошибка при создании каталога *)
   CBE_PACKING          = (CBEC_FILE+12);   (* Ошибка при архивировании *)
   CBE_UNPACKING        = (CBEC_FILE+13);   (* Ошибка при разархивировании *)

   (*  3. Ошибки разбора пути и поиска файлов *)
   CBEC_NAME            = $300;

   CBE_NODEV            = (CBEC_NAME+1);  (* Указано неверное устройство *)
   CBE_NODIR            = (CBEC_NAME+2);  (* нет каталога *)
   CBE_NOFILE           = (CBEC_NAME+3);  (* нет файла *)
   CBE_BADNAME          = (CBEC_NAME+4);  (* неверное имя файла *)

   (*  4. Прерывания пользователя *)
   CBEC_USER            = $C00;

   CBE_USERBREAK        = (CBEC_USER+1);  (* Пользователь прервал процесс *)

   (*  5. Ошибки форматов *)
   CBEC_FORMAT          = $400;

   CBE_BADFORMAT        = (CBEC_FORMAT+1); (* Неверный формат файла *)
   CBE_FUTUREFORMAT     = (CBEC_FORMAT+2); (* Формат слишком новый *)
   CBE_CORRUPTED        = (CBEC_FORMAT+3); (* Файл поврежден (CRC не совпала) *)
   CBE_OBSOLETE         = (CBEC_FORMAT+4); (* Устаревший формат *)

   (*  6. Ошибки кодирования *)
   CBEC_CODING          = $600;

   CBE_BADIP            = (CBEC_CODING+1); (* Нарушение целостности *)
   CBE_CANTRECODE       = (CBEC_CODING+2); (* не используется *)
   CBE_CANTSELFENCODE   = (CBEC_CODING+3); (* не используется *)
   CBE_BADKEYNO         = (CBEC_CODING+4); (* не используется *)
   CBE_EMPTYNODE        = (CBEC_CODING+5); (* не используется *)
   CBE_BADNETADDR       = (CBEC_CODING+6); (* Файл не для этого абонента и не им создан *)

   (*  7. Ошибки КПД *)
   CBEC_KPD             = $700;

   CBE_NOKPD            = (CBEC_KPD+1); (* Файл не имеет КПД. *)
   CBE_SIA_NOKPD        = (CBEC_KPD+2); (* Идентификатор не зарегистрован *)
   CBE_KPDDATE_WRONG    = (CBEC_KPD+3); (* Неверная дата КПД *)
   CBE_SIAKPD_WRONG     = (CBEC_KPD+4); (* Неверный КПД СИ *)
   CBE_KPD_WRONG        = (CBEC_KPD+5); (* КПД не верен *)
   CBE_NOSIA            = (CBEC_KPD+6); (* СИА не найден *)
   CBE_NOSIRC           = (CBEC_KPD+7); (* СИРЦ не найден *)

   (*  8. Общие ошибки работы с идентификаторами и КПД. *)
   CBEC_IACMN           = $800;

   CBE_BADPASSWORD      = (CBEC_IACMN+1); (* Неверный пароль *)
   CBE_PW_EXPECTED      = (CBEC_IACMN+2); (* не используется *)
   CBE_TIMEOVER         = (CBEC_IACMN+3); (* Время действия истекло *)

   (*  9. Фатальные ошибки *)
   CBEC_FATAL           = $900;

   CBE_NOMEMORY         = (CBEC_FATAL+1); (* Нехватка памяти *)
   CBE_CRYPTODEVICE     = (CBEC_FATAL+2); (* Ошибка кодирующего устройства *)
   CBE_LOGERROR         = (CBEC_FATAL+3); (* Ошибки ведения журнала *)
   CBE_LOGOPEN          = (CBEC_FATAL+4); (* Ошибки открытия журнала *)
   CBE_NOT_ALLOWED      = (CBEC_FATAL+5); (* Функция запрещена *)
   CBE_CFG              = (CBEC_FATAL+6); (* Установка неверна
                                           (или неверная конфигурация) *)
   CBE_PIA_NOT_REG      = (CBEC_FATAL+7); (* ПИА не допущен к использованию *)

   (*  10. Внутренние ошибки (ошибки программиста).
        При возникновении необходимо сообщать разработчикам *)
   CBEC_INT             =  $A00;

   CBE_NONAME           = (CBEC_INT+1);  (* Не указано имя файла *)
   CBE_BADUK            = (CBEC_INT+2);  (* - *)
   CBE_BADUK_KS         = (CBEC_INT+3);  (* - *)
   CBE_BADHANDLE        = (CBEC_INT+4);  (* Неверный handle файла *)
   CBE_NOTDECODED       = (CBEC_INT+5);  (* Попытка использовать нераскодированный идентификатор *)
   CBE_BADPARAM         = (CBEC_INT+6);  (* Неверный параметр функции *)
   CBE_LOG_SEQ          = (CBEC_INT+7);  (* Ошибка в ведении журнала - предыдущая операция не закончена *)


   (* ===================================== Extentions ============== *)

   CBEC_USERCLASS_BASE  = $4000;   (* база для классов *)
                                    (* пользовательских ошибок *)
   CBE_USERBASE         = $40;     (* база для расширения новыми ошибками *)

implementation   

end.
