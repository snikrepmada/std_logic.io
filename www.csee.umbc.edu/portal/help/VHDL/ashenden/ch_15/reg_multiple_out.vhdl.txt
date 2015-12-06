library ieee;  use ieee.std_logic_1164.all;

use work.dlx_types.all;

entity reg_multiple_out is
  generic ( num_outputs : positive;
	    Tpd : delay_length );
  port ( d : in dlx_word;
	 q : out dlx_word_array(1 to num_outputs);
	 latch_en : in std_logic;
	 out_en : in std_logic_vector(1 to num_outputs) );
end entity reg_multiple_out;
