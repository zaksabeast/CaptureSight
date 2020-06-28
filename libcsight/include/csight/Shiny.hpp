#pragma once

#include <memory>
#include <switch.h>

namespace csight::shiny {
  enum ShinyType { None, Star, Square, Any };

  struct ShinyAdvance {
    u32 advances;
    ShinyType type;
  };

  u32 getShinyValue(u32 value);

  ShinyType getShinyType(u32 PID, u32 SIDTID);

  std::shared_ptr<ShinyAdvance> calculateShinyDetails(u64 seed, u32 maxAdvances);
}  // namespace csight::shiny