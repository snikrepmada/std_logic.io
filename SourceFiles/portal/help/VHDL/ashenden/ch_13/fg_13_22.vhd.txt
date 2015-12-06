configuration controller_with_timing of control_section is

  for structural

    for flag_reg : reg
      generic map ( t_setup => 200 ps, t_hold => 150 ps,
                    t_pd => 150 ps, width => width )
      -- workaround for MTI bug mt023
      -- port map ( reset_n => '1');
      ;
      -- end workaround
    end for;

    -- . . .

  end for;

end configuration controller_with_timing;
