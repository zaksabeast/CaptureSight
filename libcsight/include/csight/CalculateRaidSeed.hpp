#pragma once

#include <vector>
#include <future>
#include <switch.h>

namespace csight::raid {
  std::future<ulong> CalculateRaidSeedAsync(uint ec, uint pid, std::vector<u8> ivs);
  ulong CalculateRaidSeed(uint ec, uint pid, std::vector<u8> ivs);
}  // namespace csight::raid