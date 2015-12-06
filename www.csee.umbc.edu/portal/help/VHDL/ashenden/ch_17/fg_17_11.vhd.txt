package body bounded_buffer_adt is

  function new_bounded_buffer ( size : in positive ) return bounded_buffer is
  begin
    return new bounded_buffer_object'(
             byte_count => 0, head_index => 0, tail_index => 0,
             store => new store_array(0 to size - 1) );
  end function new_bounded_buffer;

  procedure test_empty ( variable the_bounded_buffer : in bounded_buffer;
                         is_empty : out boolean ) is
  begin
    is_empty := the_bounded_buffer.byte_count = 0;
  end procedure test_empty;

  procedure test_full ( variable the_bounded_buffer : in bounded_buffer;
                        is_full : out boolean ) is
  begin
    is_full := the_bounded_buffer.byte_count = the_bounded_buffer.store'length;
  end procedure test_full;

  procedure write ( the_bounded_buffer : inout bounded_buffer;  data : in byte ) is
    variable buffer_full : boolean;
  begin
    test_full(the_bounded_buffer, buffer_full);
    if buffer_full then
      report "write to full bounded buffer" severity failure;
    else
      the_bounded_buffer.store(the_bounded_buffer.tail_index) := data;
      the_bounded_buffer.tail_index := (the_bounded_buffer.tail_index + 1)
                                       mod the_bounded_buffer.store'length;
      the_bounded_buffer.byte_count := the_bounded_buffer.byte_count + 1;
    end if;
  end procedure write;

  procedure read ( the_bounded_buffer : inout bounded_buffer;  data : out byte ) is
    variable buffer_empty : boolean;
  begin
    test_empty(the_bounded_buffer, buffer_empty);
    if buffer_empty then
      report "read from empty bounded buffer" severity failure;
    else
      data := the_bounded_buffer.store(the_bounded_buffer.head_index);
      the_bounded_buffer.head_index := (the_bounded_buffer.head_index + 1)
                                       mod the_bounded_buffer.store'length;
      the_bounded_buffer.byte_count := the_bounded_buffer.byte_count - 1;
    end if;
  end procedure read;

end package body bounded_buffer_adt;



-- not in book

entity fg_17_11 is
end entity fg_17_11;


architecture test of fg_17_11 is
begin

  process is

    use work.bounded_buffer_adt.all;

    variable buf : bounded_buffer := new_bounded_buffer(4);
    variable empty, full : boolean;
    variable d : byte;

  begin
    test_empty(buf, empty);
    assert empty;
    test_full(buf, full);
    assert not full;

    write(buf, X"01");
    write(buf, X"02");

    test_empty(buf, empty);
    assert not empty;
    test_full(buf, full);
    assert not full;

    write(buf, X"03");
    write(buf, X"04");

    test_empty(buf, empty);
    assert not empty;
    test_full(buf, full);
    assert full;

    write(buf, X"05");

    read(buf, d);
    read(buf, d);

    test_empty(buf, empty);
    assert not empty;
    test_full(buf, full);
    assert not full;

    read(buf, d);
    read(buf, d);

    test_empty(buf, empty);
    assert empty;
    test_full(buf, full);
    assert not full;

    read(buf, d);

    write(buf, X"06");
    write(buf, X"07");
    write(buf, X"08");
    read(buf, d);
    read(buf, d);
    write(buf, X"09");
    read(buf, d);
    write(buf, X"0A");
    read(buf, d);
    write(buf, X"0B");
    read(buf, d);
    write(buf, X"0C");
    read(buf, d);
    write(buf, X"0D");
    read(buf, d);
    write(buf, X"0E");
    read(buf, d);
    write(buf, X"0F");
    read(buf, d);

    wait;
  end process;

end architecture test;

-- end not in book
