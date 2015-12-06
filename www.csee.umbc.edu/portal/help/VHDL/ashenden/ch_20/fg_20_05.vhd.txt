entity flipflop is
  generic ( Tsetup : delay_length );
  port ( clk, d : in bit;  q : out bit );
end entity flipflop;


-- code from book

architecture behavior of flipflop is
begin

  timing_check : process (clk) is
  begin
    if clk = '1' then
      assert d'last_event >= Tsetup
        report "set up violation detected in " & timing_check'path_name
        severity error;
    end if;
  end process timing_check;

  -- . . .    -- functionality

end architecture behavior;

-- end code from book



entity fg_20_05 is
end entity fg_20_05;


architecture test of fg_20_05 is

  signal clk, d, q : bit;

begin

  dut : entity work.flipflop(behavior)
    generic map ( Tsetup => 3 ns )
    port map ( clk => clk, d => d, q => q );

  clk <= '1' after 10 ns, '0' after 20 ns;

  d <= '1' after 8 ns;

end architecture test;
