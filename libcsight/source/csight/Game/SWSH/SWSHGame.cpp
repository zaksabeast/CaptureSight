#include <csight/Enums/Ability.hpp>
#include <csight/Game/GameReader.hpp>
#include <csight/Game/SWSH/DenHashes.hpp>
#include <csight/Game/SWSH/DmaxAdventure.hpp>
#include <csight/Game/SWSH/EncounterNest8Archive_generated.h>
#include <csight/Game/SWSH/NestHoleDistributionEncounter8Archive_generated.h>
#include <csight/Game/SWSH/RaidSettings.hpp>
#include <csight/Game/SWSH/SWSHGame.hpp>
#include <csight/PKM/PK8.hpp>
#include <csight/RNG/RNG.hpp>
#include <csight/TitleIds.hpp>
#include <flatbuffers/flatbuffers.h>
#include <fstream>
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
        return 0x2f9ea520;
      case SetLanguage_ZHTW:
      case SetLanguage_ZHHANT:
        return 0x2f9ea4c0;
      case SetLanguage_KO:
        return 0x2f9ea920;
      case SetLanguage_IT:
        return 0x2f9eb2a0;
      case SetLanguage_JA:
        return 0x2f9eb480;
      case SetLanguage_FR:
      case SetLanguage_FRCA:
        return 0x2f9eb510;
      case SetLanguage_ES:
      case SetLanguage_ES419:
        return 0x2f9eb4e0;
      case SetLanguage_DE:
        return 0x2f9eb5f0;
      case SetLanguage_NL:
        return 0x2f9ec4d0;
      case SetLanguage_PT:
      case SetLanguage_RU:
      case SetLanguage_ENUS:
      case SetLanguage_ENGB:
      default:
        return 0x2f9eb320;
    }
  }

  SWSHGame::SWSHGame() : GameReader<pkm::PK8>() {
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

    m_encounterTables = { { hash : 0u, templates : templates } };
    m_eventTemplateTable = std::make_shared<RaidEncounterTable>(RaidEncounterTable { hash : 0u, templates : templates });
  }

  SWSHGame::SWSHGame(std::string swordFlatbufferFile, std::string shieldFlatbufferFile) : GameReader<pkm::PK8>() {
    m_eventTemplateTable = this->readEventEncounterTable();
    m_encounterTables = this->readEncounterTables(swordFlatbufferFile, shieldFlatbufferFile);
  }

  std::shared_ptr<Den> SWSHGame::readDen(u16 denId) {
    u8 *denBytes = new u8[0x18];

    u64 shiftedOffset = m_denOffset;

    if (denId >= FIRST_CT_DEN_ID) {
      shiftedOffset += 0x300;
    } else if (denId >= FIRST_IOA_DEN_ID) {
      shiftedOffset += 0x108;
    }

    this->readHeap(shiftedOffset + (denId * 0x18), denBytes, 0x18);

    auto den = std::make_shared<Den>(denBytes, denId, m_encounterTables, m_eventTemplateTable, this->getTrainerSIDTID());

    delete[] denBytes;
    return den;
  }

  std::vector<std::shared_ptr<Den>> SWSHGame::readDens(u32 start, u32 end, bool filterActiveDens) {
    std::vector<std::shared_ptr<Den>> dens;

    for (u32 i = start; i < end; i++) {
      auto den = this->readDen(i);
      if (!filterActiveDens || den->getIsActive()) {
        dens.push_back(den);
      }
    }

    return dens;
  }

  std::vector<std::shared_ptr<Den>> SWSHGame::readDens(DenType filterDenType, bool filterActiveDens) {
    std::pair<u32, u32> denRange(0, 0);

    switch (filterDenType) {
      case DenType::IsleOfArmor:
        denRange = std::make_pair(100, 190);
        break;
      case DenType::CrownTundra:
        denRange = std::make_pair(190, DEN_LIST_SIZE);
        break;
      default:
      case DenType::Vanilla:
        denRange = std::make_pair(0, 100);
        break;
    }

    return this->readDens(denRange.first, denRange.second, filterActiveDens);
  }

  // Unfortunately this is mostly a duplicate of readEventEncounterTable.
  // The flatbuffer classes should be unmodified after being generated, so they don't have a shared interface.
  // The good thing is both functions have the same return, so this is the only duplicate code.
  std::vector<RaidEncounterTable> SWSHGame::readEncounterTables(std::string swordFlatbufferFile,
                                                                std::string shieldFlatbufferFile) {
    bool isSword = this->getTitleId() == SWORD_TITLE_ID;
    auto encounterFile = isSword ? swordFlatbufferFile : shieldFlatbufferFile;

    std::ifstream stream(encounterFile, std::ios::in | std::ios::binary);
    std::vector<u8> encounterFlatbuffer((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());

    auto nestTables = pkNX::Structures::GetEncounterNest8Archive(encounterFlatbuffer.data())->Tables();

    std::vector<RaidEncounterTable> result = {};

    for (auto nestTable = nestTables->begin(); nestTable != nestTables->end(); ++nestTable) {
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

    return result;
  }

  // Unfortunately this is mostly a duplicate of readEncounterTable.
  // The flatbuffer classes should be unmodified after being generated, so they don't have a shared interface.
  // The good thing is both functions have the same return, so this is the only duplicate code.
  std::shared_ptr<RaidEncounterTable> SWSHGame::readEventEncounterTable() {
    std::vector<RaidEncounter> raidEncounters;
    auto encounterTable = std::make_shared<RaidEncounterTable>(RaidEncounterTable { eventHash, raidEncounters });
    u8 *eventFlatbuffer = new u8[m_eventFlatbufferSize];
    auto eventFlatbufferOffset = GetEventFlatbufferOffset();

    this->readHeap(eventFlatbufferOffset, eventFlatbuffer, m_eventFlatbufferSize);

    auto verifier = flatbuffers::Verifier(eventFlatbuffer, m_eventFlatbufferSize);
    bool isValid = pkNX::Structures::VerifyNestHoleDistributionEncounter8ArchiveBuffer(verifier);

    if (!isValid) {
      return encounterTable;
    }

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

  u64 SWSHGame::readDmaxAdventureSeed() {
    u64 seed = 0;

    this->readHeap(m_dmaxAdventureSpeciesSeedOffset, &seed, sizeof(u64));

    return seed;
  }

  std::shared_ptr<DmaxAdventure> SWSHGame::getDmaxAdventureSpeciesList(u8 npcCount) {
    auto seed = this->readDmaxAdventureSeed();
    return generateDmaxAdventure(seed, npcCount);
  }

  u32 SWSHGame::getTrainerSIDTID() {
    u32 sidtid = 0;

    this->readHeap(m_trainerBlockOffset + 0xA0, &sidtid, sizeof(u32));
    return sidtid;
  }

  std::vector<std::shared_ptr<pkm::PK8>> SWSHGame::readParty() { return this->readPKMs(m_partyOffset, 6, pkm::PK8::PartySize); }

  std::vector<std::shared_ptr<pkm::PK8>> SWSHGame::readBoxes(u16 box) {
    u16 safeBox = box > SWSHGame::MaxBox ? 0 : box;
    auto boxOffset = m_baseBoxOffset + (safeBox * 30 * pkm::PK8::PartySize);

    return this->readPKMs(boxOffset, 30, pkm::PK8::PartySize);
  }

  std::shared_ptr<pkm::PK8> SWSHGame::readWild() {
    auto pkm = this->readPKM(m_wildOffset, pkm::PK8::PartySize);
    return pkm->getIsValid() ? pkm : this->readPKM(m_legendOffset, pkm::PK8::PartySize);
  }
}
