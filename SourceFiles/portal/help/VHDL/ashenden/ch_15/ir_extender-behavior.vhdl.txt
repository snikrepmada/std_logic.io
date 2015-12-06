use work.dlx_instr.all;

architecture behavior of ir_extender is

  subtype upper_6_bits is std_logic_vector(0 to 5);
  subtype upper_16_bits is std_logic_vector(0 to 15);

begin

  extender : process ( d, immed_en, immed_size_26, immed_unsigned ) is
  begin
    if To_bit(immed_en) = '1' then
      if To_bit(immed_size_26) = '1' then  -- 26-bit immediate
      	if To_bit(immed_unsigned) = '1' then
	  q <= upper_6_bits'(others => '0') & d(6 to 31) after Tpd;
	else
	  q <= upper_6_bits'(others => d(6)) & d(6 to 31) after Tpd;
	end if;
      else -- 16-bit immediate
      	if To_bit(immed_unsigned) = '1' then
	  q <= upper_16_bits'(others => '0') & d(16 to 31) after Tpd;
	else
	  q <= upper_16_bits'(others => d(16)) & d(16 to 31) after Tpd;
	end if;
      end if;
    else
      q <= disabled_dlx_word after Tpd;
    end if;
  end process extender;

end architecture behavior;
