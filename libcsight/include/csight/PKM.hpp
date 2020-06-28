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
    virtual u16 getSpecies() = 0;
    virtual std::string getSpeciesString() = 0;
    virtual std::vector<u8> getIVs() = 0;
    virtual bool getIsShiny() = 0;
    virtual ability::Ability getAbility() = 0;
    virtual std::string getAbilityString() = 0;
    virtual u32 getPID() = 0;
    virtual u64 getRaidSeed() = 0;
    virtual u16 getForm() = 0;
    virtual bool getIsEgg() { return false; }

    u32 getPSV() {
      u32 pid = this->getPID();
      return ((pid >> 16 ^ (pid & 0xFFFF)) >> 4);
    }

    std::pair<type::PokemonType, type::PokemonType> getTypes() {
      auto form = this->getForm();
      auto species = this->getSpecies();

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

    std::vector<type::TypeMultiplier> getWeaknesses() {
      auto types = this->getTypes();
      auto typeMatchUps = utils::calculateWeakness(types.first, types.second);
      std::sort(typeMatchUps.begin(), typeMatchUps.end(),
                [](auto type1, auto type2) { return type1.multiplier > type2.multiplier; });

      return typeMatchUps;
    }

    std::string getDisplayIVs() { return csight::utils::joinNums(this->getIVs(), "/"); }

    u8 getFlawlessIVCount() {
      u8 flawlessIVs = 0;
      auto ivs = this->getIVs();

      for (u8 i = 0; i < 6; i++) {
        if (ivs[i] == 31) {
          flawlessIVs++;
        }
      }

      return flawlessIVs;
    }
  };
}  // namespace csight