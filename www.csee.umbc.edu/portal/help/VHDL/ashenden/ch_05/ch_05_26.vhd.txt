entity ch_05_26 is

end entity ch_05_26;


----------------------------------------------------------------


-- code from book:

library widget_cells, wasp_lib;

use widget_cells.reg32;

-- end of code from book


architecture test of ch_05_26 is

  signal filter_clk, accum_en : bit;
  signal sum, result : bit_vector(31 downto 0);

begin


  -- code from book:

  accum : entity reg32
    port map ( en => accum_en, clk => filter_clk, d => sum,
               q => result );

  -- end of code from book


end architecture test;
