#pragma once

#include <future>
#include <switch.h>
#include <vector>

namespace csight::raid {
  std::future<ulong> CalculateRaidSeedAsync(uint ec, uint pid, std::vector<u8> ivs);
  ulong CalculateRaidSeed(uint ec, uint pid, std::vector<u8> ivs);
}  // namespace csight::raid