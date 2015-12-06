use work.qsim_types.all, work.random.all;

entity server is

  generic ( name : string;
            distribution : distribution_type;
            mean_service_time : time;
            seed : seed_type;
            time_unit : delay_length := ns;
            info_file_name : string := "info_file.dat" );

  port ( in_arc : in arc_type;
         in_ready : out boolean;
         out_arc : out arc_type;
         info_detail : in info_detail_type );

end entity server;
