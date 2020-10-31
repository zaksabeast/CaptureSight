#pragma once

#include <csight/Game/GameReader.hpp>
#include <csight/Game/SWSH/Den.hpp>
#include <csight/Game/SWSH/DmaxAdventure.hpp>
#include <csight/PKM/PK8.hpp>
#include <memory>
#include <vector>

namespace csight::game::swsh {
  class SWSHGame : public GameReader<pkm::PK8> {
   public:
    SWSHGame();
    SWSHGame(std::string swordFlatbufferFile, std::string shieldFlatbufferFile);
    std::shared_ptr<Den> readDen(u16 denId);
    std::vector<std::shared_ptr<Den>> readDens(u32 start = 0, u32 end = DEN_LIST_SIZE, bool filterActiveDens = false);
    std::vector<std::shared_ptr<Den>> readDens(DenType filterDenType, bool filterActiveDens = false);
    std::vector<RaidEncounterTable> readEncounterTables(std::string swordFlatbufferFile, std::string shieldFlatbufferFile);
    std::shared_ptr<RaidEncounterTable> readEventEncounterTable();
    bool checkSanity(u64 offset, u32 size);
    std::vector<std::shared_ptr<pkm::PK8>> readParty();
    std::vector<std::shared_ptr<pkm::PK8>> readBoxes();
    std::shared_ptr<pkm::PK8> readWild();
    std::shared_ptr<pkm::PK8> readRaid();
    std::shared_ptr<pkm::PK8> readTrade();
    u64 readDmaxAdventureSeed();
    std::shared_ptr<DmaxAdventure> getDmaxAdventureSpeciesList(u8 npcCount);
    u32 getTrainerSIDTID();

   private:
    u64 m_denOffset = 0x450c8a70;
    u64 m_eventFlatbufferOffset = 0x2f9eb350;
    u64 m_dmaxAdventureSpeciesSeedOffset = 0x4514a4b0;
    u64 m_trainerBlockOffset = 0x45068fb8;
    u64 m_raidOffset = 0x886c1ec8;
    u64 m_legendOffset = 0x886bc058;
    u64 m_tradeOffset = 0xaf286078;
    u64 m_partyOffset = 0x450c68b0;
    u64 m_wildOffset = 0x8fea3648;
    u64 m_boxOffset = 0x45075880;

    u32 m_eventFlatbufferSize = 0x23D4;

    std::vector<RaidEncounterTable> m_encounterTables;
    std::shared_ptr<RaidEncounterTable> m_eventTemplateTable;
  };
}
