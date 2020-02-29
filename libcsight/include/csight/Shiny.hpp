#pragma once

#include <switch.h>

namespace csight::shiny {
  enum ShinyType { None, Star, Square, Any };

  u32 GetShinyValue(u32 value);
  ShinyType GetShinyType(u32 PID, u32 SIDTID);
}  // namespace csight::shiny