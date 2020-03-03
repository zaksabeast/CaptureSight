#include <vector>
#include <memory>
#include <functional>
#include <switch.h>
#include <csight/RNG.hpp>
#include <csight/Config.hpp>
#include <csight/RaidPokemon.hpp>
#include <csight/CalculateRaidPKMList.hpp>

namespace csight::raid {
  bool checkFlawlessIV(u8 iv) { return iv == 31; }

  bool checkFlawlessIVs(u8 flawlessIVFilter, std::shared_ptr<RaidPokemon> raid) {
    auto ivs = raid->GetIVs();
    u8 flawlessIVCount = std::count_if(ivs.begin(), ivs.end(), checkFlawlessIV);

    return flawlessIVCount >= flawlessIVFilter;
  }

  bool checkShinyType(shiny::ShinyType shinyType, std::shared_ptr<RaidPokemon> raid) {
    auto raidShinyType = raid->GetShinyType();

    switch (shinyType) {
      case shiny::Any:
        return raidShinyType != shiny::None;
      case shiny::Square:
        return raidShinyType == shiny::Square;
      case shiny::Star:
        return raidShinyType == shiny::Star;
      case shiny::None:
      default:
        return true;
    }
  }

  bool checkIfPassesFilters(std::shared_ptr<RaidSearchSettings> searchSettings, std::shared_ptr<RaidPokemon> raid) {
    return checkFlawlessIVs(searchSettings->GetFlawlessIVFilter(), raid) && checkShinyType(searchSettings->GetShinyTypeFilter(), raid);
  }

  void calculateRaidPKMList(std::shared_ptr<RaidSearchSettings> searchSettings,
                            std::function<void(std::shared_ptr<RaidPokemon> raid, u32 frame)> callback) {
    u64 nextSeed = searchSettings->GetSeed();

    for (u32 frame = 0; frame < MAX_RAID_ADVANCES; frame++) {
      auto raid = std::make_shared<RaidPokemon>(nextSeed, searchSettings->GetFlawlessIVs(), 0);
      nextSeed = rng::xoroshiro(nextSeed).nextulong();

      if (checkIfPassesFilters(searchSettings, raid))
        callback(raid, frame);
    }
  }
}  // namespace csight::raid