#pragma once

#include <pu/Plutonium>

pu::ui::elm::Image::Ref createPokemonSprite(s32 x, s32 y, u8 scale, u16 species, bool isEgg);
std::string getPokemonIconPath(u16 species, bool isEgg);