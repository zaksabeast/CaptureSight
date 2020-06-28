#pragma once

#include <csight/Ability.hpp>
#include <csight/PKM.hpp>
#include <csight/Shiny.hpp>
#include <switch.h>
#include <vector>

namespace csight::raid {
  class RaidPokemon : public PKM {
   public:
    RaidPokemon(u64 seed, RaidEncounter spawn);
    u32 getEC();
    u32 getPID();
    u16 getSpecies();
    std::string getSpeciesString();
    bool getIsShiny();
    shiny::ShinyType getShinyType();
    std::vector<u8> getIVs();
    ability::Ability getAbility();
    std::string getAbilityString();
    u64 getRaidSeed();
    u16 getForm();

   private:
    u64 m_seed;
    u32 m_EC;
    u32 m_PID;
    RaidEncounter m_spawn;
    std::vector<u8> m_IVs;
    shiny::ShinyType m_shineType;
    ability::Ability m_ability = ability::First;
  };
}  // namespace csight::raid