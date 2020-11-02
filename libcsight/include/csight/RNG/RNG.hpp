#pragma once

#include <csight/RNG/IRNG.hpp>
#include <csight/RNG/MersenneTwister.hpp>
#include <csight/RNG/XOROSHIRO.hpp>
#include <switch.h>

using swsh_xoroshiro = xoroshiro_detail::xoroshiro_plus<uint64_t, uint64_t, 24, 16, 37>;

namespace csight::rng {
  namespace lcrng {
    u32 advance(u32 seed);
  }

  class xoroshiro : public IRNG {
   public:
    using IRNG::next;

    xoroshiro(ulong seed);
    u64 nextulong();
    u32 next();

   private:
    swsh_xoroshiro m_prng;
  };
}
