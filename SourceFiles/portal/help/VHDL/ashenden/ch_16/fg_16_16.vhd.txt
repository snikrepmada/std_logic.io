entity real_subcircuit is
  port ( a, b : in bit;  y1, y2 : out bit );
end entity real_subcircuit;


architecture basic of real_subcircuit is
begin
  y1 <= a and b after 10 ns;
  y2 <= a nand b after 10 ns;
end architecture basic;



-- code from book

configuration full of circuit is

  for with_pad_delays  -- configure the architecture

    for functionality    -- configure the block

      for all : subcircuit
        use entity work.real_subcircuit(basic);
      end for;

    end for;

  end for;

end configuration full;

-- end code from book



entity fg_16_16 is
end entity fg_16_16;


library util;  use util.stimulus_generators.all;

architecture test of fg_16_16 is

  signal in1, in2, in3, out1, out2 : bit;
  signal test_vector : bit_vector(1 to 3);

begin

  dut : configuration work.full
    generic map ( inpad_delay => 2 ns, outpad_delay => 3 ns )
    port map ( in1 => in1, in2 => in2, in3 => in3, out1 => out1, out2 => out2 );

  stimulus : all_possible_values ( test_vector, 50 ns );

  (in1, in2, in3) <= test_vector;

end architecture test;
