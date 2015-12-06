library ieee;  use ieee.std_logic_1164.all;

entity synch_sr_ff is
  port ( clk : in std_ulogic;
         set, clr : in std_ulogic;
         q : out std_ulogic );
end entity synch_sr_ff;
