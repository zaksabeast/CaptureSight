#pragma once

#include <vector>
#include <future>
#include <switch.h>

namespace csight {
  namespace raid {
    std::future<ulong> CalculateRaidSeedAsync(uint ec, uint pid, std::vector<s8> ivs);
    ulong CalculateRaidSeed(uint ec, uint pid, std::vector<s8> ivs);
  }  // namespace raid
}  // namespace csight