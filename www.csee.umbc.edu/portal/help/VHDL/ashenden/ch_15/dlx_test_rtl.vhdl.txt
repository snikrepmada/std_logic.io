configuration dlx_test_rtl of dlx_test is

  for bench

    for cg : clock_gen
      use entity work.clock_gen(behavior)
        generic map ( Tpw => 8 ns, Tps => 2 ns );
    end for;

    for mem : memory
      use entity work.memory(preloaded)
        generic map ( mem_size => 65536,
                      Tac_first => 95 ns, Tac_burst => 35 ns, Tpd_clk_out => 2 ns );
    end for;

    for proc : dlx
      use configuration work.dlx_rtl
        generic map ( Tpd_clk_out => 2 ns, debug => trace_each_step );
    end for;

  end for;  -- bench of dlx_test

end configuration dlx_test_rtl;
