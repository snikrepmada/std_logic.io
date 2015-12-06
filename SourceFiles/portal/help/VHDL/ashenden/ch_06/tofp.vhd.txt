library ieee;  use ieee.std_logic_1164.all;

entity to_fp is
  port ( vec : in std_ulogic_vector(15 downto 0);
	 r : out real );
end entity to_fp;
