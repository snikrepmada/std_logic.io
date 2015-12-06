architecture behavioral of to_vector is

begin

  behavior : process (r) is

    variable temp : integer range -2**15 to 2**15 - 1;
    variable negative : boolean;
    variable result : std_ulogic_vector(vec'range);

  begin
    -- scale to [-2**15, +2**15) and convert to integer
    if r * real(2**15) < real(-2**15) then
      temp := -2**15;
    elsif r * real(2**15) >= real(2**15 - 1) then
      temp := 2**15 - 1;
    else
      temp := integer(r * real(2**15));
    end if;
    negative := temp < 0;
    if negative then
      temp := -(temp + 1);
    end if;
    result := (others => '0');
    for index in result'reverse_range loop
      result(index) := to_X01(bit'val(temp rem 2));
      temp := temp / 2;
      exit when temp = 0;
    end loop;
    if negative then
      result := not result;
      result(result'left) := '1';
    end if;
    vec <= result;
  end process behavior;

end architecture behavioral;
