#include <memory>
#include <csight/RaidDetails.hpp>
#include <csight/TitleIds.hpp>
#include <csight/DenHashes.hpp>
#include <csight/NestHoleDistributionEncounter8Archive_generated.h>

namespace csight {
  namespace raid {
    u8 GetDenReadId(u8 denId) {
      // Dens are zero-indexed in memory, but we omit 16 since it's for special encounters
      // This is for consistency with the PKHeX Raid Plugin and RaidFinder
      return denId > 16 ? denId : denId - 1;
    }

    std::shared_ptr<Den> RaidDetails::ReadDen(u8 denId) {
      u8* denBytes = new u8[0x18];
      u8 readId = GetDenReadId(denId);
      bool isPlayingSword = this->GetTitleId() == SWORD_TITLE_ID;
      auto encounterTables = isPlayingSword ? swordEncounterTables : shieldEncounterTables;
      auto eventTemplateTable = this->ReadEventEncounterTable(isPlayingSword);

      this->ReadHeap(this->denOffset + (readId * 0x18), denBytes, 0x18);

      auto den = std::make_shared<Den>(denBytes, denId, encounterTables, eventTemplateTable);

      delete[] denBytes;
      return den;
    }

    std::vector<std::shared_ptr<Den>> RaidDetails::ReadDens(bool shouldReadAllDens) {
      std::vector<std::shared_ptr<Den>> dens;

      // We don't treat den Ids as zero-indexed for consistency with the PKHeX Raid Plugin and RaidFinder
      for (u32 i = 1; i < 100; i++) {
        auto den = this->ReadDen(i);
        if (shouldReadAllDens || den->GetIsActive()) {
          dens.push_back(den);
        }
      }

      return dens;
    }

    std::shared_ptr<RaidEncounterTable> RaidDetails::ReadEventEncounterTable(bool isPlayingSword) {
      u32 gameVersion = isPlayingSword ? 1 : 2;
      std::vector<RaidEncounter> raidEncounters;
      auto encounterTable = std::make_shared<RaidEncounterTable>(RaidEncounterTable{eventHash, raidEncounters});
      u32 eventFlatbufferInMemorySize = 0;
      this->ReadHeap(this->eventFlatbufferOffset + 0x10, &eventFlatbufferInMemorySize, sizeof(u32));

      if (eventFlatbufferInMemorySize + 4 != this->eventFlatbufferSize)
        return encounterTable;

      u8* eventFlatbuffer = new u8[this->eventFlatbufferSize];
      this->ReadHeap(this->eventFlatbufferOffset + 0x20, eventFlatbuffer, this->eventFlatbufferSize);
      auto eventEncounterTables = pkNX::Structures::GetNestHoleDistributionEncounter8Archive(eventFlatbuffer)->Tables();

      // Don't assume Sword will always be first
      auto tableIndex = gameVersion == eventEncounterTables->Get(0)->GameVersion() ? 0 : 1;
      auto eventTable = eventEncounterTables->Get(tableIndex);
      auto eventEncounters = eventTable->Entries();

      for (auto eventEncounter = eventEncounters->begin(); eventEncounter != eventEncounters->end(); ++eventEncounter) {
        auto eventProbabilities = eventEncounter->Probabilities();
        RaidEncounter raidEncounter = {eventEncounter->Species(),
                                       (uint)eventEncounter->FlawlessIVs(),
                                       {
                                           eventProbabilities->Get(0),
                                           eventProbabilities->Get(1),
                                           eventProbabilities->Get(2),
                                           eventProbabilities->Get(3),
                                           eventProbabilities->Get(4),
                                       }};

        encounterTable->templates.push_back(raidEncounter);
      }

      encounterTable->hash = eventTable->TableID();

      delete[] eventFlatbuffer;

      return encounterTable;
    }
  }  // namespace raid
}  // namespace csight