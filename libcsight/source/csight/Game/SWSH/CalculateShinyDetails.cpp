#include <csight/Enums/ShinyType.hpp>
#include <csight/Game/SWSH/CalculateShinyDetails.hpp>
#include <csight/Game/SWSH/RaidSettings.hpp>
#include <csight/RNG/RNG.hpp>
#include <csight/Utils.hpp>
#include <memory>
#include <switch.h>
#include <vector>

namespace csight::game::swsh {
  std::shared_ptr<ShinyAdvance> calculateShinyDetails(u64 seed, u32 maxAdvances, ShinyRaidSetting raidShinyType) {
    u16 shinyAdvance = 0;
    enums::ShinyType shineType = enums::ShinyType::None;

    while (shinyAdvance < maxAdvances) {
      auto rng = rng::xoroshiro(seed);
      seed = rng.nextulong();  // Also advance for EC
      u32 SIDTID = rng.nextuint();
      u32 PID = rng.nextuint();
      shineType = utils::getShinyType(PID, SIDTID);
      if (shineType > enums::ShinyType::None)
        break;
      else
        shinyAdvance++;
    }

    // Thanks to
    // https://github.com/Leanny/PKHeX_Raid_Plugin/blob/8383d8ed7a51e9fe86a80d45c56386137c67380c/PKHeX_Raid_Plugin/Raid/RaidTemplate.cs#L151
    if (raidShinyType == ShinyRaidSetting::ForcedShiny) {
      shineType = enums::ShinyType::Square;
      shinyAdvance = 0;
    } else if (raidShinyType == ShinyRaidSetting::ForcedNonShiny) {
      shineType = enums::ShinyType::None;
      shinyAdvance = maxAdvances;
    }

    return std::make_shared<ShinyAdvance>(ShinyAdvance { advances : shinyAdvance, type : shineType });
  }
}
