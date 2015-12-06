package token_fifo_adt is

  alias element_type is work.qsim_types.token_type;

  type fifo_record;

  type fifo_type is access fifo_record;

  function new_fifo return fifo_type;

  procedure test_empty ( variable fifo : in fifo_type;
                         variable is_empty : out boolean );

  procedure insert ( fifo : inout fifo_type;
                     element : in element_type );

  procedure remove ( fifo : inout fifo_type;
                     element : out element_type );

  -- private types

  type fifo_entry_record;

  type fifo_entry is access fifo_entry_record;

  type fifo_entry_record is record
      next_entry : fifo_entry;
      element : element_type;
    end record;

  type fifo_record is record
      head_entry, tail_entry : fifo_entry;
    end record;

end package token_fifo_adt;
