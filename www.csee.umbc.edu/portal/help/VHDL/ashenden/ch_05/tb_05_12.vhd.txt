entity in_pad is
  port ( i : in bit;  z : out bit );
end entity in_pad;


entity reg32 is
  port ( en : in bit;  clk : in bit;  d : in bit_vector(31 downto 0);
         q : out bit_vector(31 downto 0) );
end entity reg32;


entity adder is
  port ( a, b : in bit_vector(31 downto 0);
         y : out bit_vector(31 downto 0);
	 c : out bit );
end entity adder;


entity filter is
end entity filter;

