library ieee;  use ieee. std_logic_1164.all;

use work.dlx_types.all;

entity memory is

  generic ( mem_size : positive;
            Tac_first : delay_length;
            Tac_burst : delay_length;
	    Tpd_clk_out : delay_length;
	    load_file_name : string := "dlx.out" );

  port ( phi1, phi2 : in std_logic;
      	 a : in dlx_address;
	 d : inout dlx_word;
	 width : in dlx_mem_width;
	 write_enable : in std_logic;
         burst : in std_logic := '0';
	 mem_enable : in std_logic;
	 ready : out std_logic );

end entity memory;
