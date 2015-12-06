package utility_definitions is

  constant word_size : natural := 16;

end package utility_definitions;


----------------------------------------------------------------


library utilities;

entity ch_20_01 is

end entity ch_20_01;


----------------------------------------------------------------


architecture test of ch_20_01 is
begin


  process is
  begin

    report

    -- code from book:

    utilities.utility_definitions.word_size'simple_name

    -- end of code from book

    ;

    wait;
  end process;


end architecture test;
