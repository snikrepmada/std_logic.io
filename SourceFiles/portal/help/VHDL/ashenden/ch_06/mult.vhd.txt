library ieee;  use ieee.std_logic_1164.all;

entity multiplier is
  port ( a, b : in std_ulogic_vector(15 downto 0);
         p : out std_ulogic_vector(31 downto 0) );
end entity multiplier;
