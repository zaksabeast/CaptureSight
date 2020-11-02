#pragma once

#include <csight/RNG/IRNG.hpp>
#include <switch.h>

// Thanks to https://github.com/Admiral-Fish/PokeFinder/blob/bdbaa4d651f62925f218e90c80a316fb782516e3/Core/RNG/MT.cpp for the
// original code

namespace csight::rng {
  class MersenneTwister : public IRNG {
   public:
    using IRNG::next;

    MersenneTwister(u32 seed = 0) {
      m_mt[0] = seed;

      for (m_index = 1; m_index < 624; m_index++) {
        seed = 0x6C078965 * (seed ^ (seed >> 30)) + m_index;
        m_mt[m_index] = seed;
      }
    }

    u32 next() {
      if (m_index >= 624) {
        this->shuffle();
      }

      u32 y = m_mt[m_index++];
      y ^= (y >> 11);
      y ^= (y << 7) & 0x9D2C5680;
      y ^= (y << 15) & 0xEFC60000;
      y ^= (y >> 18);

      return y;
    }

   private:
    u32 m_mt[624];
    u16 m_index;

    void shuffle() {
      u32 mt1 = m_mt[0], mt2;

      for (u16 i = 0; i < 227; i++) {
        mt2 = m_mt[i + 1];

        u32 y = (mt1 & 0x80000000) | (mt2 & 0x7fffffff);

        u32 y1 = y >> 1;
        if (y & 1) {
          y1 ^= 0x9908B0DF;
        }

        m_mt[i] = y1 ^ m_mt[i + 397];
        mt1 = mt2;
      }

      for (u16 i = 227; i < 623; i++) {
        mt2 = m_mt[i + 1];

        u32 y = (mt1 & 0x80000000) | (mt2 & 0x7fffffff);

        u32 y1 = y >> 1;
        if (y & 1) {
          y1 ^= 0x9908B0DF;
        }

        m_mt[i] = y1 ^ m_mt[i - 227];
        mt1 = mt2;
      }

      u32 y = (mt1 & 0x80000000) | (m_mt[0] & 0x7fffffff);

      u32 y1 = y >> 1;
      if (y & 1) {
        y1 ^= 0x9908B0DF;
      }

      m_mt[623] = y1 ^ m_mt[396];

      m_index -= 624;
    }
  };
}