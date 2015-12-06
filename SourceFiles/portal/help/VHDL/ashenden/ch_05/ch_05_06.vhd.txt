entity ch_05_06 is

end entity ch_05_06;


----------------------------------------------------------------


architecture test of ch_05_06 is

  signal y : bit := '0';
  signal or_a_b : bit := '0';
  signal clk : bit := '0';

begin


  process_05_3_a : process is
  begin

    -- code from book:

    y <= not or_a_b after 5 ns;

    -- end of code from book

    wait on or_a_b;
  end process process_05_3_a;


  stimulus_05_3_a : process is
  begin
    or_a_b <= '1' after 20 ns,
              '0' after 40 ns;
    wait;
  end process stimulus_05_3_a;


  process_05_3_b : process is
    constant T_pw : delay_length := 10 ns;
  begin

    -- code from book:

    clk <= '1' after T_pw, '0' after 2*T_pw;

    -- end of code from book

    wait for 2*T_pw;
  end process process_05_3_b;


end architecture test;
