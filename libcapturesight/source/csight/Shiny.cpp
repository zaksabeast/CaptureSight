#include <Shiny.hpp>

namespace csight {
  u32 GetShinyValue(u32 value) { return (value >> 16) ^ (value & 0xFFFF); }

  ShinyType GetShinyType(u32 PID, u32 SIDTID) {
    u32 PSV = GetShinyValue(PID);
    u32 TSV = GetShinyValue(SIDTID);

    if (PSV == TSV) {
      return Square;
    }

    if ((PSV ^ TSV) < 0x10) {
      return Star;
    }

    return None;
  }
}  // namespace csight