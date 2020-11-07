#pragma once

#include <csight/RNG/IRNG.hpp>

namespace csight::rng {
  namespace lcrng {
    inline u32 advance(u32 seed) { return seed * 0x41C64E6D + 0x6073; }
  }

  class xoroshiro : public IRNG {
   public:
    using IRNG::next;

    xoroshiro(u64 seed) : state0(seed), state1(0x82A2B175229D6A5B) {}

    u64 nextulong() {
      u64 s0 = state0;
      u64 s1 = state1;
      u64 result = s0 + s1;

      auto rotl = [](u64 num, int shift) {
        return (num << shift) | (num >> (64 - shift)); 
      };

      s1 ^= s0;
      state0 = rotl(s0, 24) ^ s1 ^ (s1 << 16);
      state1 = rotl(s1, 37);

      return result;
    }

    u32 next() { return (u32)nextulong(); }

   private:
    u64 state0, state1;
  };
}
