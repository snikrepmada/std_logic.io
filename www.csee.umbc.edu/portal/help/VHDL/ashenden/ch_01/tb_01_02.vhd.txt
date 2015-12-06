entity test_bench_01_02 is

end entity test_bench_01_02;

----------------------------------------------------------------

architecture test_reg4_struct of test_bench_01_02 is

  signal d0, d1, d2, d3, en, clk, q0, q1, q2, q3 : bit;

begin

  dut : entity work.reg4(struct)
    port map ( d0 => d0, d1 => d1, d2 => d2, d3 => d3, en => en, clk => clk,
               q0 => q0, q1 => q1, q2 => q2, q3 => q3 );

  stimulus : process is
  begin
    wait for 20 ns;
    (d0, d1, d2, d3) <= bit_vector'("1010");	wait for 20 ns;
    en <= '1';					wait for 20 ns;
    clk <= '1';					wait for 20 ns;
    (d0, d1, d2, d3) <= bit_vector'("0101");	wait for 20 ns;
    clk <= '0';					wait for 20 ns;
    (d0, d1, d2, d3) <= bit_vector'("0000");	wait for 20 ns;
    en <= '1';					wait for 20 ns;
    (d0, d1, d2, d3) <= bit_vector'("1111");	wait for 20 ns;

    wait;
  end process stimulus;

end architecture test_reg4_struct;
