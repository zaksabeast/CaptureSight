#include <csight/RNG.hpp>
#include <csight/Shiny.hpp>
#include <memory>

namespace csight::shiny {
  u32 getShinyValue(u32 value) { return (value >> 16) ^ (value & 0xFFFF); }

  ShinyType getShinyType(u32 PID, u32 SIDTID) {
    u32 PSV = getShinyValue(PID);
    u32 TSV = getShinyValue(SIDTID);

    if (PSV == TSV) {
      return Square;
    }

    if ((PSV ^ TSV) < 0x10) {
      return Star;
    }

    return None;
  }

  std::shared_ptr<ShinyAdvance> calculateShinyDetails(u64 seed, u32 maxAdvances, ShinyRaidSetting raidShinyType) {
    u16 shinyAdvance = 0;
    ShinyType shineType = ShinyType::None;

    while (shinyAdvance < maxAdvances) {
      auto rng = csight::rng::xoroshiro(seed);
      seed = rng.nextulong();  // Also advance for EC
      u32 SIDTID = rng.nextuint();
      u32 PID = rng.nextuint();
      shineType = getShinyType(PID, SIDTID);
      if (shineType > None)
        break;
      else
        shinyAdvance++;
    }

    // Thanks to
    // https://github.com/Leanny/PKHeX_Raid_Plugin/blob/8383d8ed7a51e9fe86a80d45c56386137c67380c/PKHeX_Raid_Plugin/Raid/RaidTemplate.cs#L151
    if (raidShinyType == ShinyRaidSetting::ForcedShiny && shineType == ShinyType::None) {
      shineType = ShinyType::Square;
    } else if (raidShinyType == ShinyRaidSetting::ForcedNonShiny) {
      shineType = ShinyType::None;
      shinyAdvance = maxAdvances;
    }

    return std::make_shared<ShinyAdvance>(ShinyAdvance { advances : shinyAdvance, type : shineType });
  }
}  // namespace csight::shiny