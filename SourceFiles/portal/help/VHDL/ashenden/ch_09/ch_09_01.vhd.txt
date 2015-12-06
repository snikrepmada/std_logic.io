entity ch_09_01 is

end entity ch_09_01;


----------------------------------------------------------------


architecture test of ch_09_01 is
begin


  process_09_1_a : process is

    -- code from book:

    type register_array is array (0 to 15) of bit_vector(31 downto 0);

    type register_set is record
        general_purpose_registers : register_array;
        program_counter : bit_vector(31 downto 0);
        program_status : bit_vector(31 downto 0);
      end record;

    variable CPU_registers : register_set;

    -- code revised to work around MTI bugs mt015 and mt016
    -- alias PSW is CPU_registers.program_status;
    -- alias PC is CPU_registers.program_counter;
    -- alias GPR is CPU_registers.general_purpose_registers;

    alias PSW : bit_vector(31 downto 0) is CPU_registers.program_status;
    alias PC : bit_vector(31 downto 0) is CPU_registers.program_counter;
    alias GPR : register_array is CPU_registers.general_purpose_registers;

    -- alias SP is CPU_registers.general_purpose_registers(15);

    alias SP : bit_vector(31 downto 0) is CPU_registers.general_purpose_registers(15);

    -- alias interrupt_level is PSW(30 downto 26);

    alias interrupt_level : bit_vector(30 downto 26) is PSW(30 downto 26);

    -- end revision

    -- end of code from book

    procedure procedure_09_1_b is

      -- code from book:

      -- code revised to work around MTI bug mt016
      -- alias SP is GPR(15);

      alias SP : bit_vector(31 downto 0) is GPR(15);

      -- end revision

      alias interrupt_level : bit_vector(4 downto 0) is PSW(30 downto 26);

      -- end of code from book

    begin
    end procedure procedure_09_1_b;

  begin
    wait;
  end process process_09_1_a;


end architecture test;
