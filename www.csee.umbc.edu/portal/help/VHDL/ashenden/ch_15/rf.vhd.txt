library ieee;  use ieee.std_logic_1164.all;

use work.dlx_types.all,
    work.reg_file_types.all;

entity reg_file is
  generic ( Tac : delay_length );
  port ( a1 : in reg_file_addr;
  	 q1 : out dlx_word;
	 a2 : in reg_file_addr;
	 q2 : out dlx_word;
	 a3 : in reg_file_addr;
	 d3 : in dlx_word;
	 write_en : in std_logic );
end entity reg_file;
