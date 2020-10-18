#include <csight/Enums/Ability.hpp>
#include <csight/PKM/PKM.hpp>
#include <csight/PKM/RaidPokemon.hpp>
#include <csight/RNG/RNG.hpp>
#include <csight/Utils.hpp>
#include <string>

// 255 is an unsigned integer hack
#define EMPTY_IV 255

namespace csight::pkm {
  RaidPokemon::RaidPokemon(u64 seed, game::swsh::RaidEncounter spawn, u32 playerSIDTID) : PKM::PKM() {
    m_seed = seed;
    m_spawn = spawn;
    m_SIDTID = playerSIDTID;
    auto rng = rng::xoroshiro(m_seed);
    m_EC = rng.next(0xFFFFFFFF);
    // Shininess is determined with a fake SIDTID
    u32 fakeSIDTID = rng.next(0xFFFFFFFF);
    m_PID = rng.next(0xFFFFFFFF);
    auto naturalShinyType = utils::getShinyType(m_PID, fakeSIDTID);

    if (m_spawn.shinyType == game::swsh::ShinyRaidSetting::ForcedNonShiny) {
      m_PID ^= 0x10000000;
    } else if (m_spawn.shinyType == game::swsh::ShinyRaidSetting::ForcedShiny && naturalShinyType == enums::ShinyType::None) {
      u16 high = (m_PID & 0xffff) ^ this->getTSV();
      m_PID = (high << 16) | (m_PID & 0xffff);
    }

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
      case game::swsh::AbilityRaidSetting::First:
        m_abilitySlot = enums::Ability::First;
        break;
      case game::swsh::AbilityRaidSetting::Second:
        m_abilitySlot = enums::Ability::Second;
        break;
      case game::swsh::AbilityRaidSetting::FirstOrSecond:
        m_abilitySlot = (enums::Ability)rng.next(2, 1);
        break;
      default:
      case game::swsh::AbilityRaidSetting::Any:
        m_abilitySlot = (enums::Ability)rng.next(3, 3);
        break;
    }
  }

  u32 RaidPokemon::getEC() { return m_EC; }

  u32 RaidPokemon::getPID() { return m_PID; }

  u32 RaidPokemon::getSIDTID() { return m_SIDTID; }

  u16 RaidPokemon::getSpecies() { return m_spawn.species; }

  std::vector<u8> RaidPokemon::getIVs() { return m_IVs; }

  enums::Ability RaidPokemon::getAbilitySlot() { return m_abilitySlot; };

  u16 RaidPokemon::getAbility() {
    return utils::getAbilityOfPokemon(this->getSpecies(), this->getForm(), this->getAbilitySlot());
  }

  u64 RaidPokemon::getRaidSeed() { return m_seed; }

  u16 RaidPokemon::getForm() { return m_spawn.form; }

  bool RaidPokemon::getIsEgg() { return false; }

  // Stub for the moment
  u16 RaidPokemon::getMove(u8 slot) { return 0; }

  // Stub for the moment
  u8 RaidPokemon::getNature() { return 0; }

  bool RaidPokemon::getIsValid() { return this->getSpecies() > 0; }
}
