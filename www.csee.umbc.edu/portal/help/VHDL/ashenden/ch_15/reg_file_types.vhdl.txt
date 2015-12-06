library ieee;  use ieee.std_logic_1164.all;

use work.dlx_instr.dlx_reg_addr;

package reg_file_types is

  subtype reg_file_addr is std_logic_vector(dlx_reg_addr'range);

end package reg_file_types;
