#pragma once

#include <csight/core>
#include <pu/Plutonium>
#include <vector>

class PokemonTypeLayout : public pu::ui::Layout {
 public:
  PU_SMART_CTOR(PokemonTypeLayout)
  void SetTypeMatchUps(std::vector<csight::type::TypeMultiplier> matchUps);

 private:
  void AddMatchUpText(std::vector<csight::type::TypeMultiplier> matchUps, std::string matchUpName, u32 x, u32 y);
};