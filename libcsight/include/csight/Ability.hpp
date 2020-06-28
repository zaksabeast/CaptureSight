#pragma once

#include <string>

namespace csight::ability {
  enum Ability {
    First = 0,
    Second = 1,
    Hidden = 2,
  };
  namespace filter {
    enum AbilityFilter {
      First,
      Second,
      Hidden,
      None,
      Any,
    };
  }  // namespace filter

  namespace raid {
    enum AbilityRaidSetting {
      First = 1,
      Second = 2,
      FirstOrSecond = 3,
      Any = 4,
    };
  }  // namespace raid

  std::string getAbilityString(Ability ability);
  std::string getAbilityFilterString(filter::AbilityFilter filter);
  std::string getAbilityRaidSettingString(raid::AbilityRaidSetting setting);
}  // namespace csight::ability