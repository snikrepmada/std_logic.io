-- code from book

entity reg is
  generic ( width : positive );
  port ( d :  in  bit_vector(0 to width - 1);
         q :  out  bit_vector(0 to width - 1);
         clk, reset : in bit );
end entity reg;

--------------------------------------------------

architecture behavioral of reg is
begin

  behavior : process (clk, reset) is
    constant zero : bit_vector(0 to width - 1) := (others => '0');
  begin
    if reset = '1' then
      q <= zero;
    elsif clk'event and clk = '1' then
      q <= d;
    end if;
  end process behavior;

end architecture behavioral;

-- end code from book



entity fg_12_03 is
end entity fg_12_03;


architecture test of fg_12_03 is

  -- code from book

  subtype state_vector is bit_vector(1 to 5);

  -- end code from book

  signal clk, reset : bit := '0';
  signal word_in, word_out : bit_vector(0 to 31);
  signal state_in, state_out : state_vector;

begin

  -- code from book

  word_reg : entity work.reg(behavioral)
    generic map ( width => 32 )
    port map ( -- . . . );
    -- not in book
               d => word_in, q => word_out, clk => clk, reset => reset );
    -- end not in book

  state_reg : entity work.reg(behavioral)
    generic map ( width => state_vector'length )
    port map ( -- . . . );
    -- not in book
               d => state_in, q => state_out, clk => clk, reset => reset );

  -- end code from book

  clk_gen : clk <= '1' after 10 ns, '0' after 20 ns when clk = '0';

  reset_gen : reset <= '1' after 80 ns, '0' after 105 ns;

  stimulus_word : word_in <= X"11111111" after 25 ns,
                             X"22222222" after 65 ns,
		             X"33333333" after 85 ns,
		             X"44444444" after 125 ns;

  stimulus_state : state_in <= "00001" after 25 ns,
                               "00010" after 65 ns,
		               "00011" after 85 ns,
		               "00100" after 125 ns;

end architecture test;
