entity test_bench_03_08 is

end entity test_bench_03_08;


----------------------------------------------------------------


architecture test_SR_flipflop_checking of test_bench_03_08 is

  signal S, R, Q : bit := '0';

begin

  dut : entity work.SR_flipflop(checking)
    port map ( S => S, R => R, Q => Q );

  stumulus : process is

  begin
    wait for 10 ns;
    S <= '1';			wait for 10 ns;
    S <= '0';			wait for 10 ns;
    S <= '1';			wait for 10 ns;
    S <= '0';			wait for 10 ns;
    R <= '1';			wait for 10 ns;
    R <= '0';			wait for 10 ns;
    R <= '1';			wait for 10 ns;
    R <= '0';			wait for 10 ns;
    S <= '1';	R <= '1';	wait for 10 ns;
    R <= '0';			wait for 10 ns;
    S <= '0';			wait for 10 ns;

    wait;
  end process stumulus;

end architecture test_SR_flipflop_checking;
