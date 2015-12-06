library ieee;  use ieee.std_logic_1164.all;

architecture bench_rtl of mac_test is

  signal clk, clr, ovf : std_ulogic := '0';
  signal x_real, x_imag,
	 y_real, y_imag,
	 s_real, s_imag : std_ulogic_vector(15 downto 0);

  type complex is record
      re, im : real;
    end record;

  signal x, y, s : complex := (0.0, 0.0);

  constant Tpw_clk : time := 50 ns;

begin

  x_real_converter : entity work.to_vector(behavioral) port map (x.re, x_real);
  x_imag_converter : entity work.to_vector(behavioral) port map (x.im, x_imag);
  y_real_converter : entity work.to_vector(behavioral) port map (y.re, y_real);
  y_imag_converter : entity work.to_vector(behavioral) port map (y.im, y_imag);

  dut : entity work.mac(rtl)
    port map (clk, clr,
	      x_real, x_imag, y_real, y_imag, s_real, s_imag,
	      ovf );

  s_real_converter : entity work.to_fp(behavioral) port map (s_real, s.re);
  s_imag_converter : entity work.to_fp(behavioral) port map (s_imag, s.im);


  clock_gen : process is
  begin
    clk <= '1' after Tpw_clk, '0' after 2 * Tpw_clk;
    wait for 2 * Tpw_clk;
  end process clock_gen;


  stimulus : process is
  begin
    -- first sequence
    						clr <= '1';	wait until clk = '0';
    x <= (+0.5, +0.5);	y <= (+0.5, +0.5);	clr <= '1';	wait until clk = '0';
    x <= (+0.2, +0.2);	y <= (+0.2, +0.2);	clr <= '1';	wait until clk = '0';
    x <= (+0.1, -0.1);	y <= (+0.1, +0.1);	clr <= '1';	wait until clk = '0';
    x <= (+0.1, -0.1);	y <= (+0.1, +0.1);	clr <= '0';	wait until clk = '0';

    -- should be (0.4, 0.58) when it falls out the other end

    						clr <= '0';	wait until clk = '0';
    x <= ( 0.5,  0.5);	y <= ( 0.5,  0.5);	clr <= '0';	wait until clk = '0';
    x <= ( 0.5,  0.5);	y <= ( 0.1,  0.1);	clr <= '0';	wait until clk = '0';
    x <= ( 0.5,  0.5);	y <= ( 0.5,  0.5);	clr <= '1';	wait until clk = '0';
    x <= (-0.5,  0.5);	y <= (-0.5,  0.5);	clr <= '0';	wait until clk = '0';
    						clr <= '0';	wait until clk = '0';
    						clr <= '0';	wait until clk = '0';
    						clr <= '0';	wait until clk = '0';
    						clr <= '1';	wait until clk = '0';

    wait;
  end process stimulus;

end architecture bench_rtl;
