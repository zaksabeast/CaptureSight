#include <csight/Enums/Ability.hpp>
#include <csight/Game/GameReader.hpp>
#include <csight/Game/SWSH/DenHashes.hpp>
#include <csight/Game/SWSH/EncounterNest8Archive_generated.h>
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
        return 0x2F9EA410;
      case SetLanguage_ZHTW:
      case SetLanguage_ZHHANT:
        return 0x2F9EA3B0;
      case SetLanguage_KO:
        return 0x2F9EA810;
      case SetLanguage_IT:
        return 0x2F9EB190;
      case SetLanguage_JA:
        return 0x2F9EB370;
      case SetLanguage_FR:
      case SetLanguage_FRCA:
        return 0x2F9EB400;
      case SetLanguage_ES:
      case SetLanguage_ES419:
        return 0x2F9EB3D0;
      case SetLanguage_DE:
        return 0x2F9EB4E0;
      case SetLanguage_PT:
      case SetLanguage_RU:
      case SetLanguage_NL:
      case SetLanguage_ENUS:
      case SetLanguage_ENGB:
      default:
        return 0x2F9EB350;
    }
  }

  SWSHGame::SWSHGame(bool shouldUseSmallMemoryMode) : GameReader<pkm::PK8>(shouldUseSmallMemoryMode) {
    m_shouldUseSmallMemoryMode = shouldUseSmallMemoryMode;
    m_eventFlatbufferOffset = GetEventFlatbufferOffset();
  }

  std::shared_ptr<Den> SWSHGame::readDen(u16 denId) {
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
      encounterTables = this->readEncounterTables();
      eventTemplateTable = this->readEventEncounterTable();
    }

    u64 shiftedOffset = m_denOffset;

    if (denId >= FIRST_CT_DEN_ID) {
      shiftedOffset += 0x300;
    } else if (denId >= FIRST_IOA_DEN_ID) {
      shiftedOffset += 0x108;
    }

    this->readHeap(shiftedOffset + (denId * 0x18), denBytes, 0x18);

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

  bool SWSHGame::checkSanity(u64 offset, u32 size) {
    u32 readSize = 0;

    this->readHeap(offset, &readSize, sizeof(u32));

    return readSize == size;
  }

  // Unfortunately this is mostly a duplicate of readEventEncounterTable.
  // The flatbuffer classes should be unmodified after being generated, so they don't have a shared interface.
  // The good thing is both functions have the same return, so this is the only duplicate code.
  std::vector<RaidEncounterTable> SWSHGame::readEncounterTables() {
    bool isValidSize = this->checkSanity(m_nestFlatbufferSanityOffset, m_nestFlatbufferSanityValue);
    std::vector<RaidEncounterTable> result = { { hash : 0, templates : {} } };

    if (!isValidSize) {
      return result;
    }

    u8 *encounterFlatbuffer = new u8[m_nestFlatbufferSize];
    this->readHeap(m_nestFlatbufferOffset, encounterFlatbuffer, m_nestFlatbufferSize);
    auto nestTables = pkNX::Structures::GetEncounterNest8Archive(encounterFlatbuffer)->Tables();

    // Don't assume Sword will always be first
    u32 gameVersion = this->getTitleId() == SWORD_TITLE_ID ? 1 : 2;

    for (auto nestTable = nestTables->begin(); nestTable != nestTables->end(); ++nestTable) {
      if (nestTable->GameVersion() != gameVersion) {
        continue;
      }

      std::vector<RaidEncounter> templates;
      auto encounters = nestTable->Entries();

      for (auto encounter = encounters->begin(); encounter != encounters->end(); ++encounter) {
        auto probabilities = encounter->Probabilities();

        RaidEncounter raidEncounter = {
          species : encounter->Species(),
          flawlessIVs : (u32)encounter->FlawlessIVs(),
          ability : (csight::game::swsh::AbilityRaidSetting)encounter->Ability(),
          form : (u16)encounter->AltForm(),
          probabilities : {
              probabilities->Get(0),
              probabilities->Get(1),
              probabilities->Get(2),
              probabilities->Get(3),
              probabilities->Get(4),
          },
          shinyType : ShinyRaidSetting::Random,
        };

        templates.push_back(raidEncounter);
      }

      result.push_back({ hash : nestTable->TableID(), templates : templates });
    }

    delete[] encounterFlatbuffer;

    return result;
  }

  // Unfortunately this is mostly a duplicate of readEncounterTable.
  // The flatbuffer classes should be unmodified after being generated, so they don't have a shared interface.
  // The good thing is both functions have the same return, so this is the only duplicate code.
  std::shared_ptr<RaidEncounterTable> SWSHGame::readEventEncounterTable() {
    std::vector<RaidEncounter> raidEncounters;
    auto encounterTable = std::make_shared<RaidEncounterTable>(RaidEncounterTable { eventHash, raidEncounters });

    bool isValid = this->checkSanity(m_eventFlatbufferOffset - 0x10, m_eventFlatbufferSize - 4);

    if (!isValid) {
      return encounterTable;
    }

    u8 *eventFlatbuffer = new u8[m_eventFlatbufferSize];
    this->readHeap(m_eventFlatbufferOffset, eventFlatbuffer, m_eventFlatbufferSize);
    auto eventEncounterTables = pkNX::Structures::GetNestHoleDistributionEncounter8Archive(eventFlatbuffer)->Tables();

    // Don't assume Sword will always be first
    u32 gameVersion = this->getTitleId() == SWORD_TITLE_ID ? 1 : 2;
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
