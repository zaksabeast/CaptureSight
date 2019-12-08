#pragma once

#include <switch.h>

class Den {
 public:
  u8 GetStars(u8 denId);
  u8 GetRarity(u8 denId);
  bool GetWattFlag(u8 denId);

 private:
  u64 denOffset = 0x4298FA20;
  virtual Result ReadHeap(u64 offset, void* buffer, size_t size) { return 0; }
  Result ReadDenOffset(u64 offset, void* buffer, size_t size);
};
