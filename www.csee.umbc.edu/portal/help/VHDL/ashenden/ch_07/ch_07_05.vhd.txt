entity ch_07_05 is

end entity ch_07_05;


----------------------------------------------------------------


library bv_utilities;

architecture test of ch_07_05 is

  use bv_utilities.bv_arithmetic.all;

begin


  process_07_5_a : process is

    -- code from book:

    procedure increment ( a : inout integer;   n : in integer := 1 ) is -- . . .
    -- not in book
    begin
      a := a + n;
    end procedure increment;
    -- end not in book;

    procedure increment ( a : inout bit_vector;  n : in bit_vector := B"1" ) is -- . . .
    -- not in book
    begin
      a := a + n;
    end procedure increment;
    -- end not in book;

    procedure increment ( a : inout bit_vector;  n : in integer := 1 ) is -- . . .
    -- not in book
    begin
      a := a + integer_to_bv(n, a'length);
    end procedure increment;
    -- end not in book;

    variable count_int : integer := 2;
    variable count_bv : bit_vector (15 downto 0) := X"0002";

    -- end of code from book

  begin

    -- code from book:

    increment ( count_int, 2 );
    increment ( count_int );

    increment ( count_bv, X"0002");
    increment ( count_bv, 1 );

    -- increment ( count_bv );

    -- end of code from book

    wait;
  end process process_07_5_a;


end architecture test;
