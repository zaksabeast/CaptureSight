#include <csight/core>
#include <pu/Plutonium>
#include <ui/PokemonSprite.hpp>

void setPokemonSprite(pu::ui::elm::Image::Ref sprite, u8 scale, std::shared_ptr<csight::PKM> pkm) {
  std::string spritePath = getPokemonIconPath(pkm);

  sprite->SetImage(spritePath);
  sprite->SetHeight(sprite->GetHeight() * scale);
  sprite->SetWidth(sprite->GetWidth() * scale);
}

std::string getPokemonIconPath(std::shared_ptr<csight::PKM> pkm) {
  auto speciesNum = pkm->GetSpecies();
  auto isEgg = pkm->GetIsEgg();
  auto formNum = pkm->GetForm();
  std::string species = isEgg ? "0-1" : std::to_string(speciesNum);
  std::string form = formNum > 0 ? "-" + std::to_string(formNum) : "";
  std::string shiny = (pkm->GetIsShiny() && !isEgg && speciesNum != 0) ? "s" : "";

  return "romfs:/pokemon-sprites/b_" + species + form + shiny + ".png";
}