package random is

  type distribution_type is (fixed, uniform, exponential);

  subtype probability is real range 0.0 to 1.0;

  type probability_vector is array (positive range <>) of probability;

  type seed_type is record
      seed1, seed2 : positive;
    end record seed_type;
  type seed_array is array ( natural range <> ) of seed_type;
  constant sample_seeds : seed_array(0 to 50);

  type random_info_record is record
      seed : seed_type;
      distribution : distribution_type;
      mean : real;
      lower_bound, upper_bound : real;
    end record random_info_record;


  procedure init_fixed ( random_info : out random_info_record;
                         mean : in real );

  procedure init_uniform ( random_info : out random_info_record;
                           lower_bound, upper_bound : in real;
                           seed : in seed_type );

  procedure init_exponential ( random_info : out random_info_record;
                               mean : in real;
                               seed : in seed_type );

  procedure generate_random ( random_info : inout random_info_record;
                              random_number : out real );

end package random;
