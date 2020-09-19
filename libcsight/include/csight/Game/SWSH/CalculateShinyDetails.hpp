#pragma once

#include <csight/Enums/ShinyType.hpp>
#include <csight/Game/SWSH/RaidSettings.hpp>
#include <memory>
#include <switch.h>
#include <vector>

namespace csight::game::swsh {
  struct ShinyAdvance {
    u32 advances;
    enums::ShinyType type;
  };

  std::shared_ptr<ShinyAdvance> calculateShinyDetails(u64 seed, u32 maxAdvances, ShinyRaidSetting raidShinyType);
}
