library ieee;  use ieee.std_logic_1164.all;

entity overflow_logic is
  port ( real_accumulator_ovf, imag_accumulator_ovf : in std_ulogic;
	 real_sum, imag_sum : std_ulogic_vector(21 downto 17);
	 ovf : out std_ulogic );
end entity overflow_logic;
