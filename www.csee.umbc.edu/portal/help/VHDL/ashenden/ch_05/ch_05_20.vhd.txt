package pk_05_20 is

  -- code from book:

  type FIFO_status is record
      nearly_full, nearly_empty, full, empty : bit;
    end record FIFO_status;

  -- end of code from book

end package pk_05_20;


----------------------------------------------------------------


use work.pk_05_20.all;

entity FIFO is
  port ( status : out FIFO_status;
         other_ports : out bit );
end entity FIFO;


----------------------------------------------------------------


entity ch_05_20 is

end entity ch_05_20;


----------------------------------------------------------------


use work.pk_05_20.all;

architecture test of ch_05_20 is

  signal start_flush, end_flush, DMA_buffer_full, DMA_buffer_empty : bit;

begin

  -- code from book:

  DMA_buffer : entity work.FIFO
    port map ( -- . . ., 
               status.nearly_full => start_flush,
               status.nearly_empty => end_flush,
               status.full => DMA_buffer_full,
               status.empty => DMA_buffer_empty, -- . . . );
               -- not in book
               other_ports => open );
               -- end not in book

  -- end of code from book


end architecture test;
