#include <pu/Plutonium>
#include <ui/PokemonSprite.hpp>

void setPokemonSprite(pu::ui::elm::Image::Ref sprite, u8 scale, u16 species, bool isEgg) {
  std::string spritePath = getPokemonIconPath(species, isEgg);

  sprite->SetImage(spritePath);
  sprite->SetHeight(sprite->GetHeight() * scale);
  sprite->SetWidth(sprite->GetWidth() * scale);
}

std::string getPokemonIconPath(u16 species, bool isEgg) {
  std::string icon = isEgg ? "0-1" : std::to_string(species);
  return "romfs:/pokemon-sprites/b_" + icon + ".png";
}