architecture behavior of latch is

begin 

  q <= d after Tpd when To_bit(latch_en) = '1';

end architecture behavior;
