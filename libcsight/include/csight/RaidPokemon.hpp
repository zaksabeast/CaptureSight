#pragma once

#include <vector>
#include <switch.h>
#include <csight/Shiny.hpp>

namespace csight {
  namespace raid {
    class RaidPokemon {
     public:
      RaidPokemon(u64 seed, u32 flawlessIvs, u16 species);
      u32 GetEC();
      u32 GetPID();
      u16 GetSpecies();
      bool GetIsShiny();
      shiny::ShinyType GetShineType();
      std::vector<s8> GetIVs();

     private:
      u32 EC;
      u32 PID;
      u16 species;
      std::vector<s8> IVs;
      shiny::ShinyType shineType;
    };
  }  // namespace raid
}  // namespace csight