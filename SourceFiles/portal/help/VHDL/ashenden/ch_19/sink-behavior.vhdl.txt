library math;

architecture behavior of sink is

begin

  token_consumer : process is

    variable number_of_tokens_consumed : natural := 0;
    variable life_time : real;  -- in time_unit
    variable sum_of_life_times : real := 0.0;  -- in time_unit
    variable sum_of_squares_of_life_times : real := 0.0;  --in time_unit**2

    use std.textio.all;
    file info_file : text;
    variable L : line;

    use math.math_real.sqrt;

    procedure write_summary is
      variable mean_life_time : real
        := sum_of_life_times / real(number_of_tokens_consumed);
      variable std_dev_of_life_times : real
        := sqrt ( ( sum_of_squares_of_life_times
                    - sum_of_life_times**2 / real(number_of_tokens_consumed) )
                  / real( number_of_tokens_consumed - 1 ) );
    begin
      write(L, string'("Summary information for sink "));
      write(L, name);
      write(L, string'(" up to time "));
      write(L, now, unit => time_unit);
      writeline(info_file, L);
      write(L, string'("  Number of tokens consumed = "));
      write(L, natural(number_of_tokens_consumed));
      writeline(info_file, L);
      write(L, string'("  Mean life_time = "));
      write(L, mean_life_time * time_unit, unit => time_unit);
      writeline(info_file, L);
      write(L, string'("  Standard deviation of life_times = "));
      write(L, std_dev_of_life_times * time_unit, unit => time_unit);
      writeline(info_file, L);
      writeline(info_file, L);
    end procedure write_summary;

    procedure write_trace is
    begin
      write(L, string'("Sink "));
      write(L, name);
      write(L, string'(": at "));
      write(L, now, unit => time_unit);
      write(L, string'(" consumed "));
      write(L, in_arc.token, time_unit);
      writeline(info_file, L);
    end procedure write_trace;

  begin
    file_open(info_file, info_file_name, write_mode);
    loop
      wait on info_detail'transaction, in_arc;
      if info_detail'active and info_detail = summary then
        write_summary;
      end if;
      if in_arc'event then
        number_of_tokens_consumed := number_of_tokens_consumed + 1;
        life_time := real( (now - in_arc.token.creation_time) / time_unit );
        sum_of_life_times := sum_of_life_times + life_time;
        sum_of_squares_of_life_times := sum_of_squares_of_life_times + life_time ** 2;
        if info_detail = trace then
          write_trace;
        end if;
      end if;
    end loop;
  end process token_consumer;

end architecture behavior;
