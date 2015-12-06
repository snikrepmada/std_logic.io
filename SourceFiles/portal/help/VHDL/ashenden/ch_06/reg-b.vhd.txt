architecture behavioral of reg is
begin

  behavior : process (clk) is
  begin
    if rising_edge(clk) then
      q <= d;
    end if;
  end process behavior;

end architecture behavioral;
