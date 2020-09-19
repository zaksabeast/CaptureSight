#include <csight/Enums/Ability.hpp>
#include <csight/Game/GameReader.hpp>
#include <csight/Game/SWSH/DenHashes.hpp>
#include <csight/Game/SWSH/NestHoleDistributionEncounter8Archive_generated.h>
#include <csight/Game/SWSH/RaidSettings.hpp>
#include <csight/Game/SWSH/SWSHGame.hpp>
#include <csight/PKM/PK8.hpp>
#include <csight/TitleIds.hpp>
#include <memory>
#include <switch.h>

namespace csight::game::swsh {
  u64 GetEventFlatbufferOffset() {
    u64 languageCode = 0;
    SetLanguage language = SetLanguage_ENUS;
    setGetSystemLanguage(&languageCode);
    setMakeLanguage(languageCode, &language);

    switch (language) {
      case SetLanguage_ZHCN:
      case SetLanguage_ZHHANS:
        return 0x2F9EA3F0;
      case SetLanguage_ZHTW:
      case SetLanguage_ZHHANT:
        return 0x2F9EA390;
      case SetLanguage_KO:
        return 0x2F9EA7F0;
      case SetLanguage_IT:
        return 0x2F9EB170;
      case SetLanguage_JA:
        return 0x2F9EB350;
      case SetLanguage_FR:
      case SetLanguage_FRCA:
        return 0x2F9EB3E0;
      case SetLanguage_ES:
      case SetLanguage_ES419:
        return 0x2F9EB3B0;
      case SetLanguage_DE:
        return 0x2F9EB4C0;
      case SetLanguage_PT:
      case SetLanguage_RU:
      case SetLanguage_NL:
      case SetLanguage_ENUS:
      case SetLanguage_ENGB:
      default:
        return 0x2F9EB1F0;
    }
  }

  SWSHGame::SWSHGame(bool shouldUseSmallMemoryMode) : GameReader<pkm::PK8>(shouldUseSmallMemoryMode) {
    m_shouldUseSmallMemoryMode = shouldUseSmallMemoryMode;
    m_eventFlatbufferOffset = GetEventFlatbufferOffset();
  }

  std::shared_ptr<Den> SWSHGame::readDen(u8 denId) {
    u8 *denBytes = new u8[0x18];
    std::vector<RaidEncounterTable> encounterTables;
    std::shared_ptr<RaidEncounterTable> eventTemplateTable;
    std::vector<RaidEncounter> templates = {
      {
        species : 0,
        flawlessIVs : 1,
        ability : csight::game::swsh::AbilityRaidSetting::FirstOrSecond,
        form : 0,
        probabilities : { 35, 0, 0, 0, 0 },
        shinyType : ShinyRaidSetting::Random
      },
    };

    if (m_shouldUseSmallMemoryMode) {
      encounterTables = { { hash : 0u, templates : templates } };
      eventTemplateTable = std::make_shared<RaidEncounterTable>(RaidEncounterTable { hash : 0u, templates : templates });
    } else {
      encounterTables = this->getEncounterTables();
      eventTemplateTable = this->readEventEncounterTable();
    }

    // Account for Isle of Armor offset
    u64 shiftedDenId = denId >= FIRST_IOA_DEN_ID ? denId + 11 : denId;
    this->readHeap(m_denOffset + (shiftedDenId * 0x18), denBytes, 0x18);

    auto den = std::make_shared<Den>(denBytes, denId, encounterTables, eventTemplateTable, this->getTrainerSIDTID());

    delete[] denBytes;
    return den;
  }

  std::vector<std::shared_ptr<Den>> SWSHGame::readDens(bool shouldReadAllDens) {
    std::vector<std::shared_ptr<Den>> dens;

    for (u32 i = 0; i < DEN_LIST_SIZE; i++) {
      auto den = this->readDen(i);
      if (shouldReadAllDens || den->getIsActive()) {
        dens.push_back(den);
      }
    }

    return dens;
  }

