library star_lib;
use star_lib.edge_triggered_Dff;

configuration full of counter is

  for registered  -- architecture of counter

    for all : digit_register
      use entity work.reg4(struct);

      for struct  -- architecture of reg4

        for bit0 : flipflop
          use entity edge_triggered_Dff(hi_fanout);
        end for;

        for others : flipflop
          use entity edge_triggered_Dff(basic);
        end for;

      end for;  -- end of architecture struct

    end for;

    -- . . .    -- bindings for other component instances

  end for;  -- end of architecture registered

end configuration full;



-- not in book

entity fg_13_08 is
end entity fg_13_08;


use work.counter_types.all;

architecture test of fg_13_08 is

  signal clk, clr : bit := '0';
  signal q0, q1 : digit;

begin

  dut : configuration work.full
    port map ( clk => clk, clr => clr,
               q0 => q0, q1 => q1 );

  clk_gen : clk <= not clk after 20 ns;

  clr_gen : clr <= '1' after 95 ns,
		   '0' after 135 ns;

end architecture test;

-- end not in book
