library ieee;  use ieee.std_logic_1164.all;

package fg_11_12 is

  procedure init_synchronize ( signal synch : out std_logic );

  procedure begin_synchronize ( signal synch : inout std_logic;
                                Tdelay : in delay_length := 0 fs );

  procedure end_synchronize ( signal synch : inout std_logic;
                              Tdelay : in delay_length := 0 fs );

end package fg_11_12;



package body fg_11_12 is

  -- code from book

  procedure init_synchronize ( signal synch : out std_logic ) is
  begin
    synch <= '0';
  end procedure init_synchronize;

  procedure begin_synchronize ( signal synch : inout std_logic;
                                Tdelay : in delay_length := 0 fs ) is
  begin
    synch <= 'Z' after Tdelay;
    wait until synch = 'H';
  end procedure begin_synchronize;

  procedure end_synchronize ( signal synch : inout std_logic;
                              Tdelay : in delay_length := 0 fs ) is
  begin
    synch <= '0' after Tdelay;
    wait until synch = '0';
  end procedure end_synchronize;

  -- end code from book

end package body fg_11_12;
