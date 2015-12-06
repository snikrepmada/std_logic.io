library ieee;  use ieee.std_logic_1164.all;

use work.dlx_types.all,
    work.alu_types.all;

entity alu is
  generic ( Tpd : delay_length );
  port ( s1 : in dlx_word;
      	 s2 : in dlx_word;
	 result : out dlx_word;
	 func : in alu_func;
	 zero, negative, overflow : out std_logic );
end entity alu;
