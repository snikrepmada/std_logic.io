use work.qsim_types.all;

entity sink is

  generic ( name : string;
            time_unit : delay_length := ns;
            info_file_name : string := "info_file.dat" );

  port ( in_arc : in arc_type;
	 info_detail : in info_detail_type );

end sink;
