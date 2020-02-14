#pragma once

#include <vector>
#include <memory>
#include <csight/Den.hpp>

namespace csight {
  namespace raid {
    class RaidDetails {
     public:
      RaidDetails();
      std::shared_ptr<Den> ReadDen(u8 denId);
      std::vector<std::shared_ptr<Den>> ReadDens(bool shouldReadAllDens);
      virtual u64 GetTitleId() = 0;

     private:
      u64 denOffset = 0x4298FA80;
      u64 eventFlatbufferOffset = 0x2E5E58B8;
      size_t eventFlatbufferSize = 0x23D4;
      std::shared_ptr<RaidEncounterTable> ReadEventEncounterTable(bool isPlayingSword);
      virtual Result ReadHeap(u64 offset, void* buffer, size_t size) = 0;
    };
  }  // namespace raid
}  // namespace csight