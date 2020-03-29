#pragma once

#include <vector>
#include <switch.h>
#include <csight/Shiny.hpp>
#include <csight/Ability.hpp>

namespace csight::raid {
  class RaidPokemon {
   public:
    RaidPokemon(u64 seed, u32 flawlessIvs, u16 species, ability::raid::AbilityRaidSetting abilitySetting);
    u32 GetEC();
    u32 GetPID();
    u16 GetSpecies();
    std::string GetSpeciesString();
    bool GetIsShiny();
    shiny::ShinyType GetShinyType();
    std::vector<u8> GetIVs();
    ability::Ability GetAbility();
    std::string GetAbilityString();

   private:
    u32 m_EC;
    u32 m_PID;
    u16 m_species;
    std::vector<u8> m_IVs;
    shiny::ShinyType m_shineType;
    ability::Ability m_ability = ability::First;
  };
}  // namespace csight::raid