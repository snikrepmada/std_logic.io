library ieee;  use ieee.std_logic_1164.all;

entity accumulator_reg is
  port ( clk : in std_ulogic;
	 clr : in std_ulogic;
	 d : in std_ulogic_vector(21 downto 0);
	 q : out std_ulogic_vector(21 downto 0) );
end entity accumulator_reg;
