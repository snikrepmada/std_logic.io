package bit_vector_signed_arithmetic is

  function "+" ( bv1, bv2 : bit_vector ) return bit_vector;

  function "-" ( bv : bit_vector ) return bit_vector;

  function "*" ( bv1, bv2 : bit_vector ) return bit_vector;

  -- . . .

end package bit_vector_signed_arithmetic;

--------------------------------------------------

-- not in book
library bv_utilities;  use bv_utilities.bv_arithmetic;
-- end not in book

package body bit_vector_signed_arithmetic is

  function "+" ( bv1, bv2 : bit_vector ) return bit_vector is -- . . .
  -- not in book
  begin
    return bv_arithmetic."+"(bv1, bv2);
  end function "+";
  -- end not in book

  function "-" ( bv : bit_vector ) return bit_vector is -- . . .
  -- not in book
  begin
    return bv_arithmetic."-"(bv);
  end function "-";
  -- end not in book

  function mult_unsigned ( bv1, bv2 : bit_vector ) return bit_vector is
    -- . . .
  begin
    -- not in book
    -- . . .
    return bv_arithmetic.bv_multu(bv1, bv2);
    -- end not in book
  end function mult_unsigned;

  function "*" ( bv1, bv2 : bit_vector ) return bit_vector is
  begin
    if bv1(bv1'left) = '0' and bv2(bv2'left) = '0' then
      return mult_unsigned(bv1, bv2);
    elsif bv1(bv1'left) = '0' and bv2(bv2'left) = '1' then
      return -mult_unsigned(bv1, -bv2);
    elsif bv1(bv1'left) = '1' and bv2(bv2'left) = '0' then
      return -mult_unsigned(-bv1, bv2);
    else
      return mult_unsigned(-bv1, -bv2);
    end if;
  end function "*";

  -- . . .

end package body bit_vector_signed_arithmetic;



-- not in book

entity fg_08_08 is
end entity fg_08_08;


architecture test of fg_08_08 is
begin

  stimulus : process is
    use work.bit_vector_signed_arithmetic.all;
    use std.textio.all;
    variable L : line;
  begin
    write(L, X"0002" + X"0005");
    writeline(output, L);
    write(L, X"0002" + X"FFFE");
    writeline(output, L);
    write(L, - X"0005");
    writeline(output, L);
    write(L, - X"FFFE");
    writeline(output, L);
    write(L, X"0002" * X"0005");
    writeline(output, L);
    write(L, X"0002" * X"FFFD");
    writeline(output, L);

    wait;
  end process stimulus;

end architecture test;

-- end not in book
