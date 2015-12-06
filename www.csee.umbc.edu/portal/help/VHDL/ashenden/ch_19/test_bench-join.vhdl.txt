library qsim;

use std.textio.all;

architecture join of test_bench is

  use qsim.qsim_types.all;
  use work.random.all;

  constant num_outputs : positive := 4;
  constant probabilities : probability_vector(1 to num_outputs - 1)
                := ( 0.2, 0.4, 0.1 );

  signal source_arc, join_arc : arc_type;
  signal fork_arc : arc_vector(1 to num_outputs);
  signal info_detail : info_detail_type := trace;

begin

  source1 : entity work.source(behavior)
    generic map ( name => "source1",
                  distribution => fixed,  mean_inter_arrival_time => 100 ns,
                  seed => sample_seeds(1),
                  time_unit => ns,
                  info_file_name => "source1.dat" )
    port map ( out_arc => source_arc,
               info_detail => info_detail );

  fork1 : entity work.fork(behavior)
    generic map ( name => "fork1",
                  probabilities => probabilities,
                  seed => sample_seeds(2),
                  time_unit => ns,
                  info_file_name => "fork1.dat" )
    port map ( in_arc => source_arc,
               out_arc => fork_arc,
               info_detail => info_detail );


  join1 : entity work.join(behavior)
    generic map ( name => "join1",
                  time_unit => ns,
                  info_file_name => "join1.dat" )
    port map ( in_arc => fork_arc,
               out_arc => join_arc,
               info_detail => info_detail );


  sink1 : entity work.sink(behavior)
    generic map ( name => "sink1",
                  time_unit => ns,
                  info_file_name => "sink1.dat" )
    port map ( in_arc => join_arc,
               info_detail => info_detail );


  source_monitor : process is
    variable L : line;
  begin
    wait on source_arc;
    write(L, string'("source_monitor: at "));
    write(L, now, unit => ns);
    write(L, string'(", "));
    write(L, source_arc.token, ns);
    writeline(output, L);
  end process source_monitor;


  forks : for index in 1 to num_outputs generate

    constant index_string : string := integer'image(index);

  begin

    fork_monitor : process
      variable L : line;
    begin
      wait on fork_arc(index);
      write(L, string'("fork_monitor(" & index_string & "): at "));
      write(L, now, unit => ns);
      write(L, string'(", "));
      write(L, fork_arc(index).token, ns);
      writeline(output, L);
    end process fork_monitor;

  end generate forks;


  sink_monitor : process
    variable L : line;
  begin
    wait on join_arc;
    write(L, string'("sink_monitor: at "));
    write(L, now, unit => ns);
    write(L, string'(", "));
    write(L, join_arc.token, ns);
    writeline(output, L);
  end process sink_monitor;


end architecture join;
