#pragma once

#include <csight/Den.hpp>
#include <memory>
#include <vector>

namespace csight::raid {
  class RaidDetails {
   public:
    RaidDetails(bool shouldUseSmallMemoryMode);
    std::shared_ptr<Den> readDen(u8 denId);
    std::vector<std::shared_ptr<Den>> readDens(bool shouldReadAllDens);
    std::vector<RaidEncounterTable> getEncounterTables();
    std::shared_ptr<RaidEncounterTable> readEventEncounterTable();
    virtual u64 getTitleId() = 0;

   private:
    bool m_shouldUseSmallMemoryMode = true;
    u64 m_denOffset = 0x450C0A80;
    u64 m_eventFlatbufferOffset = 0x2E5E58B8;
    size_t m_eventFlatbufferSize = 0x23D4;
    virtual Result readHeap(u64 offset, void *buffer, size_t size) = 0;
  };
}  // namespace csight::raid