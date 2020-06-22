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
    virtual bool GetIsEgg() { return false; }
    u32 GetPSV() {
      u32 pid = this->GetPID();
      return ((pid >> 16 ^ (pid & 0xFFFF)) >> 4);
    }
    std::pair<type::PokemonType, type::PokemonType> GetTypes() {
      auto form = this->GetForm();
      auto species = this->GetSpecies();

      // Arceus and Silvally have the most forms with different types at 18
      std::vector<csight::type::PokemonTypeSet> filteredList(18);
      auto endIterator = std::copy_if(type::pokemonTypeList.begin(), type::pokemonTypeList.end(), filteredList.begin(),
                                      [species](auto type) { return type.species == species; });

      filteredList.resize(std::distance(filteredList.begin(), endIterator));

      auto resultIterator
          = std::find_if(filteredList.begin(), filteredList.end(), [form](auto type) { return type.form == form; });
      auto result = resultIterator[0];

      return std::make_pair(result.type1, result.type2);
    }
    std::vector<type::TypeMultiplier> GetWeaknesses() {
      auto types = this->GetTypes();
      auto typeMatchUps = utils::calculateWeakness(types.first, types.second);
      std::sort(typeMatchUps.begin(), typeMatchUps.end(),
                [](auto type1, auto type2) { return type1.multiplier > type2.multiplier; });

      return typeMatchUps;
    }
    std::string GetDisplayIVs() { return csight::utils::joinNums(this->GetIVs(), "/"); }
    u8 GetFlawlessIVCount() {
      u8 flawlessIVs = 0;
      auto ivs = this->GetIVs();

      for (u8 i = 0; i < 6; i++) {
        if (ivs[i] == 31) {
          flawlessIVs++;
        }
      }

      return flawlessIVs;
    }
  };
}  // namespace csight