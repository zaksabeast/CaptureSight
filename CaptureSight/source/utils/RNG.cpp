#include <RNG.hpp>

namespace rng {
  namespace lcrng {
    u32 advance(u32 seed) { return seed * 0x41C64E6D + 0x6073; }
  }  // namespace lcrng

  xoroshiro::xoroshiro(ulong seed) { this->prng = swsh_xoroshiro(seed, 0x82A2B175229D6A5B); }

  u64 xoroshiro::nextulong() { return this->prng(); }
  u32 xoroshiro::nextuint() { return (uint)this->nextulong(); }
  uint xoroshiro::next(uint mask) { return this->prng() & mask; }
}  // namespace rng