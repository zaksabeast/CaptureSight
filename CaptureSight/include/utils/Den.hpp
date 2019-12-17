#pragma once

#include <memory>
#include <vector>
#include <switch.h>
#include <stratosphere.hpp>

class Den {
 public:
  Den(u8* data, u8 denId);
  ~Den();
  u64 GetSeed();
  u8 GetStars();
  u8 GetRandRoll();
  u8 GetType();
  bool GetIsActive();
  u8 GetDenId();

 private:
  u8 size = 0x18;
  u8* data = new u8[0x18];
  u8 denId = 0;
};

class RaidDetails {
 public:
  std::shared_ptr<Den> ReadDen(u8 denId);
  std::vector<std::shared_ptr<Den>> ReadDens(bool shouldReadAllDens);

 private:
  u64 denOffset = 0x4298FA80;
  virtual Result ReadHeap(u64 offset, void* buffer, size_t size);
};
