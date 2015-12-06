entity d_latch is
  port ( d, clk : in bit;  q : out bit );
end d_latch;


entity and2 is
  port ( a, b : in bit;  y : out bit );
end and2;


architecture basic of d_latch is
begin

  latch_behavior : process is
  begin
    if clk = '1' then
      q <= d after 2 ns;
    end if;
    wait on clk, d;
  end process latch_behavior;

end architecture basic;


architecture basic of and2 is
begin

  and2_behavior : process is
  begin
    y <= a and b after 2 ns;
    wait on a, b;
  end process and2_behavior;

end architecture basic;

----------------------------------------------------------------

