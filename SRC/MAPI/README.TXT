===================================================================

README for MAPI Support Kit for Delphi 3.0

===================================================================

Revision 1.0 of June 18, 1997
Copyright (c) 1997 Alexander Staubo.


------------------
ABOUT THIS RELEASE
------------------

These are the MAPI 1.0 (also known as "Extended MAPI") header files
translated for Delphi 3.0. Many people have been asking for this, 
and as far as I am aware, no complete translation has before been
released to the public.

This release does not cover Simple MAPI, Active Messaging (formerly
OLE Messaging) or Common Messaging Calls (CMC).


-----------------------------
A BIT MORE ABOUT THIS RELEASE
-----------------------------

This differs a bit from my previous releases such as the TAPI
"Support Kit" and the OLE DB header files, in that this translation
has been automated as much as 99% through the use of my "C/C++ to
Delphi header conversion program", called, appropriately, Header
Translator. (Would the persons who stifled a laugh just now please 
forward suggestions to a better product name? Thank you.)

This program, htrans for short, is not a miraculous cure to end all
C++ ills, but I am happy to say that it converted the MAPI header
files to Delphi largely on its own. The program is not yet publicly
released, although anyone interested can email me for a copy. In
its current state it suffers from a slow scanner, and it lacks a
lexical analyzer, and as a side-effect, some declarations will (as
you can see by studying the MAPI files) come out a bit weird, and
others (as you will see if you try to put anything other than MAPI
into it) will come out like nothing you've ever seen before.

Some macros have been converted to functions, others have been
completely removed. If you see something missing, please contact me
(see later section).

Anyway, these are the MAPI headers, revision "1.0" -- which really
means that I never tested this stuff very thoroughly. The testing
I shall leave to the general public.


--------------------------------------------------------
AND EVEN MORE ABOUT THIS RELEASE (DO NOT SKIP THIS PART)
--------------------------------------------------------

This release also does NOT include any documentation for MAPI. For
MAPI development, I recommend the following sources:

* _Inside MAPI_, Irving De la Cruz and Les Thaler, Microsoft Press
1996, ISBN 1-57231-312-9.

* The Microsoft Developer Network (MSDN).


This release does NOT cover Simple MAPI, Active Messaging
(formerly OLE Messaging) or CMC.


This software is neither endorsed nor supported by Microsoft Corp.


------------------------------
FILES INCLUDED IN THIS RELEASE
------------------------------

  ObjectPascal file      Original C++ header file(1)
  -----------------      ---------------------------
  imessage.pas           imessage.h
  mapicode.pas           mapicode.h
  mapidefs.pas           mapidefs.h
  mapiform.pas           mapiform.h
  mapiguid.pas           mapiguid.h
  mapihook.pas           mapihook.h
  mapispi.pas            mapispi.h
  mapitags.pas           mapitags.h
  mapiwz.pas             mapiwz.h
  mapix.pas              mapix.h
  tnef.pas               tnef.h

(1) These are not included, of course.


----------------------------------
FILES NOT INCLUDED IN THIS RELEASE
----------------------------------

Some header files were not translated, either because I deemed
them redundant, or because I just did not bother.

These include:

  Header file       Description
  -----------       -----------
  mapi.h            Simple MAPI interface
  mapidbg.h         Debugging support for MAPI service providers.
  mapinls.h         Internationalization support utilities.
  mapioid.h         MAPI object identifiers (OIDs).
  mapiutil.h        Utility functions.
  mapival.h         Macros used to validate method parameters.
  mapiwin.h         Debugging aid for service provider developers.

Future releases may include translations of additional files
depending on user response.


---------
LICENSING
---------

This software is released as "freeware". You are encouraged to 
redistribute unmodified copies this software, as long as no fee is
charged for the software, directly or indirectly, separately or as
part of ("bundled with") another software product, without the
express permission of the author (Alexander Staubo). Users are
encouraged to improve the source code, and you may modify this
software as long as you do not redistribute the modified version.


---------------------------------
SUPPORT, BUG REPORTS, SUGGESTIONS
---------------------------------

You are encouraged to send bug reports and suggestions.
Contributors will be rewarded by having their names mentioned
in the "readme" file of every subsequent release. Fame and glory 
is optional. If you modify the source code, you are also
encouraged to email me your modified version if you think your
additions would be worthwhile to other users.

This software is not supported. Hence, your technical questions
may or may not be answered.

Questions, bug reports, comments and suggestions should all be
sent to <alex@powertech.no>, subject line "MAPI headers".

While I would be happy to answer questions, my resources are
limited, time is money, and money is short, please do not bother
me with unrelated questions such as "What is MAPI?".


----------
DISCLAIMER
----------

ANY USE BY YOU OF THE SOFTWARE IS AT YOUR OWN RISK. THE SOFTWARE IS
PROVIDED FOR USE "AS IS" WITHOUT WARRANTY OF ANY KIND. TO THE 
MAXIMUM EXTENT PERMITTED BY LAW, THE AUTHOR (ALEXANDER STAUBO)
DISCLAIMS ALL WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
INCLUDING, WITHOUT LIMITATION, IMPLIED WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
NONINFRINGEMENT. THE AUTHOR (ALEXANDER STAUBO) IS NOT OBLIGATED TO
PROVIDE ANY UPDATES TO THE SOFTWARE.

Have fun!

