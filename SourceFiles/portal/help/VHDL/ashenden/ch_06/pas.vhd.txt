library ieee;  use ieee.std_logic_1164.all;

entity product_adder_subtracter is
  port ( mode : in std_ulogic;
         a, b : in std_ulogic_vector(31 downto 0);
         s : out std_ulogic_vector(32 downto 0) );
end entity product_adder_subtracter;
