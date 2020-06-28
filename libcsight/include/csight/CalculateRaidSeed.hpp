#pragma once

#include <future>
#include <switch.h>
#include <vector>

namespace csight::raid {
  std::future<ulong> calculateRaidSeedAsync(uint ec, uint pid, std::vector<u8> ivs);
  ulong calculateRaidSeed(uint ec, uint pid, std::vector<u8> ivs);
}  // namespace csight::raid