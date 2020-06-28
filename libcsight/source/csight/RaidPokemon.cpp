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
  RaidPokemon::RaidPokemon(u64 seed, RaidEncounter spawn) : PKM::PKM() {
    m_seed = seed;
    m_spawn = spawn;
    auto rng = rng::xoroshiro(m_seed);
    m_EC = rng.next(0xFFFFFFFF);
    u32 SIDTID = rng.next(0xFFFFFFFF);
    m_PID = rng.next(0xFFFFFFFF);
    m_shineType = shiny::getShinyType(m_PID, SIDTID);

    m_IVs = { EMPTY_IV, EMPTY_IV, EMPTY_IV, EMPTY_IV, EMPTY_IV, EMPTY_IV };

    for (u32 i = 0; i < m_spawn.flawlessIVs; i++) {
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
    switch (m_spawn.ability) {
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

  u32 RaidPokemon::getEC() { return m_EC; }

  u32 RaidPokemon::getPID() { return m_PID; }

  u16 RaidPokemon::getSpecies() { return m_spawn.species; }

  std::string RaidPokemon::getSpeciesString() { return utils::getSpeciesName(this->getSpecies()); }

  bool RaidPokemon::getIsShiny() { return m_shineType > shiny::None; }

  shiny::ShinyType RaidPokemon::getShinyType() { return m_shineType; }

  std::vector<u8> RaidPokemon::getIVs() { return m_IVs; }

  ability::Ability RaidPokemon::getAbility() { return m_ability; };

  std::string RaidPokemon::getAbilityString() { return ability::getAbilityString(m_ability); }

  u64 RaidPokemon::getRaidSeed() { return m_seed; }

  u16 RaidPokemon::getForm() { return m_spawn.form; }
}  // namespace csight::raid