use std.textio.line;

package qsim_types is

  constant name_max_length : natural := 20;
  type token_id_type is range 0 to integer'high;

  type token_type is record
      source_name : string(1 to name_max_length);
      source_name_length : natural;
      id : token_id_type;
      creation_time : time;
    end record;

  type token_vector is array (positive range <>) of token_type;

  type arc_type is record
      transaction : boolean;  -- flips when an arc changes
      token : token_type;
    end record arc_type;

  type arc_vector is array (positive range <>) of arc_type;

  type info_detail_type is (none, summary, trace);

  procedure write ( L : inout line;  t : in token_type;
                    creation_time_unit : in time := ns );

end package qsim_types;
