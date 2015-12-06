-- code from book

entity control_unit is

  generic ( Tpd_clk_out, Tpw_clk : delay_length;
            debug : boolean := false );

  port ( clk : in bit;
         ready : in bit;
         control1, control2 : out bit );

end entity control_unit;

-- end code from book



architecture test of control_unit is
begin
end architecture test;




entity fg_12_01 is
end entity fg_12_01;



architecture test of fg_12_01 is

  signal clk, ready : bit;

begin

  dut1 : entity work.control_unit
    -- code from book (in text)
    generic map ( 200 ps, 1500 ps, false )
    -- end code from book
    port map ( clk, ready, open, open );

  dut2 : entity work.control_unit
    -- code from book (in text)
    generic map ( Tpd_clk_out => 200 ps, Tpw_clk => 1500 ps )
    -- end code from book
    port map ( clk, ready, open, open );

  dut3 : entity work.control_unit
    -- code from book (in text)
    generic map ( 200 ps, 1500 ps, debug => open )
    -- end code from book
    port map ( clk, ready, open, open );

end architecture test;
