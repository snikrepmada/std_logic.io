entity ch_07_04 is

  -- code from book:

  impure function now return delay_length;

  -- end of code from book

  impure function now return delay_length is
  begin
    return std.standard.now;
  end function now;

  -- end of code from book

end entity ch_07_04;


