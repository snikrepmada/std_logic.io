library ieee;  use ieee.std_logic_1164.all;

use work.dlx_types.all;

entity latch is
  generic ( Tpd : delay_length );
  port ( d : in dlx_word;
      	 q : out dlx_word;
	 latch_en : in std_logic );
end entity latch;