  std::vector<RaidEncounterTable> SWSHGame::getEncounterTables() {
    if (this->getTitleId() == SWORD_TITLE_ID) {
      return getSwordEncounterTables();
    }

    return getShieldEncounterTables();
  }

  std::shared_ptr<RaidEncounterTable> SWSHGame::readEventEncounterTable() {
    bool isPlayingSword = this->getTitleId() == SWORD_TITLE_ID;
    u32 gameVersion = isPlayingSword ? 1 : 2;
    std::vector<RaidEncounter> raidEncounters;
    auto encounterTable = std::make_shared<RaidEncounterTable>(RaidEncounterTable { eventHash, raidEncounters });
    u32 eventFlatbufferInMemorySize = 0;
    this->readHeap(m_eventFlatbufferOffset + 0x10, &eventFlatbufferInMemorySize, sizeof(u32));

    if (eventFlatbufferInMemorySize + 4 != m_eventFlatbufferSize)
      return encounterTable;

    u8 *eventFlatbuffer = new u8[m_eventFlatbufferSize];
    this->readHeap(m_eventFlatbufferOffset + 0x20, eventFlatbuffer, m_eventFlatbufferSize);
    auto eventEncounterTables = pkNX::Structures::GetNestHoleDistributionEncounter8Archive(eventFlatbuffer)->Tables();

    // Don't assume Sword will always be first
    auto tableIndex = gameVersion == eventEncounterTables->Get(0)->GameVersion() ? 0 : 1;
    auto eventTable = eventEncounterTables->Get(tableIndex);
    auto eventEncounters = eventTable->Entries();

    for (auto eventEncounter = eventEncounters->begin(); eventEncounter != eventEncounters->end(); ++eventEncounter) {
      auto eventProbabilities = eventEncounter->Probabilities();
      RaidEncounter raidEncounter = {
        species : eventEncounter->Species(),
        flawlessIVs : (u32)eventEncounter->FlawlessIVs(),
        ability : (csight::game::swsh::AbilityRaidSetting)eventEncounter->Ability(),
        form : (u16)eventEncounter->AltForm(),
        probabilities : {
            eventProbabilities->Get(0),
            eventProbabilities->Get(1),
            eventProbabilities->Get(2),
            eventProbabilities->Get(3),
            eventProbabilities->Get(4),
        },
        shinyType : (ShinyRaidSetting)eventEncounter->ShinyForced(),
      };

      encounterTable->templates.push_back(raidEncounter);
    }

    encounterTable->hash = eventTable->TableID();

    delete[] eventFlatbuffer;

    return encounterTable;
  }

  std::shared_ptr<pkm ::PK8> SWSHGame::readRaid() { return this->readPKM(m_raidOffset, pkm::PK8::PartySize); }

  std::shared_ptr<pkm ::PK8> SWSHGame::readTrade() { return this->readPKM(m_tradeOffset, pkm::PK8::PartySize); }

  u32 SWSHGame::getTrainerSIDTID() {
    u32 sidtid = 0;

    this->readHeap(m_trainerBlockOffset + 0xA0, &sidtid, sizeof(u32));
    return sidtid;
  }

  std::vector<std::shared_ptr<pkm::PK8>> SWSHGame::readParty() { return this->readPKMs(m_partyOffset, 6, pkm::PK8::PartySize); }

  std::vector<std::shared_ptr<pkm::PK8>> SWSHGame::readBoxes() { return this->readPKMs(m_boxOffset, 960, pkm::PK8::PartySize); }

  std::shared_ptr<pkm::PK8> SWSHGame::readWild() {
    auto pkm = this->readPKM(m_wildOffset, pkm::PK8::PartySize);
    return pkm->getIsValid() ? pkm : this->readPKM(m_legendOffset, pkm::PK8::PartySize);
  }
}
