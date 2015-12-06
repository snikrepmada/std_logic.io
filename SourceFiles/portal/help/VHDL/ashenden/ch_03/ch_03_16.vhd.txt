entity ch_03_16 is

end entity ch_03_16;


----------------------------------------------------------------


architecture test of ch_03_16 is
begin

  -- code from book:

  hiding_example : process is
    variable a, b : integer;
  begin
    a := 10;
    for a in 0 to 7 loop
      b := a;
    end loop;
    -- a = 10, and b = 7
    -- . . .
    -- not in book:
    wait;
    -- end not in book
  end process hiding_example;

  -- end of code from book

end architecture test;
