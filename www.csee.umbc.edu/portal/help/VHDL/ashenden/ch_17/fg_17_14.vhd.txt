-- not in book

entity test_bench is
end entity test_bench;

-- end not in book


library ieee;  use ieee.std_logic_1164.all;

architecture initial_test of test_bench is

  use work.stimulus_types.all;

  -- . . .    -- component and signal declarations

  -- not in book
  signal dut_signals : std_logic_vector(0 to stimulus_vector_length - 1);
  -- end not in book

begin

  -- . . .    -- instantiate design under test

  stimulus_generation : process is

    use work.stimulus_element_ordered_collection_adt.all;

    variable stimulus_list : ordered_collection := new_ordered_collection;
    variable next_stimulus_position : position;
    variable next_stimulus : stimulus_element;
    variable position_is_null : boolean;

  begin
    insert(stimulus_list, stimulus_element'(0 ns, "0XXXXXXXXX"));
    insert(stimulus_list, stimulus_element'(200 ns, "0000110110"));
    insert(stimulus_list, stimulus_element'(300 ns, "10001ZZZZZ"));
    insert(stimulus_list, stimulus_element'(50 ns, "1XXXXXXXXX"));
    insert(stimulus_list, stimulus_element'(60 ns, "1ZZZZZZZZZ"));
    -- . . .
    -- not in book
    insert(stimulus_list, stimulus_element'(100 ns, "----------"));
    search(stimulus_list, 100 ns, next_stimulus_position);
    delete(next_stimulus_position);
    get_element(next_stimulus_position, next_stimulus);
    -- end not in book
    find_first(stimulus_list, next_stimulus_position);
    loop
      test_null_position(next_stimulus_position, position_is_null);
      exit when position_is_null;
      get_element(next_stimulus_position, next_stimulus);
      wait for next_stimulus.application_time - now;
      dut_signals <= next_stimulus.pattern;
      advance(next_stimulus_position);
    end loop;
    wait;
  end process stimulus_generation;

end architecture initial_test;
