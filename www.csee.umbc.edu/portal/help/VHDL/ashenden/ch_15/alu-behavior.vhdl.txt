library bv_utilities;

architecture behavior of alu is

begin

  alu_op: process ( s1, s2, func ) is

    use bv_utilities.bv_arithmetic.all;

    variable bv_s1, bv_s2 : dlx_bv_word;
    variable temp_result : dlx_bv_word;
    variable temp_overflow : boolean;

    type boolean_to_X01_table is array (boolean) of X01;
    constant boolean_to_X01 : boolean_to_X01_table := ( '0', '1' );

  begin
    bv_s1 := To_bitvector(s1);
    bv_s2 := To_bitvector(s2);
    temp_overflow := false;
    case func is
      when alu_pass_s1 =>
        temp_result := bv_s1;
      when alu_pass_s2 =>
        temp_result := bv_s2;
      when alu_and =>
        temp_result := bv_s1 and bv_s2;
      when alu_or =>
        temp_result := bv_s1 or bv_s2;
      when alu_xor =>
        temp_result := bv_s1 xor bv_s2;
      when alu_sll =>
        temp_result := bv_s1 sll bv_to_natural(bv_s2(27 to 31));
      when alu_srl =>
        temp_result := bv_s1 srl bv_to_natural(bv_s2(27 to 31));
      when alu_sra =>
        temp_result := bv_s1 sra bv_to_natural(bv_s2(27 to 31));
      when alu_add =>
        bv_add(bv_s1, bv_s2, temp_result, temp_overflow);
      when alu_addu =>
        bv_addu(bv_s1, bv_s2, temp_result, temp_overflow);
      when alu_sub =>
        bv_sub(bv_s1, bv_s2, temp_result, temp_overflow);
      when alu_subu =>
        bv_subu(bv_s1, bv_s2, temp_result, temp_overflow);
      when others =>
	report "illegal function code" severity error;
	temp_result := X"0000_0000";
    end case;
    result <= To_X01(temp_result) after Tpd;
    zero <= boolean_to_X01(temp_result = X"0000_0000") after Tpd;
    negative <= To_X01(temp_result(0)) after Tpd;
    overflow <= boolean_to_X01(temp_overflow) after Tpd;
  end process alu_op;

end architecture behavior;
