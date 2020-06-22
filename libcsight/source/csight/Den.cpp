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

    if (this->GetIsEvent()) {
      m_spawn = this->FindSpawn(eventEncounterTable->templates);
    } else {
      auto nest = utils::findRaidEncounterTable(encounterTables, m_denId, this->GetIsRare());
      m_spawn = this->FindSpawn(nest.templates);
    }

    auto shinyDetails = csight::shiny::CalculateShinyDetails(this->GetSeed(), MAX_RAID_ADVANCES);

    m_shinyAdvance = shinyDetails->advances;
    m_shineType = shinyDetails->type;
  }

  Den::~Den() { delete[] m_data; }

  u64 Den::GetSeed() { return *(u64 *)(m_data + 0x8); }

  u16 Den::GetShinyAdvance() { return m_shinyAdvance; }

  std::string Den::GetShinyAdvanceText() { return utils::getRaidShinyAdvanceText(m_shinyAdvance, MAX_RAID_ADVANCES); }

  shiny::ShinyType Den::GetShinyType() { return m_shineType; }

  u8 Den::GetStars() { return *(u8 *)(m_data + 0x10); }

  u8 Den::GetDisplayStars() { return this->GetStars() + 1; }

  u8 Den::GetRandRoll() { return *(u8 *)(m_data + 0x11); }

  u8 Den::GetType() { return *(u8 *)(m_data + 0x12); }

  bool Den::GetIsRare() {
    u8 type = this->GetType();
    return type > 0 && (type & 1) == 0;
  }

  u8 Den::GetFlagByte() { return *(u8 *)(m_data + 0x13); }

  bool Den::GetHasWatts() { return (this->GetFlagByte() & 1) == 0; }

  bool Den::GetIsEvent() { return (this->GetFlagByte() >> 1) & 1; }

  bool Den::GetIsActive() { return this->GetType() > 0; }

  u8 Den::GetDenId() { return m_denId; }

  std::string Den::GetDenDisplayName() {
    u8 displayId = m_denId + 1;
    if (this->GetDenType() == Vanilla) {
      return "[Vanilla " + std::to_string(displayId) + "]";
    } else {
      return "[IoA " + std::to_string(displayId - FIRST_IOA_DEN_ID) + "]";
    }
  }

  std::shared_ptr<RaidPokemon> Den::GetPKM() { return std::make_shared<RaidPokemon>(this->GetSeed(), m_spawn); };

  DenType Den::GetDenType() { return m_denId >= FIRST_IOA_DEN_ID ? IsleOfArmor : Vanilla; }

  RaidEncounter Den::FindSpawn(std::vector<RaidEncounter> raidEncounters) {
    u32 userProbability = 1;
    auto stars = this->GetStars();
    auto randRoll = this->GetRandRoll();

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