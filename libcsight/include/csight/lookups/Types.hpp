#pragma once

#include <string>
#include <switch.h>
#include <utility>
#include <vector>

namespace csight::type {
  enum PokemonType {
    None,
    Normal,
    Fighting,
    Flying,
    Poison,
    Ground,
    Rock,
    Bug,
    Ghost,
    Steel,
    Fire,
    Water,
    Grass,
    Electric,
    Psychic,
    Ice,
    Dragon,
    Dark,
    Fairy,
  };

  struct TypeMultiplier {
    PokemonType type;
    float multiplier;
  };

  struct PokemonTypeSet {
    u16 species;
    u8 form;
    PokemonType type1;
    PokemonType type2;
  };

  extern std::vector<std::string> TypeNames;

  extern std::vector<PokemonTypeSet> PokemonTypeList;
}