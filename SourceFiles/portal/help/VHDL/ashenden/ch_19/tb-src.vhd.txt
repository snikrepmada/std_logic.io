library qsim;

use std.textio.all;

architecture source of test_bench is

  use qsim.qsim_types.all;
  use work.random.all;

  signal a : arc_type;
  signal info_detail : info_detail_type := trace;

begin

  source1 : entity work.source(behavior)
    generic map ( name => "source1",
                  distribution => fixed,  mean_inter_arrival_time => 100 ns,
                  seed => sample_seeds(0),
                  time_unit => ns,
                  info_file_name => "source1.dat" )
    port map ( out_arc => a,
               info_detail => info_detail );


  monitor : process is

    variable L : line;

  begin
    wait on a;
    write(L, string'("monitor: at "));
    write(L, now, unit => ns);
    write(L, string'(" received "));
    write(L, a.token, ns);
    writeline(output, L);
  end process monitor;


end architecture source;
