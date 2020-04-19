#pragma once

#include <csight/Ability.hpp>
#include <switch.h>
#include <vector>

namespace csight::raid {
  struct RaidEncounter {
    u32 species;
    u32 flawlessIVs;
    ability::raid::AbilityRaidSetting ability;
    u16 form;
    std::vector<u32> probabilities;
  };

  struct RaidEncounterTable {
    u64 hash;
    std::vector<RaidEncounter> templates;
  };

  std::vector<RaidEncounterTable> GetSwordEncounterTables();

  std::vector<RaidEncounterTable> GetShieldEncounterTables();
}  // namespace csight::raid