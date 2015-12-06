entity ch_08_03 is

end entity ch_08_03;


----------------------------------------------------------------


library ieee;

architecture test of ch_08_03 is
begin


  process_08_3_a : process is

    -- code from book:

    use work.cpu_types;

    variable data_word : cpu_types.word;
    variable next_address : cpu_types.address;

    -- end of code from book

  begin
   wait;
  end process process_08_3_a;


  ----------------


  process_08_3_b : process is

    -- code from book:

    use work.cpu_types.word, work.cpu_types.address;

    variable data_word : word;
    variable next_address : address;

    -- end of code from book

  begin
    wait;
  end process process_08_3_b;


  ----------------


  block_08_3_c : block is

    -- code from book:

    use ieee.std_logic_1164.all;

    -- end of code from book

  begin
  end block block_08_3_c;


end architecture test;
