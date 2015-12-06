library ieee;  use ieee.std_logic_1164.all;

architecture bench of to_fp_test is

  signal vec : std_ulogic_vector(15 downto 0);
  signal r : real;

begin

  dut : entity work.to_fp(behavioral)
    port map (vec, r);

  stimulus : process is
  begin
    vec <= X"0000";  wait for 10 ns;
    vec <= X"8000";  wait for 10 ns;
    vec <= X"7FFF";  wait for 10 ns;
    vec <= X"4000";  wait for 10 ns;
    vec <= X"C000";  wait for 10 ns;

    wait;
  end process stimulus;

end architecture bench;
