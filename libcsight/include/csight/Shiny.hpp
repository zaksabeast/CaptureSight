#pragma once

#include <memory>
#include <switch.h>

namespace csight::shiny {
  enum ShinyType { None, Star, Square, Any };

  enum ShinyRaidSetting {
    Random = 0,
    ForcedNonShiny = 1,
    ForcedShiny = 2,
  };

  struct ShinyAdvance {
    u32 advances;
    ShinyType type;
  };

  u32 getShinyValue(u32 value);

  ShinyType getShinyType(u32 PID, u32 SIDTID);

  std::shared_ptr<ShinyAdvance> calculateShinyDetails(u64 seed, u32 maxAdvances,
                                                      ShinyRaidSetting raidShinyType = ShinyRaidSetting::Random);
}  // namespace csight::shiny