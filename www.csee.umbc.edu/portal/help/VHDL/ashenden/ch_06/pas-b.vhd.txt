architecture behavioral of product_adder_subtracter is
begin

  behavior : process (a, b) is

    constant Tpd_in_out : time := 3 ns;
    variable op2 : std_ulogic_vector(b'range);
    variable carry_in : std_ulogic;
    variable carry_out : std_ulogic;

  begin
    carry_out := To_X01(mode);
    if To_X01(mode) = '1' then
      op2 := not b;
    else
      op2 := b;
    end if;
    for index in 0 to 31 loop
      carry_in := carry_out;  -- of previous bit
      s(index) <= a(index) xor op2(index) xor carry_in after Tpd_in_out;
      carry_out := (a(index) and op2(index))
      	      	   or (carry_in and (a(index) xor op2(index)));
    end loop;
    s(32) <= a(31) xor op2(31) xor carry_out after Tpd_in_out;
  end process behavior;

end architecture behavioral;
