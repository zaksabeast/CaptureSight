#pragma once

#include <pu/Plutonium>

void setPokemonSprite(pu::ui::elm::Image::Ref sprite, u8 scale, u16 species, bool isEgg);
std::string getPokemonIconPath(u16 species, bool isEgg);