use work.qsim_types.all, work.random.all;

entity source is

  generic ( name : string;
            distribution : distribution_type;
            mean_inter_arrival_time : delay_length;
            seed : seed_type;
            time_unit : delay_length := ns;
            info_file_name : string := "info_file.dat" );

  port ( out_arc : out arc_type;
         info_detail : in info_detail_type );

end entity source;
