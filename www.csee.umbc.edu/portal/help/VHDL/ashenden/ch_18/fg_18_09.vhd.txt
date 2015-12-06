library bv_utilities;

use bv_utilities.bv_arithmetic.bv_to_natural,
    bv_utilities.bv_arithmetic.natural_to_bv,
    std.textio.all;

architecture file_loaded of memory is
begin

  mem_behavior : process is

    constant high_address : natural := mem_size - 1;

    type memory_array is
      array (natural range 0 to high_address / 4) of dlx_bv_word;

    variable mem : memory_array;

    -- . . .    -- other variables as in architecture preloaded

    procedure load is

      file binary_file : text open read_mode is load_file_name;
      variable L : line;
      variable ch : character;
      variable line_number : natural := 0;
      variable addr : natural;
      variable word : dlx_bv_word;

      procedure read_hex_natural(L : inout line; n : out natural) is
        variable result : natural := 0;
      begin
        for i in 1 to 8 loop
          read(L, ch);
          if '0' <= ch and ch <= '9' then
            result := result*16 + character'pos(ch) - character'pos('0');
          elsif 'A' <= ch and ch <= 'F' then
            result := result*16 + character'pos(ch) - character'pos('A') + 10;
          elsif 'a' <= ch and ch <= 'f' then
            result := result*16 + character'pos(ch) - character'pos('a') + 10;
          else
            report "Format error in file " & load_file_name
                   & " on line " & integer'image(line_number) severity error;
          end if;
        end loop;
        n := result;
      end read_hex_natural;

      procedure read_hex_word(L : inout line; word : out dlx_bv_word) is
        variable digit : natural;
        variable r : natural := 0;
      begin
        for i in 1 to 8 loop
          read(L, ch);
          if '0' <= ch and ch <= '9' then
            digit := character'pos(ch) - character'pos('0');
          elsif 'A' <= ch and ch <= 'F' then
            digit := character'pos(ch) - character'pos('A') + 10;
          elsif 'a' <= ch and ch <= 'f' then
            digit := character'pos(ch) - character'pos('a') + 10;
          else
            report "Format error in file " & load_file_name
                   & " on line " & integer'image(line_number)
                   severity error;
          end if;
          word(r to r+3) := natural_to_bv(digit, 4);
          r := r + 4;
        end loop;
      end read_hex_word;

    begin
      while not endfile(binary_file) loop
        readline(binary_file, L);
        line_number := line_number + 1;
        read_hex_natural(L, addr);
        read(L, ch);  -- the space between addr and data
        read_hex_word(L, word);
        mem(addr / 4) := word;
      end loop;
    end load;

    procedure do_write is -- . . . -- as in architecture preloaded

    procedure do_read is -- . . .  -- as in architecture preloaded

  begin
    load;  -- read binary memory image into memory array
    -- . . .       -- as in architecture preloaded
  end process mem_behavior;

end architecture file_loaded;
