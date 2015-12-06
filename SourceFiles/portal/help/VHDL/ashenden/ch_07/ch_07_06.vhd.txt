entity ch_07_06 is

end entity ch_07_06;


----------------------------------------------------------------


library bv_utilities;  use bv_utilities.bv_arithmetic;

architecture test of ch_07_06 is
begin


  process_07_5_b : process is

    -- code from book:

    function "+" ( left, right : in bit_vector ) return bit_vector is
    begin
      -- . . .
      -- not in book
      return bv_arithmetic."+"(left, right);
      -- end not in book
    end function "+";

    variable addr_reg : bit_vector(31 downto 0);
    -- . . .

    -- end of code from book

    -- code from book:

    function "abs" ( right : in bit_vector ) return bit_vector is
    begin
      -- . . .
      -- not in book
      if right(right'left) = '0' then
        return right;
      else
        return bv_arithmetic."-"(right);
      end if;
      -- end not in book
    end function "abs";

    variable accumulator : bit_vector(31 downto 0);
    -- . . .

    -- end of code from book

  begin

    -- code from book:

    addr_reg := addr_reg + X"0000_0004";

    -- end of code from book

    accumulator := X"000000FF";

    -- code from book:

    accumulator := abs accumulator;

    -- end of code from book

    accumulator := X"FFFFFFFE";
    accumulator := abs accumulator;

    wait;
  end process process_07_5_b;


end architecture test;
