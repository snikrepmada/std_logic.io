-- code from book

library star_lib;
use star_lib.edge_triggered_Dff;

configuration reg4_gate_level of reg4 is

  for struct  -- architecture of reg4

    for bit0 : flipflop
      use entity edge_triggered_Dff(hi_fanout);
    end for;

    for others : flipflop
      use entity edge_triggered_Dff(basic);
    end for;

  end for;  -- end of architecture struct

end configuration reg4_gate_level;

-- end code from book


entity fg_13_05 is
end entity fg_13_05;


architecture test of fg_13_05 is

  component reg4 is
    port ( clk, clr : in bit;  d : in bit_vector(0 to 3);
           q : out bit_vector(0 to 3) );
  end component reg4;

  signal clk, clr : bit;
  signal d, q : bit_vector(0 to 3);

begin

  flag_reg : component reg4
    port map ( clk => clk, clr => clr, d => d, q => q );

end architecture test;


configuration fg_13_05_test of fg_13_05 is

  for test

    -- code from book (in text)

    for flag_reg : reg4
      use configuration work.reg4_gate_level;
    end for;

    -- end code from book

  end for;

end configuration fg_13_05_test;
