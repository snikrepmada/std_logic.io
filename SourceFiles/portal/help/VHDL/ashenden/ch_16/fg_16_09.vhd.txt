entity latch is
  generic ( width : positive );
  port ( enable : in bit;
         d : in bit_vector(0 to width - 1);
         q : out bit_vector(0 to width - 1) );
end entity latch;

--------------------------------------------------

architecture behavioral of latch is
begin

  transfer_control : block ( enable = '1' ) is
  begin
    q <= guarded d;
  end block transfer_control;

end architecture behavioral;


-- not in book

entity fg_16_09 is
end entity fg_16_09;


architecture test of fg_16_09 is

 signal enable : bit := '0';
 signal d, q : bit_vector(0 to 7);

begin

  dut : entity work.latch(behavioral)
    generic map ( width => 8 )
    port map ( enable => enable, d => d, q => q );

  stimulus : process is
  begin
    wait for 10 ns;
    d <= X"11";  wait for 10 ns;
    enable <= '1';  wait for 10 ns;
    d <= X"AA";  wait for 10 ns;
    enable <= '0';  wait for 10 ns;
    d <= X"00";  wait for 10 ns;

    wait;
  end process stimulus;

end architecture test;

-- end not in book
