#pragma once

#include <vector>
#include <switch.h>

namespace csight {
  namespace raid {
    struct RaidTemplate {
      u32 species;
      u32 flawlessIVs;
      u32 probabilities[5];
    };

    struct RaidTemplateTable {
      u64 hash;
      std::vector<RaidTemplate> templates;
    };

    extern std::vector<RaidTemplateTable> swordNests;

    extern std::vector<RaidTemplateTable> shieldNests;
  }  // namespace raid
}  // namespace csight