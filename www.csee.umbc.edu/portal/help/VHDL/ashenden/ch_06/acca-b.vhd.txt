architecture behavioral of accumulator_adder is
begin

  behavior : process (a, b) is

    constant Tpd_in_out : time := 3 ns;
    variable carry_in : std_ulogic;
    variable carry_out : std_ulogic := '0';

  begin
    for index in 0 to 21 loop
      carry_in := carry_out;  -- of previous bit
      s(index) <= a(index) xor b(index) xor carry_in after Tpd_in_out;
      carry_out := (a(index) and b(index))
      	      	   or (carry_in and (a(index) xor b(index)));
    end loop;
    ovf <= carry_out xor carry_in after Tpd_in_out;  -- ovf is carry_out /= carry_in
  end process behavior;

end architecture behavioral;
