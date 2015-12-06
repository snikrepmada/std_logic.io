use work.qsim_types.all;

package queue_types is

  type waiting_token_type is record
      token : token_type;
      time_when_enqueued : time;
    end record waiting_token_type;

end package queue_types;
