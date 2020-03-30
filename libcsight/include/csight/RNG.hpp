#pragma once

#include <csight/XOROSHIRO.hpp>
#include <switch.h>

using swsh_xoroshiro = xoroshiro_detail::xoroshiro_plus<uint64_t, uint64_t, 24, 16, 37>;

namespace csight::rng {
  namespace lcrng {
    u32 advance(u32 seed);
  }  // namespace lcrng

  class xoroshiro {
   public:
    xoroshiro(ulong seed);
    u64 nextulong();
    u32 nextuint();
    uint next(uint mask);
    u32 next(u32 compare, u32 mask);

   private:
    swsh_xoroshiro m_prng;
  };
}  // namespace csight::rng