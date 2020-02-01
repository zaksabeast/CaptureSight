#pragma once

#include <switch.h>
#include <csight/XOROSHIRO.hpp>

using swsh_xoroshiro = xoroshiro_detail::xoroshiro_plus<uint64_t, uint64_t, 24, 16, 37>;

namespace csight {
  namespace rng {
    namespace lcrng {
      u32 advance(u32 seed);
    }  // namespace lcrng

    class xoroshiro {
     public:
      xoroshiro(ulong seed);
      u64 nextulong();
      u32 nextuint();
      uint next(uint mask);

     private:
      swsh_xoroshiro prng;
    };
  }  // namespace rng
}  // namespace csight