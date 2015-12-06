entity ch_17_06 is

end entity ch_17_06;


----------------------------------------------------------------


architecture test of ch_17_06 is
begin


  process is

    -- code from book:

    type value_cell is record
        value : bit_vector(0 to 3);
        next_cell : value_ptr;
      end record value_cell;

    type value_ptr is access value_cell;

    -- end of code from book

  begin

    wait;
  end process;


end architecture test;
