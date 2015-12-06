library ieee;  use ieee.std_logic_1164.all;

entity bus_module is
  port ( synch : inout std_ulogic;  -- . . . );
  -- not in book
         other_port : in std_ulogic := 'U' );
  -- end not in book
end entity bus_module;

--------------------------------------------------

-- not in book

library ieee;  use ieee.std_logic_1164.all;

entity bus_based_system is
end entity bus_based_system;

-- end not in book


architecture top_level of bus_based_system is

  signal synch_control : std_logic;
  -- . . .

begin

  synch_control_pull_up : synch_control <= 'H';

  bus_module_1 : entity work.bus_module(behavioral)
    port map ( synch => synch_control, -- . . . );
      -- not in book
               other_port => open );
      -- end not in book

  bus_module_2 : entity work.bus_module(behavioral)
    port map ( synch => synch_control, -- . . . );
      -- not in book
               other_port => open );
      -- end not in book

  -- . . .

end architecture top_level;
