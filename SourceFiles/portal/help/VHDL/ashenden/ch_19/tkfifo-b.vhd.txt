package body token_fifo_adt is


  function new_fifo return fifo_type is
  begin
    return new fifo_record'( null, null );
  end function new_fifo;


  procedure test_empty ( variable fifo : in fifo_type;
                         variable is_empty : out boolean ) is
  begin
    is_empty := fifo.head_entry = null;
  end procedure test_empty;


  procedure insert ( fifo : inout fifo_type;
                     element : in element_type ) is

    variable new_entry : fifo_entry
                := new fifo_entry_record'( next_entry => null,
                                           element => element );
  begin
    if fifo.tail_entry /= null then
      fifo.tail_entry.next_entry := new_entry;
    else
      fifo.head_entry := new_entry;
    end if;
    fifo.tail_entry := new_entry;
  end procedure insert;


  procedure remove ( fifo : inout fifo_type;
                     element : out element_type ) is
    variable empty_fifo : boolean;
    variable removed_entry : fifo_entry;
  begin
    test_empty(fifo, empty_fifo);
    if empty_fifo then
      report "remove from empty fifo" severity failure;
    else
      removed_entry := fifo.head_entry;
      element := removed_entry.element;
      fifo.head_entry := removed_entry.next_entry;
      if fifo.head_entry = null then  -- fifo now empty
        fifo.tail_entry := null;
      end if;
      deallocate(removed_entry);
    end if;
  end procedure remove;


end package body token_fifo_adt;
