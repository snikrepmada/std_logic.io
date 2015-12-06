architecture behavioral of synch_sr_ff is
begin

  behavior : process (clk) is

    constant Tpd_clk_out : time := 3 ns;

  begin
    if rising_edge(clk) then
      if To_X01(clr) = '1' then
        q <= '0' after Tpd_clk_out;
      elsif To_X01(set) = '1' then
        q <= '1' after Tpd_clk_out;
      end if;
    end if;
  end process behavior;

end architecture behavioral;
