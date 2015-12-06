package ch_20_09_a is

  attribute attr : integer;

end package ch_20_09_a;



use work.ch_20_09_a.all;

entity e is
  port ( p : in bit );
  attribute attr of p : signal is 1;
end entity e;


architecture arch of e is
begin

  assert false report integer'image(p'attr);

end architecture arch;



use work.ch_20_09_a.all;

entity ch_20_09 is
end entity ch_20_09;



architecture test of ch_20_09 is

  signal s : bit;

  attribute attr of s : signal is 2;

begin

  -- code from book

  c1 : entity work.e(arch)
    port map ( p => s );

  -- end code from book

end architecture test;
