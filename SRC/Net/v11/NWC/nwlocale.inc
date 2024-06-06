
(*--------------------------------------------------------------------------

   %name: nwlocale.h %
   %version: 5 %
   %date_modified: Thu Nov 13 12:14:42 1997 %
   $Copyright:

   Copyright (c) 1989-1995 Novell, Inc.  All Rights Reserved.

   THIS WORK IS  SUBJECT  TO  U.S.  AND  INTERNATIONAL  COPYRIGHT  LAWS  AND
   TREATIES.   NO  PART  OF  THIS  WORK MAY BE  USED,  PRACTICED,  PERFORMED
   COPIED, DISTRIBUTED, REVISED, MODIFIED, TRANSLATED,  ABRIDGED, CONDENSED,
   EXPANDED,  COLLECTED,  COMPILED,  LINKED,  RECAST, TRANSFORMED OR ADAPTED
   WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC. ANY USE OR EXPLOITATION
   OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT THE PERPETRATOR TO
   CRIMINAL AND CIVIL LIABILITY.$

--------------------------------------------------------------------------*)



{$IFNDEF  NWLOCALE_H }
    {$DEFINE NWLOCALE_H}
    (* make sure size_t is defined *)
    {$IFNDEF SIZE_T}
{$DEFINE SIZE_T}
Type
  size_t = Cardinal;
  psize_t = ^size_t;
  ppsize_t = ^psize_t;
{$ENDIF}


    (* make sure va_list is defined *)
    Type va_list = ^Char;

    {$IFNDEF NTYPES_H}
    {$I ntypes.inc}
    {$ENDIF}
    {$I npackon.inc}
    {$IFDEF  N_PLAT_DOS}
        Type NWLCODE = nuint;
    {$ENDIF}
    Type NUMBER_TYPE = nint32;
    (* (in imitation of stdlib.h) *)
    {$DEFINE L_MB_LEN_MAX}
    Const L_MB_LEN_MAX = 2;
    {$DEFINE MERIDLEN}
    Const MERIDLEN = 5;
    {$DEFINE NWSINGLE_BYTE}
    Const NWSINGLE_BYTE = 1;
    {$DEFINE NWDOUBLE_BYTE}
    Const NWDOUBLE_BYTE = 2;
    {$IFNDEF NLC_ALL}
    {$DEFINE NLC_ALL}
    Const NLC_ALL = 0;
    {$ENDIF}
    {$IFNDEF LC_ALL}
    {$DEFINE LC_ALL}
    Const LC_ALL = NLC_ALL;
    {$ENDIF}
    {$IFNDEF NLC_COLLATE}
    {$DEFINE NLC_COLLATE}
    Const NLC_COLLATE = 1;
    {$ENDIF}
    {$IFNDEF LC_COLLATE}
    {$DEFINE LC_COLLATE}
    Const LC_COLLATE = NLC_COLLATE;
    {$ENDIF}
    {$IFNDEF NLC_CTYPE}
    {$DEFINE NLC_CTYPE}
    Const NLC_CTYPE = 2;
    {$ENDIF}
    {$IFNDEF LC_CTYPE}
    {$DEFINE LC_CTYPE}
    Const LC_CTYPE = NLC_CTYPE;
    {$ENDIF}
    {$IFNDEF NLC_MONETARY}
    {$DEFINE NLC_MONETARY}
    Const NLC_MONETARY = 3;
    {$ENDIF}
    {$IFNDEF LC_MONETARY}
    {$DEFINE LC_MONETARY}
    Const LC_MONETARY = NLC_MONETARY;
    {$ENDIF}
    {$IFNDEF NLC_NUMERIC}
    {$DEFINE NLC_NUMERIC}
    Const NLC_NUMERIC = 4;
    {$ENDIF}
    {$IFNDEF LC_NUMERIC}
    {$DEFINE LC_NUMERIC}
    Const LC_NUMERIC = NLC_NUMERIC;
    {$ENDIF}
    {$IFNDEF NLC_TIME}
    {$DEFINE NLC_TIME}
    Const NLC_TIME = 5;
    {$ENDIF}
    {$IFNDEF LC_TIME}
    {$DEFINE LC_TIME}
    Const LC_TIME = NLC_TIME;
    {$ENDIF}
    {$IFNDEF NLC_TOTAL}
    {$DEFINE NLC_TOTAL}
    Const NLC_TOTAL = 6;
    {$ENDIF}
    {$IFNDEF LC_TOTAL}
    {$DEFINE LC_TOTAL}
    Const LC_TOTAL = NLC_TOTAL;
    {$ENDIF}
    (* -------------------------------------------------------------------------
 *    country definitions
 * -------------------------------------------------------------------------
 *)
    {$DEFINE ARABIC}
    Const ARABIC = 785;
    {$DEFINE WBAHRAIN}
    Const WBAHRAIN = 973;
    {$DEFINE WCYPRUS}
    Const WCYPRUS = 357;
    {$DEFINE WEGYPT}
    Const WEGYPT = 20;
    {$DEFINE WETHIOPIA}
    Const WETHIOPIA = 251;
    {$DEFINE WIRAN}
    Const WIRAN = 98;
    {$DEFINE WIRAQ}
    Const WIRAQ = 964;
    {$DEFINE WJORDAN}
    Const WJORDAN = 962;
    {$DEFINE WKUWAIT}
    Const WKUWAIT = 965;
    {$DEFINE WLIBYA}
    Const WLIBYA = 218;
    {$DEFINE WMALTA}
    Const WMALTA = 356;
    {$DEFINE WMOROCCO}
    Const WMOROCCO = 212;
    {$DEFINE WPAKISTAN}
    Const WPAKISTAN = 92;
    {$DEFINE WQATAR}
    Const WQATAR = 974;
    {$DEFINE WSAUDI}
    Const WSAUDI = 966;
    {$DEFINE WTANZANIA}
    Const WTANZANIA = 255;
    {$DEFINE WTUNISIA}
    Const WTUNISIA = 216;
    {$DEFINE WTURKEY}
    Const WTURKEY = 90;
    {$DEFINE WUAE}
    Const WUAE = 971;
    {$DEFINE WYEMEN}
    Const WYEMEN = 967;
    {$DEFINE AUSTRALIA}
    Const AUSTRALIA = 61;
    {$DEFINE BELGIUM}
    Const BELGIUM = 32;
    {$DEFINE CANADA_FR}
    Const CANADA_FR = 2;
    {$DEFINE CANADA}
    Const CANADA = 2;
    {$DEFINE DENMARK}
    Const DENMARK = 45;
    {$DEFINE FINLAND}
    Const FINLAND = 358;
    {$DEFINE FRANCE}
    Const FRANCE = 33;
    {$DEFINE GERMANY}
    Const GERMANY = 49;
    {$DEFINE GERMANYE}
    Const GERMANYE = 37;
    {$DEFINE HEBREW}
    Const HEBREW = 972;
    {$DEFINE IRELAND}
    Const IRELAND = 353;
    {$DEFINE ITALY}
    Const ITALY = 39;
    {$DEFINE LATIN_AMERICA}
    Const LATIN_AMERICA = 3;
    {$DEFINE WARGENTINA}
    Const WARGENTINA = 54;
    {$DEFINE WBOLIVIA}
    Const WBOLIVIA = 591;
    {$DEFINE WCHILE}
    Const WCHILE = 56;
    {$DEFINE WCOLOMBIA}
    Const WCOLOMBIA = 57;
    {$DEFINE WCOSTARICA}
    Const WCOSTARICA = 506;
    {$DEFINE WECUADOR}
    Const WECUADOR = 593;
    {$DEFINE WELSALVADOR}
    Const WELSALVADOR = 503;
    {$DEFINE WGUATEMALA}
    Const WGUATEMALA = 502;
    {$DEFINE WHONDURAS}
    Const WHONDURAS = 504;
    {$DEFINE WMEXICO}
    Const WMEXICO = 52;
    {$DEFINE WNICARAGUA}
    Const WNICARAGUA = 505;
    {$DEFINE WPANAMA}
    Const WPANAMA = 507;
    {$DEFINE WPARAGUAY}
    Const WPARAGUAY = 595;
    {$DEFINE WPERU}
    Const WPERU = 51;
    {$DEFINE WURUGUAY}
    Const WURUGUAY = 598;
    {$DEFINE WVENEZUELA}
    Const WVENEZUELA = 58;
    {$DEFINE NETHERLANDS}
    Const NETHERLANDS = 31;
    {$DEFINE NORWAY}
    Const NORWAY = 47;
    {$DEFINE PORTUGAL}
    Const PORTUGAL = 351;
    {$DEFINE SPAIN}
    Const SPAIN = 34;
    {$DEFINE SWEDEN}
    Const SWEDEN = 46;
    {$DEFINE SWITZERLAND}
    Const SWITZERLAND = 41;
    {$DEFINE UK}
    Const UK = 44;
    {$DEFINE USA}
    Const USA = 1;
    {$DEFINE JAPAN}
    Const JAPAN = 81;
    {$DEFINE KOREA}
    Const KOREA = 82;
    {$DEFINE PRC}
    Const PRC = 86;
    {$DEFINE TAIWAN}
    Const TAIWAN = 886;
    {$DEFINE TAIWAN2}
    Const TAIWAN2 = 88;
    {$DEFINE WTAIWAN}
    Const WTAIWAN = 886;
    {$DEFINE ASIAN_ENGLISH}
    Const ASIAN_ENGLISH = 99;
    {$DEFINE NEWZEALAND}
    Const NEWZEALAND = 64;
    (* -------------------------------------------------------------------------
 *    typedef Llconv
 * -------------------------------------------------------------------------
 *)
    Type
        Llconv = Record
            decimal_point  :  Array[0..3] Of nint8;
            thousands_sep  :  Array[0..3] Of nint8;
            grouping  :  Array[0..3] Of nint8;
            (*
    The international currency symbol applicable to
    the current locale.  The first three characters
    contain the alphabetic international currency
    symbol in accordance with those specified in ISO
    4217 "codes for the representation of currency
    and funds." The fourth character is the character
    used to separate the international currency
    symbol from the monetary quantity.
   *)
            int_curr_symbol  :  Array[0..7] Of nint8;
            currency_symbol  :  Array[0..3] Of nint8;
            mon_decimal_point  :  Array[0..3] Of nint8;
            mon_thousands_sep  :  Array[0..3] Of nint8;
            mon_grouping  :  Array[0..7] Of nint8;
            positive_sign  :  Array[0..3] Of nint8;
            negative_sign  :  Array[0..3] Of nint8;
            int_frac_digits  :  nint8;
            frac_digits  :  nint8;
            p_cs_precedes  :  nint8;
            p_sep_by_space  :  nint8;
            n_cs_precedes  :  nint8;
            n_sep_by_space  :  nint8;
            p_sign_posn  :  nint8;
            n_sign_posn  :  nint8;
            (* Novell Additions to the ANSI definition:*)
            code_page  :   nint ;
            country_id  :   nint ;
            data_list_separator  :  Array[0..1] Of nint8;
            date_separator  :  Array[0..1] Of nint8;
            time_separator  :  Array[0..1] Of nint8;
            time_format  :  nint8;
            date_format  :   nint ;
            am  :  Array[0..MERIDLEN-1] Of nint8;
            pm  :  Array[0..MERIDLEN-1] Of nint8;
            reserved  :  Array[0..39] Of nint8;
        End;
        LCONV = Llconv;
        pLCONV = ^LCONV;
    (* -------------------------------------------------------------------------
 *    function prototypes
 * -------------------------------------------------------------------------
 *)
    {$IFDEF  __cplusplus }
        (* TC extern C *)
    {$ENDIF}

    Function NWLlocaleconv (
         Var lconvPtr : LCONV
    ) : pLCONV;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLmblen (
        string1  :   pnstr ;
        maxBytes  :   size_t
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLsetlocale (
        category  :   nint ;
        Var locale  : nstr
    ) : pnstr;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLstrchr (
        string1  :   pnstr ;
        find  :   nint 
    ) : pnstr;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLstricmp (
        Var str1  : nstr;
        Var str2  : nstr
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* NWLstrcoll  (see below) *)
    Function NWLstrcspn (
        Var string1  : nstr;
        Var string2  : nstr
    ) : size_t;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFNDEF  NWL_EXCLUDE_TIME}
        Function NWLstrftime (
            dst  :   pnstr ;
            max  :   size_t ;
            Var fmt  : nstr;
            Var ptm  : tm
        ) : size_t;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
    {$ENDIF}
    Function NWLstrpbrk (
        string1  :   pnstr ;
        Var string2  : nstr
    ) : pnstr;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLstrrchr (
        string1  :   pnstr ;
        find  :   nint 
    ) : pnstr;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLstrrev (
        string1  :   pnstr ;
        string2  :   pnstr 
    ) : pnstr;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLstrspn (
        Var string1  : nstr;
        Var string2  : nstr
    ) : size_t;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLstrstr (
        string1  :   pnstr ;
        searchString  :   pnstr 
    ) : pnstr;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLstrtok (
        parse  :   pnstr ;
        delim  :   pnstr 
    ) : pnstr;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* NWLstrupr ( see below )*)
    Function NWIncrement (
        string1  :   pnstr ;
        numChars  :   size_t 
    ) : pnstr;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWstrImoney (
        buffer  :   pnstr ;
        Value  :   NUMBER_TYPE 
    ) : pnstr;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWstrmoney (
        buffer  :   pnstr ;
        Value  :   NUMBER_TYPE 
    ) : pnstr;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWstrncoll (
        string1  :   pnstr ;
        string2  :   pnstr ;
        maxBytes  :   size_t 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWstrncpy (
        target_string  :   pnstr ;
        source_string  :   pnstr ;
        numChars  :   nint 
    ) : pnstr;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLstrbcpy (
        dest  :   pnstr ;
        Var src  : nstr;
        maxlen  :   size_t 
    ) : pnstr;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWstrnum (
        buffer  :   pnstr ;
        Value  :   NUMBER_TYPE 
    ) : pnstr;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWstrlen (
        Var string1  : nstr
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLmbslen (
        Var string1  : nuint8
    ) : size_t;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLTruncateString (
        pStr  :   pnchar8 ;
        iMaxLen  :   nint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLInsertChar (
        src  :   pnstr ;
        insertableChar  :   pnstr 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    (* Function NWprintfhas ... as parameter *)
    {$IFNDEF NWL_EXCLUDE_FILE}
    {$IFDEF N_PLAT_DOS}
    (* Function NWfprintfhas ... as parameter *)
    {$ENDIF}
    {$ENDIF}
    {$IFDEF  N_PLAT_MSW}
    {$IFDEF  N_ARCH_32}
        {$IFNDEF  __BORLANDC__ }
//            Type NWsprintf = _NWsprintf;
        {$ENDIF}
    {$ELSE} {$IFDEF  N_PLAT_MSW}
    {$IFDEF  N_ARCH_16}
//        Type NWsprintf = NWSPRINTF;
    {$ENDIF}
    {$ENDIF}
    {$ENDIF}
    {$ELSE} {$IFDEF  N_PLAT_MSW}
    {$IFDEF  N_ARCH_16}
//        Type NWsprintf = NWSPRINTF;
    {$ENDIF}
    {$ENDIF}
    {$ENDIF}
    (* Function NWsprintfhas ... as parameter *)
    (* Functions using variable parameter lists have the pointer to the *)
    (* variable list declared as void instead of va_list to enable the user to *)
    (* compile without including stdarg.h in every module. *)
    Function NWvprintf (
        Var format  : nstr;
        arglist  :   va_list 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFNDEF NWL_EXCLUDE_FILE}
    {$IFDEF N_PLAT_DOS}
    (* Not implemented Function NWvfprintf (
        Var stream  : FILE;
        Var format  : nstr;
        arglist  :   va_list 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    {$ENDIF}
    {$ENDIF}
    Function NWvsprintf (
        buffer  :   pnstr ;
        Var format  : nstr;
        arglist  :   va_list 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF  N_PLAT_MSW}
    {$IFDEF  N_ARCH_32}
        {$IFNDEF  __BORLANDC__ }
//            Type NWwsprintf = _NWwsprintf;
        {$ENDIF}
    {$ELSE} {$IFDEF  N_PLAT_MSW}
    {$IFDEF  N_ARCH_16}
//        Type NWwsprintf = NWWSPRINTF;
    {$ENDIF}
    {$ENDIF}
    {$ENDIF}
    {$ELSE} {$IFDEF  N_PLAT_MSW}
    {$IFDEF  N_ARCH_16}
//        Type NWwsprintf = NWWSPRINTF;
    {$ENDIF}
    {$ENDIF}
    {$ENDIF}
    (* Function NWwsprintfhas ... as parameter *)
    Function NWatoi (
        string1  :   pnstr 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWitoa (
        value  :   nint ;
        string1  :   pnstr ;
        radix  :   nuint 
    ) : pnstr;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWutoa (
        value  :   nuint ;
        string1  :   pnstr ;
        radix  :   nuint 
    ) : pnstr;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWltoa (
        value  :   nint32 ;
        buf  :   pnstr ;
        radix  :   nuint 
    ) : pnstr;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWultoa (
        value  :   nuint32 ;
        buf  :   pnstr ;
        radix  :   nuint 
    ) : pnstr;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWisalpha (
        ch  :   nuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWisalnum (
        ch  :   nuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWisdigit (
        ch  :   nuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWisxdigit (
        ch  :   nuint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Procedure NWGetNWLOCALEVersion (
        majorVersion  :   pnuint8 ;
        minorVersion  :   pnuint8 ;
        revisionLevel  :   pnuint8 ;
        betaReleaseLevel  :   pnuint8 
    );
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF  N_PLAT_DOS}
    {$IFNDEF  N_LOC_NO_OLD_FUNCS}
        (* Not implemented Function NWGetShortMachineName (
            shortMachineName  :   pnstr 
        ) : NWLCODE;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}  *)
    {$ENDIF}
    {$ENDIF}
    (* This call is not needed for Windows *)
    (* Not implemented Function NWGetCollateTable (
        retCollateTable  :   pnstr ;
        maxLen  :   size_t 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}  *)
    {$IFDEF  N_PLAT_MSW}
    {$IFDEF  N_ARCH_16}
    {$IFNDEF  N_LOC_NO_OLD_MACROS}
        (* TC #define NWNextChar ( s ) AnsiNext ( s )  *)
        (* TC #define NWPrevChar ( t , s ) AnsiPrev ( t , s )  *)
        (* TC #define NWLstrupr ( s ) AnsiUpper ( s )  *)
        (* TC #define NWLstrcoll ( s1 , s2 ) lstrcmp ( s1 , s2 )  *)
        (* TC #define NWLstrxfrm ( s1 , s2 , t ) strxfrm ( s1 , s2 , t )  *)
        (* TC #define NWCharUpr ( c ) ( nint ) ( LOWORD ( ( DWORD ) AnsiUpper ( ( LPSTR ) ( DWORD ) c ) ) )  *)
    {$ELSE}
        Function NWNextChar (
            Var string1  : nstr
        ) : pnstr;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
        Function NWPrevChar (
            Var string1  : nstr;
            position  :   pnstr 
        ) : pnstr;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
        Function NWLstrupr (
            string1  :   pnstr 
        ) : pnstr;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
        Function NWLstrcoll (
            string1  :   pnstr ;
            string2  :   pnstr 
        ) : nint;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
        Function NWLstrxfrm (
            string1  :   pnstr ;
            string2  :   pnstr ;
            numBytes  :   size_t 
        ) : size_t;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
        Function NWCharUpr (
            chr  :   nint 
        ) : nint;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
    {$ENDIF}
    {$ELSE}
        Function NWNextChar (
            Var string1  : nstr
        ) : pnstr;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
        Function NWPrevChar (
            Var string1  : nstr;
            position  :   pnstr 
        ) : pnstr;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
        Function NWLstrupr (
            string1  :   pnstr 
        ) : pnstr;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
        Function NWLstrcoll (
            string1  :   pnstr ;
            string2  :   pnstr 
        ) : nint;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
        Function NWLstrxfrm (
            string1  :   pnstr ;
            string2  :   pnstr ;
            numBytes  :   size_t 
        ) : size_t;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
        Function NWCharUpr (
            chr  :   nint 
        ) : nint;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
    {$ENDIF}
    {$ELSE}
        Function NWNextChar (
            Var string1  : nstr
        ) : pnstr;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
        Function NWPrevChar (
            Var string1  : nstr;
            position  :   pnstr 
        ) : pnstr;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
        Function NWLstrupr (
            string1  :   pnstr 
        ) : pnstr;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
        Function NWLstrcoll (
            string1  :   pnstr ;
            string2  :   pnstr 
        ) : nint;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
        Function NWLstrxfrm (
            string1  :   pnstr ;
            string2  :   pnstr ;
            numBytes  :   size_t 
        ) : size_t;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
        Function NWCharUpr (
            chr  :   nint 
        ) : nint;
        {$IFDEF N_ARCH_32}
        stdcall;
        {$ENDIF}
    {$ENDIF}
    Function NWLstrlwr (
        string1  :   pnstr 
    ) : pnstr;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCharLwr (
        chr  :   nint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCharType (
        ch  :   nint 
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWCharVal (
        Var string1  : nstr
    ) : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Function NWLIsAnsi : nint;
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Procedure NWLOemToAnsi (
        oemStr  :   pnstr8 ;
        ansiStr  :   pnstr8 
    );
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    Procedure NWLAnsiToOem (
        ansiStr  :   pnstr8 ;
        oemStr  :   pnstr8 
    );
    {$IFDEF N_ARCH_32}
    stdcall;
    {$ENDIF}
    {$IFDEF  __cplusplus }
        (* TC } *)
    {$ENDIF}
    {$I npackoff.inc}
{$ENDIF}



