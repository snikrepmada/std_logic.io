library ieee;  use ieee.std_logic_1164.all;

entity master_slave_flipflop is
  port ( phi1, phi2 : in std_logic;
         d : in std_logic;
         q : out std_logic );
end entity master_slave_flipflop;


architecture behavioral of master_slave_flipflop is

  signal master_d : std_logic;

begin

  master_d <= d when phi1 = '1';

  q <= master_d when phi2 = '1';

end architecture behavioral;





-- code from book

library ieee;  use ieee.std_logic_1164.all;

entity shift_reg is
  port ( phi1, phi2 : in std_logic;
         serial_data_in : in std_logic;
         parallel_data : inout std_logic_vector );
end entity shift_reg;

--------------------------------------------------

architecture cell_level of shift_reg is

  alias normalized_parallel_data :
          std_logic_vector(0 to parallel_data'length - 1)
        is parallel_data;

  component master_slave_flipflop is
    port ( phi1, phi2 : in std_logic;
           d : in std_logic;
           q : out std_logic );
  end component master_slave_flipflop;

begin

  reg_array : for index in normalized_parallel_data'range generate
  begin

    first_cell : if index = 0 generate
    begin
      cell : component master_slave_flipflop
        port map ( phi1, phi2,
                   d => serial_data_in,
                   q => normalized_parallel_data(index) );
    end generate first_cell;

    other_cell : if index /= 0 generate
    begin
      cell : component master_slave_flipflop
        port map ( phi1, phi2,
                   d => normalized_parallel_data(index - 1),
                   q => normalized_parallel_data(index) );
    end generate other_cell;

  end generate reg_array;

end architecture cell_level;

-- end code from book



library ieee;  use ieee.std_logic_1164.all;

entity fg_14_05 is
end entity fg_14_05;


architecture test of fg_14_05 is

  signal phi1, phi2, serial_data_in : std_logic := '0';
  signal parallel_data : std_logic_vector(3 downto 0);

begin

  dut : entity work.shift_reg(cell_level)
    port map ( phi1 => phi1, phi2 => phi2,
               serial_data_in => serial_data_in,
               parallel_data => parallel_data );

  clock_gen : process is
  begin
    phi1 <= '1', '0' after 4 ns;
    phi2 <= '1' after 5 ns, '0' after 9 ns;
    wait for 10 ns;
  end process clock_gen;

  stimulus : process is
  begin
    serial_data_in <= '0';  wait until phi2 = '1';
    serial_data_in <= '1';  wait until phi2 = '1';
    serial_data_in <= '1';  wait until phi2 = '1';
    serial_data_in <= '0';  wait until phi2 = '1';
    serial_data_in <= '1';  wait until phi2 = '1';
    serial_data_in <= '1';  wait until phi2 = '1';
    serial_data_in <= '0';  wait until phi2 = '1';
    serial_data_in <= '1';  wait until phi2 = '1';
    serial_data_in <= '1';  wait until phi2 = '1';
    serial_data_in <= '0';  wait until phi2 = '1';
    serial_data_in <= '1';  wait until phi2 = '1';
    serial_data_in <= '1';  wait until phi2 = '1';
    serial_data_in <= '0';  wait until phi2 = '1';
    serial_data_in <= '1';  wait until phi2 = '1';
    serial_data_in <= '1';  wait until phi2 = '1';
    serial_data_in <= '0';

    wait;
  end process stimulus;

end architecture test;
