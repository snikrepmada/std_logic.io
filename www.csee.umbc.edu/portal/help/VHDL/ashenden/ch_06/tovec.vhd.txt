library ieee;  use ieee.std_logic_1164.all;

entity to_vector is
  port ( r : in real;
	 vec : out std_ulogic_vector(15 downto 0) );
end entity to_vector;
