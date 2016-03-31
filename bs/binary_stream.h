#include <stdint.h>
#include <cstring>
#include <vector>
class binary_stream
{
  uint8_t* buf;
  uint32_t buf_size;
  uint32_t cur_buf_pos;
  uint8_t chunks_per_byte;
  uint8_t bits_per_chunk;
  uint8_t cur_bit_pos;
public:
  binary_stream(size_t buf_size, size_t chunk_size);
  virtual ~binary_stream();
  void push_chunk(uint8_t c);
  uint8_t getChunk(uint32_t pos);
  size_t getTotalChunks();
  uint8_t* getRawStream();
};
