entity SR_flipflop is
  port ( s_n, r_n : in bit;  q, q_n : inout bit );

begin

  postponed process (q, q_n) is
  begin
    assert now = 0 fs or q = not q_n
      report "implementation error: q /= not q_n";
  end postponed process;

end entity SR_flipflop;

--------------------------------------------------

architecture dataflow of SR_flipflop is
begin

  gate_1 : q <= s_n nand q_n;
  gate_2 : q_n <= r_n nand q;

end architecture dataflow;



-- not in book

entity fg_21_05 is
end entity fg_21_05;


architecture test of fg_21_05 is

  signal s_n, r_n, q, q_n : bit;

begin

  dut : entity work.SR_flipflop
    port map ( s_n, r_n, q, q_n );

  s_n <= '1',
         '0' after 10 ns, '1' after 15 ns,
         '0' after 30 ns, '1' after 40 ns;

  r_n <= '0', '1' after 5 ns,
         '0' after 20 ns, '1' after 25 ns,
         '0' after 30 ns, '1' after 35 ns;

end architecture test;

-- end not in book
