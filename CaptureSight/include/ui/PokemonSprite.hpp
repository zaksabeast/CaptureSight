#pragma once

#include <csight/core>
#include <pu/Plutonium>

void setPokemonSprite(pu::ui::elm::Image::Ref sprite, u8 scale, std::shared_ptr<csight::PKM> pkm);
std::string getPokemonIconPath(std::shared_ptr<csight::PKM> pkm);