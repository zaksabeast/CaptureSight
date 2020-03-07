#include <pu/Plutonium>
#include <ui/PokemonSprite.hpp>

void setPokemonSprite(pu::ui::elm::Image::Ref sprite, u8 scale, u16 species, bool isEgg, bool isShiny) {
  std::string spritePath = getPokemonIconPath(species, isEgg, isShiny);

  sprite->SetImage(spritePath);
  sprite->SetHeight(sprite->GetHeight() * scale);
  sprite->SetWidth(sprite->GetWidth() * scale);
}

std::string getPokemonIconPath(u16 species, bool isEgg, bool isShiny) {
  std::string icon = isEgg ? "0-1" : std::to_string(species);
  std::string s = (isShiny && !isEgg) ? "s" : "";
  return "romfs:/pokemon-sprites/b_" + icon + s + ".png";
}