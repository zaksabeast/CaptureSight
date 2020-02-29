#pragma once

#include <vector>
#include <memory>
#include <functional>
#include <switch.h>
#include <csight/RaidPokemon.hpp>
#include <csight/Shiny.hpp>

namespace csight::raid {
  struct RaidSearchSettings {
    u64 seed;
    u8 flawlessIVs;
  };

  // Using a callback reduces memory consumption by only having one RaidPokemon in memory at a time
  void calculateRaidPKMList(RaidSearchSettings* searchSettings, std::function<void(RaidPokemon* raid, u32 frame)> callback);
}  // namespace csight::raid