use work.qsim_types.all, work.random.all;

entity fork is

  generic ( name : string;
            probabilities : probability_vector;
                -- must be one element shorter than out_arc port
            seed : seed_type;
            time_unit : delay_length := ns;
            info_file_name : string := "info_file.dat" );

  port ( in_arc : in arc_type;
         out_arc : out arc_vector;
         info_detail : in info_detail_type );       

end fork;
