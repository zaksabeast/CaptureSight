#include <string>
#include <csight/Ability.hpp>

namespace csight::ability {
  std::string GetAbilityFilterString(filter::AbilityFilter filter) {
    switch (filter) {
      case filter::First:
        return "1";
      case filter::Second:
        return "2";
      case filter::Hidden:
        return "H";
      case filter::Any:
        return "Any";
      default:
      case filter::None:
        return "None";
    }
  }

  std::string GetAbilityRaidSettingString(raid::AbilityRaidSetting setting) {
    switch (setting) {
      case raid::First:
        return "1";
      case raid::Second:
        return "2";
      case raid::FirstOrSecond:
        return "1/2";
      default:
      case raid::Any:
        return "1/2/H";
    }
  }

  std::string GetAbilityString(Ability ability) {
    switch (ability) {
      case Hidden:
        return "H";
      case Second:
        return "2";
      default:
      case First:
        return "1";
    }
  }
}  // namespace csight::ability