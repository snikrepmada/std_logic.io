library ieee;  use ieee.std_logic_1164.all;

entity mac is
  port ( clk, clr : in std_ulogic;
	 x_real : in std_ulogic_vector(15 downto 0);
	 x_imag : in std_ulogic_vector(15 downto 0);
	 y_real : in std_ulogic_vector(15 downto 0);
	 y_imag : in std_ulogic_vector(15 downto 0);
	 s_real : out std_ulogic_vector(15 downto 0);
	 s_imag : out std_ulogic_vector(15 downto 0);
	 ovf : out std_ulogic );
end entity mac;
