architecture behavioral of to_fp is

begin

  behavior : process (vec) is

    variable temp : bit_vector(vec'range);
    variable negative : boolean;
    variable int_result : integer;

  begin
    temp := to_bitvector(vec);
    negative := temp(temp'left) = '1';
    if negative then
      temp := not temp;
    end if;
    int_result := 0;
    for index in vec'range loop	  -- sign bit of temp = '0'
      int_result := int_result * 2 + bit'pos(temp(index));
    end loop;
    if negative then
      int_result := (-int_result) - 1;
    end if;
    -- convert to floating point and scale to [-1, +1)
    r <= real(int_result) / real(2**15);
  end process behavior;

end architecture behavioral;
