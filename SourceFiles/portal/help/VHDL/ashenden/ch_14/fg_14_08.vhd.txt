library ieee;  use ieee.std_logic_1164.all;

entity buf is
  port ( a : in std_logic;  y : out std_logic );
end entity buf;


architecture basic of buf is
begin
  y <= a;
end architecture basic;




-- code from book

library ieee;  use ieee.std_logic_1164.all;

entity fanout_tree is
  generic ( height : natural );
  port ( input : in std_logic;
         output : out std_logic_vector (0 to 2**height - 1) );
end entity fanout_tree;

--------------------------------------------------

architecture recursive of fanout_tree is

begin

  degenerate_tree : if height = 0 generate
  begin
    output(0) <= input;
  end generate degenerate_tree;

  compound_tree : if height > 0 generate
    signal buffered_input_0, buffered_input_1 : std_logic;
  begin

    buf_0 : entity work.buf(basic)
      port map ( a => input, y => buffered_input_0 );

    subtree_0 : entity work.fanout_tree(recursive)
      generic map ( height => height - 1 )
      port map ( input => buffered_input_0,
                 output => output(0 to 2**(height - 1) - 1) );

    buf_1 : entity work.buf(basic)
      port map ( a => input, y => buffered_input_1 );

    subtree_1 : entity work.fanout_tree(recursive)
      generic map ( height => height - 1 )
      port map ( input => buffered_input_1,
                 output => output(2**(height - 1) to 2**height - 1) );

  end generate compound_tree;

end architecture recursive;

-- end code from book



library ieee;  use ieee.std_logic_1164.all;

entity fg_14_08 is
end entity fg_14_08;


architecture test of fg_14_08 is

  signal unbuffered_clock : std_logic;
  signal buffered_clock_array : std_logic_vector(0 to 7);

begin

  -- code from book (in text)

  clock_buffer_tree : entity work.fanout_tree(recursive)
    generic map ( height => 3 )
    port map ( input => unbuffered_clock,
               output => buffered_clock_array );

  -- end code from book

  clock_gen : process is
  begin
    unbuffered_clock <= '1' after 5 ns, '0' after 10 ns;
    wait for 10 ns;
  end process clock_gen;

end architecture test;
