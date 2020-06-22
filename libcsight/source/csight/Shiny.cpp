#include <csight/RNG.hpp>
#include <csight/Shiny.hpp>
#include <memory>

namespace csight::shiny {
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

  std::shared_ptr<ShinyAdvance> CalculateShinyDetails(u64 seed, u32 maxAdvances) {
    u16 shinyAdvance = 0;
    csight::shiny::ShinyType shineType = csight::shiny::ShinyType::None;

    while (shinyAdvance < maxAdvances) {
      auto rng = csight::rng::xoroshiro(seed);
      seed = rng.nextulong();  // Also advance for EC
      u32 SIDTID = rng.nextuint();
      u32 PID = rng.nextuint();
      shineType = csight::shiny::GetShinyType(PID, SIDTID);
      if (shineType > csight::shiny::None)
        break;
      else
        shinyAdvance++;
    }

    return std::make_shared<ShinyAdvance>(ShinyAdvance { advances : shinyAdvance, type : shineType });
  }
}  // namespace csight::shiny