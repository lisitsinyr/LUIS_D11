unit LUSAES;

interface

uses
   Windows, Dialogs, sysutils;

//Заголовок для сторонних пользователей библиотеки САЭС (saedscore.dll)

(*
#if !defined(_VALIDATA_SAES_H_INCLUDED_)
#define _VALIDATA_SAES_H_INCLUDED_
*)

const
   SAES = 'saedscore.dll';
const
   CFG_ROOT_KEY = 'SOFTWARE\\Validata\\SAES';

const
   CFG_SUBKEY_USE_LOG = 'UseLog'
   CFG_SUBKEY_LOG_PATH = 'LogPath'
   CFG_SUBKEY_USE_LDAP = 'UseLDAP'
   CFG_SUBKEY_COPY_TO_LOCAL = 'CopyToLocal'

#define RLL_ERR_BASE          0x00040000
#define RLL_ERR_CONFLICT_UNKNOWN (RLL_ERR_BASE + 23)
#define RLL_ERR_CONFLICT_SKIP    (RLL_ERR_BASE + 45)
#define RLL_ERR_NO_MORE_FILES    (RLL_ERR_BASE + 46)

class CSaedSignInfo
{
public:
   CString m_sign_info;
   unsigned long m_err_code;
   CString m_error_text;

   CSaedSignInfo(void)
      :m_err_code(0){};
   ~CSaedSignInfo(void)
      {};
};

class CCertInfo
{
public:
   unsigned long m_num;
   CString m_issuer,m_subject,m_fio,m_company,m_title,m_depart;
   CCertInfo(const char* issuer,const char* subject,const char* fio,const char* company,const char* title,const char* depart="")
      :m_issuer(issuer),m_subject(subject),m_fio(fio),m_company(company),m_title(title),m_depart(depart),m_num(1){};
   ~CCertInfo(void){};
   void AddNum(void){m_num++;};
};

function SaedReadConfigString(const Name: PChar; value: string): longint;
function SaedReadConfigNum(const Name: PChar; value: longint): longint;
function SaedWriteConfigString(const Name: PChar; const value: PChar; error_text: string): longint;
function SaedWriteConfigNum(const Name: PChar; value: Longint; error_text: string): longint;

function SaedGetTotalFileNumber(const CStringArray& ar_filenames; CStringArray* p_full_filelist=NULL): Integer;

function SaedInitializeLog(error_textvalue: string): longint;
function SaedUninitializeLog(error_textvalue: string): longint;

function SaedInitializeCtx(error_textvalue: string; const profile: PChar): longint;
function SaedUninitializeCtx(error_textvalue: string): longint;
function SaedLoadCrl(error_textvalue: string): longint;
function SaedInitLdap(LDAP** pp_ldap; dnvalue: string; error_text: string): longint;
function SaedUninitLdap(LDAP* p_ldap; error_textvalue: string): longint;

function SaedSignFile(const filename: PChar; error_text: string; const detach_sign_filename: PChar): longint;
function SaedVerifyFile(const filename: PChar; signes_to_del: Integer; error_text: string; p_signs_num: Longint; CSaedSignInfo** pp_signes_info; const detach_sign_filename: PChar): longint;

procedure SaedFreeSignInfo(signs_num: Longint; CSaedSignInfo* p_signes_info);

function SaedFindAllCerts(error_text: string; CPtrArray& ar_certs; b_only_encr_keyusage: Boolean): longint;
function SaedFindBySubject(const char* issuer; const char* subject; error_text: string; CStringArray& ar_cert_hash; b_only_encr_keyusage: Boolean): longint;
function SaedFindLdap(LDAP* p_ldap; const char* dn; const char* filter; CPtrArray& ar_certs; error_text: string): longint;
function SaedCheckKeyUsage(unsigned long key_usage): Boolean;

function SaedCreateArchive(int compress_level; CString& temp_arch_filename; error_text: string; void** p_handle): longint;
function SaedAddToArchive(void* handle; const filename: PChar; const cur_dir: PChar; error_text: string; bool b_full_names=true): longint;
function SaedOpenArchive(const arch_filename: PChar; error_text: string; void** p_handle; p_num: Longint);
function SaedGetFileFromArchive(void* handle; const dir: PChar; int conflict_mode; filename: string; error_text: string; p_b_can_continue: Boolean; const alt_filename: PChar): longint;

function SaedEncryptFile(const filename: PChar; const enc_filename: PChar; const CStringArray* p_ar_cert_hash; error_text: string): longint;
function SaedDecryptFile(const filename: PChar; temp_arch_filename: string; error_text: string);

function SaedGetArchInfo(const filename: PChar; error_text: string; CPtrArray& ar_certs): longint;
function SaedCloseArchive(void* handle; error_text: string): longint;

(*
#endif // _VALIDATA_SAES_H_INCLUDED_
*)