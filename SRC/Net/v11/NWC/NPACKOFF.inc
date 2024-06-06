(* this header sets packing back to default for different compilers *)


{$IFDEF  __BORLANDC__ }
    (* TC pragma *)
{$ELSE} {$IFDEF  N_PLAT_UNIX }
    (* TC pragma *)
{$ELSE}
    (* TC pragma *)
{$ENDIF}
{$ENDIF}


{$IFDEF N_PACK_1}

{$UNDEF N_PACK_1}

{$ENDIF}

