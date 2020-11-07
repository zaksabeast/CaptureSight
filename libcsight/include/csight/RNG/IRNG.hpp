#pragma once

#include <cmath>
#include <switch.h>

namespace csight::rng {
  class IRNG {
   public:
    virtual u32 next() = 0;

    u32 next(u32 min, u32 max, u32 mask) {
      u32 diff = max - min;

      if (diff == 0) {
        return min;
      }

      u32 rand = 0;
      u32 inclusiveMax = diff + 1;

      do {
        rand = this->next() & mask;
      } while (inclusiveMax <= rand);

      return min + rand;
    }

    u32 next(u32 max, u32 mask) { return this->next(0, max, mask); }

    u32 next(u32 max) {
      u32 mask = std::pow(2, 32 - __builtin_clz(max)) - 1;
      return this->next(0, max, mask);
    }
  };
}