#pragma once

#include <string>
#include <switch.h>
#include <utility>
#include <vector>

namespace csight::enums {
  enum PokemonType {
    NoType,
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
}
