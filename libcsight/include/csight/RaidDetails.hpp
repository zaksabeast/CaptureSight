#pragma once

#include <csight/Den.hpp>
#include <memory>
#include <vector>

namespace csight::raid {
  class RaidDetails {
   public:
    RaidDetails();
    std::shared_ptr<Den> ReadDen(u8 denId);
    std::vector<std::shared_ptr<Den>> ReadDens(bool shouldReadAllDens);
    std::vector<RaidEncounterTable> GetEncounterTables();
    std::shared_ptr<RaidEncounterTable> ReadEventEncounterTable();
    virtual u64 GetTitleId() = 0;

   private:
    u64 m_denOffset = 0x4298FA80;
    u64 m_eventFlatbufferOffset = 0x2E5E58B8;
    size_t m_eventFlatbufferSize = 0x23D4;
    virtual Result ReadHeap(u64 offset, void *buffer, size_t size) = 0;
  };
}  // namespace csight::raid