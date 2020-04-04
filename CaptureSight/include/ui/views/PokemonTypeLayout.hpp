#pragma once

#include <csight/core>
#include <pu/Plutonium>
#include <vector>

class PokemonTypeLayout : public pu::ui::Layout {
 public:
  PU_SMART_CTOR(PokemonTypeLayout)
  void SetTypeMatchUps(std::vector<csight::type::TypeMultiplier> defensiveMatchUps,
                       std::vector<csight::type::TypeMultiplier> offensiveMatchUps);

 private:
  void AddMatchUpBlock(std::vector<csight::type::TypeMultiplier> matchUps, std::string header, std::string firstMatchUpName,
                       std::string secondMatchUpName, u32 baseX);
  void AddMatchUpText(std::vector<csight::type::TypeMultiplier> matchUps, std::string matchUpName, u32 x, u32 y);
};