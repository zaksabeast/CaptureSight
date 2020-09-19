#pragma once

#include <algorithm>
#include <csight/Enums/ShinyType.hpp>
#include <csight/Enums/Types.hpp>
#include <csight/Resources/Abilities.hpp>
#include <csight/Resources/Types.hpp>
#include <csight/Utils.hpp>
#include <future>
#include <string>
#include <switch.h>
#include <vector>

namespace csight::pkm {
  class PKM {
   public:
    virtual u16 getSpecies() = 0;
    virtual std::vector<u8> getIVs() = 0;
    virtual enums::Ability getAbility() = 0;
    virtual u32 getPID() = 0;
    virtual u32 getSIDTID() = 0;
    virtual u64 getRaidSeed() = 0;
    virtual u16 getForm() = 0;
    virtual bool getIsEgg() = 0;

    u16 getTSV();

    enums::ShinyType getShinyType();

    bool getIsShiny();

    std::string getSpeciesString();

    std::string getAbilityString();

    std::pair<enums::PokemonType, enums::PokemonType> getTypes();

    std::vector<enums::TypeMultiplier> getWeaknesses();

    std::string getDisplayIVs();

    u8 getFlawlessIVCount();
  };
}
