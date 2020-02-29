#include <vector>
#include <memory>
#include <functional>
#include <switch.h>
#include <csight/RNG.hpp>
#include <csight/Config.hpp>
#include <csight/RaidPokemon.hpp>
#include <csight/CalculateRaidPKMList.hpp>

namespace csight::raid {
  void calculateRaidPKMList(RaidSearchSettings* searchSettings, std::function<void(RaidPokemon* raid, u32 frame)> callback) {
    u64 nextSeed = searchSettings->seed;

    for (u32 frame = 0; frame < MAX_DEN_SHINY_FRAME; frame++) {
      auto raid = RaidPokemon(nextSeed, searchSettings->flawlessIVs, 0);
      callback(&raid, frame);
      nextSeed = rng::xoroshiro(nextSeed).nextulong();
    }
  }
}  // namespace csight::raid