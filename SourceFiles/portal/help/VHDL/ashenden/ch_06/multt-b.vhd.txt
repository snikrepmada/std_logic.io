library ieee;  use ieee.std_logic_1164.all;

architecture bench of multiplier_test is

  signal a, b : std_ulogic_vector(15 downto 0) := (others => '0');
  signal p : std_ulogic_vector(31 downto 0);

begin

  dut : entity work.multiplier(behavioral)
    port map (a, b, p);

  stimulus : process is
  begin
    a <= X"8000";  b <= X"8000";  --  -1 * -1
    wait for 50 ns;
    a <= X"0001";  b <= X"0001";  --  2**-15 * 2**-15
    wait for 50 ns;
    a <= X"0001";  b <= X"0000";  --  2**-15 * 0
    wait for 50 ns;
    a <= X"0000";  b <= X"0001";  --  0 * 2**-15
    wait for 50 ns;
    a <= X"0001";  b <= X"8000";  --  2**-15 * -1
    wait for 50 ns;
    a <= X"8000";  b <= X"0001";  --  -1 * 2**-15
    wait for 50 ns;
    a <= X"4000";  b <= X"4000";  --  0.5 * 0.5
    wait for 50 ns;
    a <= X"C000";  b <= X"4000";  --  -0.5 * 0.5
    wait for 50 ns;
    a <= X"4000";  b <= X"C000";  --  0.5 * -0.5
    wait for 50 ns;
    a <= X"C000";  b <= X"C000";  --  -0.5 * -0.5
    wait for 50 ns;
    wait;
  end process stimulus;

end architecture bench;
