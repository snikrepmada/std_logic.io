use work.qsim_types.all;

entity queue is

  generic ( name : string;
            time_unit : delay_length := ns;
            info_file_name : string := "info_file.dat" );

  port ( in_arc : in arc_type;
	 out_arc : out arc_type;
	 out_ready : in boolean;
         info_detail : in info_detail_type );

end entity queue;
