entity multiprocessor is
end entity multiprocessor;


-- code from book

architecture instrumented of multiprocessor is

  -- not in book
  constant num_processors : positive := 2;
  -- end not in book

  shared variable bus_ifetch_count,
                  bus_read_count,
                  bus_write_count : natural := 0;

  signal bus_request, bus_grant : bit_vector(0 to num_processors - 1);
  -- . . .    -- other signal declarations

begin

  processor_array :
  for processor_id in 0 to num_processors - 1 generate

    processor : process is
      -- . . .
    begin
      -- . . .    -- initialize
      loop
        bus_request(processor_id) <= '1';
        wait until bus_grant(processor_id) = '1';
        bus_ifetch_count := bus_ifetch_count + 1;
        -- . . .    -- fetch instruction
        bus_request(processor_id) <= '0';
        -- . . .    -- decode and execute instruction
        -- not in book
        wait until bus_grant(processor_id) = '0';
        -- end not in book
      end loop;
    end process processor;

  end generate processor_array;

  arbiter : process is
  begin
    -- . . .
    -- not in book
    loop
      for i in bus_request'range loop
        if bus_request(i) = '1' then
          bus_grant(i) <= '1' after 5 ns;
          wait until bus_request(i) = '0';
          bus_grant(i) <= '0' after 5 ns;
        end if;
      end loop;
      wait for 5 ns;
    end loop;
    -- end not in book
  end process arbiter;

  -- . . .    -- other processes for memory, etc

end architecture instrumented;

-- end code from book
