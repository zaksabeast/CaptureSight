#pragma once

#include <vector>
#include <switch.h>
#include <utils/Den.hpp>

namespace raid {
  class RaidDetails {
   public:
    std::shared_ptr<Den> ReadDen(u8 denId);
    std::vector<std::shared_ptr<Den>> ReadDens(bool shouldReadAllDens);
    virtual u64 GetTitleId();

   private:
    u64 denOffset = 0x4298FA80;
    virtual Result ReadHeap(u64 offset, void* buffer, size_t size);
  };
}  // namespace raid