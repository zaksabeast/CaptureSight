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
    std::shared_ptr<Den> readDen(u8 denId);
    std::vector<std::shared_ptr<Den>> readDens(bool shouldReadAllDens);
    std::vector<RaidEncounterTable> getEncounterTables();
    std::shared_ptr<RaidEncounterTable> readEventEncounterTable();
    std::vector<std::shared_ptr<pkm::PK8>> readParty();
    std::vector<std::shared_ptr<pkm::PK8>> readBoxes();
    std::shared_ptr<pkm::PK8> readWild();
    std::shared_ptr<pkm::PK8> readRaid();
    std::shared_ptr<pkm::PK8> readTrade();
    u32 getTrainerSIDTID();

   private:
    u64 m_denOffset = 0x450C0A80;
    u64 m_eventFlatbufferOffset = 0x2E5E58B8;
    u64 m_trainerBlockOffset = 0x45061108;
    u64 m_raidOffset = 0x886C1BD8;
    u64 m_legendOffset = 0x886BC058;
    u64 m_tradeOffset = 0xAF285F68;
    u64 m_partyOffset = 0x450BE8C0;
    u64 m_wildOffset = 0x8FEA3358;
    u64 m_boxOffset = 0x4506D890;

    bool m_shouldUseSmallMemoryMode = true;
    size_t m_eventFlatbufferSize = 0x23D4;
  };
}
