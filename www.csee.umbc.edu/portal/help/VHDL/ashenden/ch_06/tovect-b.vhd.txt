library ieee;  use ieee.std_logic_1164.all;

architecture bench of to_vector_test is

  signal vec : std_ulogic_vector(15 downto 0);
  signal r : real := 0.0;

begin

  dut : entity work.to_vector(behavioral)
    port map (r, vec);

  stimulus : process is
  begin
    r <=  0.0;		wait for 10 ns;
    r <= -1.0;		wait for 10 ns;
    r <= -2.0;		wait for 10 ns;
    r <= +0.9999;	wait for 10 ns;
    r <= +2.0;		wait for 10 ns;
    r <= -0.5;		wait for 10 ns;
    r <= +0.5;		wait for 10 ns;

    wait;
  end process stimulus;

end architecture bench;
