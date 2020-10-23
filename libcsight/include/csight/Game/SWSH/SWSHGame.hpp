#pragma once

#include <csight/Game/GameReader.hpp>
#include <csight/Game/SWSH/Den.hpp>
#include <csight/PKM/PK8.hpp>
#include <memory>
#include <vector>

namespace csight::game::swsh {
  class SWSHGame : public GameReader<pkm::PK8> {
   public:
    SWSHGame(bool shouldUseSmallMemoryMode);
    std::shared_ptr<Den> readDen(u16 denId);
    std::vector<std::shared_ptr<Den>> readDens(bool shouldReadAllDens);
    std::vector<RaidEncounterTable> readEncounterTables();
    std::shared_ptr<RaidEncounterTable> readEventEncounterTable();
    bool checkSanity(u64 offset, u32 size);
    std::vector<std::shared_ptr<pkm::PK8>> readParty();
    std::vector<std::shared_ptr<pkm::PK8>> readBoxes();
    std::shared_ptr<pkm::PK8> readWild();
    std::shared_ptr<pkm::PK8> readRaid();
    std::shared_ptr<pkm::PK8> readTrade();
    u32 getTrainerSIDTID();

   private:
    u64 m_denOffset = 0x450c8a70;
    u64 m_eventFlatbufferOffset = 0x2f9eb350;
    u64 m_nestFlatbufferOffset = 0x40bc5b50;
    u64 m_nestFlatbufferSanityOffset = 0x40bc5b70;
    u64 m_trainerBlockOffset = 0x45068fb8;
    u64 m_raidOffset = 0x886c1ec8;
    u64 m_legendOffset = 0x886bc058;
    u64 m_tradeOffset = 0xaf286078;
    u64 m_partyOffset = 0x450c68b0;
    u64 m_wildOffset = 0x8fea3158;
    u64 m_boxOffset = 0x45075880;

    bool m_shouldUseSmallMemoryMode = true;
    u32 m_eventFlatbufferSize = 0x23D4;
    u32 m_nestFlatbufferSize = 0x5AB00;
    // This is a u32 to enusre the flatbuffer is there
    u32 m_nestFlatbufferSanityValue = 0x5a35c;
  };
}
