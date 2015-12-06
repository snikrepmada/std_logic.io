package body qsim_types is

  use std.textio.all;

  procedure write ( L : inout line;  t : in token_type;
                    creation_time_unit : in time := ns ) is
  begin
    write(L, string'("token "));
    write(L, natural(t.id));
    write(L, string'(" from "));
    write(L, t.source_name(1 to t.source_name_length));
    write(L, string'(" created at "));
    write(L, t.creation_time, unit => creation_time_unit);
  end write;

end package body qsim_types;
