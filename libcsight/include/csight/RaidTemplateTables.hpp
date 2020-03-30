#pragma once

#include <csight/Ability.hpp>
#include <switch.h>
#include <vector>

namespace csight::raid {
  struct RaidEncounter {
    u32 species;
    u32 flawlessIVs;
    ability::raid::AbilityRaidSetting ability;
    std::vector<u32> probabilities;
  };

  struct RaidEncounterTable {
    u64 hash;
    std::vector<RaidEncounter> templates;
  };

  extern std::vector<RaidEncounterTable> swordEncounterTables;

  extern std::vector<RaidEncounterTable> shieldEncounterTables;
}  // namespace csight::raid