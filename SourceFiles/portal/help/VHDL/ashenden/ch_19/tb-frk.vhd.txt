library qsim;

use std.textio.all;

architecture fork of test_bench is

  use qsim.qsim_types.all;
  use work.random.all;

  constant num_outputs : positive := 4;
  constant probabilities : probability_vector(1 to num_outputs - 1)
                := ( 0.2, 0.4, 0.1 );

  signal source_arc : arc_type;
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


  sinks : for index in 1 to num_outputs generate

    constant index_string : string := integer'image(index);

  begin

    sink : entity work.sink(behavior)
      generic map ( name => "sink" & index_string,
                    time_unit => ns,
                    info_file_name => "sink" & index_string & ".dat" )
      port map ( in_arc => fork_arc(index),
		 info_detail => info_detail );

    sink_monitor : process
      variable L : line;
    begin
      wait on fork_arc(index);
      write(L, string'("sink_monitor(" & index_string & "): at "));
      write(L, now, unit => ns);
      write(L, string'(", "));
      write(L, fork_arc(index).token, ns);
      writeline(output, L);
    end process sink_monitor;

  end generate sinks;


end architecture fork;
