#pragma once

#include <algorithm>
#include <csight/Utils.hpp>
#include <csight/lookups/Types.hpp>
#include <future>
#include <string>
#include <switch.h>
#include <vector>

namespace csight {
  class PKM {
   public:
    virtual u16 GetSpecies() = 0;
    virtual std::string GetSpeciesString() = 0;
    virtual std::vector<u8> GetIVs() = 0;
    virtual bool GetIsShiny() = 0;
    virtual ability::Ability GetAbility() = 0;
    virtual std::string GetAbilityString() = 0;
    virtual u32 GetPID() = 0;
    virtual u64 GetRaidSeed() = 0;
    virtual u16 GetForm() = 0;
    u32 GetPSV() {
      u32 pid = this->GetPID();
      return ((pid >> 16 ^ (pid & 0xFFFF)) >> 4);
    }
    std::pair<type::PokemonType, type::PokemonType> GetTypes() {
      auto form = this->GetForm();
      auto species = this->GetSpecies();
      auto resultIterator = std::find_if(type::PokemonTypeList.begin(), type::PokemonTypeList.end(),
                                         [species, form](auto type) { return type.species == species && type.form == form; });
      auto result = resultIterator[0];

      return std::make_pair(result.type1, result.type2);
    }
    std::vector<type::TypeMultiplier> GetTypeMatchUps(bool shouldGetWeakness) {
      auto types = this->GetTypes();
      auto calculateTypeMatchUps = shouldGetWeakness ? utils::calculateWeakness : utils::calculateStrengths;
      auto typeMatchUps = calculateTypeMatchUps(types.first, types.second);
      std::sort(typeMatchUps.begin(), typeMatchUps.end(),
                [](auto type1, auto type2) { return type1.multiplier > type2.multiplier; });

      return typeMatchUps;
    }
  };
}  // namespace csight