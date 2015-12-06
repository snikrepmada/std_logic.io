entity fg_20_16 is
end entity fg_20_16;


architecture test of fg_20_16 is

  signal clk : bit;

  attribute synthesis_hint : string;

begin

  -- code from book

  controller : process is

    attribute synthesis_hint of control_loop : label is
      "implementation:FSM(clk)";
    -- . . .

  begin
    -- . . .    -- initialization
    control_loop : loop
      wait until clk = '1';
      -- . . .
    end loop;
  end process controller;

  -- end code fom book

end architecture test;
