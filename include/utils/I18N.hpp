#pragma once

#include <vector>
#include <string>
#include <switch.h>

class I18N {
 public:
  I18N();
  std::string GetPokemonName(u16 species);
  std::string GetPokemonMoveName(u16 move);

 private:
  std::vector<std::string> pokemonSpecies;
  std::vector<std::string> pokemonMoves;
  void LoadList(std::string path, std::vector<std::string>& res);
};
