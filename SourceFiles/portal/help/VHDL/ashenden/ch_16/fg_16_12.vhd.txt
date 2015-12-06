entity counter is

  generic ( tipd_reset,                   -- input prop delay on reset
            tipd_clk,                     -- input prop delay on clk
            topd_q : delay_length;        -- output prop delay on q
            tsetup_reset,                 -- setup: reset before clk
            thold_reset : delay_length ); -- hold time: reset after clk

  port ( reset,                           -- synchronous reset input
         clk : in bit;                    -- edge triggered clock input
         q : out bit_vector );            -- counter output

end entity counter;
