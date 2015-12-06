library ieee;  use ieee.std_logic_1164.all;

entity reg is
  port ( clk : in std_ulogic;
	 d : in std_ulogic_vector;
	 q : out std_ulogic_vector );
end entity reg;
