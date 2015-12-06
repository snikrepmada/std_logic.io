library ieee;  use ieee.std_logic_1164.all;

use work.dlx_types.all;

entity mux2 is
  generic ( Tpd : delay_length );
  port ( i0, i1 : in dlx_word;
      	 y : out dlx_word;
	 sel : in std_logic );
end mux2;
