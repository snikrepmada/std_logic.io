library bv_utilities;

architecture behavior of reg_file is

begin

  reg: process ( a1, a2, a3, d3, write_en ) is

    use work.dlx_instr.reg_index,
        bv_utilities.bv_arithmetic.bv_to_natural;

    constant all_zeros : dlx_word := X"0000_0000";

    type register_array is array (reg_index range 1 to 31) of dlx_word;

    variable register_file : register_array;
    variable reg_index1, reg_index2, reg_index3 : reg_index;

  begin
    -- do write first if enabled
    --
    if To_bit(write_en) = '1' then
      reg_index3 := bv_to_natural(To_bitvector(a3));
      if reg_index3 /= 0 then
        register_file(reg_index3) := To_X01(d3);
      end if;
    end if;
    --
    -- read port 1
    --
    reg_index1 := bv_to_natural(To_bitvector(a1));
    if reg_index1 /= 0 then
      q1 <= register_file(reg_index1) after Tac;
    else
      q1 <= all_zeros after Tac;
    end if;
    --
    -- read port 2
    --
    reg_index2 := bv_to_natural(To_bitvector(a2));
    if reg_index2 /= 0 then
      q2 <= register_file(reg_index2) after Tac;
    else
      q2 <= all_zeros after Tac;
    end if;
  end process reg;

end architecture behavior;
