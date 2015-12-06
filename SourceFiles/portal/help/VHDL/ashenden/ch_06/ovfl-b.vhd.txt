architecture behavioral of overflow_logic is

  constant Tpd_in_out : time := 3 ns;

begin

  ovf <= real_accumulator_ovf or imag_accumulator_ovf
	 or ( real_sum(21) xor real_sum(20) )
	 or ( real_sum(21) xor real_sum(19) )
	 or ( real_sum(21) xor real_sum(18) )
	 or ( real_sum(21) xor real_sum(17) )
	 or ( imag_sum(21) xor imag_sum(20) )
	 or ( imag_sum(21) xor imag_sum(19) )
	 or ( imag_sum(21) xor imag_sum(18) )
	 or ( imag_sum(21) xor imag_sum(17) ) after Tpd_in_out;

end architecture behavioral;
