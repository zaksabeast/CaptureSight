#include <csight/Ability.hpp>
#include <csight/PKM.hpp>
#include <csight/RNG.hpp>
#include <csight/RaidPokemon.hpp>
#include <csight/Shiny.hpp>
#include <csight/Utils.hpp>
#include <string>

// 255 is an unsighed integer hack
#define EMPTY_IV 255

namespace csight::raid {
  RaidPokemon::RaidPokemon(u64 seed, u32 flawlessIvs, u16 species, ability::raid::AbilityRaidSetting abilitySetting) :
      PKM::PKM() {
    m_seed = seed;
    m_species = species;
    auto rng = rng::xoroshiro(m_seed);
    m_EC = rng.next(0xFFFFFFFF);
    u32 SIDTID = rng.next(0xFFFFFFFF);
    m_PID = rng.next(0xFFFFFFFF);
    m_shineType = shiny::GetShinyType(m_PID, SIDTID);

    m_IVs = { EMPTY_IV, EMPTY_IV, EMPTY_IV, EMPTY_IV, EMPTY_IV, EMPTY_IV };

    for (u32 i = 0; i < flawlessIvs; i++) {
      s32 ivIndex;

      do {
        ivIndex = (s32)rng.next(7);
      } while (m_IVs[ivIndex] != EMPTY_IV);

      m_IVs[ivIndex] = 31;
    }

    for (s32 i = 0; i < 6; i++) {
      if (m_IVs[i] == EMPTY_IV) {
        m_IVs[i] = (u8)rng.next(31);
      }
    }

    // Thanks to
    // https://github.com/Leanny/leanny.github.io/blob/17916ebde2bc984f325f7b103865416f226492fb/seedchecker/common.js#L207
    switch (abilitySetting) {
      case ability::raid::First:
        m_ability = ability::First;
        break;
      case ability::raid::Second:
        m_ability = ability::Second;
        break;
      case ability::raid::FirstOrSecond:
        m_ability = (ability::Ability)rng.next(2, 1);
        break;
      default:
      case ability::raid::Any:
        m_ability = (ability::Ability)rng.next(3, 3);
        break;
    }
  }

  u32 RaidPokemon::GetEC() { return m_EC; }

  u32 RaidPokemon::GetPID() { return m_PID; }

  u16 RaidPokemon::GetSpecies() { return m_species; }

  std::string RaidPokemon::GetSpeciesString() { return utils::getSpeciesName(this->GetSpecies()); }

  bool RaidPokemon::GetIsShiny() { return m_shineType > shiny::None; }

  shiny::ShinyType RaidPokemon::GetShinyType() { return m_shineType; }

  std::vector<u8> RaidPokemon::GetIVs() { return m_IVs; }

  ability::Ability RaidPokemon::GetAbility() { return m_ability; };

  std::string RaidPokemon::GetAbilityString() { return ability::GetAbilityString(m_ability); }

  u64 RaidPokemon::GetRaidSeed() { return m_seed; }

  u8 RaidPokemon::GetForm() { return 0; }
}  // namespace csight::raid