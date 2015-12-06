--------------------------------------------------------------------------
--
--  bv_images package specification.
--
--  Functions that return the string image of values.
--  Each image is a correctly formed literal according to the
--  rules of VHDL-93.
--
--------------------------------------------------------------------------

package bv_images is


  -- Image of bit vector as binary bit string literal
  -- (in the format B"...")
  -- Length of result is bv'length + 3

  function image (bv : in bit_vector) return string;


  -- Image of bit vector as octal bit string literal
  -- (in the format O"...")
  -- Length of result is (bv'length+2)/3 + 3

  function image_octal (bv : in bit_vector) return string;


  -- Image of bit vector as hex bit string literal
  -- (in the format X"...")
  -- Length of result is (bv'length+3)/4 + 3

  function image_hex (bv : in bit_vector) return string;


end bv_images;

