entity check_mult is

end entity check_mult;


----------------------------------------------------------------

library bv_utilities;

architecture behav of check_mult is

  use bv_utilities.bv_arithmetic.all;

begin

  checker : process is

    variable bv_a, bv_b, bv_product : bit_vector(3 downto 0);
    variable overflow : boolean;


  begin
    for a in 0 to 15 loop
      for b in 0 to 15 loop
	bv_a := natural_to_bv(a, bv_a'length);
        bv_b := natural_to_bv(b, bv_b'length);
        bv_multu(bv_a, bv_b, bv_product, overflow);
	if a * b > 15 then
	  assert overflow
	    report integer'image(a) & '*' & integer'image(b)
		   & ": overflow not true";
	else
	  assert not overflow
	    report integer'image(a) & '*' & integer'image(b)
		   & ": overflow not false";
	  assert bv_to_natural(bv_product) = a * b
	    report integer'image(a) & '*' & integer'image(b)
		   & ": product = " & integer'image(bv_to_natural(bv_product));
	end if;
      end loop;
    end loop;
    wait;
  end process checker;

end architecture behav;
