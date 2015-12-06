configuration counter_down_to_gate_level of counter is

  for registered

    for all : digit_register
      use configuration work.reg4_gate_level;
    end for;

    -- . . .    -- bindings for other component instances

  end for;  -- end of architecture registered

end configuration counter_down_to_gate_level;



-- not in book

entity fg_13_07 is
end entity fg_13_07;


use work.counter_types.all;

architecture test of fg_13_07 is

  signal clk, clr : bit := '0';
  signal q0, q1 : digit;

begin

  dut : configuration work.counter_down_to_gate_level
    port map ( clk => clk, clr => clr,
               q0 => q0, q1 => q1 );

  clk_gen : clk <= not clk after 20 ns;

  clr_gen : clr <= '1' after 95 ns,
		   '0' after 135 ns;

end architecture test;

-- end not in book
