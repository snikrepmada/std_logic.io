library ieee;  use ieee.std_logic_1164.all;

use work.dlx_types.all;

entity ir_extender is
  generic ( Tpd : delay_length );
  port ( d : in dlx_word;
	 q : out dlx_word;
	 immed_size_26 : in std_logic;
	 immed_unsigned : in std_logic;
	 immed_en : in std_logic );
end entity ir_extender;
