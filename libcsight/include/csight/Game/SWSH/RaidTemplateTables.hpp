#pragma once

#include <csight/Enums/Ability.hpp>
#include <csight/Game/SWSH/RaidSettings.hpp>
#include <switch.h>
#include <vector>

namespace csight::game::swsh {
  struct RaidEncounter {
    u32 species;
    u32 flawlessIVs;
    AbilityRaidSetting ability;
    u16 form;
    std::vector<u32> probabilities;
    ShinyRaidSetting shinyType;
  };

  struct RaidEncounterTable {
    u64 hash;
    std::vector<RaidEncounter> templates;
  };

  RaidEncounterTable findRaidEncounterTable(std::vector<RaidEncounterTable> encounterTables, u32 denId, bool isRare);
}
