#include "binary_stream.h"
binary_stream::binary_stream(size_t buf_size, size_t chunk_size)
{
 this->buf = new uint8_t[buf_size];
 this->buf_size = buf_size;
 this->cur_buf_pos = 0;
 this->chunks_per_byte = 8 / chunk_size;
 this->bits_per_chunk = chunk_size; 
 this->cur_bit_pos = 0;
 
 for (uint8_t i = 0; i < this->buf_size; i++)
 {
   this->buf[i] = 0;
 }
}

binary_stream::~binary_stream()
{
 delete[] this->buf;
}

void binary_stream::push_chunk(uint8_t c)
{
  this->buf[this->cur_buf_pos] |= (c << (8 - this->bits_per_chunk + this->cur_bit_pos));
  if (this->cur_bit_pos == 8)
  {
     this->cur_bit_pos = 0;
     this->cur_buf_pos++;
  }
}

uint8_t binary_stream::getChunk(uint32_t pos)
{
//  uint32_t index = (pos / this->chunks_per_byte);
  return 0;
}

size_t binary_stream::getTotalChunks()
{
 return this->cur_buf_pos+1;
}

uint8_t* binary_stream::getRawStream()
{
 return this->buf;
}
