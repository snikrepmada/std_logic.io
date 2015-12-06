architecture behavioral of bus_module is
begin

  behavior : process is
    -- . . .
    -- not in book
    constant Tdelay_synch : delay_length := 10 ns;
    constant wait_delay : delay_length := 100 ns;
    -- end not in book
  begin
    synch <= '0'  after Tdelay_synch;
    -- . . .
    -- not in book
    wait for wait_delay;
    -- end not in book
    -- ready to start operation
    synch <= 'Z' after Tdelay_synch;
    wait until synch = 'H';
    -- . . .    -- proceed with operation
    -- . . .
  end process behavior;

end architecture behavioral;
