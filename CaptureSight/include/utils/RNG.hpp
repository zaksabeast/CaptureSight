#pragma once

#include <switch.h>
#include <utils/XOROSHIRO.hpp>

using swsh_xoroshiro = xoroshiro_detail::xoroshiro_plus<uint64_t, uint64_t, 24, 16, 37>;

namespace rng {
  namespace lcrng {
    u32 advance(u32 seed);
  }  // namespace lcrng

  class xoroshiro {
   public:
    xoroshiro(ulong seed);
    uint next(uint mask);

   private:
    swsh_xoroshiro prng;
  };
}  // namespace rng