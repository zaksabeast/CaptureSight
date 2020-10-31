#include <borealis.hpp>
#include <csight/core>
#include <memory>
#include <string>

namespace utils {
  std::string getPokemonIconPath(std::shared_ptr<csight::pkm::PKM> pkm) {
    auto speciesNum = pkm->getSpecies();
    auto isEgg = pkm->getIsEgg();
    auto formNum = pkm->getForm();
    std::string species = isEgg || speciesNum == 0 ? "0-1" : std::to_string(speciesNum);
    std::string form = formNum > 0 ? "-" + std::to_string(formNum) : "";
    std::string shiny = (pkm->getIsShiny() && !isEgg && speciesNum != 0) ? "s" : "";

    return BOREALIS_ASSET("pokemon-sprites/b_" + species + form + shiny + ".png");
  }

  std::string getPokemonIconPath(u16 speciesNum, u16 formNum) {
    std::string species = speciesNum == 0 ? "0-1" : std::to_string(speciesNum);
    std::string form = formNum > 0 ? "-" + std::to_string(formNum) : "";

    return BOREALIS_ASSET("pokemon-sprites/b_" + species + form + ".png");
  }
}  // utils