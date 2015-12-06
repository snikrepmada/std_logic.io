entity ch_03_17 is

end entity ch_03_17;


----------------------------------------------------------------


architecture test of ch_03_17 is
begin


  process_3_4_f : process is
  begin

    -- code from book:

    for i in 10 to 1 loop
      -- . . .
    end loop;

    for i in 10 downto 1 loop
      -- . . .
    end loop;

    -- end of code from book

    wait;
  end process process_3_4_f;


end architecture test;
