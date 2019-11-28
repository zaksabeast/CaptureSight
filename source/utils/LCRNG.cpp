#include <LCRNG.hpp>

namespace lcrng {
  u32 advance(u32 seed) { return seed * 0x41C64E6D + 0x6073; }
}  // namespace lcrng