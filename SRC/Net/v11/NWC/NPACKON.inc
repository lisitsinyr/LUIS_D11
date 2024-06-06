(* this header sets packing to 1 for different compilers *)


{$IFDEF N_PACK_1}


{$IFDEF  __BORLANDC__ }
    (* TC pragma *)
{$ELSE} {$IFDEF  N_PLAT_UNIX }
    (* TC pragma *)
{$ELSE}
    (* TC pragma *)
{$ENDIF}
{$ENDIF}


{$ELSE}


{$IFDEF  N_PLAT_DOS }
    {$IFDEF  __BORLANDC__ }
        (* TC pragma *)
    {$ELSE}
        {$IFDEF  _MSC_VER }
            {$IFDEF _MSC_VER>600}
                (* TC pragma *)
            {$ENDIF}
        {$ENDIF}
        (* TC pragma *)
    {$ENDIF}
{$ELSE} {$IFDEF  N_PLAT_MSW}
    {$IFDEF  __BORLANDC__ }
        (* TC pragma *)
    {$ELSE}
        {$IFDEF  _MSC_VER }
            {$IFDEF _MSC_VER>600}
                (* TC pragma *)
            {$ENDIF}
        {$ENDIF}
        (* TC pragma *)
    {$ENDIF}
{$ELSE} {$IFDEF  N_ARCH_16}
    {$IFDEF  __BORLANDC__ }
        (* TC pragma *)
    {$ELSE}
        {$IFDEF  _MSC_VER }
            {$IFDEF _MSC_VER>600}
                (* TC pragma *)
            {$ENDIF}
        {$ENDIF}
        (* TC pragma *)
    {$ENDIF}
{$ELSE} {$IFNDEF  N_PLAT_WNT}
    {$IFDEF  __BORLANDC__ }
        (* TC pragma *)
    {$ELSE}
        {$IFDEF  _MSC_VER }
            {$IFDEF _MSC_VER>600}
                (* TC pragma *)
            {$ENDIF}
        {$ENDIF}
        (* TC pragma *)
    {$ENDIF}
{$ELSE} {$IFDEF  N_PLAT_OS2 }
    {$IFDEF  __BORLANDC__ }
        (* TC pragma *)
    {$ELSE}
        {$IFDEF  _MSC_VER }
            {$IFDEF _MSC_VER>600}
                (* TC pragma *)
            {$ENDIF}
        {$ENDIF}
        (* TC pragma *)
    {$ENDIF}
{$ELSE} {$IFDEF  N_PLAT_MSW}
{$IFDEF  N_ARCH_32}
    (* For Windows 95/NT default pack is 8 *)
    (* TC pragma *)
    {$IFDEF N_FORCE_INT_16}
    (* Force packing to 1 for the thunk layer *)
    (* TC pragma *)
    (* TC pragma *)
{$ENDIF}
{$ENDIF}
{$ENDIF}
{$ENDIF}
{$ENDIF}
{$ENDIF}
{$ENDIF}


{$ELSE} {$IFDEF  N_PLAT_UNIX }

(* TC pragma *)

{$ENDIF}
{$ENDIF}


{$ENDIF}

