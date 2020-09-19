#pragma once

namespace csight::game::swsh {
  enum AbilityRaidSetting {
    First = 1,
    Second = 2,
    FirstOrSecond = 3,
    Any = 4,
  };

  enum ShinyRaidSetting {
    Random = 0,
    ForcedNonShiny = 1,
    ForcedShiny = 2,
  };
}
