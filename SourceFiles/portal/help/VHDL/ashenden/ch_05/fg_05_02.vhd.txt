architecture primitive of and_or_inv is

  signal and_a, and_b : bit;
  signal or_a_b : bit;

begin

  and_gate_a : process (a1, a2) is
  begin
    and_a <= a1 and a2;
  end process and_gate_a;

  and_gate_b : process (b1, b2) is
  begin
    and_b <= b1 and b2;
  end process and_gate_b;

  or_gate : process (and_a, and_b) is
  begin
    or_a_b <= and_a or and_b;
  end process or_gate;

  inv : process (or_a_b) is
  begin
    y <= not or_a_b;
  end process inv;

end architecture primitive;
