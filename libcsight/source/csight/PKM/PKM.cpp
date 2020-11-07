#include <algorithm>
#include <csight/Enums/ShinyType.hpp>
#include <csight/Enums/Types.hpp>
#include <csight/PKM/PKM.hpp>
#include <csight/Resources/Abilities.hpp>
#include <csight/Resources/Moves.hpp>
#include <csight/Resources/Natures.hpp>
#include <csight/Resources/Types.hpp>
#include <csight/Utils.hpp>
#include <future>
#include <string>
#include <switch.h>
#include <vector>

namespace csight::pkm {
  u16 PKM::getTSV() { return utils::getShinyValue(this->getSIDTID()); }

  enums::ShinyType PKM::getShinyType() { return utils::getShinyType(this->getPID(), this->getSIDTID()); }

  bool PKM::getIsShiny() { return this->getShinyType() != enums::ShinyType::None; }

  std::string PKM::getSpeciesString() { return utils::getSpeciesName(this->getSpecies()); }

  std::string PKM::getAbilityString() { return utils::getIndex(resources::Abilities, this->getAbility()); }

  std::string PKM::getMoveString(u8 slot) { return utils::getIndex(resources::MovesList, this->getMove(slot)); }

  std::string PKM::getNatureString() { return utils::getIndex(resources::NatureList, this->getNature()); }

  std::string PKM::getShinyTypeString() { return utils::getShinyTypeString(this->PKM::getShinyType()); }

  std::string PKM::getAbilitySlotString() {
    switch (this->getAbilitySlot()) {
      case enums::Ability::First:
        return "1";
      case enums::Ability::Second:
        return "2";
      default:
      case enums::Ability::Hidden:
        return "H";
    }
  }

  std::pair<enums::PokemonType, enums::PokemonType> PKM::getTypes() {
    auto form = this->getForm();
    auto species = this->getSpecies();

    return utils::getPokemonTypes(species, form);
  }

  std::vector<enums::TypeMultiplier> PKM::getWeaknesses() {
    auto types = this->getTypes();
    auto typeMatchUps = utils::calculateWeakness(types.first, types.second);
    std::sort(typeMatchUps.begin(), typeMatchUps.end(),
              [](auto type1, auto type2) { return type1.multiplier > type2.multiplier; });

    return typeMatchUps;
  }

  std::string PKM::getDisplayIVs() { return utils::joinNums(this->getIVs(), "/"); }

  u8 PKM::getFlawlessIVCount() {
    u8 flawlessIVs = 0;
    auto ivs = this->getIVs();

    for (u8 i = 0; i < 6; i++) {
      if (ivs[i] == 31) {
        flawlessIVs++;
      }
    }

    return flawlessIVs;
  }
}
