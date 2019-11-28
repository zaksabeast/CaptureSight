#include <pu/Plutonium>
#include <ui/PokemonSprite.hpp>

pu::ui::elm::Image::Ref createPokemonSprite(s32 x, s32 y, u8 scale, u16 species, bool isEgg) {
  std::string spritePath = getPokemonIconPath(species);
  pu::ui::elm::Image::Ref sprite = pu::ui::elm::Image::New(0, 0, spritePath);

  sprite->SetHeight(sprite->GetHeight() * scale);
  sprite->SetWidth(sprite->GetWidth() * scale);

  return sprite;
}

std::string getPokemonIconPath(u16 species) {
  return "romfs:/pokemon-sprites/b_" + std::to_string(species) + ".png";
}