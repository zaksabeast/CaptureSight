#pragma once

#include <vector>
#include <switch.h>
#include <stratosphere.hpp>
#include <utils/PK8.hpp>

class GameReader {
 public:
  GameReader();
  std::vector<std::shared_ptr<PK8>> ReadParty();
  std::vector<std::shared_ptr<PK8>> ReadBoxes();
  std::vector<std::shared_ptr<PK8>> ReadWild();

 private:
  u64 partyOffset = 0x4298E8E0;
  u64 boxOffset = 0x4293D8B0;
  u64 wildOffset = 0x8D45C648;
  DmntCheatProcessMetadata metadata;
  Result ReadHeap(u64 address, void* buffer, size_t size);
  std::vector<std::shared_ptr<PK8>> ReadPK8s(u64 offset, u32 amount, u32 bytesBetweenPokemon);
};
