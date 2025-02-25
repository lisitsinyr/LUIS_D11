/*
 * Copyright (C) МО ПНИЭИ 1997-1999
 * Этот файл содержит информацию,
 * являющуюся собственностью МО ПНИЭИ.
 *
 * Любая часть этого файла не может быть скопирована,
 * исправлена, переведена на другие языки,
 * локализована или модифицирована любым способом,
 * откомпилирована, передана по сети с или на
 * любую компьютерную систему без предварительного
 * заключения соглашения с МО ПНИЭИ.
 */

/****
 * $Id: key_dev.h,v 1.8 2000/02/11 09:02:25 cav Exp $
 *
 * Типы ключевых устройств.
 ****/
#ifndef _KEY_DEV_H_INCLUDED
/*+ Для предотвращения многократного включения данного файла +*/
#define _KEY_DEV_H_INCLUDED

/*+ Дисковод A +*/
#define FLOP_A "A:"
/*+ Дисковод B +*/
#define FLOP_B "B:"
/*+ touch memory Аккорд(4+,4++,4.5,5.0) +*/
#define TM_AKKORD_4_P "TM:A4.P"
/*+ touch memory Даллас. Автоматический выбор порта (1-4) +*/
#define TM_DS_COM0 "TM:COM0"
/*+ touch memory Даллас. Порт COM1 +*/
#define TM_DS_COM1 "TM:COM1"
/*+ touch memory Даллас. Порт COM2 +*/
#define TM_DS_COM2 "TM:COM2"
/*+ считыватель смарт-карт GSR410 +*/
#define SC_GSR410 "SC:GSR4"
/*+ считыватель смарт-карт TOWITOKO +*/
#define SC_TOWITOKO "SC:TOWT"
/*+ считыватель iKey 1000 (USB) +*/
#define IKEY_USB "iKey"
/*+ считыватель iKey 3000 (USB) +*/
#define IKEY_USB "iKey3k"
/*+ считыватель eToken   (USB)  +*/
#define ETOKEN   "eToken"

#endif /* _KEY_DEV_H_INCLUDED */
