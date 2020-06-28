#include <csight/Ability.hpp>
#include <csight/CalculateRaidPKMList.hpp>
#include <csight/Config.hpp>
#include <csight/RNG.hpp>
#include <csight/RaidPokemon.hpp>
#include <functional>
#include <memory>
#include <switch.h>
#include <vector>

namespace csight::raid {
  bool checkFlawlessIV(u8 iv) { return iv == 31; }

  bool checkFlawlessIVs(u8 flawlessIVFilter, std::shared_ptr<RaidPokemon> raid) {
    auto ivs = raid->getIVs();
    u8 flawlessIVCount = std::count_if(ivs.begin(), ivs.end(), checkFlawlessIV);

    return flawlessIVCount >= flawlessIVFilter;
  }

  bool checkShinyType(shiny::ShinyType shinyType, std::shared_ptr<RaidPokemon> raid) {
    auto raidShinyType = raid->getShinyType();

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

  bool checkAbility(ability::filter::AbilityFilter abilityFilter, std::shared_ptr<RaidPokemon> raid) {
    auto ability = raid->getAbility();

    switch (abilityFilter) {
      case ability::filter::None:
      case ability::filter::Any:
        return true;
      case ability::filter::First:
        return ability == ability::First;
      case ability::filter::Second:
        return ability == ability::Second;
      case ability::filter::Hidden:
        return ability == ability::Hidden;
    }

    return false;
  }

  bool checkIfPassesFilters(std::shared_ptr<RaidSearchSettings> searchSettings, std::shared_ptr<RaidPokemon> raid) {
    return checkFlawlessIVs(searchSettings->getFlawlessIVFilter(), raid)
        && checkShinyType(searchSettings->getShinyTypeFilter(), raid) && checkAbility(searchSettings->getAbilityFilter(), raid);
  }

  void calculateRaidPKMList(std::shared_ptr<RaidSearchSettings> searchSettings,
                            std::function<void(std::shared_ptr<RaidPokemon> raid, u32 advance)> callback) {
    u64 nextSeed = searchSettings->getSeed();
    u32 advancesToSearch = searchSettings->getAdvancesToSearch();
    auto encounter = searchSettings->getRaidEncounter();

    for (u32 advance = 0; advance < advancesToSearch; advance++) {
      auto raid = std::make_shared<RaidPokemon>(nextSeed, encounter);
      nextSeed = rng::xoroshiro(nextSeed).nextulong();

      if (checkIfPassesFilters(searchSettings, raid))
        callback(raid, advance);
    }
  }
}  // namespace csight::raid