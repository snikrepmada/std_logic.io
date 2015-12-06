architecture behavioral of accumulator_reg is
begin

  behavior : process (clk) is

    constant Tpd_clk_out : time := 3 ns;

  begin
    if rising_edge(clk) then
      if To_X01(clr) = '1' then
        q <= (others => '0') after Tpd_clk_out;
      else
        q <= d after Tpd_clk_out;
      end if;
    end if;
  end process behavior;

end architecture behavioral;
