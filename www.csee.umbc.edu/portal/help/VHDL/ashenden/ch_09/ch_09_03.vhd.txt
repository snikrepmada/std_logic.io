package system_types is

  -- code from book

  type system_status is (idle, active, overloaded);

  -- end code from book

end package system_types;




entity ch_09_03 is

end entity ch_09_03;


----------------------------------------------------------------


architecture test of ch_09_03 is

  -- code from book

  alias status_type is work.system_types.system_status;

  -- end code from book

begin


  process_09_2_b : process is

    variable status : status_type := idle;

  begin
    wait for 10 ns;
    status := active;
    wait for 10 ns;
    status := overloaded;

    wait;
  end process process_09_2_b;


end architecture test;
