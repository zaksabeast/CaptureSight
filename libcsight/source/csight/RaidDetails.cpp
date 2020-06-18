#include <csight/Ability.hpp>
#include <csight/DenHashes.hpp>
#include <csight/NestHoleDistributionEncounter8Archive_generated.h>
#include <csight/RaidDetails.hpp>
#include <csight/TitleIds.hpp>
#include <memory>
#include <switch.h>

namespace csight::raid {
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

  RaidDetails::RaidDetails(bool shouldUseSmallMemoryMode) {
    m_shouldUseSmallMemoryMode = shouldUseSmallMemoryMode;
    m_eventFlatbufferOffset = GetEventFlatbufferOffset();
  }

  std::shared_ptr<Den> RaidDetails::ReadDen(u8 denId) {
    u8 *denBytes = new u8[0x18];
    std::vector<RaidEncounterTable> encounterTables;
    std::shared_ptr<RaidEncounterTable> eventTemplateTable;

    if (m_shouldUseSmallMemoryMode) {
      encounterTables = { {
        hash : 0u,
        templates : {
            {
              species : 0,
              flawlessIVs : 1,
              ability : ability::raid::FirstOrSecond,
              form : 0,
              probabilities : { 35, 0, 0, 0, 0 },
            },
        }
      } };
      eventTemplateTable = std::make_shared<RaidEncounterTable>(RaidEncounterTable {
        hash : 0u,
        templates : {
            {
              species : 0,
              flawlessIVs : 1,
              ability : ability::raid::FirstOrSecond,
              form : 0,
              probabilities : { 35, 0, 0, 0, 0 },
            },
        }
      });
    } else {
      encounterTables = this->GetEncounterTables();
      eventTemplateTable = this->ReadEventEncounterTable();
    }

    this->ReadHeap(m_denOffset + (denId * 0x18), denBytes, 0x18);

    auto den = std::make_shared<Den>(denBytes, denId, encounterTables, eventTemplateTable);

    delete[] denBytes;
    return den;
  }

  std::vector<std::shared_ptr<Den>> RaidDetails::ReadDens(bool shouldReadAllDens) {
    std::vector<std::shared_ptr<Den>> dens;

    for (u32 i = 0; i < DEN_LIST_SIZE; i++) {
      auto den = this->ReadDen(i);
      if (shouldReadAllDens || den->GetIsActive()) {
        dens.push_back(den);
      }
    }

    return dens;
  }

  std::vector<RaidEncounterTable> RaidDetails::GetEncounterTables() {
    if (this->GetTitleId() == SWORD_TITLE_ID) {
      return GetSwordEncounterTables();
    }

    return GetShieldEncounterTables();
  }

  std::shared_ptr<RaidEncounterTable> RaidDetails::ReadEventEncounterTable() {
    bool isPlayingSword = this->GetTitleId() == SWORD_TITLE_ID;
    u32 gameVersion = isPlayingSword ? 1 : 2;
    std::vector<RaidEncounter> raidEncounters;
    auto encounterTable = std::make_shared<RaidEncounterTable>(RaidEncounterTable { eventHash, raidEncounters });
    u32 eventFlatbufferInMemorySize = 0;
    this->ReadHeap(m_eventFlatbufferOffset + 0x10, &eventFlatbufferInMemorySize, sizeof(u32));

    if (eventFlatbufferInMemorySize + 4 != m_eventFlatbufferSize)
      return encounterTable;

    u8 *eventFlatbuffer = new u8[m_eventFlatbufferSize];
    this->ReadHeap(m_eventFlatbufferOffset + 0x20, eventFlatbuffer, m_eventFlatbufferSize);
    auto eventEncounterTables = pkNX::Structures::GetNestHoleDistributionEncounter8Archive(eventFlatbuffer)->Tables();

    // Don't assume Sword will always be first
    auto tableIndex = gameVersion == eventEncounterTables->Get(0)->GameVersion() ? 0 : 1;
    auto eventTable = eventEncounterTables->Get(tableIndex);
    auto eventEncounters = eventTable->Entries();

    for (auto eventEncounter = eventEncounters->begin(); eventEncounter != eventEncounters->end(); ++eventEncounter) {
      auto eventProbabilities = eventEncounter->Probabilities();
      RaidEncounter raidEncounter = {
        eventEncounter->Species(),
        (u32)eventEncounter->FlawlessIVs(),
        (ability::raid::AbilityRaidSetting)eventEncounter->Ability(),
        (u16)eventEncounter->AltForm(),
        {
            eventProbabilities->Get(0),
            eventProbabilities->Get(1),
            eventProbabilities->Get(2),
            eventProbabilities->Get(3),
            eventProbabilities->Get(4),
        },
      };

      encounterTable->templates.push_back(raidEncounter);
    }

    encounterTable->hash = eventTable->TableID();

    delete[] eventFlatbuffer;

    return encounterTable;
  }
}  // namespace csight::raid