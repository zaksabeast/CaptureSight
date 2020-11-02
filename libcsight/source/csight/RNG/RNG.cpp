#include <csight/RNG/RNG.hpp>

namespace csight::rng {
  namespace lcrng {
    u32 advance(u32 seed) { return seed * 0x41C64E6D + 0x6073; }
  }

  xoroshiro::xoroshiro(ulong seed) { m_prng = swsh_xoroshiro(seed, 0x82A2B175229D6A5B); }

  u64 xoroshiro::nextulong() { return m_prng(); }
  u32 xoroshiro::next() { return (u32)this->nextulong(); }
}
