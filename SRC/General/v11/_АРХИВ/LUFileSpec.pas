(* -------------------------------------------------------------- *)
(* FileSpec.PAS v1.0a by Robert Walking-Owl November 1993         *)
(* -------------------------------------------------------------- *)

{ Things to add...                                                 }
{ - have # and $ be symbols for ASCII chars in dec/hex?            }

(* Buggie Things:                                                 *)
(* - anti-sets don't work with variable lenght sets, since they   *)
(*   end with the first character NOT in the set...               *)

{ $F+}

unit LUFileSpec;

interface

uses SysUtils;

const
   DosNameLen  = 12;     (* Maximum Length of DOS filenames        *)
   UnixNameLen = 32;     (* Maximum Length of Unix Filenames       *)

   MaxWildArgs = 32;     (* Maximum number of wildcard arguments   *)
   MaxNameLen  = 127;

   fCaseSensitive = $01; (* Case Sensitive Flag                    *)
   fExtendedWilds = $02; (* Use extented wildcard forms (not,sets  *)
   fUndocumented  = $80; (* Use DOS 'undocumented' filespecs       *)

type
   SpecList = array [1..MaxWildArgs] of record
      Name:  string[ MaxNameLen ];  (* or use DOS ParamStr?  *)
      Truth: Boolean
   end;
   TWildCard  = class
      FileSpecs: SpecList; (* List of filespecs      *)
      NumNegs: Word;       (* Number of "not" specs  *)
      PathChar: Char;      (* path seperation char   *)
      NotChar: Char;       (* "not" char - init '~'  *)
      QuoteChar: Char;     (* quote char - init '"'  *)
      FileNameLen: Byte;   (* MaxLength of FileNames *)
      FileNameLenMask: Byte;   (* MaxLength of FileNames *)
      function StripQuotes(x: string): string;
      procedure FileSplit(Path: string; var Dir,Name,Ext: string);
   public
      FSpCount: word;      (* Total number of specs  *)
      Flags: Byte;         (* Mode flags ...         *)
      NumMatches: byte;
      NWildCard: set of Byte;
      constructor Create;
      destructor Destroy; override;
      procedure AddSpec(name: string);
      procedure RemoveSpec;
      function FitSpec(name: string): Boolean;
      (* Methods to RemoveSpec() or ChangeSpec() aren't added *)
      (* since for most applications they seem unnecessary.   *)
      (* An IsValid() spec to see if a specification is valid *)
      (* syntax is also unnecessary, since no harm is done,   *)
      (* and DOS and Unix ignore them anyway ....             *)
   end;

function GetCountFile(aPath, aMask: string): Integer;

implementation

function GetCountFile(aPath, aMask: string): Integer;
var
   LSR: TSearchRec;
   LFound: Integer;
   LAttr : Integer;
   s: string;
   LCheckWildCard: TWildCard;
begin
   Result := 0;
   LCheckWildCard := TWildCard.Create;
   LCheckWildCard.AddSpec(aMask);

   LAttr := faAnyFile;
   s := IncludeTrailingBackslash(aPath)+'*.*';
   LFound := FindFirst(S, LAttr, LSR);
   while (LFound = 0) do begin
      if (LSR.Name <> '.') and (LSR.Name <> '..') then begin
         S := IncludeTrailingBackslash(aPath)+LSR.Name;
         if (LSR.Attr and faDirectory) = 0 then begin
            { It is File }
            if LCheckWildCard.FitSpec (LSR.Name) and (LCheckWildCard.FSpCount > 0) then begin
               Inc(Result);
            end;
         end;
      end;
      LFound := FindNext(LSR);
   end;
   SysUtils.FindClose(LSR);

   LCheckWildCard.Free;
end;

constructor TWildCard.Create;
begin
   FSpCount  := 0;
   NumNegs   := 0;
   NotChar   := '~';
   NotChar   := '/';
   QuoteChar := '"';
   Flags := fExtendedWilds or fUndocumented or fCaseSensitive;
   FileNameLen := DosNameLen;
   PathChar := '\';
end;

destructor TWildCard.Destroy;
begin
   FSpCount := 0;
end;

procedure TWildCard.RemoveSpec;
begin
   FillChar(FileSpecs, SizeOf(FileSpecs), 0);
   FSpCount := 0;
   NumNegs := 0;
end;

function TWildCard.StripQuotes( x: string ): string;
begin
   if x<>'' then begin
      if (x[1]=QuoteChar) and (x[length(x)]=QuoteChar) then
         Result := Copy(x,2,Length(x)-2)
      else
         Result := x;
   end;
end;

procedure TWildCard.AddSpec( Name: string);
var
   Truth: Boolean;
begin
   if Name <> '' then begin
      Truth := True;
      if (Flags and fExtendedWilds)<>0 then begin
         if Name[1]=NotChar then begin
            inc(NumNegs);
            Truth := False;
            Name  := Copy( Name , 2, Pred(Length(Name)) );
         end;
         Name := StripQuotes( Name );
      end;
      if (FSpCount<>MaxWildArgs) and (Name<>'') then begin
         inc(FSpCount);
         FileSpecs[FSpCount].Name := Name;
         FileSpecs[FSpCount].Truth := Truth;
      end;
   end;
end;

procedure TWildCard.FileSplit(Path: string; var Dir,Name,Ext: string);
var
   i,p,e: byte;
   InSet: Boolean;
begin
   p := 0;
   if (Flags and fCaseSensitive)=0 then Path := UpperCase(Path);
   for i:=1 to length(Path) do if Path[i]=PathChar then p:=i;
   i := Length(Path);
   InSet := False;
   e := succ(length(Path));
   repeat
      if not Inset then
         case Path[i] of
            '.':         e := i;
            ']','}',')': InSet := True;
         end
      else
         if Path[i] in ['[','{','('] then InSet := False;
      dec(i);
   until i=0;
   if p=0 then Dir := '' else Dir := Copy(Path,1,p);
   Name := Copy(Path,Succ(p),pred(e-p));
   if e<=length(Path) then
      Ext := Copy(Path,e,succ(Length(Path)-e))
   else
      Ext := '';
end;

function TWildCard.FitSpec( name: string): Boolean;

   procedure Puff(var x: string; AFileNameLen: Integer);
   begin
      while length(x) < AFileNameLen do x:=x+' '; {luis}
   end;

   var x,b: set of char;
   procedure GetSet(s: string; EndSet: char; var k: byte);
   var
      c: char;
      u: string;
      i: byte;
      A: Boolean;
   begin
      A := False;
      if s[k]=',' then
         repeat
            inc(k)
         until (k>=FileNameLenMask) or (s[k]=EndSet) or (s[k]<>','); { Luis }
      u := '';
      if (k<FileNameLenMask) and (s[k]<>EndSet) then begin { Luis }
         repeat
            u := u + s[k];
            inc(k);
         until (k>=FileNameLenMask) or (s[k]=EndSet) or (s[k]=','); { Luis }
         if u<>'' then begin
            if u[1]=NotChar then begin
               A := True;
               u := Copy(u,2,pred(length(u)));
            end;
            u := StripQuotes(u);
            if (length(u)=3) and (u[2]='-') then begin
               for c := u[1] to u[3] do if A then b := b+[c] else x := x+[c]
               end
            else begin
               for i:=1 to length(u) do if A then b := b+[u[i]] else x:=x+[u[i]];
            end
         end;
      end;
   end;

   function Match(n,s: string; AFileNameLen: Integer): Boolean;  (* Does a field match? *)
   var
      i,j,k: byte;
      //c: char;
      T: Boolean;
      Scrap: string;
   begin
      FileNameLenMask := Length(s); { Luis }
      i := 1; (* index of filespec *)
      j := 1; (* index of name     *)
      T := True;
      Puff(n,AFileNameLen);
      Puff(s,AFileNameLen);
      repeat
         if s[i]='*' then i:=FileNameLenMask (* Abort *) { Luis }
         else
            case s[i] of
               '(' : begin
                  if ((Flags and fExtendedWilds)<>0) then begin
                     Scrap := '';
                     inc(i);
                     repeat
                        Scrap := Scrap + s[i]; inc(i);
                     until (i>=FileNameLenMask) or (s[i]=')'); { Luis }
                     Scrap := StripQuotes(Scrap);
                     if Pos(Scrap,Copy(n,j,Length(n)))=0 then T := False;
                     Inc(j, Length(Scrap)-1); { luis }
                  end;
               end;
               '[' : begin
                  if ((Flags and fExtendedWilds)<>0) then begin
                     x := [];  b := [];
                     k:=succ(i);
                     repeat
                        GetSet(s,']',k);
                     until (k>=FileNameLenMask) or (s[k]=']'); { Luis }
                     i := k;
                     if x=[] then FillChar(x,SizeOf(x),#255);
                     x := x-b;
                     if not (n[j] in x) then T := False;
                  end;
               end;
               '{' : begin
                  if ((Flags and fExtendedWilds)<>0) then begin
                     x := [];  b := [];
                     k:=succ(i);
                     repeat
                        GetSet(s,'}',k);
                     until (k>=FileNameLenMask) or (s[k]='}'); { Luis }
                     i := succ(k);
                     if x=[] then FillChar(x,SizeOf(x),#255);
                     x := x-b;
                     while (n[j] in x) and (j<=FileNameLen) do inc(j);
                  end;
               end;
            else
               if T and (s[i]<>'?') then if s[i]<>n[j] then T := False;
            end;
         inc(i);
         inc(j);
      until (not T) or (s[i-1]='*') or (i>FileNameLenMask) or (j>FileNameLen); { Luis }

      if (T) and (s[i-1] <> '*') then begin                                    { Luis }
         if (i > FileNameLenMask) and (j <= AFileNameLen) then                  { Luis }
            T := False;                                                        { Luis }
      end;                                                                     { Luis }

      Result := T;
   end;

var i: Byte;
    dn,de,nn,ne,sn,se: string;
    Negate : Boolean;
begin
   Negate := False;
   NWildCard := [];
   if FSpCount=0 then NumMatches := 1
   else begin
      NumMatches := 0;
      for i:=1 to FSpCount do begin
         FileSplit(name,             dn,nn,ne);
         FileSplit(FileSpecs[i].Name,de,sn,se);

         //FileNameLen := Length(nn);               { Luis }

         if (ne='') then ne := '.   ';
         if (Flags and fUnDocumented)<>0 then begin
            if dn='' then dn:='*';
            if sn='' then sn:='*';
            if de='' then de:='*';
            if se='' then se:='.*';
         end;
         if (Match(dn,de,Length(dn)) and Match(nn,sn,Length(nn)) and Match(ne,se,Length(ne))) then begin {luis}
            NWildCard := NWildCard + [i];
            inc(NumMatches);
            if not FileSpecs[i].Truth then Negate := True;
         end;
      end;
   end;
   if (NumNegs=FSpCount) and (NumMatches=0) then
      Result := True
   else
      Result := (NumMatches<>0) xor Negate;
end;

end.

