#pragma once

#include <csight/Ability.hpp>
#include <csight/Shiny.hpp>
#include <switch.h>
#include <vector>

namespace csight::raid {
  struct RaidEncounter {
    u32 species;
    u32 flawlessIVs;
    ability::raid::AbilityRaidSetting ability;
    u16 form;
    std::vector<u32> probabilities;
    csight::shiny::ShinyRaidSetting shinyType;
  };

  struct RaidEncounterTable {
    u64 hash;
    std::vector<RaidEncounter> templates;
  };

  std::vector<RaidEncounterTable> getSwordEncounterTables();

  std::vector<RaidEncounterTable> getShieldEncounterTables();
}  // namespace csight::raid