#pragma once

#include <vector>
#include <switch.h>

namespace csight {
  namespace raid {
    struct RaidEncounter {
      u32 species;
      u32 flawlessIVs;
      u32 probabilities[5];
    };

    struct RaidEncounterTable {
      u64 hash;
      std::vector<RaidEncounter> templates;
    };

    extern std::vector<RaidEncounterTable> swordEncounterTables;

    extern std::vector<RaidEncounterTable> shieldEncounterTables;
  }  // namespace raid
}  // namespace csight