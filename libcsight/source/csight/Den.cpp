#include <csight/Ability.hpp>
#include <csight/Config.hpp>
#include <csight/Den.hpp>
#include <csight/DenHashes.hpp>
#include <csight/RNG.hpp>
#include <csight/Utils.hpp>
#include <fstream>
#include <stdio.h>

namespace csight::raid {
  // Pass the den encounter tables to use since its responsibility is to parse the den data, not read/choose encounter tables
  Den::Den(u8 *data, u8 denId, std::vector<RaidEncounterTable> encounterTables,
           std::shared_ptr<RaidEncounterTable> eventEncounterTable) {
    std::copy(data, data + m_size, m_data);

    m_denId = denId > DEN_LIST_SIZE ? DEN_LIST_SIZE : denId;

    if (this->getIsEvent()) {
      m_spawn = this->findSpawn(eventEncounterTable->templates);
    } else {
      auto nest = utils::findRaidEncounterTable(encounterTables, m_denId, this->getIsRare());
      m_spawn = this->findSpawn(nest.templates);
    }

    auto shinyDetails = csight::shiny::calculateShinyDetails(this->getSeed(), MAX_RAID_ADVANCES);

    m_shinyAdvance = shinyDetails->advances;
    m_shineType = shinyDetails->type;
  }

  Den::~Den() { delete[] m_data; }

  u64 Den::getSeed() { return *(u64 *)(m_data + 0x8); }

  u16 Den::getShinyAdvance() { return m_shinyAdvance; }

  std::string Den::getShinyAdvanceText() { return utils::getRaidShinyAdvanceText(m_shinyAdvance, MAX_RAID_ADVANCES); }

  shiny::ShinyType Den::getShinyType() { return m_shineType; }

  u8 Den::getStars() { return *(u8 *)(m_data + 0x10); }

  u8 Den::getDisplayStars() { return this->getStars() + 1; }

  u8 Den::getRandRoll() { return *(u8 *)(m_data + 0x11); }

  u8 Den::getType() { return *(u8 *)(m_data + 0x12); }

  bool Den::getIsRare() {
    u8 type = this->getType();
    return type > 0 && (type & 1) == 0;
  }

  u8 Den::getFlagByte() { return *(u8 *)(m_data + 0x13); }

  bool Den::getHasWatts() { return (this->getFlagByte() & 1) == 0; }

  bool Den::getIsEvent() { return (this->getFlagByte() >> 1) & 1; }

  bool Den::getIsActive() { return this->getType() > 0; }

  u8 Den::getDenId() { return m_denId; }

  std::string Den::getDenDisplayName() {
    u8 displayId = m_denId + 1;
    if (this->getDenType() == Vanilla) {
      return "[Vanilla " + std::to_string(displayId) + "]";
    } else {
      return "[IoA " + std::to_string(displayId - FIRST_IOA_DEN_ID) + "]";
    }
  }

  std::shared_ptr<RaidPokemon> Den::getPKM() { return std::make_shared<RaidPokemon>(this->getSeed(), m_spawn); };

  DenType Den::getDenType() { return m_denId >= FIRST_IOA_DEN_ID ? IsleOfArmor : Vanilla; }

  RaidEncounter Den::findSpawn(std::vector<RaidEncounter> raidEncounters) {
    u32 userProbability = 1;
    auto stars = this->getStars();
    auto randRoll = this->getRandRoll();

    for (auto raidEncounter : raidEncounters) {
      auto nestProbability = raidEncounter.probabilities[stars];
      userProbability += nestProbability;

      if (userProbability > randRoll) {
        return raidEncounter;
      }
    }

    return {
      species : 0,
      flawlessIVs : 1,
      ability : ability::raid::FirstOrSecond,
      form : 0,
      probabilities : { 0, 0, 0, 0, 0 },
    };
  }
}  // namespace csight::raid