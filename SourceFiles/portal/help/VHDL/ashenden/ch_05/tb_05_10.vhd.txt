entity add_1 is
  port ( d0, d1, d2, d3 : in bit;
         y0, y1, y2, y3 : out  bit );
end entity add_1;


architecture boolean_eqn of add_1 is
begin

  y0 <= not d0 after 4 ns;

  y1 <= (not d1 and d0)
        or (d1 and not d0) after 4 ns;

  y2 <= (not d2 and d1 and d0)
	or (d2 and not (d1 and d0)) after 4 ns;

  y3 <= (not d3 and d2 and d1 and d0)
	or (d3 and not (d2 and d1 and d0)) after 4 ns;

end architecture boolean_eqn;


entity buf4 is
  port ( a0, a1, a2, a3 : in bit;
         y0, y1, y2, y3 : out  bit );
end entity buf4;


architecture basic of buf4 is
begin

  y0 <= a0 after 2 ns;
  y1 <= a1 after 2 ns;
  y2 <= a2 after 2 ns;
  y3 <= a3 after 2 ns;

end architecture basic;


package counter_types is

  subtype digit is bit_vector(3 downto 0);

end package counter_types;

