architecture behavior of reg_multiple_out is

begin

  reg: process ( d, latch_en, out_en ) is

    variable latched_value : dlx_word;

  begin
    if To_bit(latch_en) = '1' then
      latched_value := To_X01(d);
    end if;
    for index in out_en'range loop
      if To_bit(out_en(index)) = '1' then
	q(index) <= latched_value after Tpd;
      else
	q(index) <= disabled_dlx_word after Tpd;
      end if;
    end loop;
  end process reg;

end architecture behavior;
