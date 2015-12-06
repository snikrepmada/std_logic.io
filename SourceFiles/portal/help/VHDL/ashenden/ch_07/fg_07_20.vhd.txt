-- code from book

library ieee;  use ieee.std_logic_1164.all;

entity reg_ctrl is
  port ( reg_addr_decoded, rd, wr, io_en, cpu_clk : in std_ulogic;
         reg_rd, reg_wr : out std_ulogic );
end entity reg_ctrl;

--------------------------------------------------

architecture bool_eqn of reg_ctrl is
begin

  rd_ctrl : reg_rd <= reg_addr_decoded and rd and io_en;

  rw_ctrl : reg_wr <= reg_addr_decoded and wr and io_en
                      and not cpu_clk;

end architecture bool_eqn;

-- end code from book




entity fg_07_20 is
end entity fg_07_20;



library ieee;  use ieee.std_logic_1164.all;
library util;

architecture test of fg_07_20 is

  signal reg_addr_decoded, rd, wr, io_en,
         cpu_clk, reg_rd, reg_wr : std_ulogic := '0';
  signal test_vector : std_ulogic_vector(1 to 5);

  use util.stimulus_generators.all;

begin

  dut : entity work.reg_ctrl
    port map ( reg_addr_decoded, rd, wr, io_en, cpu_clk, reg_rd, reg_wr );

  stimulus : process is
  begin
    all_possible_values( bv => test_vector,
                              delay_between_values => 10 ns );
    wait;
  end process stimulus;

  (reg_addr_decoded, rd, wr, io_en, cpu_clk) <= test_vector;

end architecture test;
