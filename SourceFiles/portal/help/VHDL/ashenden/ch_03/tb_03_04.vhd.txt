entity test_bench_03_04 is

end entity test_bench_03_04;


----------------------------------------------------------------


architecture test_counter_behavior of test_bench_03_04 is

  signal clk : bit := '0';
  signal count : natural;

begin

  dut : entity work.counter(behavior)
    port map ( clk => clk, count => count );

  stimulus : process is
  begin
    for cycle_count in 1 to 100 loop
      wait for 20 ns;
      clk <= '1', '0' after 10 ns;
    end loop;

    wait;
  end process stimulus;

end architecture test_counter_behavior;
