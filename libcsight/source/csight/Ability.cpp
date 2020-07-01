#include <csight/Ability.hpp>
#include <string>

namespace csight::ability {
  std::string getAbilityString(Ability ability) {
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