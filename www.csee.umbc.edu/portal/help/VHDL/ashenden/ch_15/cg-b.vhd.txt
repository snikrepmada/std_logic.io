architecture behavior of clock_gen is

  constant clock_period : delay_length := 2 * (Tpw + Tps);

begin

  reset_driver : 
    reset <= '1', '0' after 2.5 * clock_period + Tps;

  clock_driver : process is
  begin
    phi1 <= '0';
    phi2 <= '0';
    wait for clock_period / 2;
    loop
      phi1 <= '1', '0' after Tpw;
      phi2 <= '1' after clock_period / 2,
              '0' after clock_period / 2 + Tpw;
      wait for clock_period;
    end loop;
  end process clock_driver;

end architecture behavior;
