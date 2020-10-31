#include <switch.h>

// Thanks to https://github.com/Admiral-Fish/PokeFinder/blob/bdbaa4d651f62925f218e90c80a316fb782516e3/Core/RNG/MT.cpp for the
// original code

namespace csight::rng {
  class MersenneTwister {
   public:
    explicit MersenneTwister(u32 seed = 0) {
      mt[0] = seed;

      for (index = 1; index < 624; index++) {
        seed = 0x6C078965 * (seed ^ (seed >> 30)) + index;
        mt[index] = seed;
      }
    }
    u32 next() {
      if (index >= 624) {
        shuffle();
      }

      u32 y = mt[index++];
      y ^= (y >> 11);
      y ^= (y << 7) & 0x9D2C5680;
      y ^= (y << 15) & 0xEFC60000;
      y ^= (y >> 18);

      return y;
    }

    u32 next(u32 min, u32 max) {
      u32 diff = max - min;

      if (diff == 0) {
        return min;
      }

      u32 rand = 0;

      do {
        rand = this->next() & 0x1ff;
      } while (max <= rand);

      return min + rand;
    }

   private:
    u32 mt[624];
    u16 index;

    void shuffle() {
      u32 mt1 = mt[0], mt2;

      for (u16 i = 0; i < 227; i++) {
        mt2 = mt[i + 1];

        u32 y = (mt1 & 0x80000000) | (mt2 & 0x7fffffff);

        u32 y1 = y >> 1;
        if (y & 1) {
          y1 ^= 0x9908B0DF;
        }

        mt[i] = y1 ^ mt[i + 397];
        mt1 = mt2;
      }

      for (u16 i = 227; i < 623; i++) {
        mt2 = mt[i + 1];

        u32 y = (mt1 & 0x80000000) | (mt2 & 0x7fffffff);

        u32 y1 = y >> 1;
        if (y & 1) {
          y1 ^= 0x9908B0DF;
        }

        mt[i] = y1 ^ mt[i - 227];
        mt1 = mt2;
      }

      u32 y = (mt1 & 0x80000000) | (mt[0] & 0x7fffffff);

      u32 y1 = y >> 1;
      if (y & 1) {
        y1 ^= 0x9908B0DF;
      }

      mt[623] = y1 ^ mt[396];

      index -= 624;
    }
  };
}