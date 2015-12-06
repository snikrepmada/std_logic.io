-- code from book:

library std, work;  use std.standard.all;

-- end of code from book


entity ch_08_05 is

end entity ch_08_05;


----------------------------------------------------------------


architecture test of ch_08_05 is
begin


  process_08_4_a : process is

    constant a : integer := 10;
    constant b : integer := 20;
    variable result : boolean;

  begin

    -- code from book:

    result := std.standard."<" ( a, b );

    -- end of code from book

    wait;
  end process process_08_4_a;


end architecture test;
