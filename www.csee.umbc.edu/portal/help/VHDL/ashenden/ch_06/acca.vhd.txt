library ieee;  use ieee.std_logic_1164.all;

entity accumulator_adder is
  port ( a, b : in std_ulogic_vector(21 downto 0);
         s : out std_ulogic_vector(21 downto 0);
	 ovf : out std_ulogic );
end entity accumulator_adder;
