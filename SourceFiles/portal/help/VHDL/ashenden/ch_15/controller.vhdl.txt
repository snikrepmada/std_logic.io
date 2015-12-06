library ieee;  use ieee.std_logic_1164.all;

use work.dlx_types.all,
    work.alu_types.all,
    work.reg_file_types.all;

entity controller is
  generic ( Tpd_clk_ctrl, Tpd_clk_const : delay_length;
            debug : dlx_debug_control := none );
  port ( phi1, phi2 : in std_logic;
      	 reset : in std_logic;
	 halt : out std_logic;
         width : out dlx_mem_width;
         write_enable : out std_logic;
         mem_enable : out std_logic;
	 ifetch : out std_logic;
         ready : in std_logic;
         alu_in_latch_en : out std_logic;
         alu_function : out alu_func;
         alu_zero, alu_negative, alu_overflow : in std_logic;
         reg_s1_addr, reg_s2_addr, reg_dest_addr : out reg_file_addr;
         reg_write : out std_logic;
         c_latch_en : out std_logic;
         a_latch_en, a_out_en : out std_logic;
         b_latch_en, b_out_en : out std_logic;
         temp_latch_en, temp_out_en1, temp_out_en2 : out std_logic;
         iar_latch_en, iar_out_en1, iar_out_en2 : out std_logic;
         pc_latch_en, pc_out_en1, pc_out_en2 : out std_logic;
         mar_latch_en, mar_out_en1, mar_out_en2 : out std_logic;
         mem_addr_mux_sel : out std_logic;
         mdr_latch_en, mdr_out_en1, mdr_out_en2, mdr_out_en3 : out std_logic;
         mdr_mux_sel : out std_logic;
	 ir_latch_en : out std_logic;
         ir_immed1_size_26, ir_immed2_size_26 : out std_logic;
	 ir_immed1_unsigned, ir_immed2_unsigned : out std_logic;
         ir_immed1_en, ir_immed2_en : out std_logic;
         current_instruction : in dlx_word;
	 mem_addr : std_logic_vector(1 downto 0);
         const1, const2 : out dlx_word );
end entity controller;
