entity check_div is

end entity check_div;


----------------------------------------------------------------

library bv_utilities;

architecture behav of check_div is

  use bv_utilities.bv_arithmetic.all;

begin

  checker : process is

    variable bv_a, bv_b, bv_quotient, bv_remainder : bit_vector(3 downto 0);
    variable div_by_zero : boolean;


  begin
    for a in 0 to 15 loop
      for b in 0 to 15 loop
	bv_a := natural_to_bv(a, bv_a'length);
        bv_b := natural_to_bv(b, bv_b'length);
        bv_divu(bv_a, bv_b, bv_quotient, bv_remainder, div_by_zero);
	if b = 0 then
	  assert div_by_zero
	    report integer'image(a) & '/' & integer'image(b)
		   & ": div_by_zero not true";
	else
	  assert not div_by_zero
	    report integer'image(a) & '/' & integer'image(b)
		   & ": div_by_zero not false";
	  assert bv_to_natural(bv_quotient) = a / b
	    report integer'image(a) & '/' & integer'image(b)
		   & ": quotient = " & integer'image(bv_to_natural(bv_quotient));
	  assert bv_to_natural(bv_remainder) = a rem b
	    report integer'image(a) & '/' & integer'image(b)
		   & ": remainder = " & integer'image(bv_to_natural(bv_remainder));
	end if;
      end loop;
    end loop;
    wait;
  end process checker;

end architecture behav;
