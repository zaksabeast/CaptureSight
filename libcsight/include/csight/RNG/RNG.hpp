#pragma once

#include <switch.h>

namespace csight::rng {
  namespace lcrng {
    u32 advance(u32 seed) { return seed * 0x41C64E6D + 0x6073; }
  }

  class xoroshiro {
   public:
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

    u32 nextuint() { return (u32)nextulong(); }

    u32 next(u32 mask) { return nextulong() & mask; }

    u32 next(u32 max, u32 mask) {
      u32 rand = nextulong() & mask;

      while (rand >= max) {
        rand = nextulong() & mask;
      }

      return rand;
    }

   private:
    u64 state0, state1;
  };
}
