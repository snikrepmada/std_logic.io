entity address_decoder is
  port ( addr : in work.cpu_types.address;
         status : in work.cpu_types.status_value;
         mem_sel, int_sel, io_sel : out bit );
end entity address_decoder;

--------------------------------------------------

architecture functional of address_decoder is

  constant mem_low : work.cpu_types.address := X"000000";
  constant mem_high : work.cpu_types.address := X"EFFFFF";
  constant io_low : work.cpu_types.address := X"F00000";
  constant io_high : work.cpu_types.address := X"FFFFFF";

begin

  mem_decoder :
    mem_sel <= '1' when ( work.cpu_types."="(status, work.cpu_types.fetch)
                          or work.cpu_types."="(status, work.cpu_types.mem_read)
                          or work.cpu_types."="(status, work.cpu_types.mem_write) )
                        and addr >= mem_low
                        and addr <= mem_high else
               '0';

  int_decoder :
    int_sel <= '1' when work.cpu_types."="(status, work.cpu_types.int_ack) else
               '0';

  io_decoder :
    io_sel <= '1' when ( work.cpu_types."="(status, work.cpu_types.io_read)
                         or work.cpu_types."="(status, work.cpu_types.io_write) )
                       and addr >= io_low
                       and addr <= io_high else
              '0';

end architecture functional;


-- not in book

entity fg_08_02 is
end entity fg_08_02;


architecture test of fg_08_02 is

  use work.cpu_types.all;

  signal addr : address := X"000000";
  signal status : status_value := idle;
  signal mem_sel, int_sel, io_sel : bit;

begin

  dut : entity work.address_decoder
    port map ( addr => addr, status => status,
               mem_sel => mem_sel, int_sel => int_sel, io_sel => io_sel );

  stimulus : process is
  begin
    wait for 10 ns;

    status <= fetch;      wait for 10 ns;
    status <= mem_read;   wait for 10 ns;
    status <= mem_write;  wait for 10 ns;
    status <= io_read;    wait for 10 ns;
    status <= io_write;   wait for 10 ns;
    status <= int_ack;    wait for 10 ns;
    status <= idle;       wait for 10 ns;

    addr <= X"EFFFFF";    wait for 10 ns;
    status <= fetch;      wait for 10 ns;
    status <= mem_read;   wait for 10 ns;
    status <= mem_write;  wait for 10 ns;
    status <= io_read;    wait for 10 ns;
    status <= io_write;   wait for 10 ns;
    status <= int_ack;    wait for 10 ns;
    status <= idle;       wait for 10 ns;

    addr <= X"F00000";    wait for 10 ns;
    status <= fetch;      wait for 10 ns;
    status <= mem_read;   wait for 10 ns;
    status <= mem_write;  wait for 10 ns;
    status <= io_read;    wait for 10 ns;
    status <= io_write;   wait for 10 ns;
    status <= int_ack;    wait for 10 ns;
    status <= idle;       wait for 10 ns;

    addr <= X"FFFFFF";    wait for 10 ns;
    status <= fetch;      wait for 10 ns;
    status <= mem_read;   wait for 10 ns;
    status <= mem_write;  wait for 10 ns;
    status <= io_read;    wait for 10 ns;
    status <= io_write;   wait for 10 ns;
    status <= int_ack;    wait for 10 ns;
    status <= idle;       wait for 10 ns;

    wait;
  end process stimulus;

end architecture test;

-- end not in book
