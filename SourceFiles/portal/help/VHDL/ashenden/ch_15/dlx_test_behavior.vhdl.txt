configuration dlx_test_behavior of dlx_test is

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
      use entity work.dlx(behavior)
        generic map ( Tpd_clk_out => 2 ns, debug => trace_each_step );
    end for;

  end for;

end configuration dlx_test_behavior;
