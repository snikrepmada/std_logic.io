-- code from book:

entity and_gate is
  port ( i : in bit_vector;  y : out bit );
end entity and_gate;

-- end of code from book


----------------------------------------------------------------


architecture behavioral of and_gate is
begin

  reducer : process (i) is
    constant Tpd : delay_length := 2 ns;
    variable result : bit;
  begin
    result := '1';
    for index in i'range loop
      result := result and i(index);
    end loop;
    y <= result after Tpd;
  end process reducer;

end architecture behavioral;


----------------------------------------------------------------


entity ch_05_21 is

end entity ch_05_21;


----------------------------------------------------------------


architecture test of ch_05_21 is

  -- code from book:

  signal serial_select, write_en, bus_clk, serial_wr : bit;

  -- end of code from book

  use work.stimulus_generators.all;

  signal test_input : bit_vector(2 downto 0);

begin

  -- code from book:

  serial_write_gate : entity work.and_gate
    port map ( i(1) => serial_select,
               i(2) => write_en,
               i(3) => bus_clk,
               y => serial_wr );

  -- end of code from book


  ----------------


  stimulus : all_possible_values( bv => test_input,
                                  delay_between_values => 10 ns );

  (serial_select, write_en, bus_clk) <= test_input;


end architecture test;
