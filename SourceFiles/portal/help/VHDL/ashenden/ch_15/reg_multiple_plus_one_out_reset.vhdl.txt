library ieee;  use ieee.std_logic_1164.all;

use work.dlx_types.all;

entity reg_multiple_plus_one_out_reset is
  generic ( num_outputs : positive;
	    Tpd : delay_length );
  port ( d : in dlx_word;
	 q0 : out dlx_word;
	 q : out dlx_word_array(1 to num_outputs);
	 latch_en : in std_logic;
	 out_en : in std_logic_vector(1 to num_outputs);
	 reset : in std_logic );
end entity reg_multiple_plus_one_out_reset;
