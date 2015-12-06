entity test_bench_03_03 is

end entity test_bench_03_03;


----------------------------------------------------------------


library ieee;  use ieee.std_logic_1164.all;


architecture test_mux4_demo of test_bench_03_03 is

  signal sel : work.test_bench_03_02.sel_range := 0;
  signal d0, d1, d2, d3, z : std_ulogic;

begin

  dut : entity work.mux4(demo)
    port map ( sel => sel,
               d0 => d0, d1 => d1, d2 => d2, d3 => d3,
               z => z );

  stimulus : process is
  begin
    wait for 5 ns;
    d0 <= '1';			wait for 5 ns;
    d1 <= 'H';			wait for 5 ns;
    		sel <= 1;	wait for 5 ns;
    d1 <= 'L';			wait for 5 ns;
    		sel <= 2;	wait for 5 ns;
    d0 <= '0';			wait for 5 ns;
    d2 <= '1';			wait for 5 ns;
    d2 <= '0';			wait for 5 ns;
    		sel <= 3;	wait for 5 ns;
    d3 <= '1';			wait for 5 ns;
    d3 <= '0';			wait for 5 ns;

    wait;
  end process stimulus;

end architecture test_mux4_demo;
