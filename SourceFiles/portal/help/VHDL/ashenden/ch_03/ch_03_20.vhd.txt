entity ch_03_20 is

end entity ch_03_20;


----------------------------------------------------------------


architecture test of ch_03_20 is
begin


  process_3_5_c : process is
  begin

    -- code from book:

    assert false
      report "Initialization complete" severity note;

    --

    report "Initialization complete";

    -- end of code from book

    wait;
  end process process_3_5_c;


end architecture test;
