architecture behavioral of multiplier is
begin

  behavior : process (a, b) is

    constant Tpd_in_out : time := 40 ns;
    variable negative_result  : boolean;
    variable op1 : std_ulogic_vector(15 downto 0);
    variable op2 : std_ulogic_vector(15 downto 0);
    variable result : std_ulogic_vector(31 downto 0);
    variable carry_in, carry : std_ulogic;

  begin
    op1 := to_X01(a);
    op2 := to_X01(b);
    -- make both operands positive, remembering sign of result
    negative_result := (op1(15) = '1') xor (op2(15) = '1');
    if (op1(15) = '1') then
      carry := '1';
      for index in 0 to 15 loop
        carry_in := carry;
        carry := carry_in and not op1(index);
        op1(index) := not op1(index) xor carry_in;
      end loop;
    end if;
    if (op2(15) = '1') then
      carry := '1';
      for index in 0 to 15 loop
        carry_in := carry;
        carry := carry_in and not op2(index);
        op2(index) := not op2(index) xor carry_in;
      end loop;
    end if;
    -- do long multiplication
    result := (others => '0');
    for count in 0 to 15 loop
      carry := '0';
      if (op2(count) = '1') then
        for index in 0 to 15 loop
          carry_in := carry;
          carry := (result(index+count) and op1(index))
                   or (carry_in and (result(index+count) xor op1(index)));
          result(index+count) := result(index+count) xor op1(index) xor carry_in;
        end loop;
        result(count+16) := carry;
      end if;
    end loop;
    -- result now contains unsigned product, with binary point
    -- between bits 30 and 29.  assign output with sign adjusted.
    if negative_result then
      carry := '1';
      for index in 0 to 31 loop
        carry_in := carry;
        carry := carry_in and not result(index);
        result(index) := not result(index) xor carry_in;
      end loop;
    end if;
    p <= result after Tpd_in_out;
  end process behavior;

end architecture behavioral;

