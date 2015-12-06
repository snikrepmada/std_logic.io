architecture behavior of mux2 is

begin

  with To_bit(sel) select
    y <=  i0 after Tpd when '0',
      	  i1 after Tpd when '1';

end architecture behavior;
