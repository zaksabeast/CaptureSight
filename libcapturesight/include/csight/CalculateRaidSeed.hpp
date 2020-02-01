#pragma once

#include <vector>
#include <switch.h>

namespace csight {
  namespace raid {
    ulong CalculateRaidSeed(uint ec, uint pid, std::vector<s8> ivs);
  }  // namespace raid
}  // namespace csight