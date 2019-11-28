#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <utils/I18N.hpp>

// Fake i18n to store Pokemon names and moves until an actual implementation happens
I18N::I18N() {
  this->LoadList("romfs:/pokemon-species.txt", this->pokemonSpecies);
  this->LoadList("romfs:/pokemon-moves.txt", this->pokemonMoves);
}

void I18N::LoadList(std::string path, std::vector<std::string>& res) {
  std::ifstream speciesFile(path);

  if (speciesFile.good()) {
    std::string line;
    while (std::getline(speciesFile, line)) {
      res.push_back(line);
    }
  }

  speciesFile.close();
}

std::string I18N::GetPokemonName(u16 species) {
  return species > this->pokemonSpecies.size() ? this->pokemonSpecies[0] : this->pokemonSpecies[species];
}

std::string I18N::GetPokemonMoveName(u16 move) {
  return move > this->pokemonMoves.size() ? this->pokemonMoves[0] : this->pokemonMoves[move];
}
