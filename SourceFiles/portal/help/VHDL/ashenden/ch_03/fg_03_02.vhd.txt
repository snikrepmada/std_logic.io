-- test code:

use work.test_bench_03_02.all;

-- end test code


library ieee;  use ieee.std_logic_1164.all;

entity mux4 is
  port ( sel : in sel_range;
         d0, d1, d2, d3 : in std_ulogic;
         z : out std_ulogic );
end entity mux4;

--------------------------------------------------

architecture demo of mux4 is
begin

  out_select : process (sel, d0, d1, d2, d3) is
  begin
    case sel is
      when 0 => 
        z <= d0;
      when 1 => 
        z <= d1;
      when 2 => 
        z <= d2;
      when 3 => 
        z <= d3;
    end case;
  end process out_select;

end architecture demo;
