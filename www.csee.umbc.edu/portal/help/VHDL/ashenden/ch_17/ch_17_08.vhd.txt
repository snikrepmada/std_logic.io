entity ch_17_08 is

end entity ch_17_08;


----------------------------------------------------------------


architecture test of ch_17_08 is

  type T is (t1, t2, t3);

  -- code from book:

  type T_ptr is access T;

  procedure deallocate ( P : inout T_ptr );

  -- end of code from book

  procedure deallocate ( P : inout T_ptr ) is
  begin
    null;
  end procedure deallocate;

  -- end of code from book

begin


end architecture test;
